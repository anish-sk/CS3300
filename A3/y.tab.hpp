/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

union YYSTYPE
{
#line 189 "a.y" /* yacc.c:1909  */

    class treeNode* node;

#line 164 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
