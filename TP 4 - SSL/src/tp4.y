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
%token <entero> error

%type 

%% /* A continuacion las reglas gramaticales y las acciones */

input:  /* vacio */
        | input line
;

line:   '\n'
        | exp '\n'  
;
        
%%

int main ()
{
#ifdef BISON_DEBUG
        yydebug = 1;
#endif
        yyparse ();
}
