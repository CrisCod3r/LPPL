/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2         20201-2022 <jbenedi@dsic.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "libtds.h"
#include "header.h"
%}

//Uniones
%union {
    char *ident;    /* Nombre del identificador*/
    int cent;       /* Valor de la cte numerica entera*/
    struct {
        int talla;
        int refe;
    } LC;           /* Lista de campos con: talla y referencia*/

    struct {
        int talla;
        int refe;
    } LPF;          /* Lista de parametros formales con: talla y referencia*/
}

//Terminales
%token AND_ OR_ IGUAL_ DESIGUAL_ 

%token MAYOR_ MAYORIGUAL_ MENOR_ MENORIGUAL_

%token MULT_ DIV_ MAS_ MENOS_ NEGACION_ ASIG_

%token OPAR_ CPAR_ OCOR_ CCOR_ OLLA_ CLLA_

%token PUNTOYCOMA_ PUNTO_ COMA_ STRUCT_ INT_ BOOL_ RETURN_ READ_ PRINT_

%token IF_ ELSE_ WHILE_ TRUE_ FALSE_ 

// Terminales con atributo
%token<cent> CONSTANTE_
%token<ident> ID_

// No terminales con atributo
%type<cent> tipoSimple declaracionVariable
%type<cent> listaDeclaraciones declaracion
%type<cent> constante 
%type<cent> operadorAditivo operadorIgualdad operadorLogico 
%type<cent> operadorMultiplicativo operadorRelacional operadorUnario
%type<cent> expresionSufija expresionUnaria expresionRelacional
%type<cent> expresionMultiplicativa expresionIgualidad expresionAditiva
%type<cent> expresion
%type<cent> parametrosActuales listaParametrosActuales
%type<LC> listaCampos
%type<LPF> listaParametrosFormales parametrosFormales
%type<cent> declaracionFuncion
%%
//Gramática

programa     : {niv = 0; dvar = 0; cargaContexto(niv);} listaDeclaraciones
               {
                 if ($2 == 0) yyerror(ERR_NOT_MAIN);
                 else if ($2 > 1) yyerror(ERR_MANY_MAIN);
               }
             ;
             
listaDeclaraciones    : declaracion {$$ = $1;} 
                      | listaDeclaraciones declaracion {$$ = $1 + $2;}
                      ;
                      
declaracion     : declaracionVariable 
                 { $$ = 0; } // No se define funcion main
                | declaracionFuncion 
                 { $$ = $1; } // Puede que se haya definido una funcion main
                ;
        
declaracionVariable  : tipoSimple ID_ PUNTOYCOMA_
                      {
                        if (!insTdS($2,VARIABLE,$1,niv,dvar,-1))
                          yyerror(ERR_DUP_ID_VAR);
                        else dvar += TALLA_TIPO_SIMPLE;
                      }
                     | tipoSimple ID_ OCOR_ CONSTANTE_ CCOR_ PUNTOYCOMA_
                      {
                        int numelem = $4;
                        if ($4 <= 0) {
                          yyerror(ERR_ARR_SIZE);
                          numelem = 0;
                        }
                        int refe = insTdA($1, numelem);
                        if (!insTdS($2, VARIABLE,T_ARRAY,niv,dvar,refe))
                          yyerror(ERR_DUP_ID_VAR);
                        else dvar += numelem * TALLA_TIPO_SIMPLE;
                      }
                     | STRUCT_ OLLA_ listaCampos CLLA_ ID_ PUNTOYCOMA_
                      {
                        if (!insTdS($5,VARIABLE,T_RECORD,niv,dvar,$3.refe))
                          yyerror(ERR_DUP_ID_VAR);
                        else 
                          dvar += $3.talla;
                      }
                     ;
        
tipoSimple   : INT_  {$$ = T_ENTERO;}
             | BOOL_ {$$ = T_LOGICO;}
             ;
        
listaCampos   : tipoSimple ID_ PUNTOYCOMA_
               {
                 int refe = insTdR(-1,$2,$1,0);
                 if (refe == -1)
                   yyerror(ERR_DUP_ID_CAM);
                 else {
                   $$.refe = refe;
                   $$.talla = TALLA_TIPO_SIMPLE;
                 }
               }
              | listaCampos tipoSimple ID_ PUNTOYCOMA_
               {
                 int refe = $1.refe;
                 if (insTdR(refe,$3,$2,$1.talla) == -1)
                   yyerror(ERR_DUP_ID_CAM);
                 else {
                   $$.refe = refe;
                   $$.talla = $1.talla + TALLA_TIPO_SIMPLE;
                 }
               }
              ;
        
declaracionFuncion  : tipoSimple ID_  
                     { niv++; cargaContexto(niv); $<cent>$ = dvar; dvar = 0; } 
                     OPAR_ parametrosFormales CPAR_ 
                     {
                       if (!insTdS($2,FUNCION,$1,niv-1,dvar,$5.refe))
                         yyerror(ERR_DUP_ID_FUN);
                       if (strcmp($2, "main\0") == 0) 
                         $<cent>$ = 1; // Se declara funcion main
                       else 
                         $<cent>$ = 0; // No se declara funcion main
                     }
                     bloque 
                     {
                       if (verTdS) mostrarTdS();
                       descargaContexto(niv); 
                       niv--; dvar = $<cent>1; $$ = $<cent>7; 
                     }
                    ;
        
parametrosFormales  : /* epsilon */ { $$.refe = insTdD(-1,T_VACIO); $$.talla = 0; }
                    | listaParametrosFormales 
                     {
                       $$.refe = $1.refe;
                       $$.talla = $1.talla - TALLA_SEGENLACES;
                     }
                    ;
        
listaParametrosFormales : tipoSimple ID_
                         {
                           int refe = insTdD(-1, $1);
                           $$.refe = refe;
                           int talla = TALLA_TIPO_SIMPLE + TALLA_SEGENLACES;
                           $$.talla = talla;
                           if (!insTdS($2,PARAMETRO,$1,niv,-talla,refe))
                             yyerror(ERR_DUP_ID_PAR);
                         }
                        | tipoSimple ID_ COMA_ listaParametrosFormales
                         {
                           int refe = insTdD($4.refe,$1);
                           $$.refe = refe;
                           int talla = $4.talla + TALLA_TIPO_SIMPLE;
                           $$.talla = talla;
                           if (!insTdS($2,PARAMETRO,$1,niv,-talla,refe))
                             yyerror(ERR_DUP_ID_PAR);
                         }
                        ;
        
bloque    : OLLA_ declaracionVariableLocal listaInstrucciones RETURN_  expresion PUNTOYCOMA_ CLLA_
           {
             INF fun = obtTdD(-1);
             if (fun.tipo == T_ERROR ) 
               yyerror(ERR_FUN_NOT_COM); // Al dar error la TdS, no se inserta en esta y por tanto no esta compilada
             else if ($5 != T_ERROR && fun.tipo != $5)
               yyerror(ERR_RET_TYPE);
           }
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
                         {                            
                           SIMB id = obtTdS($1);
                           if (id.t == T_ERROR) 
                             yyerror(ERR_VAR_NOT_DEF);
                           else if ($3 != T_ERROR && id.t != $3)
                             yyerror(ERR_ASIG);
                         }
                        | ID_ OCOR_ expresion CCOR_ ASIG_ expresion PUNTOYCOMA_
                         {
                           SIMB id = obtTdS($1);
                           if (id.t == T_ERROR)
                             yyerror(ERR_VAR_NOT_DEF);
                           else if (id.t != T_ARRAY)
                             yyerror(ERR_ASIG);
                           else {
                             DIM dim = obtTdA(id.ref);
                             if ($3 != T_ERROR && $3 != T_ENTERO)
                               yyerror(ERR_ARR_ACC);
                             else if ($6 != T_ERROR && $6 != dim.telem)
                               yyerror(ERR_ASIG);
                           }
                         }
                        | ID_ PUNTO_ ID_ ASIG_ expresion PUNTOYCOMA_
                         {
                           SIMB id = obtTdS($1);
                           CAMP reg = obtTdR(id.ref, $3);
                           if (id.t == T_ERROR)
                             yyerror(ERR_VAR_NOT_DEF);
                           else if (id.t != T_RECORD)
                             yyerror(ERR_ASIG);
                           else if ($5 != T_ERROR && $5 != reg.t)
                             yyerror(ERR_ASIG);
                         }
                        ;
        
instruccionEntradaSalida  : READ_ OPAR_ ID_ CPAR_ PUNTOYCOMA_
                           {
                             SIMB id = obtTdS($3);
                             if (id.t == T_ERROR) 
                               yyerror(ERR_VAR_NOT_DEF);
                             else if (id.t != T_ENTERO) 
                               yyerror(ERR_READ);
                           }
                          | PRINT_ OPAR_ expresion CPAR_ PUNTOYCOMA_
                           {
                             if ($3 != T_ERROR && $3 != T_ENTERO)
                               yyerror(ERR_PRINT);
                           }
                          ;
        
instruccionSeleccion   : IF_ OPAR_ expresion CPAR_ 
                        {
                          if ($3 != T_ERROR && $3 != T_LOGICO) 
                            yyerror(ERR_IF);
                        }
                         instruccion ELSE_ instruccion
                       ;
        
instruccionIteracion   : WHILE_ OPAR_ expresion CPAR_ 
                        {
                          if ($3 != T_ERROR && $3 != T_LOGICO) 
                            yyerror(ERR_WHILE);
                        }
                         instruccion
                       ;

expresion     : expresionIgualidad { $$ = $1; }
              | expresion operadorLogico expresionIgualidad
               {
                 if ($1 == T_ERROR || $3 == T_ERROR)
                   $$ = T_ERROR;
                 else if ($1 == $3 && $1 == T_LOGICO)
                   $$ = T_LOGICO;
                 else {
                   $$ = T_ERROR;
                   yyerror(ERR_EXP_LOG);
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
                         yyerror(ERR_EXP_IGU);
                       }                         
                     }
                    ;
        
expresionRelacional  : expresionAditiva { $$ = $1; }
                     | expresionRelacional operadorRelacional expresionAditiva
                      {
                        if ($1 == T_ERROR || $3 == T_ERROR)
                          $$ = T_ERROR;
                        else if ($1 == $3 && $1 == T_ENTERO)
                          $$ = T_LOGICO;
                        else {
                          $$ = T_ERROR;
                          yyerror(ERR_EXP_REL);
                        }
                      }
                     ;
        
expresionAditiva  : expresionMultiplicativa { $$ = $1; }
                  | expresionAditiva operadorAditivo expresionMultiplicativa
                   {
                     if ($1 == T_ERROR || $3 == T_ERROR)
                       $$ = T_ERROR;
                     else if ($1 == $3 && $1 == T_ENTERO) 
                       $$ = T_ENTERO;
                     else {
                       $$ = T_ERROR;
                       yyerror(ERR_EXP_ADI);
                     }
                   }                 
                  ;
        
expresionMultiplicativa  : expresionUnaria { $$ = $1; }
                         | expresionMultiplicativa operadorMultiplicativo expresionUnaria                        
                          {
                            if ($1 == T_ERROR || $3 == T_ERROR)
                              $$ = T_ERROR;
                            else if ($1 == $3 && $1 == T_ENTERO)
                              $$ = T_ENTERO;
                            else {
                              $$ = T_ERROR;
                              yyerror(ERR_EXP_MUL);
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
                      yyerror(ERR_EXP_UN);
                    }
                  }
                 ;
        
expresionSufija  : constante { $$ = $1; }
                 | OPAR_ expresion CPAR_ { $$ = $2; }
                 | ID_ 
                  {
                    SIMB id = obtTdS($1);
                    $$ = T_ERROR;
                    if (id.t == T_ERROR)
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t == T_ARRAY)
                      yyerror(ERR_ARR_NOT_IND);
                    else if (id.t == T_RECORD)
                      yyerror(ERR_REG_NOT_CAM);
                    else
                      $$ = id.t;
                  }
                 | ID_ PUNTO_ ID_
                  {
                    SIMB id = obtTdS($1);
                    $$ = T_ERROR;
                    if (id.t == T_ERROR)                    
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t != T_RECORD)
                      yyerror(ERR_REG_TYPE);
                    else {
                      CAMP reg = obtTdR(id.ref, $3);
                      if (reg.t == T_ERROR)
                        yyerror(ERR_CAM_NOT_DEF);
                      else
                        $$ = reg.t;
                    }
                  }
                 | ID_ OCOR_ expresion CCOR_
                  {
                    SIMB id = obtTdS($1);
                    $$ = T_ERROR;
                    if (id.t == T_ERROR)                     
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t != T_ARRAY)
                      yyerror(ERR_ARR_TYPE);
                    else {
                      DIM elem = obtTdA(id.ref);
                      if ($3 != T_ERROR && $3 != T_ENTERO)
                        yyerror(ERR_ARR_ACC);
                      else
                        $$ = elem.telem;
                    }
                  }
                 | ID_ OPAR_ parametrosActuales CPAR_
                  {
                    SIMB id = obtTdS($1);
                    $$ = T_ERROR;
                    if (id.t == T_ERROR)
                      yyerror(ERR_VAR_NOT_DEF);
                    else {
                      INF func = obtTdD(id.ref);
                      if (func.tipo == T_ERROR)
                        yyerror(ERR_FUN_TYPE);
                      else if (!cmpDom(id.ref, $3))
                        yyerror(ERR_FUN_PAR);
                      else
                        $$ = func.tipo; // Inseguro de mi mismo
                    }
                  }
                 ;
        
constante    : CONSTANTE_ { $$ = T_ENTERO; }
             | TRUE_ { $$ = T_LOGICO; }
             | FALSE_ { $$ = T_LOGICO; }
             ;
        
parametrosActuales  : /*epsilon*/ { insTdD(-1, T_VACIO); }
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
