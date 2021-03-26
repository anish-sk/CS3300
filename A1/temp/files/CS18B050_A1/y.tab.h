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
