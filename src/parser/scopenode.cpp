/*
	*** Scoped Command Node
	*** src/parser/scopenode.cpp
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

#include "parser/scopenode.h"
#include <string.h>

// Constructor
ScopeNode::ScopeNode(Command::Function func) : CommandNode(func)
{
	// Private variables
	nodeType_ = TreeNode::ScopedNode;
}

// Destructor
ScopeNode::~ScopeNode()
{
}

// Execute command
bool ScopeNode::execute(ReturnValue &rv)
{
	// Execute the command
	return commands.call(function_, this, rv);
}

// Set from returnvalue node
bool ScopeNode::set(ReturnValue &rv)
{
	printf("Internal Error: Trying to 'set' a ScopeNode.\n");
	return FALSE;
}

// Initialise node
bool ScopeNode::initialise()
{
	printf("Internal Error: A ScopeNode cannot be initialised.\n");
	return FALSE;
}

// Print node contents
void ScopeNode::nodePrint(int offset, const char *prefix)
{
	// Construct tabbed offset
	Dnchar tab(offset+32);
	for (int n=0; n<offset-1; n++) tab += '\t';
	if (offset > 1) tab.strcat("   |--> ");
	tab.strcat(prefix);

	// Output node data
	printf("[SN]%s (Scoped Node) (%i variables)\n", tab.get(), variables.nVariables());
	int n = 1;
	for (TreeNode *tn = variables.variables(); tn != NULL; tn = tn->next)
	{
		Variable *v = (Variable*) tn;
		printf("%s --> %3i: %s (%s)\n", tab.get(), n++, v->name(), VTypes::dataType(v->returnType()));
		if (v->initialValue() != NULL) v->initialValue()->nodePrint(offset+1, "init: ");
	}
	printf("[SN]%s%s (Command) (%i arguments)\n", tab.get(), Command::data[function_].keyword, args_.nItems());
	// Output Argument data
	for (Refitem<TreeNode,int> *ri = args_.first(); ri != NULL; ri = ri->next) ri->item->nodePrint(offset+1);
}
