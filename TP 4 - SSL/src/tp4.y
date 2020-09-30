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
%token <cadena> IGUALIGUAL
%token <cadena> DISTINTO
%token <cadena> INCREMENTO
%token <cadena> DECREMENTO
%token <cadena> FLECHA
%token <cadena> O
%token <cadena> Y

%type 


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

exp: 

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

sentenciaCompuesta: listaDeDeclaraciones? listaSentencias?
;

listaDeDeclaraciones: declaracion
                    | listaDeDeclaraciones declaracion
;

listaSentencias: sentencia
               | listaSentencias sentencia
;

sentenciaExpresion: exp? ';'      
;

sentencia: sentenciaCompuesta 
         | sentenciaExpresion
         | sentenciaSeleccion
         | sentenciaIteracion
         | sentenciaSalto
;

sentenciaCompuesta: listaDeDeclaracionesOP listaSentenciasOP
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

sentenciaSeleccion:     
;
        
%%

int main ()
{
#ifdef BISON_DEBUG
        yydebug = 1;
#endif
        yyparse ();
}
