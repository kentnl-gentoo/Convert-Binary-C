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
* $Date: 2002/11/25 12:48:05 +0100 $
* $Revision: 8 $
* $Snapshot: /Convert-Binary-C/0.05 $
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


/*===== TYPEDEFS =============================================================*/

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
#line 355 "ctlib/parser.y"
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
#line 532 "ctlib/parser.c"
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
#line 553 "ctlib/parser.c"

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
#define YYLAST   2224

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  102
/* YYNRULES -- Number of rules. */
#define YYNRULES  321
/* YYNRULES -- Number of states. */
#define YYNSTATES  532

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
     739,   742,   746,   750,   754,   758,   761,   765,   769,   773,
     777,   781,   786,   791,   796,   801,   803,   805,   807,   809,
     811,   814,   816,   818,   821,   825,   829,   834,   836,   841,
     847,   850,   854,   858,   863,   868,   870,   874,   876,   878,
     880,   883,   887,   890,   894,   899,   901,   905,   907,   910,
     914,   919,   923,   928,   930,   932,   934,   936,   939,   943,
     946,   950,   954,   959,   964,   966,   969,   972,   976,   980,
     984,   988
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
     116,    86,    -1,   115,    86,    -1,   119,   178,   151,    -1,
     120,   178,   151,    -1,   115,    70,   178,   151,    -1,   117,
     170,   151,    -1,   118,   170,   151,    -1,   116,    70,   170,
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
      -1,   170,   140,    -1,   141,    -1,   178,   140,    -1,   141,
      -1,    -1,   141,    -1,    84,   112,    -1,    12,    68,   143,
      69,    -1,    12,   149,    68,   143,    69,    -1,    12,   149,
      -1,   144,    -1,   143,    70,   144,    -1,   143,    70,    -1,
     149,    -1,   149,    85,   112,    -1,   146,    -1,   146,    70,
      48,    -1,   147,    -1,   146,    70,   147,    -1,   117,    -1,
     117,   184,    -1,   117,   178,    -1,   117,   172,    -1,   119,
      -1,   119,   184,    -1,   119,   178,    -1,   118,    -1,   118,
     184,    -1,   118,   178,    -1,   118,   172,    -1,   120,    -1,
     120,   184,    -1,   120,   178,    -1,    59,    -1,   148,    70,
      59,    -1,    59,    -1,    62,    -1,   118,    -1,   118,   184,
      -1,   120,    -1,   120,   184,    -1,    -1,    85,   152,    -1,
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
     168,    -1,   167,   168,    -1,   169,    -1,   114,    -1,   178,
     159,    -1,   117,   178,   159,    -1,   118,   178,   159,    -1,
     119,   178,   159,    -1,   120,   178,   159,    -1,   182,   159,
      -1,   117,   182,   159,    -1,   118,   182,   159,    -1,   119,
     182,   159,    -1,   120,   182,   159,    -1,   182,   160,   159,
      -1,   117,   182,   160,   159,    -1,   118,   182,   160,   159,
      -1,   119,   182,   160,   159,    -1,   120,   182,   160,   159,
      -1,   178,    -1,   171,    -1,   175,    -1,   172,    -1,    62,
      -1,    62,   185,    -1,   173,    -1,   174,    -1,    72,   172,
      -1,    72,   120,   172,    -1,    63,   173,    64,    -1,    63,
     173,    64,   185,    -1,   176,    -1,    72,    63,   177,    64,
      -1,    72,   120,    63,   177,    64,    -1,    72,   175,    -1,
      72,   120,   175,    -1,    63,   175,    64,    -1,    63,   177,
     185,    64,    -1,    63,   175,    64,   185,    -1,    62,    -1,
      63,   177,    64,    -1,   179,    -1,   181,    -1,   180,    -1,
      72,   178,    -1,    72,   120,   178,    -1,   181,   185,    -1,
      63,   179,    64,    -1,    63,   179,    64,   185,    -1,    59,
      -1,    63,   181,    64,    -1,   183,    -1,    72,   182,    -1,
      72,   120,   182,    -1,   181,    63,   148,    64,    -1,    63,
     182,    64,    -1,    63,   182,    64,   185,    -1,   187,    -1,
     188,    -1,   185,    -1,   186,    -1,    63,    64,    -1,    63,
     145,    64,    -1,    65,    66,    -1,    65,   109,    66,    -1,
      65,    72,    66,    -1,   186,    65,   109,    66,    -1,   186,
      65,    72,    66,    -1,    72,    -1,    72,   120,    -1,    72,
     184,    -1,    72,   120,   184,    -1,    63,   187,    64,    -1,
      63,   188,    64,    -1,    63,   185,    64,    -1,    63,   187,
      64,   185,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   506,   506,   507,   514,   519,   520,   521,   525,   526,
     527,   528,   529,   529,   530,   530,   531,   532,   533,   534,
     538,   539,   543,   544,   548,   549,   550,   551,   569,   570,
     574,   575,   576,   577,   578,   579,   583,   584,   588,   589,
     591,   598,   608,   609,   611,   616,   617,   619,   624,   625,
     627,   629,   631,   636,   637,   639,   644,   645,   650,   651,
     656,   657,   662,   663,   668,   669,   674,   675,   680,   681,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   699,   700,   704,   709,   710,   748,   749,   750,   751,
     758,   775,   780,   791,   809,   814,   826,   831,   832,   837,
     842,   843,   849,   850,   851,   855,   856,   860,   861,   865,
     866,   867,   871,   872,   873,   874,   878,   879,   880,   881,
     885,   890,   895,   903,   904,   905,   910,   915,   920,   928,
     929,   930,   934,   935,   936,   937,   938,   939,   943,   944,
     945,   946,   947,   948,   949,   950,   951,   955,   956,   960,
     966,   991,  1011,  1012,  1016,  1024,  1032,  1033,  1037,  1047,
    1056,  1067,  1076,  1081,  1089,  1094,  1102,  1103,  1107,  1111,
    1118,  1142,  1162,  1171,  1182,  1189,  1194,  1202,  1203,  1207,
    1208,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1225,  1233,  1234,  1238,  1245,  1254,
    1266,  1283,  1288,  1297,  1298,  1302,  1303,  1304,  1308,  1309,
    1313,  1314,  1318,  1319,  1323,  1324,  1329,  1330,  1331,  1332,
    1333,  1334,  1338,  1339,  1340,  1344,  1345,  1346,  1347,  1351,
    1352,  1356,  1357,  1361,  1365,  1366,  1367,  1371,  1372,  1373,
    1377,  1378,  1379,  1380,  1387,  1388,  1392,  1393,  1397,  1398,
    1402,  1404,  1406,  1408,  1410,  1413,  1414,  1415,  1416,  1417,
    1419,  1420,  1421,  1422,  1423,  1427,  1428,  1432,  1433,  1437,
    1444,  1453,  1460,  1461,  1466,  1474,  1475,  1486,  1487,  1492,
    1497,  1502,  1510,  1511,  1516,  1524,  1531,  1535,  1536,  1540,
    1541,  1546,  1554,  1559,  1560,  1568,  1576,  1580,  1581,  1582,
    1586,  1590,  1591,  1598,  1599,  1600,  1614,  1615,  1616,  1620,
    1621,  1630,  1639,  1653,  1670,  1675,  1680,  1685,  1693,  1694,
    1695,  1706
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
  "function_definition", "declarator", "typedef_declarator", 
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
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   170,   171,   171,   172,
     172,   172,   173,   173,   173,   174,   174,   175,   175,   175,
     175,   175,   176,   176,   176,   177,   177,   178,   178,   179,
     179,   179,   180,   180,   180,   181,   181,   182,   182,   182,
     183,   183,   183,   184,   184,   184,   185,   185,   185,   186,
     186,   186,   186,   186,   187,   187,   187,   187,   188,   188,
     188,   188
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
       2,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     3,     3,     4,     1,     4,     5,
       2,     3,     3,     4,     4,     1,     3,     1,     1,     1,
       2,     3,     2,     3,     4,     1,     3,     1,     2,     3,
       4,     3,     4,     1,     1,     1,     1,     2,     3,     2,
       3,     3,     4,     4,     1,     2,     2,     3,     3,     3,
       3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     244,   135,   143,   138,   152,   141,     0,   136,   132,   139,
     133,   153,   109,   142,   140,   145,   144,   146,   111,   134,
     137,   110,   295,   129,     0,     0,   249,     0,     0,     0,
       0,     0,     0,   105,    96,    99,    97,   100,    98,   101,
     102,   116,   123,   147,     0,   148,     0,   245,   246,   248,
       0,   287,   289,   288,     0,   297,   197,   198,     0,   171,
       0,     0,     0,     0,   290,   298,     0,    89,     0,    88,
     269,     0,     0,   203,   266,   268,   271,   272,   267,   277,
     265,     0,   203,   265,     0,   127,   104,   108,   107,   112,
     120,   203,     0,   130,   106,   103,   117,   124,   203,     0,
     114,   115,   118,   113,   119,    86,   122,    87,   125,   121,
     128,   131,   126,     0,   151,     1,   247,    84,   250,     0,
       0,   292,   306,   229,     0,     0,     0,     0,   255,     0,
       0,   172,   175,     0,   293,   296,   301,   291,   299,     0,
       0,   203,   288,     0,     0,   203,   265,     0,   270,   285,
       0,     0,     0,     0,     0,     0,   273,   280,     0,    93,
     251,   256,     0,    94,   252,   257,     0,    90,   253,   258,
       0,    91,   254,   259,     0,     0,     0,    99,   100,   101,
       0,   154,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     4,
       2,     5,   129,     0,   225,    30,    31,    32,    33,    34,
      35,     6,     8,    24,    36,     0,    38,    42,    45,    48,
      53,    56,    58,    60,    62,    64,    66,    68,    81,    85,
       0,     0,   231,   216,   217,    84,    84,   218,   219,   220,
     221,   195,   307,   181,   188,   185,   192,    97,   100,     0,
     177,   179,     0,     4,   309,    31,     0,     0,   203,   203,
     230,   260,   169,   174,     0,     0,   294,   302,     0,     0,
      92,     0,     0,     0,    95,     0,   275,   282,     0,     0,
       0,   274,   281,   210,   207,   204,   261,   262,   263,   264,
       0,   160,   163,   166,   158,   165,   166,   149,   155,     0,
     157,     0,   156,     0,   242,     0,    36,    83,     0,     0,
     241,    84,    84,     0,     0,    28,     0,     0,     0,     0,
      25,    26,     0,   199,   201,     0,     3,    16,    17,     0,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    70,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,    84,   226,    84,
     227,   232,     0,   314,   184,   183,   182,   305,   303,   304,
     191,   190,   189,     0,   314,   187,   186,   194,   193,   308,
       0,   300,     0,   311,   310,    31,     0,   173,   176,   170,
       0,   286,   276,   284,   283,   278,     0,     0,     0,     0,
       0,     0,   212,   168,   162,   167,   164,   159,   161,   150,
       0,    84,   243,     0,   224,   240,     0,     0,     0,     0,
       0,     7,     0,   314,   200,   202,     0,    10,     0,    22,
       0,     0,     0,    69,    39,    40,    41,    43,    44,    46,
      47,    51,    52,    49,    50,    54,    55,    57,    59,    61,
      63,    65,     0,    82,   222,   228,     0,     0,     0,   315,
     316,   315,   178,   180,   196,   313,   312,   279,     0,   215,
     205,   210,   208,   211,   213,    84,   223,    84,    29,     0,
      84,    84,     0,   315,   210,    37,    11,     0,     9,    20,
      21,    13,    15,     0,   320,   318,   319,   317,   214,   206,
       0,   236,     0,     0,   234,   237,     0,    23,    67,   321,
     209,    84,     0,    84,    18,   210,     0,   238,   235,    19,
      84,   239
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   211,   212,   213,   331,   332,   501,   438,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   344,   229,   308,   230,   123,    27,    28,
     124,   125,   126,   127,    86,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   180,   181,   182,
     183,   291,   294,   414,   292,    45,   130,   131,   249,   250,
     251,   252,   231,   325,   167,   285,   409,   410,   411,   412,
     232,   233,   234,   129,   236,   237,   238,   239,   240,    46,
      47,    48,    49,    73,    74,    75,    76,    77,   152,    79,
     153,    64,    51,    52,   142,    62,    55,   470,   377,   122,
     378,   379
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -477
static const short yypact[] =
{
    1520,  -477,  -477,  -477,  -477,  -477,   115,  -477,  -477,  -477,
    -477,  -477,  -477,  -477,  -477,  -477,  -477,  -477,  -477,  -477,
    -477,  -477,  -477,  -477,   161,   714,  -477,   -12,     2,   253,
     253,  1555,  1590,  -477,  2188,  2188,   544,   663,   771,   771,
    -477,  -477,  -477,  -477,   268,  -477,     3,  1520,  -477,  -477,
     -43,  -477,  -477,   138,  1750,  -477,  -477,  -477,   173,   -35,
      -2,   434,    47,   714,  -477,  -477,   179,  -477,   364,  -477,
     205,   384,   402,    -3,  -477,  -477,  -477,  -477,  -477,  -477,
     -43,  1750,    -3,   -43,  1750,  -477,  -477,  -477,  -477,  -477,
    -477,   -47,  1750,  -477,  -477,  -477,  -477,  -477,   -47,  1750,
    -477,  -477,  -477,  -477,  -477,  -477,  -477,  -477,  -477,  -477,
    -477,  -477,  -477,   987,    52,  -477,  -477,   812,  -477,  1856,
    1931,  -477,    50,  -477,   364,   364,  1625,  1660,  -477,  1750,
      93,  -477,    57,   173,   205,  -477,   205,  -477,  -477,   179,
     733,    -3,   205,   456,   596,    -3,  -477,  1891,  -477,  -477,
     384,    66,   116,   205,   384,   644,  -477,  -477,  1957,  -477,
    -477,  -477,  1750,  -477,  -477,  -477,  1750,  -477,  -477,  -477,
    1750,  -477,  -477,  -477,  1750,    38,   736,  1050,   118,   118,
    1783,  -477,    23,    79,   987,    99,   159,  2036,  2036,   171,
     212,   213,   173,  2062,  1254,   239,   243,  2088,  2088,   235,
    -477,  -477,   240,   959,  -477,  -477,  -477,  -477,  -477,  -477,
    -477,   275,  -477,   623,   809,  2036,  -477,   269,   265,   437,
      12,   305,   283,   281,   293,   333,   -38,  -477,  -477,   317,
     304,   308,  -477,  -477,  -477,   886,  1029,  -477,  -477,  -477,
    -477,  -477,  -477,   309,   309,  1328,  1392,   771,   771,   331,
     341,  -477,    48,  -477,  -477,   352,   354,  2114,    -3,    -3,
    -477,  -477,  -477,   173,  2036,   413,  -477,  -477,   518,   733,
    -477,   456,   456,   664,  -477,   534,   205,   205,   369,   545,
     384,  -477,  -477,   221,  -477,  -477,  -477,  -477,  -477,  -477,
    2036,  -477,  -477,   344,  -477,  -477,   344,  -477,  -477,   233,
    -477,    38,  -477,  1811,  -477,  2036,  -477,  -477,   357,   374,
    -477,  2036,  1254,   381,   959,  -477,   416,  2036,  2036,   959,
    -477,  -477,    74,   193,  1695,   406,  -477,  -477,  -477,  1983,
    2036,   447,   454,  -477,  -477,  -477,  -477,  -477,  -477,  -477,
    -477,  -477,  -477,  -477,  2036,  -477,  2036,  2036,  2036,  2036,
    2036,  2036,  2036,  2036,  2036,  2036,  2036,  2036,  2036,  2036,
    2036,  2036,  2036,  2036,  2036,  2036,  -477,  1254,  -477,  1099,
    -477,  -477,  1173,   372,  -477,  -477,  -477,  -477,  -477,  -477,
    -477,  -477,  -477,  1237,   471,  -477,  -477,  -477,  -477,  -477,
    1926,  -477,   457,  -477,  -477,   461,   469,  -477,  -477,  -477,
     456,  -477,  -477,  -477,  -477,  -477,   553,  2036,   173,   418,
    1957,    49,  -477,  -477,  -477,  -477,  -477,  -477,  -477,  -477,
     141,  1254,  -477,   462,  -477,  -477,   478,   486,   223,   256,
     490,  -477,  1456,   531,  -477,  -477,  2010,  -477,   294,  -477,
     184,   236,   236,  -477,  -477,  -477,  -477,   269,   269,   265,
     265,   437,   437,   437,   437,    12,    12,   305,   283,   281,
     293,   333,    24,  -477,  -477,  -477,   492,   498,   501,   372,
    -477,   471,  -477,  -477,  -477,  -477,  -477,  -477,   500,  -477,
    -477,    18,  -477,  -477,  -477,  1254,  -477,  2036,   502,  2036,
    1254,  1254,   502,   531,   221,  -477,  -477,  2036,  -477,  -477,
    -477,  -477,  -477,  2036,  -477,   205,  -477,  -477,  -477,  -477,
    1957,  -477,   483,   343,   564,  -477,   424,  -477,  -477,  -477,
    -477,  2036,   487,  1254,  -477,   311,   521,  -477,  -477,  -477,
    1254,  -477
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -477,  -477,  -477,  -477,  -477,  -477,   144,  -477,   288,  -477,
     -63,   182,   187,   167,   188,   234,   244,   246,   249,   232,
    -477,  -159,   -55,  -477,  -123,  -223,  -178,   367,  -477,  -477,
      13,    34,    22,    26,   -30,   -20,  -477,   -67,   -69,   181,
    -477,   273,   474,   155,    45,  -477,  -477,   421,  -160,  -477,
    -477,   313,   320,   316,  -132,  -477,   488,   361,  -477,  -477,
     230,  -477,    17,  -277,   -46,  -408,   131,  -476,  -477,   217,
    -108,  -477,   573,   -28,   394,  -477,  -477,  -477,  -477,  -477,
    -477,   586,  -477,   -29,  -477,   -65,   117,  -477,   400,  -477,
      62,     0,    80,  -477,   168,   559,  -477,    33,   -13,  -477,
    -348,  -313
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -199
static const short yytable[] =
{
      50,    82,   482,   115,   100,   510,   106,   156,   110,   363,
     309,    87,    94,    29,    87,   102,    87,   108,    87,   111,
     298,   117,    31,    59,   467,   117,    32,   159,   307,    80,
      83,    91,    98,   133,    30,   467,   163,   426,   158,   145,
     121,   398,   430,    94,   295,   364,   177,    50,   121,   510,
     247,    63,   171,   162,   353,   354,   166,   148,    66,   468,
      29,   114,   134,   137,   170,   256,   141,   413,   146,    31,
     468,   174,    68,    32,    67,   132,    90,    97,   247,   156,
     322,    30,   158,   407,   467,   408,   316,   509,    69,   235,
     281,   355,   356,   299,   365,   270,    82,    22,   155,   274,
      70,   143,   520,   284,    60,   307,    87,    94,   503,   300,
     144,   136,   391,   177,   407,   257,   408,   177,   392,   468,
     184,   266,   290,   267,   146,   146,   258,   259,   371,   121,
     276,   307,   243,   423,   483,    94,   177,    12,   431,   176,
     278,   245,   264,   298,   365,   246,   293,   175,    18,   301,
     132,    60,   345,   244,    21,   137,    94,   102,   108,   111,
     243,   415,   262,   263,   415,   302,   269,   295,    53,   245,
     273,    90,    97,   246,    56,   146,   296,    57,   374,   380,
     277,   244,   420,    58,   478,   304,    89,    96,   151,   101,
     104,   322,    61,    53,   428,   429,   322,    53,    53,    53,
      53,   119,   396,   120,   424,   485,   176,   440,   281,   313,
     176,   365,   275,   171,   175,    53,   279,   106,   175,    60,
      22,    97,   305,    60,    24,    87,    94,    87,   108,   324,
      60,    53,    56,    25,    60,    57,   177,   323,    22,    61,
      53,   462,   139,   375,   381,   385,   387,   177,   307,    94,
     498,   140,   177,    94,   365,   121,   432,   310,   120,   464,
     151,   371,   278,   402,   403,   433,   278,   151,   147,   137,
     120,   151,   293,   137,   439,   311,   376,   382,   386,   388,
     132,    89,    96,   444,   445,   446,   407,   490,   408,   443,
      90,    97,    22,   365,   178,   499,   139,   312,   500,   296,
     248,   146,   317,   247,    94,   140,   318,   268,   156,   512,
     463,   268,    22,   486,   247,    70,    71,   290,    61,  -197,
     491,   247,    61,    53,  -198,    72,   365,    56,   248,   176,
      57,    96,   104,   275,   279,   326,   113,   175,   349,   350,
     324,   346,   406,   526,   518,   324,   347,   348,   323,   357,
     358,    60,    60,   323,   359,   284,   434,   435,   496,   466,
      60,   178,   360,   247,   497,   178,   513,    26,    22,    97,
     466,    70,   372,   495,   120,   361,   407,   511,   408,   362,
     529,   373,   514,   515,   178,   243,   179,   365,   151,   151,
     366,    12,   367,   278,   245,   389,   243,   151,   246,   469,
      89,    96,    18,   243,   281,   245,   244,   522,    21,   246,
     471,   390,   245,   365,    26,   528,   246,   244,   393,   466,
     394,    12,   531,    22,   244,   479,    70,   143,   290,    78,
      78,    22,    18,   404,    70,   372,   144,   120,    21,   268,
     268,   421,   517,    22,   373,   243,   149,   150,    61,    94,
     427,    94,    60,   179,   245,   284,    72,   179,   246,   493,
     422,    22,   406,    60,    70,   154,   244,   425,    78,   137,
     436,   137,   157,    94,    72,   306,   179,   351,   352,    96,
      60,   315,   399,   263,   178,   320,   321,   480,   481,   151,
      12,   442,   519,   524,   525,   178,   260,   119,   135,   120,
     178,    18,   507,   306,   507,    88,    95,    21,    88,   103,
      88,   109,    88,   112,   441,    22,   474,   151,   149,   271,
     451,   452,   453,   454,    78,    78,   507,   475,   144,   260,
      22,   447,   448,   260,   383,   476,   120,   260,   449,   450,
     268,   260,   488,   384,   157,   455,   456,     1,   487,   489,
      12,   268,   306,   248,   492,   282,   504,     7,     8,    54,
      10,    18,   505,    12,   248,   506,   508,    21,   268,   521,
     494,   248,   523,   527,    18,    78,   179,    19,   306,    20,
      21,   147,   135,   120,    65,   530,   502,   179,    81,    84,
      92,    99,   179,   457,   432,   461,   120,   147,   401,   120,
      88,    95,   260,   433,   458,   303,    54,   459,   147,   405,
     120,   460,   416,   248,   418,    12,   147,   477,   120,   417,
     473,   265,   138,   118,   397,   516,    18,   128,   484,   369,
     105,    65,    21,   116,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,     0,   160,   161,    22,   164,   165,    70,   272,
     -14,   327,   328,    12,   168,   169,     1,     0,   144,     0,
       0,   172,   173,   282,    18,     0,     7,     8,     0,    10,
      21,     0,    12,    12,     0,     0,   329,     0,   330,     0,
     -12,     0,     0,    18,    18,   306,    19,     0,    20,    21,
      21,    78,   261,    22,     0,     0,    70,   280,     0,     0,
       0,     0,     0,     0,   138,     0,    72,     0,     0,    88,
      95,    88,   109,    22,   306,     0,    70,   400,     0,     0,
       0,     0,     0,    12,     0,   286,   144,     0,     0,   287,
       2,     3,     4,   288,    18,     5,     0,   289,     6,   107,
      21,     9,    12,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,    18,     0,     0,    18,     0,     0,    21,
       0,     0,    21,    22,     1,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     7,     8,    25,    10,     0,     0,
      12,   306,    22,     0,     0,    22,   139,     0,    93,   139,
       0,    18,     0,     0,    19,   140,    20,    21,   140,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,   185,
     290,     5,   186,   187,     6,     7,     8,     9,    10,   188,
      11,    12,    13,    14,    15,   189,   190,    16,    17,   191,
     192,   193,    18,   194,   195,    19,   196,    20,    21,     0,
     197,   198,     0,     0,     0,     0,     0,     0,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,     0,     0,
       0,   199,   200,   201,   202,   203,     0,     0,     0,     0,
     117,   204,     0,   205,   206,   207,   208,   209,   210,     1,
       2,     3,     4,   185,   343,     5,   186,   187,     6,     7,
       8,     9,    10,   188,    11,    12,    13,    14,    15,   189,
     190,    16,    17,   191,   192,   193,    18,   194,   195,    19,
     196,    20,    21,     0,   197,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   200,   201,   202,   203,
       0,     0,     0,     0,   117,   368,     0,   205,   206,   207,
     208,   209,   210,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     9,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,   193,    18,
       0,     2,     3,     4,     0,    21,     5,   197,   198,     6,
       0,     0,     9,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,   253,   200,
     201,    23,   203,    21,     0,     0,     0,     0,     0,     0,
     205,   206,   207,   208,   209,   210,   185,     0,     0,   186,
     187,     0,     0,     0,     0,     0,   188,     0,     0,    23,
       0,     0,   189,   190,     2,     3,   191,   192,   193,     5,
     194,   195,     0,   196,     0,     9,     0,   197,   198,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    21,     0,   199,   200,
     201,    57,   203,     0,     0,     0,     0,   117,   370,     0,
     205,   206,   207,   208,   209,   210,   185,     0,     0,   186,
     187,     0,     0,     0,     0,     0,   188,     0,     0,     0,
       0,     0,   189,   190,     0,     0,   191,   192,   193,     0,
     194,   195,     0,   196,     0,     0,     0,   197,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   200,
     201,    57,   203,     0,     0,     0,     0,   117,   465,     0,
     205,   206,   207,   208,   209,   210,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,     0,    18,     0,     0,    19,     0,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,    23,   372,   242,   120,     0,
       1,     2,     3,     4,     0,   373,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,   185,    16,    17,   186,   187,     0,    18,     0,     0,
      19,   188,    20,    21,     0,     0,     0,   189,   190,     0,
       0,   191,   192,   193,     0,   194,   195,     0,   196,     0,
       0,     0,   197,   198,     0,     0,    22,     0,     0,    23,
     383,   242,   120,     0,     0,     0,     0,     0,     0,   384,
       0,     0,     0,   199,   200,   201,    57,   203,     0,     0,
       0,     0,   117,     0,     0,   205,   206,   207,   208,   209,
     210,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,    19,     0,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,     0,
      85,   383,     0,   120,     0,     1,     2,     3,     4,     0,
     384,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,     0,    18,     0,     0,    19,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,    93,   383,     0,   120,     0,     1,
       2,     3,     4,     0,   384,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,   432,
     242,   120,     0,     1,     2,     3,     4,     0,   433,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,    20,    21,     0,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,    22,
      16,    17,    23,    24,     0,    18,     0,     0,    19,     0,
      20,    21,    25,     1,     2,     3,     4,     0,     0,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,    22,    16,    17,    85,    24,     0,
      18,     0,     0,    19,     0,    20,    21,    25,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,    22,
      16,    17,    93,    24,     0,    18,     0,     0,    19,     0,
      20,    21,    25,     1,     2,     3,     4,     0,     0,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,    22,    16,    17,    85,   139,     0,
      18,     0,     0,    19,     0,    20,    21,   140,     0,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       9,     0,     0,    11,    12,    13,    14,    15,     0,    22,
      16,    17,    93,   139,     0,    18,     0,     0,     0,     0,
       0,    21,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,    93,   432,     5,
     120,     0,     6,     7,     8,     9,    10,   433,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,    20,    21,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     0,     0,     9,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,    23,    18,     0,     2,     3,     4,   117,    21,
       5,     0,     0,     6,     0,     0,     9,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,     0,     0,     0,    23,     0,    21,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,    23,    11,    12,    13,    14,    15,     0,
     419,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21,     0,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,   241,    16,    17,    23,     0,
     242,    18,     0,     0,    19,     0,    20,    21,     0,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,    23,     0,   242,    18,     0,     0,    19,
     193,    20,    21,     0,     0,     0,     0,     0,     0,   197,
     198,     0,     0,     0,   472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,     0,    23,     0,
     253,   200,   201,     0,   203,   197,   198,   254,     0,     0,
       0,     0,   205,   255,   207,   208,   209,   210,     0,     0,
       0,     0,   193,     0,     0,     0,   253,   200,   201,     0,
     203,   197,   198,     0,     0,   283,     0,     0,   205,   206,
     207,   208,   209,   210,     0,     0,     0,     0,     0,   193,
       0,     0,   253,   200,   201,     0,   203,   437,   197,   198,
       0,     0,     0,     0,   205,   206,   207,   208,   209,   210,
       0,     0,     0,     0,     0,   193,     0,     0,     0,   253,
     200,   201,     0,   203,   197,   198,     0,     0,   494,     0,
       0,   205,   206,   207,   208,   209,   210,     0,     0,     0,
       0,   193,     0,     0,     0,   253,   200,   201,     0,   203,
     197,   198,     0,     0,     0,     0,     0,   205,   206,   207,
     208,   209,   210,     0,     0,     0,     0,   193,     0,     0,
       0,   253,   200,   201,     0,   314,   197,   198,     0,     0,
       0,     0,     0,   205,   206,   207,   208,   209,   210,     0,
       0,     0,     0,   193,     0,     0,     0,   253,   200,   201,
       0,   319,   197,   198,     0,     0,     0,     0,     0,   205,
     206,   207,   208,   209,   210,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   200,   201,     0,   203,     0,     0,
       0,     0,     0,     0,     0,   205,   395,   207,   208,   209,
     210,     1,     2,     3,     0,     0,     0,     5,     0,     0,
       0,     7,     8,     9,    10,     0,     0,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,    19,     0,    20,    21
};

static const short yycheck[] =
{
       0,    30,   410,     0,    34,   481,    36,    72,    38,    47,
     188,    31,    32,     0,    34,    35,    36,    37,    38,    39,
     180,    68,     0,     6,   372,    68,     0,    73,   187,    29,
      30,    31,    32,    68,     0,   383,    82,   314,    85,    68,
      53,   264,   319,    63,   176,    83,   113,    47,    61,   525,
     119,    25,    98,    81,    42,    43,    84,    70,    70,   372,
      47,    44,    64,    63,    92,   120,    66,   290,    68,    47,
     383,    99,    70,    47,    86,    58,    31,    32,   147,   144,
     203,    47,    85,    65,   432,    67,   194,    69,    86,   117,
     155,    79,    80,    70,    70,   141,   125,    59,    72,   145,
      62,    63,   510,   158,    24,   264,   126,   127,    84,    86,
      72,    64,    64,   180,    65,    65,    67,   184,    70,   432,
      68,   134,    84,   136,   124,   125,   126,   127,   236,   142,
      64,   290,   119,   311,    85,   155,   203,    19,    64,   113,
     153,   119,    85,   303,    70,   119,   175,   113,    30,    70,
     133,    71,   215,   119,    36,   155,   176,   177,   178,   179,
     147,   293,    69,    70,   296,    86,   140,   299,     0,   147,
     144,   126,   127,   147,    59,   175,   176,    62,   243,   244,
      64,   147,   305,    68,   407,    86,    31,    32,    71,    34,
      35,   314,    24,    25,   317,   318,   319,    29,    30,    31,
      32,    63,   257,    65,   312,    64,   180,   330,   273,   192,
     184,    70,   150,   259,   180,    47,   154,   247,   184,   139,
      59,   176,    63,   143,    63,   245,   246,   247,   248,   203,
     150,    63,    59,    72,   154,    62,   303,   203,    59,    71,
      72,   364,    63,   243,   244,   245,   246,   314,   407,   269,
      66,    72,   319,   273,    70,   268,    63,    86,    65,   367,
     143,   369,   275,   276,   277,    72,   279,   150,    63,   269,
      65,   154,   301,   273,   329,    63,   243,   244,   245,   246,
     263,   126,   127,   346,   347,   348,    65,    64,    67,   344,
     245,   246,    59,    70,   113,    59,    63,    84,    62,   299,
     119,   301,    63,   372,   324,    72,    63,   139,   373,   487,
     365,   143,    59,   421,   383,    62,    63,    84,   150,    84,
      64,   390,   154,   155,    84,    72,    70,    59,   147,   303,
      62,   176,   177,   271,   272,    60,    68,   303,    73,    74,
     314,    72,   280,   521,   503,   319,    77,    78,   314,    44,
      45,   271,   272,   319,    71,   410,   323,   324,    64,   372,
     280,   180,    81,   432,    70,   184,   489,     0,    59,   324,
     383,    62,    63,   436,    65,    82,    65,   485,    67,    46,
      69,    72,   490,   491,   203,   372,   113,    70,   271,   272,
      86,    19,    84,   406,   372,    64,   383,   280,   372,   373,
     245,   246,    30,   390,   469,   383,   372,    64,    36,   383,
     384,    70,   390,    70,    47,   523,   390,   383,    66,   432,
      66,    19,   530,    59,   390,   408,    62,    63,    84,    29,
      30,    59,    30,    64,    62,    63,    72,    65,    36,   271,
     272,    84,   497,    59,    72,   432,    62,    63,   280,   469,
      34,   471,   372,   180,   432,   510,    72,   184,   432,   433,
      86,    59,   400,   383,    62,    63,   432,    86,    68,   469,
      64,   471,    72,   493,    72,   187,   203,    40,    41,   324,
     400,   193,    69,    70,   303,   197,   198,    69,    70,   372,
      19,    37,   505,    69,    70,   314,   129,    63,    64,    65,
     319,    30,   469,   215,   471,    31,    32,    36,    34,    35,
      36,    37,    38,    39,    67,    59,    59,   400,    62,    63,
     353,   354,   355,   356,   124,   125,   493,    66,    72,   162,
      59,   349,   350,   166,    63,    66,    65,   170,   351,   352,
     372,   174,    64,    72,   144,   357,   358,     3,    86,    63,
      19,   383,   264,   372,    64,   155,    64,    13,    14,     0,
      16,    30,    64,    19,   383,    64,    66,    36,   400,    86,
      68,   390,     8,    86,    30,   175,   303,    33,   290,    35,
      36,    63,    64,    65,    25,    64,   442,   314,    29,    30,
      31,    32,   319,   359,    63,   363,    65,    63,    64,    65,
     126,   127,   235,    72,   360,   184,    47,   361,    63,    64,
      65,   362,   296,   432,   301,    19,    63,    64,    65,   299,
     390,   133,    63,    50,   263,   494,    30,    54,   411,   235,
      86,    72,    36,    47,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    80,    81,    59,    83,    84,    62,    63,
      37,    38,    39,    19,    91,    92,     3,    -1,    72,    -1,
      -1,    98,    99,   273,    30,    -1,    13,    14,    -1,    16,
      36,    -1,    19,    19,    -1,    -1,    63,    -1,    65,    -1,
      67,    -1,    -1,    30,    30,   407,    33,    -1,    35,    36,
      36,   301,   129,    59,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,    72,    -1,    -1,   245,
     246,   247,   248,    59,   436,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    19,    -1,   162,    72,    -1,    -1,   166,
       4,     5,     6,   170,    30,     9,    -1,   174,    12,    86,
      36,    15,    19,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    30,    -1,    -1,    30,    -1,    -1,    36,
      -1,    -1,    36,    59,     3,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    72,    16,    -1,    -1,
      19,   503,    59,    -1,    -1,    59,    63,    -1,    62,    63,
      -1,    30,    -1,    -1,    33,    72,    35,    36,    72,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      84,     9,    10,    11,    12,    13,    14,    15,    16,    17,
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
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    30,
      -1,     4,     5,     6,    -1,    36,     9,    38,    39,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    59,    60,
      61,    62,    63,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,     7,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    62,
      -1,    -1,    23,    24,     4,     5,    27,    28,    29,     9,
      31,    32,    -1,    34,    -1,    15,    -1,    38,    39,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,     7,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    62,    63,    64,    65,    -1,
       3,     4,     5,     6,    -1,    72,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,     7,    25,    26,    10,    11,    -1,    30,    -1,    -1,
      33,    17,    35,    36,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,    -1,    -1,    59,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,    75,
      76,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      62,    63,    -1,    65,    -1,     3,     4,     5,     6,    -1,
      72,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    62,    63,    -1,    65,    -1,     3,
       4,     5,     6,    -1,    72,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,     3,     4,     5,     6,    -1,    72,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    59,
      25,    26,    62,    63,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    72,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    59,    25,    26,    62,    63,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    72,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    59,
      25,    26,    62,    63,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    72,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    59,    25,    26,    62,    63,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    72,    -1,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    59,
      25,    26,    62,    63,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    62,    63,     9,
      65,    -1,    12,    13,    14,    15,    16,    72,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    62,    30,    -1,     4,     5,     6,    68,    36,
       9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    62,    -1,    36,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    62,    18,    19,    20,    21,    22,    -1,
      69,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    59,    25,    26,    62,    -1,
      64,    30,    -1,    -1,    33,    -1,    35,    36,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    62,    -1,    64,    30,    -1,    -1,    33,
      29,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    62,    -1,
      59,    60,    61,    -1,    63,    38,    39,    66,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    59,    60,    61,    -1,
      63,    38,    39,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    59,    60,    61,    -1,    63,    64,    38,    39,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    59,
      60,    61,    -1,    63,    38,    39,    -1,    -1,    68,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    59,    60,    61,    -1,    63,
      38,    39,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    59,    60,    61,    -1,    63,    38,    39,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    59,    60,    61,
      -1,    63,    38,    39,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,     3,     4,     5,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36
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
     178,   179,   180,   181,   182,   183,    59,    62,    68,   149,
     179,   181,   182,   120,   178,   182,    70,    86,    70,    86,
      62,    63,    72,   170,   171,   172,   173,   174,   175,   176,
     178,   182,   170,   178,   182,    62,   121,   122,   129,   130,
     131,   178,   182,    62,   122,   129,   130,   131,   178,   182,
     121,   130,   122,   129,   130,    86,   121,    86,   122,   129,
     121,   122,   129,    68,   149,     0,   168,    68,   159,    63,
      65,   185,   186,   114,   117,   118,   119,   120,   159,   160,
     143,   144,   149,    68,    64,    64,    64,   178,   182,    63,
      72,   178,   181,    63,    72,   170,   178,    63,   185,    62,
      63,   173,   175,   177,    63,   120,   172,   175,    85,   151,
     159,   159,   160,   151,   159,   159,   160,   151,   159,   159,
     160,   151,   159,   159,   160,   118,   120,   124,   126,   128,
     134,   135,   136,   137,    68,     7,    10,    11,    17,    23,
      24,    27,    28,    29,    31,    32,    34,    38,    39,    59,
      60,    61,    62,    63,    69,    71,    72,    73,    74,    75,
      76,    88,    89,    90,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   111,
     113,   149,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    59,    64,   117,   118,   119,   120,   125,   126,   145,
     146,   147,   148,    59,    66,    72,   109,    65,   178,   178,
     114,   159,    69,    70,    85,   143,   185,   185,   181,   120,
     151,    63,    63,   120,   151,   177,    64,    64,   185,   177,
      63,   172,   175,    68,   109,   152,   159,   159,   159,   159,
      84,   138,   141,   170,   139,   141,   178,    69,   135,    70,
      86,    70,    86,   134,    86,    63,    95,   108,   112,   113,
      86,    63,    84,   149,    63,    95,   157,    63,    63,    63,
      95,    95,   111,   118,   120,   150,    60,    38,    39,    63,
      65,    91,    92,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    85,   110,    97,    72,    77,    78,    73,
      74,    40,    41,    42,    43,    79,    80,    44,    45,    71,
      81,    82,    46,    47,    83,    70,    86,    84,    69,   161,
      69,   157,    63,    72,   172,   178,   184,   185,   187,   188,
     172,   178,   184,    63,    72,   178,   184,   178,   184,    64,
      70,    64,    70,    66,    66,    72,   109,   144,   112,    69,
      63,    64,   185,   185,    64,    64,   177,    65,    67,   153,
     154,   155,   156,   112,   140,   141,   140,   139,   138,    69,
     111,    84,    86,   113,   157,    86,   150,    34,   111,   111,
     150,    64,    63,    72,   184,   184,    64,    64,    94,   109,
     111,    67,    37,   109,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   100,   101,   101,   102,   103,   104,
     105,   106,   111,   109,   157,    69,   185,   187,   188,   120,
     184,   120,    48,   147,    59,    66,    66,    64,   112,   149,
      69,    70,   152,    85,   156,    64,   157,    86,    64,    63,
      64,    64,    64,   120,    68,    97,    64,    70,    66,    59,
      62,    93,    93,    84,    64,    64,    64,   184,    66,    69,
     154,   157,   113,   111,   157,   157,   153,   109,   108,   185,
     152,    86,    64,     8,    69,    70,   113,    86,   157,    69,
      64,   157
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
#line 506 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 3:
#line 508 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-1].value, +, yyvsp[0].value ); }
    break;

  case 4:
#line 515 "ctlib/parser.y"
    {
	    HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    UNDEF_VAL( yyval.value );
	  }
    break;

  case 5:
#line 519 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 6:
#line 520 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.iv++; }
    break;

  case 7:
#line 521 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; }
    break;

  case 8:
#line 525 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 9:
#line 526 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 10:
#line 527 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 11:
#line 528 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 12:
#line 529 "ctlib/parser.y"
    {}
    break;

  case 13:
#line 529 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 14:
#line 530 "ctlib/parser.y"
    {}
    break;

  case 15:
#line 530 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 16:
#line 531 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 17:
#line 532 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 18:
#line 533 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 19:
#line 534 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 20:
#line 538 "ctlib/parser.y"
    { HN_delete( EX_NODE( yyvsp[0].identifier ) ); }
    break;

  case 21:
#line 539 "ctlib/parser.y"
    {}
    break;

  case 22:
#line 543 "ctlib/parser.y"
    {}
    break;

  case 23:
#line 544 "ctlib/parser.y"
    {}
    break;

  case 24:
#line 548 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 25:
#line 549 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 26:
#line 550 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 27:
#line 552 "ctlib/parser.y"
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
#line 569 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 29:
#line 570 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; }
    break;

  case 30:
#line 574 "ctlib/parser.y"
    { yyval.oper = '&'; }
    break;

  case 31:
#line 575 "ctlib/parser.y"
    { yyval.oper = '*'; }
    break;

  case 32:
#line 576 "ctlib/parser.y"
    { yyval.oper = '+'; }
    break;

  case 33:
#line 577 "ctlib/parser.y"
    { yyval.oper = '-'; }
    break;

  case 34:
#line 578 "ctlib/parser.y"
    { yyval.oper = '~'; }
    break;

  case 35:
#line 579 "ctlib/parser.y"
    { yyval.oper = '!'; }
    break;

  case 36:
#line 583 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 37:
#line 584 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_CAST; }
    break;

  case 38:
#line 588 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 39:
#line 590 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, *, yyvsp[0].value ); }
    break;

  case 40:
#line 592 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, /, yyvsp[0].value );
	  }
    break;

  case 41:
#line 599 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, %, yyvsp[0].value );
	  }
    break;

  case 42:
#line 608 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 43:
#line 610 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, +, yyvsp[0].value ); }
    break;

  case 44:
#line 612 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, -, yyvsp[0].value ); }
    break;

  case 45:
#line 616 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 46:
#line 618 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <<, yyvsp[0].value ); }
    break;

  case 47:
#line 620 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >>, yyvsp[0].value ); }
    break;

  case 48:
#line 624 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 49:
#line 626 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <,  yyvsp[0].value ); }
    break;

  case 50:
#line 628 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >,  yyvsp[0].value ); }
    break;

  case 51:
#line 630 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <=, yyvsp[0].value ); }
    break;

  case 52:
#line 632 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >=, yyvsp[0].value ); }
    break;

  case 53:
#line 636 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 54:
#line 638 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ==, yyvsp[0].value ); }
    break;

  case 55:
#line 640 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, !=, yyvsp[0].value ); }
    break;

  case 56:
#line 644 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 57:
#line 646 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &, yyvsp[0].value ); }
    break;

  case 58:
#line 650 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 59:
#line 652 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ^, yyvsp[0].value ); }
    break;

  case 60:
#line 656 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 61:
#line 658 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, |, yyvsp[0].value ); }
    break;

  case 62:
#line 662 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 63:
#line 664 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &&, yyvsp[0].value ); }
    break;

  case 64:
#line 668 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 65:
#line 670 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ||, yyvsp[0].value ); }
    break;

  case 66:
#line 674 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 67:
#line 676 "ctlib/parser.y"
    { yyval.value = yyvsp[-4].value.iv ? yyvsp[-2].value : yyvsp[0].value; yyval.value.flags |= yyvsp[-4].value.flags; }
    break;

  case 68:
#line 680 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 69:
#line 681 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); }
    break;

  case 70:
#line 685 "ctlib/parser.y"
    {}
    break;

  case 71:
#line 686 "ctlib/parser.y"
    {}
    break;

  case 72:
#line 687 "ctlib/parser.y"
    {}
    break;

  case 73:
#line 688 "ctlib/parser.y"
    {}
    break;

  case 74:
#line 689 "ctlib/parser.y"
    {}
    break;

  case 75:
#line 690 "ctlib/parser.y"
    {}
    break;

  case 76:
#line 691 "ctlib/parser.y"
    {}
    break;

  case 77:
#line 692 "ctlib/parser.y"
    {}
    break;

  case 78:
#line 693 "ctlib/parser.y"
    {}
    break;

  case 79:
#line 694 "ctlib/parser.y"
    {}
    break;

  case 80:
#line 695 "ctlib/parser.y"
    {}
    break;

  case 81:
#line 699 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 82:
#line 700 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 83:
#line 704 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; }
    break;

  case 85:
#line 710 "ctlib/parser.y"
    {}
    break;

  case 86:
#line 748 "ctlib/parser.y"
    {}
    break;

  case 87:
#line 749 "ctlib/parser.y"
    {}
    break;

  case 88:
#line 750 "ctlib/parser.y"
    {}
    break;

  case 89:
#line 751 "ctlib/parser.y"
    {}
    break;

  case 90:
#line 759 "ctlib/parser.y"
    {
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
    break;

  case 91:
#line 776 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  }
    break;

  case 92:
#line 781 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-3].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	    else
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  }
    break;

  case 93:
#line 792 "ctlib/parser.y"
    {
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
    break;

  case 94:
#line 810 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  }
    break;

  case 95:
#line 815 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-3].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-1].pDecl );
	    else
	      decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  }
    break;

  case 96:
#line 827 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  }
    break;

  case 97:
#line 831 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 98:
#line 832 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 99:
#line 838 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  }
    break;

  case 100:
#line 842 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 101:
#line 843 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 102:
#line 849 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      }
    break;

  case 103:
#line 850 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      }
    break;

  case 104:
#line 851 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; }
    break;

  case 107:
#line 860 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval; }
    break;

  case 108:
#line 861 "ctlib/parser.y"
    { yyval.uval = 0;  }
    break;

  case 112:
#line 871 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 113:
#line 872 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 114:
#line 873 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 115:
#line 874 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 116:
#line 878 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               }
    break;

  case 117:
#line 879 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               }
    break;

  case 118:
#line 880 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval;               }
    break;

  case 119:
#line 881 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); }
    break;

  case 120:
#line 886 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  }
    break;

  case 121:
#line 891 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  }
    break;

  case 122:
#line 896 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  }
    break;

  case 123:
#line 903 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 124:
#line 904 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 125:
#line 905 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; }
    break;

  case 126:
#line 911 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  }
    break;

  case 127:
#line 916 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  }
    break;

  case 128:
#line 921 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  }
    break;

  case 129:
#line 928 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 130:
#line 929 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 131:
#line 930 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; }
    break;

  case 132:
#line 934 "ctlib/parser.y"
    { yyval.uval = T_TYPEDEF;  }
    break;

  case 133:
#line 935 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 134:
#line 936 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 135:
#line 937 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 136:
#line 938 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 137:
#line 939 "ctlib/parser.y"
    { yyval.uval = 0;          }
    break;

  case 138:
#line 943 "ctlib/parser.y"
    { yyval.uval = T_INT;      }
    break;

  case 139:
#line 944 "ctlib/parser.y"
    { yyval.uval = T_CHAR;     }
    break;

  case 140:
#line 945 "ctlib/parser.y"
    { yyval.uval = T_SHORT;    }
    break;

  case 141:
#line 946 "ctlib/parser.y"
    { yyval.uval = T_LONG;     }
    break;

  case 142:
#line 947 "ctlib/parser.y"
    { yyval.uval = T_FLOAT;    }
    break;

  case 143:
#line 948 "ctlib/parser.y"
    { yyval.uval = T_DOUBLE;   }
    break;

  case 144:
#line 949 "ctlib/parser.y"
    { yyval.uval = T_SIGNED;   }
    break;

  case 145:
#line 950 "ctlib/parser.y"
    { yyval.uval = T_UNSIGNED; }
    break;

  case 146:
#line 951 "ctlib/parser.y"
    { yyval.uval = T_VOID;     }
    break;

  case 147:
#line 955 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 148:
#line 956 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; }
    break;

  case 149:
#line 961 "ctlib/parser.y"
    {
	    yyval.tspec.tflags = yyvsp[-3].uval;
	    yyval.tspec.ptr = struct_new( NULL, 0, yyvsp[-3].uval, PSTATE->pragma.pack.current, EX_STRDECL_LIST( yyvsp[-1].list ) );
	    LL_push( PSTATE->pCPI->structs, yyval.tspec.ptr );
	  }
    break;

  case 150:
#line 967 "ctlib/parser.y"
    {
	    Struct *pStruct;
	    LinkedList strdecls = EX_STRDECL_LIST( yyvsp[-1].list );

	    yyval.tspec.tflags = yyvsp[-4].uval;
	    pStruct = HT_get( PSTATE->pCPI->htStructs, yyvsp[-3].idOrType.str, yyvsp[-3].idOrType.len, yyvsp[-3].idOrType.hash );

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
    break;

  case 151:
#line 992 "ctlib/parser.y"
    {
	    Struct *pStruct;

	    yyval.tspec.tflags = yyvsp[-1].uval;
	    pStruct = HT_get( PSTATE->pCPI->htStructs, yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, yyvsp[0].idOrType.hash );

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
    break;

  case 152:
#line 1011 "ctlib/parser.y"
    { yyval.uval = T_STRUCT; }
    break;

  case 153:
#line 1012 "ctlib/parser.y"
    { yyval.uval = T_UNION;  }
    break;

  case 154:
#line 1017 "ctlib/parser.y"
    {
	    yyval.list = LL_new();
	    LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	    LL_unshift( PSTATE->structDeclListsList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting struct declaration list (0x%08X) (count=%d)",
	                       yyval.list, LL_count(PSTATE->structDeclListsList)) );
	  }
    break;

  case 155:
#line 1025 "ctlib/parser.y"
    {
	    yyval.list = yyvsp[-1].list;
	    LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	  }
    break;

  case 156:
#line 1032 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; }
    break;

  case 157:
#line 1033 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; }
    break;

  case 158:
#line 1038 "ctlib/parser.y"
    {
	    TypeSpec ts = { NULL, T_INT };
	    yyval.pStructDecl = structdecl_new( ts, LL_new() );
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	    LL_unshift( PSTATE->structDeclList, yyval.pStructDecl );
	    CT_DEBUG( PARSER, ("unshifting struct declaration (0x%08X) (count=%d)",
	                       yyval.pStructDecl, LL_count(PSTATE->structDeclList)) );
	  }
    break;

  case 159:
#line 1048 "ctlib/parser.y"
    {
	    yyval.pStructDecl = yyvsp[-2].pStructDecl;
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	  }
    break;

  case 160:
#line 1057 "ctlib/parser.y"
    {
	    if( (yyvsp[-1].tspec.tflags & ANY_TYPE_NAME) == 0 )
	      yyvsp[-1].tspec.tflags |= T_INT;
	    yyval.pStructDecl = structdecl_new( yyvsp[-1].tspec, LL_new() );
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	    LL_unshift( PSTATE->structDeclList, yyval.pStructDecl );
	    CT_DEBUG( PARSER, ("unshifting struct declaration (0x%08X) (count=%d)",
	                       yyval.pStructDecl, LL_count(PSTATE->structDeclList)) );
	  }
    break;

  case 161:
#line 1068 "ctlib/parser.y"
    {
	    yyval.pStructDecl = yyvsp[-2].pStructDecl;
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	  }
    break;

  case 162:
#line 1077 "ctlib/parser.y"
    {
	    yyval.pDecl = yyvsp[-1].pDecl;
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  }
    break;

  case 163:
#line 1082 "ctlib/parser.y"
    {
	    yyval.pDecl = decl_new( "", 0 );
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  }
    break;

  case 164:
#line 1090 "ctlib/parser.y"
    {
	    yyval.pDecl = yyvsp[-1].pDecl;
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  }
    break;

  case 165:
#line 1095 "ctlib/parser.y"
    {
	    yyval.pDecl = decl_new( "", 0 );
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  }
    break;

  case 166:
#line 1102 "ctlib/parser.y"
    { yyval.ival = -1; }
    break;

  case 167:
#line 1103 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].ival; }
    break;

  case 168:
#line 1107 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].value.iv; }
    break;

  case 169:
#line 1112 "ctlib/parser.y"
    {
	    yyval.tspec.tflags = T_ENUM;
	    yyval.tspec.ptr    = enumspec_new( NULL, 0, yyvsp[-1].list );
	    LL_push( PSTATE->pCPI->enums, yyval.tspec.ptr );
	    PSTATE->curEnumList = NULL;
	  }
    break;

  case 170:
#line 1119 "ctlib/parser.y"
    {
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

	    PSTATE->curEnumList = NULL;
	  }
    break;

  case 171:
#line 1143 "ctlib/parser.y"
    {
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
    break;

  case 172:
#line 1163 "ctlib/parser.y"
    {
	    yyval.list = PSTATE->curEnumList = LL_new();
	    if( yyvsp[0].pEnum->value.flags & V_IS_UNDEF ) {
	      yyvsp[0].pEnum->value.flags &= ~V_IS_UNDEF;
	      yyvsp[0].pEnum->value.iv     = 0;
	    }
	    LL_push( yyval.list, yyvsp[0].pEnum );
	  }
    break;

  case 173:
#line 1172 "ctlib/parser.y"
    {
	    if( yyvsp[0].pEnum->value.flags & V_IS_UNDEF ) {
	      Enumerator *pEnum = LL_get( yyvsp[-2].list, -1 );
	      yyvsp[0].pEnum->value.flags = pEnum->value.flags;
	      yyvsp[0].pEnum->value.iv    = pEnum->value.iv + 1;
	    }
	    LL_push( yyvsp[-2].list, yyvsp[0].pEnum );
	    yyval.list = yyvsp[-2].list;
	  }
    break;

  case 174:
#line 1183 "ctlib/parser.y"
    {
	    yyval.list = yyvsp[-1].list;
	  }
    break;

  case 175:
#line 1190 "ctlib/parser.y"
    {
	    yyval.pEnum = enum_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, NULL );
	    STORE_IN_HASH( htEnumerators, yyvsp[0].idOrType, yyval.pEnum );
	  }
    break;

  case 176:
#line 1195 "ctlib/parser.y"
    {
	    yyval.pEnum = enum_new( yyvsp[-2].idOrType.str, yyvsp[-2].idOrType.len, &yyvsp[0].value );
	    STORE_IN_HASH( htEnumerators, yyvsp[-2].idOrType, yyval.pEnum );
	  }
    break;

  case 181:
#line 1212 "ctlib/parser.y"
    {}
    break;

  case 182:
#line 1213 "ctlib/parser.y"
    {}
    break;

  case 183:
#line 1214 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 184:
#line 1215 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 185:
#line 1216 "ctlib/parser.y"
    {}
    break;

  case 186:
#line 1217 "ctlib/parser.y"
    {}
    break;

  case 187:
#line 1218 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 188:
#line 1219 "ctlib/parser.y"
    {}
    break;

  case 189:
#line 1220 "ctlib/parser.y"
    {}
    break;

  case 190:
#line 1221 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 191:
#line 1222 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 192:
#line 1223 "ctlib/parser.y"
    {}
    break;

  case 193:
#line 1224 "ctlib/parser.y"
    {}
    break;

  case 194:
#line 1225 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[0].pDecl ) ); }
    break;

  case 195:
#line 1233 "ctlib/parser.y"
    { HN_delete( EX_NODE( yyvsp[0].identifier ) ); }
    break;

  case 196:
#line 1234 "ctlib/parser.y"
    { HN_delete( EX_NODE( yyvsp[0].identifier ) ); }
    break;

  case 197:
#line 1239 "ctlib/parser.y"
    {
	    yyval.idOrType.str    = yyvsp[0].identifier->key;
	    yyval.idOrType.len    = yyvsp[0].identifier->keylen;
	    yyval.idOrType.hash   = yyvsp[0].identifier->hash;
	    yyval.idOrType.node   = yyvsp[0].identifier;
	  }
    break;

  case 198:
#line 1246 "ctlib/parser.y"
    {
	    yyval.idOrType.str    = ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier;
	    HASH_STR_LEN( yyval.idOrType.hash, yyval.idOrType.str, yyval.idOrType.len );
	    yyval.idOrType.node   = NULL;
	  }
    break;

  case 199:
#line 1255 "ctlib/parser.y"
    {
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
    break;

  case 200:
#line 1267 "ctlib/parser.y"
    {
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
    break;

  case 201:
#line 1284 "ctlib/parser.y"
    {
	    yyval.value.iv = PSTATE->pCPC->int_size;
	    yyval.value.flags = 0;
	  }
    break;

  case 202:
#line 1289 "ctlib/parser.y"
    {
	    yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
                    PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	    yyval.value.flags = 0;
	  }
    break;

  case 207:
#line 1304 "ctlib/parser.y"
    {}
    break;

  case 215:
#line 1324 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[0].idOrType ); }
    break;

  case 222:
#line 1338 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-2].idOrType ); }
    break;

  case 240:
#line 1377 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-1].idOrType ); }
    break;

  case 250:
#line 1403 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); }
    break;

  case 251:
#line 1405 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); }
    break;

  case 252:
#line 1407 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); }
    break;

  case 253:
#line 1409 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); }
    break;

  case 254:
#line 1411 "ctlib/parser.y"
    { decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); }
    break;

  case 255:
#line 1413 "ctlib/parser.y"
    {}
    break;

  case 256:
#line 1414 "ctlib/parser.y"
    {}
    break;

  case 257:
#line 1415 "ctlib/parser.y"
    {}
    break;

  case 258:
#line 1416 "ctlib/parser.y"
    {}
    break;

  case 259:
#line 1417 "ctlib/parser.y"
    {}
    break;

  case 260:
#line 1419 "ctlib/parser.y"
    {}
    break;

  case 261:
#line 1420 "ctlib/parser.y"
    {}
    break;

  case 262:
#line 1421 "ctlib/parser.y"
    {}
    break;

  case 263:
#line 1422 "ctlib/parser.y"
    {}
    break;

  case 264:
#line 1423 "ctlib/parser.y"
    {}
    break;

  case 265:
#line 1427 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 266:
#line 1428 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 267:
#line 1432 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 268:
#line 1433 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 269:
#line 1438 "ctlib/parser.y"
    {
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (count=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	  }
    break;

  case 270:
#line 1445 "ctlib/parser.y"
    {
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[-1].tspec.ptr)->pDecl->identifier, 0 );
	    if( yyvsp[0].list )
	      LL_delete( LL_splice( yyval.pDecl->array, 0, 0, EX_ARRAY( yyvsp[0].list ) ) );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (count=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	  }
    break;

  case 271:
#line 1453 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 272:
#line 1460 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 273:
#line 1462 "ctlib/parser.y"
    {
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 274:
#line 1467 "ctlib/parser.y"
    {
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 275:
#line 1474 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 276:
#line 1476 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  }
    break;

  case 277:
#line 1486 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 278:
#line 1488 "ctlib/parser.y"
    {
	    yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  }
    break;

  case 279:
#line 1493 "ctlib/parser.y"
    {
	    yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  }
    break;

  case 280:
#line 1498 "ctlib/parser.y"
    {
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 281:
#line 1503 "ctlib/parser.y"
    {
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 282:
#line 1510 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 283:
#line 1512 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  }
    break;

  case 284:
#line 1517 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  }
    break;

  case 285:
#line 1525 "ctlib/parser.y"
    {
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (count=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	  }
    break;

  case 286:
#line 1531 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 287:
#line 1535 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 288:
#line 1536 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 289:
#line 1540 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; }
    break;

  case 290:
#line 1542 "ctlib/parser.y"
    {
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 291:
#line 1547 "ctlib/parser.y"
    {
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  }
    break;

  case 292:
#line 1555 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  }
    break;

  case 293:
#line 1559 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 294:
#line 1561 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  }
    break;

  case 295:
#line 1569 "ctlib/parser.y"
    {
	    yyval.pDecl = decl_new( yyvsp[0].identifier->key, yyvsp[0].identifier->keylen );
	    HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (count=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_count(PSTATE->declaratorList)) );
	  }
    break;

  case 296:
#line 1576 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; }
    break;

  case 297:
#line 1580 "ctlib/parser.y"
    {}
    break;

  case 298:
#line 1581 "ctlib/parser.y"
    {}
    break;

  case 299:
#line 1582 "ctlib/parser.y"
    {}
    break;

  case 300:
#line 1587 "ctlib/parser.y"
    {
	    decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  }
    break;

  case 301:
#line 1590 "ctlib/parser.y"
    {}
    break;

  case 302:
#line 1592 "ctlib/parser.y"
    {
	    LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  }
    break;

  case 303:
#line 1598 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; }
    break;

  case 304:
#line 1599 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; }
    break;

  case 305:
#line 1601 "ctlib/parser.y"
    {
	    Value *pValue;
	    yyval.absDecl.pointer_flag  = 0;
	    yyval.absDecl.multiplicator = 1;
	    if( yyvsp[0].list ) {
	      LL_foreach( pValue, yyvsp[0].list )
	        yyval.absDecl.multiplicator *= pValue->iv;
	    }
	    LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  }
    break;

  case 306:
#line 1614 "ctlib/parser.y"
    { yyval.list = yyvsp[0].list;   }
    break;

  case 307:
#line 1615 "ctlib/parser.y"
    { yyval.list = NULL; }
    break;

  case 308:
#line 1616 "ctlib/parser.y"
    { yyval.list = NULL; }
    break;

  case 309:
#line 1620 "ctlib/parser.y"
    { yyval.list = NULL; }
    break;

  case 310:
#line 1622 "ctlib/parser.y"
    {
	    yyval.list = LL_new();
	    LL_unshift( PSTATE->arrayList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting array (0x%08X) (count=%d)",
	                       yyval.list, LL_count(PSTATE->arrayList)) );
	    LL_push( yyval.list, value_new( yyvsp[-1].value.iv, yyvsp[-1].value.flags ) );
	    CT_DEBUG( PARSER, ("array dimension => %d", yyvsp[-1].value) );
	  }
    break;

  case 311:
#line 1631 "ctlib/parser.y"
    {
	    yyval.list = LL_new();
	    LL_unshift( PSTATE->arrayList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting array (0x%08X) (count=%d)",
	                       yyval.list, LL_count(PSTATE->arrayList)) );
	    LL_push( yyval.list, value_new( 0, 0 ) );
	    CT_DEBUG( PARSER, ("array dimension => *") );
	  }
    break;

  case 312:
#line 1640 "ctlib/parser.y"
    {
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
    break;

  case 313:
#line 1654 "ctlib/parser.y"
    {
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
    break;

  case 314:
#line 1671 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  }
    break;

  case 315:
#line 1676 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  }
    break;

  case 316:
#line 1681 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  }
    break;

  case 317:
#line 1686 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  }
    break;

  case 318:
#line 1693 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; }
    break;

  case 319:
#line 1694 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; }
    break;

  case 320:
#line 1696 "ctlib/parser.y"
    {
	    Value *pValue;
	    yyval.absDecl.pointer_flag  = 0;
	    yyval.absDecl.multiplicator = 1;
	    if( yyvsp[-1].list ) {
	      LL_foreach( pValue, yyvsp[-1].list )
	        yyval.absDecl.multiplicator *= pValue->iv;
	    }
	    LL_destroy( EX_ARRAY( yyvsp[-1].list ), (LLDestroyFunc) value_delete );
	  }
    break;

  case 321:
#line 1707 "ctlib/parser.y"
    {
	    yyval.absDecl = yyvsp[-2].absDecl;
	    LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  }
    break;


    }

/* Line 1016 of /home/mhx/bin/bison-1.75/share/bison/yacc.c.  */
#line 4040 "ctlib/parser.c"

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


#line 1713 "ctlib/parser.y"



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
  struct lexer_state *pLexer = &pState->lexer;

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
               pState->filename, pState->lexer.ctok->line, msg );
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

  plval->identifier = HN_new( s, len, hash );

  LL_unshift( pState->nodeList, plval->identifier );
  CT_DEBUG( CLEXER, ("unshifting identifier \"%s\" (0x%08X) (count=%d)",
                     plval->identifier->key, plval->identifier,
                     LL_count(pState->nodeList)) );

  return IDENTIFIER;
}


