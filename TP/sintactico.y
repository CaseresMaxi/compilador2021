%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "funciones.h"

tabla tablaSimbolos;

extern int yylex();
extern void yyerror();
extern char* yytext;
extern int yylineno;

extern FILE* yyin;


%}

%union{
  char* strVal; 
}


%token <strVal> CONST_INT
%token <strVal> CONST_FLOAT 	
%token <strVal> CONST_STRING
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
%token <strVal> ID_T			
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
%token OP_MOD
%token OP_DIV

%left OP_SUM OP_MENOS
%left OP_MUL OP_DIVISION
%left OP_MOD OP_DIV
%right OP_ASIG

%%
programa_final : programa {printf("La expresion es valida\n");};

programa: bloque_declaracion sentencia
		| sentencia
		;

sentencia: sentencia grammar SEP_LINEA

sentencia: grammar SEP_LINEA

grammar : asig
		| while //{printf("SOY UN WHILE\n");}
		| write //{printf(" Soy un write\n");}
		| read 	//{printf(" Soy un reads\n");}
		| ciclo_especial //{printf("SOY UN CICLO ESPECIAL\n");}
		| if //{printf("SOY UN IF\n");}
		; 

while: WHILE_T cond_final LLAVE_A sentencia LLAVE_C
	 ;

if: IF_T cond_final LLAVE_A sentencia LLAVE_C
	|IF_T cond_final LLAVE_A sentencia LLAVE_C ELSE_T LLAVE_A sentencia LLAVE_C
	;

write : WRITE_T CONST_STRING_R 
	  | WRITE_T expr 
	  ;

read: READ_T ID_R 

ciclo_especial: WHILE_T ID_R IN_T PARENT_A lista_expresion PARENT_C DO_T sentencia ENDWHILE_T;

lista_expresion: expr
			   | lista_expresion COMA expr
			   ;

asig: ID_R OP_ASIG expr
	| ID_R OP_ASIG CONST_STRING_R
	;

cond_final: PARENT_A cond_final OR_AND cond_final PARENT_C | cond | NOT_T cond | PARENT_A cond_final PARENT_C

cond: PARENT_A expr COMPARADOR termino PARENT_C

COMPARADOR : OP_DISTINTO|OP_COMP|OP_MAYORIGUAL|OP_MAYOR|OP_MENOR|OP_MENORIGUAL

OR_AND: OR_T | AND_T

expr: expr OP_SUM expr  //{printf("SOY UNA SUMA\n");}
	| expr OP_MENOS expr //{printf("SOY UNA RESTA\n");}
	| termino
	;

termino : termino OP_MUL factor //{printf(" termino OP_MUL factor\n");}
		| termino OP_DIVISION factor //{printf(" termino OP_DIVISION factor\n");}
		| termino OP_MOD factor //{printf(" termino OP_MOD factor\n");}
		| termino OP_DIV factor //{printf(" termino OP_DIV factor\n");}
		| factor
		;

factor	: PARENT_A expr PARENT_C  //{printf(" PARENT_A expr PARENT_C\n");}
		| NUMERO  //{printf(" NUMERO\n");} 
		| ID_R //{printf(" ID_R\n");}
		;

bloque_declaracion: DECVAR_T declaracion ENDDEC_T

declaracion : linea_declaracion
			| declaracion linea_declaracion
			;

linea_declaracion: var_declaracion OP_AS tipo_variable SEP_LINEA

var_declaracion : ID_R 
				| var_declaracion COMA ID_R
				;

tipo_variable: FLOAT_T 
			 | INTEGER_T 
			 | STRING_T
			 ;

ID_R: ID_T {
		insertar_id(&tablaSimbolos,$1);
	};

CONST_STRING_R: CONST_STRING {
		insertar_string(&tablaSimbolos,$1);
	};

NUMERO: CONST_INT {
			insertar_numero(&tablaSimbolos,$1);
		}
	  | CONST_FLOAT {
	  		insertar_numero(&tablaSimbolos,$1);
	  	}
	  ;

%%


void main(int argc, char* argv[]){

	yyin = fopen(argv[1],"r+");
	if(!yyin){
		printf("No se pudo abrir el archivo %s\n",argv[1]);
		exit(1);
	}

	crear_Tabla(&tablaSimbolos);

	yyparse();

	vaciar_Tabla(&tablaSimbolos);
	printf("No hubo errores!\n");
	fclose(yyin);
	exit(1);

}