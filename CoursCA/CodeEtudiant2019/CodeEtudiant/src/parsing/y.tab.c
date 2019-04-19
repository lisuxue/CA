/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         asm_mipsparse
#define yylex           asm_mipslex
#define yyerror         asm_mipserror
#define yydebug         asm_mipsdebug
#define yynerrs         asm_mipsnerrs


/* Copy the first part of user declarations.  */
#line 10 "asm_mips.yac" /* yacc.c:339  */

#include <iostream>
#include <Program.h>
#include <Directive.h>
#include <Label.h>
#include <stdlib.h>
#include <stdio.h>
extern "C" {
#include "utl200.h"
#include "asm200.h"
}
#include <asm_mipsyac.h>
#include<map>
#include <sstream>

#undef  yylex
#define yylex         asm_mipslex
#define yyrestart     asm_mipsrestart
#define yyin          asm_mipsin

extern "C" {extern int            yylex     (YYSTYPE *);}

extern void           yyrestart ();
extern int            yyparse   ();
extern FILE           *yyin       ;

Program prog ;


map<int,string> strmap ;
static int strmap_id ;

void programparse(string file) {
	// ###------------------------------------------------------### 
	//    initialize global and static variables			
	// ###------------------------------------------------------### 

//	std::cout << "Starting parsing" << std::endl;
	
	strmap_id = 0;

	yyin = fopen(file.c_str(), "r") ;
	yyparse() ;
	//std::cout << "Parsing done" << std::endl;
}


static void yyerror (char * str)
	{ std::cout << "yyerror at line " << ASM_LINENO << " : " << str <<std::endl ;	}


#line 124 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_ASM_MIPS_Y_TAB_H_INCLUDED
# define YY_ASM_MIPS_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int asm_mipsdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _ALIGN_ = 258,
    _ASCII_ = 259,
    _ASCIIZ_ = 260,
    _BYTE_ = 261,
    _COMM_ = 262,
    _END_ = 263,
    _ENT_ = 264,
    _EQU_ = 265,
    _EXTERN_ = 266,
    _GLOBAL_ = 267,
    _LCOMM_ = 268,
    _NOREORDER_ = 269,
    _REORDER_ = 270,
    _SECTION_ = 271,
    _SET_ = 272,
    _SKIP_ = 273,
    _SPACE_ = 274,
    _WORD_ = 275,
    ARegister = 276,
    Ampersand = 277,
    Bar = 278,
    CarriageReturn = 279,
    Circomflex = 280,
    Codop_hint_mem = 281,
    Codop_label = 282,
    Codop_n = 283,
    Codop_od_rs = 284,
    Codop_rd = 285,
    Codop_rd_si16 = 286,
    Codop_rd_rs = 287,
    Codop_rd_rs_rt = 288,
    Codop_rd_rt_sham = 289,
    Codop_rd_rt_rs = 290,
    Codop_rd_rs_si16 = 291,
    Codop_rd_rs_ui16 = 292,
    Codop_rd_mem = 293,
    Codop_rs = 294,
    Codop_rs_label = 295,
    Codop_rs_rt = 296,
    Codop_rs_rt_label = 297,
    Codop_rs_si16 = 298,
    Codop_rt_cop0r = 299,
    Codop_rt_cop2r = 300,
    Codop_rt_mem = 301,
    Codop_ui20 = 302,
    Colon = 303,
    Comma = 304,
    Cop0Register = 305,
    DoubleGreat = 306,
    DoubleLess = 307,
    Identifier = 308,
    IntegerRegister = 309,
    LeftParen = 310,
    Litteral = 311,
    Macro_label = 312,
    Macro_n = 313,
    Macro_rd_i32 = 314,
    Macro_rd_rs = 315,
    Macro_rd_rt = 316,
    Macro_rd_label = 317,
    Macro_rs_label = 318,
    Minus = 319,
    Plus = 320,
    Register = 321,
    RightParen = 322,
    Slash = 323,
    Star = 324,
    String = 325,
    String2 = 326,
    GCC_operator = 327,
    Tilda = 328,
    Arobase = 329
  };
#endif
/* Tokens.  */
#define _ALIGN_ 258
#define _ASCII_ 259
#define _ASCIIZ_ 260
#define _BYTE_ 261
#define _COMM_ 262
#define _END_ 263
#define _ENT_ 264
#define _EQU_ 265
#define _EXTERN_ 266
#define _GLOBAL_ 267
#define _LCOMM_ 268
#define _NOREORDER_ 269
#define _REORDER_ 270
#define _SECTION_ 271
#define _SET_ 272
#define _SKIP_ 273
#define _SPACE_ 274
#define _WORD_ 275
#define ARegister 276
#define Ampersand 277
#define Bar 278
#define CarriageReturn 279
#define Circomflex 280
#define Codop_hint_mem 281
#define Codop_label 282
#define Codop_n 283
#define Codop_od_rs 284
#define Codop_rd 285
#define Codop_rd_si16 286
#define Codop_rd_rs 287
#define Codop_rd_rs_rt 288
#define Codop_rd_rt_sham 289
#define Codop_rd_rt_rs 290
#define Codop_rd_rs_si16 291
#define Codop_rd_rs_ui16 292
#define Codop_rd_mem 293
#define Codop_rs 294
#define Codop_rs_label 295
#define Codop_rs_rt 296
#define Codop_rs_rt_label 297
#define Codop_rs_si16 298
#define Codop_rt_cop0r 299
#define Codop_rt_cop2r 300
#define Codop_rt_mem 301
#define Codop_ui20 302
#define Colon 303
#define Comma 304
#define Cop0Register 305
#define DoubleGreat 306
#define DoubleLess 307
#define Identifier 308
#define IntegerRegister 309
#define LeftParen 310
#define Litteral 311
#define Macro_label 312
#define Macro_n 313
#define Macro_rd_i32 314
#define Macro_rd_rs 315
#define Macro_rd_rt 316
#define Macro_rd_label 317
#define Macro_rs_label 318
#define Minus 319
#define Plus 320
#define Register 321
#define RightParen 322
#define Slash 323
#define Star 324
#define String 325
#define String2 326
#define GCC_operator 327
#define Tilda 328
#define Arobase 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 63 "asm_mips.yac" /* yacc.c:355  */

  struct utchn  *pchn    ;
  unsigned int   uval    ;
  char          *text    ;
  

#line 319 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int asm_mipsparse (void);

#endif /* !YY_ASM_MIPS_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 335 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  319

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   177,   177,   179,   183,   185,   191,   199,   201,   206,
     209,   211,   216,   220,   224,   235,   239,   250,   254,   259,
     264,   265,   269,   275,   282,   283,   288,   299,   301,   313,
     317,   322,   327,   332,   340,   351,   358,   365,   375,   384,
     403,   416,   430,   446,   456,   471,   485,   507,   529,   550,
     572,   584,   599,   615,   644,   661,   678,   695,   714,   733,
     752,   767,   789,   814,   847,   863,   883,   903,   920,   937,
     955,   972,   990,  1003,  1012,  1017,  1019,  1021,  1023,  1028,
    1030,  1035,  1037,  1042,  1049,  1053,  1055,  1057,  1062,  1063,
    1064,  1065,  1066,  1067,  1068,  1072,  1084,  1094,  1114,  1137,
    1151,  1167,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1195,  1204,  1213,  1219,  1230,  1243,  1252,  1261,  1267,  1268,
    1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,
    1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,
    1292,  1294,  1299,  1301,  1310,  1315,  1322,  1325,  1328,  1336,
    1346,  1350,  1357,  1364,  1371,  1378,  1385,  1392,  1401,  1403,
    1408,  1410,  1413,  1419,  1420,  1421,  1422,  1423,  1424,  1425,
    1426,  1428,  1431,  1433,  1434,  1438,  1443,  1454,  1458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ALIGN_", "_ASCII_", "_ASCIIZ_",
  "_BYTE_", "_COMM_", "_END_", "_ENT_", "_EQU_", "_EXTERN_", "_GLOBAL_",
  "_LCOMM_", "_NOREORDER_", "_REORDER_", "_SECTION_", "_SET_", "_SKIP_",
  "_SPACE_", "_WORD_", "ARegister", "Ampersand", "Bar", "CarriageReturn",
  "Circomflex", "Codop_hint_mem", "Codop_label", "Codop_n", "Codop_od_rs",
  "Codop_rd", "Codop_rd_si16", "Codop_rd_rs", "Codop_rd_rs_rt",
  "Codop_rd_rt_sham", "Codop_rd_rt_rs", "Codop_rd_rs_si16",
  "Codop_rd_rs_ui16", "Codop_rd_mem", "Codop_rs", "Codop_rs_label",
  "Codop_rs_rt", "Codop_rs_rt_label", "Codop_rs_si16", "Codop_rt_cop0r",
  "Codop_rt_cop2r", "Codop_rt_mem", "Codop_ui20", "Colon", "Comma",
  "Cop0Register", "DoubleGreat", "DoubleLess", "Identifier",
  "IntegerRegister", "LeftParen", "Litteral", "Macro_label", "Macro_n",
  "Macro_rd_i32", "Macro_rd_rs", "Macro_rd_rt", "Macro_rd_label",
  "Macro_rs_label", "Minus", "Plus", "Register", "RightParen", "Slash",
  "Star", "String", "String2", "GCC_operator", "Tilda", "Arobase",
  "$accept", "adding_operator", ".a_label.", "align_directive",
  "..an_instruction..", "an_instruction", "assembly_file",
  "assembly_instructions", "byte_immediate_list", "...byte_immediate..",
  "CarriageReturn_ERR", "cop0_reg", "cop2_reg", "effective_instruction",
  "end_directive", "ent_directive", ".Identifier.", "equ_directive",
  "expr..addop__expr..", "expression", "expr__logop__expr..logop__expr..",
  "expr__mulop__expr..mulop__expr..", "expr__shfop__expr",
  "extern_directive", "format_hint_mem", "format_label", "format_n",
  "format_od_rs", "format_rd", "format_rd_mem", "format_rd_si16",
  "format_rd_rs", "format_rd_rs_rt", "format_rd_rs_si16",
  "format_rd_rs_ui16", "format_rd_rt_rs", "format_rd_rt_sham", "format_rs",
  "format_rs_label", "format_rs_rt", "format_rs_rt_label",
  "format_rs_si16", "format_rt_cop0r", "format_rt_cop2r", "format_rt_mem",
  "format_ui20", "global_directive", "signed_16_bit_immediate",
  "immediate", "integer_register", "label", "labelable_directive",
  "logic_operator", "macro_instruction", "macro_label", "macro_n",
  "macro_rd_i32", "macro_rd_label", "macro_rd_rs", "macro_rd_rt",
  "macro_rs_label", "memory_alloc_directive", "memory_ascii_alloc",
  "memory_asciiz_alloc", "memory_byte_alloc", "memory_lcomm_alloc",
  "memory_comm_alloc", "memory_space_alloc", "memory_skip_alloc",
  "memory_word_alloc", "mips_instruction", "mul_div_operator", "primary",
  "section_specification_directive", "set_directive", "other_directive",
  "_String", "shift_operator", "term", "unlabeled_directive",
  ".unlabeled_instruction.", "unsigned_16_bit_immediate",
  "word_immediate_list", "...word_immediate..", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

#define YYPACT_NINF -224

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-224)))

#define YYTABLE_NINF -146

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -224,   132,    11,  -224,   -11,   -37,   -24,   -23,   -16,   -35,
     -35,    -9,    -5,   -17,  -224,  -224,   310,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,    -2,  -224,  -224,  -224,   -11,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,     6,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,    61,  -224,   -33,   -29,   -60,   184,
      20,     3,  -224,  -224,  -224,  -224,     7,   -13,    -6,    61,
      25,    26,    24,    28,    61,    61,   -15,  -224,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,    61,    61,  -224,   -19,
     -19,   -19,   -19,   -19,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,   -11,  -224,  -224,    61,
       9,    61,  -224,    61,  -224,  -224,  -224,    61,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,    61,    61,    61,    61,    61,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,    33,    54,  -224,  -224,  -224,  -224,    55,
    -224,  -224,    56,  -224,    63,    64,    66,    69,    70,    71,
      72,    73,  -224,    74,    75,    77,    79,    81,    97,    98,
    -224,  -224,   104,   105,   106,   108,   131,  -224,  -224,  -224,
     114,   115,  -224,  -224,  -224,  -224,  -224,  -224,   134,   128,
     130,   138,    61,   -19,   -39,   -19,   -19,   -19,   -19,   -19,
     -19,   144,    61,   -19,   -19,    61,   146,    52,   159,    61,
     -19,   -19,    61,    61,  -224,  -224,    61,   152,  -224,    61,
     143,  -224,  -224,  -224,  -224,  -224,   161,   162,   169,   175,
     176,   -15,   173,   174,   178,  -224,   189,   190,  -224,  -224,
    -224,  -224,  -224,   -15,   186,   178,  -224,  -224,  -224,  -224,
    -224,  -224,   192,  -224,   -19,   -15,    61,   -19,   149,    61,
     187,   -19,   -19,   -19,   212,   188,   -19,  -224,   193,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   195,   196,
    -224,  -224,  -224,  -224,   197,  -224,  -224,  -224,  -224
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,    12,     0,     0,    24,     0,     0,     0,
       0,     0,     0,   150,    82,    83,   172,   163,     8,   170,
     169,   165,   167,   166,     0,   164,   168,   171,     0,     1,
      17,    11,     6,    25,    22,    23,     0,    81,    38,    73,
     144,   147,   146,   143,     0,   142,     0,     0,    75,    27,
      77,    76,    78,   148,   160,    32,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,   174,   118,   119,   120,   121,   122,
     123,   130,   124,   125,   126,   127,   128,   129,   131,   132,
     133,   134,   135,   137,   138,   136,   139,   173,    21,    93,
      94,    88,    89,    90,    91,    92,    84,   104,   105,   103,
     109,   108,   107,   106,   102,    20,     0,     5,    10,     0,
       0,     0,   161,     0,   162,     3,     2,     0,    86,    85,
      87,   159,   158,   141,   140,     0,     0,     0,     0,     0,
      80,   152,   155,    79,   156,   157,   151,   153,   154,   110,
     111,   112,    15,     0,     0,   116,   115,   177,   117,     0,
      40,    41,    43,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
      72,    95,     0,     0,     0,     0,     0,     9,    26,    29,
       0,     0,    28,    33,    35,    37,    34,    36,    14,     0,
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    30,     0,     0,   113,     0,
       0,    74,    44,    51,    50,    52,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    61,    62,     0,    66,    18,
      67,    19,    68,     0,     0,    71,    97,    99,   100,    98,
     101,    16,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,    56,
      53,    59,    58,    55,    54,   175,    57,    48,     0,     0,
      63,    65,    64,    70,     0,    39,    47,    46,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     -25,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   137,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -223,   -12,    17,
      57,  -224,   206,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,    23,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   147,    16,    17,     1,    18,     2,     3,   171,   218,
      31,   270,   272,    94,    19,    20,    34,    21,    48,    49,
      50,    51,    52,    22,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    23,   250,   251,   168,
      24,   117,   155,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   156,    54,    25,    26,    27,    56,   157,    55,    28,
     136,   306,   178,   221
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   254,   160,   138,   145,   146,   160,  -145,   263,    41,
      42,    29,   268,    30,    43,   274,    44,    45,    37,    32,
      43,    14,   141,    45,    43,    46,   143,    45,   160,    33,
      35,   -81,   140,   253,    47,   163,    15,    36,    43,   163,
      44,    45,   148,   149,    40,   150,   137,   172,    43,    46,
      44,    45,   177,   179,   180,   139,   161,   169,    47,    46,
     162,   163,   299,   164,   170,   304,    38,    39,    47,   142,
     144,   165,   159,   271,   200,   201,   209,   166,   173,   174,
     175,   167,   219,   181,   176,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   220,   222,   223,   202,   203,   204,   205,
     206,   207,   224,   225,    43,   226,    44,    45,   227,   228,
     229,   230,   231,   232,   233,    46,   234,   208,   235,   210,
     236,   211,   -13,     4,    47,     5,    -4,    -4,    -4,    -4,
       6,     7,     8,     9,    10,    -4,   237,   238,    11,    12,
      -4,    -4,    -4,   239,   240,   241,    -4,   242,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
     243,   244,   245,   246,   247,    13,   248,   249,    14,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,   269,    43,   284,   261,
      45,   282,    43,    15,    44,    45,   148,   149,    46,   150,
     285,   286,    43,    46,   273,    45,   262,    47,   287,   264,
     265,   303,    47,    46,   288,   289,   275,   276,   291,   292,
     279,   280,    47,   -74,   281,   151,   152,   283,   293,   294,
     252,   296,   255,   256,   257,   258,   259,   260,   297,   140,
     266,   267,   153,   154,   307,   313,   158,   277,   278,     0,
     315,   140,   316,   317,   318,    43,     0,    44,    45,     0,
       0,     0,     0,     0,   301,     0,    46,   305,   290,     0,
       0,     0,   312,   311,   212,    47,     0,     0,     0,     0,
     295,     0,   213,   214,   215,   216,   217,     0,     0,     0,
       0,   298,   300,     0,   302,     0,     0,     0,   308,   309,
     310,     0,     0,   314,    57,    58,    59,    60,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,    62,    63,
      64,     0,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,    91,    92,    93
};

static const yytype_int16 yycheck[] =
{
      12,   224,    21,    28,    64,    65,    21,    24,   231,    14,
      15,     0,   235,    24,    53,   238,    55,    56,    53,    56,
      53,    56,    55,    56,    53,    64,    55,    56,    21,    53,
      53,    48,    44,    72,    73,    54,    71,    53,    53,    54,
      55,    56,    22,    23,    53,    25,    48,    59,    53,    64,
      55,    56,    64,    65,    66,    49,    49,    70,    73,    64,
      53,    54,   285,    56,    70,   288,     9,    10,    73,    46,
      47,    64,    69,    21,    86,    87,    67,    70,    53,    53,
      56,    74,    49,    66,    56,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    49,    49,    49,    89,    90,    91,    92,
      93,   136,    49,    49,    53,    49,    55,    56,    49,    49,
      49,    49,    49,    49,    49,    64,    49,   139,    49,   141,
      49,   143,     0,     1,    73,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    49,    49,    16,    17,
      18,    19,    20,    49,    49,    49,    24,    49,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      49,    67,    67,    49,    56,    53,    56,    49,    56,    57,
      58,    59,    60,    61,    62,    63,    50,    53,    55,    55,
      56,    49,    53,    71,    55,    56,    22,    23,    64,    25,
      49,    49,    53,    64,    55,    56,    72,    73,    49,   231,
     232,    72,    73,    64,    49,    49,   238,   239,    55,    55,
     242,   243,    73,    55,   246,    51,    52,   249,    49,    49,
     223,    55,   225,   226,   227,   228,   229,   230,    56,   261,
     233,   234,    68,    69,    67,    67,    50,   240,   241,    -1,
      67,   273,    67,    67,    67,    53,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,   286,    -1,    64,   289,   261,    -1,
      -1,    -1,   294,    71,   147,    73,    -1,    -1,    -1,    -1,
     273,    -1,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,   284,   285,    -1,   287,    -1,    -1,    -1,   291,   292,
     293,    -1,    -1,   296,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    79,    81,    82,     1,     3,     8,     9,    10,    11,
      12,    16,    17,    53,    56,    71,    77,    78,    80,    89,
      90,    92,    98,   121,   125,   148,   149,   150,   154,     0,
      24,    85,    56,    53,    91,    53,    53,    53,   125,   125,
      53,    14,    15,    53,    55,    56,    64,    73,    93,    94,
      95,    96,    97,   123,   147,   153,   151,     4,     5,     6,
       7,    13,    18,    19,    20,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    57,    58,    59,
      60,    61,    62,    63,    88,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   126,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   155,    48,    85,    49,
     123,    55,   147,    55,   147,    64,    65,    76,    22,    23,
      25,    51,    52,    68,    69,   127,   146,   152,   127,    69,
      21,    49,    53,    54,    56,    64,    70,    74,   124,    70,
      70,    83,   123,    53,    53,    56,    56,   123,   157,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     123,   123,   124,   124,   124,   124,   124,    85,   123,    67,
     123,   123,    94,    94,    94,    94,    94,    94,    84,    49,
      49,   158,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    67,    67,    49,    56,    56,    49,
     122,   123,   124,    72,   122,   124,   124,   124,   124,   124,
     124,    55,    72,   122,   123,   123,   124,   124,   122,    50,
      86,    21,    87,    55,   122,   123,   123,   124,   124,   123,
     123,   123,    49,   123,    55,    49,    49,    49,    49,    49,
     124,    55,    55,    49,    49,   124,    55,    56,   124,   122,
     124,   123,   124,    72,   122,   123,   156,    67,   124,   124,
     124,    71,   123,    67,   124,    67,    67,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    77,    77,    78,    79,    79,    80,
      80,    80,    81,    82,    83,    84,    84,    85,    86,    87,
      88,    88,    89,    90,    91,    91,    92,    93,    93,    94,
      94,    94,    94,    95,    95,    96,    96,    97,    98,    99,
     100,   100,   101,   102,   102,   103,   104,   104,   104,   104,
     105,   105,   106,   107,   108,   108,   108,   109,   110,   111,
     112,   113,   114,   114,   115,   115,   116,   117,   118,   119,
     119,   119,   120,   121,   122,   123,   123,   123,   123,   124,
     124,   125,   125,   125,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   149,   150,
     151,   151,   151,   151,   151,   151,   151,   151,   152,   152,
     153,   153,   153,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   155,   155,   155,   156,   157,   158,   158
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     2,     0,     2,     3,
       2,     2,     1,     1,     2,     0,     3,     1,     1,     1,
       1,     1,     2,     2,     0,     1,     4,     1,     3,     3,
       4,     4,     1,     3,     3,     3,     3,     3,     2,     7,
       2,     2,     1,     2,     4,     2,     7,     7,     6,     4,
       4,     4,     4,     6,     6,     6,     6,     6,     6,     6,
       2,     4,     4,     6,     6,     6,     4,     4,     4,     7,
       6,     4,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     4,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     4,     6,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     2,     2,     2,
       0,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     2,     0,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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
      yychar = yylex (&yylval);
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 178 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__PLUS ; }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 180 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__MINUS; }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 187 "asm_mips.yac" /* yacc.c:1646  */
    { prog.add_line(new Label((yyvsp[-1].text))) ; }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 193 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream lit ;
		    lit << (yyvsp[0].uval);
			prog.add_line(new Directive(".align",lit.str())) ;
		}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 226 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream bylist ;
		    bylist << (yyvsp[-1].uval) << strmap[(yyvsp[0].uval)] ;
			strmap[strmap_id] = bylist.str() ;
			(yyval.uval) = (yyvsp[0].uval) ;
		}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 235 "asm_mips.yac" /* yacc.c:1646  */
    {	strmap_id++ ;
			strmap[strmap_id] = "" ;
			(yyval.uval) = strmap_id ;
		}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 242 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream bylist ;
		    bylist << strmap[(yyvsp[-2].uval)] << "," << (yyvsp[0].uval);
			strmap[strmap_id] = bylist.str() ;
			(yyval.uval) = (yyvsp[-2].uval) ;
		}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 255 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = (yyvsp[0].uval); }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 260 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = (yyvsp[0].uval) & 0x00003fff; }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 271 "asm_mips.yac" /* yacc.c:1646  */
    {	prog.add_line(new Directive(".end",(yyvsp[0].text),false)) ; }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 277 "asm_mips.yac" /* yacc.c:1646  */
    { prog.add_line(new Directive(".ent",(yyvsp[0].text),true)) ; }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 282 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.text) = NULL; }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 284 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.text) = (yyvsp[0].text)  ; }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 292 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream lit ;
		    lit << (yyvsp[-2].text) << ",	" << (yyvsp[0].uval) ;
			prog.add_line(new Directive(".equ",lit.str())) ;
		}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 300 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = (yyvsp[0].uval); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 304 "asm_mips.yac" /* yacc.c:1646  */
    {
		if   ((yyvsp[-1].uval) == ASM_OPR__PLUS)
			{(yyval.uval) = (yyvsp[-2].uval) + (yyvsp[0].uval);}
		else
			{(yyval.uval) = (yyvsp[-2].uval) - (yyvsp[0].uval);}
		}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 316 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) =   (yyvsp[-1].uval); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 321 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ~ (yyvsp[-1].uval); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 326 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = - (yyvsp[-1].uval); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 328 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) =   (yyvsp[0].uval); }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 335 "asm_mips.yac" /* yacc.c:1646  */
    {
		if   ((yyvsp[-1].uval) == ASM_OPR__OR  ) (yyval.uval) = (yyvsp[-2].uval) | (yyvsp[0].uval);
		if   ((yyvsp[-1].uval) == ASM_OPR__AND ) (yyval.uval) = (yyvsp[-2].uval) & (yyvsp[0].uval);
		if   ((yyvsp[-1].uval) == ASM_OPR__XOR ) (yyval.uval) = (yyvsp[-2].uval) ^ (yyvsp[0].uval);
		}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 343 "asm_mips.yac" /* yacc.c:1646  */
    {
		if   ((yyvsp[-1].uval) == ASM_OPR__OR  ) (yyval.uval) = (yyvsp[-2].uval) | (yyvsp[0].uval);
		if   ((yyvsp[-1].uval) == ASM_OPR__AND ) (yyval.uval) = (yyvsp[-2].uval) & (yyvsp[0].uval);
		if   ((yyvsp[-1].uval) == ASM_OPR__XOR ) (yyval.uval) = (yyvsp[-2].uval) ^ (yyvsp[0].uval);
		}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 354 "asm_mips.yac" /* yacc.c:1646  */
    {
		if   ((yyvsp[-1].uval) == ASM_OPR__MUL ) (yyval.uval) = (yyvsp[-2].uval) * (yyvsp[0].uval);
		else                       (yyval.uval) = (yyvsp[-2].uval) / (yyvsp[0].uval);
		}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 361 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = (yyvsp[-2].uval) * (yyvsp[0].uval); }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 368 "asm_mips.yac" /* yacc.c:1646  */
    {
		if   ((yyvsp[-1].uval) == ASM_OPR__SHL ) (yyval.uval) = (yyvsp[-2].uval) << (yyvsp[0].uval);
		else                       (yyval.uval) = (yyvsp[-2].uval) >> (yyvsp[0].uval);
		}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 377 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream lab ;
		    lab << (yyvsp[0].text);
			prog.add_line(new Directive(".extern",lab.str())) ;
		}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 391 "asm_mips.yac" /* yacc.c:1646  */
    {	t_Operator op ;
			string m = strmap[(yyvsp[-5].uval)] ;
			
			switch((yyvsp[-6].uval)) {
				case ASM_MPS__PREF : op = t_Operator::pref ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-6].uval) << "is not an valid Codop_hint_mem for format_hint_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPImmediate((yyvsp[-5].uval)),new OPImmediate((yyvsp[-3].uval)),new OPRegister((yyvsp[-1].uval),Src))) ;	
		}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 405 "asm_mips.yac" /* yacc.c:1646  */
    {	t_Operator op ;
			string m = strmap[(yyvsp[0].uval)] ;
			
			switch((yyvsp[-1].uval)) {
				case ASM_MPS__J : op = t_Operator::j ; break ;
				case ASM_MPS__JAL : op = t_Operator::jal ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-1].uval) << "is not an valid Codop_label for format_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPLabel(m))) ;	
		}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 418 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-1].uval)) {
				case ASM_MPS__J : op = t_Operator::jr ; break ;
				case ASM_MPS__JAL : op = t_Operator::jalr ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-1].uval) << "is not an valid Codop_label for format_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 431 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[0].uval)) {
				case ASM_MPS__SYSCALL : op = t_Operator::syscallu ; break ;
				case ASM_MPS__WAIT : op = t_Operator::waitn ; break ;
				case ASM_MPS__RFE : op = t_Operator::rfe ; break ;
				case ASM_MPS__ERET : op = t_Operator::eret ; break ;
				case ASM_MPS__SYNC : op = t_Operator::sync_ ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[0].uval) << "is not an valid Codop_n for format_n" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op)) ;
		}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 448 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-1].uval)) {
				case ASM_MPS__JALR : op = t_Operator::jalr ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-1].uval) << "is not an valid Codop_od_rs for format_od_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 460 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__JALR : op = t_Operator::jalr ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_od_rs for format_od_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Dst),new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 473 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-1].uval)) {
				case ASM_MPS__MFHI : op = t_Operator::mfhi ; break ;
				case ASM_MPS__MFLO : op = t_Operator::mflo ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-1].uval) << "is not an valid Codop_rd for format_rd" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[0].uval),Dst))) ;
		}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 492 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-6].uval)) {
				case ASM_MPS__LB : op = t_Operator::lb ; break ;
				case ASM_MPS__LBU : op = t_Operator::lbu ; break ;
				case ASM_MPS__LH : op = t_Operator::lh ; break ;
				case ASM_MPS__LHU : op = t_Operator::lhu ; break ;
				case ASM_MPS__LW : op = t_Operator::lw ; break ;
				case ASM_MPS__LWL : op = t_Operator::lwl ; break ;
				case ASM_MPS__LWR : op = t_Operator::lwr ; break ;
				case ASM_MPS__LL : op = t_Operator::ll ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-6].uval) << "is not an valid Codop_rd_mem for format_rd_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-5].uval),Dst),new OPImmediate((yyvsp[-3].uval)),new OPRegister((yyvsp[-1].uval),Src))) ;
		}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 514 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-6].uval)) {
				case ASM_MPS__LB : op = t_Operator::lb ; break ;
				case ASM_MPS__LBU : op = t_Operator::lbu ; break ;
				case ASM_MPS__LH : op = t_Operator::lh ; break ;
				case ASM_MPS__LHU : op = t_Operator::lhu ; break ;
				case ASM_MPS__LW : op = t_Operator::lw ; break ;
				case ASM_MPS__LWL : op = t_Operator::lwl ; break ;
				case ASM_MPS__LWR : op = t_Operator::lwr ; break ;
				case ASM_MPS__LL : op = t_Operator::ll ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-6].uval) << "is not an valid Codop_rd_mem for format_rd_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-5].uval),Dst),new OPExpression((yyvsp[-3].text)),new OPRegister((yyvsp[-1].uval),Src))) ;
		}
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 535 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__LB : op = t_Operator::lb ; break ;
				case ASM_MPS__LBU : op = t_Operator::lbu ; break ;
				case ASM_MPS__LH : op = t_Operator::lh ; break ;
				case ASM_MPS__LHU : op = t_Operator::lhu ; break ;
				case ASM_MPS__LW : op = t_Operator::lw ; break ;
				case ASM_MPS__LWL : op = t_Operator::lwl ; break ;
				case ASM_MPS__LWR : op = t_Operator::lwr ; break ;
				case ASM_MPS__LL : op = t_Operator::ll ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rd_mem for format_rd_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-1].uval),Src))) ;
		}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 554 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__LB : op = t_Operator::lb ; break ;
				case ASM_MPS__LBU : op = t_Operator::lbu ; break ;
				case ASM_MPS__LH : op = t_Operator::lh ; break ;
				case ASM_MPS__LHU : op = t_Operator::lhu ; break ;
				case ASM_MPS__LW : op = t_Operator::lw ; break ;
				case ASM_MPS__LWL : op = t_Operator::lwl ; break ;
				case ASM_MPS__LWR : op = t_Operator::lwr ; break ;
				case ASM_MPS__LL : op = t_Operator::ll ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rd_mem for format_rd_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Dst),new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 576 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__LUI : op = t_Operator::lui ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rd_si16 for format_rd_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Dst),new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 588 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__LUI : op = t_Operator::lui ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rd_si16 for format_rd_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Dst),new OPExpression((yyvsp[0].text)))) ;
		}
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 603 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__CLO : op = t_Operator::clo ; break ;
				case ASM_MPS__CLZ : op = t_Operator::clz ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rd_rs for format_rd_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Dst),new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 621 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__ADD :	op = t_Operator::add; break ;
				case ASM_MPS__ADDU :op = t_Operator::addu ; break ;
				case ASM_MPS__AND :	op = t_Operator::and_ ; break ;
				case ASM_MPS__MUL :	op = t_Operator::mul ; break ;
				case ASM_MPS__NOR :	op = t_Operator::nor ; break ;
				case ASM_MPS__OR :	op = t_Operator::or_ ; break ;
				case ASM_MPS__SLT :	op = t_Operator::slt ; break ;
				case ASM_MPS__SLTU :op = t_Operator::sltu ; break ;
				case ASM_MPS__SUB :	op = t_Operator::sub ; break ;
				case ASM_MPS__SUBU :op = t_Operator::subu ; break ;
				case ASM_MPS__XOR :	op = t_Operator::xor_ ; break ;
				case ASM_MPS__MOVN :op = t_Operator::movn ; break ;
				case ASM_MPS__MOVZ :op = t_Operator::movz ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rd_rs_rt for format_rd_rs_rt" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-2].uval),Src),new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 650 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__ADDI : op = t_Operator::addi ; break ;
				case ASM_MPS__ADDIU : op = t_Operator::addiu ; break ;
				case ASM_MPS__SLTI : op = t_Operator::slti ; break ;
				case ASM_MPS__SLTIU : op = t_Operator::sltiu ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rd_rs_si16 for format_rd_rs_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-2].uval),Src),new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 667 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__ADDI : op = t_Operator::addi ; break ;
				case ASM_MPS__ADDIU : op = t_Operator::addiu ; break ;
				case ASM_MPS__SLTI : op = t_Operator::slti ; break ;
				case ASM_MPS__SLTIU : op = t_Operator::sltiu ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rd_rs_si16 for format_rd_rs_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-2].uval),Src),new OPExpression((yyvsp[0].text)))) ;
		}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 684 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__SLT : op = t_Operator::slti ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rd_rs_si16 for format_rd_rs_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-2].uval),Src),new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 701 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__ANDI : op = t_Operator::andi ; break ;
				case ASM_MPS__ORI : op = t_Operator::ori ; break ;
				case ASM_MPS__XORI : op = t_Operator::xori ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rd_rs_ui16 for format_rd_rs_ui16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-2].uval),Src),new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 720 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__SLLV : op = t_Operator::sllv ; break ;
				case ASM_MPS__SRLV : op = t_Operator::srlv ; break ;
				case ASM_MPS__SRAV : op = t_Operator::srav ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rd_rt_rs for format_rd_rt_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-2].uval),Src),new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 739 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__SLL : op = t_Operator::sll ; break ;
				case ASM_MPS__SRL : op = t_Operator::srl ; break ;
				case ASM_MPS__SRA : op = t_Operator::sra ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rd_rt_sham for format_rd_rt_sham" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-2].uval),Src),new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 754 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-1].uval)) {
				case ASM_MPS__JR : op = t_Operator::jr ; break ;
				case ASM_MPS__MTHI : op = t_Operator::mthi ; break ;
				case ASM_MPS__MTLO : op = t_Operator::mtlo ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-1].uval) << "is not an valid Codop_rs for format_rs" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 771 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			string m = strmap[(yyvsp[0].uval)] ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__BGEZ : op = t_Operator::bgez ; break ;
				case ASM_MPS__BGEZAL : op = t_Operator::bgezal ; break ;
				case ASM_MPS__BGTZ : op = t_Operator::bgtz ; break ;
				case ASM_MPS__BLEZ : op = t_Operator::blez ; break ;
				case ASM_MPS__BLTZ : op = t_Operator::bltz ; break ;
				case ASM_MPS__BLTZAL : op = t_Operator::bltzal ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rs_label for format_rs_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Src),new OPLabel(m))) ;
		}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 793 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__MULT: op = t_Operator::mult; break ;
				case ASM_MPS__MULTU: op = t_Operator::multu; break ;
				case ASM_MPS__DIV: op = t_Operator::div_ ; break ;
				case ASM_MPS__DIVU: op = t_Operator::divu ; break ;
				case ASM_MPS__MADD: op = t_Operator::madd; break ;
				case ASM_MPS__MADDU: op = t_Operator::maddu; break ;
				case ASM_MPS__MSUB: op = t_Operator::msub; break ;
				case ASM_MPS__MSUBU: op = t_Operator::msubu; break ;
				case ASM_MPS__TEQ: op = t_Operator::teq; break ;
				case ASM_MPS__TGE: op = t_Operator::tge; break ;
				case ASM_MPS__TGEU: op = t_Operator::tgeu; break ;
				case ASM_MPS__TLT: op = t_Operator::tlt; break ;
				case ASM_MPS__TLTU: op = t_Operator::tltu; break ;
				case ASM_MPS__TNE: op = t_Operator::tne ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rs_label for format_rs_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Src),new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 820 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			if ((yyvsp[-4].uval) != 0 ) {
				std::cerr << "Invalid $zero register for Codop_rs_label" << std::endl ;
			}
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__MULT: op = t_Operator::mult; break ;
				case ASM_MPS__MULTU: op = t_Operator::multu; break ;
				case ASM_MPS__DIV: op = t_Operator::div_ ; break ;
				case ASM_MPS__DIVU: op = t_Operator::divu ; break ;
				case ASM_MPS__MADD: op = t_Operator::madd; break ;
				case ASM_MPS__MADDU: op = t_Operator::maddu; break ;
				case ASM_MPS__MSUB: op = t_Operator::msub; break ;
				case ASM_MPS__MSUBU: op = t_Operator::msubu; break ;
				case ASM_MPS__TEQ: op = t_Operator::teq; break ;
				case ASM_MPS__TGE: op = t_Operator::tge; break ;
				case ASM_MPS__TGEU: op = t_Operator::tgeu; break ;
				case ASM_MPS__TLT: op = t_Operator::tlt; break ;
				case ASM_MPS__TLTU: op = t_Operator::tltu; break ;
				case ASM_MPS__TNE: op = t_Operator::tne ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rs_label for format_rs_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Dst),new OPRegister((yyvsp[-2].uval),Src),new OPRegister((yyvsp[0].uval),Src))) ;
		}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 853 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			string m = strmap[(yyvsp[0].uval)] ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__BEQ : op = t_Operator::beq ; break ;
				case ASM_MPS__BNE : op = t_Operator::bne ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rs_rt_label for format_rs_rt_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Src),new OPRegister((yyvsp[-2].uval),Src),new OPLabel(m))) ;
		}
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 869 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			std::ostringstream lit ;
		    lit  << (yyvsp[0].text) ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__BEQ : op = t_Operator::beq ; break ;
				case ASM_MPS__BNE : op = t_Operator::bne ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rs_rt_label for format_rs_rt_label" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Src),new OPRegister((yyvsp[-2].uval),Src),new OPLabel(lit.str()))) ;
		}
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 887 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__TEQI: op = t_Operator::teqi; break ;
				case ASM_MPS__TGEI: op = t_Operator::tgei; break ;
				case ASM_MPS__TGEIU: op = t_Operator::tgeiu; break ;
				case ASM_MPS__TLTI: op = t_Operator::tlti; break ;
				case ASM_MPS__TLTIU: op = t_Operator::tltiu; break ;
				case ASM_MPS__TNEI: op = t_Operator::tnei; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rs_si16 for format_rs_si16" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Src),new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 907 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			t_Src_Dst spin, spinc0 ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__MFC0: op = t_Operator::mfc0; spin = Dst ; spinc0 = CopSrc ; break ;
				case ASM_MPS__MTC0: op = t_Operator::mtc0; spin = Src ; spinc0 = CopDst ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rt_cop0r for format_rt_cop0r" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),spin),new OPRegister((yyvsp[0].uval),spinc0))) ;
		}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 924 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			t_Src_Dst spin, spinc0 ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__MFC2: op = t_Operator::mfc2; spin = Dst ; spinc0 = CopSrc ; break ;
				case ASM_MPS__MTC2: op = t_Operator::mtc2; spin = Src ; spinc0 = CopDst ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rt_cop2r for format_rt_cop2r" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),spin),new OPRegister((yyvsp[0].uval),spinc0))) ;
		}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 944 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-6].uval)) {
				case ASM_MPS__SB: op = t_Operator::sb ; break ;
				case ASM_MPS__SH: op = t_Operator::sh ; break ;
				case ASM_MPS__SW: op = t_Operator::sw ; break ;
				case ASM_MPS__SC: op = t_Operator::sc ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-6].uval) << "is not an valid Codop_rt_mem for format_rt_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-5].uval),Src),new OPImmediate((yyvsp[-3].uval)),new OPRegister((yyvsp[-1].uval),Src))) ;
		}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 961 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-5].uval)) {
				case ASM_MPS__SB: op = t_Operator::sb ; break ;
				case ASM_MPS__SH: op = t_Operator::sh ; break ;
				case ASM_MPS__SW: op = t_Operator::sw ; break ;
				case ASM_MPS__SC: op = t_Operator::sc ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-5].uval) << "is not an valid Codop_rt_mem for format_rt_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-4].uval),Src),new OPRegister((yyvsp[-1].uval),Src))) ;
		}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 976 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-3].uval)) {
				case ASM_MPS__SB: op = t_Operator::sb ; break ;
				case ASM_MPS__SH: op = t_Operator::sh ; break ;
				case ASM_MPS__SW: op = t_Operator::sw ; break ;
				case ASM_MPS__SC: op = t_Operator::sc ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Codop_rt_mem for format_rt_mem" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPRegister((yyvsp[-2].uval),Src),new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 992 "asm_mips.yac" /* yacc.c:1646  */
    {
			t_Operator op ;
			switch((yyvsp[-1].uval)) {
				case ASM_MPS__BREAK: op = t_Operator::break_ ; break ;
				default: std::cerr<< "asm_mips.yac : " << (yyvsp[-1].uval) << "is not an valid Codop_ui20 for format_ui20" << std::endl ; break ;
			}
			prog.add_line(new Instruction(op,new OPImmediate((yyvsp[0].uval)))) ;
		}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1005 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream lab ;
		    lab << (yyvsp[0].text);
			prog.add_line(new Directive(".global",lab.str())) ;
		}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1013 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = (yyvsp[0].uval) & 0x0000ffff; }
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1018 "asm_mips.yac" /* yacc.c:1646  */
    {  (yyval.uval) = (yyvsp[0].uval); }
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1020 "asm_mips.yac" /* yacc.c:1646  */
    {  (yyval.uval) = (yyvsp[0].uval); }
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1022 "asm_mips.yac" /* yacc.c:1646  */
    {  (yyval.uval) = (yyvsp[0].uval); }
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1024 "asm_mips.yac" /* yacc.c:1646  */
    {  (yyval.uval) = (yyvsp[0].uval); }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1029 "asm_mips.yac" /* yacc.c:1646  */
    {  (yyval.uval) = (yyvsp[0].uval); }
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1031 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = (yyvsp[0].uval) & 0x0000001f; }
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1036 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.text) = (yyvsp[0].text); }
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1038 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << (yyvsp[0].uval);
			(yyval.text) = const_cast<char*>(str.str().c_str()) ;
		}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1043 "asm_mips.yac" /* yacc.c:1646  */
    { 
		std::cout << "Label String2 " << (yyvsp[0].text) << std::endl ;
		(yyval.text) = (yyvsp[0].text); }
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1054 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__OR   ; }
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1056 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__AND  ; }
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1058 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__XOR  ; }
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1074 "asm_mips.yac" /* yacc.c:1646  */
    {
			string m = strmap[(yyvsp[0].uval)] ;
	  		if ((yyvsp[-1].uval) != ASM_MPS__B) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[-1].uval) << "is not an valid Macro_label" << std::endl ;
			}
			prog.add_line(new Instruction(t_Operator::bgez,new OPRegister(0,Src),new OPLabel(m))) ;
		}
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1085 "asm_mips.yac" /* yacc.c:1646  */
    {
	  		if ((yyvsp[0].uval) != ASM_MPS__NOP) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[0].uval) << "is not an valid Macro_n" << std::endl ;
			}
			prog.add_line(new Instruction(t_Operator::add,new OPRegister(0,Dst),new OPRegister(0,Src),new OPRegister(0,Src))) ;
		}
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1098 "asm_mips.yac" /* yacc.c:1646  */
    {
	  		if ((yyvsp[-3].uval) != ASM_MPS__LI) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Macro_rd_i32" << std::endl ;
			}
			int hi, lo ;
			hi = ((yyvsp[0].uval) >> 16) &  0x0000FFFF ;
			lo = ((yyvsp[0].uval)      ) &  0x0000FFFF ;
						
			prog.add_line(new Directive(".set","noat")) ; 
			prog.add_line(new Instruction(t_Operator::lui,new OPRegister(1,Dst),new OPImmediate(hi))) ;
			prog.add_line(new Instruction(t_Operator::ori,new OPRegister((yyvsp[-2].uval),Dst),new OPRegister(1,Src),new OPImmediate(lo))) ;
			prog.add_line(new Directive(".set","at")) ; 
		}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1118 "asm_mips.yac" /* yacc.c:1646  */
    {
			string m = strmap[(yyvsp[0].uval)] ;
		    std::ostringstream oss_hi ;
		    std::ostringstream oss_lo ;
	  		if ((yyvsp[-3].uval) != ASM_MPS__LI) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Macro_rd_i32" << std::endl ;
			}

		    oss_hi << "%hi(" << m << ")" ;
		    oss_lo << "%lo(" << m << ")" ;
						
			prog.add_line(new Directive(".set","noat")) ; 
			prog.add_line(new Instruction(t_Operator::lui,new OPRegister(1,Dst),new OPExpression(oss_hi.str()))) ;
			prog.add_line(new Instruction(t_Operator::ori,new OPRegister((yyvsp[-2].uval),Dst),new OPRegister(1,Src),new OPExpression(oss_lo.str()))) ;
			prog.add_line(new Directive(".set","at")) ; 
		}
#line 2597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1141 "asm_mips.yac" /* yacc.c:1646  */
    {
	  		if ((yyvsp[-3].uval) != ASM_MPS__MOVE) {
				std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Macro_rd_rs" << std::endl ;
			}
						
			prog.add_line(new Instruction(t_Operator::or_,new OPRegister((yyvsp[-2].uval),Dst),new OPRegister((yyvsp[0].uval),Src),new OPRegister(0,Src))) ;
		}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1155 "asm_mips.yac" /* yacc.c:1646  */
    {
	  		if ((yyvsp[-3].uval) == ASM_MPS__NEG) {
				prog.add_line(new Instruction(t_Operator::sub,new OPRegister((yyvsp[-2].uval),Dst),new OPRegister(0,Src),new OPRegister((yyvsp[0].uval),Src))) ;
			} else if ((yyvsp[-3].uval) == ASM_MPS__NEGU) {
				prog.add_line(new Instruction(t_Operator::subu,new OPRegister((yyvsp[-2].uval),Dst),new OPRegister(0,Src),new OPRegister((yyvsp[0].uval),Src))) ;
			} else {
				std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Macro_rd_rt" << std::endl ; break ;
			}
		}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1171 "asm_mips.yac" /* yacc.c:1646  */
    {
			string m = strmap[(yyvsp[0].uval)] ;
	  		if ((yyvsp[-3].uval) == ASM_MPS__BEQZ) {
				prog.add_line(new Instruction(t_Operator::beq,new OPRegister(0,Src),new OPRegister((yyvsp[-2].uval),Src),new OPLabel(m))) ;
			} else if ((yyvsp[-3].uval) == ASM_MPS__BNEZ) {
				prog.add_line(new Instruction(t_Operator::bne,new OPRegister(0,Src),new OPRegister((yyvsp[-2].uval),Src),new OPLabel(m))) ;
			} else {
				std::cerr<< "asm_mips.yac : " << (yyvsp[-3].uval) << "is not an valid Macro_rs_label" << std::endl ; break ;
			}
		}
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1197 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << (yyvsp[0].text) ;
			prog.add_line(new Directive(".ascii",str.str())) ;
		}
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1206 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << (yyvsp[0].text) ;
			prog.add_line(new Directive(".asciiz",str.str())) ;
		}
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1215 "asm_mips.yac" /* yacc.c:1646  */
    {prog.add_line(new Directive(".byte",strmap[(yyvsp[0].uval)])) ;}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1223 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << (yyvsp[-2].text) << "," << (yyvsp[0].uval) ;
			prog.add_line(new Directive(".lcomm",str.str())) ;
		}
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1236 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << (yyvsp[-4].text) << "," << (yyvsp[-2].uval) << "," << (yyvsp[0].uval);
			prog.add_line(new Directive(".comm",str.str())) ;
		}
#line 2680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1245 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << (yyvsp[0].uval) ;
			prog.add_line(new Directive(".space",str.str())) ;
		}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1254 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << (yyvsp[0].uval) ;
			prog.add_line(new Directive(".skip",str.str())) ;
		}
#line 2698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1263 "asm_mips.yac" /* yacc.c:1646  */
    {prog.add_line(new Directive(".word",strmap[(yyvsp[0].uval)])) ;}
#line 2704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1293 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__MUL  ; }
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1295 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__DIV  ; }
#line 2716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1300 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = (yyvsp[0].uval); }
#line 2722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1302 "asm_mips.yac" /* yacc.c:1646  */
    {	
			strmap_id++ ;
			strmap[strmap_id] = (yyvsp[0].text) ;
			(yyval.uval) = strmap_id ;
		}
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1312 "asm_mips.yac" /* yacc.c:1646  */
    { 	
			prog.add_line(new Directive(".section",(yyvsp[0].text))) ;
		}
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1316 "asm_mips.yac" /* yacc.c:1646  */
    {
			prog.add_line(new Directive((yyvsp[0].text))) ;
		}
#line 2748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1324 "asm_mips.yac" /* yacc.c:1646  */
    {	prog.add_line(new Directive(".set","reorder")) ; }
#line 2754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1327 "asm_mips.yac" /* yacc.c:1646  */
    {	prog.add_line(new Directive(".set","noreorder")) ; }
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1330 "asm_mips.yac" /* yacc.c:1646  */
    {	string m = strmap[(yyvsp[0].uval)] ;
			prog.add_line(new Directive(".set",m)) ; }
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1338 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream dir ;
		    dir << (yyvsp[-1].text) ;
			prog.add_line(new Directive(dir.str(),strmap[strmap_id])) ;
		}
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1346 "asm_mips.yac" /* yacc.c:1646  */
    {	strmap_id++ ;
			strmap[strmap_id] = "" ;
			(yyval.uval) = strmap_id ;
		}
#line 2785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1352 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[-1].uval)] << " " << (yyvsp[0].text);
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[-1].uval) ;
		}
#line 2795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1359 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[-1].uval)] << "," ;
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[-1].uval) ;
		}
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1366 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[-1].uval)] << "@";
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[-1].uval) ;
		}
#line 2815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1373 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[-1].uval)] << "$" << (yyvsp[0].uval) ;
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[-1].uval) ;
		}
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1380 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[-1].uval)] << (yyvsp[0].text);
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[-1].uval) ;
		}
#line 2835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1387 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[-1].uval)] << (yyvsp[0].uval);
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[-1].uval) ;
		}
#line 2845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1394 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream str ;
		    str << strmap[(yyvsp[-1].uval)] << "-";
			strmap[strmap_id] = str.str() ;
			(yyval.uval) = (yyvsp[-1].uval) ;
		}
#line 2855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1402 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__SHL  ; }
#line 2861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1404 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ASM_OPR__SHR  ; }
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1409 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) =   (yyvsp[0].uval); }
#line 2873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1412 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = - (yyvsp[0].uval); }
#line 2879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1415 "asm_mips.yac" /* yacc.c:1646  */
    { (yyval.uval) = ~ (yyvsp[0].uval); }
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1439 "asm_mips.yac" /* yacc.c:1646  */
    {	(yyval.uval) = (yyvsp[0].uval) & 0x0000ffff; }
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1445 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream bylist ;
		    bylist << (yyvsp[-1].uval) << strmap[(yyvsp[0].uval)] ;
			strmap[strmap_id] = bylist.str() ;
			(yyval.uval) = (yyvsp[0].uval) ;
		}
#line 2901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1454 "asm_mips.yac" /* yacc.c:1646  */
    {	strmap_id++ ;
			strmap[strmap_id] = "" ;
			(yyval.uval) = strmap_id ;
		}
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1461 "asm_mips.yac" /* yacc.c:1646  */
    {	std::ostringstream bylist ;
		    bylist << strmap[(yyvsp[-2].uval)] << "," << (yyvsp[0].uval);
			strmap[strmap_id] = bylist.str() ;
			(yyval.uval) = (yyvsp[-2].uval) ;
		}
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2924 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
  return yyresult;
}
#line 1468 "asm_mips.yac" /* yacc.c:1906  */

