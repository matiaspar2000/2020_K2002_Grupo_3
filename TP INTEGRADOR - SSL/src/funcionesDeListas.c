#include <stdio.h>

typedef struct listaDeVariables {
    char tipoDeDato[10];
    char nombreV[10];
    char valor[10];
    struct listaDeVariables *siguiente;
}listaDeVariables;

typedef struct listaDeFunciones{
    char tipoDeDatoSalida[10];
    char nombreF[10];
    struct listaDeVariables *parametros[10];
    struct listaDeFunciones *siguiente;
}listaDeFunciones;


void reportarVariablesDeclaradas(listaDeVariables *TSVar){
    while(TSVar->siguiente != NULL){
        printf("Variable declarada: %s - ", TSVar->nombreV);
        printf("Tipo: %s \n", TSVar->tipoDeDato);
        TSVar = TSVar->siguiente;
    }  
}

void reportarFuncionesDeclaradas(listaDeFunciones *TSFunc){
    while(TSFunc->siguiente != NULL){
        printf("Funcion declarada: %s - ", TSFunc->nombreF);
        printf("Tipo que devuelve: %s - ", TSFunc->tipoDeDatoSalida);
        printf("Cantidad de parametros: %s \n", contarParametros(TSFunc->parametros));
        printf("Parametros: %s \n");
        reportarVariablesDeclaradas(TSFunc->parametros);
        TSFunc = TSFunc->siguiente;
    }       
}

int contarParametros(listaDeVariables *parametros){
    int contador = 0;
    while (parametros->siguiente != NULL){
        contador = contador + 1;
        parametros = parametros->siguiente;
    }  
    return contador;
}
/*
void insertarVariableUnica(variable nueva, listaDeVariables *TS){

}

void insertarFuncionUnica(funcion nueva, listaDeFunciones *TS){

}*/