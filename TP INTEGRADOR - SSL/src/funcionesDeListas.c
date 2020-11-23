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
    struct listaDeVariables *parametros[10];
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
   /*if(nueva->valor != NULL){
        if(nueva->tipoDeDato == detectarTipoDeDatoVariableNoDeclarada(nueva->valor)){ //si tiene un valor asignado controlo el tipo antes de insertar
                TS->siguiente = nueva;
                printf("Variable insertada correctamente en tabla de simbolos \n");
                return 0;
        }else{
                printf("ERROR SEMANTICO: Error al asignar el valor %s a una variable de tipo %s \n", nueva->valor, nueva->tipoDeDato);
                return -1
        };
   }else{ //si no tiene valor asignado la inserto directamente*/
        printf("Variable insertada correctamente en tabla de simbolos (sin valor asignado) \n");
        TS->siguiente = nueva;
   //}
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

/*
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
    };   esto no va xq no existe el tipo de dato string 
}

char* detectarTipoDeDato(char variableOvalor[20]){
    char tipoDeDato = detectarTipoDeDatoVariableDeclarada(variableOvalor,TS);
    if(tipoDeDato = "noDeclarado"){
        tipoDeDato = detectarTipoDeDatoVariableNoDeclarada(variableOvalor);
        return tipoDeDato;
    }else{
        return tipoDeDato;
    }   
}*/

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

listaDeFunciones* buscarFuncion(listaDeFunciones *TSFunc, char* buscada){
    while(TSFunc->siguiente != buscada){
        TSFunc = TSFunc->siguiente;
    }    
    if(TSFunc->siguiente == buscada){
        return TSFunc;
    /*}else{
        printf("ERROR SEMANTICO: funcion no declarada");
    }*/
    }
}

int tipoDeParametro(listaDeVariables *parametros){
    if(parametros->tipoDeDato == "int"){
            return 1;
    }else if(parametros->tipoDeDato == "char"){
            return 2;           
    }else if(parametros->tipoDeDato == "float"){
            return 3;            
    }else if(parametros->tipoDeDato == "char*"){
            return 4;
    }
}

//control de cantidad y tipo de dato al invocar funciones
/*

invocada = buscarFuncion(TSFunc, <$1>)
parametros = fInvocada->listaDeParametros
misParametros = lista de ints que saco de hacer $<miestructura>1.tipo de cada uno de los parametros y guardarlos en un struct a definir
*/


int controlDeParametrosDeInvocacion(parametrosAlInvocar *misParametros, listaDeVariables *parametros){
    if(contarParametrosInvocacion(misParametros) <= contarparametros(parametros)){
        printf("ERROR SEMANTICO: faltan parametros al invocar la funcion \n");
        return 0;
    }else if(contarParametrosInvocacion(misParametros) >= contarparametros(parametros)){
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

