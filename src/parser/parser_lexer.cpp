/*
	*** Parser Lexer
	*** src/parser/parser_lexer.cpp
	Copyright T. Youngs 2010-2011

	This file is part of AtenCalc.

	AtenCalc is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AtenCalc is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AtenCalc.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "main.h"
#include "base/dnchar.h"
#include "parser/variable.h"
#include "parser/parser.h"
#include "parser/grammar.h"
#include "parser/tree.h"
#include "parser/program.h"
#include "command/commands.h"
#include "base/sysfunc.h"
#include "base/messenger.h"
#include <string.h>

// Symbols
const char *SymbolTokenKeywords[CommandParser::nSymbolTokens] = { "==", ">=", "<=", "!=", "<>", "+=", "-=", "*=", "/=", "++", "--", "&&", "||" };
int SymbolTokenValues[CommandParser::nSymbolTokens] = { EQ, GEQ, LEQ, NEQ, NEQ, PEQ, MEQ, TEQ, DEQ, PLUSPLUS, MINUSMINUS, AND, OR };

// Bison-generated CommandParser_lex()
int CommandParser_lex()
{
	return cmdparser.lex();
}

// Parser lexer, called by yylex()
int CommandParser::lex()
{
	if (program_ == NULL)
	{
		printf("Lexer called when no target Program set.\n");
		return 0;
	}

	int n;
	bool done, integer, hasexp;
	static Dnchar token, name;
	char quotechar, c;
	token.clear();

	// Skip over whitespace
	while ((c = getChar()) == ' ' || c == '\t' || c == '\r' || c == '\n' );

	if (c == 0) return 0;

	// Set this point as the start of our new token (for error reporting)
	tokenStart_ = stringPos_-1;

	/*
	// A '.' followed by a character indicates a variable path - generate a step
	*/
	msg.debug("LEXER (%p): begins at [%c], peek = [%c]\n", tree_, c, peekChar());
	if ((c == '.') && isalpha(peekChar()))
	{
		msg.debug("LEXER (%p): found a '.' before an alpha character - expecting a path step next...\n",tree_);
		expectPathStep_ = TRUE;
		return '.';
	}
	
	/*
	// Number Detection - Either '.' or  a digit begins a number
	*/
	if (c == '.' || isdigit (c))
	{
		// Default to integer, unless first char is '.'
		integer = (c == '.' ? FALSE : TRUE);
		hasexp = FALSE;
		token += c;
		done = FALSE;
		do
		{
			c = getChar();
			if (isdigit(c)) token += c;
			else if (c == '.')
			{
				integer = FALSE;
				token += '.';
			}
			else if ((c == 'e') || (c == 'E'))
			{
				// Check for previous exponential in number
				if (hasexp)
				{
					printf("Error: Number has two exponentiations (e/E).\n");
					return 0;
				}
				token += 'E';
				hasexp = TRUE;
			}
			else if ((c == '-') || (c == '+'))
			{
				// We allow '-' or '+' only as part of an exponentiation, so if it is not preceeded by 'E' we stop parsing
				if ((!token.isEmpty()) && (token.lastChar() != 'E'))
				{
					unGetChar();
					done = TRUE;
				}
				else token += c;
			}
			else
			{
				unGetChar();
				done = TRUE;
			}
		} while (!done);
		// We now have the number as a text token...
		if (!hasexp)
		{
			if (integer) CommandParser_lval.intconst = atol(token);
			else CommandParser_lval.doubleconst = atof(token);
		}
		else
		{
			// Exponentiations are always returned as a double
			integer = FALSE;
			CommandParser_lval.doubleconst = atof(beforeChar(token,'E')) * pow(10.0, atof(afterChar(token,'E')));
		}
		if (integer) msg.debug("LEXER (%p): found an integer constant [%s] [%i]\n", tree_, token.get(), CommandParser_lval.intconst);
		else msg.debug("LEXER (%p): found a floating-point constant [%s] [%e]\n", tree_, token.get(), CommandParser_lval.doubleconst);
		return (integer ? INTCONST : DOUBLECONST);
	}

	/*
	// Literal Character String - surrounded by ""
	*/
	if ((c == '"') || ( c == '\''))
	{
		quotechar = c;
		// Just read everything until we find a matching quote
		done = FALSE;
		do
		{
			c = getChar();
			// Check for escaped characters....
			if (c == '\\')
			{
				// Look at next character and either add it as-is, or convert it to its proper control code
				char c2 = getChar();
				switch (c2)
				{
					case ('n'):
						token += '\n'; break;
					case ('t'):
						token += '\t'; break;
					case ('r'):
						token += '\r'; break;
					default:
						token += c2; break;
				}
			}
			else if (c == quotechar) done = TRUE;
			else if (c == '\0')
			{
				printf("Runaway character constant in input.\n");
				return 0;
			}
			else token += c;
		} while (!done);
		msg.debug("LEXER (%p): found a literal string [%s]...\n",tree_,token.get());
		name = token;
		CommandParser_lval.name = &name;
		return CHARCONST;
	}

	/*
	// Alphanumeric-token - function or variable
	*/
	if (isalpha (c))
	{
		do
		{
			token += c;
			c = getChar();
		}
		while (isalnum(c) || (c == '_'));
		unGetChar();
		msg.debug("LEXER (%p): found an alpha token [%s]...\n", tree_, token.get());
		// Skip over keyword detection if we are expecting a path step
		if (!expectPathStep_)
		{
			// Is this a variable declaration statement?
			VTypes::DataType dt = VTypes::dataType(token);
			if (dt != VTypes::nDataTypes)
			{
				msg.debug("LEXER (%p): ...which is a variable type name (->VTYPE)\n",tree_);
				CommandParser_lval.vtype = dt;
				return VTYPE;
			}

			// Built-in numeric constants
			if (ac.useConstants)
			{
				// TRUE, FALSE, or NULL token?
				if (token == "TRUE")
				{
					CommandParser_lval.intconst = 1;
					return INTCONST;
				}
				else if ((token == "FALSE") || (token == "NULL"))
				{
					CommandParser_lval.intconst = 0;
					return INTCONST;
				}
				else if (token == "Pi")
				{
					CommandParser_lval.doubleconst = PI;
					return DOUBLECONST;
				}
				else if (token == "DEGRAD")
				{
					CommandParser_lval.doubleconst = DEGRAD;
					return DOUBLECONST;
				}
				else if (token == "Bohr")
				{
					CommandParser_lval.doubleconst = BOHRRADIUS;
					return DOUBLECONST;
				}
				else if (token == "NA")
				{
					CommandParser_lval.doubleconst = AVOGADRO;
					return DOUBLECONST;
				}
				else if (token == "c")
				{
					CommandParser_lval.doubleconst = SPEEDOFLIGHT;
					return DOUBLECONST;
				}
				else if (token == "kb")
				{
					CommandParser_lval.doubleconst = BOLTZMANN;
					return DOUBLECONST;
				}
				else if (token == "h")
				{
					CommandParser_lval.doubleconst = PLANCK;
					return DOUBLECONST;
				}
				else if (token == "hbar")
				{
					CommandParser_lval.doubleconst = HBAR;
					return DOUBLECONST;
				}
			}

			// Is this a recognised high-level keyword?
			n = 0;
			if (token == "if") n = ATENCALC_IF;
			else if (token == "else") n = ATENCALC_ELSE;
			else if (token == "for") n = ATENCALC_FOR;
			else if (token == "do") n = ATENCALC_DO;
			else if (token == "continue") n = ATENCALC_CONTINUE;
			else if (token == "break") n = ATENCALC_BREAK;
			else if (token == "while") n = ATENCALC_WHILE;
			else if (token == "switch") n = ATENCALC_SWITCH;
			else if (token == "case") n = ATENCALC_CASE;
			else if (token == "default") n = ATENCALC_DEFAULT;
			else if (token == "return") n = ATENCALC_RETURN;
			else if (token == "void") n = ATENCALC_VOID;
			else if (token == "quit") n = ATENCALC_QUIT;
			if (n != 0)
			{
				msg.debug("LEXER (%p): ...which is a high-level keyword (%i)\n",tree_,n);
				return n;
			}

			// Is it an existing variable in scope?
			if (tree_ != NULL)
			{
				// Search the variable lists currently in scope...
				int scopelevel;
				Variable *v = tree_->findVariableInScope(token, scopelevel);
				if (v != NULL)
				{
					if (scopelevel == 0)
					{
						msg.debug("LEXER (%p): ...which is an existing local variable (->LOCALVAR)\n", tree_);
						CommandParser_lval.variable = v;
						return LOCALVAR;
					}
					else
					{
						msg.debug("LEXER (%p): ...which is an existing variable (->VAR)\n", tree_);
						CommandParser_lval.variable = v;
						return VAR;
					}
				}
			}

			// Is it one of Aten's function keywords?
			for (n=0; n<Command::nCommands; n++) if (strcmp(token,Command::data[n].keyword) == 0) break;
			if (n != Command::nCommands)
			{
				msg.debug("LEXER (%p): ... which is a function (->FUNCCALL).\n", tree_);
				CommandParser_lval.functionId = n;
				// Quick check - if we are declaring variables then we must raise an error
				functionStart_ = tokenStart_;
				return FUNCCALL;
			}

			// Is it a user-defined function keyword in the local scope? (Requires valid tree)
			Tree *func;
			if (tree_ != NULL)
			{
				func = tree_->findLocalFunction(token);
				if (func != NULL)
				{
					msg.debug("LEXER (%p): ... which is a used-defined function local to this tree (->USERFUNCCALL).\n", tree_);
					CommandParser_lval.tree = func;
					return USERFUNCCALL;
				}
			}

			// Is it a user-defined function keyword in the global (Forest-wide) scope, or Aten's global scope?
			func = program_->findGlobalFunction(token);
// 			if (func == NULL) func = aten.findIncludeFunction(token);
			if (func != NULL)
			{
				msg.debug("LEXER (%p): ... which is a used-defined Forest-global function (->USERFUNCCALL).\n", tree_);
				CommandParser_lval.tree = func;
				return USERFUNCCALL;
			}
		}

		// The token isn't a high- or low-level function. It's either a path step or a normal variable
		if (expectPathStep_)
		{
			expectPathStep_ = FALSE;
			msg.debug("LEXER (%p): ...which we assume is a path step (->STEPTOKEN)\n", tree_);
			name = token;
			CommandParser_lval.name = &name;
			return STEPTOKEN;
		}

		// If we get to here then we have found an unrecognised alphanumeric token
		msg.debug("LEXER (%p): ...which is unrecognised (->NEWTOKEN)\n", tree_);
		name = token;
		CommandParser_lval.name = &name;
		return NEWTOKEN;
	}

	/* We have found a symbolic character (or a pair) that corresponds to an operator */
	// Return immediately in the case of brackets, comma, and semicolon
	if ((c == '(') || (c == ')') || (c == ';') || (c == ',') || (c == '{') || (c == '}') || (c == '[') || (c == ']') || (c == '%') || (c == ':'))
	{
		msg.debug("LEXER (%p): found symbol [%c]\n",tree_,c);
		return c;
	}
	token += c;
	// Similarly, if the next character is a period, bracket or double quotes, return immediately
	char c2 = peekChar();
	if ((c2 == '.') || (c2 == '(') || (c2 == ')') || (c2 == ';') || (c2 == '{') || (c2 == '}') || (c2 == '"')) return c;
	// If next character is '-', return now if previous char was *not* another '-'
	if ((c2 == '-') && (c != '-')) return c;
	// If it is 'punctuation', add this second character to our operator and search for it
	if (ispunct(c2))
	{
		c = getChar();
		token += c;
		msg.debug("LEXER (%p): found symbol [%s]\n",tree_,token.get());
		SymbolToken st = (SymbolToken) enumSearch("", nSymbolTokens, SymbolTokenKeywords, token.get());
		if (st != nSymbolTokens) return SymbolTokenValues[st];
		else printf("Error: Unrecognised symbol found in input (%s).\n", token.get());
 	}
	else
	{
		// Make sure that this is a known symbol
		if ((c == '$') || (c == '%') || (c == '&') || (c == '@') || (c == '?') || (c == ':'))
		{
			printf("Error: Unrecognised symbol found in input (%c).\n", c);
		}
		else return c;
	}
	return 0;
}
