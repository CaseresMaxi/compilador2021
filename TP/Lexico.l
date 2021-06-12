%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

FILE *yyin;

int yyerror(void);
int errorLexico(void);

%}

%option noyywrap
%option yylineno


DIGITO 			[0-9]
LETRA			[a-zA-Z]
COMILLA_D		["]


CONST_INT 		{DIGITO}+
CONST_FLOAT 	{DIGITO}+"."{DIGITO}+
OP_AVG			"avg"|"AVG"
CONST_STRING	{COMILLA_D}.({LETRA}|!|\ |{DIGITO}|>|<)+.{COMILLA_D}
ELSE_T			"else"|"ELSE"
IF_T			"if"|"IF"
OP_DISTINTO		"!""="
OP_COMP			"=""="
OP_MAYORIGUAL	">""="
OP_MAYOR		">"
OP_MENOR		"<"
OP_MENORIGUAL	"<""="
OP_ASIG			":="
OR_T			"OR"|"||"
AND_T			"AND"|"&&"
NOT_T 			"NOT"|"!"
LLAVE_C			"}"
LLAVE_A			"{"
PARENT_C		")"
PARENT_A		"("

COMENTARIO      "-""/"(.)*"/""-"
COMENTARIO_A    "-""/"
COMENTARIO_C	"/""-"

OP_DIVISION		"/"
OP_AS			":"
OP_SUM			"+"
OP_MUL			"*"
OP_MENOS		"-"
OP_MOD 			"MOD"|"Mod"|"mod"
OP_DIV 			"DIV"|"Div"|"div"
COMA			","
WHILE_T			"while"|"WHILE"
SEP_LINEA		";"
WRITE_T			"write"|"WRITE"
READ_T			"read"|"READ"
ENDDEC_T		"enddec"|"ENDDEC"
FLOAT_T			"Float"|"float"|"FLOAT"
INTEGER_T		"Integer"|"integer"|"INTEGER"
STRING_T 		"String"|"string"|"STRING"
DECVAR_T		"decvar"|"DECVAR"
IN_T 			"in"|"In"|"IN"
DO_T 			"do"|"Do"|"DO"
ENDWHILE_T 		"endwhile"|"Endwhile"|"ENDWHILE"
ID_T			{LETRA}({LETRA}|{DIGITO})*

%%
{COMENTARIO}		
{COMENTARIO_A}		
{COMENTARIO_C}		
{CONST_STRING}		{if(strlen(yytext)<=30){
						yylval.strVal = strdup(yytext);
						return CONST_STRING;}
					 else{
						printf("Longitud de la cadena mayor a 30\n");
						errorLexico();}}
{CONST_INT}			{yylval.strVal = strdup(yytext); return CONST_INT;}
{CONST_FLOAT}		{yylval.strVal = strdup(yytext); return CONST_FLOAT;}
{ELSE_T}			return ELSE_T;
{IF_T}				return IF_T;
{IN_T}				return IN_T;
{DO_T}				return DO_T;
{AND_T}				return AND_T;
{OR_T}				return OR_T;
{NOT_T}				return NOT_T;
{ENDWHILE_T} 		return ENDWHILE_T;
{OP_DISTINTO}		return OP_DISTINTO;
{OP_COMP}			return OP_COMP;
{OP_MAYORIGUAL}		return OP_MAYORIGUAL;
{OP_MAYOR}			return OP_MAYOR;
{OP_MENOR}			return OP_MENOR;
{OP_MENORIGUAL}		return OP_MENORIGUAL;
{LLAVE_C}			return LLAVE_C;
{LLAVE_A}			return LLAVE_A;
{PARENT_C}			return PARENT_C;
{PARENT_A}			return PARENT_A;
{OP_MOD} 			{yylval.strVal = strdup(yytext); return OP_MOD;}
{OP_DIV} 			{yylval.strVal = strdup(yytext); return OP_DIV;}
{OP_DIVISION}		{yylval.strVal = strdup(yytext); return OP_DIVISION;}
{OP_SUM}			{yylval.strVal = strdup(yytext); return OP_SUM;}
{OP_MENOS}			{yylval.strVal = strdup(yytext); return OP_MENOS;}
{OP_AS}				return OP_AS;
{OP_AVG}			return OP_AVG;
{OP_MUL}			{yylval.strVal = strdup(yytext); return OP_MUL;}
{COMA}				return COMA;
{WHILE_T}			return WHILE_T;
{WRITE_T}			{yylval.strVal = strdup(yytext); return WRITE_T;}
{READ_T}			return READ_T;
{ENDDEC_T}			return ENDDEC_T;
{FLOAT_T}			return FLOAT_T;
{INTEGER_T}			return INTEGER_T;
{STRING_T} 			return STRING_T;
{OP_ASIG}			{yylval.strVal = strdup(yytext); return OP_ASIG;}
{DECVAR_T}			return DECVAR_T;
{ID_T}				{yylval.strVal = strdup(yytext); return ID_T;}
{SEP_LINEA}			return SEP_LINEA;
"\n"
"\t"
" "
.					{printf("LEX-- NO SE ENCONTRO TOKEN \n");errorLexico();}

%%

int errorLexico(void){
	printf("Error lexico\n");
	system("Pause");
	exit(1);
}

int yyerror(void){

	printf("Error de sintaxis\n");
	system("Pause");
	exit(1);
}