/*
	*** System functions
	*** src/base/sysfunc.cpp
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

#include "base/constants.h"
#include "base/dnchar.h"
#include "base/messenger.h"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

// Convert string to uppercase
const char *upperCase(const char *s)
{
	static Dnchar result(1024);
	result.clear();
	for (int i = 0; s[i] != '\0'; i++) result += toupper(s[i]);
	return result;
}

// Convert string to lowercase
const char *lowerCase(const char *s)
{
	static Dnchar result(1024);
	result.clear();
	for (int i = 0; s[i] != '\0'; i++) result += tolower(s[i]);
	return result;
}

// Get characters before first occurrence of designated character
const char *beforeChar(const char *s, char delim)
{
	static Dnchar result(1024);
	result.clear();
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == delim) break;
		result += s[i];
	}
	return result;
}

// Get characters after first occurrence of designated character
const char *afterChar(const char *s, char delim)
{
	static Dnchar result(1024);
	result.clear();
	bool found = FALSE;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (found) result += s[i];
		if (s[i] == delim) found = TRUE;
	}
	return result;
}

// Search enum list for text
int enumSearch(const char *name, int maxn, const char **itemlist, const char *query, bool reporterror)
{
	static Dnchar lowerq, lowers;
	int result = maxn, i;
	lowerq = lowerCase(query);
	for (i=0; i<maxn; i++)
	{
		lowers = lowerCase(itemlist[i]);
		if (lowerq == lowers)
		{
			result = i;
			break;
		}
	}
	if ((result == maxn) && (name[0] != '\0') && reporterror) printf("Unrecognised %s '%s'\n",name,query);
	return result;
}

// Print valid enum values
void enumPrintValid(int nitems, const char **list)
{
	msg.print("Valid values are:\n    ");
	for (int i=0; i < nitems; i++)
	{
		if ((strcmp(list[i],"_NULL_") == 0) || (list[i][0] == '_')) continue;
		msg.print("%s ", lowerCase(list[i]));
	}
	msg.print("\n");
}

// Convert the number 'n' to a string representation.
const char *itoa(signed long int n)
{
	static Dnchar result;
	result.sprintf("%li",n);
	return result;
}

// Convert the real number 'f' to a string representation
const char *ftoa(double f)
{
	static Dnchar result;
	result.sprintf("%f",f);
	return result;
}

// Convert the real number 'f' to a string representation with supplied format
const char *ftoa(double f,const char *fmt)
{
	static Dnchar result;
	result.sprintf(fmt,f);
	return result;
}

// Remove comments from line
void removeComments(char *s)
{
	char *c, quotechar = '\0';
	bool escaped = FALSE;
	for (c = s; *c != '\0'; ++c)
	{
		// Remember current quoting info...
		if (*c == '"')
		{
			if (quotechar == '\0') quotechar = '"';
			else if (quotechar == '"') quotechar = '\0';
		}
		if (*c == '\'')
		{
			if (quotechar == '\0') quotechar = '\'';
			else if (quotechar == '\'') quotechar = '\0';
		}
		if ((*c == '#') && (!escaped) && (quotechar == '\0'))
		{
			*c = '\0';
		break;
		}
		else if ((*c == '/') && (!escaped) && (quotechar == '\0'))
		{
			char *c2 = c;
			c2++;
			if (*c2 == '/')
			{
				*c = '\0';
				break;
			}
		}
		escaped = *c == '\\';
	}
}

// Return whether string consists of empty whitespace characters only
bool isEmpty(char *s)
{
	for (char *c = s; *c != '\0'; ++c)
	{
		switch (*c)
		{
			case (' '):
			case ('\t'):
			case ('\n'):
			case ('\r'):
				continue;
			default:
				return FALSE;
		}
	}
	return TRUE;
}

