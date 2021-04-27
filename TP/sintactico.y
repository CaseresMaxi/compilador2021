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
%token OP_MENOS		
%token OP_MUL		
%token WHILE_T		
%token SEP_LINEA	
%token SEPARADOR_T	
%token FLOAT_T
%token INTEGER_T
%token STRING_T
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
%token READ_T
%token ENDDEC_T
%token DECVAR_T
%token OP_ASIG
%token OP_AVG
%token COMA
%token IN_T
%token DO_T
%token ENDWHILE_T
%token OR_T
%token AND_T
%token NOT_T

%left OP_SUM OP_MENOS
%left OP_MUL OP_DIVISION
%right OP_ASIG

%%


programa: bloque_declaracion sentencia {printf("La expresion es valida\n");};


sentencia: sentencia grammar SEP_LINEA

sentencia: grammar SEP_LINEA

grammar : asig
		| while {printf("SOY UN WHILE\n");}
		| write {printf(" Soy un write\n");}
		| read {printf(" Soy un reads\n");}
		| ciclo_especial {printf("SOY UN CICLO ESPECIAL\n");}
		| if {printf("SOY UN IF\n");}
		; 

while: WHILE_T cond_final LLAVE_A sentencia LLAVE_C
	 ;

if: IF_T cond_final LLAVE_A sentencia LLAVE_C

write : WRITE_T CONST_STRING 
	  | WRITE_T expr 
	  ;

read: READ_T ID_T 

ciclo_especial: WHILE_T ID_T IN_T PARENT_A lista_expresion PARENT_C DO_T sentencia ENDWHILE_T;

lista_expresion: expr
			   | lista_expresion COMA expr
			   ;

asig: ID_T OP_ASIG expr
	;

cond_final: PARENT_A cond_final OR_AND cond_final PARENT_C | cond | NOT_T cond

cond: PARENT_A expr COMPARADOR termino PARENT_C

COMPARADOR : OP_DISTINTO|OP_COMP|OP_MAYORIGUAL|OP_MAYOR|OP_MENOR|OP_MENORIGUAL

OR_AND: OR_T | AND_T

expr: expr OP_SUM expr  {printf("SOY UNA SUMA\n");}
	| expr OP_MENOS expr {printf("SOY UNA RESTA\n");}
	| termino
	;

termino : termino OP_MUL factor {printf(" termino OP_MUL factor\n");}
		| termino OP_DIVISION factor {printf(" termino OP_DIVISION factor\n");}
		| factor
		;

factor	: PARENT_A expr PARENT_C  {printf(" PARENT_A expr PARENT_C\n");}
		| CONST_INT  {printf(" CONST_INT\n");} 
		| ID_T {printf(" ID_T\n");}
		;

bloque_declaracion: DECVAR_T declaracion ENDDEC_T

declaracion : linea_declaracion
			| declaracion linea_declaracion
			;

linea_declaracion: var_declaracion OP_AS tipo_variable SEP_LINEA

var_declaracion : ID_T 
				| var_declaracion COMA ID_T
				;

tipo_variable: FLOAT_T 
			 | INTEGER_T 
			 | STRING_T
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