/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 10 "file1.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <bits/stdc++.h>
	using namespace std;
	typedef struct node
	{
		int h1,h2,max_path,mainflag;
		char name[50];
		int size;
		struct node* child[10];
		
		bool isAvail;
		int value;
		int line;
		int lastDec;
		string netExpr;
	}node;
	int ifmax = 0,whmax =0,mainmax = 0;
	extern char* yytext;
	node* root = NULL;
	node *mknode0(int s);
	node *mknode1(int s,node* c1);
	node *mknode2(int s,node *c1,node *c2);
	node *mknode3(int s,node *c1,node *c2,node *c3);
	node *mknode4(int s,node *c1,node *c2,node *c3,node *c4);
	node *mknode5(int s,node *c1,node *c2,node *c3,node *c4,node *c5);
	node *mknode6(int s,node *c1,node *c2,node *c3,node *c4,node *c5,node *c6);
	node *mknode7(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6,node *c7);
	node *mknode8(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6,node *c7,node *c8);
	void yyerror(string);
	int yylex(void);
	
	string final_as = "\t.text\n\t.section\t.rodata\n";
	string main_as = "";

	string function_as = "";
	
	string label = ".LC";
	int labelcount = 0, varcount = 0, numvar = 0;
	unordered_map<string, int> var;	// variable name -> entry number
	unordered_map<string, pair<bool, int> > varValues; // variable name -> (true if constant, value)
	unordered_map<string, bool> varIsUsed;

	// for cse
	unordered_map<string, int> varLastDec;		// line no. of latest declaration of variable
	unordered_map<string, map<int, vector<int> > > expLast2Used; // exp -> (last Modified -> line no.s where it is used)
	void getCSE(node* root);

	map<int, int> strengthreduction;

	int linenum = 1;
	bool ifExpr = false;
	int ifSimple = -1;

	void constProp_Fold(node* root);
	vector<pair<int, pair<string,int> > > constantProp;
	// vector<tuple<int, string, int> > constantProp;
	map<int, int> constantFold;

	// Generate Assembly Code
	void gas(node *root);

#define YYSTYPE struct node *

#line 131 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FLOAT_LITERAL = 258,
    INTEGER_LITERAL = 259,
    INT = 260,
    RETURN = 261,
    BREAK = 262,
    CONT = 263,
    VOID = 264,
    FLOAT = 265,
    WHILE = 266,
    IF = 267,
    IDENTIFIER = 268,
    ELSE = 269,
    OR = 270,
    EQ = 271,
    NEQ = 272,
    LEQ = 273,
    GEQ = 274,
    AND = 275,
    FORMAT_SPECIFIER = 276,
    PRINTF = 277,
    SCANF = 278,
    FORMAT_SCANF = 279
  };
#endif
/* Tokens.  */
#define FLOAT_LITERAL 258
#define INTEGER_LITERAL 259
#define INT 260
#define RETURN 261
#define BREAK 262
#define CONT 263
#define VOID 264
#define FLOAT 265
#define WHILE 266
#define IF 267
#define IDENTIFIER 268
#define ELSE 269
#define OR 270
#define EQ 271
#define NEQ 272
#define LEQ 273
#define GEQ 274
#define AND 275
#define FORMAT_SPECIFIER 276
#define PRINTF 277
#define SCANF 278
#define FORMAT_SCANF 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    41,    32,     2,
      30,    31,    29,    38,    26,    39,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      36,    35,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    86,    91,    98,   103,   110,   117,   124,
     135,   148,   155,   162,   169,   178,   187,   198,   209,   214,
     220,   227,   234,   239,   250,   255,   262,   267,   272,   277,
     282,   287,   292,   297,   302,   309,   322,   339,   358,   369,
     374,   380,   389,   402,   413,   428,   437,   448,   459,   470,
     479,   494,   501,   508,   515,   522,   529,   536,   543,   550,
     557,   564,   571,   578,   585,   592,   599,   606,   613,   620,
     625,   634,   645,   650,   655,   660,   671,   680,   689,   698,
     705,   715,   722,   729,   734
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOAT_LITERAL", "INTEGER_LITERAL",
  "INT", "RETURN", "BREAK", "CONT", "VOID", "FLOAT", "WHILE", "IF",
  "IDENTIFIER", "ELSE", "OR", "EQ", "NEQ", "LEQ", "GEQ", "AND",
  "FORMAT_SPECIFIER", "PRINTF", "SCANF", "FORMAT_SCANF", "';'", "','",
  "'['", "']'", "'*'", "'('", "')'", "'&'", "'{'", "'}'", "'='", "'<'",
  "'>'", "'+'", "'-'", "'/'", "'%'", "'!'", "$accept", "program",
  "decl_list", "decl", "var_decl", "type_spec", "func_decl", "params",
  "param_list", "param", "stmt_list", "stmt", "while_stmt", "print_stmt",
  "scan_stmt", "compound_stmt", "local_decls", "local_decl", "if_stmt",
  "return_stmt", "break_stmt", "continue_stmt", "assign_stmt", "expr",
  "Pexpr", "integerLit", "floatLit", "identifier", "format_specifier",
  "arg_list", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    59,    44,    91,    93,    42,
      40,    41,    38,   123,   125,    61,    60,    62,    43,    45,
      47,    37,    33
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      35,   -25,   -18,    -6,    16,    35,   -62,   -62,    14,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -17,   -62,    35,    28,
      35,   -62,    14,   -62,    11,    14,    15,    25,   -62,    86,
      30,    31,    47,    35,   -62,    35,    36,   -62,   -62,   -62,
     -62,   -62,   157,    -1,    38,    57,    61,    64,    67,    73,
      14,    54,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -20,   -62,   -62,    17,    96,    17,    17,
      17,    17,    79,   156,   -62,   -62,     6,   -62,   -62,    96,
      96,    29,    29,    27,   -62,   -62,    96,    96,   -62,   -62,
      76,   -62,   -62,   -62,   -62,   -62,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,    17,    17,    17,    96,
      96,    77,    83,   -62,   -62,    66,    89,   -62,    96,    88,
      92,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,    90,   -62,    94,    98,    62,
      62,    14,    95,   102,   101,   -62,   -62,    96,   -62,   -62,
     123,   109,    14,   116,    96,   -62,    62,   117,   112,   -62,
     120,   -62,   -62,   122,   -62,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    11,    13,     0,     2,     4,     5,     0,     6,
      15,    14,    16,     1,     3,    78,     0,     7,     0,     0,
      19,     8,     0,    76,     0,     0,     0,    18,    21,     0,
       0,    22,     0,     0,     9,     0,     0,    40,    17,    20,
      10,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    29,    30,    31,    27,    39,    28,    32,
      33,    34,    26,     0,    77,    45,     0,     0,     0,     0,
       0,     0,     0,    69,    72,    73,    74,    47,    48,     0,
       0,     0,     0,     0,    38,    24,     0,     0,    67,    74,
       0,    68,    66,    65,    64,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,    79,    80,     0,     0,    41,     0,     0,
       0,    75,    51,    52,    53,    54,    56,    58,    61,    55,
      57,    59,    60,    62,    63,     0,    82,    83,     0,     0,
       0,     0,     0,     0,     0,    49,    71,     0,    70,    35,
      43,     0,     0,     0,     0,    81,     0,     0,     0,    42,
       0,    44,    36,     0,    50,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   172,   -13,    63,   -62,   -62,   -62,   145,
     -62,   -50,   -62,   -62,   -62,   149,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -61,    53,   163,   -62,    -8,   104,   -62,
     -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    26,    27,    28,
      51,    52,    53,    54,    55,    56,    42,    57,    58,    59,
      60,    61,    62,    72,    73,    74,    75,    89,   115,   137,
     138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    85,    64,    23,    10,    21,    90,    86,    17,    18,
      19,    11,    15,    20,    29,    87,    13,    31,   111,   112,
      64,    23,    40,    12,    65,   119,   120,    15,    66,    67,
      15,    68,    23,   109,    63,    76,   110,    69,    70,    30,
       1,    71,    83,    63,     2,     3,    32,    67,   135,   136,
     113,    33,   117,   114,   118,    34,    35,   143,    36,    76,
      43,    44,    45,    77,    41,    46,    47,    15,    43,    44,
      45,    76,    76,    46,    47,    15,    48,    49,    76,    76,
      37,    22,    78,    25,    48,    49,   155,    37,    84,   149,
     150,    79,   141,   160,    80,    37,    25,    81,    22,    64,
      23,    76,    76,    82,    95,    50,   161,   121,   139,    15,
      76,    17,    18,    19,   140,   142,   144,   145,   146,    88,
     147,    91,    92,    93,    94,    66,    67,   152,    68,   148,
     153,    63,    63,   151,    69,    70,   154,   156,    71,    76,
     157,   159,   162,   163,   158,   164,    76,   165,    63,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,     1,    43,    44,    45,     2,     3,    46,    47,
      15,    96,    97,    98,    99,   100,   101,    14,    39,    48,
      49,    38,    24,     0,     0,   102,   116,     0,     0,     0,
      37,     0,   103,   104,   105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
       8,    51,     3,     4,    29,    18,    67,    27,    25,    26,
      27,    29,    13,    30,    22,    35,     0,    25,    79,    80,
       3,     4,    35,    29,    25,    86,    87,    13,    29,    30,
      13,    32,     4,    27,    42,    43,    30,    38,    39,    28,
       5,    42,    50,    51,     9,    10,    31,    30,   109,   110,
      21,    26,    25,    24,    27,    25,    26,   118,    27,    67,
       6,     7,     8,    25,    28,    11,    12,    13,     6,     7,
       8,    79,    80,    11,    12,    13,    22,    23,    86,    87,
      33,    18,    25,    20,    22,    23,   147,    33,    34,   139,
     140,    30,    26,   154,    30,    33,    33,    30,    35,     3,
       4,   109,   110,    30,    25,    42,   156,    31,    31,    13,
     118,    25,    26,    27,    31,    26,    28,    25,    28,    66,
      26,    68,    69,    70,    71,    29,    30,    32,    32,    31,
      28,   139,   140,   141,    38,    39,    35,    14,    42,   147,
      31,    25,    25,    31,   152,    25,   154,    25,   156,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    15,    16,    17,    18,    19,    20,     5,    33,    22,
      23,    32,    19,    -1,    -1,    29,    82,    -1,    -1,    -1,
      33,    -1,    36,    37,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     9,    10,    44,    45,    46,    47,    48,    49,
      29,    29,    29,     0,    46,    13,    70,    25,    26,    27,
      30,    47,    48,     4,    68,    48,    50,    51,    52,    70,
      28,    70,    31,    26,    25,    26,    27,    33,    58,    52,
      47,    28,    59,     6,     7,     8,    11,    12,    22,    23,
      48,    53,    54,    55,    56,    57,    58,    60,    61,    62,
      63,    64,    65,    70,     3,    25,    29,    30,    32,    38,
      39,    42,    66,    67,    68,    69,    70,    25,    25,    30,
      30,    30,    30,    70,    34,    54,    27,    35,    67,    70,
      66,    67,    67,    67,    67,    25,    15,    16,    17,    18,
      19,    20,    29,    36,    37,    38,    39,    40,    41,    27,
      30,    66,    66,    21,    24,    71,    71,    25,    27,    66,
      66,    31,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    66,    66,    72,    73,    31,
      31,    26,    26,    66,    28,    25,    28,    26,    31,    54,
      54,    70,    32,    28,    35,    66,    14,    31,    70,    25,
      66,    54,    25,    31,    25,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    47,
      47,    48,    48,    48,    48,    48,    48,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    56,    57,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    69,    70,    71,
      71,    72,    72,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     6,
       7,     1,     1,     1,     2,     2,     2,     6,     1,     0,
       3,     1,     2,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     8,     4,     2,
       0,     3,     6,     5,     7,     2,     3,     2,     2,     4,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     1,
       4,     4,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 79 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		root = (yyval);
		strcpy((yyval)->name,"program");
	}
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"decl_list");
	}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 92 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"decl_list");
	}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"decl");
	}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 104 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"decl");
	}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode3(3,(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"var_decl");
	}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,";");
		(yyval) = mknode4(4,(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"var_decl");
	}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 125 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,"[");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"]");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode6(6,(yyvsp[-5]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"var_decl");
	}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 136 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-4]) = mknode0(0);
		strcpy((yyvsp[-4])->name,"[");
		(yyvsp[-2]) = mknode0(0);
		strcpy((yyvsp[-2])->name,"]");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,",");
		(yyval) = mknode7(7,(yyvsp[-6]),(yyvsp[-5]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"var_decl");
	}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 149 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,"VOID");
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"type_spec");
	}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 156 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,"INT");
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"type_spec");
	}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,"FLOAT");
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"type_spec");
	}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 170 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"VOID");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,"*");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"type_spec");
	}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 179 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"INT");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,"*");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"type_spec");
	}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 188 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"FLOAT");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,"*");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"type_spec");
	}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,"(");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,")");
		(yyval)= mknode6(6,(yyvsp[-5]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"func_decl");
	}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 210 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"params");
	}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode0(1);
		strcpy((yyval)->name,"params");
	}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 221 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,",");
		(yyval) = mknode3(3,(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"param_list");
	}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 228 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"param_list");
	}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 235 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"param");
	}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 240 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"[");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,"]");
		(yyval) = mknode4(4,(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"param");
	}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 251 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"stmt_list");
	}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 256 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt_list");
	}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 263 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 268 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 273 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 278 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 283 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 288 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 293 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 298 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 303 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"stmt");
	}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 310 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-4]) = mknode0(0);
		strcpy((yyvsp[-4])->name,"WHILE");
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,"(");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,")");
		(yyval) = mknode5(5,(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"while_stmt");
	}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 323 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-6]) = mknode0(0);
		strcpy((yyvsp[-6])->name,"PRINTF");
		(yyvsp[-5]) = mknode0(0);
		strcpy((yyvsp[-5])->name,"(");
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,",");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,")");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode7(7,(yyvsp[-6]),(yyvsp[-5]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"print_stmt");
	}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 340 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-7]) = mknode0(0);
		strcpy((yyvsp[-7])->name,"SCANF");
		(yyvsp[-6]) = mknode0(0);
		strcpy((yyvsp[-6])->name,"(");
		(yyvsp[-4]) = mknode0(0);
		strcpy((yyvsp[-4])->name,",");
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name, "&");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-2])->name,")");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[-1])->name,";");
		(yyval) = mknode8(8,(yyvsp[-7]),(yyvsp[-6]),(yyvsp[-5]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"scan_stmt");
	}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 359 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,"{");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,"}");
		(yyval) = mknode4(4,(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"compound_stmt");
	}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 370 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"local_decls");
	}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 374 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode0(1);
		strcpy((yyval)->name,"local_decls");
	}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 381 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode3(3,(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"local_decl");
		
		numvar++;
	}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 390 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,"[");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"]");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode6(6,(yyvsp[-5]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"local_decl");
	}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 403 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-4]) = mknode0(0);
		strcpy((yyvsp[-4])->name,"IF");
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,"(");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,")");
		(yyval) = mknode5(5,(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"if_stmt");
	}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 414 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-6]) = mknode0(0);
		strcpy((yyvsp[-6])->name,"IF");
		(yyvsp[-5]) = mknode0(0);
		strcpy((yyvsp[-5])->name,"(");
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,")");
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"ELSE");
		(yyval) = mknode7(7,(yyvsp[-6]),(yyvsp[-5]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"if_stmt");
	}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 429 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"RETURN");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"return_stmt");
	}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 438 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-2]) = mknode0(0);
		strcpy((yyvsp[-2])->name,"RETURN");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode3(3,(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"return_stmt");
	}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 449 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"BREAK");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"break_stmt");
	}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 460 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"CONT");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"continue_stmt");
	}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 471 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-2]) = mknode2(2,(yyvsp[-3]),(yyvsp[-1]));
		strcpy((yyvsp[-2])->name,"=");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyval) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyval)->name,"assign_stmt");
	}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 480 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-5]) = mknode0(0);
		strcpy((yyvsp[-5])->name,"[");
		(yyvsp[-3]) = mknode0(0);
		strcpy((yyvsp[-3])->name,"]");
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,";");
		(yyvsp[-2]) = mknode5(5,(yyvsp[-6]),(yyvsp[-5]),(yyvsp[-4]),(yyvsp[-3]),(yyvsp[-1]));
		strcpy((yyvsp[-2])->name,"=");
		(yyval) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyval)->name,"assign_stmt");
	}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 495 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"OR");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 502 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"EQ");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 509 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"NEQ");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 516 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"LEQ");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 523 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"<");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 530 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"GEQ");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 537 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,">");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 544 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"AND");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 551 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"+");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 558 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"-");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 565 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"*");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 572 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"/");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 579 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode2(2,(yyvsp[-2]),(yyvsp[0]));
		strcpy((yyvsp[-1])->name,"%");
		(yyval) = mknode1(1,(yyvsp[-1]));
		strcpy((yyval)->name,"expr");
	}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 586 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"!");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"expr");
	}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 593 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"-");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"expr");
	}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 600 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"+");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"expr");
	}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 607 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"*");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"expr");
	}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 614 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,"&");
		(yyval) = mknode2(2,(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"expr");
	}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 621 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"expr");
	}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 626 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-2]) = mknode0(0);
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[-2])->name,"(");
		strcpy((yyvsp[0])->name,")");			
		(yyval) = mknode4(4,(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"expr");
	}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 635 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-2]) = mknode0(0);
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[-2])->name,"[");
		strcpy((yyvsp[0])->name,"]");
		(yyval) = mknode4(4,(yyvsp[-3]),(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"expr");
	}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 646 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"Pexpr");
	}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 651 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"Pexpr");
	}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 656 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"Pexpr");
	}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 661 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-2]) = mknode0(0);
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[-2])->name,"(");
		strcpy((yyvsp[0])->name,")");
		(yyval) = mknode3(3,(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"Pexpr");
	}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 672 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,yytext);
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"integerLit");	
	}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 681 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,yytext);
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"floatLit");
	}
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 690 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,yytext);
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"identifier");
	}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 699 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,yytext);
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"format_specifier_print");
	}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 706 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[0]) = mknode0(0);
		strcpy((yyvsp[0])->name,yytext);
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"format_specifier_scan");
	}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 716 "file1.y" /* yacc.c:1646  */
    {
		(yyvsp[-1]) = mknode0(0);
		strcpy((yyvsp[-1])->name,",");
		(yyval) = mknode3(3,(yyvsp[-2]),(yyvsp[-1]),(yyvsp[0]));
		strcpy((yyval)->name,"arg_list");
	}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 723 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"arg_list");
	}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 730 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode1(1,(yyvsp[0]));
		strcpy((yyval)->name,"args");
	}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 734 "file1.y" /* yacc.c:1646  */
    {
		(yyval) = mknode0(1);
		strcpy((yyval)->name,"args");
	}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2361 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 741 "file1.y" /* yacc.c:1906  */


void yyerror(string s) {
    printf("Invalid Input\n");
	exit(0);
}

bool custSort1(const pair<int, int>& a, const pair<int, int>& b) 
{
	if(a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first; 
}

bool custSort2(const pair<int, pair<string, int> >& a, const pair<int, pair<string, int> >& b) 
{
	if(a.first == b.first)
		return var[a.second.first] < var[b.second.first];
	else
		return (a.first < b.first);
}

bool custSort3(const string& a, const string& b)
{
	return var[a] < var[b];
}

bool custSort4(const vector<int> &a, const vector<int> &b)
{
	return a[0] <= b[0];
}

int main()
{
	yyparse();

	constProp_Fold(root->child[0]->child[0]->child[0]->child[5]);

	// get unused variables and sort in order of declaration
	vector<string> unused;
	auto it = varIsUsed.begin();
	for(; it!=varIsUsed.end(); ++it)
		if(!it->second)
			unused.push_back(it->first);

	sort(unused.begin(), unused.end(), custSort3);
	//sort(constantFold.begin(), constantFold.end(), custSort1);
	sort(constantProp.begin(), constantProp.end(), custSort2);

	// remove space allocated for unused variables
	for(int i=0; i<unused.size(); ++i)
	{
		int entrynum = var[unused[i]];
		
		var.erase(unused[i]);
		varcount--;

		for(auto it = var.begin(); it!=var.end(); ++it)
			if(it->second > entrynum)
				it->second--;
	}

	getCSE(root->child[0]->child[0]->child[0]->child[5]);
	// for(auto itr = expLast2Used.begin(); itr != expLast2Used.end(); ++itr)
	// {
	// 	cout << "yo ";
	// 	cout << itr->first << "\n";
	// 	for(auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
	// 	{
	// 		cout << itr2->first << " ";
	// 		for(auto itr3 = itr2->second.begin(); itr3 != itr2->second.end(); ++itr3)
	// 			cout << *itr3 << " ";
	// 		cout << "\n";
	// 	}
	// }
	vector< vector<int> > ans_cse;
	for(auto itr = expLast2Used.begin(); itr != expLast2Used.end();)
	{
		for(auto itr2 = itr->second.begin(); itr2 != itr->second.end();)
		{
			if(itr2->second.size() > 1)
			{	
				ans_cse.push_back(itr2->second);
				++itr2;
			}
			else
			{
				(itr->second).erase(itr2++);
			}
		}

		if(itr->second.empty())
			expLast2Used.erase(itr++);
		else
			++itr;
	}

	// cout << "wait\n";

	// for(auto itr = expLast2Used.begin(); itr != expLast2Used.end(); ++itr)
	// {
	// 	cout << "yo ";
	// 	cout << itr->first << "\n";
	// 	for(auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
	// 	{
	// 		cout << itr2->first << " ";
	// 		for(auto itr3 = itr2->second.begin(); itr3 != itr2->second.end(); ++itr3)
	// 			cout << *itr3 << " ";
	// 		cout << "\n";
	// 	}
	// }
	sort(ans_cse.begin(), ans_cse.end(), custSort4);
	// varcount += ans_cse.size();
	
	// generate assembly code
	ofstream outasm("assembly.s");
	main_as = "\t.text\n\t.globl\tmain\n\t.type\tmain, @function\nmain:\n";
	main_as +="\tpushq\t%rbp\n\tmovq\t%rsp, %rbp\n\tsubq\t$";
	main_as += "64, %rsp\n";//to_string(4*varcount+20)+", %rsp\n";
	gas(root->child[0]->child[0]->child[0]->child[5]->child[2]);
	
	main_as += "\tnop\n\tleave\n\tret";
	final_as += function_as + main_as;
	outasm << final_as << endl;

	// print optimisation summary
	ofstream outsum("summary.txt");

	outsum << "unused-vars\n";
	for(int i=0; i<unused.size(); ++i)
		outsum << unused[i] << "\n";
	outsum << "\n";

	if(ifSimple >= 0)
		outsum << "if-simpl\n" << ifSimple << "\n\n";
	else
		outsum << "if-simpl\n\n";

	outsum << "strength-reduction\n";
	for(auto i=strengthreduction.begin(); i!= strengthreduction.end(); ++i)
	{
		outsum << i->first << " " << i->second << "\n";
	}
	outsum << "\n";

	outsum << "constant-folding\n";
	// for(int i=0; i<constantFold.size(); ++i)
	// {
	// 	if( (i < constantFold.size()-1) && constantFold[i].first == constantFold[i+1].first)
	// 		continue;
	// 	outsum << constantFold[i].first << " " << constantFold[i].second << "\n";
	// }
	for(auto i=constantFold.begin(); i!= constantFold.end(); ++i)
	{
		outsum << i->first << " " << i->second << "\n";
	}
	outsum << "\n";

	outsum << "constant-propagation";
	for(int i=0; i<constantProp.size(); ++i)
	{
		if((i>0) && (constantProp[i].first) == (constantProp[i-1].first))
		{
			if((constantProp[i].second.first) != (constantProp[i-1].second.first))
				outsum << " " << (constantProp[i].second.first) << " " << (constantProp[i].second.second) << "";
		}
		else
			outsum << "\n" << (constantProp[i].first) << " " << (constantProp[i].second.first) << " " << (constantProp[i].second.second);
	}
	outsum << "\n\n";

	outsum << "cse\n";
	for(int i=0; i<ans_cse.size(); ++i)
	{
		for(int j=0; j<ans_cse[i].size(); ++j)
			outsum << ans_cse[i][j] << " ";
		outsum << "\n";
	}

	return 0;
}

void getCSE(node* root)
{
	if(root == NULL)
		return;

	if(strcmp(root->name,"compound_stmt") == 0)
	{
		getCSE(root->child[1]);
		getCSE(root->child[2]);
	}
	else if(strcmp(root->name, "local_decls") == 0)
	{
		if(strcmp(root->child[0]->name, "#EPS") == 0)
		{
			return;
		}
		else
		{
			getCSE(root->child[0]);
			string temp = root->child[1]->child[1]->child[0]->name;	// variable's name

			varLastDec[temp] = root->child[1]->child[1]->child[0]->line;
			if(varValues.count(temp) <= 0)
			{
				varValues[temp].first = false;
				varValues[temp].second = -1;
			}
		}
	}
	else if(strcmp(root->name, "stmt_list") == 0)
	{
		getCSE(root->child[0]);
		getCSE(root->child[1]);
	}
	else if(strcmp(root->name, "stmt") == 0)
	{
		getCSE(root->child[0]);
	}
	else if(strcmp(root->name, "assign_stmt") == 0)
	{
		getCSE(root->child[0]->child[1]);

		string temp_varname = root->child[0]->child[0]->child[0]->name;
		varValues[temp_varname].first = false;

		varLastDec[temp_varname] = root->line;
		// cout << "check " << temp_varname << " " << root->line << "\n";

		if(root->child[0]->child[1]->isAvail)
		// statically computable
		{
			varValues[temp_varname].second = root->child[0]->child[1]->value;
			varValues[temp_varname].first = true;
		}
	}
	else if(strcmp(root->name, "print_stmt") == 0)
	{
		string temp = root->child[4]->child[0]->name;
		if(varValues[temp].first)
		{
			root->child[4]->child[0]->isAvail = true;
			root->child[4]->child[0]->value = varValues[temp].second;
			root->child[4]->isAvail = true;
			root->child[4]->value = root->child[4]->child[0]->value;
		}
	}
	else if(strcmp(root->name, "scan_stmt") == 0)
	{
		string temp = root->child[5]->child[0]->name;
		varValues[temp].first = false;
		varLastDec[temp] = root->line;
	}
	else if(strcmp(root->name, "if_stmt") == 0)
	{
		getCSE(root->child[2]);

		if(root->child[2]->isAvail)
		// statically computable
		{
			if(root->child[2]->value > 0)
			// else block is dead
			{
				getCSE(root->child[4]->child[0]);
			}
			else
			// "if" block is dead
			{
				if(root->size > 5)
					getCSE(root->child[6]->child[0]);
				// else
				// 	root = NULL;
			}
		}
		else
		{
			getCSE(root->child[4]);
			if(root->size > 5)
				getCSE(root->child[6]);
		}
	}
	else if(strcmp(root->name, "expr") == 0)
	{
		if(root->size == 1)
		{
			if(strcmp(root->child[0]->name, "-") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value - root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
					root->netExpr = to_string(root->value);
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
					root->netExpr = root->child[0]->child[0]->netExpr + "-" + root->child[0]->child[1]->netExpr;
					
					int temp_lastdec = max(root->child[0]->child[0]->lastDec, root->child[0]->child[1]->lastDec);
					root->lastDec = temp_lastdec;
					expLast2Used[root->netExpr][temp_lastdec].push_back(root->line);
				}

			}
			else if(strcmp(root->child[0]->name, "+") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value + root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
					root->netExpr = to_string(root->value);
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
					root->netExpr = root->child[0]->child[0]->netExpr + "+" + root->child[0]->child[1]->netExpr;
					
					int temp_lastdec = max(root->child[0]->child[0]->lastDec, root->child[0]->child[1]->lastDec);
					root->lastDec = temp_lastdec;
					expLast2Used[root->netExpr][temp_lastdec].push_back(root->line);
				}
			}
			else if(strcmp(root->child[0]->name, "*") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value * root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
					root->netExpr = to_string(root->value);
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
					root->netExpr = root->child[0]->child[0]->netExpr + "*" + root->child[0]->child[1]->netExpr;
					
					int temp_lastdec = max(root->child[0]->child[0]->lastDec, root->child[0]->child[1]->lastDec);
					root->lastDec = temp_lastdec;
					expLast2Used[root->netExpr][temp_lastdec].push_back(root->line);
				}
			}
			else if(strcmp(root->child[0]->name, "/") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "%") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, ">") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					if(root->child[0]->child[0]->value > root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;

					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "<") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value < root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "GEQ") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "LEQ") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "EQ") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "NEQ") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "OR") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "AND") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else
			// Pexpr
			{
				getCSE(root->child[0]);

				root->isAvail = root->child[0]->isAvail;

				if(root->child[0]->isAvail)
				{
					root->value = root->child[0]->value;
				}
			}
		}
		else if(root->size == 2)
		{	
			if(strcmp(root->child[0]->name, "!") == 0)
				getCSE(root->child[1]);
			else if(strcmp(root->child[0]->name, "-") == 0)
				getCSE(root->child[1]);
		}
	}
	else if(strcmp(root->name, "Pexpr") == 0)
	{
		if(strcmp(root->child[0]->name, "identifier") == 0)
		{
			if(varValues[root->child[0]->child[0]->name].first)
			// statically computable
			{
				root->child[0]->child[0]->value = varValues[root->child[0]->child[0]->name].second;
				root->child[0]->child[0]->isAvail = true;

				root->child[0]->value = root->child[0]->child[0]->value;
				root->child[0]->isAvail = true;

				root->value = root->child[0]->value;
				root->isAvail = true;
				root->netExpr = to_string(root->value);
				root->lastDec = varLastDec[root->child[0]->child[0]->name];
			}
			else
			{
				root->isAvail = false;
				root->netExpr = root->child[0]->child[0]->name;
				root->lastDec = varLastDec[root->child[0]->child[0]->name];				
			}
		}
		
		else if(strcmp(root->child[0]->name, "integerLit") == 0)
		{
			char* gen;
			root->child[0]->value = strtol(root->child[0]->child[0]->name, &gen, 10);
			root->child[0]->isAvail = true;

			root->value = root->child[0]->value;
			root->isAvail = true;
			root->netExpr = root->child[0]->child[0]->name;
		}
		else
		// Case 3: ( expr )
		{
			getCSE(root->child[1]);
			root->isAvail = root->child[1]->isAvail;
			root->value = root->child[1]->value;
			root->netExpr = "(" + root->child[1]->netExpr + ")";
			root->lastDec = root->child[1]->lastDec;

			// if(!root->child[1]->isAvail)
			// 	expLast2Used[root->netExpr][root->lastDec].push_back(root->line);
		}
	}
	
	return;	
}

void constProp_Fold(node* root)
{
	if(root == NULL)
		return;

	if(strcmp(root->name,"compound_stmt") == 0)
	{
		// cout << "here";
		constProp_Fold(root->child[1]);
		constProp_Fold(root->child[2]);
	}
	else if(strcmp(root->name, "local_decls") == 0)
	{
		if(strcmp(root->child[0]->name, "#EPS") == 0)
		{
			return;
		}
		else
		{
			constProp_Fold(root->child[0]);
			string temp = root->child[1]->child[1]->child[0]->name;

			if(var.count(temp) <= 0)
			// to get order of declaration of variables
			{
				var[temp] = varcount;
				++varcount;
			}
			if(varValues.count(temp) <= 0)
			{
				varValues[temp].first = false;
				varValues[temp].second = -1;
			}
			if(varIsUsed.count(temp) <= 0)
			// for "used variable" optimisation
			{
				varIsUsed[temp] = false;
			}
		}
	}
	else if(strcmp(root->name, "stmt_list") == 0)
	{
		constProp_Fold(root->child[0]);
		constProp_Fold(root->child[1]);
	}
	else if(strcmp(root->name, "stmt") == 0)
	{
		constProp_Fold(root->child[0]);

		if(strcmp(root->child[0]->name, "if_stmt") == 0)
		{
			if(root->child[0]->child[2]->isAvail)
			// statically computable
			{
				if(root->child[0]->child[2]->value > 0)
				// else block is dead
				{
					ifSimple = 1;
					constProp_Fold(root->child[0]->child[4]->child[0]);
				}
				else
				// "if" block is dead
				{
					ifSimple = 0;
					if(root->child[0]->size > 5)
						constProp_Fold(root->child[0]->child[6]->child[0]);
					else
						root->child[0] = NULL;
				}
			}
			else
			{
				constProp_Fold(root->child[0]->child[4]);
				if(root->size > 5)
					constProp_Fold(root->child[0]->child[6]);
			}
		}
	}
	else if(strcmp(root->name, "assign_stmt") == 0)
	{
		constProp_Fold(root->child[0]->child[1]);

		varValues[root->child[0]->child[0]->child[0]->name].first = false;

		if(root->child[0]->child[1]->isAvail)
		{
			varValues[root->child[0]->child[0]->child[0]->name].second = root->child[0]->child[1]->value;
			varValues[root->child[0]->child[0]->child[0]->name].first = true;
		}

		// isUsed
		varIsUsed[root->child[0]->child[0]->child[0]->name] = true;
	}
	else if(strcmp(root->name, "print_stmt") == 0)
	{
		string temp = root->child[4]->child[0]->name;
		varIsUsed[temp] = true;

		if(varValues[temp].first)
		{
			root->child[4]->child[0]->isAvail = true;
			root->child[4]->child[0]->value = varValues[temp].second;
			root->child[4]->isAvail = true;
			root->child[4]->value = root->child[4]->child[0]->value;

			constantProp.push_back(make_pair(root->child[4]->line, make_pair(temp, root->child[4]->value)));
		}
	}
	else if(strcmp(root->name, "scan_stmt") == 0)
	{
		string temp = root->child[5]->child[0]->name;
		varIsUsed[temp] = true;

		varValues[temp].first = false;
	}
	else if(strcmp(root->name, "if_stmt") == 0)
	{
		ifExpr = true;
		constProp_Fold(root->child[2]);
		ifExpr = false;
	}
	else if(strcmp(root->name, "expr") == 0)
	{
		if(root->size == 1)
		{
			if(strcmp(root->child[0]->name, "-") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value - root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;

					if(!ifExpr)	constantFold[root->line]=root->value;
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
				}

			}
			else if(strcmp(root->child[0]->name, "+") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value + root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;

					if(!ifExpr)	constantFold[root->line] = root->value;
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
				}
			}
			else if(strcmp(root->child[0]->name, "*") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value * root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;

					if(!ifExpr)	constantFold[root->line] = root->value;
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
				}
			}
			else if(strcmp(root->child[0]->name, "/") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "%") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, ">") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					if(root->child[0]->child[0]->value > root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;

					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "<") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value < root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "GEQ") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value >= root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "LEQ") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value <= root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "EQ") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value == root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "NEQ") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value != root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "OR") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value > 0 || root->child[0]->child[1]->value > 0)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "AND") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value > 0 && root->child[0]->child[1]->value > 0)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else
			// Pexpr
			{
				constProp_Fold(root->child[0]);

				root->isAvail = root->child[0]->isAvail;

				if(root->child[0]->isAvail)
				{
					root->value = root->child[0]->value;
				}
			}
		}
		else if(root->size == 2)
		{	
			if(strcmp(root->child[0]->name, "!") == 0)
				constProp_Fold(root->child[1]);
			else if(strcmp(root->child[0]->name, "-") == 0)
				constProp_Fold(root->child[1]);
		}
	}
	else if(strcmp(root->name, "Pexpr") == 0)
	{
		if(strcmp(root->child[0]->name, "identifier") == 0)
		{
			varIsUsed[root->child[0]->child[0]->name] = true;

			if(varValues[root->child[0]->child[0]->name].first)
			// statically computable
			{
				if(!ifExpr)
					constantProp.push_back(make_pair(root->child[0]->child[0]->line, make_pair(root->child[0]->child[0]->name, varValues[root->child[0]->child[0]->name].second)));
				root->child[0]->child[0]->value = varValues[root->child[0]->child[0]->name].second;
				root->child[0]->child[0]->isAvail = true;

				root->child[0]->value = root->child[0]->child[0]->value;
				root->child[0]->isAvail = true;

				root->value = root->child[0]->value;
				root->isAvail = true;
			}
		}
		
		else if(strcmp(root->child[0]->name, "integerLit") == 0)
		{
			char* gen;
			root->child[0]->value = strtol(root->child[0]->child[0]->name, &gen, 10);
			root->child[0]->isAvail = true;

			root->value = root->child[0]->value;
			root->isAvail = true;
		}
		else
		// Case 3: ( expr )
		{
			constProp_Fold(root->child[1]);
			root->isAvail = root->child[1]->isAvail;
			root->value = root->child[1]->value;
		}
	}
	
	return;	
}

void gas(node *root)
{
	if(root == NULL)
		return;
	
	if(strcmp(root->name, "program") == 0)
		gas(root->child[0]);
	else if(strcmp(root->name, "decl_list") == 0)
		gas(root->child[0]);
	else if(strcmp(root->name, "decl") == 0)
		gas(root->child[0]);
	else if(strcmp(root->name, "func_decl") == 0)
		gas(root->child[5]);
	else if(strcmp(root->name,"compound_stmt") == 0)
	{
		gas(root->child[1]);
		gas(root->child[2]);
	}
	else if(strcmp(root->name, "local_decls") == 0)
	{
		if(strcmp(root->child[0]->name, "#EPS") == 0)
		{
			return;
		}
		else
		{
			gas(root->child[0]);
			string temp = root->child[1]->child[1]->child[0]->name;
			if(var.count(temp) <= 0)
			{
				var[temp] = varcount;
				++varcount;
			}
		}
	}
	else if(strcmp(root->name, "stmt_list") == 0)
	{
		gas(root->child[0]);
		gas(root->child[1]);
	}
	else if(strcmp(root->name, "stmt") == 0)
		gas(root->child[0]);
	else if(strcmp(root->name, "assign_stmt") == 0)
	{
		gas(root->child[0]->child[1]);
		
		main_as += "\tmovl\t%eax, " + to_string(-4*(var[root->child[0]->child[0]->child[0]->name]+3)) + "(%rbp)\n";
	}
	else if(strcmp(root->name, "print_stmt") == 0)
	{
		function_as += label + to_string(labelcount) + ":\n\t.string\t\"%d\\n\"\n";
		
		if(root->child[4]->isAvail)
		// constant prop
			main_as += "\tmovl\t$" + to_string(root->child[4]->value) + ", %esi\n";
		else
			main_as += "\tmovl\t" + to_string(-4*(var[root->child[4]->child[0]->name]+3)) + "(%rbp), %esi\n";

		main_as += "\tleaq\t" + label + to_string(labelcount) + "(%rip), %rdi\n";
		main_as += "\tmovl\t$0, %eax\n";
		main_as += "\tcall\tprintf@PLT\n";
		
		labelcount++;
	}
	else if(strcmp(root->name, "scan_stmt") == 0)
	{
		function_as += label + to_string(labelcount) + ":\n\t.string\t\"%d\"\n";
		//printf("hellllllo");
		main_as += "\tleaq\t" + to_string(-4*(var[root->child[5]->child[0]->name]+3)) + "(%rbp), %rax\n";
		main_as += "\tmovq\t%rax, %rsi\n";
		main_as += "\tleaq\t" + label + to_string(labelcount) + "(%rip), %rdi\n";
		main_as += "\tmovl\t$0, %eax\n";
		main_as += "\tcall\tscanf@PLT\n";
		
		labelcount++;
	}
	else if(strcmp(root->name, "if_stmt") == 0)
	{
		if(root->child[2]->isAvail)
		// statically computable
		{
			if(root->child[2]->value > 0)
			// else block is dead
			{
				gas(root->child[4]->child[0]);
			}
			else
			// "if" block is dead
			{
				if(root->size > 5)
				{
					// cout << "hellllllo\n";
					gas(root->child[6]->child[0]);
				}
				else
					return;
			}
		}
		else
		{
			gas(root->child[2]);
			main_as += "\tcmpl\t$0, %eax\n";
			string temp_label = ".ELSE" + to_string(labelcount);
			labelcount++;
			
			main_as += "\tje\t" + temp_label + "\n";
			
			gas(root->child[4]);
			string temp_label1 = "";	
			if(root->size > 5)
			{
				temp_label1 = ".OUT" + to_string(labelcount++);
				main_as += "\tjmp\t" + temp_label1 + "\n";
			}
				
			main_as += temp_label + ":\n";
			
			if(root->size > 5)
			{
				gas(root->child[6]);
				main_as += temp_label1 + ":\n";
			}
		}
	}
	else if(strcmp(root->name, "while_stmt") == 0)
	{
		string temp_label = ".WHILE" + to_string(labelcount);
		string temp_label1 = ".EXITWHILE" + to_string(labelcount);
		labelcount++;
		
		main_as += temp_label + ":\n";
		
		gas(root->child[2]);
		main_as += "\tcmpl\t$0, %eax\n";
		main_as += "\tje\t" + temp_label1 + "\n";
		
		gas(root->child[4]);
		main_as += "\tjmp\t" + temp_label + "\n";
		main_as += temp_label1 + ":\n";
	}
	else if(strcmp(root->name, "expr") == 0)
	{
		if(root->isAvail)
		{
			main_as += "\tmovl\t$" + to_string(root->value) + ", %eax\n";
		}
		else if(root->size == 1)
		{
			if(root->child[0]->isAvail)
			{
				main_as += "\tmovl\t$" + to_string(root->child[0]->value) + ", %eax\n";
			}
			else if(strcmp(root->child[0]->name, "-") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tsubl\t%esi, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "+") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\taddl\t%esi, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "*") == 0)
			{
				if(root->child[0]->child[0]->isAvail && __builtin_popcount(root->child[0]->child[0]->value) == 1)
				{
					int temp_power = __builtin_ctz(root->child[0]->child[0]->value);
					gas(root->child[0]->child[1]);
					main_as += "\tsall\t$" + to_string(temp_power) + ", %eax\n";

					if(strengthreduction.count(root->child[0]->line) <= 0)
						strengthreduction[root->child[0]->line] = temp_power;
					else
						strengthreduction[root->child[0]->line] = max(strengthreduction[root->child[0]->line], temp_power);
				}
				else if(root->child[0]->child[1]->isAvail && __builtin_popcount(root->child[0]->child[1]->value) == 1)
				{
					int temp_power = __builtin_ctz(root->child[0]->child[1]->value);
					gas(root->child[0]->child[0]);
					main_as += "\tsall\t$" + to_string(temp_power) + ", %eax\n";

					if(strengthreduction.count(root->child[0]->line) <= 0)
						strengthreduction[root->child[0]->line] = temp_power;
					else
						strengthreduction[root->child[0]->line] = max(strengthreduction[root->child[0]->line], temp_power);
				}
				else
				{
					gas(root->child[0]->child[0]);
					main_as += "\tpushq\t%rax\n";
					
					gas(root->child[0]->child[1]);
					main_as += "\tmovl\t%eax, %esi\n";
					main_as += "\tpopq\t%rax\n";
					main_as += "\timull\t%esi, %eax\n";
				}
			}
			else if(strcmp(root->child[0]->name, "/") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcltd\n\tidivl\t%esi\n";
			}
			else if(strcmp(root->child[0]->name, "%") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcltd\n\tidivl\t%esi\n";
				main_as += "\tmovl\t%edx, %eax\n";
			}
			else if(strcmp(root->child[0]->name, ">") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetg\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "<") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetl\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "GEQ") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetge\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "LEQ") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetle\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "EQ") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsete\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "NEQ") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetne\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "OR") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tjne\t.L" + to_string(labelcount) + "\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tje\t.L" + to_string(labelcount+1) + "\n";
				
				main_as += ".L" + to_string(labelcount) + ":\n";
				main_as += "\tmovl\t$1, %eax\n";
				main_as += "\tjmp\t.L" + to_string(labelcount+2) + "\n";
				main_as += ".L" + to_string(labelcount+1) + ":\n";
				main_as += "\tmovl\t$0, %eax\n";
				main_as += ".L" + to_string(labelcount+2) + ":\n";
				
				labelcount += 3;
			}
			else if(strcmp(root->child[0]->name, "AND") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tje\t.L" + to_string(labelcount) + "\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tje\t.L" + to_string(labelcount) + "\n";
				main_as += "\tmovl\t$1, %eax\n";
				main_as += "\tjmp\t.L" + to_string(labelcount+1) + "\n";
				
				
				main_as += ".L" + to_string(labelcount) + ":\n";
				main_as += "\tmovl\t$0, %eax\n";
				main_as += ".L" + to_string(labelcount+1) + ":\n";
				
				labelcount += 2;
			}
			else
			// Pexpr
			{
				gas(root->child[0]);
			}
		}
		else if(root->size == 2)
		{
			if(strcmp(root->child[0]->name, "!") == 0)
			{
				gas(root->child[1]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tsete\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "-") == 0)
			{
				gas(root->child[1]);
				main_as += "\tnegl\t%eax\n";
			}
		}
	}
	else if(strcmp(root->name, "Pexpr") == 0)
	{
		if(root->isAvail)
		{
			main_as += "\tmovl\t$" + to_string(root->value) + ", %eax\n";
		}
		else if(strcmp(root->child[0]->name, "identifier") == 0)
			main_as += "\tmovl\t" + to_string(-4*(var[root->child[0]->child[0]->name]+3)) + "(%rbp), %eax\n";
		
		else if(strcmp(root->child[0]->name, "integerLit") == 0)
			main_as += "\tmovl\t$" + (string)root->child[0]->child[0]->name + ", %eax\n";
		else
			gas(root->child[1]);
	}
	
	return;
}

node *mknode8(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6,node *c7, node *c8)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->child[4] = c5;
	nn->child[5] = c6;
	nn->child[6] = c7;
	nn->child[7] = c8;
	nn->size = 8;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode7(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6,node *c7)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->child[4] = c5;
	nn->child[5] = c6;
	nn->child[6] = c7;
	nn->size = 7;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode6(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->child[4] = c5;
	nn->child[5] = c6;
	nn->size = 6;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode5(int s,node *c1,node *c2,node *c3,node* c4,node *c5)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->child[4] = c5;
	nn->size = 5;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode4(int s,node *c1,node *c2,node *c3,node* c4)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->size = 4;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode3(int s,node *c1,node *c2,node *c3)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->size = 3;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode2(int s,node *c1,node *c2)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->size = 2;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode1(int s,node *c1)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->size = 1;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode0(int s)
{
	node* nn = (node *)malloc(sizeof(node));
	if(s == 0)
	{
		nn->size = 0;
	}
	if(s == 1)
	{
		node* nnc = (node *)malloc(sizeof(node));
		nnc->size = 0;
		strcpy(nnc->name,"#EPS");
		nn->child[0] = nnc;
		nn->size = 1;
	}
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}
