%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

FILE *yyin;
int yylval;

tabla tablaSimbolos;

%}

%option noyywrap
%option yylineno


DIGITO 		[0-9]
LETRA		[a-zA-Z]
COMILLA_D	["]


CONST_INT 			{DIGITO}+
CONST_FLOAT 		{DIGITO}+"."{DIGITO}+
CONST_STRING		\"(\\.|[^"\\])*\"
ELSE_T				"else"|"ELSE"
IF_T				"if"|"IF"
OP_DISTINTO			"!""="
OP_COMP				"=""="
OP_MAYORIGUAL		">""="
OP_MAYOR			">"
OP_MENOR			"<"
OP_MENORIGUAL		"<""="
LLAVE_C				"}"
LLAVE_A				"{"
PARENT_C			")"
PARENT_A			"("
OP_DIVISION			"/"
OP_AS				":"
OP_SUM				"+"
OP_MUL				"*"
WHILE_T				"while"|"WHILE"
SEP_LINEA			";"
WRITE_T				"write"|"WRITE"
ENDDEC_T			"enddec"|"ENDDEC"
FLOAT_T				"Float"|"float"|"FLOAT"
INTEGER_T			"Integer"|"integer"|"INTEGER"
DECVAR_T			"decvar"|"DECVAR"
ID_T				{LETRA}.({LETRA}|{DIGITO})*

%%
{CONST_INT}			insertar(yytext, SIN_VALOR, &tablaSimbolos);
{CONST_FLOAT}		insertar(yytext, SIN_VALOR, &tablaSimbolos);
{CONST_STRING}		if(mi_strlen(yytext)==1){insertar(yytext, CON_VALOR, &tablaSimbolos);}
{ELSE_T}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{IF_T}				insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_DISTINTO}		insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_COMP}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_MAYORIGUAL}		insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_MAYOR}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_MENOR}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_MENORIGUAL}		insertar(yytext, CON_VALOR, &tablaSimbolos);
{LLAVE_C}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{LLAVE_A}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{PARENT_C}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{PARENT_A}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_DIVISION}		insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_SUM}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_AS}				insertar(yytext, CON_VALOR, &tablaSimbolos);
{OP_MUL}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{WHILE_T}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{SEP_LINEA}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{WRITE_T}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{ENDDEC_T}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{FLOAT_T}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{INTEGER_T}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{DECVAR_T}			insertar(yytext, CON_VALOR, &tablaSimbolos);
{ID_T}				insertar(yytext, CON_VALOR, &tablaSimbolos);
"\n"
"\t"

%%


int main(int argc, char *argv[]){

	if((yyin = fopen(argv[1], "rt")) == NULL){
		printf("\nNo se pudo abrir el archivo: %s\n", argv[1]);
	}else{
		crearTabla(&tablaSimbolos);
		yylex();
	}
	vaciar_lista(&tablaSimbolos);
	fclose(yyin);
	return 0;
}

int yyerror(void){

	printf("Syntax Error\n");
	system("Pause");
	exit(1);
}