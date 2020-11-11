#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/tpINT.y"
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
            printf("ERROR SEMANTICO: Ya existe una variable declarada con este nombre \n");
            return -1;
        }
        TS = TS->siguiente;
   }
   if(nueva->valor != NULL){
        if(nueva->tipoDeDato == detectarTipoDeDatoVariableNoDeclarada(nueva->valor)){ //si tiene un valor asignado controlo el tipo antes de insertar
                TS->siguiente = nueva;
                printf("Variable insertada correctamente en tabla de simbolos \n");
                return 0;
        }else{
                printf("ERROR SEMANTICO: Error al asignar el valor %s a una variable de tipo %s \n", nueva->valor, nueva->tipoDeDato);
                return -1
        }
   }else{ //si no tiene valor asignado la inserto directamente
        printf("Variable insertada correctamente en tabla de simbolos (sin valor asignado) \n");
        TS->siguiente = nueva;
   }
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

char* detectarTipoDeDatoVariableDeclarada(char nombreVariable[20], listaDeVariables *TS){
  while (TS->siguiente != NULL){
        if(TS->nombreV == nombreVariable && TS->nombreV != NULL){
            printf("La variable es de tipo %s \n", TS->tipoDeDato);
            return TS->tipoDeDato;
        }
        TS = TS->siguiente;
   };
   printf("ERROR SEMANTICO: La variable no fue declarada o definida todavia");
   return "noDeclarado";
}

char* detectarTipoDeDatoVariableNoDeclarada(char valor[20]){
    int i=0;
    int longitudValor= strlen(valor);
    while(isdigit(valor[i])!=0){
        i++;
    };
    if (longitudValor==i){
        printf("Se encontro un INT %s \n"); // esto no es para variables, seria por ejemplo si quiero sumar 1 + 2 
        return "int";                       // que controle que ambos sean del mismo tipo de dato
    }else if(valor[i] = "."){
        printf("Se encontro un FLOAT %s \n");
        return "float";
    }else if(longitudValor >= 1 && isdigit(valor[i])==0){
        printf("Se encontro un CHAR %s \n");
        return "char";
    /*}else if(longitudValor > 1 && isdigit(valor[i])==0){
        longitudValor = 1;
        printf("La variable es de tipo STRING %s \n");
        return "string";
    };   esto no va xq no existe el tipo de dato string*/ 
}

char* detectarTipoDeDato(char variableOvalor[20]){
    char tipoDeDato = detectarTipoDeDatoVariableDeclarada(variableOvalor,TS);
    if(tipoDeDato = "noDeclarado"){
        tipoDeDato = detectarTipoDeDatoVariableNoDeclarada(variableOvalor);
        return tipoDeDato;
    }else{
        return tipoDeDato;
    }   
}
