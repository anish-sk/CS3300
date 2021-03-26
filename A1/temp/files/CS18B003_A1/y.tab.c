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
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	extern FILE *yyin;
	int ic=0, ifc=0, fc=0, ptr=0, glb=0, mxie=0, ieb=0;
	int flcs=1;

#line 76 "y.tab.c" /* yacc.c:339  */

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
    FOR = 258,
    DO = 259,
    WHILE = 260,
    IF = 261,
    SL = 262,
    XR = 263,
    IDEN = 264,
    CUR = 265,
    COL = 266,
    OC = 267,
    DOT = 268,
    STRING_LITERAL = 269,
    SIZEOF = 270,
    CM = 271,
    CC = 272,
    SC = 273,
    IC = 274,
    FC = 275,
    ELSE = 276,
    SWITCH = 277,
    DEFAULT = 278,
    CASE = 279,
    BREAK = 280,
    CONTINUE = 281,
    RETURN = 282,
    INT = 283,
    LONG = 284,
    SHORT = 285,
    FLOAT = 286,
    DOUBLE = 287,
    VOID = 288,
    CHAR = 289,
    EXTERN = 290,
    STRUCT = 291,
    NEW = 292,
    EQ = 293,
    GE = 294,
    LE = 295,
    NE = 296,
    AND = 297,
    OR = 298,
    INC = 299,
    DEC = 300,
    NN = 301,
    GT = 302,
    LT = 303,
    ASS = 304,
    PLS = 305,
    MIN = 306,
    NEG = 307,
    MUL = 308,
    AMP = 309,
    DIV = 310,
    MOD = 311,
    OP = 312,
    CP = 313,
    OB = 314,
    CB = 315
  };
#endif
/* Tokens.  */
#define FOR 258
#define DO 259
#define WHILE 260
#define IF 261
#define SL 262
#define XR 263
#define IDEN 264
#define CUR 265
#define COL 266
#define OC 267
#define DOT 268
#define STRING_LITERAL 269
#define SIZEOF 270
#define CM 271
#define CC 272
#define SC 273
#define IC 274
#define FC 275
#define ELSE 276
#define SWITCH 277
#define DEFAULT 278
#define CASE 279
#define BREAK 280
#define CONTINUE 281
#define RETURN 282
#define INT 283
#define LONG 284
#define SHORT 285
#define FLOAT 286
#define DOUBLE 287
#define VOID 288
#define CHAR 289
#define EXTERN 290
#define STRUCT 291
#define NEW 292
#define EQ 293
#define GE 294
#define LE 295
#define NE 296
#define AND 297
#define OR 298
#define INC 299
#define DEC 300
#define NN 301
#define GT 302
#define LT 303
#define ASS 304
#define PLS 305
#define MIN 306
#define NEG 307
#define MUL 308
#define AMP 309
#define DIV 310
#define MOD 311
#define OP 312
#define CP 313
#define OB 314
#define CB 315

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

#line 247 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   856

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  204
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  342

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    13,    13,    15,    15,    15,    16,    16,    16,    16,
      17,    17,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,    18,    20,    20,    22,    22,    23,    23,
      23,    23,    23,    23,    26,    26,    27,    27,    28,    28,
      28,    28,    28,    29,    29,    29,    29,    31,    31,    32,
      32,    34,    35,    35,    36,    36,    37,    37,    38,    38,
      40,    40,    40,    40,    41,    41,    45,    45,    46,    46,
      46,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    63,    63,    67,    67,
      68,    69,    69,    69,    70,    70,    70,    70,    71,    71,
      71,    71,    73,    74,    74,    74,    75,    75,    76,    76,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    83,    83,    84,    84,    85,    85,
      89,    89,    90,    90,    90,    91,    92,    93,    93,    93,
      93,    94,    94,    95,    95,    96,    97,    98,    98,    98,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FOR", "DO", "WHILE", "IF", "SL", "XR",
  "IDEN", "CUR", "COL", "OC", "DOT", "STRING_LITERAL", "SIZEOF", "CM",
  "CC", "SC", "IC", "FC", "ELSE", "SWITCH", "DEFAULT", "CASE", "BREAK",
  "CONTINUE", "RETURN", "INT", "LONG", "SHORT", "FLOAT", "DOUBLE", "VOID",
  "CHAR", "EXTERN", "STRUCT", "NEW", "EQ", "GE", "LE", "NE", "AND", "OR",
  "INC", "DEC", "NN", "GT", "LT", "ASS", "PLS", "MIN", "NEG", "MUL", "AMP",
  "DIV", "MOD", "OP", "CP", "OB", "CB", "$accept", "program", "mlines",
  "$@1", "moneline", "lines", "oneline", "init_list", "function_dec",
  "param_list_dec", "function", "inner_fun", "param_list", "mul_brack",
  "left", "left1", "fcall", "mul_idens", "param_list_call", "mul_exp12",
  "flow", "arr", "init", "expression", "exp0", "exp1", "exp2", "$@2",
  "$@3", "$@4", "exp3", "exp4", "exp5", "exp6", "exp7", "exp8", "exp9",
  "exp10", "exp11", "exp12", "unary_ops", "muls", "sums", "rels", "eqas",
  "decs", "dec", "dec_gen", "dec_base", "dec_base_1", "dec_struct",
  "dec_gen_struct", "dec_base_struct", "dec_base_struct_1", "type",
  "sin_type", "MULt_MUL", "struct_init", "sin_struct_init", "mul_iden_cm",
  "ret_stat", "ifs", "$@5", "while", "fors", "op1", "op2", "op3", "dowh",
  "switch", "cases", "inner", YY_NULLPTR
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
     315
};
# endif

#define YYPACT_NINF -194

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-194)))

#define YYTABLE_NINF -50

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     811,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,    22,
      83,  -194,   111,  -194,  -194,  -194,     6,   117,  -194,  -194,
     -41,  -194,   811,    -3,   146,    36,  -194,  -194,   158,   107,
    -194,  -194,   820,  -194,   268,   589,   571,   131,   -41,    16,
    -194,  -194,  -194,   147,   820,    19,   185,   195,   205,   181,
     118,   243,  -194,   755,  -194,   240,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,   635,  -194,   246,  -194,   252,
    -194,     5,  -194,   160,   151,   239,    72,   216,   281,   267,
     248,   249,   242,   755,   235,    21,   589,   -14,  -194,  -194,
     296,   122,  -194,   247,   295,   299,   301,   311,  -194,   181,
    -194,   376,  -194,    46,   820,  -194,   313,   217,   820,   755,
     635,   269,    27,   653,   755,   319,  -194,  -194,   327,   755,
    -194,  -194,  -194,   755,  -194,  -194,   755,  -194,  -194,  -194,
    -194,  -194,   755,  -194,  -194,   755,   755,   755,   755,   755,
     755,   755,  -194,  -194,   235,  -194,    69,    50,  -194,  -194,
     755,  -194,    19,    19,   278,  -194,   326,   488,   329,   345,
     346,   341,   342,   709,   543,  -194,   303,   543,  -194,   314,
     350,  -194,    63,    79,   755,  -194,    29,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,   802,   305,   219,  -194,   145,  -194,
    -194,   351,   352,   820,   309,  -194,   635,  -194,  -194,   358,
      74,   242,  -194,  -194,    24,  -194,   160,   151,   239,    72,
     216,   281,   267,   248,   249,  -194,   589,   334,   367,  -194,
      31,  -194,  -194,   755,   681,  -194,   432,  -194,  -194,    82,
     348,  -194,  -194,  -194,  -194,  -194,  -194,  -194,   382,   755,
     755,   755,  -194,  -194,  -194,   121,   331,  -194,  -194,   589,
     755,  -194,  -194,    63,  -194,  -194,  -194,   802,   335,    61,
    -194,  -194,   377,   381,  -194,  -194,   755,  -194,  -194,   589,
    -194,  -194,    41,  -194,  -194,   163,  -194,   384,   727,  -194,
     355,  -194,  -194,   229,   231,   245,  -194,  -194,   176,  -194,
    -194,  -194,  -194,   820,  -194,   250,   755,  -194,   635,  -194,
    -194,  -194,  -194,  -194,    89,   773,  -194,   488,   488,   343,
     755,  -194,   820,  -194,  -194,  -194,  -194,  -194,   257,   488,
    -194,   378,    37,  -194,  -194,  -194,  -194,   403,   755,  -194,
    -194,   488,   320,   113,  -194,    37,  -194,   320,  -194,    37,
    -194,  -194
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   152,   153,   154,   155,   156,   157,   158,   160,     0,
       0,     2,     4,     8,     7,     6,     0,   150,     9,   165,
     161,     1,     0,   137,     0,     0,   131,   164,     0,   162,
     151,   159,     0,     5,     0,     0,     0,   135,     0,     0,
     130,   161,   163,     0,   128,     0,    38,   157,     0,     0,
       0,    52,   114,    85,    71,     0,    69,    70,   112,   113,
     108,   109,   110,   115,   111,     0,    78,    68,   136,    64,
      73,    80,    88,    90,    92,    94,    96,    98,   100,   102,
     104,   106,    66,     0,    43,     0,     0,   137,   133,   132,
       0,     0,   129,   147,     0,   143,     0,     0,    27,     0,
      26,     0,    34,     0,     0,    28,     0,     0,     0,    83,
       0,     0,    60,     0,     0,     0,    74,    75,     0,     0,
     118,   116,   117,     0,   119,   120,     0,   125,   122,   121,
     124,   123,     0,   127,   126,     0,     0,     0,     0,     0,
       0,     0,    81,    45,    44,   134,   141,     0,   166,   167,
       0,   142,     0,     0,   149,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,    10,    18,     0,
      47,    21,    88,     0,     0,    12,     0,    19,    20,    13,
      14,    15,    16,    17,     0,    29,     0,    31,     0,    53,
      72,     0,     0,     0,     0,    65,     0,    54,    51,     0,
      56,    67,    77,    76,     0,    89,    91,    93,    95,    97,
      99,   101,   103,   105,   107,    46,     0,   139,     0,   168,
       0,   144,   145,     0,     0,   204,     0,   197,   200,     0,
       0,   198,   199,   192,   193,   194,   195,   196,     0,     0,
       0,     0,    58,    59,   170,     0,     0,    37,    11,     0,
       0,    22,    50,    81,    38,    32,    40,     0,    30,     0,
      86,    82,     0,    61,    62,    55,     0,    79,   140,     0,
     169,   146,     0,   177,   178,     0,   179,     0,     0,   203,
       0,   201,   185,     0,     0,     0,   171,    23,     0,    48,
      49,    33,    42,     0,    29,     0,     0,    84,     0,    57,
     138,   148,   180,   181,     0,     0,   202,     0,     0,     0,
       0,    24,     0,    30,    87,    63,   182,   183,     0,     0,
     175,   172,     0,    25,   184,   176,   173,     0,     0,   187,
     186,     0,     0,     0,   174,     0,   191,     0,   189,     0,
     190,   188
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,   393,  -194,  -194,  -128,  -194,  -144,  -194,   -30,
    -194,   317,  -170,   -73,  -162,  -194,  -194,   312,  -194,   153,
    -134,  -102,   -80,   -33,  -194,  -194,   -82,  -194,  -194,  -194,
     291,   290,   288,   289,   287,   293,   300,   292,   -48,   -55,
     -68,  -194,  -194,  -194,  -194,   396,     7,  -194,   404,  -194,
    -194,   128,  -194,  -194,     0,  -194,   104,     2,   -11,   227,
    -131,  -109,  -194,  -136,   -90,  -194,  -194,  -194,   -87,   -54,
     -21,  -193
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    22,    12,   166,   167,   168,    13,   255,
      14,   102,    49,    37,   169,   170,    66,    67,   198,   199,
     171,   111,    68,    69,    70,    71,    72,   193,   108,   296,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   123,   126,   132,   135,    43,   175,    25,    26,    89,
      44,    94,    95,    96,   176,    17,    97,   177,    19,   149,
     178,   179,   331,   180,   181,   278,   305,   319,   182,   183,
     330,   238
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,   142,    18,    85,    48,    27,   145,    15,   194,    34,
     112,   143,   252,   227,   256,    23,    32,    30,   115,   172,
     107,   234,    16,   228,    18,    87,   232,   192,    93,    15,
     186,    20,    45,   174,    50,    35,   246,   114,    87,   248,
     114,   205,    24,   196,    45,    36,    35,   114,   233,   116,
     117,   118,    39,   173,    40,   112,    36,   114,   200,   201,
     327,   328,   184,   185,   119,    24,   218,   235,   219,    29,
     236,   215,    29,   217,   187,   172,   141,   293,   294,   -49,
     274,   144,   172,    21,   267,   172,   204,   292,   289,   174,
     266,   271,   253,   214,   264,   329,   174,   251,   280,   174,
     281,   301,   282,   237,   188,    36,   174,   316,   191,   229,
     133,    -3,   -49,   134,   320,   321,   173,   220,   216,   173,
      36,    31,   140,   141,   337,   140,   325,   103,    36,   114,
     245,   147,   140,    42,   104,   105,   268,   114,   334,   286,
     148,   112,   172,    90,   172,     1,     2,     3,     4,     5,
       6,     7,     8,    28,   259,    38,   174,   230,   174,   231,
      29,   104,   105,   227,   227,    27,   323,    41,   290,   288,
      29,   234,   234,   228,   228,   227,   232,   232,   173,   114,
      86,   302,   174,   234,    50,   228,   295,   227,   232,   300,
     272,   275,   310,   262,   311,   234,   315,   228,   233,   233,
     232,   124,   125,    98,   335,    91,   283,   284,   285,   339,
     233,   200,    99,   120,   314,   121,   122,   235,   235,    27,
     236,   236,   233,   100,   277,   172,   172,   291,   290,   235,
     304,   276,   236,   114,   190,   257,   258,   172,   101,   174,
     174,   235,   174,   112,   236,   114,   307,   114,   308,   172,
     172,   174,   109,   237,   237,   172,   106,    50,   113,   229,
     229,   114,   309,   174,   174,   237,   312,   313,   114,   174,
     136,   229,   318,   114,   324,   138,   127,   237,   128,   129,
     221,   222,   291,   229,   173,    46,   130,   131,   137,   173,
     139,   141,   140,   188,    36,   333,     1,     2,     3,     4,
       5,    47,     7,     8,    28,   146,   150,   230,   230,   231,
     231,   336,   188,   151,   338,   152,   340,   153,   341,   230,
     154,   231,    51,   156,   157,   158,   159,   195,   202,    51,
      52,   230,    53,   231,    54,    55,   203,   223,   224,    56,
      57,   239,   160,   327,   328,   161,   162,   163,     1,     2,
       3,     4,     5,     6,     7,     8,     9,   240,   241,   242,
     243,   247,   -39,   249,    58,    59,   250,   263,   260,   261,
      60,    61,    62,    63,    64,   265,   147,   164,   329,   156,
     157,   158,   159,   269,    24,    51,    52,   158,    53,   287,
      54,    55,   -41,    87,   297,    56,    57,   298,   160,   326,
     322,   161,   162,   163,     1,     2,     3,     4,     5,     6,
       7,     8,     9,   306,   332,    33,   155,   206,   189,   299,
      58,    59,   207,   208,   210,   209,    60,    61,    62,    63,
      64,   211,   213,   164,   165,   156,   157,   158,   159,   212,
      92,    51,    52,    88,    53,   270,    54,    55,     0,     0,
       0,    56,    57,     0,   160,     0,     0,   161,   162,   163,
       1,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,     0,     0,     0,     0,     0,    58,    59,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,     0,   164,
     279,   156,   157,   158,   159,     0,     0,    51,    52,     0,
      53,     0,    54,    55,     0,     0,   225,    56,    57,     0,
     160,     0,     0,   161,   162,   163,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,    58,    59,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,   226,   156,   157,   158,   159,
       0,     0,    51,    52,     0,    53,     0,    54,    55,     0,
       0,     0,    56,    57,     0,   160,     0,     0,   161,   162,
     163,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      51,    52,     0,    53,     0,    54,    55,    58,    59,     0,
      56,    57,     0,    60,    61,    62,    63,    64,    51,    52,
     164,    53,     0,    54,    55,     0,     0,     0,    56,    57,
       0,     0,     0,     0,     0,    58,    59,     0,     0,     0,
       0,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,    84,     0,    58,    59,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    51,    52,    65,    53,     0,    54,
      55,     0,     0,     0,    56,    57,     0,     0,     0,     0,
       0,     0,    51,    52,     0,    53,     0,    54,    55,     0,
     197,     0,    56,    57,     0,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,    60,    61,    62,    63,    64,
      51,    52,   110,    53,     0,    54,    55,    58,    59,   273,
      56,    57,     0,    60,    61,    62,    63,    64,     0,     1,
       2,     3,     4,     5,     6,     7,     8,    28,    51,    52,
       0,    53,     0,    54,    55,    58,    59,   244,    56,    57,
       0,    60,    61,    62,    63,    64,    51,    52,     0,    53,
       0,    54,    55,     0,     0,   303,    56,    57,     0,     0,
       0,     0,     0,    58,    59,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    51,    52,     0,    53,     0,    54,
      55,    58,    59,     0,    56,    57,     0,    60,    61,    62,
      63,    64,    51,    52,     0,    53,     0,    54,    55,     0,
     317,     0,    56,    57,     0,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,    58,    59,   254,
       0,     0,     0,    60,    61,    62,    63,    64,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,    28,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     1,     2,
       3,     4,     5,     6,     7,     8,    28
};

static const yytype_int16 yycheck[] =
{
       0,    83,     0,    36,    34,    16,    86,     0,   110,    12,
      65,    84,   174,   157,   184,     9,    57,    17,    13,   101,
      53,   157,    22,   157,    22,     9,   157,   109,     9,    22,
     103,     9,    32,   101,    34,    49,   164,    16,     9,   167,
      16,   123,    36,    16,    44,    59,    49,    16,   157,    44,
      45,    46,    16,   101,    18,   110,    59,    16,   113,   114,
      23,    24,    16,    17,    59,    36,    16,   157,    18,    53,
     157,   144,    53,   146,   104,   157,    49,    16,    17,    16,
     224,    60,   164,     0,    60,   167,   119,   257,   250,   157,
      16,    60,   174,   141,   196,    58,   164,    18,   226,   167,
      18,    60,   238,   157,   104,    59,   174,    18,   108,   157,
      38,     0,    49,    41,   307,   308,   164,   150,    49,   167,
      59,    17,    43,    49,    11,    43,   319,     9,    59,    16,
     163,     9,    43,    29,    16,    17,   216,    16,   331,    18,
      18,   196,   224,    39,   226,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     9,     9,   224,   157,   226,   157,
      53,    16,    17,   307,   308,   176,   310,     9,   250,   249,
      53,   307,   308,   307,   308,   319,   307,   308,   226,    16,
      49,    18,   250,   319,   184,   319,   259,   331,   319,   269,
     223,   224,    16,   193,    18,   331,   298,   331,   307,   308,
     331,    50,    51,    18,   332,    58,   239,   240,   241,   337,
     319,   266,    17,    53,   296,    55,    56,   307,   308,   230,
     307,   308,   331,    18,   224,   307,   308,   257,   310,   319,
     278,   224,   319,    16,    17,    16,    17,   319,    57,   307,
     308,   331,   310,   298,   331,    16,    17,    16,    17,   331,
     332,   319,    12,   307,   308,   337,    13,   257,    12,   307,
     308,    16,    17,   331,   332,   319,    16,    17,    16,   337,
      54,   319,   305,    16,    17,     8,    37,   331,    39,    40,
     152,   153,   312,   331,   332,    17,    47,    48,     7,   337,
      42,    49,    43,   293,    59,   328,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     9,    59,   307,   308,   307,
     308,   332,   312,    18,   335,    16,   337,    16,   339,   319,
       9,   319,     9,     3,     4,     5,     6,    58,     9,     9,
      10,   331,    12,   331,    14,    15,     9,    59,    12,    19,
      20,    12,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    12,    12,    18,
      18,    58,    57,    49,    44,    45,    16,    58,    17,    17,
      50,    51,    52,    53,    54,    17,     9,    57,    58,     3,
       4,     5,     6,    49,    36,     9,    10,     5,    12,    58,
      14,    15,    57,     9,    17,    19,    20,    16,    22,    21,
      57,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    58,    11,    22,    99,   126,   106,   266,
      44,    45,   132,   135,   137,   136,    50,    51,    52,    53,
      54,   138,   140,    57,    58,     3,     4,     5,     6,   139,
      44,     9,    10,    39,    12,   218,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    22,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    -1,    -1,    57,
      58,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    -1,    18,    19,    20,    -1,
      22,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    -1,    -1,    57,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      -1,    -1,    19,    20,    -1,    22,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       9,    10,    -1,    12,    -1,    14,    15,    44,    45,    -1,
      19,    20,    -1,    50,    51,    52,    53,    54,     9,    10,
      57,    12,    -1,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,     9,    10,    57,    12,    -1,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
       9,    10,    57,    12,    -1,    14,    15,    44,    45,    18,
      19,    20,    -1,    50,    51,    52,    53,    54,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     9,    10,
      -1,    12,    -1,    14,    15,    44,    45,    18,    19,    20,
      -1,    50,    51,    52,    53,    54,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,     9,    10,    -1,    12,    -1,    14,
      15,    44,    45,    -1,    19,    20,    -1,    50,    51,    52,
      53,    54,     9,    10,    -1,    12,    -1,    14,    15,    -1,
      17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    17,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    28,    29,
      30,    31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      62,    63,    65,    69,    71,   107,   115,   116,   118,   119,
       9,     0,    64,     9,    36,   108,   109,   119,    36,    53,
     115,   117,    57,    63,    12,    49,    59,    74,     9,    16,
      18,     9,   117,   106,   111,   115,    17,    33,    70,    73,
     115,     9,    10,    12,    14,    15,    19,    20,    44,    45,
      50,    51,    52,    53,    54,    57,    77,    78,    83,    84,
      85,    86,    87,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    60,    84,    49,     9,   109,   110,
     117,    58,   106,     9,   112,   113,   114,   117,    18,    17,
      18,    57,    72,     9,    16,    17,    13,    84,    89,    12,
      57,    82,   100,    12,    16,    13,    44,    45,    46,    59,
      53,    55,    56,   102,    50,    51,   103,    37,    39,    40,
      47,    48,   104,    38,    41,   105,    54,     7,     8,    42,
      43,    49,    87,    74,    60,    83,     9,     9,    18,   120,
      59,    18,    16,    16,     9,    72,     3,     4,     5,     6,
      22,    25,    26,    27,    57,    58,    66,    67,    68,    75,
      76,    81,    87,    99,   101,   107,   115,   118,   121,   122,
     124,   125,   129,   130,    16,    17,    74,    70,   115,    78,
      17,   115,    87,    88,    82,    58,    16,    17,    79,    80,
     100,   100,     9,     9,    84,    87,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    74,    49,    74,    16,    18,
      84,   112,   112,    59,    12,    18,    57,    68,    81,    99,
     115,   118,   121,   122,   124,   125,   129,   130,   132,    12,
      12,    12,    18,    18,    18,    84,    66,    58,    66,    49,
      16,    18,    75,    87,    17,    70,    73,    16,    17,     9,
      17,    17,   115,    58,    82,    17,    16,    60,    83,    49,
     120,    60,    84,    18,    68,    84,   107,   115,   126,    58,
      66,    18,   124,    84,    84,    84,    18,    58,    83,    75,
      87,    70,    73,    16,    17,    74,    90,    17,    16,    80,
      83,    60,    18,    18,    99,   127,    58,    17,    17,    17,
      16,    18,    16,    17,    87,    82,    18,    17,    84,   128,
     132,   132,    57,    68,    17,   132,    21,    23,    24,    58,
     131,   123,    11,    84,   132,    66,   131,    11,   131,    66,
     131,   131
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    63,    65,    65,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    88,    87,    89,    90,    87,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   103,
     103,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     107,   108,   108,   108,   109,   109,   109,   109,   110,   110,
     110,   110,   111,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   123,   122,   124,   125,   126,   126,   126,
     126,   127,   127,   128,   128,   129,   130,   131,   131,   131,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     5,     5,     5,     2,     3,
       4,     3,     4,     5,     5,     6,     2,     3,     1,     3,
       4,     4,     5,     2,     3,     3,     4,     1,     3,     1,
       2,     3,     1,     3,     1,     2,     1,     3,     2,     2,
       1,     3,     3,     5,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     2,     2,     3,     3,     1,     4,
       1,     2,     4,     0,     5,     0,     0,     6,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     3,     3,     4,     2,     3,     1,     5,     3,
       4,     2,     3,     1,     3,     3,     4,     1,     5,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     2,     1,     6,     6,     2,     3,
       2,     3,     5,     0,     8,     5,     6,     1,     1,     1,
       2,     1,     2,     1,     2,     3,     6,     1,     5,     4,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     2,     1
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
        case 3:
#line 15 "a1.y" /* yacc.c:1646  */
    {glb++;}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 15 "a1.y" /* yacc.c:1646  */
    {glb++;}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 16 "a1.y" /* yacc.c:1646  */
    {fc++;}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 46 "a1.y" /* yacc.c:1646  */
    {ic++;}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 48 "a1.y" /* yacc.c:1646  */
    {flcs=0;}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 48 "a1.y" /* yacc.c:1646  */
    {flcs=1;}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 48 "a1.y" /* yacc.c:1646  */
    {flcs=0;}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 48 "a1.y" /* yacc.c:1646  */
    {flcs=1;}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 81 "a1.y" /* yacc.c:1646  */
    {ptr+=flcs;}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 90 "a1.y" /* yacc.c:1646  */
    {ifc++;}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 90 "a1.y" /* yacc.c:1646  */
    {ieb++; if(mxie<ieb) mxie=ieb; }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 90 "a1.y" /* yacc.c:1646  */
    {ieb--;}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1756 "y.tab.c" /* yacc.c:1646  */
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
#line 101 "a1.y" /* yacc.c:1906  */


void yyerror(char *s) 
{
    printf("***parsing terminated*** [syntax error]\n");
	exit(0);
}

int main(int argc, char* argv[]) {
	
	if(argc!=2)
	{
		printf("***process terminated*** [input error]: invalid number of command-line arguments\n");
		return 0;
	}
	
	else if(!(yyin=fopen(argv[1], "r")))
	{
		printf("***process terminated*** [input error]: no such file %s exists\n", argv[1]);
		return 0;
	}
		
	
    if(!yyparse()){
		printf("***parsing successful***\n");
		printf("#global_declarations = %d\n", glb);
		printf("#function_definitions = %d\n", fc);
		printf("#integer_constants = %d\n", ic);
		printf("#pointers_declarations = %d\n", ptr);
		printf("#ifs_without_else = %d\n", ifc);
		printf("if-else max-depth = %d\n", mxie);
		return 0;
	}
	else{
		printf("***parsing terminated*** [syntax error]\n");
		return 0;
	}
}
