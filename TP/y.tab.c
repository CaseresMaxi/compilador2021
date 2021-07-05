
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "funciones.h"
#include "Lista.h"

#define COND_AND 2
#define COND_OR 1
#define COND_NORMAL 0

tabla tablaSimbolos;

t_lista listaPolaca;
t_pila 	pilaPolaca;

//CICLO ESPECIAL
t_pila  pilaWhileEspecialIni;
t_pila  pilaWhileEspecialIniSentencia;
t_pila  pilaWhileEspecialFin;
t_pila  pilaWhileEspecialExp;
t_pila  pilaWhileEspecialCantExp;

//AND OR
t_pila  pilaTipoCondicion;
t_pila  pilaOr;

//VARIABLES PARA LA TS
int bandDecvar = 0;
t_pila_decvar pilaDecvar;
int cantApila = 0;

//VARIABLES PARA LA POLACA
int cont = 1; //Inicia en 1 para imprimir correctamente el numero en el código intermedio
char simboloAux[3];
int bandNot = 0;
char idWhileEspecial[50]; //Variable que guarda el id del ciclo especial
int cantExpresiones;
int bandId = 0;

extern int yylex();
extern void yyerror();
extern char* yytext;
extern int yylineno;

extern FILE* yyin;




/* Line 189 of yacc.c  */
#line 125 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 52 "Sintactico.y"

  char* strVal; 



/* Line 214 of yacc.c  */
#line 271 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 283 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    14,    17,    19,    21,
      23,    25,    27,    29,    30,    37,    38,    49,    55,    58,
      61,    64,    65,    66,    67,    80,    81,    84,    85,    90,
      94,    98,    99,   106,   107,   114,   115,   122,   123,   124,
     132,   133,   134,   142,   143,   144,   152,   153,   160,   161,
     162,   170,   174,   175,   179,   183,   187,   189,   191,   193,
     195,   197,   199,   203,   207,   209,   213,   217,   221,   225,
     227,   231,   233,   235,   236,   241,   243,   246,   251,   253,
     257,   259,   261,   263,   265,   267,   269
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    91,    56,    -1,    56,    -1,
      56,    57,    24,    -1,    57,    24,    -1,    71,    -1,    58,
      -1,    62,    -1,    63,    -1,    64,    -1,    60,    -1,    -1,
      23,    59,    72,    15,    56,    14,    -1,    -1,     7,    72,
      15,    56,    14,    61,     6,    15,    56,    14,    -1,     7,
      72,    15,    56,    14,    -1,    38,    98,    -1,    38,    88,
      -1,    39,    97,    -1,    -1,    -1,    -1,    23,    65,    97,
      66,    45,    17,    68,    67,    16,    46,    56,    47,    -1,
      -1,    69,    88,    -1,    -1,    68,    44,    70,    88,    -1,
      97,    42,    88,    -1,    97,    42,    98,    -1,    -1,    17,
      72,    49,    72,    73,    16,    -1,    -1,    17,    86,    49,
      72,    74,    16,    -1,    -1,    17,    72,    49,    86,    75,
      16,    -1,    -1,    -1,    17,    72,    48,    76,    72,    77,
      16,    -1,    -1,    -1,    17,    86,    48,    78,    72,    79,
      16,    -1,    -1,    -1,    17,    72,    48,    80,    86,    81,
      16,    -1,    -1,    17,    86,    49,    86,    82,    16,    -1,
      -1,    -1,    17,    86,    48,    83,    86,    84,    16,    -1,
      17,    86,    16,    -1,    -1,    50,    85,    72,    -1,    17,
      72,    16,    -1,    88,    87,    89,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    88,
      20,    88,    -1,    88,    21,    88,    -1,    89,    -1,    89,
      22,    90,    -1,    89,    19,    90,    -1,    89,    51,    90,
      -1,    89,    52,    90,    -1,    90,    -1,    17,    88,    16,
      -1,    99,    -1,    97,    -1,    -1,    41,    92,    93,    40,
      -1,    94,    -1,    93,    94,    -1,    95,    18,    96,    24,
      -1,    97,    -1,    95,    44,    97,    -1,    26,    -1,    27,
      -1,    28,    -1,    37,    -1,     5,    -1,     3,    -1,     4,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   116,   117,   120,   122,   124,   125,   126,
     127,   128,   129,   132,   132,   182,   182,   233,   266,   267,
     270,   273,   275,   287,   273,   334,   334,   342,   342,   352,
     357,   360,   360,   367,   367,   374,   374,   381,   384,   381,
     400,   403,   400,   419,   422,   419,   438,   438,   445,   448,
     445,   464,   465,   465,   468,   471,   478,   486,   494,   502,
     510,   518,   528,   529,   530,   533,   536,   539,   542,   545,
     548,   549,   550,   553,   553,   555,   556,   559,   561,   562,
     566,   577,   588,   601,   626,   631,   635
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST_INT", "CONST_FLOAT",
  "CONST_STRING", "ELSE_T", "IF_T", "OP_DISTINTO", "OP_COMP",
  "OP_MAYORIGUAL", "OP_MAYOR", "OP_MENOR", "OP_MENORIGUAL", "LLAVE_C",
  "LLAVE_A", "PARENT_C", "PARENT_A", "OP_AS", "OP_DIVISION", "OP_SUM",
  "OP_MENOS", "OP_MUL", "WHILE_T", "SEP_LINEA", "SEPARADOR_T", "FLOAT_T",
  "INTEGER_T", "STRING_T", "DIM_T", "AS_T", "TOKEN_PUT", "GET_T",
  "CONST_T", "TOKEN_AND", "TOKEN_OR", "MAX_TOKEN", "ID_T", "WRITE_T",
  "READ_T", "ENDDEC_T", "DECVAR_T", "OP_ASIG", "OP_AVG", "COMA", "IN_T",
  "DO_T", "ENDWHILE_T", "OR_T", "AND_T", "NOT_T", "OP_MOD", "OP_DIV",
  "$accept", "programa_final", "programa", "sentencia", "grammar", "while",
  "$@1", "if", "$@2", "write", "read", "ciclo_especial", "$@3", "$@4",
  "$@5", "lista_expresion", "$@6", "$@7", "asig", "cond_final", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "cond", "COMPARADOR", "expr", "termino",
  "factor", "bloque_declaracion", "$@21", "declaracion",
  "linea_declaracion", "var_declaracion", "tipo_variable", "ID_R",
  "CONST_STRING_R", "NUMERO", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    59,    58,    61,    60,    60,    62,    62,
      63,    65,    66,    67,    64,    69,    68,    70,    68,    71,
      71,    73,    72,    74,    72,    75,    72,    76,    77,    72,
      78,    79,    72,    80,    81,    72,    82,    72,    83,    84,
      72,    72,    85,    72,    72,    86,    87,    87,    87,    87,
      87,    87,    88,    88,    88,    89,    89,    89,    89,    89,
      90,    90,    90,    92,    91,    93,    93,    94,    95,    95,
      96,    96,    96,    97,    98,    99,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     0,     6,     0,    10,     5,     2,     2,
       2,     0,     0,     0,    12,     0,     2,     0,     4,     3,
       3,     0,     6,     0,     6,     0,     6,     0,     0,     7,
       0,     0,     7,     0,     0,     7,     0,     6,     0,     0,
       7,     3,     0,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     1,     0,     4,     1,     2,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    13,    83,     0,     0,    73,     0,     2,     4,
       0,     8,    12,     9,    10,    11,     7,     0,     0,     0,
      52,     0,     0,     0,    85,    86,    84,     0,    19,    64,
      69,    72,    18,    71,    20,     0,     1,     0,     6,     3,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,    78,
       5,    29,    30,     0,    54,    43,     0,    51,    48,     0,
      56,    57,    58,    59,    60,    61,     0,    53,     0,     0,
       0,    70,    62,    63,    66,    65,    67,    68,    74,    76,
       0,     0,     0,     0,    31,    35,     0,     0,    33,    46,
      55,    15,     0,     0,    80,    81,    82,     0,    79,    38,
      44,     0,     0,    41,    49,     0,     0,     0,    14,    25,
      77,     0,     0,    32,    36,     0,     0,    34,    47,     0,
      23,     0,    39,    45,    42,    50,     0,    27,     0,    26,
       0,     0,     0,    16,    28,     0,     0,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    22,    12,   117,    13,
      14,    15,    23,    80,   138,   130,   131,   141,    16,    42,
     111,   115,   112,    92,   121,    96,   125,    93,   122,   116,
      97,   126,    45,    43,    76,    44,    29,    30,    17,    35,
      56,    57,    58,   107,    31,    32,    33
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -25
static const yytype_int16 yypact[] =
{
      21,   -14,   -16,   -25,    60,   -15,   -25,    25,   -25,   114,
       2,   -25,   -25,   -25,   -25,   -25,   -25,   114,   -12,     3,
     -25,    16,   -14,   -15,   -25,   -25,   -25,    51,    -2,    53,
     -25,   -25,   -25,   -25,   -25,   -15,   -25,    26,   -25,   114,
      60,     3,    33,    41,   165,   -14,   114,    46,   -25,    -6,
      51,    51,    51,    51,    51,    51,   -24,   -25,    56,   -25,
     -25,    -2,   -25,   151,   -25,    -5,     3,   -25,    17,     3,
     -25,   -25,   -25,   -25,   -25,   -25,    51,   -25,    73,   114,
      24,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     115,   -15,   -14,    51,   -25,   -25,   -14,    51,   -25,   -25,
      53,    59,    78,    67,   -25,   -25,   -25,    62,   -25,   -25,
     -25,    77,    82,   -25,   -25,    97,    98,    64,   -25,   -25,
     -25,   103,   104,   -25,   -25,   106,   108,   -25,   -25,    79,
      85,    51,   -25,   -25,   -25,   -25,   114,   -25,   110,    -2,
     111,    51,    89,   -25,    -2,   114,     4,   -25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   -13,    -7,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,     7,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,    61,   -25,    -3,    55,    54,   -25,   -25,
     -25,    88,   -25,   -25,     0,   107,   -25
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -41
static const yytype_int16 yytable[] =
{
      18,    28,    37,    19,    39,    34,    24,    25,    21,    18,
      81,     1,   -37,     3,    50,    51,    88,    18,    50,    51,
      41,   -21,     3,    48,    49,    36,    38,     2,     1,    47,
      40,    46,    37,    78,   -40,    59,    20,    61,    63,    18,
       3,     3,     4,     5,     2,   -37,    18,    82,    83,    64,
      60,   147,    77,    20,    24,    25,    59,    67,     3,     4,
       5,    79,     6,    24,    25,    26,   102,   -40,    27,   103,
     129,    37,    52,    94,    90,    53,    98,    27,    18,    18,
       1,    65,    66,   -17,   119,     1,   120,   101,     3,    68,
      69,   108,   118,   123,   136,    37,     2,     3,   124,   109,
      91,     2,    18,   113,    54,    55,    84,    85,    86,    87,
       3,     4,     5,   127,   128,     3,     4,     5,     1,   132,
     133,     1,   134,   140,   135,   143,   142,    95,   139,   137,
      99,   100,   146,    37,     2,   145,    18,     2,   144,    37,
      18,   104,   105,   106,    89,    18,    18,    62,     3,     4,
       5,     3,     4,     5,   110,     0,     0,     0,   114,    70,
      71,    72,    73,    74,    75,     0,     0,    81,     0,     0,
       0,    50,    51,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,     0,     0,    50,    51
};

static const yytype_int16 yycheck[] =
{
       0,     4,     9,    17,    17,     5,     3,     4,     1,     9,
      16,     7,    17,    37,    20,    21,    40,    17,    20,    21,
      17,    37,    37,    23,    27,     0,    24,    23,     7,    22,
      42,    15,    39,    46,    17,    35,    50,    40,    41,    39,
      37,    37,    38,    39,    23,    50,    46,    50,    51,    16,
      24,    47,    45,    50,     3,     4,    56,    16,    37,    38,
      39,    15,    41,     3,     4,     5,    79,    50,    17,    45,
       6,    78,    19,    66,    18,    22,    69,    17,    78,    79,
       7,    48,    49,    24,    17,     7,    24,    14,    37,    48,
      49,    91,    14,    16,    15,   102,    23,    37,    16,    92,
      44,    23,   102,    96,    51,    52,    52,    53,    54,    55,
      37,    38,    39,    16,    16,    37,    38,    39,     7,    16,
      16,     7,    16,   136,    16,    14,    16,    66,   131,    44,
      69,    76,   145,   140,    23,    46,   136,    23,   141,   146,
     140,    26,    27,    28,    56,   145,   146,    40,    37,    38,
      39,    37,    38,    39,    93,    -1,    -1,    -1,    97,     8,
       9,    10,    11,    12,    13,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    23,    37,    38,    39,    41,    54,    55,    56,
      57,    58,    60,    62,    63,    64,    71,    91,    97,    17,
      50,    72,    59,    65,     3,     4,     5,    17,    88,    89,
      90,    97,    98,    99,    97,    92,     0,    57,    24,    56,
      42,    17,    72,    86,    88,    85,    15,    72,    97,    88,
      20,    21,    19,    22,    51,    52,    93,    94,    95,    97,
      24,    88,    98,    88,    16,    48,    49,    16,    48,    49,
       8,     9,    10,    11,    12,    13,    87,    72,    56,    15,
      66,    16,    88,    88,    90,    90,    90,    90,    40,    94,
      18,    44,    76,    80,    72,    86,    78,    83,    72,    86,
      89,    14,    56,    45,    26,    27,    28,    96,    97,    72,
      86,    73,    75,    72,    86,    74,    82,    61,    14,    17,
      24,    77,    81,    16,    16,    79,    84,    16,    16,     6,
      68,    69,    16,    16,    16,    16,    15,    44,    67,    88,
      56,    70,    16,    14,    88,    46,    56,    47
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 114 "Sintactico.y"
    {printf("La expresion es valida\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 132 "Sintactico.y"
    {
			char cadena[7];
			char num[4];
			itoa(cont, num, 10);
			strcpy(cadena,"ET");
			strcat(cadena,num);
			apilar_en_polaca(&listaPolaca,cadena,cont++,&pilaPolaca);
		}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 140 "Sintactico.y"
    {
			char cadena[7];
			char num[4];
			int tipoCond = desapilar(&pilaTipoCondicion);


			if (tipoCond == COND_AND) {
				desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
				desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
			} else if (tipoCond == COND_OR) {
				desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);

				int saltoOr = desapilar(&pilaOr);
				desapilar_polaca(&listaPolaca,&pilaPolaca,saltoOr);

				int pos_comp = desapilar(&pilaOr);
				invertir_comp_en_pos(&listaPolaca,pos_comp);
			} else {
				int ret = desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
	
				if (ret == 0) {
					printf("ERROR FATAL");
				}
			}

			insertar_en_polaca(&listaPolaca,"BI",cont++);

			itoa(desapilar(&pilaPolaca),num,10);
			strcpy(cadena,"ET");
			strcat(cadena,num);
			insertar_en_polaca(&listaPolaca, cadena , cont++);

			char auxEtiq[10];
			char numero[10];
			strcpy(auxEtiq,"ET");
			itoa(cont, numero, 10);
			strcat(auxEtiq,numero);

			insertar_en_polaca(&listaPolaca,auxEtiq,cont++);
	 }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 182 "Sintactico.y"
    {

		int tipoCond = desapilar(&pilaTipoCondicion);

		if (tipoCond == COND_AND) {
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
		} else if (tipoCond == COND_OR) {
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);

			int saltoOr = desapilar(&pilaOr);
			desapilar_polaca(&listaPolaca,&pilaPolaca,saltoOr);

			int pos_comp = desapilar(&pilaOr);
			invertir_comp_en_pos(&listaPolaca,pos_comp);
		} else {
			int ret = desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);

			if (ret == 0) {
				printf("ERROR FATAL");
			}
		}

		insertar_en_polaca(&listaPolaca,"BI",cont++);
		apilar_en_polaca(&listaPolaca, "", cont++, &pilaPolaca);


		char auxEtiq[10];
		char numero[10];
		strcpy(auxEtiq,"ET");
		itoa(cont, numero, 10);
		strcat(auxEtiq,numero);

		insertar_en_polaca(&listaPolaca,auxEtiq,cont++);

	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 217 "Sintactico.y"
    {
		int ret = desapilar_polaca(&listaPolaca, &pilaPolaca, cont);

		if (ret == 0) {
			printf("ERROR FATAL");
		}

		char auxEtiq[10];
		char numero[10];
		strcpy(auxEtiq,"ET");
		itoa(cont, numero, 10);
		strcat(auxEtiq,numero);

		insertar_en_polaca(&listaPolaca,auxEtiq,cont++);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 233 "Sintactico.y"
    {
		int tipoCond = desapilar(&pilaTipoCondicion);


		if (tipoCond == COND_AND) {
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont);
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont);
		} else if (tipoCond == COND_OR) {
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont);
			
			int saltoOr = desapilar(&pilaOr);
			desapilar_polaca(&listaPolaca,&pilaPolaca,saltoOr);

			int pos_comp = desapilar(&pilaOr);
			invertir_comp_en_pos(&listaPolaca,pos_comp);
		} else {
			int ret = desapilar_polaca(&listaPolaca,&pilaPolaca,cont);

			if (ret == 0) {
				printf("ERROR FATAL");
			}
		}

		char auxEtiq[10];
		char numero[10];
		strcpy(auxEtiq,"ET");
		itoa(cont, numero, 10);
		strcat(auxEtiq,numero);

		insertar_en_polaca(&listaPolaca,auxEtiq,cont++);
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 266 "Sintactico.y"
    {insertar_en_polaca(&listaPolaca,"WRITE",cont++);}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 267 "Sintactico.y"
    {insertar_en_polaca(&listaPolaca,"WRITE",cont++);}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 270 "Sintactico.y"
    {insertar_en_polaca(&listaPolaca,"READ",cont++);}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 273 "Sintactico.y"
    {
			bandId = 1;
	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 275 "Sintactico.y"
    {
			apilar(&pilaWhileEspecialIni,cont);

			char cadena[7];
			char num[4];
			itoa(cont, num, 10);
			strcpy(cadena,"ET");
			strcat(cadena,num);

			insertar_en_polaca(&listaPolaca,cadena,cont++);
			cantExpresiones = 0;
			bandId = 0;
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 287 "Sintactico.y"
    {
			insertar_en_polaca(&listaPolaca,"BI",cont++);
			apilar_en_polaca(&listaPolaca, "", cont++, &pilaWhileEspecialFin);
			apilar(&pilaWhileEspecialCantExp,cantExpresiones);
			apilar(&pilaWhileEspecialIniSentencia,cont);

			char auxEtiq[10];
			char numero[10];
			strcpy(auxEtiq,"ET");
			itoa(cont, numero, 10);
			strcat(auxEtiq,numero);

			insertar_en_polaca(&listaPolaca,auxEtiq,cont++);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 300 "Sintactico.y"
    {
			int posIni = desapilar(&pilaWhileEspecialIni);

			char auxPosIni[10];
			char num[4];
			itoa(posIni, num, 10);
			strcpy(auxPosIni,"ET");
			strcat(auxPosIni,num);

			insertar_en_polaca(&listaPolaca,"BI",cont++);
			insertar_en_polaca(&listaPolaca,auxPosIni,cont++);

			int ret = desapilar_polaca(&listaPolaca,&pilaWhileEspecialFin,cont);

			if (ret == 0) {
				printf("ERROR FATAL");
			}

			int cantFinExpresiones = desapilar(&pilaWhileEspecialCantExp);
			int auxIniSentencia = desapilar(&pilaWhileEspecialIniSentencia);

			for(;cantFinExpresiones > 0; cantFinExpresiones --) {
				desapilar_polaca(&listaPolaca,&pilaWhileEspecialExp,auxIniSentencia);
			}

			char auxEtiq[10];
			char numero[10];
			strcpy(auxEtiq,"ET");
			itoa(cont, numero, 10);
			strcat(auxEtiq,numero);

			insertar_en_polaca(&listaPolaca,auxEtiq,cont++);
	}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 334 "Sintactico.y"
    {
		insertar_en_polaca(&listaPolaca,idWhileEspecial,cont++);
	}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 336 "Sintactico.y"
    {
		insertar_en_polaca(&listaPolaca,"CMP",cont++);
		insertar_en_polaca(&listaPolaca,"BE",cont++);
		apilar_en_polaca(&listaPolaca, "", cont++, &pilaWhileEspecialExp);
		cantExpresiones++;
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 342 "Sintactico.y"
    {
		insertar_en_polaca(&listaPolaca,idWhileEspecial,cont++);
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 344 "Sintactico.y"
    {
		insertar_en_polaca(&listaPolaca,"CMP",cont++);
		insertar_en_polaca(&listaPolaca,"BE",cont++);
		apilar_en_polaca(&listaPolaca, "", cont++, &pilaWhileEspecialExp);
		cantExpresiones++;
	}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 352 "Sintactico.y"
    {
		
		insertar_en_polaca(&listaPolaca,(yyvsp[(2) - (3)].strVal),cont++);
		
	}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 360 "Sintactico.y"
    {

				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_AND);
			
			}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 367 "Sintactico.y"
    {

				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_AND);
			
			}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 374 "Sintactico.y"
    {

				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_AND);
			
			}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 381 "Sintactico.y"
    {
					//Apilamos posicion del comparador
					apilar(&pilaOr,cont-2);
				}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 384 "Sintactico.y"
    {
				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_OR);
			
			}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 389 "Sintactico.y"
    {
				//Apilar donde empieza el codigo
				char num[10];
				char etiqueta[10];

				itoa(cont,num,10);
				strcpy(etiqueta,"ET");
				strcat(etiqueta,num);
				apilar(&pilaOr,cont);
				insertar_en_polaca(&listaPolaca,etiqueta,cont++);
			}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 400 "Sintactico.y"
    {
					//Apilamos posicion del comparador
					apilar(&pilaOr,cont-2);
				}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 403 "Sintactico.y"
    {
				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_OR);
			
			}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 408 "Sintactico.y"
    {
				//Apilar donde empieza el codigo
				char num[10];
				char etiqueta[10];

				itoa(cont,num,10);
				strcpy(etiqueta,"ET");
				strcat(etiqueta,num);
				apilar(&pilaOr,cont);
				insertar_en_polaca(&listaPolaca,etiqueta,cont++);
			}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 419 "Sintactico.y"
    {
					//Apilamos posicion del comparador
					apilar(&pilaOr,cont-2);
				}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 422 "Sintactico.y"
    {
				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_OR);
			
			}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 427 "Sintactico.y"
    {
				//Apilar donde empieza el codigo
				char num[10];
				char etiqueta[10];

				itoa(cont,num,10);
				strcpy(etiqueta,"ET");
				strcat(etiqueta,num);
				apilar(&pilaOr,cont);
				insertar_en_polaca(&listaPolaca,etiqueta,cont++);
			}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 438 "Sintactico.y"
    {

				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_AND);
			
			}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 445 "Sintactico.y"
    {
					//Apilamos posicion del comparador
					apilar(&pilaOr,cont-2);
				}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 448 "Sintactico.y"
    {
				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_OR);
			
			}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 453 "Sintactico.y"
    {
				//Apilar donde empieza el codigo
				char num[10];
				char etiqueta[10];

				itoa(cont,num,10);
				strcpy(etiqueta,"ET");
				strcat(etiqueta,num);
				apilar(&pilaOr,cont);
				insertar_en_polaca(&listaPolaca,etiqueta,cont++);
			}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 465 "Sintactico.y"
    {
		  	bandNot = 1;
		  }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 471 "Sintactico.y"
    {
			insertar_en_polaca(&listaPolaca,"CMP",cont++);
			insertar_en_polaca(&listaPolaca,simboloAux,cont++);
			apilar_en_polaca(&listaPolaca,"",cont++,&pilaPolaca);
			apilar(&pilaTipoCondicion,COND_NORMAL);
		}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 478 "Sintactico.y"
    { 
							if (bandNot == 0) {
								strcpy(simboloAux,"BEQ");
							} else {
								strcpy(simboloAux,"BNE");
								bandNot = 0;
							}
						}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 486 "Sintactico.y"
    { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BNE");
							} else {
								strcpy(simboloAux,"BEQ");
								bandNot = 0;
							}
						}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 494 "Sintactico.y"
    { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BLT");
							} else {
								strcpy(simboloAux,"BGE");
								bandNot = 0;
							}
						}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 502 "Sintactico.y"
    { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BLE");
							} else {
								strcpy(simboloAux,"BGT");
								bandNot = 0;
							}
						}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 510 "Sintactico.y"
    { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BGE");
							} else {
								strcpy(simboloAux,"BLT");
								bandNot = 0;
							}
						}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 518 "Sintactico.y"
    { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BGT");
							} else {
								strcpy(simboloAux,"BLE");
								bandNot = 0;
							}
						}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 528 "Sintactico.y"
    {insertar_en_polaca(&listaPolaca,(yyvsp[(2) - (3)].strVal),cont++); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 529 "Sintactico.y"
    {insertar_en_polaca(&listaPolaca,(yyvsp[(2) - (3)].strVal),cont++);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 533 "Sintactico.y"
    { 
			insertar_en_polaca(&listaPolaca,(yyvsp[(2) - (3)].strVal),cont++); 
		}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 536 "Sintactico.y"
    { 
			insertar_en_polaca(&listaPolaca,(yyvsp[(2) - (3)].strVal),cont++); 
		}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 539 "Sintactico.y"
    { 
			insertar_en_polaca(&listaPolaca,"MOD",cont++); 
		}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 542 "Sintactico.y"
    { 
			insertar_en_polaca(&listaPolaca,"DIV",cont++); 
		}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 553 "Sintactico.y"
    { bandDecvar = 1; printf("\n  "); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 553 "Sintactico.y"
    { bandDecvar = 0; }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 566 "Sintactico.y"
    {
					char* valor_actual;
					while(cantApila > 0) 
					{
						valor_actual = desapilar_decvar(&pilaDecvar);
						if(insertar_id(&tablaSimbolos,valor_actual,TIPO_FLOAT) == 0) {
							exit(1);
						}
						cantApila--;
					}
				}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 577 "Sintactico.y"
    {
			 		char* valor_actual;
					while(cantApila > 0) 
					{
						valor_actual = desapilar_decvar(&pilaDecvar);
						if(insertar_id(&tablaSimbolos,valor_actual,TIPO_INTEGER) == 0) {
							exit(1);
						}
						cantApila--;
					}
			 }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 588 "Sintactico.y"
    {
			 		char* valor_actual;
					while(cantApila > 0) 
					{
						valor_actual = desapilar_decvar(&pilaDecvar);
						if(insertar_id(&tablaSimbolos,valor_actual,TIPO_STRING)== 0) {
							exit(1);
						}
						cantApila--;
					}
			 }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 601 "Sintactico.y"
    {
		if(bandDecvar == 1) {
			cantApila++;
			apilar_decvar(&pilaDecvar,(yyvsp[(1) - (1)].strVal));

		} else {
			//Validar si existe

			if(validar_id(&tablaSimbolos,(yyvsp[(1) - (1)].strVal)) == 1) {
				//Si existe
				if( bandId == 0) {
					insertar_en_polaca(&listaPolaca,(yyvsp[(1) - (1)].strVal),cont++);
				} else {
					strcpy(idWhileEspecial,(yyvsp[(1) - (1)].strVal));
				}
			} else {
				printf("\n\nERROR\nLa variable %s no se encuentra declarada",(yyvsp[(1) - (1)].strVal));
				exit(1);
			}


		}

	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 626 "Sintactico.y"
    {
		insertar_en_polaca(&listaPolaca,(yyvsp[(1) - (1)].strVal),cont++);
		insertar_string(&tablaSimbolos,(yyvsp[(1) - (1)].strVal));
	}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 631 "Sintactico.y"
    {
			insertar_en_polaca(&listaPolaca,(yyvsp[(1) - (1)].strVal),cont++);
			insertar_numero(&tablaSimbolos,(yyvsp[(1) - (1)].strVal),TIPO_INTEGER);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 635 "Sintactico.y"
    {
	  		insertar_en_polaca(&listaPolaca,(yyvsp[(1) - (1)].strVal),cont++);
	  		insertar_numero(&tablaSimbolos,(yyvsp[(1) - (1)].strVal),TIPO_FLOAT);
	  	}
    break;



/* Line 1455 of yacc.c  */
#line 2446 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 642 "Sintactico.y"



void main(int argc, char* argv[]){

	yyin = fopen(argv[1],"r+");
	if(!yyin){
		printf("No se pudo abrir el archivo %s\n",argv[1]);
		exit(1);
	}

	crear_Tabla(&tablaSimbolos);
	crear_lista(&listaPolaca);

	crear_Pila(&pilaPolaca);
	crear_Pila_decvar(&pilaDecvar);

	//CICLO ESPECIAL
	crear_Pila(&pilaWhileEspecialIni);
	crear_Pila(&pilaWhileEspecialFin);
	crear_Pila(&pilaWhileEspecialExp);
	crear_Pila(&pilaWhileEspecialCantExp);
	crear_Pila(&pilaWhileEspecialIniSentencia);
	
	//AND OR
	crear_Pila(&pilaTipoCondicion);
	crear_Pila(&pilaOr);

	yyparse();

	vaciar_Tabla(&tablaSimbolos);
	vaciar_polaca(&listaPolaca);


	generarAssembler(&listaPolaca,&tablaSimbolos);


	printf("No hubo errores!\n");
	fclose(yyin);
	exit(1);

}
