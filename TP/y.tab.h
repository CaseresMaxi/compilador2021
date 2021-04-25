
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONST_INT = 258,
     CONST_FLOAT = 259,
     CONST_STRING = 260,
     ELSE_T = 261,
     IF_T = 262,
     OP_DISTINTO = 263,
     OP_COMP = 264,
     OP_MAYORIGUAL = 265,
     OP_MAYOR = 266,
     OP_MENOR = 267,
     OP_MENORIGUAL = 268,
     LLAVE_C = 269,
     LLAVE_A = 270,
     PARENT_C = 271,
     PARENT_A = 272,
     OP_DIVISION = 273,
     OP_AS = 274,
     OP_SUM = 275,
     OP_MENOS = 276,
     OP_MUL = 277,
     WHILE_T = 278,
     SEP_LINEA = 279,
     SEPARADOR_T = 280,
     FLOAT_T = 281,
     INTEGER_T = 282,
     DIM_T = 283,
     AS_T = 284,
     TOKEN_PUT = 285,
     GET_T = 286,
     CONST_T = 287,
     TOKEN_AND = 288,
     TOKEN_OR = 289,
     MAX_TOKEN = 290,
     ID_T = 291,
     WRITE_T = 292,
     ENDDEC_T = 293,
     DECVAR_T = 294,
     OP_ASIG = 295,
     OP_AVG = 296,
     COMA = 297
   };
#endif
/* Tokens.  */
#define CONST_INT 258
#define CONST_FLOAT 259
#define CONST_STRING 260
#define ELSE_T 261
#define IF_T 262
#define OP_DISTINTO 263
#define OP_COMP 264
#define OP_MAYORIGUAL 265
#define OP_MAYOR 266
#define OP_MENOR 267
#define OP_MENORIGUAL 268
#define LLAVE_C 269
#define LLAVE_A 270
#define PARENT_C 271
#define PARENT_A 272
#define OP_DIVISION 273
#define OP_AS 274
#define OP_SUM 275
#define OP_MENOS 276
#define OP_MUL 277
#define WHILE_T 278
#define SEP_LINEA 279
#define SEPARADOR_T 280
#define FLOAT_T 281
#define INTEGER_T 282
#define DIM_T 283
#define AS_T 284
#define TOKEN_PUT 285
#define GET_T 286
#define CONST_T 287
#define TOKEN_AND 288
#define TOKEN_OR 289
#define MAX_TOKEN 290
#define ID_T 291
#define WRITE_T 292
#define ENDDEC_T 293
#define DECVAR_T 294
#define OP_ASIG 295
#define OP_AVG 296
#define COMA 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


