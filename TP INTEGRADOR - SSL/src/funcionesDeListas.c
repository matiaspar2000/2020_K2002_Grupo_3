#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct variable{
    char tipoDeDato[20];
    char nombreV[20];
    char valor[20];
}variable;

typedef struct listaDeVariables {
    struct variable contenido;
    struct listaDeVariables *siguiente;
}listaDeVariables;

typedef struct funcion{
    char tipoDeDatoSalida[20];
    char nombreF[20];
    struct listaDeVariables *parametros;
}funcion;

typedef struct listaDeFunciones{
    struct funcion contenido;
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
    printf("VARIABLES DECLARADAS: \n");
    while(TSVar->siguiente != NULL){
        printf("Variable declarada: %s - ", TSVar->contenido.nombreV);
        printf("Tipo: %s \n", TSVar->contenido.tipoDeDato);
        printf("Valor: %s \n", TSVar->contenido.valor);
        TSVar = TSVar->siguiente;
    }  
}

void reportarFuncionesDeclaradas(listaDeFunciones *TSFunc){
    printf("FUNCIONES DECLARADAS: \n");
    while(TSFunc->siguiente != NULL){
        printf("Funcion declarada: %s - ", TSFunc->contenido.nombreF);
        printf("Tipo que devuelve: %s - ", TSFunc->contenido.tipoDeDatoSalida);
        printf("Cantidad de parametros: %s \n", contarParametros(TSFunc->contenido.parametros));
        printf("Parametros: %s \n");
        reportarVariablesDeclaradas(TSFunc->contenido.parametros);
        TSFunc = TSFunc->siguiente;
    }       
}

int insertarVariableUnica(variable valor){
   struct listaDeVariables *temp, *aux;
   printf("INSERTANDO VARIABLE EN LA TS: \n");
   temp= (struct node *)malloc(sizeof(struct listaDeVariables));
   temp->contenido = valor;
   temp->siguiente = NULL;
   aux = TSVar;                                                 // DECLARAR TSVar en el .y
   while(aux->siguiente != NULL){
        if(aux->contenido.nombreV == valor.nombreV){
            printf("ERROR SEMANTICO: Ya existe una variable declarada con este nombre \n");
            return -1;
        }
        aux = aux->siguiente;
   }
   aux->siguiente = temp;
   printf("Variable insertada correctamente en tabla de simbolos \n");
   return 0;
}  

int insertarFuncionUnica(funcion valor){
   struct listaDeFunciones *temp, *aux;
   printf("INSERTANDO FUNCION EN LA TS: \n");
   temp= (struct node *)malloc(sizeof(struct listaDeFunciones));
   temp->contenido = valor;
   temp->siguiente = NULL;
   aux = TSFunc;                            //DECLARAR TSFunc en el .y
   while (aux->siguiente != NULL){
        if(aux->contenido.nombreF == valor.nombreF){
            printf("ERROR SEMANTICO: Ya existe una funcion declarada con este nombre \n");
            return -1;
        }
        aux = aux->siguiente;
   }
   aux->siguiente = temp;
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

//FALTA ARREGLAR
void insertarTipoParametro(parametrosAlInvocar *lista, int nuevo){
    while (lista->siguiente != NULL){
        lista = lista->siguiente;
   }
   lista->siguiente->tipo = nuevo;
   lista->siguiente->siguiente = NULL;
}

listaDeFunciones* buscarFuncion(char* buscada){
    struct listaDeFunciones *temp;
    temp=TSFunc;
    while(temp != NULL){
        if(temp->contenido.nombreF == buscada){
            return temp;
        }
        temp = TSFunc->siguiente;
    }    
    printf("ERROR SEMANTICO: funcion no declarada");
    return 0;
}
//FALTA ARREGLAR
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

//FALTA ARREGLAR
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

