/* -------- */
/* Prologue */
/* -------- */
%{

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "command/commands.h"
#include "parser/parser.h"
#include "parser/tree.h"
#include "base/messenger.h"

/* Prototypes */
int CommandParser_lex(void);
void CommandParser_error(char *s);

/* Local Variables */
Dnchar tokenName;
List<Dnchar> stepNameStack;
VTypes::DataType declaredType, funcType;
TreeNode *tempNode;

%}

// Redeclare function names
%name-prefix="CommandParser_"

/* Type Definition */
%union {
	int functionId;			/* Function enum id */
	Dnchar *name;			/* character pointer for names */
	TreeNode *node;			/* node pointer */
	Variable *variable;		/* variable pointer */
	Tree *tree;			/* function (tree) pointer */
	VTypes::DataType vtype;		/* variable type for next declarations */
	signed long int intconst;	/* integer constant value */
	double doubleconst;		/* double constant value */
};

%token <intconst> INTCONST
%token <doubleconst> DOUBLECONST
%token <name> NEWTOKEN CHARCONST STEPTOKEN
%token <variable> VAR LOCALVAR
%token <functionId> FUNCCALL
%token <tree> USERFUNCCALL
%token <vtype> VTYPE
%token ATENCALC_DO ATENCALC_WHILE ATENCALC_FOR ATENCALC_SWITCH ATENCALC_CASE ATENCALC_DEFAULT ATENCALC_IF ATENCALC_RETURN ATENCALC_VOID ATENCALC_CONTINUE ATENCALC_BREAK ATENCALC_QUIT
%nonassoc ATENCALC_ELSE

%left AND OR
%left '=' PEQ MEQ TEQ DEQ 
%left GEQ LEQ EQ NEQ '>' '<'
%left '+' '-'
%left '*' '/' '%'
%right UMINUS
%left PLUSPLUS MINUSMINUS
%right '!'
%right '^'

%type <node> constant expression expressionlist variable statement flowstatement statementlist block blockment assignment
%type <node> declaration functiondeclaration caselabel caselist
%type <node> ARRAYCONST function userfunction assignedvariablename variablelistitem variablelist typedvariablelistitem typedvariablelist
%type <name> variablename
%type <node> pushscope
%type <tree> pushfunc

%%

/* ------------------------- */
/* Main Program Construction */
/* ------------------------- */

/* Program List */
programlist:
	program						{ }
	| programlist program				{ }
	;

/* Single Program 'Statement' */
program:
	statementlist					{
		if (($1 != NULL) && (!cmdparser.addStatement($1))) YYABORT;
		}
	| block						{
		if (($1 != NULL) && (!cmdparser.addStatement($1))) YYABORT;
		}
	;

/* --------- */
/* Constants */
/* --------- */

constant:
	INTCONST					{ $$ = cmdparser.addConstant($1); }
	| DOUBLECONST					{ $$ = cmdparser.addConstant($1); }
	| CHARCONST					{ $$ = cmdparser.addConstant($1->get()); }
	;

/* ----------------- */
/* Variables & Paths */
/* ----------------- */

/* Single Path Step */
step:
	STEPTOKEN pushstepname '[' expression ']' 	{
		if (!cmdparser.expandPath(stepNameStack.last(), $4)) YYABORT;
		stepNameStack.removeLast();
		}
	| STEPTOKEN pushstepname '(' expressionlist ')' {
		if (!cmdparser.expandPath(stepNameStack.last(), NULL, $4)) YYABORT;
		stepNameStack.removeLast();
		}
	| STEPTOKEN pushstepname '(' ')' 		{
		if (!cmdparser.expandPath(stepNameStack.last(), NULL, NULL)) YYABORT;
		stepNameStack.removeLast();
		}
	| STEPTOKEN pushstepname 			{
		if (!cmdparser.expandPath($1)) YYABORT;
		stepNameStack.removeLast();
		}
	;

/* Multiple Step Path */
steplist:
	step 						{ }
	| steplist '.' step				{ }
	| steplist error				{ printf("Error formulating path.\n"); YYABORT; }
	;

/* Pre-Existing Variable */
variable:
	VAR '[' expression ']'				{
		$$ = cmdparser.wrapVariable($1,$3);
		if ($$ == NULL) { printf("Error in variable expression (code 1)\n"); YYABORT; }
		}
	| VAR						{
		$$ = cmdparser.wrapVariable($1);
		if ($$ == NULL) { printf("Error in variable expression (code 2)\n"); YYABORT; }
		}
	| LOCALVAR '[' expression ']'			{
		$$ = cmdparser.wrapVariable($1,$3);
		if ($$ == NULL) { printf("Error in variable expression (code 3)\n"); YYABORT; }
		}
	| LOCALVAR					{
		$$ = cmdparser.wrapVariable($1);
		if ($$ == NULL) { printf("Error in variable expression (code 4)\n"); YYABORT; }
		}
	| variable '.' 					{
		cmdparser.createPath($1);
		} steplist {
		$$ = cmdparser.finalisePath();
		}
	| variable '('					{
		printf("Can't use a variable as a function. Did you mean '[' instead?\n"); $$ = NULL;
		}
	;

/* -------------- */
/* Function Calls */
/* -------------- */

/* Built-In Functions */
function:
	FUNCCALL '(' ')'				{
		$$ = cmdparser.addFunction( (Command::Function) $1);
		msg.debug("PARSER: function : function '%s'\n", commands.data[(Command::Function) $1].keyword);
		}
	| FUNCCALL '(' expressionlist ')'		{
		$$ = cmdparser.addFunctionWithArglist( (Command::Function) $1,$3);
		msg.debug("PARSER: function : function '%s' with exprlist\n", commands.data[(Command::Function) $1].keyword);
		}
	| FUNCCALL error				{
		printf("Error: Missing brackets after function call?\n");
		YYABORT;
		}
	;

/* User-Defined Functions */
userfunction:
	USERFUNCCALL '(' ')'				{
		$$ = cmdparser.addUserFunction($1);
		msg.debug("PARSER: userfunction : function '%s'\n", $1->name());
		}
	| USERFUNCCALL '(' expressionlist ')'		{
		$$ = cmdparser.addUserFunction($1,$3);
		msg.debug("PARSER: userfunction : function '%s' with expressionlist\n", $1->name());
		}
	| USERFUNCCALL error				{
		printf("Error: Missing brackets after function call?\n");
		YYABORT;
		}
	;

/* ------------ */
/* Misc Objects */
/* ------------ */

/* Array Vector Constant / Assignment Group */
ARRAYCONST:
	'{' expressionlist '}'				{
		$$ = cmdparser.addArrayConstant($2);
		}
	;

/* ----------- */
/* Expressions */
/* ----------- */

assignment:
	variable '=' expression				{ $$ = cmdparser.addOperator(Command::OperatorAssignment,$1,$3); }
	| variable '=' ARRAYCONST			{ $$ = cmdparser.addOperator(Command::OperatorAssignment,$1,$3); }
	| variable '=' error				{ printf("Mangled expression used in assignment.\n"); YYABORT; }
	;

/* Expression */
expression:
	constant					{ $$ = $1; }
	| function					{ $$ = $1; }
	| userfunction					{ $$ = $1; }
	| variable PEQ expression			{ $$ = cmdparser.addOperator(Command::OperatorAssignmentPlus,$1,$3); }
	| variable MEQ expression			{ $$ = cmdparser.addOperator(Command::OperatorAssignmentSubtract,$1,$3); }
	| variable TEQ expression			{ $$ = cmdparser.addOperator(Command::OperatorAssignmentMultiply,$1,$3); }
	| variable DEQ expression			{ $$ = cmdparser.addOperator(Command::OperatorAssignmentDivide,$1,$3); }
	| '-' expression %prec UMINUS			{ $$ = cmdparser.addOperator(Command::OperatorNegate, $2); }
	| variable PLUSPLUS				{ $$ = cmdparser.addOperator(Command::OperatorPostfixIncrease, $1);  }
	| variable MINUSMINUS				{ $$ = cmdparser.addOperator(Command::OperatorPostfixDecrease, $1); }
	| PLUSPLUS variable				{ $$ = cmdparser.addOperator(Command::OperatorPrefixIncrease, $2); }
	| MINUSMINUS variable				{ $$ = cmdparser.addOperator(Command::OperatorPrefixDecrease, $2); }
	| variable					{ $$ = $1; }
	| expression '+' expression			{ $$ = cmdparser.addOperator(Command::OperatorAdd, $1, $3); }
	| expression '-' expression			{ $$ = cmdparser.addOperator(Command::OperatorSubtract, $1, $3); }
	| expression '*' expression			{ $$ = cmdparser.addOperator(Command::OperatorMultiply, $1, $3); }
	| expression '/' expression			{ $$ = cmdparser.addOperator(Command::OperatorDivide, $1, $3); }
	| expression '^' expression			{ $$ = cmdparser.addOperator(Command::OperatorPower, $1, $3); }
	| expression '%' expression			{ $$ = cmdparser.addOperator(Command::OperatorModulus, $1, $3); }
	| expression EQ expression			{ $$ = cmdparser.addOperator(Command::OperatorEqualTo, $1, $3); }
	| expression NEQ expression			{ $$ = cmdparser.addOperator(Command::OperatorNotEqualTo, $1, $3); }
	| expression '>' expression			{ $$ = cmdparser.addOperator(Command::OperatorGreaterThan, $1, $3); }
	| expression GEQ expression			{ $$ = cmdparser.addOperator(Command::OperatorGreaterThanEqualTo, $1, $3); }
	| expression '<' expression			{ $$ = cmdparser.addOperator(Command::OperatorLessThan, $1, $3); }
	| expression LEQ expression			{ $$ = cmdparser.addOperator(Command::OperatorLessThanEqualTo, $1, $3); }
	| expression AND expression			{ $$ = cmdparser.addOperator(Command::OperatorAnd, $1, $3); }
	| expression OR expression			{ $$ = cmdparser.addOperator(Command::OperatorOr, $1, $3); }
	| '(' expression ')'				{ $$ = $2; }
	| '!' expression				{ $$ = cmdparser.addOperator(Command::OperatorNot, $2); }
	| NEWTOKEN					{ printf("Error: '%s' has not been declared as a function or a variable.\n", yylval.name->get()); YYABORT; }
	;

/* Expression LIst */
expressionlist:
	expression					{
		$$ = $1;
		if ($$ == NULL) YYABORT;
		}
	| expressionlist ',' expression			{
		$$ = Tree::joinArguments($3,$1);
		}
	| expressionlist expression			{
		printf("Error: Missing comma between items.\n");
		YYABORT;
		}
	;

/* ----------------------------- */
/* New Variables and Declaration */
/* ----------------------------- */

/* Conversion of allowable names to single token type */
variablename:
	VAR 						{
		msg.debug("PARSER: variablename : existing var '%s'\n", tokenName.get());
		tokenName = yylval.variable->name();
		$$ = &tokenName;
		}
	| FUNCCALL					{
		msg.debug("PARSER: variablename : existing built-in function '%s'\n", tokenName.get());
		tokenName = Command::data[yylval.functionId].keyword;
		$$ = &tokenName;
		}
	| LOCALVAR					{
		msg.debug("PARSER: variablename : existing local var '%s'\n", tokenName.get());
		printf("Error: Existing variable in local scope cannot be redeclared.\n");
		YYABORT;
		}
	| constant					{
		msg.debug("PARSER: variablename : constant '%s'\n", tokenName.get());
		printf("Error: Constant value found in declaration.\n");
		YYABORT;
		}
	| USERFUNCCALL					{
		msg.debug("PARSER: variablename : existing user function '%s'\n", tokenName.get());
		printf("Error: Existing user-defined function name cannot be redeclared.\n");
		YYABORT;
		}
	| VTYPE						{
		msg.debug("PARSER: variablename : variable type-name '%s'\n", VTypes::dataType( yylval.vtype));
		printf("Error: Type-name used in variable declaration.\n");
		YYABORT;
		}
	| NEWTOKEN savetokenname			{
		msg.debug("PARSER: variablename : new token '%s'\n", tokenName.get());
		if (declaredType == VTypes::NoData) { printf("Token '%s' is undeclared.\n", tokenName.get()); YYABORT; }
		$$ = $1;
		}
	;

/* Variable name with assigned value */
assignedvariablename:
	variablename '=' ARRAYCONST			{
		msg.debug("PARSER: assignedvariablename : var '%s' with array assignment\n", tokenName.get());
		$$ = cmdparser.addVariable(declaredType, &tokenName, $3);
		}
	| variablename '[' expression ']' '=' expression {
		msg.debug("PARSER: assignedvariablename : array var '%s' with expr assignment\n", tokenName.get());
		$$ = cmdparser.addArrayVariable(declaredType, &tokenName,$3,$6);
		}
	| variablename '[' expression ']' '=' ARRAYCONST {
		msg.debug("PARSER: assignedvariablename : array var '%s' with array assignment\n", tokenName.get());
		$$ = cmdparser.addArrayVariable(declaredType, &tokenName,$3,$6);
		}
	| variablename '=' expression 			{
		msg.debug("PARSER: assignedvariablename : var '%s' with expr assignment\n", tokenName.get());
		$$ = cmdparser.addVariable(declaredType, &tokenName, $3);
		}
	;

/* Variable List Item */
variablelistitem:
	variablename					{
		msg.debug("PARSER: assignedvariablename : var '%s'\n", tokenName.get());
		$$ = cmdparser.addVariable(declaredType, &tokenName);
		}
	| variablename '[' expression ']' 		{
		msg.debug("PARSER: assignedvariablename : array var '%s'\n", tokenName.get());
		$$ = cmdparser.addArrayVariable(declaredType, &tokenName, $3);
		}
	| assignedvariablename 				{
		$$ = $1;
		}
	;

/* Variable List Single */
variablelist:
	variablelistitem				{
		$$ = $1;
		}
	| variablelist ',' variablelistitem		{
		$$ = Tree::joinArguments($3,$1);
		}
	| variablelist variablelistitem			{
		printf("Error: Missing comma between declarations?\n");
		YYABORT;
		}
	;

/* Typed Variable List Single */
typedvariablelistitem:
	VTYPE savetype variablename			{
		msg.debug("PARSER: typedvariablelistitem : var '%s'\n", tokenName.get());
		$$ = cmdparser.addVariable(declaredType, &tokenName);
		}
	| VTYPE savetype variablename '=' expression 	{
		msg.debug("PARSER: typedvariablelistitem : var '%s' with expr assignment\n", tokenName.get());
		$$ = cmdparser.addVariable(declaredType, &tokenName, $5);
		}
	;

/* Typed Variable List */
typedvariablelist:
	typedvariablelistitem				{
		$$ = $1;
		}
	| typedvariablelist ',' typedvariablelistitem	{
		$$ = Tree::joinArguments($3,$1);
		}
	| typedvariablelist typedvariablelistitem	{
		printf("Error: Missing comma between declarations?\n");
		YYABORT;
		}
	;

/* Variable Declaration Statement */
declaration:
	VTYPE savetype variablelist			{
		msg.debug("PARSER: declaration : standard variable declaration list\n");
		$$ = cmdparser.addDeclarations($3);
		declaredType = VTypes::NoData;
		}
	| VTYPE savetype error				{
		printf("Illegal use of reserved word '%s'.\n", VTypes::dataType(declaredType));
		YYABORT;
		}
	;

/* -------------------- */
/* Function Declaration */
/* -------------------- */

/* User-Defined Function Declaration */
functiondeclaration:
	ATENCALC_VOID cleartype NEWTOKEN pushfunc '(' ')' block {
		msg.debug("PARSER: functiondeclaration : user-defined subroutine (VOID return value, no arguments)\n");
		if (!cmdparser.addStatement($7)) YYABORT;
		cmdparser.popTree();
		declaredType = VTypes::NoData;
		}
	| ATENCALC_VOID cleartype NEWTOKEN pushfunc '(' typedvariablelist ')' {
		msg.debug("PARSER: functiondeclaration : user-defined subroutine (VOID return value, arguments)\n");
		if (!$4->addLocalFunctionArguments($6)) YYABORT;
		} block {
		if (!cmdparser.addStatement($9)) YYABORT;
		cmdparser.popTree();
		declaredType = VTypes::NoData;
		}
	| VTYPE savetype NEWTOKEN pushfunc '(' ')' block {
		msg.debug("PARSER: functiondeclaration : user-defined function (%s return value, no arguments)\n", VTypes::dataType($4->returnType()));
		if (!cmdparser.addStatement($7)) YYABORT;
		cmdparser.popTree();
		declaredType = VTypes::NoData;
		}
	| VTYPE savetype NEWTOKEN pushfunc '(' typedvariablelist ')' {
		msg.debug("PARSER: functiondeclaration : user-defined function (%s return value, arguments)\n", VTypes::dataType($4->returnType()));
		if (!$4->addLocalFunctionArguments($6)) YYABORT;
		} block {
		if (!cmdparser.addStatement($9)) YYABORT;
		cmdparser.popTree();
		declaredType = VTypes::NoData;
		}
	;

/* ---------- */
/* Statements */
/* ---------- */

/* Statement Delimiter */
delim:
	';'						{ }
	| delim ';'					{ }
	;

/* Single Statement */
statement:
	assignment delim				{
		$$ = $1;
		}
	| declaration delim				{
		$$ = $1;
		}
	| expression delim				{
		$$ = $1;
		}
	| function delim				{
		$$ = $1;
		}
	| userfunction delim				{
		$$ = $1;
		}
	| flowstatement					{
		$$ = $1;
		}
	| functiondeclaration				{
		$$ = NULL;
		}
	| ATENCALC_RETURN expression delim	 		{
		$$ = cmdparser.addFunction(Command::Return,$2);
		}
	| ATENCALC_RETURN delim				{
		$$ = cmdparser.addFunction(Command::Return);
		}
	| ATENCALC_CONTINUE delim				{
		$$ = cmdparser.addFunction(Command::Continue);
		}
	| ATENCALC_BREAK delim				{
		$$ = cmdparser.addFunction(Command::Break);
		}
	| ATENCALC_QUIT delim				{
		$$ = cmdparser.addFunction(Command::Quit);
		}
	;

/* Statement List */
statementlist:
	statement					{
		$$ = $1;
		}
	| statementlist statement			{
		if ($2 == NULL) $$ = $1;
		else $$ = cmdparser.joinCommands($1, $2);
		}
	;

/* Block Statement */
block:
	'{' pushscope statementlist '}' popscope	{
		$$ = $3;
		}
	| '{' '}'					{
		$$ = cmdparser.addFunction(Command::NoFunction);
		}
	;

/* Block or Statement, but not Statement List */
blockment:
	statement					{
		$$ = $1;
		}
	| block						{
		$$ = $1;
		}
	;

/* Flow-Control Statement */
flowstatement:
	ATENCALC_IF '(' expression ')' blockment ATENCALC_ELSE blockment 	{
		$$ = cmdparser.addFunction(Command::If,$3,$5,$7);
		}
	| ATENCALC_IF '(' expression ')' blockment 			{
		$$ = cmdparser.addFunction(Command::If,$3,$5);
		}
	| ATENCALC_FOR pushscope '(' assignment ';' expression ';' expression ')' blockment {
		$$ = cmdparser.joinCommands($2, cmdparser.addFunction(Command::For, $4,$6,$8,$10)); cmdparser.popScope();
		}
	| ATENCALC_FOR pushscope '(' declaration ';' expression ';' expression ')' blockment {
		$$ = cmdparser.joinCommands($2, cmdparser.addFunction(Command::For, $4,$6,$8,$10)); cmdparser.popScope();
		}
	| ATENCALC_WHILE pushscope '(' expression ')' blockment	{
		$$ = cmdparser.joinCommands($2, cmdparser.addFunction(Command::While, $4,$6));
		cmdparser.popScope();
		}
	| ATENCALC_DO pushscope block ATENCALC_WHILE '(' expression ')' ';' {
		$$ = cmdparser.joinCommands($2, cmdparser.addFunction(Command::DoWhile, $3,$6));
		cmdparser.popScope();
		}
	| ATENCALC_SWITCH '(' expression ')' 		{
		if (($3->returnType() != VTypes::IntegerData) && ($3->returnType() != VTypes::StringData))
		{
			printf("Error: Switch value must be of integer or string type.\n");
			YYABORT;
		}
		} '{' caselist '}' {
		$$ = cmdparser.addFunction(Command::Switch, $3);
		$$->addJoinedArguments($7);
		}
	;

/* Switch Statement Case/Default Label */
caselabel:
	ATENCALC_CASE '(' expression ')' ':'		{
		if (($3->returnType() != VTypes::IntegerData) && ($3->returnType() != VTypes::StringData))
		{
			printf("Error: Case value must be of integer or string type.\n");
			YYABORT;
		}
		$$ = cmdparser.addFunction(Command::Case, $3);
		if ($$ == NULL) { printf("Error: Invalid case expression.\n"); YYABORT; }
		}
	| ATENCALC_DEFAULT ':'				{
		$$ = cmdparser.addFunction(Command::Default);
		}
	;

/* Switch Statement Case List */
caselist:
	caselabel 					{
		$$ = $1;
		}
	| caselist statementlist			{
		$$ = Tree::joinArguments($2,$1);
		}
	| caselist caselabel				{
		$$ = Tree::joinArguments($2,$1);
		}
	;

/* -------------------------- */
/* Semantic Value Subroutines */
/* -------------------------- */

savetokenname:
	/* empty */					{ tokenName = *yylval.name; }
	;

savetype:
	/* empty */					{ declaredType = yylval.vtype; }
	;

cleartype:
	/* empty */					{ declaredType = VTypes::NoData; }
	;

pushscope:
	/* empty */					{ $$ = cmdparser.pushScope(); if ($$ == NULL) YYABORT; }
	;

popscope:
	/* empty */					{ if (!cmdparser.popScope()) YYABORT; }
	;

pushstepname:
	/* empty */					{ stepNameStack.add()->set(yylval.name->get()); }
	;

pushfunc:
	/* empty */					{
		msg.debug("PARSER: pushfunc : function/statement '%s'\n", yylval.name->get());
		$$ = cmdparser.pushFunction(yylval.name->get(), declaredType);
		cmdparser.pushScope();
		}
	;

%%

void yyerror(char *s)
{
}
