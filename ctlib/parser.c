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
* $Date: 2004/05/23 12:37:48 +0200 $
* $Revision: 36 $
* $Snapshot: /Convert-Binary-C/0.53 $
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
#define YYLAST   2260

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  132
/* YYNRULES -- Number of rules. */
#define YYNRULES  364
/* YYNRULES -- Number of states. */
#define YYNSTATES  614

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
     512,   514,   519,   525,   528,   530,   532,   534,   536,   539,
     542,   545,   548,   550,   553,   557,   560,   564,   567,   569,
     572,   574,   575,   577,   580,   586,   593,   596,   598,   600,
     604,   606,   610,   612,   616,   618,   622,   624,   627,   630,
     633,   635,   638,   641,   643,   646,   649,   652,   654,   657,
     660,   662,   666,   668,   670,   672,   675,   677,   680,   681,
     684,   689,   691,   694,   699,   700,   703,   705,   708,   712,
     715,   716,   718,   720,   722,   724,   726,   728,   730,   732,
     736,   741,   745,   748,   752,   756,   761,   763,   766,   768,
     771,   774,   780,   788,   794,   800,   808,   818,   822,   825,
     828,   832,   833,   835,   837,   840,   842,   844,   846,   847,
     851,   852,   857,   858,   863,   864,   869,   870,   875,   876,
     880,   881,   886,   887,   892,   893,   898,   899,   904,   905,
     910,   911,   917,   918,   924,   925,   931,   932,   938,   940,
     942,   944,   946,   948,   951,   953,   955,   958,   962,   966,
     971,   973,   978,   984,   987,   991,   995,  1000,  1005,  1007,
    1011,  1013,  1015,  1017,  1020,  1024,  1027,  1031,  1036,  1038,
    1042,  1044,  1047,  1051,  1056,  1060,  1065,  1067,  1069,  1071,
    1073,  1076,  1080,  1083,  1087,  1091,  1096,  1101,  1103,  1106,
    1109,  1113,  1117,  1121,  1125
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     183,     0,    -1,    62,    -1,    90,    62,    -1,    37,    65,
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
      -1,   100,    41,    -1,    65,   166,    66,    73,   169,   173,
      74,    -1,    61,    -1,    64,    -1,   119,    -1,   104,    69,
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
     116,    -1,   117,    -1,   117,    87,   121,    68,   118,    -1,
     118,    -1,   105,   120,   119,    -1,    88,    -1,    51,    -1,
      52,    -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,   119,    -1,
     121,    69,   119,    -1,   118,    -1,    -1,   121,    -1,   136,
      67,    -1,   137,    67,    -1,   126,    67,    -1,   125,    67,
      -1,   129,   210,    92,   167,    -1,   130,   210,    92,   167,
      -1,   125,    69,   210,    92,   167,    -1,   127,   202,    92,
     167,    -1,   128,   202,    92,   167,    -1,   126,    69,   202,
      92,   167,    -1,   134,    -1,   136,    -1,   140,    -1,   135,
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
     145,    -1,   157,    -1,   146,    73,   148,    74,    -1,   146,
     165,    73,   148,    74,    -1,   146,   165,    -1,   147,    -1,
       6,    -1,    18,    -1,   149,    -1,   148,   149,    -1,   152,
      67,    -1,   151,    67,    -1,   150,    67,    -1,   139,    -1,
     130,   154,    -1,   151,    69,   154,    -1,   128,   153,    -1,
     152,    69,   153,    -1,   202,   155,    -1,   156,    -1,   210,
     155,    -1,   156,    -1,    -1,   156,    -1,    68,   122,    -1,
     158,    73,   159,   173,    74,    -1,   158,   165,    73,   159,
     173,    74,    -1,   158,   165,    -1,    12,    -1,   160,    -1,
     159,    69,   160,    -1,   165,    -1,   165,    88,   122,    -1,
     162,    -1,   162,    69,    50,    -1,   163,    -1,   162,    69,
     163,    -1,   127,    -1,   127,   216,    -1,   127,   210,    -1,
     127,   204,    -1,   129,    -1,   129,   216,    -1,   129,   210,
      -1,   128,    -1,   128,   216,    -1,   128,   210,    -1,   128,
     204,    -1,   130,    -1,   130,   216,    -1,   130,   210,    -1,
      61,    -1,   164,    69,    61,    -1,    61,    -1,    64,    -1,
     128,    -1,   128,   216,    -1,   130,    -1,   130,   216,    -1,
      -1,    88,   168,    -1,    73,   169,   173,    74,    -1,   119,
      -1,   170,   168,    -1,   169,    69,   170,   168,    -1,    -1,
     171,    88,    -1,   172,    -1,   171,   172,    -1,    70,   122,
      71,    -1,    72,   165,    -1,    -1,    69,    -1,   175,    -1,
     176,    -1,   179,    -1,   180,    -1,   181,    -1,   182,    -1,
      94,    -1,   165,    68,   174,    -1,    11,   122,    68,   174,
      -1,    27,    68,   174,    -1,    73,    74,    -1,    73,   177,
      74,    -1,    73,   178,    74,    -1,    73,   177,   178,    74,
      -1,   124,    -1,   177,   124,    -1,   174,    -1,   178,   174,
      -1,   123,    67,    -1,    32,    65,   121,    66,   174,    -1,
      32,    65,   121,    66,   174,     8,   174,    -1,    10,    65,
     121,    66,   174,    -1,    34,    65,   121,    66,   174,    -1,
      31,   174,    34,    65,   121,    66,    67,    -1,    24,    65,
     123,    67,   123,    67,   123,    66,   174,    -1,    28,   165,
      67,    -1,    23,    67,    -1,     7,    67,    -1,    17,   123,
      67,    -1,    -1,   184,    -1,   185,    -1,   184,   185,    -1,
     186,    -1,   124,    -1,    93,    -1,    -1,   210,   187,   176,
      -1,    -1,   127,   210,   188,   176,    -1,    -1,   128,   210,
     189,   176,    -1,    -1,   129,   210,   190,   176,    -1,    -1,
     130,   210,   191,   176,    -1,    -1,   214,   192,   176,    -1,
      -1,   127,   214,   193,   176,    -1,    -1,   128,   214,   194,
     176,    -1,    -1,   129,   214,   195,   176,    -1,    -1,   130,
     214,   196,   176,    -1,    -1,   214,   177,   197,   176,    -1,
      -1,   127,   214,   177,   198,   176,    -1,    -1,   128,   214,
     177,   199,   176,    -1,    -1,   129,   214,   177,   200,   176,
      -1,    -1,   130,   214,   177,   201,   176,    -1,   210,    -1,
     203,    -1,   207,    -1,   204,    -1,    64,    -1,    64,   217,
      -1,   205,    -1,   206,    -1,    76,   204,    -1,    76,   130,
     204,    -1,    65,   205,    66,    -1,    65,   205,    66,   217,
      -1,   208,    -1,    76,    65,   209,    66,    -1,    76,   130,
      65,   209,    66,    -1,    76,   207,    -1,    76,   130,   207,
      -1,    65,   207,    66,    -1,    65,   209,   217,    66,    -1,
      65,   207,    66,   217,    -1,    64,    -1,    65,   209,    66,
      -1,   211,    -1,   213,    -1,   212,    -1,    76,   210,    -1,
      76,   130,   210,    -1,   213,   217,    -1,    65,   211,    66,
      -1,    65,   211,    66,   217,    -1,    61,    -1,    65,   213,
      66,    -1,   215,    -1,    76,   214,    -1,    76,   130,   214,
      -1,   213,    65,   164,    66,    -1,    65,   214,    66,    -1,
      65,   214,    66,   217,    -1,   219,    -1,   220,    -1,   217,
      -1,   218,    -1,    65,    66,    -1,    65,   161,    66,    -1,
      70,    71,    -1,    70,   119,    71,    -1,    70,    76,    71,
      -1,   218,    70,   119,    71,    -1,   218,    70,    76,    71,
      -1,    76,    -1,    76,   130,    -1,    76,   216,    -1,    76,
     130,   216,    -1,    65,   219,    66,    -1,    65,   220,    66,
      -1,    65,   217,    66,    -1,    65,   219,    66,   217,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   558,   558,   559,   567,   570,   572,   576,   580,   581,
     583,   586,   592,   594,   598,   599,   603,   604,   608,   609,
     614,   620,   621,   622,   626,   627,   628,   629,   630,   630,
     631,   631,   632,   633,   634,   638,   639,   643,   644,   648,
     649,   650,   651,   669,   670,   674,   675,   676,   677,   678,
     679,   683,   684,   688,   689,   691,   698,   708,   709,   711,
     716,   717,   719,   724,   725,   727,   729,   731,   736,   737,
     739,   744,   745,   750,   751,   756,   757,   762,   763,   768,
     769,   774,   775,   780,   781,   785,   786,   787,   788,   789,
     790,   791,   792,   793,   794,   795,   799,   800,   804,   808,
     810,   848,   849,   850,   851,   858,   880,   886,   897,   917,
     923,   935,   940,   941,   946,   951,   952,   958,   959,   960,
     964,   965,   968,   970,   974,   975,   979,   980,   981,   985,
     986,   987,   988,   992,   993,   994,   995,   999,  1004,  1009,
    1017,  1018,  1019,  1023,  1024,  1025,  1029,  1030,  1033,  1038,
    1043,  1051,  1052,  1053,  1057,  1058,  1059,  1060,  1061,  1062,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1078,
    1079,  1083,  1099,  1130,  1156,  1165,  1166,  1170,  1185,  1200,
    1201,  1202,  1206,  1220,  1235,  1249,  1265,  1279,  1289,  1302,
    1312,  1325,  1326,  1330,  1334,  1350,  1382,  1408,  1416,  1430,
    1448,  1458,  1471,  1472,  1476,  1477,  1481,  1482,  1483,  1484,
    1485,  1486,  1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,
    1502,  1503,  1507,  1522,  1538,  1552,  1572,  1579,  1589,  1591,
    1595,  1596,  1600,  1601,  1604,  1606,  1610,  1611,  1615,  1616,
    1619,  1621,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1636,
    1637,  1638,  1642,  1643,  1644,  1645,  1649,  1650,  1654,  1655,
    1659,  1663,  1664,  1665,  1669,  1670,  1671,  1675,  1676,  1677,
    1678,  1684,  1686,  1690,  1691,  1695,  1696,  1697,  1701,  1701,
    1703,  1703,  1705,  1705,  1707,  1707,  1709,  1709,  1712,  1712,
    1713,  1713,  1714,  1714,  1715,  1715,  1716,  1716,  1718,  1718,
    1719,  1719,  1720,  1720,  1721,  1721,  1722,  1722,  1726,  1727,
    1731,  1732,  1736,  1748,  1762,  1769,  1770,  1776,  1785,  1786,
    1797,  1798,  1804,  1810,  1816,  1825,  1826,  1831,  1839,  1851,
    1855,  1856,  1860,  1861,  1867,  1876,  1881,  1882,  1890,  1903,
    1907,  1908,  1909,  1913,  1918,  1919,  1927,  1928,  1929,  1943,
    1944,  1945,  1949,  1963,  1977,  1978,  1997,  2019,  2024,  2029,
    2034,  2042,  2043,  2044,  2055
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
  "aggregate_key", "member_declaration_list", "member_declaration", 
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
     149,   149,   150,   151,   151,   152,   152,   153,   153,   154,
     154,   155,   155,   156,   157,   157,   157,   158,   159,   159,
     160,   160,   161,   161,   162,   162,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     164,   164,   165,   165,   166,   166,   166,   166,   167,   167,
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
     217,   217,   218,   218,   218,   218,   218,   219,   219,   219,
     219,   220,   220,   220,   220
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
       1,     4,     5,     2,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     2,     3,     2,     3,     2,     1,     2,
       1,     0,     1,     2,     5,     6,     2,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     2,     1,     2,     2,
       1,     3,     1,     1,     1,     2,     1,     2,     0,     2,
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
       2,     3,     2,     3,     3,     4,     4,     1,     2,     2,
       3,     3,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     271,   157,   165,   160,   175,   163,   197,   158,   154,   161,
     155,   176,   126,   164,   162,   167,   166,   168,   128,   156,
     159,   127,     0,   338,   151,     0,     0,   277,   276,     0,
       0,     0,     0,     0,     0,   120,   111,   114,   112,   115,
     113,   116,   117,   133,   140,   169,     0,   174,   170,     0,
       0,   272,   273,   275,   278,   330,   332,   331,   288,   340,
       0,     0,     0,     0,     0,   333,   341,   104,     0,   103,
       0,   312,     0,     0,     5,   309,   311,   314,   315,   310,
     320,   308,   290,     5,   308,   292,   149,   119,   125,   124,
     129,   137,     5,   294,   152,   121,   118,   134,   141,     5,
     296,   131,   132,   135,   130,   136,   101,   139,   102,   142,
     138,   150,   153,   148,   222,   223,     0,   173,     0,   196,
       1,   274,     0,     0,     0,   335,   349,   256,     0,     0,
       0,     0,   298,     0,     0,     0,     0,    20,     2,    21,
       0,    45,    46,    47,    48,    49,    50,    22,    24,    39,
      51,     0,    53,    57,    60,    63,    68,    71,    73,    75,
      77,    79,    81,    83,    96,     0,   336,   339,   344,   334,
     342,     0,     0,     5,   331,     0,     0,     5,   308,     0,
     313,   328,     0,     0,     0,     0,     0,     0,   316,   323,
       0,     6,   228,     0,   300,     0,   228,     0,   302,     0,
     228,     0,   304,     0,   228,     0,   306,     0,     0,     0,
     114,   115,   146,   182,   116,   169,     0,   177,     0,     0,
       0,     0,   240,   198,   200,     0,    99,   279,   220,   350,
     206,   213,   210,   217,   112,   115,     0,   202,   204,     0,
     352,    46,     0,     0,     5,     5,   257,     0,   289,     0,
      43,     0,    40,    41,     0,   224,   226,   115,   116,     0,
       3,    32,    33,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    85,     0,    51,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,   345,     0,     0,   228,     0,     0,     0,
     228,     0,   318,   325,     0,     0,     0,   317,   324,     0,
       0,   108,   281,     0,   291,   109,   283,     0,   293,   105,
     285,     0,   295,   106,   287,     0,   297,     0,   185,   188,
     191,   169,   183,   190,   191,   142,   171,   178,   181,   180,
       0,   179,     0,     0,   241,     0,     0,   240,     0,     0,
       0,    99,     0,     0,     0,     0,    99,     0,     0,   122,
      20,   151,   252,   248,   100,     0,     0,   258,   242,   243,
      99,    99,   244,   245,   246,   247,     0,   357,   209,   208,
     207,   348,   346,   347,   216,   215,   214,     0,   357,   212,
     211,   219,   218,   351,     0,   343,     0,   354,   353,    46,
       0,   299,     0,     0,    23,     0,   357,   225,   227,     0,
      26,     0,    37,     0,     0,     0,    84,    54,    55,    56,
      58,    59,    61,    62,    66,    67,    64,    65,    69,    70,
      72,    74,    76,    78,    80,     0,     7,    97,   107,     0,
     110,   329,   319,   327,   326,   321,     0,     0,   234,   231,
     229,   301,   303,   305,   307,    98,   193,   187,   192,   189,
     184,   186,   172,   199,   194,   201,     0,   269,     0,     0,
       0,   268,    99,    99,     0,     0,     0,     0,   123,     0,
     260,    99,   253,    99,   254,   259,     0,     0,     0,   358,
     359,   358,   203,   205,   221,   356,   355,    44,     0,   358,
     234,    52,    27,     0,    25,    35,    36,    29,    31,     0,
     322,     4,     0,     0,   240,     0,     0,   236,   195,     0,
      99,   270,     0,   251,   267,     0,     0,     0,     0,   249,
     255,   363,   361,   362,   360,   240,    38,    82,     0,   239,
     234,     0,   232,   235,   237,    99,   250,    99,     0,    99,
      99,     0,   364,     0,   238,     0,   230,   263,     0,     0,
     261,   264,     0,    12,    34,   233,    99,     0,    99,     8,
       0,     0,     0,    13,    14,     0,   265,   262,     0,     0,
       0,    12,     0,    99,     0,     0,     9,     0,    15,   266,
      16,     0,     0,     0,     0,    10,    18,     0,     0,     0,
       0,    17,    11,    19
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   147,   191,   200,    27,   373,   582,   583,   584,   607,
     148,   149,   265,   266,   517,   421,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   278,   374,   466,   375,   127,    29,    30,   128,   129,
     130,   131,   489,    87,    35,    36,    37,    38,    39,   212,
     213,    40,    41,    42,    43,    44,    45,    46,    47,   216,
     217,   218,   219,   220,   338,   342,   467,   339,    48,    49,
     222,   223,   236,   237,   238,   239,   376,   259,   321,   460,
     524,   525,   526,   527,   355,   377,   378,   379,   132,   381,
     382,   383,   384,   385,    50,    51,    52,    53,   122,   193,
     197,   201,   205,   133,   195,   199,   203,   207,   247,   323,
     327,   331,   335,    74,    75,    76,    77,    78,   184,    80,
     185,    65,    55,    56,   174,    63,    59,   500,   391,   126,
     392,   393
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -517
static const short yypact[] =
{
    1330,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,
    -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,
    -517,  -517,   -63,  -517,  -517,   253,   411,  -517,  -517,    29,
     331,   378,   378,  1571,  1608,  -517,  2224,  2224,  1015,  1089,
     679,   679,  -517,  -517,  -517,  -517,   126,  -517,  -517,   300,
      37,  1330,  -517,  -517,  -517,  -517,  -517,    18,  1936,  -517,
    2068,   -11,   185,    69,   411,  -517,  -517,  -517,   272,  -517,
     392,    72,   418,   725,    25,  -517,  -517,  -517,  -517,  -517,
    -517,    93,  1936,    25,    98,  1936,  -517,  -517,  -517,  -517,
    -517,  -517,    16,  1936,  -517,  -517,  -517,  -517,  -517,    19,
    1936,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,
    -517,  -517,  -517,  -517,  -517,  -517,  1969,   121,   147,   130,
    -517,  -517,   140,  1824,  1963,  -517,    80,  -517,   392,   392,
    1645,  1682,  1936,   140,  2094,  2120,  2120,  -517,  -517,  -517,
     962,  -517,  -517,  -517,  -517,  -517,  -517,    78,  -517,   507,
     805,  2068,  -517,   327,   -62,    77,    23,    63,   143,   173,
     233,   223,   -41,  -517,  -517,   196,    72,  -517,    72,  -517,
    -517,   272,   561,    25,    72,   442,  1116,    25,  -517,  1861,
    -517,  -517,   418,   262,   269,    72,   418,  1174,  -517,  -517,
     275,  -517,   256,   140,  1936,   140,   256,   140,  1936,   140,
     256,   140,  1936,   140,   256,   140,  1936,   140,   301,  1719,
     985,   137,  -517,  -517,    67,   283,  1295,  -517,   292,   356,
     377,  1969,   298,  -517,   302,   147,   807,  -517,  -517,  -517,
     321,   321,  1367,  1435,   679,   679,   323,   350,  -517,   255,
    -517,   353,   363,  2146,    25,    25,  -517,   140,  -517,   962,
    -517,   962,  -517,  -517,   288,   311,  1756,   137,   137,   382,
    -517,  -517,  -517,  1989,  2068,   389,   438,  -517,  -517,  -517,
    -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  2068,  -517,
    -517,  2068,  2068,  2068,  2068,  2068,  2068,  2068,  2068,  2068,
    2068,  2068,  2068,  2068,  2068,  2068,  2068,  2068,  2068,  2068,
     422,  2068,  -517,  -517,   341,   561,   256,   442,   442,  1484,
     256,   393,    72,    72,   419,   439,   418,  -517,  -517,   451,
    2016,  -517,  -517,   140,  -517,  -517,  -517,   140,  -517,  -517,
    -517,   140,  -517,  -517,  -517,   140,  -517,  2068,  -517,  -517,
     433,   450,  -517,  -517,   433,   468,  -517,  -517,  -517,  -517,
     247,  -517,   301,  1468,   147,   449,  2068,   298,   498,   476,
    2068,  2068,   506,   511,   521,   147,  1184,   534,   535,   137,
     537,   539,  -517,  -517,   542,   549,   550,  -517,  -517,  -517,
     885,  1036,  -517,  -517,  -517,  -517,   727,   205,  -517,  -517,
    -517,  -517,  -517,  -517,  -517,  -517,  -517,  1262,   545,  -517,
    -517,  -517,  -517,  -517,  1896,  -517,   556,  -517,  -517,   557,
     558,  -517,   568,   569,  -517,  1503,   271,  -517,  -517,  2042,
    -517,   347,  -517,   402,   391,   391,  -517,  -517,  -517,  -517,
     327,   327,   -62,   -62,    77,    77,    77,    77,    23,    23,
      63,   143,   173,   233,   223,    86,  -517,  -517,  -517,   442,
    -517,  -517,  -517,  -517,  -517,  -517,   455,   -44,   425,  -517,
    -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,
    -517,  -517,  -517,  -517,  -517,  -517,   553,  -517,  2068,   589,
     593,  -517,  2068,  1184,   594,   602,  2068,  2068,   137,   600,
    -517,  1184,  -517,  1110,  -517,  -517,   601,   603,   605,   205,
    -517,   545,  -517,  -517,  -517,  -517,  -517,   604,   604,   271,
     425,  -517,  -517,  2068,  -517,  -517,  -517,  -517,  -517,  2068,
    -517,  -517,  2068,   147,   606,  2016,     6,  -517,  -517,   474,
    1184,  -517,   612,  -517,  -517,   608,   489,   497,  2068,  -517,
    -517,  -517,    72,  -517,  -517,   606,  -517,  -517,   609,  -517,
     213,   610,  -517,  -517,  -517,  1184,  -517,  2068,  2068,  1184,
    1184,   488,  -517,   611,  -517,  2016,  -517,  -517,   616,   505,
     678,  -517,   622,    15,  -517,  -517,  2068,   623,  1184,  -517,
     626,   636,   456,   630,  -517,   634,  -517,  -517,  2068,   631,
     637,    15,    15,  1184,   518,   639,  -517,   522,  -517,  -517,
    -517,   638,   640,   451,  2068,  -517,    78,   529,   590,   641,
     451,  -517,  -517,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -517,  -290,  -517,   297,  -517,  -517,   114,  -517,   124,  -517,
    -517,  -517,  -517,  -517,   294,  -517,   357,  -517,  -103,   -57,
      -9,   248,    82,   426,   427,   428,   424,   431,  -517,  -265,
    -120,  -517,   -60,  -299,  -320,    70,  -517,  -517,    13,   163,
      36,   216,  -517,     4,   -13,  -517,   -56,  -106,   215,  -517,
    -517,  -517,   109,   493,   478,    -3,    -4,  -517,  -517,   502,
    -202,  -517,  -517,  -517,   383,   387,   394,  -104,  -517,  -517,
     525,   397,  -517,  -517,   352,  -517,   -43,   310,  -157,  -516,
     244,   208,  -517,   238,  -298,   103,  -517,   471,   -19,   379,
    -517,  -517,  -517,  -517,  -517,  -517,   714,  -517,  -517,  -517,
    -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,
    -517,  -517,  -517,   -25,  -517,   -61,   -34,  -517,   273,  -517,
    -132,     1,   -14,  -517,   113,   519,  -517,  -131,   -52,  -517,
    -307,  -304
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -287
static const short yytable[] =
{
     165,    54,    60,   117,   242,   125,   119,    83,   298,   552,
     125,    61,   188,    31,   347,   284,   285,   234,   260,   180,
      88,    95,   521,    88,   103,    88,   109,    88,   112,   457,
      91,    98,    81,    84,    92,    99,    33,   120,   183,   325,
     101,   480,   107,   329,   111,   177,   299,   333,   280,   575,
     311,    95,    54,   190,   315,   166,   190,   475,    61,   476,
     210,   479,   190,   194,    31,   169,   198,   288,   289,   173,
      28,   178,   465,   234,   202,   224,   522,   580,   523,   497,
     254,   206,   498,   123,   210,   581,    12,    33,   124,  -284,
     497,   465,  -286,   498,   553,   465,    67,    18,    68,   390,
     396,   400,   402,    21,    83,   343,   290,   291,   497,   292,
     293,   498,   215,    57,   302,   188,   303,    88,    95,   286,
     287,    28,   125,   410,   417,   418,   317,    91,    98,   178,
     178,   244,   245,   314,  -147,   168,   230,   179,    62,    57,
     260,   183,   124,   422,    57,    57,    57,    57,   183,   448,
     243,   347,   183,   450,   519,   301,    12,    61,   426,   232,
     210,    61,   532,    32,    57,   210,  -280,    18,    61,   388,
     394,  -282,    61,    21,    95,   311,   315,    57,   427,   428,
     429,   447,   224,   340,   456,    62,    57,   114,   169,   254,
     115,   254,   230,   210,   221,   210,    95,   103,   345,   116,
     459,   112,   246,   225,   423,   341,    98,   380,   114,   178,
     344,   115,   215,   226,    32,   232,    34,   215,   294,    88,
      95,    88,   109,   548,    12,   214,   551,   430,   431,    91,
      98,   389,   395,   399,   401,    18,   468,   568,   107,   445,
     468,    21,    64,    95,   109,   112,   343,   563,   317,   258,
     123,   167,   125,    98,   547,   124,   585,   465,   295,   314,
     452,   453,   300,   314,   246,   301,    23,    34,   246,    71,
     386,   297,   246,   183,   183,   124,   246,   432,   433,   208,
     234,   387,   183,   522,   304,   523,   231,  -241,   304,   187,
      12,   234,    95,    61,    61,    62,    95,   210,   234,    62,
      57,    18,    61,   255,    79,    79,   169,    21,    23,   234,
     169,   224,   171,   606,    23,   337,   511,   456,    25,   296,
     613,   405,   484,   172,   406,   214,   188,   340,   312,    26,
     214,   211,   209,    23,   496,   313,   415,   171,   235,   233,
     319,   124,   231,    79,   320,   496,   189,   416,   172,   215,
    -143,   344,   183,   178,   414,   257,   256,   301,   258,   348,
     258,   114,    23,   496,   115,    71,   175,   354,   544,   337,
     544,   192,    61,   118,   438,   439,   415,   176,   544,   208,
     196,   124,    23,    61,   208,    71,   386,   416,   305,   403,
     356,   124,   309,   546,   235,   233,   204,   387,    69,   230,
      70,    79,    79,   281,   314,   459,   179,   167,   282,   283,
     230,   124,   255,   512,   255,   183,   513,   230,   529,   404,
     304,   304,   232,   349,   407,   350,   536,   537,   230,    62,
      12,   211,   209,   232,   408,    61,   211,   209,   317,    23,
     232,    18,    71,    72,   351,   459,   352,    21,   419,   189,
     246,   232,   515,    23,    73,   516,    71,   175,   179,   451,
     318,   424,   214,   124,   257,   256,   257,   256,   176,   485,
     306,   301,    23,   514,   310,    95,    25,   425,   561,    23,
     549,    79,   181,   182,   495,   454,    95,    26,    95,   446,
     562,   250,   252,   253,    73,   522,    95,   523,   569,   304,
     169,   337,   169,    23,   179,   455,   181,   307,   279,   124,
     304,    90,    97,   138,   102,   105,   208,  -144,   176,    58,
     179,   520,   590,   474,   591,   124,    89,    96,   594,    89,
     104,    89,   110,    89,   113,  -145,   434,   435,   436,   437,
     555,   478,   204,   301,   608,    66,   -30,   261,   262,   231,
      82,    85,    93,   100,   572,   559,   573,   301,   301,   412,
     231,   413,   304,   560,    12,   477,   301,   231,   211,   209,
      58,   577,   263,   481,   301,    18,   482,   264,   231,   -28,
      12,    21,   318,   170,   600,   488,   533,   301,   602,   483,
     603,    18,    66,   227,   539,   609,   495,    21,   610,   486,
     487,   235,   233,   499,   248,  -222,    23,  -223,    90,    97,
     397,   301,   235,   233,   501,   124,   490,   504,   491,   235,
     233,   398,    23,    89,    96,    79,   171,   528,   505,   506,
     235,   233,   509,   556,   507,   508,   535,   172,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   611,   530,   567,   301,
     531,   534,   570,   571,   322,   538,   324,   541,   326,   542,
     328,   543,   330,   558,   332,   550,   334,   510,   336,   557,
     564,   587,     1,   576,   566,   574,   578,    97,   105,   579,
     586,   588,     7,     8,   279,    10,   599,   589,    12,   592,
     593,   601,   595,   604,   596,   597,   170,   605,   612,    18,
      90,    97,    19,   279,    20,    21,   598,   279,   411,   518,
     440,   443,   441,   353,   442,    89,    96,    89,   110,   444,
       1,     2,     3,     4,    97,   471,     5,   470,   469,     6,
       7,     8,     9,    10,    12,    11,    12,    13,    14,    15,
     357,   473,    16,    17,   545,    18,   503,    18,   565,   493,
      19,    21,    20,    21,   554,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,    23,    71,
     186,    24,   386,   229,   461,     0,     0,   124,   462,     0,
       0,    73,   463,   387,     0,     0,   464,     0,     0,     0,
       1,     2,     3,     4,   358,     0,     5,   359,   360,     6,
       7,     8,     9,    10,   361,    11,    12,    13,    14,    15,
     362,   363,    16,    17,   364,   365,   134,    18,   366,   367,
      19,   368,    20,    21,   369,     0,     0,   135,   136,     0,
       0,     0,     0,     0,     0,     0,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,     0,   370,   138,
     139,   371,   140,     0,     0,     0,   279,     0,     0,   279,
     226,   372,   141,   142,   143,   144,   145,   146,     1,     2,
       3,     4,   358,   277,     5,   359,   360,     6,     7,     8,
       9,    10,   361,    11,    12,    13,    14,    15,   362,   363,
      16,    17,   364,   365,   134,    18,   366,   367,    19,   368,
      20,    21,   369,     0,     0,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,   138,   139,   371,
     140,     0,     0,     0,     0,     0,     0,     0,   226,   492,
     141,   142,   143,   144,   145,   146,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     0,     0,     9,     0,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     2,
       3,   134,    18,     0,     5,     0,     0,     0,    21,     0,
       9,     0,   135,   136,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,     1,     0,
       0,    21,     0,   137,   138,   139,    24,   140,     7,     8,
       0,    10,     0,     0,    12,     0,     0,   141,   142,   143,
     144,   145,   146,   358,     0,    18,   359,   360,    19,     0,
      20,    21,     0,   361,     0,     0,     0,     0,     0,   362,
     363,     0,     0,   364,   365,   134,     0,   366,   367,     0,
     368,     0,     0,   369,     0,     0,   135,   136,     0,     0,
       0,     0,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,   370,   138,   139,
     115,   140,     7,     8,     0,    10,     0,     0,    12,   226,
     494,   141,   142,   143,   144,   145,   146,   358,     0,    18,
     359,   360,    19,     0,    20,    21,     0,   361,     0,     0,
       0,     0,     0,   362,   363,    12,     0,   364,   365,   134,
       0,   366,   367,     0,   368,     0,    18,   369,     0,     0,
     135,   136,    21,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,   138,   139,   115,   140,     0,    23,     0,     0,
      71,   308,     0,   226,   540,   141,   142,   143,   144,   145,
     146,   358,   176,    12,   359,   360,     0,     0,     0,     0,
       0,   361,     0,     0,    18,     0,     0,   362,   363,     0,
      21,   364,   365,   134,     0,   366,   367,     0,   368,     0,
       0,   369,     0,     0,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,    71,   316,
       0,     0,     0,     0,     0,   370,   138,   139,   115,   140,
      73,     0,     0,     0,     0,     0,     0,   226,     0,   141,
     142,   143,   144,   145,   146,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,     0,    18,     0,     0,    19,     0,    20,    21,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       9,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,    23,     0,    18,    24,   397,   229,     0,
       0,    21,   124,     1,     2,     3,     4,     0,   398,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,    24,
      18,     0,     0,    19,     0,    20,    21,    22,     0,   346,
       1,     2,     3,     4,     0,     0,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,    23,    16,    17,    24,    25,     0,    18,     0,     0,
      19,     0,    20,    21,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,    86,   397,     0,     0,     0,     0,   124,     1,     2,
       3,     4,     0,   398,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,    19,     0,
      20,    21,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     0,     0,     9,     0,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,    23,     0,    18,    94,
     397,     0,     0,    12,    21,   124,     1,     2,     3,     4,
       0,   398,     5,     0,    18,     6,     7,     8,     9,    10,
      21,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,    24,    18,     0,     0,    19,     0,    20,    21,
       0,     0,   472,     0,     0,    23,     0,     0,    71,   449,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,     0,     0,     0,     0,     0,     0,    24,   415,   229,
       0,     0,     0,   124,     1,     2,     3,     4,     0,   416,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,     0,     0,    19,     0,    20,    21,     0,     0,
       0,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,    23,    16,    17,    86,    25,     0,    18,     0,
       0,    19,     0,    20,    21,     0,     0,    26,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,    23,
      16,    17,    94,    25,     0,    18,     0,     0,    19,     0,
      20,    21,     0,     0,    26,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,    23,    16,    17,    86,
     171,     0,    18,     0,     0,    19,     0,    20,    21,     0,
       0,   172,     0,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     9,     0,     0,    11,    12,    13,
      14,    15,     0,    23,    16,    17,    94,   171,     0,    18,
       0,     0,     0,     0,     0,    21,     0,     0,   172,     0,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     0,
       0,     9,     0,     0,    11,    12,    13,    14,    15,     0,
      23,    16,    17,    94,   171,     0,    18,   337,     0,     0,
       0,     0,    21,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,   415,     0,     0,     0,     0,   124,     1,     2,     3,
       4,     0,   416,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,    20,
      21,     0,     0,     0,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,   228,    16,    17,    24,     0,
     229,    18,     0,     0,    19,     0,    20,    21,     0,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,    24,    18,   229,     0,    19,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     0,     0,     5,   502,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
      24,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     0,     0,     9,     0,     0,    11,    12,    13,
      14,    15,   134,     0,    16,    17,     0,     0,     0,    18,
      24,     0,     0,   135,   136,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,     0,
       0,     0,     0,     0,   137,   138,   139,     0,   140,   135,
     136,     0,     0,    24,   240,     0,     0,     0,   141,   241,
     143,   144,   145,   146,     0,   134,     0,     0,     0,     0,
     137,   138,   139,     0,   140,   420,   135,   136,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
       0,   134,     0,     0,     0,     0,     0,   137,   138,   139,
       0,   140,   135,   136,     0,     0,     0,     0,     0,   458,
       0,   141,   142,   143,   144,   145,   146,   134,     0,     0,
       0,     0,     0,   137,   138,   139,     0,   140,   135,   136,
       0,     0,     0,     0,     0,   510,     0,   141,   142,   143,
     144,   145,   146,   134,     0,     0,     0,     0,     0,   137,
     138,   139,     0,   140,   135,   136,     0,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   134,
       0,     0,     0,     0,     0,   137,   138,   139,     0,   249,
     135,   136,     0,     0,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   134,     0,     0,     0,     0,
       0,   137,   138,   139,     0,   251,   135,   136,     0,     0,
       0,     0,     0,     0,     0,   141,   142,   143,   144,   145,
     146,     0,     0,     0,     0,     0,     0,   137,   138,   139,
       0,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   409,   143,   144,   145,   146,     1,     2,     3,
       0,     0,     0,     5,     0,     0,     0,     7,     8,     9,
      10,     0,     0,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,    20,
      21
};

static const short yycheck[] =
{
      60,     0,    65,    46,   124,    57,    49,    32,    49,   525,
      62,    25,    73,     0,   216,    77,    78,   123,    62,    71,
      33,    34,    66,    36,    37,    38,    39,    40,    41,   319,
      33,    34,    31,    32,    33,    34,     0,     0,    72,   196,
      36,   361,    38,   200,    40,    70,    87,   204,   151,   565,
     182,    64,    51,    37,   186,    66,    37,   356,    72,   357,
     116,   360,    37,    82,    51,    64,    85,    44,    45,    68,
       0,    70,   337,   179,    93,   118,    70,    62,    72,   386,
     140,   100,   386,    65,   140,    70,    19,    51,    70,    73,
     397,   356,    73,   397,    88,   360,    67,    30,    69,   230,
     231,   232,   233,    36,   129,   209,    83,    84,   415,    46,
      47,   415,   116,     0,   166,   176,   168,   130,   131,    42,
      43,    51,   174,   243,   255,   256,   187,   130,   131,   128,
     129,   130,   131,   185,    67,    66,   123,    65,    25,    26,
      62,   175,    70,   263,    31,    32,    33,    34,   182,   306,
      70,   353,   186,   310,    68,    69,    19,   171,   278,   123,
     216,   175,   482,     0,    51,   221,    73,    30,   182,   230,
     231,    73,   186,    36,   187,   307,   308,    64,   281,   282,
     283,   301,   225,   208,   316,    72,    73,    61,   187,   249,
      64,   251,   179,   249,    73,   251,   209,   210,   211,    73,
     320,   214,   132,    73,   264,   209,   209,   226,    61,   208,
     209,    64,   216,    73,    51,   179,     0,   221,    75,   232,
     233,   234,   235,   522,    19,   116,   524,   284,   285,   232,
     233,   230,   231,   232,   233,    30,   340,   557,   234,   299,
     344,    36,    26,   256,   257,   258,   350,   545,   309,   140,
      65,    66,   304,   256,   519,    70,   576,   522,    85,   311,
     312,   313,    66,   315,   194,    69,    61,    51,   198,    64,
      65,    48,   202,   307,   308,    70,   206,   286,   287,   116,
     386,    76,   316,    70,   171,    72,   123,    74,   175,    73,
      19,   397,   305,   307,   308,   182,   309,   353,   404,   186,
     187,    30,   316,   140,    31,    32,   305,    36,    61,   415,
     309,   354,    65,   603,    61,    68,   419,   449,    65,    86,
     610,    66,   365,    76,    69,   216,   387,   352,    66,    76,
     221,   116,   116,    61,   386,    66,    65,    65,   123,   123,
      65,    70,   179,    70,    88,   397,    73,    76,    76,   353,
      67,   350,   386,   352,    66,   140,   140,    69,   249,    67,
     251,    61,    61,   415,    64,    64,    65,    69,   499,    68,
     501,    74,   386,    73,   292,   293,    65,    76,   509,   216,
      83,    70,    61,   397,   221,    64,    65,    76,   172,    66,
      88,    70,   176,   513,   179,   179,    99,    76,    67,   386,
      69,   128,   129,    76,   456,   525,    65,    66,    81,    82,
     397,    70,   249,    66,   251,   449,    69,   404,   478,    69,
     307,   308,   386,    67,    71,    69,   486,   487,   415,   316,
      19,   216,   216,   397,    71,   449,   221,   221,   499,    61,
     404,    30,    64,    65,    67,   565,    69,    36,    66,   176,
     380,   415,    61,    61,    76,    64,    64,    65,    65,    66,
     187,    72,   353,    70,   249,   249,   251,   251,    76,   366,
     173,    69,    61,    71,   177,   488,    65,    39,   538,    61,
     523,   208,    64,    65,   381,    66,   499,    76,   501,    67,
     542,   134,   135,   136,    76,    70,   509,    72,   558,   386,
     499,    68,   501,    61,    65,    66,    64,    65,   151,    70,
     397,    33,    34,    62,    36,    37,   353,    67,    76,     0,
      65,    66,    66,    74,    68,    70,    33,    34,   588,    36,
      37,    38,    39,    40,    41,    67,   288,   289,   290,   291,
      66,    65,   245,    69,   604,    26,    39,    40,    41,   386,
      31,    32,    33,    34,    66,    66,    68,    69,    69,   249,
     397,   251,   449,    66,    19,    67,    69,   404,   353,   353,
      51,    66,    65,    67,    69,    30,    65,    70,   415,    72,
      19,    36,   309,    64,    66,   369,   483,    69,    66,    68,
      68,    30,    73,   122,   491,    66,   493,    36,    69,    65,
      65,   386,   386,   387,   133,    68,    61,    68,   130,   131,
      65,    69,   397,   397,   398,    70,    67,    61,    68,   404,
     404,    76,    61,   130,   131,   352,    65,    74,    71,    71,
     415,   415,   416,   530,    66,    66,    34,    76,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,    66,    68,   555,    69,
      67,    67,   559,   560,   193,    65,   195,    66,   197,    66,
     199,    66,   201,    65,   203,    69,   205,    73,   207,    67,
      71,   578,     3,    67,    74,    74,     8,   209,   210,    67,
      67,    65,    13,    14,   337,    16,   593,    61,    19,    69,
      66,    62,    71,    65,    67,   591,   187,    67,    67,    30,
     232,   233,    33,   356,    35,    36,   592,   360,   247,   425,
     294,   297,   295,   221,   296,   232,   233,   234,   235,   298,
       3,     4,     5,     6,   256,   352,     9,   350,   344,    12,
      13,    14,    15,    16,    19,    18,    19,    20,    21,    22,
     225,   354,    25,    26,   510,    30,   404,    30,   550,   380,
      33,    36,    35,    36,   526,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    61,    64,
      65,    64,    65,    66,   323,    -1,    -1,    70,   327,    -1,
      -1,    76,   331,    76,    -1,    -1,   335,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    -1,   519,    -1,    -1,   522,
      73,    74,    75,    76,    77,    78,    79,    80,     3,     4,
       5,     6,     7,    88,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,     4,
       5,    29,    30,    -1,     9,    -1,    -1,    -1,    36,    -1,
      15,    -1,    40,    41,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,     3,    -1,
      -1,    36,    -1,    61,    62,    63,    64,    65,    13,    14,
      -1,    16,    -1,    -1,    19,    -1,    -1,    75,    76,    77,
      78,    79,    80,     7,    -1,    30,    10,    11,    33,    -1,
      35,    36,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    27,    28,    29,    -1,    31,    32,    -1,
      34,    -1,    -1,    37,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    13,    14,    -1,    16,    -1,    -1,    19,    73,
      74,    75,    76,    77,    78,    79,    80,     7,    -1,    30,
      10,    11,    33,    -1,    35,    36,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    19,    -1,    27,    28,    29,
      -1,    31,    32,    -1,    34,    -1,    30,    37,    -1,    -1,
      40,    41,    36,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    -1,    61,    -1,    -1,
      64,    65,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,     7,    76,    19,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    30,    -1,    -1,    23,    24,    -1,
      36,    27,    28,    29,    -1,    31,    32,    -1,    34,    -1,
      -1,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,
      76,    77,    78,    79,    80,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    61,    -1,    30,    64,    65,    66,    -1,
      -1,    36,    70,     3,     4,     5,     6,    -1,    76,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    64,
      30,    -1,    -1,    33,    -1,    35,    36,    37,    -1,    74,
       3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    61,    25,    26,    64,    65,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    70,     3,     4,
       5,     6,    -1,    76,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    61,    -1,    30,    64,
      65,    -1,    -1,    19,    36,    70,     3,     4,     5,     6,
      -1,    76,     9,    -1,    30,    12,    13,    14,    15,    16,
      36,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      -1,    -1,    64,    30,    -1,    -1,    33,    -1,    35,    36,
      -1,    -1,    74,    -1,    -1,    61,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    70,     3,     4,     5,     6,    -1,    76,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    61,    25,    26,    64,    65,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    76,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    61,
      25,    26,    64,    65,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,    76,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    61,    25,    26,    64,
      65,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    76,    -1,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    61,    25,    26,    64,    65,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    76,    -1,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      61,    25,    26,    64,    65,    -1,    30,    68,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    70,     3,     4,     5,
       6,    -1,    76,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    61,    25,    26,    64,    -1,
      66,    30,    -1,    -1,    33,    -1,    35,    36,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    64,    30,    66,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    50,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      64,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,
      21,    22,    29,    -1,    25,    26,    -1,    -1,    -1,    30,
      64,    -1,    -1,    40,    41,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    65,    40,
      41,    -1,    -1,    64,    71,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    29,    -1,    -1,    -1,    -1,
      61,    62,    63,    -1,    65,    66,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      -1,    65,    40,    41,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    75,    76,    77,    78,    79,    80,    29,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    -1,    65,    40,    41,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,    77,
      78,    79,    80,    29,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    65,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    29,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    -1,    65,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    29,    -1,    -1,    -1,    -1,
      -1,    61,    62,    63,    -1,    65,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,     3,     4,     5,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,     4,     5,     6,     9,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    25,    26,    30,    33,
      35,    36,    37,    61,    64,    65,    76,    93,   124,   125,
     126,   127,   128,   129,   130,   133,   134,   135,   136,   137,
     140,   141,   142,   143,   144,   145,   146,   147,   157,   158,
     183,   184,   185,   186,   210,   211,   212,   213,   214,   215,
      65,   211,   213,   214,   130,   210,   214,    67,    69,    67,
      69,    64,    65,    76,   202,   203,   204,   205,   206,   207,
     208,   210,   214,   202,   210,   214,    64,   132,   133,   142,
     143,   144,   210,   214,    64,   133,   142,   143,   144,   210,
     214,   132,   143,   133,   142,   143,    67,   132,    67,   133,
     142,   132,   133,   142,    61,    64,    73,   165,    73,   165,
       0,   185,   187,    65,    70,   217,   218,   124,   127,   128,
     129,   130,   177,   192,    29,    40,    41,    61,    62,    63,
      65,    75,    76,    77,    78,    79,    80,    90,    99,   100,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   121,    66,    66,    66,   210,
     214,    65,    76,   210,   213,    65,    76,   202,   210,    65,
     217,    64,    65,   205,   207,   209,    65,   130,   204,   207,
      37,    91,    92,   188,   177,   193,    92,   189,   177,   194,
      92,   190,   177,   195,    92,   191,   177,   196,   128,   130,
     135,   137,   138,   139,   141,   145,   148,   149,   150,   151,
     152,    73,   159,   160,   165,    73,    73,   176,    61,    66,
     127,   128,   129,   130,   136,   137,   161,   162,   163,   164,
      71,    76,   119,    70,   210,   210,   124,   197,   176,    65,
     105,    65,   105,   105,   121,   128,   130,   137,   141,   166,
      62,    40,    41,    65,    70,   101,   102,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    88,   120,   105,
     107,    76,    81,    82,    77,    78,    42,    43,    44,    45,
      83,    84,    46,    47,    75,    85,    86,    48,    49,    87,
      66,    69,   217,   217,   213,   130,    92,    65,    65,   130,
      92,   209,    66,    66,   217,   209,    65,   204,   207,    65,
      88,   167,   176,   198,   176,   167,   176,   199,   176,   167,
     176,   200,   176,   167,   176,   201,   176,    68,   153,   156,
     202,   145,   154,   156,   210,   133,    74,   149,    67,    67,
      69,    67,    69,   148,    69,   173,    88,   159,     7,    10,
      11,    17,    23,    24,    27,    28,    31,    32,    34,    37,
      61,    64,    74,    94,   121,   123,   165,   174,   175,   176,
     177,   178,   179,   180,   181,   182,    65,    76,   204,   210,
     216,   217,   219,   220,   204,   210,   216,    65,    76,   210,
     216,   210,   216,    66,    69,    66,    69,    71,    71,    76,
     119,   176,   166,   166,    66,    65,    76,   216,   216,    66,
      66,   104,   119,   121,    72,    39,   119,   107,   107,   107,
     108,   108,   109,   109,   110,   110,   110,   110,   111,   111,
     112,   113,   114,   115,   116,   121,    67,   119,   167,    65,
     167,    66,   217,   217,    66,    66,   209,    90,    73,   119,
     168,   176,   176,   176,   176,   118,   122,   155,   156,   155,
     154,   153,    74,   160,    74,   122,   173,    67,    65,   122,
     123,    67,    65,    68,   165,   174,    65,    65,   130,   131,
      67,    68,    74,   178,    74,   174,   217,   219,   220,   130,
     216,   130,    50,   163,    61,    71,    71,    66,    66,   130,
      73,   107,    66,    69,    71,    61,    64,   103,   103,    68,
      66,    66,    70,    72,   169,   170,   171,   172,    74,   121,
      68,    67,   123,   174,    67,    34,   121,   121,    65,   174,
      74,    66,    66,    66,   216,   169,   119,   118,   122,   165,
      69,   173,   168,    88,   172,    66,   174,    67,    65,    66,
      66,   121,   217,   173,    71,   170,    74,   174,   123,   121,
     174,   174,    66,    68,    74,   168,    67,    66,     8,    67,
      62,    70,    95,    96,    97,   123,    67,   174,    65,    61,
      66,    68,    69,    66,   121,    71,    67,    95,    97,   174,
      66,    62,    66,    68,    65,    67,    90,    98,   121,    66,
      69,    66,    67,    90
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
#line 558 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 3:
#line 560 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-1].value, +, yyvsp[0].value ); ;}
    break;

  case 20:
#line 615 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier )
	      HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    UNDEF_VAL( yyval.value );
	  ;}
    break;

  case 21:
#line 620 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 22:
#line 621 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.iv++; ;}
    break;

  case 23:
#line 622 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 24:
#line 626 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 25:
#line 627 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 26:
#line 628 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 27:
#line 629 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 28:
#line 630 "ctlib/parser.y"
    {;}
    break;

  case 29:
#line 630 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 30:
#line 631 "ctlib/parser.y"
    {;}
    break;

  case 31:
#line 631 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 32:
#line 632 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 33:
#line 633 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 34:
#line 634 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 35:
#line 638 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 36:
#line 639 "ctlib/parser.y"
    {;}
    break;

  case 37:
#line 643 "ctlib/parser.y"
    {;}
    break;

  case 38:
#line 644 "ctlib/parser.y"
    {;}
    break;

  case 39:
#line 648 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 40:
#line 649 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 41:
#line 650 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 42:
#line 652 "ctlib/parser.y"
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
#line 669 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 44:
#line 670 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 45:
#line 674 "ctlib/parser.y"
    { yyval.oper = '&'; ;}
    break;

  case 46:
#line 675 "ctlib/parser.y"
    { yyval.oper = '*'; ;}
    break;

  case 47:
#line 676 "ctlib/parser.y"
    { yyval.oper = '+'; ;}
    break;

  case 48:
#line 677 "ctlib/parser.y"
    { yyval.oper = '-'; ;}
    break;

  case 49:
#line 678 "ctlib/parser.y"
    { yyval.oper = '~'; ;}
    break;

  case 50:
#line 679 "ctlib/parser.y"
    { yyval.oper = '!'; ;}
    break;

  case 51:
#line 683 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 52:
#line 684 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_CAST; ;}
    break;

  case 53:
#line 688 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 54:
#line 690 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, *, yyvsp[0].value ); ;}
    break;

  case 55:
#line 692 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, /, yyvsp[0].value );
	  ;}
    break;

  case 56:
#line 699 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, %, yyvsp[0].value );
	  ;}
    break;

  case 57:
#line 708 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 58:
#line 710 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, +, yyvsp[0].value ); ;}
    break;

  case 59:
#line 712 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, -, yyvsp[0].value ); ;}
    break;

  case 60:
#line 716 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 61:
#line 718 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <<, yyvsp[0].value ); ;}
    break;

  case 62:
#line 720 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >>, yyvsp[0].value ); ;}
    break;

  case 63:
#line 724 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 64:
#line 726 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <,  yyvsp[0].value ); ;}
    break;

  case 65:
#line 728 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >,  yyvsp[0].value ); ;}
    break;

  case 66:
#line 730 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <=, yyvsp[0].value ); ;}
    break;

  case 67:
#line 732 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >=, yyvsp[0].value ); ;}
    break;

  case 68:
#line 736 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 69:
#line 738 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ==, yyvsp[0].value ); ;}
    break;

  case 70:
#line 740 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, !=, yyvsp[0].value ); ;}
    break;

  case 71:
#line 744 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 72:
#line 746 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &, yyvsp[0].value ); ;}
    break;

  case 73:
#line 750 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 74:
#line 752 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ^, yyvsp[0].value ); ;}
    break;

  case 75:
#line 756 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 76:
#line 758 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, |, yyvsp[0].value ); ;}
    break;

  case 77:
#line 762 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 78:
#line 764 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &&, yyvsp[0].value ); ;}
    break;

  case 79:
#line 768 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 80:
#line 770 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ||, yyvsp[0].value ); ;}
    break;

  case 81:
#line 774 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 82:
#line 776 "ctlib/parser.y"
    { yyval.value = yyvsp[-4].value.iv ? yyvsp[-2].value : yyvsp[0].value; yyval.value.flags |= yyvsp[-4].value.flags; ;}
    break;

  case 83:
#line 780 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 84:
#line 781 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 85:
#line 785 "ctlib/parser.y"
    {;}
    break;

  case 86:
#line 786 "ctlib/parser.y"
    {;}
    break;

  case 87:
#line 787 "ctlib/parser.y"
    {;}
    break;

  case 88:
#line 788 "ctlib/parser.y"
    {;}
    break;

  case 89:
#line 789 "ctlib/parser.y"
    {;}
    break;

  case 90:
#line 790 "ctlib/parser.y"
    {;}
    break;

  case 91:
#line 791 "ctlib/parser.y"
    {;}
    break;

  case 92:
#line 792 "ctlib/parser.y"
    {;}
    break;

  case 93:
#line 793 "ctlib/parser.y"
    {;}
    break;

  case 94:
#line 794 "ctlib/parser.y"
    {;}
    break;

  case 95:
#line 795 "ctlib/parser.y"
    {;}
    break;

  case 96:
#line 799 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 97:
#line 800 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 98:
#line 804 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 100:
#line 810 "ctlib/parser.y"
    {;}
    break;

  case 101:
#line 848 "ctlib/parser.y"
    {;}
    break;

  case 102:
#line 849 "ctlib/parser.y"
    {;}
    break;

  case 103:
#line 850 "ctlib/parser.y"
    {;}
    break;

  case 104:
#line 851 "ctlib/parser.y"
    {;}
    break;

  case 105:
#line 859 "ctlib/parser.y"
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
#line 881 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 107:
#line 887 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-4].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-2].pDecl );
	    else if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 108:
#line 898 "ctlib/parser.y"
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
#line 918 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 110:
#line 924 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-4].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-2].pDecl );
	    else if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 111:
#line 936 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 112:
#line 940 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 113:
#line 941 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 114:
#line 947 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 115:
#line 951 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 116:
#line 952 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 117:
#line 958 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 118:
#line 959 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 119:
#line 960 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;}
    break;

  case 124:
#line 974 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval; ;}
    break;

  case 125:
#line 975 "ctlib/parser.y"
    { yyval.uval = 0;  ;}
    break;

  case 129:
#line 985 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 130:
#line 986 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 131:
#line 987 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 132:
#line 988 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 133:
#line 992 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 134:
#line 993 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 135:
#line 994 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval;               ;}
    break;

  case 136:
#line 995 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 137:
#line 1000 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 138:
#line 1005 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 139:
#line 1010 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 140:
#line 1017 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 141:
#line 1018 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 142:
#line 1019 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 143:
#line 1023 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 144:
#line 1024 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 145:
#line 1025 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 146:
#line 1029 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 147:
#line 1030 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 148:
#line 1034 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 149:
#line 1039 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 150:
#line 1044 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 151:
#line 1051 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 152:
#line 1052 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 153:
#line 1053 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 154:
#line 1057 "ctlib/parser.y"
    { yyval.uval = T_TYPEDEF;  ;}
    break;

  case 155:
#line 1058 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 156:
#line 1059 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 157:
#line 1060 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 158:
#line 1061 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 159:
#line 1062 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 160:
#line 1066 "ctlib/parser.y"
    { yyval.uval = T_INT;      ;}
    break;

  case 161:
#line 1067 "ctlib/parser.y"
    { yyval.uval = T_CHAR;     ;}
    break;

  case 162:
#line 1068 "ctlib/parser.y"
    { yyval.uval = T_SHORT;    ;}
    break;

  case 163:
#line 1069 "ctlib/parser.y"
    { yyval.uval = T_LONG;     ;}
    break;

  case 164:
#line 1070 "ctlib/parser.y"
    { yyval.uval = T_FLOAT;    ;}
    break;

  case 165:
#line 1071 "ctlib/parser.y"
    { yyval.uval = T_DOUBLE;   ;}
    break;

  case 166:
#line 1072 "ctlib/parser.y"
    { yyval.uval = T_SIGNED;   ;}
    break;

  case 167:
#line 1073 "ctlib/parser.y"
    { yyval.uval = T_UNSIGNED; ;}
    break;

  case 168:
#line 1074 "ctlib/parser.y"
    { yyval.uval = T_VOID;     ;}
    break;

  case 169:
#line 1078 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 170:
#line 1079 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 171:
#line 1084 "ctlib/parser.y"
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
#line 1100 "ctlib/parser.y"
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
#line 1131 "ctlib/parser.y"
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
#line 1157 "ctlib/parser.y"
    {
	    yyval.context.uval     = yyvsp[0].uval;
	    yyval.context.ctx.pFI  = PSTATE->pFI;
	    yyval.context.ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 175:
#line 1165 "ctlib/parser.y"
    { yyval.uval = T_STRUCT; ;}
    break;

  case 176:
#line 1166 "ctlib/parser.y"
    { yyval.uval = T_UNION;  ;}
    break;

  case 177:
#line 1171 "ctlib/parser.y"
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

  case 178:
#line 1186 "ctlib/parser.y"
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

  case 179:
#line 1200 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 180:
#line 1201 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 181:
#line 1202 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 182:
#line 1207 "ctlib/parser.y"
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

  case 183:
#line 1221 "ctlib/parser.y"
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

  case 184:
#line 1236 "ctlib/parser.y"
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

  case 185:
#line 1250 "ctlib/parser.y"
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

  case 186:
#line 1266 "ctlib/parser.y"
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
#line 1280 "ctlib/parser.y"
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

  case 188:
#line 1290 "ctlib/parser.y"
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

  case 189:
#line 1303 "ctlib/parser.y"
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
#line 1313 "ctlib/parser.y"
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
#line 1325 "ctlib/parser.y"
    { yyval.ival = -1; ;}
    break;

  case 192:
#line 1326 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].ival; ;}
    break;

  case 193:
#line 1330 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].value.iv; ;}
    break;

  case 194:
#line 1335 "ctlib/parser.y"
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

  case 195:
#line 1351 "ctlib/parser.y"
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

  case 196:
#line 1383 "ctlib/parser.y"
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

  case 197:
#line 1409 "ctlib/parser.y"
    {
	    yyval.context.ctx.pFI  = PSTATE->pFI;
	    yyval.context.ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 198:
#line 1417 "ctlib/parser.y"
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

  case 199:
#line 1431 "ctlib/parser.y"
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

  case 200:
#line 1449 "ctlib/parser.y"
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

  case 201:
#line 1459 "ctlib/parser.y"
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

  case 206:
#line 1481 "ctlib/parser.y"
    {;}
    break;

  case 207:
#line 1482 "ctlib/parser.y"
    {;}
    break;

  case 208:
#line 1483 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 209:
#line 1484 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 210:
#line 1485 "ctlib/parser.y"
    {;}
    break;

  case 211:
#line 1486 "ctlib/parser.y"
    {;}
    break;

  case 212:
#line 1487 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 213:
#line 1488 "ctlib/parser.y"
    {;}
    break;

  case 214:
#line 1489 "ctlib/parser.y"
    {;}
    break;

  case 215:
#line 1490 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 216:
#line 1491 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 217:
#line 1492 "ctlib/parser.y"
    {;}
    break;

  case 218:
#line 1493 "ctlib/parser.y"
    {;}
    break;

  case 219:
#line 1494 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 220:
#line 1502 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 221:
#line 1503 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 222:
#line 1508 "ctlib/parser.y"
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

  case 223:
#line 1523 "ctlib/parser.y"
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

  case 224:
#line 1539 "ctlib/parser.y"
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

  case 225:
#line 1553 "ctlib/parser.y"
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

  case 226:
#line 1573 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = PSTATE->pCPC->int_size;
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 227:
#line 1580 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
	              PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 231:
#line 1596 "ctlib/parser.y"
    {;}
    break;

  case 239:
#line 1616 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[0].idOrType ); ;}
    break;

  case 249:
#line 1636 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-2].idOrType ); ;}
    break;

  case 267:
#line 1675 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-1].idOrType ); ;}
    break;

  case 278:
#line 1701 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 279:
#line 1702 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 280:
#line 1703 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 281:
#line 1704 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 282:
#line 1705 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 283:
#line 1706 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 284:
#line 1707 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 285:
#line 1708 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 286:
#line 1709 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 287:
#line 1710 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 288:
#line 1712 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 289:
#line 1712 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 290:
#line 1713 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 291:
#line 1713 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 292:
#line 1714 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 293:
#line 1714 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 294:
#line 1715 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 295:
#line 1715 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 296:
#line 1716 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 297:
#line 1716 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 298:
#line 1718 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 299:
#line 1718 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 300:
#line 1719 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 301:
#line 1719 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 302:
#line 1720 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 303:
#line 1720 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 304:
#line 1721 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 305:
#line 1721 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 306:
#line 1722 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 307:
#line 1722 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 308:
#line 1726 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 309:
#line 1727 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 310:
#line 1731 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 311:
#line 1732 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 312:
#line 1737 "ctlib/parser.y"
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

  case 313:
#line 1749 "ctlib/parser.y"
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

  case 314:
#line 1762 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 315:
#line 1769 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 316:
#line 1771 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 317:
#line 1777 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 318:
#line 1785 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 319:
#line 1787 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 320:
#line 1797 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 321:
#line 1799 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 322:
#line 1805 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 323:
#line 1811 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 324:
#line 1817 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 325:
#line 1825 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 326:
#line 1827 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 327:
#line 1832 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 328:
#line 1840 "ctlib/parser.y"
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

  case 329:
#line 1851 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 330:
#line 1855 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 331:
#line 1856 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 332:
#line 1860 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 333:
#line 1862 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 334:
#line 1868 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 335:
#line 1877 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 336:
#line 1881 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 337:
#line 1883 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 338:
#line 1891 "ctlib/parser.y"
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

  case 339:
#line 1903 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 340:
#line 1907 "ctlib/parser.y"
    {;}
    break;

  case 341:
#line 1908 "ctlib/parser.y"
    {;}
    break;

  case 342:
#line 1909 "ctlib/parser.y"
    {;}
    break;

  case 343:
#line 1914 "ctlib/parser.y"
    {
	    if( yyvsp[-3].pDecl )
	      decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  ;}
    break;

  case 344:
#line 1918 "ctlib/parser.y"
    {;}
    break;

  case 345:
#line 1920 "ctlib/parser.y"
    {
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;

  case 346:
#line 1927 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 347:
#line 1928 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 348:
#line 1930 "ctlib/parser.y"
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

  case 349:
#line 1943 "ctlib/parser.y"
    { yyval.list = yyvsp[0].list;   ;}
    break;

  case 350:
#line 1944 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 351:
#line 1945 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 352:
#line 1950 "ctlib/parser.y"
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

  case 353:
#line 1964 "ctlib/parser.y"
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

  case 354:
#line 1977 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 355:
#line 1979 "ctlib/parser.y"
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

  case 356:
#line 1998 "ctlib/parser.y"
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

  case 357:
#line 2020 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 358:
#line 2025 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 359:
#line 2030 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 360:
#line 2035 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 361:
#line 2042 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 362:
#line 2043 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 363:
#line 2045 "ctlib/parser.y"
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

  case 364:
#line 2056 "ctlib/parser.y"
    {
	    yyval.absDecl = yyvsp[-2].absDecl;
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 4535 "ctlib/parser.c"

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


#line 2063 "ctlib/parser.y"



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


