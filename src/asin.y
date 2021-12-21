/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2         20201-2022 <jbenedi@dsic.upv.es> **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "libtds.h"
#include "header.h"
#include "libgci.h"
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
    
    struct {
        int tipo;
        int desp;
    } EXP;
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
%type<cent> operadorAditivo operadorIgualdad operadorLogico 
%type<cent> operadorMultiplicativo operadorRelacional operadorUnario

%type<cent> parametrosActuales listaParametrosActuales
%type<LC> listaCampos
%type<LPF> listaParametrosFormales parametrosFormales
%type<cent> declaracionFuncion

%type<EXP> expresionSufija expresionUnaria expresionRelacional
%type<EXP> expresionMultiplicativa expresionIgualidad expresionAditiva
%type<EXP> expresion constante
%%
//Gramática

programa     : {niv = 0; dvar = 0; cargaContexto(niv); si = 0;} listaDeclaraciones
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
                       niv--; dvar = $<cent>3; $$ = $<cent>7; 
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
                 if ($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                   $$.tipo = T_ERROR;
                 else if ($1.tipo == $3.tipo && $1.tipo == T_LOGICO) {
                   $$.tipo = T_LOGICO;
                   $$.desp = creaVarTemp();
                   emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
                   if ($2 == ESUM) { // OR
                    emite(EMENEQ, crArgPos(niv, $$.desp), crArgEnt(1), crArgEnt(si + 2));
                    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.desp));
                   }
                 }
                 else {
                   $$.tipo = T_ERROR;
                   yyerror(ERR_EXP_LOG);
                 }
               }
              ;
        
expresionIgualidad  : expresionRelacional { $$ = $1; }
                    | expresionIgualidad operadorIgualdad expresionRelacional
                     {
                       if ($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                         $$.tipo = T_ERROR;
                       else if ($1.tipo == $3.tipo) {
                         $$.tipo = T_LOGICO;
                         $$.desp = creaVarTemp();
                         emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.desp));
                         emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgEnt(si + 2));
                         emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.desp));
                       }
                       else {
                         $$.tipo = T_ERROR;
                         yyerror(ERR_EXP_IGU);
                       }                         
                     }
                    ;
        
expresionRelacional  : expresionAditiva { $$ = $1; }
                     | expresionRelacional operadorRelacional expresionAditiva
                      {
                        if ($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                          $$.tipo = T_ERROR;
                        else if ($1.tipo == $3.tipo && $1.tipo == T_ENTERO) {
                          $$.tipo = T_LOGICO;
                          $$.desp = creaVarTemp();
                          emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.desp));
                          emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgEnt(si+2));
                          emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.desp));
                        }
                        else {
                          $$.tipo = T_ERROR;
                          yyerror(ERR_EXP_REL);
                        }
                      }
                     ;
        
expresionAditiva  : expresionMultiplicativa { $$ = $1; }
                  | expresionAditiva operadorAditivo expresionMultiplicativa
                   {
                     if ($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                       $$.tipo = T_ERROR;
                     else if ($1.tipo == $3.tipo && $1.tipo == T_ENTERO) {
                       $$.tipo = T_ENTERO;
                       
                       // ¿Dentro o fuera del else?
                       
                       $$.desp = creaVarTemp();
                       emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp),    crArgPos(niv, $$.desp));
                     }
                     else {
                       $$.tipo = T_ERROR;
                       yyerror(ERR_EXP_ADI);
                     }
                   }                 
                  ;
        
expresionMultiplicativa  : expresionUnaria { $$ = $1; }
                         | expresionMultiplicativa operadorMultiplicativo expresionUnaria                        
                          {
                            if ($1.tipo == T_ERROR || $3.tipo == T_ERROR)
                              $$.tipo = T_ERROR;
                            else if ($1.tipo == $3.tipo && $1.tipo == T_ENTERO) {
                              $$.tipo = T_ENTERO;
                              $$.desp = creaVarTemp();
                              emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
                            }
                            else {
                              $$.tipo = T_ERROR;
                              yyerror(ERR_EXP_MUL);
                            }
                          }
                         ;
        
expresionUnaria  : expresionSufija { $$ = $1; }
                 | operadorUnario expresionUnaria 
                  {
                    if ($2.tipo == T_ERROR)
                      $$ = $2;
                    else if ($2.tipo == T_LOGICO && $1 == ESIG) {
                      $$.tipo = T_LOGICO;
                      $$.desp = creaVarTemp();
                      emite(EDIF, crArgEnt(1), crArgPos(niv, $2.desp), crArgPos(niv, $$.desp));
                    }
                    else if ($2.tipo == T_ENTERO && $1 != ESIG) {
                      $$.tipo = T_ENTERO;
                      $$.desp = creaVarTemp();
                      emite($1, crArgEnt(0), crArgPos(niv, $2.desp), crArgPos(niv, $$.desp));
                    }
                    else {
                      $$.tipo = T_ERROR;
                      yyerror(ERR_EXP_UN);
                    }
                  }
                 ;
        
expresionSufija  : constante { $$ = $1; }
                 | OPAR_ expresion CPAR_ { $$ = $2; }
                 | ID_ 
                  {
                    SIMB id = obtTdS($1);
                    $$.tipo = T_ERROR;
                    if (id.t == T_ERROR)
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t == T_ARRAY)
                      yyerror(ERR_ARR_NOT_IND);
                    else if (id.t == T_RECORD)
                      yyerror(ERR_REG_NOT_CAM);
                    else {
                      $$.tipo = id.t;
                      $$.desp = creaVarTemp();
                      emite(EASIG, crArgPos(niv, id.d), crArgNul(), crArgPos(niv, $$.desp));
                    }
                  }
                 | ID_ PUNTO_ ID_
                  {
                    SIMB id = obtTdS($1);
                    $$.tipo = T_ERROR;
                    if (id.t == T_ERROR)                    
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t != T_RECORD)
                      yyerror(ERR_REG_TYPE);
                    else {
                      CAMP reg = obtTdR(id.ref, $3);
                      if (reg.t == T_ERROR)
                        yyerror(ERR_CAM_NOT_DEF);
                      else {
                        $$.tipo = reg.t;
                        int d = id.d + reg.d;
                        $$.desp = creaVarTemp();
                        emite(EASIG, crArgEnt(d), crArgNul(), crArgPos(niv, $$.desp)); 
                        // ¿crArgEnt(d) o crArgPos(niv, d)?
                      }
                    }
                  }
                 | ID_ OCOR_ expresion CCOR_
                  {
                    SIMB id = obtTdS($1);
                    $$.tipo = T_ERROR;
                    if (id.t == T_ERROR)                     
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t != T_ARRAY)
                      yyerror(ERR_ARR_TYPE);
                    else {
                      DIM elem = obtTdA(id.ref);
                      if ($3.tipo != T_ERROR && $3.tipo != T_ENTERO)
                        yyerror(ERR_ARR_ACC);
                      else {
                        $$.tipo = elem.telem;
                        int despRel = TALLA_TIPO_SIMPLE * $3.desp;
                        emite(EASIG, crArgEnt(despRel), crArgNul(), crArgPos(niv, $3.desp));
                        $$.desp = creaVarTemp();
                        emite(EAV, crArgPos(niv, id.d), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
                      }
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
        
constante    : CONSTANTE_ { $$.tipo = T_ENTERO; $$.desp = $1;}
             | TRUE_ { $$.tipo = T_LOGICO; $$.desp = TRUE;}
             | FALSE_ { $$.tipo = T_LOGICO; $$.desp = FALSE;}
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
        
operadorLogico   : AND_ { $$ = EMULT; }
                 | OR_  { $$ = ESUM; }
                 ;
        
operadorIgualdad   : IGUAL_ { $$ = EIGUAL; }
                   | DESIGUAL_ { $$ = EDIST; }
                   ;
        
operadorRelacional   : MAYOR_ { $$ = EMAY; }
                     | MENOR_ { $$ = EMEN; }
                     | MAYORIGUAL_ { $$ = EMAYEQ; }
                     | MENORIGUAL_ { $$ = EMENEQ; }
                     ;
        
operadorAditivo   : MAS_ { $$ = ESUM; }
                  | MENOS_ { $$ = EDIF; }
                  ;
        
operadorMultiplicativo   : MULT_ { $$ = EMULT; }
                         | DIV_ { $$ = EDIVI; }
                         ;
        
operadorUnario   : MAS_ { $$ = ESUM; }
                 | MENOS_ {$$ = EDIF; }
                 | NEGACION_ { $$ = ESIG; }
                 ;
        

%%
