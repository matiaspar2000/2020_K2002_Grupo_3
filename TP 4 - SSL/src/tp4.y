
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define YYDEBUG1
  
extern int lineno;
extern FILE* yyin; 

void yyerror(char const *s);                                                  
    int yylex();  
    int yywrap(){
        return(1);
    }    

%}

%union {
        char cadena[50];
        int entero;
        int tipo;
        char caracter;
        float real;      
}

%token <entero> NUM 
%token <cadena> IDENTIFICADOR
%token <cadena> TIPO_DATO
%token <cadena> PALABRA_RESERVADA //Ver si realmente es necesario usar el resto de las palabras reservadas
%token <cadena> STRING 
%token <caracter> CCARACTER
%token <real> CONSTANTE_REAL
%token <entero> ERROR 
%token <cadena> MAYORIGUAL
%token <cadena> MENORIGUAL 
%token <cadena> IGUALIGUAL
%token <cadena> DISTINTO
%token <cadena> INCREMENTO
%token <cadena> DECREMENTO
%token <cadena> FLECHA
%token <cadena> OR
%token <cadena> AND
%token <cadena> MASIGUAL
%token <cadena> SIZEOF
%token <cadena> IF
%token <cadena> ELSE
%token <cadena> SWITCH
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> CONTINUE
%token <cadena> BREAK
%token <cadena> RETURN
%token <cadena> GOTO



%left '.' FLECHA '*' '%' '/' '+' '-'  '>' '<' MAYORIGUAL MENORIGUAL '&' '|' AND OR  IGUALIGUAL DISTINTO ',' 
%right '(' ')''[' ']' '&' '!' '*' '?' ':' '='    SIZEOF MASIGUAL INCREMENTO DECREMENTO 

%% /* reglas gramaticales y acciones */

input:  /* vacio */
        | input line
;

line:   '\n'
        | exp '\n'    
        | declaracion '\n' 
        | definicionDeFuncion '\n' 
        | sentencia '\n' 
        | error '\n'
;

exp: expAsignacion
;

expAsignacion: expCondicional 
               | expUnaria operadorAsignacion expAsignacion   
;

operadorAsignacion: '='
                    |MASIGUAL
;

expCondicional:  expOLogico
                | expOLogico '?' exp ':' expCondicional  

;
expORLogico: expANDLogico
           | expORLogico OR expANDLogico 
;

expANDLogico: expORInclusivo
             |expANDLogico AND expORInclusivo 
;

expORInclusivo: expANDLogico  
                | expORInclusivo '|' expAND
;

expAND: expIgualdad
        |expAND '&' expIgualdad
;

expIgualdad: expRelacional
             | expIgualdad operadorIgualdad expRelacional
;

operadorIgualdad: IGUALIGUAL
                 |DISTINTO
;

expRelacional: expRelacional operadorRelacional expAditiva
;

operadorRelacional: '<'
                   |'>'
                   |MAYORIGUAL
                   |MENORIGUAL
;

expAditiva:  expMultiplicativa
            | expAditiva operadorAditividad expMultiplicativa
;

operadorAditividad: '+'
                   |'-'
;

expMultiplicativa: expUnaria 
                  | expMultiplicativa operadorMultiplicativo expUnaria
;

operadorMultiplicativo: '/'
                  |'%'
                  |'*'
;

expUnaria: expSufijo 
           | INCREMENTO expUnaria
           | DECREMENTO expUnaria
           | operadorUnario expUnaria
           | SIZEOF  expUnaria
           | SIZEOF '(' TIPO_DATO ')'
;

operadorUnario: '&'
               |'*'
               |'!'
;

expSufijo: expPrimaria
          | expSufijo '[' exp ']' 
          | expSufijo '(' listaArgumentos ')'
          | expSufijo '.' IDENTIFICADOR
          | expSufijo FLECHA IDENTIFICADOR
          | expSufijo INCREMENTO
          | expSufijo DECREMENTO
;

listaArgumentos: exp
                |listaArgumentos ',' exp
;

expresionPrimaria: IDENTIFICADOR
                  |CONSTANTE_REAL
                  |STRING
                  |NUM
                  |'(' exp ')'
                  |ERROR
;

declaracion: TIPO_DATO IDENTIFICADOR parametros
;

parametros: '(' listaDeParametros ')'
            | '(' ')'
;

listaDeParametros:   parametro
                    | listaDeParametros ',' parametro
;

parametro:     TIPO_DATO     {printf("Se encontró un parámetro de tipo %s \n", $1); }
               | TIPO_DATO IDENTIFICADOR  {printf("Se encontró un parámetro de tipo %s de nombre %s \n", $<cadena>1, $<cadena>2); }
               | ERROR IDENTIFICADOR  {printf("error al declarar el tipo de dato del parámetro"); }   
               | TIPODATO ERROR {printf("error al definir el identificador del parámetro"); }
;

cuerpo:  ';'    {}                       
         | sentenciaCompuesta    {printf("función definida correctamente");}             
         | '{' ERROR '}' {yyerror; printf("error al definir la función");}               
         | ERROR  {yyerror; printf("error al definir la función");}
;

definicionDeFuncion:   TIPODATO IDENTIFICADOR parametros cuerpo     {printf("Se declaró correctamente la funcion %s \n", $<cadena>2;}    
                        | error IDENTIFICADOR parametros cuerpo     {yyerror; printf("Error al definir el tipo de dato de la funcion\n");}
                        | TIPODATO error parametros cuerpo          {yyerror; printf("Error al definir el identificador de la funcion\n");}                                                         
;

sentencia: sentenciaCompuesta 
         | sentenciaExpresion
         | sentenciaSeleccion
         | sentenciaIteracion
         | sentenciaSalto
;

sentenciaCompuesta: '{' listaDeDeclaracionesOP listaSentenciasOP '}'
;

listaDeDeclaracionesOP: /* vacio */
                        | listaDeDeclaraciones
;

listaDeDeclaraciones: declaracion
                    | listaDeDeclaraciones declaracion
;

listaSentenciasOP: /* vacio */
                   | listaSentencias
;

listaSentencias: sentencia
               | listaSentencias sentencia
;

sentenciaExpresion: expOP ';'      
;

expOP: /* vacio */
       | exp
;

sentenciaSeleccion: IF '(' exp ')' sentencia                                    
                  | IF '(' exp ')' sentencia ELSE sentencia         
                  | SWITCH '(' entero ')' sentencia                                  
;

sentenciaIteracion: WHILE '(' exp ')' sentencia                                  
                  | DO sentencia WHILE '(' exp ')'                   
                  | FOR '(' expOP ';' expOP ';' expOP ')' sentencia               
;

sentenciaSalto: CONTINUE ';'                   
              | BREAK ';'                   
              | RETURN expOP ';'             
              | GOTO IDENTIFICADOR ';'     

/*La sentencia continue solo debe aparecer dentro del cuerpo de un ciclo. La sentencia
break solo debe aparecer dentro de un switch o en el cuerpo de un ciclo. La
sentencia return con una expresión no puede aparecer en una función void.
*/

;
        
%%
%%
void yyerror (char const *s)
{
  fprintf(stderr, "Error Sintactico en la linea %d = %s \n", lineno,s);
  exit(1);
}

int main (int argc, char *argv[])
{
    int flag;
 
    yyin=fopen("archivoFuente.c","r");
 
    flag=yyparse();
 
    fclose(yyin);
   
    return flag;
}