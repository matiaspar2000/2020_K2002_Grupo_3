%{
#include "tpINT.tab.h"
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

[1-9]{DIGITO_DECIMAL}* {yylval.miestructura.entero = atoi(yytext);yylval.miestructura.tipo=1; return NUM;}                       
0{DIGITO_OCTAL}* {yylval.miestructura.entero = strtol(yytext, NULL, 0); yylval.miestructura.tipo=1; return NUM;} 
0[xX]{DIGITO_HEXADECIMAL}+ {yylval.miestructura.entero = strtol(yytext, NULL, 0); yylval.miestructura.tipo=1; return NUM;}
{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+([eE]([\+\-]?){DIGITO_DECIMAL}+)? {yylval.miestructura.real=atof(yytext); yylval.miestructura.tipo=3; return CONSTANTE_REAL;}
char|"int"|float|double|long|short|signed|unsigned|void|enum|struct|typedef|union  {strcpy(yylval.miestructura.cadena,yytext); return TIPO_DATO;}
case|default|fo {strcpy(yylval.miestructura.cadena,yytext); return PALABRA_RESERVADA;}
if {strcpy(yylval.miestructura.cadena,yytext); return IF;}
else {strcpy(yylval.miestructura.cadena,yytext); return ELSE;}
switch {strcpy(yylval.miestructura.cadena,yytext); return SWITCH;}
while {strcpy(yylval.miestructura.cadena,yytext); return WHILE;}
for {strcpy(yylval.miestructura.cadena,yytext); return FOR;}
do {strcpy(yylval.miestructura.cadena,yytext); return DO;}
continue {strcpy(yylval.miestructura.cadena,yytext); return CONTINUE;}
break {strcpy(yylval.miestructura.cadena,yytext); return BREAK;}
return {strcpy(yylval.miestructura.cadena,yytext); return RETURN;}
goto {strcpy(yylval.miestructura.cadena,yytext); return GOTO;}
volatile|extern|static|auto|register|sizeof {strcpy(yylval.miestructura.cadena,yytext); return PALABRA_RESERVADA;}
[a-zA-Z_][a-zA-Z0-9_]* {strcpy(yylval.miestructura.cadena,yytext); return IDENTIFICADOR;}
\'(.|"\n")\' {strcpy(yylval.miestructura.cadena,yytext);yylval.miestructura.tipo=2; return CCARACTER;}
\"(.|"\n")*\" {strcpy(yylval.miestructura.cadena,yytext);yylval.miestructura.tipo=4; return STRING;}
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
";"     {return ';';}  
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
\<\=     {strcpy(yylval.miestructura.cadena,yytext); return MAYORIGUAL;}
\=\=     {strcpy(yylval.miestructura.cadena,yytext); return IGUALIGUAL;}
\!\=     {strcpy(yylval.miestructura.cadena,yytext); return DISTINTO;}
\+\=     {strcpy(yylval.miestructura.cadena,yytext); return MASIGUAL;}
\+\+     {strcpy(yylval.miestructura.cadena,yytext); return INCREMENTO;}
\-\-     {strcpy(yylval.miestructura.cadena,yytext); return DECREMENTO;}
\-\>     {strcpy(yylval.miestructura.cadena,yytext); return FLECHA;}
\|\|     {return 'O';}
\&\&     {return 'Y';}
sizeof   {strcpy(yylval.miestructura.cadena,yytext); return SIZEOF;}
"("     {return '(';} 
")"     {return ')';} 
"{"     {return '{';} 
"}"     {return '}';} 
"\n"    {}
[^\t' ']    {printf("Se encontró la cadena desconocida %s en la linea %d \n",yytext,yylineno);}

%% 