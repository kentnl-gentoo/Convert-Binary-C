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
     SKIP_TOK = 292,
     PTR_OP = 293,
     INC_OP = 294,
     DEC_OP = 295,
     LEFT_OP = 296,
     RIGHT_OP = 297,
     LE_OP = 298,
     GE_OP = 299,
     EQ_OP = 300,
     NE_OP = 301,
     AND_OP = 302,
     OR_OP = 303,
     ELLIPSIS = 304,
     MUL_ASSIGN = 305,
     DIV_ASSIGN = 306,
     MOD_ASSIGN = 307,
     ADD_ASSIGN = 308,
     SUB_ASSIGN = 309,
     LEFT_ASSIGN = 310,
     RIGHT_ASSIGN = 311,
     AND_ASSIGN = 312,
     XOR_ASSIGN = 313,
     OR_ASSIGN = 314,
     IDENTIFIER = 315,
     STRING_LITERAL = 316,
     CONSTANT = 317,
     TYPE_NAME = 318
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
#define SKIP_TOK 292
#define PTR_OP 293
#define INC_OP 294
#define DEC_OP 295
#define LEFT_OP 296
#define RIGHT_OP 297
#define LE_OP 298
#define GE_OP 299
#define EQ_OP 300
#define NE_OP 301
#define AND_OP 302
#define OR_OP 303
#define ELLIPSIS 304
#define MUL_ASSIGN 305
#define DIV_ASSIGN 306
#define MOD_ASSIGN 307
#define ADD_ASSIGN 308
#define SUB_ASSIGN 309
#define LEFT_ASSIGN 310
#define RIGHT_ASSIGN 311
#define AND_ASSIGN 312
#define XOR_ASSIGN 313
#define OR_ASSIGN 314
#define IDENTIFIER 315
#define STRING_LITERAL 316
#define CONSTANT 317
#define TYPE_NAME 318




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
* $Project: Convert-Binary-C $
* $Author: mhx $
* $Date: 2003/01/06 03:40:49 +0100 $
* $Revision: 18 $
* $Snapshot: /Convert-Binary-C/0.07 $
* $Source: /ctlib/parser.y $
*
********************************************************************************
*
* Copyright (c) 2002-2003 Marcus Holland-Moritz. All rights reserved.
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
#include "fileinfo.h"
#include "parser.h"
#include "pragma.h"

#include "util/list.h"
#include "util/memalloc.h"

#include "ucpp/cpp.h"


/*===== DEFINES ==============================================================*/

/* ADDITIONAL BISON CONFIGURATION */

#define YYPARSE_PARAM pState
#define YYLEX_PARAM   pState
#define YYERROR_VERBOSE

/*
 * Bison version >= 1.31 is needed for YYFPRINTF
 */
#if YYDEBUG && defined CTYPE_DEBUGGING
#define YYFPRINTF BisonDebugFunc
#endif

#define c_error( msg )    \
        parser_error( PSTATE, msg )


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
	  CT_DEBUG( PARSER, ("making new typedef => %s (list 0x%08X)",            \
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

struct _ParserState {

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

  struct lexer_state *pLexer;

  char               *filename;

  u_32                flags;

};

typedef struct {
  char    *str;
  int      len;
  HashSum  hash;
  HashNode node;
} IdOrTypeName;


/*===== STATIC FUNCTION PROTOTYPES ===========================================*/

static int   c_lex( void *pYYLVAL, ParserState *pState );

static int   get_char_value( char *s );
static int   string_size( char *s );
static int   check_type( void *pVVLVAL, ParserState *pState, char *s );
static void  parser_error( ParserState *pState, char *msg );

#ifdef CTYPE_DEBUGGING
static void *ex_object( char *type, LinkedList list, void *object );
#else
static void *ex_object( LinkedList list, void *object );
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
#line 384 "ctlib/parser.y"
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
  signed long        ival;
  unsigned long      uval;
  char               oper;
  IdOrTypeName       idOrType;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 565 "ctlib/parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 577 "ctlib/parser.c"

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
#define YYFINAL  115
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2143

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  120
/* YYNRULES -- Number of rules. */
#define YYNRULES  343
/* YYNRULES -- Number of states. */
#define YYNSTATES  556

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,     2,     2,    79,    72,     2,
      64,    65,    73,    74,    71,    75,    68,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    85,    87,
      80,    86,    81,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,    82,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    83,    70,    76,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    20,
      25,    29,    34,    35,    40,    41,    46,    49,    52,    59,
      67,    69,    71,    73,    77,    79,    82,    85,    88,    91,
      96,    98,   100,   102,   104,   106,   108,   110,   115,   117,
     121,   125,   129,   131,   135,   139,   141,   145,   149,   151,
     155,   159,   163,   167,   169,   173,   177,   179,   183,   185,
     189,   191,   195,   197,   201,   203,   207,   209,   215,   217,
     221,   223,   225,   227,   229,   231,   233,   235,   237,   239,
     241,   243,   245,   249,   251,   252,   254,   257,   260,   263,
     266,   270,   274,   279,   283,   287,   292,   294,   296,   298,
     300,   302,   304,   306,   309,   312,   314,   317,   319,   321,
     323,   325,   327,   330,   333,   336,   339,   341,   344,   347,
     350,   353,   356,   359,   361,   364,   367,   369,   372,   375,
     377,   379,   382,   385,   388,   390,   393,   396,   398,   400,
     402,   404,   406,   408,   410,   412,   414,   416,   418,   420,
     422,   424,   426,   428,   430,   435,   441,   444,   446,   448,
     450,   453,   456,   459,   462,   464,   467,   471,   474,   478,
     481,   483,   486,   488,   489,   491,   494,   499,   505,   508,
     510,   514,   517,   519,   523,   525,   529,   531,   535,   537,
     540,   543,   546,   548,   551,   554,   556,   559,   562,   565,
     567,   570,   573,   575,   579,   581,   583,   585,   588,   590,
     593,   594,   597,   601,   606,   608,   611,   616,   617,   620,
     622,   625,   629,   632,   634,   636,   638,   640,   642,   644,
     648,   653,   657,   660,   664,   668,   673,   675,   678,   680,
     683,   686,   692,   700,   706,   712,   720,   730,   734,   737,
     740,   744,   745,   747,   749,   752,   754,   756,   757,   761,
     762,   767,   768,   773,   774,   779,   780,   785,   786,   790,
     791,   796,   797,   802,   803,   808,   809,   814,   815,   820,
     821,   827,   828,   834,   835,   841,   842,   848,   850,   852,
     854,   856,   858,   861,   863,   865,   868,   872,   876,   881,
     883,   888,   894,   897,   901,   905,   910,   915,   917,   921,
     923,   925,   927,   930,   934,   937,   941,   946,   948,   952,
     954,   957,   961,   966,   970,   975,   977,   979,   981,   983,
     986,   990,   993,   997,  1001,  1006,  1011,  1013,  1016,  1019,
    1023,  1027,  1031,  1035
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     170,     0,    -1,    61,    -1,    89,    61,    -1,    60,    -1,
      62,    -1,    89,    -1,    64,   112,    65,    -1,    90,    -1,
      91,    66,   112,    67,    -1,    91,    64,    65,    -1,    91,
      64,    95,    65,    -1,    -1,    91,    92,    68,    94,    -1,
      -1,    91,    93,    38,    94,    -1,    91,    39,    -1,    91,
      40,    -1,    64,   154,    65,    69,   157,    70,    -1,    64,
     154,    65,    69,   157,    71,    70,    -1,    60,    -1,    63,
      -1,   110,    -1,    95,    71,   110,    -1,    91,    -1,    39,
      96,    -1,    40,    96,    -1,    97,    98,    -1,    29,    96,
      -1,    29,    64,   154,    65,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    96,    -1,
      64,   154,    65,    98,    -1,    98,    -1,    99,    73,    98,
      -1,    99,    78,    98,    -1,    99,    79,    98,    -1,    99,
      -1,   100,    74,    99,    -1,   100,    75,    99,    -1,   100,
      -1,   101,    41,   100,    -1,   101,    42,   100,    -1,   101,
      -1,   102,    80,   101,    -1,   102,    81,   101,    -1,   102,
      43,   101,    -1,   102,    44,   101,    -1,   102,    -1,   103,
      45,   102,    -1,   103,    46,   102,    -1,   103,    -1,   104,
      72,   103,    -1,   104,    -1,   105,    82,   104,    -1,   105,
      -1,   106,    83,   105,    -1,   106,    -1,   107,    47,   106,
      -1,   107,    -1,   108,    48,   107,    -1,   108,    -1,   108,
      84,   112,    85,   109,    -1,   109,    -1,    96,   111,   110,
      -1,    86,    -1,    50,    -1,    51,    -1,    52,    -1,    53,
      -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,
      -1,    59,    -1,   110,    -1,   112,    71,   110,    -1,   109,
      -1,    -1,   112,    -1,   126,    87,    -1,   127,    87,    -1,
     117,    87,    -1,   116,    87,    -1,   120,   197,   155,    -1,
     121,   197,   155,    -1,   116,    71,   197,   155,    -1,   118,
     189,   155,    -1,   119,   189,   155,    -1,   117,    71,   189,
     155,    -1,   124,    -1,   126,    -1,   130,    -1,   125,    -1,
     127,    -1,   131,    -1,   132,    -1,   121,   132,    -1,   120,
     122,    -1,   123,    -1,   121,   123,    -1,   132,    -1,   123,
      -1,    19,    -1,    36,    -1,    30,    -1,   120,   133,    -1,
     125,   132,    -1,   124,   122,    -1,   124,   133,    -1,   133,
      -1,   121,   133,    -1,   125,   123,    -1,   125,   133,    -1,
     120,   134,    -1,   127,   132,    -1,   126,   122,    -1,   134,
      -1,   121,   134,    -1,   127,   123,    -1,   135,    -1,   121,
     135,    -1,   127,   123,    -1,   128,    -1,   131,    -1,   131,
     132,    -1,   120,    63,    -1,   130,   122,    -1,    63,    -1,
     121,    63,    -1,   131,   123,    -1,    14,    -1,    16,    -1,
      33,    -1,     3,    -1,    13,    -1,    35,    -1,     5,    -1,
      15,    -1,    21,    -1,     9,    -1,    20,    -1,     4,    -1,
      25,    -1,    22,    -1,    26,    -1,   135,    -1,   146,    -1,
     136,    69,   137,    70,    -1,   136,   153,    69,   137,    70,
      -1,   136,   153,    -1,     6,    -1,    18,    -1,   138,    -1,
     137,   138,    -1,   141,    87,    -1,   140,    87,    -1,   139,
      87,    -1,   129,    -1,   121,   143,    -1,   140,    71,   143,
      -1,   119,   142,    -1,   141,    71,   142,    -1,   189,   144,
      -1,   145,    -1,   197,   144,    -1,   145,    -1,    -1,   145,
      -1,    85,   113,    -1,    12,    69,   147,    70,    -1,    12,
     153,    69,   147,    70,    -1,    12,   153,    -1,   148,    -1,
     147,    71,   148,    -1,   147,    71,    -1,   153,    -1,   153,
      86,   113,    -1,   150,    -1,   150,    71,    49,    -1,   151,
      -1,   150,    71,   151,    -1,   118,    -1,   118,   203,    -1,
     118,   197,    -1,   118,   191,    -1,   120,    -1,   120,   203,
      -1,   120,   197,    -1,   119,    -1,   119,   203,    -1,   119,
     197,    -1,   119,   191,    -1,   121,    -1,   121,   203,    -1,
     121,   197,    -1,    60,    -1,   152,    71,    60,    -1,    60,
      -1,    63,    -1,   119,    -1,   119,   203,    -1,   121,    -1,
     121,   203,    -1,    -1,    86,   156,    -1,    69,   157,    70,
      -1,    69,   157,    71,    70,    -1,   110,    -1,   158,   156,
      -1,   157,    71,   158,   156,    -1,    -1,   159,    86,    -1,
     160,    -1,   159,   160,    -1,    66,   113,    67,    -1,    68,
     153,    -1,   162,    -1,   163,    -1,   166,    -1,   167,    -1,
     168,    -1,   169,    -1,   153,    85,   161,    -1,    11,   113,
      85,   161,    -1,    27,    85,   161,    -1,    69,    70,    -1,
      69,   164,    70,    -1,    69,   165,    70,    -1,    69,   164,
     165,    70,    -1,   115,    -1,   164,   115,    -1,   161,    -1,
     165,   161,    -1,   114,    87,    -1,    32,    64,   112,    65,
     161,    -1,    32,    64,   112,    65,   161,     8,   161,    -1,
      10,    64,   112,    65,   161,    -1,    34,    64,   112,    65,
     161,    -1,    31,   161,    34,    64,   112,    65,    87,    -1,
      24,    64,   114,    87,   114,    87,   114,    65,   161,    -1,
      28,   153,    87,    -1,    23,    87,    -1,     7,    87,    -1,
      17,   114,    87,    -1,    -1,   171,    -1,   172,    -1,   171,
     172,    -1,   173,    -1,   115,    -1,    -1,   197,   174,   163,
      -1,    -1,   118,   197,   175,   163,    -1,    -1,   119,   197,
     176,   163,    -1,    -1,   120,   197,   177,   163,    -1,    -1,
     121,   197,   178,   163,    -1,    -1,   201,   179,   163,    -1,
      -1,   118,   201,   180,   163,    -1,    -1,   119,   201,   181,
     163,    -1,    -1,   120,   201,   182,   163,    -1,    -1,   121,
     201,   183,   163,    -1,    -1,   201,   164,   184,   163,    -1,
      -1,   118,   201,   164,   185,   163,    -1,    -1,   119,   201,
     164,   186,   163,    -1,    -1,   120,   201,   164,   187,   163,
      -1,    -1,   121,   201,   164,   188,   163,    -1,   197,    -1,
     190,    -1,   194,    -1,   191,    -1,    63,    -1,    63,   204,
      -1,   192,    -1,   193,    -1,    73,   191,    -1,    73,   121,
     191,    -1,    64,   192,    65,    -1,    64,   192,    65,   204,
      -1,   195,    -1,    73,    64,   196,    65,    -1,    73,   121,
      64,   196,    65,    -1,    73,   194,    -1,    73,   121,   194,
      -1,    64,   194,    65,    -1,    64,   196,   204,    65,    -1,
      64,   194,    65,   204,    -1,    63,    -1,    64,   196,    65,
      -1,   198,    -1,   200,    -1,   199,    -1,    73,   197,    -1,
      73,   121,   197,    -1,   200,   204,    -1,    64,   198,    65,
      -1,    64,   198,    65,   204,    -1,    60,    -1,    64,   200,
      65,    -1,   202,    -1,    73,   201,    -1,    73,   121,   201,
      -1,   200,    64,   152,    65,    -1,    64,   201,    65,    -1,
      64,   201,    65,   204,    -1,   206,    -1,   207,    -1,   204,
      -1,   205,    -1,    64,    65,    -1,    64,   149,    65,    -1,
      66,    67,    -1,    66,   110,    67,    -1,    66,    73,    67,
      -1,   205,    66,   110,    67,    -1,   205,    66,    73,    67,
      -1,    73,    -1,    73,   121,    -1,    73,   203,    -1,    73,
     121,   203,    -1,    64,   206,    65,    -1,    64,   207,    65,
      -1,    64,   204,    65,    -1,    64,   206,    65,   204,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   541,   541,   542,   549,   555,   556,   557,   561,   562,
     563,   564,   565,   565,   566,   566,   567,   568,   569,   570,
     574,   575,   579,   580,   584,   585,   586,   587,   605,   606,
     610,   611,   612,   613,   614,   615,   619,   620,   624,   625,
     627,   634,   644,   645,   647,   652,   653,   655,   660,   661,
     663,   665,   667,   672,   673,   675,   680,   681,   686,   687,
     692,   693,   698,   699,   704,   705,   710,   711,   716,   717,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   735,   736,   740,   744,   746,   784,   785,   786,   787,
     794,   816,   822,   833,   856,   862,   874,   879,   880,   885,
     890,   891,   897,   898,   899,   903,   904,   908,   909,   913,
     914,   915,   919,   920,   921,   922,   926,   927,   928,   929,
     933,   938,   943,   951,   952,   953,   957,   958,   959,   963,
     964,   967,   972,   977,   985,   986,   987,   991,   992,   993,
     994,   995,   996,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1012,  1013,  1017,  1030,  1059,  1084,  1085,  1089,
    1102,  1115,  1116,  1117,  1121,  1135,  1150,  1164,  1180,  1194,
    1204,  1217,  1227,  1240,  1241,  1245,  1249,  1263,  1293,  1319,
    1333,  1349,  1356,  1366,  1379,  1380,  1384,  1385,  1389,  1390,
    1391,  1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,
    1401,  1402,  1410,  1411,  1415,  1430,  1446,  1460,  1479,  1486,
    1496,  1498,  1502,  1503,  1504,  1508,  1509,  1512,  1514,  1518,
    1519,  1523,  1524,  1529,  1530,  1531,  1532,  1533,  1534,  1538,
    1539,  1540,  1544,  1545,  1546,  1547,  1551,  1552,  1556,  1557,
    1561,  1565,  1566,  1567,  1571,  1572,  1573,  1577,  1578,  1579,
    1580,  1586,  1588,  1592,  1593,  1597,  1598,  1602,  1602,  1604,
    1604,  1606,  1606,  1608,  1608,  1610,  1610,  1613,  1613,  1614,
    1614,  1615,  1615,  1616,  1616,  1617,  1617,  1619,  1619,  1620,
    1620,  1621,  1621,  1622,  1622,  1623,  1623,  1627,  1628,  1632,
    1633,  1637,  1649,  1663,  1670,  1671,  1677,  1686,  1687,  1698,
    1699,  1705,  1711,  1717,  1726,  1727,  1732,  1740,  1752,  1756,
    1757,  1761,  1762,  1768,  1777,  1782,  1783,  1791,  1804,  1808,
    1809,  1810,  1814,  1819,  1820,  1828,  1829,  1830,  1844,  1845,
    1846,  1850,  1851,  1865,  1879,  1898,  1920,  1925,  1930,  1935,
    1943,  1944,  1945,  1956
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
  "RESTRICT_TOK", "SKIP_TOK", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", 
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", 
  "ELLIPSIS", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", 
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", 
  "OR_ASSIGN", "IDENTIFIER", "STRING_LITERAL", "CONSTANT", "TYPE_NAME", 
  "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'", "'*'", 
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", 
  "'?'", "':'", "'='", "';'", "$accept", "string_literal_list", 
  "primary_expression", "postfix_expression", "@1", "@2", "member_name", 
  "argument_expression_list", "unary_expression", "unary_operator", 
  "cast_expression", "multiplicative_expression", "additive_expression", 
  "shift_expression", "relational_expression", "equality_expression", 
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression", 
  "logical_AND_expression", "logical_OR_expression", 
  "conditional_expression", "assignment_expression", 
  "assignment_operator", "comma_expression", "constant_expression", 
  "comma_expression_opt", "declaration", "default_declaring_list", 
  "declaring_list", "declaration_specifier", "type_specifier", 
  "declaration_qualifier_list", "type_qualifier_list", 
  "declaration_qualifier", "type_qualifier", 
  "basic_declaration_specifier", "basic_type_specifier", 
  "sue_declaration_specifier", "sue_type_specifier", "su_type_specifier", 
  "sut_type_specifier", "typedef_declaration_specifier", 
  "typedef_type_specifier", "storage_class", "basic_type_name", 
  "elaborated_type_name", "aggregate_name", "aggregate_key", 
  "member_declaration_list", "member_declaration", 
  "unnamed_su_declaration", "member_default_declaring_list", 
  "member_declaring_list", "member_declarator", 
  "member_identifier_declarator", "bit_field_size_opt", "bit_field_size", 
  "enum_name", "enumerator_list", "enumerator", "parameter_type_list", 
  "parameter_list", "parameter_declaration", "identifier_list", 
  "identifier_or_typedef_name", "type_name", "initializer_opt", 
  "initializer", "initializer_list", "designation_opt", "designator_list", 
  "designator", "statement", "labeled_statement", "compound_statement", 
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
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    40,    41,    91,    93,    46,   123,
     125,    44,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    94,   124,    63,    58,    61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    88,    89,    89,    90,    90,    90,    90,    91,    91,
      91,    91,    92,    91,    93,    91,    91,    91,    91,    91,
      94,    94,    95,    95,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    98,    98,    99,    99,
      99,    99,   100,   100,   100,   101,   101,   101,   102,   102,
     102,   102,   102,   103,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   112,   112,   113,   114,   114,   115,   115,   115,   115,
     116,   116,   116,   117,   117,   117,   118,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   124,   124,   124,   124,   125,   125,   125,   125,
     126,   126,   126,   127,   127,   127,   128,   128,   128,   129,
     129,   130,   130,   130,   131,   131,   131,   132,   132,   132,
     132,   132,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   134,   134,   135,   135,   135,   136,   136,   137,
     137,   138,   138,   138,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   146,   146,   146,   147,
     147,   147,   148,   148,   149,   149,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   152,   152,   153,   153,   154,   154,   154,   154,
     155,   155,   156,   156,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   161,   161,   161,   162,
     162,   162,   163,   163,   163,   163,   164,   164,   165,   165,
     166,   167,   167,   167,   168,   168,   168,   169,   169,   169,
     169,   170,   170,   171,   171,   172,   172,   174,   173,   175,
     173,   176,   173,   177,   173,   178,   173,   179,   173,   180,
     173,   181,   173,   182,   173,   183,   173,   184,   173,   185,
     173,   186,   173,   187,   173,   188,   173,   189,   189,   190,
     190,   191,   191,   191,   192,   192,   192,   193,   193,   194,
     194,   194,   194,   194,   195,   195,   195,   196,   196,   197,
     197,   198,   198,   198,   199,   199,   199,   200,   200,   201,
     201,   201,   202,   202,   202,   203,   203,   203,   204,   204,
     204,   205,   205,   205,   205,   205,   206,   206,   206,   206,
     207,   207,   207,   207
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     4,
       3,     4,     0,     4,     0,     4,     2,     2,     6,     7,
       1,     1,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     1,     2,     2,     2,     2,
       3,     3,     4,     3,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       1,     2,     2,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     2,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     3,     2,     3,     2,
       1,     2,     1,     0,     1,     2,     4,     5,     2,     1,
       3,     2,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       2,     2,     1,     3,     1,     1,     1,     2,     1,     2,
       0,     2,     3,     4,     1,     2,     4,     0,     2,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       2,     5,     7,     5,     5,     7,     9,     3,     2,     2,
       3,     0,     1,     1,     2,     1,     1,     0,     3,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     3,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       5,     0,     5,     0,     5,     0,     5,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     3,     3,     4,     1,
       4,     5,     2,     3,     3,     4,     4,     1,     3,     1,
       1,     1,     2,     3,     2,     3,     4,     1,     3,     1,
       2,     3,     4,     3,     4,     1,     1,     1,     1,     2,
       3,     2,     3,     3,     4,     4,     1,     2,     2,     3,
       3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     251,   140,   148,   143,   157,   146,     0,   141,   137,   144,
     138,   158,   109,   147,   145,   150,   149,   151,   111,   139,
     142,   110,   317,   134,     0,     0,   256,     0,     0,     0,
       0,     0,     0,   105,    96,    99,    97,   100,    98,   101,
     102,   116,   123,   152,     0,   153,     0,   252,   253,   255,
     257,   309,   311,   310,   267,   319,   204,   205,     0,   178,
       0,     0,     0,     0,   312,   320,     0,    89,     0,    88,
     291,     0,     0,   210,   288,   290,   293,   294,   289,   299,
     287,   269,   210,   287,   271,   132,   104,   108,   107,   112,
     120,   210,   273,   135,   106,   103,   117,   124,   210,   275,
     114,   115,   118,   113,   119,    86,   122,    87,   125,   121,
     133,   136,   131,     0,   156,     1,   254,     0,     0,     0,
     314,   328,   236,     0,     0,     0,     0,   277,     0,     0,
     179,   182,     0,   315,   318,   323,   313,   321,     0,     0,
     210,   310,     0,     0,   210,   287,     0,   292,   307,     0,
       0,     0,     0,     0,     0,   295,   302,     0,    93,     0,
     279,     0,    94,     0,   281,     0,    90,     0,   283,     0,
      91,     0,   285,     0,     0,     0,    99,   100,   129,   164,
     101,   152,     0,   159,     0,     0,     0,     0,    84,   258,
     202,   329,   188,   195,   192,   199,    97,   100,     0,   184,
     186,     0,     0,     0,     0,     4,     2,     5,     0,   331,
      30,    31,    32,    33,    34,    35,     6,     8,    24,    36,
       0,    38,    42,    45,    48,    53,    56,    58,    60,    62,
      64,    66,    68,     0,     0,   210,   210,   237,     0,   268,
     176,   181,     0,     0,   316,   324,     0,     0,    92,     0,
       0,     0,    95,     0,   297,   304,     0,     0,     0,   296,
     303,   217,    31,   214,   211,   260,     0,   270,   262,     0,
     272,   264,     0,   274,   266,     0,   276,     0,   167,   170,
     173,   152,   165,   172,   173,   125,   154,   160,   163,     0,
     162,     0,   161,     0,     0,     0,     0,    84,     0,     0,
       0,     0,    84,     0,     0,     4,   134,   232,    81,    85,
       0,     0,   238,   223,   224,    84,    84,   225,   226,   227,
     228,     0,   336,   191,   190,   189,   327,   325,   326,   198,
     197,   196,     0,   336,   194,   193,   201,   200,   330,     0,
     322,     0,     0,    28,     0,    25,    26,     0,   206,   208,
     100,   101,     0,   333,     3,    16,    17,     0,     0,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    70,     0,    36,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   332,    31,     0,   278,   180,    83,
     183,   177,     0,   308,   298,   306,   305,   300,     0,     0,
       0,     0,     0,     0,   219,   280,   282,   284,   286,   175,
     169,   174,   171,   166,   168,   155,   249,     0,     0,     0,
     248,    84,    84,     0,     0,     0,     0,     0,   240,    84,
     233,    84,   234,   239,     0,     0,     0,   337,   338,   337,
     185,   187,   203,     0,     0,     7,     0,   336,   207,   209,
       0,    10,     0,    22,     0,     0,     0,    69,    39,    40,
      41,    43,    44,    46,    47,    51,    52,    49,    50,    54,
      55,    57,    59,    61,    63,    65,     0,   335,   334,   301,
       0,   222,   212,   217,   215,   218,   220,     0,    84,   250,
       0,   231,   247,     0,     0,     0,    82,   229,   235,   342,
     340,   341,   339,    29,     0,   337,   217,    37,    11,     0,
       9,    20,    21,    13,    15,     0,   221,   213,     0,    84,
     230,    84,     0,    84,    84,   343,     0,    23,    67,   216,
     243,     0,     0,   241,   244,    18,   217,    84,     0,    84,
      19,     0,   245,   242,    84,   246
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   216,   217,   218,   359,   360,   523,   462,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   308,   372,   309,   400,   310,   122,    27,    28,
     123,   124,   125,   126,    86,    33,    34,    35,    36,    37,
     178,   179,    38,    39,    40,    41,    42,    43,    44,   182,
     183,   184,   185,   186,   278,   282,   420,   279,    45,   129,
     130,   198,   199,   200,   201,   311,   352,   166,   264,   411,
     412,   413,   414,   312,   313,   314,   127,   316,   317,   318,
     319,   320,    46,    47,    48,    49,   117,   159,   163,   167,
     171,   128,   161,   165,   169,   173,   238,   266,   269,   272,
     275,    73,    74,    75,    76,    77,   151,    79,   152,    64,
      51,    52,   141,    62,    55,   448,   326,   121,   327,   328
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -474
static const short yypact[] =
{
    1455,  -474,  -474,  -474,  -474,  -474,   384,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,    51,   581,  -474,   -44,   -41,   169,
     169,  1491,  1527,  -474,  2107,  2107,   602,   633,   908,   908,
    -474,  -474,  -474,  -474,   450,  -474,    74,  1455,  -474,  -474,
    -474,  -474,  -474,    87,  1845,  -474,  -474,  -474,   -38,    27,
      55,   143,    73,   581,  -474,  -474,   128,  -474,   526,  -474,
     195,   610,   681,    -8,  -474,  -474,  -474,  -474,  -474,  -474,
      81,  1845,    -8,    98,  1845,  -474,  -474,  -474,  -474,  -474,
    -474,    -7,  1845,  -474,  -474,  -474,  -474,  -474,    16,  1845,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,   959,   116,  -474,  -474,   149,  1736,  1843,
    -474,   104,  -474,   526,   526,  1563,  1599,  1845,   149,   119,
    -474,   144,   -38,   195,  -474,   195,  -474,  -474,   128,   621,
      -8,   195,   639,   702,    -8,  -474,  1772,  -474,  -474,   610,
     175,   179,   195,   610,   979,  -474,  -474,  1861,  -474,   149,
    1845,   149,  -474,   149,  1845,   149,  -474,   149,  1845,   149,
    -474,   149,  1845,   149,   308,   704,  1095,    36,  -474,  -474,
      29,   182,  1664,  -474,   197,     6,    21,   959,   781,  -474,
    -474,  -474,   388,   388,  1233,  1298,   908,   908,   252,   258,
    -474,    33,  1957,  1975,  1975,  -474,  -474,  -474,   930,  -474,
    -474,   282,  -474,  -474,  -474,  -474,   295,  -474,   708,   778,
    2014,  -474,   213,   238,   322,   118,   342,   310,   298,   331,
     347,    -9,  -474,   352,  2032,    -8,    -8,  -474,   149,  -474,
    -474,   -38,  2014,   333,  -474,  -474,   274,   621,  -474,   639,
     639,  1770,  -474,   311,   195,   195,   358,   528,   610,  -474,
    -474,    31,  -474,  -474,  -474,  -474,   149,  -474,  -474,   149,
    -474,  -474,   149,  -474,  -474,   149,  -474,  2014,  -474,  -474,
     346,   368,  -474,  -474,   346,   370,  -474,  -474,  -474,   215,
    -474,   308,  -474,  1700,   394,   381,  2014,  2014,   398,   396,
     386,   -38,  1315,   424,   431,   420,   433,  -474,  -474,   445,
     441,   459,  -474,  -474,  -474,   856,  1001,  -474,  -474,  -474,
    -474,  1076,   641,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  1141,   457,  -474,  -474,  -474,  -474,  -474,  1806,
    -474,   490,   930,  -474,   930,  -474,  -474,    69,   373,  1635,
      36,    36,   487,  -474,  -474,  -474,  -474,  1900,  2014,   486,
     518,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  2014,  -474,  -474,  2014,  2014,  2014,  2014,  2014,
    2014,  2014,  2014,  2014,  2014,  2014,  2014,  2014,  2014,  2014,
    2014,  2014,  2014,  2014,  -474,   491,   493,  -474,  -474,  -474,
    -474,  -474,   639,  -474,  -474,  -474,  -474,  -474,   542,  2014,
     -38,   351,  1861,   -17,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  2014,   477,   479,
    -474,  2014,  1315,   480,   530,  2014,  2014,  2014,  -474,  1315,
    -474,  1158,  -474,  -474,   522,   533,   536,   641,  -474,   457,
    -474,  -474,  -474,   544,   545,  -474,  1390,   461,  -474,  -474,
    1918,  -474,   163,  -474,     0,    58,    58,  -474,  -474,  -474,
    -474,   213,   213,   238,   238,   322,   322,   322,   322,   118,
     118,   342,   310,   298,   331,   347,    18,  -474,  -474,  -474,
     546,  -474,  -474,   255,  -474,  -474,  -474,   176,  1315,  -474,
     508,  -474,  -474,   550,   209,   234,  -474,  -474,  -474,  -474,
     195,  -474,  -474,   551,   551,   461,    31,  -474,  -474,  2014,
    -474,  -474,  -474,  -474,  -474,  2014,  -474,  -474,  1861,  1315,
    -474,  2014,  2014,  1315,  1315,  -474,   407,  -474,  -474,  -474,
    -474,   535,   239,   617,  -474,  -474,   332,  2014,   541,  1315,
    -474,   564,  -474,  -474,  1315,  -474
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -474,  -474,  -474,  -474,  -474,  -474,   167,  -474,   193,  -474,
    -202,   120,   131,   164,   155,   246,   253,   260,   257,   251,
    -474,  -216,  -104,  -474,  -121,  -249,  -260,   125,  -474,  -474,
      11,    23,    13,     9,     4,   -31,  -474,   -99,   -83,   -82,
    -474,  -474,  -474,   -96,   501,   152,   101,   -68,  -474,   468,
    -158,  -474,  -474,  -474,   365,   376,   375,   -65,  -474,   540,
     421,  -474,  -474,   337,  -474,    10,   -20,   360,  -391,   162,
    -473,  -474,   266,    90,  -474,   392,   357,   372,  -474,  -474,
    -474,  -474,  -474,  -474,   643,  -474,  -474,  -474,  -474,  -474,
    -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,  -474,
    -474,   -18,  -474,   -15,   141,  -474,   340,  -474,   -36,   235,
       5,  -474,   354,   443,  -474,   -13,   -51,  -474,  -288,  -280
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -266
static const short yytable[] =
{
      87,    94,   120,    87,   102,    87,   108,    87,   111,    32,
     120,    29,    82,    31,   176,   233,    59,   180,   374,   147,
     528,   494,    56,    30,   287,    57,   399,    66,   419,    60,
      68,   177,    94,   445,    63,   196,   197,   429,   100,   392,
     106,   446,   110,    67,   445,   181,    69,   428,    12,   409,
     144,   410,   446,   263,   114,    12,    32,   155,    29,    18,
      31,   399,  -263,   196,   197,    21,    18,   520,   131,   495,
      30,   437,    21,   528,   115,   393,    60,   289,   157,   157,
     399,   154,   244,   176,   245,  -265,   180,   347,   176,   437,
     120,   180,   291,   290,    87,    94,   132,   409,   340,   410,
     177,   256,   157,   525,   341,   177,    82,   281,   292,   176,
     283,    22,   351,   253,   181,    24,  -130,   257,   521,   181,
     133,   522,   175,    94,    25,    26,   350,   195,   155,   192,
     396,   194,    90,    97,   455,   287,   174,   539,   135,   259,
     437,   193,   131,    60,    94,   102,   285,    60,   247,   111,
    -259,   118,   251,   119,    60,   195,   280,   192,    60,   194,
     490,   382,   383,    87,    94,    87,   108,  -261,   445,   193,
     234,   500,    26,   468,   469,   470,   446,   323,   329,   325,
     331,   335,   337,    89,    96,   187,   101,   104,    22,   240,
     241,   175,   138,   399,   176,   120,   175,   180,   384,   385,
     106,   139,   256,   404,   405,   174,   256,   118,   134,   119,
     174,   177,   150,   253,   257,   421,    94,   349,   188,   421,
      94,   347,   408,   347,   283,   181,    90,    97,   518,    22,
     242,   348,    70,    71,   519,    50,   259,   464,   196,   197,
     254,   529,    72,   176,   255,   176,   351,   437,   351,   196,
     197,   131,   237,   463,    60,    60,   196,   197,   517,   146,
     350,   119,   350,    60,    80,    83,    91,    98,   467,  -126,
     444,   541,   486,   280,   533,    22,    97,    89,    96,   138,
     437,   444,    50,   150,   288,   237,   375,   551,   139,   237,
     150,   376,   377,   237,   150,    90,    97,   237,   136,   534,
     277,   140,   175,   145,   548,   437,   497,   155,   263,   538,
     437,   433,   378,   379,   504,   505,   174,   338,    94,   108,
     111,   409,   453,   410,   454,   527,    60,    96,   104,   339,
     195,   447,   192,   506,   194,   458,   459,    60,   146,   134,
     119,   195,   449,   192,   193,   194,    89,    96,   195,   353,
     192,   349,   194,   349,    53,   193,   354,   256,   145,   145,
     235,   236,   193,   380,   381,   348,   408,   348,    22,    78,
      78,    70,   142,   196,   197,   146,   403,   119,    61,    53,
     389,   143,   388,    53,    53,    53,    53,   386,   387,   136,
     150,   150,   434,   277,   391,   343,   345,   346,   409,   150,
     410,    53,   550,   401,   241,   444,   443,    60,    78,   145,
     284,   542,   156,   373,   390,   537,    94,    53,    94,   394,
     491,   492,   493,   406,   263,    61,    53,   324,   330,   334,
     336,   277,   259,   158,   512,   373,   512,   456,   160,   119,
     237,   164,   162,    54,    56,   427,   457,    57,    22,   168,
      97,    70,   321,    58,   119,  -127,   172,  -128,   170,   535,
     431,   322,   150,    78,    78,   195,   515,   192,    65,   194,
     373,   432,    81,    84,    92,    99,    12,   545,   546,   193,
      12,   426,   136,   156,    94,   430,   136,    18,   435,   373,
      54,    18,   246,    21,   260,   436,   246,    21,   471,   472,
     248,    96,   512,    61,   252,  -204,   137,    61,    53,   189,
      56,   473,   474,    57,    78,    65,   437,    22,  -205,   113,
     239,   332,   501,   119,   284,   456,   145,   119,   438,   507,
     333,   443,    88,    95,   457,    88,   103,    88,   109,    88,
     112,   479,   480,   150,   439,   315,   475,   476,   477,   478,
     452,   265,   460,   267,   465,   268,   466,   270,   487,   271,
     488,   273,   498,   274,   503,   276,   499,   502,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,    22,   509,   530,    70,
     142,   260,   146,   407,   119,   531,   170,   137,   510,   143,
      12,   511,   373,   246,   246,     1,   146,   489,   119,   513,
     514,    18,    61,   526,   532,     7,     8,    21,    10,   540,
     516,    12,   547,   543,   544,   549,    88,    95,   552,   554,
     397,    78,    18,   524,   481,    19,     1,    20,    21,   553,
      12,    22,   482,   485,   555,    24,     7,     8,   484,    10,
     483,    18,    12,   373,    25,   293,   424,    21,   415,   422,
      12,   416,   398,    18,   417,   423,    19,   418,    20,    21,
      22,    18,   243,   148,   149,   246,   451,    21,   536,   496,
       0,    22,   136,    72,   136,   138,   246,   441,     0,   105,
     116,     0,     0,     0,   139,    88,    95,    88,   109,    22,
      12,    22,   148,   249,    70,   321,     0,   119,     2,     3,
       4,    18,   143,     5,   322,     0,     6,    21,   373,     9,
     107,    12,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,    18,     0,    18,     0,     0,     0,    21,     0,
      21,    22,     0,     0,    70,   153,   -14,   355,   356,     0,
       0,     0,     0,     0,    72,     0,   246,     0,     0,     0,
       0,     0,    22,     0,    22,    70,   250,    93,   138,     0,
       0,     0,   357,     0,   358,   143,   -12,   139,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,   294,   277,
       5,   295,   296,     6,     7,     8,     9,    10,   297,    11,
      12,    13,    14,    15,   298,   299,    16,    17,   300,   301,
     202,    18,   302,   303,    19,   304,    20,    21,     0,     0,
     203,   204,     0,     0,     0,     0,     0,     0,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,     0,     0,
       0,   305,   206,   207,   306,   208,     0,     0,     0,     0,
     188,   307,     0,   210,   262,   212,   213,   214,   215,     1,
       2,     3,     4,   294,   371,     5,   295,   296,     6,     7,
       8,     9,    10,   297,    11,    12,    13,    14,    15,   298,
     299,    16,    17,   300,   301,   202,    18,   302,   303,    19,
     304,    20,    21,     0,     0,   203,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,   305,   206,   207,   306,
     208,     7,     8,     0,    10,   188,   440,    12,   210,   262,
     212,   213,   214,   215,     2,     3,     4,     0,    18,     5,
       0,    19,     6,    20,    21,     9,     0,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,   202,
      18,     0,     0,     2,     3,     4,    21,     0,     5,   203,
     204,     6,     0,     0,     9,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,     0,    18,
     205,   206,   207,    23,   208,    21,     0,     0,    12,     0,
       0,     0,   210,   262,   212,   213,   214,   215,   294,    18,
       0,   295,   296,     0,     0,    21,     0,     0,   297,     0,
       0,     0,    23,     0,   298,   299,     0,     0,   300,   301,
     202,     0,   302,   303,     0,   304,     0,     0,     0,    22,
     203,   204,    70,   258,     0,     0,     0,     0,     0,     0,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
       0,   305,   206,   207,    57,   208,     0,     0,     0,     0,
     188,   442,     0,   210,   262,   212,   213,   214,   215,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     2,
       3,    16,    17,     0,     5,     0,    18,     0,     0,    19,
       9,    20,    21,     0,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,    22,     0,     0,    23,
     321,   191,   119,     0,     1,     2,     3,     4,     0,   322,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,   294,    16,    17,   295,   296,
       0,    18,     0,     0,    19,   297,    20,    21,     0,     0,
       0,   298,   299,     0,     0,   300,   301,   202,     0,   302,
     303,     0,   304,     0,     0,     0,     0,   203,   204,     0,
       0,    22,     0,     0,    23,   332,   191,   119,     0,     0,
       0,     0,     0,     0,   333,     0,     0,     0,   305,   206,
     207,    57,   208,     0,     0,     0,     0,   188,   508,     0,
     210,   262,   212,   213,   214,   215,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,     0,    18,     0,     0,    19,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,     0,    85,   332,     0,   119,
       0,     1,     2,     3,     4,     0,   333,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,   294,    16,    17,   295,   296,     0,    18,     0,
       0,    19,   297,    20,    21,     0,     0,     0,   298,   299,
       0,     0,   300,   301,   202,     0,   302,   303,     0,   304,
       0,     0,     0,     0,   203,   204,     0,     0,    22,     0,
       0,    93,   332,     0,   119,     0,     0,     0,     0,     0,
       0,   333,     0,     0,     0,   305,   206,   207,    57,   208,
       0,     0,     0,     0,   188,     0,     0,   210,   262,   212,
     213,   214,   215,     1,     2,     3,     4,     0,     0,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,   456,   191,   119,     0,     1,     2,
       3,     4,     0,   457,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,     0,
      20,    21,     0,     0,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,    22,    16,    17,    23,    24,
       0,    18,     0,     0,    19,     0,    20,    21,    25,     0,
       1,     2,     3,     4,     0,     0,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,    22,    16,    17,    85,    24,     0,    18,     0,     0,
      19,     0,    20,    21,    25,     0,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,    22,    16,    17,
      93,    24,     0,    18,     0,     0,    19,     0,    20,    21,
      25,     0,     1,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,    22,    16,    17,    85,   138,     0,    18,
       0,     0,    19,     0,    20,    21,   139,     0,     0,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       9,     0,     0,    11,    12,    13,    14,    15,     0,    22,
      16,    17,    93,   138,     0,    18,     0,     0,     2,     3,
       4,    21,   139,     5,     0,     0,     6,     0,     0,     9,
       0,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,     0,    93,   456,
      21,   119,     0,     0,     2,     3,     4,     0,   457,     5,
       0,     0,     6,     0,     0,     9,     0,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,    23,     0,     0,
      18,     0,     0,     0,   286,     0,    21,     0,     0,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,    23,     0,     0,    18,     0,     0,    19,
     425,    20,    21,     0,     0,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,    12,
      11,    12,    13,    14,    15,     0,   190,    16,    17,    23,
      18,   191,    18,     0,     0,    19,    21,    20,    21,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
      22,    16,    17,    70,   402,    23,    18,   191,     0,    19,
       0,    20,    21,   143,     0,     0,     0,     0,     1,     2,
       3,     4,     0,     0,     5,   450,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,    23,
      16,    17,   202,     0,     0,    18,     0,     0,    19,     0,
      20,    21,   203,   204,     0,     0,     0,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,   204,     0,   205,   206,   207,     0,   208,    23,     0,
     209,     0,     0,     0,     0,   210,   211,   212,   213,   214,
     215,   205,   206,   207,     0,   208,     0,     0,     0,   202,
     261,     0,     0,   210,   262,   212,   213,   214,   215,   203,
     204,     0,     0,     0,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   203,   204,     0,
     205,   206,   207,     0,   208,   461,     0,     0,     0,     0,
       0,     0,   210,   262,   212,   213,   214,   215,   205,   206,
     207,     0,   208,     0,     0,     0,   202,   516,     0,     0,
     210,   262,   212,   213,   214,   215,   203,   204,     0,     0,
       0,     0,     0,     0,   202,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   204,     0,   205,   206,   207,
       0,   342,     0,     0,     0,     0,     0,     0,     0,   210,
     262,   212,   213,   214,   215,   205,   206,   207,     0,   344,
       0,     0,     0,   202,     0,     0,     0,   210,   262,   212,
     213,   214,   215,   203,   204,     0,     0,     0,     0,     0,
       0,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,   204,     0,   205,   206,   207,     0,   208,     0,
       0,     0,     0,     0,     0,     0,   210,   262,   212,   213,
     214,   215,   205,   206,   207,     0,   208,     0,     0,     0,
       0,     0,     0,     0,   210,   395,   212,   213,   214,   215,
       1,     2,     3,     0,     0,     0,     5,     0,     0,     0,
       7,     8,     9,    10,     0,     0,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,    20,    21
};

static const short yycheck[] =
{
      31,    32,    53,    34,    35,    36,    37,    38,    39,     0,
      61,     0,    30,     0,   113,   119,     6,   113,   220,    70,
     493,   412,    60,     0,   182,    63,   242,    71,   277,    24,
      71,   113,    63,   321,    25,   118,   118,   297,    34,    48,
      36,   321,    38,    87,   332,   113,    87,   296,    19,    66,
      68,    68,   332,   157,    44,    19,    47,    72,    47,    30,
      47,   277,    69,   146,   146,    36,    30,    67,    58,    86,
      47,    71,    36,   546,     0,    84,    71,    71,    86,    86,
     296,    72,   133,   182,   135,    69,   182,   208,   187,    71,
     141,   187,    71,    87,   125,   126,    69,    66,    65,    68,
     182,   152,    86,    85,    71,   187,   124,   175,    87,   208,
     175,    60,   208,   149,   182,    64,    87,   153,    60,   187,
      65,    63,   113,   154,    73,     0,   208,   118,   143,   118,
     234,   118,    31,    32,    65,   293,   113,   528,    65,   154,
      71,   118,   132,   138,   175,   176,   177,   142,   139,   180,
      69,    64,   143,    66,   149,   146,   174,   146,   153,   146,
     409,    43,    44,   194,   195,   196,   197,    69,   456,   146,
      66,   431,    47,   375,   376,   377,   456,   192,   193,   192,
     193,   194,   195,    31,    32,    69,    34,    35,    60,    70,
      71,   182,    64,   409,   293,   246,   187,   293,    80,    81,
     196,    73,   253,   254,   255,   182,   257,    64,    65,    66,
     187,   293,    71,   249,   250,   280,   247,   208,    69,   284,
     251,   342,   258,   344,   289,   293,   125,   126,    65,    60,
      86,   208,    63,    64,    71,     0,   251,   358,   321,   321,
      65,    65,    73,   342,    65,   344,   342,    71,   344,   332,
     332,   241,   127,   357,   249,   250,   339,   339,   460,    64,
     342,    66,   344,   258,    29,    30,    31,    32,   372,    87,
     321,   531,   393,   291,    65,    60,   175,   125,   126,    64,
      71,   332,    47,   142,    87,   160,    73,   547,    73,   164,
     149,    78,    79,   168,   153,   194,   195,   172,    63,    65,
      85,    66,   293,    68,    65,    71,   427,   322,   412,   525,
      71,   301,    74,    75,   435,   436,   293,    65,   349,   350,
     351,    66,   342,    68,   344,    70,   321,   175,   176,    71,
     321,   322,   321,   437,   321,   348,   349,   332,    64,    65,
      66,   332,   333,   332,   321,   332,   194,   195,   339,    67,
     339,   342,   339,   344,     0,   332,    61,   408,   123,   124,
     125,   126,   339,    41,    42,   342,   402,   344,    60,    29,
      30,    63,    64,   456,   456,    64,    65,    66,    24,    25,
      82,    73,    72,    29,    30,    31,    32,    45,    46,   154,
     249,   250,   302,    85,    47,   202,   203,   204,    66,   258,
      68,    47,    70,    70,    71,   456,   316,   402,    68,   174,
     175,   532,    72,   220,    83,   519,   447,    63,   449,    67,
     410,    70,    71,    65,   528,    71,    72,   192,   193,   194,
     195,    85,   447,    73,   447,   242,   449,    64,    81,    66,
     315,    84,    82,     0,    60,    64,    73,    63,    60,    92,
     349,    63,    64,    69,    66,    87,    99,    87,    98,   510,
      64,    73,   321,   123,   124,   456,   457,   456,    25,   456,
     277,    85,    29,    30,    31,    32,    19,    70,    71,   456,
      19,    87,   247,   143,   515,    87,   251,    30,    64,   296,
      47,    30,   138,    36,   154,    64,   142,    36,   378,   379,
     140,   349,   515,   149,   144,    85,    63,   153,   154,   117,
      60,   380,   381,    63,   174,    72,    71,    60,    85,    69,
     128,    64,   432,    66,   289,    64,   291,    66,    87,   439,
      73,   441,    31,    32,    73,    34,    35,    36,    37,    38,
      39,   386,   387,   402,    85,   188,   382,   383,   384,   385,
      60,   159,    65,   161,    68,   163,    38,   165,    67,   167,
      67,   169,    85,   171,    34,   173,    87,    87,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,    60,    65,   498,    63,
      64,   251,    64,    65,    66,    87,   236,   154,    65,    73,
      19,    65,   409,   249,   250,     3,    64,    65,    66,    65,
      65,    30,   258,    67,    64,    13,    14,    36,    16,   529,
      69,    19,    87,   533,   534,     8,   125,   126,    87,    65,
     238,   291,    30,   466,   388,    33,     3,    35,    36,   549,
      19,    60,   389,   392,   554,    64,    13,    14,   391,    16,
     390,    30,    19,   460,    73,   187,   291,    36,   266,   284,
      19,   269,   241,    30,   272,   289,    33,   275,    35,    36,
      60,    30,   132,    63,    64,   321,   339,    36,   516,   413,
      -1,    60,   447,    73,   449,    64,   332,   315,    -1,    87,
      47,    -1,    -1,    -1,    73,   194,   195,   196,   197,    60,
      19,    60,    63,    64,    63,    64,    -1,    66,     4,     5,
       6,    30,    73,     9,    73,    -1,    12,    36,   525,    15,
      87,    19,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    30,    -1,    30,    -1,    -1,    -1,    36,    -1,
      36,    60,    -1,    -1,    63,    64,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    73,    -1,   402,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    60,    63,    64,    63,    64,    -1,
      -1,    -1,    64,    -1,    66,    73,    68,    73,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    85,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,     3,
       4,     5,     6,     7,    86,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    13,    14,    -1,    16,    69,    70,    19,    72,    73,
      74,    75,    76,    77,     4,     5,     6,    -1,    30,     9,
      -1,    33,    12,    35,    36,    15,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,
      30,    -1,    -1,     4,     5,     6,    36,    -1,     9,    39,
      40,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      60,    61,    62,    63,    64,    36,    -1,    -1,    19,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,     7,    30,
      -1,    10,    11,    -1,    -1,    36,    -1,    -1,    17,    -1,
      -1,    -1,    63,    -1,    23,    24,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    -1,    34,    -1,    -1,    -1,    60,
      39,    40,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,     4,
       5,    25,    26,    -1,     9,    -1,    30,    -1,    -1,    33,
      15,    35,    36,    -1,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,
      64,    65,    66,    -1,     3,     4,     5,     6,    -1,    73,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,     7,    25,    26,    10,    11,
      -1,    30,    -1,    -1,    33,    17,    35,    36,    -1,    -1,
      -1,    23,    24,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    -1,
      72,    73,    74,    75,    76,    77,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    63,    64,    -1,    66,
      -1,     3,     4,     5,     6,    -1,    73,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,     7,    25,    26,    10,    11,    -1,    30,    -1,
      -1,    33,    17,    35,    36,    -1,    -1,    -1,    23,    24,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    -1,    34,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    60,    -1,
      -1,    63,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    73,    74,
      75,    76,    77,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,     3,     4,
       5,     6,    -1,    73,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    60,    25,    26,    63,    64,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,    73,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    60,    25,    26,    63,    64,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    73,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    60,    25,    26,
      63,    64,    -1,    30,    -1,    -1,    33,    -1,    35,    36,
      73,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    60,    25,    26,    63,    64,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    73,    -1,    -1,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    60,
      25,    26,    63,    64,    -1,    30,    -1,    -1,     4,     5,
       6,    36,    73,     9,    -1,    -1,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    63,    64,
      36,    66,    -1,    -1,     4,     5,     6,    -1,    73,     9,
      -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    63,    -1,    -1,
      30,    -1,    -1,    -1,    70,    -1,    36,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    63,    -1,    -1,    30,    -1,    -1,    33,
      70,    35,    36,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    19,
      18,    19,    20,    21,    22,    -1,    60,    25,    26,    63,
      30,    65,    30,    -1,    -1,    33,    36,    35,    36,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      60,    25,    26,    63,    64,    63,    30,    65,    -1,    33,
      -1,    35,    36,    73,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    49,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    63,
      25,    26,    29,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    60,    61,    62,    -1,    64,    63,    -1,
      67,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    60,    61,    62,    -1,    64,    -1,    -1,    -1,    29,
      69,    -1,    -1,    72,    73,    74,    75,    76,    77,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      60,    61,    62,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    60,    61,
      62,    -1,    64,    -1,    -1,    -1,    29,    69,    -1,    -1,
      72,    73,    74,    75,    76,    77,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    60,    61,    62,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    60,    61,    62,    -1,    64,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    60,    61,    62,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,    60,    61,    62,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
       3,     4,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     9,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    25,    26,    30,    33,
      35,    36,    60,    63,    64,    73,   115,   116,   117,   118,
     119,   120,   121,   123,   124,   125,   126,   127,   130,   131,
     132,   133,   134,   135,   136,   146,   170,   171,   172,   173,
     197,   198,   199,   200,   201,   202,    60,    63,    69,   153,
     198,   200,   201,   121,   197,   201,    71,    87,    71,    87,
      63,    64,    73,   189,   190,   191,   192,   193,   194,   195,
     197,   201,   189,   197,   201,    63,   122,   123,   132,   133,
     134,   197,   201,    63,   123,   132,   133,   134,   197,   201,
     122,   133,   123,   132,   133,    87,   122,    87,   123,   132,
     122,   123,   132,    69,   153,     0,   172,   174,    64,    66,
     204,   205,   115,   118,   119,   120,   121,   164,   179,   147,
     148,   153,    69,    65,    65,    65,   197,   201,    64,    73,
     197,   200,    64,    73,   189,   197,    64,   204,    63,    64,
     192,   194,   196,    64,   121,   191,   194,    86,   155,   175,
     164,   180,   155,   176,   164,   181,   155,   177,   164,   182,
     155,   178,   164,   183,   119,   121,   125,   127,   128,   129,
     131,   135,   137,   138,   139,   140,   141,    69,    69,   163,
      60,    65,   118,   119,   120,   121,   126,   127,   149,   150,
     151,   152,    29,    39,    40,    60,    61,    62,    64,    67,
      72,    73,    74,    75,    76,    77,    89,    90,    91,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    66,   197,   197,   115,   184,   163,
      70,    71,    86,   147,   204,   204,   200,   121,   155,    64,
      64,   121,   155,   196,    65,    65,   204,   196,    64,   191,
     194,    69,    73,   110,   156,   163,   185,   163,   163,   186,
     163,   163,   187,   163,   163,   188,   163,    85,   142,   145,
     189,   135,   143,   145,   197,   123,    70,   138,    87,    71,
      87,    71,    87,   137,     7,    10,    11,    17,    23,    24,
      27,    28,    31,    32,    34,    60,    63,    70,   110,   112,
     114,   153,   161,   162,   163,   164,   165,   166,   167,   168,
     169,    64,    73,   191,   197,   203,   204,   206,   207,   191,
     197,   203,    64,    73,   197,   203,   197,   203,    65,    71,
      65,    71,    64,    96,    64,    96,    96,   112,   119,   121,
     127,   131,   154,    67,    61,    39,    40,    64,    66,    92,
      93,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    86,   111,    96,    98,    73,    78,    79,    74,    75,
      41,    42,    43,    44,    80,    81,    45,    46,    72,    82,
      83,    47,    48,    84,    67,    73,   110,   163,   148,   109,
     113,    70,    64,    65,   204,   204,    65,    65,   196,    66,
      68,   157,   158,   159,   160,   163,   163,   163,   163,   113,
     144,   145,   144,   143,   142,    70,    87,    64,   113,   114,
      87,    64,    85,   153,   161,    64,    64,    71,    87,    85,
      70,   165,    70,   161,   204,   206,   207,   121,   203,   121,
      49,   151,    60,   154,   154,    65,    64,    73,   203,   203,
      65,    65,    95,   110,   112,    68,    38,   110,    98,    98,
      98,    99,    99,   100,   100,   101,   101,   101,   101,   102,
     102,   103,   104,   105,   106,   107,   112,    67,    67,    65,
     113,   153,    70,    71,   156,    86,   160,   112,    85,    87,
     114,   161,    87,    34,   112,   112,   110,   161,    70,    65,
      65,    65,   203,    65,    65,   121,    69,    98,    65,    71,
      67,    60,    63,    94,    94,    85,    67,    70,   158,    65,
     161,    87,    64,    65,    65,   204,   157,   110,   109,   156,
     161,   114,   112,   161,   161,    70,    71,    87,    65,     8,
      70,   114,    87,   161,    65,   161
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
#line 541 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 3:
#line 543 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-1].value, +, yyvsp[0].value ); ;}
    break;

  case 4:
#line 550 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier )
	      HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    UNDEF_VAL( yyval.value );
	  ;}
    break;

  case 5:
#line 555 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 6:
#line 556 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.iv++; ;}
    break;

  case 7:
#line 557 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 8:
#line 561 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 9:
#line 562 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 10:
#line 563 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 11:
#line 564 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 12:
#line 565 "ctlib/parser.y"
    {;}
    break;

  case 13:
#line 565 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 14:
#line 566 "ctlib/parser.y"
    {;}
    break;

  case 15:
#line 566 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 16:
#line 567 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 17:
#line 568 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 18:
#line 569 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 19:
#line 570 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 20:
#line 574 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 21:
#line 575 "ctlib/parser.y"
    {;}
    break;

  case 22:
#line 579 "ctlib/parser.y"
    {;}
    break;

  case 23:
#line 580 "ctlib/parser.y"
    {;}
    break;

  case 24:
#line 584 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 25:
#line 585 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 26:
#line 586 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 27:
#line 588 "ctlib/parser.y"
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

  case 28:
#line 605 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 29:
#line 606 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 30:
#line 610 "ctlib/parser.y"
    { yyval.oper = '&'; ;}
    break;

  case 31:
#line 611 "ctlib/parser.y"
    { yyval.oper = '*'; ;}
    break;

  case 32:
#line 612 "ctlib/parser.y"
    { yyval.oper = '+'; ;}
    break;

  case 33:
#line 613 "ctlib/parser.y"
    { yyval.oper = '-'; ;}
    break;

  case 34:
#line 614 "ctlib/parser.y"
    { yyval.oper = '~'; ;}
    break;

  case 35:
#line 615 "ctlib/parser.y"
    { yyval.oper = '!'; ;}
    break;

  case 36:
#line 619 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 37:
#line 620 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_CAST; ;}
    break;

  case 38:
#line 624 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 39:
#line 626 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, *, yyvsp[0].value ); ;}
    break;

  case 40:
#line 628 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, /, yyvsp[0].value );
	  ;}
    break;

  case 41:
#line 635 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, %, yyvsp[0].value );
	  ;}
    break;

  case 42:
#line 644 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 43:
#line 646 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, +, yyvsp[0].value ); ;}
    break;

  case 44:
#line 648 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, -, yyvsp[0].value ); ;}
    break;

  case 45:
#line 652 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 46:
#line 654 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <<, yyvsp[0].value ); ;}
    break;

  case 47:
#line 656 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >>, yyvsp[0].value ); ;}
    break;

  case 48:
#line 660 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 49:
#line 662 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <,  yyvsp[0].value ); ;}
    break;

  case 50:
#line 664 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >,  yyvsp[0].value ); ;}
    break;

  case 51:
#line 666 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <=, yyvsp[0].value ); ;}
    break;

  case 52:
#line 668 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >=, yyvsp[0].value ); ;}
    break;

  case 53:
#line 672 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 54:
#line 674 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ==, yyvsp[0].value ); ;}
    break;

  case 55:
#line 676 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, !=, yyvsp[0].value ); ;}
    break;

  case 56:
#line 680 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 57:
#line 682 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &, yyvsp[0].value ); ;}
    break;

  case 58:
#line 686 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 59:
#line 688 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ^, yyvsp[0].value ); ;}
    break;

  case 60:
#line 692 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 61:
#line 694 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, |, yyvsp[0].value ); ;}
    break;

  case 62:
#line 698 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 63:
#line 700 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &&, yyvsp[0].value ); ;}
    break;

  case 64:
#line 704 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 65:
#line 706 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ||, yyvsp[0].value ); ;}
    break;

  case 66:
#line 710 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 67:
#line 712 "ctlib/parser.y"
    { yyval.value = yyvsp[-4].value.iv ? yyvsp[-2].value : yyvsp[0].value; yyval.value.flags |= yyvsp[-4].value.flags; ;}
    break;

  case 68:
#line 716 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 69:
#line 717 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 70:
#line 721 "ctlib/parser.y"
    {;}
    break;

  case 71:
#line 722 "ctlib/parser.y"
    {;}
    break;

  case 72:
#line 723 "ctlib/parser.y"
    {;}
    break;

  case 73:
#line 724 "ctlib/parser.y"
    {;}
    break;

  case 74:
#line 725 "ctlib/parser.y"
    {;}
    break;

  case 75:
#line 726 "ctlib/parser.y"
    {;}
    break;

  case 76:
#line 727 "ctlib/parser.y"
    {;}
    break;

  case 77:
#line 728 "ctlib/parser.y"
    {;}
    break;

  case 78:
#line 729 "ctlib/parser.y"
    {;}
    break;

  case 79:
#line 730 "ctlib/parser.y"
    {;}
    break;

  case 80:
#line 731 "ctlib/parser.y"
    {;}
    break;

  case 81:
#line 735 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 82:
#line 736 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 83:
#line 740 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 85:
#line 746 "ctlib/parser.y"
    {;}
    break;

  case 86:
#line 784 "ctlib/parser.y"
    {;}
    break;

  case 87:
#line 785 "ctlib/parser.y"
    {;}
    break;

  case 88:
#line 786 "ctlib/parser.y"
    {;}
    break;

  case 89:
#line 787 "ctlib/parser.y"
    {;}
    break;

  case 90:
#line 795 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pTypedefList = NULL;
	    }
	    else {
	      if( yyvsp[-2].uval & T_TYPEDEF ) {
	        TypeSpec ts;
	        ts.tflags = yyvsp[-2].uval;
	        ts.ptr    = NULL;
                if( (ts.tflags & ANY_TYPE_NAME) == 0 )
                  ts.tflags |= T_INT;
	        yyval.pTypedefList = typedef_list_new( ts, LL_new() );
	        LL_push( PSTATE->pCPI->typedef_lists, yyval.pTypedefList );
	        MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	      }
	      else {
	        yyval.pTypedefList = NULL;
	        decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	      }
	    }
	  ;}
    break;

  case 91:
#line 817 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;}
    break;

  case 92:
#line 823 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-3].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	    else if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;}
    break;

  case 93:
#line 834 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pTypedefList = NULL;
	    }
	    else {
	      if( yyvsp[-2].tspec.tflags & T_TYPEDEF ) {
                if( (yyvsp[-2].tspec.tflags & ANY_TYPE_NAME) == 0 )
                  yyvsp[-2].tspec.tflags |= T_INT;
                else if( yyvsp[-2].tspec.tflags & T_ENUM )
                  ((EnumSpecifier *) yyvsp[-2].tspec.ptr)->tflags |= T_HASTYPEDEF;
                else if( yyvsp[-2].tspec.tflags & (T_STRUCT | T_UNION) )
                  ((Struct *) yyvsp[-2].tspec.ptr)->tflags |= T_HASTYPEDEF;
	        yyval.pTypedefList = typedef_list_new( yyvsp[-2].tspec, LL_new() );
	        LL_push( PSTATE->pCPI->typedef_lists, yyval.pTypedefList );
	        MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	      }
	      else {
	        yyval.pTypedefList = NULL;
	        decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	      }
	    }
	  ;}
    break;

  case 94:
#line 857 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;}
    break;

  case 95:
#line 863 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-3].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	    else if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;}
    break;

  case 96:
#line 875 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 97:
#line 879 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 98:
#line 880 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 99:
#line 886 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 100:
#line 890 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 101:
#line 891 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 102:
#line 897 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 103:
#line 898 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 104:
#line 899 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;}
    break;

  case 107:
#line 908 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval; ;}
    break;

  case 108:
#line 909 "ctlib/parser.y"
    { yyval.uval = 0;  ;}
    break;

  case 112:
#line 919 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 113:
#line 920 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 114:
#line 921 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 115:
#line 922 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 116:
#line 926 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 117:
#line 927 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 118:
#line 928 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval;               ;}
    break;

  case 119:
#line 929 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 120:
#line 934 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 121:
#line 939 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 122:
#line 944 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 123:
#line 951 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 124:
#line 952 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 125:
#line 953 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 126:
#line 957 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 127:
#line 958 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 128:
#line 959 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 129:
#line 963 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 130:
#line 964 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 131:
#line 968 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 132:
#line 973 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 133:
#line 978 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 134:
#line 985 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 135:
#line 986 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 136:
#line 987 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 137:
#line 991 "ctlib/parser.y"
    { yyval.uval = T_TYPEDEF;  ;}
    break;

  case 138:
#line 992 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 139:
#line 993 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 140:
#line 994 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 141:
#line 995 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 142:
#line 996 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 143:
#line 1000 "ctlib/parser.y"
    { yyval.uval = T_INT;      ;}
    break;

  case 144:
#line 1001 "ctlib/parser.y"
    { yyval.uval = T_CHAR;     ;}
    break;

  case 145:
#line 1002 "ctlib/parser.y"
    { yyval.uval = T_SHORT;    ;}
    break;

  case 146:
#line 1003 "ctlib/parser.y"
    { yyval.uval = T_LONG;     ;}
    break;

  case 147:
#line 1004 "ctlib/parser.y"
    { yyval.uval = T_FLOAT;    ;}
    break;

  case 148:
#line 1005 "ctlib/parser.y"
    { yyval.uval = T_DOUBLE;   ;}
    break;

  case 149:
#line 1006 "ctlib/parser.y"
    { yyval.uval = T_SIGNED;   ;}
    break;

  case 150:
#line 1007 "ctlib/parser.y"
    { yyval.uval = T_UNSIGNED; ;}
    break;

  case 151:
#line 1008 "ctlib/parser.y"
    { yyval.uval = T_VOID;     ;}
    break;

  case 152:
#line 1012 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 153:
#line 1013 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 154:
#line 1018 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      LinkedList strdecls = EX_STRDECL_LIST( yyvsp[-1].list );
	      yyval.tspec.tflags = yyvsp[-3].uval;
	      yyval.tspec.ptr = struct_new( NULL, 0, yyvsp[-3].uval, PSTATE->pragma.pack.current, strdecls );
	      LL_push( PSTATE->pCPI->structs, yyval.tspec.ptr );
	    }
	  ;}
    break;

  case 155:
#line 1031 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      LinkedList strdecls = EX_STRDECL_LIST( yyvsp[-1].list );
	      Struct *pStruct = HT_get( PSTATE->pCPI->htStructs, yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-3].idOrType.hash );
	      yyval.tspec.tflags = yyvsp[-4].uval;

	      if( pStruct == NULL ) {
	        yyval.tspec.ptr = struct_new( yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-4].uval, PSTATE->pragma.pack.current, strdecls );
	        LL_push( PSTATE->pCPI->structs, yyval.tspec.ptr );
	        STORE_IN_HASH( htStructs, yyvsp[-3].idOrType, yyval.tspec.ptr );
	      }
	      else {
	        DELETE_NODE( yyvsp[-3].idOrType );
	        yyval.tspec.ptr = pStruct;

	        if( pStruct->declarations == NULL ) {
	          pStruct->declarations = strdecls;
	          pStruct->pack         = PSTATE->pragma.pack.current;
	        }
	        else
	          LL_destroy( strdecls, (LLDestroyFunc) structdecl_delete );
	      }
	    }
	  ;}
    break;

  case 156:
#line 1060 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      Struct *pStruct = HT_get( PSTATE->pCPI->htStructs, yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, yyvsp[0].idOrType.hash );

	      yyval.tspec.tflags = yyvsp[-1].uval;

	      if( pStruct == NULL ) {
	        yyval.tspec.ptr = struct_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, yyvsp[-1].uval, 0, NULL );
	        LL_push( PSTATE->pCPI->structs, yyval.tspec.ptr );
	        STORE_IN_HASH( htStructs, yyvsp[0].idOrType, yyval.tspec.ptr );
	      }
	      else {
	        DELETE_NODE( yyvsp[0].idOrType );
	        yyval.tspec.ptr = pStruct;
	      }
	    }
	  ;}
    break;

  case 157:
#line 1084 "ctlib/parser.y"
    { yyval.uval = T_STRUCT; ;}
    break;

  case 158:
#line 1085 "ctlib/parser.y"
    { yyval.uval = T_UNION;  ;}
    break;

  case 159:
#line 1090 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = LL_new();
	      LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	      LL_unshift( PSTATE->structDeclListsList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting struct declaration list (0x%08X) (count=%d)",
	                         yyval.list, LL_count(PSTATE->structDeclListsList)) );
	    }
	  ;}
    break;

  case 160:
#line 1103 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = yyvsp[-1].list;
	      LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	    }
	  ;}
    break;

  case 161:
#line 1115 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 162:
#line 1116 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 163:
#line 1117 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 164:
#line 1122 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pStructDecl = NULL;
	    }
	    else {
	      yyval.pStructDecl = structdecl_new( yyvsp[0].tspec, NULL );
	      LL_unshift( PSTATE->structDeclList, yyval.pStructDecl );
	      CT_DEBUG( PARSER, ("unshifting unnamed struct declaration (0x%08X)", yyval.pStructDecl) );
	    }
	  ;}
    break;

  case 165:
#line 1136 "ctlib/parser.y"
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
	      CT_DEBUG( PARSER, ("unshifting struct declaration (0x%08X) (count=%d)",
	                         yyval.pStructDecl, LL_count(PSTATE->structDeclList)) );
	    }
	  ;}
    break;

  case 166:
#line 1151 "ctlib/parser.y"
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

  case 167:
#line 1165 "ctlib/parser.y"
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
	      CT_DEBUG( PARSER, ("unshifting struct declaration (0x%08X) (count=%d)",
	                         yyval.pStructDecl, LL_count(PSTATE->structDeclList)) );
	    }
	  ;}
    break;

  case 168:
#line 1181 "ctlib/parser.y"
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

  case 169:
#line 1195 "ctlib/parser.y"
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

  case 170:
#line 1205 "ctlib/parser.y"
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

  case 171:
#line 1218 "ctlib/parser.y"
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

  case 172:
#line 1228 "ctlib/parser.y"
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

  case 173:
#line 1240 "ctlib/parser.y"
    { yyval.ival = -1; ;}
    break;

  case 174:
#line 1241 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].ival; ;}
    break;

  case 175:
#line 1245 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].value.iv; ;}
    break;

  case 176:
#line 1250 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	      LL_destroy( yyvsp[-1].list, (LLDestroyFunc) enum_delete );
	    }
	    else {
	      yyval.tspec.tflags = T_ENUM;
	      yyval.tspec.ptr    = enumspec_new( NULL, 0, yyvsp[-1].list );
	      LL_push( PSTATE->pCPI->enums, yyval.tspec.ptr );
	    }
	    PSTATE->curEnumList = NULL;
	  ;}
    break;

  case 177:
#line 1264 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      EnumSpecifier *pEnum;

	      yyval.tspec.tflags = T_ENUM;
	      pEnum = HT_get( PSTATE->pCPI->htEnums, yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-3].idOrType.hash );

	      if( pEnum == NULL ) {
	        yyval.tspec.ptr = enumspec_new( yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-1].list );
	        LL_push( PSTATE->pCPI->enums, yyval.tspec.ptr );
	        STORE_IN_HASH( htEnums, yyvsp[-3].idOrType, yyval.tspec.ptr );
	      }
	      else {
	        DELETE_NODE( yyvsp[-3].idOrType );
	        yyval.tspec.ptr = pEnum;

	        if( pEnum->enumerators == NULL )
	          enumspec_update( pEnum, yyvsp[-1].list );
	        else
	          LL_destroy( yyvsp[-1].list, (LLDestroyFunc) enum_delete );
	      }
	    }

	    PSTATE->curEnumList = NULL;
	  ;}
    break;

  case 178:
#line 1294 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      EnumSpecifier *pEnum;

	      yyval.tspec.tflags = T_ENUM;
	      pEnum = HT_get( PSTATE->pCPI->htEnums, yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, yyvsp[0].idOrType.hash );

	      if( pEnum == NULL ) {
	        yyval.tspec.ptr = enumspec_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, NULL );
	        LL_push( PSTATE->pCPI->enums, yyval.tspec.ptr );
	        STORE_IN_HASH( htEnums, yyvsp[0].idOrType, yyval.tspec.ptr );
	      }
	      else {
	        DELETE_NODE( yyvsp[0].idOrType );
	        yyval.tspec.ptr = pEnum;
	      }
	    }
	  ;}
    break;

  case 179:
#line 1320 "ctlib/parser.y"
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

  case 180:
#line 1334 "ctlib/parser.y"
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

  case 181:
#line 1350 "ctlib/parser.y"
    {
	    yyval.list = yyvsp[-1].list;
	  ;}
    break;

  case 182:
#line 1357 "ctlib/parser.y"
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

  case 183:
#line 1367 "ctlib/parser.y"
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

  case 188:
#line 1389 "ctlib/parser.y"
    {;}
    break;

  case 189:
#line 1390 "ctlib/parser.y"
    {;}
    break;

  case 190:
#line 1391 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 191:
#line 1392 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 192:
#line 1393 "ctlib/parser.y"
    {;}
    break;

  case 193:
#line 1394 "ctlib/parser.y"
    {;}
    break;

  case 194:
#line 1395 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 195:
#line 1396 "ctlib/parser.y"
    {;}
    break;

  case 196:
#line 1397 "ctlib/parser.y"
    {;}
    break;

  case 197:
#line 1398 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 198:
#line 1399 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 199:
#line 1400 "ctlib/parser.y"
    {;}
    break;

  case 200:
#line 1401 "ctlib/parser.y"
    {;}
    break;

  case 201:
#line 1402 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 202:
#line 1410 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 203:
#line 1411 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 204:
#line 1416 "ctlib/parser.y"
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

  case 205:
#line 1431 "ctlib/parser.y"
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

  case 206:
#line 1447 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      unsigned size;
	      u_32 flags;
	      (void) GetTypeInfo( PSTATE->pCPC, &yyvsp[0].tspec, NULL, &size, NULL, NULL, &flags );
	      yyval.value.iv    = size;
	      yyval.value.flags = 0;
	      if( flags & T_HASBITFIELD )
	        yyval.value.flags |= V_IS_UNSAFE_BITFIELD;
	      if( flags & T_UNSAFE_VAL )
	        yyval.value.flags |= V_IS_UNSAFE;
	    }
	  ;}
    break;

  case 207:
#line 1461 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      if( yyvsp[0].absDecl.pointer_flag ) {
	        yyval.value.iv = PSTATE->pCPC->ptr_size * yyvsp[0].absDecl.multiplicator;
	      }
	      else {
	        unsigned size;
	        u_32 flags;
	        (void) GetTypeInfo( PSTATE->pCPC, &yyvsp[-1].tspec, NULL, &size, NULL, NULL, &flags );
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

  case 208:
#line 1480 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = PSTATE->pCPC->int_size;
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 209:
#line 1487 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
                      PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 214:
#line 1504 "ctlib/parser.y"
    {;}
    break;

  case 222:
#line 1524 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[0].idOrType ); ;}
    break;

  case 229:
#line 1538 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-2].idOrType ); ;}
    break;

  case 247:
#line 1577 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-1].idOrType ); ;}
    break;

  case 257:
#line 1602 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 258:
#line 1603 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 259:
#line 1604 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 260:
#line 1605 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 261:
#line 1606 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 262:
#line 1607 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 263:
#line 1608 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 264:
#line 1609 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 265:
#line 1610 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 266:
#line 1611 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 267:
#line 1613 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 268:
#line 1613 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 269:
#line 1614 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 270:
#line 1614 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 271:
#line 1615 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 272:
#line 1615 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 273:
#line 1616 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 274:
#line 1616 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 275:
#line 1617 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 276:
#line 1617 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 277:
#line 1619 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 278:
#line 1619 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 279:
#line 1620 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 280:
#line 1620 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 281:
#line 1621 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 282:
#line 1621 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 283:
#line 1622 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 284:
#line 1622 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 285:
#line 1623 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 286:
#line 1623 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 287:
#line 1627 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 288:
#line 1628 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 289:
#line 1632 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 290:
#line 1633 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 291:
#line 1638 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	      LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	      CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (count=%d)",
	                         yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	    }
	  ;}
    break;

  case 292:
#line 1650 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( ((Typedef *) yyvsp[-1].tspec.ptr)->pDecl->identifier, 0 );
	      if( yyvsp[0].list )
	        LL_delete( LL_splice( yyval.pDecl->array, 0, 0, EX_ARRAY( yyvsp[0].list ) ) );
	      LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	      CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (count=%d)",
	                         yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	    }
	  ;}
    break;

  case 293:
#line 1663 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 294:
#line 1670 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 295:
#line 1672 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 296:
#line 1678 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 297:
#line 1686 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 298:
#line 1688 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 299:
#line 1698 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 300:
#line 1700 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 301:
#line 1706 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 302:
#line 1712 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 303:
#line 1718 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 304:
#line 1726 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 305:
#line 1728 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 306:
#line 1733 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 307:
#line 1741 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	      LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	      CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (count=%d)",
	                         yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	    }
	  ;}
    break;

  case 308:
#line 1752 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 309:
#line 1756 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 310:
#line 1757 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 311:
#line 1761 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 312:
#line 1763 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 313:
#line 1769 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 314:
#line 1778 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 315:
#line 1782 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 316:
#line 1784 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 317:
#line 1792 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier ) {
	      yyval.pDecl = decl_new( yyvsp[0].identifier->key, yyvsp[0].identifier->keylen );
	      HN_delete( EX_NODE( yyvsp[0].identifier ) );
	      LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	      CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (count=%d)",
	                         yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	    }
	    else {
	      yyval.pDecl = NULL;
	    }
	  ;}
    break;

  case 318:
#line 1804 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 319:
#line 1808 "ctlib/parser.y"
    {;}
    break;

  case 320:
#line 1809 "ctlib/parser.y"
    {;}
    break;

  case 321:
#line 1810 "ctlib/parser.y"
    {;}
    break;

  case 322:
#line 1815 "ctlib/parser.y"
    {
	    if( yyvsp[-3].pDecl )
	      decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  ;}
    break;

  case 323:
#line 1819 "ctlib/parser.y"
    {;}
    break;

  case 324:
#line 1821 "ctlib/parser.y"
    {
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;

  case 325:
#line 1828 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 326:
#line 1829 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 327:
#line 1831 "ctlib/parser.y"
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

  case 328:
#line 1844 "ctlib/parser.y"
    { yyval.list = yyvsp[0].list;   ;}
    break;

  case 329:
#line 1845 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 330:
#line 1846 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 331:
#line 1850 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 332:
#line 1852 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = LL_new();
	      LL_unshift( PSTATE->arrayList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting array (0x%08X) (count=%d)",
	                         yyval.list, LL_count(PSTATE->arrayList)) );
	      LL_push( yyval.list, value_new( yyvsp[-1].value.iv, yyvsp[-1].value.flags ) );
	      CT_DEBUG( PARSER, ("array dimension => %d", yyvsp[-1].value) );
	    }
	  ;}
    break;

  case 333:
#line 1866 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = LL_new();
	      LL_unshift( PSTATE->arrayList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting array (0x%08X) (count=%d)",
	                         yyval.list, LL_count(PSTATE->arrayList)) );
	      LL_push( yyval.list, value_new( 0, 0 ) );
	      CT_DEBUG( PARSER, ("array dimension => *") );
	    }
	  ;}
    break;

  case 334:
#line 1880 "ctlib/parser.y"
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
	        CT_DEBUG( PARSER, ("unshifting array (0x%08X) (count=%d)",
	                           yyval.list, LL_count(PSTATE->arrayList)) );
	      }
	      LL_push( yyval.list, value_new( yyvsp[-1].value.iv, yyvsp[-1].value.flags ) );
	      CT_DEBUG( PARSER, ("array dimension => %d", yyvsp[-1].value) );
	    }
	  ;}
    break;

  case 335:
#line 1899 "ctlib/parser.y"
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
	        CT_DEBUG( PARSER, ("unshifting array (0x%08X) (count=%d)",
	                           yyval.list, LL_count(PSTATE->arrayList)) );
	      }
	      LL_push( yyval.list, value_new( 0, 0 ) );
	      CT_DEBUG( PARSER, ("array dimension => *" ) );
	    }
	  ;}
    break;

  case 336:
#line 1921 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 337:
#line 1926 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 338:
#line 1931 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 339:
#line 1936 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 340:
#line 1943 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 341:
#line 1944 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 342:
#line 1946 "ctlib/parser.y"
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

  case 343:
#line 1957 "ctlib/parser.y"
    {
	    yyval.absDecl = yyvsp[-2].absDecl;
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 4437 "ctlib/parser.c"

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


#line 1964 "ctlib/parser.y"



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

static int c_lex( void *pYYLVAL, ParserState *pState )
{
  YYSTYPE *plval = (YYSTYPE *) pYYLVAL;
  int rval, token;
  struct lexer_state *pLexer = pState->pLexer;

  CT_DEBUG( CLEXER, ("parser.y::c_lex()") );

  while( (rval = lex( pLexer )) < CPPERR_EOF ) {
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
          int len = strlen( pLexer->ctok->name );

          CT_DEBUG( CLEXER, ("new context: file '%s', line %ld",
                             pLexer->ctok->name, pLexer->ctok->line) );

          if( ! HT_exists( pState->pCPI->htFiles, pLexer->ctok->name, len, 0 ) )
	    HT_store( pState->pCPI->htFiles, pLexer->ctok->name, len, 0, 
                      fileinfo_new( pLexer->input ) );

          if( pState->filename )
            Free( pState->filename );

          pState->filename = (char *) Alloc( len + 1 );
          strcpy( pState->filename, pLexer->ctok->name );
        }
        break;

      case NUMBER:
        CT_DEBUG( CLEXER, ("token-type => NUMBER => [%s]", pLexer->ctok->name) );
        plval->value.iv = strtol( pLexer->ctok->name, NULL, 0 );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("constant: %s -> %d", pLexer->ctok->name, plval->value.iv) );
        return CONSTANT;

      case STRING:
        CT_DEBUG( CLEXER, ("token-type => STRING => [%s]", pLexer->ctok->name) );
        plval->value.iv = string_size( pLexer->ctok->name );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("string literal: %s -> %d", pLexer->ctok->name, plval->value.iv) );
        return STRING_LITERAL;

      case CHAR:
        CT_DEBUG( CLEXER, ("token-type => CHAR => [%s]", pLexer->ctok->name) );
        plval->value.iv = get_char_value( pLexer->ctok->name );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("constant: %s -> %d", pLexer->ctok->name, plval->value.iv) );
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
static void *ex_object( LinkedList list, void *object )
#endif
{
  void *obj;
  int   item = 0;

  CT_DEBUG( PARSER, ("ex_object( type=\"%s\", list=0x%08X, object=0x%08X )",
                     type, list, object) );

  LL_foreach( obj, list ) {
    if( obj == object )
      break;
    item++;
  }

  if( obj != object ) {
    CT_DEBUG( PARSER, ("%s (0x%08X) not found in ex_object()", type, object, item) );
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
  FormatError( pState->pCPI, "%s, line %d: %s",
               pState->filename, pState->pLexer->ctok->line, msg );
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

static int get_char_value( char *s )
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

static int string_size( char *s )
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

static int check_type( void *pYYLVAL, ParserState *pState, char *s )
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
    CT_DEBUG( CLEXER, ("unshifting identifier \"%s\" (0x%08X) (count=%d)",
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
                           struct lexer_state *pLexer )
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

  pState = (ParserState *) Alloc( sizeof( ParserState ) );

  pState->pCPI                = pCPI;
  pState->pCPC                = pCPC;
  pState->pLexer              = pLexer;

  pState->flags               = 0;
  pState->filename            = NULL;
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

  if( pState->filename )
    Free( pState->filename );

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
        CT_DEBUG( PARSER, ("[ARRAY=0x%08X]", list) );
        LL_foreach( pVal, list )
          CT_DEBUG( PARSER, ("[value=%d,flags=0x%08X]", pVal->iv, pVal->flags) );
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


