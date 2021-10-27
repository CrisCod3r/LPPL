%{
#include <stdio.h>
#include "asin.h"
#include "header.h"

#define  retornar(x) {if (verbosidad) ECHO; return(x) ; }
%}

%option yylineno
%option noinput
%option nounput



/* Necesario para detectar y mostrar el número de línea */
finlinea "\n" 

delimitador [ \t]+
digito [0-9]
letra [a-zA-Z]
id {letra}({letra}|{digito}|_)*
entero {digito}+
real {digito}+\.{digito}*|{digito}*\.{digito}+
constante {entero}|{real}
comentario "//".*


%%
{comentario}       { if (verbosidad) ECHO ; }
{delimitador}   { if (verbosidad) ECHO ; }

"=="            { retornar (IGUAL_) ; }
"!="            { retornar (DESIGUAL_) ; }
"&&"            { retornar (AND_) ; }
"||"            { retornar (OR_) ; }

"if"            { retornar (IF_) ; }
"else"          { retornar (ELSE_) ; }
"while"         { retornar (WHILE_) ; }

"true"          { retornar (TRUE_) ; }
"false"         { retornar (FALSE_) ; }

"<"             { retornar (MENOR_) ; }
"<="            { retornar (MENORIGUAL_) ; }
">"             { retornar (MAYOR_) ; }
">="            { retornar (MAYORIGUAL_) ; }
"!"             { retornar (NEGACION_) ; }

"+"             { retornar (MAS_) ; }
"-"             { retornar (MENOS_) ; }
"*"             { retornar (MULT_) ; }
"/"             { retornar (DIV_) ; }


"="             { retornar (ASIG_) ; }

"("             { retornar (OPAR_) ; }
")"             { retornar (CPAR_) ; }
"["             { retornar (OCOR_) ; }
"]"             { retornar (CCOR_) ; }
"{"             { retornar (OLLA_) ; }
"}"             { retornar (CLLA_) ; }

";"             { retornar (PUNTOYCOMA_) ; }
"."             { retornar (PUNTO_) ; }
","             { retornar (COMA_) ; }


"struct"        { retornar (STRUCT_) ; }
"int"           { retornar (INT_) ; }
"bool"          { retornar (BOOL_) ; }

"return"        { retornar (RETURN_) ; }
"read"          { retornar (READ_) ; }
"print"         { retornar (PRINT_) ; }



{constante}     { retornar (CONSTANTE_) ; }
{id}            { retornar (ID_) ; }
{finlinea}      { if (verbosidad) { ECHO; fprintf (stdout, "%3d.- ", yylineno); } }
.               { yyerror("Símbolo desconocido") ; }

%%

