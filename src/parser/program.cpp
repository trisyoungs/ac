/*
	*** Program
	*** src/parser/forest.cpp
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

#include "parser/parser.h"
#include "parser/program.h"
#include "parser/usercommandnode.h"
#include "parser/integer.h"
#include "parser/double.h"
#include "parser/character.h"
#include "base/sysfunc.h"
#include "base/messenger.h"
#include <string.h>
#include <stdarg.h>

// Constructors
Program::Program()
{
	// Private variables
	name_ = "NewProgram";
	initialPushTree_ = FALSE;
	mainProgram_.setParent(this);
	
	// Public variables
	prev = NULL;
	next = NULL;
}

// Destructor
Program::~Program()
{
}

// Clear forest
void Program::clear()
{
	functions_.clear();
}

// Set name of forest
void Program::setName(const char *s)
{
	name_ = s;
}

// Return name of forest
const char *Program::name()
{
	return name_.get();
}

// Return filename of source file
const char *Program::filename()
{
	return filename_.get();
}

// Return main program
Tree *Program::mainProgram()
{
	return &mainProgram_;
}

// Add a Program-global function
Tree *Program::addGlobalFunction(const char *name)
{
	Tree *tree = functions_.add();
	tree->setName(name);
	tree->setType(Tree::FunctionTree);
	tree->setParent(this);
	return tree;
}

// Search for existing global function
Tree *Program::findGlobalFunction(const char *name)
{
	Tree *result;
	for (result = functions_.first(); result != NULL; result = result->next) if (strcmp(result->name(),name) == 0) break;
	return result;
}

// Return first defined global function...
Tree *Program::globalFunctions()
{
	return functions_.first();
}

// Execute specified global function
bool Program::executeGlobalFunction(const char *funcname, ReturnValue &rv, const char *arglist ...)
{
	msg.enter("Program::executeGlobalFunction");
	// First, locate funciton with the name supplied
	Tree *func = findGlobalFunction(funcname);
	if (func == NULL)
	{
		printf("Error: No global function named '%s' exists in '%s'.\n", funcname, name_.get());
		msg.exit("Program::executeGlobalFunction");
		return FALSE;
	}

	// Construct list of arguments to pass to function
	va_list vars;
	va_start(vars, arglist);
	List<TreeNode> args;
	TreeNode *var;
	for (const char *c = &arglist[0]; *c != '\0'; c++)
	{
		switch (*c)
		{
			case ('i'):
				var = new IntegerVariable(va_arg(vars, int), TRUE);
				break;
			case ('d'):
				var = new DoubleVariable(va_arg(vars, double), TRUE);
				break;
			case ('c'):
			case ('s'):
				var = new StringVariable(va_arg(vars, const char *), TRUE);
				break;
			default:
				printf("Invalid argument specifier '%c' in Program::executeGlobalFunctin.\n", *c);
				var = NULL;
				break;
		}
		args.own(var);
	}
	va_end(vars);

	// Now, pass all the info on to the static 'run' command in UserCommandNode
	bool success = UserCommandNode::run(func,rv,args.first());

	msg.exit("Program::executeGlobalFunction");
	return success;
}

// Generate forest from string 
bool Program::generateFromString(const char *s, const char *name, bool dontpushtree)
{
	msg.enter("Program::generateFromString");
	name_ = name;
	initialPushTree_ = dontpushtree;
	bool result = cmdparser.generateFromString(this, s, initialPushTree_);
	msg.exit("Program::generateFromString");
	return result;
}

// Generate forest from string list
bool Program::generateFromStringList(Dnchar *stringListHead, const char *name, bool dontpushtree)
{
	msg.enter("Program::generateFromStringList");
	name_ = name;
	initialPushTree_ = dontpushtree;
	bool result = cmdparser.generateFromStringList(this, stringListHead, initialPushTree_);
	msg.exit("Program::generateFromStringList");
	return result;
}

// Delete specified tree
void Program::deleteTree(Tree *t)
{
	if (t == NULL) return;
	// Search for the specified tree...
	if (functions_.contains(t)) functions_.remove(t);
	else printf("Internal Error: Tree to be deleted is not owned by the current parent structure.\n");
}

// Execute all trees in forest
int Program::execute(ReturnValue &rv)
{
	msg.enter("Program::execute");
	int result = mainProgram_.execute(rv);
	msg.exit("Program::execute");
	return result;
}

// Print forest information
void Program::print()
{
	printf("Program '%s':\nContains: %i functions.\n", name_.get(), functions_.nItems());
	if (functions_.nItems() > 0) printf("  Functions:\n");
	for (int n=0; n<functions_.nItems(); ++n) printf("     %-3i  %s\n", n+1, functions_[n]->name());
}

