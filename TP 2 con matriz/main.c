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
int matriz [6] [5] = {{-1,1,-1,2,-1},
                      {1,1,0,-1,-1},
                      {-1,3,-1,2,-1},
                      {3,3,2,-1,4},
                      {-1,-1,2,-1,5},
                      {-1,-1,0,-1,-1}};
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

int leer(int estado, char caracter)
{
    {
        switch(caracter)
            {
                case CERO: return matriz[estado][0];
                case UNO:
                case DOS:
                case TRES:
                case CUATRO:
                case CINCO:
                case SEIS:
                case SIETE:
                case OCHO:
                case NUEVE: return matriz[estado][1];
                case SUMA:
                case RESTA:
                case MULTIPLICACION:
                case DIVISION: return matriz[estado][2];
                case APERTURA: if(estado==0 || estado==2)
                                {
                                    push(&expresion,caracter);
                                    return matriz[estado][3];
                                }
                                return -1;
                case CIERRE: if(estado==3 || estado== 4)
                                {
                                    pop(&expresion);
                                    if(expresion-> valor == '$')
                                    {
                                        return 5;
                                    }
                                    return matriz[estado][4];
                                }
                                return -1;
                default :  return -2;
            }
    }
}

int estados(char cadena[50])
{
    int estado_actual=0;
    int posicion;
    for (posicion=0; posicion<strlen(cadena); posicion++)
    {
        estado_actual=leer(estado_actual,cadena[posicion]);
        if(estado_actual==-1)
        {
            printf("La expresion \"%s\" es incorrecta ",cadena);
            printf("el error esta en el caracter \"%c\" en la posicion ",cadena[posicion]);
            printf("%i \n",posicion+1);
            break;
        }
        if(estado_actual==-2){
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
        if(ultimo_estado==1 || ultimo_estado==5){
                printf("La cadena \"%s\"  es correcta \n",cadena);
            }
        else if(ultimo_estado!=-1 && ultimo_estado!=-2){
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
