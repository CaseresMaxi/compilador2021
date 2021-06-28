#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIPO_FLOAT "FLOAT"
#define TIPO_STRING "STRING"
#define TIPO_INTEGER "INTEGER"

typedef struct tupla{
	char lexema[200];
	char tipo[10];
	char valor[200];
	int   longitud;
	struct tupla* siguiente;

}tuplaTabla;


typedef  tuplaTabla* tabla;


void crear_Tabla(tabla* tabla_p);

void vaciar_Tabla(tabla* tabla_p);

int insertar_id (tabla* tabla_p, char* lexema_p, char* tipo_dato);

int validar_id (tabla* tabla_p, char* lexema_p);

int insertar_string (tabla* tabla_p, char* lexema_p);

int insertar_numero (tabla* tabla_p, char* lexema_p,char* tipo_dato);

int enlistar_en_orden(tabla* l,char* lexema,char* tipo_dato, char* valor, int longitud);

void eliminarCaracter(char *str, char garbage);

void mostrarLista(tabla*);

void extraerValor (char* cadena,char* valor);

void mostrarLista(tabla *l)
{
    printf("\nContenido de la lista");
    while(*l)
    {
        printf("\n%s",(*l)->lexema);
        l=&(*l)->siguiente;
    }
}




void crear_Tabla(tabla* tabla_p){
	*tabla_p = NULL;
}



void vaciar_Tabla(tabla* tabla_p)
{
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
        printf("|%-32s|%-8s|%-32s|%-8s|\n", (*tabla_p)->lexema, (*tabla_p)->tipo, !((*tabla_p)->valor)?"-":(*tabla_p)->valor, (*tabla_p)->longitud == 0?"":itoa((*tabla_p)->longitud,aux,10));
        fprintf(pf,"|%-32s|%-8s|%-32s|%-8s|\n", (*tabla_p)->lexema, (*tabla_p)->tipo, !((*tabla_p)->valor)?"-":(*tabla_p)->valor, (*tabla_p)->longitud == 0?"":itoa((*tabla_p)->longitud,aux,10));
        tabla_p=&(*tabla_p)->siguiente;


        //free(viejo);
    }

    for(i=0;i<85;i++){
   		printf("-");
   		fprintf(pf,"-");
   	}

   	printf("\n");

    fclose(pf);
}

int insertar_id (tabla* tabla_p, char* lexema_p, char* tipo_dato){
	int resultado = 0;

	resultado = enlistar_en_orden(tabla_p,lexema_p,tipo_dato,"-",0);

	if(resultado == 0){
		printf("\nERROR: variable %s ya se encuentra declarada");
		return 0;
	}

	return 1;
}

int validar_id (tabla* tabla_p, char* lexema_p) {
	while(*tabla_p)
    {
        if(strcmp((*tabla_p)->lexema,lexema_p) == 0) {
        	return 1;
        }
        tabla_p=&(*tabla_p)->siguiente;
    }
        
    return 0;
}

int insertar_numero (tabla* tabla_p, char* lexema_p, char* tipo_dato) {
	int resultado = 0;
	char aux[200];

	strcpy(aux, "_");
	strcat(aux, lexema_p);


	resultado = enlistar_en_orden(tabla_p, aux,tipo_dato,lexema_p,0);

	if(resultado == 0){
		return 0;
	}

	return 1;
}

int insertar_string (tabla* tabla_p, char* lexema_p) {
	int resultado = 0;
	char aux[200];

	eliminarCaracter(lexema_p, '"');
	strcpy(aux, "_");
	strcat(aux, lexema_p);

	//Sacarle a AUX espacios y caracteres especiales

	resultado = enlistar_en_orden(tabla_p, aux,TIPO_STRING,lexema_p,strlen(lexema_p));

	if(resultado == 0){
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


int enlistar_en_orden(tabla* l,char* lexema,char* tipo_dato, char* valor, int longitud)
{
	int resultado = 0;
	if(strstr(lexema,"__")){
		strcpy(lexema, lexema+1);
	}
	while(*l && (resultado=strcmp((*l)->lexema,lexema))<=0)
	{

		if(resultado == 0){
			return 0;
		}
	   	l=&(*l)->siguiente;
	}
	tuplaTabla* nuevo = (tuplaTabla*) malloc(sizeof(tuplaTabla));
	if(!nuevo){
		printf("Error, no hay memoria\n.");
		return -1;
	}
	strcpy(nuevo->lexema, lexema);

	strcpy(nuevo->tipo,tipo_dato);
	char valorAux [100];
	extraerValor(valor,valorAux);
	strcpy(nuevo->valor,valorAux);

	nuevo->longitud = longitud;

	nuevo->siguiente=*l;
	*l=nuevo;
	
    return 1;
}

void extraerValor (char* cadena,char* valor){
	/*char aux [100];
    char * paux = cadena;
    paux++;
    while(isdigit(*paux)) 
    {
    	paux++;
    }
    char * posfinal = paux;
    *posfinal='\0';
    strcpy(, cadena+1);*/
    printf("Entre225\n");
    char *aux = cadena; 
    char *posfinal;
	aux++;
	if(strstr(cadena,"-")){
		strcpy( valor, cadena);
	}else{
		printf("Cadena: %s\n",cadena);
		while(isdigit(*aux)) aux++;
		posfinal = aux;
		char auxiliarFinal = *posfinal;
		*posfinal='\0';
		printf("Cadena+1: %s\n",cadena+1);
		strcpy( valor, cadena+1); //Lo paso y le vuelvo a poner lo que hay en el \0
		*posfinal = auxiliarFinal;
	
	}
	
}