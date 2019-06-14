/*
	*** AtenCalc Main
	*** src/main.cpp
	Copyright T. Youngs 2010-2012

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
#include "parser/program.h"
#include "base/sysfunc.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

#define VERSION "1.0.0"

// External AtenCalc declaration and constructor definition (to setup options)
AtenCalc ac;
AtenCalc::AtenCalc()
{
	debugOutput = FALSE;
	exitAfterArguments = TRUE;
	abortOnError = FALSE;
	useConstants = TRUE;
}

int main(int argc, char *argv[])
{
	// Set random seed
// 	srand( (unsigned)time( NULL ) );

	// Main program
	Program program;
	ReturnValue result;
	Dnchar s(8096);

	// Parse CLI Options (and expressions)
	int argn = 0, n, nargsparsed = 0;
	bool isShort, hasArg;
	// Cycle over program arguments and available CLI options (skip [0] which is the binary name)
	while (argn < (argc-1))
	{
		argn++;
		// Check for null argument
		if (argv[argn][0] == '\0') continue;
		// Check for a CLI argument (presence of '-')
		// It's possible that this is the start of the expression (with a negative number) rather than a CLI switch....
		if ((argv[argn][0] == '-') && (!isdigit(argv[argn][1])) && (argv[argn][1] != '.'))
		{
			// Perform switch(es) function(s)
			n = 1;
			while (argv[argn][n] != '\0')
			{
				switch (argv[argn][n])
				{
					// Turn on debug messages
					case ('d'):
						ac.debugOutput = TRUE;
						break;
					// Don't abort on first error
					case ('e'):
						ac.abortOnError = FALSE;
						break;
					// Enter interactive mode after processing arguments
					case ('i'):
						ac.exitAfterArguments = FALSE;
						break;
					// Simple mode - don't recognise any constants except PI
					case ('s'):
						ac.useConstants = FALSE;
						break;
					// Print help
					case ('h'):
						printf("Syntax: ac [options] <expr> [<expr>]\n");
						printf("\nUsage Notes (%s):\n", VERSION);
						printf("\t0) The default unit for trigonometric functions is degrees\n");
						printf("\t   General expression syntax is C-like (i.e. functions need parentheses, commands separated with semicolon etc.)\n");
						printf("\t1) Arguments passed to ac will be evaluated as expressions\n");
						printf("\t\te.g. 'ac 4+4' will return '8'\n");
						printf("\t\te.g. 'ac \"sin(120.0)\" will return '0.86625'\n");
						printf("\t\tIf arguments are given in this way, the default behaviour of ac is to exit immediately after the last argument is processed.\n");
						printf("\nProgram Options:\n");
						printf("\t-d\tEnable lots of debugging output.\n");
						printf("\t-h\tDisplay this message and quit.\n");
						printf("\t-i\tEnter interactive mode (don't exit after processing any CLI arguments)\n");
						printf("\t-s\tSimple mode - doesn't recognise any named constants, including PI.\n");
						printf("\n");
						return 0;
						break;
					// Undefined option
					default:
						printf("Command-line option -%c not recognised.\n", argv[argn][n]);
						return -1;
				}
				++n;
			}
		}
		else
		{
// 			// Not a CLI switch, so might be the expression!
			program.mainProgram()->reset();
			// Add on terminating ';' to argument, just in case
			s = argv[argn];
			s += ';';
			if (!program.generateFromString(s, "Expression from argument")) { if (ac.abortOnError) return -1; }
			int exec = program.execute(result); 
			if ((exec == 0) && ac.abortOnError) return -1;
			if (exec == -1) return 0;
			if (result.type() != VTypes::NoData) printf("%s\n", result.asString());
 			else { if (ac.abortOnError) return -1; }
			++nargsparsed;
		}
	}
	
	// Exit now if arguments were processed?
	if ((nargsparsed != 0) && ac.exitAfterArguments) return 0;
	
	// Setup and restore history from previous sessions
	Dnchar HOMEDIR = getenv("HOME"), historyFile;
	historyFile.sprintf("%s/.achistory", HOMEDIR.get());
	read_history(historyFile.get());

	// Anything redirected to stdin (or forcibly piped)?
	// Grab all lines from cin to a temporary stringlist....
	char *line; //line[8096];
	while (cin.good() && (!cin.eof()))
	{
		// Get string from user
		//cin.getline(line, 8095);
		line = readline("ac> ");
		if (isEmpty(line)) continue;

		// Add on terminating ';' to argument, just in case
		s = line;
		s += ';';

		program.mainProgram()->reset();
		if (!program.generateFromString(s, "Expression from cin")) { if (ac.abortOnError) return -1; }
		int exec = program.execute(result);
		if ((exec == 0) && ac.abortOnError) return -1;
		if (exec == -1) break;
		if (result.type() == VTypes::IntegerData) printf("%li\n", result.asInteger());
		else if (result.type() == VTypes::DoubleData) printf("%e\n", result.asDouble());
		else { if (ac.abortOnError) return -1; }

		// Add the command to the history and delete it 
		add_history(line);
		free(line);
	}
	
	// Save history
	write_history(historyFile.get());

	// Done.
	return 0;
}

