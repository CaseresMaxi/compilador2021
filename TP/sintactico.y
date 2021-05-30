%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "funciones.h"
#include "Lista.h"

tabla tablaSimbolos;

t_lista listaPolaca;

//Variables para polaca
int cont = 0;
char simboloAux[3];
int bandNot = 0;

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
%token OP_AS		
%token <strVal> OP_DIVISION	
%token <strVal> OP_SUM
%token <strVal> OP_MENOS		
%token <strVal> OP_MUL		
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
%token <strVal> OP_ASIG
%token OP_AVG
%token COMA
%token IN_T
%token DO_T
%token ENDWHILE_T
%token OR_T
%token AND_T
%token NOT_T
%token <strVal> OP_MOD
%token <strVal> OP_DIV

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

if: IF_T cond_final LLAVE_A sentencia LLAVE_C | IF_T cond_final LLAVE_A sentencia LLAVE_C ELSE_T LLAVE_A sentencia LLAVE_C

write : WRITE_T CONST_STRING_R 
	  | WRITE_T expr 
	  ;

read: READ_T ID_R 

ciclo_especial: WHILE_T ID_R IN_T PARENT_A lista_expresion PARENT_C DO_T sentencia ENDWHILE_T;

lista_expresion: expr
			   | lista_expresion COMA expr
			   ;

asig: ID_R OP_ASIG expr{
		insertar_en_polaca(&listaPolaca,$2,cont++);
	}
	| ID_R OP_ASIG CONST_STRING_R 
	;

cond_final: PARENT_A cond_final OR_AND cond_final PARENT_C 
		  | cond 
		  | NOT_T {
		  	bandNot = 1;
		  } cond 
		  | PARENT_A cond_final PARENT_C
		  ;

cond: PARENT_A expr COMPARADOR termino PARENT_C {
			insertar_en_polaca(&listaPolaca,"CMP",cont++);
			insertar_en_polaca(&listaPolaca,simboloAux,cont++);
		}

COMPARADOR : OP_DISTINTO { 
							if (bandNot == 0) {
								strcpy(simboloAux,"BEQ");
							} else {
								strcpy(simboloAux,"BNE");
							}
						}
						|OP_COMP { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BNE");
							} else {
								strcpy(simboloAux,"BEQ");
								bandNot = 0;
							}
						}
						|OP_MAYORIGUAL { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BLT");
							} else {
								strcpy(simboloAux,"BGE");
								bandNot = 0;
							}
						}
						|OP_MAYOR { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BLE");
							} else {
								strcpy(simboloAux,"BGT");
								bandNot = 0;
							}
						}
						|OP_MENOR { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BGE");
							} else {
								strcpy(simboloAux,"BLT");
								bandNot = 0;
							}
						}
						|OP_MENORIGUAL { 
							if (bandNot == 0) {
								strcpy(simboloAux, "BGT");
							} else {
								strcpy(simboloAux,"BLE");
								bandNot = 0;
							}
						}
						;

//*RESERVAR SALTOS*
OR_AND: OR_T 
			| AND_T
			; 

expr: expr OP_SUM expr {insertar_en_polaca(&listaPolaca,$2,cont++); }
	| expr OP_MENOS expr {insertar_en_polaca(&listaPolaca,$2,cont++);} 
	| termino
	;

termino : termino OP_MUL factor { 
			insertar_en_polaca(&listaPolaca,$2,cont++); 
		}
		| termino OP_DIVISION factor { 
			insertar_en_polaca(&listaPolaca,$2,cont++); 
		}
		| termino OP_MOD factor { 
			insertar_en_polaca(&listaPolaca,$2,cont++); 
		}
		| termino OP_DIV factor { 
			insertar_en_polaca(&listaPolaca,$2,cont++); 
		}
		| factor
		;

factor	: PARENT_A expr PARENT_C
		| NUMERO
		| ID_R
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
	insertar_en_polaca(&listaPolaca,$1,cont++);
		insertar_id(&tablaSimbolos,$1);
	};

CONST_STRING_R: CONST_STRING {
		insertar_en_polaca(&listaPolaca,$1,cont++);
		insertar_string(&tablaSimbolos,$1);
	};

NUMERO: CONST_INT {
			insertar_en_polaca(&listaPolaca,$1,cont++);
			insertar_numero(&tablaSimbolos,$1);
		}
	  | CONST_FLOAT {
	  		insertar_en_polaca(&listaPolaca,$1,cont++);
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
	crear_lista(&listaPolaca);


	yyparse();

	vaciar_Tabla(&tablaSimbolos);
	vaciar_polaca(&listaPolaca);
	printf("No hubo errores!\n");
	fclose(yyin);
	exit(1);

}