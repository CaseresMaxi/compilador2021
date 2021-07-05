
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
     OP_AS = 273,
     OP_DIVISION = 274,
     OP_SUM = 275,
     OP_MENOS = 276,
     OP_MUL = 277,
     WHILE_T = 278,
     SEP_LINEA = 279,
     SEPARADOR_T = 280,
     FLOAT_T = 281,
     INTEGER_T = 282,
     STRING_T = 283,
     DIM_T = 284,
     AS_T = 285,
     TOKEN_PUT = 286,
     GET_T = 287,
     CONST_T = 288,
     TOKEN_AND = 289,
     TOKEN_OR = 290,
     MAX_TOKEN = 291,
     ID_T = 292,
     WRITE_T = 293,
     READ_T = 294,
     ENDDEC_T = 295,
     DECVAR_T = 296,
     OP_ASIG = 297,
     OP_AVG = 298,
     COMA = 299,
     IN_T = 300,
     DO_T = 301,
     ENDWHILE_T = 302,
     OR_T = 303,
     AND_T = 304,
     NOT_T = 305,
     OP_MOD = 306,
     OP_DIV = 307
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
#define OP_AS 273
#define OP_DIVISION 274
#define OP_SUM 275
#define OP_MENOS 276
#define OP_MUL 277
#define WHILE_T 278
#define SEP_LINEA 279
#define SEPARADOR_T 280
#define FLOAT_T 281
#define INTEGER_T 282
#define STRING_T 283
#define DIM_T 284
#define AS_T 285
#define TOKEN_PUT 286
#define GET_T 287
#define CONST_T 288
#define TOKEN_AND 289
#define TOKEN_OR 290
#define MAX_TOKEN 291
#define ID_T 292
#define WRITE_T 293
#define READ_T 294
#define ENDDEC_T 295
#define DECVAR_T 296
#define OP_ASIG 297
#define OP_AVG 298
#define COMA 299
#define IN_T 300
#define DO_T 301
#define ENDWHILE_T 302
#define OR_T 303
#define AND_T 304
#define NOT_T 305
#define OP_MOD 306
#define OP_DIV 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 52 "Sintactico.y"

  char* strVal; 



/* Line 1676 of yacc.c  */
#line 162 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


