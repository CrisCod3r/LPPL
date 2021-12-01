/*****************************************************************************/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define FALSE 0
#define TRUE  1

/***************************************************** Codigos de operadores */
#define ANDD 0
#define ORR  1

#define IGUALL    0
#define DESIGUALL 1

#define MAYORR   0
#define MENORR   1
#define MYIGUALL 2
#define MNIGUALL 3

#define MASS   0
#define MENOSS 1

#define MULTT 0
#define DIVV  1 

#define POSS 0
#define NEGG 1
#define NOTT 2

/********************************************************* Errores generales */
#define ERR_NOT_MAIN    "Funcion main no definida"
#define ERR_MANY_MAIN   "Mas de una funcion main definida"

#define ERR_DUP_ID_VAR  "Identificador de variable ya definido"
#define ERR_DUP_ID_CAM  "Identificador de campo ya definido"
#define ERR_DUP_ID_FUN  "Identificador de funcion ya definido"
#define ERR_DUP_ID_PAR  "Identificador de parametro ya definido"

#define ERR_ARR_TYPE    "Varible no es tipo ARRAY"
#define ERR_ARR_SIZE    "Talla inapropiada del array"
#define ERR_ARR_ACC     "Expresion de acceso a array no valida"
#define ERR_ARR_NOT_IND "Acceso a array sin indice"

#define ERR_REG_TYPE    "Variable no es tipo STRUCT"
#define ERR_REG_NOT_CAM "Acceso a registro sin campo"

#define ERR_CAM_NOT_DEF "Acceso a campo no definido"

#define ERR_FUN_TYPE    "Variable no es tipo FUNCION"
#define ERR_FUN_NOT_COM "Funcion no compilada"
#define ERR_FUN_PAR     "Tipos de parametros de funcion no validos"

#define ERR_RET_TYPE    "Tipo del valor retornado no valido"
#define ERR_VAR_NOT_DEF "Variable no definida"

#define ERR_ASIG        "Error de tipos en la instruccion de asignacion"
#define ERR_READ        "Variable de lectura no es tipo entero"
#define ERR_PRINT       "Expresion a imprimir no es tipo entero"
#define ERR_IF          "Condicion del if no es tipo logico"
#define ERR_WHILE       "Condicion del while no es tipo logico"

#define ERR_EXP_LOG     "Error en \"expresion logica\""
#define ERR_EXP_IGU     "Error en \"expresion de igualdad\""
#define ERR_EXP_REL     "Error en \"expresion relacional\""
#define ERR_EXP_ADI     "Error en \"expresion aditiva\""
#define ERR_EXP_MUL     "Error en \"expresion multiplicativa\""
#define ERR_EXP_UN      "Error en \"expresion unaria\""

/***************************************************** Constantes simbolicas */
#define TALLA_TIPO_SIMPLE 1      /* Talla asociada a los tipos simples       */
#define TALLA_SEGENLACES  2      /* Talla del segmento de Enlaces de Control */

/************************ Variables externas definidas en Programa Principal */
extern int verTdS;                      /* Flag para saber si mostrar la TdS */

/***************************** Variables externas definidas en las librerıas */
extern int dvar;               /* Desplazamiento en el Segmento de Variables */
extern int niv;                /* Nivel de anidamiento "global" o "local"    */

/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();

extern FILE *yyin;
extern int   yylineno;

/********************************* Funciones y variables externas auxiliares */
extern int verbosidad;                   /* Flag si se desea una traza       */

extern void yyerror(const char * msg) ;      /* Tratamiento de errores       */

#endif  /* _HEADER_H */
/*****************************************************************************/
/*****************************************************************************/
