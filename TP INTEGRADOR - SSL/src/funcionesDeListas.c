#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaDeVariables {
    char tipoDeDato[20];
    char nombreV[20];
    char valor[20];
    struct listaDeVariables *siguiente;
}listaDeVariables;

typedef struct listaDeFunciones{
    char tipoDeDatoSalida[20];
    char nombreF[20];
    struct listaDeVariables *parametros;
    struct listaDeFunciones *siguiente;
}listaDeFunciones;


int contarParametros(listaDeVariables *parametros){//cantidad de parametros de la lista de variables 
    int contador = 0;
    while (parametros->siguiente != NULL){
        contador = contador + 1;
        parametros = parametros->siguiente;
    }  
    return contador;
}

void reportarVariablesDeclaradas(listaDeVariables *TSVar){ //me dice el nombre y tipo de cada variable 
    printf("VARIABLES DECLARADAS: ");
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

int insertarVariableUnica(listaDeVariables *nueva, listaDeVariables *TS){
   printf("INSERTANDO VARIABLE...\n");
   while (TS->siguiente != NULL){
        if(TS->nombreV == nueva->nombreV){
            printf("ERROR SEMANTICO: Ya existe una variable declarada con este nombre \n");
            return -1;
        }
        TS = TS->siguiente;
   }
    printf("Variable insertada correctamente en tabla de simbolos \n");
    TS->siguiente = nueva;
   return 0;
}  

int insertarFuncionUnica(listaDeFunciones *nueva, listaDeFunciones *TS){
  while (TS->siguiente != NULL){
        if(TS->nombreF == nueva->nombreF){
            printf("ERROR SEMANTICO: Ya existe una funcion declarada con este nombre \n");
            return -1;
        }
        TS = TS->siguiente;
   }
   TS->siguiente = nueva;
   printf("Funcion insertada correctamente en tabla de simbolos \n");
   return 0;
}  
typedef struct parametrosAlInvocar{
    int tipo;
    struct parametrosAlInvocar *siguiente;
}parametrosAlInvocar;

int contarParametrosInvocacion(parametrosAlInvocar *parametros){
    int contador = 0;
    while (parametros->siguiente != NULL){
        contador = contador + 1;
        parametros = parametros->siguiente;
    }  
    return contador;
}

void insertarTipoParametro(parametrosAlInvocar *lista, int nuevo){
    while (lista->siguiente != NULL){
        lista = lista->siguiente;
   }
   lista->siguiente->tipo = nuevo;
   lista->siguiente->siguiente = NULL;
}

listaDeFunciones buscarFuncion(listaDeFunciones *TSFunc, char* buscada){
    while(TSFunc->siguiente->nombreF != buscada){
        TSFunc = TSFunc->siguiente;
    }    
    if(TSFunc->siguiente->nombreF == buscada){
        return *TSFunc;
    /*}else{
        printf("ERROR SEMANTICO: funcion no declarada");
    }*/
    }
}

int tipoDeParametro(char* parametros){
    if(parametros == "int"){
            return 1;
    }else if(parametros == "char"){
            return 2;           
    }else if(parametros == "float"){
            return 3;            
    }else if(parametros == "char*"){
            return 4;
    }
}

int controlDeParametrosDeInvocacion(parametrosAlInvocar *misParametros, listaDeFunciones funcionInvocada){
    struct listaDeVariables *parametros = funcionInvocada.parametros;
    if(contarParametrosInvocacion(misParametros) <= contarParametros(parametros)){
        printf("ERROR SEMANTICO: faltan parametros al invocar la funcion \n");
        return 0;
    }else if(contarParametrosInvocacion(misParametros) >= contarParametros(parametros)){
        printf("ERROR SEMANTICO: sobran parametros al invocar la funcion \n");
        return 0;
    }else{
        printf("Funcion invocada correctamente \n");
        return 0;
    }

    while(parametros->siguiente != NULL && misParametros->siguiente != NULL){
        if(misParametros->tipo != tipoDeParametro(parametros->tipoDeDato)){
            printf("ERROR SEMANTICO: no coincide el tipo de dato pasado con el requerido por la funcion \n");
            return 0;
        }else{
            parametros = parametros->siguiente;
            misParametros = misParametros->siguiente;
        }
    }
    if(parametros->siguiente == NULL && misParametros->siguiente == NULL){
        return 1;
    }
}

