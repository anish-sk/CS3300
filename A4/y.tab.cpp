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
#line 4 "a.y" /* yacc.c:339  */

    #include <bits/stdc++.h>
    #include "IRGenerator.hpp"
    using namespace std;
    void yyerror(char*);
    int yylex(void);
    #define nc (node->children)
    void set_programLongestPath(int); // Set Longest Path in the program
    void set_ifLongestPath(int);      // Set Longest Path among all subtrees of if statement
    void set_whileLongestPath(int);   // Set Longest Path among all subtrees of while statement
    void set_mainLongestPath(int);    // Set Longest Path of main subtee
    void set_switchLongestPath(int);  // Set Longest Path among all subtrees of switch statement
    extern FILE* yyin;
    char mytext[10000];
    int programLongestPath = 0;
    int ifLongestPath = 0;
    int whileLongestPath = 0;
    int mainLongestPath = 0;
    int switchLongestPath = 0;
    int isMain = 0;
    int prop_need = 1;  
    extern char* yytext;
    treeNode* ast;   // pointer to the root of the final abstract syntax tree   
    int line_no = 0;
    unordered_map<string, int> curr_isconst;
    unordered_map<string, int> curr_symbol_table;
    unordered_map<string, int> used;
    unordered_map<string, int> isconst;
    unordered_map<string, int> if_isconst;
    unordered_map<string, int> else_isconst;
    unordered_map<string, int> symbol_table;
    unordered_map<string, int> if_symbol_table;
    unordered_map<string, int> else_symbol_table;
    vector<string> varlist;
    vector<vector<string>> summary(6, vector<string>());
    unordered_map<int, string> opti_list{
                                {0, "unused-vars"},
                                {1, "if-simpl"},
                                {2, "strength-reduction"},
                                {3, "constant-folding"},
                                {4, "constant-propagation"},
                                {5, "cse"},
                                };
    int if_else = -1;
    map<int, int> constant_folding;
    map<int, vector<pair<string, int>>> constant_prop;
    map<int, int> strength_reduction;
    map<string, int> curr_var_counter;
    map<string, int> var_counter;
    map<string, int> if_var_counter;
    map<string, int> else_var_counter;
    int global_counter = 0; 
    int curr_global_counter = 0;
    struct vnnode{
        string name;
        int l;
        int r;
    };
    #define vnentry pair<string, pair<int, int> >
    map<vnentry, int> curr_value_number;
    map<int, vnentry> curr_rev_value_number;
    map<vnentry, int> value_number;
    map<int, vnentry> rev_value_number;
    map<vnentry, int> if_value_number;
    map<int, vnentry> if_rev_value_number;
    map<vnentry, int> else_value_number;
    map<int, vnentry> else_rev_value_number;
    map<int, multiset<int>> csubexprs;
    set<string> constlist;

#line 137 "y.tab.cpp" /* yacc.c:339  */

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
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    IDENTIFIER = 258,
    INTEGER_NUMBER = 259,
    FLOAT_NUMBER = 260,
    PLUS = 261,
    MINUS = 262,
    MULT = 263,
    DIV = 264,
    IF = 265,
    ELSE = 266,
    FOR = 267,
    WHILE = 268,
    DO = 269,
    INT = 270,
    FLOAT = 271,
    CHAR = 272,
    EQ = 273,
    EQEQ = 274,
    GEQ = 275,
    LEQ = 276,
    GT = 277,
    LT = 278,
    NEWOP = 279,
    NEQ = 280,
    BITAND = 281,
    BITOR = 282,
    BITNOT = 283,
    BITXOR = 284,
    AND = 285,
    OR = 286,
    NOT = 287,
    MOD = 288,
    EXTERN = 289,
    LONG = 290,
    SHORT = 291,
    DOUBLE = 292,
    PRINTF = 293,
    PERCENTD = 294,
    PERCENTDSLASHN = 295,
    SCANF = 296,
    VOID = 297,
    SWITCH = 298,
    CASE = 299,
    STRUCT = 300,
    BREAK = 301,
    CONTINUE = 302,
    RETURN = 303,
    STRLITERAL = 304,
    CHARLITERAL = 305,
    INC = 306,
    DEC = 307,
    ARROW = 308,
    SIZEOF = 309,
    DEFAULT = 310
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER_NUMBER 259
#define FLOAT_NUMBER 260
#define PLUS 261
#define MINUS 262
#define MULT 263
#define DIV 264
#define IF 265
#define ELSE 266
#define FOR 267
#define WHILE 268
#define DO 269
#define INT 270
#define FLOAT 271
#define CHAR 272
#define EQ 273
#define EQEQ 274
#define GEQ 275
#define LEQ 276
#define GT 277
#define LT 278
#define NEWOP 279
#define NEQ 280
#define BITAND 281
#define BITOR 282
#define BITNOT 283
#define BITXOR 284
#define AND 285
#define OR 286
#define NOT 287
#define MOD 288
#define EXTERN 289
#define LONG 290
#define SHORT 291
#define DOUBLE 292
#define PRINTF 293
#define PERCENTD 294
#define PERCENTDSLASHN 295
#define SCANF 296
#define VOID 297
#define SWITCH 298
#define CASE 299
#define STRUCT 300
#define BREAK 301
#define CONTINUE 302
#define RETURN 303
#define STRLITERAL 304
#define CHARLITERAL 305
#define INC 306
#define DEC 307
#define ARROW 308
#define SIZEOF 309
#define DEFAULT 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 75 "a.y" /* yacc.c:355  */

    class treeNode* node;

#line 291 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 308 "y.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   329

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,    59,     2,     2,    61,     2,    65,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    60,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,    64,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   186,   186,   193,   198,   203,   208,   213,   218,   225,
     231,   237,   243,   249,   254,   261,   268,   274,   280,   286,
     291,   297,   302,   308,   317,   321,   327,   332,   337,   341,
     347,   351,   356,   360,   364,   368,   372,   376,   380,   384,
     388,   392,   396,   400,   404,   409,   417,   424,   431,   436,
     445,   452,   458,   462,   468,   473,   479,   486,   494,   499,
     505,   511,   517,   526,   530,   535,   541,   547,   555,   562,
     570,   579,   586,   593,   599,   605,   611,   617,   623,   628,
     634,   640,   646,   652,   658,   664,   670,   676,   682,   688,
     693,   698,   703,   708,   713,   717,   722,   728,   732,   736,
     740,   746,   757,   768,   775,   782,   787,   792,   796
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER_NUMBER",
  "FLOAT_NUMBER", "PLUS", "MINUS", "MULT", "DIV", "IF", "ELSE", "FOR",
  "WHILE", "DO", "INT", "FLOAT", "CHAR", "EQ", "EQEQ", "GEQ", "LEQ", "GT",
  "LT", "NEWOP", "NEQ", "BITAND", "BITOR", "BITNOT", "BITXOR", "AND", "OR",
  "NOT", "MOD", "EXTERN", "LONG", "SHORT", "DOUBLE", "PRINTF", "PERCENTD",
  "PERCENTDSLASHN", "SCANF", "VOID", "SWITCH", "CASE", "STRUCT", "BREAK",
  "CONTINUE", "RETURN", "STRLITERAL", "CHARLITERAL", "INC", "DEC", "ARROW",
  "SIZEOF", "DEFAULT", "'['", "']'", "'('", "')'", "';'", "','", "':'",
  "'{'", "'}'", "'.'", "$accept", "program", "decl_list", "decl",
  "struct_decl", "var_decl", "type_spec", "extern_spec", "func_decl",
  "params", "param_list", "param", "stmt_list", "stmt", "while_stmt",
  "dowhile_stmt", "print_stmt", "format_specifier1", "scanf_stmt",
  "format_specifier2", "compound_stmt", "local_decls", "local_decl",
  "if_stmt", "return_stmt", "break_stmt", "continue_stmt", "switch_stmt",
  "compound_case", "single_case", "default_case", "assign_stmt",
  "incr_stmt", "decr_stmt", "expr", "Pexpr", "integerLit", "floatLit",
  "identifier", "arg_list", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    91,    93,    40,    41,
      59,    44,    58,   123,   125,    46
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,  -139,     5,     3,    16,  -139,  -139,  -139,     5,    13,
    -139,  -139,  -139,    -3,  -139,  -139,    45,    24,    27,    29,
    -139,  -139,     9,    11,  -139,    33,  -139,  -139,  -139,   -11,
    -139,     6,     5,     5,    10,    41,  -139,  -139,     5,    28,
       5,  -139,    15,    99,    56,    51,    33,    37,  -139,    53,
    -139,    33,    58,  -139,  -139,  -139,    14,  -139,  -139,  -139,
     193,  -139,    21,    21,    21,    21,    21,    67,    14,    69,
     276,  -139,  -139,   -46,    71,    73,   205,    74,    75,    76,
      77,    82,   254,     1,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,    39,  -139,
    -139,  -139,  -139,  -139,  -139,    21,    68,    83,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    14,    14,    14,    14,   123,   104,   107,
      14,  -139,  -139,  -139,    87,  -139,  -139,    14,    88,    89,
       5,    14,     5,    92,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,    98,  -139,    95,   101,   118,   119,   100,  -139,    96,
    -139,   120,   127,  -139,   128,  -139,  -139,   161,   133,   174,
    -139,  -139,    14,  -139,   205,   205,    14,     5,   167,   131,
    -139,    14,   177,    14,  -139,   187,  -139,   140,   142,     5,
     160,   145,    14,   149,   205,   150,   151,   153,     9,   158,
     160,  -139,   154,  -139,  -139,  -139,  -139,   156,   155,   159,
     164,  -139,  -139,  -139,   205,   205,  -139,   205,   205
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      22,    21,     0,     0,    22,     4,     7,     5,     0,     0,
       6,   103,   104,    19,     1,     3,     0,    14,    15,    13,
      20,    53,     0,    22,     9,    22,    17,    18,    16,    22,
     101,     0,     0,     0,     0,    24,    27,    10,     0,     0,
       0,    52,     0,    19,    28,     0,    22,     0,     8,     0,
      11,    22,     0,    53,    23,    26,     0,    54,    12,    29,
      22,   102,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    97,    98,    99,     0,     0,     0,   104,     0,     0,
       0,     0,     0,     0,    31,    35,    40,    41,    42,    33,
      34,    37,    38,    39,    36,    32,    43,    44,     0,    91,
      99,    90,    92,    93,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,    60,    61,    58,     0,    51,    30,     0,     0,     0,
       0,     0,     0,     0,   100,    55,    84,    85,    86,    87,
      79,    76,    75,    74,    73,    81,    80,    82,    77,    88,
      83,     0,   106,   107,     0,     0,     0,     0,    48,     0,
      50,     0,     0,    59,     0,    71,    72,     0,     0,     0,
      78,    96,     0,    95,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,   105,    56,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    69,     0,    70,    57,    46,    47,     0,     0,     0,
       0,    63,    68,    49,     0,     0,    62,    65,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,   216,  -139,   -18,    48,  -139,  -139,  -139,
    -139,   178,  -138,   -74,  -139,  -139,  -139,  -139,  -139,  -139,
     184,   179,  -139,  -139,  -139,  -139,  -139,  -139,    20,  -139,
    -139,  -139,  -139,  -139,   -41,    54,   -21,  -139,    -2,  -139,
    -139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    34,
      35,    36,    83,    84,    85,    86,    87,   169,    88,   171,
      89,    29,    41,    90,    91,    92,    93,    94,   209,   210,
     220,    95,    96,    97,    69,    70,    71,    72,   100,   163,
     164
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    31,   127,    14,    11,    20,    16,    37,    11,   136,
     123,    74,   124,    30,    75,    76,    -2,    11,    30,    61,
      62,    63,    64,     1,    11,    30,    61,   106,    17,    18,
      43,    44,    26,    58,    32,    27,    47,    28,    49,    77,
      65,   134,    78,    12,    79,     1,    66,    80,    81,    82,
       1,     1,    12,    39,    73,    19,    32,   137,    98,    12,
      21,     2,     2,    42,    53,   135,    73,     1,    67,    45,
     -25,    33,    68,    38,    98,    50,    51,    40,    32,    68,
      73,    98,   161,   162,   165,   166,   227,   228,    48,   172,
     138,   139,   140,    22,    33,   141,   174,    24,    25,    38,
     178,    22,    46,    23,   142,    24,    25,    20,    40,    56,
     195,   196,    52,    57,    53,    59,    99,   101,   102,   103,
     104,    73,    73,    73,    73,   105,   107,   144,    73,   125,
     214,   126,   128,   129,   130,    73,   167,   131,   177,    73,
     179,   194,   132,   145,   168,   197,   170,   173,   175,   176,
     201,   180,   203,   136,   136,   181,   182,   187,   186,   143,
     183,   212,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   184,   185,   191,
      73,   188,    98,    98,    73,   198,   189,   218,   190,    73,
     192,    73,   193,   199,   200,   202,    11,   207,   204,   205,
      73,   206,    98,    74,   208,   211,    75,    76,    11,   213,
     215,   216,   217,   219,   222,    74,   223,   224,    75,    76,
      15,   225,    98,    98,    55,    98,    98,     1,   226,    54,
     221,    77,    60,     0,    78,     0,    79,     0,    32,    80,
      81,    82,     0,    77,     0,     0,    78,     0,    79,     0,
       0,    80,    81,    82,     0,     0,    53,    11,    30,    61,
      62,    63,    64,     0,     0,     0,     0,     0,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,   108,   109,   110,   111,    66,     0,     0,     0,
       0,     0,    12,     0,     0,   112,   113,   114,   115,   116,
     117,   118,     0,     0,     0,     0,   119,   120,    67,   121,
       0,     0,    68,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122
};

static const yytype_int16 yycheck[] =
{
       2,    22,    76,     0,     3,     8,     8,    25,     3,    83,
      56,    10,    58,     4,    13,    14,     0,     3,     4,     5,
       6,     7,     8,    34,     3,     4,     5,    68,    15,    16,
      32,    33,     8,    51,    45,     8,    38,     8,    40,    38,
      26,    82,    41,    38,    43,    34,    32,    46,    47,    48,
      34,    34,    38,    64,    56,    42,    45,    18,    60,    38,
      63,    45,    45,    57,    63,    64,    68,    34,    54,    59,
      59,    23,    58,    25,    76,    60,    61,    29,    45,    58,
      82,    83,   123,   124,   125,   126,   224,   225,    60,   130,
      51,    52,    53,    56,    46,    56,   137,    60,    61,    51,
     141,    56,    61,    58,    65,    60,    61,     8,    60,    56,
     184,   185,    56,    60,    63,    57,    62,    63,    64,    65,
      66,   123,   124,   125,   126,    58,    57,    59,   130,    58,
     204,    58,    58,    58,    58,   137,    13,    60,   140,   141,
     142,   182,    60,    60,    40,   186,    39,    60,    60,    60,
     191,    59,   193,   227,   228,    57,    61,    61,    58,   105,
      59,   202,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    59,    59,    18,
     182,    61,   184,   185,   186,   187,    59,   208,    60,   191,
      57,   193,    18,    26,    63,    18,     3,   199,    11,    59,
     202,    59,   204,    10,    44,    60,    13,    14,     3,    60,
      60,    60,    59,    55,    60,    10,    60,    62,    13,    14,
       4,    62,   224,   225,    46,   227,   228,    34,    64,    45,
     210,    38,    53,    -1,    41,    -1,    43,    -1,    45,    46,
      47,    48,    -1,    38,    -1,    -1,    41,    -1,    43,    -1,
      -1,    46,    47,    48,    -1,    -1,    63,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,     6,     7,     8,     9,    32,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    31,    54,    33,
      -1,    -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    45,    67,    68,    69,    70,    71,    72,    73,
      74,     3,    38,   104,     0,    69,   104,    15,    16,    42,
       8,    63,    56,    58,    60,    61,     8,     8,     8,    87,
       4,   102,    45,    72,    75,    76,    77,    71,    72,    64,
      72,    88,    57,   104,   104,    59,    61,   104,    60,   104,
      60,    61,    56,    63,    86,    77,    56,    60,    71,    57,
      87,     5,     6,     7,     8,    26,    32,    54,    58,   100,
     101,   102,   103,   104,    10,    13,    14,    38,    41,    43,
      46,    47,    48,    78,    79,    80,    81,    82,    84,    86,
      89,    90,    91,    92,    93,    97,    98,    99,   104,   101,
     104,   101,   101,   101,   101,    58,   100,    57,     6,     7,
       8,     9,    19,    20,    21,    22,    23,    24,    25,    30,
      31,    33,    53,    56,    58,    58,    58,    79,    58,    58,
      58,    60,    60,    60,   100,    64,    79,    18,    51,    52,
      53,    56,    65,   101,    59,    60,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   100,   100,   105,   106,   100,   100,    13,    40,    83,
      39,    85,   100,    60,   100,    60,    60,   104,   100,   104,
      59,    57,    61,    59,    59,    59,    58,    61,    61,    59,
      60,    18,    57,    18,   100,    79,    79,   100,   104,    26,
      63,   100,    18,   100,    11,    59,    59,   104,    44,    94,
      95,    60,   100,    60,    79,    60,    60,    59,   102,    55,
      96,    94,    60,    60,    62,    62,    64,    78,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    69,    70,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    92,    93,    94,    94,    95,    96,    97,    97,    97,
      97,    98,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   102,   103,   104,   104,   105,   105,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     3,
       4,     6,     7,     2,     2,     2,     3,     3,     3,     2,
       3,     1,     0,     6,     1,     0,     3,     1,     2,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     7,     1,     8,
       1,     4,     2,     0,     3,     6,     5,     7,     2,     3,
       2,     2,     8,     2,     1,     4,     3,     4,     7,     6,
       6,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     1,     4,     4,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     0
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
#line 186 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("program", v); 
                        set_programLongestPath((yyval.node)->maxSubtreeLength);
                        ast = (yyval.node);
                    }
#line 1573 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 193 "a.y" /* yacc.c:1646  */
    { 
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("decl_list", v); 
                            }
#line 1582 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 198 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl_list", v); 
                }
#line 1591 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 203 "a.y" /* yacc.c:1646  */
    {   
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl", v); 
                }
#line 1600 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 208 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl", v); 
                }
#line 1609 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 213 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("decl", v); 
                    }
#line 1618 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 218 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[-5].node) = new treeNode("STRUCT"); (yyvsp[-3].node) = new treeNode("{"); 
                                                            (yyvsp[-1].node) = new treeNode("}"); (yyvsp[0].node) = new treeNode(";");
                                                            vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("struct_decl", v); 
                                                        }
#line 1629 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 225 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[0].node) = new treeNode(";");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("var_decl", v); 
                                    }
#line 1639 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 231 "a.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-1].node) = new treeNode(",");
                                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("var_decl", v); 
                                            }
#line 1649 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 237 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[-3].node) = new treeNode("["); (yyvsp[-1].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                            vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("var_decl", v); 
                                                        }
#line 1659 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 243 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-4].node) = new treeNode("["); (yyvsp[-2].node) = new treeNode("]"); (yyvsp[-1].node) = new treeNode(",");
                                                                    vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("var_decl", v); 
                                                                }
#line 1669 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 249 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("VOID");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                (yyval.node) = new treeNode("type_spec", v); 
                            }
#line 1679 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 254 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("INT");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                (yyval.node) = new treeNode("type_spec", v);
                                (yyval.node)->width = 4;
                            }
#line 1690 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 261 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode("FLOAT");
                                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                    (yyval.node)->width = 8;
                                }
#line 1701 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 268 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("VOID"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1711 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 274 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("INT"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1721 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 280 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("FLOAT"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                  }
#line 1731 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 286 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("STRUCT");
                                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("type_spec", v); 
                                }
#line 1741 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 291 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2].node) = new treeNode("STRUCT"); (yyvsp[0].node) = new treeNode("MULT");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("type_spec", v);
                                    }
#line 1751 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 297 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].node) = new treeNode("EXTERN");
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("extern_spec", v);
                    }
#line 1761 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 302 "a.y" /* yacc.c:1646  */
    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    (yyval.node) = new treeNode("extern_spec", v);
                }
#line 1771 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 308 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                                                    vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("func_decl", v);      
                                                                    if((yyvsp[-4].node)->lexValue == "main") {
                                                                        set_mainLongestPath((yyval.node)->maxSubtreeLength);
                                                                    }
                                                                }
#line 1784 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 317 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("params", v);
                    }
#line 1793 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 321 "a.y" /* yacc.c:1646  */
    {
          auto x = new treeNode("epsilon");
          vector<treeNode*> v = {x};
          (yyval.node) = new treeNode("params", v);
        }
#line 1803 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 327 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-1].node) = new treeNode(",");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("param_list", v);
                                    }
#line 1813 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 332 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("param_list", v);
                    }
#line 1822 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 337 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("param", v);
                            }
#line 1831 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 341 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-1].node) = new treeNode("["); (yyvsp[0].node) = new treeNode("]");
                                        vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("param", v);
                                    }
#line 1841 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 347 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("stmt_list", v);
                            }
#line 1850 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 351 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt_list", v);
                }
#line 1859 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 356 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1868 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 360 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1877 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 364 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                }
#line 1886 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 368 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1895 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 372 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1904 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 376 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1913 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 380 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                 }
#line 1922 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 384 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1931 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 388 "a.y" /* yacc.c:1646  */
    {    
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1940 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 392 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1949 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1958 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 400 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                }
#line 1967 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 404 "a.y" /* yacc.c:1646  */
    {   
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                }
#line 1976 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 409 "a.y" /* yacc.c:1646  */
    { 
                                        (yyvsp[-4].node) = new treeNode("WHILE");
                                        (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                        vector<treeNode*> v = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("while_stmt", v); 
                                        set_whileLongestPath((yyval.node)->maxSubtreeLength); 
                                    }
#line 1988 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 417 "a.y" /* yacc.c:1646  */
    { 
                                                (yyvsp[-6].node) = new treeNode("DO"); (yyvsp[-4].node) = new treeNode("WHILE");
                                                (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
                                                vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("dowhile_stmt", v);  
                                            }
#line 1999 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 424 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-6].node) = new treeNode("PRINTF"); (yyvsp[-5].node) = new treeNode("("); (yyvsp[-3].node) = new treeNode(",");
                                                                    (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
                                                                    vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("print_stmt", v); 
                                                                }
#line 2010 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 431 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("PERCENTDSLASHN");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("format_specifier1", v);
                            }
#line 2020 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 436 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-7].node) = new treeNode("SCANF"); (yyvsp[-6].node) = new treeNode("("); (yyvsp[-4].node) = new treeNode(",");
                                                                    (yyvsp[-3].node) = new treeNode("&");
                                                                    (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
                                                                    vector<treeNode*> v = {(yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("scanf_stmt", v); 
                                                                    //cout<<"asbd"<<flush;
                                                                }
#line 2033 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 445 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("PERCENTD");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("format_specifier2", v);
                                //cout<<"abd"<<flush;
                            }
#line 2044 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 452 "a.y" /* yacc.c:1646  */
    {
                                                    (yyvsp[-3].node) = new treeNode("{"); (yyvsp[0].node) = new treeNode("}");
                                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                    (yyval.node) = new treeNode("compound_stmt", v);
                                                }
#line 2054 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 458 "a.y" /* yacc.c:1646  */
    {
                                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("local_decls", v);
                                    }
#line 2063 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 462 "a.y" /* yacc.c:1646  */
    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    (yyval.node) = new treeNode("local_decls", v);
                }
#line 2073 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 468 "a.y" /* yacc.c:1646  */
    {
                                            (yyvsp[0].node) = new treeNode(";");
                                            vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                            (yyval.node) = new treeNode("local_decl", v);
                                        }
#line 2083 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 473 "a.y" /* yacc.c:1646  */
    {
                                                        (yyvsp[-3].node) = new treeNode("["); (yyvsp[-1].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                        vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("local_decl", v); 
                                                    }
#line 2093 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 479 "a.y" /* yacc.c:1646  */
    {   
                                    (yyvsp[-4].node) = new treeNode("IF");
                                    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                    vector<treeNode*> v = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("if_stmt", v);
                                    set_ifLongestPath((yyval.node)->maxSubtreeLength); 
                                }
#line 2105 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 486 "a.y" /* yacc.c:1646  */
    { 
                                            (yyvsp[-6].node) = new treeNode("IF");
                                            (yyvsp[-5].node) = new treeNode("("); (yyvsp[-3].node) = new treeNode(")"); (yyvsp[-1].node) = new treeNode("ELSE");
                                            vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                            (yyval.node) = new treeNode("if_stmt", v);
                                            set_ifLongestPath((yyval.node)->maxSubtreeLength); 
                                        }
#line 2117 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 494 "a.y" /* yacc.c:1646  */
    { 
                            (yyvsp[-1].node) = new treeNode("RETURN"); (yyvsp[0].node) = new treeNode(";");
                            vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                            (yyval.node) = new treeNode("return_stmt", v);
                        }
#line 2127 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 499 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("RETURN"); (yyvsp[0].node) = new treeNode(";");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("return_stmt", v);
                                }
#line 2137 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 505 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[-1].node) = new treeNode("BREAK"); (yyvsp[0].node) = new treeNode(";");
                            vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                            (yyval.node) = new treeNode("break_stmt", v);
                        }
#line 2147 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 511 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1].node) = new treeNode("CONTINUE"); (yyvsp[0].node) = new treeNode(";");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("continue_stmt", v);
                            }
#line 2157 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 517 "a.y" /* yacc.c:1646  */
    {
                                                                        (yyvsp[-7].node) = new treeNode("SWITCH");
                                                                        (yyvsp[-6].node) = new treeNode("("); (yyvsp[-4].node) = new treeNode(")");
                                                                        (yyvsp[-3].node) = new treeNode("{"); (yyvsp[0].node) = new treeNode("}");
                                                                        vector<treeNode*> v = {(yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                        (yyval.node) = new treeNode("switch_stmt", v);
                                                                        set_switchLongestPath((yyval.node)->maxSubtreeLength);    
                                                                    }
#line 2170 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 526 "a.y" /* yacc.c:1646  */
    {
                                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("compound_case", v); 
                                            }
#line 2179 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 530 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("compound_case", v);
                            }
#line 2188 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 535 "a.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-3].node) = new treeNode("CASE"); (yyvsp[-1].node) = new treeNode(":");
                                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("single_case", v);
                                            }
#line 2198 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 541 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2].node) = new treeNode("DEFAULT"); (yyvsp[-1].node) = new treeNode(":");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("default_case", v);
                                    }
#line 2208 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 547 "a.y" /* yacc.c:1646  */
    {
                                        vector<treeNode*> u = {(yyvsp[-3].node), (yyvsp[-1].node)};
                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                        (yyvsp[0].node) = new treeNode(";");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("assign_stmt", v);
                                        
                                    }
#line 2221 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 555 "a.y" /* yacc.c:1646  */
    {   // check this one
                                                        (yyvsp[-5].node) = new treeNode("["); (yyvsp[-3].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                        vector<treeNode*> u = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("assign_stmt", v);    
                                                    }
#line 2233 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 562 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[0].node) = new treeNode(";");
                                                            (yyvsp[-4].node) = new treeNode("ARROW");
                                                            vector<treeNode*> u = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                            (yyvsp[-2].node) = new treeNode("EQ", u);
                                                            vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("assign_stmt", v);
                                                        }
#line 2246 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 570 "a.y" /* yacc.c:1646  */
    {
                                                        (yyvsp[0].node) = new treeNode(";");
                                                        (yyvsp[-4].node) = new treeNode(".");
                                                        vector<treeNode*> u = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("assign_stmt", v);
                                                    }
#line 2259 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 579 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode(";");
                                    (yyvsp[-1].node) = new treeNode("INC");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("incr_stmt", v);
                                }
#line 2270 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 586 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode(";");
                                    (yyvsp[-1].node) = new treeNode("DEC");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("decr_stmt", v);
                                }
#line 2281 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 593 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("LT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2292 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 599 "a.y" /* yacc.c:1646  */
    {   
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("GT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2303 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 605 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("LEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2314 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 611 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("GEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2325 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 617 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("OR", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2336 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 623 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-3].node) = new treeNode("SIZEOF"); (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("expr", v);
                            }
#line 2346 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 628 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("EQEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2357 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 634 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("NEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2368 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 640 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("NEWOP", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2379 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 646 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("AND", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2390 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 652 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("ARROW", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2401 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 658 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("PLUS", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2412 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 664 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MINUS", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2423 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 670 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MULT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2434 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 676 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("DIV", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2445 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 682 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MOD", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2456 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 688 "a.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].node) = new treeNode("NOT");
                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                    (yyval.node) = new treeNode("expr", v);
                }
#line 2466 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 693 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("MINUS");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2476 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 698 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("PLUS");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2486 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 703 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("MULT");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2496 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 708 "a.y" /* yacc.c:1646  */
    {   
                        (yyvsp[-1].node) = new treeNode("BITAND");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2506 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 713 "a.y" /* yacc.c:1646  */
    {
                vector<treeNode*> v = {(yyvsp[0].node)};
                (yyval.node) = new treeNode("expr", v);
            }
#line 2515 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 717 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("expr", v); 
                                }
#line 2525 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 722 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("["); (yyvsp[0].node) = new treeNode("]");
                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("expr", v); 
                                }
#line 2535 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 728 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
                    }
#line 2544 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 732 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("Pexpr", v);
                }
#line 2553 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 736 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
                    }
#line 2562 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 740 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
                    }
#line 2572 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 746 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("INTEGER_NUMBER");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("integerLit", v);
                                (yyval.node)->lexValue = mytext;
                                (yyval.node)->width = 4;
                                (yyval.node)->line_no = line_no;
                                (yyval.node)->isconst = 1;
                                (yyval.node)->value = strtol(mytext, NULL, 0);
                            }
#line 2587 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 757 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node) = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new treeNode("floatLit", v);
                            (yyval.node)->lexValue = mytext;
                            (yyval.node)->width = 8;
                            (yyval.node)->line_no = line_no;
                            (yyval.node)->isconst = 1;
                            (yyval.node)->value = strtol(mytext, NULL, 0);
                        }
#line 2602 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 768 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node) = new treeNode("IDENTIFIER");
                            vector<treeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new treeNode("identifier", v);
                            (yyval.node)->lexValue = mytext;
                            (yyval.node)->line_no = line_no;
                        }
#line 2614 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 775 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].node) = new treeNode("IDENTIFIER");
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("identifier", v);
                        (yyval.node)->lexValue = "printf";
                    }
#line 2625 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 782 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1].node) = new treeNode(",");
                                vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("arg_list", v);
                            }
#line 2635 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 787 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("arg_list", v);
                }
#line 2644 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 792 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("args", v);
                }
#line 2653 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 796 "a.y" /* yacc.c:1646  */
    {
            auto x = new treeNode("epsilon");
            vector<treeNode*> v = {x};
            (yyval.node) = new treeNode("args", v);
        }
#line 2663 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2667 "y.tab.cpp" /* yacc.c:1646  */
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
#line 802 "a.y" /* yacc.c:1906  */


void yyerror(char* s) {
    printf("***parsing terminated*** [syntax error]\n");
    exit(0);
}

void set_programLongestPath(int x) {
    programLongestPath = max(programLongestPath, x);
}

void set_ifLongestPath(int x) {
    ifLongestPath = max(ifLongestPath, x);
}

void set_whileLongestPath(int x) {
    whileLongestPath = max(whileLongestPath, x);
}

void set_switchLongestPath(int x) {
    switchLongestPath = max(switchLongestPath, x);
}

void set_mainLongestPath(int x) {
     mainLongestPath = max(mainLongestPath, x);
}


int compbexp(treeNode* node){
    int result = 0;
    int op1 = (nc[0])->value;
    int op2 = (nc[1])->value;
    //cerr<<"op1= "<<op1<<" op2 = "<<op2<<"\n";
    if(!(nc[0]->isconst && nc[1]->isconst)){
        return -1;
    }
    string name = node->nodeName;
    if(name == "LT"){
        result = op1 < op2;
    }
    else if(name == "GT"){
        result = op1 > op2;
    }
    else if(name == "LEQ"){
        result = op1 <= op2;
    }
    else if(name == "GEQ"){
        result = op1 >= op2;
    }
    else if(name == "OR"){
        result = op1 || op2;
    }
    else if(name == "EQEQ"){
        result = op1 == op2;
    }
    else if(name == "NEQ"){
        result = op1 != op2;
    }
    else if(name == "NEWOP"){
        result = (op1 < op2)?-1:((op1 == op2)?0:1);
    }
    else if(name == "AND"){
        result = op1 && op2;
    }
    else if(name == "PLUS"){
        //cerr<<(nc[0])->nodeName<<" op1 = "<<op1<<" op2 = "<<op2<<"\n";
        result = op1 + op2;
    }
    else if(name == "MINUS"){
        result = op1 - op2;
    }
    else if(name == "MULT"){
        result = op1 * op2;
    }
    else if(name == "DIV"){
        result = op1 / op2;
    }
    else if(name == "MOD"){
        result = op1 % op2;
    }
    node->value = result;
    if(name == "PLUS" or name == "MINUS" or name == "MULT" or name == "DIV"){
        if(constant_folding.count(node->line_no)){
            constant_folding[node->line_no] = max(constant_folding[node->line_no], result);
        }
        else{
            constant_folding[node->line_no] = result;
        }
    }
    return 0;
}
int compuexp(treeNode *node ){
    int result = 0;
    int op1 = nc[1]->value;
    if(!(nc[1]->isconst)){
        return -1;
    }
    string name = nc[0]->nodeName;
    if(name == "NOT"){
        result = !(op1);
    }
    else if(name == "MINUS"){
        result = -op1;
    }
    else if(name == "PLUS"){
        result = op1;
    }
    node->value = result;
    constant_folding[node->line_no] = max(constant_folding[node->line_no], result);
    return 0;
}
void fold(treeNode* node, int val){
    treeNode *nnode = new treeNode("integerLit");
    nnode->isconst = 1;
    nnode->value = val;
    nnode->lexValue = to_string(val);
    nnode->width = 4;
    nnode->line_no = node->line_no;
    vector<treeNode*> u = {nnode};
    treeNode *mnode = new treeNode("Pexpr", u);
    mnode->isconst = 1;
    mnode->value = val;
    //cerr<<val<<"\n";
    *node = *mnode;
}
void dfs(treeNode*);
void dfs(treeNode* node,unordered_map<string, int> &symbol_table, unordered_map<string, int> & isconst){
    if(node == nullptr){
        return;
    }
    else{
        string name = node->nodeName;
        if(name == "if_stmt"){                
            if(nc.size() == 5){ 
                prop_need = 0;                   
                dfs(nc[2]);
                prop_need = 1;                   
                if(nc[2]->isconst){                        
                    if(nc[2]->value){
                        if_else = 1;
                        dfs(nc[4]);
                        treeNode *nnode = new treeNode("stmt");
                        *nnode = *nc[4];
                        *node = *nnode;       
                    }
                    else{
                        if_else = 0;
                        node->nodeName = "if_gone";
                    }
                }
                else{                        
                    curr_symbol_table = symbol_table;
                    curr_isconst = isconst;
                    dfs(nc[4]);
                    if_symbol_table = symbol_table;
                    if_isconst = isconst;
                    symbol_table = curr_symbol_table;
                    isconst = curr_isconst;
                    for(auto ip: if_symbol_table){
                        if(ip.second != symbol_table[ip.first]){
                            isconst[ip.first] = 0;
                        }
                    }
                    for(auto ip: if_isconst){
                        if(ip.second == 0 or isconst[ip.first] == 0){
                            isconst[ip.first] = 0;
                        }
                    }
                }
            }         
            else if(nc.size() == 7){
                prop_need = 0;                   
                dfs(nc[2]);
                prop_need = 1;                   
                if(nc[2]->isconst){                        
                    if(nc[2]->value){
                        if_else = 1;
                        dfs(nc[4]);
                        treeNode *nnode = new treeNode("stmt");
                        *nnode = *nc[4];
                        *node = *nnode;       
                    }
                    else{
                        if_else = 0;
                        dfs(nc[6]);
                        treeNode *nnode = new treeNode("stmt");
                        *nnode = *nc[6];
                        *node = *nnode;       
                    }
                }
                else{                        
                    //if_symbol_table = symbol_table;
                    //if_isconst = isconst;
                    curr_symbol_table = symbol_table;
                    curr_isconst = isconst;
                    dfs(nc[4]);
                    if_symbol_table = symbol_table;
                    if_isconst = isconst;
                    //else_symbol_table = symbol_table;
                    //else_isconst = isconst;
                    symbol_table = curr_symbol_table;
                    isconst = curr_isconst;
                    dfs(nc[6]);
                    else_symbol_table = symbol_table;
                    else_isconst = isconst;
                    symbol_table = curr_symbol_table;
                    isconst = curr_isconst;
                    for(auto ip: if_symbol_table){
                        if(ip.second != else_symbol_table[ip.first]){
                            isconst[ip.first] = 0;
                        }
                    }
                    for(auto ip: if_isconst){
                        if(ip.second == 0 or else_isconst[ip.first] == 0){
                            isconst[ip.first] = 0;
                        }
                        else if(ip.second == 1 and else_isconst[ip.first] == 1){
                            if(if_symbol_table[ip.first] == else_symbol_table[ip.first]){
                                isconst[ip.first] = 1;
                            }
                        }
                    }
                    for(auto ip: if_symbol_table){
                        if(isconst.count(ip.first) and isconst[ip.first]){
                            if(ip.second == else_symbol_table[ip.first]){
                                symbol_table[ip.first] = ip.second;
                            }
                        }
                    }
                }
            }
            //(fstack.top()).print_stable();
            return;
        }
        else if(name == "while_stmt"){
            /* dfs(nc[2]);
            wcount = 0;
            while(nc[2]->val and ((wcount)++ < maxloop) and (!finish)){                    
                dfs(nc[4]);
                dfs(nc[2]);
            }                        
            return; */
        }
        else if(name == "func_decl"){                
            //hello
        }
        //cout<<name<<"\n"<<flush;
        if(nc.size())
        for(auto child : nc){
            dfs(child);
            if(child->isconst){
            if(name == "AND" and !(child->value))
            break;
            if(name == "OR" and child->value)
            break;
            } 
        }
        if(name == "identifier"){
            if(symbol_table.count(node->lexValue) == 0)
            symbol_table[node->lexValue] = 0;
            else node->value = symbol_table[node->lexValue];
            if(isconst[node->lexValue]){
                node->isconst = 1;
            }
        }
        else if(name == "local_decl"){
            if(nc.size() == 3){                    
                varlist.push_back(nc[1]->lexValue);       
            }
        }
        else if(name == "expr"){
            if(nc.size() == 1){
                treeNode* op = nc[0];
                if((op->children).size() == 2){
                    if( compbexp(op) == 0){
                        fold(node, op->value);
                    }
                }
                else if(op->nodeName == "Pexpr"){
                    if(nc[0]->isconst){
                        node->value = op->value;
                        node->isconst = 1;
                    }
                }
            }
            else if(nc.size() == 2){
                if(compuexp(node) == 0){
                    fold(node, node->value);
                }
            }
            else if(nc.size() == 4){
                if(nc[0]->nodeName == "SIZEOF")
                    {
                        if(nc[2]->isconst){
                            fold(node, nc[2]->width);
                        }
                    }
                else if(nc[1]->nodeName == "["){
                    
                }
                else if(nc[1]->nodeName == "("){
                   
                }
            }
        }
        else if(name == "Pexpr"){
            if(nc.size() == 3){ 
                if(nc[1]->isconst){
                    fold(node, nc[1]->value);
                    node->width = nc[1]->width;
                }                   
            }
            else{
                if(nc[0]->isconst){
                    //cerr<<nc[0]->lexValue<<" "<<nc[0]->value<<" "<<node->value<<"\n";
                    if(nc[0]->nodeName == "identifier" and prop_need){
                        constant_prop[node->line_no].push_back({nc[0]->lexValue, nc[0]->value});
                    }
                    fold(node, nc[0]->value);
                    node->width = nc[0]->width;
                }
                if(nc[0]->nodeName == "identifier"){
                    used[nc[0]->lexValue] = 1;
                }
            }
        }
        else if(name == "assign_stmt"){                
            //cout<<"hi";
            treeNode *eqnode = nc[0];
            if((eqnode->children).size() == 2){
            used[(nc[0]->children[0])->lexValue] = 1;
            if((nc[0]->children[1])->isconst){
                symbol_table[(nc[0]->children[0])->lexValue] = (nc[0]->children[1])->value;
                isconst[(nc[0]->children[0])->lexValue] = 1;
            }
            else{
                isconst[(nc[0]->children[0])->lexValue] = 0;
            }
            }
        }
        else if(name == "print_stmt"){
            //cout<<"hi";
            used[nc[4]->lexValue] = 1;
            if(nc[4]->isconst)
            constant_prop[node->line_no].push_back({nc[4]->lexValue, nc[4]->value});
        }
        else if(name == "scanf_stmt"){                
            nc[5]->isconst = 0;
            isconst[nc[5]->lexValue] = 0;
            used[nc[5]->lexValue] = 1;
        }
        else if(name == "return_stmt"){                
            if(nc.size() == 3){                    

            }
        }
    }
}
void dfs(treeNode* node){
    dfs(node, symbol_table, isconst);
}

void sr(treeNode* node){
    if(node == nullptr){
        return;
    }
    /*if(node->line_no == 27){
        cerr<<node->value<<" "<<node->nodeName<<"\n";
    }*/
    if(constant_folding.count(node->line_no) and node->nodeName == "integerLit"){
        constant_folding[node->line_no] = max(constant_folding[node->line_no], node->value);
    }
    for(auto child: nc){
        sr(child);
    }
    string name = node->nodeName;
    if(name == "MULT"){
        int va = nc[1]->value;
        //cerr<<va<<"\n";
        if(((va & (va - 1)) == 0) and va){
            int res = -1;
            while(va){
                res++;
                va = va >> 1;
            }
            fold(nc[1], res);
            node->nodeName = "SLEFTR";
            strength_reduction[node->line_no] = max(strength_reduction[node->line_no], res);
            constlist.insert(to_string(res));
        }
        va = nc[0]->value;
        if(((va & (va - 1)) == 0) and va){
            int res = -1;
            while(va){
                res++;
                va = va >> 1;
            }
            fold(nc[0], res);
            node->nodeName = "SLEFTL";
            strength_reduction[node->line_no] = max(strength_reduction[node->line_no], res);
            constlist.insert(to_string(res));
        }

        
    }
    if(name == "integerLit"){
        constlist.insert(node->lexValue);
    }
}
void sav(int x){
    if(x == 0){
        curr_value_number = value_number;
        curr_rev_value_number = rev_value_number;
        curr_global_counter = global_counter;
        curr_var_counter = var_counter;
    }
    else if(x == 1){
        if_value_number = value_number;
        if_rev_value_number = rev_value_number;
        if_var_counter = var_counter;
        value_number = curr_value_number;
        rev_value_number = curr_rev_value_number;
        var_counter = curr_var_counter;
        global_counter = curr_global_counter;
    }
    else{
        else_value_number = value_number;
        else_rev_value_number = rev_value_number;
        else_var_counter = var_counter;
        value_number = curr_value_number;
        rev_value_number = curr_rev_value_number;
        var_counter = curr_var_counter;
        global_counter = curr_global_counter;
    }
}
void cse(treeNode * node){
    if(node == nullptr) return;
    string name = node->nodeName;
    /*if(name == "if_stmt"){
        if(nc.size() == 5){
            cse(nc[2]);
            sav(0);
            cse(nc[4]);
            sav(1);
            //cerr<<"hi";
        }
        else if(nc.size() == 7){
            cse(nc[2]);
            sav(0);
            cse(nc[4]);
            sav(1);
            cse(nc[6]);
            sav(2);
            for(auto ip: if_var_counter){
                if(ip.second > var_counter[ip.first]){
                    global_counter++;
                    var_counter[ip.first]++;
                }
            }
            for(auto ip: else_var_counter){
                if(ip.second > var_counter[ip.first]){
                    global_counter++;
                    var_counter[ip.first]++;
                }
            }
        }
        return;
    }*/
    if(nc.size())
    for(auto child: nc){
        cse(child);
    }
    if(name == "Pexpr"){
        if(nc.size() == 3){
            node->numbering = nc[1]->numbering;
        }
        else{
            if(nc[0]->nodeName == "identifier"){
                vnentry entr = {nc[0]->lexValue + "$" + to_string(var_counter[nc[0]->lexValue]),{-1,-1}};
                if(value_number.count(entr))
                node->numbering = value_number[entr];
                else{
                    global_counter++;
                    value_number[entr] = global_counter;
                    rev_value_number[global_counter] = entr;
                    node->numbering = value_number[entr];
                }
            }
            else{
                vnentry entr = {nc[0]->lexValue,{-1,-1}};
                node->numbering = value_number[entr];
            }
        }
    }
    else if(name == "expr"){
            if(nc.size() == 1){
                treeNode* op = nc[0];
                if((op->children).size() == 2){
                    //cerr<<"hi\n";
                    int l = (op->children[0])->numbering;
                    int r = (op->children[1])->numbering;
                    vnentry entr =  {op->nodeName,{l,r}};
        //cerr<<entr.first<<" "<<entr.second.first<<" "<<entr.second.second<<"\n";
                    if(value_number.count(entr)){                            
                        csubexprs[value_number[entr]].insert(node->line_no);
                    } 
                    else{
                        global_counter++;
                        value_number[entr]=global_counter;
                        rev_value_number[global_counter]=entr;
                        csubexprs[value_number[entr]].insert(node->line_no);
                    }
                    //cerr<<value_number[entr]<<"\n";
                    node->numbering = value_number[entr];
                }
                else if(op->nodeName == "Pexpr"){
                    node->numbering = op->numbering;
                }
            }
    }
    else if(name == "assign_stmt"){
        treeNode *eqnode = nc[0];
        if((eqnode->children).size() == 2){
            var_counter[(eqnode->children[0])->lexValue]++;
            //global_counter++;
            //value_number[{node->lexValue + to_string(var_counter[node->lexValue]),{-1,-1}}] = global_counter;
            //rev_value_number[global_counter] = {node->lexValue + to_string(var_counter[node->lexValue]),{-1,-1}};
        }
    }
    else if(name == "scanf_stmt"){ 
        var_counter[nc[5]->lexValue]++;
    }               
}

int main() {
    yyparse();
    // printf("***parsing successful***\n");
    // printf("%d\n", programLongestPath);
    // printf("%d\n", ifLongestPath);
    // printf("%d\n", whileLongestPath);
    // printf("%d\n", switchLongestPath);
    // printf("%d\n", mainLongestPath);
    dfs(ast);
    for(auto ip: constant_folding){
        constant_folding[ip.first] = -1e9;
    }
    sr(ast);
    for (auto x: varlist){
        global_counter ++;
        value_number[{x+"$0",{-1,-1}}] = global_counter;
        rev_value_number[global_counter] = {x+"$0",{-1,-1}};
    }
    for (auto x: constlist){
        global_counter ++;
        value_number[{x,{-1,-1}}] = global_counter;
        rev_value_number[global_counter] = {x,{-1,-1}};
    }
    cse(ast);
    //printAST(ast);
    for(auto var: varlist){
        if(!(used.count(var))){
            if(var == "main") continue;
            summary[0].push_back(var);
        }
    }
    if(if_else != -1){
        summary[1].push_back(to_string(if_else));
    }
    for(auto ip : strength_reduction){
        summary[2].push_back(to_string(ip.first + 1) + " " + to_string(ip.second));
    }
    for(auto ip: constant_folding){
        if(ip.second != -1e9)
        summary[3].push_back(to_string(ip.first + 1) + " " + to_string(ip.second));
    }
    map<string, int> index;
    for(int i=0; i<varlist.size(); i++){
        index[varlist[i]] = i; 
    }
    map<int, set< pair<int, pair< string, int > > > > constant_prop_ord;
    for(auto ip: constant_prop){
        for(auto pa: ip.second){
            constant_prop_ord[ip.first].insert({index[pa.first],pa});
        }
    }
    for(auto ip: constant_prop_ord){
        string su = to_string(ip.first+1);
        string st = "";
        for(auto pa: ip.second){
            //if(isconst[pa.first])
            st += (" " + pa.second.first + " " + to_string(pa.second.second));
        }
        if(st.size())
        summary[4].push_back(su+st);
    }
    for(auto ip: csubexprs){
        //cerr<<ip.first<<"\n";
        if(ip.second.size() == 1){
            continue;
        }
        vnentry x = rev_value_number[ip.first];
        //cerr<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
        if(x.second.first == -1 or x.second.first == 0){
            continue;
        }
        //cerr<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
        string su =  "";
        for(auto line: ip.second){
            su += (" " + to_string(line+1));
        }
        summary[5].push_back(su.substr(1));
    }
    int a = generateIR();   // generate 3AC intermediate representation
    ofstream summ;
    summ.open("summary.txt");
    for(int i=0; i<6; i++){
        summ<<opti_list[i]<<"\n";
        for(auto line: summary[i]){
            summ<<line<<"\n";
        }
        if(i<5)
        summ<<"\n";
    }
    summ.close();
    return 0;
}
