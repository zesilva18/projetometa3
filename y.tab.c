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
#line 7 "jucompiler.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "semantics.h"

symbab_tab* symtab;

struct ast_tree *raiz;
struct ast_tree *aux;
struct ast_tree *temp;

int flag = 1;
char *type;
int n_sons;
int flag_erro = 0;
int flag_erro2 = 0;

extern int yylex(void);
extern int yyerror(char *s);
extern int yylineno;
extern int line;
extern int collum;

int flag_while = 0;

void mantertipo(ast_tree* no,char* type){
        ast_tree* auxiliar = NULL;
        for (ast_tree *atual = no; atual; atual = atual->brother){
            auxiliar=ast_node(type, "",0,0);
            auxiliar->brother=atual->son;
            atual->son=auxiliar;
        }
}


#line 108 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CLASS = 258,
    PUBLIC = 259,
    STATIC = 260,
    COMMA = 261,
    LBRACE = 262,
    RBRACE = 263,
    LPAR = 264,
    RPAR = 265,
    LSQ = 266,
    RSQ = 267,
    ELSE = 268,
    ARROW = 269,
    RESERVED = 270,
    WHILE = 271,
    SEMICOLON = 272,
    ID = 273,
    STRLIT = 274,
    INTLIT = 275,
    REALLIT = 276,
    BOOLLIT = 277,
    BOOL = 278,
    INT = 279,
    DOUBLE = 280,
    PLUS = 281,
    MINUS = 282,
    STAR = 283,
    DIV = 284,
    MOD = 285,
    AND = 286,
    OR = 287,
    XOR = 288,
    LSHIFT = 289,
    RSHIFT = 290,
    EQ = 291,
    GE = 292,
    GT = 293,
    LE = 294,
    LT = 295,
    NE = 296,
    NOT = 297,
    ASSIGN = 298,
    PRINT = 299,
    RETURN = 300,
    PARSEINT = 301,
    DOTLENGTH = 302,
    VOID = 303,
    IF = 304,
    STRING = 305
  };
#endif
/* Tokens.  */
#define CLASS 258
#define PUBLIC 259
#define STATIC 260
#define COMMA 261
#define LBRACE 262
#define RBRACE 263
#define LPAR 264
#define RPAR 265
#define LSQ 266
#define RSQ 267
#define ELSE 268
#define ARROW 269
#define RESERVED 270
#define WHILE 271
#define SEMICOLON 272
#define ID 273
#define STRLIT 274
#define INTLIT 275
#define REALLIT 276
#define BOOLLIT 277
#define BOOL 278
#define INT 279
#define DOUBLE 280
#define PLUS 281
#define MINUS 282
#define STAR 283
#define DIV 284
#define MOD 285
#define AND 286
#define OR 287
#define XOR 288
#define LSHIFT 289
#define RSHIFT 290
#define EQ 291
#define GE 292
#define GT 293
#define LE 294
#define LT 295
#define NE 296
#define NOT 297
#define ASSIGN 298
#define PRINT 299
#define RETURN 300
#define PARSEINT 301
#define DOTLENGTH 302
#define VOID 303
#define IF 304
#define STRING 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "jucompiler.y"

char* string;
struct ast_tree* ast_tree;
struct info_lex *lex;  

#line 266 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   393

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    91,    95,   101,   104,   108,   116,   125,
     136,   142,   150,   151,   154,   162,   166,   173,   176,   177,
     178,   181,   186,   192,   196,   202,   206,   217,   223,   226,
     250,   253,   269,   284,   298,   304,   306,   310,   314,   318,
     321,   322,   323,   326,   327,   330,   333,   336,   339,   342,
     344,   347,   350,   354,   355,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "PUBLIC", "STATIC", "COMMA",
  "LBRACE", "RBRACE", "LPAR", "RPAR", "LSQ", "RSQ", "ELSE", "ARROW",
  "RESERVED", "WHILE", "SEMICOLON", "ID", "STRLIT", "INTLIT", "REALLIT",
  "BOOLLIT", "BOOL", "INT", "DOUBLE", "PLUS", "MINUS", "STAR", "DIV",
  "MOD", "AND", "OR", "XOR", "LSHIFT", "RSHIFT", "EQ", "GE", "GT", "LE",
  "LT", "NE", "NOT", "ASSIGN", "PRINT", "RETURN", "PARSEINT", "DOTLENGTH",
  "VOID", "IF", "STRING", "$accept", "Program", "HelpProgam", "MethodDecl",
  "MethodHeader", "MethodBody", "HelpMethod", "FieldDecl", "HelpField",
  "Type", "FormalParams", "FormalParamsAux", "VarDecl", "VarDeclAux",
  "Statement", "StatementAux", "MethodInvocation", "ShiftReduce",
  "MethodInvocationaux", "ParseArgs", "Expr", "ExprAux", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    21,    28,    33,   -46,    41,    26,    51,    41,    49,
      41,    41,   -46,    88,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,    68,    81,    75,    85,   109,   -46,    16,    10,    84,
      46,    94,   -46,     3,    98,   201,   100,   106,   111,   103,
     109,   109,   105,   127,   110,    10,   140,   148,   145,   159,
     -46,   -46,   122,   224,   155,   224,    78,   178,   -46,    -6,
     -46,   -46,   -46,   247,   247,   247,   -46,   -46,   153,   284,
      20,   224,   -46,   166,   -46,   -46,   -46,   -46,   168,   170,
     -46,   171,   172,   -46,   122,   176,   175,   181,   -46,   182,
     180,   177,   185,   192,   193,    -3,   268,   224,   -46,   -46,
     -46,   -46,   -46,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   196,
     197,   199,   189,   194,   -46,   -46,   195,   118,   -46,   -46,
     -46,   144,   -46,   -46,   224,   -46,   -46,   198,   200,   -46,
     -46,   -46,   119,   119,   -46,   -46,   -46,   316,   300,   332,
     348,   348,   353,    39,    39,    39,    39,   353,   -46,   224,
     144,   166,   -46,   -46,   207,   -46,   180,   -46,   -46,   202,
     203,   -46,   172,   -46,   216,   144,   -46,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     5,     2,     3,     4,    20,    18,
      19,     0,     0,     0,     0,     0,     7,    17,    23,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
      42,    30,     0,     0,     0,     0,     0,     0,    35,    75,
      77,    78,    79,     0,     0,     0,    80,    81,     0,    53,
       0,     0,    10,    28,    12,    11,    39,    40,    17,     0,
      14,     0,    25,     9,     0,     0,     0,     0,    46,     0,
      50,     0,     0,     0,     0,    75,     0,     0,    76,    73,
      71,    72,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     8,     0,     0,    21,    43,
      29,     0,    47,    45,     0,    48,    34,     0,     0,    82,
      74,    54,    55,    56,    57,    58,    59,    62,    60,    61,
      63,    64,    65,    70,    68,    69,    67,    66,    52,     0,
       0,    28,    26,    22,     0,    33,    50,    38,    37,     0,
      31,    27,    25,    49,     0,     0,    24,    51,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,    40,   -46,   -46,   -46,   -27,   -46,   134,    -9,
     184,    58,   -46,    70,   -29,   150,   -25,   -46,    66,   -23,
     -45,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    22,    26,    38,    11,    46,    39,
      49,   128,    40,   123,    41,    85,    66,    89,   135,    67,
      68,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    52,    43,    54,    23,    42,    54,    43,    86,    90,
      91,    93,    54,    74,    75,    42,    42,    43,    43,    48,
       1,   119,    44,    84,    96,    45,   121,    42,     4,    43,
      99,   100,   101,    18,    19,    20,    48,    97,   120,     3,
       5,    98,     6,    12,    98,     7,    55,    29,    14,    -6,
      16,    17,   141,    30,    51,    84,    13,    15,     8,    42,
      47,    43,    31,    32,    33,   103,   104,   105,   106,   107,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    24,    57,    25,   166,
      34,    35,    36,    27,    28,    37,    59,    92,    60,    61,
      62,    50,   165,    53,    63,    64,    42,    56,    43,    70,
      29,    18,    19,    20,   169,    71,    30,   -13,   164,    72,
      65,    73,    76,    29,    36,    31,    32,    33,    78,    30,
     -44,   170,    18,    19,    20,    42,    21,    43,    31,    32,
      33,    18,    19,    20,    77,    29,   178,   105,   106,   107,
      42,    30,    43,    34,    35,    36,    87,    80,    37,    81,
      31,    32,    33,    82,    57,    88,    34,    35,    36,    83,
     102,    37,   122,    59,    44,    60,    61,    62,   127,    94,
     125,    63,    64,   126,   130,   131,   134,    57,    34,    35,
      36,   132,   133,    37,   136,   137,    95,    65,    60,    61,
      62,    36,   138,   139,    63,    64,   158,   161,   159,   160,
      57,   162,   124,   163,   174,   167,   175,   168,    58,    59,
      65,    60,    61,    62,    36,   172,   177,    63,    64,    79,
     176,   171,   173,    57,   129,     0,     0,     0,     0,     0,
       0,     0,    59,    65,    60,    61,    62,    36,     0,     0,
      63,    64,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    65,    60,    61,    62,
      36,     0,     0,    63,    64,     0,     0,     0,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,    36,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   103,   104,   105,   106,
     107,   108,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   103,   104,   105,   106,   107,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   103,   104,
     105,   106,   107,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   103,   104,   105,   106,   107,   103,
     104,   105,   106,   107,   113,   114,   115,   116,   117,   118,
     114,   115,   116,   117
};

static const yytype_int16 yycheck[] =
{
      25,    30,    25,     9,    13,    30,     9,    30,    53,    54,
      55,    56,     9,    40,    41,    40,    41,    40,    41,    28,
       3,     1,     6,    52,    57,     9,    71,    52,     0,    52,
      63,    64,    65,    23,    24,    25,    45,    43,    18,    18,
       7,    47,     1,    17,    47,     4,    43,     1,     8,     8,
      10,    11,    97,     7,     8,    84,     5,     8,    17,    84,
      50,    84,    16,    17,    18,    26,    27,    28,    29,    30,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    18,     9,     7,   134,
      44,    45,    46,    18,     9,    49,    18,    19,    20,    21,
      22,    17,   131,     9,    26,    27,   131,     9,   131,     9,
       1,    23,    24,    25,   159,     9,     7,     8,   127,     8,
      42,    18,    17,     1,    46,    16,    17,    18,    18,     7,
       8,   160,    23,    24,    25,   160,    48,   160,    16,    17,
      18,    23,    24,    25,    17,     1,   175,    28,    29,    30,
     175,     7,   175,    44,    45,    46,     1,    17,    49,    11,
      16,    17,    18,    18,     9,    10,    44,    45,    46,    10,
      17,    49,     6,    18,     6,    20,    21,    22,     6,     1,
      10,    26,    27,    12,     8,    10,     6,     9,    44,    45,
      46,    10,    10,    49,    17,    10,    18,    42,    20,    21,
      22,    46,    10,    10,    26,    27,    10,    18,    11,    10,
       9,    17,    78,    18,    12,    17,    13,    17,    17,    18,
      42,    20,    21,    22,    46,    18,    10,    26,    27,    45,
     172,   161,   166,     9,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    42,    20,    21,    22,    46,    -1,    -1,
      26,    27,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    42,    20,    21,    22,
      46,    -1,    -1,    26,    27,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    26,    27,    28,    29,    30,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    26,    27,    28,    29,    30,    26,
      27,    28,    29,    30,    36,    37,    38,    39,    40,    41,
      37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    18,     0,     7,     1,     4,    17,    53,
      54,    58,    17,     5,    53,     8,    53,    53,    23,    24,
      25,    48,    55,    60,    18,     7,    56,    18,     9,     1,
       7,    16,    17,    18,    44,    45,    46,    49,    57,    60,
      63,    65,    67,    70,     6,     9,    59,    50,    60,    61,
      17,     8,    65,     9,     9,    43,     9,     9,    17,    18,
      20,    21,    22,    26,    27,    42,    67,    70,    71,    72,
       9,     9,     8,    18,    57,    57,    17,    17,    18,    61,
      17,    11,    18,    10,    65,    66,    71,     1,    10,    68,
      71,    71,    19,    71,     1,    18,    72,    43,    47,    72,
      72,    72,    17,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     1,
      18,    71,     6,    64,    59,    10,    12,     6,    62,    66,
       8,    10,    10,    10,     6,    69,    17,    10,    10,    10,
      10,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    10,    11,
      10,    18,    17,    18,    60,    65,    71,    17,    17,    71,
      65,    64,    18,    69,    12,    13,    62,    10,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     5,     5,
       3,     2,     2,     0,     6,     2,     3,     0,     1,     1,
       1,     3,     4,     0,     4,     0,     4,     3,     0,     4,
       2,     5,     7,     5,     4,     2,     3,     5,     5,     2,
       2,     1,     2,     2,     0,     4,     3,     4,     2,     3,
       0,     7,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     1,
       1,     1,     3
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
#line 83 "jucompiler.y"
                                                            {
                                                                (yyval.ast_tree) = ast_node("Program","",0,0);       
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-3].lex)->name,(yyvsp[-3].lex)->line,(yyvsp[-3].lex)->collum));
                                                                add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                raiz = (yyval.ast_tree);
                                                            }
#line 1609 "y.tab.c"
    break;

  case 3:
#line 91 "jucompiler.y"
                                                             {
                                                                (yyval.ast_tree) = (yyvsp[-1].ast_tree);
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                            }
#line 1618 "y.tab.c"
    break;

  case 4:
#line 95 "jucompiler.y"
                                                             {                                                           
                                                                (yyval.ast_tree) = (yyvsp[-1].ast_tree);
                                                                
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1629 "y.tab.c"
    break;

  case 5:
#line 101 "jucompiler.y"
                                                             {
                                                                (yyval.ast_tree) = (yyvsp[0].ast_tree);
                                                            }
#line 1637 "y.tab.c"
    break;

  case 6:
#line 104 "jucompiler.y"
                                                            {(yyval.ast_tree)=NULL;}
#line 1643 "y.tab.c"
    break;

  case 7:
#line 108 "jucompiler.y"
                                                                                    {
                                                                                    (yyval.ast_tree) = ast_node("MethodDecl","",0,0);
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    }
#line 1653 "y.tab.c"
    break;

  case 8:
#line 116 "jucompiler.y"
                                                               {
                                                                (yyval.ast_tree) = ast_node("MethodHeader","",0,0);
                                                                aux = ast_node("MethodParams","",0,0);
                                                                add_childs((yyval.ast_tree),(yyvsp[-4].ast_tree)); 
                                                                add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-3].lex)->name,(yyvsp[-3].lex)->line,(yyvsp[-3].lex)->collum));
                                                                add_childs((yyval.ast_tree), aux);
                                                                add_childs(aux,(yyvsp[-1].ast_tree));
                                                               }
#line 1666 "y.tab.c"
    break;

  case 9:
#line 125 "jucompiler.y"
                                                               {
                                                                (yyval.ast_tree) = ast_node("MethodHeader","",0,0);
                                                                aux = ast_node("MethodParams","",0,0);
                                                                add_childs((yyval.ast_tree),ast_node("Void", "", (yyvsp[-4].lex)->line, (yyvsp[-4].lex)->collum)); 
                                                                add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-3].lex)->name,(yyvsp[-3].lex)->line,(yyvsp[-3].lex)->collum));
                                                                add_childs((yyval.ast_tree), aux);
                                                                add_childs(aux,(yyvsp[-1].ast_tree));
                                                               }
#line 1679 "y.tab.c"
    break;

  case 10:
#line 136 "jucompiler.y"
                                                                                 {(yyval.ast_tree) = ast_node("MethodBody","",0,0); 
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                                    }
#line 1687 "y.tab.c"
    break;

  case 11:
#line 142 "jucompiler.y"
                                                                              {if((yyvsp[-1].ast_tree)!=NULL){
                                                                                    (yyval.ast_tree) = (yyvsp[-1].ast_tree);
                                                                                    add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                                    }
                                                                                    else{
                                                                                        (yyval.ast_tree) = (yyvsp[0].ast_tree);
                                                                                    }
                                                                                    }
#line 1700 "y.tab.c"
    break;

  case 12:
#line 150 "jucompiler.y"
                                                                                 {(yyval.ast_tree) = (yyvsp[-1].ast_tree); add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1706 "y.tab.c"
    break;

  case 13:
#line 151 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 1712 "y.tab.c"
    break;

  case 14:
#line 154 "jucompiler.y"
                                                         {
                                                                (yyval.ast_tree) = ast_node("FieldDecl", "",0,0);
                                                                add_childs((yyval.ast_tree),(yyvsp[-3].ast_tree));
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].lex)->name,(yyvsp[-2].lex)->line,(yyvsp[-2].lex)->collum));
                                                                mantertipo((yyvsp[-1].ast_tree), (yyvsp[-3].ast_tree)->type);
                                                                add_brother((yyval.ast_tree), (yyvsp[-1].ast_tree));
                                                                
                                                            }
#line 1725 "y.tab.c"
    break;

  case 15:
#line 162 "jucompiler.y"
                                                             {(yyval.ast_tree) = NULL;flag_erro = 1; flag_erro2 = 1;}
#line 1731 "y.tab.c"
    break;

  case 16:
#line 166 "jucompiler.y"
                                                      {
                                                                (yyval.ast_tree) = ast_node("FieldDecl","",0,0);                                                                
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-1].lex)->name,(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum));
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1742 "y.tab.c"
    break;

  case 17:
#line 173 "jucompiler.y"
                                                           {(yyval.ast_tree) = NULL; }
#line 1748 "y.tab.c"
    break;

  case 18:
#line 176 "jucompiler.y"
                                                            {(yyval.ast_tree) = ast_node((yyvsp[0].lex)->name,"",(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum);}
#line 1754 "y.tab.c"
    break;

  case 19:
#line 177 "jucompiler.y"
                                                            {(yyval.ast_tree) = ast_node((yyvsp[0].lex)->name,"",(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum);}
#line 1760 "y.tab.c"
    break;

  case 20:
#line 178 "jucompiler.y"
                                                            {(yyval.ast_tree) = ast_node((yyvsp[0].lex)->name,"",(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum);}
#line 1766 "y.tab.c"
    break;

  case 21:
#line 181 "jucompiler.y"
                                                                           {(yyval.ast_tree) = ast_node("ParamDecl","",0,0);
                                                                            add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                            add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-1].lex)->name,(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum));
                                                                            add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 1775 "y.tab.c"
    break;

  case 22:
#line 186 "jucompiler.y"
                                                                           {
                                                                           (yyval.ast_tree) = ast_node("ParamDecl","",0,0);
                                                                           add_childs((yyval.ast_tree),ast_node("StringArray","",(yyvsp[-3].lex)->line,(yyvsp[-3].lex)->collum));
                                                                           add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[0].lex)->name,(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum));
                                                                           }
#line 1785 "y.tab.c"
    break;

  case 23:
#line 192 "jucompiler.y"
                                                                            {(yyval.ast_tree) = NULL;}
#line 1791 "y.tab.c"
    break;

  case 24:
#line 196 "jucompiler.y"
                                                                          { (yyval.ast_tree) = ast_node("ParamDecl","",0,0);
                                                                            add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                            add_childs((yyval.ast_tree),ast_node("Id",(yyvsp[-1].lex)->name,(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum));
                                                                            add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                            }
#line 1801 "y.tab.c"
    break;

  case 25:
#line 202 "jucompiler.y"
                                                                          {(yyval.ast_tree) = NULL;}
#line 1807 "y.tab.c"
    break;

  case 26:
#line 206 "jucompiler.y"
                                                                        {
    
                                                                (yyval.ast_tree) = ast_node("VarDecl", "",0,0);
                                                                add_childs((yyval.ast_tree), (yyvsp[-3].ast_tree));
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].lex)->name,(yyvsp[-2].lex)->line,(yyvsp[-2].lex)->collum));
                                                                mantertipo((yyvsp[-1].ast_tree), (yyvsp[-3].ast_tree)->type);
                                                                add_brother((yyval.ast_tree), (yyvsp[-1].ast_tree));
                                                                
                                                                }
#line 1821 "y.tab.c"
    break;

  case 27:
#line 217 "jucompiler.y"
                                                           { 
                                                                (yyval.ast_tree) = ast_node("VarDecl","",0,0);
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-1].lex)->name,(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum));                                                              
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1832 "y.tab.c"
    break;

  case 28:
#line 223 "jucompiler.y"
                                                            {(yyval.ast_tree) = NULL;}
#line 1838 "y.tab.c"
    break;

  case 29:
#line 226 "jucompiler.y"
                                                          {
                                                                int count = 0;
                                                                if((yyvsp[-2].ast_tree) != NULL){
                                                                    count++;
                                                                }
                                                                aux = (yyvsp[-1].ast_tree);
                                                                while(aux != NULL){
                                                                    if(aux->type != NULL && strcmp(aux->type,"Semicolon")!=0){
                                                                        count++;
                                                                    }

                                                                    aux = aux->brother;
                                                                }
                                                                
                                                                if(count > 1){
                                                                    (yyval.ast_tree) = ast_node("Block","",0,0);
                                                                    add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                    add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                }
                                                                else {
                                                                    (yyval.ast_tree) = (yyvsp[-2].ast_tree);
                                                                }
                                                            }
#line 1866 "y.tab.c"
    break;

  case 30:
#line 250 "jucompiler.y"
                                                                                             {(yyval.ast_tree) = NULL;}
#line 1872 "y.tab.c"
    break;

  case 31:
#line 253 "jucompiler.y"
                                                                            {
                                                                               (yyval.ast_tree) = ast_node("If","", (yyvsp[-4].lex)->line,(yyvsp[-4].lex)->collum);
                                                                               

                                                                               add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));


                                                                               if((yyvsp[0].ast_tree) == NULL || strcmp((yyvsp[0].ast_tree)->type, "Semicolon") == 0){
                                                                                    add_childs((yyval.ast_tree),ast_node("Block","",0,0));
                                                                                    add_childs((yyval.ast_tree),ast_node("Block","",0,0));
                                                                               }else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    add_childs((yyval.ast_tree),ast_node("Block","",0,0));
                                                                               }
                                                                            }
#line 1892 "y.tab.c"
    break;

  case 32:
#line 269 "jucompiler.y"
                                                                            {
                                                                                (yyval.ast_tree) = ast_node("If","",(yyvsp[-6].lex)->line,(yyvsp[-6].lex)->collum);
                                                                                add_childs((yyval.ast_tree),(yyvsp[-4].ast_tree));
                                                                                if((yyvsp[-2].ast_tree) == NULL || strcmp((yyvsp[-2].ast_tree)->type,"Semicolon") == 0){  
                                                                                    add_childs((yyval.ast_tree),ast_node("Block","",0,0));}
                                                                                else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                                    }
                                                                                if((yyvsp[0].ast_tree) == NULL|| strcmp((yyvsp[0].ast_tree)->type,"Semicolon") == 0){ 
                                                                                    add_childs((yyval.ast_tree),ast_node("Block","",0,0));}
                                                                                else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    }

                                                                            }
#line 1912 "y.tab.c"
    break;

  case 33:
#line 284 "jucompiler.y"
                                                                            {
                                                                             (yyval.ast_tree) = ast_node("While","",(yyvsp[-4].lex)->line,(yyvsp[-4].lex)->collum);
                                                                             add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                             if((yyvsp[0].ast_tree) == NULL || strcmp((yyvsp[0].ast_tree)->type,"Semicolon") == 0){
                                                                                add_childs((yyval.ast_tree),ast_node("Block","",0,0));
                                                                                }
                                                                             else {
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                }
                                                                                
                                                                             
                                                                             
                                                                            }
#line 1930 "y.tab.c"
    break;

  case 34:
#line 298 "jucompiler.y"
                                                                            {
                                                                                (yyval.ast_tree) = ast_node("Assign","",(yyvsp[-2].lex)->line,(yyvsp[-2].lex)->collum);
                                                                                add_childs((yyval.ast_tree),ast_node("Id",(yyvsp[-3].lex)->name,(yyvsp[-3].lex)->line,(yyvsp[-3].lex)->collum));
                                                                                add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                            }
#line 1940 "y.tab.c"
    break;

  case 35:
#line 304 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("Return", "",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);}
#line 1946 "y.tab.c"
    break;

  case 36:
#line 306 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("Return","",(yyvsp[-2].lex)->line,(yyvsp[-2].lex)->collum);
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                                    }
#line 1954 "y.tab.c"
    break;

  case 37:
#line 310 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("Print","",(yyvsp[-4].lex)->line,(yyvsp[-4].lex)->collum);
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                                    }
#line 1962 "y.tab.c"
    break;

  case 38:
#line 314 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("Print","",(yyvsp[-4].lex)->line,(yyvsp[-4].lex)->collum);
                                                                                    add_childs((yyval.ast_tree), ast_node("StrLit", (yyvsp[-2].lex)->name,(yyvsp[-2].lex)->line,(yyvsp[-2].lex)->collum));
                                                                                    }
#line 1970 "y.tab.c"
    break;

  case 39:
#line 318 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 1976 "y.tab.c"
    break;

  case 40:
#line 321 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 1982 "y.tab.c"
    break;

  case 41:
#line 322 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("Semicolon","",(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum);}
#line 1988 "y.tab.c"
    break;

  case 42:
#line 323 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;flag_erro2 = 1;}
#line 1994 "y.tab.c"
    break;

  case 43:
#line 326 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree); add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2000 "y.tab.c"
    break;

  case 44:
#line 327 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 2006 "y.tab.c"
    break;

  case 45:
#line 330 "jucompiler.y"
                                                                       {(yyval.ast_tree) = ast_node("Call", "",(yyvsp[-3].lex)->line, (yyvsp[-3].lex)->collum);
                                                                        add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-3].lex)->name,(yyvsp[-3].lex)->line,(yyvsp[-3].lex)->collum));add_childs((yyval.ast_tree), (yyvsp[-1].ast_tree));}
#line 2013 "y.tab.c"
    break;

  case 46:
#line 333 "jucompiler.y"
                                                                              {(yyval.ast_tree) = ast_node("Call", "",(yyvsp[-2].lex)->line, (yyvsp[-2].lex)->collum);
                                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].lex)->name,(yyvsp[-2].lex)->line,(yyvsp[-2].lex)->collum));}
#line 2020 "y.tab.c"
    break;

  case 47:
#line 336 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1; flag_erro2 = 1;}
#line 2026 "y.tab.c"
    break;

  case 48:
#line 339 "jucompiler.y"
                                                             {(yyval.ast_tree) = (yyvsp[-1].ast_tree);add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2032 "y.tab.c"
    break;

  case 49:
#line 342 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 2038 "y.tab.c"
    break;

  case 50:
#line 344 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 2044 "y.tab.c"
    break;

  case 51:
#line 347 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("ParseArgs","",(yyvsp[-6].lex)->line,(yyvsp[-6].lex)->collum);
                                                                                    add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-4].lex)->name,(yyvsp[-4].lex)->line,(yyvsp[-4].lex)->collum));add_childs((yyval.ast_tree), (yyvsp[-2].ast_tree));}
#line 2051 "y.tab.c"
    break;

  case 52:
#line 350 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1; flag_erro2 = 1;}
#line 2057 "y.tab.c"
    break;

  case 53:
#line 354 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 2063 "y.tab.c"
    break;

  case 54:
#line 355 "jucompiler.y"
                                                                                              {(yyval.ast_tree) = ast_node("Assign","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum); add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].lex)->name,(yyvsp[-2].lex)->line,(yyvsp[-2].lex)->collum)); add_childs((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 2069 "y.tab.c"
    break;

  case 55:
#line 358 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Add","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2075 "y.tab.c"
    break;

  case 56:
#line 359 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Sub","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2081 "y.tab.c"
    break;

  case 57:
#line 360 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Mul","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2087 "y.tab.c"
    break;

  case 58:
#line 361 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Div","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2093 "y.tab.c"
    break;

  case 59:
#line 362 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Mod","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2099 "y.tab.c"
    break;

  case 60:
#line 363 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Or","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2105 "y.tab.c"
    break;

  case 61:
#line 364 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Xor","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2111 "y.tab.c"
    break;

  case 62:
#line 365 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("And","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2117 "y.tab.c"
    break;

  case 63:
#line 366 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Lshift","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2123 "y.tab.c"
    break;

  case 64:
#line 367 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Rshift","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2129 "y.tab.c"
    break;

  case 65:
#line 368 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Eq","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2135 "y.tab.c"
    break;

  case 66:
#line 369 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Ne","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2141 "y.tab.c"
    break;

  case 67:
#line 370 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Lt","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2147 "y.tab.c"
    break;

  case 68:
#line 371 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Gt","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2153 "y.tab.c"
    break;

  case 69:
#line 372 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Le","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2159 "y.tab.c"
    break;

  case 70:
#line 373 "jucompiler.y"
                                                                                          {(yyval.ast_tree) = ast_node("Ge","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2165 "y.tab.c"
    break;

  case 71:
#line 374 "jucompiler.y"
                                                                                       {(yyval.ast_tree) = ast_node("Minus","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2171 "y.tab.c"
    break;

  case 72:
#line 375 "jucompiler.y"
                                                                                       {(yyval.ast_tree) = ast_node("Not","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2177 "y.tab.c"
    break;

  case 73:
#line 376 "jucompiler.y"
                                                                                       {(yyval.ast_tree) = ast_node("Plus","",(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum);add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2183 "y.tab.c"
    break;

  case 74:
#line 377 "jucompiler.y"
                                                                                       {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 2189 "y.tab.c"
    break;

  case 75:
#line 378 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("Id",(yyvsp[0].lex)->name,(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum);}
#line 2195 "y.tab.c"
    break;

  case 76:
#line 379 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("Length","",(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum); add_childs((yyval.ast_tree),ast_node("Id",(yyvsp[-1].lex)->name,(yyvsp[-1].lex)->line,(yyvsp[-1].lex)->collum));}
#line 2201 "y.tab.c"
    break;

  case 77:
#line 380 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("DecLit",(yyvsp[0].lex)->name,(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum);}
#line 2207 "y.tab.c"
    break;

  case 78:
#line 381 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("RealLit",(yyvsp[0].lex)->name,(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum);}
#line 2213 "y.tab.c"
    break;

  case 79:
#line 382 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = ast_node("BoolLit",(yyvsp[0].lex)->name,(yyvsp[0].lex)->line,(yyvsp[0].lex)->collum);}
#line 2219 "y.tab.c"
    break;

  case 80:
#line 383 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 2225 "y.tab.c"
    break;

  case 81:
#line 384 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 2231 "y.tab.c"
    break;

  case 82:
#line 385 "jucompiler.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1; flag_erro2 = 1;}
#line 2237 "y.tab.c"
    break;


#line 2241 "y.tab.c"

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
#line 388 "jucompiler.y"




int main(int argc, char *argv[]){
    if(argc >= 2){
        if(strcmp(argv[1],"-e1") == 0){
            /* Analise Lexical : Mostra so os erros */
            flag=0;
            yylex();
        }else if(strcmp(argv[1],"-l") == 0){
            /* Analise Lexical : Mostra os erros e os tokens */
            flag=1;
            yylex();
        }
        if(strcmp(argv[1],"-e2") == 0){
            /* Analise Sintatica : Mostra so os erros */
            flag=2;
            yyparse();
        }
        else if(strcmp(argv[1],"-t") == 0){
            /* Analise Sintatica : Mostra os erros e a arvore */
            flag=2;
            yyparse();
            if(flag_erro == 0){
                ast_print(raiz,0);
            }
        }
        else if(strcmp(argv[1],"-s") == 0){
            flag=2;
            yyparse();
            programCheck(raiz);
            Table();
            if(flag_erro == 0){
                ast_print(raiz,0);
            }
        }
    }else{
            flag=2;
            yyparse();
            if(raiz != NULL){
                programCheck(raiz);
            }
            
        }
    return 0;
}
