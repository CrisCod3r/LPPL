/*****************************************************************************/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define FALSE 0
#define TRUE  1

#define ANDD 0
#define ORR 1
#define IGUALL 0
#define DESIGUALL 1
#define MAYORR 0
#define MENORR 1
#define MYIGUALL 2
#define MNIGUALL 3
#define MASS 0
#define MENOSS 1
#define MULTT 0
#define DIVV 1 
#define POSS 0
#define NEGG 1
#define NOTT 2

typedef struct exp {
    int tipo;
    int valor;    
} EXP;

typedef struct lc {
    int numCampos;
    int talla;
    int refe;
} LC;

typedef struct lpf {
    int refe;
    int talla;
} LPF;

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
