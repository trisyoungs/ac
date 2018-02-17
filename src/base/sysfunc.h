/*
	*** System functions
	*** src/base/sysfunc.h
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

#ifndef ATEN_SYSFUNC_H
#define ATEN_SYSFUNC_H

// Number/string conversion
const char *itoa(signed long int);
const char *ftoa(double);
const char *ftoa(double, const char*);

// String functions
const char *upperCase(const char*);
const char *lowerCase(const char*);
const char *beforeChar(const char*, char);
const char *afterChar(const char*, char);
void removeComments(char *s);
bool isEmpty(char *s);

// Enum search and print
int enumSearch(const char *name, int nitems, const char **list, const char *query, bool reporterror = 1);
void enumPrintValid(int nitems, const char **list);

#endif
