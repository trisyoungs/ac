/*
	*** Other Commands
	*** src/command/other.cpp
	Copyright T. Youngs 2007-2011

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

#include "parser/commandnode.h"
#include "parser/tree.h"
#include "parser/variablenode.h"
#include "parser/format.h"
#include "base/messenger.h"
#include <cstring>

// Print formatted string
bool Command::function_PrintF(CommandNode *c, ReturnValue &rv)
{
	Format *fmt = c->createFormat(0,1);
	if (fmt == NULL)
	{
		printf("Error - No format defined in 'printf' command.\n");
		return FALSE;
	}
	if (fmt->writeToString()) msg.print("%s",fmt->string());
	return TRUE;
}

