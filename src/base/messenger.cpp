/*
	*** Messaging routines
	*** src/base/messenger.cpp
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

#include "base/messenger.h"
#include "base/sysfunc.h"
#include "base/constants.h"
#include "main.h"
#include <stdarg.h>
#include <stdio.h>

// Singleton
Messenger msg;

// Constructor
Messenger::Messenger()
{
	// Private variables
	callLevel_ = 0;
}

// Standard message
void Messenger::print(const char *fmt ...) const
{
	// Print to the text view in the main window if it has been initialised.
	// If program is in quiet mode, don't print anything to stdout
	// Otherwise, print to stdout. Also print to stdout if debuglevel >= msglevel.
	va_list arguments;
	static char msgs[8096];
	msgs[0] = '\0';
	// Parse the argument list (...) and internally write the output string into msgs[]
	va_start(arguments,fmt);
	vsprintf(msgs,fmt,arguments);
	printf("%s",msgs);
	va_end(arguments);
}

// Standard message in specific output level
void Messenger::debug(const char *fmt ...) const
{
	if (!ac.debugOutput) return;
	// Print to the text view in the main window if it has been initialised.
	// If program is in quiet mode, don't print anything except Messenger::Error calls
	va_list arguments;
	static char msgs[8096];
	msgs[0] = '\0';
	// Parse the argument list (...) and internally write the output string into msgs[]
	va_start(arguments,fmt);
	vsprintf(msgs,fmt,arguments);
	// Print message to stdout, but only if specified output type is active
	printf("%s",msgs);
	va_end(arguments);
}

// Function enter
void Messenger::enter(const char *callname)
{
	if (!ac.debugOutput) return;
	// Debug Messaging - Enter Function
	printf("%2i ",callLevel_);
	for (int n=0; n<callLevel_; n++) printf("--");
	printf("Begin : %s...\n", callname);
	callLevel_ ++;
}

// Function leave
void Messenger::exit(const char *callname)
{
	if (!ac.debugOutput) return;
	// Debug Messaging - Leave Function
	callLevel_ --;
	printf("%2i ", callLevel_);
	for (int n=0; n<callLevel_; n++) printf("--");
	printf("End   : %s.\n", callname);
}
