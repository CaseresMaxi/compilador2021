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
LLAVE_C			"}"
LLAVE_A			"{"
PARENT_C		")"
PARENT_A		"("
OP_DIVISION		"/"
OP_AS			":"
OP_SUM			"+"
OP_MUL			"*"
OP_MENOS		"-"
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
ID_T			{LETRA}.({LETRA}|{DIGITO})*

%%
{CONST_STRING}		{printf("LEX-- ENTRE A CONST_STRING\n");
					 if(strlen(yytext)<=30){
						printf("Longitud del string %d\n",strlen(yytext));
						return CONST_STRING;}
					 else{
						printf("LEX-- longitud de la cadena mayor a 30\n");
						errorLexico();}}
{CONST_INT}			{printf("LEX-- ENTRE A TOKEN ENTERO\n"); return CONST_INT;}
{CONST_FLOAT}		return CONST_FLOAT;
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
{PARENT_C}			{printf("LEX-- ENTRE A TOKEN PARENT_C\n"); return PARENT_C;}
{PARENT_A}			{printf("LEX-- ENTRE A TOKEN PARENT_A\n"); return PARENT_A;}
{OP_DIVISION}		return OP_DIVISION;
{OP_SUM}			{printf("LEX-- ENTRE A TOKEN OP_SUM\n"); return OP_SUM;}
{OP_MENOS}			{printf("LEX-- ENTRE A TOKEN OP_MENOS\n"); return OP_MENOS;}
{OP_AS}				return OP_AS;
{OP_AVG}			{printf("LEX-- ENTRE A TOKEN OP_AVG\n"); return OP_AVG;}
{OP_MUL}			return OP_MUL;
{COMA}				return COMA;
{WHILE_T}			return WHILE_T;
{SEP_LINEA}			return SEP_LINEA;
{WRITE_T}			{printf("LEX-- ENTRE A WRITE\n"); return WRITE_T;};
{READ_T}			{printf("LEX-- ENTRE A WRITE\n"); return READ_T;};
{ENDDEC_T}			return ENDDEC_T;
{FLOAT_T}			return FLOAT_T;
{INTEGER_T}			return INTEGER_T;
{STRING_T} 			return STRING_T;
{OP_ASIG}			{printf("LEX-- ENTRE A TOKEN OP_ASIG\n"); return OP_ASIG;}
{DECVAR_T}			return DECVAR_T;
{ID_T}				{printf("LEX-- ENTRE A TOKEN ID_T\n"); return ID_T;}
"\n"
"\t"
" "
.					{printf("LEX-- NO SE ENCONTRO TOKEN \n");errorLexico();}

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