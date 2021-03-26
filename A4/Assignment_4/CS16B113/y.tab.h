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
