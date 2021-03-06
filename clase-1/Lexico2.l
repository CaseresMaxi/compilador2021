%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "funciones.h"

FILE *yyin;
int yylval;

tabla tablaSimbolos;

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
CONST_STRING	{COMILLA_D}.({LETRA}|!|\ |{DIGITO}|>|<)+.{COMILLA_D}
ELSE_T			"else"|"ELSE"
IF_T			"if"|"IF"
OP_DISTINTO		"!""="
OP_COMP			"=""="
OP_MAYORIGUAL	">""="
OP_MAYOR		">"
OP_MENOR		"<"
OP_MENORIGUAL	"<""="
LLAVE_C			"}"
LLAVE_A			"{"
PARENT_C		")"
PARENT_A		"("
OP_DIVISION		"/"
OP_AS			":"
OP_SUM			"+"
OP_MUL			"*"
OP_MENOS		"-"
WHILE_T			"while"|"WHILE"
SEP_LINEA		";"
WRITE_T			"write"|"WRITE"
ENDDEC_T		"enddec"|"ENDDEC"
FLOAT_T			"Float"|"float"|"FLOAT"
INTEGER_T		"Integer"|"integer"|"INTEGER"
DECVAR_T		"decvar"|"DECVAR"
ID_T			{LETRA}.({LETRA}|{DIGITO})*

%%
{CONST_INT}			{printf("ENTRE A TOKEN ENTERO\n"); return CONST_INT;}
{CONST_FLOAT}		return CONST_FLOAT;
{CONST_STRING}		{printf("ENTRE A CONST_STRING\n");
					 if(strlen(yytext)<=30){
						printf("Longitud del string %d\n",strlen(yytext));
						return CONST_STRING;}
					 else{
						printf("longitud de la cadena mayor a 30\n");
						errorLexico();}}
{ELSE_T}			return ELSE_T;
{IF_T}				return IF_T;
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
{OP_DIVISION}		return OP_DIVISION;
{OP_SUM}			{printf("ENTRE A TOKEN OP_SUM\n"); return OP_SUM;}
{OP_AS}				return OP_AS;
{OP_MUL}			return OP_MUL;
{WHILE_T}			return WHILE_T;
{SEP_LINEA}			return SEP_LINEA;
{WRITE_T}			return WRITE_T;
{ENDDEC_T}			return ENDDEC_T;
{FLOAT_T}			return FLOAT_T;
{INTEGER_T}			return INTEGER_T;
{DECVAR_T}			return DECVAR_T;
{ID_T}				{printf("ENTRE A TOKEN ID_T\n"); return ID_T;}
.					{printf("NO SE ENCONTRO TOKEN \n");errorLexico();}
"\n"
"\t"

%%

//
//int main(int argc, char *argv[]){
//
//	if((yyin = fopen(argv[1], "rt")) == NULL){
//		printf("\nNo se pudo abrir el archivo: %s\n", argv[1]);
//	}else{
//		crearTabla(&tablaSimbolos);
//		yylex();
//	}
//	vaciar_lista(&tablaSimbolos);
//	fclose(yyin);
//	return 0;
//}
//

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