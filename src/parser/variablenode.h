/*
	*** Variable Node
	*** src/parser/variablenode.h
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

#ifndef ATENCALC_VARIABLENODE_H
#define ATENCALC_VARIABLENODE_H

#include "parser/treenode.h"

// Forward Declarations
class Variable;

// Variable Node
class VariableNode : public TreeNode
{
	public:
	// Constructor / Destructor
	VariableNode(Variable *v = NULL);
	~VariableNode();

	/*
	// Variable Data
	*/
	private:
	// Variable that this node links to
	Variable* variable_;
	// Array index (if any)
	TreeNode *arrayIndex_;
	
	public:
	// Set variable target
	void setVariable(Variable *v);
	// Get variable target
	Variable* variable();
	// Set array index
	void setArrayIndex(TreeNode *index);
	// Return array index
	TreeNode *arrayIndex();	
	// Return name of variable target
	const char *name();
	// Finalise variable path (if there is one)
	void finalisePath();

	/*
	// Inherited Virtuals
	*/
	public:
	// Execute node
	bool execute(ReturnValue &rv);
	// Print node contents
	void nodePrint(int offset, const char *prefix = "");
	// Set from returnvalue node
	bool set(ReturnValue &rv);
	// Initialise node
	bool initialise();
	// Search accessors (if any) available for linked variable
	StepNode *findAccessor(const char *s, TreeNode *arrayindex, TreeNode *arglist = NULL);
};

#endif
