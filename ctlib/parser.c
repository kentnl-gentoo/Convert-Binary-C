/* A Bison parser, made from ctlib/parser.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse c_parse
#define yylex c_lex
#define yyerror c_error
#define yylval c_lval
#define yychar c_char
#define yydebug c_debug
#define yynerrs c_nerrs
# define	AUTO_TOK	257
# define	DOUBLE_TOK	258
# define	INT_TOK	259
# define	STRUCT_TOK	260
# define	BREAK_TOK	261
# define	ELSE_TOK	262
# define	LONG_TOK	263
# define	SWITCH_TOK	264
# define	CASE_TOK	265
# define	ENUM_TOK	266
# define	REGISTER_TOK	267
# define	TYPEDEF_TOK	268
# define	CHAR_TOK	269
# define	EXTERN_TOK	270
# define	RETURN_TOK	271
# define	UNION_TOK	272
# define	CONST_TOK	273
# define	FLOAT_TOK	274
# define	SHORT_TOK	275
# define	UNSIGNED_TOK	276
# define	CONTINUE_TOK	277
# define	FOR_TOK	278
# define	SIGNED_TOK	279
# define	VOID_TOK	280
# define	DEFAULT_TOK	281
# define	GOTO_TOK	282
# define	SIZEOF_TOK	283
# define	VOLATILE_TOK	284
# define	DO_TOK	285
# define	IF_TOK	286
# define	STATIC_TOK	287
# define	WHILE_TOK	288
# define	INLINE_TOK	289
# define	RESTRICT_TOK	290
# define	PTR_OP	291
# define	INC_OP	292
# define	DEC_OP	293
# define	LEFT_OP	294
# define	RIGHT_OP	295
# define	LE_OP	296
# define	GE_OP	297
# define	EQ_OP	298
# define	NE_OP	299
# define	AND_OP	300
# define	OR_OP	301
# define	ELLIPSIS	302
# define	MUL_ASSIGN	303
# define	DIV_ASSIGN	304
# define	MOD_ASSIGN	305
# define	ADD_ASSIGN	306
# define	SUB_ASSIGN	307
# define	LEFT_ASSIGN	308
# define	RIGHT_ASSIGN	309
# define	AND_ASSIGN	310
# define	XOR_ASSIGN	311
# define	OR_ASSIGN	312
# define	IDENTIFIER	313
# define	STRING_LITERAL	314
# define	CONSTANT	315
# define	TYPE_NAME	316

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
* $Date: 2002/09/25 22:25:04 +0200 $
* $Revision: 5 $
* $Snapshot: /Convert-Binary-C/0.03 $
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
#define EX_NODE( node )         ex_object( "Node",           PSTATE->nodeList,            node  )
#define EX_DECL( decl )         ex_object( "Declarator",     PSTATE->declaratorList,      decl  )
#define EX_ARRAY( array )       ex_object( "Array",          PSTATE->arrayList,           array )
#define EX_STRUCT_DECL( decl )  ex_object( "StructDecl",     PSTATE->structDeclList,      decl  )
#define EX_STRDECL_LIST( list ) ex_object( "StructDeclList", PSTATE->structDeclListsList, list  )
#else
#define EX_NODE( node )         ex_object( PSTATE->nodeList,            node  )
#define EX_DECL( decl )         ex_object( PSTATE->declaratorList,      decl  )
#define EX_ARRAY( array )       ex_object( PSTATE->arrayList,           array )
#define EX_STRUCT_DECL( decl )  ex_object( PSTATE->structDeclList,      decl  )
#define EX_STRDECL_LIST( list ) ex_object( PSTATE->structDeclListsList, list  )
#endif

#define STORE_IN_HASH( table, key, obj )                                       \
          if( key.node == NULL )                                               \
            HT_store( PSTATE->pCPI->table, key.str, key.len, key.hash, obj );  \
          else                                                                 \
            HT_storenode( PSTATE->pCPI->table, EX_NODE( key.node ), obj )

#define DELETE_NODE( key )                                                     \
          if( key.node != NULL )                                               \
            HN_delete( EX_NODE( key.node ) )

#define POSTFIX_DECL( decl, postfix )                                  \
	  if( postfix ) {                                              \
            EX_ARRAY( postfix );                                       \
	    if( decl->pointer_flag )                                   \
	      LL_destroy( postfix, (LLDestroyFunc) value_delete );     \
	    else                                                       \
	      LL_delete( LL_splice( decl->array, 0, 0, postfix ) );    \
	  }

#define MAKE_TYPEDEF( type, decl )                                                        \
	  if( type.tflags & T_TYPEDEF ) {                                                 \
            Typedef *pTypedef;                                                            \
            if( (type.tflags & ANY_TYPE_NAME) == 0 )                                      \
              type.tflags |= T_INT;                                                       \
	    pTypedef = typedef_new( type, EX_DECL( decl ) );                              \
	    LL_push( PSTATE->pCPI->typedefs, pTypedef );                                  \
	    HT_store( PSTATE->pCPI->htTypedefs, decl->identifier, 0, 0, pTypedef );       \
	  }                                                                               \
	  else                                                                            \
	    decl_delete( EX_DECL( decl ) )

#define UNDEF_VAL( x ) do { x.iv = 0; x.flags = V_IS_UNDEF; } while(0)

#define UNARY_OP( result, op, val ) \
          do { result.iv = op val.iv; result.flags = val.flags; } while(0)

#define BINARY_OP( result, val1, op, val2 )           \
          do {                                        \
            result.iv    = val1.iv   op val2.iv;      \
            result.flags = val1.flags | val2.flags;   \
          } while(0)


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


#line 347 "ctlib/parser.y"
#ifndef YYSTYPE
typedef union {
  HashNode           identifier;
  Declarator        *pDecl;
  AbstractDeclarator absDecl;
  StructDeclaration *pStructDecl;
  LinkedList         list;
  Enumerator        *pEnum;
  TypeSpec           tspec;
  Value              value;
  signed long        ival;
  unsigned long      uval;
  char               oper;
  IdOrTypeName       idOrType;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 0
#endif



#define	YYFINAL		532
#define	YYFLAG		-32768
#define	YYNTBASE	87

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 316 ? yytranslate[x] : 188)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     5,     7,     9,    11,    15,    17,    22,
      26,    31,    32,    37,    38,    43,    46,    49,    56,    64,
      66,    68,    70,    74,    76,    79,    82,    85,    88,    93,
      95,    97,    99,   101,   103,   105,   107,   112,   114,   118,
     122,   126,   128,   132,   136,   138,   142,   146,   148,   152,
     156,   160,   164,   166,   170,   174,   176,   180,   182,   186,
     188,   192,   194,   198,   200,   204,   206,   212,   214,   218,
     220,   222,   224,   226,   228,   230,   232,   234,   236,   238,
     240,   242,   246,   248,   249,   251,   254,   257,   260,   263,
     267,   271,   276,   280,   284,   289,   291,   293,   295,   297,
     299,   301,   303,   306,   309,   311,   314,   316,   318,   320,
     322,   324,   327,   330,   333,   336,   338,   341,   344,   347,
     350,   353,   356,   358,   361,   364,   367,   370,   373,   375,
     378,   381,   383,   385,   387,   389,   391,   393,   395,   397,
     399,   401,   403,   405,   407,   409,   411,   413,   415,   420,
     426,   429,   431,   433,   435,   438,   441,   444,   447,   451,
     454,   458,   461,   463,   466,   468,   469,   471,   474,   479,
     485,   488,   490,   494,   497,   499,   503,   505,   509,   511,
     515,   517,   520,   523,   526,   528,   531,   534,   536,   539,
     542,   545,   547,   550,   553,   555,   559,   561,   563,   565,
     568,   570,   573,   574,   577,   581,   586,   588,   591,   596,
     597,   600,   602,   605,   609,   612,   614,   616,   618,   620,
     622,   624,   628,   633,   637,   640,   644,   648,   653,   655,
     658,   660,   663,   666,   672,   680,   686,   692,   700,   710,
     714,   717,   720,   724,   725,   727,   729,   732,   734,   736,
     739,   743,   747,   751,   755,   758,   762,   766,   770,   774,
     778,   783,   788,   793,   798,   800,   802,   804,   806,   808,
     811,   813,   815,   818,   822,   826,   831,   833,   838,   844,
     847,   851,   855,   860,   865,   867,   871,   873,   875,   877,
     880,   884,   887,   891,   896,   898,   902,   904,   907,   911,
     916,   920,   925,   927,   929,   931,   933,   936,   940,   943,
     947,   951,   956,   961,   963,   966,   969,   973,   977,   981,
     985
};
static const short yyrhs[] =
{
      60,     0,    87,    60,     0,    59,     0,    61,     0,    87,
       0,    63,   110,    64,     0,    88,     0,    89,    65,   110,
      66,     0,    89,    63,    64,     0,    89,    63,    93,    64,
       0,     0,    89,    90,    67,    92,     0,     0,    89,    91,
      37,    92,     0,    89,    38,     0,    89,    39,     0,    63,
     149,    64,    68,   152,    69,     0,    63,   149,    64,    68,
     152,    70,    69,     0,    59,     0,    62,     0,   108,     0,
      93,    70,   108,     0,    89,     0,    38,    94,     0,    39,
      94,     0,    95,    96,     0,    29,    94,     0,    29,    63,
     149,    64,     0,    71,     0,    72,     0,    73,     0,    74,
       0,    75,     0,    76,     0,    94,     0,    63,   149,    64,
      96,     0,    96,     0,    97,    72,    96,     0,    97,    77,
      96,     0,    97,    78,    96,     0,    97,     0,    98,    73,
      97,     0,    98,    74,    97,     0,    98,     0,    99,    40,
      98,     0,    99,    41,    98,     0,    99,     0,   100,    79,
      99,     0,   100,    80,    99,     0,   100,    42,    99,     0,
     100,    43,    99,     0,   100,     0,   101,    44,   100,     0,
     101,    45,   100,     0,   101,     0,   102,    71,   101,     0,
     102,     0,   103,    81,   102,     0,   103,     0,   104,    82,
     103,     0,   104,     0,   105,    46,   104,     0,   105,     0,
     106,    47,   105,     0,   106,     0,   106,    83,   110,    84,
     107,     0,   107,     0,    94,   109,   108,     0,    85,     0,
      49,     0,    50,     0,    51,     0,    52,     0,    53,     0,
      54,     0,    55,     0,    56,     0,    57,     0,    58,     0,
     108,     0,   110,    70,   108,     0,   107,     0,     0,   110,
       0,   124,    86,     0,   125,    86,     0,   115,    86,     0,
     114,    86,     0,   118,   177,   150,     0,   119,   177,   150,
       0,   114,    70,   177,   150,     0,   116,   169,   150,     0,
     117,   169,   150,     0,   115,    70,   169,   150,     0,   122,
       0,   124,     0,   126,     0,   123,     0,   125,     0,   127,
       0,   128,     0,   119,   128,     0,   118,   120,     0,   121,
       0,   119,   121,     0,   128,     0,   121,     0,    19,     0,
      36,     0,    30,     0,   118,   129,     0,   123,   128,     0,
     122,   120,     0,   122,   129,     0,   129,     0,   119,   129,
       0,   123,   121,     0,   123,   129,     0,   118,   130,     0,
     125,   128,     0,   124,   120,     0,   130,     0,   119,   130,
       0,   125,   121,     0,   127,   128,     0,   118,    62,     0,
     126,   120,     0,    62,     0,   119,    62,     0,   127,   121,
       0,    14,     0,    16,     0,    33,     0,     3,     0,    13,
       0,    35,     0,     5,     0,    15,     0,    21,     0,     9,
       0,    20,     0,     4,     0,    25,     0,    22,     0,    26,
       0,   131,     0,   141,     0,   132,    68,   133,    69,     0,
     132,   148,    68,   133,    69,     0,   132,   148,     0,     6,
       0,    18,     0,   134,     0,   133,   134,     0,   136,    86,
       0,   135,    86,     0,   119,   138,     0,   135,    70,   138,
       0,   117,   137,     0,   136,    70,   137,     0,   169,   139,
       0,   140,     0,   177,   139,     0,   140,     0,     0,   140,
       0,    84,   111,     0,    12,    68,   142,    69,     0,    12,
     148,    68,   142,    69,     0,    12,   148,     0,   143,     0,
     142,    70,   143,     0,   142,    70,     0,   148,     0,   148,
      85,   111,     0,   145,     0,   145,    70,    48,     0,   146,
       0,   145,    70,   146,     0,   116,     0,   116,   183,     0,
     116,   177,     0,   116,   171,     0,   118,     0,   118,   183,
       0,   118,   177,     0,   117,     0,   117,   183,     0,   117,
     177,     0,   117,   171,     0,   119,     0,   119,   183,     0,
     119,   177,     0,    59,     0,   147,    70,    59,     0,    59,
       0,    62,     0,   117,     0,   117,   183,     0,   119,     0,
     119,   183,     0,     0,    85,   151,     0,    68,   152,    69,
       0,    68,   152,    70,    69,     0,   108,     0,   153,   151,
       0,   152,    70,   153,   151,     0,     0,   154,    85,     0,
     155,     0,   154,   155,     0,    65,   111,    66,     0,    67,
     148,     0,   157,     0,   158,     0,   161,     0,   162,     0,
     163,     0,   164,     0,   148,    84,   156,     0,    11,   111,
      84,   156,     0,    27,    84,   156,     0,    68,    69,     0,
      68,   159,    69,     0,    68,   160,    69,     0,    68,   159,
     160,    69,     0,   113,     0,   159,   113,     0,   156,     0,
     160,   156,     0,   112,    86,     0,    32,    63,   110,    64,
     156,     0,    32,    63,   110,    64,   156,     8,   156,     0,
      10,    63,   110,    64,   156,     0,    34,    63,   110,    64,
     156,     0,    31,   156,    34,    63,   110,    64,    86,     0,
      24,    63,   112,    86,   112,    86,   112,    64,   156,     0,
      28,   148,    86,     0,    23,    86,     0,     7,    86,     0,
      17,   112,    86,     0,     0,   166,     0,   167,     0,   166,
     167,     0,   168,     0,   113,     0,   177,   158,     0,   116,
     177,   158,     0,   117,   177,   158,     0,   118,   177,   158,
       0,   119,   177,   158,     0,   181,   158,     0,   116,   181,
     158,     0,   117,   181,   158,     0,   118,   181,   158,     0,
     119,   181,   158,     0,   181,   159,   158,     0,   116,   181,
     159,   158,     0,   117,   181,   159,   158,     0,   118,   181,
     159,   158,     0,   119,   181,   159,   158,     0,   177,     0,
     170,     0,   174,     0,   171,     0,    62,     0,    62,   184,
       0,   172,     0,   173,     0,    72,   171,     0,    72,   119,
     171,     0,    63,   172,    64,     0,    63,   172,    64,   184,
       0,   175,     0,    72,    63,   176,    64,     0,    72,   119,
      63,   176,    64,     0,    72,   174,     0,    72,   119,   174,
       0,    63,   174,    64,     0,    63,   176,   184,    64,     0,
      63,   174,    64,   184,     0,    62,     0,    63,   176,    64,
       0,   178,     0,   180,     0,   179,     0,    72,   177,     0,
      72,   119,   177,     0,   180,   184,     0,    63,   178,    64,
       0,    63,   178,    64,   184,     0,    59,     0,    63,   180,
      64,     0,   182,     0,    72,   181,     0,    72,   119,   181,
       0,   180,    63,   147,    64,     0,    63,   181,    64,     0,
      63,   181,    64,   184,     0,   186,     0,   187,     0,   184,
       0,   185,     0,    63,    64,     0,    63,   144,    64,     0,
      65,    66,     0,    65,   108,    66,     0,    65,    72,    66,
       0,   185,    65,   108,    66,     0,   185,    65,    72,    66,
       0,    72,     0,    72,   119,     0,    72,   183,     0,    72,
     119,   183,     0,    63,   186,    64,     0,    63,   187,    64,
       0,    63,   184,    64,     0,    63,   186,    64,   184,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   496,   497,   504,   509,   510,   511,   515,   516,   517,
     518,   519,   519,   520,   520,   521,   522,   523,   524,   528,
     529,   533,   534,   538,   539,   540,   541,   559,   560,   564,
     565,   566,   567,   568,   569,   573,   574,   578,   579,   581,
     588,   598,   599,   601,   606,   607,   609,   614,   615,   617,
     619,   621,   626,   627,   629,   634,   635,   640,   641,   646,
     647,   652,   653,   658,   659,   664,   665,   670,   671,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     689,   690,   694,   699,   700,   738,   739,   740,   741,   748,
     754,   760,   768,   773,   779,   788,   793,   794,   799,   804,
     805,   811,   812,   813,   817,   818,   822,   823,   827,   828,
     829,   833,   834,   835,   836,   840,   841,   842,   843,   847,
     852,   857,   865,   866,   867,   872,   877,   882,   890,   891,
     892,   896,   897,   898,   899,   900,   901,   905,   906,   907,
     908,   909,   910,   911,   912,   913,   917,   918,   922,   928,
     953,   973,   974,   978,   986,   994,   995,   999,  1009,  1018,
    1029,  1038,  1043,  1051,  1056,  1064,  1065,  1069,  1073,  1080,
    1104,  1124,  1133,  1144,  1151,  1156,  1164,  1165,  1169,  1170,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1195,  1196,  1200,  1207,  1216,  1228,
    1245,  1250,  1259,  1260,  1264,  1265,  1266,  1270,  1271,  1275,
    1276,  1280,  1281,  1285,  1286,  1291,  1292,  1293,  1294,  1295,
    1296,  1300,  1301,  1302,  1306,  1307,  1308,  1309,  1313,  1314,
    1318,  1319,  1323,  1327,  1328,  1329,  1333,  1334,  1335,  1339,
    1340,  1341,  1342,  1349,  1350,  1354,  1355,  1359,  1360,  1364,
    1366,  1368,  1370,  1372,  1375,  1376,  1377,  1378,  1379,  1381,
    1382,  1383,  1384,  1385,  1389,  1390,  1394,  1395,  1399,  1406,
    1415,  1422,  1423,  1428,  1436,  1437,  1448,  1449,  1454,  1459,
    1464,  1472,  1473,  1478,  1486,  1493,  1497,  1498,  1502,  1503,
    1508,  1516,  1521,  1522,  1530,  1538,  1542,  1543,  1544,  1548,
    1552,  1553,  1560,  1561,  1562,  1576,  1577,  1578,  1582,  1583,
    1592,  1601,  1615,  1632,  1637,  1642,  1647,  1655,  1656,  1657,
    1668
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "AUTO_TOK", "DOUBLE_TOK", "INT_TOK", 
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
  "'='", "';'", "string_literal_list", "primary_expression", 
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

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    87,    87,    88,    88,    88,    88,    89,    89,    89,
      89,    90,    89,    91,    89,    89,    89,    89,    89,    92,
      92,    93,    93,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    99,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   111,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   116,   116,   116,   117,   117,
     117,   118,   118,   118,   119,   119,   120,   120,   121,   121,
     121,   122,   122,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   125,   125,   125,   126,   126,   126,   127,   127,
     127,   128,   128,   128,   128,   128,   128,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   130,   130,   131,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   140,   141,   141,
     141,   142,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   148,   148,   149,   149,
     149,   149,   150,   150,   151,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   156,   156,   156,
     156,   157,   157,   157,   158,   158,   158,   158,   159,   159,
     160,   160,   161,   162,   162,   162,   163,   163,   163,   164,
     164,   164,   164,   165,   165,   166,   166,   167,   167,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   169,   169,   170,   170,   171,   171,
     171,   172,   172,   172,   173,   173,   174,   174,   174,   174,
     174,   175,   175,   175,   176,   176,   177,   177,   178,   178,
     178,   179,   179,   179,   180,   180,   181,   181,   181,   182,
     182,   182,   183,   183,   183,   184,   184,   184,   185,   185,
     185,   185,   185,   186,   186,   186,   186,   187,   187,   187,
     187
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     2,     1,     1,     1,     3,     1,     4,     3,
       4,     0,     4,     0,     4,     2,     2,     6,     7,     1,
       1,     1,     3,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     1,     2,     2,     2,     2,     3,
       3,     4,     3,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       2,     1,     1,     1,     2,     2,     2,     2,     3,     2,
       3,     2,     1,     2,     1,     0,     1,     2,     4,     5,
       2,     1,     3,     2,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     1,     2,     2,     1,     3,     1,     1,     1,     2,
       1,     2,     0,     2,     3,     4,     1,     2,     4,     0,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     2,     5,     7,     5,     5,     7,     9,     3,
       2,     2,     3,     0,     1,     1,     2,     1,     1,     2,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     1,     1,     1,     1,     1,     2,
       1,     1,     2,     3,     3,     4,     1,     4,     5,     2,
       3,     3,     4,     4,     1,     3,     1,     1,     1,     2,
       3,     2,     3,     4,     1,     3,     1,     2,     3,     4,
       3,     4,     1,     1,     1,     1,     2,     3,     2,     3,
       3,     4,     4,     1,     2,     2,     3,     3,     3,     3,
       4
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
     243,   134,   142,   137,   151,   140,     0,   135,   131,   138,
     132,   152,   108,   141,   139,   144,   143,   145,   110,   133,
     136,   109,   294,   128,     0,     0,   248,     0,     0,     0,
       0,     0,     0,   104,    95,    98,    96,    99,    97,   100,
     101,   115,   122,   146,     0,   147,   244,   245,   247,     0,
     286,   288,   287,     0,   296,   196,   197,     0,   170,     0,
       0,     0,     0,   289,   297,     0,    88,     0,    87,   268,
       0,     0,   202,   265,   267,   270,   271,   266,   276,   264,
       0,   202,   264,     0,   126,   103,   107,   106,   111,   119,
     202,     0,   129,   105,   102,   116,   123,   202,     0,   113,
     114,   117,   112,   118,    85,   121,    86,   124,   120,   127,
     130,   125,     0,   150,   246,    83,   249,     0,     0,   291,
     305,   228,     0,     0,     0,     0,   254,     0,     0,   171,
     174,     0,   292,   295,   300,   290,   298,     0,     0,   202,
     287,     0,     0,   202,   264,     0,   269,   284,     0,     0,
       0,     0,     0,     0,   272,   279,     0,    92,   250,   255,
       0,    93,   251,   256,     0,    89,   252,   257,     0,    90,
     253,   258,     0,     0,     0,    98,    99,   100,     0,   153,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     3,     1,     4,
     128,     0,   224,    29,    30,    31,    32,    33,    34,     5,
       7,    23,    35,     0,    37,    41,    44,    47,    52,    55,
      57,    59,    61,    63,    65,    67,    80,    84,     0,     0,
     230,   215,   216,    83,    83,   217,   218,   219,   220,   194,
     306,   180,   187,   184,   191,    96,    99,     0,   176,   178,
       0,     3,   308,    30,     0,     0,   202,   202,   229,   259,
     168,   173,     0,     0,   293,   301,     0,     0,    91,     0,
       0,     0,    94,     0,   274,   281,     0,     0,     0,   273,
     280,   209,   206,   203,   260,   261,   262,   263,     0,   159,
     162,   165,   157,   164,   165,   148,   154,     0,   156,     0,
     155,     0,   241,     0,    35,    82,     0,     0,   240,    83,
      83,     0,     0,    27,     0,     0,     0,     0,    24,    25,
       0,   198,   200,     0,     2,    15,    16,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    69,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,    83,   225,    83,   226,   231,
       0,   313,   183,   182,   181,   304,   302,   303,   190,   189,
     188,     0,   313,   186,   185,   193,   192,   307,     0,   299,
       0,   310,   309,    30,     0,   172,   175,   169,     0,   285,
     275,   283,   282,   277,     0,     0,     0,     0,     0,     0,
     211,   167,   161,   166,   163,   158,   160,   149,     0,    83,
     242,     0,   223,   239,     0,     0,     0,     0,     0,     6,
       0,   313,   199,   201,     0,     9,     0,    21,     0,     0,
       0,    68,    38,    39,    40,    42,    43,    45,    46,    50,
      51,    48,    49,    53,    54,    56,    58,    60,    62,    64,
       0,    81,   221,   227,     0,     0,     0,   314,   315,   314,
     177,   179,   195,   312,   311,   278,     0,   214,   204,   209,
     207,   210,   212,    83,   222,    83,    28,     0,    83,    83,
       0,   314,   209,    36,    10,     0,     8,    19,    20,    12,
      14,     0,   319,   317,   318,   316,   213,   205,     0,   235,
       0,     0,   233,   236,     0,    22,    66,   320,   208,    83,
       0,    83,    17,   209,     0,   237,   234,    18,    83,   238,
       0,     0,     0
};

static const short yydefgoto[] =
{
     209,   210,   211,   329,   330,   499,   436,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   342,   227,   306,   228,   121,    27,    28,   122,
     123,   124,   125,    85,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   178,   179,   180,   181,
     289,   292,   412,   290,    45,   128,   129,   247,   248,   249,
     250,   229,   323,   165,   283,   407,   408,   409,   410,   230,
     231,   232,   127,   234,   235,   236,   237,   238,   530,    46,
      47,    48,    72,    73,    74,    75,    76,   150,    78,   151,
      63,    50,    51,   140,    61,    54,   468,   375,   120,   376,
     377
};

static const short yypact[] =
{
    1468,-32768,-32768,-32768,-32768,-32768,   171,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,    48,   107,-32768,   -36,   -16,   539,
     539,  1503,  1538,-32768,  2136,  2136,   537,   611,  1146,  1146,
  -32768,-32768,-32768,-32768,   233,-32768,  1468,-32768,-32768,   -66,
  -32768,-32768,   -22,  1698,-32768,-32768,-32768,    31,   -59,     7,
     375,    16,   107,-32768,-32768,   130,-32768,   672,-32768,    86,
     689,   483,    56,-32768,-32768,-32768,-32768,-32768,-32768,   -66,
    1698,    56,   -66,  1698,-32768,-32768,-32768,-32768,-32768,-32768,
     -64,  1698,-32768,-32768,-32768,-32768,-32768,   -64,  1698,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,   935,    44,-32768,   760,-32768,  1804,  1879,-32768,
      87,-32768,   672,   672,  1573,  1608,-32768,  1698,   207,-32768,
      63,    31,    86,-32768,    86,-32768,-32768,   130,  1025,    56,
      86,   738,   649,    56,-32768,  1839,-32768,-32768,   689,   111,
     119,    86,   689,   656,-32768,-32768,  1905,-32768,-32768,-32768,
    1698,-32768,-32768,-32768,  1698,-32768,-32768,-32768,  1698,-32768,
  -32768,-32768,  1698,   393,   684,  1295,    80,    80,  1731,-32768,
      22,    77,   935,   100,   127,  1984,  1984,   136,   169,   152,
      31,  2010,  1202,   187,   189,  2036,  2036,   195,-32768,-32768,
     214,   907,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   231,
  -32768,   249,   322,  1984,-32768,   196,   220,   306,    15,   337,
     242,   244,   241,   290,   -11,-32768,-32768,   291,   279,   285,
  -32768,-32768,-32768,   834,   977,-32768,-32768,-32768,-32768,-32768,
  -32768,   619,   619,  1276,  1340,  1146,  1146,   328,   330,-32768,
     131,-32768,-32768,   340,   350,  2062,    56,    56,-32768,-32768,
  -32768,    31,  1984,   316,-32768,-32768,   552,  1025,-32768,   738,
     738,   955,-32768,   570,    86,    86,   355,   675,   689,-32768,
  -32768,   154,-32768,-32768,-32768,-32768,-32768,-32768,  1984,-32768,
  -32768,   360,-32768,-32768,   360,-32768,-32768,   411,-32768,   393,
  -32768,  1759,-32768,  1984,-32768,-32768,   362,   338,-32768,  1984,
    1202,   365,   907,-32768,   425,  1984,  1984,   907,-32768,-32768,
     148,    99,  1643,   400,-32768,-32768,-32768,  1931,  1984,   401,
     456,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,  1984,-32768,  1984,  1984,  1984,  1984,  1984,  1984,
    1984,  1984,  1984,  1984,  1984,  1984,  1984,  1984,  1984,  1984,
    1984,  1984,  1984,  1984,-32768,  1202,-32768,  1047,-32768,-32768,
    1121,    19,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,  1185,   602,-32768,-32768,-32768,-32768,-32768,  1874,-32768,
     433,-32768,-32768,   430,   432,-32768,-32768,-32768,   738,-32768,
  -32768,-32768,-32768,-32768,   694,  1984,    31,   364,  1905,     1,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   211,  1202,
  -32768,   415,-32768,-32768,   439,   441,   247,   254,   442,-32768,
    1404,   852,-32768,-32768,  1958,-32768,   273,-32768,    43,    38,
      38,-32768,-32768,-32768,-32768,   196,   196,   220,   220,   306,
     306,   306,   306,    15,    15,   337,   242,   244,   241,   290,
       5,-32768,-32768,-32768,   445,   451,   453,    19,-32768,   602,
  -32768,-32768,-32768,-32768,-32768,-32768,   462,-32768,-32768,   358,
  -32768,-32768,-32768,  1202,-32768,  1984,   465,  1984,  1202,  1202,
     465,   852,   154,-32768,-32768,  1984,-32768,-32768,-32768,-32768,
  -32768,  1984,-32768,    86,-32768,-32768,-32768,-32768,  1905,-32768,
     444,   320,   528,-32768,   392,-32768,-32768,-32768,-32768,  1984,
     452,  1202,-32768,   499,   477,-32768,-32768,-32768,  1202,-32768,
     544,   547,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,-32768,-32768,   109,-32768,   235,-32768,  -185,
     125,   137,   371,   156,   197,   194,   198,   199,   210,-32768,
    -159,   -73,-32768,   163,  -225,  -178,   367,-32768,-32768,    13,
      33,    23,    27,   -14,   -20,-32768,   217,   -92,   188,-32768,
     342,   317,    83,   185,-32768,-32768,   427,  -173,-32768,-32768,
     276,   310,   318,  -110,-32768,   479,   352,-32768,-32768,   243,
  -32768,     4,   -77,   -37,  -407,   145,  -472,-32768,   230,    -7,
  -32768,   573,   165,   386,-32768,-32768,-32768,-32768,-32768,-32768,
     583,-32768,   -27,-32768,   -65,    62,-32768,   455,-32768,    52,
       0,   118,-32768,   167,   574,-32768,    41,   -13,-32768,  -296,
    -294
};


#define	YYLAST		2172


static const short yytable[] =
{
      49,   480,   115,    81,   115,   296,   154,   508,   307,   131,
      58,    86,    93,    29,    86,   101,    86,   107,    86,   110,
      99,   156,   105,    31,   109,   245,   305,    32,   343,    79,
      82,    90,    97,    30,    65,   157,   361,   396,    12,   119,
     143,   117,    93,   118,   161,   254,    49,   119,   113,    18,
      66,   508,    62,   245,    67,    21,   146,   351,   352,    29,
     169,   130,   135,   411,   293,   139,   405,   144,   406,    31,
      68,   132,   362,    32,   465,   363,   466,   154,    22,    30,
     134,    69,   370,   282,   118,   465,   481,   466,   279,   501,
      55,   371,   297,    56,   353,   354,    81,   497,   153,    12,
     498,   518,   268,   305,    86,    93,   272,    22,   298,   496,
      18,    24,   182,   363,    88,    95,    21,   100,   103,   264,
      25,   265,   144,   144,   256,   257,    12,   119,   296,   305,
     241,   421,   149,    93,   465,   130,   466,    18,   276,   174,
     243,   156,    59,    21,   244,   173,   291,   299,   262,   145,
     242,   118,   255,   135,    93,   101,   107,   110,   241,   442,
     443,   444,   430,   300,   118,   267,    22,    52,   243,   271,
      24,   431,   244,   144,   294,   274,   372,   378,   242,    25,
     476,   413,   394,   275,   413,   314,   302,   293,    59,    22,
     303,    60,    52,   137,   311,   389,    52,    52,    52,    52,
     273,   390,   138,   149,   277,   174,   279,    88,    95,   174,
     149,   173,   429,    52,   149,   173,    89,    96,   363,   405,
     169,   406,   308,    86,    93,    86,   107,   369,   322,    52,
      55,   105,   309,    56,   321,   424,   310,    60,    52,    57,
     428,   373,   379,   383,   385,   160,   305,    93,   164,   493,
     315,    93,   316,   119,   437,    59,   168,    95,   103,    59,
     276,   400,   401,   172,   276,   130,    59,   135,   344,   441,
      59,   135,   291,   345,   346,   483,   260,   261,   245,  -196,
     233,   363,   374,   380,   384,   386,   -13,   325,   326,   245,
     461,   324,    55,   347,   348,    56,   245,   294,  -197,   144,
     176,   112,    93,   422,   266,   246,   154,   510,   266,    89,
      96,   488,   327,   357,   328,    60,   -11,   363,   489,    60,
      52,   273,   277,   359,   363,   358,    88,    95,   174,   175,
     404,   149,   149,   246,   173,   282,   360,   494,   245,   322,
     149,   524,   516,   495,   322,   321,   349,   350,    87,    94,
     321,    87,   102,    87,   108,    87,   111,   464,   462,    96,
     369,   363,   432,   433,   320,   364,   176,    26,   464,   365,
     176,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   355,   356,   241,   520,   397,   261,    59,    59,   176,
     363,   276,   387,   243,   241,   175,    59,   244,   467,   175,
     388,   241,   279,   242,   243,    95,   391,   341,   244,   469,
     477,   243,   484,    26,   242,   244,   392,   464,   175,   402,
     304,   242,   515,   405,   420,   406,   313,   507,    89,    96,
     318,   319,   149,   478,   479,   282,   266,   266,   117,   133,
     118,    87,    94,   241,   288,    60,   419,    93,   304,    93,
     404,   423,    22,   243,   177,    69,   141,   244,   491,   425,
     149,   522,   523,   242,   434,   142,   418,   135,   439,   135,
      22,    93,   445,   446,   137,   320,   509,   288,   426,   427,
     320,   512,   513,   138,    77,    77,   447,   448,    59,   176,
     517,   438,   472,   440,   258,   288,   473,   304,   474,    59,
     176,   485,    12,   486,   487,   176,   490,    96,   505,   502,
     505,   453,   454,    18,   526,   503,    59,   504,   175,    21,
     177,   529,    77,   304,   177,   460,   155,   258,   506,   175,
     519,   258,   505,   492,   175,   258,   521,   266,   525,   258,
       1,   528,    22,   177,   531,    69,   152,   532,   266,   500,
       7,     8,   456,    10,   455,    71,    12,   457,   246,   458,
      87,    94,    87,   108,   405,   266,   406,    18,   527,   246,
      19,   459,    20,    21,    53,   416,   246,    77,    77,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   155,    22,    64,
     258,    69,    70,    80,    83,    91,    98,   415,   280,   301,
     263,    71,   414,   395,     1,   145,   133,   118,   246,   367,
      53,    12,   116,   104,     7,     8,   126,    10,    77,   114,
      12,   471,    18,   145,   399,   118,   136,   514,    21,   482,
     304,    18,     0,   177,    19,    64,    20,    21,     0,     0,
     511,     0,   158,   159,   177,   162,   163,     0,     0,   177,
       0,    22,     0,   166,   167,   381,     0,   118,    12,   304,
     170,   171,     0,     0,   382,    12,     0,     0,    22,    18,
       0,    69,   370,     0,   118,    21,    18,     0,     2,     3,
       4,   371,    21,     5,     0,     0,     6,   106,     0,     9,
     259,     0,    11,    12,    13,    14,    15,     0,    22,    16,
      17,    69,   270,     0,    18,    22,     0,     0,    69,   278,
      21,   142,   449,   450,   451,   452,   280,   136,    71,     0,
       0,    22,     0,   284,    69,   141,   304,   285,   145,   403,
     118,   286,     0,    22,   142,   287,    92,   137,    22,     0,
       0,   147,   148,     0,    77,     0,   138,   145,   475,   118,
       0,    71,     0,     1,     2,     3,     4,   183,   288,     5,
     184,   185,     6,     7,     8,     9,    10,   186,    11,    12,
      13,    14,    15,   187,   188,    16,    17,   189,   190,   191,
      18,   192,   193,    19,   194,    20,    21,    22,   195,   196,
     147,   269,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     198,   199,   200,   201,     0,     0,     0,     0,   115,   202,
       0,   203,   204,   205,   206,   207,   208,     1,     2,     3,
       4,   183,     0,     5,   184,   185,     6,     7,     8,     9,
      10,   186,    11,    12,    13,    14,    15,   187,   188,    16,
      17,   189,   190,   191,    18,   192,   193,    19,   194,    20,
      21,    12,   195,   196,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,   197,   198,   199,   200,   201,     0,     0,
       0,     0,   115,   366,     0,   203,   204,   205,   206,   207,
     208,     2,     3,     4,     0,   430,     5,   118,     0,     6,
       0,     0,     9,     0,   431,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,   191,    18,     0,     2,
       3,     4,     0,    21,     5,   195,   196,     6,     0,     0,
       9,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,   251,   198,   199,    23,
     201,    21,     0,     0,    12,     0,     0,     0,   203,   204,
     205,   206,   207,   208,   183,    18,     0,   184,   185,     0,
       0,    21,     0,     0,   186,     0,     0,    23,     0,     0,
     187,   188,     0,     0,   189,   190,   191,     0,   192,   193,
       0,   194,     0,     0,    22,   195,   196,    69,   398,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   198,   199,    56,
     201,     0,     0,     0,    12,   115,   368,     0,   203,   204,
     205,   206,   207,   208,   183,    18,     0,   184,   185,     0,
       0,    21,     0,     0,   186,     0,     0,     0,     0,     0,
     187,   188,     0,     0,   189,   190,   191,     0,   192,   193,
       0,   194,     0,     0,    22,   195,   196,     0,   137,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   198,   199,    56,
     201,     0,     0,     0,     0,   115,   463,     0,   203,   204,
     205,   206,   207,   208,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     1,
       0,    18,     0,     0,    19,     0,    20,    21,     0,     7,
       8,     0,    10,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,    19,
      22,    20,    21,    23,   370,   240,   118,     0,     1,     2,
       3,     4,     0,   371,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,   183,
      16,    17,   184,   185,     0,    18,     0,     0,    19,   186,
      20,    21,     0,     0,     0,   187,   188,     0,     0,   189,
     190,   191,     0,   192,   193,     0,   194,     0,     0,     0,
     195,   196,     0,     0,    22,     0,     0,    23,   381,   240,
     118,     0,     0,     0,     0,     0,     0,   382,     0,     0,
       0,   197,   198,   199,    56,   201,     0,     0,     0,     0,
     115,     0,     0,   203,   204,   205,   206,   207,   208,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     2,
       3,    16,    17,     0,     5,     0,    18,     0,     0,    19,
       9,    20,    21,     0,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,     0,     0,    84,   381,
       0,   118,     0,     1,     2,     3,     4,     0,   382,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,    92,   381,     0,   118,     0,     1,     2,     3,
       4,     0,   382,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,   430,   240,   118,
       0,     1,     2,     3,     4,     0,   431,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,    19,     0,    20,    21,     0,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,    22,    16,    17,
      23,    24,     0,    18,     0,     0,    19,     0,    20,    21,
      25,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,    22,    16,    17,    84,    24,     0,    18,     0,
       0,    19,     0,    20,    21,    25,     1,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    15,     0,    22,    16,    17,
      92,    24,     0,    18,     0,     0,    19,     0,    20,    21,
      25,     1,     2,     3,     4,     0,     0,     5,     0,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,    22,    16,    17,    84,   137,     0,    18,     0,
       0,    19,     0,    20,    21,   138,     0,     2,     3,     4,
       0,     0,     5,     0,     0,     6,     0,     0,     9,     0,
       0,    11,    12,    13,    14,    15,     0,    22,    16,    17,
      92,   137,     0,    18,     0,     0,     0,     0,     0,    21,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,    92,   430,     5,   118,     0,
       6,     7,     8,     9,    10,   431,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,    18,     0,
       0,    19,     0,    20,    21,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     0,     0,     9,     0,     0,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     0,
      23,    18,     0,     2,     3,     4,   115,    21,     5,     0,
       0,     6,     0,     0,     9,     0,     0,    11,    12,    13,
      14,    15,     0,     0,    16,    17,     0,     0,     0,    18,
       0,     0,     0,    23,     0,    21,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,    23,    11,    12,    13,    14,    15,     0,   417,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,    20,
      21,     0,     1,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,   239,    16,    17,    23,     0,   240,    18,
       0,     0,    19,     0,    20,    21,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,    23,     0,   240,    18,     0,     0,    19,   191,    20,
      21,     0,     0,     0,     0,     0,     0,   195,   196,     0,
       0,     0,   470,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,     0,    23,     0,   251,   198,
     199,     0,   201,   195,   196,   252,     0,     0,     0,     0,
     203,   253,   205,   206,   207,   208,     0,     0,     0,     0,
     191,     0,     0,     0,   251,   198,   199,     0,   201,   195,
     196,     0,     0,   281,     0,     0,   203,   204,   205,   206,
     207,   208,     0,     0,     0,     0,     0,   191,     0,     0,
     251,   198,   199,     0,   201,   435,   195,   196,     0,     0,
       0,     0,   203,   204,   205,   206,   207,   208,     0,     0,
       0,     0,     0,   191,     0,     0,     0,   251,   198,   199,
       0,   201,   195,   196,     0,     0,   492,     0,     0,   203,
     204,   205,   206,   207,   208,     0,     0,     0,     0,   191,
       0,     0,     0,   251,   198,   199,     0,   201,   195,   196,
       0,     0,     0,     0,     0,   203,   204,   205,   206,   207,
     208,     0,     0,     0,     0,   191,     0,     0,     0,   251,
     198,   199,     0,   312,   195,   196,     0,     0,     0,     0,
       0,   203,   204,   205,   206,   207,   208,     0,     0,     0,
       0,   191,     0,     0,     0,   251,   198,   199,     0,   317,
     195,   196,     0,     0,     0,     0,     0,   203,   204,   205,
     206,   207,   208,     0,     0,     0,     0,     0,     0,     0,
       0,   251,   198,   199,     0,   201,     0,     0,     0,     0,
       0,     0,     0,   203,   393,   205,   206,   207,   208,     1,
       2,     3,     0,     0,     0,     5,     0,     0,     0,     7,
       8,     9,    10,     0,     0,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21
};

static const short yycheck[] =
{
       0,   408,    68,    30,    68,   178,    71,   479,   186,    68,
       6,    31,    32,     0,    34,    35,    36,    37,    38,    39,
      34,    85,    36,     0,    38,   117,   185,     0,   213,    29,
      30,    31,    32,     0,    70,    72,    47,   262,    19,    52,
      67,    63,    62,    65,    81,   118,    46,    60,    44,    30,
      86,   523,    25,   145,    70,    36,    69,    42,    43,    46,
      97,    57,    62,   288,   174,    65,    65,    67,    67,    46,
      86,    64,    83,    46,   370,    70,   370,   142,    59,    46,
      64,    62,    63,   156,    65,   381,    85,   381,   153,    84,
      59,    72,    70,    62,    79,    80,   123,    59,    71,    19,
      62,   508,   139,   262,   124,   125,   143,    59,    86,    66,
      30,    63,    68,    70,    31,    32,    36,    34,    35,   132,
      72,   134,   122,   123,   124,   125,    19,   140,   301,   288,
     117,   309,    70,   153,   430,   131,   430,    30,   151,   112,
     117,    85,    24,    36,   117,   112,   173,    70,    85,    63,
     117,    65,    65,   153,   174,   175,   176,   177,   145,   344,
     345,   346,    63,    86,    65,   138,    59,     0,   145,   142,
      63,    72,   145,   173,   174,    64,   241,   242,   145,    72,
     405,   291,   255,    64,   294,   192,    86,   297,    70,    59,
      63,    24,    25,    63,   190,    64,    29,    30,    31,    32,
     148,    70,    72,   141,   152,   178,   271,   124,   125,   182,
     148,   178,    64,    46,   152,   182,    31,    32,    70,    65,
     257,    67,    86,   243,   244,   245,   246,   234,   201,    62,
      59,   245,    63,    62,   201,   312,    84,    70,    71,    68,
     317,   241,   242,   243,   244,    80,   405,   267,    83,   434,
      63,   271,    63,   266,   327,   137,    91,   174,   175,   141,
     273,   274,   275,    98,   277,   261,   148,   267,    72,   342,
     152,   271,   299,    77,    78,    64,    69,    70,   370,    84,
     115,    70,   241,   242,   243,   244,    37,    38,    39,   381,
     363,    60,    59,    73,    74,    62,   388,   297,    84,   299,
     112,    68,   322,   310,   137,   117,   371,   485,   141,   124,
     125,    64,    63,    71,    65,   148,    67,    70,    64,   152,
     153,   269,   270,    82,    70,    81,   243,   244,   301,   112,
     278,   269,   270,   145,   301,   408,    46,    64,   430,   312,
     278,   519,   501,    70,   317,   312,    40,    41,    31,    32,
     317,    34,    35,    36,    37,    38,    39,   370,   365,   174,
     367,    70,   321,   322,   201,    86,   178,     0,   381,    84,
     182,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    44,    45,   370,    64,    69,    70,   269,   270,   201,
      70,   404,    64,   370,   381,   178,   278,   370,   371,   182,
      70,   388,   467,   370,   381,   322,    66,    85,   381,   382,
     406,   388,   419,    46,   381,   388,    66,   430,   201,    64,
     185,   388,   495,    65,    86,    67,   191,    69,   243,   244,
     195,   196,   370,    69,    70,   508,   269,   270,    63,    64,
      65,   124,   125,   430,    84,   278,    84,   467,   213,   469,
     398,    86,    59,   430,   112,    62,    63,   430,   431,    34,
     398,    69,    70,   430,    64,    72,   303,   467,    67,   469,
      59,   491,   347,   348,    63,   312,   483,    84,   315,   316,
     317,   488,   489,    72,    29,    30,   349,   350,   370,   301,
     503,   328,    59,    37,   127,    84,    66,   262,    66,   381,
     312,    86,    19,    64,    63,   317,    64,   322,   467,    64,
     469,   355,   356,    30,   521,    64,   398,    64,   301,    36,
     178,   528,    67,   288,   182,   362,    71,   160,    66,   312,
      86,   164,   491,    68,   317,   168,     8,   370,    86,   172,
       3,    64,    59,   201,     0,    62,    63,     0,   381,   440,
      13,    14,   358,    16,   357,    72,    19,   359,   370,   360,
     243,   244,   245,   246,    65,   398,    67,    30,    69,   381,
      33,   361,    35,    36,     0,   299,   388,   122,   123,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   142,    59,    25,
     233,    62,    63,    29,    30,    31,    32,   297,   153,   182,
     131,    72,   294,   261,     3,    63,    64,    65,   430,   233,
      46,    19,    49,    86,    13,    14,    53,    16,   173,    46,
      19,   388,    30,    63,    64,    65,    62,   492,    36,   409,
     405,    30,    -1,   301,    33,    71,    35,    36,    -1,    -1,
     487,    -1,    79,    80,   312,    82,    83,    -1,    -1,   317,
      -1,    59,    -1,    90,    91,    63,    -1,    65,    19,   434,
      97,    98,    -1,    -1,    72,    19,    -1,    -1,    59,    30,
      -1,    62,    63,    -1,    65,    36,    30,    -1,     4,     5,
       6,    72,    36,     9,    -1,    -1,    12,    86,    -1,    15,
     127,    -1,    18,    19,    20,    21,    22,    -1,    59,    25,
      26,    62,    63,    -1,    30,    59,    -1,    -1,    62,    63,
      36,    72,   351,   352,   353,   354,   271,   153,    72,    -1,
      -1,    59,    -1,   160,    62,    63,   501,   164,    63,    64,
      65,   168,    -1,    59,    72,   172,    62,    63,    59,    -1,
      -1,    62,    63,    -1,   299,    -1,    72,    63,    64,    65,
      -1,    72,    -1,     3,     4,     5,     6,     7,    84,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    59,    38,    39,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    19,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,     4,     5,     6,    -1,    63,     9,    65,    -1,    12,
      -1,    -1,    15,    -1,    72,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    29,    30,    -1,     4,
       5,     6,    -1,    36,     9,    38,    39,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    59,    60,    61,    62,
      63,    36,    -1,    -1,    19,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,     7,    30,    -1,    10,    11,    -1,
      -1,    36,    -1,    -1,    17,    -1,    -1,    62,    -1,    -1,
      23,    24,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      -1,    34,    -1,    -1,    59,    38,    39,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    19,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,     7,    30,    -1,    10,    11,    -1,
      -1,    36,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      -1,    34,    -1,    -1,    59,    38,    39,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,     3,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,    -1,    13,
      14,    -1,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      59,    35,    36,    62,    63,    64,    65,    -1,     3,     4,
       5,     6,    -1,    72,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,     7,
      25,    26,    10,    11,    -1,    30,    -1,    -1,    33,    17,
      35,    36,    -1,    -1,    -1,    23,    24,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    -1,    34,    -1,    -1,    -1,
      38,    39,    -1,    -1,    59,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    75,    76,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,     4,
       5,    25,    26,    -1,     9,    -1,    30,    -1,    -1,    33,
      15,    35,    36,    -1,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    59,    -1,    -1,    62,    63,
      -1,    65,    -1,     3,     4,     5,     6,    -1,    72,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    62,    63,    -1,    65,    -1,     3,     4,     5,
       6,    -1,    72,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,     3,     4,     5,     6,    -1,    72,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    59,    25,    26,
      62,    63,    -1,    30,    -1,    -1,    33,    -1,    35,    36,
      72,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    59,    25,    26,    62,    63,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    72,     3,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    59,    25,    26,
      62,    63,    -1,    30,    -1,    -1,    33,    -1,    35,    36,
      72,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    59,    25,    26,    62,    63,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    72,    -1,     4,     5,     6,
      -1,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    59,    25,    26,
      62,    63,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    62,    63,     9,    65,    -1,
      12,    13,    14,    15,    16,    72,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      62,    30,    -1,     4,     5,     6,    68,    36,     9,    -1,
      -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    62,    -1,    36,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    62,    18,    19,    20,    21,    22,    -1,    69,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    -1,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    59,    25,    26,    62,    -1,    64,    30,
      -1,    -1,    33,    -1,    35,    36,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    62,    -1,    64,    30,    -1,    -1,    33,    29,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    62,    -1,    59,    60,
      61,    -1,    63,    38,    39,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    59,    60,    61,    -1,    63,    38,
      39,    -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      59,    60,    61,    -1,    63,    64,    38,    39,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    59,    60,    61,
      -1,    63,    38,    39,    -1,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    59,    60,    61,    -1,    63,    38,    39,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    59,
      60,    61,    -1,    63,    38,    39,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    59,    60,    61,    -1,    63,
      38,    39,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,     3,
       4,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36
};
#define YYPURE 1

/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

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

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

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
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


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
#define YYABORT 	goto yyabortlab
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
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


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
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
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

#ifdef YYERROR_VERBOSE

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
#endif

#line 315 "/usr/local/share/bison/bison.simple"


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

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

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

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
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
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
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
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
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
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

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
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 1:
#line 496 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 2:
#line 498 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-1].value, +, yyvsp[0].value ); ;
    break;}
case 3:
#line 505 "ctlib/parser.y"
{
	    HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    UNDEF_VAL( yyval.value );
	  ;
    break;}
case 4:
#line 509 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 5:
#line 510 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; yyval.value.iv++; ;
    break;}
case 6:
#line 511 "ctlib/parser.y"
{ yyval.value = yyvsp[-1].value; ;
    break;}
case 7:
#line 515 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 8:
#line 516 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 9:
#line 517 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 10:
#line 518 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 11:
#line 519 "ctlib/parser.y"
{;
    break;}
case 12:
#line 519 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 13:
#line 520 "ctlib/parser.y"
{;
    break;}
case 14:
#line 520 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 15:
#line 521 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 16:
#line 522 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 17:
#line 523 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 18:
#line 524 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 19:
#line 528 "ctlib/parser.y"
{ HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;
    break;}
case 20:
#line 529 "ctlib/parser.y"
{;
    break;}
case 21:
#line 533 "ctlib/parser.y"
{;
    break;}
case 22:
#line 534 "ctlib/parser.y"
{;
    break;}
case 23:
#line 538 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 24:
#line 539 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 25:
#line 540 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 26:
#line 542 "ctlib/parser.y"
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
	  ;
    break;}
case 27:
#line 559 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 28:
#line 560 "ctlib/parser.y"
{ yyval.value = yyvsp[-1].value; ;
    break;}
case 29:
#line 564 "ctlib/parser.y"
{ yyval.oper = '&'; ;
    break;}
case 30:
#line 565 "ctlib/parser.y"
{ yyval.oper = '*'; ;
    break;}
case 31:
#line 566 "ctlib/parser.y"
{ yyval.oper = '+'; ;
    break;}
case 32:
#line 567 "ctlib/parser.y"
{ yyval.oper = '-'; ;
    break;}
case 33:
#line 568 "ctlib/parser.y"
{ yyval.oper = '~'; ;
    break;}
case 34:
#line 569 "ctlib/parser.y"
{ yyval.oper = '!'; ;
    break;}
case 35:
#line 573 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 36:
#line 574 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; yyval.value.flags |= V_IS_UNSAFE_CAST; ;
    break;}
case 37:
#line 578 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 38:
#line 580 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, *, yyvsp[0].value ); ;
    break;}
case 39:
#line 582 "ctlib/parser.y"
{
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, /, yyvsp[0].value );
	  ;
    break;}
case 40:
#line 589 "ctlib/parser.y"
{
	    if( yyvsp[0].value.iv == 0 )
	      UNDEF_VAL( yyval.value );
	    else
	      BINARY_OP( yyval.value, yyvsp[-2].value, %, yyvsp[0].value );
	  ;
    break;}
case 41:
#line 598 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 42:
#line 600 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, +, yyvsp[0].value ); ;
    break;}
case 43:
#line 602 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, -, yyvsp[0].value ); ;
    break;}
case 44:
#line 606 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 45:
#line 608 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, <<, yyvsp[0].value ); ;
    break;}
case 46:
#line 610 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, >>, yyvsp[0].value ); ;
    break;}
case 47:
#line 614 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 48:
#line 616 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, <,  yyvsp[0].value ); ;
    break;}
case 49:
#line 618 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, >,  yyvsp[0].value ); ;
    break;}
case 50:
#line 620 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, <=, yyvsp[0].value ); ;
    break;}
case 51:
#line 622 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, >=, yyvsp[0].value ); ;
    break;}
case 52:
#line 626 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 53:
#line 628 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, ==, yyvsp[0].value ); ;
    break;}
case 54:
#line 630 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, !=, yyvsp[0].value ); ;
    break;}
case 55:
#line 634 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 56:
#line 636 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, &, yyvsp[0].value ); ;
    break;}
case 57:
#line 640 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 58:
#line 642 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, ^, yyvsp[0].value ); ;
    break;}
case 59:
#line 646 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 60:
#line 648 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, |, yyvsp[0].value ); ;
    break;}
case 61:
#line 652 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 62:
#line 654 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, &&, yyvsp[0].value ); ;
    break;}
case 63:
#line 658 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 64:
#line 660 "ctlib/parser.y"
{ BINARY_OP( yyval.value, yyvsp[-2].value, ||, yyvsp[0].value ); ;
    break;}
case 65:
#line 664 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 66:
#line 666 "ctlib/parser.y"
{ yyval.value = yyvsp[-4].value.iv ? yyvsp[-2].value : yyvsp[0].value; yyval.value.flags |= yyvsp[-4].value.flags; ;
    break;}
case 67:
#line 670 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 68:
#line 671 "ctlib/parser.y"
{ UNDEF_VAL( yyval.value ); ;
    break;}
case 69:
#line 675 "ctlib/parser.y"
{;
    break;}
case 70:
#line 676 "ctlib/parser.y"
{;
    break;}
case 71:
#line 677 "ctlib/parser.y"
{;
    break;}
case 72:
#line 678 "ctlib/parser.y"
{;
    break;}
case 73:
#line 679 "ctlib/parser.y"
{;
    break;}
case 74:
#line 680 "ctlib/parser.y"
{;
    break;}
case 75:
#line 681 "ctlib/parser.y"
{;
    break;}
case 76:
#line 682 "ctlib/parser.y"
{;
    break;}
case 77:
#line 683 "ctlib/parser.y"
{;
    break;}
case 78:
#line 684 "ctlib/parser.y"
{;
    break;}
case 79:
#line 685 "ctlib/parser.y"
{;
    break;}
case 80:
#line 689 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 81:
#line 690 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 82:
#line 694 "ctlib/parser.y"
{ yyval.value = yyvsp[0].value; ;
    break;}
case 84:
#line 700 "ctlib/parser.y"
{;
    break;}
case 85:
#line 738 "ctlib/parser.y"
{;
    break;}
case 86:
#line 739 "ctlib/parser.y"
{;
    break;}
case 87:
#line 740 "ctlib/parser.y"
{;
    break;}
case 88:
#line 741 "ctlib/parser.y"
{;
    break;}
case 89:
#line 749 "ctlib/parser.y"
{
	    yyval.tspec.tflags = yyvsp[-2].uval;
	    yyval.tspec.ptr    = NULL;
	    MAKE_TYPEDEF( yyval.tspec, yyvsp[-1].pDecl );
	  ;
    break;}
case 90:
#line 755 "ctlib/parser.y"
{
	    yyval.tspec.tflags = 0;
	    yyval.tspec.ptr    = NULL;
	    decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;
    break;}
case 91:
#line 761 "ctlib/parser.y"
{
	    yyval.tspec = yyvsp[-3].tspec;
	    MAKE_TYPEDEF( yyval.tspec, yyvsp[-1].pDecl );
	  ;
    break;}
case 92:
#line 769 "ctlib/parser.y"
{
	    yyval.tspec = yyvsp[-2].tspec;
	    MAKE_TYPEDEF( yyval.tspec, yyvsp[-1].pDecl );
	  ;
    break;}
case 93:
#line 774 "ctlib/parser.y"
{
	    yyval.tspec.tflags = 0;
	    yyval.tspec.ptr    = NULL;
	    decl_delete( EX_DECL( yyvsp[-1].pDecl ) );
	  ;
    break;}
case 94:
#line 780 "ctlib/parser.y"
{
	    yyval.tspec = yyvsp[-3].tspec;
	    MAKE_TYPEDEF( yyval.tspec, yyvsp[-1].pDecl );
	  ;
    break;}
case 95:
#line 789 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;
    break;}
case 96:
#line 793 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 97:
#line 794 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 98:
#line 800 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;
    break;}
case 99:
#line 804 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 100:
#line 805 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 101:
#line 811 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval;      ;
    break;}
case 102:
#line 812 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval;      ;
    break;}
case 103:
#line 813 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 106:
#line 822 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval; ;
    break;}
case 107:
#line 823 "ctlib/parser.y"
{ yyval.uval = 0;  ;
    break;}
case 111:
#line 833 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 112:
#line 834 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 113:
#line 835 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 114:
#line 836 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 115:
#line 840 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval;      ;
    break;}
case 116:
#line 841 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval;      ;
    break;}
case 117:
#line 842 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval;      ;
    break;}
case 118:
#line 843 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 119:
#line 848 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;
    break;}
case 120:
#line 853 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;
    break;}
case 121:
#line 858 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;
    break;}
case 122:
#line 865 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 123:
#line 866 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 124:
#line 867 "ctlib/parser.y"
{ yyval.tspec = yyvsp[-1].tspec; ;
    break;}
case 125:
#line 873 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;
    break;}
case 126:
#line 878 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;
    break;}
case 127:
#line 883 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;
    break;}
case 128:
#line 890 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 129:
#line 891 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 130:
#line 892 "ctlib/parser.y"
{ yyval.tspec = yyvsp[-1].tspec; ;
    break;}
case 131:
#line 896 "ctlib/parser.y"
{ yyval.uval = T_TYPEDEF;  ;
    break;}
case 132:
#line 897 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 133:
#line 898 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 134:
#line 899 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 135:
#line 900 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 136:
#line 901 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 137:
#line 905 "ctlib/parser.y"
{ yyval.uval = T_INT;      ;
    break;}
case 138:
#line 906 "ctlib/parser.y"
{ yyval.uval = T_CHAR;     ;
    break;}
case 139:
#line 907 "ctlib/parser.y"
{ yyval.uval = T_SHORT;    ;
    break;}
case 140:
#line 908 "ctlib/parser.y"
{ yyval.uval = T_LONG;     ;
    break;}
case 141:
#line 909 "ctlib/parser.y"
{ yyval.uval = T_FLOAT;    ;
    break;}
case 142:
#line 910 "ctlib/parser.y"
{ yyval.uval = T_DOUBLE;   ;
    break;}
case 143:
#line 911 "ctlib/parser.y"
{ yyval.uval = T_SIGNED;   ;
    break;}
case 144:
#line 912 "ctlib/parser.y"
{ yyval.uval = T_UNSIGNED; ;
    break;}
case 145:
#line 913 "ctlib/parser.y"
{ yyval.uval = T_VOID;     ;
    break;}
case 146:
#line 917 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 147:
#line 918 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 148:
#line 923 "ctlib/parser.y"
{
	    yyval.tspec.tflags = yyvsp[-3].uval;
	    yyval.tspec.ptr = struct_new( NULL, 0, yyvsp[-3].uval, PSTATE->pragma.pack.current, EX_STRDECL_LIST( yyvsp[-1].list ) );
	    LL_push( PSTATE->pCPI->structs, yyval.tspec.ptr );
	  ;
    break;}
case 149:
#line 929 "ctlib/parser.y"
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
	  ;
    break;}
case 150:
#line 954 "ctlib/parser.y"
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
	  ;
    break;}
case 151:
#line 973 "ctlib/parser.y"
{ yyval.uval = T_STRUCT; ;
    break;}
case 152:
#line 974 "ctlib/parser.y"
{ yyval.uval = T_UNION;  ;
    break;}
case 153:
#line 979 "ctlib/parser.y"
{
	    yyval.list = LL_new();
	    LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	    LL_unshift( PSTATE->structDeclListsList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting struct declaration list (0x%08X) (size=%d)",
	                       yyval.list, LL_size(PSTATE->structDeclListsList)) );
	  ;
    break;}
case 154:
#line 987 "ctlib/parser.y"
{
	    yyval.list = yyvsp[-1].list;
	    LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	  ;
    break;}
case 155:
#line 994 "ctlib/parser.y"
{ yyval.pStructDecl = yyvsp[-1].pStructDecl; ;
    break;}
case 156:
#line 995 "ctlib/parser.y"
{ yyval.pStructDecl = yyvsp[-1].pStructDecl; ;
    break;}
case 157:
#line 1000 "ctlib/parser.y"
{
	    TypeSpec ts = { NULL, T_INT };
	    yyval.pStructDecl = structdecl_new( ts, LL_new() );
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	    LL_unshift( PSTATE->structDeclList, yyval.pStructDecl );
	    CT_DEBUG( PARSER, ("unshifting struct declaration (0x%08X) (size=%d)",
	                       yyval.pStructDecl, LL_size(PSTATE->structDeclList)) );
	  ;
    break;}
case 158:
#line 1010 "ctlib/parser.y"
{
	    yyval.pStructDecl = yyvsp[-2].pStructDecl;
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	  ;
    break;}
case 159:
#line 1019 "ctlib/parser.y"
{
	    if( (yyvsp[-1].tspec.tflags & ANY_TYPE_NAME) == 0 )
	      yyvsp[-1].tspec.tflags |= T_INT;
	    yyval.pStructDecl = structdecl_new( yyvsp[-1].tspec, LL_new() );
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	    LL_unshift( PSTATE->structDeclList, yyval.pStructDecl );
	    CT_DEBUG( PARSER, ("unshifting struct declaration (0x%08X) (size=%d)",
	                       yyval.pStructDecl, LL_size(PSTATE->structDeclList)) );
	  ;
    break;}
case 160:
#line 1030 "ctlib/parser.y"
{
	    yyval.pStructDecl = yyvsp[-2].pStructDecl;
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	  ;
    break;}
case 161:
#line 1039 "ctlib/parser.y"
{
	    yyval.pDecl = yyvsp[-1].pDecl;
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  ;
    break;}
case 162:
#line 1044 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( "", 0 );
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  ;
    break;}
case 163:
#line 1052 "ctlib/parser.y"
{
	    yyval.pDecl = yyvsp[-1].pDecl;
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  ;
    break;}
case 164:
#line 1057 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( "", 0 );
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  ;
    break;}
case 165:
#line 1064 "ctlib/parser.y"
{ yyval.ival = -1; ;
    break;}
case 166:
#line 1065 "ctlib/parser.y"
{ yyval.ival = yyvsp[0].ival; ;
    break;}
case 167:
#line 1069 "ctlib/parser.y"
{ yyval.ival = yyvsp[0].value.iv; ;
    break;}
case 168:
#line 1074 "ctlib/parser.y"
{
	    yyval.tspec.tflags = T_ENUM;
	    yyval.tspec.ptr    = enumspec_new( NULL, 0, yyvsp[-1].list );
	    LL_push( PSTATE->pCPI->enums, yyval.tspec.ptr );
	    PSTATE->curEnumList = NULL;
	  ;
    break;}
case 169:
#line 1081 "ctlib/parser.y"
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
	  ;
    break;}
case 170:
#line 1105 "ctlib/parser.y"
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
	  ;
    break;}
case 171:
#line 1125 "ctlib/parser.y"
{
	    yyval.list = PSTATE->curEnumList = LL_new();
	    if( yyvsp[0].pEnum->value.flags & V_IS_UNDEF ) {
	      yyvsp[0].pEnum->value.flags &= ~V_IS_UNDEF;
	      yyvsp[0].pEnum->value.iv     = 0;
	    }
	    LL_push( yyval.list, yyvsp[0].pEnum );
	  ;
    break;}
case 172:
#line 1134 "ctlib/parser.y"
{
	    if( yyvsp[0].pEnum->value.flags & V_IS_UNDEF ) {
	      Enumerator *pEnum = LL_get( yyvsp[-2].list, -1 );
	      yyvsp[0].pEnum->value.flags = pEnum->value.flags;
	      yyvsp[0].pEnum->value.iv    = pEnum->value.iv + 1;
	    }
	    LL_push( yyvsp[-2].list, yyvsp[0].pEnum );
	    yyval.list = yyvsp[-2].list;
	  ;
    break;}
case 173:
#line 1145 "ctlib/parser.y"
{
	    yyval.list = yyvsp[-1].list;
	  ;
    break;}
case 174:
#line 1152 "ctlib/parser.y"
{
	    yyval.pEnum = enum_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, NULL );
	    STORE_IN_HASH( htEnumerators, yyvsp[0].idOrType, yyval.pEnum );
	  ;
    break;}
case 175:
#line 1157 "ctlib/parser.y"
{
	    yyval.pEnum = enum_new( yyvsp[-2].idOrType.str, yyvsp[-2].idOrType.len, &yyvsp[0].value );
	    STORE_IN_HASH( htEnumerators, yyvsp[-2].idOrType, yyval.pEnum );
	  ;
    break;}
case 180:
#line 1174 "ctlib/parser.y"
{;
    break;}
case 181:
#line 1175 "ctlib/parser.y"
{;
    break;}
case 182:
#line 1176 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 183:
#line 1177 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 184:
#line 1178 "ctlib/parser.y"
{;
    break;}
case 185:
#line 1179 "ctlib/parser.y"
{;
    break;}
case 186:
#line 1180 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 187:
#line 1181 "ctlib/parser.y"
{;
    break;}
case 188:
#line 1182 "ctlib/parser.y"
{;
    break;}
case 189:
#line 1183 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 190:
#line 1184 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 191:
#line 1185 "ctlib/parser.y"
{;
    break;}
case 192:
#line 1186 "ctlib/parser.y"
{;
    break;}
case 193:
#line 1187 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 194:
#line 1195 "ctlib/parser.y"
{ HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;
    break;}
case 195:
#line 1196 "ctlib/parser.y"
{ HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;
    break;}
case 196:
#line 1201 "ctlib/parser.y"
{
	    yyval.idOrType.str    = yyvsp[0].identifier->key;
	    yyval.idOrType.len    = yyvsp[0].identifier->keylen;
	    yyval.idOrType.hash   = yyvsp[0].identifier->hash;
	    yyval.idOrType.node   = yyvsp[0].identifier;
	  ;
    break;}
case 197:
#line 1208 "ctlib/parser.y"
{
	    yyval.idOrType.str    = ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier;
	    HASH_STR_LEN( yyval.idOrType.hash, yyval.idOrType.str, yyval.idOrType.len );
	    yyval.idOrType.node   = NULL;
	  ;
    break;}
case 198:
#line 1217 "ctlib/parser.y"
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
	  ;
    break;}
case 199:
#line 1229 "ctlib/parser.y"
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
	  ;
    break;}
case 200:
#line 1246 "ctlib/parser.y"
{
	    yyval.value.iv = PSTATE->pCPC->int_size;
	    yyval.value.flags = 0;
	  ;
    break;}
case 201:
#line 1251 "ctlib/parser.y"
{
	    yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
                    PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	    yyval.value.flags = 0;
	  ;
    break;}
case 206:
#line 1266 "ctlib/parser.y"
{;
    break;}
case 214:
#line 1286 "ctlib/parser.y"
{ DELETE_NODE( yyvsp[0].idOrType ); ;
    break;}
case 221:
#line 1300 "ctlib/parser.y"
{ DELETE_NODE( yyvsp[-2].idOrType ); ;
    break;}
case 239:
#line 1339 "ctlib/parser.y"
{ DELETE_NODE( yyvsp[-1].idOrType ); ;
    break;}
case 249:
#line 1365 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 250:
#line 1367 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 251:
#line 1369 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 252:
#line 1371 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 253:
#line 1373 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 254:
#line 1375 "ctlib/parser.y"
{;
    break;}
case 255:
#line 1376 "ctlib/parser.y"
{;
    break;}
case 256:
#line 1377 "ctlib/parser.y"
{;
    break;}
case 257:
#line 1378 "ctlib/parser.y"
{;
    break;}
case 258:
#line 1379 "ctlib/parser.y"
{;
    break;}
case 259:
#line 1381 "ctlib/parser.y"
{;
    break;}
case 260:
#line 1382 "ctlib/parser.y"
{;
    break;}
case 261:
#line 1383 "ctlib/parser.y"
{;
    break;}
case 262:
#line 1384 "ctlib/parser.y"
{;
    break;}
case 263:
#line 1385 "ctlib/parser.y"
{;
    break;}
case 264:
#line 1389 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 265:
#line 1390 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 266:
#line 1394 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 267:
#line 1395 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 268:
#line 1400 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (size=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_size(PSTATE->declaratorList)) );
	  ;
    break;}
case 269:
#line 1407 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[-1].tspec.ptr)->pDecl->identifier, 0 );
	    if( yyvsp[0].list )
	      LL_delete( LL_splice( yyval.pDecl->array, 0, 0, EX_ARRAY( yyvsp[0].list ) ) );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (size=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_size(PSTATE->declaratorList)) );
	  ;
    break;}
case 270:
#line 1415 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 271:
#line 1422 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 272:
#line 1424 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 273:
#line 1429 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 274:
#line 1436 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 275:
#line 1438 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;
    break;}
case 276:
#line 1448 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 277:
#line 1450 "ctlib/parser.y"
{
	    yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;
    break;}
case 278:
#line 1455 "ctlib/parser.y"
{
	    yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;
    break;}
case 279:
#line 1460 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 280:
#line 1465 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 281:
#line 1472 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 282:
#line 1474 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;
    break;}
case 283:
#line 1479 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;
    break;}
case 284:
#line 1487 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (size=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_size(PSTATE->declaratorList)) );
	  ;
    break;}
case 285:
#line 1493 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 286:
#line 1497 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 287:
#line 1498 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 288:
#line 1502 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 289:
#line 1504 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 290:
#line 1509 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 291:
#line 1517 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;
    break;}
case 292:
#line 1521 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 293:
#line 1523 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;
    break;}
case 294:
#line 1531 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( yyvsp[0].identifier->key, yyvsp[0].identifier->keylen );
	    HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (size=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_size(PSTATE->declaratorList)) );
	  ;
    break;}
case 295:
#line 1538 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 296:
#line 1542 "ctlib/parser.y"
{;
    break;}
case 297:
#line 1543 "ctlib/parser.y"
{;
    break;}
case 298:
#line 1544 "ctlib/parser.y"
{;
    break;}
case 299:
#line 1549 "ctlib/parser.y"
{
	    decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  ;
    break;}
case 300:
#line 1552 "ctlib/parser.y"
{;
    break;}
case 301:
#line 1554 "ctlib/parser.y"
{
	    LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;
    break;}
case 302:
#line 1560 "ctlib/parser.y"
{ yyval.absDecl = yyvsp[0].absDecl; ;
    break;}
case 303:
#line 1561 "ctlib/parser.y"
{ yyval.absDecl = yyvsp[0].absDecl; ;
    break;}
case 304:
#line 1563 "ctlib/parser.y"
{
	    Value *pValue;
	    yyval.absDecl.pointer_flag  = 0;
	    yyval.absDecl.multiplicator = 1;
	    if( yyvsp[0].list ) {
	      LL_foreach( pValue, yyvsp[0].list )
	        yyval.absDecl.multiplicator *= pValue->iv;
	    }
	    LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;
    break;}
case 305:
#line 1576 "ctlib/parser.y"
{ yyval.list = yyvsp[0].list;   ;
    break;}
case 306:
#line 1577 "ctlib/parser.y"
{ yyval.list = NULL; ;
    break;}
case 307:
#line 1578 "ctlib/parser.y"
{ yyval.list = NULL; ;
    break;}
case 308:
#line 1582 "ctlib/parser.y"
{ yyval.list = NULL; ;
    break;}
case 309:
#line 1584 "ctlib/parser.y"
{
	    yyval.list = LL_new();
	    LL_unshift( PSTATE->arrayList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting array (0x%08X) (size=%d)",
	                       yyval.list, LL_size(PSTATE->arrayList)) );
	    LL_push( yyval.list, value_new( yyvsp[-1].value.iv, yyvsp[-1].value.flags ) );
	    CT_DEBUG( PARSER, ("array dimension => %d", yyvsp[-1].value) );
	  ;
    break;}
case 310:
#line 1593 "ctlib/parser.y"
{
	    yyval.list = LL_new();
	    LL_unshift( PSTATE->arrayList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting array (0x%08X) (size=%d)",
	                       yyval.list, LL_size(PSTATE->arrayList)) );
	    LL_push( yyval.list, value_new( 0, 0 ) );
	    CT_DEBUG( PARSER, ("array dimension => *") );
	  ;
    break;}
case 311:
#line 1602 "ctlib/parser.y"
{
	    if( yyvsp[-3].list ) {
              yyval.list = yyvsp[-3].list;
	    }
	    else {
              yyval.list = LL_new();
	      LL_unshift( PSTATE->arrayList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting array (0x%08X) (size=%d)",
	                         yyval.list, LL_size(PSTATE->arrayList)) );
	    }
	    LL_push( yyval.list, value_new( yyvsp[-1].value.iv, yyvsp[-1].value.flags ) );
	    CT_DEBUG( PARSER, ("array dimension => %d", yyvsp[-1].value) );
	  ;
    break;}
case 312:
#line 1616 "ctlib/parser.y"
{
	    if( yyvsp[-3].list ) {
              yyval.list = yyvsp[-3].list;
	    }
	    else {
              yyval.list = LL_new();
	      LL_unshift( PSTATE->arrayList, yyval.list );
	      CT_DEBUG( PARSER, ("unshifting array (0x%08X) (size=%d)",
	                         yyval.list, LL_size(PSTATE->arrayList)) );
	    }
	    LL_push( yyval.list, value_new( 0, 0 ) );
	    CT_DEBUG( PARSER, ("array dimension => *" ) );
	  ;
    break;}
case 313:
#line 1633 "ctlib/parser.y"
{
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;
    break;}
case 314:
#line 1638 "ctlib/parser.y"
{
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;
    break;}
case 315:
#line 1643 "ctlib/parser.y"
{
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;
    break;}
case 316:
#line 1648 "ctlib/parser.y"
{
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;
    break;}
case 317:
#line 1655 "ctlib/parser.y"
{ yyval.absDecl = yyvsp[-1].absDecl; ;
    break;}
case 318:
#line 1656 "ctlib/parser.y"
{ yyval.absDecl = yyvsp[-1].absDecl; ;
    break;}
case 319:
#line 1658 "ctlib/parser.y"
{
	    Value *pValue;
	    yyval.absDecl.pointer_flag  = 0;
	    yyval.absDecl.multiplicator = 1;
	    if( yyvsp[-1].list ) {
	      LL_foreach( pValue, yyvsp[-1].list )
	        yyval.absDecl.multiplicator *= pValue->iv;
	    }
	    LL_destroy( EX_ARRAY( yyvsp[-1].list ), (LLDestroyFunc) value_delete );
	  ;
    break;}
case 320:
#line 1669 "ctlib/parser.y"
{
	    yyval.absDecl = yyvsp[-2].absDecl;
	    LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;
    break;}
}

#line 705 "/usr/local/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

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
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
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
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

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

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 1675 "ctlib/parser.y"



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
        CT_DEBUG( CLEXER, ("new context: file '%s', line %ld",
                           pLexer->ctok->name, pLexer->ctok->line) );

        if( pState->filename )
          Free( pState->filename );

        pState->filename = (char *) Alloc( strlen( pLexer->ctok->name ) + 1 );
        strcpy( pState->filename, pLexer->ctok->name );
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
  CT_DEBUG( CLEXER, ("unshifting identifier \"%s\" (0x%08X) (size=%d)",
                     plval->identifier->key, plval->identifier, LL_size(pState->nodeList)) );

  return IDENTIFIER;
}
