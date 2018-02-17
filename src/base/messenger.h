/*
	*** Messaging routines
	*** src/base/messenger.h
	Copyright T. Youngs 2010-2011

	This file is part of AtenCalc.

	Aten is free software: you can redistribute it and/or modify
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

#ifndef ATENCALC_MESSENGER_H
#define ATENCALC_MESSENGER_H

// Global messaging and program output levels
class Messenger
{
	public:
	// Constructor
	Messenger();

	/*
	// Output Modes
	*/
	private:
	// Call level, used to provide indent for enter/exit info
	int callLevel_;

	/*
	// Messaging functions
	*/
	public:
	// Print normal message
	void print(const char* ...) const;
	// Print message in specific output level
	void debug(const char* ...) const;
	// Entrances / exits to / from subroutines
	void enter(const char *callname);
	void exit(const char *callname);
};

extern Messenger msg;

#endif
