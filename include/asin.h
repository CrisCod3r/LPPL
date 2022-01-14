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

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    AND_ = 258,
    OR_ = 259,
    IGUAL_ = 260,
    DESIGUAL_ = 261,
    MAYOR_ = 262,
    MAYORIGUAL_ = 263,
    MENOR_ = 264,
    MENORIGUAL_ = 265,
    MULT_ = 266,
    DIV_ = 267,
    MAS_ = 268,
    MENOS_ = 269,
    NEGACION_ = 270,
    ASIG_ = 271,
    OPAR_ = 272,
    CPAR_ = 273,
    OCOR_ = 274,
    CCOR_ = 275,
    OLLA_ = 276,
    CLLA_ = 277,
    PUNTOYCOMA_ = 278,
    PUNTO_ = 279,
    COMA_ = 280,
    STRUCT_ = 281,
    INT_ = 282,
    BOOL_ = 283,
    RETURN_ = 284,
    READ_ = 285,
    PRINT_ = 286,
    IF_ = 287,
    ELSE_ = 288,
    WHILE_ = 289,
    TRUE_ = 290,
    FALSE_ = 291,
    CONSTANTE_ = 292,
    ID_ = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "src/asin.y"

    char *ident;    /* Nombre del identificador*/
    int cent;       /* Valor de la cte numerica entera*/
    struct {
        int talla;
        int refe;
    } LC;           /* Lista de campos con: talla y referencia*/

    struct {
        int talla;
        int refe;
    } LPF;          /* Lista de parametros formales con: talla y referencia*/
    
    struct {
        int tipo;
        int desp;
    } EXP;
    
    struct {
        int ref1;
        int ref2;
    } REF;

#line 120 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
