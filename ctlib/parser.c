/* A Bison parser, made from ctlib/parser.y, by GNU bison 1.75.  */

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
#define YYBISON	1

/* Pure parsers.  */
#define YYPURE	1

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
     PTR_OP = 292,
     INC_OP = 293,
     DEC_OP = 294,
     LEFT_OP = 295,
     RIGHT_OP = 296,
     LE_OP = 297,
     GE_OP = 298,
     EQ_OP = 299,
     NE_OP = 300,
     AND_OP = 301,
     OR_OP = 302,
     ELLIPSIS = 303,
     MUL_ASSIGN = 304,
     DIV_ASSIGN = 305,
     MOD_ASSIGN = 306,
     ADD_ASSIGN = 307,
     SUB_ASSIGN = 308,
     LEFT_ASSIGN = 309,
     RIGHT_ASSIGN = 310,
     AND_ASSIGN = 311,
     XOR_ASSIGN = 312,
     OR_ASSIGN = 313,
     IDENTIFIER = 314,
     STRING_LITERAL = 315,
     CONSTANT = 316,
     TYPE_NAME = 317
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
#define PTR_OP 292
#define INC_OP 293
#define DEC_OP 294
#define LEFT_OP 295
#define RIGHT_OP 296
#define LE_OP 297
#define GE_OP 298
#define EQ_OP 299
#define NE_OP 300
#define AND_OP 301
#define OR_OP 302
#define ELLIPSIS 303
#define MUL_ASSIGN 304
#define DIV_ASSIGN 305
#define MOD_ASSIGN 306
#define ADD_ASSIGN 307
#define SUB_ASSIGN 308
#define LEFT_ASSIGN 309
#define RIGHT_ASSIGN 310
#define AND_ASSIGN 311
#define XOR_ASSIGN 312
#define OR_ASSIGN 313
#define IDENTIFIER 314
#define STRING_LITERAL 315
#define CONSTANT 316
#define TYPE_NAME 317




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
* $Date: 2002/12/07 18:17:28 +0100 $
* $Revision: 10 $
* $Snapshot: /Convert-Binary-C/0.06 $
* $Source: /ctlib/parser.y $
*
********************************************************************************
*
* Copyright (c) 2002 Marcus Holland-Moritz. All rights reserved.
* This program is free software; you can redistribute it and/or
* modify it under the same terms as Perl itself.
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
	'[',		/* LBRK, */		/*		*/
	']',		/* RBRK, */		/*		*/
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

#ifndef YYSTYPE
#line 383 "ctlib/parser.y"
typedef union {
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
} yystype;
/* Line 193 of /home/mhx/bin/bison-1.75/share/bison/yacc.c.  */
#line 560 "ctlib/parser.c"
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} yyltype;
# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */


/* Line 213 of /home/mhx/bin/bison-1.75/share/bison/yacc.c.  */
#line 581 "ctlib/parser.c"

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
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)

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
	    (To)[yyi] = (From)[yyi];	\
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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
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
#define YYLAST   2136

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  117
/* YYNRULES -- Number of rules. */
#define YYNRULES  336
/* YYNRULES -- Number of states. */
#define YYNSTATES  547

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    78,    71,     2,
      63,    64,    72,    73,    70,    74,    67,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    86,
      79,    85,    80,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    82,    69,    75,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
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
     350,   353,   356,   359,   361,   364,   367,   370,   373,   376,
     378,   381,   384,   386,   388,   390,   392,   394,   396,   398,
     400,   402,   404,   406,   408,   410,   412,   414,   416,   418,
     423,   429,   432,   434,   436,   438,   441,   444,   447,   450,
     454,   457,   461,   464,   466,   469,   471,   472,   474,   477,
     482,   488,   491,   493,   497,   500,   502,   506,   508,   512,
     514,   518,   520,   523,   526,   529,   531,   534,   537,   539,
     542,   545,   548,   550,   553,   556,   558,   562,   564,   566,
     568,   571,   573,   576,   577,   580,   584,   589,   591,   594,
     599,   600,   603,   605,   608,   612,   615,   617,   619,   621,
     623,   625,   627,   631,   636,   640,   643,   647,   651,   656,
     658,   661,   663,   666,   669,   675,   683,   689,   695,   703,
     713,   717,   720,   723,   727,   728,   730,   732,   735,   737,
     739,   740,   744,   745,   750,   751,   756,   757,   762,   763,
     768,   769,   773,   774,   779,   780,   785,   786,   791,   792,
     797,   798,   803,   804,   810,   811,   817,   818,   824,   825,
     831,   833,   835,   837,   839,   841,   844,   846,   848,   851,
     855,   859,   864,   866,   871,   877,   880,   884,   888,   893,
     898,   900,   904,   906,   908,   910,   913,   917,   920,   924,
     929,   931,   935,   937,   940,   944,   949,   953,   958,   960,
     962,   964,   966,   969,   973,   976,   980,   984,   989,   994,
     996,   999,  1002,  1006,  1010,  1014,  1018
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     166,     0,    -1,    60,    -1,    88,    60,    -1,    59,    -1,
      61,    -1,    88,    -1,    63,   111,    64,    -1,    89,    -1,
      90,    65,   111,    66,    -1,    90,    63,    64,    -1,    90,
      63,    94,    64,    -1,    -1,    90,    91,    67,    93,    -1,
      -1,    90,    92,    37,    93,    -1,    90,    38,    -1,    90,
      39,    -1,    63,   150,    64,    68,   153,    69,    -1,    63,
     150,    64,    68,   153,    70,    69,    -1,    59,    -1,    62,
      -1,   109,    -1,    94,    70,   109,    -1,    90,    -1,    38,
      95,    -1,    39,    95,    -1,    96,    97,    -1,    29,    95,
      -1,    29,    63,   150,    64,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,    95,    -1,
      63,   150,    64,    97,    -1,    97,    -1,    98,    72,    97,
      -1,    98,    77,    97,    -1,    98,    78,    97,    -1,    98,
      -1,    99,    73,    98,    -1,    99,    74,    98,    -1,    99,
      -1,   100,    40,    99,    -1,   100,    41,    99,    -1,   100,
      -1,   101,    79,   100,    -1,   101,    80,   100,    -1,   101,
      42,   100,    -1,   101,    43,   100,    -1,   101,    -1,   102,
      44,   101,    -1,   102,    45,   101,    -1,   102,    -1,   103,
      71,   102,    -1,   103,    -1,   104,    81,   103,    -1,   104,
      -1,   105,    82,   104,    -1,   105,    -1,   106,    46,   105,
      -1,   106,    -1,   107,    47,   106,    -1,   107,    -1,   107,
      83,   111,    84,   108,    -1,   108,    -1,    95,   110,   109,
      -1,    85,    -1,    49,    -1,    50,    -1,    51,    -1,    52,
      -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,   109,    -1,   111,    70,   109,    -1,   108,
      -1,    -1,   111,    -1,   125,    86,    -1,   126,    86,    -1,
     116,    86,    -1,   115,    86,    -1,   119,   193,   151,    -1,
     120,   193,   151,    -1,   115,    70,   193,   151,    -1,   117,
     185,   151,    -1,   118,   185,   151,    -1,   116,    70,   185,
     151,    -1,   123,    -1,   125,    -1,   127,    -1,   124,    -1,
     126,    -1,   128,    -1,   129,    -1,   120,   129,    -1,   119,
     121,    -1,   122,    -1,   120,   122,    -1,   129,    -1,   122,
      -1,    19,    -1,    36,    -1,    30,    -1,   119,   130,    -1,
     124,   129,    -1,   123,   121,    -1,   123,   130,    -1,   130,
      -1,   120,   130,    -1,   124,   122,    -1,   124,   130,    -1,
     119,   131,    -1,   126,   129,    -1,   125,   121,    -1,   131,
      -1,   120,   131,    -1,   126,   122,    -1,   128,   129,    -1,
     119,    62,    -1,   127,   121,    -1,    62,    -1,   120,    62,
      -1,   128,   122,    -1,    14,    -1,    16,    -1,    33,    -1,
       3,    -1,    13,    -1,    35,    -1,     5,    -1,    15,    -1,
      21,    -1,     9,    -1,    20,    -1,     4,    -1,    25,    -1,
      22,    -1,    26,    -1,   132,    -1,   142,    -1,   133,    68,
     134,    69,    -1,   133,   149,    68,   134,    69,    -1,   133,
     149,    -1,     6,    -1,    18,    -1,   135,    -1,   134,   135,
      -1,   137,    86,    -1,   136,    86,    -1,   120,   139,    -1,
     136,    70,   139,    -1,   118,   138,    -1,   137,    70,   138,
      -1,   185,   140,    -1,   141,    -1,   193,   140,    -1,   141,
      -1,    -1,   141,    -1,    84,   112,    -1,    12,    68,   143,
      69,    -1,    12,   149,    68,   143,    69,    -1,    12,   149,
      -1,   144,    -1,   143,    70,   144,    -1,   143,    70,    -1,
     149,    -1,   149,    85,   112,    -1,   146,    -1,   146,    70,
      48,    -1,   147,    -1,   146,    70,   147,    -1,   117,    -1,
     117,   199,    -1,   117,   193,    -1,   117,   187,    -1,   119,
      -1,   119,   199,    -1,   119,   193,    -1,   118,    -1,   118,
     199,    -1,   118,   193,    -1,   118,   187,    -1,   120,    -1,
     120,   199,    -1,   120,   193,    -1,    59,    -1,   148,    70,
      59,    -1,    59,    -1,    62,    -1,   118,    -1,   118,   199,
      -1,   120,    -1,   120,   199,    -1,    -1,    85,   152,    -1,
      68,   153,    69,    -1,    68,   153,    70,    69,    -1,   109,
      -1,   154,   152,    -1,   153,    70,   154,   152,    -1,    -1,
     155,    85,    -1,   156,    -1,   155,   156,    -1,    65,   112,
      66,    -1,    67,   149,    -1,   158,    -1,   159,    -1,   162,
      -1,   163,    -1,   164,    -1,   165,    -1,   149,    84,   157,
      -1,    11,   112,    84,   157,    -1,    27,    84,   157,    -1,
      68,    69,    -1,    68,   160,    69,    -1,    68,   161,    69,
      -1,    68,   160,   161,    69,    -1,   114,    -1,   160,   114,
      -1,   157,    -1,   161,   157,    -1,   113,    86,    -1,    32,
      63,   111,    64,   157,    -1,    32,    63,   111,    64,   157,
       8,   157,    -1,    10,    63,   111,    64,   157,    -1,    34,
      63,   111,    64,   157,    -1,    31,   157,    34,    63,   111,
      64,    86,    -1,    24,    63,   113,    86,   113,    86,   113,
      64,   157,    -1,    28,   149,    86,    -1,    23,    86,    -1,
       7,    86,    -1,    17,   113,    86,    -1,    -1,   167,    -1,
     168,    -1,   167,   168,    -1,   169,    -1,   114,    -1,    -1,
     193,   170,   159,    -1,    -1,   117,   193,   171,   159,    -1,
      -1,   118,   193,   172,   159,    -1,    -1,   119,   193,   173,
     159,    -1,    -1,   120,   193,   174,   159,    -1,    -1,   197,
     175,   159,    -1,    -1,   117,   197,   176,   159,    -1,    -1,
     118,   197,   177,   159,    -1,    -1,   119,   197,   178,   159,
      -1,    -1,   120,   197,   179,   159,    -1,    -1,   197,   160,
     180,   159,    -1,    -1,   117,   197,   160,   181,   159,    -1,
      -1,   118,   197,   160,   182,   159,    -1,    -1,   119,   197,
     160,   183,   159,    -1,    -1,   120,   197,   160,   184,   159,
      -1,   193,    -1,   186,    -1,   190,    -1,   187,    -1,    62,
      -1,    62,   200,    -1,   188,    -1,   189,    -1,    72,   187,
      -1,    72,   120,   187,    -1,    63,   188,    64,    -1,    63,
     188,    64,   200,    -1,   191,    -1,    72,    63,   192,    64,
      -1,    72,   120,    63,   192,    64,    -1,    72,   190,    -1,
      72,   120,   190,    -1,    63,   190,    64,    -1,    63,   192,
     200,    64,    -1,    63,   190,    64,   200,    -1,    62,    -1,
      63,   192,    64,    -1,   194,    -1,   196,    -1,   195,    -1,
      72,   193,    -1,    72,   120,   193,    -1,   196,   200,    -1,
      63,   194,    64,    -1,    63,   194,    64,   200,    -1,    59,
      -1,    63,   196,    64,    -1,   198,    -1,    72,   197,    -1,
      72,   120,   197,    -1,   196,    63,   148,    64,    -1,    63,
     197,    64,    -1,    63,   197,    64,   200,    -1,   202,    -1,
     203,    -1,   200,    -1,   201,    -1,    63,    64,    -1,    63,
     145,    64,    -1,    65,    66,    -1,    65,   109,    66,    -1,
      65,    72,    66,    -1,   201,    65,   109,    66,    -1,   201,
      65,    72,    66,    -1,    72,    -1,    72,   120,    -1,    72,
     199,    -1,    72,   120,   199,    -1,    63,   202,    64,    -1,
      63,   203,    64,    -1,    63,   200,    64,    -1,    63,   202,
      64,   200,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   534,   534,   535,   542,   548,   549,   550,   554,   555,
     556,   557,   558,   558,   559,   559,   560,   561,   562,   563,
     567,   568,   572,   573,   577,   578,   579,   580,   598,   599,
     603,   604,   605,   606,   607,   608,   612,   613,   617,   618,
     620,   627,   637,   638,   640,   645,   646,   648,   653,   654,
     656,   658,   660,   665,   666,   668,   673,   674,   679,   680,
     685,   686,   691,   692,   697,   698,   703,   704,   709,   710,
     714,   715,   716,   717,   718,   719,   720,   721,   722,   723,
     724,   728,   729,   733,   738,   739,   777,   778,   779,   780,
     787,   809,   815,   826,   849,   855,   867,   872,   873,   878,
     883,   884,   890,   891,   892,   896,   897,   901,   902,   906,
     907,   908,   912,   913,   914,   915,   919,   920,   921,   922,
     926,   931,   936,   944,   945,   946,   951,   956,   961,   969,
     970,   971,   975,   976,   977,   978,   979,   980,   984,   985,
     986,   987,   988,   989,   990,   991,   992,   996,   997,  1001,
    1014,  1043,  1068,  1069,  1073,  1086,  1099,  1100,  1104,  1119,
    1133,  1149,  1163,  1173,  1186,  1196,  1209,  1210,  1214,  1218,
    1232,  1262,  1288,  1302,  1318,  1325,  1335,  1348,  1349,  1353,
    1354,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,  1366,
    1367,  1368,  1369,  1370,  1371,  1379,  1380,  1384,  1399,  1415,
    1429,  1448,  1455,  1466,  1467,  1471,  1472,  1473,  1477,  1478,
    1482,  1483,  1487,  1488,  1492,  1493,  1498,  1499,  1500,  1501,
    1502,  1503,  1507,  1508,  1509,  1513,  1514,  1515,  1516,  1520,
    1521,  1525,  1526,  1530,  1534,  1535,  1536,  1540,  1541,  1542,
    1546,  1547,  1548,  1549,  1556,  1557,  1561,  1562,  1566,  1567,
    1571,  1571,  1573,  1573,  1575,  1575,  1577,  1577,  1579,  1579,
    1582,  1582,  1583,  1583,  1584,  1584,  1585,  1585,  1586,  1586,
    1588,  1588,  1589,  1589,  1590,  1590,  1591,  1591,  1592,  1592,
    1596,  1597,  1601,  1602,  1606,  1618,  1632,  1639,  1640,  1646,
    1655,  1656,  1667,  1668,  1674,  1680,  1686,  1695,  1696,  1701,
    1709,  1721,  1725,  1726,  1730,  1731,  1737,  1746,  1751,  1752,
    1760,  1773,  1777,  1778,  1779,  1783,  1788,  1789,  1797,  1798,
    1799,  1813,  1814,  1815,  1819,  1820,  1834,  1848,  1867,  1889,
    1894,  1899,  1904,  1912,  1913,  1914,  1925
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
  "RESTRICT_TOK", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", 
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "ELLIPSIS", 
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", 
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", 
  "IDENTIFIER", "STRING_LITERAL", "CONSTANT", "TYPE_NAME", "'('", "')'", 
  "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'", "'*'", "'+'", "'-'", 
  "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", 
  "'='", "';'", "$accept", "string_literal_list", "primary_expression", 
  "postfix_expression", "@1", "@2", "member_name", 
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
  "sue_declaration_specifier", "sue_type_specifier", 
  "typedef_declaration_specifier", "typedef_type_specifier", 
  "storage_class", "basic_type_name", "elaborated_type_name", 
  "aggregate_name", "aggregate_key", "member_declaration_list", 
  "member_declaration", "member_default_declaring_list", 
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
     315,   316,   317,    40,    41,    91,    93,    46,   123,   125,
      44,    38,    42,    43,    45,   126,    33,    47,    37,    60,
      62,    94,   124,    63,    58,    61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    87,    88,    88,    89,    89,    89,    89,    90,    90,
      90,    90,    91,    90,    92,    90,    90,    90,    90,    90,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    99,    99,    99,   100,   100,   100,   101,   101,
     101,   101,   101,   102,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   112,   113,   113,   114,   114,   114,   114,
     115,   115,   115,   116,   116,   116,   117,   117,   117,   118,
     118,   118,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   123,   123,   123,   123,   124,   124,   124,   124,
     125,   125,   125,   126,   126,   126,   127,   127,   127,   128,
     128,   128,   129,   129,   129,   129,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   131,   131,   132,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   139,   139,   140,   140,   141,   142,
     142,   142,   143,   143,   143,   144,   144,   145,   145,   146,
     146,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   148,   148,   149,   149,   150,
     150,   150,   150,   151,   151,   152,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156,   157,   157,   157,   157,
     157,   157,   158,   158,   158,   159,   159,   159,   159,   160,
     160,   161,   161,   162,   163,   163,   163,   164,   164,   164,
     165,   165,   165,   165,   166,   166,   167,   167,   168,   168,
     170,   169,   171,   169,   172,   169,   173,   169,   174,   169,
     175,   169,   176,   169,   177,   169,   178,   169,   179,   169,
     180,   169,   181,   169,   182,   169,   183,   169,   184,   169,
     185,   185,   186,   186,   187,   187,   187,   188,   188,   188,
     189,   189,   190,   190,   190,   190,   190,   191,   191,   191,
     192,   192,   193,   193,   194,   194,   194,   195,   195,   195,
     196,   196,   197,   197,   197,   198,   198,   198,   199,   199,
     199,   200,   200,   200,   201,   201,   201,   201,   201,   202,
     202,   202,   202,   203,   203,   203,   203
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
       2,     2,     2,     1,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     2,     1,     1,     1,     2,     2,     2,     2,     3,
       2,     3,     2,     1,     2,     1,     0,     1,     2,     4,
       5,     2,     1,     3,     2,     1,     3,     1,     3,     1,
       3,     1,     2,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     1,     2,     2,     1,     3,     1,     1,     1,
       2,     1,     2,     0,     2,     3,     4,     1,     2,     4,
       0,     2,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     2,     3,     3,     4,     1,
       2,     1,     2,     2,     5,     7,     5,     5,     7,     9,
       3,     2,     2,     3,     0,     1,     1,     2,     1,     1,
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
     244,   135,   143,   138,   152,   141,     0,   136,   132,   139,
     133,   153,   109,   142,   140,   145,   144,   146,   111,   134,
     137,   110,   310,   129,     0,     0,   249,     0,     0,     0,
       0,     0,     0,   105,    96,    99,    97,   100,    98,   101,
     102,   116,   123,   147,     0,   148,     0,   245,   246,   248,
     250,   302,   304,   303,   260,   312,   197,   198,     0,   171,
       0,     0,     0,     0,   305,   313,     0,    89,     0,    88,
     284,     0,     0,   203,   281,   283,   286,   287,   282,   292,
     280,   262,   203,   280,   264,   127,   104,   108,   107,   112,
     120,   203,   266,   130,   106,   103,   117,   124,   203,   268,
     114,   115,   118,   113,   119,    86,   122,    87,   125,   121,
     128,   131,   126,     0,   151,     1,   247,     0,     0,     0,
     307,   321,   229,     0,     0,     0,     0,   270,     0,     0,
     172,   175,     0,   308,   311,   316,   306,   314,     0,     0,
     203,   303,     0,     0,   203,   280,     0,   285,   300,     0,
       0,     0,     0,     0,     0,   288,   295,     0,    93,     0,
     272,     0,    94,     0,   274,     0,    90,     0,   276,     0,
      91,     0,   278,     0,     0,     0,    99,   100,   101,     0,
     154,     0,     0,     0,    84,   251,   195,   322,   181,   188,
     185,   192,    97,   100,     0,   177,   179,     0,     0,     0,
       0,     4,     2,     5,     0,   324,    30,    31,    32,    33,
      34,    35,     6,     8,    24,    36,     0,    38,    42,    45,
      48,    53,    56,    58,    60,    62,    64,    66,    68,     0,
       0,   203,   203,   230,     0,   261,   169,   174,     0,     0,
     309,   317,     0,     0,    92,     0,     0,     0,    95,     0,
     290,   297,     0,     0,     0,   289,   296,   210,    31,   207,
     204,   253,     0,   263,   255,     0,   265,   257,     0,   267,
     259,     0,   269,     0,   160,   163,   166,   158,   165,   166,
     149,   155,     0,   157,     0,   156,     0,     0,     0,     0,
      84,     0,     0,     0,     0,    84,     0,     0,     4,   129,
     225,    81,    85,     0,     0,   231,   216,   217,    84,    84,
     218,   219,   220,   221,     0,   329,   184,   183,   182,   320,
     318,   319,   191,   190,   189,     0,   329,   187,   186,   194,
     193,   323,     0,   315,     0,     0,    28,     0,    25,    26,
       0,   199,   201,     0,   326,     3,    16,    17,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    70,     0,    36,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   325,    31,     0,   271,   173,
      83,   176,   170,     0,   301,   291,   299,   298,   293,     0,
       0,     0,     0,     0,     0,   212,   273,   275,   277,   279,
     168,   162,   167,   164,   159,   161,   150,   242,     0,     0,
       0,   241,    84,    84,     0,     0,     0,     0,     0,   233,
      84,   226,    84,   227,   232,     0,     0,     0,   330,   331,
     330,   178,   180,   196,     0,     0,     7,     0,   329,   200,
     202,     0,    10,     0,    22,     0,     0,     0,    69,    39,
      40,    41,    43,    44,    46,    47,    51,    52,    49,    50,
      54,    55,    57,    59,    61,    63,    65,     0,   328,   327,
     294,     0,   215,   205,   210,   208,   211,   213,     0,    84,
     243,     0,   224,   240,     0,     0,     0,    82,   222,   228,
     335,   333,   334,   332,    29,     0,   330,   210,    37,    11,
       0,     9,    20,    21,    13,    15,     0,   214,   206,     0,
      84,   223,    84,     0,    84,    84,   336,     0,    23,    67,
     209,   236,     0,     0,   234,   237,    18,   210,    84,     0,
      84,    19,     0,   238,   235,    84,   239
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   212,   213,   214,   350,   351,   514,   453,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   301,   363,   302,   391,   303,   122,    27,    28,
     123,   124,   125,   126,    86,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   179,   180,   181,
     182,   274,   277,   411,   275,    45,   129,   130,   194,   195,
     196,   197,   304,   343,   166,   260,   402,   403,   404,   405,
     305,   306,   307,   127,   309,   310,   311,   312,   313,    46,
      47,    48,    49,   117,   159,   163,   167,   171,   128,   161,
     165,   169,   173,   234,   262,   265,   268,   271,    73,    74,
      75,    76,    77,   151,    79,   152,    64,    51,    52,   141,
      62,    55,   439,   319,   121,   320,   321
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -471
static const short yypact[] =
{
    1437,  -471,  -471,  -471,  -471,  -471,   219,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,   190,   463,  -471,    13,    21,   165,
     165,  1472,  1507,  -471,  2100,  2100,   573,   649,   897,   897,
    -471,  -471,  -471,  -471,   312,  -471,    16,  1437,  -471,  -471,
    -471,  -471,  -471,   420,  1827,  -471,  -471,  -471,   -13,   -45,
     -20,   390,     4,   463,  -471,  -471,   247,  -471,   240,  -471,
     440,   432,   470,     2,  -471,  -471,  -471,  -471,  -471,  -471,
      11,  1827,     2,    24,  1827,  -471,  -471,  -471,  -471,  -471,
    -471,   -47,  1827,  -471,  -471,  -471,  -471,  -471,   -15,  1827,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,   947,    46,  -471,  -471,    61,  1719,  1835,
    -471,    72,  -471,   240,   240,  1542,  1577,  1827,    61,   171,
    -471,    73,   -13,   440,  -471,   440,  -471,  -471,   247,  1808,
       2,   440,   478,   667,     2,  -471,  1754,  -471,  -471,   432,
      90,   105,   440,   432,   692,  -471,  -471,  1853,  -471,    61,
    1827,    61,  -471,    61,  1827,    61,  -471,    61,  1827,    61,
    -471,    61,  1827,    61,    26,   687,  1082,    12,    12,  1646,
    -471,    32,    33,   947,   772,  -471,  -471,  -471,   359,   359,
    1218,  1282,   897,   897,   110,   114,  -471,    62,  1951,  1969,
    1969,  -471,  -471,  -471,   919,  -471,  -471,   123,  -471,  -471,
    -471,  -471,   133,  -471,  1208,   769,  2008,  -471,   261,   242,
     285,    63,   342,   125,   124,   127,   175,    -7,  -471,   163,
    2026,     2,     2,  -471,    61,  -471,  -471,   -13,  2008,   428,
    -471,  -471,   483,  1808,  -471,   478,   478,   967,  -471,   537,
     440,   440,   168,   547,   432,  -471,  -471,   447,  -471,  -471,
    -471,  -471,    61,  -471,  -471,    61,  -471,  -471,    61,  -471,
    -471,    61,  -471,  2008,  -471,  -471,   166,  -471,  -471,   166,
    -471,  -471,   122,  -471,    26,  -471,  1674,   174,   202,  2008,
    2008,   193,   274,   273,   -13,  1299,   310,   327,   316,   321,
    -471,  -471,   340,   362,   361,  -471,  -471,  -471,   846,   989,
    -471,  -471,  -471,  -471,  1063,   448,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  1127,   697,  -471,  -471,  -471,
    -471,  -471,  1789,  -471,   404,   919,  -471,   919,  -471,  -471,
      69,   154,  1612,   409,  -471,  -471,  -471,  -471,  1893,  2008,
     412,   450,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  2008,  -471,  -471,  2008,  2008,  2008,  2008,
    2008,  2008,  2008,  2008,  2008,  2008,  2008,  2008,  2008,  2008,
    2008,  2008,  2008,  2008,  2008,  -471,   436,   443,  -471,  -471,
    -471,  -471,  -471,   478,  -471,  -471,  -471,  -471,  -471,   551,
    2008,   -13,   449,  1853,   -30,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  2008,   431,
     438,  -471,  2008,  1299,   457,   515,  2008,  2008,  2008,  -471,
    1299,  -471,  1144,  -471,  -471,   517,   519,   520,   448,  -471,
     697,  -471,  -471,  -471,   524,   526,  -471,  1373,   508,  -471,
    -471,  1911,  -471,   244,  -471,    87,    50,    50,  -471,  -471,
    -471,  -471,   261,   261,   242,   242,   285,   285,   285,   285,
      63,    63,   342,   125,   124,   127,   175,    27,  -471,  -471,
    -471,   506,  -471,  -471,   231,  -471,  -471,  -471,   295,  1299,
    -471,   505,  -471,  -471,   542,   300,   302,  -471,  -471,  -471,
    -471,   440,  -471,  -471,   552,   552,   508,   447,  -471,  -471,
    2008,  -471,  -471,  -471,  -471,  -471,  2008,  -471,  -471,  1853,
    1299,  -471,  2008,  2008,  1299,  1299,  -471,   500,  -471,  -471,
    -471,  -471,   533,   344,   613,  -471,  -471,   360,  2008,   536,
    1299,  -471,   559,  -471,  -471,  1299,  -471
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -471,  -471,  -471,  -471,  -471,  -471,   167,  -471,   185,  -471,
    -196,    47,   203,    59,   201,   246,   249,   251,   245,   257,
    -471,  -223,  -106,  -471,    54,  -244,  -249,   120,  -471,  -471,
      17,    18,    22,     9,   -10,   -31,  -471,   -83,  -107,   -66,
    -471,   313,   405,   286,    40,  -471,  -471,   451,  -152,  -471,
    -471,   346,   364,   374,   170,  -471,   522,   423,  -471,  -471,
     329,  -471,    19,   199,    43,  -391,   157,  -470,  -471,   262,
      93,  -471,   476,    -6,   363,  -471,  -471,  -471,  -471,  -471,
    -471,   620,  -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,
    -471,  -471,  -471,  -471,  -471,  -471,  -471,  -471,     6,  -471,
     -39,   152,  -471,   347,  -471,   115,   204,    37,  -471,   214,
     626,  -471,  -131,   -51,  -471,  -271,  -252
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -259
static const short yytable[] =
{
      87,    94,   120,    87,   102,    87,   108,    87,   111,    32,
     120,   192,   485,   229,   519,   390,   115,    29,    30,   147,
     365,  -256,    31,   132,   100,    59,   106,   281,   110,   410,
     176,    12,    94,   155,    63,   400,    82,   401,   157,   192,
     383,   420,    18,   436,   133,   419,    56,   177,    21,    57,
     390,   259,   193,  -258,   436,   486,    32,   318,   324,   328,
     330,    60,   437,   114,    29,    30,   390,   519,   135,    31,
     157,    90,    97,   437,   144,   160,   384,   131,   164,  -252,
     193,   154,   240,    66,   241,    22,   168,   157,    70,   142,
     120,    68,  -254,   172,    87,    94,   176,   428,   143,    67,
     176,   252,   282,   284,   155,   373,   374,    69,    60,   512,
     273,   516,   513,   177,   183,   255,   158,   177,   283,   285,
      26,   176,   175,    94,   387,   162,   333,   191,   530,   184,
      82,   174,   334,   446,   281,   188,   189,   230,   177,   428,
     190,   170,   375,   376,    94,   102,   108,   111,   243,   316,
     322,   131,   247,   511,   250,   191,   481,   428,   238,    87,
      94,    87,   108,   188,   189,    90,    97,    26,   190,   251,
     459,   460,   461,   491,   331,    60,   436,   390,   308,    60,
     276,    22,   106,   244,   332,   138,    60,   248,   175,   344,
      60,   120,   175,   345,   139,   437,   379,   174,   252,   395,
     396,   174,   252,   176,    50,   380,   273,   192,   255,   381,
     449,   450,    94,   342,    53,    97,    94,   447,   192,   119,
     177,   382,   341,   150,    22,   192,   448,    70,    71,   385,
      90,    97,   397,    80,    83,    91,    98,    72,    61,    53,
     236,   237,   454,    53,    53,    53,    53,   233,   193,    22,
     273,    50,   176,    24,   176,   508,   131,   458,   340,   193,
     417,    53,    25,   435,   249,   418,   193,   136,   253,   177,
     140,   177,   145,   532,   435,   170,   155,    53,    56,   421,
     233,    57,    60,    60,   233,    61,    53,    58,   233,   542,
     276,    60,   233,   529,   150,   175,   400,   259,   401,    22,
     518,   150,    70,   142,   174,   150,    22,   503,   509,   503,
     138,    94,   143,   424,   510,   369,   370,    89,    96,   139,
     101,   104,   497,   191,   438,   371,   372,   145,   145,   231,
     232,   188,   189,   366,   191,   440,   190,   422,   367,   368,
     192,   191,   188,   189,   342,   278,   342,   190,   252,   188,
     189,    60,   242,   341,   190,   341,   242,   423,   136,   520,
     249,   253,    60,    61,   524,   428,   525,    61,    53,   399,
     428,    56,   428,   426,    57,   503,    78,    78,   145,   279,
     113,   193,    97,   336,   338,   339,   377,   378,   425,   340,
     427,   340,   317,   323,   327,   329,   435,   150,   150,   255,
    -197,   364,   434,   455,   528,  -198,   150,    94,   539,    94,
     428,    89,    96,   259,   428,    78,   462,   463,    22,   156,
     482,    70,   314,   364,   119,   400,   178,   401,   233,   541,
      60,   315,   466,   467,   468,   469,    88,    95,   477,    88,
     103,    88,   109,    88,   112,   430,   412,   136,   429,   412,
     526,   136,   278,   118,   134,   119,   191,   506,   364,   242,
     242,    96,   104,   443,   188,   189,   150,    12,    61,   190,
      78,    78,   488,   451,   364,    94,    89,    96,    18,   456,
     495,   496,    12,   118,    21,   119,   279,   457,   145,    12,
     156,    22,   178,    18,   148,   149,   178,   392,   237,    21,
      18,   256,   478,   146,    72,   119,    21,    22,   399,   479,
      70,   314,   400,   119,   401,   489,   492,   178,   483,   484,
     315,    78,    22,   498,   490,   434,    24,    12,   242,    22,
      88,    95,    70,   153,   444,    25,   445,    22,    18,   242,
     148,   245,    72,   493,    21,   150,   146,   134,   119,   494,
     143,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   536,
     537,   447,   517,   119,   464,   465,     1,   533,   470,   471,
     448,   500,   521,   501,   502,   364,     7,     8,   504,    10,
     505,   522,    12,   185,   256,    88,    95,    88,   109,   178,
     146,   394,   119,    18,   235,   523,    19,   242,    20,    21,
     146,   398,   119,   531,   146,   480,   119,   534,   535,   538,
     507,   540,   543,   545,   515,   472,    54,   475,    96,   473,
     415,    78,   474,   544,   286,   261,   364,   263,   546,   264,
     476,   266,   136,   267,   136,   269,   414,   270,   178,   272,
     178,    65,     1,   413,   239,    81,    84,    92,    99,   105,
     389,   442,     7,     8,   527,    10,   487,   116,    12,     0,
       0,   432,     0,    54,     0,     0,     0,     0,     0,    18,
       0,     0,    19,     0,    20,    21,    12,     0,     0,   137,
       0,     2,     3,     4,     0,     0,     5,    18,    65,     6,
       0,   364,     9,    21,     0,    11,    12,    13,    14,    15,
     388,    12,    16,    17,     0,     0,    12,    18,     0,     0,
       0,     0,    18,    21,     0,     0,    22,    18,    21,    70,
     246,     0,     0,    21,     0,   107,     0,     0,   406,   143,
       0,   407,     0,     0,   408,     0,    22,   409,     0,    93,
     138,    22,     0,     0,    70,   254,    22,     0,     0,   139,
     325,     0,   119,     0,    72,     0,     0,     0,     0,   326,
       0,   273,     0,     0,     0,     1,     2,     3,     4,   287,
     137,     5,   288,   289,     6,     7,     8,     9,    10,   290,
      11,    12,    13,    14,    15,   291,   292,    16,    17,   293,
     294,   198,    18,   295,   296,    19,   297,    20,    21,     0,
     199,   200,     0,     0,     0,     0,     0,     0,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,     0,     0,
       0,   298,   202,   203,   299,   204,     0,     0,     0,     0,
     184,   300,     0,   206,   258,   208,   209,   210,   211,     1,
       2,     3,     4,   287,   362,     5,   288,   289,     6,     7,
       8,     9,    10,   290,    11,    12,    13,    14,    15,   291,
     292,    16,    17,   293,   294,   198,    18,   295,   296,    19,
     297,    20,    21,     0,   199,   200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,   298,   202,   203,   299,   204,
       7,     8,     0,    10,   184,   431,    12,   206,   258,   208,
     209,   210,   211,     2,     3,     4,     0,    18,     5,     0,
      19,     6,    20,    21,     9,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,   198,    18,
       0,     2,     3,     4,     0,    21,     5,   199,   200,     6,
       0,     0,     9,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,   201,   202,
     203,    23,   204,    21,     0,     0,    12,     0,     0,     0,
     206,   258,   208,   209,   210,   211,   287,    18,     0,   288,
     289,     0,     0,    21,     0,     0,   290,     0,     0,    23,
       0,     0,   291,   292,     0,     0,   293,   294,   198,     0,
     295,   296,     0,   297,     0,     0,    22,   199,   200,    70,
     393,     0,     0,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,   298,   202,
     203,    57,   204,     0,     0,     0,     0,   184,   433,     0,
     206,   258,   208,   209,   210,   211,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     2,     3,    16,    17,
       0,     5,     0,    18,     0,     0,    19,     9,    20,    21,
       0,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,     0,    23,   314,   187,   119,     0,
       1,     2,     3,     4,     0,   315,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,   287,    16,    17,   288,   289,     0,    18,     0,     0,
      19,   290,    20,    21,     0,     0,     0,   291,   292,     0,
       0,   293,   294,   198,     0,   295,   296,     0,   297,     0,
       0,     0,   199,   200,     0,     0,    22,     0,     0,    23,
     325,   187,   119,     0,     0,     0,     0,     0,     0,   326,
       0,     0,     0,   298,   202,   203,    57,   204,     0,     0,
       0,     0,   184,   499,     0,   206,   258,   208,   209,   210,
     211,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,   -14,   346,   347,    18,     0,
       0,    19,     0,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,   349,     0,   -12,     0,    22,     0,     0,
      85,   325,     0,   119,     0,     1,     2,     3,     4,     0,
     326,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,   287,    16,    17,   288,
     289,     0,    18,     0,     0,    19,   290,    20,    21,     0,
       0,     0,   291,   292,     0,     0,   293,   294,   198,     0,
     295,   296,     0,   297,     0,     0,     0,   199,   200,     0,
       0,    22,     0,     0,    93,   325,     0,   119,     0,     0,
       0,     0,     0,     0,   326,     0,     0,     0,   298,   202,
     203,    57,   204,     0,     0,     0,     0,   184,     0,     0,
     206,   258,   208,   209,   210,   211,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,     0,    18,     0,     0,    19,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,   447,   187,   119,     0,
       1,     2,     3,     4,     0,   448,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,    20,    21,     0,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,    22,    16,    17,    23,
      24,     0,    18,     0,     0,    19,     0,    20,    21,    25,
       1,     2,     3,     4,     0,     0,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,    22,    16,    17,    85,    24,     0,    18,     0,     0,
      19,     0,    20,    21,    25,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,    22,    16,    17,    93,
      24,     0,    18,     0,     0,    19,     0,    20,    21,    25,
       1,     2,     3,     4,     0,     0,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,    22,    16,    17,    85,   138,     0,    18,     0,     0,
      19,     0,    20,    21,   139,     0,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     9,     0,     0,
      11,    12,    13,    14,    15,     0,    22,    16,    17,    93,
     138,     0,    18,     0,     0,     0,     0,     0,    21,   139,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     0,
       0,     9,     0,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,    93,   447,    18,   119,     2,     3,
       4,     0,    21,     5,   448,     0,     6,     0,     0,     9,
       0,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,     0,    23,     0,
      21,     0,     0,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     7,     8,     9,    10,    23,    11,    12,    13,
      14,    15,     0,   416,    16,    17,     0,     0,     0,    18,
       0,     0,    19,     0,    20,    21,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,   186,    16,
      17,    23,     0,   187,    18,     0,     0,    19,     0,    20,
      21,     0,     1,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,    23,     0,   187,    18,
       0,     0,    19,     0,    20,    21,     0,    12,     0,     0,
       1,     2,     3,     4,     0,     0,     5,   441,    18,     6,
       7,     8,     9,    10,    21,    11,    12,    13,    14,    15,
       0,    23,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,    20,    21,   198,     0,     0,    22,     0,     0,
       0,   138,     0,   199,   200,     0,     0,     0,     0,     0,
     139,     0,   198,     0,     0,     0,     0,     0,     0,    23,
       0,   199,   200,     0,   201,   202,   203,     0,   204,     0,
       0,   205,     0,     0,     0,     0,   206,   207,   208,   209,
     210,   211,   201,   202,   203,     0,   204,     0,     0,     0,
       0,   257,   198,     0,   206,   258,   208,   209,   210,   211,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
     198,     0,     0,     0,     0,     0,     0,     0,     0,   199,
     200,     0,   201,   202,   203,     0,   204,   452,     0,     0,
       0,     0,     0,     0,   206,   258,   208,   209,   210,   211,
     201,   202,   203,     0,   204,     0,     0,     0,     0,   507,
     198,     0,   206,   258,   208,   209,   210,   211,     0,   199,
     200,     0,     0,     0,     0,     0,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   200,     0,
     201,   202,   203,     0,   335,     0,     0,     0,     0,     0,
       0,     0,   206,   258,   208,   209,   210,   211,   201,   202,
     203,     0,   337,     0,     0,     0,     0,   198,     0,     0,
     206,   258,   208,   209,   210,   211,   199,   200,     0,     0,
       0,     0,     0,     0,     0,   198,     0,     0,     0,     0,
       0,     0,     0,     0,   199,   200,     0,   201,   202,   203,
       0,   204,     0,     0,     0,     0,     0,     0,     0,   206,
     258,   208,   209,   210,   211,   201,   202,   203,     0,   204,
       0,     0,     0,     0,     0,     0,     0,   206,   386,   208,
     209,   210,   211,     1,     2,     3,     0,     0,     0,     5,
       0,     0,     0,     7,     8,     9,    10,     0,     0,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,    20,    21
};

static const short yycheck[] =
{
      31,    32,    53,    34,    35,    36,    37,    38,    39,     0,
      61,   118,   403,   119,   484,   238,     0,     0,     0,    70,
     216,    68,     0,    68,    34,     6,    36,   179,    38,   273,
     113,    19,    63,    72,    25,    65,    30,    67,    85,   146,
      47,   290,    30,   314,    64,   289,    59,   113,    36,    62,
     273,   157,   118,    68,   325,    85,    47,   188,   189,   190,
     191,    24,   314,    44,    47,    47,   289,   537,    64,    47,
      85,    31,    32,   325,    68,    81,    83,    58,    84,    68,
     146,    72,   133,    70,   135,    59,    92,    85,    62,    63,
     141,    70,    68,    99,   125,   126,   179,    70,    72,    86,
     183,   152,    70,    70,   143,    42,    43,    86,    71,    59,
      84,    84,    62,   179,    68,   154,    73,   183,    86,    86,
       0,   204,   113,   154,   230,    82,    64,   118,   519,    68,
     124,   113,    70,    64,   286,   118,   118,    65,   204,    70,
     118,    98,    79,    80,   175,   176,   177,   178,   139,   188,
     189,   132,   143,    66,    64,   146,   400,    70,    85,   190,
     191,   192,   193,   146,   146,   125,   126,    47,   146,    64,
     366,   367,   368,   422,    64,   138,   447,   400,   184,   142,
     174,    59,   192,   140,    70,    63,   149,   144,   179,    66,
     153,   242,   183,    60,    72,   447,    71,   179,   249,   250,
     251,   183,   253,   286,     0,    81,    84,   314,   247,    82,
     341,   342,   243,   204,     0,   175,   247,    63,   325,    65,
     286,    46,   204,    71,    59,   332,    72,    62,    63,    66,
     190,   191,    64,    29,    30,    31,    32,    72,    24,    25,
      69,    70,   348,    29,    30,    31,    32,   127,   314,    59,
      84,    47,   335,    63,   337,   451,   237,   363,   204,   325,
      86,    47,    72,   314,   149,    63,   332,    63,   153,   335,
      66,   337,    68,   522,   325,   232,   315,    63,    59,    86,
     160,    62,   245,   246,   164,    71,    72,    68,   168,   538,
     284,   254,   172,   516,   142,   286,    65,   403,    67,    59,
      69,   149,    62,    63,   286,   153,    59,   438,    64,   440,
      63,   342,    72,   294,    70,    73,    74,    31,    32,    72,
      34,    35,   428,   314,   315,    40,    41,   123,   124,   125,
     126,   314,   314,    72,   325,   326,   314,    63,    77,    78,
     447,   332,   325,   325,   335,   175,   337,   325,   399,   332,
     332,   314,   138,   335,   332,   337,   142,    84,   154,    64,
     245,   246,   325,   149,    64,    70,    64,   153,   154,   254,
      70,    59,    70,    63,    62,   506,    29,    30,   174,   175,
      68,   447,   342,   198,   199,   200,    44,    45,   295,   335,
      63,   337,   188,   189,   190,   191,   447,   245,   246,   438,
      84,   216,   309,   349,   510,    84,   254,   438,    64,   440,
      70,   125,   126,   519,    70,    68,   369,   370,    59,    72,
     401,    62,    63,   238,    65,    65,   113,    67,   308,    69,
     393,    72,   373,   374,   375,   376,    31,    32,   384,    34,
      35,    36,    37,    38,    39,    84,   276,   243,    86,   279,
     501,   247,   282,    63,    64,    65,   447,   448,   273,   245,
     246,   175,   176,    59,   447,   447,   314,    19,   254,   447,
     123,   124,   418,    64,   289,   506,   190,   191,    30,    67,
     426,   427,    19,    63,    36,    65,   282,    37,   284,    19,
     143,    59,   179,    30,    62,    63,   183,    69,    70,    36,
      30,   154,    66,    63,    72,    65,    36,    59,   393,    66,
      62,    63,    65,    65,    67,    84,   423,   204,    69,    70,
      72,   174,    59,   430,    86,   432,    63,    19,   314,    59,
     125,   126,    62,    63,   335,    72,   337,    59,    30,   325,
      62,    63,    72,    86,    36,   393,    63,    64,    65,    34,
      72,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,    69,
      70,    63,    66,    65,   371,   372,     3,   523,   377,   378,
      72,    64,   489,    64,    64,   400,    13,    14,    64,    16,
      64,    86,    19,   117,   247,   190,   191,   192,   193,   286,
      63,    64,    65,    30,   128,    63,    33,   393,    35,    36,
      63,    64,    65,   520,    63,    64,    65,   524,   525,    86,
      68,     8,    86,    64,   457,   379,     0,   382,   342,   380,
     284,   284,   381,   540,   183,   159,   451,   161,   545,   163,
     383,   165,   438,   167,   440,   169,   282,   171,   335,   173,
     337,    25,     3,   279,   132,    29,    30,    31,    32,    86,
     237,   332,    13,    14,   507,    16,   404,    47,    19,    -1,
      -1,   308,    -1,    47,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    19,    -1,    -1,    63,
      -1,     4,     5,     6,    -1,    -1,     9,    30,    72,    12,
      -1,   516,    15,    36,    -1,    18,    19,    20,    21,    22,
     234,    19,    25,    26,    -1,    -1,    19,    30,    -1,    -1,
      -1,    -1,    30,    36,    -1,    -1,    59,    30,    36,    62,
      63,    -1,    -1,    36,    -1,    86,    -1,    -1,   262,    72,
      -1,   265,    -1,    -1,   268,    -1,    59,   271,    -1,    62,
      63,    59,    -1,    -1,    62,    63,    59,    -1,    -1,    72,
      63,    -1,    65,    -1,    72,    -1,    -1,    -1,    -1,    72,
      -1,    84,    -1,    -1,    -1,     3,     4,     5,     6,     7,
     154,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,     3,
       4,     5,     6,     7,    85,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      13,    14,    -1,    16,    68,    69,    19,    71,    72,    73,
      74,    75,    76,     4,     5,     6,    -1,    30,     9,    -1,
      33,    12,    35,    36,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    30,
      -1,     4,     5,     6,    -1,    36,     9,    38,    39,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    59,    60,
      61,    62,    63,    36,    -1,    -1,    19,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,     7,    30,    -1,    10,
      11,    -1,    -1,    36,    -1,    -1,    17,    -1,    -1,    62,
      -1,    -1,    23,    24,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    -1,    59,    38,    39,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,     4,     5,    25,    26,
      -1,     9,    -1,    30,    -1,    -1,    33,    15,    35,    36,
      -1,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    59,    -1,    -1,    62,    63,    64,    65,    -1,
       3,     4,     5,     6,    -1,    72,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,     7,    25,    26,    10,    11,    -1,    30,    -1,    -1,
      33,    17,    35,    36,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,    -1,    -1,    59,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    37,    38,    39,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    59,    -1,    -1,
      62,    63,    -1,    65,    -1,     3,     4,     5,     6,    -1,
      72,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,     7,    25,    26,    10,
      11,    -1,    30,    -1,    -1,    33,    17,    35,    36,    -1,
      -1,    -1,    23,    24,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    -1,    -1,    38,    39,    -1,
      -1,    59,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    75,    76,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
       3,     4,     5,     6,    -1,    72,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    59,    25,    26,    62,
      63,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    72,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    59,    25,    26,    62,    63,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    72,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    59,    25,    26,    62,
      63,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    72,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    59,    25,    26,    62,    63,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    72,    -1,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    59,    25,    26,    62,
      63,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    72,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    62,    63,    30,    65,     4,     5,
       6,    -1,    36,     9,    72,    -1,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    62,    -1,
      36,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    62,    18,    19,    20,
      21,    22,    -1,    69,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    59,    25,
      26,    62,    -1,    64,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    62,    -1,    64,    30,
      -1,    -1,    33,    -1,    35,    36,    -1,    19,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    48,    30,    12,
      13,    14,    15,    16,    36,    18,    19,    20,    21,    22,
      -1,    62,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    29,    -1,    -1,    59,    -1,    -1,
      -1,    63,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    38,    39,    -1,    59,    60,    61,    -1,    63,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    59,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    68,    29,    -1,    71,    72,    73,    74,    75,    76,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    59,    60,    61,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      59,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,    68,
      29,    -1,    71,    72,    73,    74,    75,    76,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      59,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    59,    60,
      61,    -1,    63,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      71,    72,    73,    74,    75,    76,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    59,    60,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    59,    60,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,     3,     4,     5,    -1,    -1,    -1,     9,
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
      35,    36,    59,    62,    63,    72,   114,   115,   116,   117,
     118,   119,   120,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   142,   166,   167,   168,   169,
     193,   194,   195,   196,   197,   198,    59,    62,    68,   149,
     194,   196,   197,   120,   193,   197,    70,    86,    70,    86,
      62,    63,    72,   185,   186,   187,   188,   189,   190,   191,
     193,   197,   185,   193,   197,    62,   121,   122,   129,   130,
     131,   193,   197,    62,   122,   129,   130,   131,   193,   197,
     121,   130,   122,   129,   130,    86,   121,    86,   122,   129,
     121,   122,   129,    68,   149,     0,   168,   170,    63,    65,
     200,   201,   114,   117,   118,   119,   120,   160,   175,   143,
     144,   149,    68,    64,    64,    64,   193,   197,    63,    72,
     193,   196,    63,    72,   185,   193,    63,   200,    62,    63,
     188,   190,   192,    63,   120,   187,   190,    85,   151,   171,
     160,   176,   151,   172,   160,   177,   151,   173,   160,   178,
     151,   174,   160,   179,   118,   120,   124,   126,   128,   134,
     135,   136,   137,    68,    68,   159,    59,    64,   117,   118,
     119,   120,   125,   126,   145,   146,   147,   148,    29,    38,
      39,    59,    60,    61,    63,    66,    71,    72,    73,    74,
      75,    76,    88,    89,    90,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      65,   193,   193,   114,   180,   159,    69,    70,    85,   143,
     200,   200,   196,   120,   151,    63,    63,   120,   151,   192,
      64,    64,   200,   192,    63,   187,   190,    68,    72,   109,
     152,   159,   181,   159,   159,   182,   159,   159,   183,   159,
     159,   184,   159,    84,   138,   141,   185,   139,   141,   193,
      69,   135,    70,    86,    70,    86,   134,     7,    10,    11,
      17,    23,    24,    27,    28,    31,    32,    34,    59,    62,
      69,   109,   111,   113,   149,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    63,    72,   187,   193,   199,   200,
     202,   203,   187,   193,   199,    63,    72,   193,   199,   193,
     199,    64,    70,    64,    70,    63,    95,    63,    95,    95,
     111,   118,   120,   150,    66,    60,    38,    39,    63,    65,
      91,    92,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    85,   110,    95,    97,    72,    77,    78,    73,
      74,    40,    41,    42,    43,    79,    80,    44,    45,    71,
      81,    82,    46,    47,    83,    66,    72,   109,   159,   144,
     108,   112,    69,    63,    64,   200,   200,    64,    64,   192,
      65,    67,   153,   154,   155,   156,   159,   159,   159,   159,
     112,   140,   141,   140,   139,   138,    69,    86,    63,   112,
     113,    86,    63,    84,   149,   157,    63,    63,    70,    86,
      84,    69,   161,    69,   157,   200,   202,   203,   120,   199,
     120,    48,   147,    59,   150,   150,    64,    63,    72,   199,
     199,    64,    64,    94,   109,   111,    67,    37,   109,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   100,   100,
     101,   101,   102,   103,   104,   105,   106,   111,    66,    66,
      64,   112,   149,    69,    70,   152,    85,   156,   111,    84,
      86,   113,   157,    86,    34,   111,   111,   109,   157,    69,
      64,    64,    64,   199,    64,    64,   120,    68,    97,    64,
      70,    66,    59,    62,    93,    93,    84,    66,    69,   154,
      64,   157,    86,    63,    64,    64,   200,   153,   109,   108,
     152,   157,   113,   111,   157,   157,    69,    70,    86,    64,
       8,    69,   113,    86,   157,    64,   157
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
#define YYEMPTY		-2
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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)           \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX	yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX	yylex (&yylval)
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
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
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
/*-----------------------------.
| Print this symbol on YYOUT.  |
`-----------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue)
#else
yysymprint (yyout, yytype, yyvalue)
    FILE* yyout;
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyout, yytoknum[yytype], yyvalue);
# endif
    }
  else
    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyout, ")");
}
#endif /* YYDEBUG. */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yydestruct (int yytype, YYSTYPE yyvalue)
#else
yydestruct (yytype, yyvalue)
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  switch (yytype)
    {
      default:
        break;
    }
}



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif




int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of parse errors so far.  */
int yynerrs;

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

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

  if (yyssp >= yyss + yystacksize - 1)
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
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
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

      if (yyssp >= yyss + yystacksize - 1)
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

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with.  */

  if (yychar <= 0)		/* This means end of input.  */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more.  */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

      /* We have to keep this `#if YYDEBUG', since we use variables
	 which are defined only if `YYDEBUG' is set.  */
      YYDPRINTF ((stderr, "Next token is "));
      YYDSYMPRINT ((stderr, yychar1, yylval));
      YYDPRINTF ((stderr, "\n"));
    }

  /* If the proper action on seeing token YYCHAR1 is to reduce or to
     detect an error, take that action.  */
  yyn += yychar1;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
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
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

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



#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn - 1, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif
  switch (yyn)
    {
        case 2:
#line 534 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 3:
#line 536 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-1].value, +, yyvsp[0].value ); }
    break;

  case 4:
#line 543 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier )
	      HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    UNDEF_VAL( yyval.value );
	  }
    break;

  case 5:
#line 548 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 6:
#line 549 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.iv++; }
    break;

  case 7:
#line 550 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; }
    break;

  case 8:
#line 554 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 9:
#line 555 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 10:
#line 556 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 11:
#line 557 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 12:
#line 558 "ctlib/parser.y"
    {}
    break;

  case 13:
#line 558 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 14:
#line 559 "ctlib/parser.y"
    {}
    break;

  case 15:
#line 559 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 16:
#line 560 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 17:
#line 561 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 18:
#line 562 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 19:
#line 563 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 20:
#line 567 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); }
    break;

  case 21:
#line 568 "ctlib/parser.y"
    {}
    break;

  case 22:
#line 572 "ctlib/parser.y"
    {}
    break;

  case 23:
#line 573 "ctlib/parser.y"
    {}
    break;

  case 24:
#line 577 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 25:
#line 578 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 26:
#line 579 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 27:
#line 581 "ctlib/parser.y"
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
	  }
    break;

  case 28:
#line 598 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 29:
#line 599 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; }
    break;

  case 30:
#line 603 "ctlib/parser.y"
    { yyval.oper = '&'; }
    break;

  case 31:
#line 604 "ctlib/parser.y"
    { yyval.oper = '*'; }
    break;

  case 32:
#line 605 "ctlib/parser.y"
    { yyval.oper = '+'; }
    break;

  case 33:
#line 606 "ctlib/parser.y"
    { yyval.oper = '-'; }
    break;

  case 34:
#line 607 "ctlib/parser.y"
    { yyval.oper = '~'; }
    break;

  case 35:
#line 608 "ctlib/parser.y"
    { yyval.oper = '!'; }
    break;

  case 36:
#line 612 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 37:
#line 613 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_CAST; }
    break;

  case 38:
#line 617 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 39:
#line 619 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, *, yyvsp[0].value ); }
    break;

  case 40:
#line 621 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, /, yyvsp[0].value );
	  }
    break;

  case 41:
#line 628 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, %, yyvsp[0].value );
	  }
    break;

  case 42:
#line 637 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 43:
#line 639 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, +, yyvsp[0].value ); }
    break;

  case 44:
#line 641 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, -, yyvsp[0].value ); }
    break;

  case 45:
#line 645 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 46:
#line 647 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <<, yyvsp[0].value ); }
    break;

  case 47:
#line 649 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >>, yyvsp[0].value ); }
    break;

  case 48:
#line 653 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 49:
#line 655 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <,  yyvsp[0].value ); }
    break;

  case 50:
#line 657 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >,  yyvsp[0].value ); }
    break;

  case 51:
#line 659 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <=, yyvsp[0].value ); }
    break;

  case 52:
#line 661 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >=, yyvsp[0].value ); }
    break;

  case 53:
#line 665 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 54:
#line 667 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ==, yyvsp[0].value ); }
    break;

  case 55:
#line 669 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, !=, yyvsp[0].value ); }
    break;

  case 56:
#line 673 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 57:
#line 675 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &, yyvsp[0].value ); }
    break;

  case 58:
#line 679 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 59:
#line 681 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ^, yyvsp[0].value ); }
    break;

  case 60:
#line 685 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 61:
#line 687 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, |, yyvsp[0].value ); }
    break;

  case 62:
#line 691 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 63:
#line 693 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &&, yyvsp[0].value ); }
    break;

  case 64:
#line 697 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 65:
#line 699 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ||, yyvsp[0].value ); }
    break;

  case 66:
#line 703 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 67:
#line 705 "ctlib/parser.y"
    { yyval.value = yyvsp[-4].value.iv ? yyvsp[-2].value : yyvsp[0].value; yyval.value.flags |= yyvsp[-4].value.flags; }
    break;

  case 68:
#line 709 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 69:
#line 710 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 70:
#line 714 "ctlib/parser.y"
    {}
    break;

  case 71:
#line 715 "ctlib/parser.y"
    {}
    break;

  case 72:
#line 716 "ctlib/parser.y"
    {}
    break;

  case 73:
#line 717 "ctlib/parser.y"
    {}
    break;

  case 74:
#line 718 "ctlib/parser.y"
    {}
    break;

  case 75:
#line 719 "ctlib/parser.y"
    {}
    break;

  case 76:
#line 720 "ctlib/parser.y"
    {}
    break;

  case 77:
#line 721 "ctlib/parser.y"
    {}
    break;

  case 78:
#line 722 "ctlib/parser.y"
    {}
    break;

  case 79:
#line 723 "ctlib/parser.y"
    {}
    break;

  case 80:
#line 724 "ctlib/parser.y"
    {}
    break;

  case 81:
#line 728 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 82:
#line 729 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 83:
#line 733 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 85:
#line 739 "ctlib/parser.y"
    {}
    break;

  case 86:
#line 777 "ctlib/parser.y"
    {}
    break;

  case 87:
#line 778 "ctlib/parser.y"
    {}
    break;

  case 88:
#line 779 "ctlib/parser.y"
    {}
    break;

  case 89:
#line 780 "ctlib/parser.y"
    {}
    break;

  case 90:
#line 788 "ctlib/parser.y"
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
	  }
    break;

  case 91:
#line 810 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  }
    break;

  case 92:
#line 816 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-3].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	    else if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  }
    break;

  case 93:
#line 827 "ctlib/parser.y"
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
	  }
    break;

  case 94:
#line 850 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  }
    break;

  case 95:
#line 856 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-3].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	    else if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  }
    break;

  case 96:
#line 868 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  }
    break;

  case 97:
#line 872 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 98:
#line 873 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 99:
#line 879 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  }
    break;

  case 100:
#line 883 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 101:
#line 884 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 102:
#line 890 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      }
    break;

  case 103:
#line 891 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      }
    break;

  case 104:
#line 892 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; }
    break;

  case 107:
#line 901 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval; }
    break;

  case 108:
#line 902 "ctlib/parser.y"
    { yyval.uval = 0;  }
    break;

  case 112:
#line 912 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 113:
#line 913 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 114:
#line 914 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 115:
#line 915 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 116:
#line 919 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               }
    break;

  case 117:
#line 920 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               }
    break;

  case 118:
#line 921 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval;               }
    break;

  case 119:
#line 922 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 120:
#line 927 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  }
    break;

  case 121:
#line 932 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  }
    break;

  case 122:
#line 937 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  }
    break;

  case 123:
#line 944 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 124:
#line 945 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 125:
#line 946 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; }
    break;

  case 126:
#line 952 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  }
    break;

  case 127:
#line 957 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  }
    break;

  case 128:
#line 962 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  }
    break;

  case 129:
#line 969 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 130:
#line 970 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 131:
#line 971 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; }
    break;

  case 132:
#line 975 "ctlib/parser.y"
    { yyval.uval = T_TYPEDEF;  }
    break;

  case 133:
#line 976 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 134:
#line 977 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 135:
#line 978 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 136:
#line 979 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 137:
#line 980 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 138:
#line 984 "ctlib/parser.y"
    { yyval.uval = T_INT;      }
    break;

  case 139:
#line 985 "ctlib/parser.y"
    { yyval.uval = T_CHAR;     }
    break;

  case 140:
#line 986 "ctlib/parser.y"
    { yyval.uval = T_SHORT;    }
    break;

  case 141:
#line 987 "ctlib/parser.y"
    { yyval.uval = T_LONG;     }
    break;

  case 142:
#line 988 "ctlib/parser.y"
    { yyval.uval = T_FLOAT;    }
    break;

  case 143:
#line 989 "ctlib/parser.y"
    { yyval.uval = T_DOUBLE;   }
    break;

  case 144:
#line 990 "ctlib/parser.y"
    { yyval.uval = T_SIGNED;   }
    break;

  case 145:
#line 991 "ctlib/parser.y"
    { yyval.uval = T_UNSIGNED; }
    break;

  case 146:
#line 992 "ctlib/parser.y"
    { yyval.uval = T_VOID;     }
    break;

  case 147:
#line 996 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 148:
#line 997 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 149:
#line 1002 "ctlib/parser.y"
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
	  }
    break;

  case 150:
#line 1015 "ctlib/parser.y"
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
	  }
    break;

  case 151:
#line 1044 "ctlib/parser.y"
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
	  }
    break;

  case 152:
#line 1068 "ctlib/parser.y"
    { yyval.uval = T_STRUCT; }
    break;

  case 153:
#line 1069 "ctlib/parser.y"
    { yyval.uval = T_UNION;  }
    break;

  case 154:
#line 1074 "ctlib/parser.y"
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
	  }
    break;

  case 155:
#line 1087 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = yyvsp[-1].list;
	      LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	    }
	  }
    break;

  case 156:
#line 1099 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; }
    break;

  case 157:
#line 1100 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; }
    break;

  case 158:
#line 1105 "ctlib/parser.y"
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
	  }
    break;

  case 159:
#line 1120 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pStructDecl = NULL;
	    }
	    else {
	      yyval.pStructDecl = yyvsp[-2].pStructDecl;
	      if( yyvsp[0].pDecl )
	        LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	    }
	  }
    break;

  case 160:
#line 1134 "ctlib/parser.y"
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
	  }
    break;

  case 161:
#line 1150 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pStructDecl = NULL;
	    }
	    else {
	      yyval.pStructDecl = yyvsp[-2].pStructDecl;
	      if( yyvsp[0].pDecl )
	        LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	    }
	  }
    break;

  case 162:
#line 1164 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = yyvsp[-1].pDecl;
	      yyval.pDecl->bitfield_size = yyvsp[0].ival;
	    }
	  }
    break;

  case 163:
#line 1174 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( "", 0 );
	      yyval.pDecl->bitfield_size = yyvsp[0].ival;
	    }
	  }
    break;

  case 164:
#line 1187 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = yyvsp[-1].pDecl;
	      yyval.pDecl->bitfield_size = yyvsp[0].ival;
	    }
	  }
    break;

  case 165:
#line 1197 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pDecl = NULL;
	    }
	    else {
	      yyval.pDecl = decl_new( "", 0 );
	      yyval.pDecl->bitfield_size = yyvsp[0].ival;
	    }
	  }
    break;

  case 166:
#line 1209 "ctlib/parser.y"
    { yyval.ival = -1; }
    break;

  case 167:
#line 1210 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].ival; }
    break;

  case 168:
#line 1214 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].value.iv; }
    break;

  case 169:
#line 1219 "ctlib/parser.y"
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
	  }
    break;

  case 170:
#line 1233 "ctlib/parser.y"
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
	  }
    break;

  case 171:
#line 1263 "ctlib/parser.y"
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
	  }
    break;

  case 172:
#line 1289 "ctlib/parser.y"
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
	  }
    break;

  case 173:
#line 1303 "ctlib/parser.y"
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
	  }
    break;

  case 174:
#line 1319 "ctlib/parser.y"
    {
	    yyval.list = yyvsp[-1].list;
	  }
    break;

  case 175:
#line 1326 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pEnum = NULL;
	    }
	    else {
	      yyval.pEnum = enum_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, NULL );
	      STORE_IN_HASH( htEnumerators, yyvsp[0].idOrType, yyval.pEnum );
	    }
	  }
    break;

  case 176:
#line 1336 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pEnum = NULL;
	    }
	    else {
	      yyval.pEnum = enum_new( yyvsp[-2].idOrType.str, yyvsp[-2].idOrType.len, &yyvsp[0].value );
	      STORE_IN_HASH( htEnumerators, yyvsp[-2].idOrType, yyval.pEnum );
	    }
	  }
    break;

  case 181:
#line 1358 "ctlib/parser.y"
    {}
    break;

  case 182:
#line 1359 "ctlib/parser.y"
    {}
    break;

  case 183:
#line 1360 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 184:
#line 1361 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 185:
#line 1362 "ctlib/parser.y"
    {}
    break;

  case 186:
#line 1363 "ctlib/parser.y"
    {}
    break;

  case 187:
#line 1364 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 188:
#line 1365 "ctlib/parser.y"
    {}
    break;

  case 189:
#line 1366 "ctlib/parser.y"
    {}
    break;

  case 190:
#line 1367 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 191:
#line 1368 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 192:
#line 1369 "ctlib/parser.y"
    {}
    break;

  case 193:
#line 1370 "ctlib/parser.y"
    {}
    break;

  case 194:
#line 1371 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 195:
#line 1379 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); }
    break;

  case 196:
#line 1380 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); }
    break;

  case 197:
#line 1385 "ctlib/parser.y"
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
	  }
    break;

  case 198:
#line 1400 "ctlib/parser.y"
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
	  }
    break;

  case 199:
#line 1416 "ctlib/parser.y"
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
	  }
    break;

  case 200:
#line 1430 "ctlib/parser.y"
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
	  }
    break;

  case 201:
#line 1449 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = PSTATE->pCPC->int_size;
	      yyval.value.flags = 0;
	    }
	  }
    break;

  case 202:
#line 1456 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
                      PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	      yyval.value.flags = 0;
	    }
	  }
    break;

  case 207:
#line 1473 "ctlib/parser.y"
    {}
    break;

  case 215:
#line 1493 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[0].idOrType ); }
    break;

  case 222:
#line 1507 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-2].idOrType ); }
    break;

  case 240:
#line 1546 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-1].idOrType ); }
    break;

  case 250:
#line 1571 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 251:
#line 1572 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); }
    break;

  case 252:
#line 1573 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 253:
#line 1574 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); }
    break;

  case 254:
#line 1575 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 255:
#line 1576 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); }
    break;

  case 256:
#line 1577 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 257:
#line 1578 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); }
    break;

  case 258:
#line 1579 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 259:
#line 1580 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); }
    break;

  case 260:
#line 1582 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 261:
#line 1582 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 262:
#line 1583 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 263:
#line 1583 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 264:
#line 1584 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 265:
#line 1584 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 266:
#line 1585 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 267:
#line 1585 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 268:
#line 1586 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 269:
#line 1586 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 270:
#line 1588 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 271:
#line 1588 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 272:
#line 1589 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 273:
#line 1589 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 274:
#line 1590 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 275:
#line 1590 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 276:
#line 1591 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 277:
#line 1591 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 278:
#line 1592 "ctlib/parser.y"
    { BEGIN_LOCAL; }
    break;

  case 279:
#line 1592 "ctlib/parser.y"
    { END_LOCAL; }
    break;

  case 280:
#line 1596 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 281:
#line 1597 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 282:
#line 1601 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 283:
#line 1602 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 284:
#line 1607 "ctlib/parser.y"
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
	  }
    break;

  case 285:
#line 1619 "ctlib/parser.y"
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
	  }
    break;

  case 286:
#line 1632 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 287:
#line 1639 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 288:
#line 1641 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 289:
#line 1647 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 290:
#line 1655 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 291:
#line 1657 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  }
    break;

  case 292:
#line 1667 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 293:
#line 1669 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  }
    break;

  case 294:
#line 1675 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  }
    break;

  case 295:
#line 1681 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 296:
#line 1687 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 297:
#line 1695 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 298:
#line 1697 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  }
    break;

  case 299:
#line 1702 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  }
    break;

  case 300:
#line 1710 "ctlib/parser.y"
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
	  }
    break;

  case 301:
#line 1721 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 302:
#line 1725 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 303:
#line 1726 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 304:
#line 1730 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 305:
#line 1732 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 306:
#line 1738 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 307:
#line 1747 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  }
    break;

  case 308:
#line 1751 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 309:
#line 1753 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  }
    break;

  case 310:
#line 1761 "ctlib/parser.y"
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
	  }
    break;

  case 311:
#line 1773 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 312:
#line 1777 "ctlib/parser.y"
    {}
    break;

  case 313:
#line 1778 "ctlib/parser.y"
    {}
    break;

  case 314:
#line 1779 "ctlib/parser.y"
    {}
    break;

  case 315:
#line 1784 "ctlib/parser.y"
    {
	    if( yyvsp[-3].pDecl )
	      decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  }
    break;

  case 316:
#line 1788 "ctlib/parser.y"
    {}
    break;

  case 317:
#line 1790 "ctlib/parser.y"
    {
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  }
    break;

  case 318:
#line 1797 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; }
    break;

  case 319:
#line 1798 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; }
    break;

  case 320:
#line 1800 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag  = 0;
	    yyval.absDecl.multiplicator = 1;
	    if( yyvsp[0].list ) {
	      Value *pValue;
	      LL_foreach( pValue, yyvsp[0].list )
	        yyval.absDecl.multiplicator *= pValue->iv;
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	    }
	  }
    break;

  case 321:
#line 1813 "ctlib/parser.y"
    { yyval.list = yyvsp[0].list;   }
    break;

  case 322:
#line 1814 "ctlib/parser.y"
    { yyval.list = NULL; }
    break;

  case 323:
#line 1815 "ctlib/parser.y"
    { yyval.list = NULL; }
    break;

  case 324:
#line 1819 "ctlib/parser.y"
    { yyval.list = NULL; }
    break;

  case 325:
#line 1821 "ctlib/parser.y"
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
	  }
    break;

  case 326:
#line 1835 "ctlib/parser.y"
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
	  }
    break;

  case 327:
#line 1849 "ctlib/parser.y"
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
	  }
    break;

  case 328:
#line 1868 "ctlib/parser.y"
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
	  }
    break;

  case 329:
#line 1890 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  }
    break;

  case 330:
#line 1895 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  }
    break;

  case 331:
#line 1900 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  }
    break;

  case 332:
#line 1905 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  }
    break;

  case 333:
#line 1912 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; }
    break;

  case 334:
#line 1913 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; }
    break;

  case 335:
#line 1915 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag  = 0;
	    yyval.absDecl.multiplicator = 1;
	    if( yyvsp[-1].list ) {
	      Value *pValue;
	      LL_foreach( pValue, yyvsp[-1].list )
	        yyval.absDecl.multiplicator *= pValue->iv;
	      LL_destroy( EX_ARRAY( yyvsp[-1].list ), (LLDestroyFunc) value_delete );
	    }
	  }
    break;

  case 336:
#line 1926 "ctlib/parser.y"
    {
	    yyval.absDecl = yyvsp[-2].absDecl;
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  }
    break;


    }

/* Line 1016 of /home/mhx/bin/bison-1.75/share/bison/yacc.c.  */
#line 4330 "ctlib/parser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

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
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
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
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
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
	  while (yyssp > yyss)
	    {
	      YYDPRINTF ((stderr, "Error: popping "));
	      YYDSYMPRINT ((stderr,
			    yystos[*yyssp],
			    *yyvsp));
	      YYDPRINTF ((stderr, "\n"));
	      yydestruct (yystos[*yyssp], *yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yydestruct (yychar1, yylval);
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

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

      YYDPRINTF ((stderr, "Error: popping "));
      YYDSYMPRINT ((stderr,
		    yystos[*yyssp], *yyvsp));
      YYDPRINTF ((stderr, "\n"));

      yydestruct (yystos[yystate], *yyvsp);
      yyvsp--;
      yystate = *--yyssp;


#if YYDEBUG
      if (yydebug)
	{
	  short *yyssp1 = yyss - 1;
	  YYFPRINTF (stderr, "Error: state stack now");
	  while (yyssp1 != yyssp)
	    YYFPRINTF (stderr, " %d", *++yyssp1);
	  YYFPRINTF (stderr, "\n");
	}
#endif
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


#line 1933 "ctlib/parser.y"



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
    if( rval )
      continue;

    token = pLexer->ctok->type;

    switch( token ) {
      case NONE:
      case COMMENT:
      case NEWLINE:
      case BUNCH:
        break;

      case CONTEXT:
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
        plval->value.iv = strtol( pLexer->ctok->name, NULL, 0 );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("constant: %s -> %d", pLexer->ctok->name, plval->value.iv) );
        return CONSTANT;

      case STRING:
        plval->value.iv = string_size( pLexer->ctok->name );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("string literal: %s -> %d", pLexer->ctok->name, plval->value.iv) );
        return STRING_LITERAL;

      case CHAR:
        plval->value.iv = get_char_value( pLexer->ctok->name );
        plval->value.flags = 0;
        CT_DEBUG( CLEXER, ("constant: %s -> %d", pLexer->ctok->name, plval->value.iv) );
        return CONSTANT;

      case PRAGMA:
        CT_DEBUG( CLEXER, ("line %ld: <#pragma>", pLexer->line) );

        pState->pragma.str = pLexer->ctok->name;
        pragma_parse( &pState->pragma );

        CT_DEBUG( CLEXER, ("current packing: %d\n", pState->pragma.pack.current) );

        break;

      case NAME:
        {
          char *tokstr = pLexer->ctok->name;

#include "t_parser.c"

          unknown:
            return check_type( pYYLVAL, pState, tokstr );
        }

      default:
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
*   ROUTINE: c_parser_create
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

int c_parser_run( ParserState *pState )
{
  return c_parse( (void *) pState );
}

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


