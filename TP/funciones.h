#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tupla{
	char* lexema;
	char* tipo;
	char* valor;
	int   longitud;
	struct tupla* siguiente;

}tuplaTabla;


typedef  tuplaTabla* tabla;


void crear_Tabla(tabla* tabla_p);

void vaciar_Tabla(tabla* tabla_p);

int insertar_id (tabla* tabla_p, char* lexema_p);

int insertar_string (tabla* tabla_p, char* lexema_p);

int insertar_numero (tabla* tabla_p, char* lexema_p);

int enlistar_en_orden(tabla* tabla_p,tuplaTabla* );

void eliminarCaracter(char *str, char garbage);




void crear_Tabla(tabla* tabla_p){
	*tabla_p = NULL;
}



void vaciar_Tabla(tabla* tabla_p)
{
    tuplaTabla* viejo;
    char aux[30];
    int i;
    FILE* pf = fopen("ts.txt","w+");
    if(!pf){
    	printf("No se pudo abrir el archivo;\n");
    	return;
    }

   	printf("\n\nTABLA DE SIMBOLOS:\n\n");
   	fprintf(pf,"\nTABLA DE SIMBOLOS:\n\n");

   	for(i=0;i<85;i++){
   		printf("_");
   		fprintf(pf,"_");
   	}

   	printf("\n");
   	fprintf(pf,"\n");

   	printf("|%-32s|%-8s|%-32s|%-8s|\n", "LEXEMA", "TIPO", "VALOR", "LONGITUD");
   	fprintf(pf,"|%-32s|%-8s|%-32s|%-8s|\n", "LEXEMA", "TIPO", "VALOR", "LONGITUD");

   	for(i=0;i<85;i++){
   		printf("-");
   		fprintf(pf,"-");
   	}
   	printf("\n");
   	fprintf(pf,"\n");

    while(*tabla_p)
    {
        viejo=*tabla_p;
        *tabla_p=viejo->siguiente;
        printf("|%-32s|%-8s|%-32s|%-8s|\n", viejo->lexema, "", !(viejo->valor)?"-":viejo->valor, viejo->longitud == 0?"":itoa(viejo->longitud,aux,10));
        fprintf(pf,"|%-32s|%-8s|%-32s|%-8s|\n", viejo->lexema, "", !(viejo->valor)?"-":viejo->valor, viejo->longitud == 0?"":itoa(viejo->longitud,aux,10));

        free(viejo);
    }

    for(i=0;i<85;i++){
   		printf("-");
   		fprintf(pf,"-");
   	}

   	printf("\n");

    fclose(pf);
}

int insertar_id (tabla* tabla_p, char* lexema_p){
	int resultado = 0;
	tuplaTabla* nuevo = (tuplaTabla*) malloc(sizeof(tuplaTabla));
	if(!nuevo){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	nuevo->lexema = (char*) malloc(sizeof(char) * strlen(lexema_p) + 2);
	if(!(nuevo->lexema)){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	strcpy(nuevo->lexema, lexema_p);

	nuevo->tipo = NULL;
	nuevo->valor = NULL;
	nuevo->longitud = 0;

	resultado = enlistar_en_orden(tabla_p, nuevo);

	if(resultado == 0){
		free(nuevo);
		return 0;
	}

	return 1;
}

int insertar_numero (tabla* tabla_p, char* lexema_p){
	int resultado = 0;
	tuplaTabla* nuevo = (tuplaTabla*) malloc(sizeof(tuplaTabla));
	if(!nuevo){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	nuevo->lexema = (char*) malloc(sizeof(char) * strlen(lexema_p) + 2);
	if(!(nuevo->lexema)){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	strcpy(nuevo->lexema, "_");
	strcat(nuevo->lexema, lexema_p);

	nuevo->tipo = NULL;
	nuevo->valor = NULL;
	nuevo->longitud = 0;

	nuevo->valor = (char*) malloc(sizeof(char) * strlen(lexema_p) + 1);
	if(!(nuevo->valor)){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	strcpy(nuevo->valor, lexema_p);

	resultado = enlistar_en_orden(tabla_p, nuevo);

	if(resultado == 0){
		free(nuevo);
		return 0;
	}

	return 1;
}

int insertar_string (tabla* tabla_p, char* lexema_p) {
	int resultado = 0;
	tuplaTabla* nuevo = (tuplaTabla*) malloc(sizeof(tuplaTabla));
	if(!nuevo){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	nuevo->lexema = (char*) malloc(sizeof(char) * strlen(lexema_p) + 2);
	if(!(nuevo->lexema)){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	eliminarCaracter(lexema_p, '"');
	strcpy(nuevo->lexema, "_");
	strcat(nuevo->lexema, lexema_p);

	nuevo->valor = (char*) malloc(sizeof(char) * strlen(lexema_p) + 1);
	
	if(!(nuevo->valor)){
		printf("Error, no hay memoria\n.");
		return -1;
	}

	nuevo->tipo = NULL;
	strcpy(nuevo->valor, lexema_p);

	nuevo->longitud = strlen(lexema_p);

	resultado = enlistar_en_orden(tabla_p, nuevo);

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
	int resultado = 0;
	while(*l && (resultado=strcmp((*l)->lexema,d->lexema))<=0)
	{
		if(resultado == 0){
			return 0;
		}
	   	l=&(*l)->siguiente;
	}
	d->siguiente=*l;
	*l=d;
	
    return 1;
}