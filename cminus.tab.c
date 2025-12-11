/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cminusSintSem.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "parser_context.h"

    extern int yylex(void);
    /* extern int yyparse(void); */
    extern FILE *yyin;
    extern int yylineno;

    void yyerror(ParserContext *ctx, const char *s);

#line 85 "cminus.tab.c"

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

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUM = 4,                        /* NUM  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_LE = 11,                        /* LE  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_GE = 14,                        /* GE  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_NE = 16,                        /* NE  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_SEMI = 18,                      /* SEMI  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_LPAREN = 20,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 21,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 22,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 23,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_TIMES = 28,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 29,                    /* DIVIDE  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_program = 31,                   /* program  */
  YYSYMBOL_declaration_list = 32,          /* declaration_list  */
  YYSYMBOL_declaration = 33,               /* declaration  */
  YYSYMBOL_var_declaration = 34,           /* var_declaration  */
  YYSYMBOL_type_specifier = 35,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 36,           /* fun_declaration  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_param_list = 39,                /* param_list  */
  YYSYMBOL_param = 40,                     /* param  */
  YYSYMBOL_compound_stmt = 41,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 42,        /* local_declarations  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_compound_stmt_with_scope = 45,  /* compound_stmt_with_scope  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_expression_stmt = 47,           /* expression_stmt  */
  YYSYMBOL_selection_stmt = 48,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 49,            /* iteration_stmt  */
  YYSYMBOL_return_stmt = 50,               /* return_stmt  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_var = 52,                       /* var  */
  YYSYMBOL_simple_expression = 53,         /* simple_expression  */
  YYSYMBOL_relop = 54,                     /* relop  */
  YYSYMBOL_additive_expression = 55,       /* additive_expression  */
  YYSYMBOL_addop = 56,                     /* addop  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_mulop = 58,                     /* mulop  */
  YYSYMBOL_factor = 59,                    /* factor  */
  YYSYMBOL_call = 60,                      /* call  */
  YYSYMBOL_args = 61,                      /* args  */
  YYSYMBOL_arg_list = 62                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   154,   154,   168,   180,   185,   186,   191,   210,   245,
     248,   256,   255,   291,   292,   293,   298,   310,   315,   341,
     371,   381,   393,   398,   410,   415,   416,   417,   418,   419,
     423,   423,   433,   434,   439,   454,   473,   491,   497,   507,
     529,   534,   562,   594,   609,   613,   614,   615,   616,   617,
     618,   623,   638,   642,   643,   648,   663,   667,   668,   673,
     674,   675,   676,   687,   714,   715,   720,   732
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM", "ELSE",
  "IF", "INT", "RETURN", "VOID", "WHILE", "LE", "LT", "GT", "GE", "EQ",
  "NE", "ASSIGN", "SEMI", "COMMA", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "PLUS", "MINUS", "TIMES", "DIVIDE", "$accept",
  "program", "declaration_list", "declaration", "var_declaration",
  "type_specifier", "fun_declaration", "$@1", "params", "param_list",
  "param", "compound_stmt", "local_declarations", "statement_list",
  "statement", "compound_stmt_with_scope", "$@2", "expression_stmt",
  "selection_stmt", "iteration_stmt", "return_stmt", "expression", "var",
  "simple_expression", "relop", "additive_expression", "addop", "term",
  "mulop", "factor", "call", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,   -57,   -57,    22,     5,   -57,   -57,     4,   -57,   -57,
     -57,   -13,   -57,    29,     6,    17,    52,    27,    44,    63,
      46,    49,   -57,   -57,    47,    48,     5,    50,   -57,   -57,
     -57,   -57,     5,   -57,    67,    -2,   -13,    40,   -57,    51,
      26,    54,   -57,    28,   -57,   -57,   -57,    48,   -57,   -57,
     -57,   -57,    57,    59,   -57,    23,    24,   -57,   -57,    28,
      28,    28,   -57,    60,    28,    56,   -57,   -57,    28,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,    28,    28,   -57,
     -57,    28,   -57,    58,    61,    62,    65,   -57,    66,   -57,
     -57,   -57,    37,    24,   -57,   -57,    28,   -57,     7,     7,
     -57,    76,   -57,     7,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    11,     7,     0,     0,     0,    15,     0,    10,     0,
       0,    13,    17,     8,    18,     0,     0,     0,    22,    12,
      16,    19,    24,    21,     0,    30,     0,    41,    62,     0,
       0,     0,    33,     0,    20,    23,    26,     0,    25,    27,
      28,    29,     0,    60,    40,    44,    52,    56,    61,    65,
       0,     0,    37,     0,     0,     0,    31,    32,     0,    45,
      46,    47,    48,    49,    50,    53,    54,     0,     0,    57,
      58,     0,    67,     0,    64,     0,     0,    38,     0,    59,
      39,    60,    43,    51,    55,    63,     0,    42,    30,    30,
      66,    34,    36,    30,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,    78,    64,    25,   -57,   -57,   -57,   -57,
      68,    36,   -57,   -57,   -56,   -57,   -57,   -57,   -57,   -57,
     -57,   -40,   -23,   -57,   -57,    11,   -57,    12,   -57,     3,
     -57,   -57,   -57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    14,    20,    21,
      22,    29,    32,    35,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    77,    55,    78,    56,    81,    57,
      58,    83,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    37,    38,    65,    39,    12,    40,    11,    41,    13,
      37,    38,     1,    39,     2,    40,    42,    41,    43,    82,
      85,    86,     9,    44,    88,    42,    16,    43,    90,    37,
      38,    37,    38,    15,    69,    70,    71,    72,    73,    74,
      17,    19,   101,   102,    62,    23,    43,   104,    43,    75,
      76,    19,    79,    80,    91,    91,   100,    34,    91,     1,
      59,    18,    60,    75,    76,   -14,    24,    25,    26,    27,
      36,    61,    28,    31,    64,    67,    68,    89,    87,    95,
      96,   103,    10,    66,    94,    97,    98,    99,    92,     0,
      93,     0,     0,     0,    30,     0,    33
};

static const yytype_int8 yycheck[] =
{
      40,     3,     4,    43,     6,    18,     8,     3,    10,    22,
       3,     4,     7,     6,     9,     8,    18,    10,    20,    59,
      60,    61,     0,    25,    64,    18,    20,    20,    68,     3,
       4,     3,     4,     4,    11,    12,    13,    14,    15,    16,
      23,    16,    98,    99,    18,    18,    20,   103,    20,    26,
      27,    26,    28,    29,    77,    78,    96,    32,    81,     7,
      20,     9,    22,    26,    27,    21,     3,    21,    19,    22,
       3,    20,    24,    23,    20,    18,    17,    21,    18,    21,
      19,     5,     4,    47,    81,    23,    21,    21,    77,    -1,
      78,    -1,    -1,    -1,    26,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    31,    32,    33,    34,    35,    36,     0,
      33,     3,    18,    22,    37,     4,    20,    23,     9,    35,
      38,    39,    40,    18,     3,    21,    19,    22,    24,    41,
      40,    23,    42,    34,    35,    43,     3,     3,     4,     6,
       8,    10,    18,    20,    25,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    55,    57,    59,    60,    20,
      22,    20,    18,    51,    20,    51,    41,    18,    17,    11,
      12,    13,    14,    15,    16,    26,    27,    54,    56,    28,
      29,    58,    51,    61,    62,    51,    51,    18,    51,    21,
      51,    52,    55,    57,    59,    21,    19,    23,    21,    21,
      51,    44,    44,     5,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    35,
      35,    37,    36,    38,    38,    38,    39,    39,    40,    40,
      41,    42,    42,    43,    43,    44,    44,    44,    44,    44,
      46,    45,    47,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    60,    61,    61,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     0,     7,     1,     1,     0,     3,     1,     2,     4,
       4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       0,     2,     2,     1,     5,     7,     5,     2,     3,     3,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     4,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (ctx, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ParserContext *ctx)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ctx);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ParserContext *ctx)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ctx);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, ParserContext *ctx)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ctx); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, ParserContext *ctx)
{
  YY_USE (yyvaluep);
  YY_USE (ctx);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ParserContext *ctx)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: declaration_list  */
#line 155 "cminusSintSem.y"
    { 
        (yyval.node) = (yyvsp[0].node);
        ctx->ast_root = (yyval.node);
        printf("Analise sintatica concluida com sucesso!\n"); 
        if (!ctx->has_errors) {
            printf("Analise semantica: Nenhum erro encontrado.\n");
        }
        /* Impressão da AST movida para a main */
    }
#line 1214 "cminus.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 169 "cminusSintSem.y"
    {
        TreeNode *t = (yyvsp[-1].node);
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        } else {
            (yyval.node) = (yyvsp[0].node);
        }
    }
#line 1230 "cminus.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 180 "cminusSintSem.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1236 "cminus.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 185 "cminusSintSem.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1242 "cminus.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 186 "cminusSintSem.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1248 "cminus.tab.c"
    break;

  case 7: /* var_declaration: type_specifier ID SEMI  */
#line 192 "cminusSintSem.y"
    {
        /* Análise semântica */
        insert_symbol_ctx(ctx, (yyvsp[-1].id), (yyvsp[-2].tipo), KIND_VAR, yylineno);
        
        /* Construção da AST - padrão correto */
        (yyval.node) = newStmtNode((yyvsp[-2].tipo) == TYPE_INT ? INTEGERK : VOIDK);
        (yyval.node)->type = (yyvsp[-2].tipo);
        
        /* Criar nó ID e anexar como filho */
        (yyval.node)->child[0] = newVarNode(IDK);
        (yyval.node)->child[0]->kind.var.attr.name = strdup((yyvsp[-1].id));
        (yyval.node)->child[0]->kind.var.varKind = KIND_VAR;
        (yyval.node)->child[0]->kind.var.acesso = DECLK;
        (yyval.node)->child[0]->type = (yyvsp[-2].tipo);
        (yyval.node)->child[0]->lineno = yylineno;
        
        free((yyvsp[-1].id));
    }
#line 1271 "cminus.tab.c"
    break;

  case 8: /* var_declaration: type_specifier ID LBRACK NUM RBRACK SEMI  */
#line 211 "cminusSintSem.y"
    {
        /* Análise semântica */
        if ((yyvsp[-5].tipo) == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: array '%s' nao pode ser void\n", 
                    yylineno, (yyvsp[-4].id));
            ctx->has_errors = 1;
        } else {
            insert_array_ctx(ctx, (yyvsp[-4].id), (yyvsp[-2].ival), yylineno);
        }
        
        /* Construção da AST - padrão correto */
        (yyval.node) = newStmtNode((yyvsp[-5].tipo) == TYPE_INT ? INTEGERK : VOIDK);
        (yyval.node)->type = (yyvsp[-5].tipo);
        
        /* Criar nó ID array e anexar como filho */
        (yyval.node)->child[0] = newVarNode(VECTORK);
        (yyval.node)->child[0]->kind.var.attr.name = strdup((yyvsp[-4].id));
        (yyval.node)->child[0]->kind.var.varKind = KIND_ARRAY;
        (yyval.node)->child[0]->kind.var.acesso = DECLK;
        (yyval.node)->child[0]->type = (yyvsp[-5].tipo);
        (yyval.node)->child[0]->lineno = yylineno;
        
        /* Adicionar tamanho do array como filho do nó array */
        (yyval.node)->child[0]->child[0] = newExpNode(CONSTK);
        (yyval.node)->child[0]->child[0]->kind.var.attr.val = (yyvsp[-2].ival);
        (yyval.node)->child[0]->child[0]->type = TYPE_INT;
        (yyval.node)->child[0]->child[0]->lineno = yylineno;
        
        free((yyvsp[-4].id));
    }
#line 1306 "cminus.tab.c"
    break;

  case 9: /* type_specifier: INT  */
#line 245 "cminusSintSem.y"
         { 
        (yyval.tipo) = TYPE_INT;
    }
#line 1314 "cminus.tab.c"
    break;

  case 10: /* type_specifier: VOID  */
#line 248 "cminusSintSem.y"
           { 
        (yyval.tipo) = TYPE_VOID;
    }
#line 1322 "cminus.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 256 "cminusSintSem.y"
    {
        /* Análise semântica */
        insert_function_ctx(ctx, (yyvsp[0].id), (yyvsp[-1].tipo), yylineno);
        Simbolo *func_sym = lookup_symbol_current_ctx(ctx, (yyvsp[0].id));
        enter_scope_ctx(ctx);
        if (func_sym) {
            func_sym->def_scope = ctx->escopo_atual;
        }
    }
#line 1336 "cminus.tab.c"
    break;

  case 12: /* fun_declaration: type_specifier ID $@1 LPAREN params RPAREN compound_stmt  */
#line 266 "cminusSintSem.y"
    {
        leave_scope_ctx(ctx);
        
        /* Construção da AST - padrão correto */
        (yyval.node) = newStmtNode((yyvsp[-6].tipo) == TYPE_INT ? INTEGERK : VOIDK);
        (yyval.node)->type = (yyvsp[-6].tipo);
        
        /* Criar nó ID função e anexar como filho */
        (yyval.node)->child[0] = newVarNode(IDK);
        (yyval.node)->child[0]->kind.var.attr.name = strdup((yyvsp[-5].id));
        (yyval.node)->child[0]->kind.var.varKind = KIND_FUNC;
        (yyval.node)->child[0]->kind.var.acesso = DECLK;
        (yyval.node)->child[0]->type = (yyvsp[-6].tipo);
        (yyval.node)->child[0]->lineno = yylineno;
        
        /* Adicionar parâmetros e corpo como filhos do nó função */
        (yyval.node)->child[0]->child[0] = (yyvsp[-2].node);  /* parâmetros */
        (yyval.node)->child[0]->child[1] = (yyvsp[0].node);  /* corpo */
        
        free((yyvsp[-5].id));
    }
#line 1362 "cminus.tab.c"
    break;

  case 13: /* params: param_list  */
#line 291 "cminusSintSem.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1368 "cminus.tab.c"
    break;

  case 14: /* params: VOID  */
#line 292 "cminusSintSem.y"
           { (yyval.node) = NULL; }
#line 1374 "cminus.tab.c"
    break;

  case 15: /* params: %empty  */
#line 293 "cminusSintSem.y"
                  { (yyval.node) = NULL; }
#line 1380 "cminus.tab.c"
    break;

  case 16: /* param_list: param_list COMMA param  */
#line 299 "cminusSintSem.y"
    {
        TreeNode *t = (yyvsp[-2].node);
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-2].node);
        } else {
            (yyval.node) = (yyvsp[0].node);
        }
    }
#line 1396 "cminus.tab.c"
    break;

  case 17: /* param_list: param  */
#line 310 "cminusSintSem.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1402 "cminus.tab.c"
    break;

  case 18: /* param: type_specifier ID  */
#line 316 "cminusSintSem.y"
    {
        /* Análise semântica */
        if ((yyvsp[-1].tipo) == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: parametro '%s' nao pode ser void\n",
                    yylineno, (yyvsp[0].id));
            ctx->has_errors = 1;
        } else {
            insert_symbol_ctx(ctx, (yyvsp[0].id), (yyvsp[-1].tipo), KIND_VAR, yylineno);
            Simbolo *p = lookup_symbol_current_ctx(ctx, (yyvsp[0].id));
            if (p) p->is_param = 1;
        }
        
        /* Construção da AST - padrão correto */
        (yyval.node) = newStmtNode((yyvsp[-1].tipo) == TYPE_INT ? INTEGERK : VOIDK);
        (yyval.node)->type = (yyvsp[-1].tipo);
        
        (yyval.node)->child[0] = newVarNode(IDK);
        (yyval.node)->child[0]->kind.var.attr.name = strdup((yyvsp[0].id));
        (yyval.node)->child[0]->kind.var.varKind = KIND_VAR;
        (yyval.node)->child[0]->kind.var.acesso = DECLK;
        (yyval.node)->child[0]->type = (yyvsp[-1].tipo);
        (yyval.node)->child[0]->lineno = yylineno;
        
        free((yyvsp[0].id));
    }
#line 1432 "cminus.tab.c"
    break;

  case 19: /* param: type_specifier ID LBRACK RBRACK  */
#line 342 "cminusSintSem.y"
    {
        /* Análise semântica */
        if ((yyvsp[-3].tipo) == TYPE_VOID) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: parametro array '%s' nao pode ser void\n",
                    yylineno, (yyvsp[-2].id));
            ctx->has_errors = 1;
        } else {
            insert_symbol_ctx(ctx, (yyvsp[-2].id), TYPE_INT_ARRAY, KIND_ARRAY, yylineno);
            Simbolo *p = lookup_symbol_current_ctx(ctx, (yyvsp[-2].id));
            if (p) p->is_param = 1;
        }
        
        /* Construção da AST - padrão correto */
        (yyval.node) = newStmtNode((yyvsp[-3].tipo) == TYPE_INT ? INTEGERK : VOIDK);
        (yyval.node)->type = (yyvsp[-3].tipo);
        
        (yyval.node)->child[0] = newVarNode(VECTORK);
        (yyval.node)->child[0]->kind.var.attr.name = strdup((yyvsp[-2].id));
        (yyval.node)->child[0]->kind.var.varKind = KIND_ARRAY;
        (yyval.node)->child[0]->kind.var.acesso = DECLK;
        (yyval.node)->child[0]->type = TYPE_INT_ARRAY;
        (yyval.node)->child[0]->lineno = yylineno;
        
        free((yyvsp[-2].id));
    }
#line 1462 "cminus.tab.c"
    break;

  case 20: /* compound_stmt: LBRACE local_declarations statement_list RBRACE  */
#line 372 "cminusSintSem.y"
    {
        (yyval.node) = newStmtNode(COMPK);
        (yyval.node)->child[0] = (yyvsp[-2].node);  /* declarações locais */
        (yyval.node)->child[1] = (yyvsp[-1].node);  /* lista de statements */
        (yyval.node)->lineno = yylineno;
    }
#line 1473 "cminus.tab.c"
    break;

  case 21: /* local_declarations: local_declarations var_declaration  */
#line 382 "cminusSintSem.y"
    {
        TreeNode *t = (yyvsp[-1].node);
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        } else {
            (yyval.node) = (yyvsp[0].node);
        }
    }
#line 1489 "cminus.tab.c"
    break;

  case 22: /* local_declarations: %empty  */
#line 393 "cminusSintSem.y"
                  { (yyval.node) = NULL; }
#line 1495 "cminus.tab.c"
    break;

  case 23: /* statement_list: statement_list statement  */
#line 399 "cminusSintSem.y"
    {
        TreeNode *t = (yyvsp[-1].node);
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        } else {
            (yyval.node) = (yyvsp[0].node);
        }
    }
#line 1511 "cminus.tab.c"
    break;

  case 24: /* statement_list: %empty  */
#line 410 "cminusSintSem.y"
                  { (yyval.node) = NULL; }
#line 1517 "cminus.tab.c"
    break;

  case 25: /* statement: expression_stmt  */
#line 415 "cminusSintSem.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1523 "cminus.tab.c"
    break;

  case 26: /* statement: compound_stmt_with_scope  */
#line 416 "cminusSintSem.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1529 "cminus.tab.c"
    break;

  case 27: /* statement: selection_stmt  */
#line 417 "cminusSintSem.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1535 "cminus.tab.c"
    break;

  case 28: /* statement: iteration_stmt  */
#line 418 "cminusSintSem.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1541 "cminus.tab.c"
    break;

  case 29: /* statement: return_stmt  */
#line 419 "cminusSintSem.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1547 "cminus.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 423 "cminusSintSem.y"
    { enter_scope_ctx(ctx); }
#line 1553 "cminus.tab.c"
    break;

  case 31: /* compound_stmt_with_scope: $@2 compound_stmt  */
#line 425 "cminusSintSem.y"
    { 
        leave_scope_ctx(ctx);
        (yyval.node) = (yyvsp[0].node);
    }
#line 1562 "cminus.tab.c"
    break;

  case 32: /* expression_stmt: expression SEMI  */
#line 433 "cminusSintSem.y"
                    { (yyval.node) = (yyvsp[-1].node); }
#line 1568 "cminus.tab.c"
    break;

  case 33: /* expression_stmt: SEMI  */
#line 434 "cminusSintSem.y"
           { (yyval.node) = NULL; }
#line 1574 "cminus.tab.c"
    break;

  case 34: /* selection_stmt: IF LPAREN expression RPAREN statement  */
#line 440 "cminusSintSem.y"
    {
        /* Análise semântica */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->type != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do IF deve ser inteira\n", yylineno);
            ctx->has_errors = 1;
        }
        
        /* Construção da AST */
        (yyval.node) = newStmtNode(IFK);
        (yyval.node)->child[0] = (yyvsp[-2].node);    /* condição */
        (yyval.node)->child[1] = (yyvsp[0].node);    /* then */
        (yyval.node)->child[2] = NULL;  /* else */
        (yyval.node)->lineno = yylineno;
    }
#line 1593 "cminus.tab.c"
    break;

  case 35: /* selection_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 455 "cminusSintSem.y"
    {
        /* Análise semântica */
        if ((yyvsp[-4].node) && (yyvsp[-4].node)->type != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do IF deve ser inteira\n", yylineno);
            ctx->has_errors = 1;
        }
        
        /* Construção da AST */
        (yyval.node) = newStmtNode(IFK);
        (yyval.node)->child[0] = (yyvsp[-4].node);    /* condição */
        (yyval.node)->child[1] = (yyvsp[-2].node);    /* then */
        (yyval.node)->child[2] = (yyvsp[0].node);    /* else */
        (yyval.node)->lineno = yylineno;
    }
#line 1612 "cminus.tab.c"
    break;

  case 36: /* iteration_stmt: WHILE LPAREN expression RPAREN statement  */
#line 474 "cminusSintSem.y"
    {
        /* Análise semântica */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->type != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: condicao do WHILE deve ser inteira\n", yylineno);
            ctx->has_errors = 1;
        }
        
        /* Construção da AST */
        (yyval.node) = newStmtNode(WHILEK);
        (yyval.node)->child[0] = (yyvsp[-2].node);    /* condição */
        (yyval.node)->child[1] = (yyvsp[0].node);    /* corpo */
        (yyval.node)->lineno = yylineno;
    }
#line 1630 "cminus.tab.c"
    break;

  case 37: /* return_stmt: RETURN SEMI  */
#line 492 "cminusSintSem.y"
    {
        (yyval.node) = newStmtNode(RETURNK);
        (yyval.node)->child[0] = NULL;  /* sem expressão */
        (yyval.node)->lineno = yylineno;
    }
#line 1640 "cminus.tab.c"
    break;

  case 38: /* return_stmt: RETURN expression SEMI  */
#line 498 "cminusSintSem.y"
    {
        (yyval.node) = newStmtNode(RETURNK);
        (yyval.node)->child[0] = (yyvsp[-1].node);    /* expressão */
        (yyval.node)->lineno = yylineno;
    }
#line 1650 "cminus.tab.c"
    break;

  case 39: /* expression: var ASSIGN expression  */
#line 508 "cminusSintSem.y"
    {
        /* Análise semântica */
        TipoVar var_type = (yyvsp[-2].node) ? (yyvsp[-2].node)->type : TYPE_ERROR;
        TipoVar exp_type = (yyvsp[0].node) ? (yyvsp[0].node)->type : TYPE_ERROR;
        
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->nodekind == VARK && (yyvsp[-2].node)->kind.var.varKind == KIND_ARRAY && 
            (yyvsp[-2].node)->child[0] == NULL) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: nao e possivel atribuir a array completo\n", yylineno);
            ctx->has_errors = 1;
        } else if (var_type != exp_type && exp_type != TYPE_ERROR && var_type != TYPE_ERROR) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: tipos incompativeis na atribuicao\n", yylineno);
            ctx->has_errors = 1;
        }
        
        /* Construção da AST */
        (yyval.node) = newExpNode(ASSIGNK);
        (yyval.node)->child[0] = (yyvsp[-2].node);
        (yyval.node)->child[1] = (yyvsp[0].node);
        (yyval.node)->type = var_type;
        (yyval.node)->lineno = yylineno;
    }
#line 1676 "cminus.tab.c"
    break;

  case 40: /* expression: simple_expression  */
#line 529 "cminusSintSem.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1682 "cminus.tab.c"
    break;

  case 41: /* var: ID  */
#line 535 "cminusSintSem.y"
    {
        Simbolo *s = lookup_symbol_ctx(ctx, (yyvsp[0].id));
        TipoVar tipo = TYPE_ERROR;
        TipoSimbolo kind = KIND_VAR;
        
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: variavel '%s' nao declarada\n", yylineno, (yyvsp[0].id));
            ctx->has_errors = 1;
        } else {
            tipo = s->tipo;
            kind = s->kind;
        }
        
        /* Cria nó de variável */
        if (kind == KIND_ARRAY) {
            (yyval.node) = newVarNode(VECTORK);
            (yyval.node)->type = TYPE_INT_ARRAY;
        } else {
            (yyval.node) = newVarNode(IDK);
            (yyval.node)->type = tipo;
        }
        (yyval.node)->kind.var.attr.name = strdup((yyvsp[0].id));
        (yyval.node)->kind.var.varKind = kind;
        (yyval.node)->kind.var.acesso = ACCESSK;
        (yyval.node)->lineno = yylineno;
        free((yyvsp[0].id));
    }
#line 1714 "cminus.tab.c"
    break;

  case 42: /* var: ID LBRACK expression RBRACK  */
#line 563 "cminusSintSem.y"
    {
        Simbolo *s = lookup_symbol_ctx(ctx, (yyvsp[-3].id));
        TipoVar tipo = TYPE_ERROR;
        
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: variavel '%s' nao declarada\n", yylineno, (yyvsp[-3].id));
            ctx->has_errors = 1;
        } else if (s->kind != KIND_ARRAY) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' nao e um array\n", yylineno, (yyvsp[-3].id));
            ctx->has_errors = 1;
        } else if ((yyvsp[-1].node) && (yyvsp[-1].node)->type != TYPE_INT) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: indice de array deve ser inteiro\n", yylineno);
            ctx->has_errors = 1;
        } else {
            tipo = TYPE_INT;
        }
        
        /* Cria nó de acesso a array */
        (yyval.node) = newVarNode(VECTORK);
        (yyval.node)->kind.var.attr.name = strdup((yyvsp[-3].id));
        (yyval.node)->kind.var.varKind = KIND_ARRAY;
        (yyval.node)->kind.var.acesso = ACCESSK;
        (yyval.node)->child[0] = (yyvsp[-1].node);  /* índice */
        (yyval.node)->type = tipo;
        (yyval.node)->lineno = yylineno;
        free((yyvsp[-3].id));
    }
#line 1746 "cminus.tab.c"
    break;

  case 43: /* simple_expression: additive_expression relop additive_expression  */
#line 595 "cminusSintSem.y"
    {
        /* Análise semântica */
        TipoVar t1 = (yyvsp[-2].node) ? (yyvsp[-2].node)->type : TYPE_ERROR;
        TipoVar t2 = (yyvsp[0].node) ? (yyvsp[0].node)->type : TYPE_ERROR;
        TipoVar result = check_expression_type_ctx(ctx, "relacional", t1, t2, yylineno);
        
        /* Construção da AST */
        (yyval.node) = newExpNode(OPK);
        (yyval.node)->child[0] = (yyvsp[-2].node);
        (yyval.node)->child[1] = (yyvsp[0].node);
        (yyval.node)->op = (yyvsp[-1].ival);  /* operador relacional */
        (yyval.node)->type = result;
        (yyval.node)->lineno = yylineno;
    }
#line 1765 "cminus.tab.c"
    break;

  case 44: /* simple_expression: additive_expression  */
#line 609 "cminusSintSem.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1771 "cminus.tab.c"
    break;

  case 45: /* relop: LE  */
#line 613 "cminusSintSem.y"
           { (yyval.ival) = LE; }
#line 1777 "cminus.tab.c"
    break;

  case 46: /* relop: LT  */
#line 614 "cminusSintSem.y"
           { (yyval.ival) = LT; }
#line 1783 "cminus.tab.c"
    break;

  case 47: /* relop: GT  */
#line 615 "cminusSintSem.y"
           { (yyval.ival) = GT; }
#line 1789 "cminus.tab.c"
    break;

  case 48: /* relop: GE  */
#line 616 "cminusSintSem.y"
           { (yyval.ival) = GE; }
#line 1795 "cminus.tab.c"
    break;

  case 49: /* relop: EQ  */
#line 617 "cminusSintSem.y"
           { (yyval.ival) = EQ; }
#line 1801 "cminus.tab.c"
    break;

  case 50: /* relop: NE  */
#line 618 "cminusSintSem.y"
           { (yyval.ival) = NE; }
#line 1807 "cminus.tab.c"
    break;

  case 51: /* additive_expression: additive_expression addop term  */
#line 624 "cminusSintSem.y"
    {
        /* Análise semântica */
        TipoVar t1 = (yyvsp[-2].node) ? (yyvsp[-2].node)->type : TYPE_ERROR;
        TipoVar t2 = (yyvsp[0].node) ? (yyvsp[0].node)->type : TYPE_ERROR;
        TipoVar result = check_expression_type_ctx(ctx, "aditivo", t1, t2, yylineno);
        
        /* Construção da AST */
        (yyval.node) = newExpNode(OPK);
        (yyval.node)->child[0] = (yyvsp[-2].node);
        (yyval.node)->child[1] = (yyvsp[0].node);
        (yyval.node)->op = (yyvsp[-1].ival);  /* operador aditivo */
        (yyval.node)->type = result;
        (yyval.node)->lineno = yylineno;
    }
#line 1826 "cminus.tab.c"
    break;

  case 52: /* additive_expression: term  */
#line 638 "cminusSintSem.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1832 "cminus.tab.c"
    break;

  case 53: /* addop: PLUS  */
#line 642 "cminusSintSem.y"
             { (yyval.ival) = PLUS; }
#line 1838 "cminus.tab.c"
    break;

  case 54: /* addop: MINUS  */
#line 643 "cminusSintSem.y"
              { (yyval.ival) = MINUS; }
#line 1844 "cminus.tab.c"
    break;

  case 55: /* term: term mulop factor  */
#line 649 "cminusSintSem.y"
    {
        /* Análise semântica */
        TipoVar t1 = (yyvsp[-2].node) ? (yyvsp[-2].node)->type : TYPE_ERROR;
        TipoVar t2 = (yyvsp[0].node) ? (yyvsp[0].node)->type : TYPE_ERROR;
        TipoVar result = check_expression_type_ctx(ctx, "multiplicativo", t1, t2, yylineno);
        
        /* Construção da AST */
        (yyval.node) = newExpNode(OPK);
        (yyval.node)->child[0] = (yyvsp[-2].node);
        (yyval.node)->child[1] = (yyvsp[0].node);
        (yyval.node)->op = (yyvsp[-1].ival);  /* operador multiplicativo */
        (yyval.node)->type = result;
        (yyval.node)->lineno = yylineno;
    }
#line 1863 "cminus.tab.c"
    break;

  case 56: /* term: factor  */
#line 663 "cminusSintSem.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1869 "cminus.tab.c"
    break;

  case 57: /* mulop: TIMES  */
#line 667 "cminusSintSem.y"
              { (yyval.ival) = TIMES; }
#line 1875 "cminus.tab.c"
    break;

  case 58: /* mulop: DIVIDE  */
#line 668 "cminusSintSem.y"
               { (yyval.ival) = DIVIDE; }
#line 1881 "cminus.tab.c"
    break;

  case 59: /* factor: LPAREN expression RPAREN  */
#line 673 "cminusSintSem.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 1887 "cminus.tab.c"
    break;

  case 60: /* factor: var  */
#line 674 "cminusSintSem.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1893 "cminus.tab.c"
    break;

  case 61: /* factor: call  */
#line 675 "cminusSintSem.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1899 "cminus.tab.c"
    break;

  case 62: /* factor: NUM  */
#line 677 "cminusSintSem.y"
    { 
        (yyval.node) = newExpNode(CONSTK);
        (yyval.node)->kind.var.attr.val = (yyvsp[0].ival);
        (yyval.node)->type = TYPE_INT;
        (yyval.node)->lineno = yylineno;
    }
#line 1910 "cminus.tab.c"
    break;

  case 63: /* call: ID LPAREN args RPAREN  */
#line 688 "cminusSintSem.y"
    {
        Simbolo *s = lookup_symbol_ctx(ctx, (yyvsp[-3].id));
        TipoVar tipo = TYPE_INT;  /* padrão */
        
        if (!s) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: funcao '%s' nao declarada\n", yylineno, (yyvsp[-3].id));
            ctx->has_errors = 1;
        } else if (s->kind != KIND_FUNC) {
            fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' nao e uma funcao\n", yylineno, (yyvsp[-3].id));
            ctx->has_errors = 1;
        } else {
            tipo = s->tipo;  /* tipo de retorno da função */
        }
        
        /* Cria nó de chamada de função */
        (yyval.node) = newExpNode(CALLK);
        (yyval.node)->kind.var.attr.name = strdup((yyvsp[-3].id));
        (yyval.node)->child[0] = (yyvsp[-1].node);  /* argumentos */
        (yyval.node)->type = tipo;
        (yyval.node)->lineno = yylineno;
        free((yyvsp[-3].id));
    }
#line 1937 "cminus.tab.c"
    break;

  case 64: /* args: arg_list  */
#line 714 "cminusSintSem.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1943 "cminus.tab.c"
    break;

  case 65: /* args: %empty  */
#line 715 "cminusSintSem.y"
                  { (yyval.node) = NULL; }
#line 1949 "cminus.tab.c"
    break;

  case 66: /* arg_list: arg_list COMMA expression  */
#line 721 "cminusSintSem.y"
    {
        TreeNode *t = (yyvsp[-2].node);
        if (t != NULL) {
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-2].node);
        } else {
            (yyval.node) = (yyvsp[0].node);
        }
    }
#line 1965 "cminus.tab.c"
    break;

  case 67: /* arg_list: expression  */
#line 732 "cminusSintSem.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1971 "cminus.tab.c"
    break;


#line 1975 "cminus.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (ctx, YY_("syntax error"));
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
                      yytoken, &yylval, ctx);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (ctx, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 735 "cminusSintSem.y"


/* ===== FUNÇÕES PARA GRAPHVIZ ===== */

/* Estrutura par contexto de impressão DOT */
typedef struct {
    int node_counter;
    FILE *fp;
} DotContext;

/* Função auxiliar para escapar strings */
static char *escape_label(const char *str) {
    if (!str) return strdup("");

    int len = strlen(str);
    char *escaped = (char *)malloc(len * 2 + 1);
    
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '"' || str[i] == '\\') {
            escaped[j++] = '\\';
        }

        escaped[j++] = str[i];
    }

    escaped[j] = '\0';

    return escaped;
}

/* Função para obter nome do tipo */
static const char* get_type_name(TipoVar type) {
    switch (type) {
        case TYPE_INT: return "int";
        case TYPE_VOID: return "void";
        case TYPE_INT_ARRAY: return "int[]";
        case TYPE_ERROR: return "ERROR";
        default: return "unknown";
    }
}

/* Função para obter símbolo do operador */
static const char* get_op_symbol(int op) {
    switch (op) {
        case PLUS: return "+";
        case MINUS: return "-";
        case TIMES: return "*";
        case DIVIDE: return "/";
        case LT: return "<";
        case LE: return "<=";
        case GT: return ">";
        case GE: return ">=";
        case EQ: return "==";
        case NE: return "!=";
        default: return "?";
    }
}

/* Função recursiva para gerar GraphViz DOT */
static int printTreeDOT_recursive(DotContext *ctx, TreeNode *tree, int parent_id) {
    if (tree == NULL) return -1;
    
    int current_id = ctx->node_counter++;
    FILE *fp = ctx->fp;
    
    /* Define cor e forma do nó */
    const char *shape = "box";
    const char *color = "lightblue";
    char label[256] = "";
    
    if (tree->nodekind == STMTK) {
        color = "lightgreen";
        switch (tree->kind.stmt) {
            case INTEGERK:
                if (tree->child[0] && tree->child[0]->nodekind == VARK) {
                    if (tree->child[0]->kind.var.varKind == KIND_FUNC) {
                        snprintf(label, sizeof(label), "Function\\n[int]");
                        color = "gold";
                    } else if (tree->child[0]->kind.var.varKind == KIND_ARRAY) {
                        snprintf(label, sizeof(label), "Array Decl\\n[int]");
                    } else {
                        snprintf(label, sizeof(label), "Var Decl\\n[int]");
                    }
                } else {
                    snprintf(label, sizeof(label), "Type: int");
                }
                break;
            case VOIDK:
                if (tree->child[0] && tree->child[0]->nodekind == VARK && 
                    tree->child[0]->kind.var.varKind == KIND_FUNC) {
                    snprintf(label, sizeof(label), "Function\\n[void]");
                    color = "gold";
                } else {
                    snprintf(label, sizeof(label), "Type: void");
                }
                break;
            case IFK: 
                snprintf(label, sizeof(label), "IF"); 
                color = "orange";
                break;
            case WHILEK: 
                snprintf(label, sizeof(label), "WHILE"); 
                color = "orange";
                break;
            case RETURNK: 
                snprintf(label, sizeof(label), "RETURN"); 
                color = "pink";
                break;
            case COMPK: 
                snprintf(label, sizeof(label), "Compound\\nStatement"); 
                color = "lightcyan";
                break;
        }
    } else if (tree->nodekind == VARK) {
        color = "lightyellow";
        char *esc_name = escape_label(tree->kind.var.attr.name);
        
        if (tree->kind.var.varKind == KIND_FUNC) {
            snprintf(label, sizeof(label), "%s\\n(function)", esc_name);
        } else if (tree->kind.var.varKind == KIND_ARRAY) {
            if (tree->kind.var.acesso == DECLK) {
                snprintf(label, sizeof(label), "%s\\n(array decl)", esc_name);
            } else {
                snprintf(label, sizeof(label), "%s\\n(array access)", esc_name);
            }
        } else {
            if (tree->kind.var.acesso == DECLK) {
                snprintf(label, sizeof(label), "%s\\n(declaration)", esc_name);
            } else {
                snprintf(label, sizeof(label), "%s\\n(variable)", esc_name);
            }
        }
        free(esc_name);
    } else if (tree->nodekind == EXPK) {
        color = "lavender";
        switch (tree->kind.exp) {
            case OPK:
                snprintf(label, sizeof(label), "Op: %s", get_op_symbol(tree->op));
                color = "plum";
                shape = "ellipse";
                break;
            case CONSTK:
                snprintf(label, sizeof(label), "Const\\n%d", tree->kind.var.attr.val);
                color = "lightpink";
                shape = "ellipse";
                break;
            case IDK: {
                char *esc_name = escape_label(tree->kind.var.attr.name);
                snprintf(label, sizeof(label), "ID: %s", esc_name);
                free(esc_name);
                break;
            }
            case ASSIGNK:
                snprintf(label, sizeof(label), "Assign\\n=");
                color = "khaki";
                break;
            case CALLK: {
                char *esc_name = escape_label(tree->kind.var.attr.name);
                snprintf(label, sizeof(label), "Call\\n%s()", esc_name);
                free(esc_name);
                color = "peachpuff";
                break;
            }
            case VECTORK: {
                char *esc_name = escape_label(tree->kind.var.attr.name);
                if (tree->child[0]) {
                    snprintf(label, sizeof(label), "Vector\\n%s[..]", esc_name);
                } else {
                    snprintf(label, sizeof(label), "Vector\\n%s", esc_name);
                }
                free(esc_name);
                break;
            }
        }
    }
    
    /* Cria o nó */
    fprintf(fp, "  node%d [label=\"%s\", shape=%s, style=\"filled\", fillcolor=%s];\n",
            current_id, label, shape, color);
    
    /* Liga ao pai se existir */
    if (parent_id >= 0) {
        fprintf(fp, "  node%d -> node%d;\n", parent_id, current_id);
    }
    
    /* Processa filhos */
    for (int i = 0; i < MAXCHILDREN; i++) {
        if (tree->child[i] != NULL) {
            printTreeDOT_recursive(ctx, tree->child[i], current_id);
        }
    }
    
    /* Processa irmãos */
    if (tree->sibling != NULL) {
        int sibling_id = printTreeDOT_recursive(ctx, tree->sibling, parent_id);
        if (sibling_id >= 0) {
            fprintf(fp, "  node%d -> node%d [style=dashed, color=gray, constraint=false];\n",
                    current_id, sibling_id);
        }
    }
    
    return current_id;
}

/* Função principal para gerar arquivo DOT */
void printTreeDOT(TreeNode *tree, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Erro: nao foi possivel criar arquivo '%s'\n", filename);
        return;
    }
    
    /* Cria contexto */
    DotContext ctx = {0, fp};
    
    /* Cabeçalho */
    fprintf(fp, "digraph AST {\n");
    fprintf(fp, "  rankdir=TB;\n");
    fprintf(fp, "  node [fontname=\"Arial\", fontsize=12];\n");
    fprintf(fp, "  edge [fontname=\"Arial\", fontsize=10];\n");
    fprintf(fp, "  \n");
    
    /* Gera a árvore */
    printTreeDOT_recursive(&ctx, tree, -1);
    
    /* Rodapé */
    fprintf(fp, "}\n");
    
    fclose(fp);
    printf("\nArquivo GraphViz gerado: %s\n", filename);
    printf("Para gerar a imagem, execute:\n");
    printf("  dot -Tpng %s -o ast.png\n", filename);
    printf("  ou\n");
    printf("  dot -Tsvg %s -o ast.svg\n", filename);
}

/* ===== IMPLEMENTAÇÃO DA TABELA DE SÍMBOLOS ===== */

void enter_scope_ctx(ParserContext *ctx) {
    Escopo *novo = (Escopo*) malloc(sizeof(Escopo));
    novo->simbolos = NULL;
    novo->pai = ctx->escopo_atual;
    novo->next_all = ctx->lista_escopos;
    ctx->lista_escopos = novo;
    ctx->escopo_atual = novo;
}

void leave_scope_ctx(ParserContext *ctx) {
    if (!ctx->escopo_atual) return;
    ctx->escopo_atual = ctx->escopo_atual->pai;
}

Simbolo* lookup_symbol_current_ctx(ParserContext *ctx, const char *nome) {
    if (!ctx->escopo_atual) return NULL;
    Simbolo *s = ctx->escopo_atual->simbolos;
    while (s) {
        if (strcmp(s->nome, nome) == 0) return s;
        s = s->prox;
    }
    return NULL;
}

Simbolo* lookup_symbol_ctx(ParserContext *ctx, const char *nome) {
    Escopo *e = ctx->escopo_atual;
    while (e) {
        Simbolo *s = e->simbolos;
        while (s) {
            if (strcmp(s->nome, nome) == 0) return s;
            s = s->prox;
        }
        e = e->pai;
    }
    return NULL;
}

void insert_symbol_ctx(ParserContext *ctx, const char *nome, TipoVar tipo, TipoSimbolo kind, int linha) {
    if (!ctx->escopo_atual) {
        fprintf(stderr, "Erro interno: nenhum escopo ativo\n");
        return;
    }
    
    if (lookup_symbol_current_ctx(ctx, nome)) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' ja declarado neste escopo\n", linha, nome);
        ctx->has_errors = 1;
        return;
    }
    
    Simbolo *s = (Simbolo*) malloc(sizeof(Simbolo));
    s->nome = strdup(nome);
    s->tipo = tipo;
    s->kind = kind;
    s->tamanho = 0;
    s->num_params = 0;
    s->param_types = NULL;
    s->linha = linha;
    s->prox = ctx->escopo_atual->simbolos;
    s->is_param = 0;
    s->def_scope = NULL;
    ctx->escopo_atual->simbolos = s;
}

void insert_array_ctx(ParserContext *ctx, const char *nome, int tamanho, int linha) {
    if (!ctx->escopo_atual) return;
    
    if (lookup_symbol_current_ctx(ctx, nome)) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' ja declarado neste escopo\n", linha, nome);
        ctx->has_errors = 1;
        return;
    }
    
    Simbolo *s = (Simbolo*) malloc(sizeof(Simbolo));
    s->nome = strdup(nome);
    s->tipo = TYPE_INT_ARRAY;
    s->kind = KIND_ARRAY;
    s->tamanho = tamanho;
    s->num_params = 0;
    s->param_types = NULL;
    s->linha = linha;
    s->prox = ctx->escopo_atual->simbolos;
    ctx->escopo_atual->simbolos = s;
}

void insert_function_ctx(ParserContext *ctx, const char *nome, TipoVar tipo_retorno, int linha) {
    if (!ctx->escopo_atual) return;
    
    if (lookup_symbol_current_ctx(ctx, nome)) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: '%s' ja declarado neste escopo\n", linha, nome);
        ctx->has_errors = 1;
        return;
    }
    
    Simbolo *s = (Simbolo*) malloc(sizeof(Simbolo));
    s->nome = strdup(nome);
    s->tipo = tipo_retorno;
    s->kind = KIND_FUNC;
    s->tamanho = 0;
    s->num_params = 0;
    s->param_types = NULL;
    s->linha = linha;
    s->prox = ctx->escopo_atual->simbolos;
    ctx->escopo_atual->simbolos = s;
}

TipoVar check_expression_type_ctx(ParserContext *ctx, const char *op, TipoVar t1, TipoVar t2, int linha) {
    if (t1 == TYPE_ERROR || t2 == TYPE_ERROR) {
        return TYPE_ERROR;
    }
    
    if (t1 == TYPE_VOID || t2 == TYPE_VOID) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: operacao %s com tipo void\n", linha, op);
        ctx->has_errors = 1;
        return TYPE_ERROR;
    }
    
    if (t1 != TYPE_INT || t2 != TYPE_INT) {
        fprintf(stderr, "ERRO SEMANTICO: linha %d: operacao %s requer operandos inteiros\n", linha, op);
        ctx->has_errors = 1;
        return TYPE_ERROR;
    }
    
    return TYPE_INT;
}

void ExibirTabelaSimbolos_ctx(ParserContext *ctx) {
    printf("\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("|                      TABELA DE SIMBOLOS DO COMPILADOR C-MINUS                      |\n");
    printf("--------------------------------------------------------------------------------------\n");
    
    printf("\n%-20s | %-10s | %-8s | %-10s | %-8s | %-6s | %s\n", 
           "NOME", "TIPO", "CATEGORIA", "ESCOPO", "TAMANHO", "PARAMS", "LINHA");
    printf("%-20s-%-10s-%-8s-%-10s-%-8s-%-6s---------\n",
           "--------------------", "----------", "--------", "----------", "--------", "------");
    
    /* Conta e armazena ponteiros para todos os escopos */
    int count = 0;
    Escopo *e = ctx->lista_escopos;
    while (e) { count++; e = e->next_all; }
    if (count == 0) {
        printf("\n");
        return;
    }
    
    Escopo **arr = (Escopo**) malloc(count * sizeof(Escopo*));
    int i = 0;
    e = ctx->lista_escopos;
    while (e) { arr[i++] = e; e = e->next_all; }

    /* printf("%-6d | ", computed_params); */
    
    /* Imprime do escopo mais antigo (global) para o mais interno,
       atribuindo escopo_num começando em 0 */
    int escopo_num = 0;
    for (int idx = count - 1; idx >= 0; idx--) {
        Simbolo *s = arr[idx]->simbolos;
        while (s) {
            printf("%-20s | ", s->nome);
            
            /* Tipo */
            switch (s->tipo) {
                case TYPE_INT:        printf("%-10s | ", "int"); break;
                case TYPE_VOID:       printf("%-10s | ", "void"); break;
                case TYPE_INT_ARRAY:  printf("%-10s | ", "int[]"); break;
                case TYPE_ERROR:      printf("%-10s | ", "ERROR"); break;
            }
            
            /* Tipo de Símbolo */
            switch (s->kind) {
                case KIND_VAR:   printf("%-8s | ", "VAR"); break;
                case KIND_ARRAY: printf("%-8s | ", "ARRAY"); break;
                case KIND_FUNC:  printf("%-8s | ", "FUNC"); break;
            }
            
            /* Escopo */
            printf("%-10d | ", escopo_num);
            
            /* Tamanho ou Params */
            if (s->kind == KIND_ARRAY) {
                printf("%-8d | ", s->tamanho);
            } else if (s->kind == KIND_FUNC) {
                printf("%-8s | ", "-");
            } else {
                printf("%-8s | ", "-");
            }
            
            /* Número de parâmetros */
            if (s->kind == KIND_FUNC) {
                int computed_params = 0;
                if (s->def_scope) {
                    Simbolo *ps = s->def_scope->simbolos;
                    while (ps) {
                        if (ps->is_param) computed_params++;
                        ps = ps->prox;
                    }
                }
                printf("%-6d | ", computed_params);
            } else {
                printf("%-6s | ", "-");
            }
            
            printf("%d\n", s->linha);
            s = s->prox;
        }
        escopo_num++;
    }
    
    free(arr);
    printf("\n");
}

void free_all_scopes_ctx(ParserContext *ctx) {
    Escopo *e = ctx->lista_escopos;
    while (e) {
        Simbolo *s = e->simbolos;
        while (s) {
            Simbolo *tmp = s;
            s = s->prox;
            free(tmp->nome);
            if (tmp->param_types) free(tmp->param_types);
            free(tmp);
        }
        Escopo *tmp_e = e;
        e = e->next_all;
        free(tmp_e);
    }
    ctx->lista_escopos = NULL;
    ctx->escopo_atual = NULL;
}

/* ===== IMPLEMENTAÇÃO DAS FUNÇÕES DA AST ===== */

/* Cria nó de statement */
TreeNode* newStmtNode(StmtKind kind) {
    TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    if (t == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para TreeNode\n");
        exit(1);
    }
    for (int i = 0; i < MAXCHILDREN; i++)
        t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = STMTK;
    t->kind.stmt = kind;
    t->lineno = yylineno;
    t->type = TYPE_VOID;
    t->op = 0;
    return t;
}

/* Cria nó de expressão */
TreeNode* newExpNode(ExpKind kind) {
    TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    if (t == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para TreeNode\n");
        exit(1);
    }
    for (int i = 0; i < MAXCHILDREN; i++)
        t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = EXPK;
    t->kind.exp = kind;
    t->lineno = yylineno;
    t->type = TYPE_INT;
    t->op = 0;
    t->kind.var.attr.name = NULL;
    return t;
}

/* Cria nó de variável/identificador */
TreeNode* newVarNode(ExpKind kind) {
    TreeNode *t = (TreeNode*) malloc(sizeof(TreeNode));
    if (t == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para TreeNode\n");
        exit(1);
    }
    for (int i = 0; i < MAXCHILDREN; i++)
        t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = VARK;
    t->kind.var.acesso = DECLK;
    t->kind.var.varKind = KIND_VAR;
    t->kind.var.attr.name = NULL;
    t->lineno = yylineno;
    t->type = TYPE_INT;
    t->op = 0;
    return t;
}

/* Imprime a árvore sintática */
void printTree(TreeNode *tree, int indent) {
    if (tree == NULL) return;
    
    /* Imprime indentação */
    for (int i = 0; i < indent; i++)
        printf("  ");
    
    /* Imprime tipo do nó */
    if (tree->nodekind == STMTK) {
        switch (tree->kind.stmt) {
            case INTEGERK:
                printf("[int]");
                if (tree->child[0]) {
                    if (tree->child[0]->nodekind == VARK) {
                        if (tree->child[0]->kind.var.varKind == KIND_FUNC) {
                            printf(" Function");
                        } else if (tree->child[0]->kind.var.varKind == KIND_ARRAY) {
                            printf(" Array");
                        } else {
                            printf(" Var");
                        }
                    }
                }
                printf("\n");
                break;
            case VOIDK:
                printf("[void]");
                if (tree->child[0] && tree->child[0]->nodekind == VARK && 
                    tree->child[0]->kind.var.varKind == KIND_FUNC) {
                    printf(" Function");
                }
                printf("\n");
                break;
            case IFK: printf("If\n"); break;
            case WHILEK: printf("While\n"); break;
            case RETURNK: printf("Return\n"); break;
            case COMPK: printf("Compound Statement\n"); break;
        }
    } else if (tree->nodekind == VARK) {
        printf("[%s]", tree->kind.var.attr.name);
        if (tree->kind.var.varKind == KIND_FUNC) {
            printf(" (function)");
        } else if (tree->kind.var.varKind == KIND_ARRAY) {
            printf(" (array)");
        } else if (tree->kind.var.varKind == KIND_VAR) {
            if (tree->kind.var.acesso == DECLK) {
                printf(" (declaration)");
            } else {
                printf(" (access)");
            }
        }
        printf("\n");
    } else if (tree->nodekind == EXPK) {
        switch (tree->kind.exp) {
            case OPK:
                printf("Op: ");
                switch (tree->op) {
                    case PLUS: printf("+"); break;
                    case MINUS: printf("-"); break;
                    case TIMES: printf("*"); break;
                    case DIVIDE: printf("/"); break;
                    case LT: printf("<"); break;
                    case LE: printf("<="); break;
                    case GT: printf(">"); break;
                    case GE: printf(">="); break;
                    case EQ: printf("=="); break;
                    case NE: printf("!="); break;
                    default: printf("?"); break;
                }
                printf("\n");
                break;
            case CONSTK: printf("Const: %d\n", tree->kind.var.attr.val); break;
            case IDK: printf("Id: %s\n", tree->kind.var.attr.name); break;
            case ASSIGNK: printf("Assign (=)\n"); break;
            case CALLK: printf("Call: %s()\n", tree->kind.var.attr.name); break;
            case VECTORK: printf("Vector: %s", tree->kind.var.attr.name); 
                if (tree->child[0]) printf(" [indexed]");
                printf("\n");
                break;
        }
    }
    
    /* Imprime filhos */
    for (int i = 0; i < MAXCHILDREN; i++)
        printTree(tree->child[i], indent + 1);
    
    /* Imprime irmãos */
    printTree(tree->sibling, indent);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Erro: nao foi possivel abrir arquivo '%s'\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }

    /* Cria contexto do parser */
    ParserContext *ctx = parser_context_create();

    if (!ctx) {
        fprintf(stderr, "Erro: falha ao criar o contexto do parser\n");
        if (yyin != stdin) fclose(yyin);
        return 1;
    }
    
    /* Cria escopo global */
    enter_scope_ctx(ctx);
    
    /* Adiciona funções built-in input e output */
    insert_symbol_ctx(ctx, "input", TYPE_INT, KIND_FUNC, 0);
    insert_symbol_ctx(ctx, "output", TYPE_VOID, KIND_FUNC, 0);
    
    yyparse(ctx);
    
    ExibirTabelaSimbolos_ctx(ctx);

    /* Se não houver erros, imprime a AST */
    if (!ctx->has_errors && ctx->ast_root) {
        printf("\n");
        printf("================================================================================\n");
        printf("                      ARVORE SINTATICA ABSTRATA (AST)\n");
        printf("================================================================================\n");
        printTree(ctx->ast_root, 0);
        printf("================================================================================\n");

        printTreeDOT(ctx->ast_root, "ast.dot");
    }

    /* Libera todos os escopos e simbolos */
    free_all_scopes_ctx(ctx);

    int return_code = ctx->has_errors ? 1 : 0;

    parser_context_destroy(ctx);
    
    if (yyin != stdin) fclose(yyin);

    return return_code;
}

void yyerror(ParserContext *ctx, const char *s) {
    fprintf(stderr, "Erro sintatico linha %d: %s\n", yylineno, s);
    ctx->has_errors = 1;
}
