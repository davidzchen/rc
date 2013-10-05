/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 7 "src/parse.y"

/* note that this actually needs to appear before any system header
   files are included; byacc likes to throw in <stdlib.h> first. */
#include "rc.h"
#include "lex.h"
#include "heredoc.h"
#include "tree.h"
#include "nalloc.h"

static Node *star, *nolist;
Node *parsetree;	/* not using yylval because bison declares it as an auto */


/* Line 268 of yacc.c  */
#line 85 "y.tab.c"

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
     ANDAND = 258,
     BACKBACK = 259,
     BANG = 260,
     CASE = 261,
     COUNT = 262,
     DUP = 263,
     ELSE = 264,
     END = 265,
     FLAT = 266,
     FN = 267,
     FOR = 268,
     IF = 269,
     IN = 270,
     OROR = 271,
     PIPE = 272,
     REDIR = 273,
     SREDIR = 274,
     SUB = 275,
     SUBSHELL = 276,
     SWITCH = 277,
     TWIDDLE = 278,
     WHILE = 279,
     WORD = 280,
     HUH = 281
   };
#endif
/* Tokens.  */
#define ANDAND 258
#define BACKBACK 259
#define BANG 260
#define CASE 261
#define COUNT 262
#define DUP 263
#define ELSE 264
#define END 265
#define FLAT 266
#define FN 267
#define FOR 268
#define IF 269
#define IN 270
#define OROR 271
#define PIPE 272
#define REDIR 273
#define SREDIR 274
#define SUB 275
#define SUBSHELL 276
#define SWITCH 277
#define TWIDDLE 278
#define WHILE 279
#define WORD 280
#define HUH 281




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 32 "src/parse.y"

	struct Node *node;
	struct Redir redir;
	struct Pipe pipe;
	struct Dup dup;
	struct Word word;
	char *keyword;



/* Line 293 of yacc.c  */
#line 184 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 196 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   568

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    29,     2,    31,     2,
      34,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    36,     2,    37,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    16,    19,    21,
      24,    26,    29,    31,    34,    38,    42,    46,    47,    50,
      52,    55,    58,    62,    66,    68,    71,    74,    76,    81,
      82,    84,    87,    92,   101,   108,   113,   122,   127,   132,
     137,   142,   145,   148,   152,   156,   160,   163,   164,   166,
     168,   171,   174,   176,   180,   182,   184,   186,   190,   193,
     199,   202,   205,   208,   211,   215,   219,   223,   226,   228,
     230,   232,   234,   236,   238,   240,   242,   244,   246,   248,
     250,   251,   254,   255,   258,   261,   262
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    42,    40,    -1,     1,    40,    -1,    10,
      -1,    28,    -1,    53,    30,    -1,    53,    31,    -1,    53,
      -1,    41,    42,    -1,    53,    -1,    44,    43,    -1,    41,
      -1,    53,    28,    -1,    32,    43,    33,    -1,    34,    43,
      27,    -1,    56,    35,    58,    -1,    -1,    49,    48,    -1,
       8,    -1,    18,    58,    -1,    19,    58,    -1,     6,    61,
      30,    -1,     6,    61,    28,    -1,    53,    -1,    50,    51,
      -1,    44,    51,    -1,    53,    -1,    45,     9,    63,    53,
      -1,    -1,    55,    -1,    45,    48,    -1,    14,    46,    63,
      52,    -1,    13,    34,    58,    15,    61,    27,    63,    53,
      -1,    13,    34,    58,    27,    63,    53,    -1,    24,    46,
      63,    53,    -1,    22,    34,    58,    27,    63,    32,    51,
      33,    -1,    23,    54,    58,    61,    -1,    53,     3,    63,
      53,    -1,    53,    16,    63,    53,    -1,    53,    17,    63,
      53,    -1,    49,    53,    -1,    47,    53,    -1,     5,    54,
      53,    -1,    21,    54,    53,    -1,    12,    61,    45,    -1,
      12,    61,    -1,    -1,    36,    -1,    56,    -1,    55,    58,
      -1,    55,    49,    -1,    59,    -1,    56,    36,    57,    -1,
      59,    -1,    60,    -1,    57,    -1,    58,    36,    57,    -1,
      29,    57,    -1,    29,    57,    20,    61,    27,    -1,     7,
      57,    -1,    11,    57,    -1,    37,    57,    -1,    37,    45,
      -1,     4,    58,    45,    -1,     4,    58,    57,    -1,    34,
      62,    27,    -1,    18,    45,    -1,    25,    -1,    13,    -1,
      15,    -1,    24,    -1,    14,    -1,    22,    -1,    12,    -1,
       9,    -1,     6,    -1,    23,    -1,     5,    -1,    21,    -1,
      -1,    61,    58,    -1,    -1,    62,    28,    -1,    62,    58,
      -1,    -1,    63,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    54,    57,    58,    61,    62,    65,    66,
      69,    70,    72,    73,    75,    77,    79,    81,    82,    85,
      86,    89,    93,    94,    96,    97,    98,   100,   101,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   122,   123,   125,
     126,   127,   129,   130,   132,   133,   135,   136,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     162,   163,   165,   166,   167,   169,   170
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ANDAND", "BACKBACK", "BANG", "CASE",
  "COUNT", "DUP", "ELSE", "END", "FLAT", "FN", "FOR", "IF", "IN", "OROR",
  "PIPE", "REDIR", "SREDIR", "SUB", "SUBSHELL", "SWITCH", "TWIDDLE",
  "WHILE", "WORD", "HUH", "')'", "'\\n'", "'$'", "';'", "'&'", "'{'",
  "'}'", "'('", "'='", "'^'", "'`'", "$accept", "rc", "end", "cmdsa",
  "line", "body", "cmdsan", "brace", "paren", "assign", "epilog", "redir",
  "case", "cbody", "iftail", "cmd", "optcaret", "simple", "first", "sword",
  "word", "comword", "keyword", "words", "nlwords", "optnl", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    41,    10,    36,
      59,    38,   123,   125,    40,    61,    94,    96
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    46,    47,    48,    48,    49,
      49,    49,    50,    50,    51,    51,    51,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    62,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     2,     2,     1,     2,
       1,     2,     1,     2,     3,     3,     3,     0,     2,     1,
       2,     2,     3,     3,     1,     2,     2,     1,     4,     0,
       1,     2,     4,     8,     6,     4,     8,     4,     4,     4,
       4,     2,     2,     3,     3,     3,     2,     0,     1,     1,
       2,     2,     1,     3,     1,     1,     1,     3,     2,     5,
       2,     2,     2,     2,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     0,     2,     2,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    47,     0,    19,     0,    80,     0,     0,
       0,     0,    47,     0,    47,     0,    68,     0,    29,    82,
       0,     0,    29,     0,    17,    29,    29,     8,    30,    49,
      52,     4,     5,     3,    78,    76,    75,    74,    69,    72,
      70,     0,    79,    73,    77,    71,    56,     0,    54,    55,
      48,    29,    60,    61,    46,     0,    29,    85,    67,    20,
      21,    29,     0,     0,    85,    58,    12,     0,    29,    10,
       0,    63,    62,     1,     9,     2,     0,    31,    17,    42,
      41,    85,    85,    85,     6,     7,    51,    50,     0,     0,
       0,    64,    65,    43,    45,    81,     0,     0,    29,    44,
       0,    80,    29,    80,    14,    11,    13,    66,    83,    84,
      18,    29,    29,    29,    16,    53,    57,    80,    85,    15,
      86,    17,    32,    27,    85,    37,    35,     0,    38,    39,
      40,     0,    29,    85,     0,    59,    85,    34,    29,    29,
      29,    28,    80,    29,    29,     0,    24,    33,     0,    26,
      25,    36,    23,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    33,    66,    23,    67,    68,    24,    57,    25,
      77,    26,   144,   145,   122,    69,    51,    28,    29,    46,
      95,    48,    49,    54,    70,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const yytype_int16 yypact[] =
{
     166,    -1,   503,   -12,   503,   -98,   503,   -98,    21,    26,
     336,   503,   -12,    38,   -12,    26,   -98,   503,   531,   -98,
     336,    81,   531,    -1,    29,   531,   531,    33,   200,   -25,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,    54,   -98,   -98,   -98,   -98,   -98,   234,   -98,   -98,
     -98,   531,   -98,   -98,   336,   503,   531,   -98,   -98,    51,
      51,   531,   503,   503,   -98,    68,   -98,    56,   531,    66,
     268,   -98,   -98,   -98,   -98,   -98,   503,   -98,    29,    75,
      75,   -98,   -98,   -98,   -98,   -98,   -98,    51,   503,   503,
     503,   -98,   -98,    75,   -98,    51,    44,    72,   367,    75,
     -19,    51,   367,   -98,   -98,   -98,   -98,   -98,   -98,    51,
     -98,   367,   367,   367,    51,   -98,   -98,   -98,   -98,   -98,
     -98,    35,   -98,    12,   -98,   503,    12,   401,    75,    75,
     -98,   435,   367,   -98,     2,   -98,   -98,    12,   367,   469,
     367,    12,   -98,   469,   469,    60,    66,    12,   302,   -98,
     -98,   -98,   -98,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,    78,     1,    73,   -16,   -69,    -8,    91,   -98,
      30,   -21,   -98,   -59,   -98,    16,    64,   -98,   -98,    15,
       3,     0,   -98,   -97,   -98,    39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -30
static const yytype_int16 yytable[] =
{
      30,    22,    58,    78,   125,    47,   127,    86,   124,    31,
      88,    89,    71,    59,    60,    81,    27,    90,    30,    52,
     131,    53,    30,    22,    50,    30,    30,    32,    82,    83,
     120,    87,    65,    58,   139,    72,    81,     5,    27,    91,
      97,    79,    80,     5,   133,   148,    94,    76,    11,    82,
      83,    30,   105,    76,    11,    55,    30,    78,    96,   117,
      56,    30,    92,    84,    85,   100,   101,    93,    30,    81,
     143,   118,    62,   109,   143,   143,    61,    99,    63,    59,
      90,    73,    82,    83,   149,   150,    18,    90,   103,   104,
     121,   114,    83,   151,   106,    74,    84,    85,    30,   119,
      78,    75,    30,   102,   115,   116,    64,     0,   110,     0,
       0,    30,    30,    30,   123,     0,     0,     0,   126,     0,
     111,   112,   113,     0,     0,     0,     0,   128,   129,   130,
       0,     0,    30,     0,     0,     0,     0,     0,    30,    30,
      30,     0,     0,    30,    30,     0,     0,     0,   137,     0,
       0,     0,     0,     0,   141,   146,   147,   132,     0,   146,
     146,     0,     0,   134,     0,     0,     0,     1,     0,   -29,
       2,     3,   138,     4,     5,   140,   -29,     6,     7,     8,
       9,     0,   -29,   -29,    10,    11,     0,    12,    13,    14,
      15,    16,     0,     0,   -29,    17,   -29,   -29,    18,     0,
      19,     0,     0,    20,     2,    34,    35,     4,     5,    36,
       0,     6,    37,    38,    39,    40,     0,     0,    10,    11,
       0,    42,    43,    44,    45,    16,     0,     0,     0,    17,
       0,     0,     0,     0,    19,     0,     0,    20,     2,    34,
      35,     4,     0,    36,     0,     6,    37,    38,    39,    40,
       0,     0,    41,     0,     0,    42,    43,    44,    45,    16,
       0,     0,     0,    17,     0,     0,    18,     0,    19,     0,
      90,    20,     2,    34,    35,     4,     0,    36,     0,     6,
      37,    38,    39,    40,     0,     0,    41,     0,     0,    42,
      43,    44,    45,    16,     0,   107,   108,    17,     0,     0,
       0,     0,    19,     0,     0,    20,     2,    34,    35,     4,
       0,    36,     0,     6,    37,    38,    39,    40,     0,     0,
      41,     0,     0,    42,    43,    44,    45,    16,     0,     0,
     152,    17,   153,     0,     0,     0,    19,     0,     0,    20,
       2,    34,    35,     4,     0,    36,     0,     6,    37,    38,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    16,     0,     0,     0,    17,     0,     0,    18,     0,
      19,     2,     3,    20,     4,     5,     0,     0,     6,     7,
       8,     9,     0,     0,     0,    10,    11,     0,    12,    13,
      14,    15,    16,     0,     0,   120,    17,     0,     0,    18,
       0,    19,     0,     0,    20,     2,    34,    35,     4,     0,
      36,     0,     6,    37,    38,    39,    40,     0,     0,    41,
       0,     0,    42,    43,    44,    45,    16,     0,   135,     0,
      17,     0,     0,     0,     0,    19,     0,     0,    20,     2,
      34,    35,     4,     0,    36,     0,     6,    37,    38,    39,
      40,     0,     0,    41,     0,     0,    42,    43,    44,    45,
      16,     0,   136,     0,    17,     0,     0,     0,     0,    19,
       0,     0,    20,     2,     3,   142,     4,     5,     0,     0,
       6,     7,     8,     9,     0,     0,     0,    10,    11,     0,
      12,    13,    14,    15,    16,     0,     0,     0,    17,     0,
       0,    18,     0,    19,     0,     0,    20,     2,    34,    35,
       4,     0,    36,     0,     6,    37,    38,    39,    40,     0,
       0,    41,     0,     0,    42,    43,    44,    45,    16,     0,
       0,     0,    17,     0,     0,     2,     3,    19,     4,     5,
      20,     0,     6,     7,     8,     9,     0,     0,     0,    10,
      11,     0,    12,    13,    14,    15,    16,     0,     0,     0,
      17,     0,     0,    18,     0,    19,     0,     0,    20
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-98))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,     0,    10,    24,   101,     2,   103,    28,    27,    10,
      35,    36,    20,    10,    11,     3,     0,    36,    18,     4,
     117,     6,    22,    22,    36,    25,    26,    28,    16,    17,
      28,    28,    17,    41,    32,    20,     3,     8,    22,    47,
      56,    25,    26,     8,     9,   142,    54,    18,    19,    16,
      17,    51,    68,    18,    19,    34,    56,    78,    55,    15,
      34,    61,    47,    30,    31,    62,    63,    51,    68,     3,
     139,    27,    34,    70,   143,   144,    12,    61,    14,    76,
      36,     0,    16,    17,   143,   144,    32,    36,    20,    33,
      98,    88,    17,    33,    28,    22,    30,    31,    98,    27,
     121,    23,   102,    64,    89,    90,    15,    -1,    78,    -1,
      -1,   111,   112,   113,    98,    -1,    -1,    -1,   102,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,   111,   112,   113,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,    -1,    -1,   143,   144,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,   118,    -1,   143,
     144,    -1,    -1,   124,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,   133,     7,     8,   136,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    32,    -1,
      34,    -1,    -1,    37,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    37,     4,     5,
       6,     7,    -1,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    32,    -1,    34,    -1,
      36,    37,     4,     5,     6,     7,    -1,     9,    -1,    11,
      12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    37,     4,     5,     6,     7,
      -1,     9,    -1,    11,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    -1,    -1,    -1,    34,    -1,    -1,    37,
       4,     5,     6,     7,    -1,     9,    -1,    11,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      34,     4,     5,    37,     7,     8,    -1,    -1,    11,    12,
      13,    14,    -1,    -1,    -1,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    34,    -1,    -1,    37,     4,     5,     6,     7,    -1,
       9,    -1,    11,    12,    13,    14,    15,    -1,    -1,    18,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    27,    -1,
      29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,     4,
       5,     6,     7,    -1,     9,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    27,    -1,    29,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    37,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    -1,    -1,    -1,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    32,    -1,    34,    -1,    -1,    37,     4,     5,     6,
       7,    -1,     9,    -1,    11,    12,    13,    14,    15,    -1,
      -1,    18,    -1,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,     4,     5,    34,     7,     8,
      37,    -1,    11,    12,    13,    14,    -1,    -1,    -1,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    32,    -1,    34,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     7,     8,    11,    12,    13,    14,
      18,    19,    21,    22,    23,    24,    25,    29,    32,    34,
      37,    39,    41,    42,    45,    47,    49,    53,    55,    56,
      59,    10,    28,    40,     5,     6,     9,    12,    13,    14,
      15,    18,    21,    22,    23,    24,    57,    58,    59,    60,
      36,    54,    57,    57,    61,    34,    34,    46,    45,    58,
      58,    54,    34,    54,    46,    57,    41,    43,    44,    53,
      62,    45,    57,     0,    42,    40,    18,    48,    49,    53,
      53,     3,    16,    17,    30,    31,    49,    58,    35,    36,
      36,    45,    57,    53,    45,    58,    58,    43,    63,    53,
      58,    58,    63,    20,    33,    43,    28,    27,    28,    58,
      48,    63,    63,    63,    58,    57,    57,    15,    27,    27,
      28,    45,    52,    53,    27,    61,    53,    61,    53,    53,
      53,    61,    63,     9,    63,    27,    27,    53,    63,    32,
      63,    53,     6,    44,    50,    51,    53,    53,    61,    51,
      51,    33,    28,    30
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
        case 2:

/* Line 1806 of yacc.c  */
#line 53 "src/parse.y"
    { parsetree = (yyvsp[(1) - (2)].node); YYACCEPT; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 54 "src/parse.y"
    { yyerrok; parsetree = NULL; YYABORT; }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 57 "src/parse.y"
    { if (!heredoc(1)) YYABORT; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 58 "src/parse.y"
    { if (!heredoc(0)) YYABORT; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 62 "src/parse.y"
    { (yyval.node) = ((yyvsp[(1) - (2)].node) != NULL ? mk(nNowait,(yyvsp[(1) - (2)].node)) : (yyvsp[(1) - (2)].node)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 66 "src/parse.y"
    { (yyval.node) = ((yyvsp[(1) - (2)].node) != NULL ? mk(nBody,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)) : (yyvsp[(2) - (2)].node)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 70 "src/parse.y"
    { (yyval.node) = ((yyvsp[(1) - (2)].node) == NULL ? (yyvsp[(2) - (2)].node) : (yyvsp[(2) - (2)].node) == NULL ? (yyvsp[(1) - (2)].node) : mk(nBody,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node))); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 73 "src/parse.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); if (!heredoc(0)) YYABORT; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 75 "src/parse.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 77 "src/parse.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 79 "src/parse.y"
    { (yyval.node) = mk(nAssign,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 81 "src/parse.y"
    { (yyval.node) = NULL; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 82 "src/parse.y"
    { (yyval.node) = mk(nEpilog,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 85 "src/parse.y"
    { (yyval.node) = mk(nDup,(yyvsp[(1) - (1)].dup).type,(yyvsp[(1) - (1)].dup).left,(yyvsp[(1) - (1)].dup).right); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 86 "src/parse.y"
    { (yyval.node) = mk(nRedir,(yyvsp[(1) - (2)].redir).type,(yyvsp[(1) - (2)].redir).fd,(yyvsp[(2) - (2)].node));
				  if ((yyvsp[(1) - (2)].redir).type == rHeredoc && !qdoc((yyvsp[(2) - (2)].node), (yyval.node))) YYABORT; /* queue heredocs up */
				}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 89 "src/parse.y"
    { (yyval.node) = mk(nRedir,(yyvsp[(1) - (2)].redir).type,(yyvsp[(1) - (2)].redir).fd,(yyvsp[(2) - (2)].node));
				  if ((yyvsp[(1) - (2)].redir).type == rHeredoc && !qdoc((yyvsp[(2) - (2)].node), (yyval.node))) YYABORT; /* queue heredocs up */
				}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 93 "src/parse.y"
    { (yyval.node) = mk(nCase, (yyvsp[(2) - (3)].node)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 94 "src/parse.y"
    { (yyval.node) = mk(nCase, (yyvsp[(2) - (3)].node)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 96 "src/parse.y"
    { (yyval.node) = mk(nCbody, (yyvsp[(1) - (1)].node), NULL); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 97 "src/parse.y"
    { (yyval.node) = mk(nCbody, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 98 "src/parse.y"
    { (yyval.node) = mk(nCbody, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 101 "src/parse.y"
    { (yyval.node) = mk(nElse,(yyvsp[(1) - (4)].node),(yyvsp[(4) - (4)].node)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 103 "src/parse.y"
    { (yyval.node) = NULL; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 105 "src/parse.y"
    { (yyval.node) = mk(nBrace,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 106 "src/parse.y"
    { (yyval.node) = mk(nIf,(yyvsp[(2) - (4)].node),(yyvsp[(4) - (4)].node)); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 107 "src/parse.y"
    { (yyval.node) = mk(nForin,(yyvsp[(3) - (8)].node),(yyvsp[(5) - (8)].node),(yyvsp[(8) - (8)].node)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 108 "src/parse.y"
    { (yyval.node) = mk(nForin,(yyvsp[(3) - (6)].node),star,(yyvsp[(6) - (6)].node)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 109 "src/parse.y"
    { (yyval.node) = mk(nWhile,(yyvsp[(2) - (4)].node),(yyvsp[(4) - (4)].node)); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 110 "src/parse.y"
    { (yyval.node) = mk(nSwitch,(yyvsp[(3) - (8)].node),(yyvsp[(7) - (8)].node)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 111 "src/parse.y"
    { (yyval.node) = mk(nMatch,(yyvsp[(3) - (4)].node),(yyvsp[(4) - (4)].node)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 112 "src/parse.y"
    { (yyval.node) = mk(nAndalso,(yyvsp[(1) - (4)].node),(yyvsp[(4) - (4)].node)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 113 "src/parse.y"
    { (yyval.node) = mk(nOrelse,(yyvsp[(1) - (4)].node),(yyvsp[(4) - (4)].node)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 114 "src/parse.y"
    { (yyval.node) = mk(nPipe,(yyvsp[(2) - (4)].pipe).left,(yyvsp[(2) - (4)].pipe).right,(yyvsp[(1) - (4)].node),(yyvsp[(4) - (4)].node)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 115 "src/parse.y"
    { (yyval.node) = ((yyvsp[(2) - (2)].node) != NULL ? mk(nPre,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)) : (yyvsp[(1) - (2)].node)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 116 "src/parse.y"
    { (yyval.node) = ((yyvsp[(2) - (2)].node) != NULL ? mk(nPre,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)) : (yyvsp[(1) - (2)].node)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 117 "src/parse.y"
    { (yyval.node) = mk(nBang,(yyvsp[(3) - (3)].node)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 118 "src/parse.y"
    { (yyval.node) = mk(nSubshell,(yyvsp[(3) - (3)].node)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 119 "src/parse.y"
    { (yyval.node) = mk(nNewfn,(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 120 "src/parse.y"
    { (yyval.node) = mk(nRmfn,(yyvsp[(2) - (2)].node)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 126 "src/parse.y"
    { (yyval.node) = ((yyvsp[(2) - (2)].node) != NULL ? mk(nArgs,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)) : (yyvsp[(1) - (2)].node)); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 127 "src/parse.y"
    { (yyval.node) = mk(nArgs,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 130 "src/parse.y"
    { (yyval.node) = mk(nConcat,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 133 "src/parse.y"
    { (yyval.node) = mk(nWord, (yyvsp[(1) - (1)].keyword), NULL, FALSE); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 136 "src/parse.y"
    { (yyval.node) = mk(nConcat,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 138 "src/parse.y"
    { (yyval.node) = mk(nVar,(yyvsp[(2) - (2)].node)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 139 "src/parse.y"
    { (yyval.node) = mk(nVarsub,(yyvsp[(2) - (5)].node),(yyvsp[(4) - (5)].node)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 140 "src/parse.y"
    { (yyval.node) = mk(nCount,(yyvsp[(2) - (2)].node)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 141 "src/parse.y"
    { (yyval.node) = mk(nFlat, (yyvsp[(2) - (2)].node)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 142 "src/parse.y"
    { (yyval.node) = mk(nBackq,nolist,(yyvsp[(2) - (2)].node)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 143 "src/parse.y"
    { (yyval.node) = mk(nBackq,nolist,(yyvsp[(2) - (2)].node)); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 144 "src/parse.y"
    { (yyval.node) = mk(nBackq,(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 145 "src/parse.y"
    { (yyval.node) = mk(nBackq,(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 146 "src/parse.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 147 "src/parse.y"
    { (yyval.node) = mk(nNmpipe,(yyvsp[(1) - (2)].redir).type,(yyvsp[(1) - (2)].redir).fd,(yyvsp[(2) - (2)].node)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 148 "src/parse.y"
    { (yyval.node) = mk(nWord, (yyvsp[(1) - (1)].word).w, (yyvsp[(1) - (1)].word).m, (yyvsp[(1) - (1)].word).q); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 150 "src/parse.y"
    { (yyval.keyword) = "for"; }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 151 "src/parse.y"
    { (yyval.keyword) = "in"; }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 152 "src/parse.y"
    { (yyval.keyword) = "while"; }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 153 "src/parse.y"
    { (yyval.keyword) = "if"; }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 154 "src/parse.y"
    { (yyval.keyword) = "switch"; }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 155 "src/parse.y"
    { (yyval.keyword) = "fn"; }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 156 "src/parse.y"
    { (yyval.keyword) = "else"; }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 157 "src/parse.y"
    { (yyval.keyword) = "case"; }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 158 "src/parse.y"
    { (yyval.keyword) = "~"; }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 159 "src/parse.y"
    { (yyval.keyword) = "!"; }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 160 "src/parse.y"
    { (yyval.keyword) = "@"; }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 162 "src/parse.y"
    { (yyval.node) = NULL; }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 163 "src/parse.y"
    { (yyval.node) = ((yyvsp[(1) - (2)].node) != NULL ? ((yyvsp[(2) - (2)].node) != NULL ? mk(nLappend,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)) : (yyvsp[(1) - (2)].node)) : (yyvsp[(2) - (2)].node)); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 165 "src/parse.y"
    { (yyval.node) = NULL; }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 167 "src/parse.y"
    { (yyval.node) = ((yyvsp[(1) - (2)].node) != NULL ? ((yyvsp[(2) - (2)].node) != NULL ? mk(nLappend,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node)) : (yyvsp[(1) - (2)].node)) : (yyvsp[(2) - (2)].node)); }
    break;



/* Line 1806 of yacc.c  */
#line 2130 "y.tab.c"
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 172 "src/parse.y"


void initparse() {
	star = treecpy(mk(nVar, mk(nWord,"*", NULL, FALSE)), ealloc);
	nolist = treecpy(mk(nVar, mk(nWord,"ifs", NULL, FALSE)), ealloc);
}


