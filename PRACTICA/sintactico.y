%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

extern int yylex();
extern void yyerror();
extern char* yytext;
extern int yylineno;

extern FILE* yyin;


%}



%token CONST_INT 	
%token CONST_FLOAT 	
%token CONST_STRING	
%token ELSE_T			
%token IF_T			
%token OP_DISTINTO	
%token OP_COMP		
%token OP_MAYORIGUAL
%token OP_MAYOR		
%token OP_MENOR		
%token OP_MENORIGUAL
%token LLAVE_C		
%token LLAVE_A		
%token PARENT_C		
%token PARENT_A		
%token OP_DIVISION	
%token OP_AS		
%token OP_SUM		
%token OP_MUL		
%token WHILE_T		
%token SEP_LINEA	
%token SEPARADOR_T	
%token FLOAT_T		
%token INTEGER_T	
%token DIM_T		
%token AS_T			
%token TOKEN_PUT	
%token GET_T		
%token CONST_T  	
%token TOKEN_AND	
%token TOKEN_OR		
%token MAX_TOKEN	
%token ID_T			
%token WRITE_T
%token ENDDEC_T
%token DECVAR_T

%left OP_SUM OP_MENOS
%left OP_MUL OP_DIVISION

%%

programa: 	 grammar SEP_LINEA
			|grammar SEP_LINEA "\\n"grammar SEP_LINEA
			;
grammar: expr  {printf("La expresion es valida\n");};

expr:expr OP_SUM expr  {printf("SOY UNA SUMA\n");}
	|expr OP_MENOS expr
	|expr OP_MUL expr
	|expr OP_DIVISION expr
	|CONST_STRING {printf("SOY UN STRING\n");}
	|CONST_INT {printf("SOY UNA CTE\n", CONST_INT);}
	;

%%


void main(int argc, char* argv[]){

	yyin = fopen(argv[1],"r+");
	if(!yyin){
		printf("No se pudo abrir el archivo %s\n",argv[1]);
		exit(1);
	}
	yyparse();
	printf("No hubo errores!\n");
	fclose(yyin);
	exit(1);

}