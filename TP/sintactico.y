%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include "funciones.h"
#include "Lista.h"

#define COND_AND 2
#define COND_OR 1
#define COND_NORMAL 0

tabla tablaSimbolos;

t_lista listaPolaca;
t_pila 	pilaPolaca;

//CICLO ESPECIAL
t_pila  pilaWhileEspecialIni;
t_pila  pilaWhileEspecialIniSentencia;
t_pila  pilaWhileEspecialFin;
t_pila  pilaWhileEspecialExp;
t_pila  pilaWhileEspecialCantExp;

//AND OR
t_pila  pilaTipoCondicion;

//VARIABLES PARA LA TS
int bandDecvar = 0;
t_pila_decvar pilaDecvar;
int cantApila = 0;

//VARIABLES PARA LA POLACA
int cont = 1; //Inicia en 1 para imprimir correctamente el numero en el código intermedio
char simboloAux[3];
int bandNot = 0;
char idWhileEspecial[50]; //Variable que guarda el id del ciclo especial
int cantExpresiones;
int bandId = 0;

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

while: WHILE_T{
			char cadena[7];
			char num[4];
			itoa(cont, num, 10);
			strcpy(cadena,"ET");
			strcat(cadena,num);
			apilar_en_polaca(&listaPolaca,cadena,cont++,&pilaPolaca);
		}	
		cond_final LLAVE_A sentencia LLAVE_C {
			char cadena[7];
			char num[4];
			int tipoCond = desapilar(&pilaTipoCondicion);


			if (tipoCond == COND_AND) {
				desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
				desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
			} else if (tipoCond == COND_OR) {
				desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
				desapilar_polaca_sig(&listaPolaca,&pilaPolaca);
			} else {
				int ret = desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
	
				if (ret == 0) {
					printf("ERROR FATAL");
				}
			}

			insertar_en_polaca(&listaPolaca,"BI",cont++);

			itoa(desapilar(&pilaPolaca),num,10);
			strcpy(cadena,"ET");
			strcat(cadena,num);
			insertar_en_polaca(&listaPolaca, cadena , cont++);
	 }
	 ;

if: IF_T cond_final LLAVE_A sentencia LLAVE_C {

		int tipoCond = desapilar(&pilaTipoCondicion);

		if (tipoCond == COND_AND) {
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
		} else if (tipoCond == COND_OR) {
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);
			desapilar_polaca_sig(&listaPolaca,&pilaPolaca);
		} else {
			int ret = desapilar_polaca(&listaPolaca,&pilaPolaca,cont+2);

			if (ret == 0) {
				printf("ERROR FATAL");
			}
		}

		insertar_en_polaca(&listaPolaca,"BI",cont++);
		apilar_en_polaca(&listaPolaca, "", cont++, &pilaPolaca);

	}	ELSE_T LLAVE_A sentencia LLAVE_C {
		int ret = desapilar_polaca(&listaPolaca, &pilaPolaca, cont);

		if (ret == 0) {
			printf("ERROR FATAL");
		}
	}
	|
	IF_T cond_final LLAVE_A sentencia LLAVE_C {
		int tipoCond = desapilar(&pilaTipoCondicion);


		if (tipoCond == COND_AND) {
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont);
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont);
		} else if (tipoCond == COND_OR) {
			desapilar_polaca(&listaPolaca,&pilaPolaca,cont);
			desapilar_polaca_sig(&listaPolaca,&pilaPolaca);
		} else {
			int ret = desapilar_polaca(&listaPolaca,&pilaPolaca,cont);

			if (ret == 0) {
				printf("ERROR FATAL");
			}
		}
	}
	;

write : WRITE_T CONST_STRING_R {insertar_en_polaca(&listaPolaca,"WRITE",cont++);}
	  | WRITE_T expr {insertar_en_polaca(&listaPolaca,"WRITE",cont++);}
	  ;

read: READ_T ID_R {insertar_en_polaca(&listaPolaca,"READ",cont++);};


ciclo_especial: WHILE_T {
			bandId = 1;
	} ID_R {
			apilar(&pilaWhileEspecialIni,cont);

			char cadena[7];
			char num[4];
			itoa(cont, num, 10);
			strcpy(cadena,"ET");
			strcat(cadena,num);

			insertar_en_polaca(&listaPolaca,cadena,cont++);
			cantExpresiones = 0;
			bandId = 0;
	} IN_T PARENT_A lista_expresion {
			insertar_en_polaca(&listaPolaca,"BI",cont++);
			apilar_en_polaca(&listaPolaca, "", cont++, &pilaWhileEspecialFin);
			apilar(&pilaWhileEspecialCantExp,cantExpresiones);
			apilar(&pilaWhileEspecialIniSentencia,cont);
	} PARENT_C DO_T sentencia ENDWHILE_T {
			int posIni = desapilar(&pilaWhileEspecialIni);

			char auxPosIni[10];
			char num[4];
			itoa(posIni, num, 10);
			strcpy(auxPosIni,"ET");
			strcat(auxPosIni,num);

			insertar_en_polaca(&listaPolaca,"BI",cont++);
			insertar_en_polaca(&listaPolaca,auxPosIni,cont++);

			int ret = desapilar_polaca(&listaPolaca,&pilaWhileEspecialFin,cont);

			if (ret == 0) {
				printf("ERROR FATAL");
			}

			int cantFinExpresiones = desapilar(&pilaWhileEspecialCantExp);
			int auxIniSentencia = desapilar(&pilaWhileEspecialIniSentencia);

			for(;cantFinExpresiones > 0; cantFinExpresiones --) {
				desapilar_polaca(&listaPolaca,&pilaWhileEspecialExp,auxIniSentencia);
			}
	};

lista_expresion: {
		insertar_en_polaca(&listaPolaca,idWhileEspecial,cont++);
	}	expr {
		insertar_en_polaca(&listaPolaca,"CMP",cont++);
		insertar_en_polaca(&listaPolaca,"BE",cont++);
		apilar_en_polaca(&listaPolaca, "", cont++, &pilaWhileEspecialExp);
		cantExpresiones++;
	}
	| lista_expresion COMA {
		insertar_en_polaca(&listaPolaca,idWhileEspecial,cont++);
	} expr {
		insertar_en_polaca(&listaPolaca,"CMP",cont++);
		insertar_en_polaca(&listaPolaca,"BE",cont++);
		apilar_en_polaca(&listaPolaca, "", cont++, &pilaWhileEspecialExp);
		cantExpresiones++;
	}
			   ;

asig: ID_R OP_ASIG expr{
		
		insertar_en_polaca(&listaPolaca,$2,cont++);
		
	}
	| ID_R OP_ASIG CONST_STRING_R 
	;

cond_final: PARENT_A cond_final AND_T cond_final {

				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_AND);
			
			} PARENT_C
			| PARENT_A cond AND_T cond_final {

				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_AND);
			
			} PARENT_C
			| PARENT_A cond_final AND_T cond {

				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_AND);
			
			} PARENT_C
			| PARENT_A cond_final OR_T cond_final {
				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_OR);
			
			} PARENT_C 
			| PARENT_A cond OR_T cond_final {
				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_OR);
			
			} PARENT_C 
			| PARENT_A cond_final OR_T cond {
				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_OR);
			
			} PARENT_C 
		  | PARENT_A cond AND_T cond {

				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_AND);
			
			} PARENT_C
			| PARENT_A cond OR_T cond {
				int aux = desapilar(&pilaTipoCondicion);
				aux = desapilar(&pilaTipoCondicion);
				apilar(&pilaTipoCondicion,COND_OR);
			
			} PARENT_C 
		  | PARENT_A cond PARENT_C
		  | NOT_T {
		  	bandNot = 1;
		  } cond_final
		  | PARENT_A cond_final PARENT_C
		  ;

cond: expr COMPARADOR termino {
			insertar_en_polaca(&listaPolaca,"CMP",cont++);
			insertar_en_polaca(&listaPolaca,simboloAux,cont++);
			apilar_en_polaca(&listaPolaca,"",cont++,&pilaPolaca);
			apilar(&pilaTipoCondicion,COND_NORMAL);
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
			insertar_en_polaca(&listaPolaca,"MOD",cont++); 
		}
		| termino OP_DIV factor { 
			insertar_en_polaca(&listaPolaca,"DIV",cont++); 
		}
		| factor
		;

factor	: PARENT_A expr PARENT_C
		| NUMERO
		| ID_R
		;

bloque_declaracion: DECVAR_T { bandDecvar = 1; printf("\nInicio decvar"); } declaracion ENDDEC_T { bandDecvar = 0; printf("\nFin decvar");}

declaracion : linea_declaracion
			| declaracion linea_declaracion
			;

linea_declaracion: var_declaracion OP_AS tipo_variable SEP_LINEA

var_declaracion: ID_R 
				| var_declaracion COMA ID_R
				;

tipo_variable: 
				FLOAT_T {
					char* valor_actual;
					while(cantApila > 0) 
					{
						valor_actual = desapilar_decvar(&pilaDecvar);
						insertar_id(&tablaSimbolos,valor_actual,TIPO_FLOAT);
						cantApila--;
					}
				}
			 | INTEGER_T {
			 		char* valor_actual;
					while(cantApila > 0) 
					{
						valor_actual = desapilar_decvar(&pilaDecvar);
						insertar_id(&tablaSimbolos,valor_actual,TIPO_INTEGER);
						cantApila--;
					}
			 } 
			 | STRING_T {
			 		char* valor_actual;
					while(cantApila > 0) 
					{
						valor_actual = desapilar_decvar(&pilaDecvar);
						insertar_id(&tablaSimbolos,valor_actual,TIPO_STRING);
						cantApila--;
					}
			 } 
			 ;

ID_R: ID_T {
		if(bandDecvar == 1) {
			printf("\nApilando.%s",$1);
			cantApila++;
			apilar_decvar(&pilaDecvar,$1);

		} else {
			//Validar si existe

			if(validar_id(&tablaSimbolos,$1) == 1) {
				//Si existe
				if( bandId == 0) {
					insertar_en_polaca(&listaPolaca,$1,cont++);
				} else {
					strcpy(idWhileEspecial,$1);
				}
			} else {
				/*
				printf("\n\nERROR\nLa variable %s no se encuentra declarada",$1);
				exit(1);*/
			}


		}

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

	crear_Pila(&pilaPolaca);
	crear_Pila_decvar(&pilaDecvar);

	//CICLO ESPECIAL
	crear_Pila(&pilaWhileEspecialIni);
	crear_Pila(&pilaWhileEspecialFin);
	crear_Pila(&pilaWhileEspecialExp);
	crear_Pila(&pilaWhileEspecialCantExp);
	crear_Pila(&pilaWhileEspecialIniSentencia);
	
	//AND OR
	crear_Pila(&pilaTipoCondicion);

	yyparse();

	vaciar_Tabla(&tablaSimbolos);
	vaciar_polaca(&listaPolaca);


	//generarAssembler(&listaPolaca,&tablaSimbolos);


	printf("No hubo errores!\n");
	fclose(yyin);
	exit(1);

}