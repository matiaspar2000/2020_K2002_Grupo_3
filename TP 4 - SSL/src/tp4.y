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

 struct yylval_struct
  {


  } mystruct;

}

%token

%type 

%% /* A continuacion las reglas gramaticales y las acciones */

input:  /* vacio */
        | input line
;

line:   '\n'
        | exp '\n'  

%%

int main ()
{
    #ifdef BISON_DEBUG
        yydebug = 1;
#endif
  yyparse ();
}
