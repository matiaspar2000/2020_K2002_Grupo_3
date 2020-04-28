#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estadoFinal (char *cadena){
    int matriz [7][6] =
           {{2,1,1,6,6,6},
            {1,1,1,6,6,6},
            {3,3,6,6,4,6},
            {3,3,6,6,6,6},
            {5,5,5,5,5,6},
            {5,5,5,5,6,6},
            {6,6,6,6,6,6}};
    int estadoNumero;
    for (estadoNumero=0; *cadena != '\0'; cadena++)
    {switch (*cadena) {
      case '0': estadoNumero = matriz [estadoNumero] [0]; break;
      case '1' ... '7': estadoNumero = matriz [estadoNumero] [1]; break;
      case '8' ... '9': estadoNumero = matriz [estadoNumero] [2]; break;
      case 'a' ... 'f': estadoNumero = matriz [estadoNumero] [3]; break;
      case 'A' ... 'F': estadoNumero = matriz [estadoNumero] [3]; break;
      case 'x': estadoNumero = matriz [estadoNumero] [4]; break;
      case 'X': estadoNumero = matriz [estadoNumero] [4]; break;
      default : estadoNumero = 6;}
    }
    return  estadoNumero;
}

int main()
{
    char aux[50];
    FILE *archivo;
    FILE *salida;
 	archivo = fopen("archivo.txt","r");
 	salida = fopen("salida.txt", "w");
 	if (archivo == NULL)
 		exit(1);
    while(!feof(archivo))
        fgets (aux, 50, archivo);
    char separador[] = ",";
    char *numero = strtok(aux, separador);
    if(numero != NULL){
        while(numero != NULL){
            fputs(numero,salida);
            if(estadoFinal(numero)==1){
                fputs(" es un numero decimal\n",salida);
            }
            else if(estadoFinal(numero)==3){
                fputs(" es un numero octal\n",salida);
            }
            else if(estadoFinal(numero)==5){
                fputs(" es un numero hexadecimal\n",salida);
            }
            else {
                fputs(" no es un numero\n",salida);
            }
            numero = strtok(NULL, separador);
        }
    }
    fclose(archivo);
    fclose(salida);
    return 0;
}

