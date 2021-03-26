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
