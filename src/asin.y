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
    
    struct {
        int ref1;
        int ref2;
    } REF;
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

programa     : {
                 niv = 0; dvar = 0; si = 0; cargaContexto(niv);
               
                 // Reserva de espacio para variables globales
                 $<REF>$.ref1 = creaLans(si);
                 emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
                 // Salto a funcion main
                 $<REF>$.ref2 = creaLans(si);
                 emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
               }
               
               listaDeclaraciones
               
               {
                 if ($2 == 0) yyerror(ERR_NOT_MAIN);
                 else if ($2 > 1) yyerror(ERR_MANY_MAIN);
                 else {
                   // Completa LANS para variables globales
                   completaLans($<REF>1.ref1, crArgEnt(dvar));
                   // Completa LANS salto a main
                   completaLans($<REF>1.ref2, crArgEtq(obtTdS("main").d));
                 }
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
                       if (!insTdS($2,FUNCION,$1,niv-1,si,$5.refe))
                         yyerror(ERR_DUP_ID_FUN);
                       if (strcmp($2, "main\0") == 0) $<cent>$ = 1;
                       else $<cent>$ = 0;
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
        
bloque    : { 
             // Carga de los enlaces de control
             emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
             emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
             // Reserva espacio para las variables locales y temporales
             $<REF>$.ref1 = creaLans(si);
             emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
           }
           OLLA_ declaracionVariableLocal listaInstrucciones RETURN_  expresion PUNTOYCOMA_ CLLA_
           {
             INF fun = obtTdD(-1);
             if (fun.tipo == T_ERROR ) 
               yyerror(ERR_FUN_NOT_COM); // Al dar error la TdS, no se inserta en esta y por tanto no esta compilada
             else if ($6.tipo != T_ERROR && fun.tipo != $6.tipo)
               yyerror(ERR_RET_TYPE);
               
             // Completa la reserva de espacio para las variables locales y temporales
             completaLans($<REF>1.ref1, crArgEnt(dvar));
             // Guardar el valor de retorno
             int dret; // desplazamiento del valor de retorno en el RA
             dret = TALLA_SEGENLACES + fun.tsp + TALLA_TIPO_SIMPLE;
             emite(EASIG, crArgPos(niv, $6.desp), crArgNul(), crArgPos(niv, -dret));
             // Libera el segmento de variables locales y temporales
             emite(TOPFP, crArgNul(), crArgNul(), crArgNul());
             // Descarga de los enlaces de control
             emite(FPPOP, crArgNul(), crArgNul(), crArgNul());
             // Emite FIN si es "main" y RETURN si no
             if (strcmp(fun.nom, "main") == 0) emite(FIN, crArgNul(), crArgNul(), crArgNul());
             else emite(RET, crArgNul(), crArgNul(), crArgNul());
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
                           else if ($3.tipo != T_ERROR && id.t != $3.tipo)
                             yyerror(ERR_ASIG);
                           else 
                             emite(EASIG, crArgPos(niv, $3.desp), crArgNul(), crArgPos(id.n, id.d));
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
                             if ($3.tipo != T_ERROR && $3.tipo != T_ENTERO)
                               yyerror(ERR_ARR_ACC);
                             else if ($6.tipo != T_ERROR && $6.tipo != dim.telem)
                               yyerror(ERR_ASIG);
                             else {
                               emite(EMULT, crArgPos(niv, $3.desp), crArgEnt(TALLA_TIPO_SIMPLE), crArgPos(niv, $3.desp));
                               emite(EVA, crArgPos(id.n, id.d), crArgPos(niv, $3.desp), crArgPos(niv, $6.desp));
                             }
                            
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
                           else if ($5.tipo != T_ERROR && $5.tipo != reg.t)
                             yyerror(ERR_ASIG);
                           else {
                             int d = id.d + reg.d;
                             emite(EASIG, crArgPos(niv, $5.desp), crArgNul(), crArgPos(id.n, d));
                           }
                         }
                        ;
        
instruccionEntradaSalida  : READ_ OPAR_ ID_ CPAR_ PUNTOYCOMA_
                           {
                             SIMB id = obtTdS($3);
                             if (id.t == T_ERROR) 
                               yyerror(ERR_VAR_NOT_DEF);
                             else if (id.t != T_ENTERO) 
                               yyerror(ERR_READ);
                             emite(EREAD, crArgNul(), crArgNul(), crArgPos(id.n, id.d));
                           }
                          | PRINT_ OPAR_ expresion CPAR_ PUNTOYCOMA_
                           {
                             if ($3.tipo != T_ERROR && $3.tipo != T_ENTERO)
                               yyerror(ERR_PRINT);
                             emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, $3.desp));
                           }
                          ;
        
instruccionSeleccion   : IF_ OPAR_ expresion CPAR_ 
                        {
                          if ($3.tipo != T_ERROR && $3.tipo != T_LOGICO) 
                            yyerror(ERR_IF);
                          else {
                            $<cent>$ = creaLans(si);
                            emite(EIGUAL, crArgPos(niv, $3.desp), crArgEnt(0), crArgEtq(-1));
                          }
                        }
                         instruccion
                        {
                          $<cent>$ = creaLans(si);
                          emite(GOTOS,crArgNul(), crArgNul(), crArgEtq(-1));
                          completaLans($<cent>5, crArgEtq(si));
                        }
                         ELSE_ instruccion
                        {
                          completaLans($<cent>7, crArgEtq(si));
                        }
                       ;
        
instruccionIteracion   : WHILE_ 
                        {
                          $<cent>$ = si;
                        }
                         OPAR_ expresion CPAR_ 
                        {
                          if ($4.tipo != T_ERROR && $4.tipo != T_LOGICO) 
                            yyerror(ERR_WHILE);
                          else {
                            $<cent>$ = creaLans(si);
                            emite(EIGUAL, crArgPos(niv, $4.desp), crArgEnt(0), crArgEtq(-1));
                          }
                        }
                         instruccion
                        {
                          emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cent>2));
                          completaLans($<cent>6, crArgEtq(si));
                        }
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
                    emite(EMENEQ, crArgPos(niv, $$.desp), crArgEnt(1), crArgEtq(si + 2));
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
                         emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgEtq(si + 2));
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
                          emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgEtq(si+2));
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
                       $$.desp = creaVarTemp();
                       emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
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
        
expresionSufija  : constante { $$.tipo = $1.tipo; 
                        $$.desp = creaVarTemp();
                        emite(EASIG, crArgEnt($1.desp), crArgNul(), crArgPos(niv, $$.desp));
                  }
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
                      emite(EASIG, crArgPos(id.n, id.d), crArgNul(), crArgPos(niv, $$.desp));
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
                        emite(EASIG, crArgPos(id.n, d), crArgNul(), crArgPos(niv, $$.desp));
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
                        emite(EMULT, crArgPos(niv, $3.desp), crArgEnt(TALLA_TIPO_SIMPLE), crArgPos(niv, $3.desp));
                        $$.desp = creaVarTemp();
                        emite(EAV, crArgPos(id.n, id.d), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
                      }
                    }
                  }
                 | ID_ OPAR_ 
                   {
                     // Reserva espacio para el valor de retorno
                     emite(EPUSH, crArgNul(), crArgNul(), crArgEnt(0));
                   }
                   parametrosActuales CPAR_
                   {
                     SIMB id = obtTdS($1);
                     $$.tipo = T_ERROR;
                     if (id.t == T_ERROR) {
                       yyerror(ERR_VAR_NOT_DEF);
                     }
                     else {
                       INF func = obtTdD(id.ref);
                       if (func.tipo == T_ERROR)
                         yyerror(ERR_FUN_TYPE);
                       else if (!cmpDom(id.ref, $4))
                         yyerror(ERR_FUN_PAR);
                       else {
                         $$.tipo = func.tipo; // Inseguro de mi mismo
                         $$.desp = creaVarTemp();
                         // Llamada a la funcion (Ya incluye push)
                         emite(CALL, crArgNul(), crArgNul(), crArgEtq(id.d));
                         // Desapila el segmento de parametros
                         emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(func.tsp));
                         // Desapila y asigna el valor de retorno
                         emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, $$.desp));
                       }
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
        
listaParametrosActuales : expresion { 
                            $$ = insTdD(-1, $1.tipo); 
                            emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.desp));
                          }
                        | expresion COMA_ 
                          {
                            emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.desp));
                          }
                          listaParametrosActuales
                          {
                            $$ = insTdD($4, $1.tipo);
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
