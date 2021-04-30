#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CON_VALOR 1
#define SIN_VALOR 0
#define ES_STRING 2


//{COMILLA_D}.({LETRA}|!|\ |{DIGITO}|>|<)+.{COMILLA_D} Sirve para strings.

typedef struct tupla{
	char* lexema;
	char* valor;
	char* tipo;
	struct tupla* siguiente;

}tuplaTabla;


typedef  tuplaTabla* tabla;





int insertar(char* , int ,tabla*  );

int enlistar_en_orden(tabla* ,tuplaTabla* );

void vaciar_lista(tabla* l);

void crearTabla(tabla* lista);

void eliminarCaracter(char *str, char garbage);

int mi_strlen(char* cadena);



void crearTabla(tabla* lista){
	*lista = NULL;

}



void vaciar_lista(tabla* l)
{
    tuplaTabla* viejo;
   	printf("\n\nLA LISTA CONTIENE:\n\n");

    while(*l)
    {
        viejo=*l;
        *l=viejo->siguiente;
        printf("LEXEMA: %s\tVALOR: %s\n", viejo->lexema, viejo->valor);

        free(viejo);
    }
}


int insertar(char* lexemaE, int valor,tabla*  tablaSimbolos){

	tuplaTabla* nuevo;
	int resultado = 0;
	nuevo = (tuplaTabla*) malloc(sizeof(tuplaTabla));
	if(!nuevo){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	/* SI ES UN STRING, LE SACO LAS COMILLAS, RESERVO LA MEMORIA Y ASIGNO LOS VALORES A LOS CAMPOS DE LA TUPLA*/
	if(valor == ES_STRING){
			nuevo->lexema = (char*) malloc(sizeof(char) * strlen(lexemaE) + 1);
			if(!(nuevo->lexema)){
				printf("Error, no hay memoria\n.");
				return -1;
			}

			eliminarCaracter(lexemaE, '"');
			strcpy(nuevo->lexema, "_");
			strcat(nuevo->lexema, lexemaE);
			nuevo->valor = (char*) malloc(sizeof(char) * strlen(lexemaE) + 1);
			if(!(nuevo->valor)){
				printf("Error, no hay memoria\n.");
				return -1;
			}
			strcpy(nuevo->valor, lexemaE);

	}else{/* SI NO ES UN STRING VERIFICO SI ES CON VALOR O SIN VALOR. PARA AMBOS CASOS ASIGNO EL NOMBRE AL LEXEMA Y RESERVO LA MEMORIA*/

		nuevo->lexema = (char*) malloc(sizeof(char) * strlen(lexemaE) + 2);
		if(!(nuevo->lexema)){
			printf("Error, no hay memoria\n.");
			return -1;
		}

		strcpy(nuevo->lexema, "_");
		strcat(nuevo->lexema, lexemaE);

		nuevo->tipo = NULL;
		nuevo->valor = NULL;

		/*SI ES CON VALOR GUARDO EL VALOR DEL LEXEMA EN LA TUPLA*/
		if(valor == CON_VALOR){
			nuevo->valor = (char*) malloc(sizeof(char) * strlen(lexemaE) + 1);
			if(!(nuevo->valor)){
				printf("Error, no hay memoria\n.");
				return -1;
			}

			strcpy(nuevo->valor, lexemaE);
		}

	}
	/*LO INSERTO EN LA LISTA DE MANERA ORDENADA*/
	resultado = enlistar_en_orden(tablaSimbolos, nuevo);

	if(resultado == 0){
		free(nuevo);
		return 0;
	}

	return 1;


}


void eliminarCaracter(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}


int enlistar_en_orden(tabla* l,tuplaTabla* d)
{
    tabla pm;
    int resultado = 0;
   while(*l && (resultado=strcmp((*l)->lexema,d->lexema))<=0)
   {
   		if(resultado == 0){
   			return 0;
   		}
       	l=&(*l)->siguiente;
   }
   if(!*l)
        {

            d->siguiente=NULL;
            *l=d;
            return 1;
        }
    d->siguiente=*l;
    *l=d;

    return 1;
}

int mi_strlen(char* cadena){

	int i = 0;
	while(*cadena){
		i++;
		cadena++;
	}

	return ( i <= 30 )? 1:0;
}