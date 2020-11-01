%{
#include "tp4.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define YYDEBUG1

extern FILE* yyin;
%}
%option yylineno

DIGITO_DECIMAL [0-9]
DIGITO_OCTAL [0-7]
DIGITO_HEXADECIMAL [a-fA-F0-9]
LETRA [a-zA-Z]

%%

[1-9]{DIGITO_DECIMAL}* {yylval.entero = atoi(yytext); return NUM;}                       
0{DIGITO_OCTAL}* {yylval.entero = strtol(yytext, NULL, 0); return NUM;} 
0[xX]{DIGITO_HEXADECIMAL}+ {yylval.entero = strtol(yytext, NULL, 0); return NUM;}
{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+([eE]([\+\-]?){DIGITO_DECIMAL}+)? {yylval.real=atof(yytext); return CONSTANTE_REAL;}
char|int|float|double|long|short|signed|unsigned|void|enum|struct|typedef|union  {strcpy(yylval.cadena,yytext); return TIPO_DATO;}
case|default|fo {strcpy(yylval.cadena,yytext); return PALABRA_RESERVADA;}
if {strcpy(yylval.cadena,yytext); return IF;}
else {strcpy(yylval.cadena,yytext); return ELSE;}
switch {strcpy(yylval.cadena,yytext); return SWITCH;}
while {strcpy(yylval.cadena,yytext); return WHILE;}
for {strcpy(yylval.cadena,yytext); return FOR;}
do {strcpy(yylval.cadena,yytext); return DO;}
continue {strcpy(yylval.cadena,yytext); return CONTINUE;}
break {strcpy(yylval.cadena,yytext); return BREAK;}
return {strcpy(yylval.cadena,yytext); return RETURN;}
goto {strcpy(yylval.cadena,yytext); return GOTO;}
volatile|extern|static|auto|register|sizeof {strcpy(yylval.cadena,yytext); return PALABRA_RESERVADA;}
[a-zA-Z_][a-zA-Z0-9_]* {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;}
\'(.|"\n")\' {strcpy(yylval.cadena,yytext); return CCARACTER;}
\"(.|"\n")*\" {strcpy(yylval.cadena,yytext); return STRING;}
\/\*(\*+[^\*\/]|[^\*])*\*+\/ {} //comentario largo
\/\/(.)* {} //comentario corto
"+"     {return '+';}
"-"     {return '-';}
"*"     {return '*';}
"/"     {return '/';}
"^"     {return '^';} 
"["     {return '[';} 
"]"     {return ']';} 
"="     {return '=';} 
";"     {return ';';}  //agregar algun simbolo si llegara a faltar
","     {return ',';}
"&"     {return '&';}
"|"     {return '|';}
"!"     {return '!';}
"%"     {return '%';}
"/"     {return '/';}
"<"     {return '<';}
">"     {return '>';}
"?"     {return '?';}
":"     {return ':';}
\<\=     {strcpy(yylval.cadena,yytext); return MAYORIGUAL;}
\=\=     {strcpy(yylval.cadena,yytext); return IGUALIGUAL;}
\!\=     {strcpy(yylval.cadena,yytext); return DISTINTO;}
\+\=     {strcpy(yylval.cadena,yytext); return MASIGUAL;}
\+\+     {strcpy(yylval.cadena,yytext); return INCREMENTO;}
\-\-     {strcpy(yylval.cadena,yytext); return DECREMENTO;}
\-\>     {strcpy(yylval.cadena,yytext); return FLECHA;}
\|\|     {return 'O';}
\&\&     {return 'Y';}
sizeof   {strcpy(yylval.cadena,yytext); return SIZEOF;}
"("     {return '(';} 
")"     {return ')';} 
"{"     {return '{';} 
"}"     {return '}';} 

%% 