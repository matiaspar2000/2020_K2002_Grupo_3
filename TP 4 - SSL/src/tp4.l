%{
#include <stdio.h>
#include <string.h>

%}

DIGITO_DECIMAL [0-9]
DIGITO_OCTAL [0-7]
DIGITO_HEXADECIMAL [a-fA-F0-9]
LETRA [a-zA-Z]

%%

[1-9]{DIGITO_DECIMAL}* {yylval.entero=atoi(yytext); return NUM;}                       
0{DIGITO_OCTAL}* {yylval.entero = strtol(yytext, NULL, 0); return NUM;} 
0[xX]{DIGITO_HEXADECIMAL}+ {yylval.entero = strtol(yytext, NULL, 0); return NUM;}

{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+([eE]([\+\-]?){DIGITO_DECIMAL}+)? {printf("Se encontró la constante real: %s \n", yytext)}
"char"|"int"|"float"|"double"|"long"|"short"|"signed"|"unsigned"|"void"|"enum"|"struct"|"typedef"|"union"  {strcpy(yylval.cadena,yytext); return TIPO_DATO;}
"switch"|"case"|"break"|"default"|"continue"|"do"|"while"|"if"|"else"|"fo"|"return"|"goto" {printf("Se encontró la palabra reservada de tipo control: %s \n", yytext)}
"volatile"|"goto"|"extern"|"static"|"auto"|"register" {printf("Se encontró la palabra reservada de tipo otro: %s \n", yytext)}
\+\+|\*|\+|\&|\!|"sizeof"|\/|\%|\<|\<\=|\=\=|\!\=|\&\&|\|\||\?\:|\=|\+\=|\(|\)|\{|\}|\,|\;|\[|\] {printf("Se encontró un operador o caracter de puntuacion: %s \n", yytext)}
[a-zA-Z_][a-zA-Z0-9_]* {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;}
\'(.|"\n")\'  {printf("Se encontró el caracter: %s \n", yytext)} 
\"(.|"\n")*\" {strcpy(yylval.cadena,yytext); return STRING;}
\/\*(\*+[^\*\/]|[^\*])*\*+\/ {printf("Se encontró el comentario largo: %s \n", yytext)}
\/\/(.)* {printf("Se encontró el comentario corto : %s \n", yytext)}

%%