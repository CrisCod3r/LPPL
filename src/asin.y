/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2         20201-2022 <jbenedi@dsic.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
%}
//Uniones
%union {
    char *ident;       /* Nombre del identificador*/
    int cent;          /* Valor de la cte numerica entera*/
}

//Terminales
%token AND_ OR_ IGUAL_ DESIGUAL_ 

%token MAYOR_ MAYORIGUAL_ MENOR_ MENORIGUAL_

%token MULT_ DIV_ MAS_ MENOS_ NEGACION_ ASIG_

%token OPAR_ CPAR_ OCOR_ CCOR_ OLLA_ CLLA_

%token PUNTOYCOMA_ PUNTO_ COMA_ STRUCT_ INT_ BOOL_ RETURN_ READ_ PRINT_

%token IF_ ELSE_ WHILE_ TRUE_ FALSE_ 

// Token con atributo
%token<cent> CONSTANTE_
%token<ident> ID_

%type<cent> tipoSimple declaracionVariable

//Gramática
%%

programa     : {niv = 0; dvar = 0;} listaDeclaraciones
             ;
             
listaDeclaraciones    : declaracion
                      | listaDeclaraciones declaracion
                      ;
                      
declaracion     : declaracionVariable
                 {
                    insTdS($1)
                 }
                | declaracionFuncion
                ;
        
declaracionVariable  : tipoSimple ID_ PUNTOYCOMA_
                      {
                        if (!insTdS($2,VARIABLE,$1,niv,dvar,-1))
                            yyerror("Ya se encuentra definida esta variable")
                        else dvar += TALLA_TIPO_SIMPLE;
                      }
                     | tipoSimple ID_ OCOR_ CONSTANTE_ CCOR_ PUNTOYCOMA_
                      {
                        int numelem = $4;
                        if ($4 <= 0) {
                            yyerror("Talla inapropiada del array");
                            numelem = 0;
                        }
                        int refe = insTdA($1, numelem);
                        if (!insTdS($2, VARIABLE,T_ARRAY,niv,dvar,refe))
                            yyerror("Identificador ya definido");
                        else dvar += numelem * TALLA_TIPO_SIMPLE;
                      }
                     | STRUCT_ OLLA_ listaCampos CLLA_ ID_ PUNTOYCOMA_
                     ;
        
tipoSimple   : INT_ {$$ = T_ENTERO;}
             | BOOL_ {$$ = T_LOGICO;}
             ;
        
listaCampos   : tipoSimple ID_ PUNTOYCOMA_
              | listaCampos tipoSimple ID_ PUNTOYCOMA_
              ;
        
declaracionFuncion  : tipoSimple ID_ OPAR_ parametrosFormales CPAR_ bloque
                    ;
        
parametrosFormales  : 
                    | listaParametrosFormales
                    ;
        
listaParametrosFormales : tipoSimple ID_
                        | tipoSimple ID_ COMA_ listaParametrosFormales
                        ;
        
bloque    : OLLA_ declaracionVariableLocal listaInstrucciones RETURN_  expresion PUNTOYCOMA_ CLLA_
          ;
        
declaracionVariableLocal   : 
                           | declaracionVariableLocal declaracionVariable
                           ;
        
listaInstrucciones   : 
                     | listaInstrucciones instruccion
                     ;
        
instruccion    : OLLA_ listaInstrucciones CLLA_
               | instruccionAsignacion
               | instruccionSeleccion
               | instruccionEntradaSalida
               | instruccionIteracion
               ;
        
instruccionAsignacion   : ID_ ASIG_ expresion PUNTOYCOMA_
                        | ID_ OCOR_ expresion CCOR_ ASIG_ expresion PUNTOYCOMA_
                        | ID_ PUNTO_ ID_ ASIG_ expresion PUNTOYCOMA_
                        ;
        
instruccionEntradaSalida  : READ_ OPAR_ ID_ CPAR_ PUNTOYCOMA_
                          | PRINT_ OPAR_ expresion CPAR_ PUNTOYCOMA_
                          ;
        
instruccionSeleccion   : IF_ OPAR_ expresion CPAR_ instruccion ELSE_ instruccion
                       ;
        
instruccionIteracion   : WHILE_ OPAR_ expresion CPAR_ instruccion
                      ;
        
expresion     : expresionIgualidad
              | expresion operadorLogico expresionIgualidad
              ;
        
expresionIgualidad  : expresionRelacional
                    | expresionIgualidad operadorIgualdad expresionRelacional
                    ;
        
expresionRelacional  : expresionAditiva
                     | expresionRelacional operadorRelacional expresionAditiva
                     ;
        
expresionAditiva  : expresionMultiplicativa
                  | expresionAditiva operadorAditivo expresionMultiplicativa
                  ;
        
expresionMultiplicativa  : expresionUnaria
                         | expresionMultiplicativa operadorMultiplicativo expresionUnaria                        ;
        
expresionUnaria  : expresionSufija
                 | operadorUnario expresionUnaria
                 ;
        
expresionSufija  : constante
                 | OPAR_ expresion CPAR_
                 | ID_
                 | ID_ PUNTO_ ID_
                 | ID_ OCOR_ expresion CCOR_
                 | ID_ OPAR_ parametrosActuales CPAR_
                 ;
        
constante    : CONSTANTE_
             | TRUE_
             | FALSE_
             ;
        
parametrosActuales  : 
                    | listaParametrosActuales
                    ;
        
listaParametrosActuales : expresion
                        | expresion COMA_ listaParametrosActuales
                        ;
        
operadorLogico   : AND_
                 | OR_
                 ;
        
operadorIgualdad   : IGUAL_
                   | DESIGUAL_
                   ;
        
operadorRelacional   : MAYOR_
                     | MENOR_
                     | MAYORIGUAL_
                     | MENORIGUAL_
                     ;
        
operadorAditivo   : MAS_
                  | MENOS_
                  ;
        
operadorMultiplicativo   : MULT_
                         | DIV_
                         ;
        
operadorUnario   : MAS_
                 | MENOS_
                 | NEGACION_
                 ;
        

%%

