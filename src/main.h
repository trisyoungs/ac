/*
	*** AtenCalc Main
	*** src/main.h
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

#ifndef ATENCALC_H
#define ATENCALC_H

// AtenCalc
class AtenCalc
{
	public:
	// Constructor
	AtenCalc();

	/*
	// Program Options
	*/
	public:
	// Whether debug output is enabled
	bool debugOutput;
	// Whether to exit immediately after processing arguments (if any were provided)
	bool exitAfterArguments;
	// Whether to abort on first encountered error
	bool abortOnError;
	// Whether to recognise certain symbolic constants in input
	bool useConstants;
};

// Global Declaration
extern AtenCalc ac;

#endif
