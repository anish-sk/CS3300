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
#line 3 "Ass2.y" /* yacc.c:339  */

	#include <stdio.h>
	#include<string.h>
	void yyerror(char *);
	int yylex(void);
	extern FILE *yyin;
	extern char *yytext;
	int yydebug=1;
	int lbl_main=0,lbl_pass=1;
	int tr_depth=0,if_depth=0,wh_depth=0,sw_depth=0,main_depth=0;
	struct Node{
		int depth;
		int max_path;
	};
	#define YYSTYPE struct Node
	struct Node s(int n,struct Node states[]){
		int max_depth=0,prev_max_depth=0,max_path=0;
		for(int i=0;i<n;i++){
			if((states[i].depth+1)>=max_depth){
				prev_max_depth=max_depth;
				max_depth=states[i].depth+1;
			}
			else if(prev_max_depth<states[i].depth+1) prev_max_depth=states[i].depth+1;
			max_path=(max_path>states[i].max_path)?max_path:states[i].max_path;
		}
		struct Node ans;
		ans.max_path=(max_path>max_depth+prev_max_depth)?max_path:max_depth+prev_max_depth;
		ans.depth=max_depth;	
		return ans;
	}
	struct Node s1(struct Node x1){
		struct Node temp[]={x1};
		return s(1,temp);
	}
	struct Node s2(struct Node x1,struct Node x2){
		struct Node temp[]={x1,x2};
		return s(2,temp);
	}
	struct Node s3(struct Node x1,struct Node x2,struct Node x3){
		struct Node temp[]={x1,x2,x3};
		return s(3,temp);
	}
	struct Node s4(struct Node x1,struct Node x2,struct Node x3,struct Node x4){
		struct Node temp[]={x1,x2,x3,x4};
		return s(4,temp);
	}

#line 114 "y.tab.c" /* yacc.c:339  */

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
    VOID = 258,
    INT = 259,
    FLOAT = 260,
    EXTERN = 261,
    STRUCT = 262,
    IF = 263,
    ELSE = 264,
    SWITCH = 265,
    FOR = 266,
    WHILE = 267,
    DO = 268,
    BREAK = 269,
    CONTINUE = 270,
    CASE = 271,
    DEFAULT = 272,
    RETURN = 273,
    INTEGERLITERAL = 274,
    FLOATLITERAL = 275,
    SIZEOF = 276,
    IDENTIFIER = 277,
    OP = 278,
    CP = 279,
    OFB = 280,
    CFB = 281,
    OSB = 282,
    CSB = 283,
    SC = 284,
    DOT = 285,
    INC = 286,
    DEC = 287,
    AMPERSAND = 288,
    UN_OR = 289,
    LESS = 290,
    GREATER = 291,
    EQ = 292,
    COM_EQ = 293,
    NOT = 294,
    NOT_EQ = 295,
    LE = 296,
    GE = 297,
    ACCESS = 298,
    PLUS = 299,
    MINUS = 300,
    STAR = 301,
    DIV = 302,
    MOD = 303,
    NEW_OP = 304,
    COMMA = 305,
    OR = 306,
    PRINT = 307,
    FORMAT_SPEC = 308,
    AND = 309,
    COLON = 310,
    QU = 311
  };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define FLOAT 260
#define EXTERN 261
#define STRUCT 262
#define IF 263
#define ELSE 264
#define SWITCH 265
#define FOR 266
#define WHILE 267
#define DO 268
#define BREAK 269
#define CONTINUE 270
#define CASE 271
#define DEFAULT 272
#define RETURN 273
#define INTEGERLITERAL 274
#define FLOATLITERAL 275
#define SIZEOF 276
#define IDENTIFIER 277
#define OP 278
#define CP 279
#define OFB 280
#define CFB 281
#define OSB 282
#define CSB 283
#define SC 284
#define DOT 285
#define INC 286
#define DEC 287
#define AMPERSAND 288
#define UN_OR 289
#define LESS 290
#define GREATER 291
#define EQ 292
#define COM_EQ 293
#define NOT 294
#define NOT_EQ 295
#define LE 296
#define GE 297
#define ACCESS 298
#define PLUS 299
#define MINUS 300
#define STAR 301
#define DIV 302
#define MOD 303
#define NEW_OP 304
#define COMMA 305
#define OR 306
#define PRINT 307
#define FORMAT_SPEC 308
#define AND 309
#define COLON 310
#define QU 311

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

#line 277 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    56,    57,    60,    60,    60,    63,    65,
      66,    67,    68,    71,    72,    73,    74,    75,    76,    77,
      78,    81,    82,    85,    88,    89,    92,    93,    96,    97,
     100,   101,   104,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   108,   111,   114,   117,   120,   123,   126,
     127,   130,   131,   134,   135,   138,   139,   142,   144,   146,
     148,   149,   152,   154,   156,   157,   158,   159,   162,   164,
     166,   166,   167,   167,   168,   169,   170,   170,   171,   172,
     172,   173,   173,   174,   174,   175,   176,   176,   177,   177,
     178,   179,   180,   181,   184,   184,   184,   185,   188,   189,
     190,   192,   193,   196,   197
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "FLOAT", "EXTERN",
  "STRUCT", "IF", "ELSE", "SWITCH", "FOR", "WHILE", "DO", "BREAK",
  "CONTINUE", "CASE", "DEFAULT", "RETURN", "INTEGERLITERAL",
  "FLOATLITERAL", "SIZEOF", "IDENTIFIER", "OP", "CP", "OFB", "CFB", "OSB",
  "CSB", "SC", "DOT", "INC", "DEC", "AMPERSAND", "UN_OR", "LESS",
  "GREATER", "EQ", "COM_EQ", "NOT", "NOT_EQ", "LE", "GE", "ACCESS", "PLUS",
  "MINUS", "STAR", "DIV", "MOD", "NEW_OP", "COMMA", "OR", "PRINT",
  "FORMAT_SPEC", "AND", "COLON", "QU", "$accept", "program", "decl_list",
  "decl", "struct_decl", "var_decl", "type_spec", "extern_spec",
  "func_decl", "params", "param_list", "param", "stmt_list", "stmt",
  "while_stmt", "dowhile_stmt", "print_stmt", "format_specifier",
  "compound_stmt", "local_decls", "local_decl", "if_stmt", "return_stmt",
  "break_stmt", "continue_stmt", "switch_stmt", "compound_case",
  "single_case", "default_case", "assign_stmt", "incr_stmt", "decr_stmt",
  "expr", "Pexpr", "integerLit", "floatLit", "identifier", "arg_list",
  "args", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,   -81,   -18,    11,    96,   -81,   -81,   -81,   -18,   110,
     -81,   -81,   -16,   -81,   -81,    40,   -30,   -28,    -4,   -81,
     -81,    92,     4,   -81,   102,   -81,   -81,   -81,    86,   -18,
     -18,    33,    12,   -81,   -81,    36,   -81,   -18,    46,   -18,
     -81,    43,    55,    69,   102,    -5,   -17,   -81,   -22,    78,
     -81,   -81,   -81,   -81,   102,   107,   -81,   -81,     7,   -81,
     -81,    88,   107,    27,    27,    27,    27,    27,    89,   120,
     -81,   -81,    77,   114,   115,   118,    58,   113,   125,   177,
     124,    26,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   215,    27,   135,   -81,   -81,
     -81,   -81,   -81,   -81,   141,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
     107,   107,   107,   107,   107,   137,   -81,   -81,   -81,   143,
     128,   -81,   -81,   107,   -18,   146,   154,   107,   -18,   166,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   142,   169,
     167,   178,   179,   180,   182,   -81,   -81,   151,   181,   170,
     -81,   -81,   184,   171,   -81,   107,   -81,   -81,    58,   192,
      58,   107,   -18,   183,   107,   -81,   107,   -81,   210,   208,
     -81,   201,   202,   107,   214,   219,    58,     4,   108,   -81,
     220,   221,   222,   -81,   -81,   -81,   189,   198,   -81,   228,
     -81,   -81,   -81,    58,    58,   -81,    58,    58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      22,    21,     0,     0,    22,     4,     7,     5,     0,     0,
       6,   100,    19,     1,     3,     0,    13,    14,    15,    50,
      20,    22,     0,     9,    22,    16,    17,    18,    22,     0,
       0,     0,    24,    27,    98,     0,    10,     0,     0,     0,
      49,    19,    28,     0,    22,     0,     0,     8,     0,     0,
      50,    23,    26,    11,    22,     0,    51,    29,    22,    12,
      99,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    35,    40,    41,    33,    34,    37,    38,
      39,    36,    32,    42,    43,     0,     0,     0,    90,    96,
      86,    88,    87,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,     0,     0,     0,    57,    58,    55,     0,
       0,    48,    30,     0,     0,     0,     0,     0,     0,     0,
      97,    52,    70,    71,    76,    77,    72,    73,    80,    81,
      82,    83,    84,    85,    78,    74,    79,   102,   103,     0,
       0,     0,     0,     0,     0,    56,    47,     0,     0,     0,
      68,    69,     0,     0,    75,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    64,     0,   101,    53,     0,
      44,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,    67,    66,    54,     0,     0,    60,     0,
      45,    46,    65,     0,     0,    59,    62,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   251,   -81,   -23,    37,   -81,   -81,   -81,
     -81,   212,   -80,   -73,   -81,   -81,   -81,   -81,   216,   207,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,    62,   -81,   -81,
     -81,   -81,   -36,   122,   -20,   -81,    -2,   -81,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    31,
      32,    33,    81,    82,    83,    84,    85,   167,    86,    28,
      40,    87,    88,    89,    90,    91,   198,   199,   209,    92,
      93,    94,    68,    69,    70,    71,    99,   158,   159
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    36,    35,   125,    11,    55,    15,    56,   132,    19,
      22,    13,    23,     1,    29,    73,    25,    74,    26,    75,
      76,    77,    78,    34,    53,    79,    97,    41,    42,    11,
      20,    59,    50,    24,    73,    46,    74,    48,    75,    76,
      77,    78,    27,   129,    79,    54,    34,    60,    11,    11,
      62,    50,   131,    72,     1,     2,    95,    43,    30,    80,
      72,    37,    44,    21,    45,    39,    73,    22,    74,    23,
      75,    76,    77,    78,    95,    47,    79,    72,    80,    95,
      11,    30,    49,    50,   157,   160,   161,   162,   163,    20,
      24,    37,     1,    29,    50,    39,    -2,   168,     1,    29,
     120,   172,     1,     2,   121,   188,    57,   190,     1,    29,
      80,    96,    38,    16,    17,    18,   -25,   104,    72,    72,
      72,    72,    72,   205,   197,   207,    34,    60,    61,    11,
      62,    72,   169,   216,   217,    72,   173,   122,   123,   187,
      63,   124,   126,   132,   132,   191,    64,   130,   194,   164,
     195,    65,    66,    67,   127,   105,   106,   202,   107,   140,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     141,   118,   165,    72,   119,   170,    95,   206,    95,    72,
     192,   166,    72,   171,    72,    98,   100,   101,   102,   103,
     174,    72,   175,   176,    95,   177,    34,    60,    61,    11,
      62,   182,   178,   179,   180,   181,   128,   184,   186,   183,
      63,    95,    95,   185,    95,    95,    64,   189,   139,   196,
     193,    65,    66,    67,   197,   200,   201,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   133,   203,   213,   134,   135,   136,   204,   210,
     211,   212,   137,   214,   215,    14,    52,    58,   138,    51,
     208
};

static const yytype_uint8 yycheck[] =
{
       2,    24,    22,    76,    22,    27,     8,    29,    81,    25,
      27,     0,    29,     6,     7,     8,    46,    10,    46,    12,
      13,    14,    15,    19,    29,    18,    62,    29,    30,    22,
      46,    54,    25,    50,     8,    37,    10,    39,    12,    13,
      14,    15,    46,    79,    18,    50,    19,    20,    22,    22,
      23,    25,    26,    55,     6,     7,    58,    24,    21,    52,
      62,    24,    50,    23,    28,    28,     8,    27,    10,    29,
      12,    13,    14,    15,    76,    29,    18,    79,    52,    81,
      22,    44,    27,    25,   120,   121,   122,   123,   124,    46,
      50,    54,     6,     7,    25,    58,     0,   133,     6,     7,
      23,   137,     6,     7,    27,   178,    28,   180,     6,     7,
      52,    23,    26,     3,     4,     5,    24,    28,   120,   121,
     122,   123,   124,   196,    16,    17,    19,    20,    21,    22,
      23,   133,   134,   213,   214,   137,   138,    23,    23,   175,
      33,    23,    29,   216,   217,   181,    39,    23,   184,    12,
     186,    44,    45,    46,    29,    35,    36,   193,    38,    24,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      29,    51,    29,   175,    54,    29,   178,   197,   180,   181,
     182,    53,   184,    29,   186,    63,    64,    65,    66,    67,
      24,   193,    50,    24,   196,    28,    19,    20,    21,    22,
      23,    50,    24,    24,    24,    23,    29,    37,    37,    28,
      33,   213,   214,    29,   216,   217,    39,    25,    96,     9,
      37,    44,    45,    46,    16,    24,    24,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    27,    29,    55,    30,    31,    32,    29,    29,
      29,    29,    37,    55,    26,     4,    44,    50,    43,    43,
     198
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    58,    59,    60,    61,    62,    63,    64,
      65,    22,    93,     0,    60,    93,     3,     4,     5,    25,
      46,    23,    27,    29,    50,    46,    46,    46,    76,     7,
      63,    66,    67,    68,    19,    91,    62,    63,    26,    63,
      77,    93,    93,    24,    50,    28,    93,    29,    93,    27,
      25,    75,    68,    29,    50,    27,    29,    28,    76,    62,
      20,    21,    23,    33,    39,    44,    45,    46,    89,    90,
      91,    92,    93,     8,    10,    12,    13,    14,    15,    18,
      52,    69,    70,    71,    72,    73,    75,    78,    79,    80,
      81,    82,    86,    87,    88,    93,    23,    89,    90,    93,
      90,    90,    90,    90,    28,    35,    36,    38,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    51,    54,
      23,    27,    23,    23,    23,    70,    29,    29,    29,    89,
      23,    26,    70,    27,    30,    31,    32,    37,    43,    90,
      24,    29,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    89,    94,    95,
      89,    89,    89,    89,    12,    29,    53,    74,    89,    93,
      29,    29,    89,    93,    24,    50,    24,    28,    24,    24,
      24,    23,    50,    28,    37,    29,    37,    89,    70,    25,
      70,    89,    93,    37,    89,    89,     9,    16,    83,    84,
      24,    24,    89,    29,    29,    70,    91,    17,    84,    85,
      29,    29,    29,    55,    55,    26,    69,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    61,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    72,    73,    74,    75,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    81,    82,
      83,    83,    84,    85,    86,    86,    86,    86,    87,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    91,    92,
      93,    94,    94,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     3,
       4,     6,     7,     2,     2,     2,     3,     3,     3,     2,
       3,     1,     0,     6,     1,     0,     3,     1,     2,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     7,     1,     4,     2,
       0,     3,     6,     5,     7,     2,     3,     2,     2,     8,
       2,     1,     4,     3,     4,     7,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     1,     4,     4,     1,     1,     1,     3,     1,     1,
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
#line 53 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s1((yyvsp[0])); tr_depth=((yyval)).max_path + 1; }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-1]),(yyvsp[0])); }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "Ass2.y" /* yacc.c:1646  */
    { (yyval)= s1((yyvsp[0])); }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 60 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s1((yyvsp[0])); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s1((yyvsp[0])); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s1((yyvsp[0])); }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-4]),(yyvsp[-2])); }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-2]),(yyvsp[-1])); }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s3((yyvsp[-3]),(yyvsp[-2]),(yyvsp[0])); }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s3((yyvsp[-5]),(yyvsp[-4]),(yyvsp[-2])); }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s4((yyvsp[-6]),(yyvsp[-5]),(yyvsp[-3]),(yyvsp[0])); }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 71 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-1]),(struct Node){0,0}); }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 72 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-1]),(struct Node){0,0}); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 73 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-1]),(struct Node){0,0}); }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 74 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-2]),(struct Node){0,0}); }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 75 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-2]),(struct Node){0,0}); }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 76 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-2]),(struct Node){0,0}); }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 77 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[0]),(struct Node){0,0}); }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 78 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-1]),(struct Node){0,0}); }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 81 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = (struct Node){1,1}; }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 82 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = (struct Node){1,1}; }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 85 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s4((yyvsp[-5]),(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0])); if(lbl_main) {main_depth=((yyval)).max_path+1;lbl_main=0;} printf("%d",((yyval)).max_path); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 88 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s1((yyvsp[0])); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 89 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = (struct Node){1,1}; }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 92 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-2]),(yyvsp[0])); }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 93 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 96 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-1]),(yyvsp[0])); }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 97 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-3]),(yyvsp[-2])); }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 100 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-1]),(yyvsp[0])); printf("%d", (yyval).max_path);}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 101 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); printf("stl = %d\n", (yyval).max_path);}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 104 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); printf("st = %d\n", (yyval).max_path);}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 104 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 104 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 105 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 106 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 106 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 107 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 107 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 108 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 108 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 108 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 111 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-2]),(yyvsp[0])); wh_depth=(wh_depth>((yyval)).max_path+1)?wh_depth:(((yyval)).max_path+1); }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 114 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-5]),(yyvsp[-2])); }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 117 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-4]),(yyvsp[-2])); }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 120 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,1}; }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 123 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-2]),(yyvsp[-1])); printf("cst = %d\n", (yyval).max_path);}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 126 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-1]),(yyvsp[0])); }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 127 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,1}; }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 130 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-2]),(yyvsp[-1])); }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 131 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s3((yyvsp[-5]),(yyvsp[-4]),(yyvsp[-2])); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 134 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-2]),(yyvsp[0])); if_depth=(if_depth>((yyval)).max_path+1)?if_depth:(((yyval)).max_path+1); }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 135 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s3((yyvsp[-4]),(yyvsp[-2]),(yyvsp[0])); if_depth=(if_depth>((yyval)).max_path+1)?if_depth:(((yyval)).max_path+1); }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 138 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,2}; }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 139 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-1]),(struct Node){0,0}); }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 142 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,2}; }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 144 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,2}; }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 146 "Ass2.y" /* yacc.c:1646  */
    {(yyval)=s3((yyvsp[-5]),(yyvsp[-2]),(yyvsp[-1])); printf("ccase %d dcase %d\n", (yyvsp[-2]).depth, (yyvsp[-1]).depth); sw_depth=(sw_depth>((yyval)).max_path+1)?sw_depth:((yyval)).max_path+1;}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 148 "Ass2.y" /* yacc.c:1646  */
    { (yyval) =s2((yyvsp[-1]),(yyvsp[0])); }
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 149 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 152 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-2]),(yyvsp[0])); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 154 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[0]),(struct Node){0,0}); }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 156 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2(s2((yyvsp[-3]),(yyvsp[-1])),(struct Node){0,0});  printf("ass = %d\n", (yyval).max_path);}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 157 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2(s3((yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1])),(struct Node){0,0}); }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 158 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2(s3((yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1])),(struct Node){0,0}); }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 159 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2(s3((yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1])),(struct Node){0,0}); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 162 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-2]),(struct Node){0,0}); }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 164 "Ass2.y" /* yacc.c:1646  */
    { (yyval) = s2((yyvsp[-2]),(struct Node){0,0}); }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 166 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 166 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 167 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 167 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 168 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 169 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-1]),(struct Node){0,0}); }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 170 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 170 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 171 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 172 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 172 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-2]),(yyvsp[0])); }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 173 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 173 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 174 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 174 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 175 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1(s2((yyvsp[-2]),(yyvsp[0]))); }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 176 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[0]),(struct Node){0,0}); }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 176 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[0]),(struct Node){0,0}); }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 177 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[0]),(struct Node){0,0}); }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 177 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[0]),(struct Node){0,0}); }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 178 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[0]),(struct Node){0,0}); }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 179 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 180 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-3]),(yyvsp[-1])); }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 181 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-3]),(yyvsp[-1])); }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 184 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 184 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 184 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 185 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-1]),(struct Node){0,0}); }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 188 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,1}; }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 189 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,1}; }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 190 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,1}; if(strcmp(yytext,"main")==0) lbl_main=1; }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 192 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s2((yyvsp[-2]),(yyvsp[0])); }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 193 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 196 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=s1((yyvsp[0])); }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 197 "Ass2.y" /* yacc.c:1646  */
    { (yyval)=(struct Node){1,1}; }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2134 "y.tab.c" /* yacc.c:1646  */
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
#line 200 "Ass2.y" /* yacc.c:1906  */


void yyerror(char *s) {
	lbl_pass=0;
	return;
}

int main(int argc,char* argv[]) {
	yyin=fopen(argv[1],"r");
	yyparse();
	if(lbl_pass){
		printf("tree_depth = %d \n",tr_depth);
		printf("if_depth = %d \n",if_depth);
		printf("while_depth = %d \n",wh_depth);
		printf("switch_depth = %d \n",sw_depth);
		printf("main_depth = %d \n",main_depth);
	}
	else printf("%s \n","***parsing terminated*** [syntax error]");
	return 0;
}


