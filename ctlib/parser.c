/* A Bison parser, made by GNU Bison 2.0a.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

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
* $Date: 2005/05/31 01:57:54 +0200 $
* $Revision: 57 $
* $Source: /ctlib/parser.y $
*
********************************************************************************
*
* Copyright (c) 2002-2005 Marcus Holland-Moritz. All rights reserved.
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

#ifdef UCPP_REENTRANT
  struct CPP         *cpp;
#endif
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 344 "ctlib/parser.y"
typedef union YYSTYPE {
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
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 530 "ctlib/parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 363 "ctlib/parser.y"


/*===== STATIC FUNCTION PROTOTYPES ===========================================*/

static inline int   c_lex(YYSTYPE *plval, ParserState *pState);

static inline int   get_char_value(const char *s);
static inline int   string_size(const char *s);
static inline int   check_type(YYSTYPE *plval, ParserState *pState, const char *s);
static        void  parser_error(ParserState *pState, const char *msg);



/* Line 214 of yacc.c.  */
#line 554 "ctlib/parser.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  else
#   define YYSIZE_T unsigned long int
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  120
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2192

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  131
/* YYNRULES -- Number of rules. */
#define YYNRULES  362
/* YYNRULES -- Number of states. */
#define YYNSTATES  608

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
static const unsigned short int yyprhs[] =
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
     306,   308,   310,   312,   314,   316,   318,   320,   324,   326,
     327,   329,   332,   335,   338,   341,   346,   351,   357,   362,
     367,   373,   375,   377,   379,   381,   383,   385,   387,   390,
     393,   395,   398,   399,   401,   403,   405,   407,   409,   411,
     414,   417,   420,   423,   425,   428,   431,   434,   437,   440,
     443,   445,   448,   451,   453,   456,   459,   461,   463,   466,
     469,   472,   474,   477,   480,   482,   484,   486,   488,   490,
     492,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   519,   525,   528,   530,   532,   534,   535,   537,
     539,   542,   545,   548,   550,   553,   557,   560,   562,   563,
     565,   568,   574,   581,   584,   586,   588,   592,   594,   598,
     600,   604,   606,   610,   612,   615,   618,   621,   623,   626,
     629,   631,   634,   637,   640,   642,   645,   648,   650,   654,
     656,   658,   660,   663,   665,   668,   669,   672,   675,   680,
     682,   685,   690,   691,   694,   696,   699,   703,   706,   707,
     709,   711,   713,   715,   717,   719,   721,   723,   727,   732,
     736,   739,   743,   747,   752,   754,   757,   759,   762,   765,
     771,   779,   785,   791,   799,   809,   813,   816,   819,   823,
     824,   826,   828,   831,   833,   835,   837,   838,   842,   843,
     848,   849,   854,   855,   860,   861,   866,   867,   871,   872,
     877,   878,   883,   884,   889,   890,   895,   896,   901,   902,
     908,   909,   915,   916,   922,   923,   929,   931,   933,   935,
     937,   939,   942,   944,   946,   949,   953,   957,   962,   964,
     969,   975,   978,   982,   986,   991,   996,   998,  1002,  1004,
    1006,  1008,  1011,  1015,  1018,  1022,  1027,  1029,  1033,  1035,
    1038,  1042,  1047,  1051,  1056,  1058,  1060,  1062,  1064,  1067,
    1071,  1074,  1078,  1082,  1087,  1092,  1094,  1097,  1100,  1104,
    1108,  1112,  1116
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     182,     0,    -1,    61,    -1,    90,    61,    -1,    37,    65,
      90,    66,    -1,    -1,    91,    -1,    37,    65,   121,    66,
      67,    -1,    37,   131,    65,   121,    66,    67,    -1,    37,
     131,    65,   121,    68,    95,    66,    67,    -1,    37,   131,
      65,   121,    68,    95,    68,    95,    66,    67,    -1,    37,
     131,    65,   121,    68,    95,    68,    95,    68,    98,    66,
      67,    -1,    -1,    96,    -1,    97,    -1,    96,    69,    97,
      -1,    61,    65,   121,    66,    -1,    70,    64,    71,    61,
      65,   121,    66,    -1,    90,    -1,    98,    69,    90,    -1,
      64,    -1,    62,    -1,    90,    -1,    65,   121,    66,    -1,
      99,    -1,   100,    70,   121,    71,    -1,   100,    65,    66,
      -1,   100,    65,   104,    66,    -1,    -1,   100,   101,    72,
     103,    -1,    -1,   100,   102,    39,   103,    -1,   100,    40,
      -1,   100,    41,    -1,    65,   165,    66,    73,   168,   172,
      74,    -1,    64,    -1,    63,    -1,   119,    -1,   104,    69,
     119,    -1,   100,    -1,    40,   105,    -1,    41,   105,    -1,
     106,   107,    -1,    29,   105,    -1,    29,    65,   165,    66,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,   105,    -1,    65,   165,    66,   107,    -1,
     107,    -1,   108,    76,   107,    -1,   108,    81,   107,    -1,
     108,    82,   107,    -1,   108,    -1,   109,    77,   108,    -1,
     109,    78,   108,    -1,   109,    -1,   110,    42,   109,    -1,
     110,    43,   109,    -1,   110,    -1,   111,    83,   110,    -1,
     111,    84,   110,    -1,   111,    44,   110,    -1,   111,    45,
     110,    -1,   111,    -1,   112,    46,   111,    -1,   112,    47,
     111,    -1,   112,    -1,   113,    75,   112,    -1,   113,    -1,
     114,    85,   113,    -1,   114,    -1,   115,    86,   114,    -1,
     115,    -1,   116,    48,   115,    -1,   116,    -1,   117,    49,
     116,    -1,   117,    -1,   117,    87,   121,    68,   118,    -1,
     118,    -1,   105,   120,   119,    -1,    88,    -1,    51,    -1,
      52,    -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,   119,    -1,
     121,    69,   119,    -1,   118,    -1,    -1,   121,    -1,   136,
      67,    -1,   137,    67,    -1,   126,    67,    -1,   125,    67,
      -1,   129,   209,    92,   166,    -1,   130,   209,    92,   166,
      -1,   125,    69,   209,    92,   166,    -1,   127,   201,    92,
     166,    -1,   128,   201,    92,   166,    -1,   126,    69,   201,
      92,   166,    -1,   134,    -1,   136,    -1,   140,    -1,   135,
      -1,   137,    -1,   141,    -1,   142,    -1,   130,   142,    -1,
     129,   132,    -1,   133,    -1,   130,   133,    -1,    -1,   130,
      -1,   142,    -1,   133,    -1,    19,    -1,    36,    -1,    30,
      -1,   129,   143,    -1,   135,   142,    -1,   134,   132,    -1,
     134,   143,    -1,   143,    -1,   130,   143,    -1,   135,   133,
      -1,   135,   143,    -1,   129,   144,    -1,   137,   142,    -1,
     136,   132,    -1,   144,    -1,   130,   144,    -1,   137,   133,
      -1,   145,    -1,   130,   145,    -1,   137,   133,    -1,   138,
      -1,   141,    -1,   141,   142,    -1,   129,    63,    -1,   140,
     132,    -1,    63,    -1,   130,    63,    -1,   141,   133,    -1,
      14,    -1,    16,    -1,    33,    -1,     3,    -1,    13,    -1,
      35,    -1,     5,    -1,    15,    -1,    21,    -1,     9,    -1,
      20,    -1,     4,    -1,    25,    -1,    22,    -1,    26,    -1,
     145,    -1,   156,    -1,   146,    73,   148,    74,    -1,   146,
     164,    73,   148,    74,    -1,   146,   164,    -1,   147,    -1,
       6,    -1,    18,    -1,    -1,   149,    -1,   150,    -1,   149,
     150,    -1,   152,    67,    -1,   151,    67,    -1,   139,    -1,
     128,   153,    -1,   152,    69,   153,    -1,   201,   154,    -1,
     155,    -1,    -1,   155,    -1,    68,   122,    -1,   157,    73,
     158,   172,    74,    -1,   157,   164,    73,   158,   172,    74,
      -1,   157,   164,    -1,    12,    -1,   159,    -1,   158,    69,
     159,    -1,   164,    -1,   164,    88,   122,    -1,   161,    -1,
     161,    69,    50,    -1,   162,    -1,   161,    69,   162,    -1,
     127,    -1,   127,   215,    -1,   127,   209,    -1,   127,   203,
      -1,   129,    -1,   129,   215,    -1,   129,   209,    -1,   128,
      -1,   128,   215,    -1,   128,   209,    -1,   128,   203,    -1,
     130,    -1,   130,   215,    -1,   130,   209,    -1,    64,    -1,
     163,    69,    64,    -1,    64,    -1,    63,    -1,   128,    -1,
     128,   215,    -1,   130,    -1,   130,   215,    -1,    -1,    88,
     167,    -1,    73,    74,    -1,    73,   168,   172,    74,    -1,
     119,    -1,   169,   167,    -1,   168,    69,   169,   167,    -1,
      -1,   170,    88,    -1,   171,    -1,   170,   171,    -1,    70,
     122,    71,    -1,    72,   164,    -1,    -1,    69,    -1,   174,
      -1,   175,    -1,   178,    -1,   179,    -1,   180,    -1,   181,
      -1,    94,    -1,   164,    68,   173,    -1,    11,   122,    68,
     173,    -1,    27,    68,   173,    -1,    73,    74,    -1,    73,
     176,    74,    -1,    73,   177,    74,    -1,    73,   176,   177,
      74,    -1,   124,    -1,   176,   124,    -1,   173,    -1,   177,
     173,    -1,   123,    67,    -1,    32,    65,   121,    66,   173,
      -1,    32,    65,   121,    66,   173,     8,   173,    -1,    10,
      65,   121,    66,   173,    -1,    34,    65,   121,    66,   173,
      -1,    31,   173,    34,    65,   121,    66,    67,    -1,    24,
      65,   123,    67,   123,    67,   123,    66,   173,    -1,    28,
     164,    67,    -1,    23,    67,    -1,     7,    67,    -1,    17,
     123,    67,    -1,    -1,   183,    -1,   184,    -1,   183,   184,
      -1,   185,    -1,   124,    -1,    93,    -1,    -1,   209,   186,
     175,    -1,    -1,   127,   209,   187,   175,    -1,    -1,   128,
     209,   188,   175,    -1,    -1,   129,   209,   189,   175,    -1,
      -1,   130,   209,   190,   175,    -1,    -1,   213,   191,   175,
      -1,    -1,   127,   213,   192,   175,    -1,    -1,   128,   213,
     193,   175,    -1,    -1,   129,   213,   194,   175,    -1,    -1,
     130,   213,   195,   175,    -1,    -1,   213,   176,   196,   175,
      -1,    -1,   127,   213,   176,   197,   175,    -1,    -1,   128,
     213,   176,   198,   175,    -1,    -1,   129,   213,   176,   199,
     175,    -1,    -1,   130,   213,   176,   200,   175,    -1,   209,
      -1,   202,    -1,   206,    -1,   203,    -1,    63,    -1,    63,
     216,    -1,   204,    -1,   205,    -1,    76,   203,    -1,    76,
     130,   203,    -1,    65,   204,    66,    -1,    65,   204,    66,
     216,    -1,   207,    -1,    76,    65,   208,    66,    -1,    76,
     130,    65,   208,    66,    -1,    76,   206,    -1,    76,   130,
     206,    -1,    65,   206,    66,    -1,    65,   208,   216,    66,
      -1,    65,   206,    66,   216,    -1,    63,    -1,    65,   208,
      66,    -1,   210,    -1,   212,    -1,   211,    -1,    76,   209,
      -1,    76,   130,   209,    -1,   212,   216,    -1,    65,   210,
      66,    -1,    65,   210,    66,   216,    -1,    64,    -1,    65,
     212,    66,    -1,   214,    -1,    76,   213,    -1,    76,   130,
     213,    -1,   212,    65,   163,    66,    -1,    65,   213,    66,
      -1,    65,   213,    66,   216,    -1,   218,    -1,   219,    -1,
     216,    -1,   217,    -1,    65,    66,    -1,    65,   160,    66,
      -1,    70,    71,    -1,    70,   119,    71,    -1,    70,    76,
      71,    -1,   217,    70,   119,    71,    -1,   217,    70,    76,
      71,    -1,    76,    -1,    76,   130,    -1,    76,   215,    -1,
      76,   130,   215,    -1,    65,   218,    66,    -1,    65,   219,
      66,    -1,    65,   216,    66,    -1,    65,   218,    66,   216,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   625,   625,   626,   634,   637,   639,   643,   647,   648,
     650,   653,   659,   661,   665,   666,   670,   671,   675,   676,
     681,   687,   688,   689,   693,   694,   695,   696,   697,   697,
     698,   698,   699,   700,   701,   705,   706,   710,   711,   715,
     716,   717,   718,   736,   737,   741,   742,   743,   744,   745,
     746,   750,   751,   755,   756,   758,   765,   775,   776,   778,
     783,   784,   786,   791,   792,   794,   796,   798,   803,   804,
     806,   811,   812,   817,   818,   823,   824,   829,   830,   835,
     836,   841,   842,   847,   848,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   861,   862,   866,   867,   871,   875,
     877,   915,   916,   917,   918,   925,   949,   955,   966,   988,
     994,  1006,  1011,  1012,  1017,  1022,  1023,  1029,  1030,  1031,
    1035,  1036,  1039,  1041,  1045,  1046,  1050,  1051,  1052,  1056,
    1057,  1058,  1059,  1063,  1064,  1065,  1066,  1070,  1075,  1080,
    1088,  1089,  1090,  1094,  1095,  1096,  1100,  1101,  1104,  1109,
    1114,  1122,  1123,  1124,  1128,  1129,  1130,  1131,  1132,  1133,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1149,
    1150,  1154,  1171,  1207,  1236,  1245,  1246,  1250,  1251,  1255,
    1266,  1280,  1281,  1285,  1289,  1302,  1316,  1343,  1363,  1364,
    1368,  1372,  1389,  1425,  1456,  1464,  1479,  1498,  1511,  1527,
    1528,  1532,  1533,  1537,  1538,  1539,  1540,  1541,  1542,  1543,
    1544,  1545,  1546,  1547,  1548,  1549,  1550,  1558,  1559,  1563,
    1564,  1571,  1584,  1605,  1613,  1624,  1626,  1630,  1631,  1632,
    1636,  1637,  1640,  1642,  1646,  1647,  1651,  1652,  1655,  1657,
    1662,  1663,  1664,  1665,  1666,  1667,  1668,  1672,  1673,  1674,
    1678,  1679,  1680,  1681,  1685,  1686,  1690,  1691,  1695,  1699,
    1700,  1701,  1705,  1706,  1707,  1711,  1712,  1713,  1714,  1720,
    1722,  1726,  1727,  1731,  1732,  1733,  1737,  1737,  1739,  1739,
    1741,  1741,  1743,  1743,  1745,  1745,  1748,  1748,  1749,  1749,
    1750,  1750,  1751,  1751,  1752,  1752,  1754,  1754,  1755,  1755,
    1756,  1756,  1757,  1757,  1758,  1758,  1762,  1763,  1767,  1768,
    1772,  1776,  1790,  1797,  1798,  1804,  1813,  1814,  1825,  1826,
    1832,  1838,  1844,  1853,  1854,  1859,  1867,  1871,  1875,  1876,
    1880,  1881,  1887,  1896,  1901,  1902,  1910,  1922,  1926,  1927,
    1928,  1932,  1937,  1938,  1946,  1947,  1948,  1963,  1964,  1965,
    1969,  1980,  1991,  1992,  2003,  2017,  2022,  2027,  2032,  2040,
    2041,  2042,  2054
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
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
  "assignment_expression", "assignment_operator", "comma_expression",
  "constant_expression", "comma_expression_opt", "declaration",
  "default_declaring_list", "declaring_list", "declaration_specifier",
  "type_specifier", "declaration_qualifier_list", "type_qualifier_list",
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

/* INFRINGES ON USER NAME SPACE */
#ifndef _
# define _(msgid) msgid
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
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
static const unsigned char yyr1[] =
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
     120,   120,   120,   120,   120,   120,   121,   121,   122,   123,
     123,   124,   124,   124,   124,   125,   125,   125,   126,   126,
     126,   127,   127,   127,   128,   128,   128,   129,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   133,   134,
     134,   134,   134,   135,   135,   135,   135,   136,   136,   136,
     137,   137,   137,   138,   138,   138,   139,   139,   140,   140,
     140,   141,   141,   141,   142,   142,   142,   142,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     144,   145,   145,   145,   146,   147,   147,   148,   148,   149,
     149,   150,   150,   151,   152,   152,   153,   153,   154,   154,
     155,   156,   156,   156,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   163,   163,   164,
     164,   165,   165,   165,   165,   166,   166,   167,   167,   167,
     168,   168,   169,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   173,   173,   173,   173,   173,   174,   174,   174,
     175,   175,   175,   175,   176,   176,   177,   177,   178,   179,
     179,   179,   180,   180,   180,   181,   181,   181,   181,   182,
     182,   183,   183,   184,   184,   184,   186,   185,   187,   185,
     188,   185,   189,   185,   190,   185,   191,   185,   192,   185,
     193,   185,   194,   185,   195,   185,   196,   185,   197,   185,
     198,   185,   199,   185,   200,   185,   201,   201,   202,   202,
     203,   203,   203,   204,   204,   204,   205,   205,   206,   206,
     206,   206,   206,   207,   207,   207,   208,   208,   209,   209,
     210,   210,   210,   211,   211,   211,   212,   212,   213,   213,
     213,   214,   214,   214,   215,   215,   215,   216,   216,   216,
     217,   217,   217,   217,   217,   218,   218,   218,   218,   219,
     219,   219,   219
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
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
       1,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       1,     2,     2,     2,     2,     4,     4,     5,     4,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     1,     1,     2,     2,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     2,     1,     1,     1,     0,     1,     1,
       2,     2,     2,     1,     2,     3,     2,     1,     0,     1,
       2,     5,     6,     2,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     2,     2,     1,     2,     2,
       1,     2,     2,     2,     1,     2,     2,     1,     3,     1,
       1,     1,     2,     1,     2,     0,     2,     2,     4,     1,
       2,     4,     0,     2,     1,     2,     3,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     3,     4,     1,     2,     1,     2,     2,     5,
       7,     5,     5,     7,     9,     3,     2,     2,     3,     0,
       1,     1,     2,     1,     1,     1,     0,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     5,
       0,     5,     0,     5,     0,     5,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     3,     3,     4,     1,     4,
       5,     2,     3,     3,     4,     4,     1,     3,     1,     1,
       1,     2,     3,     2,     3,     4,     1,     3,     1,     2,
       3,     4,     3,     4,     1,     1,     1,     1,     2,     3,
       2,     3,     3,     4,     4,     1,     2,     2,     3,     3,
       3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
     269,   157,   165,   160,   175,   163,   194,   158,   154,   161,
     155,   176,   126,   164,   162,   167,   166,   168,   128,   156,
     159,   127,     0,   151,   336,     0,     0,   275,   274,     0,
       0,     0,     0,     0,     0,   120,   111,   114,   112,   115,
     113,   116,   117,   133,   140,   169,     0,   174,   170,     0,
       0,   270,   271,   273,   276,   328,   330,   329,   286,   338,
       0,     0,     0,     0,     0,   331,   339,   104,     0,   103,
       0,   310,     0,     0,     5,   307,   309,   312,   313,   308,
     318,   306,   288,     5,   306,   290,   149,   119,   125,   124,
     129,   137,     5,   292,   152,   121,   118,   134,   141,     5,
     294,   131,   132,   135,   130,   136,   101,   139,   102,   142,
     138,   150,   153,   148,   220,   219,   177,   173,     0,   193,
       1,   272,     0,     0,     0,   333,   347,   254,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     2,    21,    20,
       0,    45,    46,    47,    48,    49,    50,    22,    24,    39,
      51,     0,    53,    57,    60,    63,    68,    71,    73,    75,
      77,    79,    81,    83,    96,     0,   334,   337,   342,   332,
     340,     0,     0,     5,   329,     0,     0,     5,   306,     0,
     311,   326,     0,     0,     0,     0,     0,     0,   314,   321,
       0,     6,   225,     0,   298,     0,   225,     0,   300,     0,
     225,     0,   302,     0,   225,     0,   304,     0,     0,     0,
     114,   115,   146,   183,   116,   169,     0,   178,   179,     0,
       0,   177,   238,   195,   197,     0,    99,   277,   217,   348,
     203,   210,   207,   214,   112,   115,     0,   199,   201,     0,
     350,    46,     0,     0,     5,     5,   255,     0,   287,     0,
      43,     0,    40,    41,     0,   221,   223,   115,   116,     0,
       3,    32,    33,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    85,     0,    51,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   335,   343,     0,     0,   225,     0,     0,     0,
     225,     0,   316,   323,     0,     0,     0,   315,   322,     0,
       0,   108,   279,     0,   289,   109,   281,     0,   291,   105,
     283,     0,   293,   106,   285,     0,   295,     0,   184,   187,
     188,   169,   142,   171,   180,   182,   181,     0,     0,   239,
       0,     0,   238,     0,     0,     0,    99,     0,     0,     0,
       0,    99,     0,     0,   122,   151,    20,   250,   246,   100,
       0,     0,   256,   240,   241,    99,    99,   242,   243,   244,
     245,     0,   355,   206,   205,   204,   346,   344,   345,   213,
     212,   211,     0,   355,   209,   208,   216,   215,   349,     0,
     341,     0,   352,   351,    46,     0,   297,     0,     0,    23,
       0,   355,   222,   224,     0,    26,     0,    37,     0,     0,
       0,    84,    54,    55,    56,    58,    59,    61,    62,    66,
      67,    64,    65,    69,    70,    72,    74,    76,    78,    80,
       0,     7,    97,   107,     0,   110,   327,   317,   325,   324,
     319,     0,     0,   232,   229,   226,   299,   301,   303,   305,
      98,   190,   186,   189,   185,   172,   196,   191,   198,     0,
     267,     0,     0,     0,   266,    99,    99,     0,     0,     0,
       0,   123,     0,   258,    99,   251,    99,   252,   257,     0,
       0,     0,   356,   357,   356,   200,   202,   218,   354,   353,
      44,     0,   356,   232,    52,    27,     0,    25,    36,    35,
      29,    31,     0,   320,     4,     0,     0,   227,   238,     0,
       0,   234,   192,     0,    99,   268,     0,   249,   265,     0,
       0,     0,     0,   247,   253,   361,   359,   360,   358,   238,
      38,    82,     0,   237,   232,     0,   230,   233,   235,    99,
     248,    99,     0,    99,    99,     0,   362,     0,   236,     0,
     228,   261,     0,     0,   259,   262,     0,    12,    34,   231,
      99,     0,    99,     8,     0,     0,     0,    13,    14,     0,
     263,   260,     0,     0,     0,    12,     0,    99,     0,     0,
       9,     0,    15,   264,    16,     0,     0,     0,     0,    10,
      18,     0,     0,     0,     0,    17,    11,    19
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,   147,   191,   200,    27,   368,   576,   577,   578,   601,
     148,   149,   265,   266,   510,   416,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   278,   369,   461,   370,   127,    29,    30,   128,   129,
     130,   131,   482,    87,    35,    36,    37,    38,    39,   212,
     213,    40,    41,    42,    43,    44,    45,    46,    47,   216,
     217,   218,   219,   220,   338,   462,   339,    48,    49,   222,
     223,   236,   237,   238,   239,   371,   259,   321,   455,   518,
     519,   520,   521,   350,   372,   373,   374,   132,   376,   377,
     378,   379,   380,    50,    51,    52,    53,   122,   193,   197,
     201,   205,   133,   195,   199,   203,   207,   247,   323,   327,
     331,   335,    74,    75,    76,    77,    78,   184,    80,   185,
      65,    55,    56,   174,    63,    59,   493,   386,   126,   387,
     388
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -503
static const short int yypact[] =
{
    1280,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,
    -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,
    -503,  -503,   -53,  -503,  -503,   164,   877,  -503,  -503,   169,
     340,   237,   237,  1488,  1524,  -503,  2156,  2156,   971,  1045,
    1102,  1102,  -503,  -503,  -503,  -503,   214,  -503,  -503,   291,
      29,  1280,  -503,  -503,  -503,  -503,  -503,    43,  1852,  -503,
    2000,   -29,   312,   -25,   877,  -503,  -503,  -503,   200,  -503,
     324,    92,   363,   491,    27,  -503,  -503,  -503,  -503,  -503,
    -503,    11,  1852,    27,    24,  1852,  -503,  -503,  -503,  -503,
    -503,  -503,    -7,  1852,  -503,  -503,  -503,  -503,  -503,    -6,
    1852,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,
    -503,  -503,  -503,  -503,  -503,  -503,  1886,    33,   102,    37,
    -503,  -503,    50,  1723,  1111,  -503,    64,  -503,   324,   324,
    1589,  1625,  1852,    50,  2026,  2052,  2052,  -503,  -503,  -503,
     918,  -503,  -503,  -503,  -503,  -503,  -503,    94,  -503,   474,
     578,  2000,  -503,   131,   264,   375,    -5,   377,    98,   129,
     101,   132,   -33,  -503,  -503,    -8,    92,  -503,    92,  -503,
    -503,   200,   998,    27,    92,   378,   670,    27,  -503,  1779,
    -503,  -503,   363,   160,   176,    92,   363,  1176,  -503,  -503,
     165,  -503,   180,    50,  1852,    50,   180,    50,  1852,    50,
     180,    50,  1852,    50,   180,    50,  1852,    50,   271,  1914,
     941,    19,  -503,  -503,   105,   236,   235,  1886,  -503,   261,
     459,  1886,   248,  -503,   245,   102,   757,  -503,  -503,  -503,
      18,    18,  1316,  1384,  1102,  1102,   296,   268,  -503,   229,
    -503,   286,   304,  2078,    27,    27,  -503,    50,  -503,   918,
    -503,   918,  -503,  -503,   283,    -2,  1687,    19,    19,   313,
    -503,  -503,  -503,  1922,  2000,   359,   406,  -503,  -503,  -503,
    -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  2000,  -503,
    -503,  2000,  2000,  2000,  2000,  2000,  2000,  2000,  2000,  2000,
    2000,  2000,  2000,  2000,  2000,  2000,  2000,  2000,  2000,  2000,
     395,  2000,  -503,  -503,   320,   998,   180,   378,   378,  1891,
     180,   368,    92,    92,   403,   391,   363,  -503,  -503,   412,
    1931,  -503,  -503,    50,  -503,  -503,  -503,    50,  -503,  -503,
    -503,    50,  -503,  -503,  -503,    50,  -503,  2000,  -503,  -503,
     428,   413,   432,  -503,  -503,  -503,  -503,   271,   429,   102,
     434,  2000,   248,   444,   458,  2000,  2000,   485,   492,   500,
     102,  1066,   506,   513,    19,   511,   514,  -503,  -503,   515,
     516,   519,  -503,  -503,  -503,   841,   647,  -503,  -503,  -503,
    -503,  1144,   666,  -503,  -503,  -503,  -503,  -503,  -503,  -503,
    -503,  -503,  1212,  1894,  -503,  -503,  -503,  -503,  -503,  1813,
    -503,   525,  -503,  -503,   521,   522,  -503,   528,   548,  -503,
    1420,   505,  -503,  -503,  1974,  -503,   302,  -503,    16,   373,
     373,  -503,  -503,  -503,  -503,   131,   131,   264,   264,   375,
     375,   375,   375,    -5,    -5,   377,    98,   129,   101,   132,
     422,  -503,  -503,  -503,   378,  -503,  -503,  -503,  -503,  -503,
    -503,   405,   185,   183,  -503,  -503,  -503,  -503,  -503,  -503,
    -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,   542,
    -503,  2000,   554,   557,  -503,  2000,  1066,   559,   594,  2000,
    2000,    19,   585,  -503,  1066,  -503,   992,  -503,  -503,   577,
     586,   587,   666,  -503,  1894,  -503,  -503,  -503,  -503,  -503,
     582,   582,   505,   211,  -503,  -503,  2000,  -503,  -503,  -503,
    -503,  -503,  2000,  -503,  -503,  2000,   102,  -503,   590,  1931,
       3,  -503,  -503,   303,  1066,  -503,   589,  -503,  -503,   595,
     315,   326,  2000,  -503,  -503,  -503,    92,  -503,  -503,   590,
    -503,  -503,   597,  -503,   250,   598,  -503,  -503,  -503,  1066,
    -503,  2000,  2000,  1066,  1066,    74,  -503,   603,  -503,  1931,
    -503,  -503,   613,   327,   653,  -503,   615,    28,  -503,  -503,
    2000,   616,  1066,  -503,   625,   627,   463,   623,  -503,   628,
    -503,  -503,  2000,   622,   630,    28,    28,  1066,   337,   634,
    -503,   477,  -503,  -503,  -503,   633,   632,   412,  2000,  -503,
      94,   431,   438,   636,   412,  -503,  -503,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -503,  -313,  -503,   116,  -503,  -503,   119,  -503,   115,  -503,
    -503,  -503,  -503,  -503,   285,  -503,   314,  -503,   -58,   249,
     262,   275,   284,   419,   421,   411,   417,   439,  -503,  -265,
    -115,  -503,   -60,  -333,  -314,    60,  -503,  -503,     2,   159,
      48,    95,  -503,     7,   -13,  -503,   281,   -67,   181,  -503,
    -503,  -503,   369,   608,   430,   118,  -102,  -503,  -503,   494,
    -503,   501,  -503,  -503,   370,  -503,   379,  -503,  -503,   507,
     392,  -503,  -503,   341,  -503,   -42,   323,  -104,  -502,   241,
     201,  -503,   228,  -339,   -71,  -503,   420,   -23,   374,  -503,
    -503,  -503,  -503,  -503,  -503,   699,  -503,  -503,  -503,  -503,
    -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,  -503,
    -503,  -503,   -24,  -503,   -37,   -28,  -503,   238,  -503,  -171,
       1,   -22,  -503,   144,   486,  -503,  -129,   -52,  -503,  -272,
    -225
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -285
static const short int yytable[] =
{
     165,    54,    31,    61,   117,   125,   452,   119,    83,   242,
     125,   311,    60,   469,   215,   315,   298,   546,   468,   180,
      88,    95,   472,    88,   103,    88,   109,    88,   112,   120,
     190,   190,    81,    84,    92,    99,   188,   166,    12,   288,
     289,   168,   473,   101,   183,   107,   177,   111,    33,    18,
      61,    95,    54,    31,   299,    21,   234,   569,   300,   194,
      28,   301,   198,   410,   190,   169,  -282,  -284,   124,   173,
     202,   178,   460,   515,   411,   516,   224,   206,   290,   291,
     254,    71,    24,   381,  -278,   301,   460,   507,   124,   574,
     460,   547,   325,   280,   382,    34,   329,  -280,   575,    33,
     333,   385,   391,   395,   397,    83,   221,   341,   123,   490,
     225,    28,   234,   124,   302,   215,   303,    88,    95,   215,
     490,    64,   125,   226,    12,   230,   412,   413,   405,   178,
     178,   244,   245,   314,   243,    18,   311,   315,   490,   188,
     566,    21,   567,   301,    57,   451,    34,   183,   417,    61,
     317,    91,    98,    61,   183,   260,   491,   179,   183,    32,
      61,   526,   124,   421,    61,   114,   115,   491,   187,    62,
      57,   232,  -147,   294,    95,    57,    57,    57,    57,   545,
     297,   230,   542,   224,   340,   491,   442,   296,   169,   254,
     192,   254,   246,   383,   389,    57,    95,   103,   342,   196,
     557,   112,   443,   375,   418,   454,   445,   281,    57,   178,
      32,   209,   282,   283,   295,   204,    62,    57,   233,    88,
      95,    88,   109,   422,   423,   424,   312,   232,    24,    25,
     319,   384,   390,   394,   396,   256,    67,   562,    68,   440,
      26,   107,   313,    95,   109,   112,   260,   541,    91,    98,
     460,   514,   125,   515,   246,   516,   579,   517,   246,   314,
     447,   448,   246,   314,    24,   171,   246,   305,   320,    79,
      79,   309,   317,   451,   233,   208,   172,   114,   115,   183,
     183,   515,   231,   516,   600,    61,    61,   116,   183,   306,
     478,   607,    95,   310,    61,   400,    95,   211,   401,   255,
      71,    24,    72,  -143,   235,   488,   169,   224,    79,   343,
     169,   189,   209,    73,   234,   304,   209,   349,   477,   304,
     515,   257,   516,   340,  -239,   234,    62,    98,   345,   489,
      62,    57,   234,   351,    71,    24,   175,   399,   231,   337,
     489,   284,   285,   234,   256,   188,   256,   176,   178,   409,
      91,    98,   301,   183,   114,   115,   504,   402,   489,    61,
     235,   204,   398,   538,   118,   538,    79,    79,   505,   549,
      61,   506,   301,   538,    98,   403,   208,   123,   167,   414,
     208,   553,   124,   230,   301,   179,   167,    71,    24,   175,
     124,   540,   554,   571,   230,   301,   301,   210,   211,   314,
     176,   230,   211,   594,   454,   527,   301,    69,   255,    70,
     255,   523,   230,   533,   189,   488,   183,   286,   287,   530,
     531,   210,    61,   292,   293,   318,   181,    24,   182,   232,
     257,   419,   257,   179,   446,   246,   508,   509,   124,    73,
     232,   181,    24,   307,   454,   420,    79,   232,   250,   252,
     253,   304,   304,   550,   176,   317,   179,   450,   232,   481,
      62,   124,   441,    90,    97,   279,   102,   105,    95,   449,
     179,   513,   555,   137,   543,   124,   233,   492,   561,    95,
    -144,    95,   564,   565,   556,   214,    58,   233,   494,    95,
     512,   301,   563,   169,   233,   169,   337,   603,   210,  -145,
     604,   581,   210,   465,   605,   233,   502,   301,   467,   258,
      12,   470,    66,   -30,   261,   262,   593,    82,    85,    93,
     100,    18,   588,   471,    12,   304,   346,    21,   347,   584,
     210,   585,   210,   425,   426,    18,   304,    58,   602,   263,
     231,    21,   227,   596,   264,   597,   -28,   318,   427,   428,
     170,   231,   474,   248,    71,    24,   186,   475,   231,    66,
      90,    97,   235,   429,   430,   431,   432,    73,   476,   231,
     410,   479,   407,   235,   408,   124,   433,   434,   480,  -220,
     235,   411,  -219,   483,   301,    79,   214,   484,   304,   497,
     214,   235,   498,   499,   500,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   322,   501,   324,   522,   326,   258,   328,
     258,   330,   524,   332,   525,   334,   528,   336,   529,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,    97,
     105,    89,    96,   535,    89,   104,    89,   110,    89,   113,
     532,   279,   536,   537,   353,   503,   551,   354,   355,   544,
     552,   572,    90,    97,   356,   279,   277,   406,   558,   279,
     357,   358,   560,   170,   359,   360,   134,   568,   361,   362,
     570,   363,   573,   580,   364,    12,    97,   135,   136,    12,
     582,   583,   586,   589,   587,   595,    18,   590,   598,   599,
      18,   592,    21,   606,   591,   511,    21,   437,   137,   138,
     114,   366,   140,   435,   438,   348,   436,   464,   344,   463,
     226,   487,   141,   142,   143,   144,   145,   146,   279,    71,
      24,   381,   352,    71,    24,   308,   124,   439,    89,    96,
     496,   466,   382,   456,   539,   559,   176,   457,   548,   486,
     121,   458,     0,     0,     0,   459,     0,     0,     0,     0,
       1,     2,     3,     4,   353,     0,     5,   354,   355,     6,
       7,     8,     9,    10,   356,    11,    12,    13,    14,    15,
     357,   358,    16,    17,   359,   360,   134,    18,   361,   362,
      19,   363,    20,    21,   364,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     365,   366,   140,     0,     0,     0,   279,     0,     0,   279,
     226,   367,   141,   142,   143,   144,   145,   146,     0,     0,
      89,    96,    89,   110,     1,     2,     3,     4,   353,     0,
       5,   354,   355,     6,     7,     8,     9,    10,   356,    11,
      12,    13,    14,    15,   357,   358,    16,    17,   359,   360,
     134,    18,   361,   362,    19,   363,    20,    21,   364,     0,
       0,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,   137,   138,   365,   366,   140,    18,     0,     0,
       0,     0,     0,    21,   226,   485,   141,   142,   143,   144,
     145,   146,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     9,     0,     0,    11,    12,    13,    14,
      15,    24,    25,    16,    17,     2,     3,   134,    18,     0,
       5,     0,     0,    26,    21,     0,     9,     0,   135,   136,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,     0,     0,     1,     0,     0,    21,     0,   137,
     138,    23,   139,   140,     7,     8,     0,    10,     0,     0,
      12,     0,     0,   141,   142,   143,   144,   145,   146,   353,
       0,    18,   354,   355,    19,     0,    20,    21,     0,   356,
       0,     0,     0,     0,     0,   357,   358,    12,     0,   359,
     360,   134,     0,   361,   362,     0,   363,     0,    18,   364,
       0,     0,   135,   136,    21,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,   137,   138,   114,   366,   140,     7,     8,
       0,    10,    24,   171,    12,   226,   534,   141,   142,   143,
     144,   145,   146,   353,   172,    18,   354,   355,    19,     0,
      20,    21,     0,   356,     0,     0,     0,     0,     0,   357,
     358,     0,     0,   359,   360,   134,     0,   361,   362,     0,
     363,     0,     0,   364,     0,     1,   135,   136,     0,     0,
       0,     0,   108,     0,     0,     7,     8,     0,    10,     0,
       0,    12,     0,     0,     0,     0,     0,   137,   138,   114,
     366,   140,    18,     0,     0,    19,     0,    20,    21,   226,
     134,   141,   142,   143,   144,   145,   146,     1,     2,     3,
       4,   135,   136,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,   137,   138,    18,   139,   140,    19,     0,    20,
      21,     0,   240,     0,     0,     0,   141,   241,   143,   144,
     145,   146,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    23,    24,   381,
     229,     0,    21,     0,   124,     1,     2,     3,     4,     0,
     382,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,    71,
      24,   316,    18,     0,     0,    19,     0,    20,    21,     0,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,   392,   229,     0,
       0,     0,   124,     1,     2,     3,     4,     0,   393,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,    20,    21,    22,     0,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,    23,    24,    25,    18,     0,     0,    19,
       0,    20,    21,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      24,   392,     0,     0,     0,     0,   124,     1,     2,     3,
       4,     0,   393,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,    20,
      21,     0,     0,     1,     2,     3,     4,     0,     0,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,    94,    24,   392,
      18,     0,     0,    19,   124,    20,    21,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,     0,   410,   229,     0,     0,     0,
     124,     1,     2,     3,     4,     0,   411,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,    19,     0,    20,    21,     0,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,    86,    24,    25,    18,     0,     0,    19,     0,    20,
      21,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    24,    25,
       0,     0,     1,     2,     3,     4,     0,     0,     5,     0,
      26,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,     0,    18,
       0,     0,    19,     0,    20,    21,     0,     0,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,    86,    24,   171,    18,     0,     0,    19,     0,
      20,    21,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    24,
     171,     2,     3,     4,     0,     0,     5,     0,     0,     6,
       0,   172,     9,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
       0,     0,     0,    21,     0,     0,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
      94,     0,   410,    18,     0,     0,    19,   124,    20,    21,
       0,     0,     0,   411,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,    23,   228,     5,   229,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,     0,    18,
       0,     0,    19,     0,    20,    21,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,    23,    18,     0,   229,    19,     0,    20,    21,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       0,     5,     0,   495,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,    23,    16,    17,     0,
       0,     0,    18,     0,     0,    19,     0,    20,    21,     0,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     0,
       0,     9,     0,     0,    11,    12,    13,    14,    15,     0,
      12,    16,    17,    12,     0,    23,    18,     0,     2,     3,
       4,    18,    21,     5,    18,     0,     6,    21,     0,     9,
      21,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,     0,     0,    23,
      21,   134,     0,     0,    71,    24,   444,     0,    24,   392,
     134,     0,   135,   136,   124,     0,     0,   176,     0,     0,
     393,   135,   136,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,   137,   138,     0,   139,   140,   415,     0,
       0,     0,   137,   138,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   134,   453,     0,   141,   142,   143,   144,
     145,   146,     0,     0,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
       0,     0,     0,     0,     0,   137,   138,     0,   139,   140,
     135,   136,     0,     0,     0,     0,     0,   503,     0,   141,
     142,   143,   144,   145,   146,   134,     0,     0,     0,     0,
       0,   137,   138,     0,   139,   140,   135,   136,     0,     0,
       0,     0,     0,     0,     0,   141,   142,   143,   144,   145,
     146,   134,     0,     0,     0,     0,     0,   137,   138,     0,
     139,   249,   135,   136,     0,     0,     0,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   134,     0,     0,
       0,     0,     0,   137,   138,     0,   139,   251,   135,   136,
       0,     0,     0,     0,     0,     0,     0,   141,   142,   143,
     144,   145,   146,     0,     0,     0,     0,     0,     0,   137,
     138,     0,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   404,   143,   144,   145,   146,     1,
       2,     3,     0,     0,     0,     5,     0,     0,     0,     7,
       8,     9,    10,     0,     0,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21
};

static const short int yycheck[] =
{
      60,     0,     0,    25,    46,    57,   319,    49,    32,   124,
      62,   182,    65,   352,   116,   186,    49,   519,   351,    71,
      33,    34,   355,    36,    37,    38,    39,    40,    41,     0,
      37,    37,    31,    32,    33,    34,    73,    66,    19,    44,
      45,    66,   356,    36,    72,    38,    70,    40,     0,    30,
      72,    64,    51,    51,    87,    36,   123,   559,    66,    82,
       0,    69,    85,    65,    37,    64,    73,    73,    70,    68,
      93,    70,   337,    70,    76,    72,   118,   100,    83,    84,
     140,    63,    64,    65,    73,    69,   351,    71,    70,    61,
     355,    88,   196,   151,    76,     0,   200,    73,    70,    51,
     204,   230,   231,   232,   233,   129,    73,   209,    65,   381,
      73,    51,   179,    70,   166,   217,   168,   130,   131,   221,
     392,    26,   174,    73,    19,   123,   255,   256,   243,   128,
     129,   130,   131,   185,    70,    30,   307,   308,   410,   176,
      66,    36,    68,    69,     0,   316,    51,   175,   263,   171,
     187,    33,    34,   175,   182,    61,   381,    65,   186,     0,
     182,   475,    70,   278,   186,    63,    64,   392,    73,    25,
      26,   123,    67,    75,   187,    31,    32,    33,    34,   518,
      48,   179,   515,   225,   208,   410,   301,    86,   187,   249,
      74,   251,   132,   230,   231,    51,   209,   210,   211,    83,
     539,   214,   306,   226,   264,   320,   310,    76,    64,   208,
      51,   116,    81,    82,    85,    99,    72,    73,   123,   232,
     233,   234,   235,   281,   282,   283,    66,   179,    64,    65,
      65,   230,   231,   232,   233,   140,    67,   551,    69,   299,
      76,   234,    66,   256,   257,   258,    61,   512,   130,   131,
     515,    66,   304,    70,   194,    72,   570,    74,   198,   311,
     312,   313,   202,   315,    64,    65,   206,   172,    88,    31,
      32,   176,   309,   444,   179,   116,    76,    63,    64,   307,
     308,    70,   123,    72,   597,   307,   308,    73,   316,   173,
     361,   604,   305,   177,   316,    66,   309,   116,    69,   140,
      63,    64,    65,    67,   123,   376,   305,   349,    70,    74,
     309,    73,   217,    76,   381,   171,   221,    69,   360,   175,
      70,   140,    72,   347,    74,   392,   182,   209,    67,   381,
     186,   187,   399,    88,    63,    64,    65,    69,   179,    68,
     392,    77,    78,   410,   249,   382,   251,    76,   347,    66,
     232,   233,    69,   381,    63,    64,   414,    71,   410,   381,
     179,   245,    66,   492,    73,   494,   128,   129,    66,    66,
     392,    69,    69,   502,   256,    71,   217,    65,    66,    66,
     221,    66,    70,   381,    69,    65,    66,    63,    64,    65,
      70,   506,    66,    66,   392,    69,    69,   116,   217,   451,
      76,   399,   221,    66,   519,   476,    69,    67,   249,    69,
     251,   471,   410,   484,   176,   486,   444,    42,    43,   479,
     480,   140,   444,    46,    47,   187,    63,    64,    65,   381,
     249,    72,   251,    65,    66,   375,    63,    64,    70,    76,
     392,    63,    64,    65,   559,    39,   208,   399,   134,   135,
     136,   307,   308,   524,    76,   492,    65,    66,   410,   364,
     316,    70,    67,    33,    34,   151,    36,    37,   481,    66,
      65,    66,   532,    61,   516,    70,   381,   382,   549,   492,
      67,   494,   553,   554,   536,   116,     0,   392,   393,   502,
      68,    69,   552,   492,   399,   494,    68,    66,   217,    67,
      69,   572,   221,    74,    66,   410,   411,    69,    74,   140,
      19,    67,    26,    39,    40,    41,   587,    31,    32,    33,
      34,    30,   582,    65,    19,   381,    67,    36,    69,    66,
     249,    68,   251,   284,   285,    30,   392,    51,   598,    65,
     381,    36,   122,    66,    70,    68,    72,   309,   286,   287,
      64,   392,    67,   133,    63,    64,    65,    65,   399,    73,
     130,   131,   381,   288,   289,   290,   291,    76,    68,   410,
      65,    65,   249,   392,   251,    70,   292,   293,    65,    68,
     399,    76,    68,    67,    69,   347,   217,    68,   444,    64,
     221,   410,    71,    71,    66,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   193,    66,   195,    74,   197,   249,   199,
     251,   201,    68,   203,    67,   205,    67,   207,    34,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,   209,
     210,    33,    34,    66,    36,    37,    38,    39,    40,    41,
      65,   337,    66,    66,     7,    73,    67,    10,    11,    69,
      65,     8,   232,   233,    17,   351,    88,   247,    71,   355,
      23,    24,    74,   187,    27,    28,    29,    74,    31,    32,
      67,    34,    67,    67,    37,    19,   256,    40,    41,    19,
      65,    64,    69,    71,    66,    61,    30,    67,    65,    67,
      30,   586,    36,    67,   585,   420,    36,   296,    61,    62,
      63,    64,    65,   294,   297,   221,   295,   347,   217,   340,
      73,    74,    75,    76,    77,    78,    79,    80,   414,    63,
      64,    65,   225,    63,    64,    65,    70,   298,   130,   131,
     399,   349,    76,   323,   503,   544,    76,   327,   520,   375,
      51,   331,    -1,    -1,    -1,   335,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    -1,   512,    -1,    -1,   515,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
     232,   233,   234,   235,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    30,    -1,    -1,
      -1,    -1,    -1,    36,    73,    74,    75,    76,    77,    78,
      79,    80,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,
      22,    64,    65,    25,    26,     4,     5,    29,    30,    -1,
       9,    -1,    -1,    76,    36,    -1,    15,    -1,    40,    41,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,     3,    -1,    -1,    36,    -1,    61,
      62,    63,    64,    65,    13,    14,    -1,    16,    -1,    -1,
      19,    -1,    -1,    75,    76,    77,    78,    79,    80,     7,
      -1,    30,    10,    11,    33,    -1,    35,    36,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    23,    24,    19,    -1,    27,
      28,    29,    -1,    31,    32,    -1,    34,    -1,    30,    37,
      -1,    -1,    40,    41,    36,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    13,    14,
      -1,    16,    64,    65,    19,    73,    74,    75,    76,    77,
      78,    79,    80,     7,    76,    30,    10,    11,    33,    -1,
      35,    36,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    27,    28,    29,    -1,    31,    32,    -1,
      34,    -1,    -1,    37,    -1,     3,    40,    41,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    13,    14,    -1,    16,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    30,    -1,    -1,    33,    -1,    35,    36,    73,
      29,    75,    76,    77,    78,    79,    80,     3,     4,     5,
       6,    40,    41,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    61,    62,    30,    64,    65,    33,    -1,    35,
      36,    -1,    71,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    63,    64,    65,
      66,    -1,    36,    -1,    70,     3,     4,     5,     6,    -1,
      76,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    63,
      64,    65,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    70,     3,     4,     5,     6,    -1,    76,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    37,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    63,    64,    65,    30,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,     3,     4,     5,
       6,    -1,    76,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    63,    64,    65,
      30,    -1,    -1,    33,    70,    35,    36,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,     3,     4,     5,     6,    -1,    76,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    63,    64,    65,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      76,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    63,    64,    65,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      -1,    76,    15,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      63,    -1,    65,    30,    -1,    -1,    33,    70,    35,    36,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    63,    64,     9,    66,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    63,    30,    -1,    66,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    50,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    63,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      19,    25,    26,    19,    -1,    63,    30,    -1,     4,     5,
       6,    30,    36,     9,    30,    -1,    12,    36,    -1,    15,
      36,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    63,
      36,    29,    -1,    -1,    63,    64,    65,    -1,    64,    65,
      29,    -1,    40,    41,    70,    -1,    -1,    76,    -1,    -1,
      76,    40,    41,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    61,    62,    -1,    64,    65,    75,    76,    77,
      78,    79,    80,    29,    73,    -1,    75,    76,    77,    78,
      79,    80,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,    65,
      40,    41,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,
      76,    77,    78,    79,    80,    29,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    64,    65,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    29,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      64,    65,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    29,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    65,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,     3,
       4,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     9,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    25,    26,    30,    33,
      35,    36,    37,    63,    64,    65,    76,    93,   124,   125,
     126,   127,   128,   129,   130,   133,   134,   135,   136,   137,
     140,   141,   142,   143,   144,   145,   146,   147,   156,   157,
     182,   183,   184,   185,   209,   210,   211,   212,   213,   214,
      65,   210,   212,   213,   130,   209,   213,    67,    69,    67,
      69,    63,    65,    76,   201,   202,   203,   204,   205,   206,
     207,   209,   213,   201,   209,   213,    63,   132,   133,   142,
     143,   144,   209,   213,    63,   133,   142,   143,   144,   209,
     213,   132,   143,   133,   142,   143,    67,   132,    67,   133,
     142,   132,   133,   142,    63,    64,    73,   164,    73,   164,
       0,   184,   186,    65,    70,   216,   217,   124,   127,   128,
     129,   130,   176,   191,    29,    40,    41,    61,    62,    64,
      65,    75,    76,    77,    78,    79,    80,    90,    99,   100,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   121,    66,    66,    66,   209,
     213,    65,    76,   209,   212,    65,    76,   201,   209,    65,
     216,    63,    65,   204,   206,   208,    65,   130,   203,   206,
      37,    91,    92,   187,   176,   192,    92,   188,   176,   193,
      92,   189,   176,   194,    92,   190,   176,   195,   128,   130,
     135,   137,   138,   139,   141,   145,   148,   149,   150,   151,
     152,    73,   158,   159,   164,    73,    73,   175,    64,    66,
     127,   128,   129,   130,   136,   137,   160,   161,   162,   163,
      71,    76,   119,    70,   209,   209,   124,   196,   175,    65,
     105,    65,   105,   105,   121,   128,   130,   137,   141,   165,
      61,    40,    41,    65,    70,   101,   102,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    88,   120,   105,
     107,    76,    81,    82,    77,    78,    42,    43,    44,    45,
      83,    84,    46,    47,    75,    85,    86,    48,    49,    87,
      66,    69,   216,   216,   212,   130,    92,    65,    65,   130,
      92,   208,    66,    66,   216,   208,    65,   203,   206,    65,
      88,   166,   175,   197,   175,   166,   175,   198,   175,   166,
     175,   199,   175,   166,   175,   200,   175,    68,   153,   155,
     201,   145,   133,    74,   150,    67,    67,    69,   148,    69,
     172,    88,   158,     7,    10,    11,    17,    23,    24,    27,
      28,    31,    32,    34,    37,    63,    64,    74,    94,   121,
     123,   164,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    65,    76,   203,   209,   215,   216,   218,   219,   203,
     209,   215,    65,    76,   209,   215,   209,   215,    66,    69,
      66,    69,    71,    71,    76,   119,   175,   165,   165,    66,
      65,    76,   215,   215,    66,    66,   104,   119,   121,    72,
      39,   119,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   110,   110,   111,   111,   112,   113,   114,   115,   116,
     121,    67,   119,   166,    65,   166,    66,   216,   216,    66,
      66,   208,    90,    73,   119,   167,   175,   175,   175,   175,
     118,   122,   154,   155,   153,    74,   159,    74,   122,   172,
      67,    65,   122,   123,    67,    65,    68,   164,   173,    65,
      65,   130,   131,    67,    68,    74,   177,    74,   173,   216,
     218,   219,   130,   215,   130,    50,   162,    64,    71,    71,
      66,    66,   130,    73,   107,    66,    69,    71,    63,    64,
     103,   103,    68,    66,    66,    70,    72,    74,   168,   169,
     170,   171,    74,   121,    68,    67,   123,   173,    67,    34,
     121,   121,    65,   173,    74,    66,    66,    66,   215,   168,
     119,   118,   122,   164,    69,   172,   167,    88,   171,    66,
     173,    67,    65,    66,    66,   121,   216,   172,    71,   169,
      74,   173,   123,   121,   173,   173,    66,    68,    74,   167,
      67,    66,     8,    67,    61,    70,    95,    96,    97,   123,
      67,   173,    65,    64,    66,    68,    69,    66,   121,    71,
      67,    95,    97,   173,    66,    61,    66,    68,    65,    67,
      90,    98,   121,    66,    69,    66,    67,    90
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror (_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, _("Stack now"));
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, _("Reducing stack by rule %d (line %u), "),
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      case 64: /* "IDENTIFIER" */
#line 438 "ctlib/parser.y"
        {
  if ((yyvaluep->identifier))
    fprintf(yyoutput, "'%s' len=%d, hash=0x%lx", (yyvaluep->identifier)->key, (yyvaluep->identifier)->keylen, (unsigned long)(yyvaluep->identifier)->hash);
  else
    fprintf(yyoutput, "NULL");
};
#line 2104 "ctlib/parser.c"
        break;
      case 153: /* "member_declarator" */
#line 533 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2128 "ctlib/parser.c"
        break;
      case 164: /* "identifier_or_typedef_name" */
#line 439 "ctlib/parser.y"
        {
  if ((yyvaluep->identifier))
    fprintf(yyoutput, "'%s' len=%d, hash=0x%lx", (yyvaluep->identifier)->key, (yyvaluep->identifier)->keylen, (unsigned long)(yyvaluep->identifier)->hash);
  else
    fprintf(yyoutput, "NULL");
};
#line 2138 "ctlib/parser.c"
        break;
      case 201: /* "declarator" */
#line 532 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2162 "ctlib/parser.c"
        break;
      case 202: /* "typedef_declarator" */
#line 535 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2186 "ctlib/parser.c"
        break;
      case 203: /* "parameter_typedef_declarator" */
#line 534 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2210 "ctlib/parser.c"
        break;
      case 204: /* "clean_typedef_declarator" */
#line 537 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2234 "ctlib/parser.c"
        break;
      case 205: /* "clean_postfix_typedef_declarator" */
#line 538 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2258 "ctlib/parser.c"
        break;
      case 206: /* "paren_typedef_declarator" */
#line 536 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2282 "ctlib/parser.c"
        break;
      case 207: /* "paren_postfix_typedef_declarator" */
#line 539 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2306 "ctlib/parser.c"
        break;
      case 208: /* "simple_paren_typedef_declarator" */
#line 540 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2330 "ctlib/parser.c"
        break;
      case 209: /* "identifier_declarator" */
#line 531 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2354 "ctlib/parser.c"
        break;
      case 210: /* "unary_identifier_declarator" */
#line 541 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2378 "ctlib/parser.c"
        break;
      case 211: /* "postfix_identifier_declarator" */
#line 543 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2402 "ctlib/parser.c"
        break;
      case 212: /* "paren_identifier_declarator" */
#line 542 "ctlib/parser.y"
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
        Value *pValue;
        LL_foreach(pValue, (yyvaluep->pDecl)->ext.array)
          fprintf(yyoutput, "[%ld]", pValue->iv);
      }
    }
  }
  else
    fprintf(yyoutput, "NULL");
};
#line 2426 "ctlib/parser.c"
        break;
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 64: /* "IDENTIFIER" */
#line 424 "ctlib/parser.y"
        {
  if ((yyvaluep->identifier))
  {
    CT_DEBUG(PARSER, ("deleting node @ %p", (yyvaluep->identifier)));
    HN_delete((yyvaluep->identifier));
  }
};
#line 2468 "ctlib/parser.c"
        break;
      case 148: /* "member_declaration_list_opt" */
#line 569 "ctlib/parser.y"
        {
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) structdecl_delete);
  }
};
#line 2479 "ctlib/parser.c"
        break;
      case 149: /* "member_declaration_list" */
#line 569 "ctlib/parser.y"
        {
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) structdecl_delete);
  }
};
#line 2490 "ctlib/parser.c"
        break;
      case 150: /* "member_declaration" */
#line 468 "ctlib/parser.y"
        {
  if ((yyvaluep->pStructDecl))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration @ %p", (yyvaluep->pStructDecl)));
    structdecl_delete((yyvaluep->pStructDecl));
  }
};
#line 2501 "ctlib/parser.c"
        break;
      case 151: /* "unnamed_su_declaration" */
#line 468 "ctlib/parser.y"
        {
  if ((yyvaluep->pStructDecl))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration @ %p", (yyvaluep->pStructDecl)));
    structdecl_delete((yyvaluep->pStructDecl));
  }
};
#line 2512 "ctlib/parser.c"
        break;
      case 152: /* "member_declaring_list" */
#line 468 "ctlib/parser.y"
        {
  if ((yyvaluep->pStructDecl))
  {
    CT_DEBUG(PARSER, ("deleting struct declaration @ %p", (yyvaluep->pStructDecl)));
    structdecl_delete((yyvaluep->pStructDecl));
  }
};
#line 2523 "ctlib/parser.c"
        break;
      case 153: /* "member_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2534 "ctlib/parser.c"
        break;
      case 158: /* "enumerator_list" */
#line 552 "ctlib/parser.y"
        {
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting enumerator list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) enum_delete);
  }
};
#line 2545 "ctlib/parser.c"
        break;
      case 164: /* "identifier_or_typedef_name" */
#line 424 "ctlib/parser.y"
        {
  if ((yyvaluep->identifier))
  {
    CT_DEBUG(PARSER, ("deleting node @ %p", (yyvaluep->identifier)));
    HN_delete((yyvaluep->identifier));
  }
};
#line 2556 "ctlib/parser.c"
        break;
      case 201: /* "declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2567 "ctlib/parser.c"
        break;
      case 202: /* "typedef_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2578 "ctlib/parser.c"
        break;
      case 203: /* "parameter_typedef_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2589 "ctlib/parser.c"
        break;
      case 204: /* "clean_typedef_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2600 "ctlib/parser.c"
        break;
      case 205: /* "clean_postfix_typedef_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2611 "ctlib/parser.c"
        break;
      case 206: /* "paren_typedef_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2622 "ctlib/parser.c"
        break;
      case 207: /* "paren_postfix_typedef_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2633 "ctlib/parser.c"
        break;
      case 208: /* "simple_paren_typedef_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2644 "ctlib/parser.c"
        break;
      case 209: /* "identifier_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2655 "ctlib/parser.c"
        break;
      case 210: /* "unary_identifier_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2666 "ctlib/parser.c"
        break;
      case 211: /* "postfix_identifier_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2677 "ctlib/parser.c"
        break;
      case 212: /* "paren_identifier_declarator" */
#line 492 "ctlib/parser.y"
        {
  if ((yyvaluep->pDecl))
  {
    CT_DEBUG(PARSER, ("deleting declarator @ %p", (yyvaluep->pDecl)));
    decl_delete((yyvaluep->pDecl));
  }
};
#line 2688 "ctlib/parser.c"
        break;
      case 216: /* "postfixing_abstract_declarator" */
#line 560 "ctlib/parser.y"
        {
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting array list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) value_delete);
  }
};
#line 2699 "ctlib/parser.c"
        break;
      case 217: /* "array_abstract_declarator" */
#line 560 "ctlib/parser.y"
        {
  if ((yyvaluep->list))
  {
    CT_DEBUG(PARSER, ("deleting array list @ %p", (yyvaluep->list)));
    LL_destroy((yyvaluep->list), (LLDestroyFunc) value_delete);
  }
};
#line 2710 "ctlib/parser.c"
        break;

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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


  yyvsp[0] = yylval;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (_("parser stack overflow"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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


      YYDPRINTF ((stderr, _("Stack size increased to %lu\n"),
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, _("Entering state %d\n"), yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, _("Reading a token: ")));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, _("Now at end of input.\n")));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT (_("Next token is"), yytoken, &yylval, &yylloc);
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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT (_("Shifting"), yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 627 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-1].value), +, (yyvsp[0].value)); ;}
    break;

  case 20:
#line 682 "ctlib/parser.y"
    {
	    if ((yyvsp[0].identifier))
	      HN_delete((yyvsp[0].identifier));
	    UNDEF_VAL((yyval.value));
	  ;}
    break;

  case 22:
#line 688 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[0].value); (yyval.value).iv++; ;}
    break;

  case 23:
#line 689 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[-1].value); ;}
    break;

  case 25:
#line 694 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 26:
#line 695 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 27:
#line 696 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 28:
#line 697 "ctlib/parser.y"
    {;}
    break;

  case 29:
#line 697 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 30:
#line 698 "ctlib/parser.y"
    {;}
    break;

  case 31:
#line 698 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 32:
#line 699 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 33:
#line 700 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 34:
#line 701 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 35:
#line 705 "ctlib/parser.y"
    { if((yyvsp[0].identifier)) HN_delete((yyvsp[0].identifier)); ;}
    break;

  case 36:
#line 706 "ctlib/parser.y"
    {;}
    break;

  case 37:
#line 710 "ctlib/parser.y"
    {;}
    break;

  case 38:
#line 711 "ctlib/parser.y"
    {;}
    break;

  case 40:
#line 716 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 41:
#line 717 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 42:
#line 719 "ctlib/parser.y"
    {
	    switch( (yyvsp[-1].oper) ) {
	      case '-' : UNARY_OP((yyval.value), -, (yyvsp[0].value)); break;
	      case '~' : UNARY_OP((yyval.value), ~, (yyvsp[0].value)); break;
	      case '!' : UNARY_OP((yyval.value), !, (yyvsp[0].value)); break;
	      case '+' : (yyval.value) = (yyvsp[0].value);             break;

	      case '*' :
	      case '&' :
	        (yyval.value) = (yyvsp[0].value); (yyval.value).flags |= V_IS_UNSAFE_PTROP;
	        break;

	      default:
	        UNDEF_VAL((yyval.value));
	        break;
	    }
	  ;}
    break;

  case 43:
#line 736 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[0].value); ;}
    break;

  case 44:
#line 737 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[-1].value); ;}
    break;

  case 45:
#line 741 "ctlib/parser.y"
    { (yyval.oper) = '&'; ;}
    break;

  case 46:
#line 742 "ctlib/parser.y"
    { (yyval.oper) = '*'; ;}
    break;

  case 47:
#line 743 "ctlib/parser.y"
    { (yyval.oper) = '+'; ;}
    break;

  case 48:
#line 744 "ctlib/parser.y"
    { (yyval.oper) = '-'; ;}
    break;

  case 49:
#line 745 "ctlib/parser.y"
    { (yyval.oper) = '~'; ;}
    break;

  case 50:
#line 746 "ctlib/parser.y"
    { (yyval.oper) = '!'; ;}
    break;

  case 52:
#line 751 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[0].value); (yyval.value).flags |= V_IS_UNSAFE_CAST; ;}
    break;

  case 54:
#line 757 "ctlib/parser.y"
    { BINARY_OP( (yyval.value), (yyvsp[-2].value), *, (yyvsp[0].value) ); ;}
    break;

  case 55:
#line 759 "ctlib/parser.y"
    {
	    if ((yyvsp[0].value).iv == 0)
	      UNDEF_VAL((yyval.value));
	    else
	      BINARY_OP((yyval.value), (yyvsp[-2].value), /, (yyvsp[0].value));
	  ;}
    break;

  case 56:
#line 766 "ctlib/parser.y"
    {
	    if ((yyvsp[0].value).iv == 0)
	      UNDEF_VAL((yyval.value));
	    else
	      BINARY_OP((yyval.value), (yyvsp[-2].value), %, (yyvsp[0].value));
	  ;}
    break;

  case 58:
#line 777 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), +, (yyvsp[0].value)); ;}
    break;

  case 59:
#line 779 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), -, (yyvsp[0].value)); ;}
    break;

  case 61:
#line 785 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), <<, (yyvsp[0].value)); ;}
    break;

  case 62:
#line 787 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), >>, (yyvsp[0].value)); ;}
    break;

  case 64:
#line 793 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), <,  (yyvsp[0].value)); ;}
    break;

  case 65:
#line 795 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), >,  (yyvsp[0].value)); ;}
    break;

  case 66:
#line 797 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), <=, (yyvsp[0].value)); ;}
    break;

  case 67:
#line 799 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), >=, (yyvsp[0].value)); ;}
    break;

  case 69:
#line 805 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), ==, (yyvsp[0].value)); ;}
    break;

  case 70:
#line 807 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), !=, (yyvsp[0].value)); ;}
    break;

  case 72:
#line 813 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), &, (yyvsp[0].value)); ;}
    break;

  case 74:
#line 819 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), ^, (yyvsp[0].value)); ;}
    break;

  case 76:
#line 825 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), |, (yyvsp[0].value)); ;}
    break;

  case 78:
#line 831 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), &&, (yyvsp[0].value)); ;}
    break;

  case 80:
#line 837 "ctlib/parser.y"
    { BINARY_OP((yyval.value), (yyvsp[-2].value), ||, (yyvsp[0].value)); ;}
    break;

  case 82:
#line 843 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[-4].value).iv ? (yyvsp[-2].value) : (yyvsp[0].value); (yyval.value).flags |= (yyvsp[-4].value).flags; ;}
    break;

  case 84:
#line 848 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 85:
#line 852 "ctlib/parser.y"
    {;}
    break;

  case 86:
#line 853 "ctlib/parser.y"
    {;}
    break;

  case 87:
#line 854 "ctlib/parser.y"
    {;}
    break;

  case 88:
#line 855 "ctlib/parser.y"
    {;}
    break;

  case 89:
#line 856 "ctlib/parser.y"
    {;}
    break;

  case 90:
#line 857 "ctlib/parser.y"
    {;}
    break;

  case 91:
#line 858 "ctlib/parser.y"
    {;}
    break;

  case 92:
#line 859 "ctlib/parser.y"
    {;}
    break;

  case 93:
#line 860 "ctlib/parser.y"
    {;}
    break;

  case 94:
#line 861 "ctlib/parser.y"
    {;}
    break;

  case 95:
#line 862 "ctlib/parser.y"
    {;}
    break;

  case 97:
#line 867 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[0].value); ;}
    break;

  case 100:
#line 877 "ctlib/parser.y"
    {;}
    break;

  case 101:
#line 915 "ctlib/parser.y"
    {;}
    break;

  case 102:
#line 916 "ctlib/parser.y"
    {;}
    break;

  case 103:
#line 917 "ctlib/parser.y"
    {;}
    break;

  case 104:
#line 918 "ctlib/parser.y"
    {;}
    break;

  case 105:
#line 926 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pTypedefList) = NULL;
	    else
	    {
	      if ((yyvsp[-3].uval) & T_TYPEDEF)
	      {
	        TypeSpec ts;
	        ts.tflags = (yyvsp[-3].uval);
	        ts.ptr    = NULL;
	        if ((ts.tflags & ANY_TYPE_NAME) == 0)
	          ts.tflags |= T_INT;
	        (yyval.pTypedefList) = typedef_list_new(ts, LL_new());
	        LL_push(PSTATE->pCPI->typedef_lists, (yyval.pTypedefList));
	        MAKE_TYPEDEF((yyval.pTypedefList), (yyvsp[-2].pDecl));
	      }
	      else
	      {
	        (yyval.pTypedefList) = NULL;
	        decl_delete((yyvsp[-2].pDecl));
	      }
	    }
	  ;}
    break;

  case 106:
#line 950 "ctlib/parser.y"
    {
	    (yyval.pTypedefList) = NULL;
	    if ((yyvsp[-2].pDecl))
	      decl_delete((yyvsp[-2].pDecl));
	  ;}
    break;

  case 107:
#line 956 "ctlib/parser.y"
    {
	    (yyval.pTypedefList) = (yyvsp[-4].pTypedefList);
	    if ((yyval.pTypedefList))
	      MAKE_TYPEDEF((yyval.pTypedefList), (yyvsp[-2].pDecl));
	    else if((yyvsp[-2].pDecl))
	      decl_delete((yyvsp[-2].pDecl));
	  ;}
    break;

  case 108:
#line 967 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pTypedefList) = NULL;
	    else
	    {
	      if ((yyvsp[-3].tspec).tflags & T_TYPEDEF)
	      {
	        if (((yyvsp[-3].tspec).tflags & ANY_TYPE_NAME) == 0)
	          (yyvsp[-3].tspec).tflags |= T_INT;
	        ctt_refcount_inc((yyvsp[-3].tspec).ptr);
	        (yyval.pTypedefList) = typedef_list_new((yyvsp[-3].tspec), LL_new());
	        LL_push(PSTATE->pCPI->typedef_lists, (yyval.pTypedefList));
	        MAKE_TYPEDEF((yyval.pTypedefList), (yyvsp[-2].pDecl));
	      }
	      else
	      {
	        (yyval.pTypedefList) = NULL;
	        decl_delete((yyvsp[-2].pDecl));
	      }
	    }
	  ;}
    break;

  case 109:
#line 989 "ctlib/parser.y"
    {
	    (yyval.pTypedefList) = NULL;
	    if ((yyvsp[-2].pDecl))
	      decl_delete((yyvsp[-2].pDecl));
	  ;}
    break;

  case 110:
#line 995 "ctlib/parser.y"
    {
	    (yyval.pTypedefList) = (yyvsp[-4].pTypedefList);
	    if ((yyval.pTypedefList))
	      MAKE_TYPEDEF((yyval.pTypedefList), (yyvsp[-2].pDecl));
	    else if ((yyvsp[-2].pDecl))
	      decl_delete((yyvsp[-2].pDecl));
	  ;}
    break;

  case 111:
#line 1007 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = NULL;
	    (yyval.tspec).tflags = (yyvsp[0].uval);
	  ;}
    break;

  case 114:
#line 1018 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = NULL;
	    (yyval.tspec).tflags = (yyvsp[0].uval);
	  ;}
    break;

  case 118:
#line 1030 "ctlib/parser.y"
    { (yyval.uval) = (yyvsp[0].uval);      ;}
    break;

  case 119:
#line 1031 "ctlib/parser.y"
    { (yyval.uval) = (yyvsp[-1].uval) | (yyvsp[0].uval); ;}
    break;

  case 125:
#line 1046 "ctlib/parser.y"
    { (yyval.uval) = 0;  ;}
    break;

  case 129:
#line 1056 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[-1].uval), (yyvsp[0].uval)); ;}
    break;

  case 130:
#line 1057 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[-1].uval), (yyvsp[0].uval)); ;}
    break;

  case 131:
#line 1058 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[-1].uval), (yyvsp[0].uval)); ;}
    break;

  case 132:
#line 1059 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[-1].uval), (yyvsp[0].uval)); ;}
    break;

  case 134:
#line 1064 "ctlib/parser.y"
    { (yyval.uval) = (yyvsp[0].uval);             ;}
    break;

  case 135:
#line 1065 "ctlib/parser.y"
    { (yyval.uval) = (yyvsp[-1].uval);             ;}
    break;

  case 136:
#line 1066 "ctlib/parser.y"
    { (yyval.uval) = LLC_OR((yyvsp[-1].uval), (yyvsp[0].uval)); ;}
    break;

  case 137:
#line 1071 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[0].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[0].tspec).tflags | (yyvsp[-1].uval);
	  ;}
    break;

  case 138:
#line 1076 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[-1].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[-1].tspec).tflags | (yyvsp[0].uval);
	  ;}
    break;

  case 139:
#line 1081 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[-1].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[-1].tspec).tflags | (yyvsp[0].uval);
	  ;}
    break;

  case 141:
#line 1089 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[0].tspec); ;}
    break;

  case 142:
#line 1090 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[-1].tspec); ;}
    break;

  case 144:
#line 1095 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[0].tspec); ;}
    break;

  case 145:
#line 1096 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[-1].tspec); ;}
    break;

  case 148:
#line 1105 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[-1].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[-1].tspec).tflags | (yyvsp[0].uval);
	  ;}
    break;

  case 149:
#line 1110 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[0].pTypedef);
	    (yyval.tspec).tflags = T_TYPE | (yyvsp[-1].uval);
	  ;}
    break;

  case 150:
#line 1115 "ctlib/parser.y"
    {
	    (yyval.tspec).ptr    = (yyvsp[-1].tspec).ptr;
	    (yyval.tspec).tflags = (yyvsp[-1].tspec).tflags | (yyvsp[0].uval);
	  ;}
    break;

  case 151:
#line 1122 "ctlib/parser.y"
    { (yyval.tspec).ptr = (yyvsp[0].pTypedef); (yyval.tspec).tflags = T_TYPE; ;}
    break;

  case 152:
#line 1123 "ctlib/parser.y"
    { (yyval.tspec).ptr = (yyvsp[0].pTypedef); (yyval.tspec).tflags = T_TYPE; ;}
    break;

  case 153:
#line 1124 "ctlib/parser.y"
    { (yyval.tspec) = (yyvsp[-1].tspec);                         ;}
    break;

  case 154:
#line 1128 "ctlib/parser.y"
    { (yyval.uval) = T_TYPEDEF;  ;}
    break;

  case 155:
#line 1129 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 156:
#line 1130 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 157:
#line 1131 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 158:
#line 1132 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 159:
#line 1133 "ctlib/parser.y"
    { (yyval.uval) = 0;          ;}
    break;

  case 160:
#line 1137 "ctlib/parser.y"
    { (yyval.uval) = T_INT;      ;}
    break;

  case 161:
#line 1138 "ctlib/parser.y"
    { (yyval.uval) = T_CHAR;     ;}
    break;

  case 162:
#line 1139 "ctlib/parser.y"
    { (yyval.uval) = T_SHORT;    ;}
    break;

  case 163:
#line 1140 "ctlib/parser.y"
    { (yyval.uval) = T_LONG;     ;}
    break;

  case 164:
#line 1141 "ctlib/parser.y"
    { (yyval.uval) = T_FLOAT;    ;}
    break;

  case 165:
#line 1142 "ctlib/parser.y"
    { (yyval.uval) = T_DOUBLE;   ;}
    break;

  case 166:
#line 1143 "ctlib/parser.y"
    { (yyval.uval) = T_SIGNED;   ;}
    break;

  case 167:
#line 1144 "ctlib/parser.y"
    { (yyval.uval) = T_UNSIGNED; ;}
    break;

  case 168:
#line 1145 "ctlib/parser.y"
    { (yyval.uval) = T_VOID;     ;}
    break;

  case 171:
#line 1155 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	    }
	    else
	    {
	      Struct *pStruct;
	      pStruct = struct_new(NULL, 0, (yyvsp[-3].context).uval, PSTATE->pragma.pack.current, (yyvsp[-1].list));
	      pStruct->context = (yyvsp[-3].context).ctx;
	      LL_push(PSTATE->pCPI->structs, pStruct);
	      (yyval.tspec).tflags = (yyvsp[-3].context).uval;
	      (yyval.tspec).ptr = pStruct;
	    }
	  ;}
    break;

  case 172:
#line 1172 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      Struct *pStruct = HT_get(PSTATE->pCPI->htStructs, (yyvsp[-3].identifier)->key, (yyvsp[-3].identifier)->keylen, (yyvsp[-3].identifier)->hash);

	      if (pStruct == NULL)
	      {
	        pStruct = struct_new((yyvsp[-3].identifier)->key, (yyvsp[-3].identifier)->keylen, (yyvsp[-4].context).uval, PSTATE->pragma.pack.current, (yyvsp[-1].list));
	        pStruct->context = (yyvsp[-4].context).ctx;
	        LL_push(PSTATE->pCPI->structs, pStruct);
	        HT_storenode(PSTATE->pCPI->htStructs, (yyvsp[-3].identifier), pStruct);
	      }
	      else
	      {
	        DELETE_NODE((yyvsp[-3].identifier));

	        if (pStruct->declarations == NULL)
	        {
	          pStruct->context      = (yyvsp[-4].context).ctx;
	          pStruct->declarations = (yyvsp[-1].list);
	          pStruct->pack         = PSTATE->pragma.pack.current;
	        }
	        else
	          LL_destroy((yyvsp[-1].list), (LLDestroyFunc) structdecl_delete);
	      }
	      (yyval.tspec).tflags = (yyvsp[-4].context).uval;
	      (yyval.tspec).ptr = pStruct;
	    }
	  ;}
    break;

  case 173:
#line 1208 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      Struct *pStruct = HT_get(PSTATE->pCPI->htStructs, (yyvsp[0].identifier)->key, (yyvsp[0].identifier)->keylen, (yyvsp[0].identifier)->hash);

	      if (pStruct == NULL)
	      {
	        pStruct = struct_new((yyvsp[0].identifier)->key, (yyvsp[0].identifier)->keylen, (yyvsp[-1].context).uval, 0, NULL);
	        pStruct->context = (yyvsp[-1].context).ctx;
	        LL_push(PSTATE->pCPI->structs, pStruct);
	        HT_storenode(PSTATE->pCPI->htStructs, (yyvsp[0].identifier), pStruct);
	      }
	      else
	        DELETE_NODE((yyvsp[0].identifier));

	      (yyval.tspec).tflags = (yyvsp[-1].context).uval;
	      (yyval.tspec).ptr = pStruct;
	    }
	  ;}
    break;

  case 174:
#line 1237 "ctlib/parser.y"
    {
	    (yyval.context).uval     = (yyvsp[0].uval);
	    (yyval.context).ctx.pFI  = PSTATE->pFI;
	    (yyval.context).ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 175:
#line 1245 "ctlib/parser.y"
    { (yyval.uval) = T_STRUCT; ;}
    break;

  case 176:
#line 1246 "ctlib/parser.y"
    { (yyval.uval) = T_UNION;  ;}
    break;

  case 177:
#line 1250 "ctlib/parser.y"
    { (yyval.list) = IS_LOCAL ? NULL : LL_new(); ;}
    break;

  case 179:
#line 1256 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      ctt_refcount_inc((yyvsp[0].pStructDecl)->type.ptr);
	      (yyval.list) = LL_new();
	      LL_push((yyval.list), (yyvsp[0].pStructDecl));
	    }
	  ;}
    break;

  case 180:
#line 1267 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      ctt_refcount_inc((yyvsp[0].pStructDecl)->type.ptr);
	      (yyval.list) = (yyvsp[-1].list);
	      LL_push((yyval.list), (yyvsp[0].pStructDecl));
	    }
	  ;}
    break;

  case 183:
#line 1285 "ctlib/parser.y"
    { (yyval.pStructDecl) = IS_LOCAL ? NULL : structdecl_new((yyvsp[0].tspec), NULL); ;}
    break;

  case 184:
#line 1290 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pStructDecl) = NULL;
	    else
	    {
	      if (((yyvsp[-1].tspec).tflags & ANY_TYPE_NAME) == 0)
	        (yyvsp[-1].tspec).tflags |= T_INT;
	      (yyval.pStructDecl) = structdecl_new((yyvsp[-1].tspec), LL_new());
	      if ((yyvsp[0].pDecl))
	        LL_push((yyval.pStructDecl)->declarators, (yyvsp[0].pDecl));
	    }
	  ;}
    break;

  case 185:
#line 1303 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pStructDecl) = NULL;
	    else
	    {
	      (yyval.pStructDecl) = (yyvsp[-2].pStructDecl);
	      if ((yyvsp[0].pDecl))
	        LL_push((yyval.pStructDecl)->declarators, (yyvsp[0].pDecl));
	    }
	  ;}
    break;

  case 186:
#line 1317 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pDecl) = NULL;
	    else
	    {
	      (yyval.pDecl) = (yyvsp[-1].pDecl);

	      if (((yyvsp[0].value).flags & V_IS_UNDEF) == 0)
	      {
	        if ((yyvsp[0].value).iv <= 0)
	        {
	          char *msg;
	          AllocF(char *, msg, 80 + CTT_IDLEN((yyvsp[-1].pDecl)));
	          sprintf(msg, "%s width for bit-field '%s'",
	                  (yyvsp[0].value).iv < 0 ? "negative" : "zero", (yyvsp[-1].pDecl)->identifier);
	          decl_delete((yyvsp[-1].pDecl));
	          yyerror(msg);
	          Free(msg);
	          YYERROR;
	        }

	        (yyval.pDecl)->bitfield_flag = 1;
	        (yyval.pDecl)->ext.bitfield.bits = (unsigned char) (yyvsp[0].value).iv;
	      }
	    }
	  ;}
    break;

  case 187:
#line 1344 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pDecl) = NULL;
	    else
	    {
	      if ((yyvsp[0].value).iv < 0)
	      {
	        yyerror("negative width for bit-field");
	        YYERROR;
	      }

	      (yyval.pDecl) = decl_new("", 0);
	      (yyval.pDecl)->bitfield_flag = 1;
	      (yyval.pDecl)->ext.bitfield.bits = (unsigned char) (yyvsp[0].value).iv;
	    }
	  ;}
    break;

  case 188:
#line 1363 "ctlib/parser.y"
    { UNDEF_VAL((yyval.value)); ;}
    break;

  case 190:
#line 1368 "ctlib/parser.y"
    { (yyval.value) = (yyvsp[0].value); ;}
    break;

  case 191:
#line 1373 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      LL_destroy((yyvsp[-2].list), (LLDestroyFunc) enum_delete);
	    }
	    else
	    {
	      EnumSpecifier *pEnum = enumspec_new(NULL, 0, (yyvsp[-2].list));
	      pEnum->context = (yyvsp[-4].context).ctx;
	      LL_push(PSTATE->pCPI->enums, pEnum);
	      (yyval.tspec).tflags = T_ENUM;
	      (yyval.tspec).ptr = pEnum;
	    }
	  ;}
    break;

  case 192:
#line 1390 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      EnumSpecifier *pEnum = HT_get(PSTATE->pCPI->htEnums, (yyvsp[-4].identifier)->key, (yyvsp[-4].identifier)->keylen, (yyvsp[-4].identifier)->hash);

	      if (pEnum == NULL)
	      {
	        pEnum = enumspec_new((yyvsp[-4].identifier)->key, (yyvsp[-4].identifier)->keylen, (yyvsp[-2].list));
	        pEnum->context = (yyvsp[-5].context).ctx;
	        LL_push(PSTATE->pCPI->enums, pEnum);
	        HT_storenode(PSTATE->pCPI->htEnums, (yyvsp[-4].identifier), pEnum);
	      }
	      else
	      {
	        DELETE_NODE((yyvsp[-4].identifier));

	        if (pEnum->enumerators == NULL)
	        {
	          enumspec_update(pEnum, (yyvsp[-2].list));
	          pEnum->context = (yyvsp[-5].context).ctx;
	        }
	        else
	          LL_destroy((yyvsp[-2].list), (LLDestroyFunc) enum_delete);
	      }

	      (yyval.tspec).tflags = T_ENUM;
	      (yyval.tspec).ptr = pEnum;
	    }
	  ;}
    break;

  case 193:
#line 1426 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.tspec).tflags = 0;
	      (yyval.tspec).ptr = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      EnumSpecifier *pEnum = HT_get(PSTATE->pCPI->htEnums, (yyvsp[0].identifier)->key, (yyvsp[0].identifier)->keylen, (yyvsp[0].identifier)->hash);

	      if (pEnum == NULL)
	      {
	        pEnum = enumspec_new((yyvsp[0].identifier)->key, (yyvsp[0].identifier)->keylen, NULL);
	        pEnum->context = (yyvsp[-1].context).ctx;
	        LL_push(PSTATE->pCPI->enums, pEnum);
	        HT_storenode(PSTATE->pCPI->htEnums, (yyvsp[0].identifier), pEnum);
	      }
	      else
	      {
	        DELETE_NODE((yyvsp[0].identifier));
	      }

	      (yyval.tspec).tflags = T_ENUM;
	      (yyval.tspec).ptr = pEnum;
	    }
	  ;}
    break;

  case 194:
#line 1457 "ctlib/parser.y"
    {
	    (yyval.context).ctx.pFI  = PSTATE->pFI;
	    (yyval.context).ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 195:
#line 1465 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = LL_new();
	      if ((yyvsp[0].pEnum)->value.flags & V_IS_UNDEF)
	      {
	        (yyvsp[0].pEnum)->value.flags &= ~V_IS_UNDEF;
	        (yyvsp[0].pEnum)->value.iv     = 0;
	      }
	      LL_push((yyval.list), (yyvsp[0].pEnum));
	    }
	  ;}
    break;

  case 196:
#line 1480 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      if ((yyvsp[0].pEnum)->value.flags & V_IS_UNDEF)
	      {
	        Enumerator *pEnum = LL_get((yyvsp[-2].list), -1);
	        (yyvsp[0].pEnum)->value.flags = pEnum->value.flags;
	        (yyvsp[0].pEnum)->value.iv    = pEnum->value.iv + 1;
	      }
	      LL_push((yyvsp[-2].list), (yyvsp[0].pEnum));
	      (yyval.list) = (yyvsp[-2].list);
	    }
	  ;}
    break;

  case 197:
#line 1499 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.pEnum) = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      (yyval.pEnum) = enum_new((yyvsp[0].identifier)->key, (yyvsp[0].identifier)->keylen, NULL);
	      HT_storenode(PSTATE->pCPI->htEnumerators, (yyvsp[0].identifier), (yyval.pEnum));
	    }
	  ;}
    break;

  case 198:
#line 1512 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	    {
	      (yyval.pEnum) = NULL;
	      /* identifier_or_typedef_name is NULL */
	    }
	    else
	    {
	      (yyval.pEnum) = enum_new((yyvsp[-2].identifier)->key, (yyvsp[-2].identifier)->keylen, &(yyvsp[0].value));
	      HT_storenode(PSTATE->pCPI->htEnumerators, (yyvsp[-2].identifier), (yyval.pEnum));
	    }
	  ;}
    break;

  case 203:
#line 1537 "ctlib/parser.y"
    {;}
    break;

  case 204:
#line 1538 "ctlib/parser.y"
    {;}
    break;

  case 205:
#line 1539 "ctlib/parser.y"
    { if ((yyvsp[0].pDecl)) decl_delete((yyvsp[0].pDecl)); ;}
    break;

  case 206:
#line 1540 "ctlib/parser.y"
    { if ((yyvsp[0].pDecl)) decl_delete((yyvsp[0].pDecl)); ;}
    break;

  case 207:
#line 1541 "ctlib/parser.y"
    {;}
    break;

  case 208:
#line 1542 "ctlib/parser.y"
    {;}
    break;

  case 209:
#line 1543 "ctlib/parser.y"
    { if ((yyvsp[0].pDecl)) decl_delete((yyvsp[0].pDecl)); ;}
    break;

  case 210:
#line 1544 "ctlib/parser.y"
    {;}
    break;

  case 211:
#line 1545 "ctlib/parser.y"
    {;}
    break;

  case 212:
#line 1546 "ctlib/parser.y"
    { if ((yyvsp[0].pDecl)) decl_delete((yyvsp[0].pDecl)); ;}
    break;

  case 213:
#line 1547 "ctlib/parser.y"
    { if ((yyvsp[0].pDecl)) decl_delete((yyvsp[0].pDecl)); ;}
    break;

  case 214:
#line 1548 "ctlib/parser.y"
    {;}
    break;

  case 215:
#line 1549 "ctlib/parser.y"
    {;}
    break;

  case 216:
#line 1550 "ctlib/parser.y"
    { if ((yyvsp[0].pDecl)) decl_delete((yyvsp[0].pDecl)); ;}
    break;

  case 217:
#line 1558 "ctlib/parser.y"
    { if ((yyvsp[0].identifier)) HN_delete((yyvsp[0].identifier)); ;}
    break;

  case 218:
#line 1559 "ctlib/parser.y"
    { if ((yyvsp[0].identifier)) HN_delete((yyvsp[0].identifier)); ;}
    break;

  case 220:
#line 1565 "ctlib/parser.y"
    {
	    (yyval.identifier) = IS_LOCAL ? NULL : HN_new((yyvsp[0].pTypedef)->pDecl->identifier, CTT_IDLEN((yyvsp[0].pTypedef)->pDecl), 0);
	  ;}
    break;

  case 221:
#line 1572 "ctlib/parser.y"
    {
	    if (!IS_LOCAL)
	    {
	      unsigned size;
	      u_32 flags;
	      (void) PSTATE->pCPC->get_type_info(&PSTATE->pCPC->layout, &(yyvsp[0].tspec), NULL, "sf", &size, &flags);
	      (yyval.value).iv    = size;
	      (yyval.value).flags = 0;
	      if (flags & T_UNSAFE_VAL)
	        (yyval.value).flags |= V_IS_UNSAFE;
	    }
	  ;}
    break;

  case 222:
#line 1585 "ctlib/parser.y"
    {
	    if (!IS_LOCAL)
	    {
	      if ((yyvsp[0].absDecl).pointer_flag)
	      {
	        (yyval.value).iv = PSTATE->pCPC->layout.ptr_size * (yyvsp[0].absDecl).multiplicator;
	        (yyval.value).flags = 0;
	      }
	      else
	      {
	        unsigned size;
	        u_32 flags;
	        (void) PSTATE->pCPC->get_type_info(&PSTATE->pCPC->layout, &(yyvsp[-1].tspec), NULL, "sf", &size, &flags);
	        (yyval.value).iv = size * (yyvsp[0].absDecl).multiplicator;
	        (yyval.value).flags = 0;
	        if (flags & T_UNSAFE_VAL)
	          (yyval.value).flags |= V_IS_UNSAFE;
	      }
	    }
	  ;}
    break;

  case 223:
#line 1606 "ctlib/parser.y"
    {
	    if (!IS_LOCAL)
	    {
	      (yyval.value).iv = PSTATE->pCPC->layout.int_size;
	      (yyval.value).flags = 0;
	    }
	  ;}
    break;

  case 224:
#line 1614 "ctlib/parser.y"
    {
	    if (!IS_LOCAL)
	    {
	      (yyval.value).iv = (yyvsp[0].absDecl).multiplicator * ((yyvsp[0].absDecl).pointer_flag ?
	              PSTATE->pCPC->layout.ptr_size : PSTATE->pCPC->layout.int_size);
	      (yyval.value).flags = 0;
	    }
	  ;}
    break;

  case 229:
#line 1632 "ctlib/parser.y"
    {;}
    break;

  case 237:
#line 1652 "ctlib/parser.y"
    { DELETE_NODE((yyvsp[0].identifier)); ;}
    break;

  case 247:
#line 1672 "ctlib/parser.y"
    { DELETE_NODE((yyvsp[-2].identifier)); ;}
    break;

  case 265:
#line 1711 "ctlib/parser.y"
    { DELETE_NODE((yyvsp[-1].identifier)); ;}
    break;

  case 276:
#line 1737 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 277:
#line 1738 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[-2].pDecl)); ;}
    break;

  case 278:
#line 1739 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 279:
#line 1740 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[-2].pDecl)); ;}
    break;

  case 280:
#line 1741 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 281:
#line 1742 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[-2].pDecl)); ;}
    break;

  case 282:
#line 1743 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 283:
#line 1744 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[-2].pDecl)); ;}
    break;

  case 284:
#line 1745 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 285:
#line 1746 "ctlib/parser.y"
    { END_LOCAL; decl_delete((yyvsp[-2].pDecl)); ;}
    break;

  case 286:
#line 1748 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 287:
#line 1748 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 288:
#line 1749 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 289:
#line 1749 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 290:
#line 1750 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 291:
#line 1750 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 292:
#line 1751 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 293:
#line 1751 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 294:
#line 1752 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 295:
#line 1752 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 296:
#line 1754 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 297:
#line 1754 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 298:
#line 1755 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 299:
#line 1755 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 300:
#line 1756 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 301:
#line 1756 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 302:
#line 1757 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 303:
#line 1757 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 304:
#line 1758 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 305:
#line 1758 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 310:
#line 1773 "ctlib/parser.y"
    {
	    (yyval.pDecl) = IS_LOCAL ? NULL : decl_new((yyvsp[0].pTypedef)->pDecl->identifier, CTT_IDLEN((yyvsp[0].pTypedef)->pDecl));
	  ;}
    break;

  case 311:
#line 1777 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.pDecl) = NULL;
	    else
	    {
	      (yyval.pDecl) = decl_new((yyvsp[-1].pTypedef)->pDecl->identifier, CTT_IDLEN((yyvsp[-1].pTypedef)->pDecl));
	      if ((yyvsp[0].list))
	      {
	        (yyval.pDecl)->array_flag = 1;
	        (yyval.pDecl)->ext.array = (yyvsp[0].list);
	      }
	    }
	  ;}
    break;

  case 314:
#line 1799 "ctlib/parser.y"
    {
	    if ((yyvsp[0].pDecl))
	      (yyvsp[0].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[0].pDecl);
	  ;}
    break;

  case 315:
#line 1805 "ctlib/parser.y"
    {
	    if ((yyvsp[0].pDecl))
	      (yyvsp[0].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[0].pDecl);
	  ;}
    break;

  case 316:
#line 1813 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[-1].pDecl); ;}
    break;

  case 317:
#line 1815 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[-2].pDecl), (yyvsp[0].list));
	    (yyval.pDecl) = (yyvsp[-2].pDecl);
	  ;}
    break;

  case 319:
#line 1827 "ctlib/parser.y"
    {
	    if ((yyvsp[-1].pDecl))
	      (yyvsp[-1].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[-1].pDecl);
	  ;}
    break;

  case 320:
#line 1833 "ctlib/parser.y"
    {
	    if ((yyvsp[-1].pDecl))
	      (yyvsp[-1].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[-1].pDecl);
	  ;}
    break;

  case 321:
#line 1839 "ctlib/parser.y"
    {
	    if ((yyvsp[0].pDecl))
	      (yyvsp[0].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[0].pDecl);
	  ;}
    break;

  case 322:
#line 1845 "ctlib/parser.y"
    {
	    if ((yyvsp[0].pDecl))
	      (yyvsp[0].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[0].pDecl);
	  ;}
    break;

  case 323:
#line 1853 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[-1].pDecl); ;}
    break;

  case 324:
#line 1855 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[-2].pDecl), (yyvsp[-1].list));
	    (yyval.pDecl) = (yyvsp[-2].pDecl);
	  ;}
    break;

  case 325:
#line 1860 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[-2].pDecl), (yyvsp[0].list));
	    (yyval.pDecl) = (yyvsp[-2].pDecl);
	  ;}
    break;

  case 326:
#line 1868 "ctlib/parser.y"
    {
	    (yyval.pDecl) = IS_LOCAL ? NULL : decl_new((yyvsp[0].pTypedef)->pDecl->identifier, CTT_IDLEN((yyvsp[0].pTypedef)->pDecl));
	  ;}
    break;

  case 327:
#line 1871 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[-1].pDecl); ;}
    break;

  case 331:
#line 1882 "ctlib/parser.y"
    {
	    if ((yyvsp[0].pDecl))
	      (yyvsp[0].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[0].pDecl);
	  ;}
    break;

  case 332:
#line 1888 "ctlib/parser.y"
    {
	    if ((yyvsp[0].pDecl))
	      (yyvsp[0].pDecl)->pointer_flag = 1;
	    (yyval.pDecl) = (yyvsp[0].pDecl);
	  ;}
    break;

  case 333:
#line 1897 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[-1].pDecl), (yyvsp[0].list));
	    (yyval.pDecl) = (yyvsp[-1].pDecl);
	  ;}
    break;

  case 334:
#line 1901 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[-1].pDecl); ;}
    break;

  case 335:
#line 1903 "ctlib/parser.y"
    {
	    POSTFIX_DECL((yyvsp[-2].pDecl), (yyvsp[0].list));
	    (yyval.pDecl) = (yyvsp[-2].pDecl);
	  ;}
    break;

  case 336:
#line 1911 "ctlib/parser.y"
    {
	    if ((yyvsp[0].identifier))
	    {
	      (yyval.pDecl) = decl_new((yyvsp[0].identifier)->key, (yyvsp[0].identifier)->keylen);
	      HN_delete((yyvsp[0].identifier));
	    }
	    else
	    {
	      (yyval.pDecl) = NULL;
	    }
	  ;}
    break;

  case 337:
#line 1922 "ctlib/parser.y"
    { (yyval.pDecl) = (yyvsp[-1].pDecl); ;}
    break;

  case 338:
#line 1926 "ctlib/parser.y"
    {;}
    break;

  case 339:
#line 1927 "ctlib/parser.y"
    {;}
    break;

  case 340:
#line 1928 "ctlib/parser.y"
    {;}
    break;

  case 341:
#line 1933 "ctlib/parser.y"
    {
	    if ((yyvsp[-3].pDecl))
	      decl_delete((yyvsp[-3].pDecl));
	  ;}
    break;

  case 342:
#line 1937 "ctlib/parser.y"
    {;}
    break;

  case 343:
#line 1939 "ctlib/parser.y"
    {
	    if ((yyvsp[0].list))
	      LL_destroy((yyvsp[0].list), (LLDestroyFunc) value_delete);
	  ;}
    break;

  case 346:
#line 1949 "ctlib/parser.y"
    {
	    (yyval.absDecl).pointer_flag  = 0;
	    (yyval.absDecl).multiplicator = 1;
	    if ((yyvsp[0].list))
	    {
	      Value *pValue;
	      LL_foreach(pValue, (yyvsp[0].list))
	        (yyval.absDecl).multiplicator *= pValue->iv;
	      LL_destroy((yyvsp[0].list), (LLDestroyFunc) value_delete);
	    }
	  ;}
    break;

  case 348:
#line 1964 "ctlib/parser.y"
    { (yyval.list) = NULL; ;}
    break;

  case 349:
#line 1965 "ctlib/parser.y"
    { (yyval.list) = NULL; ;}
    break;

  case 350:
#line 1970 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = LL_new();
	      LL_push((yyval.list), value_new(0, V_IS_UNDEF));
	      CT_DEBUG(PARSER, ("array dimension => flexible array member"));
	    }
	  ;}
    break;

  case 351:
#line 1981 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = LL_new();
	      LL_push((yyval.list), value_new((yyvsp[-1].value).iv, (yyvsp[-1].value).flags));
	      CT_DEBUG(PARSER, ("array dimension => %ld", (yyvsp[-1].value).iv));
	    }
	  ;}
    break;

  case 352:
#line 1991 "ctlib/parser.y"
    { (yyval.list) = NULL; ;}
    break;

  case 353:
#line 1993 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = (yyvsp[-3].list) ? (yyvsp[-3].list) : LL_new();
	      LL_push((yyval.list), value_new((yyvsp[-1].value).iv, (yyvsp[-1].value).flags));
	      CT_DEBUG(PARSER, ("array dimension => %ld", (yyvsp[-1].value).iv));
	    }
	  ;}
    break;

  case 354:
#line 2004 "ctlib/parser.y"
    {
	    if (IS_LOCAL)
	      (yyval.list) = NULL;
	    else
	    {
	      (yyval.list) = (yyvsp[-3].list) ? (yyvsp[-3].list) : LL_new();
	      LL_push((yyval.list), value_new(0, 0));
	      CT_DEBUG(PARSER, ("array dimension => *" ));
	    }
	  ;}
    break;

  case 355:
#line 2018 "ctlib/parser.y"
    {
	    (yyval.absDecl).pointer_flag = 1;
	    (yyval.absDecl).multiplicator = 1;
	  ;}
    break;

  case 356:
#line 2023 "ctlib/parser.y"
    {
	    (yyval.absDecl).pointer_flag = 1;
	    (yyval.absDecl).multiplicator = 1;
	  ;}
    break;

  case 357:
#line 2028 "ctlib/parser.y"
    {
	    (yyvsp[0].absDecl).pointer_flag = 1;
	    (yyval.absDecl) = (yyvsp[0].absDecl);
	  ;}
    break;

  case 358:
#line 2033 "ctlib/parser.y"
    {
	    (yyvsp[0].absDecl).pointer_flag = 1;
	    (yyval.absDecl) = (yyvsp[0].absDecl);
	  ;}
    break;

  case 359:
#line 2040 "ctlib/parser.y"
    { (yyval.absDecl) = (yyvsp[-1].absDecl); ;}
    break;

  case 360:
#line 2041 "ctlib/parser.y"
    { (yyval.absDecl) = (yyvsp[-1].absDecl); ;}
    break;

  case 361:
#line 2043 "ctlib/parser.y"
    {
	    (yyval.absDecl).pointer_flag  = 0;
	    (yyval.absDecl).multiplicator = 1;
	    if ((yyvsp[-1].list))
	    {
	      Value *pValue;
	      LL_foreach(pValue, (yyvsp[-1].list))
	        (yyval.absDecl).multiplicator *= pValue->iv;
	      LL_destroy((yyvsp[-1].list), (LLDestroyFunc) value_delete);
	    }
	  ;}
    break;

  case 362:
#line 2055 "ctlib/parser.y"
    {
	    (yyval.absDecl) = (yyvsp[-2].absDecl);
	    if ((yyvsp[0].list))
	      LL_destroy((yyvsp[0].list), (LLDestroyFunc) value_delete);
	  ;}
    break;


      default: break;
    }

/* Line 1056 of yacc.c.  */
#line 4794 "ctlib/parser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yystrlen (yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  _("syntax error, unexpected %s");
	  _("syntax error, unexpected %s, expecting %s");
	  _("syntax error, unexpected %s, expecting %s or %s");
	  _("syntax error, unexpected %s, expecting %s or %s or %s");
	  _("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize1 = yysize + yystrlen (yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = _(yyformat);
	  yysize1 = yysize + strlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp = yystpcpy (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror (_("syntax error; also memory exhausted"));
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct (_("Error: discarding"), yytoken, &yylval);
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
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct (_("Error: popping"), yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT (_("Shifting"), yystos[yyn], yyvsp, yylsp);

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
  yydestruct (_("Error: discarding lookahead"),
              yytoken, &yylval);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror (_("parser stack overflow"));
  yydestruct (_("Error: discarding lookahead"),
	      yytoken, &yylval);
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yyssp != yyss)
    for (;;)
      {

	YYPOPSTACK;
	if (yyssp == yyss)
	  break;
	yydestruct (_("Error: popping"),
		    yystos[*yyssp], yyvsp);
      }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 2062 "ctlib/parser.y"



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
  dUCPP(pState->cpp);

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
  Enumerator *pEnum;
  Typedef    *pTypedef;
  HashSum     hash;
  int         len;

  CT_DEBUG(CLEXER, ("check_type( \"%s\" )", s));

  HASH_STR_LEN(hash, s, len);

  pEnum = HT_get(pState->pCPI->htEnumerators, s, len, hash);

  if (pEnum)
  {
    CT_DEBUG(CLEXER, ("enum found!"));
    plval->value = pEnum->value;
    return CONSTANT;
  }

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
#ifdef UCPP_REENTRANT
  pState->cpp                 = cpp;
#endif

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


