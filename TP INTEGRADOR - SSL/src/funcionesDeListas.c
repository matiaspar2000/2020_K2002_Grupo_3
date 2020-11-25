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
    char parametros[50];
    int  cantidadParametros;
}funcion;

typedef struct listaDeFunciones{
    struct funcion contenido;
    struct listaDeFunciones *siguiente;
}listaDeFunciones;

typedef struct parametrosAlInvocar{
    int tipo;
    struct parametrosAlInvocar *siguiente;
}parametrosAlInvocar;

struct listaDeVariables *TSVar = NULL;
struct listaDeFunciones *TSFunc = NULL;

void reportarVariablesDeclaradas(){
    printf("VARIABLES DECLARADAS: \n");
   struct listaDeVariables *ptr = TSVar;
   while(ptr != NULL) {
        printf("Variable: %s - ", ptr->contenido.nombreV);
        printf("Tipo: %s - ", ptr->contenido.tipoDeDato);
        printf("Valor: %s \n", ptr->contenido.valor);
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
            if(ptr->contenido.nombreV == valor.nombreV){
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
            if(ptr->contenido.nombreF == valor.nombreF){
                printf("ERROR SEMANTICO: Ya existe una variable declarada con este nombre \n");
                return;
            }
        ptr=ptr->siguiente;
        }
        ptr->siguiente=temp;
    }
} 

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
        temp = temp->siguiente;
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
int controlDeParametrosDeInvocacion(parametrosAlInvocar *misParametros, listaDeFunciones *funcionInvocada){
    struct listaDeVariables *fparametros = TSVar;
    if(contarParametrosInvocacion(misParametros) <= contarParametros(fparametros)){
        printf("ERROR SEMANTICO: faltan parametros al invocar la funcion \n");
        return 0;
    }else if(contarParametrosInvocacion(misParametros) >= contarParametros(fparametros)){
        printf("ERROR SEMANTICO: sobran parametros al invocar la funcion \n");
        return 0;
    }else{
        printf("Funcion invocada correctamente \n");
        return 0;
    }

    while(fparametros->siguiente != NULL && misParametros->siguiente != NULL){
        if(misParametros->tipo != tipoDeParametro(fparametros->contenido.tipoDeDato)){
            printf("ERROR SEMANTICO: no coincide el tipo de dato pasado con el requerido por la funcion \n");
            return 0;
        }else{
            fparametros = fparametros->siguiente;
            misParametros = misParametros->siguiente;
        }
    }
    if(fparametros->siguiente == NULL && misParametros->siguiente == NULL){
        return 1;
    }
}

