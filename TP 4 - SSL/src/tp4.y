%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int yylex();
int yywrap(){
	return(1);
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
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

%left '.' FLECHA '*' '%' '/' '+' '-'  '>' '<' MAYORIGUAL MENORIGUAL '&' '|' AND OR  IGUALIGUAL DISTINTO ',' 
%right '(' ')''[' ']' '&' '!' '*' '?' ':' '='    SIZEOF MASIGUAL INCREMENTO DECREMENTO 

%% /* reglas gramaticales y acciones */

input:  /* vacio */
        | input line
;

line:   '\n'
        | exp '\n'    {/*cami*/}
        | declaracion '\n' {/*mati puyol*/}
        | definicionExterna '\n' {/*partarrié*/}
        | sentencia '\n' {/*martín*/}
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

expMultiplicativa: '/'
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

exprecionPrimaria: IDENTIFICADOR
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

parametro:     TIPO_DATO
               | TIPO_DATO IDENTIFICADOR
               | ERROR IDENTIFICADOR     
               | TIPODATO ERROR 
;

cuerpo:  ';'                          
         | sentenciaCompuesta                 
         | '{' ERROR '}'                
         | ERROR  
;

definicionExternas:  '\n'
                      | unidadDeTraduccion
; 
unidadDeTraduccion: declaracionExterna 
                    |unidadDeTraduccion declaracionExterna
;               
declaracionExterna: definicionDeFuncion 
                   | declaracion
;
definicionDeFuncion: especificadoresDeDeclaracionOP decla listaDeDeclaracionesOP sentenciaCompuesta 
;

listaDeDeclaracionesOP: /*vacio*/
                        | listaDeDeclaraciones
;

especificadoresDeDeclaracionOP: /*vacio*/
                                | especificadoresDeDeclaracion
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

sentenciaSeleccion: PALABRA_RESERVADA '(' exp ')' sentencia                                     //if
                  | PALABRA_RESERVADA '(' exp ')' sentencia PALABRA_RESERVADA sentencia         //if else
                  | PALABRA_RESERVADA '(' entero ')' sentencia                                  //switch
;

sentenciaIteracion: PALABRA_RESERVADA '(' exp ')' sentencia                                     //while
                  | PALABRA_RESERVADA sentencia PALABRA_RESERVADA '(' exp ')'                   //do while
                  | PALABRA_RESERVADA '(' expOP ';' expOP ';' expOP ')' sentencia               //for
;

sentenciaSalto: PALABRA_RESERVADA ';'                   //continue
              | PALABRA_RESERVADA ';'                   //break
              | PALABRA_RESERVADA expOP ';'             //return
              | PALABRA_RESERVADA IDENTIFICADOR ';'     //goto

/*La sentencia continue solo debe aparecer dentro del cuerpo de un ciclo. La sentencia
break solo debe aparecer dentro de un switch o en el cuerpo de un ciclo. La
sentencia return con una expresión no puede aparecer en una función void.
*/

;
        
%%

int main ()
{
#ifdef BISON_DEBUG
        yydebug = 1;
#endif
        yyparse ();
}
