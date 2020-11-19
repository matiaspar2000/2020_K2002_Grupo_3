
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../src/funcionesDeListas.c"
#define YYDEBUG1

int flag_error=0;

extern int lineno;
extern FILE* yyin;

struct listaDeVariables *TSVar;
struct listaDeFunciones *TSFunc;
struct listaDeVariables *unaVar;
struct listaDeFunciones *unaFunc;

int yylex();
int yywrap(){
	return(1);
}

void yyerror (char const *s){
  fprintf(stderr, " ERROR SINTACTICO encontrado %s\n", s);
}

%}

%union {
        struct yylval_struct
  {
        char cadena[50];
        int entero;
        int tipo;
        char caracter;
        float real;      
        }miestructura;
}

%token <entero> NUM 
%token <cadena> IDENTIFICADOR
%token <cadena> TIPO_DATO
%token <cadena> PALABRA_RESERVADA 
%token <cadena> STRING 
%token <cadena> CCARACTER
%token <real> CONSTANTE_REAL
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
%token <cadena> FOR
%token <cadena> GOTO
%token <entero> error 

%% 

input:  /* vacio */
        | input line
;

line:   '\n'
        | expGeneral '\n'    
        | declaracion '\n' 
        | definicionDeFuncion '\n' 
        | sentencia '\n' 
;

expGeneral: expUnaria        
            | expUnaria operador expGeneral  
            | expUnaria '+' expGeneral   {if(flag_error==0) printf("Se encontro una expresion aditiva \n"); 

                                        if($<miestructura>1.tipo == $<miestructura>3.tipo){ 
                                               if($<miestructura>1.tipo==1){
                                                        $<miestructura>$.entero=$<miestructura>1.entero+$<miestructura>3.entero;
                                                        printf("CONTROL DE TIPOS EXITOSO, los operandos son del mismo tipo \n" );
                                               }else{
                                                        $<miestructura>$.real=$<miestructura>1.real+$<miestructura>3.real;
                                                        printf("CONTROL DE TIPOS EXITOSO, Los operandos son del mismo tipo \n");
                                               }
                                        }else{
                                                printf("ERROR SEMANTICO - Los operandos son de distinto tipo \n");
                                        }}// operadores aditivos con validacion de tipos       
;


operador:    '=' | MASIGUAL                                  {if(flag_error==0) printf("Se encontro una expresion de asignacion \n");}// operadores asignacion
            | OR | AND | IGUALIGUAL | DISTINTO                {if(flag_error==0) printf("Se encontro una expresion logica \n");}// operadores logicos
            | '<' | '>' | MENORIGUAL                          {if(flag_error==0) printf("Se encontro una expresion relacional \n");}// operadores relacionales
            | '-'                                              {if(flag_error==0) printf("Se encontro una expresion de sustraccion \n");}
            | '*' | '/' | '%'                                 {if(flag_error==0) printf("Se encontro una expresion multiplicativa \n");}// operadores multiplicativos
;            

expUnaria: expSufijo 
           | INCREMENTO expUnaria
           | DECREMENTO expUnaria
           | operadorUnario expUnaria
           | SIZEOF  expUnaria
           | SIZEOF '(' TIPO_DATO ')'
;

operadorUnario: '&' |'*' |'!'        {if(flag_error==0) printf("Se encontro una expresion unaria \n");}                         
;

expSufijo: expPrimaria
          | expSufijo '[' expGeneral ']' 
          | expSufijo '(' listaArgumentos ')'
          | expSufijo '.' IDENTIFICADOR
          | expSufijo FLECHA IDENTIFICADOR
          | expSufijo INCREMENTO
          | expSufijo DECREMENTO
;

listaArgumentos: expGeneral
                |listaArgumentos ',' expGeneral
                |/*vacio*/
;

expPrimaria:      |IDENTIFICADOR          {printf("Se encontro el identificador %s \n" , $<cadena>1);}
                  |CCARACTER              {printf(" Se encontro el caracter %c \n" , $<caracter>1);}
                  |STRING                 {printf ( "Se encontro la palabra %s \n " , $<cadena>1);}
                  |NUM                    {printf("Se encontro un numero %d \n", $<entero>1);}
                  |'(' expGeneral ')'
                  |otro tipo de dato       
;

declaracion: TIPO_DATO IDENTIFICADOR parametros {if(flag_error==0) printf("función declarada correctamente");
                                                strcpy(unaFunc->nombreF, $<miestructura>2.cadena);   
                                                strcpy(unaFunc->tipoDeDatoSalida, $<miestructura>1.cadena);
                                                insertarFuncionUnica(unaFunc,TSFunc);
                                                }  
;

parametros: '(' listaDeParametros ')'
            | '(' ')'
;

listaDeParametros:   parametro
                    | listaDeParametros ',' parametro
;

parametro:     TIPO_DATO                        {if(flag_error==0) printf("Se encontró un parámetro de tipo %s \n", $<miestructura>1.cadena); 
                                                  strcpy(unaVar->tipoDeDato, $<miestructura>1.cadena);
                                                  strcpy(unaVar->nombreV, " sin definir");
                                                  insertarVariableUnica(unaVar,*unaFunc->parametros)}
               | TIPO_DATO IDENTIFICADOR        {if(flag_error==0) printf("Se encontró un parámetro de tipo %s de nombre %s \n", $<miestructura>1.cadena, $<miestructura>2.cadena); 
                                                  strcpy(unaVar->tipoDeDato, $<miestructura>1.cadena);
                                                  strcpy(unaVar->nombreV, $<miestructura>2.cadena);
                                                  insertarVariableUnica(unaVar,*unaFunc->parametros);}
               | error IDENTIFICADOR            {printf("error al declarar el tipo de dato del parámetro"); flag_error=1;}  
               | TIPO_DATO error                {printf("error al definir el identificador del parámetro"); flag_error=1;}
;

cuerpo:  ';'                    {if(flag_error==0) printf("función definida correctamente");}                       
         | sentenciaCompuesta   {if(flag_error==0) (printf("función definida correctamente"));}             
         | '{' error '}'        {if(flag_error==0) {printf("Error al definir la función \n"); flag_error=1;};}              
         | error                {if(flag_error==0) {printf("Error al definir la función \n"); flag_error=1;};} 
;

definicionDeFuncion:   TIPO_DATO IDENTIFICADOR parametros cuerpo     {if(flag_error==0) printf("Se declaró correctamente la funcion %s \n", $<miestructura>2.cadena);
                                                                        strcpy(unaFunc->nombreF, $<miestructura>2.cadena);   
                                                                        strcpy(unaFunc->tipoDeDatoSalida, $<miestructura>1.cadena);
                                                                        insertarFuncionUnica(unaFunc,TSFunc);
                                                                        }    
                        | error IDENTIFICADOR parametros cuerpo      {yyerror; printf("Error al definir el tipo de dato de la funcion\n"); flag_error=1;} 
                        | TIPO_DATO error parametros cuerpo          {yyerror; printf("Error al definir el identificador de la funcion\n"); flag_error=1;}                                                        
;

sentencia: sentenciaCompuesta                       {printf("Se encontró una sentencia compuesta.\n");}
         | sentenciaExpresion                       {printf("Se encontró una sentencia expresión.\n");}
         | sentenciaSeleccion                       {printf("Se encontró una sentencia selección.\n");}
         | sentenciaIteracion                       {printf("Se encontró una sentencia iteración.\n");}
         | sentenciaSalto                           {printf("Se encontró una sentencia salto.\n");}
;

sentenciaCompuesta: '{' listaDeDeclaracionesOP listaSentenciasOP '}'
;

listaDeDeclaracionesOP: /* vacio */
                        | listaDeDeclaraciones
;

listaDeDeclaraciones: declaracion
                    | listaDeDeclaraciones declaracion     {printf("Se encontró una lista de declaraciones.\n");}
;

listaSentenciasOP: /* vacio */
                   | listaSentencias
;

listaSentencias: sentencia
               | listaSentencias sentencia                 {printf("Se encontró una lista de sentencias.\n");}
;

sentenciaExpresion: expOP ';'      
;

expOP: /* vacio */
       | expGeneral
;

sentenciaSeleccion: IF '(' expGeneral ')' sentencia                    {printf("Se encontró una sentencia if.\n");}
                  | IF '(' expGeneral ')' sentencia ELSE sentencia     {printf("Se encontró una sentencia if-else.\n");}
                  | SWITCH '(' IDENTIFICADOR ')' sentencia             {printf("Se encontró una sentencia switch.\n");}
;

sentenciaIteracion: WHILE '(' expGeneral ')' sentencia                           {printf("Se encontró una sentencia while.\n");}                    
                  | DO sentencia WHILE '(' expGeneral ')'                        {printf("Se encontró una sentencia do-while.\n");}     
                  | FOR '(' expOP ';' expOP ';' expOP ')' sentencia       {printf("Se encontró una sentencia for.\n");}     
;

sentenciaSalto: CONTINUE ';'                    {printf("Se encontró una sentencia continue.\n");}       
              | BREAK ';'                       {printf("Se encontró una sentencia break.\n");}
              | RETURN expOP ';'                {printf("Se encontró una sentencia return.\n");}
              | GOTO IDENTIFICADOR ';'          {printf("Se encontró una sentencia goto.\n");}
;
        
%%

int main (int argc, char *argv[])
{
    int flag;
 
    yyin=fopen("archivoFuente.c","r");
 
    flag=yyparse();
 
    fclose(yyin);

    reportarVariablesDeclaradas(TSVar);
    reportarFuncionesDeclaradas(TSFunc);
   
    return flag;
}