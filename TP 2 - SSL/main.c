#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
   char valor;
   struct Nodo *siguiente;
} pila;

typedef pila *pNodo;
typedef pila *Pila;
Pila expresion = NULL; //Pila principal para las expresiones aritmeticas

enum Alfabeto{
    CERO='0',
    UNO='1',
    DOS='2',
    TRES='3',
    CUATRO='4',
    CINCO='5',
    SEIS='6',
    SIETE='7',
    OCHO='8',
    NUEVE='9',
    APERTURA='(',
    CIERRE=')',
    MULTIPLICACION='*',
    DIVISION='/',
    SUMA='+',
    RESTA='-'
};

void push(Pila *pila, char v) {
   pNodo nuevo;
   nuevo = (pNodo)malloc(sizeof(pila));
   nuevo->valor = v;
   nuevo->siguiente = *pila;
   *pila = nuevo;
}

void pop(Pila *pila) {
   pNodo nodo;
   nodo = *pila;
   *pila = nodo->siguiente;
   free(nodo);
}

int leer(int estado , char caracter)
{
    int estadoFinal;
    if(estado==1)
    {
        switch(caracter)
            {
                case UNO:
                case DOS:
                case TRES:
                case CUATRO:
                case CINCO:
                case SEIS:
                case SIETE:
                case OCHO:
                case NUEVE: return estadoFinal=2; break;
                case APERTURA: push(&expresion,caracter);return estadoFinal=3; break;
                //No pertenecen al estado inicial
                case SUMA:
                case RESTA:
                case MULTIPLICACION:
                case DIVISION:
                case CIERRE:
                case CERO: return estadoFinal=0;
                default :  return estadoFinal=-1;
            }
    }
    if(estado==2)
    {
        switch(caracter)
            {
                case CERO:
                case UNO:
                case DOS:
                case TRES:
                case CUATRO:
                case CINCO:
                case SEIS:
                case SIETE:
                case OCHO:
                case NUEVE:
                            return estadoFinal=2; break;
                case SUMA:
                case RESTA:
                case MULTIPLICACION:
                case DIVISION:return estadoFinal=1; break;
                //No pertenecen al estado 2
                case CIERRE:
                case APERTURA: return estadoFinal=0; break;
                default : return estadoFinal=-1;
            }
    }
    if(estado==3)
    {
        switch(caracter)
            {
                case UNO:
                case DOS:
                case TRES:
                case CUATRO:
                case CINCO:
                case SEIS:
                case SIETE:
                case OCHO:
                case NUEVE:   return estadoFinal=4; break;
                case '(': push(&expresion,caracter); return estadoFinal=3; break;
                case CERO:
                case SUMA:
                case RESTA:
                case MULTIPLICACION:
                case DIVISION:
                case CIERRE: return estadoFinal=0; break;
                default : return estadoFinal=-1;
            }
    }
    if(estado==4)
    {
        switch(caracter)
            {
                case CERO:
                case UNO:
                case DOS:
                case TRES:
                case CUATRO:
                case CINCO:
                case SEIS:
                case SIETE:
                case OCHO:
                case NUEVE:
                            return estadoFinal=4; break;
                case SUMA:
                case RESTA:
                case MULTIPLICACION:
                case DIVISION:return estadoFinal=3; break;
                case CIERRE: pop(&expresion);
                            if(expresion->valor!='$')
                                {
                                    return estadoFinal=5;
                                }
                            else
                                {
                                    return estadoFinal=6;
                                }
                                break;
                case APERTURA: return estadoFinal=0; break;
                default : return estadoFinal=-1;
            }
    }
    if(estado==5)
    {
        switch(caracter)
            {
                case SUMA:
                case RESTA:
                case MULTIPLICACION:
                case DIVISION:return estadoFinal=3; break;
                case CIERRE: pop(&expresion);
                            if(expresion->valor!='$')
                                {
                                    return estadoFinal=5;
                                }
                                return estadoFinal=6;
                                break;
                case CERO:
                case UNO:
                case DOS:
                case TRES:
                case CUATRO:
                case CINCO:
                case SEIS:
                case SIETE:
                case OCHO:
                case NUEVE:
                case APERTURA:return estadoFinal=0; break;
                default : return estadoFinal=-1;
            }
    }
    if(estado==6)
    {
        switch(caracter)
            {
                case SUMA:
                case RESTA:
                case MULTIPLICACION:
                case DIVISION:return estadoFinal=1; break;
                case CERO:
                case UNO:
                case DOS:
                case TRES:
                case CUATRO:
                case CINCO:
                case SEIS:
                case SIETE:
                case OCHO:
                case NUEVE:
                case CIERRE:
                case APERTURA:return estadoFinal=0; break;
                default : return estadoFinal=-1;
            }
    }
return -1;
}

int estados(char cadena[50])
{
    int estado_actual=1;
    int posicion;
    for (posicion=0; posicion<strlen(cadena); posicion++)
    {
        estado_actual=leer(estado_actual,cadena[posicion]);
        if(estado_actual==0)
        {
            printf("La expresion \"%s\" es incorrecta ",cadena);
            printf("el error esta en el caracter \"%c\" en la posicion ",cadena[posicion]);
            printf("%i \n",posicion+1);
            break;
        }
        if(estado_actual==-1){
            printf("El caracter \"%c\" en la posicion ",cadena[posicion]);
            printf("\"%i\" no pertenece al alfabeto \n",posicion+1);
            break;
        }
    }
 return estado_actual;
}

void SepararYVerificar(char cadena[50]){

    int i=0,u,largo,v,ultimo_estado;
    largo=strlen(cadena);
    while(cadena[i]!='\0')
    {
        if(cadena[i]==' ')
        {
        while(cadena[i]==' ')
        {
        for(u=i;u<largo;u++)
        cadena[u]=cadena[u+1];
        u--;
        }
    }
    i++;
    }
    if(strlen(cadena)!=0){
        ultimo_estado=estados(cadena);
        if(ultimo_estado==2 || ultimo_estado==6){
                printf("La cadena \"%s\"  es correcta \n",cadena);
            }
        else if(ultimo_estado!=0 && ultimo_estado!=-1){
            printf("La expresion es incorrecta, el error esta en el ultimo caracter\n");
        }

    }
    else{
        printf("La cadena esta vacia \n");
    }
}

int main() {
    push(&expresion,'$');
    char cadena[50];
    while(gets(cadena))
    {
            SepararYVerificar(cadena);
            memset(cadena, 0, 50);
            while(expresion->valor!='$')
                {
                    pop(&expresion);
                }
            //posicion=0;
    }
 return 0;
}
