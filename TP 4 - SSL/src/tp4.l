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
{DIGITO_DECIMAL}*(\.){DIGITO_DECIMAL}+([eE]([\+\-]?){DIGITO_DECIMAL}+)? {yylval.real=atof(yytext); return CONSTANTE_REAL;}
char|int|float|double|long|short|signed|unsigned|void|enum|struct|typedef|union  {strcpy(yylval.cadena,yytext); return TIPO_DATO;}
switch|case|break|default|continue|do|while|if|else|fo|return|goto {strcpy(yylval.cadena,yytext); return PALABRA_RESERVADA;}
volatile|goto|extern|static|auto|register {strcpy(yylval.cadena,yytext); return PALABRA_RESERVADA;}
\+\+|\*|\+|\&|\!|sizeof|\/|\%|\<|\<\=|\=\=|\!\=|\&\&|\|\||\?\:|\=|\+\=|\(|\)|\{|\}|\,|\;|\[|\] {return yytext;}
[a-zA-Z_][a-zA-Z0-9_]* {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;}
\'(.|"\n")\' {strcpy(yylval.cadena,yytext[1]); return CCARACTER;}
\"(.|"\n")*\" {strcpy(yylval.cadena,yytext); return STRING;}
\/\*(\*+[^\*\/]|[^\*])*\*+\/ {} //comntario largo
\/\/(.)* {} //comentario corto



%%