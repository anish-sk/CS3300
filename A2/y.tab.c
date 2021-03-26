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

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAXSIZE 15
    void yyerror(char*);
    int yylex(void);
    int max(int, int);
    FILE* yyin;
    char mytext[100];
    extern int integerConstantCount;
    int pointerDeclarations = 0;
    int lpath = 0;
    int iflpath = 0;
    int whilelpath = 0;
    int switchlpath = 0;
    int mainlpath = 0;
    int ismain = 0;
    struct node {
        int val;
        char name[100];
        int max;
        int maxending;
        struct node *children[MAXSIZE];
    };
    struct ab{
        int a;
        int b;
    };
    #define YYSTYPE struct node
    void initialize(struct ab children[]);
    int maxsubtree (struct ab children[]);
    int maxending(struct ab children[]);
    char mytext[100];

#line 102 "y.tab.c" /* yacc.c:339  */

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
    IDENTIFIER = 258,
    NUMBER = 259,
    INTEGER = 260,
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
    PRINTF = 279,
    FMTSPEC = 280,
    NEWOP = 281,
    NEQ = 282,
    BITAND = 283,
    BITOR = 284,
    BITNOT = 285,
    BITXOR = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    MOD = 290,
    EXTERN = 291,
    LONG = 292,
    SHORT = 293,
    DOUBLE = 294,
    VOID = 295,
    SWITCH = 296,
    CASE = 297,
    STRUCT = 298,
    BREAK = 299,
    CONTINUE = 300,
    RETURN = 301,
    STRLITERAL = 302,
    CHARLITERAL = 303,
    INC = 304,
    DEC = 305,
    ARROW = 306,
    SIZEOF = 307,
    DEFAULT = 308
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define NUMBER 259
#define INTEGER 260
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
#define PRINTF 279
#define FMTSPEC 280
#define NEWOP 281
#define NEQ 282
#define BITAND 283
#define BITOR 284
#define BITNOT 285
#define BITXOR 286
#define AND 287
#define OR 288
#define NOT 289
#define MOD 290
#define EXTERN 291
#define LONG 292
#define SHORT 293
#define DOUBLE 294
#define VOID 295
#define SWITCH 296
#define CASE 297
#define STRUCT 298
#define BREAK 299
#define CONTINUE 300
#define RETURN 301
#define STRLITERAL 302
#define CHARLITERAL 303
#define INC 304
#define DEC 305
#define ARROW 306
#define SIZEOF 307
#define DEFAULT 308

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

#line 259 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      60,    61,     2,     2,    57,     2,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,    56,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    53,    63,    73,    82,    90,   100,   115,
     125,   136,   149,   165,   174,   183,   192,   202,   212,   222,
     231,   243,   252,   261,   261,   283,   293,   302,   312,   322,
     331,   344,   353,   363,   371,   379,   387,   395,   403,   411,
     419,   427,   435,   443,   451,   482,   497,   513,   529,   539,
     553,   563,   572,   582,   597,   610,   627,   636,   648,   659,
     670,   688,   697,   707,   720,   732,   748,   766,   799,   834,
     859,   885,   908,   931,   954,   977,  1000,  1011,  1034,  1057,
    1080,  1103,  1126,  1149,  1172,  1195,  1218,  1241,  1250,  1259,
    1268,  1277,  1286,  1294,  1305,  1318,  1326,  1334,  1342,  1354,
    1365,  1375,  1385,  1396,  1406,  1415
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "NUMBER", "INTEGER",
  "PLUS", "MINUS", "MULT", "DIV", "IF", "ELSE", "FOR", "WHILE", "DO",
  "INT", "FLOAT", "CHAR", "EQ", "EQEQ", "GEQ", "LEQ", "GT", "LT", "PRINTF",
  "FMTSPEC", "NEWOP", "NEQ", "BITAND", "BITOR", "BITNOT", "BITXOR", "AND",
  "OR", "NOT", "MOD", "EXTERN", "LONG", "SHORT", "DOUBLE", "VOID",
  "SWITCH", "CASE", "STRUCT", "BREAK", "CONTINUE", "RETURN", "STRLITERAL",
  "CHARLITERAL", "INC", "DEC", "ARROW", "SIZEOF", "DEFAULT", "'{'", "'}'",
  "';'", "','", "'['", "']'", "'('", "')'", "':'", "'.'", "$accept",
  "program", "decl_list", "decl", "struct_decl", "var_decl", "type_spec",
  "extern_spec", "func_decl", "$@1", "params", "param_list", "param",
  "stmt_list", "stmt", "while_stmt", "dowhile_stmt", "print_stmt",
  "format_specifier", "compound_stmt", "local_decls", "local_decl",
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
     305,   306,   307,   308,   123,   125,    59,    44,    91,    93,
      40,    41,    58,    46
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -27

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,  -100,    11,    17,    26,  -100,  -100,  -100,    11,     0,
    -100,  -100,    -6,  -100,  -100,    56,    20,    22,    35,  -100,
    -100,  -100,    -5,    41,    -8,  -100,  -100,  -100,    38,    11,
    -100,    11,  -100,   -10,    -1,     7,    11,  -100,    53,    56,
      32,    11,    12,     9,  -100,  -100,   -55,  -100,    -5,    24,
      21,    -5,  -100,    51,  -100,    27,  -100,  -100,  -100,  -100,
       5,     5,     5,     5,     5,    18,    51,    36,   237,  -100,
    -100,   -47,  -100,   184,  -100,  -100,  -100,  -100,  -100,  -100,
       5,    40,    43,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,    51,    51,
      44,    58,   208,    61,    63,    73,    74,    16,   122,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,    59,    70,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,    60,  -100,    23,    76,    51,    51,   121,   113,    51,
    -100,  -100,  -100,    83,  -100,  -100,    51,    84,    85,    11,
      51,    11,  -100,  -100,    51,  -100,    81,    87,    89,  -100,
      88,    90,  -100,    94,  -100,  -100,   134,    96,   135,  -100,
     208,   208,    51,    11,   102,  -100,    51,   142,    51,   150,
    -100,   103,   104,   127,   114,    51,   115,   208,   116,   117,
      41,   130,   127,  -100,   118,  -100,  -100,  -100,  -100,   123,
     126,   120,  -100,  -100,   208,   208,  -100,   208,   208
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      22,    21,     0,     0,    22,     4,     7,     5,     0,     0,
       6,   101,    19,     1,     3,    23,    14,    15,    13,    20,
      51,     9,    22,     0,     0,    17,    18,    16,    22,     0,
      10,     0,    99,     0,    22,     0,     0,    50,    19,     0,
       0,     0,     0,    25,    28,     8,     0,    11,    22,    29,
       0,    22,    52,     0,    12,     0,    51,    24,    27,   100,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    95,
      96,    97,    30,    22,    89,    97,    88,    90,    91,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      36,    41,    42,    34,    35,    38,    39,    40,    37,    33,
      43,    44,     0,     0,    98,    53,    82,    83,    84,    85,
      77,    74,    73,    72,    71,    79,    78,    80,    75,    86,
      81,     0,   103,   104,     0,     0,     0,     0,     0,     0,
      58,    59,    56,     0,    49,    31,     0,     0,     0,     0,
       0,     0,    76,    94,     0,    93,     0,     0,     0,    48,
       0,     0,    57,     0,    69,    70,     0,     0,     0,   102,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    54,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,    67,     0,    68,    55,    46,    47,     0,
       0,     0,    61,    66,     0,     0,    60,    63,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,   185,  -100,   -15,    19,  -100,  -100,  -100,
    -100,  -100,   139,   -99,   -90,  -100,  -100,  -100,  -100,   141,
     136,  -100,  -100,  -100,  -100,  -100,  -100,    -3,  -100,  -100,
    -100,  -100,  -100,   -62,   213,   -18,  -100,    -2,  -100,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    24,
      42,    43,    44,   108,   109,   110,   111,   112,   170,   113,
      28,    37,   114,   115,   116,   117,   118,   201,   202,   211,
     119,   120,   121,    67,    68,    69,    70,    75,   143,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    52,    19,    53,    81,    33,    15,    30,    11,    59,
      32,    98,   147,    99,    11,    16,    17,    13,   155,    11,
      59,    32,    60,    61,    62,     1,    -2,    38,    25,    39,
      26,     1,     2,    54,    46,     1,   141,   142,    29,    49,
      18,    31,    29,    27,    63,   153,    32,    36,    20,    40,
      64,    71,    34,    41,    11,    59,    32,    60,    61,    62,
     -26,    19,     1,    45,    71,    66,    51,    31,    65,     2,
      41,   122,   152,    50,     1,    56,    66,   156,    80,    63,
     164,    29,    55,   166,   167,    64,    72,   171,    47,    48,
     189,   190,    36,    35,   173,    82,    71,    71,   177,   125,
     122,   124,   179,    65,   145,    71,   122,   206,   157,   158,
     159,    66,    21,    22,    23,   217,   218,   160,   146,   163,
     191,   148,   161,   149,   194,    11,   196,   155,   155,   150,
     151,   162,   100,   204,   168,   101,   102,   165,   169,   172,
     174,   175,   180,    71,    71,   183,   103,    71,   181,   182,
     185,   184,   186,   188,    71,   187,   193,   176,    71,   178,
     195,   197,    71,   104,   198,   199,   105,   106,   107,   200,
     203,   205,   207,   208,   213,   216,    56,   154,   122,   122,
      71,   192,   209,   210,    71,   214,    71,    11,   215,    14,
      58,    57,    73,    71,   100,   122,     0,   101,   102,   212,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,    11,   122,   122,     0,   122,   122,     0,   100,     0,
       1,   101,   102,     0,     0,   104,     0,    29,   105,   106,
     107,     0,   103,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,    83,    84,    85,    86,     0,     0,   104,
       0,     0,   105,   106,   107,     0,    87,    88,    89,    90,
      91,     0,    56,    92,    93,     0,     0,     0,     0,    94,
      95,     0,    96,    74,    76,    77,    78,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,   123,     0,     0,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140
};

static const yytype_int16 yycheck[] =
{
       2,    56,     8,    58,    66,    23,     8,    22,     3,     4,
       5,    58,   102,    60,     3,    15,    16,     0,   108,     3,
       4,     5,     6,     7,     8,    36,     0,    29,     8,    31,
       8,    36,    43,    48,    36,    36,    98,    99,    43,    41,
      40,    22,    43,     8,    28,   107,     5,    28,    54,    59,
      34,    53,    60,    34,     3,     4,     5,     6,     7,     8,
      61,     8,    36,    56,    66,    60,    57,    48,    52,    43,
      51,    73,    56,    61,    36,    54,    60,    18,    60,    28,
      57,    43,    58,   145,   146,    34,    59,   149,    56,    57,
     180,   181,    73,    55,   156,    59,    98,    99,   160,    56,
     102,    61,   164,    52,    60,   107,   108,   197,    49,    50,
      51,    60,    56,    57,    58,   214,   215,    58,    60,    59,
     182,    60,    63,    60,   186,     3,   188,   217,   218,    56,
      56,    61,    10,   195,    13,    13,    14,    61,    25,    56,
      56,    56,    61,   145,   146,    57,    24,   149,    61,    60,
      56,    61,    18,    18,   156,    59,    54,   159,   160,   161,
      18,    11,   164,    41,    61,    61,    44,    45,    46,    42,
      56,    56,    56,    56,    56,    55,    54,    55,   180,   181,
     182,   183,   200,    53,   186,    62,   188,     3,    62,     4,
      51,    50,    56,   195,    10,   197,    -1,    13,    14,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,     3,   214,   215,    -1,   217,   218,    -1,    10,    -1,
      36,    13,    14,    -1,    -1,    41,    -1,    43,    44,    45,
      46,    -1,    24,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    -1,    -1,    41,
      -1,    -1,    44,    45,    46,    -1,    19,    20,    21,    22,
      23,    -1,    54,    26,    27,    -1,    -1,    -1,    -1,    32,
      33,    -1,    35,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    43,    65,    66,    67,    68,    69,    70,    71,
      72,     3,   101,     0,    67,   101,    15,    16,    40,     8,
      54,    56,    57,    58,    73,     8,     8,     8,    84,    43,
      69,    70,     5,    99,    60,    55,    70,    85,   101,   101,
      59,    70,    74,    75,    76,    56,   101,    56,    57,   101,
      61,    57,    56,    58,    69,    58,    54,    83,    76,     4,
       6,     7,     8,    28,    34,    52,    60,    97,    98,    99,
     100,   101,    59,    84,    98,   101,    98,    98,    98,    98,
      60,    97,    59,     6,     7,     8,     9,    19,    20,    21,
      22,    23,    26,    27,    32,    33,    35,    51,    58,    60,
      10,    13,    14,    24,    41,    44,    45,    46,    77,    78,
      79,    80,    81,    83,    86,    87,    88,    89,    90,    94,
      95,    96,   101,    98,    61,    56,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    97,    97,   102,   103,    60,    60,    78,    60,    60,
      56,    56,    56,    97,    55,    78,    18,    49,    50,    51,
      58,    63,    61,    59,    57,    61,    97,    97,    13,    25,
      82,    97,    56,    97,    56,    56,   101,    97,   101,    97,
      61,    61,    60,    57,    61,    56,    18,    59,    18,    78,
      78,    97,   101,    54,    97,    18,    97,    11,    61,    61,
      42,    91,    92,    56,    97,    56,    78,    56,    56,    99,
      53,    93,    91,    56,    62,    62,    55,    77,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    68,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    73,    72,    74,    74,    75,    75,    76,
      76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    79,    80,    81,    82,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    89,
      90,    91,    91,    92,    93,    94,    94,    94,    94,    95,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    99,
     100,   101,   102,   102,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     3,
       4,     6,     7,     2,     2,     2,     3,     3,     3,     2,
       3,     1,     0,     0,     7,     1,     0,     3,     1,     2,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     7,     1,     4,
       2,     0,     3,     6,     5,     7,     2,     3,     2,     2,
       8,     2,     1,     4,     3,     4,     7,     6,     6,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     1,     4,     4,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     0
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
#line 44 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-1]).max; children[0].b = (yyvsp[-1]).maxending;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                //printf("after decl_list %d\n", $$.maxending);
                }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 64 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                //printf("after var_decl%d\n", lpath);
                }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 83 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[-4]).max; children[1].b = (yyvsp[-4]).maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = (yyvsp[-2]).max; children[3].b = (yyvsp[-2]).maxending;
                children[4].a = 1; children[4].b = 1;
                children[5].a = 1; children[5].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = (yyvsp[-1]).max; children[1].b = (yyvsp[-1]).maxending;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-3]).max; children[0].b = (yyvsp[-3]).maxending;
                children[1].a = (yyvsp[-2]).max; children[1].b = (yyvsp[-2]).maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = (yyvsp[0]).max; children[3].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 137 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-5]).max; children[0].b = (yyvsp[-5]).maxending;
                children[1].a = (yyvsp[-4]).max; children[1].b = (yyvsp[-4]).maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = (yyvsp[-2]).max; children[3].b = (yyvsp[-2]).maxending;
                children[4].a = 1; children[4].b = 1;
                children[5].a = 1; children[5].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-6]).max; children[0].b = (yyvsp[-6]).maxending;
                children[1].a = (yyvsp[-5]).max; children[1].b = (yyvsp[-5]).maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = (yyvsp[-3]).max; children[3].b = (yyvsp[-3]).maxending;
                children[4].a = 1; children[4].b = 1;
                children[5].a = 1; children[5].b = 1;
                children[6].a = (yyvsp[0]).max; children[6].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 166 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-1]).max; children[0].b = (yyvsp[-1]).maxending;
                children[1].a = 1; children[1].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 175 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-1]).max; children[0].b = (yyvsp[-1]).maxending;
                children[1].a = 1; children[1].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 184 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-1]).max; children[0].b = (yyvsp[-1]).maxending;
                children[1].a = 1; children[1].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 193 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 203 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 213 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 223 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 232 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[-1]).max; children[1].b = (yyvsp[-1]).maxending;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 244 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 252 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 261 "a.y" /* yacc.c:1646  */
    {if(strcmp(mytext, "main") == 0) ismain = 1;}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 262 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-6]).max; children[0].b = (yyvsp[-6]).maxending;
                children[1].a = (yyvsp[-5]).max; children[1].b = (yyvsp[-5]).maxending;
                //children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = (yyvsp[-2]).max; children[4].b = (yyvsp[-2]).maxending;
                children[5].a = 1; children[5].b = 1;
                children[6].a = (yyvsp[0]).max; children[6].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                if(ismain){
                    mainlpath = max(mainlpath, (yyval).max);
                    ismain = 0;
                }
                //printf("after func_decl %d\n", $$.max);
                //printf("after comp_stmt %d\n", $7.max);
                }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 284 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                //printf("after params %d\n", $$.max);
                }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 293 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 303 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 313 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 323 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-1]).max; children[0].b = (yyvsp[-1]).maxending;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 332 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-3]).max; children[0].b = (yyvsp[-3]).maxending;
                children[1].a = (yyvsp[-2]).max; children[1].b = (yyvsp[-2]).maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = 1; children[3].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 345 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-1]).max; children[0].b = (yyvsp[-1]).maxending;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 354 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 364 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 372 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 380 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 388 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 396 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 404 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 412 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 420 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 428 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 436 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 444 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 452 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 483 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-2]).max; children[2].b = (yyvsp[-2]).maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = (yyvsp[0]).max; children[4].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                whilelpath = max(whilelpath, (yyval).max);
                }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 498 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[-5]).max; children[1].b = (yyvsp[-5]).maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = 1; children[3].b = 1;
                children[4].a = (yyvsp[-2]).max; children[4].b = (yyvsp[-2]).maxending;
                children[5].a = 1; children[5].b = 1;
                children[6].a = 1; children[6].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 514 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-4]).max; children[2].b = (yyvsp[-4]).maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = (yyvsp[-2]).max; children[4].b = (yyvsp[-2]).maxending;
                children[5].a = 1; children[5].b = 1;
                children[6].a = 1; children[6].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 530 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                    children[0].a = 1; children[0].b = 1;
                    (yyval).maxending = maxending(children);
                    (yyval).max = maxsubtree(children);
                    (yyval).max = max((yyval).max, (yyval).maxending);
                    lpath = max(lpath, (yyval).max);
                    }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 540 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[-2]).max; children[1].b = (yyvsp[-2]).maxending;
                children[2].a = (yyvsp[-1]).max; children[2].b = (yyvsp[-1]).maxending;
                children[3].a = 1; children[3].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                //printf("after comp_stmt %d %d\n", $$.max, $$.maxending);
                }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 554 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-1]).max; children[0].b = (yyvsp[-1]).maxending;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 563 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 573 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = (yyvsp[-1]).max; children[1].b = (yyvsp[-1]).maxending;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 583 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-5]).max; children[0].b = (yyvsp[-5]).maxending;
                children[1].a = (yyvsp[-4]).max; children[1].b = (yyvsp[-4]).maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = (yyvsp[-2]).max; children[3].b = (yyvsp[-2]).maxending;
                children[4].a = 1; children[4].b = 1;
                children[5].a = 1; children[5].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 598 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-2]).max; children[2].b = (yyvsp[-2]).maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = (yyvsp[0]).max; children[4].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                iflpath = max(iflpath, (yyval).max);
                }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 611 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-4]).max; children[2].b = (yyvsp[-4]).maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = (yyvsp[-2]).max; children[4].b = (yyvsp[-2]).maxending;
                children[5].a = 1; children[5].b = 1;
                children[6].a = (yyvsp[0]).max; children[6].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                iflpath = max(iflpath, (yyval).max);
                }
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 628 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 637 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[-1]).max; children[1].b = (yyvsp[-1]).maxending;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 649 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 660 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 671 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-5]).max; children[2].b = (yyvsp[-5]).maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = 1; children[4].b = 1;
                children[5].a = (yyvsp[-2]).max; children[5].b = (yyvsp[-2]).maxending;
                children[6].a = (yyvsp[-1]).max; children[6].b = (yyvsp[-1]).maxending;
                children[7].a = 1; children[7].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                switchlpath = max(switchlpath, (yyval).max);
                }
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 689 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-1]).max; children[0].b = (yyvsp[-1]).maxending;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 698 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 708 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[-2]).max; children[1].b = (yyvsp[-2]).maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = (yyvsp[0]).max; children[3].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 721 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 733 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-3]).max; children[0].b = (yyvsp[-3]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[-1]).max; children[2].b = (yyvsp[-1]).maxending;
                children[3].a = (yyvsp[0]).max; children[3].b = (yyvsp[0]).maxending;
                //printf("after expr %d %d\n", $3.max, $3.maxending);
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                //printf("after assign %d\n", $$.max);
                }
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 749 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-6]).max; children[0].b = (yyvsp[-6]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-4]).max; children[2].b = (yyvsp[-4]).maxending;
                children[3].a = 1; children[3].b = 1;
                //children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = (yyvsp[-1]).max; children[5].b = (yyvsp[-1]).maxending;
                children[6].a = 1; children[6].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.maxending = maxending(children);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 783 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-5]).max; children[0].b = (yyvsp[-5]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-3]).max; children[2].b = (yyvsp[-3]).maxending;
                //children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = (yyvsp[-1]).max; children[4].b = (yyvsp[-1]).maxending;
                children[5].a = 1; children[5].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.maxending = maxending(children);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 816 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-5]).max; children[0].b = (yyvsp[-5]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-3]).max; children[2].b = (yyvsp[-3]).maxending;
                //children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = (yyvsp[-1]).max; children[4].b = (yyvsp[-1]).maxending;
                children[5].a = 1; children[5].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.maxending = maxending(children);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 848 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 874 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 886 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 909 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 932 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 955 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 978 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1001 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-1]).max; children[2].b = (yyvsp[-1]).maxending;
                children[3].a = 1; children[3].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1012 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1035 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1058 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1081 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1104 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1127 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1150 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1173 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1196 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1219 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                (yyval).maxending = max(x+1, 2);
                (yyval).max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1242 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1251 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1260 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1269 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1278 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[0]).max; children[1].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1287 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1295 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-3]).max; children[0].b = (yyvsp[-3]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-1]).max; children[2].b = (yyvsp[-1]).maxending;
                children[3].a = 1; children[3].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1306 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-3]).max; children[0].b = (yyvsp[-3]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[-1]).max; children[2].b = (yyvsp[-1]).maxending;
                children[3].a = 1; children[3].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1319 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1327 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1335 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1343 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = (yyvsp[-1]).max; children[1].b = (yyvsp[-1]).maxending;
                children[2].a = 1; children[2].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1355 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                //children[0].a = 0; children[0].b = -1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1366 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1376 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1386 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[-2]).max; children[0].b = (yyvsp[-2]).maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                children[2].a = (yyvsp[0]).max; children[2].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1397 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1407 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = (yyvsp[0]).max; children[0].b = (yyvsp[0]).maxending;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1415 "a.y" /* yacc.c:1646  */
    {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                (yyval).maxending = maxending(children);
                (yyval).max = maxsubtree(children);
                (yyval).max = max((yyval).max, (yyval).maxending);
                lpath = max(lpath, (yyval).max);
                }
#line 2997 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3001 "y.tab.c" /* yacc.c:1646  */
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
#line 1425 "a.y" /* yacc.c:1906  */


void yyerror(char* s) {
    printf("syntax error\n");
    exit(0);
}

void initialize(struct ab children[]){
    for(int i=0; i<MAXSIZE; i++){
        children[i].a =  0;
        children[i].b =  0;

    }
}

int maxending(struct ab children[]){
    int mx = 0;
    for(int i=0; i<MAXSIZE; i++){
        mx = max(mx, children[i].b);
    }
    return (mx+1);
}

int maxsubtree(struct ab children[]){
    int m1=0, m2 =0;
    for(int i=0; i<MAXSIZE; i++){
        if(children[i].b >=m1){
            m2 = m1;
            m1 = children[i].b;
        }
        else if(children[i].b >=m2){
            m2 = children[i].b;
        }
    }
    int m3 = 0;
    for(int i=0; i<MAXSIZE; i++){
        m3 = max(m3, children[i].a);
    }
    return max(m3,m1 + m2 + 1);
}

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main(int argc, char** argv) {
    //yyin = fopen(argv[1], "r");
    //if(argc == 1) {
    //    printf("***process terminated*** [error]\n");
    //}
    //else {
    //    FILE* fp = fopen(argv[1], "r");
    //    if(fp) {
    //        yyin = fp;
    //        yyparse();
    //        printf("%d\n", lpath);
    //        printf("%d\n", iflpath);
    //        printf("%d\n", whilelpath);
    //        printf("%d\n", switchlpath);
    //        printf("%d\n", mainlpath);
    //    }
    //    else {
    //        printf("***process terminated*** [error]\n");
    //    }
    //}
    yyparse();
    printf("%d\n", lpath);
    printf("%d\n", iflpath);
    printf("%d\n", whilelpath);
    printf("%d\n", switchlpath);
    printf("%d\n", mainlpath);
    return 0;
}
