/*
	*** Program
	*** src/parser/program.h
	Copyright T. Youngs 2007-2011

	This file is part of Aten.

	Aten is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Aten is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Aten.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ATEN_FOREST_H
#define ATEN_FOREST_H

#include "base/dnchar.h"
#include "parser/tree.h"

// Program
class Program
{
	public:
	// Constructors / Destructor
	Program();
	~Program();
	// List pointers
	Program *prev, *next;


	/*
	// Tree data
	*/
	private:
	// Name, if any
	Dnchar name_;
	// Original source filename, if any
	Dnchar filename_;
	// Main program
	Tree mainProgram_;
	// User-defined global functions (but local to this program)
	List<Tree> functions_;
	// Whether or not a tree was pushed initially
	bool initialPushTree_;

	public:
	// Clear contents of program, including functions
	void clear();
	// Set name of program
	void setName(const char *s);
	// Return name of program
	const char *name();
	// Return associated filename (if any)
	const char *filename();
	// Generate program from string 
	bool generateFromString(const char *s, const char *name = NULL, bool dontpushtree = FALSE);
	// Generate program from string list
	bool generateFromStringList(Dnchar *stringListHead, const char *name = NULL, bool dontpushtree = FALSE);
	// Return main program
	Tree *mainProgram();
	// Add a new Program-global function tree
	Tree *addGlobalFunction(const char *name);
	// Search for existing global function
	Tree *findGlobalFunction(const char *s);
	// Return first defined global function
	Tree *globalFunctions();
	// Execute specified global function
	bool executeGlobalFunction(const char *name, ReturnValue &rv, const char *arglist ...);
	// Delete specified tree
	void deleteTree(Tree *t);
	// Execute main program
	int execute(ReturnValue& rv);
	// Print program information
	void print();
};

#endif
