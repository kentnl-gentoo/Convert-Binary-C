/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
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
     IDENTIFIER = 316,
     STRING_LITERAL = 317,
     CONSTANT = 318,
     TYPE_NAME = 319
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
#define IDENTIFIER 316
#define STRING_LITERAL 317
#define CONSTANT 318
#define TYPE_NAME 319




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
* $Date: 2004/09/18 22:20:43 +0200 $
* $Revision: 37 $
* $Snapshot: /Convert-Binary-C/0.56 $
* $Source: /ctlib/parser.y $
*
********************************************************************************
*
* Copyright (c) 2002-2004 Marcus Holland-Moritz. All rights reserved.
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
#define YYERROR_VERBOSE

/*
 * Bison version >= 1.31 is needed for YYFPRINTF
 */
#if YYDEBUG && defined CTYPE_DEBUGGING
#define YYFPRINTF BisonDebugFunc
#endif

#define c_error( msg )    \
        parser_error( PSTATE, msg )

#define c_parse CTlib_c_parse

/* MACROS */

#define PSTATE                  ((ParserState *) pState)

#if CTYPE_DEBUGGING
#define EX_OBJECT( id, list, obj ) ex_object( id, list, obj )
#else
#define EX_OBJECT( id, list, obj ) ex_object( list, obj )
#endif

#define EX_NODE( node )         EX_OBJECT( "Node",           PSTATE->nodeList,            node  )
#define EX_DECL( decl )         EX_OBJECT( "Declarator",     PSTATE->declaratorList,      decl  )
#define EX_ARRAY( array )       EX_OBJECT( "Array",          PSTATE->arrayList,           array )
#define EX_STRUCT_DECL( decl )  EX_OBJECT( "StructDecl",     PSTATE->structDeclList,      decl  )
#define EX_STRDECL_LIST( list ) EX_OBJECT( "StructDeclList", PSTATE->structDeclListsList, list  )

#define STORE_IN_HASH( table, key, obj )                                       \
        do {                                                                   \
          if( key.node == NULL )                                               \
            HT_store( PSTATE->pCPI->table, key.str, key.len, key.hash, obj );  \
          else                                                                 \
            HT_storenode( PSTATE->pCPI->table, EX_NODE( key.node ), obj );     \
        } while(0)

#define DELETE_NODE( key )                                                     \
        do {                                                                   \
          if( key.node != NULL )                                               \
            HN_delete( EX_NODE( key.node ) );                                  \
        } while(0)

#define POSTFIX_DECL( decl, postfix )                                          \
        do {                                                                   \
          if( postfix ) {                                                      \
            EX_ARRAY( postfix );                                               \
            if( decl->pointer_flag )                                           \
              LL_destroy( postfix, (LLDestroyFunc) value_delete );             \
            else                                                               \
              LL_delete( LL_splice( decl->array, 0, 0, postfix ) );            \
          }                                                                    \
        } while(0)

#define MAKE_TYPEDEF( list, decl )                                                \
        do {                                                                      \
          Typedef *pTypedef = typedef_new( &(list->type), EX_DECL( decl ) );      \
          CT_DEBUG( PARSER, ("making new typedef => %s (list @ %p)",              \
                             decl->identifier, list) );                           \
          LL_push( list->typedefs, pTypedef );                                    \
          HT_store( PSTATE->pCPI->htTypedefs, decl->identifier, 0, 0, pTypedef ); \
        } while(0)

#define UNDEF_VAL( x ) do { x.iv = 0; x.flags = V_IS_UNDEF; } while(0)

#define UNARY_OP( result, op, val ) \
          do { result.iv = op val.iv; result.flags = val.flags; } while(0)

#define BINARY_OP( result, val1, op, val2 )           \
          do {                                        \
            result.iv    = val1.iv   op val2.iv;      \
            result.flags = val1.flags | val2.flags;   \
          } while(0)

#define LLC_OR( t1, t2 )                              \
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

  LinkedList          curEnumList;
  LinkedList          nodeList,
                      arrayList,
                      declaratorList,
                      declListsList,
                      structDeclList,
                      structDeclListsList;

  PragmaState         pragma;

#ifdef UCPP_REENTRANT
  struct CPP         *cpp;
#endif
  struct lexer_state *pLexer;

  FileInfo           *pFI;

  u_32                flags;

};

typedef struct {
  char    *str;
  int      len;
  HashSum  hash;
  HashNode node;
} IdOrTypeName;


/*===== STATIC FUNCTION PROTOTYPES ===========================================*/

static inline int   c_lex( void *pYYLVAL, ParserState *pState );

static inline int   get_char_value( char *s );
static inline int   string_size( char *s );
static inline int   check_type( void *pVVLVAL, ParserState *pState, char *s );
static        void  parser_error( ParserState *pState, char *msg );

#ifdef CTYPE_DEBUGGING
static        void *ex_object( char *type, LinkedList list, void *object );
#else
static inline void *ex_object( LinkedList list, void *object );
#endif


/*===== EXTERNAL VARIABLES ===================================================*/

/*===== GLOBAL VARIABLES =====================================================*/

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
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 393 "ctlib/parser.y"
typedef union YYSTYPE {
  HashNode           identifier;
  Declarator        *pDecl;
  AbstractDeclarator absDecl;
  StructDeclaration *pStructDecl;
  TypedefList       *pTypedefList;
  LinkedList         list;
  Enumerator        *pEnum;
  TypeSpec           tspec;
  Value              value;
  struct {
    unsigned long    uval;
    ContextInfo      ctx;
  }                  context;
  signed long        ival;
  unsigned long      uval;
  char               oper;
  IdOrTypeName       idOrType;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 580 "ctlib/parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 592 "ctlib/parser.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
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
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  120
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2146

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  133
/* YYNRULES -- Number of rules. */
#define YYNRULES  366
/* YYNRULES -- Number of states. */
#define YYNSTATES  615

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
static const unsigned short yyprhs[] =
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
     539,   542,   545,   548,   551,   553,   556,   560,   563,   567,
     570,   572,   575,   577,   578,   580,   583,   589,   596,   599,
     601,   603,   607,   609,   613,   615,   619,   621,   625,   627,
     630,   633,   636,   638,   641,   644,   646,   649,   652,   655,
     657,   660,   663,   665,   669,   671,   673,   675,   678,   680,
     683,   684,   687,   692,   694,   697,   702,   703,   706,   708,
     711,   715,   718,   719,   721,   723,   725,   727,   729,   731,
     733,   735,   739,   744,   748,   751,   755,   759,   764,   766,
     769,   771,   774,   777,   783,   791,   797,   803,   811,   821,
     825,   828,   831,   835,   836,   838,   840,   843,   845,   847,
     849,   850,   854,   855,   860,   861,   866,   867,   872,   873,
     878,   879,   883,   884,   889,   890,   895,   896,   901,   902,
     907,   908,   913,   914,   920,   921,   927,   928,   934,   935,
     941,   943,   945,   947,   949,   951,   954,   956,   958,   961,
     965,   969,   974,   976,   981,   987,   990,   994,   998,  1003,
    1008,  1010,  1014,  1016,  1018,  1020,  1023,  1027,  1030,  1034,
    1039,  1041,  1045,  1047,  1050,  1054,  1059,  1063,  1068,  1070,
    1072,  1074,  1076,  1079,  1083,  1086,  1090,  1094,  1099,  1104,
    1106,  1109,  1112,  1116,  1120,  1124,  1128
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     184,     0,    -1,    62,    -1,    90,    62,    -1,    37,    65,
      90,    66,    -1,    -1,    91,    -1,    37,    65,   121,    66,
      67,    -1,    37,   131,    65,   121,    66,    67,    -1,    37,
     131,    65,   121,    68,    95,    66,    67,    -1,    37,   131,
      65,   121,    68,    95,    68,    95,    66,    67,    -1,    37,
     131,    65,   121,    68,    95,    68,    95,    68,    98,    66,
      67,    -1,    -1,    96,    -1,    97,    -1,    96,    69,    97,
      -1,    62,    65,   121,    66,    -1,    70,    61,    71,    62,
      65,   121,    66,    -1,    90,    -1,    98,    69,    90,    -1,
      61,    -1,    63,    -1,    90,    -1,    65,   121,    66,    -1,
      99,    -1,   100,    70,   121,    71,    -1,   100,    65,    66,
      -1,   100,    65,   104,    66,    -1,    -1,   100,   101,    72,
     103,    -1,    -1,   100,   102,    39,   103,    -1,   100,    40,
      -1,   100,    41,    -1,    65,   167,    66,    73,   170,   174,
      74,    -1,    61,    -1,    64,    -1,   119,    -1,   104,    69,
     119,    -1,   100,    -1,    40,   105,    -1,    41,   105,    -1,
     106,   107,    -1,    29,   105,    -1,    29,    65,   167,    66,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,   105,    -1,    65,   167,    66,   107,    -1,
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
      -1,   129,   211,    92,   168,    -1,   130,   211,    92,   168,
      -1,   125,    69,   211,    92,   168,    -1,   127,   203,    92,
     168,    -1,   128,   203,    92,   168,    -1,   126,    69,   203,
      92,   168,    -1,   134,    -1,   136,    -1,   140,    -1,   135,
      -1,   137,    -1,   141,    -1,   142,    -1,   130,   142,    -1,
     129,   132,    -1,   133,    -1,   130,   133,    -1,    -1,   130,
      -1,   142,    -1,   133,    -1,    19,    -1,    36,    -1,    30,
      -1,   129,   143,    -1,   135,   142,    -1,   134,   132,    -1,
     134,   143,    -1,   143,    -1,   130,   143,    -1,   135,   133,
      -1,   135,   143,    -1,   129,   144,    -1,   137,   142,    -1,
     136,   132,    -1,   144,    -1,   130,   144,    -1,   137,   133,
      -1,   145,    -1,   130,   145,    -1,   137,   133,    -1,   138,
      -1,   141,    -1,   141,   142,    -1,   129,    64,    -1,   140,
     132,    -1,    64,    -1,   130,    64,    -1,   141,   133,    -1,
      14,    -1,    16,    -1,    33,    -1,     3,    -1,    13,    -1,
      35,    -1,     5,    -1,    15,    -1,    21,    -1,     9,    -1,
      20,    -1,     4,    -1,    25,    -1,    22,    -1,    26,    -1,
     145,    -1,   158,    -1,   146,    73,   148,    74,    -1,   146,
     166,    73,   148,    74,    -1,   146,   166,    -1,   147,    -1,
       6,    -1,    18,    -1,    -1,   149,    -1,   150,    -1,   149,
     150,    -1,   153,    67,    -1,   152,    67,    -1,   151,    67,
      -1,   139,    -1,   130,   155,    -1,   152,    69,   155,    -1,
     128,   154,    -1,   153,    69,   154,    -1,   203,   156,    -1,
     157,    -1,   211,   156,    -1,   157,    -1,    -1,   157,    -1,
      68,   122,    -1,   159,    73,   160,   174,    74,    -1,   159,
     166,    73,   160,   174,    74,    -1,   159,   166,    -1,    12,
      -1,   161,    -1,   160,    69,   161,    -1,   166,    -1,   166,
      88,   122,    -1,   163,    -1,   163,    69,    50,    -1,   164,
      -1,   163,    69,   164,    -1,   127,    -1,   127,   217,    -1,
     127,   211,    -1,   127,   205,    -1,   129,    -1,   129,   217,
      -1,   129,   211,    -1,   128,    -1,   128,   217,    -1,   128,
     211,    -1,   128,   205,    -1,   130,    -1,   130,   217,    -1,
     130,   211,    -1,    61,    -1,   165,    69,    61,    -1,    61,
      -1,    64,    -1,   128,    -1,   128,   217,    -1,   130,    -1,
     130,   217,    -1,    -1,    88,   169,    -1,    73,   170,   174,
      74,    -1,   119,    -1,   171,   169,    -1,   170,    69,   171,
     169,    -1,    -1,   172,    88,    -1,   173,    -1,   172,   173,
      -1,    70,   122,    71,    -1,    72,   166,    -1,    -1,    69,
      -1,   176,    -1,   177,    -1,   180,    -1,   181,    -1,   182,
      -1,   183,    -1,    94,    -1,   166,    68,   175,    -1,    11,
     122,    68,   175,    -1,    27,    68,   175,    -1,    73,    74,
      -1,    73,   178,    74,    -1,    73,   179,    74,    -1,    73,
     178,   179,    74,    -1,   124,    -1,   178,   124,    -1,   175,
      -1,   179,   175,    -1,   123,    67,    -1,    32,    65,   121,
      66,   175,    -1,    32,    65,   121,    66,   175,     8,   175,
      -1,    10,    65,   121,    66,   175,    -1,    34,    65,   121,
      66,   175,    -1,    31,   175,    34,    65,   121,    66,    67,
      -1,    24,    65,   123,    67,   123,    67,   123,    66,   175,
      -1,    28,   166,    67,    -1,    23,    67,    -1,     7,    67,
      -1,    17,   123,    67,    -1,    -1,   185,    -1,   186,    -1,
     185,   186,    -1,   187,    -1,   124,    -1,    93,    -1,    -1,
     211,   188,   177,    -1,    -1,   127,   211,   189,   177,    -1,
      -1,   128,   211,   190,   177,    -1,    -1,   129,   211,   191,
     177,    -1,    -1,   130,   211,   192,   177,    -1,    -1,   215,
     193,   177,    -1,    -1,   127,   215,   194,   177,    -1,    -1,
     128,   215,   195,   177,    -1,    -1,   129,   215,   196,   177,
      -1,    -1,   130,   215,   197,   177,    -1,    -1,   215,   178,
     198,   177,    -1,    -1,   127,   215,   178,   199,   177,    -1,
      -1,   128,   215,   178,   200,   177,    -1,    -1,   129,   215,
     178,   201,   177,    -1,    -1,   130,   215,   178,   202,   177,
      -1,   211,    -1,   204,    -1,   208,    -1,   205,    -1,    64,
      -1,    64,   218,    -1,   206,    -1,   207,    -1,    76,   205,
      -1,    76,   130,   205,    -1,    65,   206,    66,    -1,    65,
     206,    66,   218,    -1,   209,    -1,    76,    65,   210,    66,
      -1,    76,   130,    65,   210,    66,    -1,    76,   208,    -1,
      76,   130,   208,    -1,    65,   208,    66,    -1,    65,   210,
     218,    66,    -1,    65,   208,    66,   218,    -1,    64,    -1,
      65,   210,    66,    -1,   212,    -1,   214,    -1,   213,    -1,
      76,   211,    -1,    76,   130,   211,    -1,   214,   218,    -1,
      65,   212,    66,    -1,    65,   212,    66,   218,    -1,    61,
      -1,    65,   214,    66,    -1,   216,    -1,    76,   215,    -1,
      76,   130,   215,    -1,   214,    65,   165,    66,    -1,    65,
     215,    66,    -1,    65,   215,    66,   218,    -1,   220,    -1,
     221,    -1,   218,    -1,   219,    -1,    65,    66,    -1,    65,
     162,    66,    -1,    70,    71,    -1,    70,   119,    71,    -1,
      70,    76,    71,    -1,   219,    70,   119,    71,    -1,   219,
      70,    76,    71,    -1,    76,    -1,    76,   130,    -1,    76,
     217,    -1,    76,   130,   217,    -1,    65,   220,    66,    -1,
      65,   221,    66,    -1,    65,   218,    66,    -1,    65,   220,
      66,   218,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   559,   559,   560,   568,   571,   573,   577,   581,   582,
     584,   587,   593,   595,   599,   600,   604,   605,   609,   610,
     615,   621,   622,   623,   627,   628,   629,   630,   631,   631,
     632,   632,   633,   634,   635,   639,   640,   644,   645,   649,
     650,   651,   652,   670,   671,   675,   676,   677,   678,   679,
     680,   684,   685,   689,   690,   692,   699,   709,   710,   712,
     717,   718,   720,   725,   726,   728,   730,   732,   737,   738,
     740,   745,   746,   751,   752,   757,   758,   763,   764,   769,
     770,   775,   776,   781,   782,   786,   787,   788,   789,   790,
     791,   792,   793,   794,   795,   796,   800,   801,   805,   809,
     811,   849,   850,   851,   852,   859,   881,   887,   898,   918,
     924,   936,   941,   942,   947,   952,   953,   959,   960,   961,
     965,   966,   969,   971,   975,   976,   980,   981,   982,   986,
     987,   988,   989,   993,   994,   995,   996,  1000,  1005,  1010,
    1018,  1019,  1020,  1024,  1025,  1026,  1030,  1031,  1034,  1039,
    1044,  1052,  1053,  1054,  1058,  1059,  1060,  1061,  1062,  1063,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1079,
    1080,  1084,  1100,  1131,  1157,  1166,  1167,  1171,  1172,  1176,
    1191,  1206,  1207,  1208,  1212,  1226,  1241,  1255,  1271,  1285,
    1295,  1308,  1318,  1331,  1332,  1336,  1340,  1356,  1388,  1414,
    1422,  1436,  1454,  1464,  1477,  1478,  1482,  1483,  1487,  1488,
    1489,  1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,
    1499,  1500,  1508,  1509,  1513,  1528,  1544,  1558,  1578,  1585,
    1595,  1597,  1601,  1602,  1606,  1607,  1610,  1612,  1616,  1617,
    1621,  1622,  1625,  1627,  1632,  1633,  1634,  1635,  1636,  1637,
    1638,  1642,  1643,  1644,  1648,  1649,  1650,  1651,  1655,  1656,
    1660,  1661,  1665,  1669,  1670,  1671,  1675,  1676,  1677,  1681,
    1682,  1683,  1684,  1690,  1692,  1696,  1697,  1701,  1702,  1703,
    1707,  1707,  1709,  1709,  1711,  1711,  1713,  1713,  1715,  1715,
    1718,  1718,  1719,  1719,  1720,  1720,  1721,  1721,  1722,  1722,
    1724,  1724,  1725,  1725,  1726,  1726,  1727,  1727,  1728,  1728,
    1732,  1733,  1737,  1738,  1742,  1754,  1768,  1775,  1776,  1782,
    1791,  1792,  1803,  1804,  1810,  1816,  1822,  1831,  1832,  1837,
    1845,  1857,  1861,  1862,  1866,  1867,  1873,  1882,  1887,  1888,
    1896,  1909,  1913,  1914,  1915,  1919,  1924,  1925,  1933,  1934,
    1935,  1949,  1950,  1951,  1955,  1969,  1983,  1984,  2003,  2025,
    2030,  2035,  2040,  2048,  2049,  2050,  2061
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
  "XOR_ASSIGN", "OR_ASSIGN", "IDENTIFIER", "STRING_LITERAL", "CONSTANT", 
  "TYPE_NAME", "'('", "')'", "';'", "':'", "','", "'['", "']'", "'.'", 
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
  "unnamed_su_declaration", "member_default_declaring_list", 
  "member_declaring_list", "member_declarator", 
  "member_identifier_declarator", "bit_field_size_opt", "bit_field_size", 
  "enum_name", "enum_key_context", "enumerator_list", "enumerator", 
  "parameter_type_list", "parameter_list", "parameter_declaration", 
  "identifier_list", "identifier_or_typedef_name", "type_name", 
  "initializer_opt", "initializer", "initializer_list", "designation_opt", 
  "designator_list", "designator", "comma_opt", "statement", 
  "labeled_statement", "compound_statement", "declaration_list", 
  "statement_list", "expression_statement", "selection_statement", 
  "iteration_statement", "jump_statement", "source_file", 
  "translation_unit", "external_definition", "function_definition", "@3", 
  "@4", "@5", "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14", 
  "@15", "@16", "@17", "declarator", "typedef_declarator", 
  "parameter_typedef_declarator", "clean_typedef_declarator", 
  "clean_postfix_typedef_declarator", "paren_typedef_declarator", 
  "paren_postfix_typedef_declarator", "simple_paren_typedef_declarator", 
  "identifier_declarator", "unary_identifier_declarator", 
  "postfix_identifier_declarator", "paren_identifier_declarator", 
  "old_function_declarator", "postfix_old_function_declarator", 
  "abstract_declarator", "postfixing_abstract_declarator", 
  "array_abstract_declarator", "unary_abstract_declarator", 
  "postfix_abstract_declarator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
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
     149,   150,   150,   150,   151,   152,   152,   153,   153,   154,
     154,   155,   155,   156,   156,   157,   158,   158,   158,   159,
     160,   160,   161,   161,   162,   162,   163,   163,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   165,   165,   166,   166,   167,   167,   167,   167,
     168,   168,   169,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   175,   175,   175,   175,   175,   175,
     175,   176,   176,   176,   177,   177,   177,   177,   178,   178,
     179,   179,   180,   181,   181,   181,   182,   182,   182,   183,
     183,   183,   183,   184,   184,   185,   185,   186,   186,   186,
     188,   187,   189,   187,   190,   187,   191,   187,   192,   187,
     193,   187,   194,   187,   195,   187,   196,   187,   197,   187,
     198,   187,   199,   187,   200,   187,   201,   187,   202,   187,
     203,   203,   204,   204,   205,   205,   205,   206,   206,   206,
     207,   207,   208,   208,   208,   208,   208,   209,   209,   209,
     210,   210,   211,   211,   212,   212,   212,   213,   213,   213,
     214,   214,   215,   215,   215,   216,   216,   216,   217,   217,
     217,   218,   218,   218,   219,   219,   219,   219,   219,   220,
     220,   220,   220,   221,   221,   221,   221
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
       2,     2,     2,     2,     1,     2,     3,     2,     3,     2,
       1,     2,     1,     0,     1,     2,     5,     6,     2,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       2,     2,     1,     3,     1,     1,     1,     2,     1,     2,
       0,     2,     4,     1,     2,     4,     0,     2,     1,     2,
       3,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     2,     5,     7,     5,     5,     7,     9,     3,
       2,     2,     3,     0,     1,     1,     2,     1,     1,     1,
       0,     3,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     3,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     5,     0,     5,     0,     5,     0,     5,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     3,
       3,     4,     1,     4,     5,     2,     3,     3,     4,     4,
       1,     3,     1,     1,     1,     2,     3,     2,     3,     4,
       1,     3,     1,     2,     3,     4,     3,     4,     1,     1,
       1,     1,     2,     3,     2,     3,     3,     4,     4,     1,
       2,     2,     3,     3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     273,   157,   165,   160,   175,   163,   199,   158,   154,   161,
     155,   176,   126,   164,   162,   167,   166,   168,   128,   156,
     159,   127,     0,   340,   151,     0,     0,   279,   278,     0,
       0,     0,     0,     0,     0,   120,   111,   114,   112,   115,
     113,   116,   117,   133,   140,   169,     0,   174,   170,     0,
       0,   274,   275,   277,   280,   332,   334,   333,   290,   342,
       0,     0,     0,     0,     0,   335,   343,   104,     0,   103,
       0,   314,     0,     0,     5,   311,   313,   316,   317,   312,
     322,   310,   292,     5,   310,   294,   149,   119,   125,   124,
     129,   137,     5,   296,   152,   121,   118,   134,   141,     5,
     298,   131,   132,   135,   130,   136,   101,   139,   102,   142,
     138,   150,   153,   148,   224,   225,   177,   173,     0,   198,
       1,   276,     0,     0,     0,   337,   351,   258,     0,     0,
       0,     0,   300,     0,     0,     0,     0,    20,     2,    21,
       0,    45,    46,    47,    48,    49,    50,    22,    24,    39,
      51,     0,    53,    57,    60,    63,    68,    71,    73,    75,
      77,    79,    81,    83,    96,     0,   338,   341,   346,   336,
     344,     0,     0,     5,   333,     0,     0,     5,   310,     0,
     315,   330,     0,     0,     0,     0,     0,     0,   318,   325,
       0,     6,   230,     0,   302,     0,   230,     0,   304,     0,
     230,     0,   306,     0,   230,     0,   308,     0,     0,     0,
     114,   115,   146,   184,   116,   169,     0,   178,   179,     0,
       0,     0,   177,   242,   200,   202,     0,    99,   281,   222,
     352,   208,   215,   212,   219,   112,   115,     0,   204,   206,
       0,   354,    46,     0,     0,     5,     5,   259,     0,   291,
       0,    43,     0,    40,    41,     0,   226,   228,   115,   116,
       0,     3,    32,    33,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    85,     0,
      51,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   339,   347,     0,     0,   230,     0,     0,
       0,   230,     0,   320,   327,     0,     0,     0,   319,   326,
       0,     0,   108,   283,     0,   293,   109,   285,     0,   295,
     105,   287,     0,   297,   106,   289,     0,   299,     0,   187,
     190,   193,   169,   185,   192,   193,   142,   171,   180,   183,
     182,     0,   181,     0,     0,   243,     0,     0,   242,     0,
       0,     0,    99,     0,     0,     0,     0,    99,     0,     0,
     122,    20,   151,   254,   250,   100,     0,     0,   260,   244,
     245,    99,    99,   246,   247,   248,   249,     0,   359,   211,
     210,   209,   350,   348,   349,   218,   217,   216,     0,   359,
     214,   213,   221,   220,   353,     0,   345,     0,   356,   355,
      46,     0,   301,     0,     0,    23,     0,   359,   227,   229,
       0,    26,     0,    37,     0,     0,     0,    84,    54,    55,
      56,    58,    59,    61,    62,    66,    67,    64,    65,    69,
      70,    72,    74,    76,    78,    80,     0,     7,    97,   107,
       0,   110,   331,   321,   329,   328,   323,     0,     0,   236,
     233,   231,   303,   305,   307,   309,    98,   195,   189,   194,
     191,   186,   188,   172,   201,   196,   203,     0,   271,     0,
       0,     0,   270,    99,    99,     0,     0,     0,     0,   123,
       0,   262,    99,   255,    99,   256,   261,     0,     0,     0,
     360,   361,   360,   205,   207,   223,   358,   357,    44,     0,
     360,   236,    52,    27,     0,    25,    35,    36,    29,    31,
       0,   324,     4,     0,     0,   242,     0,     0,   238,   197,
       0,    99,   272,     0,   253,   269,     0,     0,     0,     0,
     251,   257,   365,   363,   364,   362,   242,    38,    82,     0,
     241,   236,     0,   234,   237,   239,    99,   252,    99,     0,
      99,    99,     0,   366,     0,   240,     0,   232,   265,     0,
       0,   263,   266,     0,    12,    34,   235,    99,     0,    99,
       8,     0,     0,     0,    13,    14,     0,   267,   264,     0,
       0,     0,    12,     0,    99,     0,     0,     9,     0,    15,
     268,    16,     0,     0,     0,     0,    10,    18,     0,     0,
       0,     0,    17,    11,    19
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   147,   191,   200,    27,   374,   583,   584,   585,   608,
     148,   149,   266,   267,   518,   422,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   279,   375,   467,   376,   127,    29,    30,   128,   129,
     130,   131,   490,    87,    35,    36,    37,    38,    39,   212,
     213,    40,    41,    42,    43,    44,    45,    46,    47,   216,
     217,   218,   219,   220,   221,   339,   343,   468,   340,    48,
      49,   223,   224,   237,   238,   239,   240,   377,   260,   322,
     461,   525,   526,   527,   528,   356,   378,   379,   380,   132,
     382,   383,   384,   385,   386,    50,    51,    52,    53,   122,
     193,   197,   201,   205,   133,   195,   199,   203,   207,   248,
     324,   328,   332,   336,    74,    75,    76,    77,    78,   184,
      80,   185,    65,    55,    56,   174,    63,    59,   501,   392,
     126,   393,   394
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -519
static const short yypact[] =
{
    1263,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,
    -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,
    -519,  -519,   -29,  -519,  -519,   117,   664,  -519,  -519,   -65,
     219,   447,   447,  1504,  1541,  -519,  2110,  2110,   948,  1022,
     854,   854,  -519,  -519,  -519,  -519,    46,  -519,  -519,    92,
      53,  1263,  -519,  -519,  -519,  -519,  -519,    81,  1869,  -519,
    1971,   -53,   203,    62,   664,  -519,  -519,  -519,   176,  -519,
     567,   201,   569,   672,    75,  -519,  -519,  -519,  -519,  -519,
    -519,    69,  1869,    75,    87,  1869,  -519,  -519,  -519,  -519,
    -519,  -519,     4,  1869,  -519,  -519,  -519,  -519,  -519,    18,
    1869,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,
    -519,  -519,  -519,  -519,  -519,  -519,  1228,   106,    76,   114,
    -519,  -519,   135,  1757,  1867,  -519,   142,  -519,   567,   567,
    1578,  1615,  1869,   135,  1980,  2023,  2023,  -519,  -519,  -519,
     895,  -519,  -519,  -519,  -519,  -519,  -519,   167,  -519,   261,
     738,  1971,  -519,   -20,   141,   124,    37,   304,   164,   170,
     184,   230,   -19,  -519,  -519,    89,   201,  -519,   201,  -519,
    -519,   176,  1330,    75,   201,   631,  1049,    75,  -519,  1794,
    -519,  -519,   569,   243,   250,   201,   569,  1107,  -519,  -519,
     231,  -519,   236,   135,  1869,   135,   236,   135,  1869,   135,
     236,   135,  1869,   135,   236,   135,  1869,   135,   330,  1652,
     918,    60,  -519,  -519,   150,   267,   265,  1228,  -519,   300,
     296,   341,  1228,   317,  -519,   359,    76,   740,  -519,  -519,
    -519,   476,   476,  1300,  1368,   854,   854,   326,   353,  -519,
     133,  -519,   363,   385,  2032,    75,    75,  -519,   135,  -519,
     895,  -519,   895,  -519,  -519,   159,    13,  1689,    60,    60,
     411,  -519,  -519,  -519,  1874,  1971,   397,   445,  -519,  -519,
    -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  1971,
    -519,  -519,  1971,  1971,  1971,  1971,  1971,  1971,  1971,  1971,
    1971,  1971,  1971,  1971,  1971,  1971,  1971,  1971,  1971,  1971,
    1971,   425,  1971,  -519,  -519,   387,  1330,   236,   631,   631,
    1349,   236,   491,   201,   201,   444,   493,   569,  -519,  -519,
     456,  1919,  -519,  -519,   135,  -519,  -519,  -519,   135,  -519,
    -519,  -519,   135,  -519,  -519,  -519,   135,  -519,  1971,  -519,
    -519,   459,   495,  -519,  -519,   459,   497,  -519,  -519,  -519,
    -519,   277,  -519,   330,   475,    76,   496,  1971,   317,   500,
     524,  1971,  1971,   526,   532,   531,    76,  1117,   536,   538,
      60,   539,   541,  -519,  -519,   542,   548,   555,  -519,  -519,
    -519,   818,   969,  -519,  -519,  -519,  -519,   654,   652,  -519,
    -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  1195,   490,
    -519,  -519,  -519,  -519,  -519,  1829,  -519,   563,  -519,  -519,
     558,   568,  -519,   578,   582,  -519,  1436,   418,  -519,  -519,
    1928,  -519,   213,  -519,   346,   279,   279,  -519,  -519,  -519,
    -519,   -20,   -20,   141,   141,   124,   124,   124,   124,    37,
      37,   304,   164,   170,   184,   230,   396,  -519,  -519,  -519,
     631,  -519,  -519,  -519,  -519,  -519,  -519,   525,    47,   428,
    -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,
    -519,  -519,  -519,  -519,  -519,  -519,  -519,   575,  -519,  1971,
     583,   585,  -519,  1971,  1117,   587,   622,  1971,  1971,    60,
     596,  -519,  1117,  -519,  1043,  -519,  -519,   598,   611,   612,
     652,  -519,   490,  -519,  -519,  -519,  -519,  -519,   589,   589,
     418,   428,  -519,  -519,  1971,  -519,  -519,  -519,  -519,  -519,
    1971,  -519,  -519,  1971,    76,   616,  1919,    23,  -519,  -519,
     303,  1117,  -519,   614,  -519,  -519,   621,   316,   327,  1971,
    -519,  -519,  -519,   201,  -519,  -519,   616,  -519,  -519,   626,
    -519,   234,   619,  -519,  -519,  -519,  1117,  -519,  1971,  1971,
    1117,  1117,   308,  -519,   624,  -519,  1919,  -519,  -519,   632,
     338,   693,  -519,   636,   -33,  -519,  -519,  1971,   637,  1117,
    -519,   640,   645,   465,   641,  -519,   646,  -519,  -519,  1971,
     643,   644,   -33,   -33,  1117,   364,   659,  -519,   482,  -519,
    -519,  -519,   661,   665,   456,  1971,  -519,   167,   406,   416,
     667,   456,  -519,  -519,   167
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -519,  -306,  -519,    90,  -519,  -519,   146,  -519,   148,  -519,
    -519,  -519,  -519,  -519,   313,  -519,   289,  -519,  -107,   328,
     334,  -205,   342,   483,   446,   485,   481,   484,  -519,  -307,
    -117,  -519,   -60,  -339,  -320,     9,  -519,  -519,    15,   149,
      16,   108,  -519,     7,   -13,  -519,   388,  -106,   221,  -519,
    -519,  -519,   403,   281,   408,   217,   140,  -519,  -519,   562,
    -519,   570,  -519,  -519,  -519,   432,   435,   443,  -115,  -519,
    -519,   573,   451,  -519,  -519,   395,  -519,   -43,   292,   179,
    -518,   297,   256,  -519,   283,  -319,   -26,  -519,   399,   -36,
     430,  -519,  -519,  -519,  -519,  -519,  -519,   805,  -519,  -519,
    -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,
    -519,  -519,  -519,  -519,     6,  -519,   -61,   -32,  -519,   259,
    -519,   -34,     1,   -14,  -519,    72,   429,  -519,  -132,   -52,
    -519,  -328,  -324
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -289
static const short yytable[] =
{
     165,    54,    67,   117,    68,   125,   119,   243,   553,    28,
     125,    61,   188,   166,   458,    31,    33,   235,   476,   180,
      88,    95,   480,    88,   103,    88,   109,    88,   112,   581,
     299,   466,    81,    84,    92,    99,    60,   582,    83,   477,
     183,   190,   481,   101,   281,   107,   194,   111,   576,   198,
     466,    95,    54,   120,   466,   190,   282,   202,    61,   498,
      28,   283,   284,   499,   206,   169,    31,    33,   300,   173,
     498,   178,    57,   235,   499,   225,   177,  -286,   416,    12,
     255,   289,   290,   124,   435,   436,   437,   438,   498,   417,
      18,  -288,   499,   523,   344,   524,    21,    62,    57,   391,
     397,   401,   403,    57,    57,    57,    57,   114,    34,   261,
     115,   554,   190,   522,   303,   188,   304,    88,    95,   116,
     291,   292,   125,    57,   418,   419,   318,   411,   168,   178,
     178,   245,   246,   315,    64,    83,    57,   114,   231,   233,
     115,   247,  -282,   183,    62,    57,   123,   423,   312,    32,
     183,   124,   316,   114,   183,   301,   115,    61,   302,    34,
    -284,    61,   427,   533,   192,   118,   287,   288,    61,    12,
     389,   395,    61,   196,    95,   428,   429,   430,    23,   222,
      18,   187,    25,   225,   549,   448,    21,   226,   169,   204,
     255,   381,   255,    26,   231,   233,    95,   103,   346,   406,
      32,   112,   407,   247,   460,   424,   552,   247,   227,   178,
     345,   247,   244,   548,   341,   247,   466,  -147,   285,   286,
      88,    95,    88,   109,   209,   415,   469,   564,   302,   261,
     469,   234,   390,   396,   400,   402,   344,    23,   569,   295,
     446,   171,   107,   305,    95,   109,   112,   305,   257,   318,
      91,    98,   172,   125,    62,   296,   215,   586,    62,    57,
     315,   453,   454,   307,   315,   208,   179,   311,   123,   167,
     297,   124,   232,   124,   312,   316,   183,   183,   298,   513,
     306,   235,   514,   457,   310,   183,    69,   234,    70,   256,
      79,    79,   235,    95,    61,    61,   320,    95,   607,   235,
     -30,   262,   263,    61,   523,   614,   524,   169,  -243,   313,
     235,   169,   225,   512,    89,    96,   314,    89,   104,    89,
     110,    89,   113,   485,   321,   209,   264,   188,   232,    79,
     209,   265,   189,   -28,  -143,   497,   204,   211,    23,   347,
     516,   486,   171,   517,   236,   338,   497,    91,    98,   342,
     293,   294,   345,   172,   178,   183,   496,   215,   257,   341,
     257,   258,   215,   350,   497,   351,   208,   349,   545,   556,
     545,   208,   302,    61,   573,   326,   574,   302,   545,   330,
     305,   305,   560,   334,    61,   302,   355,    79,    79,    62,
     247,    23,   404,   561,    71,   175,   302,   547,   338,   256,
     236,   256,   231,   233,   578,   315,   176,   302,   352,   460,
     353,    89,    96,   231,   233,   302,   457,   515,   183,   530,
     231,   233,   405,   251,   253,   254,    98,   537,   538,    58,
     601,   231,   233,   302,   408,   189,    61,    12,   211,   318,
     280,    90,    97,   211,   102,   105,   319,   357,    18,   460,
      91,    98,   179,   167,    21,    66,   409,   124,   534,   305,
      82,    85,    93,   100,   520,   302,   540,    79,   496,   425,
     305,   258,   610,   258,    98,   611,    95,   420,   489,   562,
      58,   550,   612,   416,   426,   302,   449,    95,   124,    95,
     451,   563,   447,   170,   417,   234,   500,    95,   523,   570,
     524,   169,    66,   169,   210,   557,   234,   502,    23,    12,
     455,    71,    72,   234,    89,    96,    89,   110,   138,   214,
      18,   228,   305,    73,   234,   510,    21,   338,   210,   595,
     568,   591,   249,   592,   571,   572,   232,    23,    90,    97,
      71,   387,   413,   259,   414,   609,   124,   232,   603,   473,
     604,    23,   388,   588,   232,   398,   179,   452,   179,   456,
     124,   124,  -144,   124,  -145,   232,   399,   478,   600,   319,
     475,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   479,
     179,   521,   323,   482,   325,   124,   327,   483,   329,   484,
     331,   487,   333,   488,   335,   210,   337,  -224,   236,  -225,
     210,   302,    79,   431,   432,   491,   170,    97,   105,   236,
     214,   433,   434,   492,   505,   214,   236,   280,    23,   506,
      23,    71,   175,   181,   182,   439,   440,   236,   210,   507,
     210,    90,    97,   176,   508,    73,   280,   412,   509,   529,
     280,   531,   532,   259,   535,   259,   536,     1,     2,     3,
       4,   539,   511,     5,   542,    97,     6,     7,     8,     9,
      10,    12,    11,    12,    13,    14,    15,   543,   544,    16,
      17,   558,    18,    12,    18,   551,   559,    19,    21,    20,
      21,    12,    23,   567,    18,   181,   308,   565,   575,   577,
      21,   579,    18,   580,   587,   589,   590,   176,    21,   280,
     593,   597,   594,    23,   596,    23,    71,   387,    24,   387,
     230,   602,   124,   462,   124,    23,   605,   463,   388,    25,
     388,   464,   606,    23,   613,   465,    71,   186,   598,   519,
      26,   599,   442,     1,     2,     3,     4,   359,    73,     5,
     360,   361,     6,     7,     8,     9,    10,   362,    11,    12,
      13,    14,    15,   363,   364,    16,    17,   365,   366,   134,
      18,   367,   368,    19,   369,    20,    21,   370,   441,   444,
     135,   136,   443,   445,   354,   472,   471,   348,   470,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   358,
     504,   371,   138,   139,   372,   140,   474,   566,   546,   280,
     555,   494,   280,   227,   373,   141,   142,   143,   144,   145,
     146,     1,     2,     3,     4,   359,   278,     5,   360,   361,
       6,     7,     8,     9,    10,   362,    11,    12,    13,    14,
      15,   363,   364,    16,    17,   365,   366,   134,    18,   367,
     368,    19,   369,    20,    21,   370,   121,     1,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
      10,     0,     0,    12,     0,     0,     0,     0,     0,   371,
     138,   139,   372,   140,    18,     0,     0,    19,     0,    20,
      21,   227,   493,   141,   142,   143,   144,   145,   146,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       9,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     2,     3,   134,    18,     0,     5,     0,     0,
       0,    21,     0,     9,     0,   135,   136,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,     1,     0,     0,    21,     0,   137,   138,   139,    24,
     140,     7,     8,     0,    10,     0,     0,    12,     0,     0,
     141,   142,   143,   144,   145,   146,   359,     0,    18,   360,
     361,    19,     0,    20,    21,     0,   362,     0,     0,     0,
       0,     0,   363,   364,     0,     0,   365,   366,   134,     0,
     367,   368,     0,   369,     0,     0,   370,     0,     0,   135,
     136,     0,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
     371,   138,   139,   115,   140,     7,     8,     0,    10,     0,
       0,    12,   227,   495,   141,   142,   143,   144,   145,   146,
     359,     0,    18,   360,   361,    19,     0,    20,    21,     0,
     362,     0,     0,     0,     0,     0,   363,   364,    12,     0,
     365,   366,   134,     0,   367,   368,     0,   369,     0,    18,
     370,     0,     0,   135,   136,    21,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   371,   138,   139,   115,   140,     0,
      23,     0,     0,    71,   309,     0,   227,   541,   141,   142,
     143,   144,   145,   146,   359,   176,    12,   360,   361,     0,
       0,     0,     0,     0,   362,     0,     0,    18,     0,     0,
     363,   364,     0,    21,   365,   366,   134,     0,   367,   368,
       0,   369,     0,     0,   370,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,    71,   317,     0,     0,     0,     0,     0,   371,   138,
     139,   115,   140,    73,     0,     0,     0,     0,     0,     0,
     227,     0,   141,   142,   143,   144,   145,   146,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,     0,
      20,    21,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     9,     0,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,    23,     0,    18,    24,
     398,   230,     0,     0,    21,   124,     1,     2,     3,     4,
       0,   399,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,    24,    18,     0,     0,    19,     0,    20,    21,
      22,     0,     0,     1,     2,     3,     4,     0,     0,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,    23,    16,    17,    24,    25,     0,
      18,     0,     0,    19,     0,    20,    21,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    23,     0,     0,    86,   398,    21,     0,    12,     0,
     124,     1,     2,     3,     4,     0,   399,     5,     0,    18,
       6,     7,     8,     9,    10,    21,    11,    12,    13,    14,
      15,    23,     0,    16,    17,   171,     0,     0,    18,     0,
       0,    19,     0,    20,    21,     0,   172,     0,     0,     0,
      23,     0,     0,    71,   450,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,     0,     0,     0,    23,
       0,     0,    94,   398,     0,     0,     0,     0,   124,     1,
       2,     3,     4,     0,   399,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,   416,   230,     0,     0,     0,   124,     1,     2,     3,
       4,     0,   417,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,    20,
      21,     0,     0,     0,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,    23,    16,    17,    86,    25,
       0,    18,     0,     0,    19,     0,    20,    21,     0,     0,
      26,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,    23,    16,    17,    94,    25,     0,    18,     0,
       0,    19,     0,    20,    21,     0,     0,    26,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,    23,
      16,    17,    86,   171,     0,    18,     0,     0,    19,     0,
      20,    21,     0,     0,   172,     0,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     9,     0,     0,
      11,    12,    13,    14,    15,     0,    23,    16,    17,    94,
     171,     0,    18,     0,     0,     0,     0,     0,    21,     0,
       0,   172,     0,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     9,     0,     0,    11,    12,    13,
      14,    15,     0,    23,    16,    17,    94,   171,     0,    18,
     338,     0,     0,     0,     0,    21,     0,     0,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,   416,     0,     0,     0,     0,   124,
       1,     2,     3,     4,     0,   417,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,    20,    21,     0,     0,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,   229,    16,
      17,    24,     0,   230,    18,     0,     0,    19,     0,    20,
      21,     0,     1,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,    24,    18,
     230,     0,    19,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     0,     0,     5,   503,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,    24,    16,    17,   134,     0,     0,    18,
       0,     0,    19,   134,    20,    21,     0,   135,   136,     0,
       0,     0,     0,     0,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,     0,   140,    24,     0,   137,   138,   139,   241,   140,
     421,     0,   141,   242,   143,   144,   145,   146,   134,   141,
     142,   143,   144,   145,   146,     0,     0,   134,     0,   135,
     136,     0,     0,     0,     0,     0,     0,     0,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,     0,   140,     0,     0,     0,     0,   137,
     138,   139,   459,   140,   141,   142,   143,   144,   145,   146,
     134,   511,     0,   141,   142,   143,   144,   145,   146,   134,
       0,   135,   136,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,     0,   140,     0,     0,     0,
       0,   137,   138,   139,     0,   250,   141,   142,   143,   144,
     145,   146,   134,     0,     0,   141,   142,   143,   144,   145,
     146,   134,     0,   135,   136,     0,     0,     0,     0,     0,
       0,     0,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,     0,   252,     0,
       0,     0,     0,   137,   138,   139,     0,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,   141,   410,   143,
     144,   145,   146,     1,     2,     3,     0,     0,     0,     5,
       0,     0,     0,     7,     8,     9,    10,     0,     0,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,    20,    21
};

static const short yycheck[] =
{
      60,     0,    67,    46,    69,    57,    49,   124,   526,     0,
      62,    25,    73,    66,   320,     0,     0,   123,   357,    71,
      33,    34,   361,    36,    37,    38,    39,    40,    41,    62,
      49,   338,    31,    32,    33,    34,    65,    70,    32,   358,
      72,    37,   362,    36,   151,    38,    82,    40,   566,    85,
     357,    64,    51,     0,   361,    37,    76,    93,    72,   387,
      51,    81,    82,   387,   100,    64,    51,    51,    87,    68,
     398,    70,     0,   179,   398,   118,    70,    73,    65,    19,
     140,    44,    45,    70,   289,   290,   291,   292,   416,    76,
      30,    73,   416,    70,   209,    72,    36,    25,    26,   231,
     232,   233,   234,    31,    32,    33,    34,    61,     0,    62,
      64,    88,    37,    66,   166,   176,   168,   130,   131,    73,
      83,    84,   174,    51,   256,   257,   187,   244,    66,   128,
     129,   130,   131,   185,    26,   129,    64,    61,   123,   123,
      64,   132,    73,   175,    72,    73,    65,   264,   182,     0,
     182,    70,   186,    61,   186,    66,    64,   171,    69,    51,
      73,   175,   279,   483,    74,    73,    42,    43,   182,    19,
     231,   232,   186,    83,   187,   282,   283,   284,    61,    73,
      30,    73,    65,   226,   523,   302,    36,    73,   187,    99,
     250,   227,   252,    76,   179,   179,   209,   210,   211,    66,
      51,   214,    69,   194,   321,   265,   525,   198,    73,   208,
     209,   202,    70,   520,   208,   206,   523,    67,    77,    78,
     233,   234,   235,   236,   116,    66,   341,   546,    69,    62,
     345,   123,   231,   232,   233,   234,   351,    61,   558,    75,
     300,    65,   235,   171,   257,   258,   259,   175,   140,   310,
      33,    34,    76,   305,   182,    85,   116,   577,   186,   187,
     312,   313,   314,   173,   316,   116,    65,   177,    65,    66,
      86,    70,   123,    70,   308,   309,   308,   309,    48,    66,
     172,   387,    69,   317,   176,   317,    67,   179,    69,   140,
      31,    32,   398,   306,   308,   309,    65,   310,   604,   405,
      39,    40,    41,   317,    70,   611,    72,   306,    74,    66,
     416,   310,   355,   420,    33,    34,    66,    36,    37,    38,
      39,    40,    41,   366,    88,   217,    65,   388,   179,    70,
     222,    70,    73,    72,    67,   387,   246,   116,    61,    74,
      61,   367,    65,    64,   123,    68,   398,   130,   131,   209,
      46,    47,   351,    76,   353,   387,   382,   217,   250,   353,
     252,   140,   222,    67,   416,    69,   217,    67,   500,    66,
     502,   222,    69,   387,    66,   196,    68,    69,   510,   200,
     308,   309,    66,   204,   398,    69,    69,   128,   129,   317,
     381,    61,    66,    66,    64,    65,    69,   514,    68,   250,
     179,   252,   387,   387,    66,   457,    76,    69,    67,   526,
      69,   130,   131,   398,   398,    69,   450,    71,   450,   479,
     405,   405,    69,   134,   135,   136,   209,   487,   488,     0,
      66,   416,   416,    69,    71,   176,   450,    19,   217,   500,
     151,    33,    34,   222,    36,    37,   187,    88,    30,   566,
     233,   234,    65,    66,    36,    26,    71,    70,   484,   387,
      31,    32,    33,    34,    68,    69,   492,   208,   494,    72,
     398,   250,    66,   252,   257,    69,   489,    66,   370,   539,
      51,   524,    66,    65,    39,    69,   307,   500,    70,   502,
     311,   543,    67,    64,    76,   387,   388,   510,    70,   559,
      72,   500,    73,   502,   116,   531,   398,   399,    61,    19,
      66,    64,    65,   405,   233,   234,   235,   236,    62,   116,
      30,   122,   450,    76,   416,   417,    36,    68,   140,   589,
     556,    66,   133,    68,   560,   561,   387,    61,   130,   131,
      64,    65,   250,   140,   252,   605,    70,   398,    66,    74,
      68,    61,    76,   579,   405,    65,    65,    66,    65,    66,
      70,    70,    67,    70,    67,   416,    76,    67,   594,   310,
      74,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,    65,
      65,    66,   193,    67,   195,    70,   197,    65,   199,    68,
     201,    65,   203,    65,   205,   217,   207,    68,   387,    68,
     222,    69,   353,   285,   286,    67,   187,   209,   210,   398,
     217,   287,   288,    68,    61,   222,   405,   338,    61,    71,
      61,    64,    65,    64,    65,   293,   294,   416,   250,    71,
     252,   233,   234,    76,    66,    76,   357,   248,    66,    74,
     361,    68,    67,   250,    67,   252,    34,     3,     4,     5,
       6,    65,    73,     9,    66,   257,    12,    13,    14,    15,
      16,    19,    18,    19,    20,    21,    22,    66,    66,    25,
      26,    67,    30,    19,    30,    69,    65,    33,    36,    35,
      36,    19,    61,    74,    30,    64,    65,    71,    74,    67,
      36,     8,    30,    67,    67,    65,    61,    76,    36,   420,
      69,    67,    66,    61,    71,    61,    64,    65,    64,    65,
      66,    62,    70,   324,    70,    61,    65,   328,    76,    65,
      76,   332,    67,    61,    67,   336,    64,    65,   592,   426,
      76,   593,   296,     3,     4,     5,     6,     7,    76,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   295,   298,
      40,    41,   297,   299,   222,   353,   351,   217,   345,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,   226,
     405,    61,    62,    63,    64,    65,   355,   551,   511,   520,
     527,   381,   523,    73,    74,    75,    76,    77,    78,    79,
      80,     3,     4,     5,     6,     7,    88,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    51,     3,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      16,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    30,    -1,    -1,    33,    -1,    35,
      36,    73,    74,    75,    76,    77,    78,    79,    80,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,     4,     5,    29,    30,    -1,     9,    -1,    -1,
      -1,    36,    -1,    15,    -1,    40,    41,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,     3,    -1,    -1,    36,    -1,    61,    62,    63,    64,
      65,    13,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,
      75,    76,    77,    78,    79,    80,     7,    -1,    30,    10,
      11,    33,    -1,    35,    36,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    13,    14,    -1,    16,    -1,
      -1,    19,    73,    74,    75,    76,    77,    78,    79,    80,
       7,    -1,    30,    10,    11,    33,    -1,    35,    36,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    23,    24,    19,    -1,
      27,    28,    29,    -1,    31,    32,    -1,    34,    -1,    30,
      37,    -1,    -1,    40,    41,    36,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,
      61,    -1,    -1,    64,    65,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,     7,    76,    19,    10,    11,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    30,    -1,    -1,
      23,    24,    -1,    36,    27,    28,    29,    -1,    31,    32,
      -1,    34,    -1,    -1,    37,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    75,    76,    77,    78,    79,    80,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    61,    -1,    30,    64,
      65,    66,    -1,    -1,    36,    70,     3,     4,     5,     6,
      -1,    76,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    64,    30,    -1,    -1,    33,    -1,    35,    36,
      37,    -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    61,    25,    26,    64,    65,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    61,    -1,    -1,    64,    65,    36,    -1,    19,    -1,
      70,     3,     4,     5,     6,    -1,    76,     9,    -1,    30,
      12,    13,    14,    15,    16,    36,    18,    19,    20,    21,
      22,    61,    -1,    25,    26,    65,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    76,    -1,    -1,    -1,
      61,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    61,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    70,     3,
       4,     5,     6,    -1,    76,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    70,     3,     4,     5,
       6,    -1,    76,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    61,    25,    26,    64,    65,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,
      76,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    61,    25,    26,    64,    65,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    76,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    61,
      25,    26,    64,    65,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,    76,    -1,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    61,    25,    26,    64,
      65,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    76,    -1,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    61,    25,    26,    64,    65,    -1,    30,
      68,    -1,    -1,    -1,    -1,    36,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    70,
       3,     4,     5,     6,    -1,    76,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    61,    25,
      26,    64,    -1,    66,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    64,    30,
      66,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    50,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    64,    25,    26,    29,    -1,    -1,    30,
      -1,    -1,    33,    29,    35,    36,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    -1,    65,    64,    -1,    61,    62,    63,    71,    65,
      66,    -1,    75,    76,    77,    78,    79,    80,    29,    75,
      76,    77,    78,    79,    80,    -1,    -1,    29,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,    61,
      62,    63,    73,    65,    75,    76,    77,    78,    79,    80,
      29,    73,    -1,    75,    76,    77,    78,    79,    80,    29,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    -1,    65,    -1,    -1,    -1,
      -1,    61,    62,    63,    -1,    65,    75,    76,    77,    78,
      79,    80,    29,    -1,    -1,    75,    76,    77,    78,    79,
      80,    29,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    65,    -1,
      -1,    -1,    -1,    61,    62,    63,    -1,    65,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,     3,     4,     5,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    13,    14,    15,    16,    -1,    -1,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     9,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    25,    26,    30,    33,
      35,    36,    37,    61,    64,    65,    76,    93,   124,   125,
     126,   127,   128,   129,   130,   133,   134,   135,   136,   137,
     140,   141,   142,   143,   144,   145,   146,   147,   158,   159,
     184,   185,   186,   187,   211,   212,   213,   214,   215,   216,
      65,   212,   214,   215,   130,   211,   215,    67,    69,    67,
      69,    64,    65,    76,   203,   204,   205,   206,   207,   208,
     209,   211,   215,   203,   211,   215,    64,   132,   133,   142,
     143,   144,   211,   215,    64,   133,   142,   143,   144,   211,
     215,   132,   143,   133,   142,   143,    67,   132,    67,   133,
     142,   132,   133,   142,    61,    64,    73,   166,    73,   166,
       0,   186,   188,    65,    70,   218,   219,   124,   127,   128,
     129,   130,   178,   193,    29,    40,    41,    61,    62,    63,
      65,    75,    76,    77,    78,    79,    80,    90,    99,   100,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   121,    66,    66,    66,   211,
     215,    65,    76,   211,   214,    65,    76,   203,   211,    65,
     218,    64,    65,   206,   208,   210,    65,   130,   205,   208,
      37,    91,    92,   189,   178,   194,    92,   190,   178,   195,
      92,   191,   178,   196,    92,   192,   178,   197,   128,   130,
     135,   137,   138,   139,   141,   145,   148,   149,   150,   151,
     152,   153,    73,   160,   161,   166,    73,    73,   177,    61,
      66,   127,   128,   129,   130,   136,   137,   162,   163,   164,
     165,    71,    76,   119,    70,   211,   211,   124,   198,   177,
      65,   105,    65,   105,   105,   121,   128,   130,   137,   141,
     167,    62,    40,    41,    65,    70,   101,   102,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    88,   120,
     105,   107,    76,    81,    82,    77,    78,    42,    43,    44,
      45,    83,    84,    46,    47,    75,    85,    86,    48,    49,
      87,    66,    69,   218,   218,   214,   130,    92,    65,    65,
     130,    92,   210,    66,    66,   218,   210,    65,   205,   208,
      65,    88,   168,   177,   199,   177,   168,   177,   200,   177,
     168,   177,   201,   177,   168,   177,   202,   177,    68,   154,
     157,   203,   145,   155,   157,   211,   133,    74,   150,    67,
      67,    69,    67,    69,   148,    69,   174,    88,   160,     7,
      10,    11,    17,    23,    24,    27,    28,    31,    32,    34,
      37,    61,    64,    74,    94,   121,   123,   166,   175,   176,
     177,   178,   179,   180,   181,   182,   183,    65,    76,   205,
     211,   217,   218,   220,   221,   205,   211,   217,    65,    76,
     211,   217,   211,   217,    66,    69,    66,    69,    71,    71,
      76,   119,   177,   167,   167,    66,    65,    76,   217,   217,
      66,    66,   104,   119,   121,    72,    39,   119,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   110,   110,   111,
     111,   112,   113,   114,   115,   116,   121,    67,   119,   168,
      65,   168,    66,   218,   218,    66,    66,   210,    90,    73,
     119,   169,   177,   177,   177,   177,   118,   122,   156,   157,
     156,   155,   154,    74,   161,    74,   122,   174,    67,    65,
     122,   123,    67,    65,    68,   166,   175,    65,    65,   130,
     131,    67,    68,    74,   179,    74,   175,   218,   220,   221,
     130,   217,   130,    50,   164,    61,    71,    71,    66,    66,
     130,    73,   107,    66,    69,    71,    61,    64,   103,   103,
      68,    66,    66,    70,    72,   170,   171,   172,   173,    74,
     121,    68,    67,   123,   175,    67,    34,   121,   121,    65,
     175,    74,    66,    66,    66,   217,   170,   119,   118,   122,
     166,    69,   174,   169,    88,   173,    66,   175,    67,    65,
      66,    66,   121,   218,   174,    71,   171,    74,   175,   123,
     121,   175,   175,    66,    68,    74,   169,    67,    66,     8,
      67,    62,    70,    95,    96,    97,   123,    67,   175,    65,
      61,    66,    68,    69,    66,   121,    71,    67,    95,    97,
     175,    66,    62,    66,    68,    65,    67,    90,    98,   121,
      66,    69,    66,    67,    90
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
#define YYERROR		goto yyerrlab1

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
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
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
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
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
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

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
  register const char *yys = yystr;

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
  register char *yyd = yydest;
  register const char *yys = yysrc;

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
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
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
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

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
  /* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



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
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
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
	short *yyss1 = yyss;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

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
        case 2:
#line 559 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 3:
#line 561 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-1].value, +, yyvsp[0].value ); ;}
    break;

  case 20:
#line 616 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier )
	      HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    UNDEF_VAL( yyval.value );
	  ;}
    break;

  case 21:
#line 621 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 22:
#line 622 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.iv++; ;}
    break;

  case 23:
#line 623 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 24:
#line 627 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 25:
#line 628 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 26:
#line 629 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 27:
#line 630 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 28:
#line 631 "ctlib/parser.y"
    {;}
    break;

  case 29:
#line 631 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 30:
#line 632 "ctlib/parser.y"
    {;}
    break;

  case 31:
#line 632 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 32:
#line 633 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 33:
#line 634 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 34:
#line 635 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 35:
#line 639 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 36:
#line 640 "ctlib/parser.y"
    {;}
    break;

  case 37:
#line 644 "ctlib/parser.y"
    {;}
    break;

  case 38:
#line 645 "ctlib/parser.y"
    {;}
    break;

  case 39:
#line 649 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 40:
#line 650 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 41:
#line 651 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 42:
#line 653 "ctlib/parser.y"
    {
	    switch( yyvsp[-1].oper ) {
	      case '-' : UNARY_OP( yyval.value, -, yyvsp[0].value ); break;
	      case '~' : UNARY_OP( yyval.value, ~, yyvsp[0].value ); break;
	      case '!' : UNARY_OP( yyval.value, !, yyvsp[0].value ); break;
	      case '+' : yyval.value = yyvsp[0].value;               break;

	      case '*' :
	      case '&' :
	        yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_PTROP;
	        break;

	      default:
	        UNDEF_VAL( yyval.value );
	        break;
	    }
	  ;}
    break;

  case 43:
#line 670 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 44:
#line 671 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 45:
#line 675 "ctlib/parser.y"
    { yyval.oper = '&'; ;}
    break;

  case 46:
#line 676 "ctlib/parser.y"
    { yyval.oper = '*'; ;}
    break;

  case 47:
#line 677 "ctlib/parser.y"
    { yyval.oper = '+'; ;}
    break;

  case 48:
#line 678 "ctlib/parser.y"
    { yyval.oper = '-'; ;}
    break;

  case 49:
#line 679 "ctlib/parser.y"
    { yyval.oper = '~'; ;}
    break;

  case 50:
#line 680 "ctlib/parser.y"
    { yyval.oper = '!'; ;}
    break;

  case 51:
#line 684 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 52:
#line 685 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_CAST; ;}
    break;

  case 53:
#line 689 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 54:
#line 691 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, *, yyvsp[0].value ); ;}
    break;

  case 55:
#line 693 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, /, yyvsp[0].value );
	  ;}
    break;

  case 56:
#line 700 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, %, yyvsp[0].value );
	  ;}
    break;

  case 57:
#line 709 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 58:
#line 711 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, +, yyvsp[0].value ); ;}
    break;

  case 59:
#line 713 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, -, yyvsp[0].value ); ;}
    break;

  case 60:
#line 717 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 61:
#line 719 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <<, yyvsp[0].value ); ;}
    break;

  case 62:
#line 721 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >>, yyvsp[0].value ); ;}
    break;

  case 63:
#line 725 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 64:
#line 727 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <,  yyvsp[0].value ); ;}
    break;

  case 65:
#line 729 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >,  yyvsp[0].value ); ;}
    break;

  case 66:
#line 731 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <=, yyvsp[0].value ); ;}
    break;

  case 67:
#line 733 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >=, yyvsp[0].value ); ;}
    break;

  case 68:
#line 737 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 69:
#line 739 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ==, yyvsp[0].value ); ;}
    break;

  case 70:
#line 741 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, !=, yyvsp[0].value ); ;}
    break;

  case 71:
#line 745 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 72:
#line 747 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &, yyvsp[0].value ); ;}
    break;

  case 73:
#line 751 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 74:
#line 753 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ^, yyvsp[0].value ); ;}
    break;

  case 75:
#line 757 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 76:
#line 759 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, |, yyvsp[0].value ); ;}
    break;

  case 77:
#line 763 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 78:
#line 765 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &&, yyvsp[0].value ); ;}
    break;

  case 79:
#line 769 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 80:
#line 771 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ||, yyvsp[0].value ); ;}
    break;

  case 81:
#line 775 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 82:
#line 777 "ctlib/parser.y"
    { yyval.value = yyvsp[-4].value.iv ? yyvsp[-2].value : yyvsp[0].value; yyval.value.flags |= yyvsp[-4].value.flags; ;}
    break;

  case 83:
#line 781 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 84:
#line 782 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 85:
#line 786 "ctlib/parser.y"
    {;}
    break;

  case 86:
#line 787 "ctlib/parser.y"
    {;}
    break;

  case 87:
#line 788 "ctlib/parser.y"
    {;}
    break;

  case 88:
#line 789 "ctlib/parser.y"
    {;}
    break;

  case 89:
#line 790 "ctlib/parser.y"
    {;}
    break;

  case 90:
#line 791 "ctlib/parser.y"
    {;}
    break;

  case 91:
#line 792 "ctlib/parser.y"
    {;}
    break;

  case 92:
#line 793 "ctlib/parser.y"
    {;}
    break;

  case 93:
#line 794 "ctlib/parser.y"
    {;}
    break;

  case 94:
#line 795 "ctlib/parser.y"
    {;}
    break;

  case 95:
#line 796 "ctlib/parser.y"
    {;}
    break;

  case 96:
#line 800 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 97:
#line 801 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 98:
#line 805 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 100:
#line 811 "ctlib/parser.y"
    {;}
    break;

  case 101:
#line 849 "ctlib/parser.y"
    {;}
    break;

  case 102:
#line 850 "ctlib/parser.y"
    {;}
    break;

  case 103:
#line 851 "ctlib/parser.y"
    {;}
    break;

  case 104:
#line 852 "ctlib/parser.y"
    {;}
    break;

  case 105:
#line 860 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pTypedefList = NULL;
	    }
	    else {
	      if( yyvsp[-3].uval & T_TYPEDEF ) {
	        TypeSpec ts;
	        ts.tflags = yyvsp[-3].uval;
	        ts.ptr    = NULL;
	        if( (ts.tflags & ANY_TYPE_NAME) == 0 )
	          ts.tflags |= T_INT;
	        yyval.pTypedefList = typedef_list_new( ts, LL_new() );
	        LL_push( PSTATE->pCPI->typedef_lists, yyval.pTypedefList );
	        MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-2].pDecl );
	      }
	      else {
	        yyval.pTypedefList = NULL;
	        decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	      }
	    }
	  ;}
    break;

  case 106:
#line 882 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 107:
#line 888 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-4].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-2].pDecl );
	    else if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 108:
#line 899 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pTypedefList = NULL;
	    }
	    else {
	      if( yyvsp[-3].tspec.tflags & T_TYPEDEF ) {
	        if( (yyvsp[-3].tspec.tflags & ANY_TYPE_NAME) == 0 )
	          yyvsp[-3].tspec.tflags |= T_INT;
	        CTT_REFCOUNT_INC(yyvsp[-3].tspec.ptr);
	        yyval.pTypedefList = typedef_list_new( yyvsp[-3].tspec, LL_new() );
	        LL_push( PSTATE->pCPI->typedef_lists, yyval.pTypedefList );
	        MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-2].pDecl );
	      }
	      else {
	        yyval.pTypedefList = NULL;
	        decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	      }
	    }
	  ;}
    break;

  case 109:
#line 919 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 110:
#line 925 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-4].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-2].pDecl );
	    else if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 111:
#line 937 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 112:
#line 941 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 113:
#line 942 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 114:
#line 948 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 115:
#line 952 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 116:
#line 953 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 117:
#line 959 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 118:
#line 960 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 119:
#line 961 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;}
    break;

  case 124:
#line 975 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval; ;}
    break;

  case 125:
#line 976 "ctlib/parser.y"
    { yyval.uval = 0;  ;}
    break;

  case 129:
#line 986 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 130:
#line 987 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 131:
#line 988 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 132:
#line 989 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 133:
#line 993 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 134:
#line 994 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 135:
#line 995 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval;               ;}
    break;

  case 136:
#line 996 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 137:
#line 1001 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 138:
#line 1006 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 139:
#line 1011 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 140:
#line 1018 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 141:
#line 1019 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 142:
#line 1020 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 143:
#line 1024 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 144:
#line 1025 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 145:
#line 1026 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 146:
#line 1030 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 147:
#line 1031 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 148:
#line 1035 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 149:
#line 1040 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 150:
#line 1045 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 151:
#line 1052 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 152:
#line 1053 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 153:
#line 1054 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 154:
#line 1058 "ctlib/parser.y"
    { yyval.uval = T_TYPEDEF;  ;}
    break;

  case 155:
#line 1059 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 156:
#line 1060 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 157:
#line 1061 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 158:
#line 1062 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 159:
#line 1063 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 160:
#line 1067 "ctlib/parser.y"
    { yyval.uval = T_INT;      ;}
    break;

  case 161:
#line 1068 "ctlib/parser.y"
    { yyval.uval = T_CHAR;     ;}
    break;

  case 162:
#line 1069 "ctlib/parser.y"
    { yyval.uval = T_SHORT;    ;}
    break;

  case 163:
#line 1070 "ctlib/parser.y"
    { yyval.uval = T_LONG;     ;}
    break;

  case 164:
#line 1071 "ctlib/parser.y"
    { yyval.uval = T_FLOAT;    ;}
    break;

  case 165:
#line 1072 "ctlib/parser.y"
    { yyval.uval = T_DOUBLE;   ;}
    break;

  case 166:
#line 1073 "ctlib/parser.y"
    { yyval.uval = T_SIGNED;   ;}
    break;

  case 167:
#line 1074 "ctlib/parser.y"
    { yyval.uval = T_UNSIGNED; ;}
    break;

  case 168:
#line 1075 "ctlib/parser.y"
    { yyval.uval = T_VOID;     ;}
    break;

  case 169:
#line 1079 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 170:
#line 1080 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 171:
#line 1085 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      Struct *pStruct;
	      LinkedList strdecls = EX_STRDECL_LIST( yyvsp[-1].list );
	      pStruct = struct_new( NULL, 0, yyvsp[-3].context.uval, PSTATE->pragma.pack.current, strdecls );
	      pStruct->context = yyvsp[-3].context.ctx;
	      LL_push( PSTATE->pCPI->structs, pStruct );
	      yyval.tspec.tflags = yyvsp[-3].context.uval;
	      yyval.tspec.ptr = pStruct;
	    }
	  ;}
    break;

  case 172:
#line 1101 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      LinkedList strdecls = EX_STRDECL_LIST( yyvsp[-1].list );
	      Struct *pStruct = HT_get( PSTATE->pCPI->htStructs, yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-3].idOrType.hash );

	      if( pStruct == NULL ) {
	        pStruct = struct_new( yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-4].context.uval, PSTATE->pragma.pack.current, strdecls );
	        pStruct->context = yyvsp[-4].context.ctx;
	        LL_push( PSTATE->pCPI->structs, pStruct );
	        STORE_IN_HASH( htStructs, yyvsp[-3].idOrType, pStruct );
	      }
	      else {
	        DELETE_NODE( yyvsp[-3].idOrType );

	        if( pStruct->declarations == NULL ) {
	          pStruct->context      = yyvsp[-4].context.ctx;
	          pStruct->declarations = strdecls;
	          pStruct->pack         = PSTATE->pragma.pack.current;
	        }
	        else
	          LL_destroy( strdecls, (LLDestroyFunc) structdecl_delete );
	      }
	      yyval.tspec.tflags = yyvsp[-4].context.uval;
	      yyval.tspec.ptr = pStruct;
	    }
	  ;}
    break;

  case 173:
#line 1132 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      Struct *pStruct = HT_get( PSTATE->pCPI->htStructs, yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, yyvsp[0].idOrType.hash );

	      if( pStruct == NULL ) {
	        pStruct = struct_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, yyvsp[-1].context.uval, 0, NULL );
	        pStruct->context = yyvsp[-1].context.ctx;
	        LL_push( PSTATE->pCPI->structs, pStruct );
	        STORE_IN_HASH( htStructs, yyvsp[0].idOrType, pStruct );
	      }
	      else {
	        DELETE_NODE( yyvsp[0].idOrType );
	      }

	      yyval.tspec.tflags = yyvsp[-1].context.uval;
	      yyval.tspec.ptr = pStruct;
	    }
	  ;}
    break;

  case 174:
#line 1158 "ctlib/parser.y"
    {
	    yyval.context.uval     = yyvsp[0].uval;
	    yyval.context.ctx.pFI  = PSTATE->pFI;
	    yyval.context.ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 175:
#line 1166 "ctlib/parser.y"
    { yyval.uval = T_STRUCT; ;}
    break;

  case 176:
#line 1167 "ctlib/parser.y"
    { yyval.uval = T_UNION;  ;}
    break;

  case 177:
#line 1171 "ctlib/parser.y"
    { yyval.list = LL_new(); ;}
    break;

  case 178:
#line 1172 "ctlib/parser.y"
    { yyval.list = yyvsp[0].list; ;}
    break;

  case 179:
#line 1177 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      StructDeclaration *pSD = EX_STRUCT_DECL(yyvsp[0].pStructDecl);
	      CTT_REFCOUNT_INC(pSD->type.ptr);
	      yyval.list = LL_new();
	      LL_push(yyval.list, pSD);
	      LL_unshift(PSTATE->structDeclListsList, yyval.list);
	      CT_DEBUG(PARSER, ("unshifting struct declaration list (%p) (count=%d)",
	                        yyval.list, LL_count(PSTATE->structDeclListsList)));
	    }
	  ;}
    break;

  case 180:
#line 1192 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      StructDeclaration *pSD = EX_STRUCT_DECL(yyvsp[0].pStructDecl);
	      CTT_REFCOUNT_INC(pSD->type.ptr);
	      yyval.list = yyvsp[-1].list;
	      LL_push(yyval.list, pSD);
	    }
	  ;}
    break;

  case 181:
#line 1206 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 182:
#line 1207 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 183:
#line 1208 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 184:
#line 1213 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pStructDecl = NULL;
	    }
	    else {
	      yyval.pStructDecl = structdecl_new( yyvsp[0].tspec, NULL );
	      LL_unshift( PSTATE->structDeclList, yyval.pStructDecl );
	      CT_DEBUG( PARSER, ("unshifting unnamed struct declaration (%p)", yyval.pStructDecl) );
	    }
	  ;}
    break;

  case 185:
#line 1227 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pStructDecl = NULL;
	    }
	    else {
	      TypeSpec ts = { NULL, T_INT };
	      yyval.pStructDecl = structdecl_new( ts, LL_new() );
	      if( yyvsp[0].pDecl )
	        LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	      LL_unshift( PSTATE->structDeclList, yyval.pStructDecl );
	      CT_DEBUG( PARSER, ("unshifting struct declaration (%p) (count=%d)",
	                         yyval.pStructDecl, LL_count(PSTATE->structDeclList)) );
	    }
	  ;}
    break;

  case 186:
#line 1242 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pStructDecl = NULL;
	    }
	    else {
	      yyval.pStructDecl = yyvsp[-2].pStructDecl;
	      if( yyvsp[0].pDecl )
	        LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	    }
	  ;}
    break;

  case 187:
#line 1256 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pStructDecl = NULL;
	    }
	    else {
	      if( (yyvsp[-1].tspec.tflags & ANY_TYPE_NAME) == 0 )
	        yyvsp[-1].tspec.tflags |= T_INT;
	      yyval.pStructDecl = structdecl_new( yyvsp[-1].tspec, LL_new() );
	      if( yyvsp[0].pDecl )
	        LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	      LL_unshift( PSTATE->structDeclList, yyval.pStructDecl );
	      CT_DEBUG( PARSER, ("unshifting struct declaration (%p) (count=%d)",
	                         yyval.pStructDecl, LL_count(PSTATE->structDeclList)) );
	    }
	  ;}
    break;

  case 188:
#line 1272 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pStructDecl = NULL;
	    }
	    else {
	      yyval.pStructDecl = yyvsp[-2].pStructDecl;
	      if( yyvsp[0].pDecl )
	        LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	    }
	  ;}
    break;

  case 189:
#line 1286 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = yyvsp[-1].pDecl;
	      yyval.pDecl->bitfield_size = yyvsp[0].ival;
	    }
	  ;}
    break;

  case 190:
#line 1296 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( "", 0 );
	      yyval.pDecl->bitfield_size = yyvsp[0].ival;
	    }
	  ;}
    break;

  case 191:
#line 1309 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = yyvsp[-1].pDecl;
	      yyval.pDecl->bitfield_size = yyvsp[0].ival;
	    }
	  ;}
    break;

  case 192:
#line 1319 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( "", 0 );
	      yyval.pDecl->bitfield_size = yyvsp[0].ival;
	    }
	  ;}
    break;

  case 193:
#line 1331 "ctlib/parser.y"
    { yyval.ival = -1; ;}
    break;

  case 194:
#line 1332 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].ival; ;}
    break;

  case 195:
#line 1336 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].value.iv; ;}
    break;

  case 196:
#line 1341 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	      LL_destroy( yyvsp[-2].list, (LLDestroyFunc) enum_delete );
	    }
	    else {
	      EnumSpecifier *pEnum = enumspec_new( NULL, 0, yyvsp[-2].list );
	      pEnum->context = yyvsp[-4].context.ctx;
	      LL_push( PSTATE->pCPI->enums, pEnum );
	      yyval.tspec.tflags = T_ENUM;
	      yyval.tspec.ptr = pEnum;
	    }
	    PSTATE->curEnumList = NULL;
	  ;}
    break;

  case 197:
#line 1357 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      EnumSpecifier *pEnum = HT_get( PSTATE->pCPI->htEnums, yyvsp[-4].idOrType.str, yyvsp[-4].idOrType.len, yyvsp[-4].idOrType.hash );

	      if( pEnum == NULL ) {
	        pEnum = enumspec_new( yyvsp[-4].idOrType.str, yyvsp[-4].idOrType.len, yyvsp[-2].list );
	        pEnum->context = yyvsp[-5].context.ctx;
	        LL_push( PSTATE->pCPI->enums, pEnum );
	        STORE_IN_HASH( htEnums, yyvsp[-4].idOrType, pEnum );
	      }
	      else {
	        DELETE_NODE( yyvsp[-4].idOrType );

	        if( pEnum->enumerators == NULL ) {
	          enumspec_update( pEnum, yyvsp[-2].list );
	          pEnum->context = yyvsp[-5].context.ctx;
	        }
	        else
	          LL_destroy( yyvsp[-2].list, (LLDestroyFunc) enum_delete );
	      }

	      yyval.tspec.tflags = T_ENUM;
	      yyval.tspec.ptr = pEnum;
	    }

	    PSTATE->curEnumList = NULL;
	  ;}
    break;

  case 198:
#line 1389 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      EnumSpecifier *pEnum = HT_get( PSTATE->pCPI->htEnums, yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, yyvsp[0].idOrType.hash );

	      if( pEnum == NULL ) {
	        pEnum = enumspec_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, NULL );
	        pEnum->context = yyvsp[-1].context.ctx;
	        LL_push( PSTATE->pCPI->enums, pEnum );
	        STORE_IN_HASH( htEnums, yyvsp[0].idOrType, pEnum );
	      }
	      else {
	        DELETE_NODE( yyvsp[0].idOrType );
	      }

	      yyval.tspec.tflags = T_ENUM;
	      yyval.tspec.ptr = pEnum;
	    }
	  ;}
    break;

  case 199:
#line 1415 "ctlib/parser.y"
    {
	    yyval.context.ctx.pFI  = PSTATE->pFI;
	    yyval.context.ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 200:
#line 1423 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = PSTATE->curEnumList = LL_new();
	      if( yyvsp[0].pEnum->value.flags & V_IS_UNDEF ) {
	        yyvsp[0].pEnum->value.flags &= ~V_IS_UNDEF;
	        yyvsp[0].pEnum->value.iv     = 0;
	      }
	      LL_push( yyval.list, yyvsp[0].pEnum );
	    }
	  ;}
    break;

  case 201:
#line 1437 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      if( yyvsp[0].pEnum->value.flags & V_IS_UNDEF ) {
	        Enumerator *pEnum = LL_get( yyvsp[-2].list, -1 );
	        yyvsp[0].pEnum->value.flags = pEnum->value.flags;
	        yyvsp[0].pEnum->value.iv    = pEnum->value.iv + 1;
	      }
	      LL_push( yyvsp[-2].list, yyvsp[0].pEnum );
	      yyval.list = yyvsp[-2].list;
	    }
	  ;}
    break;

  case 202:
#line 1455 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pEnum = NULL;
	    }
	    else {
	      yyval.pEnum = enum_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, NULL );
	      STORE_IN_HASH( htEnumerators, yyvsp[0].idOrType, yyval.pEnum );
	    }
	  ;}
    break;

  case 203:
#line 1465 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pEnum = NULL;
	    }
	    else {
	      yyval.pEnum = enum_new( yyvsp[-2].idOrType.str, yyvsp[-2].idOrType.len, &yyvsp[0].value );
	      STORE_IN_HASH( htEnumerators, yyvsp[-2].idOrType, yyval.pEnum );
	    }
	  ;}
    break;

  case 208:
#line 1487 "ctlib/parser.y"
    {;}
    break;

  case 209:
#line 1488 "ctlib/parser.y"
    {;}
    break;

  case 210:
#line 1489 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 211:
#line 1490 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 212:
#line 1491 "ctlib/parser.y"
    {;}
    break;

  case 213:
#line 1492 "ctlib/parser.y"
    {;}
    break;

  case 214:
#line 1493 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 215:
#line 1494 "ctlib/parser.y"
    {;}
    break;

  case 216:
#line 1495 "ctlib/parser.y"
    {;}
    break;

  case 217:
#line 1496 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 218:
#line 1497 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 219:
#line 1498 "ctlib/parser.y"
    {;}
    break;

  case 220:
#line 1499 "ctlib/parser.y"
    {;}
    break;

  case 221:
#line 1500 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 222:
#line 1508 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 223:
#line 1509 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 224:
#line 1514 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier ) {
	      yyval.idOrType.str  = yyvsp[0].identifier->key;
	      yyval.idOrType.len  = yyvsp[0].identifier->keylen;
	      yyval.idOrType.hash = yyvsp[0].identifier->hash;
	      yyval.idOrType.node = yyvsp[0].identifier;
	    }
	    else {
	      yyval.idOrType.str  = NULL;
	      yyval.idOrType.len  = 0;
	      yyval.idOrType.hash = 0;
	      yyval.idOrType.node = NULL;
	    }
	  ;}
    break;

  case 225:
#line 1529 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.idOrType.str  = NULL;
	      yyval.idOrType.len  = 0;
	      yyval.idOrType.hash = 0;
	    }
	    else {
	      yyval.idOrType.str = ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier;
	      HASH_STR_LEN( yyval.idOrType.hash, yyval.idOrType.str, yyval.idOrType.len );
	    }
	    yyval.idOrType.node = NULL;
	  ;}
    break;

  case 226:
#line 1545 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      unsigned size;
	      u_32 flags;
	      (void) get_type_info( PSTATE->pCPC, &yyvsp[0].tspec, NULL, &size, NULL, NULL, &flags );
	      yyval.value.iv    = size;
	      yyval.value.flags = 0;
	      if( flags & T_HASBITFIELD )
	        yyval.value.flags |= V_IS_UNSAFE_BITFIELD;
	      if( flags & T_UNSAFE_VAL )
	        yyval.value.flags |= V_IS_UNSAFE;
	    }
	  ;}
    break;

  case 227:
#line 1559 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      if( yyvsp[0].absDecl.pointer_flag ) {
	        yyval.value.iv = PSTATE->pCPC->ptr_size * yyvsp[0].absDecl.multiplicator;
	        yyval.value.flags = 0;
	      }
	      else {
	        unsigned size;
	        u_32 flags;
	        (void) get_type_info( PSTATE->pCPC, &yyvsp[-1].tspec, NULL, &size, NULL, NULL, &flags );
	        yyval.value.iv = size * yyvsp[0].absDecl.multiplicator;
	        yyval.value.flags = 0;
	        if( flags & T_HASBITFIELD )
	          yyval.value.flags |= V_IS_UNSAFE_BITFIELD;
	        if( flags & T_UNSAFE_VAL )
	          yyval.value.flags |= V_IS_UNSAFE;
	      }
	    }
	  ;}
    break;

  case 228:
#line 1579 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = PSTATE->pCPC->int_size;
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 229:
#line 1586 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
	              PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 233:
#line 1602 "ctlib/parser.y"
    {;}
    break;

  case 241:
#line 1622 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[0].idOrType ); ;}
    break;

  case 251:
#line 1642 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-2].idOrType ); ;}
    break;

  case 269:
#line 1681 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-1].idOrType ); ;}
    break;

  case 280:
#line 1707 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 281:
#line 1708 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 282:
#line 1709 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 283:
#line 1710 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 284:
#line 1711 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 285:
#line 1712 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 286:
#line 1713 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 287:
#line 1714 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 288:
#line 1715 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 289:
#line 1716 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 290:
#line 1718 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 291:
#line 1718 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 292:
#line 1719 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 293:
#line 1719 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 294:
#line 1720 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 295:
#line 1720 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 296:
#line 1721 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 297:
#line 1721 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 298:
#line 1722 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 299:
#line 1722 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 300:
#line 1724 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 301:
#line 1724 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 302:
#line 1725 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 303:
#line 1725 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 304:
#line 1726 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 305:
#line 1726 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 306:
#line 1727 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 307:
#line 1727 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 308:
#line 1728 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 309:
#line 1728 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 310:
#line 1732 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 311:
#line 1733 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 312:
#line 1737 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 313:
#line 1738 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 314:
#line 1743 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	      LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	      CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (%p) (count=%d)",
	                         yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	    }
	  ;}
    break;

  case 315:
#line 1755 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( ((Typedef *) yyvsp[-1].tspec.ptr)->pDecl->identifier, 0 );
	      if( yyvsp[0].list )
	        LL_delete( LL_splice( yyval.pDecl->array, 0, 0, EX_ARRAY( yyvsp[0].list ) ) );
	      LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	      CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (%p) (count=%d)",
	                         yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	    }
	  ;}
    break;

  case 316:
#line 1768 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 317:
#line 1775 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 318:
#line 1777 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 319:
#line 1783 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 320:
#line 1791 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 321:
#line 1793 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 322:
#line 1803 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 323:
#line 1805 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 324:
#line 1811 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 325:
#line 1817 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 326:
#line 1823 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 327:
#line 1831 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 328:
#line 1833 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 329:
#line 1838 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 330:
#line 1846 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	      LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	      CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (%p) (count=%d)",
	                         yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	    }
	  ;}
    break;

  case 331:
#line 1857 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 332:
#line 1861 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 333:
#line 1862 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 334:
#line 1866 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 335:
#line 1868 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 336:
#line 1874 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 337:
#line 1883 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 338:
#line 1887 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 339:
#line 1889 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 340:
#line 1897 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier ) {
	      yyval.pDecl = decl_new( yyvsp[0].identifier->key, yyvsp[0].identifier->keylen );
	      HN_delete( EX_NODE( yyvsp[0].identifier ) );
	      LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	      CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (%p) (count=%d)",
	                         yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	    }
	    else {
	      yyval.pDecl = NULL;
	    }
	  ;}
    break;

  case 341:
#line 1909 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 342:
#line 1913 "ctlib/parser.y"
    {;}
    break;

  case 343:
#line 1914 "ctlib/parser.y"
    {;}
    break;

  case 344:
#line 1915 "ctlib/parser.y"
    {;}
    break;

  case 345:
#line 1920 "ctlib/parser.y"
    {
	    if( yyvsp[-3].pDecl )
	      decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  ;}
    break;

  case 346:
#line 1924 "ctlib/parser.y"
    {;}
    break;

  case 347:
#line 1926 "ctlib/parser.y"
    {
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;

  case 348:
#line 1933 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 349:
#line 1934 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 350:
#line 1936 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag  = 0;
	    yyval.absDecl.multiplicator = 1;
	    if( yyvsp[0].list ) {
	      Value *pValue;
	      LL_foreach( pValue, yyvsp[0].list )
	        yyval.absDecl.multiplicator *= pValue->iv;
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	    }
	  ;}
    break;

  case 351:
#line 1949 "ctlib/parser.y"
    { yyval.list = yyvsp[0].list;   ;}
    break;

  case 352:
#line 1950 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 353:
#line 1951 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 354:
#line 1956 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = LL_new();
	      LL_unshift( PSTATE->arrayList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting array (%p) (count=%d)",
	                         yyval.list, LL_count(PSTATE->arrayList)) );
	      LL_push( yyval.list, value_new( 0, V_IS_UNDEF ) );
	      CT_DEBUG( PARSER, ("array dimension => flexible array member") );
	    }
	  ;}
    break;

  case 355:
#line 1970 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = LL_new();
	      LL_unshift( PSTATE->arrayList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting array (%p) (count=%d)",
	                         yyval.list, LL_count(PSTATE->arrayList)) );
	      LL_push( yyval.list, value_new( yyvsp[-1].value.iv, yyvsp[-1].value.flags ) );
	      CT_DEBUG( PARSER, ("array dimension => %ld", yyvsp[-1].value.iv) );
	    }
	  ;}
    break;

  case 356:
#line 1983 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 357:
#line 1985 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      if( yyvsp[-3].list ) {
	        yyval.list = yyvsp[-3].list;
	      }
	      else {
	        yyval.list = LL_new();
	        LL_unshift( PSTATE->arrayList, yyval.list );
	        CT_DEBUG( PARSER, ("unshifting array (%p) (count=%d)",
	                           yyval.list, LL_count(PSTATE->arrayList)) );
	      }
	      LL_push( yyval.list, value_new( yyvsp[-1].value.iv, yyvsp[-1].value.flags ) );
	      CT_DEBUG( PARSER, ("array dimension => %ld", yyvsp[-1].value.iv) );
	    }
	  ;}
    break;

  case 358:
#line 2004 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      if( yyvsp[-3].list ) {
	        yyval.list = yyvsp[-3].list;
	      }
	      else {
	        yyval.list = LL_new();
	        LL_unshift( PSTATE->arrayList, yyval.list );
	        CT_DEBUG( PARSER, ("unshifting array (%p) (count=%d)",
	                           yyval.list, LL_count(PSTATE->arrayList)) );
	      }
	      LL_push( yyval.list, value_new( 0, 0 ) );
	      CT_DEBUG( PARSER, ("array dimension => *" ) );
	    }
	  ;}
    break;

  case 359:
#line 2026 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 360:
#line 2031 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 361:
#line 2036 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 362:
#line 2041 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 363:
#line 2048 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 364:
#line 2049 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 365:
#line 2051 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag  = 0;
	    yyval.absDecl.multiplicator = 1;
	    if( yyvsp[-1].list ) {
	      Value *pValue;
	      LL_foreach( pValue, yyvsp[-1].list )
	        yyval.absDecl.multiplicator *= pValue->iv;
	      LL_destroy( EX_ARRAY( yyvsp[-1].list ), (LLDestroyFunc) value_delete );
	    }
	  ;}
    break;

  case 366:
#line 2062 "ctlib/parser.y"
    {
	    yyval.absDecl = yyvsp[-2].absDecl;
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 4523 "ctlib/parser.c"

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
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 2069 "ctlib/parser.y"



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

static inline int c_lex( void *pYYLVAL, ParserState *pState )
{
  YYSTYPE *plval = (YYSTYPE *) pYYLVAL;
  int rval, token;
  struct lexer_state *pLexer = pState->pLexer;
  dUCPP(pState->cpp);

  CT_DEBUG( CLEXER, ("parser.y::c_lex()") );

  while( (rval = lex( aUCPP_ pLexer )) < CPPERR_EOF ) {
    if( rval ) {
      CT_DEBUG( CLEXER, ("lex() returned %d", rval) );
      continue;
    }

    token = pLexer->ctok->type;

    switch( token ) {
      case NONE:
        CT_DEBUG( CLEXER, ("token-type => NONE") );
        break;

      case COMMENT:
        CT_DEBUG( CLEXER, ("token-type => COMMENT => [%s]", pLexer->ctok->name) );
        break;

      case NEWLINE:
        CT_DEBUG( CLEXER, ("token-type => NEWLINE") );
        break;

      case BUNCH:
        CT_DEBUG( CLEXER, ("token-type => BUNCH => [%s]", pLexer->ctok->name) );
        break;

      case CONTEXT:
        CT_DEBUG( CLEXER, ("token-type => CONTEXT => [%s]", pLexer->ctok->name) );
        {
          FileInfo *pFI;
          size_t len = strlen( pLexer->ctok->name );

          CT_DEBUG( CLEXER, ("new context: file '%s', line %ld",
                             pLexer->ctok->name, pLexer->ctok->line) );

          pFI = HT_get( pState->pCPI->htFiles, pLexer->ctok->name, len, 0 );

          if( pFI == NULL ) {
            pFI = fileinfo_new( pLexer->input, pLexer->ctok->name, len );
            HT_store( pState->pCPI->htFiles, pLexer->ctok->name, len, 0, pFI );
          }

          pState->pFI = pFI;
        }
        break;

      case NUMBER:
        CT_DEBUG( CLEXER, ("token-type => NUMBER => [%s]", pLexer->ctok->name) );
        plval->value.iv = strtol( pLexer->ctok->name, NULL, 0 );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("constant: %s -> %ld", pLexer->ctok->name, plval->value.iv) );
        return CONSTANT;

      case STRING:
        CT_DEBUG( CLEXER, ("token-type => STRING => [%s]", pLexer->ctok->name) );
        plval->value.iv = string_size( pLexer->ctok->name );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("string literal: %s -> %ld", pLexer->ctok->name, plval->value.iv) );
        return STRING_LITERAL;

      case CHAR:
        CT_DEBUG( CLEXER, ("token-type => CHAR => [%s]", pLexer->ctok->name) );
        plval->value.iv = get_char_value( pLexer->ctok->name );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("constant: %s -> %ld", pLexer->ctok->name, plval->value.iv) );
        return CONSTANT;

      case PRAGMA:
        CT_DEBUG( CLEXER, ("token-type => PRAGMA") );
        CT_DEBUG( CLEXER, ("line %ld: <#pragma>", pLexer->line) );

        pState->pragma.str = pLexer->ctok->name;
        pragma_parse( &pState->pragma );

        CT_DEBUG( CLEXER, ("current packing: %d\n", pState->pragma.pack.current) );

        break;

      case NAME:
        CT_DEBUG( CLEXER, ("token-type => NAME => [%s]", pLexer->ctok->name) );
        {
          char *tokstr = pLexer->ctok->name;
          const CKeywordToken *ckt;

#include "t_parser.c"

          unknown:

          if( (ckt = HT_get( pState->pCPC->keyword_map, tokstr, 0, 0 )) != NULL ) {
            if( ckt->token == SKIP_TOK ) {
              CT_DEBUG( CLEXER, ("skipping token '%s' in line %ld", tokstr, pLexer->line) );
              break;
            }

            return ckt->token;
          }

          return check_type( pYYLVAL, pState, tokstr );
        }

      default:
        CT_DEBUG( CLEXER, ("token-type => %d", token) );
        if( (rval = tokentab[token]) != 0 ) {
          return rval;
        }
        else {
          CT_DEBUG( CLEXER, ("unhandled token in line %ld: <%2d>", pLexer->line, token) );
        }
        break;
    }
  }

  CT_DEBUG( CLEXER, ("EOF!") );

  return 0;
}

/*******************************************************************************
*
*   ROUTINE: ex_object
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

#ifdef CTYPE_DEBUGGING
static void *ex_object( char *type, LinkedList list, void *object )
#else
static inline void *ex_object( LinkedList list, void *object )
#endif
{
  void *obj;
  int   item = 0;

  CT_DEBUG( PARSER, ("ex_object( type=\"%s\", list=%p, object=%p )",
                     type, list, object) );

  LL_foreach( obj, list ) {
    if( obj == object )
      break;
    item++;
  }

  if( obj != object ) {
    CT_DEBUG( PARSER, ("%s (%p) not found in ex_object()", type, object) );
    return object;
  }

  CT_DEBUG( PARSER, ("%s found (item=%d) in ex_object()", type, item) );

  return LL_extract( list, item );
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

static void parser_error( ParserState *pState, char *msg )
{
  push_error( pState->pCPI, "%s, line %ld: %s",
              pState->pFI ? pState->pFI->name : "[unknown]",
              pState->pLexer->ctok->line, msg );
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

static inline int get_char_value( char *s )
{
  while( *s && *s != '\'' ) s++;

  if( *++s != '\\' )
    return (int)*s;

  switch( *++s ) {
    case '0' :
    case '1' :
    case '2' :
    case '3' : return (int) strtol( s, NULL, 8 );
    case 'a' : return (int) '\a';
    case 'b' : return (int) '\b';
    case 'f' : return (int) '\f';
    case 'h' : return (int) strtol( ++s, NULL, 16 );
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

static inline int string_size( char *s )
{
  int size, count;

  while( *s && *s != '\"' ) s++;

  for( s++, size=0; *s; size++ ) {
    if( *s == '\"' )
      break;

    if( *s++ != '\\' )
      continue;

    if( *s == 'x' ) {
      count = 0;
      do s++; while( count++ < 2
                     && ( (*s >= '0' && *s <= '9')
                       || (*s >= 'a' && *s <= 'f')
                       || (*s >= 'A' && *s <= 'F') ) );
      continue;
    }

    if( *s >= '0' && *s <= '7' ) {
      count = 0;
      do s++; while( count++ < 2 && *s >= '0' && *s <= '7' );
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

static inline int check_type( void *pYYLVAL, ParserState *pState, char *s )
{
  YYSTYPE    *plval = (YYSTYPE *) pYYLVAL;
  Enumerator *pEnum;
  Typedef    *pTypedef;
  HashSum     hash;
  int         len;

  CT_DEBUG( CLEXER, ("check_type( \"%s\" )", s) );

  HASH_STR_LEN( hash, s, len );

  pEnum = HT_get( pState->pCPI->htEnumerators, s, len, hash );

  if( pEnum ) {
    CT_DEBUG( CLEXER, ("enum found!") );
    plval->value = pEnum->value;
    return CONSTANT;
  }

  pTypedef = HT_get( pState->pCPI->htTypedefs, s, len, hash );

  if( pTypedef ) {
    CT_DEBUG( CLEXER, ("typedef found!") );
    plval->tspec.tflags = T_TYPE;
    plval->tspec.ptr    = pTypedef;
    return TYPE_NAME;
  }

  if( pState->flags & F_LOCAL ) {
    plval->identifier = NULL;
  }
  else {
    plval->identifier = HN_new( s, len, hash );

    LL_unshift( pState->nodeList, plval->identifier );
    CT_DEBUG( CLEXER, ("unshifting identifier \"%s\" (%p) (count=%d)",
                       plval->identifier->key, plval->identifier,
                       LL_count(pState->nodeList)) );
  }

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

const CKeywordToken *get_c_keyword_token( const char *name )
{
#include "t_ckeytok.c"
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

const CKeywordToken *get_skip_token( void )
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

ParserState *c_parser_new( const CParseConfig *pCPC, CParseInfo *pCPI,
                           pUCPP_ struct lexer_state *pLexer )
{
  ParserState *pState;

#ifdef CTYPE_DEBUGGING
#ifdef YYDEBUG
  extern int pragma_debug;
  c_debug = pragma_debug = DEBUG_FLAG( YACC ) ? 1 : 0;
#endif
#endif

  if( pCPC == NULL || pCPI == NULL || pLexer == NULL )
    return NULL;

  AllocF( ParserState *, pState, sizeof( ParserState ) );

  pState->pCPI                = pCPI;
  pState->pCPC                = pCPC;
  pState->pLexer              = pLexer;
#ifdef UCPP_REENTRANT
  pState->cpp                 = cpp;
#endif

  pState->flags               = 0;
  pState->pFI                 = NULL;
  pState->curEnumList         = NULL;

  pState->nodeList            = LL_new();
  pState->declaratorList      = LL_new();
  pState->arrayList           = LL_new();
  pState->structDeclList      = LL_new();
  pState->structDeclListsList = LL_new();

  pragma_init( &pState->pragma );

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

int c_parser_run( ParserState *pState )
{
  return c_parse( (void *) pState );
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

void c_parser_delete( ParserState *pState )
{
  LinkedList list;

#ifdef CTYPE_DEBUGGING
  int count;
#endif

  if( pState == NULL )
    return;

  /*-----------------------*/
  /* Cleanup pragma parser */
  /*-----------------------*/

  pragma_free( &pState->pragma );

  /*---------------------*/
  /* Cleanup Enumerators */
  /*---------------------*/

#ifdef CTYPE_DEBUGGING
  if( DEBUG_FLAG( PARSER ) ) {
    CT_DEBUG( PARSER, ("cleanup enumerator(s)") );
    if( pState->curEnumList && (count = LL_count( pState->curEnumList )) > 0 )
      CT_DEBUG( PARSER, ("%d enumerator(s) still in memory, cleaning up...", count) );
  }
#endif

  LL_destroy( pState->curEnumList, (LLDestroyFunc) enum_delete );

  /*---------------*/
  /* Cleanup Nodes */
  /*---------------*/

#ifdef CTYPE_DEBUGGING
  if( DEBUG_FLAG( PARSER ) ) {
    CT_DEBUG( PARSER, ("cleanup node(s)") );
    if( (count = LL_count( pState->nodeList )) > 0 ) {
      HashNode hn;
      CT_DEBUG( PARSER, ("%d node(s) still in memory, cleaning up...", count) );
      LL_foreach( hn, pState->nodeList )
        CT_DEBUG( PARSER, ("[%s]", hn->key) );
    }
  }
#endif

  LL_destroy( pState->nodeList, (LLDestroyFunc) HN_delete );

  /*---------------------*/
  /* Cleanup Declarators */
  /*---------------------*/

#ifdef CTYPE_DEBUGGING
  if( DEBUG_FLAG( PARSER ) ) {
    CT_DEBUG( PARSER, ("cleanup declarator(s)") );
    if( (count = LL_count( pState->declaratorList )) > 0 )
      CT_DEBUG( PARSER, ("%d declarator(s) still in memory, cleaning up...", count) );
  }
#endif

  LL_destroy( pState->declaratorList, (LLDestroyFunc) decl_delete );

  /*----------------*/
  /* Cleanup Arrays */
  /*----------------*/

#ifdef CTYPE_DEBUGGING
  if( DEBUG_FLAG( PARSER ) ) {
    Value *pVal;
    CT_DEBUG( PARSER, ("cleanup array(s)") );
    if( (count = LL_count( pState->arrayList )) > 0 ) {
      CT_DEBUG( PARSER, ("%d array(s) still in memory, cleaning up...", count) );
      LL_foreach( list, pState->arrayList ) {
        CT_DEBUG( PARSER, ("[ARRAY=%p]", list) );
        LL_foreach( pVal, list )
          CT_DEBUG( PARSER, ("[value=%ld,flags=0x%08lX]",
                             pVal->iv, (unsigned long) pVal->flags) );
      }
    }
  }
#endif

  LL_foreach( list, pState->arrayList )
    LL_destroy( list, (LLDestroyFunc) value_delete );

  LL_destroy( pState->arrayList, NULL );

  /*----------------------------*/
  /* Cleanup Struct Declarators */
  /*----------------------------*/

#ifdef CTYPE_DEBUGGING
  if( DEBUG_FLAG( PARSER ) ) {
    CT_DEBUG( PARSER, ("cleanup struct declarator(s)") );
    if( (count = LL_count( pState->structDeclList )) > 0 )
      CT_DEBUG( PARSER, ("%d struct declarator(s) still in memory, cleaning up...", count) );
  }
#endif

  LL_destroy( pState->structDeclList, (LLDestroyFunc) structdecl_delete );

  /*---------------------------------*/
  /* Cleanup Struct Declarator Lists */
  /*---------------------------------*/

#ifdef CTYPE_DEBUGGING
  if( DEBUG_FLAG( PARSER ) ) {
    CT_DEBUG( PARSER, ("cleanup struct declarator list(s)") );
    if( (count = LL_count( pState->structDeclListsList )) > 0 )
      CT_DEBUG( PARSER, ("%d struct declarator list(s) still in memory, cleaning up...", count) );
  }
#endif

  LL_foreach( list, pState->structDeclListsList )
    LL_destroy( list, (LLDestroyFunc) structdecl_delete );

  LL_destroy( pState->structDeclListsList, NULL );

  Free( pState );
}


