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
#line 2 "a1.y" /* yacc.c:339  */

        
	#include <stdio.h>
        #include <string.h>
        #include <stdlib.h>
        void yyerror(char *);
        int yylex(void);
        char mytext[100];
        char var[100];
        int num = 0;
        extern char *yytext;
        extern FILE *yyin;
        extern int yylineno;
        int er = 0;
        int yydebug = 1;
        int global_declarations = 0;
        int function_definitions = 0;
        int integer_constants = 0;
        int local_pointer = 0;
        int pointers_declarations = 0;
        int ifs_without_else = 0;
        int max_depth = 0;
        #define max(x, y) (x>=y?x:y) 

#line 91 "y.tab.c" /* yacc.c:339  */

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
    VARIABLE = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    COL = 262,
    COM = 263,
    CONTINUE = 264,
    DEFAULT = 265,
    DO = 266,
    DOUBLE = 267,
    ELSE = 268,
    ERR = 269,
    EXTERN = 270,
    FLOAT = 271,
    FOR = 272,
    IF = 273,
    INT = 274,
    LONG = 275,
    RETURN = 276,
    SHORT = 277,
    SIZEOF = 278,
    STRUCT = 279,
    SWITCH = 280,
    VOID = 281,
    WHILE = 282,
    LSQ = 283,
    RSQ = 284,
    LPA = 285,
    RPA = 286,
    LCU = 287,
    RCU = 288,
    DOT = 289,
    ARROW = 290,
    PINC = 291,
    PDEC = 292,
    BAND = 293,
    MUL = 294,
    ADD = 295,
    SUB = 296,
    NEG = 297,
    NOT = 298,
    DIV = 299,
    MOD = 300,
    LESS = 301,
    GRTR = 302,
    LEQ = 303,
    GEQ = 304,
    EEQ = 305,
    EQ = 306,
    NEQ = 307,
    XOR = 308,
    OR = 309,
    BOR = 310,
    AND = 311,
    TWAY = 312,
    SCONST = 313,
    SCOLON = 314,
    FCONST = 315,
    ICONST = 316,
    CCONST = 317,
    DUMMY = 318
  };
#endif
/* Tokens.  */
#define VARIABLE 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define COL 262
#define COM 263
#define CONTINUE 264
#define DEFAULT 265
#define DO 266
#define DOUBLE 267
#define ELSE 268
#define ERR 269
#define EXTERN 270
#define FLOAT 271
#define FOR 272
#define IF 273
#define INT 274
#define LONG 275
#define RETURN 276
#define SHORT 277
#define SIZEOF 278
#define STRUCT 279
#define SWITCH 280
#define VOID 281
#define WHILE 282
#define LSQ 283
#define RSQ 284
#define LPA 285
#define RPA 286
#define LCU 287
#define RCU 288
#define DOT 289
#define ARROW 290
#define PINC 291
#define PDEC 292
#define BAND 293
#define MUL 294
#define ADD 295
#define SUB 296
#define NEG 297
#define NOT 298
#define DIV 299
#define MOD 300
#define LESS 301
#define GRTR 302
#define LEQ 303
#define GEQ 304
#define EEQ 305
#define EQ 306
#define NEQ 307
#define XOR 308
#define OR 309
#define BOR 310
#define AND 311
#define TWAY 312
#define SCONST 313
#define SCOLON 314
#define FCONST 315
#define ICONST 316
#define CCONST 317
#define DUMMY 318

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

#line 268 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   125,   128,   127,   135,   137,   139,   140,
     143,   144,   147,   148,   154,   155,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   169,   170,   173,   174,   177,
     178,   182,   182,   183,   183,   187,   187,   188,   188,   191,
     192,   195,   198,   200,   203,   204,   204,   207,   211,   214,
     215,   216,   219,   220,   221,   224,   225,   227,   228,   232,
     233,   236,   238,   242,   243,   247,   249,   251,   253,   255,
     257,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     278,   280,   282,   284,   286,   288,   290,   292,   294,   296,
     298,   300,   302,   304,   307,   310,   317,   321,   325,   326,
     329,   332,   335,   338,   342,   349,   350,   353,   355,   359,
     363,   364,   365,   366,   367,   368,   371,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   391,   392,   395,   398,   399,   402,   403,
     405,   408,   409,   410,   411,   414,   415,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   432,
     433,   434,   435,   436,   437,   440,   441,   444,   445
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VARIABLE", "BREAK", "CASE", "CHAR",
  "COL", "COM", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ERR",
  "EXTERN", "FLOAT", "FOR", "IF", "INT", "LONG", "RETURN", "SHORT",
  "SIZEOF", "STRUCT", "SWITCH", "VOID", "WHILE", "LSQ", "RSQ", "LPA",
  "RPA", "LCU", "RCU", "DOT", "ARROW", "PINC", "PDEC", "BAND", "MUL",
  "ADD", "SUB", "NEG", "NOT", "DIV", "MOD", "LESS", "GRTR", "LEQ", "GEQ",
  "EEQ", "EQ", "NEQ", "XOR", "OR", "BOR", "AND", "TWAY", "SCONST",
  "SCOLON", "FCONST", "ICONST", "CCONST", "DUMMY", "$accept", "program",
  "declaration_list", "@1", "declaration", "var_declaration",
  "svar_declaration", "svar_declaration_list", "basic_type", "type",
  "pointer_type", "stars", "var_list", "$@2", "$@3", "svar_list", "$@4",
  "$@5", "var_dec", "svar_dec", "var_dec_lhs", "var_id", "$@6",
  "fun_declaration", "fun_prototype", "proto_param_list", "proto_params",
  "nd_bracket", "struct_definition", "decl_statement", "statement_list",
  "compound_statement", "statement", "lstatement", "if_statement",
  "while_statement", "switch_statement", "return_statement",
  "case_statement", "continue_statement", "break_statement",
  "default_statement", "assign_statement", "exp_wrap", "for_statement",
  "do_statement", "expression", "cast_expression", "term", "lhs",
  "function_call", "arguments", "argument_list", "expression_statement",
  "constants", "multisconsts", "binary_operator", "relational_operator",
  "logical_operator", "unary_operator", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF -210

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-210)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1106,  -210,  -210,  -210,  -210,  -210,  -210,  -210,    18,  -210,
       5,  -210,    24,  -210,  -210,   612,  -210,  -210,  -210,     7,
    -210,  1106,  -210,    38,  -210,  -210,  -210,  -210,    44,    52,
      35,  1121,  -210,  -210,    59,    11,    65,   520,   520,  1121,
    1121,    78,   634,  -210,  -210,    59,    90,   105,   387,   520,
     561,   561,   561,   561,   561,   561,  -210,  -210,    69,  -210,
    -210,  -210,   110,   982,   561,   -29,   115,  -210,  -210,  -210,
     561,   982,  1037,  -210,   122,   146,  -210,    28,  -210,  -210,
     150,   131,  -210,  -210,   520,   438,  1058,   132,   792,   817,
     520,   109,   109,   109,   109,   109,   109,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,   520,
     520,   520,   109,  -210,  -210,   520,   520,   109,    68,  -210,
     137,    54,  1121,  -210,  -210,   107,   160,   982,   139,   169,
     147,    79,   141,  -210,  -210,  -210,   982,   982,   982,   982,
     846,  -210,   152,   154,   230,  -210,  -210,  -210,  -210,    59,
    -210,   520,  -210,  -210,  -210,  -210,   155,   124,   520,   129,
     182,   336,   162,   163,   479,   164,   165,   230,  -210,  -210,
    -210,   612,  -210,  -210,   168,  -210,   290,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,   679,    97,
    -210,  -210,  1054,  -210,  -210,   764,  -210,   290,  -210,  -210,
     175,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,   387,   520,  -210,   707,   520,   520,   651,
    -210,  -210,  -210,   520,   290,  -210,   173,   520,   145,   874,
    -210,   902,   930,   735,  -210,   520,   148,   520,   336,   336,
     336,  -210,   958,   520,   158,   192,  -210,  -210,   159,   178,
     520,   336,  -210,   336,   180,  -210,  -210,   336,  -210
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    24,    23,    17,    16,    21,    22,     0,    19,
       0,     2,     4,     6,    25,     0,     7,     8,     9,    20,
       1,     0,    44,     0,    45,    11,    26,    10,    31,    39,
      42,     0,     5,    20,     0,     0,     0,   105,     0,    49,
      14,     0,     0,    46,    32,     0,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   168,   145,   143,
     141,   142,     0,   106,     0,   115,   128,   130,   129,   144,
       0,    40,    27,    52,     0,    50,    15,     0,    13,    12,
      35,    41,    42,    34,   137,     0,    27,     0,     0,     0,
       0,   124,   125,   121,   120,   118,   117,   146,    43,   158,
     157,   156,   152,   149,   147,   148,   150,   151,   161,   162,
     160,   163,   159,   164,   154,   166,   153,   165,   155,     0,
       0,     0,   114,   122,   123,     0,     0,   119,    29,    28,
      53,     0,    49,    57,    58,     0,     0,   138,     0,   136,
       0,     0,    29,   116,   131,   132,   111,   112,   113,   110,
       0,    30,     0,    54,     0,    48,    47,    51,    36,     0,
     135,     0,   127,   126,   134,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    79,
      59,     0,    60,    66,     0,    65,    61,    67,    68,    69,
      70,    72,    75,    71,    76,    73,    74,    77,     0,   115,
      78,    38,   139,    56,   102,     0,   101,     0,    93,    80,
       0,    81,    82,    83,    84,    86,    89,    85,    90,    87,
      88,    91,    92,   105,     0,    98,     0,     0,     0,     0,
      64,    62,   140,     0,     0,   103,     0,   105,     0,     0,
      99,     0,     0,   110,   100,     0,     0,   105,     0,     0,
       0,   104,     0,   105,     0,    94,    97,    96,     0,     0,
     105,     0,   109,     0,     0,    95,   108,     0,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,   185,  -210,  -210,     2,  -210,   179,   -12,     6,
       8,   -14,    -9,  -210,  -210,    61,  -210,  -210,  -210,  -210,
     -38,    25,  -210,  -210,  -210,    89,  -210,  -210,    81,  -210,
    -173,  -122,  -210,   -88,  -144,  -129,  -128,  -111,   -85,   -82,
     -78,   -77,   -60,  -209,   -36,   -22,   -37,  -210,   -35,  -210,
    -210,  -210,  -210,   -10,  -210,   171,  -210,  -210,  -210,  -210
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    21,    12,   180,    40,    41,    14,   181,
      73,   129,    27,    35,    36,    79,   135,   136,    28,    80,
      29,    82,    34,    16,    17,    74,    75,   153,   182,   183,
     184,   209,   186,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,    62,   220,   221,   198,    64,    65,    66,
      67,   138,   139,   222,    68,    69,   119,   120,   121,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    71,    13,    26,    81,    20,    15,   123,   124,   156,
     187,    88,    89,   231,   238,    91,    92,    93,    94,    95,
      96,    19,   125,    13,    -3,   188,   189,    15,   246,   122,
      26,    22,   185,   187,   235,   127,    83,    42,   254,    31,
      30,    33,   187,   190,   259,    72,    42,   137,   188,   189,
     141,   264,   -33,    88,    86,   185,    87,   188,   189,    43,
      26,   244,    22,   187,   185,    39,   190,    24,   134,   191,
      44,   -45,   192,    45,    26,   190,   193,   194,   188,   189,
      37,    18,   146,   147,   148,   185,   154,   133,   149,   150,
     187,    86,   191,   140,   195,   192,   190,   130,    24,   193,
     194,   191,    18,    38,   192,   188,   189,   142,   193,   194,
     163,    77,   185,   155,   151,   123,   124,   195,   196,   199,
      84,    81,   191,   190,   202,   192,   195,    58,   151,   193,
     194,   205,   197,   123,   124,    85,   199,   226,    72,    98,
     229,   196,   199,   126,   200,   123,   124,   195,   233,   191,
     196,   199,   192,   131,   132,   197,   193,   194,   -37,    37,
     255,   256,   257,   143,   197,   152,   158,   200,   159,    26,
     160,   196,   199,   265,   195,   266,   200,   161,   162,   268,
     142,   165,   166,   204,   203,   197,    63,   239,   206,   207,
     241,   242,   223,   224,   227,   228,   243,   200,   196,   199,
      63,   230,   236,   245,   247,   261,    32,   253,   252,   263,
      63,   267,   197,   199,   199,   199,    63,   260,   262,    76,
     201,   157,     0,    63,   200,   237,   199,     0,   199,    97,
       0,     0,   199,    46,   167,   168,     1,     0,     0,   169,
     170,   171,     2,     0,     0,     3,     4,   172,   173,     5,
       6,   174,     7,    47,     8,   175,     9,   176,     0,     0,
      48,     0,   177,   178,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,   179,
      59,    60,    61,    46,   167,   168,     1,     0,     0,   169,
     170,   171,     2,     0,     0,     3,     4,   172,   173,     5,
       6,   174,     7,    47,     8,   175,     9,   176,     0,     0,
      48,     0,   177,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,    46,
     167,   168,     0,     0,     0,   169,   170,   171,    58,   179,
      59,    60,    61,   172,   173,     0,     0,   174,     0,    47,
       0,   175,     0,   176,     0,     0,    48,     0,   177,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     1,    58,   208,    59,    60,    61,     2,
       0,     0,     3,     4,     0,     0,     5,     6,     0,     7,
      47,    23,     0,     9,     0,     0,     0,    48,     0,    49,
       0,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     1,    58,     0,    59,    60,    61,
       2,     0,     0,     3,     4,     0,     0,     5,     6,     0,
       7,    47,    23,     0,     9,     0,     0,     0,    90,     0,
      49,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,    59,    60,
      61,     0,    47,     0,     0,     0,     0,     0,     0,    48,
       0,    49,     0,     0,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,   225,    59,
      60,    61,     0,    47,     0,     0,     0,     0,     0,     0,
      48,     0,    49,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
      59,    60,    61,     0,    47,     0,     0,     0,     0,     0,
       0,    90,     0,    49,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     1,    58,
       0,    59,    60,    61,     2,     0,     0,     3,     4,     0,
       0,     5,     6,     0,     7,     0,    23,    22,     9,     0,
       1,     0,     0,     0,     0,     0,     2,     0,     0,     3,
       4,    24,     0,     5,     6,     0,     7,     0,    23,    99,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   100,   101,    99,     0,   102,
     103,   104,   105,    78,     0,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,   118,     0,
     232,     0,     0,   100,   101,    99,     0,   102,   103,   104,
     105,     0,     0,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,   117,   118,     0,   232,     0,
       0,   100,   101,    99,     0,   102,   103,   104,   105,     0,
       0,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,   118,     0,   240,     0,     0,   100,
     101,   234,    99,   102,   103,   104,   105,     0,     0,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,   118,     0,   251,     0,     0,     0,   100,   101,
      99,     0,   102,   103,   104,   105,     0,     0,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,   118,     0,   144,     0,    99,   100,   101,     0,     0,
     102,   103,   104,   105,     0,     0,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,   118,
     145,   100,   101,     0,    99,   102,   103,   104,   105,     0,
       0,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,   118,   164,     0,     0,     0,     0,
     100,   101,    99,     0,   102,   103,   104,   105,     0,     0,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   118,     0,   248,     0,     0,   100,   101,
      99,     0,   102,   103,   104,   105,     0,     0,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,   118,     0,   249,     0,     0,   100,   101,    99,     0,
     102,   103,   104,   105,     0,     0,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,   118,
       0,   250,     0,     0,   100,   101,    99,     0,   102,   103,
     104,   105,     0,     0,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,   118,     0,   258,
      99,     0,   100,   101,     0,     0,   102,   103,   104,   105,
       0,     0,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,   118,   100,   101,     0,     0,
     102,   103,   104,   105,     0,     0,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,   118,
      22,     0,     0,     1,     0,     0,     0,     0,     0,     2,
       0,     0,     3,     4,     0,     0,     5,     6,     0,     7,
       0,    23,     0,     9,     1,     0,     0,     0,     0,     0,
       2,     0,     0,     3,     4,     0,   128,     5,     6,     0,
       7,     0,    23,     0,     9,     0,     0,     0,   100,   101,
       0,     0,   102,   103,   104,   105,     0,   142,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,   118,     1,     0,     0,     0,     0,     0,     2,     0,
       0,     3,     4,     0,     0,     5,     6,     1,     7,     0,
       8,     0,     9,     2,     0,     0,     3,     4,     0,     0,
       5,     6,     0,     7,     0,    23,     0,     9
};

static const yytype_int16 yycheck[] =
{
      37,    38,     0,    15,    42,     0,     0,    36,    37,   131,
     154,    48,    49,   186,   223,    50,    51,    52,    53,    54,
      55,     3,    51,    21,     0,   154,   154,    21,   237,    64,
      42,     3,   154,   177,   207,    70,    45,    31,   247,    32,
      15,     3,   186,   154,   253,    39,    40,    84,   177,   177,
      85,   260,     8,    90,    48,   177,    48,   186,   186,    34,
      72,   234,     3,   207,   186,    30,   177,    39,    77,   154,
      59,     3,   154,     8,    86,   186,   154,   154,   207,   207,
      28,     0,   119,   120,   121,   207,    32,    59,   125,   126,
     234,    85,   177,    85,   154,   177,   207,    72,    39,   177,
     177,   186,    21,    51,   186,   234,   234,    39,   186,   186,
      31,    33,   234,    59,   128,    36,    37,   177,   154,   154,
      30,   159,   207,   234,   161,   207,   186,    58,   142,   207,
     207,   168,   154,    36,    37,    30,   171,   174,   132,    29,
     177,   177,   177,    28,   154,    36,    37,   207,    51,   234,
     186,   186,   234,    31,     8,   177,   234,   234,     8,    28,
     248,   249,   250,    31,   186,    28,    59,   177,     8,   181,
      31,   207,   207,   261,   234,   263,   186,     8,    31,   267,
      39,    29,    28,    59,    29,   207,   223,   224,    59,     7,
     227,   228,    30,    30,    30,    30,   233,   207,   234,   234,
     237,    33,    27,    30,    59,    13,    21,    59,   245,    31,
     247,    31,   234,   248,   249,   250,   253,    59,    59,    40,
     159,   132,    -1,   260,   234,   223,   261,    -1,   263,    58,
      -1,    -1,   267,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    32,    33,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    58,    59,
      60,    61,    62,    17,    18,    -1,    -1,    21,    -1,    23,
      -1,    25,    -1,    27,    -1,    -1,    30,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,    58,    59,    60,    61,    62,    12,
      -1,    -1,    15,    16,    -1,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    -1,    -1,    30,    -1,    32,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,     6,    58,    -1,    60,    61,    62,
      12,    -1,    -1,    15,    16,    -1,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    -1,    -1,    -1,    30,    -1,
      32,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,
      62,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      60,    61,    62,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    58,
      -1,    60,    61,    62,    12,    -1,    -1,    15,    16,    -1,
      -1,    19,    20,    -1,    22,    -1,    24,     3,    26,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    15,
      16,    39,    -1,    19,    20,    -1,    22,    -1,    24,     8,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,     8,    -1,    38,
      39,    40,    41,    59,    -1,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      59,    -1,    -1,    34,    35,     8,    -1,    38,    39,    40,
      41,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    59,    -1,
      -1,    34,    35,     8,    -1,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    59,    -1,    -1,    34,
      35,     7,     8,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    -1,    34,    35,
       8,    -1,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    31,    -1,     8,    34,    35,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      33,    34,    35,    -1,     8,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    29,    -1,    -1,    -1,    -1,
      34,    35,     8,    -1,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    -1,    31,    -1,    -1,    34,    35,
       8,    -1,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    -1,    31,    -1,    -1,    34,    35,     8,    -1,
      38,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      -1,    31,    -1,    -1,    34,    35,     8,    -1,    38,    39,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    -1,    31,
       8,    -1,    34,    35,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    34,    35,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
       3,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    15,    16,    -1,    -1,    19,    20,    -1,    22,
      -1,    24,    -1,    26,     6,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    15,    16,    -1,    39,    19,    20,    -1,
      22,    -1,    24,    -1,    26,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    40,    41,    -1,    39,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,     6,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    15,    16,    -1,    -1,    19,    20,     6,    22,    -1,
      24,    -1,    26,    12,    -1,    -1,    15,    16,    -1,    -1,
      19,    20,    -1,    22,    -1,    24,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    12,    15,    16,    19,    20,    22,    24,    26,
      65,    66,    68,    69,    72,    73,    87,    88,    92,     3,
       0,    67,     3,    24,    39,    59,    72,    76,    82,    84,
      85,    32,    66,     3,    86,    77,    78,    28,    51,    30,
      70,    71,    73,    85,    59,     8,     3,    23,    30,    32,
      36,    37,    38,    39,    40,    41,    42,    43,    58,    60,
      61,    62,   107,   110,   111,   112,   113,   114,   118,   119,
     123,   110,    73,    74,    89,    90,    71,    33,    59,    79,
      83,    84,    85,    76,    30,    30,    73,    74,   110,   110,
      30,   112,   112,   112,   112,   112,   112,   119,    29,     8,
      34,    35,    38,    39,    40,    41,    44,    45,    46,    47,
      48,    49,    50,    52,    53,    54,    55,    56,    57,   120,
     121,   122,   112,    36,    37,    51,    28,   112,    39,    75,
      85,    31,     8,    59,    76,    80,    81,   110,   115,   116,
      74,   112,    39,    31,    31,    33,   110,   110,   110,   110,
     110,    75,    28,    91,    32,    59,    95,    89,    59,     8,
      31,     8,    31,    31,    29,    29,    28,     4,     5,     9,
      10,    11,    17,    18,    21,    25,    27,    32,    33,    59,
      69,    73,    92,    93,    94,    95,    96,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   108,   109,   110,   112,
     117,    79,   110,    29,    59,   110,    59,     7,    59,    95,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     108,   109,   117,    30,    30,    59,   110,    30,    30,   110,
      33,    94,    59,    51,     7,    94,    27,    69,   107,   110,
      59,   110,   110,   110,    94,    30,   107,    59,    31,    31,
      31,    59,   110,    59,   107,    97,    97,    97,    31,   107,
      59,    13,    59,    31,   107,    97,    97,    31,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    67,    66,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    77,    76,    78,    76,    80,    79,    81,    79,    82,
      82,    83,    84,    84,    85,    86,    85,    87,    88,    89,
      89,    89,    90,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    99,   100,   101,   101,
     102,   103,   104,   105,   106,   107,   107,   108,   108,   109,
     110,   110,   110,   110,   110,   110,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   114,   115,   115,   116,   116,
     117,   118,   118,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   121,   122,   122,   123,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     3,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       2,     0,     3,     0,     4,     0,     3,     0,     4,     1,
       3,     1,     1,     4,     1,     0,     3,     6,     6,     0,
       1,     3,     1,     2,     3,     2,     3,     6,     6,     1,
       1,     1,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     5,     5,     2,     3,
       4,     2,     2,     3,     4,     0,     1,     9,     8,     7,
       3,     3,     3,     3,     2,     1,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     4,     1,     1,
       1,     3,     3,     1,     4,     4,     1,     0,     1,     3,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 122 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]); max_depth = max(max_depth, (yyval));}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 126 "a1.y" /* yacc.c:1646  */
    {global_declarations++;(yyval) = max((yyval), (yyvsp[0]));}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 128 "a1.y" /* yacc.c:1646  */
    {global_declarations++;}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 130 "a1.y" /* yacc.c:1646  */
    {(yyval) = max((yyvsp[-2]), (yyvsp[-1]));
                    //printf("%d", $$);
                    max_depth = max(max_depth, (yyval));}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 136 "a1.y" /* yacc.c:1646  */
    {(yyval) = 0;}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 138 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 158 "a1.y" /* yacc.c:1646  */
    {/*printf("found int\n");*/}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 162 "a1.y" /* yacc.c:1646  */
    {/*printf("hey struct %s\n", yytext);*/}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 182 "a1.y" /* yacc.c:1646  */
    {/*printf("var %s found\n", yytext);*/}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 183 "a1.y" /* yacc.c:1646  */
    {/*printf("var %s found\n", yytext);*/}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 187 "a1.y" /* yacc.c:1646  */
    {/*printf("var %s found\n", yytext);*/}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 188 "a1.y" /* yacc.c:1646  */
    {/*printf("var %s found\n", yytext);*/}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 203 "a1.y" /* yacc.c:1646  */
    {local_pointer = 0;}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 204 "a1.y" /* yacc.c:1646  */
    {local_pointer++; if(local_pointer == 1) pointers_declarations++;}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 208 "a1.y" /* yacc.c:1646  */
    {function_definitions++; (yyval) = (yyvsp[0]);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 229 "a1.y" /* yacc.c:1646  */
    {/*printf("struct found");*/}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 237 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 239 "a1.y" /* yacc.c:1646  */
    {(yyval) = max((yyvsp[-1]), (yyvsp[0]));}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 244 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 248 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 250 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 252 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 254 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 256 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 258 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 260 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 262 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 264 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 266 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 268 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 270 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 272 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 274 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 279 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 281 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 283 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 285 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 287 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 289 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 291 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 293 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 295 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 297 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 299 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 301 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 303 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 308 "a1.y" /* yacc.c:1646  */
    {ifs_without_else++;
                (yyval) = (yyvsp[0]);}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 311 "a1.y" /* yacc.c:1646  */
    {(yyval) = max((yyvsp[-2]), 1 + (yyvsp[0]));
                max_depth = max(max_depth, (yyval));
                //printf("%d", $$);
                }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 318 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 322 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 339 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 354 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 356 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 360 "a1.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-5]);}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 408 "a1.y" /* yacc.c:1646  */
    {integer_constants++;}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 409 "a1.y" /* yacc.c:1646  */
    {integer_constants++;}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2069 "y.tab.c" /* yacc.c:1646  */
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
#line 448 "a1.y" /* yacc.c:1906  */


void yyerror(char *s) {
    er++;
    if(er == 1){
        fprintf(stdout, "***parsing terminated*** [syntax error]\n");
        //fprintf(stdout, "lineno = %d", yylineno);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf("***process terminated*** [input error]: invalid number of command-line arguments\n");
    }
    else{
        yyin = fopen(argv[1], "r");
        if(yyin == NULL){
            printf("***process terminated*** [input error]: no such file %s exists\n", argv[1]);
        }
        else{
            yyparse();
            if(er == 0){
                printf("***parsing successful***\n");
                printf("#global_declarations = %d\n", global_declarations);
                printf("#function_definitions = %d\n", function_definitions);
                printf("#integer_constants = %d\n", integer_constants);
                printf("#pointers_declarations = %d\n", pointers_declarations);
                printf("#ifs_without_else = %d\n", ifs_without_else);
                printf("if-else max-depth = %d\n", max_depth);
            }
        }
    }
    return 0;
}

