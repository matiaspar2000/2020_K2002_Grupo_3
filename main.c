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
int estados(char *cadena)
{
    int estado_actual;
    for (estado_actual=1; *cadena != '\0'; cadena++)
    {
        estado_actual=leer(estado_actual,*cadena);
    }
 return estado_actual;
}
int main() {
    char aux[50];
    while(gets(aux))
    {
        int ultimo_estado;
        ultimo_estado=estados(aux);
        if(ultimo_estado==2 || ultimo_estado==6)
        {
            printf("La expresion es correcta \n");
        }
        else
        {
            printf("No es correcta \n");
        }
        memset(aux, 0, 50);
        while(expresion!=NULL)
        {
            pop(&expresion);
        }
    }
 return 0;
}
