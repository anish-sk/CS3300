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
