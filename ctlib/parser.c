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
* $Date: 2003/01/14 21:13:03 +0100 $
* $Revision: 19 $
* $Snapshot: /Convert-Binary-C/0.09 $
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
#line 569 "ctlib/parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
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
#define YYFINAL  117
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2132

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  122
/* YYNRULES -- Number of rules. */
#define YYNRULES  345
/* YYNRULES -- Number of states. */
#define YYNSTATES  558

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
     450,   452,   455,   458,   461,   464,   466,   469,   473,   476,
     480,   483,   485,   488,   490,   491,   493,   496,   501,   507,
     510,   512,   514,   518,   521,   523,   527,   529,   533,   535,
     539,   541,   544,   547,   550,   552,   555,   558,   560,   563,
     566,   569,   571,   574,   577,   579,   583,   585,   587,   589,
     592,   594,   597,   598,   601,   605,   610,   612,   615,   620,
     621,   624,   626,   629,   633,   636,   638,   640,   642,   644,
     646,   648,   652,   657,   661,   664,   668,   672,   677,   679,
     682,   684,   687,   690,   696,   704,   710,   716,   724,   734,
     738,   741,   744,   748,   749,   751,   753,   756,   758,   760,
     761,   765,   766,   771,   772,   777,   778,   783,   784,   789,
     790,   794,   795,   800,   801,   806,   807,   812,   813,   818,
     819,   824,   825,   831,   832,   838,   839,   845,   846,   852,
     854,   856,   858,   860,   862,   865,   867,   869,   872,   876,
     880,   885,   887,   892,   898,   901,   905,   909,   914,   919,
     921,   925,   927,   929,   931,   934,   938,   941,   945,   950,
     952,   956,   958,   961,   965,   970,   974,   979,   981,   983,
     985,   987,   990,   994,   997,  1001,  1005,  1010,  1015,  1017,
    1020,  1023,  1027,  1031,  1035,  1039
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     172,     0,    -1,    61,    -1,    89,    61,    -1,    60,    -1,
      62,    -1,    89,    -1,    64,   112,    65,    -1,    90,    -1,
      91,    66,   112,    67,    -1,    91,    64,    65,    -1,    91,
      64,    95,    65,    -1,    -1,    91,    92,    68,    94,    -1,
      -1,    91,    93,    38,    94,    -1,    91,    39,    -1,    91,
      40,    -1,    64,   156,    65,    69,   159,    70,    -1,    64,
     156,    65,    69,   159,    71,    70,    -1,    60,    -1,    63,
      -1,   110,    -1,    95,    71,   110,    -1,    91,    -1,    39,
      96,    -1,    40,    96,    -1,    97,    98,    -1,    29,    96,
      -1,    29,    64,   156,    65,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    96,    -1,
      64,   156,    65,    98,    -1,    98,    -1,    99,    73,    98,
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
     117,    87,    -1,   116,    87,    -1,   120,   199,   157,    -1,
     121,   199,   157,    -1,   116,    71,   199,   157,    -1,   118,
     191,   157,    -1,   119,   191,   157,    -1,   117,    71,   191,
     157,    -1,   124,    -1,   126,    -1,   130,    -1,   125,    -1,
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
      25,    -1,    22,    -1,    26,    -1,   135,    -1,   147,    -1,
     136,    69,   138,    70,    -1,   136,   155,    69,   138,    70,
      -1,   136,   155,    -1,   137,    -1,     6,    -1,    18,    -1,
     139,    -1,   138,   139,    -1,   142,    87,    -1,   141,    87,
      -1,   140,    87,    -1,   129,    -1,   121,   144,    -1,   141,
      71,   144,    -1,   119,   143,    -1,   142,    71,   143,    -1,
     191,   145,    -1,   146,    -1,   199,   145,    -1,   146,    -1,
      -1,   146,    -1,    85,   113,    -1,   148,    69,   149,    70,
      -1,   148,   155,    69,   149,    70,    -1,   148,   155,    -1,
      12,    -1,   150,    -1,   149,    71,   150,    -1,   149,    71,
      -1,   155,    -1,   155,    86,   113,    -1,   152,    -1,   152,
      71,    49,    -1,   153,    -1,   152,    71,   153,    -1,   118,
      -1,   118,   205,    -1,   118,   199,    -1,   118,   193,    -1,
     120,    -1,   120,   205,    -1,   120,   199,    -1,   119,    -1,
     119,   205,    -1,   119,   199,    -1,   119,   193,    -1,   121,
      -1,   121,   205,    -1,   121,   199,    -1,    60,    -1,   154,
      71,    60,    -1,    60,    -1,    63,    -1,   119,    -1,   119,
     205,    -1,   121,    -1,   121,   205,    -1,    -1,    86,   158,
      -1,    69,   159,    70,    -1,    69,   159,    71,    70,    -1,
     110,    -1,   160,   158,    -1,   159,    71,   160,   158,    -1,
      -1,   161,    86,    -1,   162,    -1,   161,   162,    -1,    66,
     113,    67,    -1,    68,   155,    -1,   164,    -1,   165,    -1,
     168,    -1,   169,    -1,   170,    -1,   171,    -1,   155,    85,
     163,    -1,    11,   113,    85,   163,    -1,    27,    85,   163,
      -1,    69,    70,    -1,    69,   166,    70,    -1,    69,   167,
      70,    -1,    69,   166,   167,    70,    -1,   115,    -1,   166,
     115,    -1,   163,    -1,   167,   163,    -1,   114,    87,    -1,
      32,    64,   112,    65,   163,    -1,    32,    64,   112,    65,
     163,     8,   163,    -1,    10,    64,   112,    65,   163,    -1,
      34,    64,   112,    65,   163,    -1,    31,   163,    34,    64,
     112,    65,    87,    -1,    24,    64,   114,    87,   114,    87,
     114,    65,   163,    -1,    28,   155,    87,    -1,    23,    87,
      -1,     7,    87,    -1,    17,   114,    87,    -1,    -1,   173,
      -1,   174,    -1,   173,   174,    -1,   175,    -1,   115,    -1,
      -1,   199,   176,   165,    -1,    -1,   118,   199,   177,   165,
      -1,    -1,   119,   199,   178,   165,    -1,    -1,   120,   199,
     179,   165,    -1,    -1,   121,   199,   180,   165,    -1,    -1,
     203,   181,   165,    -1,    -1,   118,   203,   182,   165,    -1,
      -1,   119,   203,   183,   165,    -1,    -1,   120,   203,   184,
     165,    -1,    -1,   121,   203,   185,   165,    -1,    -1,   203,
     166,   186,   165,    -1,    -1,   118,   203,   166,   187,   165,
      -1,    -1,   119,   203,   166,   188,   165,    -1,    -1,   120,
     203,   166,   189,   165,    -1,    -1,   121,   203,   166,   190,
     165,    -1,   199,    -1,   192,    -1,   196,    -1,   193,    -1,
      63,    -1,    63,   206,    -1,   194,    -1,   195,    -1,    73,
     193,    -1,    73,   121,   193,    -1,    64,   194,    65,    -1,
      64,   194,    65,   206,    -1,   197,    -1,    73,    64,   198,
      65,    -1,    73,   121,    64,   198,    65,    -1,    73,   196,
      -1,    73,   121,   196,    -1,    64,   196,    65,    -1,    64,
     198,   206,    65,    -1,    64,   196,    65,   206,    -1,    63,
      -1,    64,   198,    65,    -1,   200,    -1,   202,    -1,   201,
      -1,    73,   199,    -1,    73,   121,   199,    -1,   202,   206,
      -1,    64,   200,    65,    -1,    64,   200,    65,   206,    -1,
      60,    -1,    64,   202,    65,    -1,   204,    -1,    73,   203,
      -1,    73,   121,   203,    -1,   202,    64,   154,    65,    -1,
      64,   203,    65,    -1,    64,   203,    65,   206,    -1,   208,
      -1,   209,    -1,   206,    -1,   207,    -1,    64,    65,    -1,
      64,   151,    65,    -1,    66,    67,    -1,    66,   110,    67,
      -1,    66,    73,    67,    -1,   207,    66,   110,    67,    -1,
     207,    66,    73,    67,    -1,    73,    -1,    73,   121,    -1,
      73,   205,    -1,    73,   121,   205,    -1,    64,   208,    65,
      -1,    64,   209,    65,    -1,    64,   206,    65,    -1,    64,
     208,    65,   206,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   548,   548,   549,   556,   562,   563,   564,   568,   569,
     570,   571,   572,   572,   573,   573,   574,   575,   576,   577,
     581,   582,   586,   587,   591,   592,   593,   594,   612,   613,
     617,   618,   619,   620,   621,   622,   626,   627,   631,   632,
     634,   641,   651,   652,   654,   659,   660,   662,   667,   668,
     670,   672,   674,   679,   680,   682,   687,   688,   693,   694,
     699,   700,   705,   706,   711,   712,   717,   718,   723,   724,
     728,   729,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   742,   743,   747,   751,   753,   791,   792,   793,   794,
     801,   823,   829,   840,   863,   869,   881,   886,   887,   892,
     897,   898,   904,   905,   906,   910,   911,   915,   916,   920,
     921,   922,   926,   927,   928,   929,   933,   934,   935,   936,
     940,   945,   950,   958,   959,   960,   964,   965,   966,   970,
     971,   974,   979,   984,   992,   993,   994,   998,   999,  1000,
    1001,  1002,  1003,  1007,  1008,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1019,  1020,  1024,  1040,  1071,  1097,  1106,  1107,
    1111,  1124,  1137,  1138,  1139,  1143,  1157,  1172,  1186,  1202,
    1216,  1226,  1239,  1249,  1262,  1263,  1267,  1271,  1287,  1319,
    1345,  1353,  1367,  1383,  1390,  1400,  1413,  1414,  1418,  1419,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1444,  1445,  1449,  1464,  1480,  1494,
    1513,  1520,  1530,  1532,  1536,  1537,  1538,  1542,  1543,  1546,
    1548,  1552,  1553,  1557,  1558,  1563,  1564,  1565,  1566,  1567,
    1568,  1572,  1573,  1574,  1578,  1579,  1580,  1581,  1585,  1586,
    1590,  1591,  1595,  1599,  1600,  1601,  1605,  1606,  1607,  1611,
    1612,  1613,  1614,  1620,  1622,  1626,  1627,  1631,  1632,  1636,
    1636,  1638,  1638,  1640,  1640,  1642,  1642,  1644,  1644,  1647,
    1647,  1648,  1648,  1649,  1649,  1650,  1650,  1651,  1651,  1653,
    1653,  1654,  1654,  1655,  1655,  1656,  1656,  1657,  1657,  1661,
    1662,  1666,  1667,  1671,  1683,  1697,  1704,  1705,  1711,  1720,
    1721,  1732,  1733,  1739,  1745,  1751,  1760,  1761,  1766,  1774,
    1786,  1790,  1791,  1795,  1796,  1802,  1811,  1816,  1817,  1825,
    1838,  1842,  1843,  1844,  1848,  1853,  1854,  1862,  1863,  1864,
    1878,  1879,  1880,  1884,  1885,  1899,  1913,  1932,  1954,  1959,
    1964,  1969,  1977,  1978,  1979,  1990
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
  "elaborated_type_name", "aggregate_name", "aggregate_key_context", 
  "aggregate_key", "member_declaration_list", "member_declaration", 
  "unnamed_su_declaration", "member_default_declaring_list", 
  "member_declaring_list", "member_declarator", 
  "member_identifier_declarator", "bit_field_size_opt", "bit_field_size", 
  "enum_name", "enum_key_context", "enumerator_list", "enumerator", 
  "parameter_type_list", "parameter_list", "parameter_declaration", 
  "identifier_list", "identifier_or_typedef_name", "type_name", 
  "initializer_opt", "initializer", "initializer_list", "designation_opt", 
  "designator_list", "designator", "statement", "labeled_statement", 
  "compound_statement", "declaration_list", "statement_list", 
  "expression_statement", "selection_statement", "iteration_statement", 
  "jump_statement", "source_file", "translation_unit", 
  "external_definition", "function_definition", "@3", "@4", "@5", "@6", 
  "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15", "@16", 
  "@17", "declarator", "typedef_declarator", 
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
     133,   133,   134,   134,   135,   135,   135,   136,   137,   137,
     138,   138,   139,   139,   139,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   147,   147,   147,
     148,   149,   149,   149,   150,   150,   151,   151,   152,   152,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   156,   157,   157,   158,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   164,   164,   164,   165,   165,   165,   165,   166,   166,
     167,   167,   168,   169,   169,   169,   170,   170,   170,   171,
     171,   171,   171,   172,   172,   173,   173,   174,   174,   176,
     175,   177,   175,   178,   175,   179,   175,   180,   175,   181,
     175,   182,   175,   183,   175,   184,   175,   185,   175,   186,
     175,   187,   175,   188,   175,   189,   175,   190,   175,   191,
     191,   192,   192,   193,   193,   193,   194,   194,   194,   195,
     195,   196,   196,   196,   196,   196,   197,   197,   197,   198,
     198,   199,   199,   200,   200,   200,   201,   201,   201,   202,
     202,   203,   203,   203,   204,   204,   204,   205,   205,   205,
     206,   206,   206,   207,   207,   207,   207,   207,   208,   208,
     208,   208,   209,   209,   209,   209
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
       1,     2,     2,     2,     2,     1,     2,     3,     2,     3,
       2,     1,     2,     1,     0,     1,     2,     4,     5,     2,
       1,     1,     3,     2,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     1,     2,     2,     1,     3,     1,     1,     1,     2,
       1,     2,     0,     2,     3,     4,     1,     2,     4,     0,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     2,     5,     7,     5,     5,     7,     9,     3,
       2,     2,     3,     0,     1,     1,     2,     1,     1,     0,
       3,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       3,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     5,     0,     5,     0,     5,     0,     5,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     3,     3,
       4,     1,     4,     5,     2,     3,     3,     4,     4,     1,
       3,     1,     1,     1,     2,     3,     2,     3,     4,     1,
       3,     1,     2,     3,     4,     3,     4,     1,     1,     1,
       1,     2,     3,     2,     3,     3,     4,     4,     1,     2,
       2,     3,     3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     253,   140,   148,   143,   158,   146,   180,   141,   137,   144,
     138,   159,   109,   147,   145,   150,   149,   151,   111,   139,
     142,   110,   319,   134,     0,     0,   258,     0,     0,     0,
       0,     0,     0,   105,    96,    99,    97,   100,    98,   101,
     102,   116,   123,   152,     0,   157,   153,     0,     0,   254,
     255,   257,   259,   311,   313,   312,   269,   321,     0,     0,
       0,     0,   314,   322,     0,    89,     0,    88,   293,     0,
       0,   212,   290,   292,   295,   296,   291,   301,   289,   271,
     212,   289,   273,   132,   104,   108,   107,   112,   120,   212,
     275,   135,   106,   103,   117,   124,   212,   277,   114,   115,
     118,   113,   119,    86,   122,    87,   125,   121,   133,   136,
     131,   206,   207,     0,   156,     0,   179,     1,   256,     0,
       0,     0,   316,   330,   238,     0,     0,     0,     0,   279,
       0,   317,   320,   325,   315,   323,     0,     0,   212,   312,
       0,     0,   212,   289,     0,   294,   309,     0,     0,     0,
       0,     0,     0,   297,   304,     0,    93,     0,   281,     0,
      94,     0,   283,     0,    90,     0,   285,     0,    91,     0,
     287,     0,     0,     0,    99,   100,   129,   165,   101,   152,
       0,   160,     0,     0,     0,     0,     0,   181,   184,     0,
      84,   260,   204,   331,   190,   197,   194,   201,    97,   100,
       0,   186,   188,     0,     0,     0,     0,     4,     2,     5,
       0,   333,    30,    31,    32,    33,    34,    35,     6,     8,
      24,    36,     0,    38,    42,    45,    48,    53,    56,    58,
      60,    62,    64,    66,    68,     0,     0,   212,   212,   239,
       0,   270,   318,   326,     0,     0,    92,     0,     0,     0,
      95,     0,   299,   306,     0,     0,     0,   298,   305,   219,
      31,   216,   213,   262,     0,   272,   264,     0,   274,   266,
       0,   276,   268,     0,   278,     0,   168,   171,   174,   152,
     166,   173,   174,   125,   154,   161,   164,     0,   163,     0,
     162,     0,   177,   183,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,    84,     0,     0,     4,   134,   234,
      81,    85,     0,     0,   240,   225,   226,    84,    84,   227,
     228,   229,   230,     0,   338,   193,   192,   191,   329,   327,
     328,   200,   199,   198,     0,   338,   196,   195,   203,   202,
     332,     0,   324,     0,     0,    28,     0,    25,    26,     0,
     208,   210,   100,   101,     0,   335,     3,    16,    17,     0,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    70,     0,    36,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   334,    31,     0,   280,
       0,   310,   300,   308,   307,   302,     0,     0,     0,     0,
       0,     0,   221,   282,   284,   286,   288,    83,   176,   170,
     175,   172,   167,   169,   155,   182,   185,   178,   251,     0,
       0,     0,   250,    84,    84,     0,     0,     0,     0,     0,
     242,    84,   235,    84,   236,   241,     0,     0,     0,   339,
     340,   339,   187,   189,   205,     0,     0,     7,     0,   338,
     209,   211,     0,    10,     0,    22,     0,     0,     0,    69,
      39,    40,    41,    43,    44,    46,    47,    51,    52,    49,
      50,    54,    55,    57,    59,    61,    63,    65,     0,   337,
     336,   303,     0,   224,   214,   219,   217,   220,   222,     0,
      84,   252,     0,   233,   249,     0,     0,     0,    82,   231,
     237,   344,   342,   343,   341,    29,     0,   339,   219,    37,
      11,     0,     9,    20,    21,    13,    15,     0,   223,   215,
       0,    84,   232,    84,     0,    84,    84,   345,     0,    23,
      67,   218,   245,     0,     0,   243,   246,    18,   219,    84,
       0,    84,    19,     0,   247,   244,    84,   248
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   218,   219,   220,   361,   362,   525,   464,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   310,   374,   311,   418,   312,   124,    27,    28,
     125,   126,   127,   128,    84,    33,    34,    35,    36,    37,
     176,   177,    38,    39,    40,    41,    42,    43,    44,    45,
     180,   181,   182,   183,   184,   276,   280,   419,   277,    46,
      47,   186,   187,   200,   201,   202,   203,   313,   354,   164,
     262,   409,   410,   411,   412,   314,   315,   316,   129,   318,
     319,   320,   321,   322,    48,    49,    50,    51,   119,   157,
     161,   165,   169,   130,   159,   163,   167,   171,   240,   264,
     267,   270,   273,    71,    72,    73,    74,    75,   149,    77,
     150,    62,    53,    54,   139,    60,    57,   450,   328,   123,
     329,   330
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -465
static const short yypact[] =
{
    1447,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,    98,   370,  -465,   -26,    21,   267,
     267,  1483,  1519,  -465,  2096,  2096,   650,   659,  1094,  1094,
    -465,  -465,  -465,  -465,    26,  -465,  -465,   303,    59,  1447,
    -465,  -465,  -465,  -465,  -465,   399,  1837,  -465,   -39,   476,
       1,   370,  -465,  -465,   139,  -465,   393,  -465,   464,   446,
     386,    -9,  -465,  -465,  -465,  -465,  -465,  -465,    32,  1837,
      -9,    55,  1837,  -465,  -465,  -465,  -465,  -465,  -465,    30,
    1837,  -465,  -465,  -465,  -465,  -465,    41,  1837,  -465,  -465,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,   951,    83,    28,    91,  -465,  -465,   121,
    1728,  1835,  -465,   165,  -465,   393,   393,  1555,  1591,  1837,
     121,   464,  -465,   464,  -465,  -465,   139,  1841,    -9,   464,
     462,   694,    -9,  -465,  1764,  -465,  -465,   446,   175,   182,
     464,   446,   971,  -465,  -465,  1864,  -465,   121,  1837,   121,
    -465,   121,  1837,   121,  -465,   121,  1837,   121,  -465,   121,
    1837,   121,   417,   696,  1244,    79,  -465,  -465,    16,   228,
    1656,  -465,   232,    67,    85,   951,   103,  -465,   176,    28,
     773,  -465,  -465,  -465,   186,   186,  1225,  1290,  1094,  1094,
     204,   227,  -465,   -38,  1943,  1969,  1969,  -465,  -465,  -465,
     922,  -465,  -465,   257,  -465,  -465,  -465,  -465,   285,  -465,
     359,   770,  1995,  -465,   211,   107,   164,    38,   231,   279,
     276,   288,   327,   -34,  -465,   323,  2021,    -9,    -9,  -465,
     121,  -465,  -465,  -465,   479,  1841,  -465,   462,   462,  1762,
    -465,   486,   464,   464,   313,   516,   446,  -465,  -465,   487,
    -465,  -465,  -465,  -465,   121,  -465,  -465,   121,  -465,  -465,
     121,  -465,  -465,   121,  -465,  1995,  -465,  -465,   308,   314,
    -465,  -465,   308,   317,  -465,  -465,  -465,   170,  -465,   417,
    -465,  1692,  -465,    28,  1995,   223,   322,   353,  1995,  1995,
     334,   360,   350,    28,  1307,   383,   390,   385,   398,  -465,
    -465,   430,   418,   436,  -465,  -465,  -465,   848,   993,  -465,
    -465,  -465,  -465,  1068,   646,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  1133,  1818,  -465,  -465,  -465,  -465,
    -465,  1798,  -465,   467,   922,  -465,   922,  -465,  -465,   -18,
     156,  1627,    79,    79,   459,  -465,  -465,  -465,  -465,  1890,
    1995,   468,   518,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  1995,  -465,  -465,  1995,  1995,  1995,
    1995,  1995,  1995,  1995,  1995,  1995,  1995,  1995,  1995,  1995,
    1995,  1995,  1995,  1995,  1995,  1995,  -465,   508,   509,  -465,
     462,  -465,  -465,  -465,  -465,  -465,   536,  1995,    28,   271,
    1864,     7,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  1995,
     493,   498,  -465,  1995,  1307,   499,   559,  1995,  1995,  1995,
    -465,  1307,  -465,  1150,  -465,  -465,   530,   532,   533,   646,
    -465,  1818,  -465,  -465,  -465,   538,   539,  -465,  1382,   866,
    -465,  -465,  1917,  -465,   150,  -465,    78,    54,    54,  -465,
    -465,  -465,  -465,   211,   211,   107,   107,   164,   164,   164,
     164,    38,    38,   231,   279,   276,   288,   327,   -48,  -465,
    -465,  -465,   542,  -465,  -465,   244,  -465,  -465,  -465,   196,
    1307,  -465,   524,  -465,  -465,   541,   264,   311,  -465,  -465,
    -465,  -465,   464,  -465,  -465,   545,   545,   866,   487,  -465,
    -465,  1995,  -465,  -465,  -465,  -465,  -465,  1995,  -465,  -465,
    1864,  1307,  -465,  1995,  1995,  1307,  1307,  -465,   405,  -465,
    -465,  -465,  -465,   528,   361,   609,  -465,  -465,   394,  1995,
     531,  1307,  -465,   554,  -465,  -465,  1307,  -465
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -465,  -465,  -465,  -465,  -465,  -465,   157,  -465,   180,  -465,
    -202,   -79,   106,   129,   144,   234,   235,   237,   239,   233,
    -465,  -273,  -111,  -465,  -159,  -224,  -236,    22,  -465,  -465,
      11,    13,    15,     9,     4,   -31,  -465,   203,   -96,   138,
    -465,  -465,  -465,   248,   461,   410,    36,   -95,  -465,  -465,
     445,  -163,  -465,  -465,  -465,   345,   348,   354,   -43,  -465,
    -465,   449,   351,  -465,  -465,   305,  -465,   -28,   202,    99,
    -361,   130,  -464,  -465,   243,    77,  -465,   480,    23,   333,
    -465,  -465,  -465,  -465,  -465,  -465,   606,  -465,  -465,  -465,
    -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,  -465,
    -465,  -465,  -465,     6,  -465,   -58,   -40,  -465,   382,  -465,
    -108,   242,   117,  -465,   256,   591,  -465,  -140,   -27,  -465,
    -258,  -254
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -268
static const short yytable[] =
{
      85,    92,   417,    85,   100,    85,   106,    85,   109,    32,
     235,    29,   153,    30,   394,    31,   114,   285,   179,   116,
     376,   417,    26,   439,   198,   417,   131,   342,   122,   148,
      92,   530,   122,   343,    61,    12,    80,   527,    98,   251,
     104,   145,   108,   255,   261,    64,    18,   457,   198,   496,
     395,   349,    21,   439,   327,   333,   337,   339,    32,   117,
      29,    65,    30,   431,    31,   447,   133,    88,    95,   448,
     426,    26,   142,   407,   430,   408,   447,   155,   279,   152,
     448,   384,   385,   153,   530,   179,   111,   188,   111,   112,
     179,   112,    66,   497,   257,   113,    85,    92,    12,  -265,
     148,  -261,   158,  -130,   242,   162,   243,   148,    67,    18,
    -267,   148,   122,   166,   523,    21,   155,   524,   386,   387,
     170,    92,   173,   254,  -263,   398,   172,   155,   285,   197,
     281,   194,    80,   195,   417,   196,   325,   331,   287,   251,
     255,    58,    92,   100,   283,   522,   245,   109,   406,   439,
     249,   239,   185,   197,   288,   194,   289,   195,    22,   196,
     189,   188,    24,    88,    95,    85,    92,    85,   106,   541,
     156,    25,   290,   292,   293,   470,   471,   472,   278,   160,
     239,   380,   381,   492,   239,   349,    58,   349,   239,   173,
     190,   257,   239,   172,   173,   168,   179,   502,   172,    22,
     447,   466,   104,   136,   448,   382,   383,   148,   148,    95,
     460,   461,   137,   317,    92,   520,   148,   122,    92,   351,
     458,   521,   121,   350,   254,   402,   403,   198,   254,   459,
      22,   236,    88,    95,   136,   420,   488,   246,   198,   420,
     252,   250,    52,   137,   281,   198,    22,   253,   465,    68,
     323,   175,   121,    58,   540,   275,    55,    58,   199,   324,
     519,   531,   294,   469,    58,   188,   153,   439,    58,   340,
     499,    78,    81,    89,    96,   435,   388,   389,   506,   507,
      59,    55,   199,   148,   377,    55,    55,    55,    55,   378,
     379,    52,   406,   427,   293,   278,   446,   543,   341,   261,
     173,   473,   474,   134,   172,    55,   138,   446,   143,   514,
     407,   514,   408,   553,   529,  -126,   174,    55,   175,   286,
      92,   106,   109,   175,   355,    59,    55,    22,   508,   535,
      68,    69,   197,   449,   194,   439,   195,   168,   196,   239,
      70,   494,   495,   197,   451,   194,   356,   195,   352,   196,
     197,   390,   194,   351,   195,   351,   196,   350,   391,   350,
     148,   178,   198,   111,    58,    58,   112,   143,   143,   237,
     238,   392,   115,    58,   393,   544,   536,   514,   404,   254,
     493,   436,   439,   174,   345,   347,   348,    95,   174,    12,
     396,   257,   244,   275,   134,   445,   244,   -14,   357,   358,
      18,  -127,   375,    59,  -128,    12,    21,    59,    55,   428,
     539,    76,    76,   174,   143,   282,    18,   429,    92,   261,
      92,   432,    21,   359,   433,   360,   550,   -12,   178,   175,
      22,   446,   439,   178,    24,   434,   326,   332,   336,   338,
      58,    87,    94,    25,    99,   102,    22,   437,    76,    68,
     151,    58,   154,    22,   438,   375,    68,   140,   353,    70,
     407,   199,   408,   120,   552,   121,   141,   197,   517,   194,
    -206,   195,   199,   196,   375,   547,   548,    22,   375,   199,
      68,   140,   352,  -207,   352,   537,    92,   134,   475,   476,
     141,   134,    86,    93,   174,    86,   101,    86,   107,    86,
     110,   439,   275,   244,   244,   440,    22,    76,    76,   146,
     147,   503,    59,   477,   478,   479,   480,    58,   509,    70,
     445,   441,    22,   154,   462,   146,   247,   454,   144,   282,
     121,   143,   481,   482,   258,   141,   467,    87,    94,   178,
     120,   132,   121,   144,   132,   121,   455,   174,   456,   174,
     144,   401,   121,   407,    76,   408,   468,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   489,   490,   532,   500,   244,
     144,   405,   121,    94,   102,   501,   504,   375,    86,    93,
     244,    56,   353,   505,   353,   511,   199,   512,   513,   191,
     144,   491,   121,   515,   516,   534,    87,    94,   542,   528,
     241,   533,   545,   546,   518,   549,    63,   551,   554,   556,
      79,    82,    90,    97,   483,   526,   484,   487,   555,   485,
     291,   258,   486,   557,   423,   422,   421,   263,   295,   265,
      56,   266,   375,   268,   425,   269,   453,   271,   538,   272,
     443,   274,   135,     1,   498,   118,   244,    86,    93,    86,
     107,    63,     1,     7,     8,    12,    10,     0,     0,    12,
       0,    76,     7,     8,     0,    10,    18,     0,    12,     0,
      18,     0,    21,    19,     0,    20,    21,     0,     0,    18,
       0,   134,    19,   134,    20,    21,     0,     0,     0,     0,
       2,     3,     4,     0,     0,     5,    22,   375,     6,    68,
     323,     9,   121,    12,    11,    12,    13,    14,    15,   324,
     399,    16,    17,     0,    18,     0,    18,     0,     0,     0,
      21,     0,    21,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,   135,   413,     0,   105,   414,     0,     0,
     415,     0,     0,   416,    22,     0,    22,    68,   248,    91,
     136,    94,     0,     0,     0,     0,     0,   141,     0,   137,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
     296,   275,     5,   297,   298,     6,     7,     8,     9,    10,
     299,    11,    12,    13,    14,    15,   300,   301,    16,    17,
     302,   303,   204,    18,   304,   305,    19,   306,    20,    21,
       0,     0,   205,   206,     0,     0,     0,     0,     0,     0,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
       0,     0,     0,   307,   208,   209,   308,   210,     0,     0,
       0,     0,   190,   309,     0,   212,   260,   214,   215,   216,
     217,     1,     2,     3,     4,   296,   373,     5,   297,   298,
       6,     7,     8,     9,    10,   299,    11,    12,    13,    14,
      15,   300,   301,    16,    17,   302,   303,   204,    18,   304,
     305,    19,   306,    20,    21,    12,     0,   205,   206,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,   307,   208,
     209,   308,   210,     0,     0,     0,     0,   190,   442,     0,
     212,   260,   214,   215,   216,   217,     2,     3,     4,     0,
     458,     5,   121,     0,     6,     0,     0,     9,     0,   459,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,   204,    18,     0,     0,     2,     3,     4,    21,     0,
       5,   205,   206,     6,     0,     0,     9,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,   207,   208,   209,    23,   210,    21,     0,     0,
      12,     0,     0,     0,   212,   260,   214,   215,   216,   217,
     296,    18,     0,   297,   298,     0,     0,    21,     0,     0,
     299,     0,     0,     0,    23,     0,   300,   301,     0,     0,
     302,   303,   204,     0,   304,   305,     0,   306,     0,     0,
       0,    22,   205,   206,    68,   256,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,   307,   208,   209,   112,   210,     0,     0,
       0,     0,   190,   444,     0,   212,   260,   214,   215,   216,
     217,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     1,    18,     0,
       0,    19,     0,    20,    21,     0,     0,     7,     8,     0,
      10,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,    19,    22,    20,
      21,    23,   323,   193,   121,     0,     1,     2,     3,     4,
       0,   324,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,   296,    16,    17,
     297,   298,     0,    18,     0,     0,    19,   299,    20,    21,
       0,     0,     0,   300,   301,     0,     0,   302,   303,   204,
       0,   304,   305,     0,   306,     0,     0,     0,     0,   205,
     206,     0,     0,    22,     0,     0,    23,   334,   193,   121,
       0,     0,     0,     0,     0,     0,   335,     0,     0,     0,
     307,   208,   209,   112,   210,     0,     0,     0,     0,   190,
     510,     0,   212,   260,   214,   215,   216,   217,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     2,     3,
      16,    17,     0,     5,     0,    18,     0,     0,    19,     9,
      20,    21,     0,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,    22,     0,     0,    83,   334,
       0,   121,     0,     1,     2,     3,     4,     0,   335,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,   296,    16,    17,   297,   298,     0,
      18,     0,     0,    19,   299,    20,    21,     0,     0,     0,
     300,   301,     0,     0,   302,   303,   204,     0,   304,   305,
       0,   306,     0,     0,     0,     0,   205,   206,     0,     0,
      22,     0,     0,    91,   334,     0,   121,     0,     0,     0,
       0,     0,     0,   335,     0,     0,     0,   307,   208,   209,
     112,   210,     0,     0,     0,     0,   190,     0,     0,   212,
     260,   214,   215,   216,   217,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,     0,    18,     0,     0,    19,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,   458,   193,   121,     0,
       1,     2,     3,     4,     0,   459,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,    20,    21,     0,     0,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,    22,    16,    17,
      23,    24,     0,    18,     0,     0,    19,     0,    20,    21,
      25,     0,     1,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,    22,    16,    17,    83,    24,     0,    18,
       0,     0,    19,     0,    20,    21,    25,     0,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,    22,
      16,    17,    91,    24,     0,    18,     0,     0,    19,     0,
      20,    21,    25,     0,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,    22,    16,    17,    83,   136,
       0,    18,     0,     0,    19,     0,    20,    21,   137,     0,
       0,     2,     3,     4,     0,     0,     5,     0,     0,     6,
       0,     0,     9,     0,     0,    11,    12,    13,    14,    15,
       0,    22,    16,    17,    91,   136,     0,    18,     0,     0,
       2,     3,     4,    21,   137,     5,     0,     0,     6,     0,
       0,     9,     0,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,     0,
      91,   458,    21,   121,     0,     0,     2,     3,     4,     0,
     459,     5,     0,     0,     6,     0,     0,     9,     0,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,    23,
       0,     0,    18,     0,     0,     0,   284,     0,    21,     0,
       0,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,    23,     0,     0,    18,     0,
       0,    19,   424,    20,    21,     0,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,    12,    11,    12,    13,    14,    15,     0,   192,    16,
      17,    23,    18,   193,    18,     0,     0,    19,    21,    20,
      21,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,    22,    16,    17,    68,   400,    23,    18,   193,
       0,    19,     0,    20,    21,   141,     0,    12,     0,     0,
       1,     2,     3,     4,     0,     0,     5,   452,    18,     6,
       7,     8,     9,    10,    21,    11,    12,    13,    14,    15,
      12,    23,    16,    17,   204,     0,     0,    18,     0,     0,
      19,    18,    20,    21,   205,   206,     0,    21,    22,     0,
       0,     0,   334,     0,   121,     0,     0,     0,     0,     0,
       0,   335,     0,   204,     0,   207,   208,   209,     0,   210,
      23,    22,   211,   205,   206,   136,     0,   212,   213,   214,
     215,   216,   217,     0,   137,     0,     0,     0,     0,   204,
       0,     0,     0,     0,   207,   208,   209,     0,   210,   205,
     206,     0,     0,   259,     0,     0,   212,   260,   214,   215,
     216,   217,     0,     0,     0,     0,   204,     0,     0,     0,
     207,   208,   209,     0,   210,   463,   205,   206,     0,     0,
       0,     0,   212,   260,   214,   215,   216,   217,     0,     0,
       0,     0,   204,     0,     0,     0,     0,   207,   208,   209,
       0,   210,   205,   206,     0,     0,   518,     0,     0,   212,
     260,   214,   215,   216,   217,     0,     0,     0,   204,     0,
       0,     0,     0,   207,   208,   209,     0,   344,   205,   206,
       0,     0,     0,     0,     0,   212,   260,   214,   215,   216,
     217,     0,     0,     0,   204,     0,     0,     0,     0,   207,
     208,   209,     0,   346,   205,   206,     0,     0,     0,     0,
       0,   212,   260,   214,   215,   216,   217,     0,     0,     0,
     204,     0,     0,     0,     0,   207,   208,   209,     0,   210,
     205,   206,     0,     0,     0,     0,     0,   212,   260,   214,
     215,   216,   217,     0,     0,     0,     0,     0,     0,     0,
       0,   207,   208,   209,     0,   210,     0,     0,     0,     0,
       0,     0,     0,   212,   397,   214,   215,   216,   217,     1,
       2,     3,     0,     0,     0,     5,     0,     0,     0,     7,
       8,     9,    10,     0,     0,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21
};

static const short yycheck[] =
{
      31,    32,   275,    34,    35,    36,    37,    38,    39,     0,
     121,     0,    70,     0,    48,     0,    44,   180,   113,    47,
     222,   294,     0,    71,   120,   298,    65,    65,    55,    69,
      61,   495,    59,    71,    25,    19,    30,    85,    34,   147,
      36,    68,    38,   151,   155,    71,    30,    65,   144,   410,
      84,   210,    36,    71,   194,   195,   196,   197,    49,     0,
      49,    87,    49,   299,    49,   323,    65,    31,    32,   323,
     294,    49,    66,    66,   298,    68,   334,    86,   173,    70,
     334,    43,    44,   141,   548,   180,    60,   115,    60,    63,
     185,    63,    71,    86,   152,    69,   127,   128,    19,    69,
     140,    69,    79,    87,   131,    82,   133,   147,    87,    30,
      69,   151,   139,    90,    60,    36,    86,    63,    80,    81,
      97,   152,   113,   150,    69,   236,   113,    86,   291,   120,
     173,   120,   126,   120,   407,   120,   194,   195,    71,   247,
     248,    24,   173,   174,   175,    67,   137,   178,   256,    71,
     141,   129,    69,   144,    87,   144,    71,   144,    60,   144,
      69,   189,    64,   127,   128,   196,   197,   198,   199,   530,
      71,    73,    87,    70,    71,   377,   378,   379,   172,    80,
     158,    74,    75,   407,   162,   344,    69,   346,   166,   180,
      69,   249,   170,   180,   185,    96,   291,   433,   185,    60,
     458,   360,   198,    64,   458,    41,    42,   247,   248,   173,
     350,   351,    73,   190,   245,    65,   256,   244,   249,   210,
      64,    71,    66,   210,   251,   252,   253,   323,   255,    73,
      60,    66,   196,   197,    64,   278,   395,   138,   334,   282,
      65,   142,     0,    73,   287,   341,    60,    65,   359,    63,
      64,   113,    66,   136,   527,    85,     0,   140,   120,    73,
     462,    65,    86,   374,   147,   293,   324,    71,   151,    65,
     429,    29,    30,    31,    32,   303,    45,    46,   437,   438,
      24,    25,   144,   323,    73,    29,    30,    31,    32,    78,
      79,    49,   400,    70,    71,   289,   323,   533,    71,   410,
     291,   380,   381,    61,   291,    49,    64,   334,    66,   449,
      66,   451,    68,   549,    70,    87,   113,    61,   180,    87,
     351,   352,   353,   185,    67,    69,    70,    60,   439,    65,
      63,    64,   323,   324,   323,    71,   323,   238,   323,   317,
      73,    70,    71,   334,   335,   334,    61,   334,   210,   334,
     341,    72,   341,   344,   341,   346,   341,   344,    82,   346,
     400,   113,   458,    60,   247,   248,    63,   125,   126,   127,
     128,    83,    69,   256,    47,   534,    65,   517,    65,   406,
     408,   304,    71,   180,   204,   205,   206,   351,   185,    19,
      67,   449,   136,    85,   152,   318,   140,    38,    39,    40,
      30,    87,   222,   147,    87,    19,    36,   151,   152,    87,
     521,    29,    30,   210,   172,   173,    30,    64,   449,   530,
     451,    87,    36,    64,    64,    66,    65,    68,   180,   291,
      60,   458,    71,   185,    64,    85,   194,   195,   196,   197,
     323,    31,    32,    73,    34,    35,    60,    64,    66,    63,
      64,   334,    70,    60,    64,   275,    63,    64,   210,    73,
      66,   323,    68,    64,    70,    66,    73,   458,   459,   458,
      85,   458,   334,   458,   294,    70,    71,    60,   298,   341,
      63,    64,   344,    85,   346,   512,   517,   245,   382,   383,
      73,   249,    31,    32,   291,    34,    35,    36,    37,    38,
      39,    71,    85,   247,   248,    87,    60,   125,   126,    63,
      64,   434,   256,   384,   385,   386,   387,   400,   441,    73,
     443,    85,    60,   141,    65,    63,    64,    60,    64,   287,
      66,   289,   388,   389,   152,    73,    68,   127,   128,   291,
      64,    65,    66,    64,    65,    66,   344,   344,   346,   346,
      64,    65,    66,    66,   172,    68,    38,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,    67,    67,   500,    85,   323,
      64,    65,    66,   173,   174,    87,    87,   407,   127,   128,
     334,     0,   344,    34,   346,    65,   458,    65,    65,   119,
      64,    65,    66,    65,    65,    64,   196,   197,   531,    67,
     130,    87,   535,   536,    69,    87,    25,     8,    87,    65,
      29,    30,    31,    32,   390,   468,   391,   394,   551,   392,
     185,   249,   393,   556,   289,   287,   282,   157,   189,   159,
      49,   161,   462,   163,   293,   165,   341,   167,   518,   169,
     317,   171,    61,     3,   411,    49,   400,   196,   197,   198,
     199,    70,     3,    13,    14,    19,    16,    -1,    -1,    19,
      -1,   289,    13,    14,    -1,    16,    30,    -1,    19,    -1,
      30,    -1,    36,    33,    -1,    35,    36,    -1,    -1,    30,
      -1,   449,    33,   451,    35,    36,    -1,    -1,    -1,    -1,
       4,     5,     6,    -1,    -1,     9,    60,   527,    12,    63,
      64,    15,    66,    19,    18,    19,    20,    21,    22,    73,
     240,    25,    26,    -1,    30,    -1,    30,    -1,    -1,    -1,
      36,    -1,    36,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,   152,   264,    -1,    87,   267,    -1,    -1,
     270,    -1,    -1,   273,    60,    -1,    60,    63,    64,    63,
      64,   351,    -1,    -1,    -1,    -1,    -1,    73,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    85,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,     3,     4,     5,     6,     7,    86,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    19,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    -1,
      72,    73,    74,    75,    76,    77,     4,     5,     6,    -1,
      64,     9,    66,    -1,    12,    -1,    -1,    15,    -1,    73,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    29,    30,    -1,    -1,     4,     5,     6,    36,    -1,
       9,    39,    40,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    60,    61,    62,    63,    64,    36,    -1,    -1,
      19,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
       7,    30,    -1,    10,    11,    -1,    -1,    36,    -1,    -1,
      17,    -1,    -1,    -1,    63,    -1,    23,    24,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    -1,    34,    -1,    -1,
      -1,    60,    39,    40,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,     3,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    13,    14,    -1,
      16,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    60,    35,
      36,    63,    64,    65,    66,    -1,     3,     4,     5,     6,
      -1,    73,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,     7,    25,    26,
      10,    11,    -1,    30,    -1,    -1,    33,    17,    35,    36,
      -1,    -1,    -1,    23,    24,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    -1,    34,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    60,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    -1,    72,    73,    74,    75,    76,    77,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,     4,     5,
      25,    26,    -1,     9,    -1,    30,    -1,    -1,    33,    15,
      35,    36,    -1,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    64,
      -1,    66,    -1,     3,     4,     5,     6,    -1,    73,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,     7,    25,    26,    10,    11,    -1,
      30,    -1,    -1,    33,    17,    35,    36,    -1,    -1,    -1,
      23,    24,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      -1,    34,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,
      60,    -1,    -1,    63,    64,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,
      73,    74,    75,    76,    77,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
       3,     4,     5,     6,    -1,    73,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    60,    25,    26,
      63,    64,    -1,    30,    -1,    -1,    33,    -1,    35,    36,
      73,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    60,    25,    26,    63,    64,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    73,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    60,
      25,    26,    63,    64,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    73,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    60,    25,    26,    63,    64,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,    73,    -1,
      -1,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    60,    25,    26,    63,    64,    -1,    30,    -1,    -1,
       4,     5,     6,    36,    73,     9,    -1,    -1,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      63,    64,    36,    66,    -1,    -1,     4,     5,     6,    -1,
      73,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    63,
      -1,    -1,    30,    -1,    -1,    -1,    70,    -1,    36,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    63,    -1,    -1,    30,    -1,
      -1,    33,    70,    35,    36,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    19,    18,    19,    20,    21,    22,    -1,    60,    25,
      26,    63,    30,    65,    30,    -1,    -1,    33,    36,    35,
      36,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    60,    25,    26,    63,    64,    63,    30,    65,
      -1,    33,    -1,    35,    36,    73,    -1,    19,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    49,    30,    12,
      13,    14,    15,    16,    36,    18,    19,    20,    21,    22,
      19,    63,    25,    26,    29,    -1,    -1,    30,    -1,    -1,
      33,    30,    35,    36,    39,    40,    -1,    36,    60,    -1,
      -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    29,    -1,    60,    61,    62,    -1,    64,
      63,    60,    67,    39,    40,    64,    -1,    72,    73,    74,
      75,    76,    77,    -1,    73,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    60,    61,    62,    -1,    64,    39,
      40,    -1,    -1,    69,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      60,    61,    62,    -1,    64,    65,    39,    40,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    60,    61,    62,
      -1,    64,    39,    40,    -1,    -1,    69,    -1,    -1,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    60,    61,    62,    -1,    64,    39,    40,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    64,    39,    40,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    64,
      39,    40,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,     3,
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
      35,    36,    60,    63,    64,    73,   115,   116,   117,   118,
     119,   120,   121,   123,   124,   125,   126,   127,   130,   131,
     132,   133,   134,   135,   136,   137,   147,   148,   172,   173,
     174,   175,   199,   200,   201,   202,   203,   204,   200,   202,
     203,   121,   199,   203,    71,    87,    71,    87,    63,    64,
      73,   191,   192,   193,   194,   195,   196,   197,   199,   203,
     191,   199,   203,    63,   122,   123,   132,   133,   134,   199,
     203,    63,   123,   132,   133,   134,   199,   203,   122,   133,
     123,   132,   133,    87,   122,    87,   123,   132,   122,   123,
     132,    60,    63,    69,   155,    69,   155,     0,   174,   176,
      64,    66,   206,   207,   115,   118,   119,   120,   121,   166,
     181,    65,    65,    65,   199,   203,    64,    73,   199,   202,
      64,    73,   191,   199,    64,   206,    63,    64,   194,   196,
     198,    64,   121,   193,   196,    86,   157,   177,   166,   182,
     157,   178,   166,   183,   157,   179,   166,   184,   157,   180,
     166,   185,   119,   121,   125,   127,   128,   129,   131,   135,
     138,   139,   140,   141,   142,    69,   149,   150,   155,    69,
      69,   165,    60,    65,   118,   119,   120,   121,   126,   127,
     151,   152,   153,   154,    29,    39,    40,    60,    61,    62,
      64,    67,    72,    73,    74,    75,    76,    77,    89,    90,
      91,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    66,   199,   199,   115,
     186,   165,   206,   206,   202,   121,   157,    64,    64,   121,
     157,   198,    65,    65,   206,   198,    64,   193,   196,    69,
      73,   110,   158,   165,   187,   165,   165,   188,   165,   165,
     189,   165,   165,   190,   165,    85,   143,   146,   191,   135,
     144,   146,   199,   123,    70,   139,    87,    71,    87,    71,
      87,   138,    70,    71,    86,   149,     7,    10,    11,    17,
      23,    24,    27,    28,    31,    32,    34,    60,    63,    70,
     110,   112,   114,   155,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    64,    73,   193,   199,   205,   206,   208,
     209,   193,   199,   205,    64,    73,   199,   205,   199,   205,
      65,    71,    65,    71,    64,    96,    64,    96,    96,   112,
     119,   121,   127,   131,   156,    67,    61,    39,    40,    64,
      66,    92,    93,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    86,   111,    96,    98,    73,    78,    79,
      74,    75,    41,    42,    43,    44,    80,    81,    45,    46,
      72,    82,    83,    47,    48,    84,    67,    73,   110,   165,
      64,    65,   206,   206,    65,    65,   198,    66,    68,   159,
     160,   161,   162,   165,   165,   165,   165,   109,   113,   145,
     146,   145,   144,   143,    70,   150,   113,    70,    87,    64,
     113,   114,    87,    64,    85,   155,   163,    64,    64,    71,
      87,    85,    70,   167,    70,   163,   206,   208,   209,   121,
     205,   121,    49,   153,    60,   156,   156,    65,    64,    73,
     205,   205,    65,    65,    95,   110,   112,    68,    38,   110,
      98,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     101,   102,   102,   103,   104,   105,   106,   107,   112,    67,
      67,    65,   113,   155,    70,    71,   158,    86,   162,   112,
      85,    87,   114,   163,    87,    34,   112,   112,   110,   163,
      70,    65,    65,    65,   205,    65,    65,   121,    69,    98,
      65,    71,    67,    60,    63,    94,    94,    85,    67,    70,
     160,    65,   163,    87,    64,    65,    65,   206,   159,   110,
     109,   158,   163,   114,   112,   163,   163,    70,    71,    87,
      65,     8,    70,   114,    87,   163,    65,   163
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
#line 548 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 3:
#line 550 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-1].value, +, yyvsp[0].value ); ;}
    break;

  case 4:
#line 557 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier )
	      HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    UNDEF_VAL( yyval.value );
	  ;}
    break;

  case 5:
#line 562 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 6:
#line 563 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.iv++; ;}
    break;

  case 7:
#line 564 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 8:
#line 568 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 9:
#line 569 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 10:
#line 570 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 11:
#line 571 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 12:
#line 572 "ctlib/parser.y"
    {;}
    break;

  case 13:
#line 572 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 14:
#line 573 "ctlib/parser.y"
    {;}
    break;

  case 15:
#line 573 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 16:
#line 574 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 17:
#line 575 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 18:
#line 576 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 19:
#line 577 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 20:
#line 581 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 21:
#line 582 "ctlib/parser.y"
    {;}
    break;

  case 22:
#line 586 "ctlib/parser.y"
    {;}
    break;

  case 23:
#line 587 "ctlib/parser.y"
    {;}
    break;

  case 24:
#line 591 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 25:
#line 592 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 26:
#line 593 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 27:
#line 595 "ctlib/parser.y"
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
#line 612 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 29:
#line 613 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 30:
#line 617 "ctlib/parser.y"
    { yyval.oper = '&'; ;}
    break;

  case 31:
#line 618 "ctlib/parser.y"
    { yyval.oper = '*'; ;}
    break;

  case 32:
#line 619 "ctlib/parser.y"
    { yyval.oper = '+'; ;}
    break;

  case 33:
#line 620 "ctlib/parser.y"
    { yyval.oper = '-'; ;}
    break;

  case 34:
#line 621 "ctlib/parser.y"
    { yyval.oper = '~'; ;}
    break;

  case 35:
#line 622 "ctlib/parser.y"
    { yyval.oper = '!'; ;}
    break;

  case 36:
#line 626 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 37:
#line 627 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_CAST; ;}
    break;

  case 38:
#line 631 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 39:
#line 633 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, *, yyvsp[0].value ); ;}
    break;

  case 40:
#line 635 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, /, yyvsp[0].value );
	  ;}
    break;

  case 41:
#line 642 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, %, yyvsp[0].value );
	  ;}
    break;

  case 42:
#line 651 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 43:
#line 653 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, +, yyvsp[0].value ); ;}
    break;

  case 44:
#line 655 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, -, yyvsp[0].value ); ;}
    break;

  case 45:
#line 659 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 46:
#line 661 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <<, yyvsp[0].value ); ;}
    break;

  case 47:
#line 663 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >>, yyvsp[0].value ); ;}
    break;

  case 48:
#line 667 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 49:
#line 669 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <,  yyvsp[0].value ); ;}
    break;

  case 50:
#line 671 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >,  yyvsp[0].value ); ;}
    break;

  case 51:
#line 673 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <=, yyvsp[0].value ); ;}
    break;

  case 52:
#line 675 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >=, yyvsp[0].value ); ;}
    break;

  case 53:
#line 679 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 54:
#line 681 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ==, yyvsp[0].value ); ;}
    break;

  case 55:
#line 683 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, !=, yyvsp[0].value ); ;}
    break;

  case 56:
#line 687 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 57:
#line 689 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &, yyvsp[0].value ); ;}
    break;

  case 58:
#line 693 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 59:
#line 695 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ^, yyvsp[0].value ); ;}
    break;

  case 60:
#line 699 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 61:
#line 701 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, |, yyvsp[0].value ); ;}
    break;

  case 62:
#line 705 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 63:
#line 707 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &&, yyvsp[0].value ); ;}
    break;

  case 64:
#line 711 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 65:
#line 713 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ||, yyvsp[0].value ); ;}
    break;

  case 66:
#line 717 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 67:
#line 719 "ctlib/parser.y"
    { yyval.value = yyvsp[-4].value.iv ? yyvsp[-2].value : yyvsp[0].value; yyval.value.flags |= yyvsp[-4].value.flags; ;}
    break;

  case 68:
#line 723 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 69:
#line 724 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 70:
#line 728 "ctlib/parser.y"
    {;}
    break;

  case 71:
#line 729 "ctlib/parser.y"
    {;}
    break;

  case 72:
#line 730 "ctlib/parser.y"
    {;}
    break;

  case 73:
#line 731 "ctlib/parser.y"
    {;}
    break;

  case 74:
#line 732 "ctlib/parser.y"
    {;}
    break;

  case 75:
#line 733 "ctlib/parser.y"
    {;}
    break;

  case 76:
#line 734 "ctlib/parser.y"
    {;}
    break;

  case 77:
#line 735 "ctlib/parser.y"
    {;}
    break;

  case 78:
#line 736 "ctlib/parser.y"
    {;}
    break;

  case 79:
#line 737 "ctlib/parser.y"
    {;}
    break;

  case 80:
#line 738 "ctlib/parser.y"
    {;}
    break;

  case 81:
#line 742 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 82:
#line 743 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 83:
#line 747 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 85:
#line 753 "ctlib/parser.y"
    {;}
    break;

  case 86:
#line 791 "ctlib/parser.y"
    {;}
    break;

  case 87:
#line 792 "ctlib/parser.y"
    {;}
    break;

  case 88:
#line 793 "ctlib/parser.y"
    {;}
    break;

  case 89:
#line 794 "ctlib/parser.y"
    {;}
    break;

  case 90:
#line 802 "ctlib/parser.y"
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
#line 824 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;}
    break;

  case 92:
#line 830 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-3].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	    else if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;}
    break;

  case 93:
#line 841 "ctlib/parser.y"
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
#line 864 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;}
    break;

  case 95:
#line 870 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-3].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	    else if( yyvsp[-1].pDecl )
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;}
    break;

  case 96:
#line 882 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 97:
#line 886 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 98:
#line 887 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 99:
#line 893 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 100:
#line 897 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 101:
#line 898 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 102:
#line 904 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 103:
#line 905 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 104:
#line 906 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;}
    break;

  case 107:
#line 915 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval; ;}
    break;

  case 108:
#line 916 "ctlib/parser.y"
    { yyval.uval = 0;  ;}
    break;

  case 112:
#line 926 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 113:
#line 927 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 114:
#line 928 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 115:
#line 929 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 116:
#line 933 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 117:
#line 934 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 118:
#line 935 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval;               ;}
    break;

  case 119:
#line 936 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 120:
#line 941 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 121:
#line 946 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 122:
#line 951 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 123:
#line 958 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 124:
#line 959 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 125:
#line 960 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 126:
#line 964 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 127:
#line 965 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 128:
#line 966 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 129:
#line 970 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 130:
#line 971 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 131:
#line 975 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 132:
#line 980 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 133:
#line 985 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 134:
#line 992 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 135:
#line 993 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 136:
#line 994 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 137:
#line 998 "ctlib/parser.y"
    { yyval.uval = T_TYPEDEF;  ;}
    break;

  case 138:
#line 999 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 139:
#line 1000 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 140:
#line 1001 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 141:
#line 1002 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 142:
#line 1003 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 143:
#line 1007 "ctlib/parser.y"
    { yyval.uval = T_INT;      ;}
    break;

  case 144:
#line 1008 "ctlib/parser.y"
    { yyval.uval = T_CHAR;     ;}
    break;

  case 145:
#line 1009 "ctlib/parser.y"
    { yyval.uval = T_SHORT;    ;}
    break;

  case 146:
#line 1010 "ctlib/parser.y"
    { yyval.uval = T_LONG;     ;}
    break;

  case 147:
#line 1011 "ctlib/parser.y"
    { yyval.uval = T_FLOAT;    ;}
    break;

  case 148:
#line 1012 "ctlib/parser.y"
    { yyval.uval = T_DOUBLE;   ;}
    break;

  case 149:
#line 1013 "ctlib/parser.y"
    { yyval.uval = T_SIGNED;   ;}
    break;

  case 150:
#line 1014 "ctlib/parser.y"
    { yyval.uval = T_UNSIGNED; ;}
    break;

  case 151:
#line 1015 "ctlib/parser.y"
    { yyval.uval = T_VOID;     ;}
    break;

  case 152:
#line 1019 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 153:
#line 1020 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 154:
#line 1025 "ctlib/parser.y"
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

  case 155:
#line 1041 "ctlib/parser.y"
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

  case 156:
#line 1072 "ctlib/parser.y"
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

  case 157:
#line 1098 "ctlib/parser.y"
    {
	    yyval.context.uval     = yyvsp[0].uval;
	    yyval.context.ctx.pFI  = PSTATE->pFI;
	    yyval.context.ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 158:
#line 1106 "ctlib/parser.y"
    { yyval.uval = T_STRUCT; ;}
    break;

  case 159:
#line 1107 "ctlib/parser.y"
    { yyval.uval = T_UNION;  ;}
    break;

  case 160:
#line 1112 "ctlib/parser.y"
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

  case 161:
#line 1125 "ctlib/parser.y"
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

  case 162:
#line 1137 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 163:
#line 1138 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 164:
#line 1139 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 165:
#line 1144 "ctlib/parser.y"
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

  case 166:
#line 1158 "ctlib/parser.y"
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

  case 167:
#line 1173 "ctlib/parser.y"
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

  case 168:
#line 1187 "ctlib/parser.y"
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

  case 169:
#line 1203 "ctlib/parser.y"
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

  case 170:
#line 1217 "ctlib/parser.y"
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

  case 171:
#line 1227 "ctlib/parser.y"
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

  case 172:
#line 1240 "ctlib/parser.y"
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

  case 173:
#line 1250 "ctlib/parser.y"
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

  case 174:
#line 1262 "ctlib/parser.y"
    { yyval.ival = -1; ;}
    break;

  case 175:
#line 1263 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].ival; ;}
    break;

  case 176:
#line 1267 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].value.iv; ;}
    break;

  case 177:
#line 1272 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	      LL_destroy( yyvsp[-1].list, (LLDestroyFunc) enum_delete );
	    }
	    else {
	      EnumSpecifier *pEnum = enumspec_new( NULL, 0, yyvsp[-1].list );
	      pEnum->context = yyvsp[-3].context.ctx;
	      LL_push( PSTATE->pCPI->enums, pEnum );
	      yyval.tspec.tflags = T_ENUM;
	      yyval.tspec.ptr = pEnum;
	    }
	    PSTATE->curEnumList = NULL;
	  ;}
    break;

  case 178:
#line 1288 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.tspec.tflags = 0;
	      yyval.tspec.ptr = NULL;
	    }
	    else {
	      EnumSpecifier *pEnum = HT_get( PSTATE->pCPI->htEnums, yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-3].idOrType.hash );

	      if( pEnum == NULL ) {
	        pEnum = enumspec_new( yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-1].list );
	        pEnum->context = yyvsp[-4].context.ctx;
	        LL_push( PSTATE->pCPI->enums, pEnum );
	        STORE_IN_HASH( htEnums, yyvsp[-3].idOrType, pEnum );
	      }
	      else {
	        DELETE_NODE( yyvsp[-3].idOrType );

	        if( pEnum->enumerators == NULL ) {
	          enumspec_update( pEnum, yyvsp[-1].list );
	          pEnum->context = yyvsp[-4].context.ctx;
	        }
	        else
	          LL_destroy( yyvsp[-1].list, (LLDestroyFunc) enum_delete );
	      }

	      yyval.tspec.tflags = T_ENUM;
	      yyval.tspec.ptr = pEnum;
	    }

	    PSTATE->curEnumList = NULL;
	  ;}
    break;

  case 179:
#line 1320 "ctlib/parser.y"
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

  case 180:
#line 1346 "ctlib/parser.y"
    {
	    yyval.context.ctx.pFI  = PSTATE->pFI;
	    yyval.context.ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 181:
#line 1354 "ctlib/parser.y"
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

  case 182:
#line 1368 "ctlib/parser.y"
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

  case 183:
#line 1384 "ctlib/parser.y"
    {
	    yyval.list = yyvsp[-1].list;
	  ;}
    break;

  case 184:
#line 1391 "ctlib/parser.y"
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

  case 185:
#line 1401 "ctlib/parser.y"
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

  case 190:
#line 1423 "ctlib/parser.y"
    {;}
    break;

  case 191:
#line 1424 "ctlib/parser.y"
    {;}
    break;

  case 192:
#line 1425 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 193:
#line 1426 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 194:
#line 1427 "ctlib/parser.y"
    {;}
    break;

  case 195:
#line 1428 "ctlib/parser.y"
    {;}
    break;

  case 196:
#line 1429 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 197:
#line 1430 "ctlib/parser.y"
    {;}
    break;

  case 198:
#line 1431 "ctlib/parser.y"
    {;}
    break;

  case 199:
#line 1432 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 200:
#line 1433 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 201:
#line 1434 "ctlib/parser.y"
    {;}
    break;

  case 202:
#line 1435 "ctlib/parser.y"
    {;}
    break;

  case 203:
#line 1436 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 204:
#line 1444 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 205:
#line 1445 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 206:
#line 1450 "ctlib/parser.y"
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

  case 207:
#line 1465 "ctlib/parser.y"
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

  case 208:
#line 1481 "ctlib/parser.y"
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

  case 209:
#line 1495 "ctlib/parser.y"
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

  case 210:
#line 1514 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = PSTATE->pCPC->int_size;
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 211:
#line 1521 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
                      PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 216:
#line 1538 "ctlib/parser.y"
    {;}
    break;

  case 224:
#line 1558 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[0].idOrType ); ;}
    break;

  case 231:
#line 1572 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-2].idOrType ); ;}
    break;

  case 249:
#line 1611 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-1].idOrType ); ;}
    break;

  case 259:
#line 1636 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 260:
#line 1637 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 261:
#line 1638 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 262:
#line 1639 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 263:
#line 1640 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 264:
#line 1641 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 265:
#line 1642 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 266:
#line 1643 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 267:
#line 1644 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 268:
#line 1645 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 269:
#line 1647 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 270:
#line 1647 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 271:
#line 1648 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 272:
#line 1648 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 273:
#line 1649 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 274:
#line 1649 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 275:
#line 1650 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 276:
#line 1650 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 277:
#line 1651 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 278:
#line 1651 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 279:
#line 1653 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 280:
#line 1653 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 281:
#line 1654 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 282:
#line 1654 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 283:
#line 1655 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 284:
#line 1655 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 285:
#line 1656 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 286:
#line 1656 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 287:
#line 1657 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 288:
#line 1657 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 289:
#line 1661 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 290:
#line 1662 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 291:
#line 1666 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 292:
#line 1667 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 293:
#line 1672 "ctlib/parser.y"
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

  case 294:
#line 1684 "ctlib/parser.y"
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

  case 295:
#line 1697 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 296:
#line 1704 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 297:
#line 1706 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 298:
#line 1712 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 299:
#line 1720 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 300:
#line 1722 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 301:
#line 1732 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 302:
#line 1734 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 303:
#line 1740 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 304:
#line 1746 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 305:
#line 1752 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 306:
#line 1760 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 307:
#line 1762 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 308:
#line 1767 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 309:
#line 1775 "ctlib/parser.y"
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

  case 310:
#line 1786 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 311:
#line 1790 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 312:
#line 1791 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 313:
#line 1795 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 314:
#line 1797 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 315:
#line 1803 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 316:
#line 1812 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 317:
#line 1816 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 318:
#line 1818 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 319:
#line 1826 "ctlib/parser.y"
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

  case 320:
#line 1838 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 321:
#line 1842 "ctlib/parser.y"
    {;}
    break;

  case 322:
#line 1843 "ctlib/parser.y"
    {;}
    break;

  case 323:
#line 1844 "ctlib/parser.y"
    {;}
    break;

  case 324:
#line 1849 "ctlib/parser.y"
    {
	    if( yyvsp[-3].pDecl )
	      decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  ;}
    break;

  case 325:
#line 1853 "ctlib/parser.y"
    {;}
    break;

  case 326:
#line 1855 "ctlib/parser.y"
    {
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;

  case 327:
#line 1862 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 328:
#line 1863 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 329:
#line 1865 "ctlib/parser.y"
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

  case 330:
#line 1878 "ctlib/parser.y"
    { yyval.list = yyvsp[0].list;   ;}
    break;

  case 331:
#line 1879 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 332:
#line 1880 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 333:
#line 1884 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 334:
#line 1886 "ctlib/parser.y"
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

  case 335:
#line 1900 "ctlib/parser.y"
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

  case 336:
#line 1914 "ctlib/parser.y"
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

  case 337:
#line 1933 "ctlib/parser.y"
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

  case 338:
#line 1955 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 339:
#line 1960 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 340:
#line 1965 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 341:
#line 1970 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 342:
#line 1977 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 343:
#line 1978 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 344:
#line 1980 "ctlib/parser.y"
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

  case 345:
#line 1991 "ctlib/parser.y"
    {
	    yyval.absDecl = yyvsp[-2].absDecl;
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 4470 "ctlib/parser.c"

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


#line 1998 "ctlib/parser.y"



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


