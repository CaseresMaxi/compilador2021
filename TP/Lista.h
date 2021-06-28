#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_DESAPILAR "VACIO"


typedef struct l_nodo
{
    struct l_nodo* sig;
    int nroPolaca;
    char elemento[200];

}l_nodo;
typedef l_nodo* t_lista;

typedef struct s_nodo
{
    struct  s_nodo *sig;
    int info;
}t_nodo;
typedef t_nodo* t_pila;

typedef struct s_nodo_decvar
{
    struct  s_nodo_decvar *sig;
    char info[200];
}t_nodo_decvar;
typedef t_nodo_decvar* t_pila_decvar;

typedef struct s_nodo_asm
{
    struct  s_nodo_asm *sig;
    char info[100];
}t_nodo_asm;
typedef t_nodo_asm* t_pila_asm;


//PILA
void crear_Pila(t_pila *);
int apilar(t_pila*,int);
int desapilar(t_pila*);

void crear_Pila_decvar(t_pila_decvar *);
int apilar_decvar(t_pila_decvar*,char*);
char* desapilar_decvar(t_pila_decvar*);

//LISTA
void crear_lista(t_lista*);
int lista_vacia(t_lista*);
int desenlistar(t_lista *,char *);
int lista_llena(t_lista* );

//POLACA
int insertar_en_polaca(t_lista* ,char*, int );
int apilar_en_polaca(t_lista* ,char*, int , t_pila*);
int desapilar_polaca(t_lista* , t_pila*, int);
int desapilar_polaca_sig(t_lista*, t_pila*);
int vaciar_polaca(t_lista* );
void rellenarPolaca(t_lista*, int , int ); //Completar la posicion apilada

//ASSEMBLER
int generarAssembler(t_lista* , tabla* );
void crear_Pila_asm(t_pila_asm *p);
int apilar_asm(t_pila_asm *p,char * elemento);
int desapilar_asm(t_pila_asm* p,char* d);
void reemplazarEnPolaca(t_lista* listaPolaca,char* id_viejo,char* nuevo_id);
int esOperadorBinario(char *d);
int esOperadorUnario(char *d);


void crear_lista(t_lista* l)
{
    *l=NULL;
}

int lista_vacia(t_lista* l)
{
    return !*l;
}

int insertar_en_polaca(t_lista* l,char* d, int posicion)
{
    t_lista* nodoaux = l;
    l_nodo* nuevo = (l_nodo*)malloc(sizeof(l_nodo));
    if(!nuevo){
        printf("NO RESERVO MEMORIA\n");
        return 0;
    }

    nuevo->sig=NULL;
    strcpy(nuevo->elemento,d);
    nuevo->nroPolaca = posicion;
    if(!*l){
        *l = nuevo;
    }else{
        while((*nodoaux)->sig != NULL){
            nodoaux = &(*nodoaux)->sig;
        }
        (*nodoaux)->sig = nuevo;
    }
    return 1;
}

int apilar_en_polaca(t_lista* l,char* d, int posicion, t_pila *p)
{
    int ret = insertar_en_polaca(l,d, posicion);

    if (ret == 1) {
        return apilar(p, posicion);
    } else {
        return 0;
    }
}

int desapilar_polaca(t_lista* l, t_pila* p, int posicion)
{
    int posLista = desapilar(p);

    if (posLista == 0) {
        printf("ERROR: PILA VACIA");
        return 0;
    }

    rellenarPolaca(l,posLista,posicion);

    return 1;
}

int desapilar_polaca_sig(t_lista* l, t_pila* p)
{
    int posLista = desapilar(p);

    if (posLista == 0) {
        printf("ERROR: PILA VACIA");
        return 0;
    }

    rellenarPolaca(l,posLista,posLista+1);

    return 1;
}



int desenlistar(t_lista *l,char *d)
{
    if(!*l)
        return 0;
    l_nodo* viejo;
    viejo=*l;
    strcpy(d,viejo->elemento);
    *l=viejo->sig;
    free(viejo);
    return 1;
}

int lista_llena(t_lista* l)
{
    l_nodo* aux=(l_nodo*)malloc(sizeof(l_nodo));
    return !aux;
}

int vaciar_polaca(t_lista* l)
{
    FILE* pf = fopen("intermedia.txt","w+");
    if(!pf){
        printf("No se pudo abrir el archivo;\n");
        return 0;
    }

    while(*l)
    {
        fprintf(pf,"%d\t%s\n",(*l)->nroPolaca, (*l)->elemento);
        l=&(*l)->sig;
        //free(aux);
    }
    fclose(pf);
    return 1;
}


void rellenarPolaca(t_lista *l, int posicion, int valor){

    t_lista* aux = l;
    char cadena[5];
    while(*aux && (((*aux)->nroPolaca-posicion) != 0)  ){
        aux = &(*aux)->sig;
    }
    if(!*aux){
        printf("LISTA VACIA!\n");
    }
    if(((*aux)->nroPolaca-posicion) == 0){
        itoa(valor, cadena, 10);
        strcpy((*aux)->elemento, cadena );
    }
}


void rellenarPolacaChar(t_lista *l, int posicion, char* valor){

    t_lista* aux = l;
    while(*aux && (((*aux)->nroPolaca-posicion) != 0)  ){
        aux = &(*aux)->sig;
    }
    if(!*aux){
        printf("LISTA VACIA!\n");
    }
    if(((*aux)->nroPolaca-posicion) == 0){
        strcpy((*aux)->elemento, valor );
    }
}

void crear_Pila(t_pila *p)
{
    *p=NULL;
}

int apilar(t_pila *p,int posicion)
{
    t_nodo *nuevo=(t_nodo *)malloc(sizeof(t_nodo));
    if(nuevo==NULL)
        return 0;
    nuevo->sig=*p;
    nuevo->info=posicion;
    *p=nuevo;
    return 1;
}

int desapilar(t_pila *p)
{

    int valor_actual;
    t_nodo *viejo=*p;
    if(viejo==NULL)
        return 0;
    *p=viejo->sig;
    valor_actual = viejo->info;
    free(viejo);

    return valor_actual;
}

//////////////////////////////////

void crear_Pila_decvar(t_pila_decvar *p)
{
    *p=NULL;
}

int apilar_decvar(t_pila_decvar *p,char* dato)
{
    t_nodo_decvar *nuevo=(t_nodo_decvar *)malloc(sizeof(t_nodo_decvar));
    if(nuevo==NULL){
        printf("\nSin memoria");
        return 0;
    }
    nuevo->sig=*p;
    strcpy(nuevo->info,dato);
    *p=nuevo;
    return 1;
}

char* desapilar_decvar(t_pila_decvar *p)
{

    char* valor_actual;
    t_nodo_decvar *viejo=*p;
    if(viejo==NULL) {
        return NO_DESAPILAR;
    }
    *p=viejo->sig;
    strcpy(valor_actual,viejo->info);
    free(viejo);

    return valor_actual;
}

///////////////////////////////////
void crear_Pila_asm(t_pila_asm *p)
{
    *p=NULL;
}

int apilar_asm(t_pila_asm *p,char * elemento)
{
    t_nodo_asm *nuevo=(t_nodo_asm *)malloc(sizeof(t_nodo_asm));
    if(nuevo==NULL)
        return 0;
    nuevo->sig=*p;
    strcpy(nuevo->info,elemento);
    *p=nuevo;
    return 1;
}

int desapilar_asm(t_pila_asm* p,char* d)
{
    t_nodo_asm* viejo;
    if(!*p)
        return 0;
    viejo=(t_nodo_asm*)malloc(sizeof(t_nodo_asm));
    viejo=*p;
    strcpy(d,viejo->info);
    *p=viejo->sig;
    free(viejo);
    return 1;
}

///////////////////////////////////

int generarAssembler(t_lista* listaPolaca, tabla* listaSimbolos) 
{
    tabla* auxSimbolos = listaSimbolos;
    tuplaTabla* auxTuplaSimbolos;

    //Pila Assembler
    t_pila_asm pila;

    char operando1[100];
    char operando2[100];

    char varAuxResultado[100];

    strcpy(varAuxResultado,"_@varAuxResultado");

    crear_Pila_asm(&pila);

    FILE *finalf = fopen("Final.asm","w+");
    if(!finalf){
        printf("No se pudo abrir el archivo Final.asm\n");
        return 0;
    }

    fprintf(finalf,"include macros2.asm\n");
    fprintf(finalf,"include number.asm\n");
    fprintf(finalf,".MODEL LARGE\n.386\n.STACK 200h\n\n");

    fprintf(finalf,".DATA\n;variables de la tabla de simbolos\n\n");
    
    while(*auxSimbolos)
    {
        char aux_tipo1[10];
        char aux_tipo2[25];
        char aux_tipo3[25];
        char aux_valor_float[50];
        char aux_lexema[200];

        char aux_char[50];

        if(strcmp((*auxSimbolos)->tipo,TIPO_STRING) == 0) {
            strcpy(aux_tipo1,"db");

            strcpy(aux_char,"db");
            sprintf(aux_tipo2,", '$' , %d dup\t(?)",(*auxSimbolos)->longitud);
            strcpy(aux_tipo3,"");
            
        } else {
            strcpy(aux_tipo1,"dd");
            strcpy(aux_tipo2,";esddfloat");
            strcpy(aux_tipo3,"_esddfloat");
        }

        if(strcmp((*auxSimbolos)->valor,"-") == 0) {
            sprintf(aux_lexema,"_%s%s",(*auxSimbolos)->lexema,aux_tipo3);
            reemplazarEnPolaca(listaPolaca,(*auxSimbolos)->lexema,aux_lexema);
            fprintf(finalf,"_%s%s\t%s\t?\t%s",(*auxSimbolos)->lexema,aux_tipo3,aux_tipo1,aux_tipo2);
        } else {
            if(strcmp((*auxSimbolos)->tipo,TIPO_STRING) == 0) {
                strcpy(aux_valor_float,"\"");
                strcat(aux_valor_float,(*auxSimbolos)->valor);
                strcat(aux_valor_float,"\"");

                sprintf(aux_lexema,"%s%s",(*auxSimbolos)->lexema,aux_tipo3);
                reemplazarEnPolaca(listaPolaca,aux_valor_float,aux_lexema);
            } else {
                strcpy(aux_valor_float,(*auxSimbolos)->valor);

                sprintf(aux_lexema,"%s%s",(*auxSimbolos)->lexema,aux_tipo3);
                reemplazarEnPolaca(listaPolaca,aux_valor_float,aux_lexema);

                if(strcmp((*auxSimbolos)->tipo,TIPO_INTEGER) == 0) {
                    strcat(aux_valor_float,".0");
                }
            }

            fprintf(finalf,"%s%s\t%s\t%s\t%s",(*auxSimbolos)->lexema,aux_tipo3,aux_tipo1,aux_valor_float,aux_tipo2);
        }

        fprintf(finalf,"\n");

        auxSimbolos=&(*auxSimbolos)->siguiente;

    }
/*
    fprintf(finalf,"_@max1\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max2\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max3\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max4\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max5\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max6\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max7\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max8\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max9\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@max10\tdd\t?\t;esddfloat\n");
    fprintf(finalf,"_@aux\tdd\t?\t;esddfloat\n");
*/
    fprintf(finalf,"\n\n\n\n");  // agrego saltos de linea al archivo assembler
    fprintf(finalf,".CODE\n;comienzo de la zona de codigo\n\n\nstart:\n");
    fprintf(finalf,"MOV EAX,@DATA\n");
    fprintf(finalf,"MOV DS,EAX\n");
    fprintf(finalf,"MOV ES,EAX\n\n\n");

    while(*listaPolaca){
      //printf("%s\n",(*listaPolaca)->elemento);
      if(esOperadorBinario((*listaPolaca)->elemento)){
        if(strcmp((*listaPolaca)->elemento,"+")==0){
            desapilar_asm(&pila,operando1);
            fprintf(finalf,"FLD %s\n",operando1);
            desapilar_asm(&pila,operando2);
            
            if((strcmp(varAuxResultado,operando2)==0) && (strcmp(operando2,operando1)==0)){

            }
            fprintf(finalf,"FLD %s\n",operando2);
            fprintf(finalf,"FADD\n");
            fprintf(finalf, "FSTP %s\n",varAuxResultado);
            apilar_asm(&pila,varAuxResultado);
        }else if(strcmp((*listaPolaca)->elemento,"-")==0){
            desapilar_asm(&pila,operando1);
            fprintf(finalf,"FLD %s\n",operando1);
            desapilar_asm(&pila,operando2);
            fprintf(finalf,"FLD %s\n",operando2);
            fprintf(finalf,"FSUB\n");
            fprintf(finalf, "FSTP %s\n",varAuxResultado);
            apilar_asm(&pila,varAuxResultado);
        }else if(strcmp((*listaPolaca)->elemento,"*")==0){
            desapilar_asm(&pila,operando1);
            fprintf(finalf,"FLD %s\n",operando1);
            desapilar_asm(&pila,operando2);
            fprintf(finalf,"FLD %s\n",operando2);
            fprintf(finalf,"FMUL\n");
            fprintf(finalf, "FSTP %s\n",varAuxResultado);
            apilar_asm(&pila,varAuxResultado);
        }else if(strcmp((*listaPolaca)->elemento,"/")==0){
            desapilar_asm(&pila,operando1);
            fprintf(finalf,"FLD %s\n",operando1);
            desapilar_asm(&pila,operando2);
            fprintf(finalf,"FLD %s\n",operando2);
            fprintf(finalf,"FDIV\n");
            fprintf(finalf, "FSTP %s\n",varAuxResultado);
            apilar_asm(&pila,varAuxResultado);
        }else if(strcmp((*listaPolaca)->elemento,":=")==0){
            desapilar_asm(&pila, operando1);
            fprintf(finalf,"FLD %s\n",operando1);
            desapilar_asm(&pila,operando2);
            fprintf(finalf,"FSTP %s\n",operando2);
        }
      }else if(esOperadorUnario((*listaPolaca)->elemento)){
            if(strcmp((*listaPolaca)->elemento,"WRITE")==0){
                desapilar_asm(&pila,operando1);
                if(strstr(operando1,"_esddfloat") != NULL && strstr(operando1,"_esddstring") == NULL){
                    fprintf(finalf,"DisplayFloat %s , 2\n",operando1);
                    fprintf(finalf,"newline 1\n");
                }else{
                    fprintf(finalf,"displayString %s \n",operando1);
                    fprintf(finalf,"newline 1\n");
                }
                
                
            }else if(strcmp((*listaPolaca)->elemento,"READ")==0){
                desapilar_asm(&pila,operando1);
                fprintf(finalf,"getFloat %s",operando1); 
            }
      }else{
        apilar_asm(&pila,(*listaPolaca)->elemento);
      }
      

      listaPolaca=&(*listaPolaca)->sig;
    }

    fprintf(finalf,"\nMOV EAX, 4c00h  ; termina la ejecucion\n");
    fprintf(finalf,"INT 21h\n");
    fprintf(finalf,"END start;\n;\n");

    fclose(finalf);

    return 1;

}

void reemplazarEnPolaca(t_lista* listaPolaca,char* id_viejo,char* nuevo_id) {
    while(*listaPolaca) {
        if(strcmp((*listaPolaca)->elemento,id_viejo) == 0) {
            strcpy((*listaPolaca)->elemento,nuevo_id);
        }

        listaPolaca=&(*listaPolaca)->sig;
    }
}

int esOperadorBinario(char *d){
    if(strcmp(d,"+") == 0 || strcmp(d,"-") == 0 || strcmp(d,"/") == 0 || strcmp(d,"*") == 0 || strcmp(d,"BGE") == 0 || strcmp(d,"BGT") == 0 
            || strcmp(d,"BLE") == 0 || strcmp(d,"BLT") == 0 || strcmp(d,"BNE") == 0 || strcmp(d,"BEQ") == 0 || strcmp(d,":=") == 0 || strcmp(d,"CMP") == 0
            || strcmp(d,"MOD") == 0 || strcmp(d,"DIV") == 0){

        return 1;
    }

    return 0;
}


int esOperadorUnario(char *d){
    if(strcmp(d, "WRITE") == 0 || strcmp(d, "READ") == 0){
        return 1;
    }

    return 0;
}