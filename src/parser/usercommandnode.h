/*
	*** User-Defined Command Node
	*** src/parser/usercommandnode.h
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

#ifndef ATENCALC_USERCOMMANDNODE_H
#define ATENCALC_USERCOMMANDNODE_H

#include "templates/reflist.h"
#include "templates/list.h"
#include "templates/vector3.h"
#include "command/commands.h"
#include "parser/treenode.h"
#include "parser/returnvalue.h"

// Forward Declarations
class Tree;

// User Command Node
class UserCommandNode : public TreeNode
{
	public:
	// Constructor / Destructor
	UserCommandNode(Tree *func);
	~UserCommandNode();

	/*
	// Command Data
	*/
	protected:
	// Pointer to Tree containing the user-defined function
	Tree *function_;
	
	public:
	// Check validity of supplied arguments
	bool checkArguments();
	// Execute command
	bool execute(ReturnValue &rv);
	// Print node contents
	void nodePrint(int offset, const char *prefix = "");
	// Set from returnvalue node
	bool set(ReturnValue &rv);
	// Initialise node
	bool initialise();
	// Create, run, and free a single function with simple arguments
	static bool run(Tree *func, ReturnValue &rv, const char *arglist ...);
	static bool run(Tree *func, ReturnValue &rv, TreeNode *arglisthead);
};

#endif
