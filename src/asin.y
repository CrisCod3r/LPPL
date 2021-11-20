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
    EXP exp;
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

%type<cent> constante 
%type<cent> operadorAditivo operadorIgualdad operadorLogico 
%type<cent> operadorMultiplicativo operadorRelacional operadorUnario
%type<cent> expresionSufija expresionUnaria expresionRelacional
%type<cent> expresionMultiplicativa expresionIgualidad expresionAditiva
%type<cent> expresion
%type<cent> parametrosActuales listaParametrosActuales
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
        
expresion     : expresionIgualidad { $$ = $1; }
              | expresion operadorLogico expresionIgualidad
               {
                 if ($1 == T_ERROR || $3 == T_ERROR)
                   $$ = T_ERROR;
                 else if ($1 == $3 == T_LOGICO)
                   $$ = T_LOGICO;
                 else {
                   $$ = T_ERROR;
                   yyerror("Operador no compatible con los tipos");
                 }
               }
              ;
        
expresionIgualidad  : expresionRelacional { $$ = $1; }
                    | expresionIgualidad operadorIgualdad expresionRelacional
                     {
                       if ($1 == T_ERROR || $3 == T_ERROR)
                         $$ = T_ERROR;
                       else if ($1 == $3)
                         $$ = T_LOGICO;
                       else {
                         $$ = T_ERROR;
                         yyerror("Operador no compatible con los tipos");
                       }                         
                     }
                    ;
        
expresionRelacional  : expresionAditiva { $$ = $1; }
                     | expresionRelacional operadorRelacional expresionAditiva
                      {
                        if ($1 == T_ERROR || $3 == T_ERROR)
                          $$ = T_ERROR;
                        else if ($1 == $3 == T_ENTERO)
                          $$ = T_LOGICO;
                        else {
                          $$ = T_ERROR;
                          yyerror("Operador no compatible con los tipos");
                        }
                      }
                     ;
        
expresionAditiva  : expresionMultiplicativa { $$ = $1; }
                  | expresionAditiva operadorAditivo expresionMultiplicativa
                   {
                     if ($1 == T_ERROR || $3 == T_ERROR)
                       $$ = T_ERROR;
                     else if ($1 == $3 == T_ENTERO) 
                       $$ = T_ENTERO;
                     else {
                       $$ = T_ERROR;
                       yyerror("Operador no compatible con los tipos");
                     }
                   }                 
                  ;
        
expresionMultiplicativa  : expresionUnaria { $$ = $1; }
                         | expresionMultiplicativa operadorMultiplicativo expresionUnaria                        
                          {
                            if ($1 == T_ERROR || $3 == T_ERROR)
                              $$ = T_ERROR;
                            else if ($1 == $3 == T_ENTERO)
                              $$ = T_ENTERO;
                            else {
                              $$ = T_ERROR;
                              yyerror("Operador no compatible con los tipos");
                            }
                          }
                         ;
        
expresionUnaria  : expresionSufija { $$ = $1; }
                 | operadorUnario expresionUnaria 
                  {
                    if ($2 == T_ERROR)
                      $$ = $2;
                    else if ($2 == T_LOGICO && $1 == NOTT)
                      $$ = T_LOGICO;
                    else if ($2 == T_ENTERO && $1 != NOTT)
                      $$ = T_ENTERO;
                    else {
                      $$ = T_ERROR;
                      yyerror("Operador no compatible con los tipos");
                    }
                  }
                 ;
        
expresionSufija  : constante { $$ = $1; }
                 | OPAR_ expresion CPAR_ { $$ = $2; }
                 | ID_ 
                  {
                    SIMB id = obtTdS($1);
                    $$ = T_ERROR;
                    if (id.t == T_ERROR) {
                      yyerror("Variable no definida");
                    }
                    else if (id.t == T_ARRAY) {
                      yyerror("Array sin indice");
                    }
                    else if (id.t == T_RECORD) {
                      yyerror("No se accede a ningun registro");
                    }
                    else {
                      $$ = sim.t;
                    }
                  }
                 | ID_ PUNTO_ ID_
                  {
                    SIMB id = obtTdS($1);
                    $$ = T_ERROR;
                    if (id.t == T_ERROR) {                      
                      yyerror("Variable no definida");
                    }
                    else if (id.t != T_RECORD) {
                      yyerror("Variable no es de tipo STRUCT");
                    }
                    else {
                      CAMP reg = obtTdR(id.ref, $3);
                      if (reg.t == T_ERROR) {
                        yyerror("Registro no definido");
                      }
                      else if (id.t == T_ARRAY) {
                        yyerror("Array sin indice");
                      }
                      else if (id.t == T_RECORD) {
                        yyerror("No se accede a ningun registro");
                      }
                      else {
                        $$ = reg.t;
                      }
                    }
                  }
                 | ID_ OCOR_ expresion CCOR_
                  {
                    SIMB id = obtTdS($1);
                    $$ = T_ERROR;
                    if (id.t == T_ERROR) {                      
                      yyerror("Variable no definida");
                    }
                    else if (id.t != T_ARRAY) {
                      yyerror("Variable no es de tipo ARRAY");
                    }
                    else {
                      DIM elem = obtTdA(id.ref);
                      if ($3 != T_ENTERO) {
                        yyerror("Expresion de acceso a array invalida");
                      }
                      else {
                        $$ = elem.telem;
                      }
                    }
                  }
                 | ID_ OPAR_ parametrosActuales CPAR_
                  {
                    SIMB id = obtTdS($1);
                    $$ = T_ERROR;
                    if (id.t == T_ERROR) {
                      yyerror("Variable no definida");
                    }
                    else {
                      INF func = obtTdD(id.ref);
                      if (func.tipo == T_ERROR) {
                        yyerror("Esta variable no es una funcion");
                      }
                      else if (!cmpDom(id.ref, $3)){
                        yyerror("Parametros no adecuados para la funcion");
                      }
                      else {
                        $$ = func.tipo;
                      }
                    }
                  }
                 ;
        
constante    : CONSTANTE_ { $$ = T_ENTERO; }
             | TRUE_ { $$ = T_LOGICO; }
             | FALSE_ { $$ = T_LOGICO; }
             ;
        
parametrosActuales  : { insTdD(-1, T_VACIO); }
                    | listaParametrosActuales
                     {
                       $$ = $1;
                     }
                    ;
        
listaParametrosActuales : expresion { $$ = insTdD(-1, $1); }
                        | expresion COMA_ listaParametrosActuales
                         {
                           $$ = insTdD($3, $1);
                         }
                        ;
        
operadorLogico   : AND_ { $$ = ANDD; }
                 | OR_  { $$ = ORR; }
                 ;
        
operadorIgualdad   : IGUAL_ { $$ = IGUALL; }
                   | DESIGUAL_ { $$ = DESIGUALL; }
                   ;
        
operadorRelacional   : MAYOR_ { $$ = MAYORR; }
                     | MENOR_ { $$ = MENORR; }
                     | MAYORIGUAL_ { $$ = MYIGUALL; }
                     | MENORIGUAL_ { $$ = MNIGUALL; }
                     ;
        
operadorAditivo   : MAS_ { $$ = MASS; }
                  | MENOS_ { $$ = MENOSS; }
                  ;
        
operadorMultiplicativo   : MULT_ { $$ = MULTT; }
                         | DIV_ { $$ = DIVV; }
                         ;
        
operadorUnario   : MAS_ { $$ = POSS; }
                 | MENOS_ {$$ = NEGG; }
                 | NEGACION_ { $$ = NOTT; }
                 ;
        

%%

