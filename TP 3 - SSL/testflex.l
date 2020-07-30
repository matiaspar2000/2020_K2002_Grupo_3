%option noyywrap
%option yylineno

%{
#include <stdio.h>

int acumDecimales = 0;
%}

DIGITO_DECIMAL [0-9]
DIGITO_OCTAL [0-7]
DIGITO_HEXADECIMAL [a-fA-F0-9]
LETRA [a-zA-Z]

%%

[1-9]{DIGITO_DECIMAL}* {printf("Se encontró la constante entera decimal: %s \n", yytext);}
0{DIGITO_OCTAL}* {printf("Se encontró la constante entera octal: %s \n", yytext);} 
0[xX]{DIGITO_HEXADECIMAL}+ {printf("Se encontró la constante entera hexadecimal: %s \n", yytext);}
{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+([eE]([\+\-]?){DIGITO_DECIMAL}+)? {printf("Se encontró la constante real: %s \n", yytext);}
"char"|"int"|"float"|"double"|"long"|"short"|"signed"|"unsigned"|"void"|"enum"|"struct"|"typedef"|"union"  {printf("Se encontró la palabra reservada de tipo de dato: %s \n", yytext);}
"switch"|"case"|"break"|"default"|"continue"|"do"|"while"|"if"|"else"|"fo"|"return"|"goto" {printf("Se encontró la palabra reservada de tipo control: %s \n", yytext);}
"volatile"|"goto"|"extern"|"static"|"auto"|"register" {printf("Se encontró la palabra reservada de tipo otro: %s \n", yytext);}
\+\+|\*|\+|\&|\!|"sizeof"|\/|\%|\<|\<\=|\=\=|\!\=|\&\&|\|\||\?\:|\=|\+\=|\(|\)|\{|\}|\,|\; {printf("Se encontró un operador o caracter de puntuacion: %s \n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("Se encontró el identificador: %s \n", yytext);}
\'(.)\' {printf("Se encontró el caracter: %s \n", yytext);}    
\"(.)*\" {printf("Se encontró el literal cadena: %s de largo %d \n", yytext, yyleng);}  
\/\*(\*+[^\*\/]|[^\*])*\*+\/ {printf("Se encontró el comentario largo: %s \n", yytext);}
\/\/(.)* {printf("Se encontró el comentario corto : %s \n", yytext);}

%%
int main() {
    yyin=fopen("entrada.txt", "r"); 
    yyout=fopen("salida.txt", "w");
    yylex();

    return 0;
}


/*
Categorías léxicas de C a reconocer:

--Constantes (Entera decimal, entera octal, entera hexadecimal, real, caracter)
--Literal cadena
--Palabras reservadas (distinguir entre tipo de dato, estructuras de control y otros)
--Identificadores 
Caracteres de puntuación y operadores de C.

Comentarios (es realidad son reconocidos por el PRECOMPILADOR)

Comentarios de una línea
Comentarios de múltiples líneas

operador: uno de ++ * + & ! sizeof / % < <= == != && || ?: = +=
carácterPuntuación: uno de ( ) { } , ;   


/*char|int|float|double|long|short|signed|unsigned|void|enum|struct|typedef|union 
switch|case|break|default|continue|do|while|if|else|fo|return|goto 
volatile|goto|extern|static|auto|register 

/* CLASIFICACIÓN DE PALABRAS RESERVADAS 

TIPOS DE DATO = char,int,float,double,long,short,signed,unsigned,void,enum ,struct,typedef,union

ESTRUCTURAS DE CONTROL = switch,case,break,default,continue,do,while,if,else,fo,return,goto

OTROS= volatile, goto, extern, static, auto, register */