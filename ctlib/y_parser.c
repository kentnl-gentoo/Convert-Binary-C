/* A Bison parser, made by GNU Bison 2.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse c_parse
#define yylex   c_lex
#define yyerror c_error
#define yylval  c_lval
#define yychar  c_char
#define yydebug c_debug
#define yynerrs c_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AUTO_TOK = 258,
     DOUBLE_TOK = 259,
     INT_TOK = 260,
     STRUCT_TOK = 261,
     BREAK_TOK = 262,
     ELSE_TOK = 263,
     LONG_TOK = 264,
     SWITCH_TOK = 265,
     CASE_TOK = 266,
     ENUM_TOK = 267,
     REGISTER_TOK = 268,
     TYPEDEF_TOK = 269,
     CHAR_TOK = 270,
     EXTERN_TOK = 271,
     RETURN_TOK = 272,
     UNION_TOK = 273,
     CONST_TOK = 274,
     FLOAT_TOK = 275,
     SHORT_TOK = 276,
     UNSIGNED_TOK = 277,
     CONTINUE_TOK = 278,
     FOR_TOK = 279,
     SIGNED_TOK = 280,
     VOID_TOK = 281,
     DEFAULT_TOK = 282,
     GOTO_TOK = 283,
     SIZEOF_TOK = 284,
     VOLATILE_TOK = 285,
     DO_TOK = 286,
     IF_TOK = 287,
     STATIC_TOK = 288,
     WHILE_TOK = 289,
     INLINE_TOK = 290,
     RESTRICT_TOK = 291,
     ASM_TOK = 292,
     SKIP_TOK = 293,
     PTR_OP = 294,
     INC_OP = 295,
     DEC_OP = 296,
     LEFT_OP = 297,
     RIGHT_OP = 298,
     LE_OP = 299,
     GE_OP = 300,
     EQ_OP = 301,
     NE_OP = 302,
     AND_OP = 303,
     OR_OP = 304,
     ELLIPSIS = 305,
     MUL_ASSIGN = 306,
     DIV_ASSIGN = 307,
     MOD_ASSIGN = 308,
     ADD_ASSIGN = 309,
     SUB_ASSIGN = 310,
     LEFT_ASSIGN = 311,
     RIGHT_ASSIGN = 312,
     AND_ASSIGN = 313,
     XOR_ASSIGN = 314,
     OR_ASSIGN = 315,
     STRING_LITERAL = 316,
     CONSTANT = 317,
     TYPE_NAME = 318,
     IDENTIFIER = 319
   };
#endif
/* Tokens.  */
#define AUTO_TOK 258
#define DOUBLE_TOK 259
#define INT_TOK 260
#define STRUCT_TOK 261
#define BREAK_TOK 262
#define ELSE_TOK 263
#define LONG_TOK 264
#define SWITCH_TOK 265
#define CASE_TOK 266
#define ENUM_TOK 267
#define REGISTER_TOK 268
#define TYPEDEF_TOK 269
#define CHAR_TOK 270
#define EXTERN_TOK 271
#define RETURN_TOK 272
#define UNION_TOK 273
#define CONST_TOK 274
#define FLOAT_TOK 275
#define SHORT_TOK 276
#define UNSIGNED_TOK 277
#define CONTINUE_TOK 278
#define FOR_TOK 279
#define SIGNED_TOK 280
#define VOID_TOK 281
#define DEFAULT_TOK 282
#define GOTO_TOK 283
#define SIZEOF_TOK 284
#define VOLATILE_TOK 285
#define DO_TOK 286
#define IF_TOK 287
#define STATIC_TOK 288
#define WHILE_TOK 289
#define INLINE_TOK 290
#define RESTRICT_TOK 291
#define ASM_TOK 292
#define SKIP_TOK 293
#define PTR_OP 294
#define INC_OP 295
#define DEC_OP 296
#define LEFT_OP 297
#define RIGHT_OP 298
#define LE_OP 299
#define GE_OP 300
#define EQ_OP 301
#define NE_OP 302
#define AND_OP 303
#define OR_OP 304
#define ELLIPSIS 305
#define MUL_ASSIGN 306
#define DIV_ASSIGN 307
#define MOD_ASSIGN 308
#define ADD_ASSIGN 309
#define SUB_ASSIGN 310
#define LEFT_ASSIGN 311
#define RIGHT_ASSIGN 312
#define AND_ASSIGN 313
#define XOR_ASSIGN 314
#define OR_ASSIGN 315
#define STRING_LITERAL 316
#define CONSTANT 317
#define TYPE_NAME 318
#define IDENTIFIER 319




/* Copy the first part of user declarations.  */
#line 1 "ctlib/parser.y"

/*******************************************************************************
*
* MODULE: parser.y
*
********************************************************************************
*
* DESCRIPTION: C parser
*
********************************************************************************
*
* $Project: /Convert-Binary-C $
* $Author: mhx $
* $Date: 2006/08/26 13:33:44 +0200 $
* $Revision: 64 $
* $Source: /ctlib/parser.y $
*
********************************************************************************
*
* Copyright (c) 2002-2006 Marcus Holland-Moritz. All rights reserved.
* This program is free software; you can redistribute it and/or modify
* it under the same terms as Perl itself.
*
* Portions Copyright (c) 1989, 1990 James A. Roskind.
* Also see the original copyright notice below.
*
*******************************************************************************/

/* Copyright (C) 1989,1990 James A. Roskind, All rights reserved.
This grammar was developed  and  written  by  James  A.  Roskind.
Copying  of  this  grammar  description, as a whole, is permitted
providing this notice is intact and applicable  in  all  complete
copies.   Translations as a whole to other parser generator input
languages  (or  grammar  description  languages)   is   permitted
provided  that  this  notice is intact and applicable in all such
copies,  along  with  a  disclaimer  that  the  contents  are   a
translation.   The reproduction of derived text, such as modified
versions of this grammar, or the output of parser generators,  is
permitted,  provided  the  resulting  work includes the copyright
notice "Portions Copyright (c)  1989,  1990  James  A.  Roskind".
Derived products, such as compilers, translators, browsers, etc.,
that  use  this  grammar,  must also provide the notice "Portions
Copyright  (c)  1989,  1990  James  A.  Roskind"  in   a   manner
appropriate  to  the  utility,  and in keeping with copyright law
(e.g.: EITHER displayed when first invoked/executed; OR displayed
continuously on display terminal; OR via placement in the  object
code  in  form  readable in a printout, with or near the title of
the work, or at the end of the file).  No royalties, licenses  or
commissions  of  any  kind are required to copy this grammar, its
translations, or derivative products, when the copies are made in
compliance with this notice. Persons or corporations that do make
copies in compliance with this notice may charge  whatever  price
is  agreeable  to  a  buyer, for such copies or derivative works.
THIS GRAMMAR IS PROVIDED ``AS IS'' AND  WITHOUT  ANY  EXPRESS  OR
IMPLIED  WARRANTIES,  INCLUDING,  WITHOUT LIMITATION, THE IMPLIED
WARRANTIES  OF  MERCHANTABILITY  AND  FITNESS  FOR  A  PARTICULAR
PURPOSE.

James A. Roskind
Independent Consultant
516 Latania Palm Drive
Indialantic FL, 32903
(407)729-4348
jar@ileaf.com


ACKNOWLEDGMENT:

Without the effort expended by the ANSI C standardizing committee,  I
would  have been lost.  Although the ANSI C standard does not include
a fully disambiguated syntax description, the committee has at  least
provided most of the disambiguating rules in narratives.

Several  reviewers  have also recently critiqued this grammar, and/or
assisted in discussions during it's preparation.  These reviewers are
certainly not responsible for the errors I have committed  here,  but
they  are responsible for allowing me to provide fewer errors.  These
colleagues include: Bruce Blodgett, and Mark Langley.

*/

/*===== GLOBAL INCLUDES ======================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*===== LOCAL INCLUDES =======================================================*/

#include "ctdebug.h"
#include "ctparse.h"
#include "cterror.h"
#include "fileinfo.h"
#include "parser.h"
#include "pragma.h"

#include "util/ccattr.h"
#include "util/list.h"
#include "util/memalloc.h"

#include "ucpp/cpp.h"

#include "cppreent.h"


/*===== DEFINES ==============================================================*/

/* ADDITIONAL BISON CONFIGURATION */

#define YYMAXDEPTH        10000
#define YYPARSE_PARAM    pState
#define YYLEX_PARAM      pState

/*
 * Bison version >= 1.31 is needed for YYFPRINTF
 */
#if YYDEBUG && defined CTLIB_DEBUGGING
#define YYFPRINTF BisonDebugFunc
#endif

#define c_error(msg)    parser_error(PSTATE, msg)

#define c_parse         CTlib_c_parse

/* MACROS */

#define PSTATE          ((ParserState *) pState)

#define DELETE_NODE(node)                                                      \
        do {                                                                   \
          if (node != NULL)                                                    \
            HN_delete(node);                                                   \
        } while (0)

#define POSTFIX_DECL(decl, postfix)                                            \
        do {                                                                   \
          if (postfix)                                                         \
          {                                                                    \
            if (decl->pointer_flag)                                            \
              LL_destroy(postfix, (LLDestroyFunc) value_delete);               \
            else                                                               \
            {                                                                  \
              if (decl->array_flag)                                            \
                LL_delete(LL_splice(decl->ext.array, 0, 0, postfix));          \
              else                                                             \
              {                                                                \
                decl->array_flag = 1;                                          \
                decl->ext.array = postfix;                                     \
              }                                                                \
            }                                                                  \
          }                                                                    \
        } while (0)

#define MAKE_TYPEDEF(list, decl)                                               \
        do {                                                                   \
          Typedef *pTypedef = typedef_new(&(list->type), decl);                \
          CT_DEBUG(PARSER, ("making new typedef => %s (list @ %p)",            \
                            decl->identifier, list));                          \
          LL_push(list->typedefs, pTypedef);                                   \
          HT_store(PSTATE->pCPI->htTypedefs, decl->identifier, 0, 0, pTypedef);\
        } while (0)

#define UNDEF_VAL(x) do { x.iv = 0; x.flags = V_IS_UNDEF; } while (0)

#define UNARY_OP(result, op, val) \
          do { result.iv = op val.iv; result.flags = val.flags; } while (0)

#define BINARY_OP(result, val1, op, val2)             \
          do {                                        \
            result.iv    = val1.iv   op val2.iv;      \
            result.flags = val1.flags | val2.flags;   \
          } while (0)

#define LLC_OR(t1, t2)                                \
        (                                             \
          ((t1) & T_LONG) && ((t2) & T_LONG)          \
          ? (t1) | (t2) | T_LONGLONG : (t1) | (t2)    \
        )

#define F_LOCAL     0x00000001U
#define BEGIN_LOCAL (PSTATE->flags |= F_LOCAL)
#define END_LOCAL   (PSTATE->flags &= ~F_LOCAL)
#define IS_LOCAL    (PSTATE->flags & F_LOCAL)


/*===== TYPEDEFS =============================================================*/

struct _parserState {

  const CParseConfig *pCPC;

  CParseInfo         *pCPI;

  PragmaState         pragma;

  struct CPP         *pp;
  struct lexer_state *pLexer;

  FileInfo           *pFI;

  u_32                flags;

};


/*===== STATIC VARIABLES =====================================================*/

/* TOKEN MAPPING TABLE */

static const int tokentab[] = {
	0,		/* NONE, */		/* whitespace */
	0,		/* NEWLINE, */		/* newline */
	0,		/* COMMENT, */		/* comment */
	0,		/* NUMBER, */		/* number constant */
	0,		/* NAME, */		/* identifier */
	0,		/* BUNCH, */		/* non-C characters */
	0,		/* PRAGMA, */		/* a #pragma directive */
	0,		/* CONTEXT, */		/* new file or #line */
	0,		/* STRING, */		/* constant "xxx" */
	CONSTANT,	/* CHAR, */		/* constant 'xxx' */
	'/',		/* SLASH, */		/*	/	*/
	DIV_ASSIGN,	/* ASSLASH, */		/*	/=	*/
	'-',		/* MINUS, */		/*	-	*/
	DEC_OP,		/* MMINUS, */		/*	--	*/
	SUB_ASSIGN,	/* ASMINUS, */		/*	-=	*/
	PTR_OP,		/* ARROW, */		/*	->	*/
	'+',		/* PLUS, */		/*	+	*/
	INC_OP,		/* PPLUS, */		/*	++	*/
	ADD_ASSIGN,	/* ASPLUS, */		/*	+=	*/
	'<',		/* LT, */		/*	<	*/
	LE_OP,		/* LEQ, */		/*	<=	*/
	LEFT_OP,	/* LSH, */		/*	<<	*/
	LEFT_ASSIGN,	/* ASLSH, */		/*	<<=	*/
	'>',		/* GT, */		/*	>	*/
	GE_OP,		/* GEQ, */		/*	>=	*/
	RIGHT_OP,	/* RSH, */		/*	>>	*/
	RIGHT_ASSIGN,	/* ASRSH, */		/*	>>=	*/
	'=',		/* ASGN, */		/*	=	*/
	EQ_OP,		/* SAME, */		/*	==	*/
#ifdef CAST_OP
	0,		/* CAST, */		/*	=>	*/
#endif
	'~',		/* NOT, */		/*	~	*/
	NE_OP,		/* NEQ, */		/*	!=	*/
	'&',		/* AND, */		/*	&	*/
	AND_OP,		/* LAND, */		/*	&&	*/
	AND_ASSIGN,	/* ASAND, */		/*	&=	*/
	'|',		/* OR, */		/*	|	*/
	OR_OP,		/* LOR, */		/*	||	*/
	OR_ASSIGN,	/* ASOR, */		/*	|=	*/
	'%',		/* PCT, */		/*	%	*/
	MOD_ASSIGN,	/* ASPCT, */		/*	%=	*/
	'*',		/* STAR, */		/*	*	*/
	MUL_ASSIGN,	/* ASSTAR, */		/*	*=	*/
	'^',		/* CIRC, */		/*	^	*/
	XOR_ASSIGN,	/* ASCIRC, */		/*	^=	*/
	'!',		/* LNOT, */		/*	!	*/
	'{',		/* LBRA, */		/*	{	*/
	'}',		/* RBRA, */		/*	}	*/
	'[',		/* LBRK, */		/*	[	*/
	']',		/* RBRK, */		/*	]	*/
	'(',		/* LPAR, */		/*	(	*/
	')',		/* RPAR, */		/*	)	*/
	',',		/* COMMA, */		/*	,	*/
	'?',		/* QUEST, */		/*	?	*/
	';',		/* SEMIC, */		/*	;	*/
	':',		/* COLON, */		/*	:	*/
	'.',		/* DOT, */		/*	.	*/
	ELLIPSIS,	/* MDOTS, */		/*	...	*/
	0,		/* SHARP, */		/*	#	*/
	0,		/* DSHARP, */		/*	##	*/

	0,		/* OPT_NONE, */		/* optional space to separate tokens in text output */

	0,		/* DIGRAPH_TOKENS, */		/* there begin digraph tokens */

	/* for DIG_*, do not change order, unless checking undig() in cpp.c */
	'[',		/* DIG_LBRK, */		/*	<:	*/
	']',		/* DIG_RBRK, */		/*	:>	*/
	'{',		/* DIG_LBRA, */		/*	<%	*/
	'}',		/* DIG_RBRA, */		/*	%>	*/
	0,		/* DIG_SHARP, */	/*	%:	*/
	0,		/* DIG_DSHARP, */	/*	%:%:	*/

	0,		/* DIGRAPH_TOKENS_END, */	/* digraph tokens end here */

	0,		/* LAST_MEANINGFUL_TOKEN, */	/* reserved words will go there */

	0,		/* MACROARG, */		/* special token for representing macro arguments */

	0,		/* UPLUS = CPPERR, */	/* unary + */
	0,		/* UMINUS */		/* unary - */
};



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 342 "ctlib/parser.y"
{
  HashNode           identifier;
  Declarator        *pDecl;
  AbstractDeclarator absDecl;
  StructDeclaration *pStructDecl;
  TypedefList       *pTypedefList;
  LinkedList         list;
  Enumerator        *pEnum;
  Typedef           *pTypedef;
  TypeSpec           tspec;
  Value              value;
  struct {
    u_32             uval;
    ContextInfo      ctx;
  }                  context;
  u_32               uval;
  char               oper;
}
/* Line 193 of yacc.c.  */
#line 548 "ctlib/y_parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 361 "ctlib/parser.y"


/*===== STATIC FUNCTION PROTOTYPES ===========================================*/

static inline int   c_lex(YYSTYPE *plval, ParserState *pState);

static inline int   get_char_value(const char *s);
static inline int   string_size(const char *s);
static inline int   check_type(YYSTYPE *plval, ParserState *pState, const char *s);
static        void  parser_error(ParserState *pState, const char *msg);



/* Line 216 of yacc.c.  */
#line 573 "ctlib/y_parser.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  120
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  132
/* YYNRULES -- Number of rules.  */
#define YYNRULES  365
/* YYNRULES -- Number of states.  */
#define YYNSTATES  617

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,     2,     2,    82,    75,     2,
      65,    66,    76,    77,    69,    78,    72,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    67,
      83,    88,    84,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    86,    74,    79,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    13,    14,    16,    22,    29,
      38,    49,    62,    63,    65,    67,    71,    76,    84,    86,
      90,    92,    94,    96,   100,   102,   107,   111,   116,   117,
     122,   123,   128,   131,   134,   142,   144,   146,   148,   152,
     154,   157,   160,   163,   166,   171,   173,   175,   177,   179,
     181,   183,   185,   190,   192,   196,   200,   204,   206,   210,
     214,   216,   220,   224,   226,   230,   234,   238,   242,   244,
     248,   252,   254,   258,   260,   264,   266,   270,   272,   276,
     278,   282,   284,   290,   292,   296,   298,   300,   302,   304,
     306,   308,   310,   312,   314,   316,   318,   319,   321,   323,
     327,   329,   330,   332,   335,   338,   341,   344,   349,   354,
     360,   365,   370,   376,   378,   380,   382,   384,   386,   388,
     390,   393,   396,   398,   401,   402,   404,   406,   408,   410,
     412,   414,   417,   420,   423,   426,   428,   431,   434,   437,
     440,   443,   446,   448,   451,   454,   456,   459,   462,   464,
     466,   469,   472,   475,   477,   480,   483,   485,   487,   489,
     491,   493,   495,   497,   499,   501,   503,   505,   507,   509,
     511,   513,   515,   517,   522,   528,   531,   533,   535,   537,
     538,   540,   542,   545,   548,   551,   553,   556,   560,   563,
     565,   566,   568,   571,   577,   584,   587,   589,   591,   595,
     597,   601,   603,   607,   609,   613,   615,   618,   621,   624,
     626,   629,   632,   634,   637,   640,   643,   645,   648,   651,
     653,   657,   659,   661,   663,   666,   668,   671,   672,   675,
     678,   683,   685,   688,   693,   694,   697,   699,   702,   706,
     709,   710,   712,   714,   716,   718,   720,   722,   724,   726,
     730,   735,   739,   742,   746,   750,   755,   757,   760,   762,
     765,   768,   774,   782,   788,   794,   802,   812,   816,   819,
     822,   826,   827,   829,   831,   834,   836,   838,   840,   841,
     845,   846,   851,   852,   857,   858,   863,   864,   869,   870,
     874,   875,   880,   881,   886,   887,   892,   893,   898,   899,
     904,   905,   911,   912,   918,   919,   925,   926,   932,   934,
     936,   938,   940,   942,   945,   947,   949,   952,   956,   960,
     965,   967,   972,   978,   981,   985,   989,   994,   999,  1001,
    1005,  1007,  1009,  1011,  1014,  1018,  1021,  1025,  1030,  1032,
    1036,  1038,  1041,  1045,  1050,  1054,  1059,  1061,  1063,  1065,
    1067,  1070,  1074,  1079,  1085,  1091,  1096,  1101,  1106,  1108,
    1111,  1114,  1118,  1122,  1126,  1130
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     183,     0,    -1,    61,    -1,    90,    61,    -1,    37,    65,
      90,    66,    -1,    -1,    91,    -1,    37,    65,   122,    66,
      67,    -1,    37,   132,    65,   122,    66,    67,    -1,    37,
     132,    65,   122,    68,    95,    66,    67,    -1,    37,   132,
      65,   122,    68,    95,    68,    95,    66,    67,    -1,    37,
     132,    65,   122,    68,    95,    68,    95,    68,    98,    66,
      67,    -1,    -1,    96,    -1,    97,    -1,    96,    69,    97,
      -1,    61,    65,   122,    66,    -1,    70,    64,    71,    61,
      65,   122,    66,    -1,    90,    -1,    98,    69,    90,    -1,
      64,    -1,    62,    -1,    90,    -1,    65,   122,    66,    -1,
      99,    -1,   100,    70,   122,    71,    -1,   100,    65,    66,
      -1,   100,    65,   104,    66,    -1,    -1,   100,   101,    72,
     103,    -1,    -1,   100,   102,    39,   103,    -1,   100,    40,
      -1,   100,    41,    -1,    65,   166,    66,    73,   169,   173,
      74,    -1,    64,    -1,    63,    -1,   119,    -1,   104,    69,
     119,    -1,   100,    -1,    40,   105,    -1,    41,   105,    -1,
     106,   107,    -1,    29,   105,    -1,    29,    65,   166,    66,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,   105,    -1,    65,   166,    66,   107,    -1,
     107,    -1,   108,    76,   107,    -1,   108,    81,   107,    -1,
     108,    82,   107,    -1,   108,    -1,   109,    77,   108,    -1,
     109,    78,   108,    -1,   109,    -1,   110,    42,   109,    -1,
     110,    43,   109,    -1,   110,    -1,   111,    83,   110,    -1,
     111,    84,   110,    -1,   111,    44,   110,    -1,   111,    45,
     110,    -1,   111,    -1,   112,    46,   111,    -1,   112,    47,
     111,    -1,   112,    -1,   113,    75,   112,    -1,   113,    -1,
     114,    85,   113,    -1,   114,    -1,   115,    86,   114,    -1,
     115,    -1,   116,    48,   115,    -1,   116,    -1,   117,    49,
     116,    -1,   117,    -1,   117,    87,   122,    68,   118,    -1,
     118,    -1,   105,   120,   119,    -1,    88,    -1,    51,    -1,
      52,    -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    -1,   119,
      -1,   119,    -1,   122,    69,   119,    -1,   118,    -1,    -1,
     122,    -1,   137,    67,    -1,   138,    67,    -1,   127,    67,
      -1,   126,    67,    -1,   130,   210,    92,   167,    -1,   131,
     210,    92,   167,    -1,   126,    69,   210,    92,   167,    -1,
     128,   202,    92,   167,    -1,   129,   202,    92,   167,    -1,
     127,    69,   202,    92,   167,    -1,   135,    -1,   137,    -1,
     141,    -1,   136,    -1,   138,    -1,   142,    -1,   143,    -1,
     131,   143,    -1,   130,   133,    -1,   134,    -1,   131,   134,
      -1,    -1,   131,    -1,   143,    -1,   134,    -1,    19,    -1,
      36,    -1,    30,    -1,   130,   144,    -1,   136,   143,    -1,
     135,   133,    -1,   135,   144,    -1,   144,    -1,   131,   144,
      -1,   136,   134,    -1,   136,   144,    -1,   130,   145,    -1,
     138,   143,    -1,   137,   133,    -1,   145,    -1,   131,   145,
      -1,   138,   134,    -1,   146,    -1,   131,   146,    -1,   138,
     134,    -1,   139,    -1,   142,    -1,   142,   143,    -1,   130,
      63,    -1,   141,   133,    -1,    63,    -1,   131,    63,    -1,
     142,   134,    -1,    14,    -1,    16,    -1,    33,    -1,     3,
      -1,    13,    -1,    35,    -1,     5,    -1,    15,    -1,    21,
      -1,     9,    -1,    20,    -1,     4,    -1,    25,    -1,    22,
      -1,    26,    -1,   146,    -1,   157,    -1,   147,    73,   149,
      74,    -1,   147,   165,    73,   149,    74,    -1,   147,   165,
      -1,   148,    -1,     6,    -1,    18,    -1,    -1,   150,    -1,
     151,    -1,   150,   151,    -1,   153,    67,    -1,   152,    67,
      -1,   140,    -1,   129,   154,    -1,   153,    69,   154,    -1,
     202,   155,    -1,   156,    -1,    -1,   156,    -1,    68,   123,
      -1,   158,    73,   159,   173,    74,    -1,   158,   165,    73,
     159,   173,    74,    -1,   158,   165,    -1,    12,    -1,   160,
      -1,   159,    69,   160,    -1,   165,    -1,   165,    88,   123,
      -1,   162,    -1,   162,    69,    50,    -1,   163,    -1,   162,
      69,   163,    -1,   128,    -1,   128,   216,    -1,   128,   210,
      -1,   128,   204,    -1,   130,    -1,   130,   216,    -1,   130,
     210,    -1,   129,    -1,   129,   216,    -1,   129,   210,    -1,
     129,   204,    -1,   131,    -1,   131,   216,    -1,   131,   210,
      -1,    64,    -1,   164,    69,    64,    -1,    64,    -1,    63,
      -1,   129,    -1,   129,   216,    -1,   131,    -1,   131,   216,
      -1,    -1,    88,   168,    -1,    73,    74,    -1,    73,   169,
     173,    74,    -1,   119,    -1,   170,   168,    -1,   169,    69,
     170,   168,    -1,    -1,   171,    88,    -1,   172,    -1,   171,
     172,    -1,    70,   123,    71,    -1,    72,   165,    -1,    -1,
      69,    -1,   175,    -1,   176,    -1,   179,    -1,   180,    -1,
     181,    -1,   182,    -1,    94,    -1,   165,    68,   174,    -1,
      11,   123,    68,   174,    -1,    27,    68,   174,    -1,    73,
      74,    -1,    73,   177,    74,    -1,    73,   178,    74,    -1,
      73,   177,   178,    74,    -1,   125,    -1,   177,   125,    -1,
     174,    -1,   178,   174,    -1,   124,    67,    -1,    32,    65,
     122,    66,   174,    -1,    32,    65,   122,    66,   174,     8,
     174,    -1,    10,    65,   122,    66,   174,    -1,    34,    65,
     122,    66,   174,    -1,    31,   174,    34,    65,   122,    66,
      67,    -1,    24,    65,   124,    67,   124,    67,   124,    66,
     174,    -1,    28,   165,    67,    -1,    23,    67,    -1,     7,
      67,    -1,    17,   124,    67,    -1,    -1,   184,    -1,   185,
      -1,   184,   185,    -1,   186,    -1,   125,    -1,    93,    -1,
      -1,   210,   187,   176,    -1,    -1,   128,   210,   188,   176,
      -1,    -1,   129,   210,   189,   176,    -1,    -1,   130,   210,
     190,   176,    -1,    -1,   131,   210,   191,   176,    -1,    -1,
     214,   192,   176,    -1,    -1,   128,   214,   193,   176,    -1,
      -1,   129,   214,   194,   176,    -1,    -1,   130,   214,   195,
     176,    -1,    -1,   131,   214,   196,   176,    -1,    -1,   214,
     177,   197,   176,    -1,    -1,   128,   214,   177,   198,   176,
      -1,    -1,   129,   214,   177,   199,   176,    -1,    -1,   130,
     214,   177,   200,   176,    -1,    -1,   131,   214,   177,   201,
     176,    -1,   210,    -1,   203,    -1,   207,    -1,   204,    -1,
      63,    -1,    63,   217,    -1,   205,    -1,   206,    -1,    76,
     204,    -1,    76,   131,   204,    -1,    65,   205,    66,    -1,
      65,   205,    66,   217,    -1,   208,    -1,    76,    65,   209,
      66,    -1,    76,   131,    65,   209,    66,    -1,    76,   207,
      -1,    76,   131,   207,    -1,    65,   207,    66,    -1,    65,
     209,   217,    66,    -1,    65,   207,    66,   217,    -1,    63,
      -1,    65,   209,    66,    -1,   211,    -1,   213,    -1,   212,
      -1,    76,   210,    -1,    76,   131,   210,    -1,   213,   217,
      -1,    65,   211,    66,    -1,    65,   211,    66,   217,    -1,
      64,    -1,    65,   213,    66,    -1,   215,    -1,    76,   214,
      -1,    76,   131,   214,    -1,   213,    65,   164,    66,    -1,
      65,   214,    66,    -1,    65,   214,    66,   217,    -1,   219,
      -1,   220,    -1,   217,    -1,   218,    -1,    65,    66,    -1,
      65,   161,    66,    -1,    70,   132,   121,    71,    -1,    70,
      33,   132,   119,    71,    -1,    70,   131,    33,   119,    71,
      -1,    70,   132,    76,    71,    -1,   218,    70,   119,    71,
      -1,   218,    70,    76,    71,    -1,    76,    -1,    76,   131,
      -1,    76,   216,    -1,    76,   131,   216,    -1,    65,   219,
      66,    -1,    65,   220,    66,    -1,    65,   217,    66,    -1,
      65,   219,    66,   217,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   626,   626,   627,   635,   638,   640,   644,   648,   649,
     651,   654,   660,   662,   666,   667,   671,   672,   680,   681,
     686,   701,   702,   703,   713,   714,   715,   716,   717,   717,
     718,   718,   719,   720,   721,   725,   726,   730,   731,   735,
     736,   737,   738,   756,   757,   761,   762,   763,   764,   765,
     766,   770,   771,   775,   776,   778,   785,   795,   796,   798,
     803,   804,   806,   811,   812,   814,   816,   818,   823,   824,
     826,   831,   832,   837,   838,   843,   844,   849,   850,   855,
     856,   861,   862,   867,   868,   872,   873,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   886,   887,   890,   891,
     895,   899,   901,   939,   940,   941,   942,   949,   973,   979,
     990,  1012,  1018,  1030,  1035,  1036,  1041,  1046,  1047,  1053,
    1054,  1055,  1059,  1060,  1063,  1065,  1069,  1070,  1074,  1075,
    1076,  1080,  1081,  1082,  1083,  1087,  1088,  1089,  1090,  1094,
    1099,  1104,  1112,  1113,  1114,  1118,  1119,  1120,  1124,  1125,
    1128,  1133,  1138,  1146,  1147,  1148,  1152,  1153,  1154,  1155,
    1156,  1157,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,
    1169,  1173,  1174,  1178,  1195,  1231,  1260,  1269,  1270,  1274,
    1275,  1279,  1290,  1304,  1305,  1309,  1313,  1326,  1340,  1367,
    1387,  1388,  1392,  1396,  1413,  1449,  1480,  1488,  1503,  1522,
    1535,  1551,  1552,  1556,  1557,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1582,
    1583,  1587,  1588,  1595,  1608,  1629,  1637,  1648,  1650,  1654,
    1655,  1656,  1660,  1661,  1664,  1666,  1670,  1671,  1675,  1676,
    1679,  1681,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1696,
    1697,  1698,  1702,  1703,  1704,  1705,  1709,  1710,  1714,  1715,
    1719,  1723,  1724,  1725,  1729,  1730,  1731,  1735,  1736,  1737,
    1738,  1744,  1746,  1750,  1751,  1755,  1756,  1757,  1761,  1761,
    1763,  1763,  1765,  1765,  1767,  1767,  1769,  1769,  1772,  1772,
    1773,  1773,  1774,  1774,  1775,  1775,  1776,  1776,  1778,  1778,
    1779,  1779,  1780,  1780,  1781,  1781,  1782,  1782,  1786,  1787,
    1791,  1792,  1796,  1800,  1814,  1821,  1822,  1828,  1837,  1838,
    1849,  1850,  1856,  1862,  1868,  1877,  1878,  1883,  1891,  1895,
    1899,  1900,  1904,  1905,  1911,  1920,  1925,  1926,  1934,  1946,
    1950,  1951,  1952,  1956,  1961,  1962,  1970,  1971,  1972,  1990,
    1991,  1992,  1996,  2007,  2018,  2029,  2030,  2041,  2055,  2060,
    2065,  2070,  2078,  2079,  2080,  2095
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO_TOK", "DOUBLE_TOK", "INT_TOK",
  "STRUCT_TOK", "BREAK_TOK", "ELSE_TOK", "LONG_TOK", "SWITCH_TOK",
  "CASE_TOK", "ENUM_TOK", "REGISTER_TOK", "TYPEDEF_TOK", "CHAR_TOK",
  "EXTERN_TOK", "RETURN_TOK", "UNION_TOK", "CONST_TOK", "FLOAT_TOK",
  "SHORT_TOK", "UNSIGNED_TOK", "CONTINUE_TOK", "FOR_TOK", "SIGNED_TOK",
  "VOID_TOK", "DEFAULT_TOK", "GOTO_TOK", "SIZEOF_TOK", "VOLATILE_TOK",
  "DO_TOK", "IF_TOK", "STATIC_TOK", "WHILE_TOK", "INLINE_TOK",
  "RESTRICT_TOK", "ASM_TOK", "SKIP_TOK", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "ELLIPSIS", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "STRING_LITERAL", "CONSTANT", "TYPE_NAME",
  "IDENTIFIER", "'('", "')'", "';'", "':'", "','", "'['", "']'", "'.'",
  "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "$accept",
  "string_literal_list", "asm_string", "asm_string_opt", "asm_expr",
  "asm_statement", "asm_operands_opt", "asm_operands", "asm_operand",
  "asm_clobbers", "primary_expression", "postfix_expression", "@1", "@2",
  "member_name", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "exclusive_OR_expression",
  "inclusive_OR_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression",
  "assignment_expression", "assignment_operator",
  "assignment_expression_opt", "comma_expression", "constant_expression",
  "comma_expression_opt", "declaration", "default_declaring_list",
  "declaring_list", "declaration_specifier", "type_specifier",
  "declaration_qualifier_list", "type_qualifier_list",
  "type_qualifier_list_opt", "declaration_qualifier", "type_qualifier",
  "basic_declaration_specifier", "basic_type_specifier",
  "sue_declaration_specifier", "sue_type_specifier", "su_type_specifier",
  "sut_type_specifier", "typedef_declaration_specifier",
  "typedef_type_specifier", "storage_class", "basic_type_name",
  "elaborated_type_name", "aggregate_name", "aggregate_key_context",
  "aggregate_key", "member_declaration_list_opt",
  "member_declaration_list", "member_declaration",
  "unnamed_su_declaration", "member_declaring_list", "member_declarator",
  "bit_field_size_opt", "bit_field_size", "enum_name", "enum_key_context",
  "enumerator_list", "enumerator", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "identifier_or_typedef_name",
  "type_name", "initializer_opt", "initializer", "initializer_list",
  "designation_opt", "designator_list", "designator", "comma_opt",
  "statement", "labeled_statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "source_file", "translation_unit", "external_definition",
  "function_definition", "@3", "@4", "@5", "@6", "@7", "@8", "@9", "@10",
  "@11", "@12", "@13", "@14", "@15", "@16", "@17", "declarator",
  "typedef_declarator", "parameter_typedef_declarator",
  "clean_typedef_declarator", "clean_postfix_typedef_declarator",
  "paren_typedef_declarator", "paren_postfix_typedef_declarator",
  "simple_paren_typedef_declarator", "identifier_declarator",
  "unary_identifier_declarator", "postfix_identifier_declarator",
  "paren_identifier_declarator", "old_function_declarator",
  "postfix_old_function_declarator", "abstract_declarator",
  "postfixing_abstract_declarator", "array_abstract_declarator",
  "unary_abstract_declarator", "postfix_abstract_declarator", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    40,    41,    59,    58,    44,
      91,    93,    46,   123,   125,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    91,    92,    92,    93,    94,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,    99,    99,   100,   100,   100,   100,   101,   100,
     102,   100,   100,   100,   100,   103,   103,   104,   104,   105,
     105,   105,   105,   105,   105,   106,   106,   106,   106,   106,
     106,   107,   107,   108,   108,   108,   108,   109,   109,   109,
     110,   110,   110,   111,   111,   111,   111,   111,   112,   112,
     112,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     123,   124,   124,   125,   125,   125,   125,   126,   126,   126,
     127,   127,   127,   128,   128,   128,   129,   129,   129,   130,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   135,   135,   135,   135,   136,   136,   136,   136,   137,
     137,   137,   138,   138,   138,   139,   139,   139,   140,   140,
     141,   141,   141,   142,   142,   142,   143,   143,   143,   143,
     143,   143,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   145,   145,   146,   146,   146,   147,   148,   148,   149,
     149,   150,   150,   151,   151,   152,   153,   153,   154,   154,
     155,   155,   156,   157,   157,   157,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   164,
     164,   165,   165,   166,   166,   166,   166,   167,   167,   168,
     168,   168,   169,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   174,   174,   174,   174,   174,   175,
     175,   175,   176,   176,   176,   176,   177,   177,   178,   178,
     179,   180,   180,   180,   181,   181,   181,   182,   182,   182,
     182,   183,   183,   184,   184,   185,   185,   185,   187,   186,
     188,   186,   189,   186,   190,   186,   191,   186,   192,   186,
     193,   186,   194,   186,   195,   186,   196,   186,   197,   186,
     198,   186,   199,   186,   200,   186,   201,   186,   202,   202,
     203,   203,   204,   204,   204,   205,   205,   205,   206,   206,
     207,   207,   207,   207,   207,   208,   208,   208,   209,   209,
     210,   210,   211,   211,   211,   212,   212,   212,   213,   213,
     214,   214,   214,   215,   215,   215,   216,   216,   216,   217,
     217,   217,   218,   218,   218,   218,   218,   218,   219,   219,
     219,   219,   220,   220,   220,   220
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     4,     0,     1,     5,     6,     8,
      10,    12,     0,     1,     1,     3,     4,     7,     1,     3,
       1,     1,     1,     3,     1,     4,     3,     4,     0,     4,
       0,     4,     2,     2,     7,     1,     1,     1,     3,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     3,
       1,     0,     1,     2,     2,     2,     2,     4,     4,     5,
       4,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     1,     1,
       2,     2,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     2,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     1,     2,     3,     2,     1,
       0,     1,     2,     5,     6,     2,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     2,     2,     1,
       2,     2,     1,     2,     2,     2,     1,     2,     2,     1,
       3,     1,     1,     1,     2,     1,     2,     0,     2,     2,
       4,     1,     2,     4,     0,     2,     1,     2,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       2,     5,     7,     5,     5,     7,     9,     3,     2,     2,
       3,     0,     1,     1,     2,     1,     1,     1,     0,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     5,     0,     5,     0,     5,     0,     5,     1,     1,
       1,     1,     1,     2,     1,     1,     2,     3,     3,     4,
       1,     4,     5,     2,     3,     3,     4,     4,     1,     3,
       1,     1,     1,     2,     3,     2,     3,     4,     1,     3,
       1,     2,     3,     4,     3,     4,     1,     1,     1,     1,
       2,     3,     4,     5,     5,     4,     4,     4,     1,     2,
       2,     3,     3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     271,   159,   167,   162,   177,   165,   196,   160,   156,   163,
     157,   178,   128,   166,   164,   169,   168,   170,   130,   158,
     161,   129,     0,   153,   338,     0,     0,   277,   276,     0,
       0,     0,     0,     0,     0,   122,   113,   116,   114,   117,
     115,   118,   119,   135,   142,   171,     0,   176,   172,     0,
       0,   272,   273,   275,   278,   330,   332,   331,   288,   340,
       0,     0,     0,     0,     0,   333,   341,   106,     0,   105,
       0,   312,     0,     0,     5,   309,   311,   314,   315,   310,
     320,   308,   290,     5,   308,   292,   151,   121,   127,   126,
     131,   139,     5,   294,   154,   123,   120,   136,   143,     5,
     296,   133,   134,   137,   132,   138,   103,   141,   104,   144,
     140,   152,   155,   150,   222,   221,   179,   175,     0,   195,
       1,   274,     0,     0,   124,   335,   349,   256,     0,     0,
       0,     0,   298,     0,     0,     0,     0,     2,    21,    20,
       0,    45,    46,    47,    48,    49,    50,    22,    24,    39,
      51,     0,    53,    57,    60,    63,    68,    71,    73,    75,
      77,    79,    81,    83,    98,     0,   336,   339,   344,   334,
     342,     0,     0,     5,   331,     0,     0,     5,   308,     0,
     313,   328,     0,     0,     0,     0,     0,     0,   316,   323,
       0,     6,   227,     0,   300,     0,   227,     0,   302,     0,
     227,     0,   304,     0,   227,     0,   306,     0,     0,     0,
     116,   117,   148,   185,   118,   171,     0,   180,   181,     0,
       0,   179,   240,   197,   199,     0,   101,   279,   219,   350,
     205,   212,   209,   216,   114,   117,     0,   201,   203,     0,
     124,   125,    96,     0,     5,     5,   257,     0,   289,     0,
      43,     0,    40,    41,     0,   223,   225,   117,   118,     0,
       3,    32,    33,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    85,     0,    51,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,   345,     0,     0,   227,     0,     0,     0,
     227,     0,   318,   325,     0,     0,     0,   317,   324,     0,
       0,   110,   281,     0,   291,   111,   283,     0,   293,   107,
     285,     0,   295,   108,   287,     0,   297,     0,   186,   189,
     190,   171,   144,   173,   182,   184,   183,     0,     0,   241,
       0,     0,   240,     0,     0,     0,   101,     0,     0,     0,
       0,   101,     0,     0,   124,   153,    20,   252,   248,   102,
       0,     0,   258,   242,   243,   101,   101,   244,   245,   246,
     247,     0,   358,   208,   207,   206,   348,   346,   347,   215,
     214,   213,     0,   358,   211,   210,   218,   217,   351,     0,
     343,     0,   125,     0,     0,    46,    97,     0,    46,     0,
     299,     0,     0,    23,     0,   358,   224,   226,     0,    26,
       0,    37,     0,     0,     0,    84,    54,    55,    56,    58,
      59,    61,    62,    66,    67,    64,    65,    69,    70,    72,
      74,    76,    78,    80,     0,     7,    99,   109,     0,   112,
     329,   319,   327,   326,   321,     0,     0,   234,   231,   228,
     301,   303,   305,   307,   100,   192,   188,   191,   187,   174,
     198,   193,   200,     0,   269,     0,     0,     0,   268,   101,
     101,     0,     0,     0,     0,     0,   260,   101,   253,   101,
     254,   259,     0,     0,     0,   359,   360,   359,   202,   204,
     220,     0,     0,   355,   352,   357,   356,    44,     0,   359,
     234,    52,    27,     0,    25,    36,    35,    29,    31,     0,
     322,     4,     0,     0,   229,   240,     0,     0,   236,   194,
       0,   101,   270,     0,   251,   267,     0,     0,     0,     0,
     249,   255,   364,   362,   363,   361,   353,   354,   240,    38,
      82,     0,   239,   234,     0,   232,   235,   237,   101,   250,
     101,     0,   101,   101,     0,   365,     0,   238,     0,   230,
     263,     0,     0,   261,   264,     0,    12,    34,   233,   101,
       0,   101,     8,     0,     0,     0,    13,    14,     0,   265,
     262,     0,     0,     0,    12,     0,   101,     0,     0,     9,
       0,    15,   266,    16,     0,     0,     0,     0,    10,    18,
       0,     0,     0,     0,    17,    11,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   147,   191,   200,    27,   368,   585,   586,   587,   610,
     148,   149,   265,   266,   517,   420,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   278,   407,   369,   465,   370,   127,    29,    30,   128,
     129,   130,   131,   242,    87,    35,    36,    37,    38,    39,
     212,   213,    40,    41,    42,    43,    44,    45,    46,    47,
     216,   217,   218,   219,   220,   338,   466,   339,    48,    49,
     222,   223,   236,   237,   238,   239,   371,   259,   321,   459,
     525,   526,   527,   528,   350,   372,   373,   374,   132,   376,
     377,   378,   379,   380,    50,    51,    52,    53,   122,   193,
     197,   201,   205,   133,   195,   199,   203,   207,   247,   323,
     327,   331,   335,    74,    75,    76,    77,    78,   184,    80,
     185,    65,    55,    56,   174,    63,    59,   496,   386,   126,
     387,   388
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -512
static const yytype_int16 yypact[] =
{
    1327,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,
    -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,
    -512,  -512,   -44,  -512,  -512,   285,   406,  -512,  -512,   188,
     288,   473,   473,  1535,  1571,  -512,  2154,  2154,   608,   944,
     750,   750,  -512,  -512,  -512,  -512,   -55,  -512,  -512,    20,
      36,  1327,  -512,  -512,  -512,  -512,  -512,    26,  1899,  -512,
    2017,   -41,    53,   -10,   406,  -512,  -512,  -512,   302,  -512,
     494,    97,   497,   631,    30,  -512,  -512,  -512,  -512,  -512,
    -512,    17,  1899,    30,    35,  1899,  -512,  -512,  -512,  -512,
    -512,  -512,    -7,  1899,  -512,  -512,  -512,  -512,  -512,    21,
    1899,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,
    -512,  -512,  -512,  -512,  -512,  -512,  1933,   108,    57,   120,
    -512,  -512,   134,  1770,   154,  -512,    89,  -512,   494,   494,
    1636,  1672,  1899,   134,  2024,  2069,  2069,  -512,  -512,  -512,
     891,  -512,  -512,  -512,  -512,  -512,  -512,     2,  -512,   186,
     328,  2017,  -512,   214,    88,   525,    -6,   579,   136,   138,
     143,   222,   -32,  -512,  -512,   -26,    97,  -512,    97,  -512,
    -512,   302,   850,    30,    97,   539,   971,    30,  -512,  1826,
    -512,  -512,   497,   213,   226,    97,   497,   989,  -512,  -512,
     244,  -512,   195,   134,  1899,   134,   195,   134,  1899,   134,
     195,   134,  1899,   134,   195,   134,  1899,   134,   409,  1961,
     914,   217,  -512,  -512,   149,   248,   250,  1933,  -512,   264,
     350,  1933,   307,  -512,   272,    57,   714,  -512,  -512,  -512,
     424,   424,  1363,  1431,   750,   750,   297,   332,  -512,    71,
     217,   278,  2076,  2121,    30,    30,  -512,   134,  -512,   891,
    -512,   891,  -512,  -512,    86,    34,  1734,   217,   217,   347,
    -512,  -512,  -512,  1964,  2017,   385,   429,  -512,  -512,  -512,
    -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  2017,  -512,
    -512,  2017,  2017,  2017,  2017,  2017,  2017,  2017,  2017,  2017,
    2017,  2017,  2017,  2017,  2017,  2017,  2017,  2017,  2017,  2017,
     408,  2017,  -512,  -512,   131,   850,   195,   539,   539,  1045,
     195,   267,    97,    97,   412,   381,   497,  -512,  -512,   423,
    1158,  -512,  -512,   134,  -512,  -512,  -512,   134,  -512,  -512,
    -512,   134,  -512,  -512,  -512,   134,  -512,  2017,  -512,  -512,
     427,   442,   447,  -512,  -512,  -512,  -512,   409,   446,    57,
     465,  2017,   307,   484,   481,  2017,  2017,   489,   499,   530,
      57,  1113,   541,   544,   217,   548,   552,  -512,  -512,   543,
     556,   562,  -512,  -512,  -512,   814,   965,  -512,  -512,  -512,
    -512,  1191,   623,  -512,  -512,  -512,  -512,  -512,  -512,  -512,
    -512,  -512,  1259,   633,  -512,  -512,  -512,  -512,  -512,  1860,
    -512,   569,   217,  2017,  2017,   564,  -512,   575,   580,   587,
    -512,   596,   600,  -512,  1467,   738,  -512,  -512,  1972,  -512,
     323,  -512,   276,   565,   565,  -512,  -512,  -512,  -512,   214,
     214,    88,    88,   525,   525,   525,   525,    -6,    -6,   579,
     136,   138,   143,   222,   571,  -512,  -512,  -512,   539,  -512,
    -512,  -512,  -512,  -512,  -512,   441,   303,   199,  -512,  -512,
    -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,
    -512,  -512,  -512,   597,  -512,  2017,   605,   612,  -512,  2017,
    1113,   614,   651,  2017,  2017,   635,  -512,  1113,  -512,  1039,
    -512,  -512,   636,   638,   639,   623,  -512,   633,  -512,  -512,
    -512,   630,   637,  -512,  -512,  -512,  -512,   640,   640,   738,
     394,  -512,  -512,  2017,  -512,  -512,  -512,  -512,  -512,  2017,
    -512,  -512,  2017,    57,  -512,   641,  1158,    25,  -512,  -512,
     324,  1113,  -512,   644,  -512,  -512,   649,   352,   414,  2017,
    -512,  -512,  -512,    97,  -512,  -512,  -512,  -512,   641,  -512,
    -512,   645,  -512,   334,   632,  -512,  -512,  -512,  1113,  -512,
    2017,  2017,  1113,  1113,   233,  -512,   678,  -512,  1158,  -512,
    -512,   648,   433,   748,  -512,   691,   176,  -512,  -512,  2017,
     692,  1113,  -512,   695,   697,   462,   693,  -512,   699,  -512,
    -512,  2017,   696,   703,   176,   176,  1113,   444,   710,  -512,
     506,  -512,  -512,  -512,   707,   706,   423,  2017,  -512,     2,
     460,   479,   715,   423,  -512,  -512,     2
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -512,  -313,  -512,    -1,  -512,  -512,   187,  -512,   189,  -512,
    -512,  -512,  -512,  -512,   371,  -512,   294,  -512,  -137,   363,
     378,   401,   391,   502,   504,   501,   503,   507,  -512,  -194,
    -115,  -512,  -512,   -60,  -328,  -325,    74,  -512,  -512,    13,
     105,    51,   151,  -229,   -14,     8,  -512,   122,   -94,   218,
    -512,  -512,  -512,   291,   422,   404,   362,    -9,  -512,  -512,
     583,  -512,   584,  -512,  -512,   464,  -512,   467,  -512,  -512,
     590,   463,  -512,  -512,   410,  -512,   -42,   356,   142,  -511,
     312,   299,  -512,   326,  -350,    38,  -512,   475,    24,   482,
    -512,  -512,  -512,  -512,  -512,  -512,   805,  -512,  -512,  -512,
    -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,  -512,
    -512,  -512,  -512,     5,  -512,   -61,    -4,  -512,   246,  -512,
    -166,     1,   -22,  -512,    28,   490,  -512,  -144,   -52,  -512,
    -311,  -234
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -287
static const yytype_int16 yytable[] =
{
     165,    54,   473,    61,   117,   125,   456,   119,   114,   115,
     125,   403,   188,    31,   280,   555,   311,   298,   116,   180,
     315,    60,   101,   472,   107,   166,   111,   476,    57,   234,
     190,   477,    81,    84,    92,    99,   120,    83,   288,   289,
     300,    88,    95,   301,    88,   103,    88,   109,    88,   112,
      61,    33,    54,    62,    57,   299,   168,   578,   190,    57,
      57,    57,    57,   260,    31,   169,  -284,   190,   183,   173,
     493,   178,    95,   192,    28,   177,   224,   290,   291,    57,
     254,   493,   196,   114,   115,   234,   385,   391,   395,   397,
    -280,   123,    57,   118,  -286,   522,   124,   523,   204,   414,
      62,    57,    33,   493,   124,    32,   194,   215,  -282,   198,
     415,   416,   417,   556,   302,   188,   303,   202,   123,   167,
     114,   115,   125,   124,   206,    28,   317,   406,   409,   178,
     178,   244,   245,   314,    83,   485,   230,   400,    88,    95,
     401,   311,   315,   464,   426,   427,   428,   494,   421,    61,
     455,    34,   413,    61,   533,   301,    32,   464,   494,   243,
      61,   464,   179,   425,    61,   284,   285,   124,    12,   383,
     389,   183,   306,    12,   232,   554,   310,    64,   183,    18,
     494,   221,   183,   224,    18,    21,   446,   240,   169,   254,
      21,   254,   230,   225,   551,    95,   179,   167,   566,   304,
     341,   124,    34,   304,   422,   458,   246,   226,   215,   178,
      62,   294,   215,   340,    62,    57,  -149,    95,   103,   342,
     107,   208,   112,   295,   187,   -30,   261,   262,   231,   296,
     232,   384,   390,   394,   396,   571,    12,   583,   210,   444,
      88,    95,    88,   109,   204,   255,   584,    18,   317,    95,
     375,   263,   125,    21,   588,    67,   264,    68,   -28,   314,
     451,   452,   210,   314,    95,   109,   112,   209,   246,   522,
     297,   523,   246,   524,   233,   241,   246,    79,    79,   312,
     246,   511,   455,   320,   231,    61,    61,   234,   501,   502,
     281,   256,   313,   609,    61,   282,   283,    12,   234,   575,
     616,   576,   301,   183,   183,   234,   169,   224,    18,   319,
     169,   404,   183,    95,    21,  -145,    79,    95,   481,   189,
     234,   188,   208,   305,   343,   550,   208,   309,   464,   492,
     233,   345,   179,   450,   211,   304,   304,   124,   325,   210,
     492,   235,   329,   210,    62,   301,   333,   514,   178,    24,
      25,   545,   340,   545,   255,    69,   255,    70,   257,    61,
     351,    26,   492,   398,   260,   545,    24,   171,   209,   521,
      61,   210,   209,   210,    79,    79,   349,   183,   172,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   512,
     558,   402,   513,   301,   230,    91,    98,   235,   549,   482,
     256,   399,   256,   314,   522,   230,   523,   214,  -241,   304,
      95,   458,   230,   418,   491,   530,   277,   346,   562,   347,
     304,   301,   189,   537,   538,    12,    61,   230,   250,   252,
     253,   258,   232,   318,   317,   211,    18,    90,    97,   211,
     102,   105,    21,   232,   183,   279,   179,   454,   447,   246,
     232,   124,   449,   458,    79,    89,    96,   423,    89,   104,
      89,   110,    89,   113,   522,   232,   523,   257,   424,   257,
      24,    25,    71,    24,   175,   445,   304,   337,   453,   564,
     563,   552,    26,   301,   137,   176,   231,    71,    24,   381,
      58,   565,    91,    98,   124,   337,   169,   231,   169,   580,
     382,   572,   301,    95,   231,    95,   179,   520,   214,  -146,
     603,   124,   214,   301,  -147,   402,    66,    95,   534,   231,
     469,    82,    85,    93,   100,   540,   612,   491,   593,   613,
     594,   597,   233,   495,    90,    97,    71,    24,    72,   471,
     258,    58,   258,   233,   497,   614,   475,   611,   301,    73,
     233,   474,    89,    96,   170,   318,   478,    71,    24,   175,
     181,    24,   182,    66,   479,   233,   509,   286,   287,   559,
     176,    98,   605,    73,   606,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,    79,    91,    98,   570,   227,   480,   235,
     573,   574,   181,    24,   307,   411,   483,   412,   248,   484,
     235,     1,   301,    97,   105,   176,  -222,   235,    98,   590,
    -221,     7,     8,   486,    10,   292,   293,    12,   515,   516,
     487,   279,   235,   500,   602,   503,    90,    97,    18,   519,
     301,    19,    12,    20,    21,   279,   504,   429,   430,   279,
      12,   505,    12,    18,    89,    96,    89,   110,   506,    21,
      97,    18,   507,    18,   431,   432,   508,    21,   322,    21,
     324,   529,   326,   531,   328,   106,   330,   170,   332,   532,
     334,   535,   336,   437,   438,   536,    71,    24,   381,   433,
     434,   435,   436,   124,    71,    24,   186,    24,   392,   382,
     539,   546,   542,   124,   543,   544,   569,    73,   547,   393,
     553,   560,   279,   510,   561,   579,   567,     1,     2,     3,
       4,   353,   410,     5,   354,   355,     6,     7,     8,     9,
      10,   356,    11,    12,    13,    14,    15,   357,   358,    16,
      17,   359,   360,   134,    18,   361,   362,    19,   363,    20,
      21,   364,   577,     1,   135,   136,   581,    12,   582,   589,
     591,   592,   595,     7,     8,   596,    10,   598,    18,    12,
     599,   604,   607,   608,    21,   137,   138,   365,   366,   140,
      18,   600,   615,    19,   601,    20,    21,   226,   367,   141,
     142,   143,   144,   145,   146,   518,   439,   441,   460,   440,
     442,   344,   461,   414,   348,   443,   462,   467,   124,   499,
     463,   468,   470,   279,   415,   352,   279,     1,     2,     3,
       4,   353,   548,     5,   354,   355,     6,     7,     8,     9,
      10,   356,    11,    12,    13,    14,    15,   357,   358,    16,
      17,   359,   360,   134,    18,   361,   362,    19,   363,    20,
      21,   364,   568,   557,   135,   136,   121,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,   137,   138,   365,   366,   140,
      18,     0,     0,     0,     0,     0,    21,   226,   488,   141,
     142,   143,   144,   145,   146,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     0,     0,     9,     0,     0,    11,
      12,    13,    14,    15,    24,   171,    16,    17,     2,     3,
     134,    18,     0,     5,     0,     0,   172,    21,     0,     9,
       0,   135,   136,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,     1,     0,     0,
      21,     0,   137,   138,    23,   139,   140,     7,     8,     0,
      10,     0,     0,    12,     0,     0,   141,   142,   143,   144,
     145,   146,   353,     0,    18,   354,   355,    19,     0,    20,
      21,     0,   356,     0,     0,     0,     0,     0,   357,   358,
      12,     0,   359,   360,   134,     0,   361,   362,     0,   363,
       0,    18,   364,     0,     0,   135,   136,    21,    12,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    21,   137,   138,   114,   366,
     140,     0,     0,     0,    71,    24,   308,     0,   226,   490,
     141,   142,   143,   144,   145,   146,   353,   176,     0,   354,
     355,     0,    71,    24,   316,     0,   356,     0,     0,     0,
       0,     0,   357,   358,    12,    73,   359,   360,   134,     0,
     361,   362,     0,   363,     0,    18,   364,     0,     0,   135,
     136,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   114,   366,   140,     0,     0,     0,    71,    24,
     448,     0,   226,   541,   141,   142,   143,   144,   145,   146,
     353,   176,     0,   354,   355,     0,     0,     0,     0,     0,
     356,     0,     0,     0,     0,     0,   357,   358,     0,     0,
     359,   360,   134,     0,   361,   362,     0,   363,     0,     0,
     364,     0,     0,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   114,   366,   140,     0,
       0,     0,     0,     0,     0,     0,   226,   134,   141,   142,
     143,   144,   145,   146,     1,     2,     3,     4,   135,   136,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,   137,
     138,    18,   139,   140,    19,     0,    20,    21,     0,     0,
       0,   457,     0,   141,   142,   143,   144,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,   381,   229,     0,     0,
       0,   124,     1,     2,     3,     4,     0,   382,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,     0,    18,
       0,     0,    19,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,   392,   229,     0,     0,     0,   124,
       1,     2,     3,     4,     0,   393,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,    20,    21,    22,     0,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      23,    24,    25,    18,     0,     0,    19,     0,    20,    21,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    24,   392,     0,
       0,     0,     0,   124,     1,     2,     3,     4,     0,   393,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,     0,     0,    19,     0,    20,    21,     0,     0,
       1,     2,     3,     4,     0,     0,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,    94,    24,   392,    18,     0,     0,
      19,   124,    20,    21,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,   414,   229,     0,     0,     0,   124,     1,     2,
       3,     4,     0,   415,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,     0,
      20,    21,     0,     0,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,    86,    24,
      25,    18,     0,     0,    19,     0,    20,    21,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    24,    25,     0,     0,     1,
       2,     3,     4,     0,     0,     5,     0,    26,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21,     0,     0,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,    86,
      24,   171,    18,     0,     0,    19,     0,    20,    21,     0,
       0,     0,   172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    24,   171,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     0,   172,     9,
       0,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      21,     0,     0,     1,     2,     3,     4,     0,     0,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,    94,     0,   414,
      18,     0,     0,    19,   124,    20,    21,     0,     0,     0,
     415,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,    23,   228,     5,   229,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21,     1,     2,     3,     4,     0,     0,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,    23,
      18,     0,   229,    19,     0,    20,    21,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     0,     0,     5,     0,
     498,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,    23,    16,    17,     0,     0,     0,    18,
       0,     0,    19,     0,    20,    21,     0,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     0,     0,     9,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,    23,    18,     0,     2,     3,     4,     0,    21,
       5,     0,     0,     6,     0,     0,     9,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,     0,   134,     0,     0,    23,    21,     0,     0,
       0,   134,     0,     0,   135,   136,     0,     0,     0,     0,
       0,     0,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,   137,   138,     0,   139,   140,
     419,     0,     0,   137,   138,     0,   139,   140,     0,   141,
     142,   143,   144,   145,   146,   510,   134,   141,   142,   143,
     144,   145,   146,   134,     0,     0,     0,   135,   136,     0,
       0,     0,     0,     0,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
       0,   139,   140,     0,     0,   137,   138,     0,   139,   249,
       0,     0,   141,   142,   143,   144,   145,   146,   134,   141,
     142,   143,   144,   145,   146,   134,     0,     0,     0,   135,
     136,     0,     0,     0,     0,     0,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,     0,   139,   251,     0,     0,   137,   138,     0,
     139,   140,     0,     0,   141,   142,   143,   144,   145,   146,
     134,   141,   405,   143,   144,   145,   146,     1,     2,     3,
       0,   135,   136,     5,     0,     0,     0,     7,     8,     9,
      10,     0,     0,    12,    13,    14,    15,     0,     0,    16,
      17,     0,   137,   138,    18,   139,   140,    19,     0,    20,
      21,     0,     0,     0,     0,     0,   141,   408,   143,   144,
     145,   146
};

static const yytype_int16 yycheck[] =
{
      60,     0,   352,    25,    46,    57,   319,    49,    63,    64,
      62,   240,    73,     0,   151,   526,   182,    49,    73,    71,
     186,    65,    36,   351,    38,    66,    40,   355,     0,   123,
      37,   356,    31,    32,    33,    34,     0,    32,    44,    45,
      66,    33,    34,    69,    36,    37,    38,    39,    40,    41,
      72,     0,    51,    25,    26,    87,    66,   568,    37,    31,
      32,    33,    34,    61,    51,    64,    73,    37,    72,    68,
     381,    70,    64,    74,     0,    70,   118,    83,    84,    51,
     140,   392,    83,    63,    64,   179,   230,   231,   232,   233,
      73,    65,    64,    73,    73,    70,    70,    72,    99,    65,
      72,    73,    51,   414,    70,     0,    82,   116,    73,    85,
      76,   255,   256,    88,   166,   176,   168,    93,    65,    66,
      63,    64,   174,    70,   100,    51,   187,   242,   243,   128,
     129,   130,   131,   185,   129,   364,   123,    66,   130,   131,
      69,   307,   308,   337,   281,   282,   283,   381,   263,   171,
     316,     0,    66,   175,   479,    69,    51,   351,   392,    70,
     182,   355,    65,   278,   186,    77,    78,    70,    19,   230,
     231,   175,   173,    19,   123,   525,   177,    26,   182,    30,
     414,    73,   186,   225,    30,    36,   301,    33,   187,   249,
      36,   251,   179,    73,   522,   187,    65,    66,   548,   171,
     209,    70,    51,   175,   264,   320,   132,    73,   217,   208,
     182,    75,   221,   208,   186,   187,    67,   209,   210,   211,
     234,   116,   214,    85,    73,    39,    40,    41,   123,    86,
     179,   230,   231,   232,   233,   560,    19,    61,   116,   299,
     232,   233,   234,   235,   245,   140,    70,    30,   309,   241,
     226,    65,   304,    36,   579,    67,    70,    69,    72,   311,
     312,   313,   140,   315,   256,   257,   258,   116,   194,    70,
      48,    72,   198,    74,   123,   124,   202,    31,    32,    66,
     206,   418,   448,    88,   179,   307,   308,   381,   403,   404,
      76,   140,    66,   606,   316,    81,    82,    19,   392,    66,
     613,    68,    69,   307,   308,   399,   305,   349,    30,    65,
     309,    33,   316,   305,    36,    67,    70,   309,   360,    73,
     414,   382,   217,   172,    74,   519,   221,   176,   522,   381,
     179,    67,    65,    66,   116,   307,   308,    70,   196,   217,
     392,   123,   200,   221,   316,    69,   204,    71,   347,    64,
      65,   495,   347,   497,   249,    67,   251,    69,   140,   381,
      88,    76,   414,    66,    61,   509,    64,    65,   217,    66,
     392,   249,   221,   251,   128,   129,    69,   381,    76,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    66,
      66,   240,    69,    69,   381,    33,    34,   179,   513,   361,
     249,    69,   251,   455,    70,   392,    72,   116,    74,   381,
     402,   526,   399,    66,   376,   475,    88,    67,    66,    69,
     392,    69,   176,   483,   484,    19,   448,   414,   134,   135,
     136,   140,   381,   187,   495,   217,    30,    33,    34,   221,
      36,    37,    36,   392,   448,   151,    65,    66,   306,   375,
     399,    70,   310,   568,   208,    33,    34,    72,    36,    37,
      38,    39,    40,    41,    70,   414,    72,   249,    39,   251,
      64,    65,    63,    64,    65,    67,   448,    68,    66,   539,
      66,   523,    76,    69,    61,    76,   381,    63,    64,    65,
       0,   543,   130,   131,    70,    68,   495,   392,   497,    66,
      76,   561,    69,   495,   399,   497,    65,    66,   217,    67,
      66,    70,   221,    69,    67,   364,    26,   509,   480,   414,
      74,    31,    32,    33,    34,   487,    66,   489,    66,    69,
      68,   591,   381,   382,   130,   131,    63,    64,    65,    74,
     249,    51,   251,   392,   393,    66,    65,   607,    69,    76,
     399,    67,   130,   131,    64,   309,    67,    63,    64,    65,
      63,    64,    65,    73,    65,   414,   415,    42,    43,   531,
      76,   209,    66,    76,    68,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   347,   232,   233,   558,   122,    68,   381,
     562,   563,    63,    64,    65,   249,    65,   251,   133,    65,
     392,     3,    69,   209,   210,    76,    68,   399,   256,   581,
      68,    13,    14,    67,    16,    46,    47,    19,    63,    64,
      68,   337,   414,    64,   596,    71,   232,   233,    30,    68,
      69,    33,    19,    35,    36,   351,    71,   284,   285,   355,
      19,    71,    19,    30,   232,   233,   234,   235,    71,    36,
     256,    30,    66,    30,   286,   287,    66,    36,   193,    36,
     195,    74,   197,    68,   199,    67,   201,   187,   203,    67,
     205,    67,   207,   292,   293,    34,    63,    64,    65,   288,
     289,   290,   291,    70,    63,    64,    65,    64,    65,    76,
      65,    71,    66,    70,    66,    66,    74,    76,    71,    76,
      69,    67,   418,    73,    65,    67,    71,     3,     4,     5,
       6,     7,   247,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    74,     3,    40,    41,     8,    19,    67,    67,
      65,    64,    69,    13,    14,    66,    16,    71,    30,    19,
      67,    61,    65,    67,    36,    61,    62,    63,    64,    65,
      30,   594,    67,    33,   595,    35,    36,    73,    74,    75,
      76,    77,    78,    79,    80,   424,   294,   296,   323,   295,
     297,   217,   327,    65,   221,   298,   331,   340,    70,   399,
     335,   347,   349,   519,    76,   225,   522,     3,     4,     5,
       6,     7,   510,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   553,   527,    40,    41,    51,   375,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      30,    -1,    -1,    -1,    -1,    -1,    36,    73,    74,    75,
      76,    77,    78,    79,    80,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,    20,    21,    22,    64,    65,    25,    26,     4,     5,
      29,    30,    -1,     9,    -1,    -1,    76,    36,    -1,    15,
      -1,    40,    41,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,     3,    -1,    -1,
      36,    -1,    61,    62,    63,    64,    65,    13,    14,    -1,
      16,    -1,    -1,    19,    -1,    -1,    75,    76,    77,    78,
      79,    80,     7,    -1,    30,    10,    11,    33,    -1,    35,
      36,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,
      19,    -1,    27,    28,    29,    -1,    31,    32,    -1,    34,
      -1,    30,    37,    -1,    -1,    40,    41,    36,    19,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    63,    64,    65,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,     7,    76,    -1,    10,
      11,    -1,    63,    64,    65,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    19,    76,    27,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    30,    37,    -1,    -1,    40,
      41,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    63,    64,
      65,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
       7,    76,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    -1,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    29,    75,    76,
      77,    78,    79,    80,     3,     4,     5,     6,    40,    41,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    61,
      62,    30,    64,    65,    33,    -1,    35,    36,    -1,    -1,
      -1,    73,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,
      -1,    70,     3,     4,     5,     6,    -1,    76,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,    70,
       3,     4,     5,     6,    -1,    76,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    37,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      63,    64,    65,    30,    -1,    -1,    33,    -1,    35,    36,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    70,     3,     4,     5,     6,    -1,    76,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    63,    64,    65,    30,    -1,    -1,
      33,    70,    35,    36,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    66,    -1,    -1,    -1,    70,     3,     4,
       5,     6,    -1,    76,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    63,    64,
      65,    30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    76,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    63,
      64,    65,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    -1,    76,    15,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    63,    -1,    65,
      30,    -1,    -1,    33,    70,    35,    36,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    63,    64,     9,    66,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    63,
      30,    -1,    66,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      50,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    63,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    -1,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    63,    30,    -1,     4,     5,     6,    -1,    36,
       9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    29,    -1,    -1,    63,    36,    -1,    -1,
      -1,    29,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    61,    62,    -1,    64,    65,
      66,    -1,    -1,    61,    62,    -1,    64,    65,    -1,    75,
      76,    77,    78,    79,    80,    73,    29,    75,    76,    77,
      78,    79,    80,    29,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    64,    65,    -1,    -1,    61,    62,    -1,    64,    65,
      -1,    -1,    75,    76,    77,    78,    79,    80,    29,    75,
      76,    77,    78,    79,    80,    29,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    64,    65,    -1,    -1,    61,    62,    -1,
      64,    65,    -1,    -1,    75,    76,    77,    78,    79,    80,
      29,    75,    76,    77,    78,    79,    80,     3,     4,     5,
      -1,    40,    41,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    61,    62,    30,    64,    65,    33,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    25,    26,    30,    33,
      35,    36,    37,    63,    64,    65,    76,    93,   125,   126,
     127,   128,   129,   130,   131,   134,   135,   136,   137,   138,
     141,   142,   143,   144,   145,   146,   147,   148,   157,   158,
     183,   184,   185,   186,   210,   211,   212,   213,   214,   215,
      65,   211,   213,   214,   131,   210,   214,    67,    69,    67,
      69,    63,    65,    76,   202,   203,   204,   205,   206,   207,
     208,   210,   214,   202,   210,   214,    63,   133,   134,   143,
     144,   145,   210,   214,    63,   134,   143,   144,   145,   210,
     214,   133,   144,   134,   143,   144,    67,   133,    67,   134,
     143,   133,   134,   143,    63,    64,    73,   165,    73,   165,
       0,   185,   187,    65,    70,   217,   218,   125,   128,   129,
     130,   131,   177,   192,    29,    40,    41,    61,    62,    64,
      65,    75,    76,    77,    78,    79,    80,    90,    99,   100,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   122,    66,    66,    66,   210,
     214,    65,    76,   210,   213,    65,    76,   202,   210,    65,
     217,    63,    65,   205,   207,   209,    65,   131,   204,   207,
      37,    91,    92,   188,   177,   193,    92,   189,   177,   194,
      92,   190,   177,   195,    92,   191,   177,   196,   129,   131,
     136,   138,   139,   140,   142,   146,   149,   150,   151,   152,
     153,    73,   159,   160,   165,    73,    73,   176,    64,    66,
     128,   129,   130,   131,   137,   138,   161,   162,   163,   164,
      33,   131,   132,    70,   210,   210,   125,   197,   176,    65,
     105,    65,   105,   105,   122,   129,   131,   138,   142,   166,
      61,    40,    41,    65,    70,   101,   102,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    88,   120,   105,
     107,    76,    81,    82,    77,    78,    42,    43,    44,    45,
      83,    84,    46,    47,    75,    85,    86,    48,    49,    87,
      66,    69,   217,   217,   213,   131,    92,    65,    65,   131,
      92,   209,    66,    66,   217,   209,    65,   204,   207,    65,
      88,   167,   176,   198,   176,   167,   176,   199,   176,   167,
     176,   200,   176,   167,   176,   201,   176,    68,   154,   156,
     202,   146,   134,    74,   151,    67,    67,    69,   149,    69,
     173,    88,   159,     7,    10,    11,    17,    23,    24,    27,
      28,    31,    32,    34,    37,    63,    64,    74,    94,   122,
     124,   165,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    65,    76,   204,   210,   216,   217,   219,   220,   204,
     210,   216,    65,    76,   210,   216,   210,   216,    66,    69,
      66,    69,   131,   132,    33,    76,   119,   121,    76,   119,
     176,   166,   166,    66,    65,    76,   216,   216,    66,    66,
     104,   119,   122,    72,    39,   119,   107,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   111,   111,   112,
     113,   114,   115,   116,   122,    67,   119,   167,    65,   167,
      66,   217,   217,    66,    66,   209,    90,    73,   119,   168,
     176,   176,   176,   176,   118,   123,   155,   156,   154,    74,
     160,    74,   123,   173,    67,    65,   123,   124,    67,    65,
      68,   165,   174,    65,    65,   132,    67,    68,    74,   178,
      74,   174,   217,   219,   220,   131,   216,   131,    50,   163,
      64,   119,   119,    71,    71,    71,    71,    66,    66,   131,
      73,   107,    66,    69,    71,    63,    64,   103,   103,    68,
      66,    66,    70,    72,    74,   169,   170,   171,   172,    74,
     122,    68,    67,   124,   174,    67,    34,   122,   122,    65,
     174,    74,    66,    66,    66,   216,    71,    71,   169,   119,
     118,   123,   165,    69,   173,   168,    88,   172,    66,   174,
      67,    65,    66,    66,   122,   217,   173,    71,   170,    74,
     174,   124,   122,   174,   174,    66,    68,    74,   168,    67,
      66,     8,    67,    61,    70,    95,    96,    97,   124,    67,
     174,    65,    64,    66,    68,    69,    66,   122,    71,    67,
      95,    97,   174,    66,    61,    66,    68,    65,    67,    90,
      98,   122,    66,    69,    66,    67,    90
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    const YYSTYPE * const yyvaluep;
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
      case 64: /* "IDENTIFIER" */
#line 431 "ctlib/parser.y"
	{
  if ((yyvaluep->identifier))
    fprintf(yyoutput, "'%s' len=%d, hash=0x%lx", (yyvaluep->identifier)->key, (yyvaluep->identifier)->keylen, (unsigned long)(yyvaluep->identifier)->hash);
  else
    fprintf(yyoutput, "NULL");
};
#line 2066 "ctlib/y_parser.c"
	break;
      case 154: /* "member_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2092 "ctlib/y_parser.c"
	break;
      case 165: /* "identifier_or_typedef_name" */
#line 431 "ctlib/parser.y"
	{
  if ((yyvaluep->identifier))
    fprintf(yyoutput, "'%s' len=%d, hash=0x%lx", (yyvaluep->identifier)->key, (yyvaluep->identifier)->keylen, (unsigned long)(yyvaluep->identifier)->hash);
  else
    fprintf(yyoutput, "NULL");
};
#line 2102 "ctlib/y_parser.c"
	break;
      case 202: /* "declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2128 "ctlib/y_parser.c"
	break;
      case 203: /* "typedef_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2154 "ctlib/y_parser.c"
	break;
      case 204: /* "parameter_typedef_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2180 "ctlib/y_parser.c"
	break;
      case 205: /* "clean_typedef_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2206 "ctlib/y_parser.c"
	break;
      case 206: /* "clean_postfix_typedef_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2232 "ctlib/y_parser.c"
	break;
      case 207: /* "paren_typedef_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2258 "ctlib/y_parser.c"
	break;
      case 208: /* "paren_postfix_typedef_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2284 "ctlib/y_parser.c"
	break;
      case 209: /* "simple_paren_typedef_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2310 "ctlib/y_parser.c"
	break;
      case 210: /* "identifier_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2336 "ctlib/y_parser.c"
	break;
      case 211: /* "unary_identifier_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2362 "ctlib/y_parser.c"
	break;
      case 212: /* "postfix_identifier_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2388 "ctlib/y_parser.c"
	break;
      case 213: /* "paren_identifier_declarator" */
#line 510 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    if ((yyvaluep->pDecl)->bitfield_flag)
      fprintf(yyoutput, "%s:%d", (yyvaluep->pDecl)->identifier, (yyvaluep->pDecl)->ext.bitfield.bits);
    else
    {
      fprintf(yyoutput, "%s%s", (yyvaluep->pDecl)->pointer_flag ? "*" : "", (yyvaluep->pDecl)->identifier);

      if ((yyvaluep->pDecl)->array_flag)
      {
        ListIterator ai;
        Value *pValue;

        LL_foreach(pValue, ai, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2414 "ctlib/y_parser.c"
	break;
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
yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    const YYSTYPE * const yyvaluep;
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, 
		   int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule
		   )
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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
      case 64: /* "IDENTIFIER" */
#line 422 "ctlib/parser.y"
	{
  if ((yyvaluep->identifier))
  {
    CT_DEBUG(PARSER, ("deleting node @ %p", (yyvaluep->identifier)));
    HN_delete((yyvaluep->identifier));
  }
};
#line 2790 "ctlib/y_parser.c"
	break;
      case 149: /* "member_declaration_list_opt" */
#line 569 "ctlib/parser.y"
	{
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) structdecl_delete);
  }
};
#line 2801 "ctlib/y_parser.c"
	break;
      case 150: /* "member_declaration_list" */
#line 569 "ctlib/parser.y"
	{
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) structdecl_delete);
  }
};
#line 2812 "ctlib/y_parser.c"
	break;
      case 151: /* "member_declaration" */
#line 466 "ctlib/parser.y"
	{
  if ((yyvaluep->pStructDecl))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration @ %p", (yyvaluep->pStructDecl)));
    structdecl_delete((yyvaluep->pStructDecl));
  }
};
#line 2823 "ctlib/y_parser.c"
	break;
      case 152: /* "unnamed_su_declaration" */
#line 466 "ctlib/parser.y"
	{
  if ((yyvaluep->pStructDecl))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration @ %p", (yyvaluep->pStructDecl)));
    structdecl_delete((yyvaluep->pStructDecl));
  }
};
#line 2834 "ctlib/y_parser.c"
	break;
      case 153: /* "member_declaring_list" */
#line 466 "ctlib/parser.y"
	{
  if ((yyvaluep->pStructDecl))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration @ %p", (yyvaluep->pStructDecl)));
    structdecl_delete((yyvaluep->pStructDecl));
  }
};
#line 2845 "ctlib/y_parser.c"
	break;
      case 154: /* "member_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2856 "ctlib/y_parser.c"
	break;
      case 159: /* "enumerator_list" */
#line 552 "ctlib/parser.y"
	{
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting enumerator list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) enum_delete);
  }
};
#line 2867 "ctlib/y_parser.c"
	break;
      case 165: /* "identifier_or_typedef_name" */
#line 422 "ctlib/parser.y"
	{
  if ((yyvaluep->identifier))
  {
    CT_DEBUG(PARSER, ("deleting node @ %p", (yyvaluep->identifier)));
    HN_delete((yyvaluep->identifier));
  }
};
#line 2878 "ctlib/y_parser.c"
	break;
      case 202: /* "declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2889 "ctlib/y_parser.c"
	break;
      case 203: /* "typedef_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2900 "ctlib/y_parser.c"
	break;
      case 204: /* "parameter_typedef_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2911 "ctlib/y_parser.c"
	break;
      case 205: /* "clean_typedef_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2922 "ctlib/y_parser.c"
	break;
      case 206: /* "clean_postfix_typedef_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2933 "ctlib/y_parser.c"
	break;
      case 207: /* "paren_typedef_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2944 "ctlib/y_parser.c"
	break;
      case 208: /* "paren_postfix_typedef_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2955 "ctlib/y_parser.c"
	break;
      case 209: /* "simple_paren_typedef_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2966 "ctlib/y_parser.c"
	break;
      case 210: /* "identifier_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2977 "ctlib/y_parser.c"
	break;
      case 211: /* "unary_identifier_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2988 "ctlib/y_parser.c"
	break;
      case 212: /* "postfix_identifier_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2999 "ctlib/y_parser.c"
	break;
      case 213: /* "paren_identifier_declarator" */
#line 490 "ctlib/parser.y"
	{
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 3010 "ctlib/y_parser.c"
	break;
      case 217: /* "postfixing_abstract_declarator" */
#line 560 "ctlib/parser.y"
	{
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting array list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) value_delete);
  }
};
#line 3021 "ctlib/y_parser.c"
	break;
      case 218: /* "array_abstract_declarator" */
#line 560 "ctlib/parser.y"
	{
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting array list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) value_delete);
  }
};
#line 3032 "ctlib/y_parser.c"
	break;

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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 628 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (2)].value), +, (yyvsp[(2) - (2)].value)); ;}
    break;

  case 17:
#line 673 "ctlib/parser.y"
    {
	    if ((yyvsp[(2) - (7)].identifier))
	      HN_delete((yyvsp[(2) - (7)].identifier));
	  ;}
    break;

  case 20:
#line 687 "ctlib/parser.y"
    {
	    UNDEF_VAL((yyval.value));
	    if ((yyvsp[(1) - (1)].identifier))
	    {
	      Enumerator *pEnum = HT_get(PSTATE->pCPI->htEnumerators,
	                                 (yyvsp[(1) - (1)].identifier)->key, (yyvsp[(1) - (1)].identifier)->keylen, (yyvsp[(1) - (1)].identifier)->hash);
	      if (pEnum)
	      {
	        CT_DEBUG(CLEXER, ("enum found!"));
	        (yyval.value) = pEnum->value;
	      }
	      HN_delete((yyvsp[(1) - (1)].identifier));
	    }
	  ;}
    break;

  case 22:
#line 702 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); (yyval.value).iv++; ;}
    break;

  case 23:
#line 703 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[(2) - (3)].value); ;}
    break;

  case 25:
#line 714 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 26:
#line 715 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 27:
#line 716 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 28:
#line 717 "ctlib/parser.y"
    {;}
    break;

  case 29:
#line 717 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 30:
#line 718 "ctlib/parser.y"
    {;}
    break;

  case 31:
#line 718 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 32:
#line 719 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 33:
#line 720 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 34:
#line 721 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 35:
#line 725 "ctlib/parser.y"
    { if((yyvsp[(1) - (1)].identifier)) HN_delete((yyvsp[(1) - (1)].identifier)); ;}
    break;

  case 36:
#line 726 "ctlib/parser.y"
    {;}
    break;

  case 37:
#line 730 "ctlib/parser.y"
    {;}
    break;

  case 38:
#line 731 "ctlib/parser.y"
    {;}
    break;

  case 40:
#line 736 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 41:
#line 737 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 42:
#line 739 "ctlib/parser.y"
    {
	    switch( (yyvsp[(1) - (2)].oper) ) {
	      case '-' : UNARY_OP((yyval.value), -, (yyvsp[(2) - (2)].value)); break;
	      case '~' : UNARY_OP((yyval.value), ~, (yyvsp[(2) - (2)].value)); break;
	      case '!' : UNARY_OP((yyval.value), !, (yyvsp[(2) - (2)].value)); break;
	      case '+' : (yyval.value) = (yyvsp[(2) - (2)].value);             break;

	      case '*' :
	      case '&' :
	        (yyval.value) = (yyvsp[(2) - (2)].value); (yyval.value).flags |= V_IS_UNSAFE_PTROP;
	        break;

	      default:
	        UNDEF_VAL((yyval.value));
	        break;
	    }
	  ;}
    break;

  case 43:
#line 756 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[(2) - (2)].value); ;}
    break;

  case 44:
#line 757 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[(3) - (4)].value); ;}
    break;

  case 45:
#line 761 "ctlib/parser.y"
    { (yyval.oper) = '&'; ;}
    break;

  case 46:
#line 762 "ctlib/parser.y"
    { (yyval.oper) = '*'; ;}
    break;

  case 47:
#line 763 "ctlib/parser.y"
    { (yyval.oper) = '+'; ;}
    break;

  case 48:
#line 764 "ctlib/parser.y"
    { (yyval.oper) = '-'; ;}
    break;

  case 49:
#line 765 "ctlib/parser.y"
    { (yyval.oper) = '~'; ;}
    break;

  case 50:
#line 766 "ctlib/parser.y"
    { (yyval.oper) = '!'; ;}
    break;

  case 52:
#line 771 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[(4) - (4)].value); (yyval.value).flags |= V_IS_UNSAFE_CAST; ;}
    break;

  case 54:
#line 777 "ctlib/parser.y"
    { BINARY_OP( (yyval.value), (yyvsp[(1) - (3)].value), *, (yyvsp[(3) - (3)].value) ); ;}
    break;

  case 55:
#line 779 "ctlib/parser.y"
    {
	    if ((yyvsp[(3) - (3)].value).iv == 0)
	      UNDEF_VAL((yyval.value));
	    else
	      BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), /, (yyvsp[(3) - (3)].value));
	  ;}
    break;

  case 56:
#line 786 "ctlib/parser.y"
    {
	    if ((yyvsp[(3) - (3)].value).iv == 0)
	      UNDEF_VAL((yyval.value));
	    else
	      BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), %, (yyvsp[(3) - (3)].value));
	  ;}
    break;

  case 58:
#line 797 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), +, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 59:
#line 799 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), -, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 61:
#line 805 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), <<, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 62:
#line 807 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), >>, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 64:
#line 813 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), <,  (yyvsp[(3) - (3)].value)); ;}
    break;

  case 65:
#line 815 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), >,  (yyvsp[(3) - (3)].value)); ;}
    break;

  case 66:
#line 817 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), <=, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 67:
#line 819 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), >=, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 69:
#line 825 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), ==, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 70:
#line 827 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), !=, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 72:
#line 833 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), &, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 74:
#line 839 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), ^, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 76:
#line 845 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), |, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 78:
#line 851 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), &&, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 80:
#line 857 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[(1) - (3)].value), ||, (yyvsp[(3) - (3)].value)); ;}
    break;

  case 82:
#line 863 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[(1) - (5)].value).iv ? (yyvsp[(3) - (5)].value) : (yyvsp[(5) - (5)].value); (yyval.value).flags |= (yyvsp[(1) - (5)].value).flags; ;}
    break;

  case 84:
#line 868 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 85:
#line 872 "ctlib/parser.y"
    {;}
    break;

  case 86:
#line 873 "ctlib/parser.y"
    {;}
    break;

  case 87:
#line 874 "ctlib/parser.y"
    {;}
    break;

  case 88:
#line 875 "ctlib/parser.y"
    {;}
    break;

  case 89:
#line 876 "ctlib/parser.y"
    {;}
    break;

  case 90:
#line 877 "ctlib/parser.y"
    {;}
    break;

  case 91:
#line 878 "ctlib/parser.y"
    {;}
    break;

  case 92:
#line 879 "ctlib/parser.y"
    {;}
    break;

  case 93:
#line 880 "ctlib/parser.y"
    {;}
    break;

  case 94:
#line 881 "ctlib/parser.y"
    {;}
    break;

  case 95:
#line 882 "ctlib/parser.y"
    {;}
    break;

  case 96:
#line 886 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 99:
#line 891 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[(3) - (3)].value); ;}
    break;

  case 102:
#line 901 "ctlib/parser.y"
    {;}
    break;

  case 103:
#line 939 "ctlib/parser.y"
    {;}
    break;

  case 104:
#line 940 "ctlib/parser.y"
    {;}
    break;

  case 105:
#line 941 "ctlib/parser.y"
    {;}
    break;

  case 106:
#line 942 "ctlib/parser.y"
    {;}
    break;

  case 107:
#line 950 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pTypedefList) = NULL;
	    else
	    {
	      if ((yyvsp[(1) - (4)].uval) & T_TYPEDEF)
	      {
	        TypeSpec ts;
	        ts.tflags = (yyvsp[(1) - (4)].uval);
	        ts.ptr    = NULL;
	        if ((ts.tflags & ANY_TYPE_NAME) == 0)
	          ts.tflags |= T_INT;
	        (yyval.pTypedefList) = typedef_list_new(ts, LL_new());
	        LL_push(PSTATE->pCPI->typedef_lists, (yyval.pTypedefList));
	        MAKE_TYPEDEF((yyval.pTypedefList), (yyvsp[(2) - (4)].pDecl));
	      }
	      else
	      {
	        (yyval.pTypedefList) = NULL;
	        decl_delete((yyvsp[(2) - (4)].pDecl));
	      }
	    }
	  ;}
    break;

  case 108:
#line 974 "ctlib/parser.y"
    {
	    (yyval.pTypedefList) = NULL;
	    if ((yyvsp[(2) - (4)].pDecl))
	      decl_delete((yyvsp[(2) - (4)].pDecl));
	  ;}
    break;

  case 109:
#line 980 "ctlib/parser.y"
    {
	    (yyval.pTypedefList) = (yyvsp[(1) - (5)].pTypedefList);
	    if ((yyval.pTypedefList))
	      MAKE_TYPEDEF((yyval.pTypedefList), (yyvsp[(3) - (5)].pDecl));
	    else if((yyvsp[(3) - (5)].pDecl))
	      decl_delete((yyvsp[(3) - (5)].pDecl));
	  ;}
    break;

  case 110:
#line 991 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pTypedefList) = NULL;
	    else
	    {
	      if ((yyvsp[(1) - (4)].tspec).tflags & T_TYPEDEF)
	      {
	        if (((yyvsp[(1) - (4)].tspec).tflags & ANY_TYPE_NAME) == 0)
	          (yyvsp[(1) - (4)].tspec).tflags |= T_INT;
	        ctt_refcount_inc((yyvsp[(1) - (4)].tspec).ptr);
	        (yyval.pTypedefList) = typedef_list_new((yyvsp[(1) - (4)].tspec), LL_new());
	        LL_push(PSTATE->pCPI->typedef_lists, (yyval.pTypedefList));
	        MAKE_TYPEDEF((yyval.pTypedefList), (yyvsp[(2) - (4)].pDecl));
	      }
	      else
	      {
	        (yyval.pTypedefList) = NULL;
	        decl_delete((yyvsp[(2) - (4)].pDecl));
	      }
	    }
	  ;}
    break;

  case 111:
#line 1013 "ctlib/parser.y"
    {
	    (yyval.pTypedefList) = NULL;
	    if ((yyvsp[(2) - (4)].pDecl))
	      decl_delete((yyvsp[(2) - (4)].pDecl));
	  ;}
    break;

  case 112:
#line 1019 "ctlib/parser.y"
    {
	    (yyval.pTypedefList) = (yyvsp[(1) - (5)].pTypedefList);
	    if ((yyval.pTypedefList))
	      MAKE_TYPEDEF((yyval.pTypedefList), (yyvsp[(3) - (5)].pDecl));
	    else if ((yyvsp[(3) - (5)].pDecl))
	      decl_delete((yyvsp[(3) - (5)].pDecl));
	  ;}
    break;

  case 113:
#line 1031 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = NULL;
	    (yyval.tspec).tflags = (yyvsp[(1) - (1)].uval);
	  ;}
    break;

  case 116:
#line 1042 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = NULL;
	    (yyval.tspec).tflags = (yyvsp[(1) - (1)].uval);
	  ;}
    break;

  case 120:
#line 1054 "ctlib/parser.y"
    { (yyval.uval) = (yyvsp[(2) - (2)].uval);      ;}
    break;

  case 121:
#line 1055 "ctlib/parser.y"
    { (yyval.uval) = (yyvsp[(1) - (2)].uval) | (yyvsp[(2) - (2)].uval); ;}
    break;

  case 127:
#line 1070 "ctlib/parser.y"
    { (yyval.uval) = 0;  ;}
    break;

  case 131:
#line 1080 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[(1) - (2)].uval), (yyvsp[(2) - (2)].uval)); ;}
    break;

  case 132:
#line 1081 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[(1) - (2)].uval), (yyvsp[(2) - (2)].uval)); ;}
    break;

  case 133:
#line 1082 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[(1) - (2)].uval), (yyvsp[(2) - (2)].uval)); ;}
    break;

  case 134:
#line 1083 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[(1) - (2)].uval), (yyvsp[(2) - (2)].uval)); ;}
    break;

  case 136:
#line 1088 "ctlib/parser.y"
    { (yyval.uval) = (yyvsp[(2) - (2)].uval);             ;}
    break;

  case 137:
#line 1089 "ctlib/parser.y"
    { (yyval.uval) = (yyvsp[(1) - (2)].uval);             ;}
    break;

  case 138:
#line 1090 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[(1) - (2)].uval), (yyvsp[(2) - (2)].uval)); ;}
    break;

  case 139:
#line 1095 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[(2) - (2)].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[(2) - (2)].tspec).tflags | (yyvsp[(1) - (2)].uval);
	  ;}
    break;

  case 140:
#line 1100 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[(1) - (2)].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[(1) - (2)].tspec).tflags | (yyvsp[(2) - (2)].uval);
	  ;}
    break;

  case 141:
#line 1105 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[(1) - (2)].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[(1) - (2)].tspec).tflags | (yyvsp[(2) - (2)].uval);
	  ;}
    break;

  case 143:
#line 1113 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[(2) - (2)].tspec); ;}
    break;

  case 144:
#line 1114 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[(1) - (2)].tspec); ;}
    break;

  case 146:
#line 1119 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[(2) - (2)].tspec); ;}
    break;

  case 147:
#line 1120 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[(1) - (2)].tspec); ;}
    break;

  case 150:
#line 1129 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[(1) - (2)].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[(1) - (2)].tspec).tflags | (yyvsp[(2) - (2)].uval);
	  ;}
    break;

  case 151:
#line 1134 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[(2) - (2)].pTypedef);
	    (yyval.tspec).tflags = T_TYPE | (yyvsp[(1) - (2)].uval);
	  ;}
    break;

  case 152:
#line 1139 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[(1) - (2)].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[(1) - (2)].tspec).tflags | (yyvsp[(2) - (2)].uval);
	  ;}
    break;

  case 153:
#line 1146 "ctlib/parser.y"
    { (yyval.tspec).ptr = (yyvsp[(1) - (1)].pTypedef); (yyval.tspec).tflags = T_TYPE; ;}
    break;

  case 154:
#line 1147 "ctlib/parser.y"
    { (yyval.tspec).ptr = (yyvsp[(2) - (2)].pTypedef); (yyval.tspec).tflags = T_TYPE; ;}
    break;

  case 155:
#line 1148 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[(1) - (2)].tspec);                         ;}
    break;

  case 156:
#line 1152 "ctlib/parser.y"
    { (yyval.uval) = T_TYPEDEF;  ;}
    break;

  case 157:
#line 1153 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 158:
#line 1154 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 159:
#line 1155 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 160:
#line 1156 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 161:
#line 1157 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 162:
#line 1161 "ctlib/parser.y"
    { (yyval.uval) = T_INT;      ;}
    break;

  case 163:
#line 1162 "ctlib/parser.y"
    { (yyval.uval) = T_CHAR;     ;}
    break;

  case 164:
#line 1163 "ctlib/parser.y"
    { (yyval.uval) = T_SHORT;    ;}
    break;

  case 165:
#line 1164 "ctlib/parser.y"
    { (yyval.uval) = T_LONG;     ;}
    break;

  case 166:
#line 1165 "ctlib/parser.y"
    { (yyval.uval) = T_FLOAT;    ;}
    break;

  case 167:
#line 1166 "ctlib/parser.y"
    { (yyval.uval) = T_DOUBLE;   ;}
    break;

  case 168:
#line 1167 "ctlib/parser.y"
    { (yyval.uval) = T_SIGNED;   ;}
    break;

  case 169:
#line 1168 "ctlib/parser.y"
    { (yyval.uval) = T_UNSIGNED; ;}
    break;

  case 170:
#line 1169 "ctlib/parser.y"
    { (yyval.uval) = T_VOID;     ;}
    break;

  case 173:
#line 1179 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	    }
	    else
	    {
	      Struct *pStruct;
	      pStruct = struct_new(NULL, 0, (yyvsp[(1) - (4)].context).uval, PSTATE->pragma.pack.current, (yyvsp[(3) - (4)].list));
	      pStruct->context = (yyvsp[(1) - (4)].context).ctx;
	      LL_push(PSTATE->pCPI->structs, pStruct);
	      (yyval.tspec).tflags = (yyvsp[(1) - (4)].context).uval;
	      (yyval.tspec).ptr = pStruct;
	    }
	  ;}
    break;

  case 174:
#line 1196 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      Struct *pStruct = HT_get(PSTATE->pCPI->htStructs, (yyvsp[(2) - (5)].identifier)->key, (yyvsp[(2) - (5)].identifier)->keylen, (yyvsp[(2) - (5)].identifier)->hash);

	      if (pStruct == NULL)
	      {
	        pStruct = struct_new((yyvsp[(2) - (5)].identifier)->key, (yyvsp[(2) - (5)].identifier)->keylen, (yyvsp[(1) - (5)].context).uval, PSTATE->pragma.pack.current, (yyvsp[(4) - (5)].list));
	        pStruct->context = (yyvsp[(1) - (5)].context).ctx;
	        LL_push(PSTATE->pCPI->structs, pStruct);
	        HT_storenode(PSTATE->pCPI->htStructs, (yyvsp[(2) - (5)].identifier), pStruct);
	      }
	      else
	      {
	        DELETE_NODE((yyvsp[(2) - (5)].identifier));

	        if (pStruct->declarations == NULL)
	        {
	          pStruct->context      = (yyvsp[(1) - (5)].context).ctx;
	          pStruct->declarations = (yyvsp[(4) - (5)].list);
	          pStruct->pack         = PSTATE->pragma.pack.current;
	        }
	        else
	          LL_destroy((yyvsp[(4) - (5)].list), (LLDestroyFunc) structdecl_delete);
	      }
	      (yyval.tspec).tflags = (yyvsp[(1) - (5)].context).uval;
	      (yyval.tspec).ptr = pStruct;
	    }
	  ;}
    break;

  case 175:
#line 1232 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      Struct *pStruct = HT_get(PSTATE->pCPI->htStructs, (yyvsp[(2) - (2)].identifier)->key, (yyvsp[(2) - (2)].identifier)->keylen, (yyvsp[(2) - (2)].identifier)->hash);

	      if (pStruct == NULL)
	      {
	        pStruct = struct_new((yyvsp[(2) - (2)].identifier)->key, (yyvsp[(2) - (2)].identifier)->keylen, (yyvsp[(1) - (2)].context).uval, 0, NULL);
	        pStruct->context = (yyvsp[(1) - (2)].context).ctx;
	        LL_push(PSTATE->pCPI->structs, pStruct);
	        HT_storenode(PSTATE->pCPI->htStructs, (yyvsp[(2) - (2)].identifier), pStruct);
	      }
	      else
	        DELETE_NODE((yyvsp[(2) - (2)].identifier));

	      (yyval.tspec).tflags = (yyvsp[(1) - (2)].context).uval;
	      (yyval.tspec).ptr = pStruct;
	    }
	  ;}
    break;

  case 176:
#line 1261 "ctlib/parser.y"
    {
	    (yyval.context).uval     = (yyvsp[(1) - (1)].uval);
	    (yyval.context).ctx.pFI  = PSTATE->pFI;
	    (yyval.context).ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 177:
#line 1269 "ctlib/parser.y"
    { (yyval.uval) = T_STRUCT; ;}
    break;

  case 178:
#line 1270 "ctlib/parser.y"
    { (yyval.uval) = T_UNION;  ;}
    break;

  case 179:
#line 1274 "ctlib/parser.y"
    { (yyval.list) = IS_LOCAL ? NULL : LL_new(); ;}
    break;

  case 181:
#line 1280 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      ctt_refcount_inc((yyvsp[(1) - (1)].pStructDecl)->type.ptr);
	      (yyval.list) = LL_new();
	      LL_push((yyval.list), (yyvsp[(1) - (1)].pStructDecl));
	    }
	  ;}
    break;

  case 182:
#line 1291 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      ctt_refcount_inc((yyvsp[(2) - (2)].pStructDecl)->type.ptr);
	      (yyval.list) = (yyvsp[(1) - (2)].list);
	      LL_push((yyval.list), (yyvsp[(2) - (2)].pStructDecl));
	    }
	  ;}
    break;

  case 185:
#line 1309 "ctlib/parser.y"
    { (yyval.pStructDecl) = IS_LOCAL ? NULL : structdecl_new((yyvsp[(1) - (1)].tspec), NULL); ;}
    break;

  case 186:
#line 1314 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pStructDecl) = NULL;
	    else
	    {
	      if (((yyvsp[(1) - (2)].tspec).tflags & ANY_TYPE_NAME) == 0)
	        (yyvsp[(1) - (2)].tspec).tflags |= T_INT;
	      (yyval.pStructDecl) = structdecl_new((yyvsp[(1) - (2)].tspec), LL_new());
	      if ((yyvsp[(2) - (2)].pDecl))
	        LL_push((yyval.pStructDecl)->declarators, (yyvsp[(2) - (2)].pDecl));
	    }
	  ;}
    break;

  case 187:
#line 1327 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pStructDecl) = NULL;
	    else
	    {
	      (yyval.pStructDecl) = (yyvsp[(1) - (3)].pStructDecl);
	      if ((yyvsp[(3) - (3)].pDecl))
	        LL_push((yyval.pStructDecl)->declarators, (yyvsp[(3) - (3)].pDecl));
	    }
	  ;}
    break;

  case 188:
#line 1341 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pDecl) = NULL;
	    else
	    {
	      (yyval.pDecl) = (yyvsp[(1) - (2)].pDecl);

	      if (((yyvsp[(2) - (2)].value).flags & V_IS_UNDEF) == 0)
	      {
	        if ((yyvsp[(2) - (2)].value).iv <= 0)
	        {
	          char *msg;
	          AllocF(char *, msg, 80 + CTT_IDLEN((yyvsp[(1) - (2)].pDecl)));
	          sprintf(msg, "%s width for bit-field '%s'",
	                  (yyvsp[(2) - (2)].value).iv < 0 ? "negative" : "zero", (yyvsp[(1) - (2)].pDecl)->identifier);
	          decl_delete((yyvsp[(1) - (2)].pDecl));
	          yyerror(msg);
	          Free(msg);
	          YYERROR;
	        }

	        (yyval.pDecl)->bitfield_flag = 1;
	        (yyval.pDecl)->ext.bitfield.bits = (unsigned char) (yyvsp[(2) - (2)].value).iv;
	      }
	    }
	  ;}
    break;

  case 189:
#line 1368 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pDecl) = NULL;
	    else
	    {
	      if ((yyvsp[(1) - (1)].value).iv < 0)
	      {
	        yyerror("negative width for bit-field");
	        YYERROR;
	      }

	      (yyval.pDecl) = decl_new("", 0);
	      (yyval.pDecl)->bitfield_flag = 1;
	      (yyval.pDecl)->ext.bitfield.bits = (unsigned char) (yyvsp[(1) - (1)].value).iv;
	    }
	  ;}
    break;

  case 190:
#line 1387 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 192:
#line 1392 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[(2) - (2)].value); ;}
    break;

  case 193:
#line 1397 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      LL_destroy((yyvsp[(3) - (5)].list), (LLDestroyFunc) enum_delete);
	    }
	    else
	    {
	      EnumSpecifier *pEnum = enumspec_new(NULL, 0, (yyvsp[(3) - (5)].list));
	      pEnum->context = (yyvsp[(1) - (5)].context).ctx;
	      LL_push(PSTATE->pCPI->enums, pEnum);
	      (yyval.tspec).tflags = T_ENUM;
	      (yyval.tspec).ptr = pEnum;
	    }
	  ;}
    break;

  case 194:
#line 1414 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      EnumSpecifier *pEnum = HT_get(PSTATE->pCPI->htEnums, (yyvsp[(2) - (6)].identifier)->key, (yyvsp[(2) - (6)].identifier)->keylen, (yyvsp[(2) - (6)].identifier)->hash);

	      if (pEnum == NULL)
	      {
	        pEnum = enumspec_new((yyvsp[(2) - (6)].identifier)->key, (yyvsp[(2) - (6)].identifier)->keylen, (yyvsp[(4) - (6)].list));
	        pEnum->context = (yyvsp[(1) - (6)].context).ctx;
	        LL_push(PSTATE->pCPI->enums, pEnum);
	        HT_storenode(PSTATE->pCPI->htEnums, (yyvsp[(2) - (6)].identifier), pEnum);
	      }
	      else
	      {
	        DELETE_NODE((yyvsp[(2) - (6)].identifier));

	        if (pEnum->enumerators == NULL)
	        {
	          enumspec_update(pEnum, (yyvsp[(4) - (6)].list));
	          pEnum->context = (yyvsp[(1) - (6)].context).ctx;
	        }
	        else
	          LL_destroy((yyvsp[(4) - (6)].list), (LLDestroyFunc) enum_delete);
	      }

	      (yyval.tspec).tflags = T_ENUM;
	      (yyval.tspec).ptr = pEnum;
	    }
	  ;}
    break;

  case 195:
#line 1450 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      EnumSpecifier *pEnum = HT_get(PSTATE->pCPI->htEnums, (yyvsp[(2) - (2)].identifier)->key, (yyvsp[(2) - (2)].identifier)->keylen, (yyvsp[(2) - (2)].identifier)->hash);

	      if (pEnum == NULL)
	      {
	        pEnum = enumspec_new((yyvsp[(2) - (2)].identifier)->key, (yyvsp[(2) - (2)].identifier)->keylen, NULL);
	        pEnum->context = (yyvsp[(1) - (2)].context).ctx;
	        LL_push(PSTATE->pCPI->enums, pEnum);
	        HT_storenode(PSTATE->pCPI->htEnums, (yyvsp[(2) - (2)].identifier), pEnum);
	      }
	      else
	      {
	        DELETE_NODE((yyvsp[(2) - (2)].identifier));
	      }

	      (yyval.tspec).tflags = T_ENUM;
	      (yyval.tspec).ptr = pEnum;
	    }
	  ;}
    break;

  case 196:
#line 1481 "ctlib/parser.y"
    {
	    (yyval.context).ctx.pFI  = PSTATE->pFI;
	    (yyval.context).ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 197:
#line 1489 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = LL_new();
	      if ((yyvsp[(1) - (1)].pEnum)->value.flags & V_IS_UNDEF)
	      {
	        (yyvsp[(1) - (1)].pEnum)->value.flags &= ~V_IS_UNDEF;
	        (yyvsp[(1) - (1)].pEnum)->value.iv     = 0;
	      }
	      LL_push((yyval.list), (yyvsp[(1) - (1)].pEnum));
	    }
	  ;}
    break;

  case 198:
#line 1504 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      if ((yyvsp[(3) - (3)].pEnum)->value.flags & V_IS_UNDEF)
	      {
	        Enumerator *pEnum = LL_get((yyvsp[(1) - (3)].list), -1);
	        (yyvsp[(3) - (3)].pEnum)->value.flags = pEnum->value.flags;
	        (yyvsp[(3) - (3)].pEnum)->value.iv    = pEnum->value.iv + 1;
	      }
	      LL_push((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].pEnum));
	      (yyval.list) = (yyvsp[(1) - (3)].list);
	    }
	  ;}
    break;

  case 199:
#line 1523 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.pEnum) = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      (yyval.pEnum) = enum_new((yyvsp[(1) - (1)].identifier)->key, (yyvsp[(1) - (1)].identifier)->keylen, NULL);
	      HT_storenode(PSTATE->pCPI->htEnumerators, (yyvsp[(1) - (1)].identifier), (yyval.pEnum));
	    }
	  ;}
    break;

  case 200:
#line 1536 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.pEnum) = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      (yyval.pEnum) = enum_new((yyvsp[(1) - (3)].identifier)->key, (yyvsp[(1) - (3)].identifier)->keylen, &(yyvsp[(3) - (3)].value));
	      HT_storenode(PSTATE->pCPI->htEnumerators, (yyvsp[(1) - (3)].identifier), (yyval.pEnum));
	    }
	  ;}
    break;

  case 205:
#line 1561 "ctlib/parser.y"
    {;}
    break;

  case 206:
#line 1562 "ctlib/parser.y"
    {;}
    break;

  case 207:
#line 1563 "ctlib/parser.y"
    { if ((yyvsp[(2) - (2)].pDecl)) decl_delete((yyvsp[(2) - (2)].pDecl)); ;}
    break;

  case 208:
#line 1564 "ctlib/parser.y"
    { if ((yyvsp[(2) - (2)].pDecl)) decl_delete((yyvsp[(2) - (2)].pDecl)); ;}
    break;

  case 209:
#line 1565 "ctlib/parser.y"
    {;}
    break;

  case 210:
#line 1566 "ctlib/parser.y"
    {;}
    break;

  case 211:
#line 1567 "ctlib/parser.y"
    { if ((yyvsp[(2) - (2)].pDecl)) decl_delete((yyvsp[(2) - (2)].pDecl)); ;}
    break;

  case 212:
#line 1568 "ctlib/parser.y"
    {;}
    break;

  case 213:
#line 1569 "ctlib/parser.y"
    {;}
    break;

  case 214:
#line 1570 "ctlib/parser.y"
    { if ((yyvsp[(2) - (2)].pDecl)) decl_delete((yyvsp[(2) - (2)].pDecl)); ;}
    break;

  case 215:
#line 1571 "ctlib/parser.y"
    { if ((yyvsp[(2) - (2)].pDecl)) decl_delete((yyvsp[(2) - (2)].pDecl)); ;}
    break;

  case 216:
#line 1572 "ctlib/parser.y"
    {;}
    break;

  case 217:
#line 1573 "ctlib/parser.y"
    {;}
    break;

  case 218:
#line 1574 "ctlib/parser.y"
    { if ((yyvsp[(2) - (2)].pDecl)) decl_delete((yyvsp[(2) - (2)].pDecl)); ;}
    break;

  case 219:
#line 1582 "ctlib/parser.y"
    { if ((yyvsp[(1) - (1)].identifier)) HN_delete((yyvsp[(1) - (1)].identifier)); ;}
    break;

  case 220:
#line 1583 "ctlib/parser.y"
    { if ((yyvsp[(3) - (3)].identifier)) HN_delete((yyvsp[(3) - (3)].identifier)); ;}
    break;

  case 222:
#line 1589 "ctlib/parser.y"
    {
	    (yyval.identifier) = IS_LOCAL ? NULL : HN_new((yyvsp[(1) - (1)].pTypedef)->pDecl->identifier, CTT_IDLEN((yyvsp[(1) - (1)].pTypedef)->pDecl), 0);
	  ;}
    break;

  case 223:
#line 1596 "ctlib/parser.y"
    {
	    if (!IS_LOCAL)
	    {
	      unsigned size;
	      u_32 flags;
	      (void) PSTATE->pCPC->get_type_info(&PSTATE->pCPC->layout, &(yyvsp[(1) - (1)].tspec), NULL, "sf", &size, &flags);
	      (yyval.value).iv    = size;
	      (yyval.value).flags = 0;
	      if (flags & T_UNSAFE_VAL)
	        (yyval.value).flags |= V_IS_UNSAFE;
	    }
	  ;}
    break;

  case 224:
#line 1609 "ctlib/parser.y"
    {
	    if (!IS_LOCAL)
	    {
	      if ((yyvsp[(2) - (2)].absDecl).pointer_flag)
	      {
	        (yyval.value).iv = PSTATE->pCPC->layout.ptr_size * (yyvsp[(2) - (2)].absDecl).multiplicator;
	        (yyval.value).flags = 0;
	      }
	      else
	      {
	        unsigned size;
	        u_32 flags;
	        (void) PSTATE->pCPC->get_type_info(&PSTATE->pCPC->layout, &(yyvsp[(1) - (2)].tspec), NULL, "sf", &size, &flags);
	        (yyval.value).iv = size * (yyvsp[(2) - (2)].absDecl).multiplicator;
	        (yyval.value).flags = 0;
	        if (flags & T_UNSAFE_VAL)
	          (yyval.value).flags |= V_IS_UNSAFE;
	      }
	    }
	  ;}
    break;

  case 225:
#line 1630 "ctlib/parser.y"
    {
	    if (!IS_LOCAL)
	    {
	      (yyval.value).iv = PSTATE->pCPC->layout.int_size;
	      (yyval.value).flags = 0;
	    }
	  ;}
    break;

  case 226:
#line 1638 "ctlib/parser.y"
    {
	    if (!IS_LOCAL)
	    {
	      (yyval.value).iv = (yyvsp[(2) - (2)].absDecl).multiplicator * ((yyvsp[(2) - (2)].absDecl).pointer_flag ?
	              PSTATE->pCPC->layout.ptr_size : PSTATE->pCPC->layout.int_size);
	      (yyval.value).flags = 0;
	    }
	  ;}
    break;

  case 231:
#line 1656 "ctlib/parser.y"
    {;}
    break;

  case 239:
#line 1676 "ctlib/parser.y"
    { DELETE_NODE((yyvsp[(2) - (2)].identifier)); ;}
    break;

  case 249:
#line 1696 "ctlib/parser.y"
    { DELETE_NODE((yyvsp[(1) - (3)].identifier)); ;}
    break;

  case 267:
#line 1735 "ctlib/parser.y"
    { DELETE_NODE((yyvsp[(2) - (3)].identifier)); ;}
    break;

  case 278:
#line 1761 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 279:
#line 1762 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[(1) - (3)].pDecl)); ;}
    break;

  case 280:
#line 1763 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 281:
#line 1764 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[(2) - (4)].pDecl)); ;}
    break;

  case 282:
#line 1765 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 283:
#line 1766 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[(2) - (4)].pDecl)); ;}
    break;

  case 284:
#line 1767 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 285:
#line 1768 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[(2) - (4)].pDecl)); ;}
    break;

  case 286:
#line 1769 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 287:
#line 1770 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[(2) - (4)].pDecl)); ;}
    break;

  case 288:
#line 1772 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 289:
#line 1772 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 290:
#line 1773 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 291:
#line 1773 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 292:
#line 1774 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 293:
#line 1774 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 294:
#line 1775 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 295:
#line 1775 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 296:
#line 1776 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 297:
#line 1776 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 298:
#line 1778 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 299:
#line 1778 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 300:
#line 1779 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 301:
#line 1779 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 302:
#line 1780 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 303:
#line 1780 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 304:
#line 1781 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 305:
#line 1781 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 306:
#line 1782 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 307:
#line 1782 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 312:
#line 1797 "ctlib/parser.y"
    {
	    (yyval.pDecl) = IS_LOCAL ? NULL : decl_new((yyvsp[(1) - (1)].pTypedef)->pDecl->identifier, CTT_IDLEN((yyvsp[(1) - (1)].pTypedef)->pDecl));
	  ;}
    break;

  case 313:
#line 1801 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pDecl) = NULL;
	    else
	    {
	      (yyval.pDecl) = decl_new((yyvsp[(1) - (2)].pTypedef)->pDecl->identifier, CTT_IDLEN((yyvsp[(1) - (2)].pTypedef)->pDecl));
	      if ((yyvsp[(2) - (2)].list))
	      {
	        (yyval.pDecl)->array_flag = 1;
	        (yyval.pDecl)->ext.array = (yyvsp[(2) - (2)].list);
	      }
	    }
	  ;}
    break;

  case 316:
#line 1823 "ctlib/parser.y"
    {
	    if ((yyvsp[(2) - (2)].pDecl))
	      (yyvsp[(2) - (2)].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[(2) - (2)].pDecl);
	  ;}
    break;

  case 317:
#line 1829 "ctlib/parser.y"
    {
	    if ((yyvsp[(3) - (3)].pDecl))
	      (yyvsp[(3) - (3)].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[(3) - (3)].pDecl);
	  ;}
    break;

  case 318:
#line 1837 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[(2) - (3)].pDecl); ;}
    break;

  case 319:
#line 1839 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[(2) - (4)].pDecl), (yyvsp[(4) - (4)].list));
	    (yyval.pDecl) = (yyvsp[(2) - (4)].pDecl);
	  ;}
    break;

  case 321:
#line 1851 "ctlib/parser.y"
    {
	    if ((yyvsp[(3) - (4)].pDecl))
	      (yyvsp[(3) - (4)].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[(3) - (4)].pDecl);
	  ;}
    break;

  case 322:
#line 1857 "ctlib/parser.y"
    {
	    if ((yyvsp[(4) - (5)].pDecl))
	      (yyvsp[(4) - (5)].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[(4) - (5)].pDecl);
	  ;}
    break;

  case 323:
#line 1863 "ctlib/parser.y"
    {
	    if ((yyvsp[(2) - (2)].pDecl))
	      (yyvsp[(2) - (2)].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[(2) - (2)].pDecl);
	  ;}
    break;

  case 324:
#line 1869 "ctlib/parser.y"
    {
	    if ((yyvsp[(3) - (3)].pDecl))
	      (yyvsp[(3) - (3)].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[(3) - (3)].pDecl);
	  ;}
    break;

  case 325:
#line 1877 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[(2) - (3)].pDecl); ;}
    break;

  case 326:
#line 1879 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[(2) - (4)].pDecl), (yyvsp[(3) - (4)].list));
	    (yyval.pDecl) = (yyvsp[(2) - (4)].pDecl);
	  ;}
    break;

  case 327:
#line 1884 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[(2) - (4)].pDecl), (yyvsp[(4) - (4)].list));
	    (yyval.pDecl) = (yyvsp[(2) - (4)].pDecl);
	  ;}
    break;

  case 328:
#line 1892 "ctlib/parser.y"
    {
	    (yyval.pDecl) = IS_LOCAL ? NULL : decl_new((yyvsp[(1) - (1)].pTypedef)->pDecl->identifier, CTT_IDLEN((yyvsp[(1) - (1)].pTypedef)->pDecl));
	  ;}
    break;

  case 329:
#line 1895 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[(2) - (3)].pDecl); ;}
    break;

  case 333:
#line 1906 "ctlib/parser.y"
    {
	    if ((yyvsp[(2) - (2)].pDecl))
	      (yyvsp[(2) - (2)].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[(2) - (2)].pDecl);
	  ;}
    break;

  case 334:
#line 1912 "ctlib/parser.y"
    {
	    if ((yyvsp[(3) - (3)].pDecl))
	      (yyvsp[(3) - (3)].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[(3) - (3)].pDecl);
	  ;}
    break;

  case 335:
#line 1921 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[(1) - (2)].pDecl), (yyvsp[(2) - (2)].list));
	    (yyval.pDecl) = (yyvsp[(1) - (2)].pDecl);
	  ;}
    break;

  case 336:
#line 1925 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[(2) - (3)].pDecl); ;}
    break;

  case 337:
#line 1927 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[(2) - (4)].pDecl), (yyvsp[(4) - (4)].list));
	    (yyval.pDecl) = (yyvsp[(2) - (4)].pDecl);
	  ;}
    break;

  case 338:
#line 1935 "ctlib/parser.y"
    {
	    if ((yyvsp[(1) - (1)].identifier))
	    {
	      (yyval.pDecl) = decl_new((yyvsp[(1) - (1)].identifier)->key, (yyvsp[(1) - (1)].identifier)->keylen);
	      HN_delete((yyvsp[(1) - (1)].identifier));
	    }
	    else
	    {
	      (yyval.pDecl) = NULL;
	    }
	  ;}
    break;

  case 339:
#line 1946 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[(2) - (3)].pDecl); ;}
    break;

  case 340:
#line 1950 "ctlib/parser.y"
    {;}
    break;

  case 341:
#line 1951 "ctlib/parser.y"
    {;}
    break;

  case 342:
#line 1952 "ctlib/parser.y"
    {;}
    break;

  case 343:
#line 1957 "ctlib/parser.y"
    {
	    if ((yyvsp[(1) - (4)].pDecl))
	      decl_delete((yyvsp[(1) - (4)].pDecl));
	  ;}
    break;

  case 344:
#line 1961 "ctlib/parser.y"
    {;}
    break;

  case 345:
#line 1963 "ctlib/parser.y"
    {
	    if ((yyvsp[(4) - (4)].list))
	      LL_destroy((yyvsp[(4) - (4)].list), (LLDestroyFunc) value_delete);
	  ;}
    break;

  case 348:
#line 1973 "ctlib/parser.y"
    {
	    (yyval.absDecl).pointer_flag  = 0;
	    (yyval.absDecl).multiplicator = 1;
	    if ((yyvsp[(1) - (1)].list))
	    {
	      ListIterator ai;
	      Value *pValue;

	      LL_foreach(pValue, ai, (yyvsp[(1) - (1)].list))
	        (yyval.absDecl).multiplicator *= pValue->iv;

	      LL_destroy((yyvsp[(1) - (1)].list), (LLDestroyFunc) value_delete);
	    }
	  ;}
    break;

  case 350:
#line 1991 "ctlib/parser.y"
    { (yyval.list) = NULL; ;}
    break;

  case 351:
#line 1992 "ctlib/parser.y"
    { (yyval.list) = NULL; ;}
    break;

  case 352:
#line 1997 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = LL_new();
	      LL_push((yyval.list), value_new((yyvsp[(3) - (4)].value).iv, (yyvsp[(3) - (4)].value).flags));
	      CT_DEBUG(PARSER, ("array dimension => %ld", (yyvsp[(3) - (4)].value).iv));
	    }
	  ;}
    break;

  case 353:
#line 2008 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = LL_new();
	      LL_push((yyval.list), value_new((yyvsp[(4) - (5)].value).iv, (yyvsp[(4) - (5)].value).flags));
	      CT_DEBUG(PARSER, ("array dimension => %ld", (yyvsp[(4) - (5)].value).iv));
	    }
	  ;}
    break;

  case 354:
#line 2019 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = LL_new();
	      LL_push((yyval.list), value_new((yyvsp[(4) - (5)].value).iv, (yyvsp[(4) - (5)].value).flags));
	      CT_DEBUG(PARSER, ("array dimension => %ld", (yyvsp[(4) - (5)].value).iv));
	    }
	  ;}
    break;

  case 355:
#line 2029 "ctlib/parser.y"
    { (yyval.list) = NULL; ;}
    break;

  case 356:
#line 2031 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = (yyvsp[(1) - (4)].list) ? (yyvsp[(1) - (4)].list) : LL_new();
	      LL_push((yyval.list), value_new((yyvsp[(3) - (4)].value).iv, (yyvsp[(3) - (4)].value).flags));
	      CT_DEBUG(PARSER, ("array dimension => %ld", (yyvsp[(3) - (4)].value).iv));
	    }
	  ;}
    break;

  case 357:
#line 2042 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = (yyvsp[(1) - (4)].list) ? (yyvsp[(1) - (4)].list) : LL_new();
	      LL_push((yyval.list), value_new(0, 0));
	      CT_DEBUG(PARSER, ("array dimension => *" ));
	    }
	  ;}
    break;

  case 358:
#line 2056 "ctlib/parser.y"
    {
	    (yyval.absDecl).pointer_flag = 1;
	    (yyval.absDecl).multiplicator = 1;
	  ;}
    break;

  case 359:
#line 2061 "ctlib/parser.y"
    {
	    (yyval.absDecl).pointer_flag = 1;
	    (yyval.absDecl).multiplicator = 1;
	  ;}
    break;

  case 360:
#line 2066 "ctlib/parser.y"
    {
	    (yyvsp[(2) - (2)].absDecl).pointer_flag = 1;
	    (yyval.absDecl) = (yyvsp[(2) - (2)].absDecl);
	  ;}
    break;

  case 361:
#line 2071 "ctlib/parser.y"
    {
	    (yyvsp[(3) - (3)].absDecl).pointer_flag = 1;
	    (yyval.absDecl) = (yyvsp[(3) - (3)].absDecl);
	  ;}
    break;

  case 362:
#line 2078 "ctlib/parser.y"
    { (yyval.absDecl) = (yyvsp[(2) - (3)].absDecl); ;}
    break;

  case 363:
#line 2079 "ctlib/parser.y"
    { (yyval.absDecl) = (yyvsp[(2) - (3)].absDecl); ;}
    break;

  case 364:
#line 2081 "ctlib/parser.y"
    {
	    (yyval.absDecl).pointer_flag  = 0;
	    (yyval.absDecl).multiplicator = 1;
	    if ((yyvsp[(2) - (3)].list))
	    {
	      ListIterator ai;
	      Value *pValue;

	      LL_foreach(pValue, ai, (yyvsp[(2) - (3)].list))
	        (yyval.absDecl).multiplicator *= pValue->iv;

	      LL_destroy((yyvsp[(2) - (3)].list), (LLDestroyFunc) value_delete);
	    }
	  ;}
    break;

  case 365:
#line 2096 "ctlib/parser.y"
    {
	    (yyval.absDecl) = (yyvsp[(2) - (4)].absDecl);
	    if ((yyvsp[(4) - (4)].list))
	      LL_destroy((yyvsp[(4) - (4)].list), (LLDestroyFunc) value_delete);
	  ;}
    break;


/* Line 1267 of yacc.c.  */
#line 5158 "ctlib/y_parser.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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
  return yyresult;
}


#line 2103 "ctlib/parser.y"



/*===== STATIC FUNCTIONS =====================================================*/

/*******************************************************************************
*
*   ROUTINE: c_lex
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Jan 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION: C lexer.
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

static inline int c_lex(YYSTYPE *plval, ParserState *pState)
{
  int rval, token;
  struct lexer_state *pLexer = pState->pLexer;
  dUCPP(pState->pp);

  CT_DEBUG(CLEXER, ("parser.y::c_lex()"));

  while ((rval = lex(aUCPP_ pLexer)) < CPPERR_EOF)
  {
    if (rval)
    {
      CT_DEBUG(CLEXER, ("lex() returned %d", rval));
      continue;
    }

    token = pLexer->ctok->type;

    switch (token)
    {
      case NONE:
        CT_DEBUG(CLEXER, ("token-type => NONE"));
        break;

      case COMMENT:
        CT_DEBUG(CLEXER, ("token-type => COMMENT => [%s]", pLexer->ctok->name));
        break;

      case NEWLINE:
        CT_DEBUG(CLEXER, ("token-type => NEWLINE"));
        break;

      case BUNCH:
        CT_DEBUG(CLEXER, ("token-type => BUNCH => [%s]", pLexer->ctok->name));
        break;

      case CONTEXT:
        CT_DEBUG(CLEXER, ("token-type => CONTEXT => [%s]", pLexer->ctok->name));
        {
          FileInfo *pFI;
          size_t len = strlen(pLexer->ctok->name);

          CT_DEBUG(CLEXER, ("new context: file '%s', line %ld",
                            pLexer->ctok->name, pLexer->ctok->line));

          pFI = HT_get(pState->pCPI->htFiles, pLexer->ctok->name, len, 0);

          if (pFI == NULL)
          {
            pFI = fileinfo_new(pLexer->input, pLexer->ctok->name, len);
            HT_store(pState->pCPI->htFiles, pLexer->ctok->name, len, 0, pFI);
          }

          pState->pFI = pFI;
        }
        break;

      case NUMBER:
        CT_DEBUG(CLEXER, ("token-type => NUMBER => [%s]", pLexer->ctok->name));
        plval->value.iv = strtol(pLexer->ctok->name, NULL, 0);
        plval->value.flags = 0;
        CT_DEBUG(CLEXER, ("constant: %s -> %ld", pLexer->ctok->name, plval->value.iv));
        return CONSTANT;

      case STRING:
        CT_DEBUG(CLEXER, ("token-type => STRING => [%s]", pLexer->ctok->name));
        plval->value.iv = string_size(pLexer->ctok->name);
        plval->value.flags = 0;
        CT_DEBUG(CLEXER, ("string literal: %s -> %ld", pLexer->ctok->name, plval->value.iv));
        return STRING_LITERAL;

      case CHAR:
        CT_DEBUG(CLEXER, ("token-type => CHAR => [%s]", pLexer->ctok->name));
        plval->value.iv = get_char_value(pLexer->ctok->name);
        plval->value.flags = 0;
        CT_DEBUG(CLEXER, ("constant: %s -> %ld", pLexer->ctok->name, plval->value.iv));
        return CONSTANT;

      case PRAGMA:
        CT_DEBUG(CLEXER, ("token-type => PRAGMA"));
        CT_DEBUG(CLEXER, ("line %ld: <#pragma>", pLexer->line));

        pState->pragma.str = pLexer->ctok->name;
        pragma_parse( &pState->pragma );

        CT_DEBUG(CLEXER, ("current packing: %d\n", pState->pragma.pack.current));
        break;

      case NAME:
        CT_DEBUG(CLEXER, ("token-type => NAME => [%s]", pLexer->ctok->name));
        {
          char *tokstr = pLexer->ctok->name;
          const CKeywordToken *ckt;

#include "token/t_parser.c"

          unknown:

          if ((ckt = HT_get(pState->pCPC->keyword_map, tokstr, 0, 0)) != NULL)
          {
            if (ckt->token == SKIP_TOK)
            {
              CT_DEBUG(CLEXER, ("skipping token '%s' in line %ld", tokstr, pLexer->line));
              break;
            }

            return ckt->token;
          }

          return check_type(plval, pState, tokstr);
        }

      default:
        CT_DEBUG(CLEXER, ("token-type => %d", token));
        if ((rval = tokentab[token]) != 0)
          return rval;

        CT_DEBUG(CLEXER, ("unhandled token in line %ld: <%2d>", pLexer->line, token));
        break;
    }
  }

  CT_DEBUG(CLEXER, ("EOF!"));

  return 0;
}

/*******************************************************************************
*
*   ROUTINE: parser_error
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Jan 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION:
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

static void parser_error(ParserState *pState, const char *msg)
{
  push_error(pState->pCPI, "%s, line %ld: %s",
             pState->pFI ? pState->pFI->name : "[unknown]",
             pState->pLexer->ctok->line, msg);
}

/*******************************************************************************
*
*   ROUTINE: get_char_value
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Jan 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION:
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

static inline int get_char_value(const char *s)
{
  while (*s && *s != '\'')
    s++;

  if (*++s != '\\')
    return (int) *s;

  switch (*++s)
  {
    case '0' :
    case '1' :
    case '2' :
    case '3' : return (int) strtol(s, NULL, 8);
    case 'a' : return (int) '\a';
    case 'b' : return (int) '\b';
    case 'f' : return (int) '\f';
    case 'h' : return (int) strtol(++s, NULL, 16);
    case 'n' : return (int) '\n';
    case 'r' : return (int) '\r';
    case 't' : return (int) '\t';
    case 'v' : return (int) '\v';

    default:   return (int) *s;
  }
}

/*******************************************************************************
*
*   ROUTINE: string_size
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Jan 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION:
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

static inline int string_size(const char *s)
{
  int size, count;

  while (*s && *s != '\"')
    s++;

  for (s++, size=0; *s; size++)
  {
    if (*s == '\"')
      break;

    if (*s++ != '\\')
      continue;

    if (*s == 'x')
    {
      count = 0;
      do s++; while (count++ < 2 &&
                     ((*s >= '0' && *s <= '9') ||
                      (*s >= 'a' && *s <= 'f') ||
                      (*s >= 'A' && *s <= 'F')));
      continue;
    }

    if (*s >= '0' && *s <= '7')
    {
      count = 0;
      do s++; while (count++ < 2 && *s >= '0' && *s <= '7');
    }
    else
      s++;
  }

  return size;
}

/*******************************************************************************
*
*   ROUTINE: check_type
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Jan 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION:
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

static inline int check_type(YYSTYPE *plval, ParserState *pState, const char *s)
{
  Typedef    *pTypedef;
  HashSum     hash;
  int         len;

  CT_DEBUG(CLEXER, ("check_type( \"%s\" )", s));

  HASH_STR_LEN(hash, s, len);

  pTypedef = HT_get(pState->pCPI->htTypedefs, s, len, hash);

  if (pTypedef)
  {
    CT_DEBUG(CLEXER, ("typedef found!"));
    plval->pTypedef = pTypedef;
    return TYPE_NAME;
  }

  plval->identifier = pState->flags & F_LOCAL ? NULL : HN_new(s, len, hash);

  return IDENTIFIER;
}


/*===== FUNCTIONS ============================================================*/

/*******************************************************************************
*
*   ROUTINE: get_c_keyword_token
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Dec 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION: Create a new C parser.
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

const CKeywordToken *get_c_keyword_token(const char *name)
{
#include "token/t_ckeytok.c"
unknown:
  return NULL;
}

/*******************************************************************************
*
*   ROUTINE: get_skip_token
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Dec 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION: Create a new C parser.
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

const CKeywordToken *get_skip_token(void)
{
  static const CKeywordToken ckt = { SKIP_TOK, NULL };
  return &ckt;
}

/*******************************************************************************
*
*   ROUTINE: c_parser_new
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Dec 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION: Create a new C parser.
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

ParserState *c_parser_new(const CParseConfig *pCPC, CParseInfo *pCPI,
                          pUCPP_ struct lexer_state *pLexer)
{
  ParserState *pState;

#ifdef CTLIB_DEBUGGING
#ifdef YYDEBUG
  extern int pragma_debug;
  c_debug = pragma_debug = DEBUG_FLAG(YACC) ? 1 : 0;
#endif
#endif

  if (pCPC == NULL || pCPI == NULL || pLexer == NULL)
    return NULL;

  AllocF(ParserState *, pState, sizeof(ParserState));

  pState->pCPI                = pCPI;
  pState->pCPC                = pCPC;
  pState->pLexer              = pLexer;
  pState->pp                  = aUCPP;

  pState->flags               = 0;
  pState->pFI                 = NULL;

  pragma_init(&pState->pragma);

  return pState;
}

/*******************************************************************************
*
*   ROUTINE: c_parser_run
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Dec 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION: Run the C parser.
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

int c_parser_run(ParserState *pState)
{
  return c_parse((void *) pState);
}

/*******************************************************************************
*
*   ROUTINE: c_parser_delete
*
*   WRITTEN BY: Marcus Holland-Moritz             ON: Dec 2002
*   CHANGED BY:                                   ON:
*
********************************************************************************
*
* DESCRIPTION: Delete a C parser object.
*
*   ARGUMENTS:
*
*     RETURNS:
*
*******************************************************************************/

void c_parser_delete(ParserState *pState)
{
  if (pState == NULL)
    return;

  pragma_free(&pState->pragma);

  Free(pState);
}

