/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTCONST = 258,
     DOUBLECONST = 259,
     NEWTOKEN = 260,
     CHARCONST = 261,
     STEPTOKEN = 262,
     VAR = 263,
     LOCALVAR = 264,
     FUNCCALL = 265,
     USERFUNCCALL = 266,
     VTYPE = 267,
     ATENCALC_DO = 268,
     ATENCALC_WHILE = 269,
     ATENCALC_FOR = 270,
     ATENCALC_SWITCH = 271,
     ATENCALC_CASE = 272,
     ATENCALC_DEFAULT = 273,
     ATENCALC_IF = 274,
     ATENCALC_RETURN = 275,
     ATENCALC_VOID = 276,
     ATENCALC_CONTINUE = 277,
     ATENCALC_BREAK = 278,
     ATENCALC_QUIT = 279,
     ATENCALC_ELSE = 280,
     OR = 281,
     AND = 282,
     DEQ = 283,
     TEQ = 284,
     MEQ = 285,
     PEQ = 286,
     NEQ = 287,
     EQ = 288,
     LEQ = 289,
     GEQ = 290,
     UMINUS = 291,
     MINUSMINUS = 292,
     PLUSPLUS = 293
   };
#endif
/* Tokens.  */
#define INTCONST 258
#define DOUBLECONST 259
#define NEWTOKEN 260
#define CHARCONST 261
#define STEPTOKEN 262
#define VAR 263
#define LOCALVAR 264
#define FUNCCALL 265
#define USERFUNCCALL 266
#define VTYPE 267
#define ATENCALC_DO 268
#define ATENCALC_WHILE 269
#define ATENCALC_FOR 270
#define ATENCALC_SWITCH 271
#define ATENCALC_CASE 272
#define ATENCALC_DEFAULT 273
#define ATENCALC_IF 274
#define ATENCALC_RETURN 275
#define ATENCALC_VOID 276
#define ATENCALC_CONTINUE 277
#define ATENCALC_BREAK 278
#define ATENCALC_QUIT 279
#define ATENCALC_ELSE 280
#define OR 281
#define AND 282
#define DEQ 283
#define TEQ 284
#define MEQ 285
#define PEQ 286
#define NEQ 287
#define EQ 288
#define LEQ 289
#define GEQ 290
#define UMINUS 291
#define MINUSMINUS 292
#define PLUSPLUS 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 31 "grammar.yy"

	int functionId;			/* Function enum id */
	Dnchar *name;			/* character pointer for names */
	TreeNode *node;			/* node pointer */
	Variable *variable;		/* variable pointer */
	Tree *tree;			/* function (tree) pointer */
	VTypes::DataType vtype;		/* variable type for next declarations */
	signed long int intconst;	/* integer constant value */
	double doubleconst;		/* double constant value */



/* Line 2068 of yacc.c  */
#line 139 "grammar.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE CommandParser_lval;


