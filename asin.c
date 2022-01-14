/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "src/asin.y"

#include <stdio.h>
#include <string.h>
#include "libtds.h"
#include "header.h"
#include "libgci.h"

#line 78 "asin.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND_ = 258,
    OR_ = 259,
    IGUAL_ = 260,
    DESIGUAL_ = 261,
    MAYOR_ = 262,
    MAYORIGUAL_ = 263,
    MENOR_ = 264,
    MENORIGUAL_ = 265,
    MULT_ = 266,
    DIV_ = 267,
    MAS_ = 268,
    MENOS_ = 269,
    NEGACION_ = 270,
    ASIG_ = 271,
    OPAR_ = 272,
    CPAR_ = 273,
    OCOR_ = 274,
    CCOR_ = 275,
    OLLA_ = 276,
    CLLA_ = 277,
    PUNTOYCOMA_ = 278,
    PUNTO_ = 279,
    COMA_ = 280,
    STRUCT_ = 281,
    INT_ = 282,
    BOOL_ = 283,
    RETURN_ = 284,
    READ_ = 285,
    PRINT_ = 286,
    IF_ = 287,
    ELSE_ = 288,
    WHILE_ = 289,
    TRUE_ = 290,
    FALSE_ = 291,
    CONSTANTE_ = 292,
    ID_ = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "src/asin.y"

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

#line 193 "asin.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    71,    96,    97,   100,   102,   106,   112,
     124,   133,   134,   137,   147,   160,   162,   159,   177,   178,
     185,   194,   205,   205,   237,   238,   241,   242,   245,   246,
     247,   248,   249,   252,   262,   282,   299,   308,   317,   326,
     316,   338,   342,   337,   357,   358,   378,   379,   397,   398,
     416,   417,   436,   437,   453,   454,   475,   479,   480,   496,
     516,   537,   536,   568,   569,   570,   573,   574,   580,   585,
     584,   594,   595,   598,   599,   602,   603,   604,   605,   608,
     609,   612,   613,   616,   617,   618
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND_", "OR_", "IGUAL_", "DESIGUAL_",
  "MAYOR_", "MAYORIGUAL_", "MENOR_", "MENORIGUAL_", "MULT_", "DIV_",
  "MAS_", "MENOS_", "NEGACION_", "ASIG_", "OPAR_", "CPAR_", "OCOR_",
  "CCOR_", "OLLA_", "CLLA_", "PUNTOYCOMA_", "PUNTO_", "COMA_", "STRUCT_",
  "INT_", "BOOL_", "RETURN_", "READ_", "PRINT_", "IF_", "ELSE_", "WHILE_",
  "TRUE_", "FALSE_", "CONSTANTE_", "ID_", "$accept", "programa", "@1",
  "listaDeclaraciones", "declaracion", "declaracionVariable", "tipoSimple",
  "listaCampos", "declaracionFuncion", "@2", "@3", "parametrosFormales",
  "listaParametrosFormales", "bloque", "@4", "declaracionVariableLocal",
  "listaInstrucciones", "instruccion", "instruccionAsignacion",
  "instruccionEntradaSalida", "instruccionSeleccion", "@5", "@6",
  "instruccionIteracion", "@7", "@8", "expresion", "expresionIgualidad",
  "expresionRelacional", "expresionAditiva", "expresionMultiplicativa",
  "expresionUnaria", "expresionSufija", "$@9", "constante",
  "parametrosActuales", "listaParametrosActuales", "$@10",
  "operadorLogico", "operadorIgualdad", "operadorRelacional",
  "operadorAditivo", "operadorMultiplicativo", "operadorUnario", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -72,    17,    25,   -72,   -17,   -72,   -72,    25,   -72,   -72,
     -15,   -72,    54,   -72,    31,   -13,    85,    -2,   -72,    61,
      39,    46,    58,    86,    54,   -72,    81,    88,    97,    71,
     103,   -72,   -72,   -72,   -72,    98,   -72,    54,   -72,   -72,
     -72,   101,   -72,    25,   -72,    87,    37,    31,   -72,     5,
     109,   110,   111,   -72,    84,   -72,   -72,   -72,   -72,   -72,
      55,   -72,   -72,   -72,     5,   -72,   -72,   -72,    -3,     4,
     113,   107,    59,    79,   -72,   -72,   -72,     5,    91,     5,
       5,   114,     5,     5,    92,   -72,    43,   -72,     5,    94,
     -72,   -72,   102,     5,   -72,   -72,     5,   -72,   -72,   -72,
     -72,     5,   -72,   -72,     5,   -72,   -72,     5,   -72,   115,
      52,    56,     5,     6,     8,   118,   -72,     5,    45,   -72,
     -72,   113,   107,    59,    79,   -72,   112,   116,   -72,    76,
     -72,   120,     5,    -1,   119,   -72,   -72,   -72,   -72,    67,
     -72,     5,    34,   -72,   -72,   -72,    67,    41,   -72,     5,
     105,   -72,   -72,   -72,    67,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,    11,    12,     3,     4,     6,
       0,     7,     0,     5,    15,     0,     0,     0,     8,     0,
       0,     0,     0,     0,    18,    13,     0,     0,     0,     0,
       0,    19,    10,    14,     9,    20,    16,     0,    22,    21,
      17,     0,    24,    26,    25,     0,     0,     0,    26,     0,
       0,     0,     0,    41,     0,    27,    29,    31,    30,    32,
       0,    83,    84,    85,     0,    64,    65,    63,    58,     0,
      44,    46,    48,    50,    52,    54,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,    61,     0,     0,
      71,    72,     0,     0,    73,    74,     0,    75,    77,    76,
      78,     0,    79,    80,     0,    81,    82,     0,    55,     0,
       0,     0,     0,     0,     0,     0,    57,    66,     0,    59,
      23,    45,    47,    49,    51,    53,     0,     0,    38,     0,
      33,     0,     0,    68,     0,    67,    60,    36,    37,     0,
      42,     0,     0,    69,    62,    39,     0,     0,    35,     0,
       0,    43,    34,    70,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -72,   133,    99,   -11,   -72,   -72,   -72,
     -72,   -72,   104,   -72,   -72,   -72,    95,   -44,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -49,    51,    49,    47,
      42,   -71,   -72,   -72,   -72,   -72,     0,   -72,   -72,   -72,
     -72,   -72,   -72,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    10,    16,    11,    19,
      38,    30,    31,    40,    41,    43,    46,    55,    56,    57,
      58,   139,   150,    59,    81,   146,   133,    70,    71,    72,
      73,    74,    75,   117,    76,   134,   135,   149,    93,    96,
     101,   104,   107,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    15,    90,    91,    12,    22,   108,    90,    91,    90,
      91,    90,    91,    29,    87,    86,    88,     3,    61,    62,
      63,    89,    64,    14,   143,    20,    29,    92,   131,   130,
     110,   111,    45,   113,   114,    23,   125,    90,    91,   118,
      65,    66,    67,    68,    90,    91,    90,    91,    90,    91,
      17,     4,     5,     6,    18,    90,    91,   148,    48,    90,
      91,   116,    25,   129,   152,   136,    49,    50,    51,    52,
     127,    53,   102,   103,   128,    54,    48,    85,    24,    90,
      91,     5,     6,   142,    26,    50,    51,    52,    48,    53,
     105,   106,   147,    54,   140,   145,    27,    50,    51,    52,
      82,    53,   151,    83,    32,    54,    28,    21,    84,    35,
     155,    33,     5,     6,    97,    98,    99,   100,    94,    95,
      34,    36,    42,    37,   120,    47,    78,    79,    80,   109,
     115,   112,   119,   126,   132,   137,   141,   144,   154,   138,
      13,    39,    44,    60,   121,   122,   124,     0,   123,   153
};

static const yytype_int16 yycheck[] =
{
      49,    12,     3,     4,    21,    16,    77,     3,     4,     3,
       4,     3,     4,    24,    17,    64,    19,     0,    13,    14,
      15,    24,    17,    38,    25,    38,    37,    23,    20,    23,
      79,    80,    43,    82,    83,    37,   107,     3,     4,    88,
      35,    36,    37,    38,     3,     4,     3,     4,     3,     4,
      19,    26,    27,    28,    23,     3,     4,    23,    21,     3,
       4,    18,    23,   112,    23,    20,    29,    30,    31,    32,
      18,    34,    13,    14,    18,    38,    21,    22,    17,     3,
       4,    27,    28,   132,    38,    30,    31,    32,    21,    34,
      11,    12,   141,    38,    18,   139,    38,    30,    31,    32,
      16,    34,   146,    19,    23,    38,    20,    22,    24,    38,
     154,    23,    27,    28,     7,     8,     9,    10,     5,     6,
      23,    18,    21,    25,    22,    38,    17,    17,    17,    38,
      38,    17,    38,    18,    16,    23,    16,    18,    33,    23,
       7,    37,    43,    48,    93,    96,   104,    -1,   101,   149
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    41,     0,    26,    27,    28,    42,    43,    44,
      45,    47,    21,    43,    38,    45,    46,    19,    23,    48,
      38,    22,    45,    37,    17,    23,    38,    38,    20,    45,
      50,    51,    23,    23,    23,    38,    18,    25,    49,    51,
      52,    53,    21,    54,    44,    45,    55,    38,    21,    29,
      30,    31,    32,    34,    38,    56,    57,    58,    59,    62,
      55,    13,    14,    15,    17,    35,    36,    37,    38,    65,
      66,    67,    68,    69,    70,    71,    73,    82,    17,    17,
      17,    63,    16,    19,    24,    22,    65,    17,    19,    24,
       3,     4,    23,    77,     5,     6,    78,     7,     8,     9,
      10,    79,    13,    14,    80,    11,    12,    81,    70,    38,
      65,    65,    17,    65,    65,    38,    18,    72,    65,    38,
      22,    66,    67,    68,    69,    70,    18,    18,    18,    65,
      23,    20,    16,    65,    74,    75,    20,    23,    23,    60,
      18,    16,    65,    25,    18,    56,    64,    65,    23,    76,
      61,    56,    23,    75,    33,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    43,    43,    44,    44,
      44,    45,    45,    46,    46,    48,    49,    47,    50,    50,
      51,    51,    53,    52,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    57,    57,    57,    58,    58,    60,    61,
      59,    63,    64,    62,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    72,    71,    73,    73,    73,    74,    74,    75,    76,
      75,    77,    77,    78,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     6,
       6,     1,     1,     3,     4,     0,     0,     8,     0,     1,
       2,     4,     0,     8,     0,     2,     0,     2,     3,     1,
       1,     1,     1,     4,     7,     6,     5,     5,     0,     0,
       9,     0,     0,     7,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     1,     3,     1,     3,
       4,     0,     5,     1,     1,     1,     0,     1,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 71 "src/asin.y"
               {
                 niv = 0; dvar = 0; si = 0; cargaContexto(niv);
               
                 // Reserva de espacio para variables globales
                 (yyval.REF).ref1 = creaLans(si);
                 emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
                 // Salto a funcion main
                 (yyval.REF).ref2 = creaLans(si);
                 emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
               }
#line 1491 "asin.c"
    break;

  case 3:
#line 84 "src/asin.y"
               {
                 if ((yyvsp[0].cent) == 0) yyerror(ERR_NOT_MAIN);
                 else if ((yyvsp[0].cent) > 1) yyerror(ERR_MANY_MAIN);
                 else {
                   // Completa LANS para variables globales
                   completaLans((yyvsp[-1].REF).ref1, crArgEnt(dvar));
                   // Completa LANS salto a main
                   completaLans((yyvsp[-1].REF).ref2, crArgEtq(obtTdS("main").d));
                 }
               }
#line 1506 "asin.c"
    break;

  case 4:
#line 96 "src/asin.y"
                                    {(yyval.cent) = (yyvsp[0].cent);}
#line 1512 "asin.c"
    break;

  case 5:
#line 97 "src/asin.y"
                                                       {(yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent);}
#line 1518 "asin.c"
    break;

  case 6:
#line 101 "src/asin.y"
                 { (yyval.cent) = 0; }
#line 1524 "asin.c"
    break;

  case 7:
#line 103 "src/asin.y"
                 { (yyval.cent) = (yyvsp[0].cent); }
#line 1530 "asin.c"
    break;

  case 8:
#line 107 "src/asin.y"
                      {
                        if (!insTdS((yyvsp[-1].ident),VARIABLE,(yyvsp[-2].cent),niv,dvar,-1))
                          yyerror(ERR_DUP_ID_VAR);
                        else dvar += TALLA_TIPO_SIMPLE;
                      }
#line 1540 "asin.c"
    break;

  case 9:
#line 113 "src/asin.y"
                      {
                        int numelem = (yyvsp[-2].cent);
                        if ((yyvsp[-2].cent) <= 0) {
                          yyerror(ERR_ARR_SIZE);
                          numelem = 0;
                        }
                        int refe = insTdA((yyvsp[-5].cent), numelem);
                        if (!insTdS((yyvsp[-4].ident), VARIABLE,T_ARRAY,niv,dvar,refe))
                          yyerror(ERR_DUP_ID_VAR);
                        else dvar += numelem * TALLA_TIPO_SIMPLE;
                      }
#line 1556 "asin.c"
    break;

  case 10:
#line 125 "src/asin.y"
                      {
                        if (!insTdS((yyvsp[-1].ident),VARIABLE,T_RECORD,niv,dvar,(yyvsp[-3].LC).refe))
                          yyerror(ERR_DUP_ID_VAR);
                        else 
                          dvar += (yyvsp[-3].LC).talla;
                      }
#line 1567 "asin.c"
    break;

  case 11:
#line 133 "src/asin.y"
                     {(yyval.cent) = T_ENTERO;}
#line 1573 "asin.c"
    break;

  case 12:
#line 134 "src/asin.y"
                     {(yyval.cent) = T_LOGICO;}
#line 1579 "asin.c"
    break;

  case 13:
#line 138 "src/asin.y"
               {
                 int refe = insTdR(-1,(yyvsp[-1].ident),(yyvsp[-2].cent),0);
                 if (refe == -1)
                   yyerror(ERR_DUP_ID_CAM);
                 else {
                   (yyval.LC).refe = refe;
                   (yyval.LC).talla = TALLA_TIPO_SIMPLE;
                 }
               }
#line 1593 "asin.c"
    break;

  case 14:
#line 148 "src/asin.y"
               {
                 int refe = (yyvsp[-3].LC).refe;
                 if (insTdR(refe,(yyvsp[-1].ident),(yyvsp[-2].cent),(yyvsp[-3].LC).talla) == -1)
                   yyerror(ERR_DUP_ID_CAM);
                 else {
                   (yyval.LC).refe = refe;
                   (yyval.LC).talla = (yyvsp[-3].LC).talla + TALLA_TIPO_SIMPLE;
                 }
               }
#line 1607 "asin.c"
    break;

  case 15:
#line 160 "src/asin.y"
                     { niv++; cargaContexto(niv); (yyval.cent) = dvar; dvar = 0; }
#line 1613 "asin.c"
    break;

  case 16:
#line 162 "src/asin.y"
                     {
                       if (!insTdS((yyvsp[-4].ident),FUNCION,(yyvsp[-5].cent),niv-1,si,(yyvsp[-1].LPF).refe))
                         yyerror(ERR_DUP_ID_FUN);
                       if (strcmp((yyvsp[-4].ident), "main\0") == 0) (yyval.cent) = 1;
                       else (yyval.cent) = 0;
                     }
#line 1624 "asin.c"
    break;

  case 17:
#line 169 "src/asin.y"
                     {
                       if (verTdS) mostrarTdS();
                    
                       descargaContexto(niv); 
                       niv--; dvar = (yyvsp[-5].cent); (yyval.cent) = (yyvsp[-1].cent); 
                     }
#line 1635 "asin.c"
    break;

  case 18:
#line 177 "src/asin.y"
                                    { (yyval.LPF).refe = insTdD(-1,T_VACIO); (yyval.LPF).talla = 0; }
#line 1641 "asin.c"
    break;

  case 19:
#line 179 "src/asin.y"
                     {
                       (yyval.LPF).refe = (yyvsp[0].LPF).refe;
                       (yyval.LPF).talla = (yyvsp[0].LPF).talla - TALLA_SEGENLACES;
                     }
#line 1650 "asin.c"
    break;

  case 20:
#line 186 "src/asin.y"
                         {
                           int refe = insTdD(-1, (yyvsp[-1].cent));
                           (yyval.LPF).refe = refe;
                           int talla = TALLA_TIPO_SIMPLE + TALLA_SEGENLACES;
                           (yyval.LPF).talla = talla;
                           if (!insTdS((yyvsp[0].ident),PARAMETRO,(yyvsp[-1].cent),niv,-talla,refe))
                             yyerror(ERR_DUP_ID_PAR);
                         }
#line 1663 "asin.c"
    break;

  case 21:
#line 195 "src/asin.y"
                         {
                           int refe = insTdD((yyvsp[0].LPF).refe,(yyvsp[-3].cent));
                           (yyval.LPF).refe = refe;
                           int talla = (yyvsp[0].LPF).talla + TALLA_TIPO_SIMPLE;
                           (yyval.LPF).talla = talla;
                           if (!insTdS((yyvsp[-2].ident),PARAMETRO,(yyvsp[-3].cent),niv,-talla,refe))
                             yyerror(ERR_DUP_ID_PAR);
                         }
#line 1676 "asin.c"
    break;

  case 22:
#line 205 "src/asin.y"
            { 
             // Carga de los enlaces de control
             emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
             emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
             // Reserva espacio para las variables locales y temporales
             (yyval.REF).ref1 = creaLans(si);
             emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
           }
#line 1689 "asin.c"
    break;

  case 23:
#line 214 "src/asin.y"
           {
             INF fun = obtTdD(-1);
             if (fun.tipo == T_ERROR ) 
               yyerror(ERR_FUN_NOT_COM); // Al dar error la TdS, no se inserta en esta y por tanto no esta compilada
             else if ((yyvsp[-2].EXP).tipo != T_ERROR && fun.tipo != (yyvsp[-2].EXP).tipo)
               yyerror(ERR_RET_TYPE);
               
             // Completa la reserva de espacio para las variables locales y temporales
             completaLans((yyvsp[-7].REF).ref1, crArgEnt(dvar));
             // Guardar el valor de retorno
             int dret; // desplazamiento del valor de retorno en el RA
             dret = TALLA_SEGENLACES + fun.tsp + TALLA_TIPO_SIMPLE;
             emite(EASIG, crArgPos(niv, (yyvsp[-2].EXP).desp), crArgNul(), crArgPos(niv, -dret));
             // Libera el segmento de variables locales y temporales
             emite(TOPFP, crArgNul(), crArgNul(), crArgNul());
             // Descarga de los enlaces de control
             emite(FPPOP, crArgNul(), crArgNul(), crArgNul());
             // Emite FIN si es "main" y RETURN si no
             if (strcmp(fun.nom, "main") == 0) emite(FIN, crArgNul(), crArgNul(), crArgNul());
             else emite(RET, crArgNul(), crArgNul(), crArgNul());
           }
#line 1715 "asin.c"
    break;

  case 33:
#line 253 "src/asin.y"
                         {                            
                           SIMB id = obtTdS((yyvsp[-3].ident));
                           if (id.t == T_ERROR) 
                             yyerror(ERR_VAR_NOT_DEF);
                           else if ((yyvsp[-1].EXP).tipo != T_ERROR && id.t != (yyvsp[-1].EXP).tipo)
                             yyerror(ERR_ASIG);
                           else 
                             emite(EASIG, crArgPos(niv, (yyvsp[-1].EXP).desp), crArgNul(), crArgPos(id.n, id.d));
                         }
#line 1729 "asin.c"
    break;

  case 34:
#line 263 "src/asin.y"
                         {
                           SIMB id = obtTdS((yyvsp[-6].ident));
                           if (id.t == T_ERROR)
                             yyerror(ERR_VAR_NOT_DEF);
                           else if (id.t != T_ARRAY)
                             yyerror(ERR_ASIG);
                           else {
                             DIM dim = obtTdA(id.ref);
                             if ((yyvsp[-4].EXP).tipo != T_ERROR && (yyvsp[-4].EXP).tipo != T_ENTERO)
                               yyerror(ERR_ARR_ACC);
                             else if ((yyvsp[-1].EXP).tipo != T_ERROR && (yyvsp[-1].EXP).tipo != dim.telem)
                               yyerror(ERR_ASIG);
                             else {
                               emite(EMULT, crArgPos(niv, (yyvsp[-4].EXP).desp), crArgEnt(TALLA_TIPO_SIMPLE), crArgPos(niv, (yyvsp[-4].EXP).desp));
                               emite(EVA, crArgPos(id.n, id.d), crArgPos(niv, (yyvsp[-4].EXP).desp), crArgPos(niv, (yyvsp[-1].EXP).desp));
                             }
                            
                           }
                         }
#line 1753 "asin.c"
    break;

  case 35:
#line 283 "src/asin.y"
                         {
                           SIMB id = obtTdS((yyvsp[-5].ident));
                           CAMP reg = obtTdR(id.ref, (yyvsp[-3].ident));
                           if (id.t == T_ERROR)
                             yyerror(ERR_VAR_NOT_DEF);
                           else if (id.t != T_RECORD)
                             yyerror(ERR_ASIG);
                           else if ((yyvsp[-1].EXP).tipo != T_ERROR && (yyvsp[-1].EXP).tipo != reg.t)
                             yyerror(ERR_ASIG);
                           else {
                             int d = id.d + reg.d;
                             emite(EASIG, crArgPos(niv, (yyvsp[-1].EXP).desp), crArgNul(), crArgPos(id.n, d));
                           }
                         }
#line 1772 "asin.c"
    break;

  case 36:
#line 300 "src/asin.y"
                           {
                             SIMB id = obtTdS((yyvsp[-2].ident));
                             if (id.t == T_ERROR) 
                               yyerror(ERR_VAR_NOT_DEF);
                             else if (id.t != T_ENTERO) 
                               yyerror(ERR_READ);
                             emite(EREAD, crArgNul(), crArgNul(), crArgPos(id.n, id.d));
                           }
#line 1785 "asin.c"
    break;

  case 37:
#line 309 "src/asin.y"
                           {
                             if ((yyvsp[-2].EXP).tipo != T_ERROR && (yyvsp[-2].EXP).tipo != T_ENTERO)
                               yyerror(ERR_PRINT);
                             emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[-2].EXP).desp));
                           }
#line 1795 "asin.c"
    break;

  case 38:
#line 317 "src/asin.y"
                        {
                          if ((yyvsp[-1].EXP).tipo != T_ERROR && (yyvsp[-1].EXP).tipo != T_LOGICO) 
                            yyerror(ERR_IF);
                          else {
                            (yyval.cent) = creaLans(si);
                            emite(EIGUAL, crArgPos(niv, (yyvsp[-1].EXP).desp), crArgEnt(0), crArgEtq(-1));
                          }
                        }
#line 1808 "asin.c"
    break;

  case 39:
#line 326 "src/asin.y"
                        {
                          (yyval.cent) = creaLans(si);
                          emite(GOTOS,crArgNul(), crArgNul(), crArgEtq(-1));
                          completaLans((yyvsp[-1].cent), crArgEtq(si));
                        }
#line 1818 "asin.c"
    break;

  case 40:
#line 332 "src/asin.y"
                        {
                          completaLans((yyvsp[-2].cent), crArgEtq(si));
                        }
#line 1826 "asin.c"
    break;

  case 41:
#line 338 "src/asin.y"
                        {
                          (yyval.cent) = si;
                        }
#line 1834 "asin.c"
    break;

  case 42:
#line 342 "src/asin.y"
                        {
                          if ((yyvsp[-1].EXP).tipo != T_ERROR && (yyvsp[-1].EXP).tipo != T_LOGICO) 
                            yyerror(ERR_WHILE);
                          else {
                            (yyval.cent) = creaLans(si);
                            emite(EIGUAL, crArgPos(niv, (yyvsp[-1].EXP).desp), crArgEnt(0), crArgEtq(-1));
                          }
                        }
#line 1847 "asin.c"
    break;

  case 43:
#line 351 "src/asin.y"
                        {
                          emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-5].cent)));
                          completaLans((yyvsp[-1].cent), crArgEtq(si));
                        }
#line 1856 "asin.c"
    break;

  case 44:
#line 357 "src/asin.y"
                                   { (yyval.EXP) = (yyvsp[0].EXP); }
#line 1862 "asin.c"
    break;

  case 45:
#line 359 "src/asin.y"
               {
                 if ((yyvsp[-2].EXP).tipo == T_ERROR || (yyvsp[0].EXP).tipo == T_ERROR)
                   (yyval.EXP).tipo = T_ERROR;
                 else if ((yyvsp[-2].EXP).tipo == (yyvsp[0].EXP).tipo && (yyvsp[-2].EXP).tipo == T_LOGICO) {
                   (yyval.EXP).tipo = T_LOGICO;
                   (yyval.EXP).desp = creaVarTemp();
                   emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].EXP).desp), crArgPos(niv, (yyvsp[0].EXP).desp), crArgPos(niv, (yyval.EXP).desp));
                   if ((yyvsp[-1].cent) == ESUM) { // OR
                    emite(EMENEQ, crArgPos(niv, (yyval.EXP).desp), crArgEnt(1), crArgEtq(si + 2));
                    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                   }
                 }
                 else {
                   (yyval.EXP).tipo = T_ERROR;
                   yyerror(ERR_EXP_LOG);
                 }
               }
#line 1884 "asin.c"
    break;

  case 46:
#line 378 "src/asin.y"
                                          { (yyval.EXP) = (yyvsp[0].EXP); }
#line 1890 "asin.c"
    break;

  case 47:
#line 380 "src/asin.y"
                     {
                       if ((yyvsp[-2].EXP).tipo == T_ERROR || (yyvsp[0].EXP).tipo == T_ERROR)
                         (yyval.EXP).tipo = T_ERROR;
                       else if ((yyvsp[-2].EXP).tipo == (yyvsp[0].EXP).tipo) {
                         (yyval.EXP).tipo = T_LOGICO;
                         (yyval.EXP).desp = creaVarTemp();
                         emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                         emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].EXP).desp), crArgPos(niv, (yyvsp[0].EXP).desp), crArgEtq(si + 2));
                         emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                       }
                       else {
                         (yyval.EXP).tipo = T_ERROR;
                         yyerror(ERR_EXP_IGU);
                       }                         
                     }
#line 1910 "asin.c"
    break;

  case 48:
#line 397 "src/asin.y"
                                        { (yyval.EXP) = (yyvsp[0].EXP); }
#line 1916 "asin.c"
    break;

  case 49:
#line 399 "src/asin.y"
                      {
                        if ((yyvsp[-2].EXP).tipo == T_ERROR || (yyvsp[0].EXP).tipo == T_ERROR)
                          (yyval.EXP).tipo = T_ERROR;
                        else if ((yyvsp[-2].EXP).tipo == (yyvsp[0].EXP).tipo && (yyvsp[-2].EXP).tipo == T_ENTERO) {
                          (yyval.EXP).tipo = T_LOGICO;
                          (yyval.EXP).desp = creaVarTemp();
                          emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                          emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].EXP).desp), crArgPos(niv, (yyvsp[0].EXP).desp), crArgEtq(si+2));
                          emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                        }
                        else {
                          (yyval.EXP).tipo = T_ERROR;
                          yyerror(ERR_EXP_REL);
                        }
                      }
#line 1936 "asin.c"
    break;

  case 50:
#line 416 "src/asin.y"
                                            { (yyval.EXP) = (yyvsp[0].EXP); }
#line 1942 "asin.c"
    break;

  case 51:
#line 418 "src/asin.y"
                   {
                     if ((yyvsp[-2].EXP).tipo == T_ERROR || (yyvsp[0].EXP).tipo == T_ERROR)
                       (yyval.EXP).tipo = T_ERROR;
                     else if ((yyvsp[-2].EXP).tipo == (yyvsp[0].EXP).tipo && (yyvsp[-2].EXP).tipo == T_ENTERO) {
                       (yyval.EXP).tipo = T_ENTERO;
                       
                       // ¿Dentro o fuera del else?
                       
                       (yyval.EXP).desp = creaVarTemp();
                       emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].EXP).desp), crArgPos(niv, (yyvsp[0].EXP).desp), crArgPos(niv, (yyval.EXP).desp));
                     }
                     else {
                       (yyval.EXP).tipo = T_ERROR;
                       yyerror(ERR_EXP_ADI);
                     }
                   }
#line 1963 "asin.c"
    break;

  case 52:
#line 436 "src/asin.y"
                                           { (yyval.EXP) = (yyvsp[0].EXP); }
#line 1969 "asin.c"
    break;

  case 53:
#line 438 "src/asin.y"
                          {
                            if ((yyvsp[-2].EXP).tipo == T_ERROR || (yyvsp[0].EXP).tipo == T_ERROR)
                              (yyval.EXP).tipo = T_ERROR;
                            else if ((yyvsp[-2].EXP).tipo == (yyvsp[0].EXP).tipo && (yyvsp[-2].EXP).tipo == T_ENTERO) {
                              (yyval.EXP).tipo = T_ENTERO;
                              (yyval.EXP).desp = creaVarTemp();
                              emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].EXP).desp), crArgPos(niv, (yyvsp[0].EXP).desp), crArgPos(niv, (yyval.EXP).desp));
                            }
                            else {
                              (yyval.EXP).tipo = T_ERROR;
                              yyerror(ERR_EXP_MUL);
                            }
                          }
#line 1987 "asin.c"
    break;

  case 54:
#line 453 "src/asin.y"
                                   { (yyval.EXP) = (yyvsp[0].EXP); }
#line 1993 "asin.c"
    break;

  case 55:
#line 455 "src/asin.y"
                  {
                    if ((yyvsp[0].EXP).tipo == T_ERROR)
                      (yyval.EXP) = (yyvsp[0].EXP);
                    else if ((yyvsp[0].EXP).tipo == T_LOGICO && (yyvsp[-1].cent) == ESIG) {
                      (yyval.EXP).tipo = T_LOGICO;
                      (yyval.EXP).desp = creaVarTemp();
                      emite(EDIF, crArgEnt(1), crArgPos(niv, (yyvsp[0].EXP).desp), crArgPos(niv, (yyval.EXP).desp));
                    }
                    else if ((yyvsp[0].EXP).tipo == T_ENTERO && (yyvsp[-1].cent) != ESIG) {
                      (yyval.EXP).tipo = T_ENTERO;
                      (yyval.EXP).desp = creaVarTemp();
                      emite((yyvsp[-1].cent), crArgEnt(0), crArgPos(niv, (yyvsp[0].EXP).desp), crArgPos(niv, (yyval.EXP).desp));
                    }
                    else {
                      (yyval.EXP).tipo = T_ERROR;
                      yyerror(ERR_EXP_UN);
                    }
                  }
#line 2016 "asin.c"
    break;

  case 56:
#line 475 "src/asin.y"
                             { (yyval.EXP).tipo = (yyvsp[0].EXP).tipo; 
                        (yyval.EXP).desp = creaVarTemp();
                        emite(EASIG, crArgEnt((yyvsp[0].EXP).desp), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                  }
#line 2025 "asin.c"
    break;

  case 57:
#line 479 "src/asin.y"
                                         { (yyval.EXP) = (yyvsp[-1].EXP); }
#line 2031 "asin.c"
    break;

  case 58:
#line 481 "src/asin.y"
                  {
                    SIMB id = obtTdS((yyvsp[0].ident));
                    (yyval.EXP).tipo = T_ERROR;
                    if (id.t == T_ERROR)
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t == T_ARRAY)
                      yyerror(ERR_ARR_NOT_IND);
                    else if (id.t == T_RECORD)
                      yyerror(ERR_REG_NOT_CAM);
                    else {
                      (yyval.EXP).tipo = id.t;
                      (yyval.EXP).desp = creaVarTemp();
                      emite(EASIG, crArgPos(id.n, id.d), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                    }
                  }
#line 2051 "asin.c"
    break;

  case 59:
#line 497 "src/asin.y"
                  {
                    SIMB id = obtTdS((yyvsp[-2].ident));
                    (yyval.EXP).tipo = T_ERROR;
                    if (id.t == T_ERROR)                    
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t != T_RECORD)
                      yyerror(ERR_REG_TYPE);
                    else {
                      CAMP reg = obtTdR(id.ref, (yyvsp[0].ident));
                      if (reg.t == T_ERROR)
                        yyerror(ERR_CAM_NOT_DEF);
                      else {
                        (yyval.EXP).tipo = reg.t;
                        int d = id.d + reg.d;
                        (yyval.EXP).desp = creaVarTemp();
                        emite(EASIG, crArgPos(id.n, d), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                      }
                    }
                  }
#line 2075 "asin.c"
    break;

  case 60:
#line 517 "src/asin.y"
                  {
                    SIMB id = obtTdS((yyvsp[-3].ident));
                    (yyval.EXP).tipo = T_ERROR;
                    if (id.t == T_ERROR)                     
                      yyerror(ERR_VAR_NOT_DEF);
                    else if (id.t != T_ARRAY)
                      yyerror(ERR_ARR_TYPE);
                    else {
                      DIM elem = obtTdA(id.ref);
                      if ((yyvsp[-1].EXP).tipo != T_ERROR && (yyvsp[-1].EXP).tipo != T_ENTERO)
                        yyerror(ERR_ARR_ACC);
                      else {
                        (yyval.EXP).tipo = elem.telem;
                        emite(EMULT, crArgPos(niv, (yyvsp[-1].EXP).desp), crArgEnt(TALLA_TIPO_SIMPLE), crArgPos(niv, (yyvsp[-1].EXP).desp));
                        (yyval.EXP).desp = creaVarTemp();
                        emite(EAV, crArgPos(id.n, id.d), crArgPos(niv, (yyvsp[-1].EXP).desp), crArgPos(niv, (yyval.EXP).desp));
                      }
                    }
                  }
#line 2099 "asin.c"
    break;

  case 61:
#line 537 "src/asin.y"
                   {
                     // Reserva espacio para el valor de retorno
                     emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_TIPO_SIMPLE));
                   }
#line 2108 "asin.c"
    break;

  case 62:
#line 542 "src/asin.y"
                   {
                     SIMB id = obtTdS((yyvsp[-4].ident));
                     (yyval.EXP).tipo = T_ERROR;
                     if (id.t == T_ERROR) {
                       yyerror(ERR_VAR_NOT_DEF);
                     }
                     else {
                       INF func = obtTdD(id.ref);
                       if (func.tipo == T_ERROR)
                         yyerror(ERR_FUN_TYPE);
                       else if (!cmpDom(id.ref, (yyvsp[-1].cent)))
                         yyerror(ERR_FUN_PAR);
                       else {
                         (yyval.EXP).tipo = func.tipo; // Inseguro de mi mismo
                         (yyval.EXP).desp = creaVarTemp();
                         // Llamada a la funcion (Ya incluye push)
                         emite(CALL, crArgNul(), crArgNul(), crArgEtq(id.d));
                         // Desapila el segmento de parametros
                         emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(func.tsp));
                         // Desapila y asigna el valor de retorno
                         emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, (yyval.EXP).desp));
                       }
                     }
                   }
#line 2137 "asin.c"
    break;

  case 63:
#line 568 "src/asin.y"
                          { (yyval.EXP).tipo = T_ENTERO; (yyval.EXP).desp = (yyvsp[0].cent);}
#line 2143 "asin.c"
    break;

  case 64:
#line 569 "src/asin.y"
                     { (yyval.EXP).tipo = T_LOGICO; (yyval.EXP).desp = TRUE;}
#line 2149 "asin.c"
    break;

  case 65:
#line 570 "src/asin.y"
                      { (yyval.EXP).tipo = T_LOGICO; (yyval.EXP).desp = FALSE;}
#line 2155 "asin.c"
    break;

  case 66:
#line 573 "src/asin.y"
                                  { insTdD(-1, T_VACIO); }
#line 2161 "asin.c"
    break;

  case 67:
#line 575 "src/asin.y"
                     {
                       (yyval.cent) = (yyvsp[0].cent);
                     }
#line 2169 "asin.c"
    break;

  case 68:
#line 580 "src/asin.y"
                                    { 
                            (yyval.cent) = insTdD(-1, (yyvsp[0].EXP).tipo); 
                            emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[0].EXP).desp));
                          }
#line 2178 "asin.c"
    break;

  case 69:
#line 585 "src/asin.y"
                          {
                            emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[-1].EXP).desp));
                          }
#line 2186 "asin.c"
    break;

  case 70:
#line 589 "src/asin.y"
                          {
                            (yyval.cent) = insTdD((yyvsp[0].cent), (yyvsp[-3].EXP).tipo);
                          }
#line 2194 "asin.c"
    break;

  case 71:
#line 594 "src/asin.y"
                        { (yyval.cent) = EMULT; }
#line 2200 "asin.c"
    break;

  case 72:
#line 595 "src/asin.y"
                        { (yyval.cent) = ESUM; }
#line 2206 "asin.c"
    break;

  case 73:
#line 598 "src/asin.y"
                            { (yyval.cent) = EIGUAL; }
#line 2212 "asin.c"
    break;

  case 74:
#line 599 "src/asin.y"
                               { (yyval.cent) = EDIST; }
#line 2218 "asin.c"
    break;

  case 75:
#line 602 "src/asin.y"
                              { (yyval.cent) = EMAY; }
#line 2224 "asin.c"
    break;

  case 76:
#line 603 "src/asin.y"
                              { (yyval.cent) = EMEN; }
#line 2230 "asin.c"
    break;

  case 77:
#line 604 "src/asin.y"
                                   { (yyval.cent) = EMAYEQ; }
#line 2236 "asin.c"
    break;

  case 78:
#line 605 "src/asin.y"
                                   { (yyval.cent) = EMENEQ; }
#line 2242 "asin.c"
    break;

  case 79:
#line 608 "src/asin.y"
                         { (yyval.cent) = ESUM; }
#line 2248 "asin.c"
    break;

  case 80:
#line 609 "src/asin.y"
                           { (yyval.cent) = EDIF; }
#line 2254 "asin.c"
    break;

  case 81:
#line 612 "src/asin.y"
                                 { (yyval.cent) = EMULT; }
#line 2260 "asin.c"
    break;

  case 82:
#line 613 "src/asin.y"
                                { (yyval.cent) = EDIVI; }
#line 2266 "asin.c"
    break;

  case 83:
#line 616 "src/asin.y"
                        { (yyval.cent) = ESUM; }
#line 2272 "asin.c"
    break;

  case 84:
#line 617 "src/asin.y"
                          {(yyval.cent) = EDIF; }
#line 2278 "asin.c"
    break;

  case 85:
#line 618 "src/asin.y"
                             { (yyval.cent) = ESIG; }
#line 2284 "asin.c"
    break;


#line 2288 "asin.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 622 "src/asin.y"

