
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "../src/tpINT.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../src/funcionesDeListas.c"
#define YYDEBUG1

int flag_error=0;

extern int lineno;
extern FILE* yyin;


struct listaDeVariables *TSVar;
struct listaDeFunciones *TSFunc;
struct listaDeVariables unaVar;
struct listaDeFunciones unaFunc;
struct listaDeVariables *listaAux;
struct listaDeFunciones fInvocada;
struct listaDeVariables parInvocada;
struct parametrosAlInvocar *misParametros;

int yylex();
int yywrap(){
	return(1);
}

void yyerror (char const *s){
  fprintf(stderr, " ERROR SINTACTICO encontrado %s\n", s);
}



/* Line 189 of yacc.c  */
#line 108 "tpINT.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     IDENTIFICADOR = 259,
     TIPO_DATO = 260,
     PALABRA_RESERVADA = 261,
     STRING = 262,
     CCARACTER = 263,
     CONSTANTE_REAL = 264,
     MAYORIGUAL = 265,
     MENORIGUAL = 266,
     IGUALIGUAL = 267,
     DISTINTO = 268,
     INCREMENTO = 269,
     DECREMENTO = 270,
     FLECHA = 271,
     OR = 272,
     AND = 273,
     MASIGUAL = 274,
     SIZEOF = 275,
     IF = 276,
     ELSE = 277,
     SWITCH = 278,
     WHILE = 279,
     DO = 280,
     CONTINUE = 281,
     BREAK = 282,
     RETURN = 283,
     FOR = 284,
     GOTO = 285,
     Funcion = 286
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 36 "../src/tpINT.y"

        struct yylval_struct
  {
        char cadena[50];
        int entero;
        int tipo;
        char caracter;
        float real;      
        }miestructura;



/* Line 214 of yacc.c  */
#line 188 "tpINT.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 200 "tpINT.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,    40,    43,     2,
      41,    42,    38,    33,    48,    37,    47,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
      35,    34,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    21,
      23,    27,    31,    33,    35,    37,    39,    41,    43,    45,
      47,    49,    51,    53,    55,    57,    59,    62,    65,    68,
      71,    76,    78,    80,    82,    84,    89,    94,    98,   102,
     105,   108,   110,   114,   115,   116,   118,   120,   122,   124,
     128,   132,   137,   140,   144,   147,   149,   153,   155,   158,
     161,   164,   166,   168,   172,   174,   179,   184,   189,   191,
     193,   195,   197,   199,   204,   205,   207,   209,   212,   213,
     215,   217,   220,   223,   224,   226,   232,   240,   246,   252,
     259,   269,   272,   275,   279
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    -1,    53,    54,    -1,    32,    -1,    55,
      32,    -1,    62,    32,    -1,    67,    32,    -1,    68,    32,
      -1,    57,    -1,    57,    56,    55,    -1,    57,    33,    55,
      -1,    34,    -1,    19,    -1,    17,    -1,    18,    -1,    12,
      -1,    13,    -1,    35,    -1,    36,    -1,    11,    -1,    37,
      -1,    38,    -1,    39,    -1,    40,    -1,    59,    -1,    14,
      57,    -1,    15,    57,    -1,    58,    57,    -1,    20,    57,
      -1,    20,    41,     5,    42,    -1,    43,    -1,    38,    -1,
      44,    -1,    61,    -1,    59,    45,    55,    46,    -1,    59,
      41,    60,    42,    -1,    59,    47,     4,    -1,    59,    16,
       4,    -1,    59,    14,    -1,    59,    15,    -1,    55,    -1,
      60,    48,    55,    -1,    -1,    -1,     4,    -1,     8,    -1,
       7,    -1,     3,    -1,    41,    55,    42,    -1,     5,     4,
      63,    -1,     5,     4,    34,    55,    -1,     5,     4,    -1,
      41,    64,    42,    -1,    41,    42,    -1,    65,    -1,    64,
      48,    65,    -1,     5,    -1,     5,     4,    -1,     1,     4,
      -1,     5,     1,    -1,    49,    -1,    69,    -1,    50,     1,
      51,    -1,     1,    -1,     5,     4,    63,    66,    -1,     1,
       4,    63,    66,    -1,     5,     1,    63,    66,    -1,    69,
      -1,    74,    -1,    76,    -1,    77,    -1,    78,    -1,    50,
      70,    72,    51,    -1,    -1,    71,    -1,    62,    -1,    71,
      62,    -1,    -1,    73,    -1,    68,    -1,    73,    68,    -1,
      75,    49,    -1,    -1,    55,    -1,    21,    41,    55,    42,
      68,    -1,    21,    41,    55,    42,    68,    22,    68,    -1,
      23,    41,     4,    42,    68,    -1,    24,    41,    55,    42,
      68,    -1,    25,    68,    24,    41,    55,    42,    -1,    29,
      41,    75,    49,    75,    49,    75,    42,    68,    -1,    26,
      49,    -1,    27,    49,    -1,    28,    75,    49,    -1,    30,
       4,    49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    81,    84,    85,    86,    87,    88,    91,
      92,    93,   109,   109,   110,   110,   110,   110,   111,   111,
     111,   112,   113,   113,   113,   116,   117,   118,   119,   120,
     121,   124,   124,   124,   127,   128,   129,   133,   134,   135,
     136,   139,   140,   141,   144,   144,   145,   146,   147,   148,
     151,   157,   162,   169,   170,   173,   174,   177,   181,   185,
     186,   189,   190,   191,   192,   195,   200,   201,   204,   205,
     206,   207,   208,   211,   214,   215,   218,   219,   222,   223,
     226,   227,   230,   233,   234,   237,   238,   239,   242,   243,
     244,   247,   248,   249,   250
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "IDENTIFICADOR", "TIPO_DATO",
  "PALABRA_RESERVADA", "STRING", "CCARACTER", "CONSTANTE_REAL",
  "MAYORIGUAL", "MENORIGUAL", "IGUALIGUAL", "DISTINTO", "INCREMENTO",
  "DECREMENTO", "FLECHA", "OR", "AND", "MASIGUAL", "SIZEOF", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "CONTINUE", "BREAK", "RETURN", "FOR", "GOTO",
  "Funcion", "'\\n'", "'+'", "'='", "'<'", "'>'", "'-'", "'*'", "'/'",
  "'%'", "'('", "')'", "'&'", "'!'", "'['", "']'", "'.'", "','", "';'",
  "'{'", "'}'", "$accept", "input", "line", "expGeneral", "operador",
  "expUnaria", "operadorUnario", "expSufijo", "listaArgumentos",
  "expPrimaria", "declaracion", "parametros", "listaDeParametros",
  "parametro", "cuerpo", "definicionDeFuncion", "sentencia",
  "sentenciaCompuesta", "listaDeDeclaracionesOP", "listaDeDeclaraciones",
  "listaSentenciasOP", "listaSentencias", "sentenciaExpresion", "expOP",
  "sentenciaSeleccion", "sentenciaIteracion", "sentenciaSalto", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    10,    43,    61,    60,    62,    45,    42,    47,
      37,    40,    41,    38,    33,    91,    93,    46,    44,    59,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    54,    54,    54,    55,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    68,    68,
      68,    68,    68,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    75,    75,    76,    76,    76,    77,    77,
      77,    78,    78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       4,     1,     1,     1,     1,     4,     4,     3,     3,     2,
       2,     1,     3,     0,     0,     1,     1,     1,     1,     3,
       3,     4,     2,     3,     2,     1,     3,     1,     2,     2,
       2,     1,     1,     3,     1,     4,     4,     4,     1,     1,
       1,     1,     1,     4,     0,     1,     1,     2,     0,     1,
       1,     2,     2,     0,     1,     5,     7,     5,     5,     6,
       9,     2,     2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    48,    45,     0,    47,    46,    44,
      44,    44,     0,     0,     0,    44,     0,     0,    44,     0,
       0,     4,    32,    44,    31,    33,    74,     3,    84,     9,
      44,    25,    34,     0,     0,     0,    68,    69,     0,    70,
      71,    72,     0,     0,    52,    26,    27,    44,    29,    44,
       0,    44,    84,     0,    91,    92,     0,    44,     0,     0,
       0,    76,    44,    75,     5,    20,    16,    17,    14,    15,
      13,    44,    12,    18,    19,    21,    22,    23,    24,    44,
      28,    39,    40,     0,    44,    44,     0,     6,     7,     8,
      82,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,    93,     0,    94,    49,    52,    80,     0,    44,    77,
      11,    10,    38,    41,     0,     0,    37,     0,     0,    54,
       0,    55,    64,    61,     0,    66,    62,    67,    51,    65,
      30,    44,    44,    44,    44,    44,    50,    73,    81,    36,
      44,    35,    59,    60,    58,    53,     0,     0,    85,    87,
      88,     0,     0,    42,    56,    63,    44,    89,    44,    86,
       0,    44,    90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    27,    52,    79,    29,    30,    31,   114,    32,
      61,    92,   120,   121,   125,    34,    35,    36,    62,    63,
     107,   108,    37,    38,    39,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
     -50,   144,   -50,    -1,   -50,   -50,    20,   -50,   -50,   339,
     339,   358,   -33,   -30,   -12,   307,   -19,   -10,   339,    -8,
      30,   -50,   -50,   339,   -50,   -50,    35,   -50,    13,   373,
     339,    63,   -50,    17,    33,    36,   -50,   -50,    24,   -50,
     -50,   -50,    19,    19,   -21,   -50,   -50,    87,   -50,   339,
      71,   339,   -50,    56,   -50,   -50,    32,   339,    34,    42,
      81,   -50,   243,    35,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   339,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   339,
     -50,   -50,   -50,    82,    28,   339,    85,   -50,   -50,   -50,
     -50,     9,     8,     8,   339,     6,    54,    57,    58,    61,
      64,   -50,    49,   -50,   -50,   -21,   -50,    55,   275,   -50,
     -50,   -50,   -50,   -50,   -23,    65,   -50,   105,    11,   -50,
     -20,   -50,   -50,   -50,   194,   -50,   -50,   -50,   -50,   -50,
     -50,   307,   307,   307,   339,   339,   -50,   -50,   -50,   -50,
     339,   -50,   -50,   -50,   -50,   -50,    22,    62,    90,   -50,
     -50,    72,    66,   -50,   -50,   -50,   307,   -50,   339,   -50,
      78,   307,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,     3,   -50,     7,   -50,   -50,   -50,   -50,
       0,   -38,   -50,   -25,   -49,   -50,   -15,   -31,   -50,   -50,
     -50,   -50,   -50,   -16,   -50,   -50,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -80
static const yytype_int16 yytable[] =
{
      53,    33,    56,    42,    28,    93,    95,   122,    49,   122,
     117,    50,   143,    94,   118,   144,    45,    46,    48,   139,
      91,    43,   145,   117,    44,   140,    59,   118,   146,    51,
      54,     4,     5,    57,    58,     7,     8,    80,   -50,    55,
      60,   102,     9,    10,   127,    64,   129,   106,    11,    87,
      59,   119,    97,   -57,    99,   123,   124,   123,   124,   -57,
      91,   126,   126,   109,   126,    88,    22,   136,    89,    23,
     -43,    24,    25,    90,   110,    98,   -43,    81,    82,    83,
     100,   101,   111,   103,   104,   105,   112,   113,   115,   116,
       4,     5,    96,   138,     7,     8,   130,   128,   135,   131,
     132,     9,    10,   133,    84,   134,   137,    11,    85,   142,
      86,   141,   156,   155,   157,   158,   148,   149,   150,   152,
     161,   154,     0,     0,     0,    22,     0,     0,    23,     0,
      24,    25,     0,     0,     0,     0,     0,   151,     0,     0,
       0,   159,   160,   153,     2,     3,   162,     4,     5,     6,
       0,     7,     8,     0,     0,   -44,   -44,   -44,     9,    10,
     -44,   -44,   -44,   -44,    11,    12,     0,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,   -44,   -44,   -44,
     -44,   -44,    22,   -44,   -44,    23,     0,    24,    25,   -44,
       0,   -44,     0,   -44,    26,   147,     0,   -74,   -74,    60,
       0,   -74,   -74,     0,     0,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,     0,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,     0,     0,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,     0,   -74,   -74,   -74,
       0,   -74,     0,   -74,   -74,   -74,     4,     5,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     9,    10,     0,
       0,     0,     0,    11,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     4,     5,
       0,    22,     7,     8,    23,     0,    24,    25,     0,     9,
      10,     0,     0,    26,   -78,    11,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       4,     5,     0,    22,     7,     8,    23,     0,    24,    25,
       0,     9,    10,     0,     0,    26,   -79,    11,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     4,     5,     0,    22,     7,     8,    23,     0,
      24,    25,     0,     9,    10,     0,     0,    26,     0,    11,
       0,     4,     5,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,    22,    11,     0,
      23,     0,    24,    25,    65,    66,    67,     0,     0,     0,
      68,    69,    70,     0,     0,     0,    22,     0,     0,    47,
       0,    24,    25,     0,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
      15,     1,    18,     4,     1,    43,    44,     1,    41,     1,
       1,    41,     1,    34,     5,     4,     9,    10,    11,    42,
      41,     1,    42,     1,     4,    48,    23,     5,    48,    41,
      49,     3,     4,    41,     4,     7,     8,    30,    32,    49,
       5,    57,    14,    15,    93,    32,    95,    62,    20,    32,
      47,    42,    49,    42,    51,    49,    50,    49,    50,    48,
      41,    92,    93,    63,    95,    32,    38,   105,    32,    41,
      42,    43,    44,    49,    71,     4,    48,    14,    15,    16,
      24,    49,    79,    49,    42,     4,     4,    84,    85,     4,
       3,     4,     5,   108,     7,     8,    42,    94,    49,    42,
      42,    14,    15,    42,    41,    41,    51,    20,    45,     4,
      47,    46,    22,    51,    42,    49,   131,   132,   133,   135,
      42,   146,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,   156,   158,   140,     0,     1,   161,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      -1,    47,    -1,    49,    50,     1,    -1,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      -1,    47,    -1,    49,    50,    51,     3,     4,    -1,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,     3,     4,
      -1,    38,     7,     8,    41,    -1,    43,    44,    -1,    14,
      15,    -1,    -1,    50,    51,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
       3,     4,    -1,    38,     7,     8,    41,    -1,    43,    44,
      -1,    14,    15,    -1,    -1,    50,    51,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,     3,     4,    -1,    38,     7,     8,    41,    -1,
      43,    44,    -1,    14,    15,    -1,    -1,    50,    -1,    20,
      -1,     3,     4,    -1,    -1,     7,     8,    -1,    -1,    -1,
      -1,    -1,    14,    15,    -1,    -1,    -1,    38,    20,    -1,
      41,    -1,    43,    44,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    19,    -1,    -1,    -1,    38,    -1,    -1,    41,
      -1,    43,    44,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,     0,     1,     3,     4,     5,     7,     8,    14,
      15,    20,    21,    23,    24,    25,    26,    27,    28,    29,
      30,    32,    38,    41,    43,    44,    50,    54,    55,    57,
      58,    59,    61,    62,    67,    68,    69,    74,    75,    76,
      77,    78,     4,     1,     4,    57,    57,    41,    57,    41,
      41,    41,    55,    68,    49,    49,    75,    41,     4,    55,
       5,    62,    70,    71,    32,    11,    12,    13,    17,    18,
      19,    33,    34,    35,    36,    37,    38,    39,    40,    56,
      57,    14,    15,    16,    41,    45,    47,    32,    32,    32,
      49,    41,    63,    63,    34,    63,     5,    55,     4,    55,
      24,    49,    75,    49,    42,     4,    68,    72,    73,    62,
      55,    55,     4,    55,    60,    55,     4,     1,     5,    42,
      64,    65,     1,    49,    50,    66,    69,    66,    55,    66,
      42,    42,    42,    42,    41,    49,    63,    51,    68,    42,
      48,    46,     4,     1,     4,    42,    48,     1,    68,    68,
      68,    55,    75,    55,    65,    51,    22,    42,    49,    68,
      75,    42,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 81 "../src/tpINT.y"
    {flag_error=0;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 93 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontro una expresion aditiva \n"); 

                                        if((yyvsp[(1) - (3)].miestructura).tipo == (yyvsp[(3) - (3)].miestructura).tipo){ 
                                               if((yyvsp[(1) - (3)].miestructura).tipo==1){
                                                        (yyval.miestructura).entero=(yyvsp[(1) - (3)].miestructura).entero+(yyvsp[(3) - (3)].miestructura).entero;
                                                        printf("CONTROL DE TIPOS EXITOSO, los operandos son del mismo tipo \n" );
                                               }else{
                                                        (yyval.miestructura).real=(yyvsp[(1) - (3)].miestructura).real+(yyvsp[(3) - (3)].miestructura).real;
                                                        printf("CONTROL DE TIPOS EXITOSO, Los operandos son del mismo tipo \n");
                                               }
                                        }else{
                                                printf("ERROR SEMANTICO - Los operandos son de distinto tipo \n");
                                        };}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 109 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontro una expresion de asignacion \n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 110 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontro una expresion logica \n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 111 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontro una expresion relacional \n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 112 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontro una expresion de sustraccion \n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 113 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontro una expresion multiplicativa \n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 124 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontro una expresion unaria \n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 129 "../src/tpINT.y"
    {fInvocada = buscarFuncion(TSFunc, (yyvsp[(1) - (4)].miestructura).cadena);
                                                if(controlDeParametrosDeInvocacion(misParametros,fInvocada)){
                                                        printf("Fin de la lista de parametros, todos son del tipo de dato correcto \n'");
                                                };;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 139 "../src/tpINT.y"
    {insertarTipoParametro(misParametros,(yyvsp[(1) - (1)].miestructura).entero);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 144 "../src/tpINT.y"
    {printf("Se encontro el identificador %s \n" , (yyvsp[(1) - (1)].miestructura).cadena);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 145 "../src/tpINT.y"
    {printf(" Se encontro el caracter %c \n" , (yyvsp[(1) - (1)].miestructura).caracter);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 146 "../src/tpINT.y"
    {printf ( "Se encontro la palabra %s \n " , (yyvsp[(1) - (1)].miestructura).cadena);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 147 "../src/tpINT.y"
    {printf("Se encontro un numero %d \n", (yyvsp[(1) - (1)].miestructura).entero);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 151 "../src/tpINT.y"
    {if(flag_error==0) printf("función declarada correctamente");
                                                        strcpy(unaFunc.nombreF, (yyvsp[(2) - (3)].miestructura).cadena);   
                                                        strcpy(unaFunc.tipoDeDatoSalida, (yyvsp[(1) - (3)].miestructura).cadena);
                                                        unaFunc.parametros = listaAux;
                                                        insertarFuncionUnica(unaFunc,TSFunc);
                                                        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 157 "../src/tpINT.y"
    {if(flag_error==0){ printf("Variable declarada correctamente");
                                                        strcpy(unaVar.nombreV, (yyvsp[(2) - (4)].miestructura).cadena);   
                                                        strcpy(unaVar.tipoDeDato, (yyvsp[(1) - (4)].miestructura).cadena);  
                                                        insertarVariableUnica(unaVar, TSVar); 
                                                        };;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 162 "../src/tpINT.y"
    {if(flag_error==0){ printf("Variable declarada correctamente");
                                                        strcpy(unaVar.nombreV, (yyvsp[(2) - (2)].miestructura).cadena); 
                                                        strcpy(unaVar.tipoDeDato, (yyvsp[(1) - (2)].miestructura).cadena);  
                                                        insertarVariableUnica(unaVar, TSVar); 
                                                        };;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 177 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontró un parámetro de tipo %s \n", (yyvsp[(1) - (1)].miestructura).cadena); 
                                                  strcpy(unaVar.tipoDeDato, (yyvsp[(1) - (1)].miestructura).cadena);
                                                  strcpy(unaVar.nombreV, "sin definir");
                                                  insertarVariableUnica(unaVar,listaAux);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 181 "../src/tpINT.y"
    {if(flag_error==0) printf("Se encontró un parámetro de tipo %s de nombre %s \n", (yyvsp[(1) - (2)].miestructura).cadena, (yyvsp[(2) - (2)].miestructura).cadena); 
                                                  strcpy(unaVar.nombreV, (yyvsp[(2) - (2)].miestructura).cadena);   
                                                  strcpy(unaVar.tipoDeDato, (yyvsp[(1) - (2)].miestructura).cadena); 
                                                  insertarVariableUnica(unaVar,listaAux);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 185 "../src/tpINT.y"
    {printf("error al declarar el tipo de dato del parámetro"); flag_error=1;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 186 "../src/tpINT.y"
    {printf("error al definir el identificador del parámetro"); flag_error=1;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 189 "../src/tpINT.y"
    {if(flag_error==0) printf("función definida correctamente");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 190 "../src/tpINT.y"
    {if(flag_error==0) (printf("función definida correctamente"));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 191 "../src/tpINT.y"
    {if(flag_error==0) {printf("Error al definir la función \n"); flag_error=1;};;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 192 "../src/tpINT.y"
    {if(flag_error==0) {printf("Error al definir la función \n"); flag_error=1;};;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 195 "../src/tpINT.y"
    {if(flag_error==0) printf("Se declaró correctamente la funcion %s \n", (yyvsp[(2) - (4)].miestructura).cadena);
                                                                        strcpy(unaFunc.nombreF, (yyvsp[(2) - (4)].miestructura).cadena);   
                                                                        strcpy(unaFunc.tipoDeDatoSalida, (yyvsp[(1) - (4)].miestructura).cadena);
                                                                        insertarFuncionUnica(unaFunc,TSFunc);
                                                                        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 200 "../src/tpINT.y"
    {yyerror; printf("Error al definir el tipo de dato de la funcion\n"); flag_error=1;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 201 "../src/tpINT.y"
    {yyerror; printf("Error al definir el identificador de la funcion\n"); flag_error=1;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 204 "../src/tpINT.y"
    {printf("Se encontró una sentencia compuesta.\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 205 "../src/tpINT.y"
    {printf("Se encontró una sentencia expresión.\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 206 "../src/tpINT.y"
    {printf("Se encontró una sentencia selección.\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 207 "../src/tpINT.y"
    {printf("Se encontró una sentencia iteración.\n");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 208 "../src/tpINT.y"
    {printf("Se encontró una sentencia salto.\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 219 "../src/tpINT.y"
    {printf("Se encontró una lista de declaraciones.\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 227 "../src/tpINT.y"
    {printf("Se encontró una lista de sentencias.\n");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 237 "../src/tpINT.y"
    {printf("Se encontró una sentencia if.\n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 238 "../src/tpINT.y"
    {printf("Se encontró una sentencia if-else.\n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 239 "../src/tpINT.y"
    {printf("Se encontró una sentencia switch.\n");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 242 "../src/tpINT.y"
    {printf("Se encontró una sentencia while.\n");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 243 "../src/tpINT.y"
    {printf("Se encontró una sentencia do-while.\n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 244 "../src/tpINT.y"
    {printf("Se encontró una sentencia for.\n");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 247 "../src/tpINT.y"
    {printf("Se encontró una sentencia continue.\n");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 248 "../src/tpINT.y"
    {printf("Se encontró una sentencia break.\n");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 249 "../src/tpINT.y"
    {printf("Se encontró una sentencia return.\n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 250 "../src/tpINT.y"
    {printf("Se encontró una sentencia goto.\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 1948 "tpINT.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 253 "../src/tpINT.y"


int main (int argc, char *argv[])
{
    int flag;
 
    yyin=fopen("archivoFuente.txt","r");
        if(yyin == NULL){
         puts(strerror(errno));
    }

    flag=yyparse();
 
    fclose(yyin);

    reportarVariablesDeclaradas(TSVar);
    reportarFuncionesDeclaradas(TSFunc);
   
    return flag;
//
}
//control de parametros
/*                 if(buscarFuncion(TSFunc, unaFunc)){
                            controlDeParametrosDeInvocacion(misParametros, unaVar)
                            }else{
                                    printf("ERROR SEMANTICO - funcion no declarada");
                            }*/
