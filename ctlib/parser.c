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
* $Date: 2003/06/10 15:12:09 +0200 $
* $Revision: 25 $
* $Snapshot: /Convert-Binary-C/0.41 $
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

#include "util/ccattr.h"
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
#line 386 "ctlib/parser.y"
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
#line 573 "ctlib/parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 585 "ctlib/parser.c"

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
#define YYLAST   2220

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  131
/* YYNRULES -- Number of rules. */
#define YYNRULES  365
/* YYNRULES -- Number of states. */
#define YYNSTATES  613

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
     122,   123,   128,   131,   134,   141,   149,   151,   153,   155,
     159,   161,   164,   167,   170,   173,   178,   180,   182,   184,
     186,   188,   190,   192,   197,   199,   203,   207,   211,   213,
     217,   221,   223,   227,   231,   233,   237,   241,   245,   249,
     251,   255,   259,   261,   265,   267,   271,   273,   277,   279,
     283,   285,   289,   291,   297,   299,   303,   305,   307,   309,
     311,   313,   315,   317,   319,   321,   323,   325,   327,   331,
     333,   334,   336,   339,   342,   345,   348,   353,   358,   364,
     369,   374,   380,   382,   384,   386,   388,   390,   392,   394,
     397,   400,   402,   405,   406,   408,   410,   412,   414,   416,
     418,   421,   424,   427,   430,   432,   435,   438,   441,   444,
     447,   450,   452,   455,   458,   460,   463,   466,   468,   470,
     473,   476,   479,   481,   484,   487,   489,   491,   493,   495,
     497,   499,   501,   503,   505,   507,   509,   511,   513,   515,
     517,   519,   521,   526,   532,   535,   537,   539,   541,   543,
     546,   549,   552,   555,   557,   560,   564,   567,   571,   574,
     576,   579,   581,   582,   584,   587,   592,   598,   601,   603,
     605,   609,   612,   614,   618,   620,   624,   626,   630,   632,
     635,   638,   641,   643,   646,   649,   651,   654,   657,   660,
     662,   665,   668,   670,   674,   676,   678,   680,   683,   685,
     688,   689,   692,   696,   701,   703,   706,   711,   712,   715,
     717,   720,   724,   727,   729,   731,   733,   735,   737,   739,
     741,   745,   750,   754,   757,   761,   765,   770,   772,   775,
     777,   780,   783,   789,   797,   803,   809,   817,   827,   831,
     834,   837,   841,   842,   844,   846,   849,   851,   853,   855,
     856,   860,   861,   866,   867,   872,   873,   878,   879,   884,
     885,   889,   890,   895,   896,   901,   902,   907,   908,   913,
     914,   919,   920,   926,   927,   933,   934,   940,   941,   947,
     949,   951,   953,   955,   957,   960,   962,   964,   967,   971,
     975,   980,   982,   987,   993,   996,  1000,  1004,  1009,  1014,
    1016,  1020,  1022,  1024,  1026,  1029,  1033,  1036,  1040,  1045,
    1047,  1051,  1053,  1056,  1060,  1065,  1069,  1074,  1076,  1078,
    1080,  1082,  1085,  1089,  1092,  1096,  1100,  1105,  1110,  1112,
    1115,  1118,  1122,  1126,  1130,  1134
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     182,     0,    -1,    62,    -1,    90,    62,    -1,    37,    65,
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
      -1,   100,    41,    -1,    65,   166,    66,    73,   169,    74,
      -1,    65,   166,    66,    73,   169,    69,    74,    -1,    61,
      -1,    64,    -1,   119,    -1,   104,    69,   119,    -1,   100,
      -1,    40,   105,    -1,    41,   105,    -1,   106,   107,    -1,
      29,   105,    -1,    29,    65,   166,    66,    -1,    75,    -1,
      76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
     105,    -1,    65,   166,    66,   107,    -1,   107,    -1,   108,
      76,   107,    -1,   108,    81,   107,    -1,   108,    82,   107,
      -1,   108,    -1,   109,    77,   108,    -1,   109,    78,   108,
      -1,   109,    -1,   110,    42,   109,    -1,   110,    43,   109,
      -1,   110,    -1,   111,    83,   110,    -1,   111,    84,   110,
      -1,   111,    44,   110,    -1,   111,    45,   110,    -1,   111,
      -1,   112,    46,   111,    -1,   112,    47,   111,    -1,   112,
      -1,   113,    75,   112,    -1,   113,    -1,   114,    85,   113,
      -1,   114,    -1,   115,    86,   114,    -1,   115,    -1,   116,
      48,   115,    -1,   116,    -1,   117,    49,   116,    -1,   117,
      -1,   117,    87,   121,    68,   118,    -1,   118,    -1,   105,
     120,   119,    -1,    88,    -1,    51,    -1,    52,    -1,    53,
      -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,
      -1,    59,    -1,    60,    -1,   119,    -1,   121,    69,   119,
      -1,   118,    -1,    -1,   121,    -1,   136,    67,    -1,   137,
      67,    -1,   126,    67,    -1,   125,    67,    -1,   129,   209,
      92,   167,    -1,   130,   209,    92,   167,    -1,   125,    69,
     209,    92,   167,    -1,   127,   201,    92,   167,    -1,   128,
     201,    92,   167,    -1,   126,    69,   201,    92,   167,    -1,
     134,    -1,   136,    -1,   140,    -1,   135,    -1,   137,    -1,
     141,    -1,   142,    -1,   130,   142,    -1,   129,   132,    -1,
     133,    -1,   130,   133,    -1,    -1,   130,    -1,   142,    -1,
     133,    -1,    19,    -1,    36,    -1,    30,    -1,   129,   143,
      -1,   135,   142,    -1,   134,   132,    -1,   134,   143,    -1,
     143,    -1,   130,   143,    -1,   135,   133,    -1,   135,   143,
      -1,   129,   144,    -1,   137,   142,    -1,   136,   132,    -1,
     144,    -1,   130,   144,    -1,   137,   133,    -1,   145,    -1,
     130,   145,    -1,   137,   133,    -1,   138,    -1,   141,    -1,
     141,   142,    -1,   129,    64,    -1,   140,   132,    -1,    64,
      -1,   130,    64,    -1,   141,   133,    -1,    14,    -1,    16,
      -1,    33,    -1,     3,    -1,    13,    -1,    35,    -1,     5,
      -1,    15,    -1,    21,    -1,     9,    -1,    20,    -1,     4,
      -1,    25,    -1,    22,    -1,    26,    -1,   145,    -1,   157,
      -1,   146,    73,   148,    74,    -1,   146,   165,    73,   148,
      74,    -1,   146,   165,    -1,   147,    -1,     6,    -1,    18,
      -1,   149,    -1,   148,   149,    -1,   152,    67,    -1,   151,
      67,    -1,   150,    67,    -1,   139,    -1,   130,   154,    -1,
     151,    69,   154,    -1,   128,   153,    -1,   152,    69,   153,
      -1,   201,   155,    -1,   156,    -1,   209,   155,    -1,   156,
      -1,    -1,   156,    -1,    68,   122,    -1,   158,    73,   159,
      74,    -1,   158,   165,    73,   159,    74,    -1,   158,   165,
      -1,    12,    -1,   160,    -1,   159,    69,   160,    -1,   159,
      69,    -1,   165,    -1,   165,    88,   122,    -1,   162,    -1,
     162,    69,    50,    -1,   163,    -1,   162,    69,   163,    -1,
     127,    -1,   127,   215,    -1,   127,   209,    -1,   127,   203,
      -1,   129,    -1,   129,   215,    -1,   129,   209,    -1,   128,
      -1,   128,   215,    -1,   128,   209,    -1,   128,   203,    -1,
     130,    -1,   130,   215,    -1,   130,   209,    -1,    61,    -1,
     164,    69,    61,    -1,    61,    -1,    64,    -1,   128,    -1,
     128,   215,    -1,   130,    -1,   130,   215,    -1,    -1,    88,
     168,    -1,    73,   169,    74,    -1,    73,   169,    69,    74,
      -1,   119,    -1,   170,   168,    -1,   169,    69,   170,   168,
      -1,    -1,   171,    88,    -1,   172,    -1,   171,   172,    -1,
      70,   122,    71,    -1,    72,   165,    -1,   174,    -1,   175,
      -1,   178,    -1,   179,    -1,   180,    -1,   181,    -1,    94,
      -1,   165,    68,   173,    -1,    11,   122,    68,   173,    -1,
      27,    68,   173,    -1,    73,    74,    -1,    73,   176,    74,
      -1,    73,   177,    74,    -1,    73,   176,   177,    74,    -1,
     124,    -1,   176,   124,    -1,   173,    -1,   177,   173,    -1,
     123,    67,    -1,    32,    65,   121,    66,   173,    -1,    32,
      65,   121,    66,   173,     8,   173,    -1,    10,    65,   121,
      66,   173,    -1,    34,    65,   121,    66,   173,    -1,    31,
     173,    34,    65,   121,    66,    67,    -1,    24,    65,   123,
      67,   123,    67,   123,    66,   173,    -1,    28,   165,    67,
      -1,    23,    67,    -1,     7,    67,    -1,    17,   123,    67,
      -1,    -1,   183,    -1,   184,    -1,   183,   184,    -1,   185,
      -1,   124,    -1,    93,    -1,    -1,   209,   186,   175,    -1,
      -1,   127,   209,   187,   175,    -1,    -1,   128,   209,   188,
     175,    -1,    -1,   129,   209,   189,   175,    -1,    -1,   130,
     209,   190,   175,    -1,    -1,   213,   191,   175,    -1,    -1,
     127,   213,   192,   175,    -1,    -1,   128,   213,   193,   175,
      -1,    -1,   129,   213,   194,   175,    -1,    -1,   130,   213,
     195,   175,    -1,    -1,   213,   176,   196,   175,    -1,    -1,
     127,   213,   176,   197,   175,    -1,    -1,   128,   213,   176,
     198,   175,    -1,    -1,   129,   213,   176,   199,   175,    -1,
      -1,   130,   213,   176,   200,   175,    -1,   209,    -1,   202,
      -1,   206,    -1,   203,    -1,    64,    -1,    64,   216,    -1,
     204,    -1,   205,    -1,    76,   203,    -1,    76,   130,   203,
      -1,    65,   204,    66,    -1,    65,   204,    66,   216,    -1,
     207,    -1,    76,    65,   208,    66,    -1,    76,   130,    65,
     208,    66,    -1,    76,   206,    -1,    76,   130,   206,    -1,
      65,   206,    66,    -1,    65,   208,   216,    66,    -1,    65,
     206,    66,   216,    -1,    64,    -1,    65,   208,    66,    -1,
     210,    -1,   212,    -1,   211,    -1,    76,   209,    -1,    76,
     130,   209,    -1,   212,   216,    -1,    65,   210,    66,    -1,
      65,   210,    66,   216,    -1,    61,    -1,    65,   212,    66,
      -1,   214,    -1,    76,   213,    -1,    76,   130,   213,    -1,
     212,    65,   164,    66,    -1,    65,   213,    66,    -1,    65,
     213,    66,   216,    -1,   218,    -1,   219,    -1,   216,    -1,
     217,    -1,    65,    66,    -1,    65,   161,    66,    -1,    70,
      71,    -1,    70,   119,    71,    -1,    70,    76,    71,    -1,
     217,    70,   119,    71,    -1,   217,    70,    76,    71,    -1,
      76,    -1,    76,   130,    -1,    76,   215,    -1,    76,   130,
     215,    -1,    65,   218,    66,    -1,    65,   219,    66,    -1,
      65,   216,    66,    -1,    65,   218,    66,   216,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   551,   551,   552,   560,   563,   565,   569,   573,   574,
     576,   579,   585,   587,   591,   592,   596,   597,   601,   602,
     607,   613,   614,   615,   619,   620,   621,   622,   623,   623,
     624,   624,   625,   626,   627,   628,   632,   633,   637,   638,
     642,   643,   644,   645,   663,   664,   668,   669,   670,   671,
     672,   673,   677,   678,   682,   683,   685,   692,   702,   703,
     705,   710,   711,   713,   718,   719,   721,   723,   725,   730,
     731,   733,   738,   739,   744,   745,   750,   751,   756,   757,
     762,   763,   768,   769,   774,   775,   779,   780,   781,   782,
     783,   784,   785,   786,   787,   788,   789,   793,   794,   798,
     802,   804,   842,   843,   844,   845,   852,   874,   880,   891,
     914,   920,   932,   937,   938,   943,   948,   949,   955,   956,
     957,   961,   962,   965,   967,   971,   972,   976,   977,   978,
     982,   983,   984,   985,   989,   990,   991,   992,   996,  1001,
    1006,  1014,  1015,  1016,  1020,  1021,  1022,  1026,  1027,  1030,
    1035,  1040,  1048,  1049,  1050,  1054,  1055,  1056,  1057,  1058,
    1059,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,
    1075,  1076,  1080,  1096,  1127,  1153,  1162,  1163,  1167,  1180,
    1193,  1194,  1195,  1199,  1213,  1228,  1242,  1258,  1272,  1282,
    1295,  1305,  1318,  1319,  1323,  1327,  1343,  1375,  1401,  1409,
    1423,  1439,  1446,  1456,  1469,  1470,  1474,  1475,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,
    1491,  1492,  1500,  1501,  1505,  1520,  1536,  1550,  1569,  1576,
    1586,  1588,  1592,  1593,  1594,  1598,  1599,  1602,  1604,  1608,
    1609,  1613,  1614,  1619,  1620,  1621,  1622,  1623,  1624,  1625,
    1629,  1630,  1631,  1635,  1636,  1637,  1638,  1642,  1643,  1647,
    1648,  1652,  1656,  1657,  1658,  1662,  1663,  1664,  1668,  1669,
    1670,  1671,  1677,  1679,  1683,  1684,  1688,  1689,  1690,  1694,
    1694,  1696,  1696,  1698,  1698,  1700,  1700,  1702,  1702,  1705,
    1705,  1706,  1706,  1707,  1707,  1708,  1708,  1709,  1709,  1711,
    1711,  1712,  1712,  1713,  1713,  1714,  1714,  1715,  1715,  1719,
    1720,  1724,  1725,  1729,  1741,  1755,  1762,  1763,  1769,  1778,
    1779,  1790,  1791,  1797,  1803,  1809,  1818,  1819,  1824,  1832,
    1844,  1848,  1849,  1853,  1854,  1860,  1869,  1874,  1875,  1883,
    1896,  1900,  1901,  1902,  1906,  1911,  1912,  1920,  1921,  1922,
    1936,  1937,  1938,  1942,  1943,  1957,  1971,  1990,  2012,  2017,
    2022,  2027,  2035,  2036,  2037,  2048
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
     102,   100,   100,   100,   100,   100,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   108,   109,   109,
     109,   110,   110,   110,   111,   111,   111,   111,   111,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   122,
     123,   123,   124,   124,   124,   124,   125,   125,   125,   126,
     126,   126,   127,   127,   127,   128,   128,   128,   129,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   135,   135,   135,   135,   136,   136,
     136,   137,   137,   137,   138,   138,   138,   139,   139,   140,
     140,   140,   141,   141,   141,   142,   142,   142,   142,   142,
     142,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   144,   145,   145,   145,   146,   147,   147,   148,   148,
     149,   149,   149,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   157,   157,   157,   158,   159,
     159,   159,   160,   160,   161,   161,   162,   162,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   164,   164,   165,   165,   166,   166,   166,   166,
     167,   167,   168,   168,   168,   169,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   173,   173,   173,   173,   173,
     174,   174,   174,   175,   175,   175,   175,   176,   176,   177,
     177,   178,   179,   179,   179,   180,   180,   180,   181,   181,
     181,   181,   182,   182,   183,   183,   184,   184,   184,   186,
     185,   187,   185,   188,   185,   189,   185,   190,   185,   191,
     185,   192,   185,   193,   185,   194,   185,   195,   185,   196,
     185,   197,   185,   198,   185,   199,   185,   200,   185,   201,
     201,   202,   202,   203,   203,   203,   204,   204,   204,   205,
     205,   206,   206,   206,   206,   206,   207,   207,   207,   208,
     208,   209,   209,   210,   210,   210,   211,   211,   211,   212,
     212,   213,   213,   213,   214,   214,   214,   215,   215,   215,
     216,   216,   216,   217,   217,   217,   217,   217,   218,   218,
     218,   218,   219,   219,   219,   219
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     4,     0,     1,     5,     6,     8,
      10,    12,     0,     1,     1,     3,     4,     7,     1,     3,
       1,     1,     1,     3,     1,     4,     3,     4,     0,     4,
       0,     4,     2,     2,     6,     7,     1,     1,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     1,     2,     2,     2,     2,     4,     4,     5,     4,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     0,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     1,     2,
       2,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     2,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     3,     2,     3,     2,     1,
       2,     1,     0,     1,     2,     4,     5,     2,     1,     1,
       3,     2,     1,     3,     1,     3,     1,     3,     1,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       2,     2,     1,     3,     1,     1,     1,     2,     1,     2,
       0,     2,     3,     4,     1,     2,     4,     0,     2,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     2,     5,     7,     5,     5,     7,     9,     3,     2,
       2,     3,     0,     1,     1,     2,     1,     1,     1,     0,
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
     272,   158,   166,   161,   176,   164,   198,   159,   155,   162,
     156,   177,   127,   165,   163,   168,   167,   169,   129,   157,
     160,   128,     0,   339,   152,     0,     0,   278,   277,     0,
       0,     0,     0,     0,     0,   121,   112,   115,   113,   116,
     114,   117,   118,   134,   141,   170,     0,   175,   171,     0,
       0,   273,   274,   276,   279,   331,   333,   332,   289,   341,
       0,     0,     0,     0,     0,   334,   342,   105,     0,   104,
       0,   313,     0,     0,     5,   310,   312,   315,   316,   311,
     321,   309,   291,     5,   309,   293,   150,   120,   126,   125,
     130,   138,     5,   295,   153,   122,   119,   135,   142,     5,
     297,   132,   133,   136,   131,   137,   102,   140,   103,   143,
     139,   151,   154,   149,   224,   225,     0,   174,     0,   197,
       1,   275,     0,     0,     0,   336,   350,   257,     0,     0,
       0,     0,   299,     0,     0,     0,     0,    20,     2,    21,
       0,    46,    47,    48,    49,    50,    51,    22,    24,    40,
      52,     0,    54,    58,    61,    64,    69,    72,    74,    76,
      78,    80,    82,    84,    97,     0,   337,   340,   345,   335,
     343,     0,     0,     5,   332,     0,     0,     5,   309,     0,
     314,   329,     0,     0,     0,     0,     0,     0,   317,   324,
       0,     6,   230,     0,   301,     0,   230,     0,   303,     0,
     230,     0,   305,     0,   230,     0,   307,     0,     0,     0,
     115,   116,   147,   183,   117,   170,     0,   178,     0,     0,
       0,     0,     0,   199,   202,     0,   100,   280,   222,   351,
     208,   215,   212,   219,   113,   116,     0,   204,   206,     0,
     353,    47,     0,     0,     5,     5,   258,     0,   290,     0,
      44,     0,    41,    42,     0,   226,   228,   116,   117,     0,
       3,    32,    33,     0,     0,     0,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    86,     0,    52,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   338,   346,     0,     0,   230,     0,     0,     0,
     230,     0,   319,   326,     0,     0,     0,   318,   325,     0,
       0,   109,   282,     0,   292,   110,   284,     0,   294,   106,
     286,     0,   296,   107,   288,     0,   298,     0,   186,   189,
     192,   170,   184,   191,   192,   143,   172,   179,   182,   181,
       0,   180,     0,     0,   201,   195,     0,     0,     0,     0,
       0,   100,     0,     0,     0,     0,   100,     0,     0,   123,
      20,   152,   253,   249,   101,     0,     0,   259,   243,   244,
     100,   100,   245,   246,   247,   248,     0,   358,   211,   210,
     209,   349,   347,   348,   218,   217,   216,     0,   358,   214,
     213,   221,   220,   352,     0,   344,     0,   355,   354,    47,
       0,   300,     0,     0,    23,     0,   358,   227,   229,     0,
      26,     0,    38,     0,     0,     0,    85,    55,    56,    57,
      59,    60,    62,    63,    67,    68,    65,    66,    70,    71,
      73,    75,    77,    79,    81,     0,     7,    98,   108,     0,
     111,   330,   320,   328,   327,   322,     0,     0,   237,   234,
     231,   302,   304,   306,   308,    99,   194,   188,   193,   190,
     185,   187,   173,   200,   203,   196,   270,     0,     0,     0,
     269,   100,   100,     0,     0,     0,     0,   124,     0,   261,
     100,   254,   100,   255,   260,     0,     0,     0,   359,   360,
     359,   205,   207,   223,   357,   356,    45,     0,   359,   237,
      53,    27,     0,    25,    36,    37,    29,    31,     0,   323,
       4,     0,     0,     0,     0,     0,   239,     0,   100,   271,
       0,   252,   268,     0,     0,     0,     0,   250,   256,   364,
     362,   363,   361,     0,    39,    83,     0,   242,   237,   232,
     235,   238,   240,   100,   251,   100,     0,   100,   100,     0,
     365,   237,    34,   241,   233,     0,   264,     0,     0,   262,
     265,     0,    12,    35,   236,   100,     0,   100,     8,     0,
       0,     0,    13,    14,     0,   266,   263,     0,     0,     0,
      12,     0,   100,     0,     0,     9,     0,    15,   267,    16,
       0,     0,     0,     0,    10,    18,     0,     0,     0,     0,
      17,    11,    19
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   147,   191,   200,    27,   373,   581,   582,   583,   606,
     148,   149,   265,   266,   516,   421,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   278,   374,   466,   375,   127,    29,    30,   128,   129,
     130,   131,   488,    87,    35,    36,    37,    38,    39,   212,
     213,    40,    41,    42,    43,    44,    45,    46,    47,   216,
     217,   218,   219,   220,   338,   342,   467,   339,    48,    49,
     222,   223,   236,   237,   238,   239,   376,   259,   321,   460,
     523,   524,   525,   526,   377,   378,   379,   132,   381,   382,
     383,   384,   385,    50,    51,    52,    53,   122,   193,   197,
     201,   205,   133,   195,   199,   203,   207,   247,   323,   327,
     331,   335,    74,    75,    76,    77,    78,   184,    80,   185,
      65,    55,    56,   174,    63,    59,   499,   391,   126,   392,
     393
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -547
static const short yypact[] =
{
    1327,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,   -47,  -547,  -547,   229,   283,  -547,  -547,    56,
     158,   264,   264,  1568,  1605,  -547,  2184,  2184,   944,  1018,
     849,   849,  -547,  -547,  -547,  -547,    46,  -547,  -547,   251,
       7,  1327,  -547,  -547,  -547,  -547,  -547,     2,  1896,  -547,
    2028,   -44,   303,   -35,   283,  -547,  -547,  -547,   331,  -547,
     407,     9,   561,   470,    23,  -547,  -547,  -547,  -547,  -547,
    -547,    13,  1896,    23,    33,  1896,  -547,  -547,  -547,  -547,
    -547,  -547,    31,  1896,  -547,  -547,  -547,  -547,  -547,    39,
    1896,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  1929,    51,    74,   108,
    -547,  -547,   112,  1784,  1923,  -547,   -26,  -547,   407,   407,
    1642,  1679,  1896,   112,  2054,  2080,  2080,  -547,  -547,  -547,
     726,  -547,  -547,  -547,  -547,  -547,  -547,   145,  -547,   321,
     723,  2028,  -547,   118,    87,   129,    -6,   352,   179,   177,
     191,   241,   -33,  -547,  -547,    92,     9,  -547,     9,  -547,
    -547,   331,   496,    23,     9,   794,   678,    23,  -547,  1821,
    -547,  -547,   561,   238,   252,     9,   561,  1045,  -547,  -547,
     230,  -547,   220,   112,  1896,   112,   220,   112,  1896,   112,
     220,   112,  1896,   112,   220,   112,  1896,   112,   541,   657,
    1282,    63,  -547,  -547,    54,   266,  1224,  -547,   270,   309,
     318,  1929,    80,  -547,   268,    74,   813,  -547,  -547,  -547,
     551,   551,  1364,  1432,   849,   849,   286,   295,  -547,   171,
    -547,   353,   360,  2106,    23,    23,  -547,   112,  -547,   726,
    -547,   726,  -547,  -547,   219,   200,  1716,    63,    63,   322,
    -547,  -547,  -547,  1949,  2028,   341,   403,  -547,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  2028,  -547,
    -547,  2028,  2028,  2028,  2028,  2028,  2028,  2028,  2028,  2028,
    2028,  2028,  2028,  2028,  2028,  2028,  2028,  2028,  2028,  2028,
     406,  2028,  -547,  -547,   345,   496,   220,   794,   794,  1103,
     220,   378,     9,     9,   415,   396,   561,  -547,  -547,   416,
    1976,  -547,  -547,   112,  -547,  -547,  -547,   112,  -547,  -547,
    -547,   112,  -547,  -547,  -547,   112,  -547,  2028,  -547,  -547,
     418,   431,  -547,  -547,   418,   435,  -547,  -547,  -547,  -547,
     207,  -547,   541,  1465,    74,  -547,  2028,   144,   440,   446,
    2028,  2028,   457,   464,   468,    74,  1113,   474,   482,    63,
     501,   545,  -547,  -547,   504,   552,   555,  -547,  -547,  -547,
     891,   965,  -547,  -547,  -547,  -547,  1191,   634,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  1259,   319,  -547,
    -547,  -547,  -547,  -547,  1856,  -547,   563,  -547,  -547,   558,
     570,  -547,   577,   579,  -547,  1500,   693,  -547,  -547,  2002,
    -547,   339,  -547,   398,   256,   256,  -547,  -547,  -547,  -547,
     118,   118,    87,    87,   129,   129,   129,   129,    -6,    -6,
     352,   179,   177,   191,   241,   494,  -547,  -547,  -547,   794,
    -547,  -547,  -547,  -547,  -547,  -547,   448,   -58,   420,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  2028,   587,   584,
    -547,  2028,  1113,   593,   631,  2028,  2028,    63,   606,  -547,
    1113,  -547,  1039,  -547,  -547,   607,   608,   614,   634,  -547,
     319,  -547,  -547,  -547,  -547,  -547,   615,   615,   693,   420,
    -547,  -547,  2028,  -547,  -547,  -547,  -547,  -547,  2028,  -547,
    -547,  2028,    74,   195,  1976,   123,  -547,   366,  1113,  -547,
     622,  -547,  -547,   627,   380,   453,  2028,  -547,  -547,  -547,
       9,  -547,  -547,   297,  -547,  -547,   623,  -547,   342,  -547,
    -547,  -547,  -547,  1113,  -547,  2028,  2028,  1113,  1113,   476,
    -547,   385,  -547,  -547,  -547,  1976,  -547,   629,   499,   698,
    -547,   640,    21,  -547,  -547,  2028,   642,  1113,  -547,   646,
     654,   462,   647,  -547,   651,  -547,  -547,  2028,   648,   661,
      21,    21,  1113,   505,   662,  -547,   490,  -547,  -547,  -547,
     669,   670,   416,  2028,  -547,   145,   542,   583,   673,   416,
    -547,  -547,   145
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -547,  -302,  -547,   307,  -547,  -547,   146,  -547,   162,  -547,
    -547,  -547,  -547,  -547,   332,  -547,   294,  -547,  -103,   374,
     317,   412,   375,   465,   466,   469,   473,   486,  -547,  -271,
    -115,  -547,   -60,  -315,  -347,   141,  -547,  -547,    36,    50,
      37,   151,  -547,    17,   -13,  -547,   254,   -83,   242,  -547,
    -547,  -547,   261,   560,   517,   308,   -69,  -547,  -547,   550,
    -203,  -547,  -547,  -547,   433,   436,   452,  -114,  -547,  -547,
     572,   444,  -547,  -547,   395,  -547,   -43,   384,   150,  -495,
     291,  -546,  -547,   282,   128,  -547,   437,    20,   428,  -547,
    -547,  -547,  -547,  -547,  -547,   758,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,   -21,  -547,   -61,   -29,  -547,    27,  -547,  -140,
       1,    67,  -547,   111,    30,  -547,    25,   -52,  -547,  -288,
    -174
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -288
static const short yytable[] =
{
     165,    54,   565,   117,   260,   125,   119,   120,   520,   242,
     125,    83,   188,   347,   479,   565,   298,   457,    60,   180,
      88,    95,   166,    88,   103,    88,   109,    88,   112,   550,
      58,   168,    81,    84,    92,    99,    31,    33,   288,   289,
     234,   474,   311,   183,   243,   478,   315,   215,   280,   177,
      32,    95,    54,   101,   299,   107,    66,   111,    79,    79,
     190,    82,    85,    93,   100,   169,   465,   123,   190,   173,
     574,   178,   124,    12,   179,   224,   190,   290,   291,   124,
     254,    58,    12,   579,    18,   465,  -281,    31,    33,   465,
      21,   580,    61,    18,   170,   343,   234,    79,   496,    21,
     189,    32,   194,    66,  -285,   198,  -283,   114,    83,   496,
     115,    57,  -287,   202,   302,   188,   303,    88,    95,   116,
     206,  -148,   125,    67,   221,    68,   317,   496,   410,   178,
     178,   244,   245,   314,   530,   114,    62,    57,   115,    61,
     341,    28,    57,    57,    57,    57,   183,   215,   422,   354,
     347,    34,   215,   183,   355,    79,    79,   183,   300,   230,
     232,   301,    57,   426,   284,   285,   208,   311,   315,   388,
     394,   286,   287,   231,    95,    57,   456,    64,   427,   428,
     429,   225,   224,    62,    57,   226,   447,   340,   169,   254,
     255,   254,    28,   521,   281,   522,    95,   103,   345,   282,
     283,   112,    34,   189,   423,   459,   546,   260,   567,   178,
     344,   551,   497,   354,   318,   230,   232,   170,   475,    88,
      95,    88,   109,   497,   187,    69,   468,    70,   584,   231,
     468,   389,   395,   399,   401,    79,   343,   405,    61,   445,
     406,   497,    61,    95,   109,   112,   380,   545,   317,    61,
     465,   107,   125,    61,   294,   390,   396,   400,   402,   314,
     452,   453,   295,   314,   548,   415,   208,   209,    23,   549,
     124,   208,   171,   246,   233,   337,   416,   296,   183,   183,
     417,   418,   304,   172,   215,   414,   304,   183,   301,   297,
      23,   256,    95,    62,    25,   319,    95,    62,    57,   255,
     605,   255,    12,   234,   312,    26,   169,   612,   320,   456,
     169,   224,   114,    18,   234,   115,   510,   514,   313,    21,
     515,   234,   483,   305,   118,    23,   188,   309,    71,    72,
     233,   340,   234,  -144,   495,   246,   318,   348,    12,   246,
      73,    91,    98,   246,    23,   495,   325,   246,    25,    18,
     329,   344,   403,   178,   333,    21,   356,   183,   211,    26,
     -30,   261,   262,   495,   404,   235,   561,   209,   123,   167,
     210,   562,   209,   124,    61,    61,   349,   214,   350,    79,
      23,   192,   257,    61,   397,   351,   263,   352,   419,   124,
     196,   264,    23,   -28,   210,   398,   171,   544,   292,   293,
     256,   258,   256,   208,   314,   511,   204,   172,   512,   459,
     179,   167,   521,   424,   522,   124,   564,   527,   304,   304,
     183,   235,   230,   232,   407,   534,   535,    62,   250,   252,
     253,   408,   553,   230,   232,   301,   231,   317,    91,    98,
     230,   232,   425,   179,   451,   279,   557,   231,   124,   301,
     459,   230,   232,    61,   231,   521,   448,   522,   211,   573,
     450,   179,   455,   211,    61,   231,   124,   301,    23,   513,
     210,    71,   175,   446,    95,   210,   559,   214,   138,   547,
     306,   454,   214,   176,   310,    95,   337,    95,   560,    12,
     521,   257,   522,   257,   484,    95,   568,   304,  -145,   169,
      18,   169,  -146,   210,   209,   210,    21,   476,   304,   494,
     258,   477,   258,   179,   519,    12,    61,    98,   124,   558,
     487,   246,   301,   542,   480,   542,    18,   593,   589,   481,
     590,    23,    21,   542,    71,   186,   482,   233,   498,   485,
      91,    98,   571,   607,   572,   301,    73,   486,   233,   500,
      90,    97,   204,   102,   105,   233,   601,    23,   602,   227,
     304,   171,   518,   301,    98,   576,   233,   508,   301,  -224,
     248,   599,   172,   301,   301,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,    89,    96,   211,    89,   104,    89,   110,
      89,   113,    23,   432,   433,    71,   175,   210,   608,   337,
     531,   609,    23,  -225,   214,    71,   386,   176,   537,   489,
     494,   124,    23,   490,   503,   181,   182,   387,   235,   504,
     322,   279,   324,   412,   326,   413,   328,    73,   330,   235,
     332,   505,   334,   506,   336,   507,   235,    90,    97,   610,
     279,   529,   301,    12,   279,   528,   554,   235,   430,   431,
     532,     2,     3,     4,    18,   533,     5,   438,   439,     6,
      21,   536,     9,   539,   540,    11,    12,    13,    14,    15,
     541,   566,    16,    17,   411,   569,   570,    18,   509,   555,
      89,    96,   556,    21,   563,    23,   575,    12,    71,   386,
     434,   435,   436,   437,   124,   586,   577,   578,    18,   585,
     387,   587,    12,   279,    21,   588,   591,   592,    23,   594,
     598,    94,   171,    18,   600,   337,    97,   105,   595,    21,
       2,     3,     4,   172,   603,     5,   596,   604,     6,    23,
     611,     9,    71,   308,    11,    12,    13,    14,    15,    90,
      97,    16,    17,   597,   176,   134,    18,   517,   415,   440,
     461,   441,    21,   124,   462,   442,   135,   136,   463,   416,
     443,   353,   464,    97,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   444,   471,   470,   137,   138,   139,
      24,   140,    89,    96,    89,   110,   469,   357,   473,   502,
     543,   141,   142,   143,   144,   145,   146,   552,   492,   121,
       0,   277,   279,     0,     0,   279,     1,     2,     3,     4,
     358,     0,     5,   359,   360,     6,     7,     8,     9,    10,
     361,    11,    12,    13,    14,    15,   362,   363,    16,    17,
     364,   365,   134,    18,   366,   367,    19,   368,    20,    21,
     369,     0,     1,   135,   136,    23,     0,     0,   181,   307,
       0,     0,     7,     8,     0,    10,     0,     0,    12,     0,
     176,     0,     0,     0,   370,   138,   139,   371,   140,    18,
       0,     0,    19,     0,    20,    21,   226,   372,   141,   142,
     143,   144,   145,   146,     1,     2,     3,     4,   358,     0,
       5,   359,   360,     6,     7,     8,     9,    10,   361,    11,
      12,    13,    14,    15,   362,   363,    16,    17,   364,   365,
     134,    18,   366,   367,    19,   368,    20,    21,   369,     0,
       0,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,   370,   138,   139,   371,   140,     7,     8,     0,
      10,     0,     0,    12,   226,   491,   141,   142,   143,   144,
     145,   146,   358,     0,    18,   359,   360,    19,     0,    20,
      21,     0,   361,     0,     0,     0,     0,     0,   362,   363,
       0,     0,   364,   365,   134,     0,   366,   367,     0,   368,
       0,     0,   369,     0,     0,   135,   136,     0,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,   370,   138,   139,   115,
     140,     7,     8,     0,    10,     0,     0,    12,   226,   493,
     141,   142,   143,   144,   145,   146,   358,     0,    18,   359,
     360,    19,     0,    20,    21,     0,   361,     0,     0,     0,
       0,     0,   362,   363,    12,     0,   364,   365,   134,     0,
     366,   367,     0,   368,     0,    18,   369,     0,     0,   135,
     136,    21,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   138,   139,   115,   140,     0,    23,     0,     0,    71,
     316,     0,   226,   538,   141,   142,   143,   144,   145,   146,
     358,    73,    12,   359,   360,     0,     0,     0,     0,     0,
     361,     0,     0,    18,     0,     0,   362,   363,     0,    21,
     364,   365,   134,     0,   366,   367,     0,   368,     0,     0,
     369,     0,     0,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,     0,    71,   449,     0,
       0,     0,     0,     0,   370,   138,   139,   115,   140,   176,
       0,     0,     0,     0,     0,     0,   226,     0,   141,   142,
     143,   144,   145,   146,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
       0,    18,     0,     0,    19,     0,    20,    21,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     0,     0,     9,
       0,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,    23,     0,    18,    24,   386,   229,     0,     0,
      21,   124,     1,     2,     3,     4,     0,   387,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     2,     3,    24,    18,
       0,     5,    19,     0,    20,    21,     0,     9,   346,     0,
       0,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    21,     0,
      23,     0,     0,    24,   397,   229,     0,     0,     0,   124,
       1,     2,     3,     4,     0,   398,     5,     0,     0,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,    18,     0,     0,
      19,     0,    20,    21,    22,     0,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,    23,    16,
      17,    24,    25,     0,    18,     0,     0,    19,     0,    20,
      21,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,    86,   397,
       0,     0,     0,     0,   124,     1,     2,     3,     4,     0,
     398,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     0,
       0,     0,    18,     0,     0,    19,     0,    20,    21,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     0,     0,
       9,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,    23,     0,    18,    94,   397,     0,     0,
       0,    21,   124,     1,     2,     3,     4,     0,   398,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,    24,
      18,     0,     0,    19,     0,    20,    21,     0,     0,   472,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,   415,   229,     0,     0,     0,
     124,     1,     2,     3,     4,     0,   416,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,    19,     0,    20,    21,     0,     0,     0,     1,     2,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,    23,
      16,    17,    86,    25,     0,    18,     0,     0,    19,     0,
      20,    21,     0,     0,    26,     1,     2,     3,     4,     0,
       0,     5,     0,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,    23,    16,    17,    94,
      25,     0,    18,     0,     0,    19,     0,    20,    21,     0,
       0,    26,     1,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,    23,    16,    17,    86,   171,     0,    18,
       0,     0,    19,     0,    20,    21,     0,     0,   172,     0,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     0,
       0,     9,     0,     0,    11,    12,    13,    14,    15,     0,
      23,    16,    17,    94,   171,     0,    18,     0,     0,     0,
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
       2,     3,     4,     0,     0,     5,   501,     0,     6,     7,
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
       0,     0,     0,     0,     0,   509,     0,   141,   142,   143,
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
      60,     0,   548,    46,    62,    57,    49,     0,    66,   124,
      62,    32,    73,   216,   361,   561,    49,   319,    65,    71,
      33,    34,    66,    36,    37,    38,    39,    40,    41,   524,
       0,    66,    31,    32,    33,    34,     0,     0,    44,    45,
     123,   356,   182,    72,    70,   360,   186,   116,   151,    70,
       0,    64,    51,    36,    87,    38,    26,    40,    31,    32,
      37,    31,    32,    33,    34,    64,   337,    65,    37,    68,
     565,    70,    70,    19,    65,   118,    37,    83,    84,    70,
     140,    51,    19,    62,    30,   356,    73,    51,    51,   360,
      36,    70,    25,    30,    64,   209,   179,    70,   386,    36,
      73,    51,    82,    73,    73,    85,    73,    61,   129,   397,
      64,     0,    73,    93,   166,   176,   168,   130,   131,    73,
     100,    67,   174,    67,    73,    69,   187,   415,   243,   128,
     129,   130,   131,   185,   481,    61,    25,    26,    64,    72,
     209,     0,    31,    32,    33,    34,   175,   216,   263,    69,
     353,     0,   221,   182,    74,   128,   129,   186,    66,   123,
     123,    69,    51,   278,    77,    78,   116,   307,   308,   230,
     231,    42,    43,   123,   187,    64,   316,    26,   281,   282,
     283,    73,   225,    72,    73,    73,   301,   208,   187,   249,
     140,   251,    51,    70,    76,    72,   209,   210,   211,    81,
      82,   214,    51,   176,   264,   320,   521,    62,   555,   208,
     209,    88,   386,    69,   187,   179,   179,   187,    74,   232,
     233,   234,   235,   397,    73,    67,   340,    69,   575,   179,
     344,   230,   231,   232,   233,   208,   350,    66,   171,   299,
      69,   415,   175,   256,   257,   258,   226,   518,   309,   182,
     521,   234,   304,   186,    75,   230,   231,   232,   233,   311,
     312,   313,    85,   315,    69,    65,   216,   116,    61,    74,
      70,   221,    65,   132,   123,    68,    76,    86,   307,   308,
     255,   256,   171,    76,   353,    66,   175,   316,    69,    48,
      61,   140,   305,   182,    65,    65,   309,   186,   187,   249,
     602,   251,    19,   386,    66,    76,   305,   609,    88,   449,
     309,   354,    61,    30,   397,    64,   419,    61,    66,    36,
      64,   404,   365,   172,    73,    61,   387,   176,    64,    65,
     179,   352,   415,    67,   386,   194,   309,    67,    19,   198,
      76,    33,    34,   202,    61,   397,   196,   206,    65,    30,
     200,   350,    66,   352,   204,    36,    88,   386,   116,    76,
      39,    40,    41,   415,    69,   123,    69,   216,    65,    66,
     116,    74,   221,    70,   307,   308,    67,   116,    69,   352,
      61,    74,   140,   316,    65,    67,    65,    69,    66,    70,
      83,    70,    61,    72,   140,    76,    65,   512,    46,    47,
     249,   140,   251,   353,   456,    66,    99,    76,    69,   524,
      65,    66,    70,    72,    72,    70,    74,   477,   307,   308,
     449,   179,   386,   386,    71,   485,   486,   316,   134,   135,
     136,    71,    66,   397,   397,    69,   386,   498,   130,   131,
     404,   404,    39,    65,    66,   151,    66,   397,    70,    69,
     565,   415,   415,   386,   404,    70,   306,    72,   216,    74,
     310,    65,    66,   221,   397,   415,    70,    69,    61,    71,
     216,    64,    65,    67,   487,   221,   536,   216,    62,   522,
     173,    66,   221,    76,   177,   498,    68,   500,   540,    19,
      70,   249,    72,   251,   366,   508,   556,   386,    67,   498,
      30,   500,    67,   249,   353,   251,    36,    67,   397,   381,
     249,    65,   251,    65,    66,    19,   449,   209,    70,    66,
     369,   380,    69,   498,    67,   500,    30,   587,    66,    65,
      68,    61,    36,   508,    64,    65,    68,   386,   387,    65,
     232,   233,    66,   603,    68,    69,    76,    65,   397,   398,
      33,    34,   245,    36,    37,   404,    66,    61,    68,   122,
     449,    65,    68,    69,   256,    66,   415,   416,    69,    68,
     133,    66,    76,    69,    69,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    33,    34,   353,    36,    37,    38,    39,
      40,    41,    61,   286,   287,    64,    65,   353,    66,    68,
     482,    69,    61,    68,   353,    64,    65,    76,   490,    67,
     492,    70,    61,    68,    61,    64,    65,    76,   386,    71,
     193,   337,   195,   249,   197,   251,   199,    76,   201,   397,
     203,    71,   205,    66,   207,    66,   404,   130,   131,    66,
     356,    67,    69,    19,   360,    68,   528,   415,   284,   285,
      67,     4,     5,     6,    30,    34,     9,   292,   293,    12,
      36,    65,    15,    66,    66,    18,    19,    20,    21,    22,
      66,   553,    25,    26,   247,   557,   558,    30,    73,    67,
     130,   131,    65,    36,    71,    61,    67,    19,    64,    65,
     288,   289,   290,   291,    70,   577,     8,    67,    30,    67,
      76,    65,    19,   419,    36,    61,    69,    66,    61,    71,
     592,    64,    65,    30,    62,    68,   209,   210,    67,    36,
       4,     5,     6,    76,    65,     9,   590,    67,    12,    61,
      67,    15,    64,    65,    18,    19,    20,    21,    22,   232,
     233,    25,    26,   591,    76,    29,    30,   425,    65,   294,
     323,   295,    36,    70,   327,   296,    40,    41,   331,    76,
     297,   221,   335,   256,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   298,   352,   350,    61,    62,    63,
      64,    65,   232,   233,   234,   235,   344,   225,   354,   404,
     509,    75,    76,    77,    78,    79,    80,   525,   380,    51,
      -1,    88,   518,    -1,    -1,   521,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,     3,    40,    41,    61,    -1,    -1,    64,    65,
      -1,    -1,    13,    14,    -1,    16,    -1,    -1,    19,    -1,
      76,    -1,    -1,    -1,    61,    62,    63,    64,    65,    30,
      -1,    -1,    33,    -1,    35,    36,    73,    74,    75,    76,
      77,    78,    79,    80,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    13,    14,    -1,
      16,    -1,    -1,    19,    73,    74,    75,    76,    77,    78,
      79,    80,     7,    -1,    30,    10,    11,    33,    -1,    35,
      36,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    -1,    34,
      -1,    -1,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    13,    14,    -1,    16,    -1,    -1,    19,    73,    74,
      75,    76,    77,    78,    79,    80,     7,    -1,    30,    10,
      11,    33,    -1,    35,    36,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    19,    -1,    27,    28,    29,    -1,
      31,    32,    -1,    34,    -1,    30,    37,    -1,    -1,    40,
      41,    36,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    61,    -1,    -1,    64,
      65,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
       7,    76,    19,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    30,    -1,    -1,    23,    24,    -1,    36,
      27,    28,    29,    -1,    31,    32,    -1,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,
      77,    78,    79,    80,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    61,    -1,    30,    64,    65,    66,    -1,    -1,
      36,    70,     3,     4,     5,     6,    -1,    76,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,     4,     5,    64,    30,
      -1,     9,    33,    -1,    35,    36,    -1,    15,    74,    -1,
      -1,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      61,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
       3,     4,     5,     6,    -1,    76,     9,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    36,    37,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    61,    25,
      26,    64,    65,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    70,     3,     4,     5,     6,    -1,
      76,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    61,    -1,    30,    64,    65,    -1,    -1,
      -1,    36,    70,     3,     4,     5,     6,    -1,    76,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    64,
      30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      70,     3,     4,     5,     6,    -1,    76,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    61,
      25,    26,    64,    65,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,    76,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    61,    25,    26,    64,
      65,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    76,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    61,    25,    26,    64,    65,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    -1,    -1,    76,    -1,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      61,    25,    26,    64,    65,    -1,    30,    -1,    -1,    -1,
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
     182,   183,   184,   185,   209,   210,   211,   212,   213,   214,
      65,   210,   212,   213,   130,   209,   213,    67,    69,    67,
      69,    64,    65,    76,   201,   202,   203,   204,   205,   206,
     207,   209,   213,   201,   209,   213,    64,   132,   133,   142,
     143,   144,   209,   213,    64,   133,   142,   143,   144,   209,
     213,   132,   143,   133,   142,   143,    67,   132,    67,   133,
     142,   132,   133,   142,    61,    64,    73,   165,    73,   165,
       0,   184,   186,    65,    70,   216,   217,   124,   127,   128,
     129,   130,   176,   191,    29,    40,    41,    61,    62,    63,
      65,    75,    76,    77,    78,    79,    80,    90,    99,   100,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   121,    66,    66,    66,   209,
     213,    65,    76,   209,   212,    65,    76,   201,   209,    65,
     216,    64,    65,   204,   206,   208,    65,   130,   203,   206,
      37,    91,    92,   187,   176,   192,    92,   188,   176,   193,
      92,   189,   176,   194,    92,   190,   176,   195,   128,   130,
     135,   137,   138,   139,   141,   145,   148,   149,   150,   151,
     152,    73,   159,   160,   165,    73,    73,   175,    61,    66,
     127,   128,   129,   130,   136,   137,   161,   162,   163,   164,
      71,    76,   119,    70,   209,   209,   124,   196,   175,    65,
     105,    65,   105,   105,   121,   128,   130,   137,   141,   166,
      62,    40,    41,    65,    70,   101,   102,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    88,   120,   105,
     107,    76,    81,    82,    77,    78,    42,    43,    44,    45,
      83,    84,    46,    47,    75,    85,    86,    48,    49,    87,
      66,    69,   216,   216,   212,   130,    92,    65,    65,   130,
      92,   208,    66,    66,   216,   208,    65,   203,   206,    65,
      88,   167,   175,   197,   175,   167,   175,   198,   175,   167,
     175,   199,   175,   167,   175,   200,   175,    68,   153,   156,
     201,   145,   154,   156,   209,   133,    74,   149,    67,    67,
      69,    67,    69,   148,    69,    74,    88,   159,     7,    10,
      11,    17,    23,    24,    27,    28,    31,    32,    34,    37,
      61,    64,    74,    94,   121,   123,   165,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    65,    76,   203,   209,
     215,   216,   218,   219,   203,   209,   215,    65,    76,   209,
     215,   209,   215,    66,    69,    66,    69,    71,    71,    76,
     119,   175,   166,   166,    66,    65,    76,   215,   215,    66,
      66,   104,   119,   121,    72,    39,   119,   107,   107,   107,
     108,   108,   109,   109,   110,   110,   110,   110,   111,   111,
     112,   113,   114,   115,   116,   121,    67,   119,   167,    65,
     167,    66,   216,   216,    66,    66,   208,    90,    73,   119,
     168,   175,   175,   175,   175,   118,   122,   155,   156,   155,
     154,   153,    74,   160,   122,    74,    67,    65,   122,   123,
      67,    65,    68,   165,   173,    65,    65,   130,   131,    67,
      68,    74,   177,    74,   173,   216,   218,   219,   130,   215,
     130,    50,   163,    61,    71,    71,    66,    66,   130,    73,
     107,    66,    69,    71,    61,    64,   103,   103,    68,    66,
      66,    70,    72,   169,   170,   171,   172,   121,    68,    67,
     123,   173,    67,    34,   121,   121,    65,   173,    74,    66,
      66,    66,   215,   169,   119,   118,   122,   165,    69,    74,
     168,    88,   172,    66,   173,    67,    65,    66,    66,   121,
     216,    69,    74,    71,    74,   170,   173,   123,   121,   173,
     173,    66,    68,    74,   168,    67,    66,     8,    67,    62,
      70,    95,    96,    97,   123,    67,   173,    65,    61,    66,
      68,    69,    66,   121,    71,    67,    95,    97,   173,    66,
      62,    66,    68,    65,    67,    90,    98,   121,    66,    69,
      66,    67,    90
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
#line 551 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 3:
#line 553 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-1].value, +, yyvsp[0].value ); ;}
    break;

  case 20:
#line 608 "ctlib/parser.y"
    {
	    if( yyvsp[0].identifier )
	      HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    UNDEF_VAL( yyval.value );
	  ;}
    break;

  case 21:
#line 613 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 22:
#line 614 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.iv++; ;}
    break;

  case 23:
#line 615 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 24:
#line 619 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 25:
#line 620 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 26:
#line 621 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 27:
#line 622 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 28:
#line 623 "ctlib/parser.y"
    {;}
    break;

  case 29:
#line 623 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 30:
#line 624 "ctlib/parser.y"
    {;}
    break;

  case 31:
#line 624 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 32:
#line 625 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 33:
#line 626 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 34:
#line 627 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 35:
#line 628 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 36:
#line 632 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 37:
#line 633 "ctlib/parser.y"
    {;}
    break;

  case 38:
#line 637 "ctlib/parser.y"
    {;}
    break;

  case 39:
#line 638 "ctlib/parser.y"
    {;}
    break;

  case 40:
#line 642 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 41:
#line 643 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 42:
#line 644 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 43:
#line 646 "ctlib/parser.y"
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

  case 44:
#line 663 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 45:
#line 664 "ctlib/parser.y"
    { yyval.value = yyvsp[-1].value; ;}
    break;

  case 46:
#line 668 "ctlib/parser.y"
    { yyval.oper = '&'; ;}
    break;

  case 47:
#line 669 "ctlib/parser.y"
    { yyval.oper = '*'; ;}
    break;

  case 48:
#line 670 "ctlib/parser.y"
    { yyval.oper = '+'; ;}
    break;

  case 49:
#line 671 "ctlib/parser.y"
    { yyval.oper = '-'; ;}
    break;

  case 50:
#line 672 "ctlib/parser.y"
    { yyval.oper = '~'; ;}
    break;

  case 51:
#line 673 "ctlib/parser.y"
    { yyval.oper = '!'; ;}
    break;

  case 52:
#line 677 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 53:
#line 678 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_CAST; ;}
    break;

  case 54:
#line 682 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 55:
#line 684 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, *, yyvsp[0].value ); ;}
    break;

  case 56:
#line 686 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, /, yyvsp[0].value );
	  ;}
    break;

  case 57:
#line 693 "ctlib/parser.y"
    {
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, %, yyvsp[0].value );
	  ;}
    break;

  case 58:
#line 702 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 59:
#line 704 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, +, yyvsp[0].value ); ;}
    break;

  case 60:
#line 706 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, -, yyvsp[0].value ); ;}
    break;

  case 61:
#line 710 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 62:
#line 712 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <<, yyvsp[0].value ); ;}
    break;

  case 63:
#line 714 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >>, yyvsp[0].value ); ;}
    break;

  case 64:
#line 718 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 65:
#line 720 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <,  yyvsp[0].value ); ;}
    break;

  case 66:
#line 722 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >,  yyvsp[0].value ); ;}
    break;

  case 67:
#line 724 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, <=, yyvsp[0].value ); ;}
    break;

  case 68:
#line 726 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, >=, yyvsp[0].value ); ;}
    break;

  case 69:
#line 730 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 70:
#line 732 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ==, yyvsp[0].value ); ;}
    break;

  case 71:
#line 734 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, !=, yyvsp[0].value ); ;}
    break;

  case 72:
#line 738 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 73:
#line 740 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &, yyvsp[0].value ); ;}
    break;

  case 74:
#line 744 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 75:
#line 746 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ^, yyvsp[0].value ); ;}
    break;

  case 76:
#line 750 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 77:
#line 752 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, |, yyvsp[0].value ); ;}
    break;

  case 78:
#line 756 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 79:
#line 758 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, &&, yyvsp[0].value ); ;}
    break;

  case 80:
#line 762 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 81:
#line 764 "ctlib/parser.y"
    { BINARY_OP( yyval.value, yyvsp[-2].value, ||, yyvsp[0].value ); ;}
    break;

  case 82:
#line 768 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 83:
#line 770 "ctlib/parser.y"
    { yyval.value = yyvsp[-4].value.iv ? yyvsp[-2].value : yyvsp[0].value; yyval.value.flags |= yyvsp[-4].value.flags; ;}
    break;

  case 84:
#line 774 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 85:
#line 775 "ctlib/parser.y"
    { UNDEF_VAL( yyval.value ); ;}
    break;

  case 86:
#line 779 "ctlib/parser.y"
    {;}
    break;

  case 87:
#line 780 "ctlib/parser.y"
    {;}
    break;

  case 88:
#line 781 "ctlib/parser.y"
    {;}
    break;

  case 89:
#line 782 "ctlib/parser.y"
    {;}
    break;

  case 90:
#line 783 "ctlib/parser.y"
    {;}
    break;

  case 91:
#line 784 "ctlib/parser.y"
    {;}
    break;

  case 92:
#line 785 "ctlib/parser.y"
    {;}
    break;

  case 93:
#line 786 "ctlib/parser.y"
    {;}
    break;

  case 94:
#line 787 "ctlib/parser.y"
    {;}
    break;

  case 95:
#line 788 "ctlib/parser.y"
    {;}
    break;

  case 96:
#line 789 "ctlib/parser.y"
    {;}
    break;

  case 97:
#line 793 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 98:
#line 794 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 99:
#line 798 "ctlib/parser.y"
    { yyval.value = yyvsp[0].value; ;}
    break;

  case 101:
#line 804 "ctlib/parser.y"
    {;}
    break;

  case 102:
#line 842 "ctlib/parser.y"
    {;}
    break;

  case 103:
#line 843 "ctlib/parser.y"
    {;}
    break;

  case 104:
#line 844 "ctlib/parser.y"
    {;}
    break;

  case 105:
#line 845 "ctlib/parser.y"
    {;}
    break;

  case 106:
#line 853 "ctlib/parser.y"
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

  case 107:
#line 875 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 108:
#line 881 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-4].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-2].pDecl );
	    else if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 109:
#line 892 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.pTypedefList = NULL;
	    }
	    else {
	      if( yyvsp[-3].tspec.tflags & T_TYPEDEF ) {
	        if( (yyvsp[-3].tspec.tflags & ANY_TYPE_NAME) == 0 )
	          yyvsp[-3].tspec.tflags |= T_INT;
	        else if( yyvsp[-3].tspec.tflags & T_ENUM )
	          ((EnumSpecifier *) yyvsp[-3].tspec.ptr)->tflags |= T_HASTYPEDEF;
	        else if( yyvsp[-3].tspec.tflags & (T_STRUCT | T_UNION) )
	          ((Struct *) yyvsp[-3].tspec.ptr)->tflags |= T_HASTYPEDEF;
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

  case 110:
#line 915 "ctlib/parser.y"
    {
	    yyval.pTypedefList = NULL;
	    if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 111:
#line 921 "ctlib/parser.y"
    {
	    yyval.pTypedefList = yyvsp[-4].pTypedefList;
	    if( yyval.pTypedefList != NULL )
	      MAKE_TYPEDEF( yyval.pTypedefList, yyvsp[-2].pDecl );
	    else if( yyvsp[-2].pDecl )
	      decl_delete( EX_DECL( yyvsp[-2].pDecl ) );
	  ;}
    break;

  case 112:
#line 933 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 113:
#line 937 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 114:
#line 938 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 115:
#line 944 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;}
    break;

  case 116:
#line 948 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 117:
#line 949 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 118:
#line 955 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 119:
#line 956 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;      ;}
    break;

  case 120:
#line 957 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;}
    break;

  case 125:
#line 971 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval; ;}
    break;

  case 126:
#line 972 "ctlib/parser.y"
    { yyval.uval = 0;  ;}
    break;

  case 130:
#line 982 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 131:
#line 983 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 132:
#line 984 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 133:
#line 985 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 134:
#line 989 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 135:
#line 990 "ctlib/parser.y"
    { yyval.uval = yyvsp[0].uval;               ;}
    break;

  case 136:
#line 991 "ctlib/parser.y"
    { yyval.uval = yyvsp[-1].uval;               ;}
    break;

  case 137:
#line 992 "ctlib/parser.y"
    { yyval.uval = LLC_OR( yyvsp[-1].uval, yyvsp[0].uval ); ;}
    break;

  case 138:
#line 997 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 139:
#line 1002 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 140:
#line 1007 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 141:
#line 1014 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 142:
#line 1015 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 143:
#line 1016 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 144:
#line 1020 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 145:
#line 1021 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 146:
#line 1022 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 147:
#line 1026 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 148:
#line 1027 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 149:
#line 1031 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 150:
#line 1036 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;}
    break;

  case 151:
#line 1041 "ctlib/parser.y"
    {
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;}
    break;

  case 152:
#line 1048 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 153:
#line 1049 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 154:
#line 1050 "ctlib/parser.y"
    { yyval.tspec = yyvsp[-1].tspec; ;}
    break;

  case 155:
#line 1054 "ctlib/parser.y"
    { yyval.uval = T_TYPEDEF;  ;}
    break;

  case 156:
#line 1055 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 157:
#line 1056 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 158:
#line 1057 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 159:
#line 1058 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 160:
#line 1059 "ctlib/parser.y"
    { yyval.uval = 0;          ;}
    break;

  case 161:
#line 1063 "ctlib/parser.y"
    { yyval.uval = T_INT;      ;}
    break;

  case 162:
#line 1064 "ctlib/parser.y"
    { yyval.uval = T_CHAR;     ;}
    break;

  case 163:
#line 1065 "ctlib/parser.y"
    { yyval.uval = T_SHORT;    ;}
    break;

  case 164:
#line 1066 "ctlib/parser.y"
    { yyval.uval = T_LONG;     ;}
    break;

  case 165:
#line 1067 "ctlib/parser.y"
    { yyval.uval = T_FLOAT;    ;}
    break;

  case 166:
#line 1068 "ctlib/parser.y"
    { yyval.uval = T_DOUBLE;   ;}
    break;

  case 167:
#line 1069 "ctlib/parser.y"
    { yyval.uval = T_SIGNED;   ;}
    break;

  case 168:
#line 1070 "ctlib/parser.y"
    { yyval.uval = T_UNSIGNED; ;}
    break;

  case 169:
#line 1071 "ctlib/parser.y"
    { yyval.uval = T_VOID;     ;}
    break;

  case 170:
#line 1075 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 171:
#line 1076 "ctlib/parser.y"
    { yyval.tspec = yyvsp[0].tspec; ;}
    break;

  case 172:
#line 1081 "ctlib/parser.y"
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

  case 173:
#line 1097 "ctlib/parser.y"
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

  case 174:
#line 1128 "ctlib/parser.y"
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

  case 175:
#line 1154 "ctlib/parser.y"
    {
	    yyval.context.uval     = yyvsp[0].uval;
	    yyval.context.ctx.pFI  = PSTATE->pFI;
	    yyval.context.ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 176:
#line 1162 "ctlib/parser.y"
    { yyval.uval = T_STRUCT; ;}
    break;

  case 177:
#line 1163 "ctlib/parser.y"
    { yyval.uval = T_UNION;  ;}
    break;

  case 178:
#line 1168 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = LL_new();
	      LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	      LL_unshift( PSTATE->structDeclListsList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting struct declaration list (%p) (count=%d)",
	                         yyval.list, LL_count(PSTATE->structDeclListsList)) );
	    }
	  ;}
    break;

  case 179:
#line 1181 "ctlib/parser.y"
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

  case 180:
#line 1193 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 181:
#line 1194 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 182:
#line 1195 "ctlib/parser.y"
    { yyval.pStructDecl = yyvsp[-1].pStructDecl; ;}
    break;

  case 183:
#line 1200 "ctlib/parser.y"
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

  case 184:
#line 1214 "ctlib/parser.y"
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

  case 185:
#line 1229 "ctlib/parser.y"
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

  case 186:
#line 1243 "ctlib/parser.y"
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

  case 187:
#line 1259 "ctlib/parser.y"
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

  case 188:
#line 1273 "ctlib/parser.y"
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

  case 189:
#line 1283 "ctlib/parser.y"
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

  case 190:
#line 1296 "ctlib/parser.y"
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

  case 191:
#line 1306 "ctlib/parser.y"
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

  case 192:
#line 1318 "ctlib/parser.y"
    { yyval.ival = -1; ;}
    break;

  case 193:
#line 1319 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].ival; ;}
    break;

  case 194:
#line 1323 "ctlib/parser.y"
    { yyval.ival = yyvsp[0].value.iv; ;}
    break;

  case 195:
#line 1328 "ctlib/parser.y"
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

  case 196:
#line 1344 "ctlib/parser.y"
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

  case 197:
#line 1376 "ctlib/parser.y"
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

  case 198:
#line 1402 "ctlib/parser.y"
    {
	    yyval.context.ctx.pFI  = PSTATE->pFI;
	    yyval.context.ctx.line = PSTATE->pLexer->ctok->line;
	  ;}
    break;

  case 199:
#line 1410 "ctlib/parser.y"
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

  case 200:
#line 1424 "ctlib/parser.y"
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

  case 201:
#line 1440 "ctlib/parser.y"
    {
	    yyval.list = yyvsp[-1].list;
	  ;}
    break;

  case 202:
#line 1447 "ctlib/parser.y"
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
#line 1457 "ctlib/parser.y"
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
#line 1479 "ctlib/parser.y"
    {;}
    break;

  case 209:
#line 1480 "ctlib/parser.y"
    {;}
    break;

  case 210:
#line 1481 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 211:
#line 1482 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 212:
#line 1483 "ctlib/parser.y"
    {;}
    break;

  case 213:
#line 1484 "ctlib/parser.y"
    {;}
    break;

  case 214:
#line 1485 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 215:
#line 1486 "ctlib/parser.y"
    {;}
    break;

  case 216:
#line 1487 "ctlib/parser.y"
    {;}
    break;

  case 217:
#line 1488 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 218:
#line 1489 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 219:
#line 1490 "ctlib/parser.y"
    {;}
    break;

  case 220:
#line 1491 "ctlib/parser.y"
    {;}
    break;

  case 221:
#line 1492 "ctlib/parser.y"
    { if( yyvsp[0].pDecl ) decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;}
    break;

  case 222:
#line 1500 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 223:
#line 1501 "ctlib/parser.y"
    { if( yyvsp[0].identifier ) HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;}
    break;

  case 224:
#line 1506 "ctlib/parser.y"
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
#line 1521 "ctlib/parser.y"
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
#line 1537 "ctlib/parser.y"
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
#line 1551 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      if( yyvsp[0].absDecl.pointer_flag ) {
	        yyval.value.iv = PSTATE->pCPC->ptr_size * yyvsp[0].absDecl.multiplicator;
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
#line 1570 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = PSTATE->pCPC->int_size;
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 229:
#line 1577 "ctlib/parser.y"
    {
	    if( !IS_LOCAL ) {
	      yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
	              PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	      yyval.value.flags = 0;
	    }
	  ;}
    break;

  case 234:
#line 1594 "ctlib/parser.y"
    {;}
    break;

  case 242:
#line 1614 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[0].idOrType ); ;}
    break;

  case 250:
#line 1629 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-2].idOrType ); ;}
    break;

  case 268:
#line 1668 "ctlib/parser.y"
    { DELETE_NODE( yyvsp[-1].idOrType ); ;}
    break;

  case 279:
#line 1694 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 280:
#line 1695 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 281:
#line 1696 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 282:
#line 1697 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 283:
#line 1698 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 284:
#line 1699 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 285:
#line 1700 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 286:
#line 1701 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 287:
#line 1702 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 288:
#line 1703 "ctlib/parser.y"
    { END_LOCAL; decl_delete( EX_DECL( yyvsp[-2].pDecl ) ); ;}
    break;

  case 289:
#line 1705 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 290:
#line 1705 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 291:
#line 1706 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 292:
#line 1706 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 293:
#line 1707 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 294:
#line 1707 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 295:
#line 1708 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 296:
#line 1708 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 297:
#line 1709 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 298:
#line 1709 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 299:
#line 1711 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 300:
#line 1711 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 301:
#line 1712 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 302:
#line 1712 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 303:
#line 1713 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 304:
#line 1713 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 305:
#line 1714 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 306:
#line 1714 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 307:
#line 1715 "ctlib/parser.y"
    { BEGIN_LOCAL; ;}
    break;

  case 308:
#line 1715 "ctlib/parser.y"
    { END_LOCAL; ;}
    break;

  case 309:
#line 1719 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 310:
#line 1720 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 311:
#line 1724 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 312:
#line 1725 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 313:
#line 1730 "ctlib/parser.y"
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

  case 314:
#line 1742 "ctlib/parser.y"
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

  case 315:
#line 1755 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 316:
#line 1762 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 317:
#line 1764 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 318:
#line 1770 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 319:
#line 1778 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 320:
#line 1780 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 321:
#line 1790 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 322:
#line 1792 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 323:
#line 1798 "ctlib/parser.y"
    {
	    if( yyvsp[-1].pDecl )
	      yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 324:
#line 1804 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 325:
#line 1810 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 326:
#line 1818 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 327:
#line 1820 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 328:
#line 1825 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 329:
#line 1833 "ctlib/parser.y"
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

  case 330:
#line 1844 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 331:
#line 1848 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 332:
#line 1849 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 333:
#line 1853 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[0].pDecl; ;}
    break;

  case 334:
#line 1855 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 335:
#line 1861 "ctlib/parser.y"
    {
	    if( yyvsp[0].pDecl )
	      yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;}
    break;

  case 336:
#line 1870 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;}
    break;

  case 337:
#line 1874 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 338:
#line 1876 "ctlib/parser.y"
    {
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;}
    break;

  case 339:
#line 1884 "ctlib/parser.y"
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

  case 340:
#line 1896 "ctlib/parser.y"
    { yyval.pDecl = yyvsp[-1].pDecl; ;}
    break;

  case 341:
#line 1900 "ctlib/parser.y"
    {;}
    break;

  case 342:
#line 1901 "ctlib/parser.y"
    {;}
    break;

  case 343:
#line 1902 "ctlib/parser.y"
    {;}
    break;

  case 344:
#line 1907 "ctlib/parser.y"
    {
	    if( yyvsp[-3].pDecl )
	      decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  ;}
    break;

  case 345:
#line 1911 "ctlib/parser.y"
    {;}
    break;

  case 346:
#line 1913 "ctlib/parser.y"
    {
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;

  case 347:
#line 1920 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 348:
#line 1921 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[0].absDecl; ;}
    break;

  case 349:
#line 1923 "ctlib/parser.y"
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

  case 350:
#line 1936 "ctlib/parser.y"
    { yyval.list = yyvsp[0].list;   ;}
    break;

  case 351:
#line 1937 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 352:
#line 1938 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 353:
#line 1942 "ctlib/parser.y"
    { yyval.list = NULL; ;}
    break;

  case 354:
#line 1944 "ctlib/parser.y"
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

  case 355:
#line 1958 "ctlib/parser.y"
    {
	    if( IS_LOCAL ) {
	      yyval.list = NULL;
	    }
	    else {
	      yyval.list = LL_new();
	      LL_unshift( PSTATE->arrayList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting array (%p) (count=%d)",
	                         yyval.list, LL_count(PSTATE->arrayList)) );
	      LL_push( yyval.list, value_new( 0, 0 ) );
	      CT_DEBUG( PARSER, ("array dimension => *") );
	    }
	  ;}
    break;

  case 356:
#line 1972 "ctlib/parser.y"
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

  case 357:
#line 1991 "ctlib/parser.y"
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

  case 358:
#line 2013 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 359:
#line 2018 "ctlib/parser.y"
    {
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;}
    break;

  case 360:
#line 2023 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 361:
#line 2028 "ctlib/parser.y"
    {
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;}
    break;

  case 362:
#line 2035 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 363:
#line 2036 "ctlib/parser.y"
    { yyval.absDecl = yyvsp[-1].absDecl; ;}
    break;

  case 364:
#line 2038 "ctlib/parser.y"
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

  case 365:
#line 2049 "ctlib/parser.y"
    {
	    yyval.absDecl = yyvsp[-2].absDecl;
	    if( yyvsp[0].list )
	      LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;}
    break;


    }

/* Line 991 of yacc.c.  */
#line 4531 "ctlib/parser.c"

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


#line 2056 "ctlib/parser.y"



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
  format_error( pState->pCPI, "%s, line %ld: %s",
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


