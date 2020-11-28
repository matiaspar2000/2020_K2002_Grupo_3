#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct variable{
    char tipoDeDato[20];
    char nombreV[20];
}variable;
typedef struct listaDeVariables {
    struct variable contenido;
    struct listaDeVariables *siguiente;
}listaDeVariables;

typedef struct funcion{
    char tipoDeDatoSalida[20];
    char nombreF[20];
    char parametros[50];
    int cantidadParametros;
}funcion;

typedef struct listaDeFunciones{
    struct funcion contenido;
    struct listaDeFunciones *siguiente;
}listaDeFunciones;

struct listaDeVariables *TSVar = NULL;
struct listaDeFunciones *TSFunc = NULL;

void reportarVariablesDeclaradas(){
    printf("VARIABLES DECLARADAS: \n");
   struct listaDeVariables *ptr = TSVar;
   while(ptr != NULL) {
        printf("Variable: %s - ", ptr->contenido.nombreV);
        printf("Tipo: %s \n", ptr->contenido.tipoDeDato);
      ptr = ptr->siguiente;
   }
    printf("-------------------------------------------------------------\n"); 
}

void reportarFuncionesDeclaradas(){
    printf("FUNCIONES DECLARADAS: \n");
    struct listaDeFunciones *ptr = TSFunc;
    while(ptr != NULL){
        printf("Funcion: %s - ", ptr->contenido.nombreF);
        printf("Tipo que devuelve: %s - ", ptr->contenido.tipoDeDatoSalida);
        printf("Cantidad de parametros: %d - \n",ptr->contenido.cantidadParametros);
        printf("Tipo de dato de los parametros: %s \n", ptr->contenido.parametros);
        ptr = ptr->siguiente;
    }       
    printf("-------------------------------------------------------------\n"); 
}

void insertarVariableUnica(variable valor) {
    struct listaDeVariables *temp,*ptr;
    temp=(struct listaDeVariables *)malloc(sizeof(struct listaDeVariables));
    temp->contenido=valor;
    temp->siguiente=NULL;
    if(TSVar==NULL){
            TSVar=temp;
            return;
    }else{
        ptr=TSVar;
        while(ptr->siguiente !=NULL){
            if(strcmp(ptr->contenido.nombreV,valor.nombreV) == 0){
                printf("ERROR SEMANTICO: Ya existe una variable declarada con este nombre \n");
                return;
            }
        ptr=ptr->siguiente ;
        }
        ptr->siguiente=temp;
    }
} 

void insertarFuncionUnica(funcion valor) {
    struct listaDeFunciones *temp,*ptr;
    temp=(struct listaDeFunciones *)malloc(sizeof(struct listaDeFunciones));
    temp->contenido=valor;
    temp->siguiente=NULL;
    if(TSFunc==NULL){
        TSFunc=temp;
        return;
    }else{
        ptr=TSFunc;
        while(ptr->siguiente != NULL){
            if(strcmp(ptr->contenido.nombreF,valor.nombreF) == 0){
                printf("ERROR SEMANTICO: Ya existe una variable declarada con este nombre \n");
                return;
            }
        ptr=ptr->siguiente;
        }
        ptr->siguiente=temp;
    }
} 

funcion buscarFuncion(char* buscada){
    struct listaDeFunciones *temp;
    temp=TSFunc;
    while(temp != NULL){
        if(strcmp(temp->contenido.nombreF,buscada) == 0){
            return temp->contenido;
        }
        temp = temp->siguiente;
    }    
    printf("ERROR SEMANTICO: funcion no declarada \n");
    return temp->contenido;
}

int controlDeParametrosDeInvocacion(funcion invocada, funcion declaradaEnTS){
    printf(" --- Encontrada una invocacion de funcion \n");
    printf(" --- Controlando cantidad de parametros \n");
    if(invocada.cantidadParametros < declaradaEnTS.cantidadParametros){
        printf("ERROR SEMANTICO: faltan parametros al invocar la funcion \n");
        return 0;
    }else if(invocada.cantidadParametros > declaradaEnTS.cantidadParametros){
        printf("ERROR SEMANTICO: sobran parametros al invocar la funcion \n");
        return 0;
    }else{
        printf("Cantidad de parametros correcta, controlando tipo de parametros \n");
        if(strcmp(invocada.parametros,declaradaEnTS.parametros) == 0){
            printf("Funcion invocada correctamente \n");
            return 1;
        }else{
            printf("ERROR SEMANTICO: error en los tipos de parametros al invocar la funcion \n");
            return 0;
        }
    }
}

