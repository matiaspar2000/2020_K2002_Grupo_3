#include <stdio.h>

typedef struct variable {
    char tipoDeDato[10];
    char nombreV[10];
    char valor[10];
}variable;

typedef struct funcion{
    char tipoDeDatoSalida[10];
    char nombreF[10];
    struct listaDeVariables *parametros[10];
}funcion;

typedef struct listaDeVariables {
    struct variable var;
    struct listaDeVariables *siguiente;
}listaDeVariables;

typedef struct listaDeFunciones{
    struct funcion func;
    struct listaDeFunciones *siguiente;
}listaDeFunciones;
/*
void insertarVariableUnica(variable nueva, listaDeVariables *TS){

}

void insertarFuncionUnica(funcion nueva, listaDeFunciones *TS){

}

void reportarVariablesDeclaradas(listaDeVariables *TS){

}

void reportarFuncionesDeclaradas(listaDeFunciones *TS){

}*/