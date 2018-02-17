noinst_LIBRARIES = libparser.a

BUILT_SOURCES = grammar.h
AM_YFLAGS = -d

libparser_a_SOURCES = character.cpp commandnode.cpp double.cpp format.cpp grammar.yy integer.cpp parser.cpp parser_lexer.cpp parser_tree.cpp program.cpp returnvalue.cpp scopenode.cpp stepnode.cpp tree.cpp tree_opcheck.cpp treenode.cpp usercommandnode.cpp variable.cpp variablelist.cpp variablenode.cpp vector.cpp vtypes.cpp

noinst_HEADERS = accessor.h character.h commandnode.h double.h format.h integer.h parser.h program.h returnvalue.h scopenode.h stepnode.h tree.h treenode.h usercommandnode.h variable.h variablelist.h variablenode.h vector.h vtypes.h 

INCLUDES = -I$(top_srcdir)/src -I../ 
