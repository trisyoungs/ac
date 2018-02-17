/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         CommandParser_parse
#define yylex           CommandParser_lex
#define yyerror         CommandParser_error
#define yylval          CommandParser_lval
#define yychar          CommandParser_char
#define yydebug         CommandParser_debug
#define yynerrs         CommandParser_nerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 4 "grammar.yy"


/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "command/commands.h"
#include "parser/parser.h"
#include "parser/tree.h"
#include "base/messenger.h"

/* Prototypes */
int CommandParser_lex(void);
void CommandParser_error(char *s);

/* Local Variables */
Dnchar tokenName;
List<Dnchar> stepNameStack;
VTypes::DataType declaredType, funcType;
TreeNode *tempNode;



/* Line 268 of yacc.c  */
#line 103 "grammar.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
#line 31 "grammar.yy"

	int functionId;			/* Function enum id */
	Dnchar *name;			/* character pointer for names */
	TreeNode *node;			/* node pointer */
	Variable *variable;		/* variable pointer */
	Tree *tree;			/* function (tree) pointer */
	VTypes::DataType vtype;		/* variable type for next declarations */
	signed long int intconst;	/* integer constant value */
	double doubleconst;		/* double constant value */



/* Line 293 of yacc.c  */
#line 228 "grammar.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 240 "grammar.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNRULES -- Number of states.  */
#define YYNSTATES  262

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,    43,     2,     2,
      51,    52,    41,    39,    56,    40,    53,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    57,
      34,    28,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    29,    30,    31,    32,    35,    36,    37,
      38,    44,    45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      24,    30,    35,    38,    40,    44,    47,    52,    54,    59,
      61,    62,    67,    70,    74,    79,    82,    86,    91,    94,
      98,   102,   106,   110,   112,   114,   116,   120,   124,   128,
     132,   135,   138,   141,   144,   147,   149,   153,   157,   161,
     165,   169,   173,   177,   181,   185,   189,   193,   197,   201,
     205,   209,   212,   214,   216,   220,   223,   225,   227,   229,
     231,   233,   235,   238,   242,   249,   256,   260,   262,   267,
     269,   271,   275,   278,   282,   288,   290,   294,   297,   301,
     305,   313,   314,   324,   332,   333,   343,   345,   348,   351,
     354,   357,   360,   363,   365,   367,   371,   374,   377,   380,
     383,   385,   388,   394,   397,   399,   401,   409,   415,   426,
     437,   444,   453,   454,   463,   469,   472,   474,   477,   480,
     481,   482,   483,   484,   485,   486
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    -1,    60,    61,    -1,    85,    -1,
      86,    -1,     3,    -1,     4,    -1,     6,    -1,     7,    97,
      49,    71,    50,    -1,     7,    97,    51,    72,    52,    -1,
       7,    97,    51,    52,    -1,     7,    97,    -1,    63,    -1,
      64,    53,    63,    -1,    64,     1,    -1,     8,    49,    71,
      50,    -1,     8,    -1,     9,    49,    71,    50,    -1,     9,
      -1,    -1,    65,    53,    66,    64,    -1,    65,    51,    -1,
      10,    51,    52,    -1,    10,    51,    72,    52,    -1,    10,
       1,    -1,    11,    51,    52,    -1,    11,    51,    72,    52,
      -1,    11,     1,    -1,    54,    72,    55,    -1,    65,    28,
      71,    -1,    65,    28,    69,    -1,    65,    28,     1,    -1,
      62,    -1,    67,    -1,    68,    -1,    65,    32,    71,    -1,
      65,    31,    71,    -1,    65,    30,    71,    -1,    65,    29,
      71,    -1,    40,    71,    -1,    65,    46,    -1,    65,    45,
      -1,    46,    65,    -1,    45,    65,    -1,    65,    -1,    71,
      39,    71,    -1,    71,    40,    71,    -1,    71,    41,    71,
      -1,    71,    42,    71,    -1,    71,    48,    71,    -1,    71,
      43,    71,    -1,    71,    36,    71,    -1,    71,    35,    71,
      -1,    71,    33,    71,    -1,    71,    38,    71,    -1,    71,
      34,    71,    -1,    71,    37,    71,    -1,    71,    27,    71,
      -1,    71,    26,    71,    -1,    51,    71,    52,    -1,    47,
      71,    -1,     5,    -1,    71,    -1,    72,    56,    71,    -1,
      72,    71,    -1,     8,    -1,    10,    -1,     9,    -1,    62,
      -1,    11,    -1,    12,    -1,     5,    92,    -1,    73,    28,
      69,    -1,    73,    49,    71,    50,    28,    71,    -1,    73,
      49,    71,    50,    28,    69,    -1,    73,    28,    71,    -1,
      73,    -1,    73,    49,    71,    50,    -1,    74,    -1,    75,
      -1,    76,    56,    75,    -1,    76,    75,    -1,    12,    93,
      73,    -1,    12,    93,    73,    28,    71,    -1,    77,    -1,
      78,    56,    77,    -1,    78,    77,    -1,    12,    93,    76,
      -1,    12,    93,     1,    -1,    21,    94,     5,    98,    51,
      52,    86,    -1,    -1,    21,    94,     5,    98,    51,    78,
      52,    81,    86,    -1,    12,    93,     5,    98,    51,    52,
      86,    -1,    -1,    12,    93,     5,    98,    51,    78,    52,
      82,    86,    -1,    57,    -1,    83,    57,    -1,    70,    83,
      -1,    79,    83,    -1,    71,    83,    -1,    67,    83,    -1,
      68,    83,    -1,    88,    -1,    80,    -1,    20,    71,    83,
      -1,    20,    83,    -1,    22,    83,    -1,    23,    83,    -1,
      24,    83,    -1,    84,    -1,    85,    84,    -1,    54,    95,
      85,    55,    96,    -1,    54,    55,    -1,    84,    -1,    86,
      -1,    19,    51,    71,    52,    87,    25,    87,    -1,    19,
      51,    71,    52,    87,    -1,    15,    95,    51,    70,    57,
      71,    57,    71,    52,    87,    -1,    15,    95,    51,    79,
      57,    71,    57,    71,    52,    87,    -1,    14,    95,    51,
      71,    52,    87,    -1,    13,    95,    86,    14,    51,    71,
      52,    57,    -1,    -1,    16,    51,    71,    52,    89,    54,
      91,    55,    -1,    17,    51,    71,    52,    58,    -1,    18,
      58,    -1,    90,    -1,    91,    85,    -1,    91,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    78,    83,    86,    96,    97,    98,   107,
     111,   115,   119,   127,   128,   129,   134,   138,   142,   146,
     150,   150,   155,   166,   170,   174,   182,   186,   190,   202,
     212,   213,   214,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   253,   257,   260,   272,   277,   282,   287,
     292,   297,   302,   311,   315,   319,   323,   331,   335,   339,
     346,   349,   352,   360,   364,   372,   375,   378,   386,   391,
     403,   409,   409,   417,   423,   423,   439,   440,   445,   448,
     451,   454,   457,   460,   463,   466,   469,   472,   475,   478,
     485,   488,   496,   499,   506,   509,   516,   519,   522,   525,
     528,   532,   536,   536,   550,   559,   566,   569,   572,   582,
     586,   590,   594,   598,   602,   606
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONST", "DOUBLECONST", "NEWTOKEN",
  "CHARCONST", "STEPTOKEN", "VAR", "LOCALVAR", "FUNCCALL", "USERFUNCCALL",
  "VTYPE", "ATENCALC_DO", "ATENCALC_WHILE", "ATENCALC_FOR",
  "ATENCALC_SWITCH", "ATENCALC_CASE", "ATENCALC_DEFAULT", "ATENCALC_IF",
  "ATENCALC_RETURN", "ATENCALC_VOID", "ATENCALC_CONTINUE",
  "ATENCALC_BREAK", "ATENCALC_QUIT", "ATENCALC_ELSE", "OR", "AND", "'='",
  "DEQ", "TEQ", "MEQ", "PEQ", "'>'", "'<'", "NEQ", "EQ", "LEQ", "GEQ",
  "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "MINUSMINUS", "PLUSPLUS",
  "'!'", "'^'", "'['", "']'", "'('", "')'", "'.'", "'{'", "'}'", "','",
  "';'", "':'", "$accept", "programlist", "program", "constant", "step",
  "steplist", "variable", "$@1", "function", "userfunction", "ARRAYCONST",
  "assignment", "expression", "expressionlist", "variablename",
  "assignedvariablename", "variablelistitem", "variablelist",
  "typedvariablelistitem", "typedvariablelist", "declaration",
  "functiondeclaration", "$@2", "$@3", "delim", "statement",
  "statementlist", "block", "blockment", "flowstatement", "$@4",
  "caselabel", "caselist", "savetokenname", "savetype", "cleartype",
  "pushscope", "popscope", "pushstepname", "pushfunc", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    61,   283,
     284,   285,   286,    62,    60,   287,   288,   289,   290,    43,
      45,    42,    47,    37,   291,   292,   293,    33,    94,    91,
      93,    40,    41,    46,   123,   125,    44,    59,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    65,
      66,    65,    65,    67,    67,    67,    68,    68,    68,    69,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    77,    77,    78,    78,    78,    79,    79,
      80,    81,    80,    80,    82,    80,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    89,    88,    90,    90,    91,    91,    91,    92,
      93,    94,    95,    96,    97,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     5,
       5,     4,     2,     1,     3,     2,     4,     1,     4,     1,
       0,     4,     2,     3,     4,     2,     3,     4,     2,     3,
       3,     3,     3,     1,     1,     1,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     2,     3,     6,     6,     3,     1,     4,     1,
       1,     3,     2,     3,     5,     1,     3,     2,     3,     3,
       7,     0,     9,     7,     0,     9,     1,     2,     2,     2,
       2,     2,     2,     1,     1,     3,     2,     2,     2,     2,
       1,     2,     5,     2,     1,     1,     7,     5,    10,    10,
       6,     8,     0,     8,     5,     2,     1,     2,     2,     0,
       0,     0,     0,     0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     7,    62,     8,    17,    19,     0,     0,   130,
     132,   132,   132,     0,     0,     0,   131,     0,     0,     0,
       0,     0,     0,     0,     0,   132,     0,     2,    33,    45,
      34,    35,     0,     0,     0,   104,   110,     4,     5,   103,
       0,     0,    25,     0,    28,     0,     0,     0,     0,     0,
       0,     0,    96,    45,    34,    35,     0,   106,     0,   107,
     108,   109,    40,    44,    43,    61,     0,   113,     0,     1,
       3,     0,     0,     0,     0,     0,    42,    41,    22,    20,
     101,   102,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,    99,   111,
       0,     0,    23,    63,     0,    26,     0,    89,   129,    66,
      68,    67,    70,    71,    69,    77,    79,    80,    88,     0,
       0,     0,     0,     0,   105,    97,   135,    60,     0,    32,
       0,    31,    30,    39,    38,    37,    36,     0,    59,    58,
      54,    56,    53,    52,    57,    55,    46,    47,    48,    49,
      51,    50,    16,    18,    24,     0,    65,    27,    72,     0,
       0,     0,   129,     0,    82,     0,     0,   130,     0,     0,
       0,   122,     0,     0,   133,     0,   134,    13,     0,    64,
       0,    73,    76,     0,    81,     0,     0,     0,     0,     0,
       0,   114,   115,   117,     0,   112,    29,    12,    15,     0,
     130,     0,    85,     0,    78,     0,   120,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,    93,    94,     0,
      87,     0,     0,     0,     0,     0,     0,   126,     0,   116,
      90,    91,     0,    11,     0,    83,     0,    86,    75,    74,
     121,     0,     0,     0,   125,   123,   127,   128,     0,     9,
      10,     0,    95,     0,     0,     0,    92,    84,   118,   119,
       0,   124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,   177,   178,    53,   137,    54,    55,
     131,    32,    33,   104,   115,   116,   117,   118,   202,   203,
      34,    35,   248,   236,    57,   191,    37,   192,   193,    39,
     190,   227,   228,   158,    46,    58,    47,   195,   197,   159
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -178
static const yytype_int16 yypact[] =
{
     621,  -178,  -178,  -178,  -178,   -26,   -15,     6,     7,  -178,
    -178,  -178,  -178,    22,    27,     9,  -178,    10,    10,    10,
     421,    77,    77,   421,   421,    26,    94,  -178,  -178,   565,
      10,    10,    10,   380,    10,  -178,  -178,   754,  -178,  -178,
     421,   421,  -178,   676,  -178,   695,   778,    41,    50,    76,
     421,   421,  -178,   237,  -178,  -178,   380,    80,   128,    80,
      80,    80,    95,    39,    39,    95,   826,  -178,   754,  -178,
    -178,    42,   421,   421,   421,   421,  -178,  -178,  -178,  -178,
      80,    80,    80,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,    80,    80,  -178,
     986,  1004,  -178,  1058,   147,  -178,   326,  -178,    91,  -178,
    -178,  -178,  -178,  -178,  -178,    34,  -178,  -178,   269,   132,
     421,    23,   846,   866,    80,  -178,  -178,  -178,   568,  -178,
     421,  -178,  1058,   322,   322,   322,   322,   140,   322,   322,
     121,   121,   121,   121,   121,   121,   154,   154,    95,    95,
      95,    95,  -178,  -178,  -178,   421,  1058,  -178,  -178,    98,
     643,   421,  -178,   595,  -178,   103,   886,  -178,     8,   102,
     113,  -178,   621,   120,  -178,   343,  -178,  -178,   447,  1058,
      12,  -178,  1058,  1022,  -178,   421,   621,  1104,   421,   421,
     123,  -178,  -178,   153,    13,  -178,  -178,    75,  -178,   140,
    -178,    41,  -178,    28,   156,   906,  -178,   776,   801,   118,
     621,    41,    67,   421,   704,  -178,   595,  -178,  -178,   173,
    -178,   643,   134,   421,   421,   138,   142,  -178,   515,  -178,
    -178,  -178,  1040,  -178,   502,   176,    41,  -178,  -178,  1058,
    -178,   926,   946,   421,  -178,  -178,   754,  -178,    41,  -178,
    -178,   421,  -178,   621,   621,   966,  -178,  1058,  -178,  -178,
     143,  -178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,   180,   -43,    14,  -178,     0,  -178,     2,     4,
    -150,    86,   220,   -39,    -8,  -178,   -89,  -178,   -81,    15,
      90,  -178,  -178,  -178,   149,     1,   -63,    16,  -177,  -178,
    -178,   -13,  -178,  -178,  -156,  -178,   100,  -178,  -178,    92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -136
static const yytype_int16 yytable[] =
{
      29,    36,    30,   114,    31,   128,   106,    42,    44,   206,
     181,   187,     1,     2,     3,     4,    38,     5,     6,     7,
       8,    63,    64,    40,   200,   200,    29,    36,    30,   164,
      31,     5,     6,   229,    41,   167,    71,    29,    99,    30,
     200,    31,    38,   129,   216,     1,     2,     3,     4,    20,
       5,     6,     7,     8,    21,    22,    23,    43,    45,    78,
      24,    79,   160,   119,   201,   211,    52,    52,    29,    36,
      30,   238,    31,    50,   184,   114,   258,   259,    51,   200,
     218,    67,    20,   161,   219,     5,     6,    21,    22,    23,
      78,   175,    79,    24,    69,    25,   130,     1,     2,     3,
       4,   120,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    48,    49,    14,    15,    16,    17,    18,    19,   231,
     114,   168,   220,   219,   213,    68,   214,   121,    29,    99,
      30,   220,    31,   126,    20,   225,   226,   125,   237,    21,
      22,    23,  -135,    96,   114,    24,   165,   176,    25,   180,
       1,     2,     3,     4,   185,     5,     6,     7,     8,   188,
      91,    92,    93,    94,    95,   246,    59,    60,    61,    96,
     189,   194,    29,   114,    30,   234,    31,   209,   210,    80,
      81,    82,    97,    98,   221,   200,    29,    20,    30,   243,
      31,   240,    21,    22,    23,    93,    94,    95,    24,   154,
     244,   261,    96,   155,   251,   124,    70,   169,   235,   212,
      29,   170,    30,   215,    31,   247,     0,   217,   173,     0,
       0,     0,     0,     0,     0,     0,     0,   230,    29,    36,
      30,     0,    31,     0,     0,    56,     0,     0,     0,     0,
      62,     0,     0,    65,    66,     0,    29,    99,    30,     0,
      31,     0,   252,    29,    29,    30,    30,    31,    31,     0,
     100,   101,     0,   103,   256,   103,    72,    73,    74,    75,
     122,   123,     1,     2,   162,     4,     0,   109,   110,   111,
     112,   113,    76,    77,     0,     0,     0,     0,    78,     0,
      79,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,     0,
       0,     0,     0,     0,   156,   163,   156,     0,     0,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
     166,     0,     0,     0,     0,     0,     1,     2,     3,     4,
     103,     5,     6,     7,     8,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    20,     0,     0,     0,
      96,    21,    22,    23,     0,   179,     0,    24,   157,     0,
     182,   183,   155,    20,     0,     0,     0,     0,    21,    22,
      23,     0,     0,     0,    24,   156,     0,     0,   196,   155,
       0,     0,     0,     0,     0,   205,    83,    84,   207,   208,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     1,     2,     3,     4,    96,     5,
       6,     7,     8,   232,   103,     0,     0,    52,     0,     0,
       0,   239,     0,   241,   242,     0,     0,     0,   198,     0,
     -21,   -21,   -21,   -21,   156,   -21,   -21,   -21,   -21,   -21,
       0,    20,     0,   255,     0,     0,    21,    22,    23,     0,
       0,   257,    24,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,     0,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,
     199,     0,   -21,   -21,   -21,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,   225,   226,    14,    15,    16,    17,    18,    19,
       0,     0,    20,     0,     0,     0,     0,    21,    22,    23,
       0,     0,     0,    24,   250,    20,     0,     0,   155,     0,
      21,    22,    23,     0,     0,     0,    24,     0,     0,     0,
     245,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    15,    16,
      17,    18,    19,    71,    72,    73,    74,    75,     1,     2,
     162,     4,     0,   109,   110,   111,   112,   113,    20,     0,
      76,    77,     0,    21,    22,    23,    78,     0,    79,    24,
       0,     0,     0,   174,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    15,    16,    17,    18,    19,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    21,    22,    23,     0,
       0,     0,    24,     0,     0,    25,     0,     0,     0,     1,
       2,     3,     4,    20,     5,     6,     7,     8,    21,    22,
      23,     0,     0,     0,    24,     0,     0,   130,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     1,     2,     3,
       4,     0,     5,     6,     7,     8,    20,     0,     0,     0,
       0,    21,    22,    23,     0,     0,     0,    24,   102,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,    22,    23,     0,    20,     0,    24,   105,     0,    21,
      22,    23,     0,     0,     0,    24,   233,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,    14,    15,    16,    17,    18,    19,   107,
       0,     1,     2,   108,     4,     0,   109,   110,   111,   112,
     113,     0,     0,     0,    20,     0,     0,     0,     0,    21,
      22,    23,    83,    84,     0,    24,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,    96,     0,     0,    83,    84,     0,
       0,     0,     0,   223,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,    96,
       0,     0,    83,    84,     0,     0,     0,     0,   224,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,    83,    84,    96,     0,     0,     0,   127,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,    83,    84,    96,     0,     0,     0,   171,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,    83,    84,    96,     0,     0,     0,   172,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,    83,    84,    96,     0,     0,     0,   186,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,    83,    84,    96,     0,     0,     0,   222,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,    83,    84,    96,     0,     0,     0,   253,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,    83,    84,    96,     0,     0,     0,   254,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,    83,    84,    96,     0,     0,     0,   260,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      83,    84,     0,     0,    96,     0,   152,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    83,    84,
       0,     0,    96,     0,   153,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    83,    84,     0,     0,
      96,     0,   204,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    83,    84,     0,     0,    96,     0,
     249,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,   107,    96,     1,     2,   162,
       4,     0,   109,   110,   111,   112,   113
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-178))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,     0,     0,    46,     0,    68,    45,     1,     1,   186,
     160,   167,     3,     4,     5,     6,     0,     8,     9,    10,
      11,    21,    22,    49,    12,    12,    26,    26,    26,   118,
      26,     8,     9,   210,    49,    12,    28,    37,    37,    37,
      12,    37,    26,     1,   200,     3,     4,     5,     6,    40,
       8,     9,    10,    11,    45,    46,    47,    51,    51,    51,
      51,    53,    28,    47,    52,    52,    57,    57,    68,    68,
      68,   221,    68,    51,   163,   118,   253,   254,    51,    12,
      52,    55,    40,    49,    56,     8,     9,    45,    46,    47,
      51,   130,    53,    51,     0,    54,    54,     3,     4,     5,
       6,    51,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    11,    12,    19,    20,    21,    22,    23,    24,    52,
     163,   121,   203,    56,    49,    25,    51,    51,   128,   128,
     128,   212,   128,     5,    40,    17,    18,    57,   219,    45,
      46,    47,    51,    48,   187,    51,    14,     7,    54,    51,
       3,     4,     5,     6,    51,     8,     9,    10,    11,    57,
      39,    40,    41,    42,    43,   228,    17,    18,    19,    48,
      57,    51,   172,   216,   172,   214,   172,    54,    25,    30,
      31,    32,    33,    34,    28,    12,   186,    40,   186,    51,
     186,    57,    45,    46,    47,    41,    42,    43,    51,    52,
      58,    58,    48,    56,    28,    56,    26,   121,   216,   194,
     210,   121,   210,   199,   210,   228,    -1,   201,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,   228,   228,
     228,    -1,   228,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    23,    24,    -1,   246,   246,   246,    -1,
     246,    -1,   236,   253,   254,   253,   254,   253,   254,    -1,
      40,    41,    -1,    43,   248,    45,    29,    30,    31,    32,
      50,    51,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    56,   106,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
     130,     8,     9,    10,    11,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    40,    -1,    -1,    -1,
      48,    45,    46,    47,    -1,   155,    -1,    51,    52,    -1,
     160,   161,    56,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    51,   175,    -1,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,   185,    26,    27,   188,   189,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     3,     4,     5,     6,    48,     8,
       9,    10,    11,   213,   214,    -1,    -1,    57,    -1,    -1,
      -1,   221,    -1,   223,   224,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,   234,     8,     9,    10,    11,    12,
      -1,    40,    -1,   243,    -1,    -1,    45,    46,    47,    -1,
      -1,   251,    51,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    -1,    55,    56,    57,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    40,    -1,    -1,    56,    -1,
      45,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      55,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    19,    20,    21,
      22,    23,    24,    28,    29,    30,    31,    32,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    40,    -1,
      45,    46,    -1,    45,    46,    47,    51,    -1,    53,    51,
      -1,    -1,    -1,    55,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    21,    22,    23,    24,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    -1,     3,
       4,     5,     6,    40,     8,     9,    10,    11,    45,    46,
      47,    -1,    -1,    -1,    51,    -1,    -1,    54,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    40,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    40,    -1,    51,    52,    -1,    45,
      46,    47,    -1,    -1,    -1,    51,    52,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    20,    21,    22,    23,    24,     1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    45,
      46,    47,    26,    27,    -1,    51,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    57,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    57,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    26,    27,    48,    -1,    -1,    -1,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    26,    27,    48,    -1,    -1,    -1,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    26,    27,    48,    -1,    -1,    -1,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    26,    27,    48,    -1,    -1,    -1,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    26,    27,    48,    -1,    -1,    -1,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    26,    27,    48,    -1,    -1,    -1,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    26,    27,    48,    -1,    -1,    -1,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    26,    27,    48,    -1,    -1,    -1,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      26,    27,    -1,    -1,    48,    -1,    50,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    26,    27,
      -1,    -1,    48,    -1,    50,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    26,    27,    -1,    -1,
      48,    -1,    50,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    26,    27,    -1,    -1,    48,    -1,
      50,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,     1,    48,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    12
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    19,    20,    21,    22,    23,    24,
      40,    45,    46,    47,    51,    54,    60,    61,    62,    65,
      67,    68,    70,    71,    79,    80,    84,    85,    86,    88,
      49,    49,     1,    51,     1,    51,    93,    95,    95,    95,
      51,    51,    57,    65,    67,    68,    71,    83,    94,    83,
      83,    83,    71,    65,    65,    71,    71,    55,    95,     0,
      61,    28,    29,    30,    31,    32,    45,    46,    51,    53,
      83,    83,    83,    26,    27,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    48,    83,    83,    84,
      71,    71,    52,    71,    72,    52,    72,     1,     5,     8,
       9,    10,    11,    12,    62,    73,    74,    75,    76,    86,
      51,    51,    71,    71,    83,    57,     5,    52,    85,     1,
      54,    69,    71,    71,    71,    71,    71,    66,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    50,    50,    52,    56,    71,    52,    92,    98,
      28,    49,     5,    56,    75,    14,    71,    12,    65,    70,
      79,    52,    52,    98,    55,    72,     7,    63,    64,    71,
      51,    69,    71,    71,    75,    51,    52,    93,    57,    57,
      89,    84,    86,    87,    51,    96,    55,    97,     1,    53,
      12,    52,    77,    78,    50,    71,    87,    71,    71,    54,
      25,    52,    78,    49,    51,    63,    93,    86,    52,    56,
      77,    28,    52,    57,    57,    17,    18,    90,    91,    87,
      86,    52,    71,    52,    72,    73,    82,    77,    69,    71,
      57,    71,    71,    51,    58,    55,    85,    90,    81,    50,
      52,    28,    86,    52,    52,    71,    86,    71,    87,    87,
      52,    58
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 77 "grammar.yy"
    { }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 78 "grammar.yy"
    { }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 83 "grammar.yy"
    {
		if (((yyvsp[(1) - (1)].node) != NULL) && (!cmdparser.addStatement((yyvsp[(1) - (1)].node)))) YYABORT;
		}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 86 "grammar.yy"
    {
		if (((yyvsp[(1) - (1)].node) != NULL) && (!cmdparser.addStatement((yyvsp[(1) - (1)].node)))) YYABORT;
		}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 96 "grammar.yy"
    { (yyval.node) = cmdparser.addConstant((yyvsp[(1) - (1)].intconst)); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 97 "grammar.yy"
    { (yyval.node) = cmdparser.addConstant((yyvsp[(1) - (1)].doubleconst)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 98 "grammar.yy"
    { (yyval.node) = cmdparser.addConstant((yyvsp[(1) - (1)].name)->get()); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 107 "grammar.yy"
    {
		if (!cmdparser.expandPath(stepNameStack.last(), (yyvsp[(4) - (5)].node))) YYABORT;
		stepNameStack.removeLast();
		}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 111 "grammar.yy"
    {
		if (!cmdparser.expandPath(stepNameStack.last(), NULL, (yyvsp[(4) - (5)].node))) YYABORT;
		stepNameStack.removeLast();
		}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 115 "grammar.yy"
    {
		if (!cmdparser.expandPath(stepNameStack.last(), NULL, NULL)) YYABORT;
		stepNameStack.removeLast();
		}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 119 "grammar.yy"
    {
		if (!cmdparser.expandPath((yyvsp[(1) - (2)].name))) YYABORT;
		stepNameStack.removeLast();
		}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 127 "grammar.yy"
    { }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 128 "grammar.yy"
    { }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 129 "grammar.yy"
    { printf("Error formulating path.\n"); YYABORT; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 134 "grammar.yy"
    {
		(yyval.node) = cmdparser.wrapVariable((yyvsp[(1) - (4)].variable),(yyvsp[(3) - (4)].node));
		if ((yyval.node) == NULL) { printf("Error in variable expression (code 1)\n"); YYABORT; }
		}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 138 "grammar.yy"
    {
		(yyval.node) = cmdparser.wrapVariable((yyvsp[(1) - (1)].variable));
		if ((yyval.node) == NULL) { printf("Error in variable expression (code 2)\n"); YYABORT; }
		}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 142 "grammar.yy"
    {
		(yyval.node) = cmdparser.wrapVariable((yyvsp[(1) - (4)].variable),(yyvsp[(3) - (4)].node));
		if ((yyval.node) == NULL) { printf("Error in variable expression (code 3)\n"); YYABORT; }
		}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 146 "grammar.yy"
    {
		(yyval.node) = cmdparser.wrapVariable((yyvsp[(1) - (1)].variable));
		if ((yyval.node) == NULL) { printf("Error in variable expression (code 4)\n"); YYABORT; }
		}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 150 "grammar.yy"
    {
		cmdparser.createPath((yyvsp[(1) - (2)].node));
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 152 "grammar.yy"
    {
		(yyval.node) = cmdparser.finalisePath();
		}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 155 "grammar.yy"
    {
		printf("Can't use a variable as a function. Did you mean '[' instead?\n"); (yyval.node) = NULL;
		}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 166 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction( (Command::Function) (yyvsp[(1) - (3)].functionId));
		msg.debug("PARSER: function : function '%s'\n", commands.data[(Command::Function) (yyvsp[(1) - (3)].functionId)].keyword);
		}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 170 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunctionWithArglist( (Command::Function) (yyvsp[(1) - (4)].functionId),(yyvsp[(3) - (4)].node));
		msg.debug("PARSER: function : function '%s' with exprlist\n", commands.data[(Command::Function) (yyvsp[(1) - (4)].functionId)].keyword);
		}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 174 "grammar.yy"
    {
		printf("Error: Missing brackets after function call?\n");
		YYABORT;
		}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 182 "grammar.yy"
    {
		(yyval.node) = cmdparser.addUserFunction((yyvsp[(1) - (3)].tree));
		msg.debug("PARSER: userfunction : function '%s'\n", (yyvsp[(1) - (3)].tree)->name());
		}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 186 "grammar.yy"
    {
		(yyval.node) = cmdparser.addUserFunction((yyvsp[(1) - (4)].tree),(yyvsp[(3) - (4)].node));
		msg.debug("PARSER: userfunction : function '%s' with expressionlist\n", (yyvsp[(1) - (4)].tree)->name());
		}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 190 "grammar.yy"
    {
		printf("Error: Missing brackets after function call?\n");
		YYABORT;
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 202 "grammar.yy"
    {
		(yyval.node) = cmdparser.addArrayConstant((yyvsp[(2) - (3)].node));
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 212 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignment,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 213 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignment,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 214 "grammar.yy"
    { printf("Mangled expression used in assignment.\n"); YYABORT; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 219 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 220 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 221 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 222 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignmentPlus,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 223 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignmentSubtract,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 224 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignmentMultiply,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 225 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAssignmentDivide,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 226 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorNegate, (yyvsp[(2) - (2)].node)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 227 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPostfixIncrease, (yyvsp[(1) - (2)].node));  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 228 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPostfixDecrease, (yyvsp[(1) - (2)].node)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 229 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPrefixIncrease, (yyvsp[(2) - (2)].node)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 230 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPrefixDecrease, (yyvsp[(2) - (2)].node)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 231 "grammar.yy"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 232 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAdd, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 233 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorSubtract, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 234 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorMultiply, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 235 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorDivide, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 236 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorPower, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 237 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorModulus, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 238 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorEqualTo, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 239 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorNotEqualTo, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 240 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorGreaterThan, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 241 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorGreaterThanEqualTo, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 242 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorLessThan, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 243 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorLessThanEqualTo, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 244 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorAnd, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 245 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorOr, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 246 "grammar.yy"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 247 "grammar.yy"
    { (yyval.node) = cmdparser.addOperator(Command::OperatorNot, (yyvsp[(2) - (2)].node)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 248 "grammar.yy"
    { printf("Error: '%s' has not been declared as a function or a variable.\n", yylval.name->get()); YYABORT; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 253 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		if ((yyval.node) == NULL) YYABORT;
		}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 257 "grammar.yy"
    {
		(yyval.node) = Tree::joinArguments((yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node));
		}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 260 "grammar.yy"
    {
		printf("Error: Missing comma between items.\n");
		YYABORT;
		}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 272 "grammar.yy"
    {
		msg.debug("PARSER: variablename : existing var '%s'\n", tokenName.get());
		tokenName = yylval.variable->name();
		(yyval.name) = &tokenName;
		}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 277 "grammar.yy"
    {
		msg.debug("PARSER: variablename : existing built-in function '%s'\n", tokenName.get());
		tokenName = Command::data[yylval.functionId].keyword;
		(yyval.name) = &tokenName;
		}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 282 "grammar.yy"
    {
		msg.debug("PARSER: variablename : existing local var '%s'\n", tokenName.get());
		printf("Error: Existing variable in local scope cannot be redeclared.\n");
		YYABORT;
		}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 287 "grammar.yy"
    {
		msg.debug("PARSER: variablename : constant '%s'\n", tokenName.get());
		printf("Error: Constant value found in declaration.\n");
		YYABORT;
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 292 "grammar.yy"
    {
		msg.debug("PARSER: variablename : existing user function '%s'\n", tokenName.get());
		printf("Error: Existing user-defined function name cannot be redeclared.\n");
		YYABORT;
		}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 297 "grammar.yy"
    {
		msg.debug("PARSER: variablename : variable type-name '%s'\n", VTypes::dataType( yylval.vtype));
		printf("Error: Type-name used in variable declaration.\n");
		YYABORT;
		}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 302 "grammar.yy"
    {
		msg.debug("PARSER: variablename : new token '%s'\n", tokenName.get());
		if (declaredType == VTypes::NoData) { printf("Token '%s' is undeclared.\n", tokenName.get()); YYABORT; }
		(yyval.name) = (yyvsp[(1) - (2)].name);
		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 311 "grammar.yy"
    {
		msg.debug("PARSER: assignedvariablename : var '%s' with array assignment\n", tokenName.get());
		(yyval.node) = cmdparser.addVariable(declaredType, &tokenName, (yyvsp[(3) - (3)].node));
		}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 315 "grammar.yy"
    {
		msg.debug("PARSER: assignedvariablename : array var '%s' with expr assignment\n", tokenName.get());
		(yyval.node) = cmdparser.addArrayVariable(declaredType, &tokenName,(yyvsp[(3) - (6)].node),(yyvsp[(6) - (6)].node));
		}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 319 "grammar.yy"
    {
		msg.debug("PARSER: assignedvariablename : array var '%s' with array assignment\n", tokenName.get());
		(yyval.node) = cmdparser.addArrayVariable(declaredType, &tokenName,(yyvsp[(3) - (6)].node),(yyvsp[(6) - (6)].node));
		}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 323 "grammar.yy"
    {
		msg.debug("PARSER: assignedvariablename : var '%s' with expr assignment\n", tokenName.get());
		(yyval.node) = cmdparser.addVariable(declaredType, &tokenName, (yyvsp[(3) - (3)].node));
		}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 331 "grammar.yy"
    {
		msg.debug("PARSER: assignedvariablename : var '%s'\n", tokenName.get());
		(yyval.node) = cmdparser.addVariable(declaredType, &tokenName);
		}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 335 "grammar.yy"
    {
		msg.debug("PARSER: assignedvariablename : array var '%s'\n", tokenName.get());
		(yyval.node) = cmdparser.addArrayVariable(declaredType, &tokenName, (yyvsp[(3) - (4)].node));
		}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 339 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 346 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 349 "grammar.yy"
    {
		(yyval.node) = Tree::joinArguments((yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node));
		}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 352 "grammar.yy"
    {
		printf("Error: Missing comma between declarations?\n");
		YYABORT;
		}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 360 "grammar.yy"
    {
		msg.debug("PARSER: typedvariablelistitem : var '%s'\n", tokenName.get());
		(yyval.node) = cmdparser.addVariable(declaredType, &tokenName);
		}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 364 "grammar.yy"
    {
		msg.debug("PARSER: typedvariablelistitem : var '%s' with expr assignment\n", tokenName.get());
		(yyval.node) = cmdparser.addVariable(declaredType, &tokenName, (yyvsp[(5) - (5)].node));
		}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 372 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 375 "grammar.yy"
    {
		(yyval.node) = Tree::joinArguments((yyvsp[(3) - (3)].node),(yyvsp[(1) - (3)].node));
		}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 378 "grammar.yy"
    {
		printf("Error: Missing comma between declarations?\n");
		YYABORT;
		}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 386 "grammar.yy"
    {
		msg.debug("PARSER: declaration : standard variable declaration list\n");
		(yyval.node) = cmdparser.addDeclarations((yyvsp[(3) - (3)].node));
		declaredType = VTypes::NoData;
		}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 391 "grammar.yy"
    {
		printf("Illegal use of reserved word '%s'.\n", VTypes::dataType(declaredType));
		YYABORT;
		}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 403 "grammar.yy"
    {
		msg.debug("PARSER: functiondeclaration : user-defined subroutine (VOID return value, no arguments)\n");
		if (!cmdparser.addStatement((yyvsp[(7) - (7)].node))) YYABORT;
		cmdparser.popTree();
		declaredType = VTypes::NoData;
		}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 409 "grammar.yy"
    {
		msg.debug("PARSER: functiondeclaration : user-defined subroutine (VOID return value, arguments)\n");
		if (!(yyvsp[(4) - (7)].tree)->addLocalFunctionArguments((yyvsp[(6) - (7)].node))) YYABORT;
		}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 412 "grammar.yy"
    {
		if (!cmdparser.addStatement((yyvsp[(9) - (9)].node))) YYABORT;
		cmdparser.popTree();
		declaredType = VTypes::NoData;
		}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 417 "grammar.yy"
    {
		msg.debug("PARSER: functiondeclaration : user-defined function (%s return value, no arguments)\n", VTypes::dataType((yyvsp[(4) - (7)].tree)->returnType()));
		if (!cmdparser.addStatement((yyvsp[(7) - (7)].node))) YYABORT;
		cmdparser.popTree();
		declaredType = VTypes::NoData;
		}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 423 "grammar.yy"
    {
		msg.debug("PARSER: functiondeclaration : user-defined function (%s return value, arguments)\n", VTypes::dataType((yyvsp[(4) - (7)].tree)->returnType()));
		if (!(yyvsp[(4) - (7)].tree)->addLocalFunctionArguments((yyvsp[(6) - (7)].node))) YYABORT;
		}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 426 "grammar.yy"
    {
		if (!cmdparser.addStatement((yyvsp[(9) - (9)].node))) YYABORT;
		cmdparser.popTree();
		declaredType = VTypes::NoData;
		}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 439 "grammar.yy"
    { }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 440 "grammar.yy"
    { }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 445 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (2)].node);
		}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 448 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (2)].node);
		}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 451 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (2)].node);
		}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 454 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (2)].node);
		}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 457 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (2)].node);
		}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 460 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 463 "grammar.yy"
    {
		(yyval.node) = NULL;
		}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 466 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::Return,(yyvsp[(2) - (3)].node));
		}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 469 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::Return);
		}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 472 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::Continue);
		}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 475 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::Break);
		}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 478 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::Quit);
		}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 485 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 488 "grammar.yy"
    {
		if ((yyvsp[(2) - (2)].node) == NULL) (yyval.node) = (yyvsp[(1) - (2)].node);
		else (yyval.node) = cmdparser.joinCommands((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
		}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 496 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(3) - (5)].node);
		}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 499 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::NoFunction);
		}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 506 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 509 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 516 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::If,(yyvsp[(3) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(7) - (7)].node));
		}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 519 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::If,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node));
		}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 522 "grammar.yy"
    {
		(yyval.node) = cmdparser.joinCommands((yyvsp[(2) - (10)].node), cmdparser.addFunction(Command::For, (yyvsp[(4) - (10)].node),(yyvsp[(6) - (10)].node),(yyvsp[(8) - (10)].node),(yyvsp[(10) - (10)].node))); cmdparser.popScope();
		}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 525 "grammar.yy"
    {
		(yyval.node) = cmdparser.joinCommands((yyvsp[(2) - (10)].node), cmdparser.addFunction(Command::For, (yyvsp[(4) - (10)].node),(yyvsp[(6) - (10)].node),(yyvsp[(8) - (10)].node),(yyvsp[(10) - (10)].node))); cmdparser.popScope();
		}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 528 "grammar.yy"
    {
		(yyval.node) = cmdparser.joinCommands((yyvsp[(2) - (6)].node), cmdparser.addFunction(Command::While, (yyvsp[(4) - (6)].node),(yyvsp[(6) - (6)].node)));
		cmdparser.popScope();
		}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 532 "grammar.yy"
    {
		(yyval.node) = cmdparser.joinCommands((yyvsp[(2) - (8)].node), cmdparser.addFunction(Command::DoWhile, (yyvsp[(3) - (8)].node),(yyvsp[(6) - (8)].node)));
		cmdparser.popScope();
		}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 536 "grammar.yy"
    {
		if (((yyvsp[(3) - (4)].node)->returnType() != VTypes::IntegerData) && ((yyvsp[(3) - (4)].node)->returnType() != VTypes::StringData))
		{
			printf("Error: Switch value must be of integer or string type.\n");
			YYABORT;
		}
		}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 542 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::Switch, (yyvsp[(3) - (8)].node));
		(yyval.node)->addJoinedArguments((yyvsp[(7) - (8)].node));
		}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 550 "grammar.yy"
    {
		if (((yyvsp[(3) - (5)].node)->returnType() != VTypes::IntegerData) && ((yyvsp[(3) - (5)].node)->returnType() != VTypes::StringData))
		{
			printf("Error: Case value must be of integer or string type.\n");
			YYABORT;
		}
		(yyval.node) = cmdparser.addFunction(Command::Case, (yyvsp[(3) - (5)].node));
		if ((yyval.node) == NULL) { printf("Error: Invalid case expression.\n"); YYABORT; }
		}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 559 "grammar.yy"
    {
		(yyval.node) = cmdparser.addFunction(Command::Default);
		}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 566 "grammar.yy"
    {
		(yyval.node) = (yyvsp[(1) - (1)].node);
		}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 569 "grammar.yy"
    {
		(yyval.node) = Tree::joinArguments((yyvsp[(2) - (2)].node),(yyvsp[(1) - (2)].node));
		}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 572 "grammar.yy"
    {
		(yyval.node) = Tree::joinArguments((yyvsp[(2) - (2)].node),(yyvsp[(1) - (2)].node));
		}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 582 "grammar.yy"
    { tokenName = *yylval.name; }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 586 "grammar.yy"
    { declaredType = yylval.vtype; }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 590 "grammar.yy"
    { declaredType = VTypes::NoData; }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 594 "grammar.yy"
    { (yyval.node) = cmdparser.pushScope(); if ((yyval.node) == NULL) YYABORT; }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 598 "grammar.yy"
    { if (!cmdparser.popScope()) YYABORT; }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 602 "grammar.yy"
    { stepNameStack.add()->set(yylval.name->get()); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 606 "grammar.yy"
    {
		msg.debug("PARSER: pushfunc : function/statement '%s'\n", yylval.name->get());
		(yyval.tree) = cmdparser.pushFunction(yylval.name->get(), declaredType);
		cmdparser.pushScope();
		}
    break;



/* Line 1806 of yacc.c  */
#line 3059 "grammar.cc"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 613 "grammar.yy"


void yyerror(char *s)
{
}

