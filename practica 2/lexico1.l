%{
#include <stdio.h>
santi se la come
FILE *yyin;
int yylval;

%}

%option noyywrap
%option yylineno

DIGITO				[0-9]
DIGITO_SIN_CERO		[1-9]
CERO 				"0"
LETRA 				[a-zA-Z]
LETRA_MAYUS 		[A-Z]
LETRA_MINUS			[a-z]
GUION 				"-"
COMILLA 			\"

ABRE_PARENTESIS 	"("
CIERRA_PARENTESIS 	")"
ABRE_LLAVE 			"{"
CIERRA_LLAVE 		"}"

COMP_MENOR_IGUAL 	"<="
COMP_MAYOR_IGUAL 	">="
COMP_MENOR 			"<"
COMP_MAYOR 			">"
COMP_DISTINTO 		"!="
COMP_IGUAL 			"=="

OP_ASIGNACION 		":"
OP_SUMA 			"+"
OP_RESTA 			"-"
OP_MULTIPLICACION	"*"
OP_DIVISION 		"/"


DECVAR_R 			"DECVAR"
ENDDEC_R 			"ENDDEC"
WRITE_R 			"write"
INTEGER_R 			"Integer"
FLOAT_R 			"Float"
WHILE_R 			"while"|"WHILE"
IF_R 				"if"|"IF"
ELSE_R 				"else"|"ELSE"

STRING				\"(\\.|[^"\\])*\"

FLOAT_V 			{DIGITO}+"."{DIGITO}+
INTEGER_V 			{DIGITO}+

ID 					{LETRA}(({LETRA}|{DIGITO}|{GUION})*({LETRA}|{DIGITO}))*
%%

{ABRE_PARENTESIS} 			{printf("%s\n",yytext);}
{CIERRA_PARENTESIS} 		{printf("%s\n",yytext);}
{ABRE_LLAVE} 				{printf("%s\n",yytext);}
{CIERRA_LLAVE} 				{printf("%s\n",yytext);}
{COMP_MENOR_IGUAL} 			{printf("%s\n",yytext);}
{COMP_MAYOR_IGUAL} 			{printf("%s\n",yytext);}
{COMP_MENOR} 				{printf("%s\n",yytext);}
{COMP_MAYOR} 				{printf("%s\n",yytext);}
{COMP_DISTINTO} 			{printf("%s\n",yytext);}
{COMP_IGUAL} 				{printf("%s\n",yytext);}
{OP_ASIGNACION} 			{printf("%s\n",yytext);}
{OP_SUMA} 					{printf("%s\n",yytext);}
{OP_RESTA} 					{printf("%s\n",yytext);}
{OP_MULTIPLICACION} 		{printf("%s\n",yytext);}
{OP_DIVISION} 				{printf("%s\n",yytext);}
{DECVAR_R} 					{printf("%s\n",yytext);}
{ENDDEC_R} 					{printf("%s\n",yytext);}
{WRITE_R} 					{printf("%s\n",yytext);}
{INTEGER_R} 				{printf("%s\n",yytext);}
{FLOAT_R} 					{printf("%s\n",yytext);}
{WHILE_R} 					{printf("%s\n",yytext);}
{IF_R} 						{printf("%s\n",yytext);}
{ELSE_R} 					{printf("%s\n",yytext);}
{STRING} 					{printf("%s\n",yytext);}
{FLOAT_V} 					{printf("%s\n",yytext);}
{INTEGER_V} 				{printf("%s\n",yytext);}
{ID} 						{printf("%s\n",yytext);}


"\t"
"\n"
" "
";"
. 						{printf("/%s/\n",yytext);}

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