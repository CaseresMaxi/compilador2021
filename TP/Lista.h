#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


//PILA
void crear_Pila(t_pila *);
int apilar(t_pila*,int);
int desapilar(t_pila*);

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
    l_nodo* aux;
    FILE* pf = fopen("intermedia.txt","w+");
    FILE* auxpf = fopen("auxiliar.txt","w+");
    if(!pf){
        printf("No se pudo abrir el archivo;\n");
        return 0;
    }
    if(!auxpf){
        printf("No se pudo abrir el archivo;\n");
        return 0;
    }

    while(*l)
    {
        aux=*l;
        *l=aux->sig;
        fprintf(pf,"%d\t%s\n",aux->nroPolaca, aux->elemento);
        fprintf(auxpf,"%s\n", aux->elemento);
        free(aux);
    }
    fclose(pf);
    fclose(auxpf);
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
    printf("\nApilo posicion: %d", posicion);
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

    printf("\nDesapilo posicion: %d", valor_actual);
    return valor_actual;
}