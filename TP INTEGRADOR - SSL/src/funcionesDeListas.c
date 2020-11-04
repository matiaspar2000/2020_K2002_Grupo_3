#include <stdio.h>

typedef struct listaDeVariables {
    char tipoDeDato[20];
    char nombreV[20];
    char valor[20];
    struct listaDeVariables *siguiente;
}listaDeVariables;

typedef struct listaDeFunciones{
    char tipoDeDatoSalida[20];
    char nombreF[20];
    struct listaDeVariables *parametros[10];
    struct listaDeFunciones *siguiente;
}listaDeFunciones;

int contarParametros(listaDeVariables *parametros){
    int contador = 0;
    while (parametros->siguiente != NULL){
        contador = contador + 1;
        parametros = parametros->siguiente;
    }  
    return contador;
}

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
        printf("Cantidad de parametros: %s \n", contarParametros(*TSFunc->parametros));
        printf("Parametros: %s \n");
        reportarVariablesDeclaradas(*TSFunc->parametros);
        TSFunc = TSFunc->siguiente;
    }       
}

int insertarVariableUnica(listaDeVariables *nueva, listaDeVariables *TS){
  while (TS->siguiente != NULL){
        if(TS->nombreV == nueva->nombreV){
            printf("ERROR SEMANTICO: Ya existe una variable con este nombre \n");
            return -1;
        }
        TS = TS->siguiente;
   }
   TS->siguiente = nueva;
   return 0;
}  

int insertarFuncionUnica(listaDeFunciones *nueva, listaDeFunciones *TS){
  while (TS->siguiente != NULL){
        if(TS->nombreF == nueva->nombreF){
            printf("ERROR SEMANTICO: Ya existe una funcion con este nombre \n");
            return -1;
        }
        TS = TS->siguiente;
   }
   TS->siguiente = nueva;
   return 0;
}  