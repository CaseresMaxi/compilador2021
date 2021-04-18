%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE *yyin;
int yylval;
char *yyltext;

%}

%option noyywrap
%option yylineno


DIGITO 		[0-9]
LETRA		[a-zA-Z]
COMILLA_D	["]


CONST_INT 	{DIGITO}+
CONST_FLOAT 	{DIGITO}+"."{DIGITO}+
CONST_STRING	{COMILLA_D}.({LETRA}|!|{DIGITO}|:|¡|?|¿|\ |>|<)+.{COMILLA_D}
ELSE_T		"else"|"ELSE"
IF_T		"if"|"IF"
OP_DISTINTO	"!""="
OP_COMP		"=""="
OP_MAYORIGUAL	">""="
OP_MAYOR	">"
OP_MENOR	"<"
OP_MENORIGUAL	"<""="
LLAVE_C		"}"
LLAVE_A		"{"
PARENT_C	")"
PARENT_A	"("
OP_DIVISION	"/"
OP_AS		":"
OP_SUM		"+"
OP_MUL		"*"
WHILE_T		"while"|"WHILE"
SEP_LINEA	";"
WRITE_T		"write"|"WRITE"
ENDDEC_T	"enddec"|"ENDDEC"
FLOAT_T		"Float"|"float"|"FLOAT"
INTEGER_T	"Integer"|"integer"|"INTEGER"
DECVAR_T	"decvar"|"DECVAR"
ID_T		{LETRA}.({LETRA}|{DIGITO})*

%%
{CONST_INT}		printf("\nConstante Entera: %s\n", yytext);
{CONST_FLOAT}		printf("\nConstante Flotante: %s\n", yytext);
{CONST_STRING}		printf("\nConstante String: %s\n", yytext);
{ELSE_T}		printf("\nElse: %s\n", yytext);
{IF_T}			printf("\nIf: %s\n", yytext);
{OP_DISTINTO}		printf("\nDistinto: %s\n", yytext);
{OP_COMP}		printf("\nComparacion: %s\n", yytext);
{OP_MAYORIGUAL}		printf("\nMayor o Igual: %s\n", yytext);
{OP_MAYOR}		printf("\nMayor: %s\n", yytext);
{OP_MENOR}		printf("\nMenor: %s\n", yytext);
{OP_MENORIGUAL}		printf("\nMenor o Igual: %s\n", yytext);
{LLAVE_C}		printf("\nLlave Cerrada: %s\n", yytext);
{LLAVE_A}		printf("\nLlave Abierta: %s\n", yytext);
{PARENT_C}		printf("\nParentesis Cerrado: %s\n", yytext);
{PARENT_A}		printf("\nParentesis Abierto: %s\n", yytext);
{OP_DIVISION}		printf("\nDivision: %s\n", yytext);
{OP_SUM}		printf("\nSuma: %s\n", yytext);
{OP_AS}			printf("\nAsignacion: %s\n", yytext);
{OP_MUL}		printf("\nMultiplicacion: %s\n", yytext);
{WHILE_T}		printf("\nWhile: %s\n", yytext);
{SEP_LINEA}		printf("\nSeparador de linea: %s\n", yytext);
{WRITE_T}		printf("\nWrite: %s\n", yytext);
{ENDDEC_T}		printf("\nEnddec: %s\n", yytext);
{FLOAT_T}		printf("\nFloat: %s\n", yytext);
{INTEGER_T}		printf("\nInteger: %s\n", yytext);
{DECVAR_T}		printf("\nDecvar: %s\n", yytext);
{ID_T}			printf("\nIdentificador: %s\n", yytext);
"\n"
"\t"

%%


int main(int argc, char *argv[]){
	if((yyin = fopen(argv[1], "rt")) == NULL){
		printf("\nNo se pudo abrir el archivo: %s\n", argv[1]);
	}else{
		yylex();
	}
	fclose(yyin);
	return 0;
}

int yyerror(void){

	printf("Syntax Error\n");
	system("Pause");
	exit(1);
}