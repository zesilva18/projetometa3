/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    CLASS = 258,
    PUBLIC = 259,
    STATIC = 260,
    COMMA = 261,
    LBRACE = 262,
    RBRACE = 263,
    LPAR = 264,
    RPAR = 265,
    LSQ = 266,
    RSQ = 267,
    ELSE = 268,
    ARROW = 269,
    RESERVED = 270,
    WHILE = 271,
    SEMICOLON = 272,
    ID = 273,
    STRLIT = 274,
    INTLIT = 275,
    REALLIT = 276,
    BOOLLIT = 277,
    BOOL = 278,
    INT = 279,
    DOUBLE = 280,
    PLUS = 281,
    MINUS = 282,
    STAR = 283,
    DIV = 284,
    MOD = 285,
    AND = 286,
    OR = 287,
    XOR = 288,
    LSHIFT = 289,
    RSHIFT = 290,
    EQ = 291,
    GE = 292,
    GT = 293,
    LE = 294,
    LT = 295,
    NE = 296,
    NOT = 297,
    ASSIGN = 298,
    PRINT = 299,
    RETURN = 300,
    PARSEINT = 301,
    DOTLENGTH = 302,
    VOID = 303,
    IF = 304,
    STRING = 305
  };
#endif
/* Tokens.  */
#define CLASS 258
#define PUBLIC 259
#define STATIC 260
#define COMMA 261
#define LBRACE 262
#define RBRACE 263
#define LPAR 264
#define RPAR 265
#define LSQ 266
#define RSQ 267
#define ELSE 268
#define ARROW 269
#define RESERVED 270
#define WHILE 271
#define SEMICOLON 272
#define ID 273
#define STRLIT 274
#define INTLIT 275
#define REALLIT 276
#define BOOLLIT 277
#define BOOL 278
#define INT 279
#define DOUBLE 280
#define PLUS 281
#define MINUS 282
#define STAR 283
#define DIV 284
#define MOD 285
#define AND 286
#define OR 287
#define XOR 288
#define LSHIFT 289
#define RSHIFT 290
#define EQ 291
#define GE 292
#define GT 293
#define LE 294
#define LT 295
#define NE 296
#define NOT 297
#define ASSIGN 298
#define PRINT 299
#define RETURN 300
#define PARSEINT 301
#define DOTLENGTH 302
#define VOID 303
#define IF 304
#define STRING 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "jucompiler.y"

char* string;
struct ast_tree* ast_tree;
struct info_lex *lex;  

#line 163 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
