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
* $Date: 2002/05/22 14:30:40 +0200 $
* $Revision: 3 $
* $Snapshot: /Convert-Binary-C/0.01 $
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



#define	YYFINAL		538
#define	YYFLAG		-32768
#define	YYNTBASE	87

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 316 ? yytranslate[x] : 194)

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
     264,   269,   270,   275,   276,   282,   283,   288,   289,   294,
     295,   301,   303,   305,   307,   309,   311,   313,   315,   318,
     321,   323,   326,   328,   330,   332,   334,   336,   339,   342,
     345,   348,   350,   353,   356,   359,   362,   365,   368,   370,
     373,   376,   379,   382,   385,   387,   390,   393,   395,   397,
     399,   401,   403,   405,   407,   409,   411,   413,   415,   417,
     419,   421,   423,   425,   427,   432,   438,   441,   443,   445,
     447,   450,   453,   456,   459,   463,   466,   470,   473,   475,
     478,   480,   481,   483,   486,   491,   497,   500,   502,   506,
     509,   511,   515,   517,   521,   523,   527,   529,   532,   535,
     538,   540,   543,   546,   548,   551,   554,   557,   559,   562,
     565,   567,   571,   573,   575,   577,   580,   582,   585,   586,
     589,   593,   598,   600,   603,   608,   609,   612,   614,   617,
     621,   624,   626,   628,   630,   632,   634,   636,   640,   645,
     649,   652,   656,   660,   665,   667,   670,   672,   675,   678,
     684,   692,   698,   704,   712,   722,   726,   729,   732,   736,
     737,   739,   741,   744,   746,   748,   751,   755,   759,   763,
     767,   770,   774,   778,   782,   786,   790,   795,   800,   805,
     810,   812,   814,   816,   818,   820,   823,   825,   827,   830,
     834,   838,   843,   845,   850,   856,   859,   863,   867,   872,
     877,   879,   883,   885,   887,   889,   892,   896,   899,   903,
     908,   910,   914,   916,   919,   923,   928,   932,   937,   939,
     941,   943,   945,   948,   952,   955,   959,   963,   968,   973,
     975,   978,   981,   985,   989,   993,   997
};
static const short yyrhs[] =
{
      60,     0,    87,    60,     0,    59,     0,    61,     0,    87,
       0,    63,   110,    64,     0,    88,     0,    89,    65,   110,
      66,     0,    89,    63,    64,     0,    89,    63,    93,    64,
       0,     0,    89,    90,    67,    92,     0,     0,    89,    91,
      37,    92,     0,    89,    38,     0,    89,    39,     0,    63,
     155,    64,    68,   158,    69,     0,    63,   155,    64,    68,
     158,    70,    69,     0,    59,     0,    62,     0,   108,     0,
      93,    70,   108,     0,    89,     0,    38,    94,     0,    39,
      94,     0,    95,    96,     0,    29,    94,     0,    29,    63,
     155,    64,     0,    71,     0,    72,     0,    73,     0,    74,
       0,    75,     0,    76,     0,    94,     0,    63,   155,    64,
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
       0,   130,    86,     0,   131,    86,     0,   118,    86,     0,
     114,    86,     0,     0,   124,   183,   115,   156,     0,     0,
     125,   183,   116,   156,     0,     0,   114,    70,   183,   117,
     156,     0,     0,   122,   175,   119,   156,     0,     0,   123,
     175,   120,   156,     0,     0,   118,    70,   175,   121,   156,
       0,   128,     0,   130,     0,   132,     0,   129,     0,   131,
       0,   133,     0,   134,     0,   125,   134,     0,   124,   126,
       0,   127,     0,   125,   127,     0,   134,     0,   127,     0,
      19,     0,    36,     0,    30,     0,   124,   135,     0,   129,
     134,     0,   128,   126,     0,   128,   135,     0,   135,     0,
     125,   135,     0,   129,   127,     0,   129,   135,     0,   124,
     136,     0,   131,   134,     0,   130,   126,     0,   136,     0,
     125,   136,     0,   131,   127,     0,   133,   134,     0,   124,
      62,     0,   132,   126,     0,    62,     0,   125,    62,     0,
     133,   127,     0,    14,     0,    16,     0,    33,     0,     3,
       0,    13,     0,    35,     0,     5,     0,    15,     0,    21,
       0,     9,     0,    20,     0,     4,     0,    25,     0,    22,
       0,    26,     0,   137,     0,   147,     0,   138,    68,   139,
      69,     0,   138,   154,    68,   139,    69,     0,   138,   154,
       0,     6,     0,    18,     0,   140,     0,   139,   140,     0,
     142,    86,     0,   141,    86,     0,   125,   144,     0,   141,
      70,   144,     0,   123,   143,     0,   142,    70,   143,     0,
     175,   145,     0,   146,     0,   183,   145,     0,   146,     0,
       0,   146,     0,    84,   111,     0,    12,    68,   148,    69,
       0,    12,   154,    68,   148,    69,     0,    12,   154,     0,
     149,     0,   148,    70,   149,     0,   148,    70,     0,   154,
       0,   154,    85,   111,     0,   151,     0,   151,    70,    48,
       0,   152,     0,   151,    70,   152,     0,   122,     0,   122,
     189,     0,   122,   183,     0,   122,   177,     0,   124,     0,
     124,   189,     0,   124,   183,     0,   123,     0,   123,   189,
       0,   123,   183,     0,   123,   177,     0,   125,     0,   125,
     189,     0,   125,   183,     0,    59,     0,   153,    70,    59,
       0,    59,     0,    62,     0,   123,     0,   123,   189,     0,
     125,     0,   125,   189,     0,     0,    85,   157,     0,    68,
     158,    69,     0,    68,   158,    70,    69,     0,   108,     0,
     159,   157,     0,   158,    70,   159,   157,     0,     0,   160,
      85,     0,   161,     0,   160,   161,     0,    65,   111,    66,
       0,    67,   154,     0,   163,     0,   164,     0,   167,     0,
     168,     0,   169,     0,   170,     0,   154,    84,   162,     0,
      11,   111,    84,   162,     0,    27,    84,   162,     0,    68,
      69,     0,    68,   165,    69,     0,    68,   166,    69,     0,
      68,   165,   166,    69,     0,   113,     0,   165,   113,     0,
     162,     0,   166,   162,     0,   112,    86,     0,    32,    63,
     110,    64,   162,     0,    32,    63,   110,    64,   162,     8,
     162,     0,    10,    63,   110,    64,   162,     0,    34,    63,
     110,    64,   162,     0,    31,   162,    34,    63,   110,    64,
      86,     0,    24,    63,   112,    86,   112,    86,   112,    64,
     162,     0,    28,   154,    86,     0,    23,    86,     0,     7,
      86,     0,    17,   112,    86,     0,     0,   172,     0,   173,
       0,   172,   173,     0,   174,     0,   113,     0,   183,   164,
       0,   122,   183,   164,     0,   123,   183,   164,     0,   124,
     183,   164,     0,   125,   183,   164,     0,   187,   164,     0,
     122,   187,   164,     0,   123,   187,   164,     0,   124,   187,
     164,     0,   125,   187,   164,     0,   187,   165,   164,     0,
     122,   187,   165,   164,     0,   123,   187,   165,   164,     0,
     124,   187,   165,   164,     0,   125,   187,   165,   164,     0,
     183,     0,   176,     0,   180,     0,   177,     0,    62,     0,
      62,   190,     0,   178,     0,   179,     0,    72,   177,     0,
      72,   125,   177,     0,    63,   178,    64,     0,    63,   178,
      64,   190,     0,   181,     0,    72,    63,   182,    64,     0,
      72,   125,    63,   182,    64,     0,    72,   180,     0,    72,
     125,   180,     0,    63,   180,    64,     0,    63,   182,   190,
      64,     0,    63,   180,    64,   190,     0,    62,     0,    63,
     182,    64,     0,   184,     0,   186,     0,   185,     0,    72,
     183,     0,    72,   125,   183,     0,   186,   190,     0,    63,
     184,    64,     0,    63,   184,    64,   190,     0,    59,     0,
      63,   186,    64,     0,   188,     0,    72,   187,     0,    72,
     125,   187,     0,   186,    63,   153,    64,     0,    63,   187,
      64,     0,    63,   187,    64,   190,     0,   192,     0,   193,
       0,   190,     0,   191,     0,    63,    64,     0,    63,   150,
      64,     0,    65,    66,     0,    65,   108,    66,     0,    65,
      72,    66,     0,   191,    65,   108,    66,     0,   191,    65,
      72,    66,     0,    72,     0,    72,   125,     0,    72,   189,
       0,    72,   125,   189,     0,    63,   192,    64,     0,    63,
     193,    64,     0,    63,   190,    64,     0,    63,   192,    64,
     190,     0
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
     748,   755,   755,   762,   762,   771,   771,   777,   777,   784,
     784,   794,   799,   800,   805,   810,   811,   817,   818,   819,
     823,   824,   828,   829,   833,   834,   835,   839,   840,   841,
     842,   846,   847,   848,   849,   853,   858,   863,   871,   872,
     873,   878,   883,   888,   896,   897,   898,   902,   903,   904,
     905,   906,   907,   911,   912,   913,   914,   915,   916,   917,
     918,   919,   923,   924,   928,   934,   959,   979,   980,   984,
     992,  1000,  1001,  1005,  1015,  1024,  1035,  1044,  1049,  1057,
    1062,  1070,  1071,  1075,  1079,  1086,  1110,  1130,  1139,  1150,
    1157,  1162,  1170,  1171,  1175,  1176,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,
    1201,  1202,  1206,  1213,  1222,  1234,  1251,  1256,  1265,  1266,
    1270,  1271,  1272,  1276,  1277,  1281,  1282,  1286,  1287,  1291,
    1292,  1297,  1298,  1299,  1300,  1301,  1302,  1306,  1307,  1308,
    1312,  1313,  1314,  1315,  1319,  1320,  1324,  1325,  1329,  1333,
    1334,  1335,  1339,  1340,  1341,  1345,  1346,  1347,  1348,  1355,
    1356,  1360,  1361,  1365,  1366,  1370,  1372,  1374,  1376,  1378,
    1381,  1382,  1383,  1384,  1385,  1387,  1388,  1389,  1390,  1391,
    1395,  1396,  1400,  1401,  1405,  1412,  1421,  1428,  1429,  1434,
    1442,  1443,  1454,  1455,  1460,  1465,  1470,  1478,  1479,  1484,
    1492,  1499,  1503,  1504,  1508,  1509,  1514,  1522,  1527,  1528,
    1536,  1544,  1548,  1549,  1550,  1554,  1558,  1559,  1566,  1567,
    1568,  1582,  1583,  1584,  1588,  1589,  1598,  1607,  1621,  1638,
    1643,  1648,  1653,  1661,  1662,  1663,  1674
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
  "comma_expression_opt", "declaration", "default_declaring_list", "@3", 
  "@4", "@5", "declaring_list", "@6", "@7", "@8", "declaration_specifier", 
  "type_specifier", "declaration_qualifier_list", "type_qualifier_list", 
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
     110,   110,   111,   112,   112,   113,   113,   113,   113,   115,
     114,   116,   114,   117,   114,   119,   118,   120,   118,   121,
     118,   122,   122,   122,   123,   123,   123,   124,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   128,   128,   128,
     128,   129,   129,   129,   129,   130,   130,   130,   131,   131,
     131,   132,   132,   132,   133,   133,   133,   134,   134,   134,
     134,   134,   134,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   136,   137,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   145,   145,   146,   147,   147,   147,   148,   148,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     153,   153,   154,   154,   155,   155,   155,   155,   156,   156,
     157,   157,   157,   158,   158,   159,   159,   160,   160,   161,
     161,   162,   162,   162,   162,   162,   162,   163,   163,   163,
     164,   164,   164,   164,   165,   165,   166,   166,   167,   168,
     168,   168,   169,   169,   169,   170,   170,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     175,   175,   176,   176,   177,   177,   177,   178,   178,   178,
     179,   179,   180,   180,   180,   180,   180,   181,   181,   181,
     182,   182,   183,   183,   184,   184,   184,   185,   185,   185,
     186,   186,   187,   187,   187,   188,   188,   188,   189,   189,
     189,   190,   190,   190,   191,   191,   191,   191,   191,   192,
     192,   192,   192,   193,   193,   193,   193
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
       1,     3,     1,     0,     1,     2,     2,     2,     2,     0,
       4,     0,     4,     0,     5,     0,     4,     0,     4,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     2,     1,     1,     1,
       2,     2,     2,     2,     3,     2,     3,     2,     1,     2,
       1,     0,     1,     2,     4,     5,     2,     1,     3,     2,
       1,     3,     1,     3,     1,     3,     1,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     2,     1,     2,     2,
       1,     3,     1,     1,     1,     2,     1,     2,     0,     2,
       3,     4,     1,     2,     4,     0,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     3,     4,     1,     2,     1,     2,     2,     5,
       7,     5,     5,     7,     9,     3,     2,     2,     3,     0,
       1,     1,     2,     1,     1,     2,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     3,
       3,     4,     1,     4,     5,     2,     3,     3,     4,     4,
       1,     3,     1,     1,     1,     2,     3,     2,     3,     4,
       1,     3,     1,     2,     3,     4,     3,     4,     1,     1,
       1,     1,     2,     3,     2,     3,     3,     4,     4,     1,
       2,     2,     3,     3,     3,     3,     4
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
     249,   140,   148,   143,   157,   146,     0,   141,   137,   144,
     138,   158,   114,   147,   145,   150,   149,   151,   116,   139,
     142,   115,   300,   134,     0,     0,   254,     0,     0,     0,
       0,     0,     0,   110,   101,   104,   102,   105,   103,   106,
     107,   121,   128,   152,     0,   153,   250,   251,   253,     0,
     292,   294,   293,     0,   302,   202,   203,     0,   176,     0,
       0,     0,     0,   295,   303,     0,    88,     0,    87,   274,
       0,     0,    95,   271,   273,   276,   277,   272,   282,   270,
       0,    97,   270,     0,   132,   109,   113,   112,   117,   125,
      89,     0,   135,   111,   108,   122,   129,    91,     0,   119,
     120,   123,   118,   124,    85,   127,    86,   130,   126,   133,
     136,   131,     0,   156,   252,    83,   255,     0,     0,   297,
     311,   234,     0,     0,     0,     0,   260,     0,     0,   177,
     180,     0,   298,   301,   306,   296,   304,     0,     0,    93,
     293,     0,     0,    99,   270,     0,   275,   290,     0,     0,
       0,     0,     0,     0,   278,   285,   208,   256,   261,     0,
     208,   257,   262,     0,   208,   258,   263,     0,   208,   259,
     264,     0,     0,     0,   104,   105,   106,     0,   159,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     3,     1,     4,   134,
       0,   230,    29,    30,    31,    32,    33,    34,     5,     7,
      23,    35,     0,    37,    41,    44,    47,    52,    55,    57,
      59,    61,    63,    65,    67,    80,    84,     0,     0,   236,
     221,   222,    83,    83,   223,   224,   225,   226,   200,   312,
     186,   193,   190,   197,   102,   105,     0,   182,   184,     0,
       3,   314,    30,     0,     0,    89,    91,   235,   265,   174,
     179,     0,     0,   299,   307,     0,     0,   208,     0,     0,
       0,   208,     0,   280,   287,     0,     0,     0,   279,   286,
       0,    96,   266,    98,   267,    90,   268,    92,   269,     0,
     165,   168,   171,   163,   170,   171,   154,   160,     0,   162,
       0,   161,     0,   247,     0,    35,    82,     0,     0,   246,
      83,    83,     0,     0,    27,     0,     0,     0,     0,    24,
      25,     0,   204,   206,     0,     2,    15,    16,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    69,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,    83,   231,    83,   232,
     237,     0,   319,   189,   188,   187,   310,   308,   309,   196,
     195,   194,     0,   319,   192,   191,   199,   198,   313,     0,
     305,     0,   316,   315,    30,     0,   178,   181,   175,    94,
       0,   100,   291,   281,   289,   288,   283,     0,   215,   212,
     209,   173,   167,   172,   169,   164,   166,   155,     0,    83,
     248,     0,   229,   245,     0,     0,     0,     0,     0,     6,
       0,   319,   205,   207,     0,     9,     0,    21,     0,     0,
       0,    68,    38,    39,    40,    42,    43,    45,    46,    50,
      51,    48,    49,    53,    54,    56,    58,    60,    62,    64,
       0,    81,   227,   233,     0,     0,     0,   320,   321,   320,
     183,   185,   201,   318,   317,   284,     0,     0,     0,     0,
       0,   217,    83,   228,    83,    28,     0,    83,    83,     0,
     320,   215,    36,    10,     0,     8,    19,    20,    12,    14,
       0,   325,   323,   324,   322,     0,   220,   210,   215,   213,
     216,   218,   241,     0,     0,   239,   242,     0,    22,    66,
     326,   219,   211,     0,    83,     0,    83,    17,   215,   214,
       0,   243,   240,    18,    83,   244,     0,     0,     0
};

static const short yydefgoto[] =
{
     208,   209,   210,   330,   331,   498,   436,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   343,   226,   307,   227,   121,    27,   164,   168,
     267,    28,   156,   160,   271,   122,   123,   124,   125,    85,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,   177,   178,   179,   180,   290,   293,   412,   291,
      45,   128,   129,   246,   247,   248,   249,   228,   324,   281,
     410,   478,   479,   480,   481,   229,   230,   231,   127,   233,
     234,   235,   236,   237,   536,    46,    47,    48,    72,    73,
      74,    75,    76,   150,    78,   151,    63,    50,    51,   140,
      61,    54,   468,   376,   120,   377,   378
};

static const short yypact[] =
{
    1518,-32768,-32768,-32768,-32768,-32768,    60,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,    93,   163,-32768,   -14,    14,   465,
     465,  1553,  1588,-32768,  2186,  2186,   643,   701,   935,   935,
  -32768,-32768,-32768,-32768,   241,-32768,  1518,-32768,-32768,     6,
  -32768,-32768,   166,  1748,-32768,-32768,-32768,    52,    41,    23,
     142,    84,   163,-32768,-32768,   138,-32768,   479,-32768,   183,
     485,   714,-32768,-32768,-32768,-32768,-32768,-32768,-32768,     6,
    1748,-32768,     6,  1748,-32768,-32768,-32768,-32768,-32768,-32768,
       6,  1748,-32768,-32768,-32768,-32768,-32768,     6,  1748,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,   985,    58,-32768,   810,-32768,  1854,  1929,-32768,
      92,-32768,   479,   479,  1623,  1658,-32768,  1748,   -41,-32768,
      87,    52,   183,-32768,   183,-32768,-32768,   138,   373,-32768,
     183,   511,   732,-32768,-32768,  1889,-32768,-32768,   485,   131,
     157,   183,   485,  1005,-32768,-32768,   168,-32768,-32768,  1748,
     168,-32768,-32768,  1748,   168,-32768,-32768,  1748,   168,-32768,
  -32768,  1748,   215,   734,  1190,    62,    62,  1781,-32768,    26,
      46,   985,   175,   206,  2034,  2034,   202,   221,   208,    52,
    2060,  1252,   244,   261,  2086,  2086,   233,-32768,-32768,   268,
     957,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   294,-32768,
     549,   807,  2034,-32768,   198,   117,   288,    10,   301,   312,
     290,   304,   347,   -17,-32768,-32768,   337,   339,   343,-32768,
  -32768,-32768,   884,  1027,-32768,-32768,-32768,-32768,-32768,-32768,
     297,   297,  1326,  1390,   935,   935,   366,   364,-32768,     9,
  -32768,-32768,   372,   374,  2112,-32768,-32768,-32768,-32768,-32768,
      52,  2034,   306,-32768,-32768,   174,   373,   168,   511,   511,
    1075,   168,   410,   183,   183,   380,   427,   485,-32768,-32768,
    1955,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  2034,
  -32768,-32768,   381,-32768,-32768,   381,-32768,-32768,   442,-32768,
     215,-32768,  1809,-32768,  2034,-32768,-32768,   383,   384,-32768,
    2034,  1252,   392,   957,-32768,   447,  2034,  2034,   957,-32768,
  -32768,   109,   146,  1693,   423,-32768,-32768,-32768,  1981,  2034,
     426,   459,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,  2034,-32768,  2034,  2034,  2034,  2034,  2034,
    2034,  2034,  2034,  2034,  2034,  2034,  2034,  2034,  2034,  2034,
    2034,  2034,  2034,  2034,  2034,-32768,  1252,-32768,  1097,-32768,
  -32768,  1171,   631,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,  1235,    88,-32768,-32768,-32768,-32768,-32768,  1924,
  -32768,   443,-32768,-32768,   444,   456,-32768,-32768,-32768,-32768,
     511,-32768,-32768,-32768,-32768,-32768,-32768,   531,   239,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   216,  1252,
  -32768,   437,-32768,-32768,   461,   466,   256,   300,   467,-32768,
    1454,   253,-32768,-32768,  2008,-32768,   310,-32768,   105,   209,
     209,-32768,-32768,-32768,-32768,   198,   198,   117,   117,   288,
     288,   288,   288,    10,    10,   301,   312,   290,   304,   347,
     -15,-32768,-32768,-32768,   469,   472,   476,   631,-32768,    88,
  -32768,-32768,-32768,-32768,-32768,-32768,  2034,    52,   327,  1955,
     -31,-32768,  1252,-32768,  2034,   478,  2034,  1252,  1252,   478,
     253,   239,-32768,-32768,  2034,-32768,-32768,-32768,-32768,-32768,
    2034,-32768,   183,-32768,-32768,   492,-32768,-32768,   359,-32768,
  -32768,-32768,-32768,   477,   321,   556,-32768,   350,-32768,-32768,
  -32768,-32768,-32768,  1955,  2034,   483,  1252,-32768,   390,-32768,
     514,-32768,-32768,-32768,  1252,-32768,   575,   579,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,-32768,-32768,   145,-32768,   282,-32768,  -169,
     102,   111,   154,   193,   224,   231,   237,   232,   236,-32768,
    -162,  -100,-32768,   182,  -213,  -161,   184,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,    13,    19,    16,    17,     3,
     -30,-32768,   167,   -77,   150,-32768,   254,   481,   379,   135,
  -32768,-32768,   418,  -167,-32768,-32768,   303,   302,   309,  -106,
  -32768,   482,   349,-32768,-32768,   226,-32768,    -6,  -287,   -63,
    -465,   126,  -458,-32768,   143,   -70,-32768,   528,    -5,   413,
  -32768,-32768,-32768,-32768,-32768,-32768,   578,-32768,    -3,-32768,
     -38,   -35,-32768,   412,-32768,  -127,    15,    33,-32768,   220,
     530,-32768,    99,   -49,-32768,  -359,  -322
};


#define	YYLAST		2222


static const short yytable[] =
{
      58,    86,    93,   119,    86,   101,    86,   107,    86,   110,
     297,   119,   465,    29,   509,    49,    31,    32,   253,    30,
     146,   272,   306,   465,   308,   276,   424,    81,   259,   260,
     362,   428,    93,   154,   476,   149,   477,    99,   113,   105,
     244,   109,    62,   344,    79,    82,    90,    97,   397,   466,
     523,   130,   352,   353,   510,   364,    65,    59,   529,    29,
     466,    49,    31,    32,   143,    30,   363,   294,   244,   500,
     523,   465,    66,   390,   115,   159,   411,   135,   163,   391,
     139,    12,   144,   263,    67,   264,   167,   132,   153,   354,
     355,   119,    18,   171,    86,    93,   298,   283,    21,   306,
      68,   285,   275,    59,   154,   287,   149,    12,   466,   131,
     232,    55,   299,   149,    56,   278,   300,   149,    18,    55,
      81,   315,    56,    93,    21,   130,   181,   306,    57,   173,
     240,   172,   301,   242,   243,   297,   241,   144,   144,   255,
     256,   272,   276,    93,   101,   107,   110,    22,   134,   421,
     407,   382,    22,   118,   395,   266,    24,   254,   240,   270,
     383,   242,   243,   370,   241,    25,    89,    96,   135,   292,
      59,   495,   261,   429,    59,   364,   442,   443,   444,   364,
     409,    59,    12,   312,    26,    59,   413,   144,   295,   413,
     348,   349,   294,    18,   173,   273,   172,    22,   173,    21,
     172,   137,   373,   379,   399,   117,   133,   118,   401,   430,
     138,   118,    86,    93,    86,   107,   119,   323,   431,   322,
      52,   274,    22,   275,   403,   404,    24,   275,   437,   117,
      26,   118,   278,   149,   149,    25,    93,   145,   133,   118,
      93,   422,   149,   441,    60,    52,   145,   105,   118,    52,
      52,    52,    52,   280,   130,   374,   380,   384,   386,    89,
      96,   303,   175,   505,   461,   492,    52,   245,   496,   304,
     345,   497,    12,   407,    22,   346,   347,    69,   141,   174,
     482,   135,    52,    18,   310,   135,   364,   142,   309,    21,
      60,    52,   311,    93,   244,   245,   462,   292,   370,   289,
      55,    59,    59,    56,   476,   244,   477,   316,    96,   112,
      59,   257,   244,   295,   306,   144,   430,  -202,   118,   173,
     487,   172,   464,   513,   317,   431,   364,   175,   350,   351,
     323,   175,   322,   464,   154,   323,   149,   322,   519,   375,
     381,   385,   387,   257,   174,   356,   357,   257,   174,   483,
     175,   257,  -203,   244,   325,   257,    22,   265,   275,    69,
     371,   265,   118,   530,   488,   149,   176,   174,    60,   372,
     364,   359,    60,    52,   493,   398,   260,    89,    96,   409,
     494,   464,   321,   358,   240,   525,   360,   242,   243,   467,
     241,   364,    12,   361,   518,   240,   507,   508,   242,   243,
     469,   241,   240,    18,    59,   242,   243,   364,   241,    21,
      88,    95,   512,   100,   103,    59,   257,   515,   516,   527,
     528,   432,   433,   409,   476,   365,   477,   366,   522,   278,
     388,   176,    22,    59,   389,   176,   137,    93,   392,    93,
     393,    77,    77,   240,   405,   138,   242,   243,   490,   241,
     445,   446,   175,   520,   176,   476,   532,   477,    96,   533,
      93,   447,   448,   175,   535,   289,   305,   419,   175,   174,
     420,   506,   314,   145,   402,   118,   319,   320,   423,    77,
     174,   425,   135,   155,   135,   174,   418,   434,   265,   265,
     145,   406,   118,   439,   305,   321,   440,    60,   426,   427,
     321,    22,   472,    88,    95,   137,   449,   450,   451,   452,
     473,   438,    87,    94,   138,    87,   102,    87,   108,    87,
     111,   245,   474,   484,    22,   485,   289,    69,    70,   486,
      53,   489,   245,   501,    77,    77,   502,    71,    22,   245,
     503,    69,   141,   305,    22,   460,   491,   147,   148,   453,
     454,   142,    95,   103,   155,    64,   176,    71,   521,    80,
      83,    91,    98,   524,   526,   279,   504,   176,   504,   531,
      22,   305,   176,   147,   268,   537,    53,   116,   534,   538,
     245,   126,   455,   142,    77,   499,   -13,   326,   327,   504,
     456,   265,   136,   458,   145,   475,   118,   457,   459,   302,
     415,    64,   265,   416,   414,    87,    94,   157,   158,   396,
     161,   162,   328,   262,   329,   471,   -11,   517,   165,   166,
     265,    88,    95,   511,   114,   169,   170,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   368,     1,     0,     0,     0,
      12,     0,     0,     0,     0,   258,     7,     8,     0,    10,
       0,    18,    12,     0,     0,     0,     0,    21,   514,     0,
       0,     0,     0,    18,     0,     0,    19,     0,    20,    21,
       0,     0,   279,   136,     0,     0,     0,   282,     0,     0,
      22,   284,     0,    69,   371,   286,   118,     0,     0,   288,
       0,     0,    95,   372,     1,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     7,     8,   305,    10,     0,     0,
      12,     0,     0,    87,    94,    87,   108,     0,     0,   104,
       0,    18,     0,    12,    19,     0,    20,    21,     2,     3,
       4,     0,     0,     5,    18,     0,     6,     0,     0,     9,
      21,    12,    11,    12,    13,    14,    15,     0,   305,    16,
      17,     0,    18,     0,    18,     0,     0,     0,    21,     0,
      21,     0,     0,    22,     0,     0,    69,   152,     0,     0,
       0,     0,   305,     0,     0,     0,    71,   106,     0,     0,
       0,    22,     0,    22,    69,   269,    92,   137,     0,     0,
       0,     0,     0,     0,   142,     0,   138,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,   182,   289,     5,
     183,   184,     6,     7,     8,     9,    10,   185,    11,    12,
      13,    14,    15,   186,   187,    16,    17,   188,   189,   190,
      18,   191,   192,    19,   193,    20,    21,     0,   194,   195,
       0,     0,     0,     0,     0,     0,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     0,     0,     0,   196,
     197,   198,   199,   200,     0,     0,     0,     0,   115,   201,
       0,   202,   203,   204,   205,   206,   207,     1,     2,     3,
       4,   182,   342,     5,   183,   184,     6,     7,     8,     9,
      10,   185,    11,    12,    13,    14,    15,   186,   187,    16,
      17,   188,   189,   190,    18,   191,   192,    19,   193,    20,
      21,     0,   194,   195,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,   196,   197,   198,   199,   200,     7,     8,
       0,    10,   115,   367,    12,   202,   203,   204,   205,   206,
     207,     2,     3,     4,     0,    18,     5,     0,    19,     6,
      20,    21,     9,     0,     0,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,   190,    18,     0,     2,
       3,     4,     0,    21,     5,   194,   195,     6,     0,     0,
       9,     0,     0,    11,    12,    13,    14,    15,     0,     0,
      16,    17,     0,     0,     0,    18,   250,   197,   198,    23,
     200,    21,     0,     0,    12,     0,     0,     0,   202,   203,
     204,   205,   206,   207,   182,    18,     0,   183,   184,     0,
       0,    21,     0,     0,   185,     0,     0,    23,     0,     0,
     186,   187,     0,     0,   188,   189,   190,     0,   191,   192,
       0,   193,     0,     0,    22,   194,   195,    69,   277,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       0,     0,     0,     0,     0,     0,   196,   197,   198,    56,
     200,     0,     0,     0,    12,   115,   369,     0,   202,   203,
     204,   205,   206,   207,   182,    18,     0,   183,   184,     0,
       0,    21,     0,     0,   185,     0,     0,     0,     0,     0,
     186,   187,     0,     0,   188,   189,   190,     0,   191,   192,
       0,   193,     0,     0,    22,   194,   195,    69,   400,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,   196,   197,   198,    56,
     200,     0,     0,     0,     0,   115,   463,     0,   202,   203,
     204,   205,   206,   207,     1,     2,     3,     4,     0,     0,
       5,     0,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     2,     3,    16,    17,     0,     5,
       0,    18,     0,     0,    19,     9,    20,    21,     0,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,     0,     0,    23,   371,   239,   118,     0,     1,     2,
       3,     4,     0,   372,     5,     0,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,   182,
      16,    17,   183,   184,     0,    18,     0,     0,    19,   185,
      20,    21,     0,     0,     0,   186,   187,     0,     0,   188,
     189,   190,     0,   191,   192,     0,   193,     0,     0,     0,
     194,   195,     0,     0,    22,     0,     0,    23,   382,   239,
     118,     0,     0,     0,     0,     0,     0,   383,     0,     0,
       0,   196,   197,   198,    56,   200,     0,     0,     0,     0,
     115,     0,     0,   202,   203,   204,   205,   206,   207,     1,
       2,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,    84,   382,
       0,   118,     0,     1,     2,     3,     4,     0,   383,     5,
       0,     0,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,    92,   382,     0,   118,     0,     1,     2,     3,
       4,     0,   383,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,   430,   239,   118,
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
     296,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,    23,    11,    12,    13,    14,    15,     0,   417,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,    20,
      21,     0,     1,     2,     3,     4,     0,     0,     5,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,   238,    16,    17,    23,     0,   239,    18,
       0,     0,    19,     0,    20,    21,     0,     1,     2,     3,
       4,     0,     0,     5,     0,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
      17,    23,     0,   239,    18,     0,     0,    19,   190,    20,
      21,     0,     0,     0,     0,     0,     0,   194,   195,     0,
       0,     0,   470,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,     0,    23,     0,   250,   197,
     198,     0,   200,   194,   195,   251,     0,     0,     0,     0,
     202,   252,   204,   205,   206,   207,     0,     0,     0,     0,
     190,     0,     0,     0,   250,   197,   198,     0,   200,   194,
     195,     0,     0,   408,     0,     0,   202,   203,   204,   205,
     206,   207,     0,     0,     0,     0,     0,   190,     0,     0,
     250,   197,   198,     0,   200,   435,   194,   195,     0,     0,
       0,     0,   202,   203,   204,   205,   206,   207,     0,     0,
       0,     0,     0,   190,     0,     0,     0,   250,   197,   198,
       0,   200,   194,   195,     0,     0,   491,     0,     0,   202,
     203,   204,   205,   206,   207,     0,     0,     0,     0,   190,
       0,     0,     0,   250,   197,   198,     0,   200,   194,   195,
       0,     0,     0,     0,     0,   202,   203,   204,   205,   206,
     207,     0,     0,     0,     0,   190,     0,     0,     0,   250,
     197,   198,     0,   313,   194,   195,     0,     0,     0,     0,
       0,   202,   203,   204,   205,   206,   207,     0,     0,     0,
       0,   190,     0,     0,     0,   250,   197,   198,     0,   318,
     194,   195,     0,     0,     0,     0,     0,   202,   203,   204,
     205,   206,   207,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   197,   198,     0,   200,     0,     0,     0,     0,
       0,     0,     0,   202,   394,   204,   205,   206,   207,     1,
       2,     3,     0,     0,     0,     5,     0,     0,     0,     7,
       8,     9,    10,     0,     0,    12,    13,    14,    15,     0,
       0,    16,    17,     0,     0,     0,    18,     0,     0,    19,
       0,    20,    21
};

static const short yycheck[] =
{
       6,    31,    32,    52,    34,    35,    36,    37,    38,    39,
     177,    60,   371,     0,   479,     0,     0,     0,   118,     0,
      69,   148,   184,   382,   185,   152,   313,    30,    69,    70,
      47,   318,    62,    71,    65,    70,    67,    34,    44,    36,
     117,    38,    25,   212,    29,    30,    31,    32,   261,   371,
     508,    57,    42,    43,    85,    70,    70,    24,   523,    46,
     382,    46,    46,    46,    67,    46,    83,   173,   145,    84,
     528,   430,    86,    64,    68,    80,   289,    62,    83,    70,
      65,    19,    67,   132,    70,   134,    91,    64,    71,    79,
      80,   140,    30,    98,   124,   125,    70,   160,    36,   261,
      86,   164,   151,    70,   142,   168,   141,    19,   430,    68,
     115,    59,    86,   148,    62,   153,    70,   152,    30,    59,
     123,   191,    62,   153,    36,   131,    68,   289,    68,   112,
     117,   112,    86,   117,   117,   302,   117,   122,   123,   124,
     125,   268,   269,   173,   174,   175,   176,    59,    64,   310,
     277,    63,    59,    65,   254,   138,    63,    65,   145,   142,
      72,   145,   145,   233,   145,    72,    31,    32,   153,   172,
     137,    66,    85,    64,   141,    70,   345,   346,   347,    70,
     280,   148,    19,   189,     0,   152,   292,   172,   173,   295,
      73,    74,   298,    30,   177,    64,   177,    59,   181,    36,
     181,    63,   240,   241,   267,    63,    64,    65,   271,    63,
      72,    65,   242,   243,   244,   245,   265,   200,    72,   200,
       0,    64,    59,   272,   273,   274,    63,   276,   328,    63,
      46,    65,   270,   268,   269,    72,   266,    63,    64,    65,
     270,   311,   277,   343,    24,    25,    63,   244,    65,    29,
      30,    31,    32,    85,   260,   240,   241,   242,   243,   124,
     125,    86,   112,   476,   364,   434,    46,   117,    59,    63,
      72,    62,    19,   400,    59,    77,    78,    62,    63,   112,
      64,   266,    62,    30,    63,   270,    70,    72,    86,    36,
      70,    71,    84,   323,   371,   145,   366,   300,   368,    84,
      59,   268,   269,    62,    65,   382,    67,    63,   173,    68,
     277,   127,   389,   298,   476,   300,    63,    84,    65,   302,
      64,   302,   371,   484,    63,    72,    70,   177,    40,    41,
     313,   181,   313,   382,   372,   318,   371,   318,   500,   240,
     241,   242,   243,   159,   177,    44,    45,   163,   181,   419,
     200,   167,    84,   430,    60,   171,    59,   137,   407,    62,
      63,   141,    65,   524,    64,   400,   112,   200,   148,    72,
      70,    81,   152,   153,    64,    69,    70,   242,   243,   479,
      70,   430,   200,    71,   371,    64,    82,   371,   371,   372,
     371,    70,    19,    46,   494,   382,    69,    70,   382,   382,
     383,   382,   389,    30,   371,   389,   389,    70,   389,    36,
      31,    32,   482,    34,    35,   382,   232,   487,   488,    69,
      70,   322,   323,   523,    65,    86,    67,    84,    69,   467,
      64,   177,    59,   400,    70,   181,    63,   467,    66,   469,
      66,    29,    30,   430,    64,    72,   430,   430,   431,   430,
     348,   349,   302,   502,   200,    65,   526,    67,   323,    69,
     490,   350,   351,   313,   534,    84,   184,    84,   318,   302,
      86,   477,   190,    63,    64,    65,   194,   195,    86,    67,
     313,    34,   467,    71,   469,   318,   304,    64,   268,   269,
      63,    64,    65,    67,   212,   313,    37,   277,   316,   317,
     318,    59,    59,   124,   125,    63,   352,   353,   354,   355,
      66,   329,    31,    32,    72,    34,    35,    36,    37,    38,
      39,   371,    66,    86,    59,    64,    84,    62,    63,    63,
       0,    64,   382,    64,   122,   123,    64,    72,    59,   389,
      64,    62,    63,   261,    59,   363,    68,    62,    63,   356,
     357,    72,   173,   174,   142,    25,   302,    72,    66,    29,
      30,    31,    32,    86,     8,   153,   467,   313,   469,    86,
      59,   289,   318,    62,    63,     0,    46,    49,    64,     0,
     430,    53,   358,    72,   172,   440,    37,    38,    39,   490,
     359,   371,    62,   361,    63,    64,    65,   360,   362,   181,
     298,    71,   382,   300,   295,   124,   125,    79,    80,   260,
      82,    83,    63,   131,    65,   389,    67,   491,    90,    91,
     400,   242,   243,   480,    46,    97,    98,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   232,     3,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,   127,    13,    14,    -1,    16,
      -1,    30,    19,    -1,    -1,    -1,    -1,    36,   486,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,
      -1,    -1,   270,   153,    -1,    -1,    -1,   159,    -1,    -1,
      59,   163,    -1,    62,    63,   167,    65,    -1,    -1,   171,
      -1,    -1,   323,    72,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,    -1,    13,    14,   434,    16,    -1,    -1,
      19,    -1,    -1,   242,   243,   244,   245,    -1,    -1,    86,
      -1,    30,    -1,    19,    33,    -1,    35,    36,     4,     5,
       6,    -1,    -1,     9,    30,    -1,    12,    -1,    -1,    15,
      36,    19,    18,    19,    20,    21,    22,    -1,   476,    25,
      26,    -1,    30,    -1,    30,    -1,    -1,    -1,    36,    -1,
      36,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,   500,    -1,    -1,    -1,    72,    86,    -1,    -1,
      -1,    59,    -1,    59,    62,    63,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    84,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,     3,     4,     5,
       6,     7,    85,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    13,    14,
      -1,    16,    68,    69,    19,    71,    72,    73,    74,    75,
      76,     4,     5,     6,    -1,    30,     9,    -1,    33,    12,
      35,    36,    15,    -1,    -1,    18,    19,    20,    21,    22,
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
      -1,    34,    -1,    -1,    59,    38,    39,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,     4,     5,    25,    26,    -1,     9,
      -1,    30,    -1,    -1,    33,    15,    35,    36,    -1,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      59,    -1,    -1,    62,    63,    64,    65,    -1,     3,     4,
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
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    63,
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
	    yyval.tspec.tflags = yyvsp[-1].uval;
	    yyval.tspec.ptr    = NULL;
	    MAKE_TYPEDEF( yyval.tspec, yyvsp[0].pDecl );
	  ;
    break;}
case 91:
#line 756 "ctlib/parser.y"
{
	    yyval.tspec.tflags = 0;
	    yyval.tspec.ptr    = NULL;
	    decl_delete( EX_DECL( yyvsp[0].pDecl ) );
	  ;
    break;}
case 93:
#line 763 "ctlib/parser.y"
{
	    yyval.tspec = yyvsp[-2].tspec;
	    MAKE_TYPEDEF( yyval.tspec, yyvsp[0].pDecl );
	  ;
    break;}
case 95:
#line 772 "ctlib/parser.y"
{
	    yyval.tspec = yyvsp[-1].tspec;
	    MAKE_TYPEDEF( yyval.tspec, yyvsp[0].pDecl );
	  ;
    break;}
case 97:
#line 778 "ctlib/parser.y"
{
	    yyval.tspec.tflags = 0;
	    yyval.tspec.ptr    = NULL;
	    decl_delete( EX_DECL( yyvsp[0].pDecl ) );
	  ;
    break;}
case 99:
#line 785 "ctlib/parser.y"
{
	    yyval.tspec = yyvsp[-2].tspec;
	    MAKE_TYPEDEF( yyval.tspec, yyvsp[0].pDecl );
	  ;
    break;}
case 101:
#line 795 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;
    break;}
case 102:
#line 799 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 103:
#line 800 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 104:
#line 806 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = NULL;
	    yyval.tspec.tflags = yyvsp[0].uval;
	  ;
    break;}
case 105:
#line 810 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 106:
#line 811 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 107:
#line 817 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval;      ;
    break;}
case 108:
#line 818 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval;      ;
    break;}
case 109:
#line 819 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 112:
#line 828 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval; ;
    break;}
case 113:
#line 829 "ctlib/parser.y"
{ yyval.uval = 0;  ;
    break;}
case 117:
#line 839 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 118:
#line 840 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 119:
#line 841 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 120:
#line 842 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 121:
#line 846 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval;      ;
    break;}
case 122:
#line 847 "ctlib/parser.y"
{ yyval.uval = yyvsp[0].uval;      ;
    break;}
case 123:
#line 848 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval;      ;
    break;}
case 124:
#line 849 "ctlib/parser.y"
{ yyval.uval = yyvsp[-1].uval | yyvsp[0].uval; ;
    break;}
case 125:
#line 854 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;
    break;}
case 126:
#line 859 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;
    break;}
case 127:
#line 864 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;
    break;}
case 128:
#line 871 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 129:
#line 872 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 130:
#line 873 "ctlib/parser.y"
{ yyval.tspec = yyvsp[-1].tspec; ;
    break;}
case 131:
#line 879 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;
    break;}
case 132:
#line 884 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[0].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[0].tspec.tflags | yyvsp[-1].uval;
	  ;
    break;}
case 133:
#line 889 "ctlib/parser.y"
{
	    yyval.tspec.ptr    = yyvsp[-1].tspec.ptr;
	    yyval.tspec.tflags = yyvsp[-1].tspec.tflags | yyvsp[0].uval;
	  ;
    break;}
case 134:
#line 896 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 135:
#line 897 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 136:
#line 898 "ctlib/parser.y"
{ yyval.tspec = yyvsp[-1].tspec; ;
    break;}
case 137:
#line 902 "ctlib/parser.y"
{ yyval.uval = T_TYPEDEF;  ;
    break;}
case 138:
#line 903 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 139:
#line 904 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 140:
#line 905 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 141:
#line 906 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 142:
#line 907 "ctlib/parser.y"
{ yyval.uval = 0;          ;
    break;}
case 143:
#line 911 "ctlib/parser.y"
{ yyval.uval = T_INT;      ;
    break;}
case 144:
#line 912 "ctlib/parser.y"
{ yyval.uval = T_CHAR;     ;
    break;}
case 145:
#line 913 "ctlib/parser.y"
{ yyval.uval = T_SHORT;    ;
    break;}
case 146:
#line 914 "ctlib/parser.y"
{ yyval.uval = T_LONG;     ;
    break;}
case 147:
#line 915 "ctlib/parser.y"
{ yyval.uval = T_FLOAT;    ;
    break;}
case 148:
#line 916 "ctlib/parser.y"
{ yyval.uval = T_DOUBLE;   ;
    break;}
case 149:
#line 917 "ctlib/parser.y"
{ yyval.uval = T_SIGNED;   ;
    break;}
case 150:
#line 918 "ctlib/parser.y"
{ yyval.uval = T_UNSIGNED; ;
    break;}
case 151:
#line 919 "ctlib/parser.y"
{ yyval.uval = T_VOID;     ;
    break;}
case 152:
#line 923 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 153:
#line 924 "ctlib/parser.y"
{ yyval.tspec = yyvsp[0].tspec; ;
    break;}
case 154:
#line 929 "ctlib/parser.y"
{
	    yyval.tspec.tflags = yyvsp[-3].uval;
	    yyval.tspec.ptr = struct_new( NULL, 0, yyvsp[-3].uval, PSTATE->pragma.pack.current, EX_STRDECL_LIST( yyvsp[-1].list ) );
	    LL_push( PSTATE->pCPI->structs, yyval.tspec.ptr );
	  ;
    break;}
case 155:
#line 935 "ctlib/parser.y"
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
case 156:
#line 960 "ctlib/parser.y"
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
case 157:
#line 979 "ctlib/parser.y"
{ yyval.uval = T_STRUCT; ;
    break;}
case 158:
#line 980 "ctlib/parser.y"
{ yyval.uval = T_UNION;  ;
    break;}
case 159:
#line 985 "ctlib/parser.y"
{
	    yyval.list = LL_new();
	    LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	    LL_unshift( PSTATE->structDeclListsList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting struct declaration list (0x%08X) (size=%d)",
	                       yyval.list, LL_size(PSTATE->structDeclListsList)) );
	  ;
    break;}
case 160:
#line 993 "ctlib/parser.y"
{
	    yyval.list = yyvsp[-1].list;
	    LL_push( yyval.list, EX_STRUCT_DECL( yyvsp[0].pStructDecl ) );
	  ;
    break;}
case 161:
#line 1000 "ctlib/parser.y"
{ yyval.pStructDecl = yyvsp[-1].pStructDecl; ;
    break;}
case 162:
#line 1001 "ctlib/parser.y"
{ yyval.pStructDecl = yyvsp[-1].pStructDecl; ;
    break;}
case 163:
#line 1006 "ctlib/parser.y"
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
case 164:
#line 1016 "ctlib/parser.y"
{
	    yyval.pStructDecl = yyvsp[-2].pStructDecl;
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	  ;
    break;}
case 165:
#line 1025 "ctlib/parser.y"
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
case 166:
#line 1036 "ctlib/parser.y"
{
	    yyval.pStructDecl = yyvsp[-2].pStructDecl;
	    if( yyvsp[0].pDecl )
	      LL_push( yyval.pStructDecl->declarators, EX_DECL( yyvsp[0].pDecl ) );
	  ;
    break;}
case 167:
#line 1045 "ctlib/parser.y"
{
	    yyval.pDecl = yyvsp[-1].pDecl;
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  ;
    break;}
case 168:
#line 1050 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( "", 0 );
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  ;
    break;}
case 169:
#line 1058 "ctlib/parser.y"
{
	    yyval.pDecl = yyvsp[-1].pDecl;
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  ;
    break;}
case 170:
#line 1063 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( "", 0 );
	    yyval.pDecl->bitfield_size = yyvsp[0].ival;
	  ;
    break;}
case 171:
#line 1070 "ctlib/parser.y"
{ yyval.ival = -1; ;
    break;}
case 172:
#line 1071 "ctlib/parser.y"
{ yyval.ival = yyvsp[0].ival; ;
    break;}
case 173:
#line 1075 "ctlib/parser.y"
{ yyval.ival = yyvsp[0].value.iv; ;
    break;}
case 174:
#line 1080 "ctlib/parser.y"
{
	    yyval.tspec.tflags = T_ENUM;
	    yyval.tspec.ptr    = enumspec_new( NULL, 0, yyvsp[-1].list );
	    LL_push( PSTATE->pCPI->enums, yyval.tspec.ptr );
	    PSTATE->curEnumList = NULL;
	  ;
    break;}
case 175:
#line 1087 "ctlib/parser.y"
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
case 176:
#line 1111 "ctlib/parser.y"
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
case 177:
#line 1131 "ctlib/parser.y"
{
	    yyval.list = PSTATE->curEnumList = LL_new();
	    if( yyvsp[0].pEnum->value.flags & V_IS_UNDEF ) {
	      yyvsp[0].pEnum->value.flags &= ~V_IS_UNDEF;
	      yyvsp[0].pEnum->value.iv     = 0;
	    }
	    LL_push( yyval.list, yyvsp[0].pEnum );
	  ;
    break;}
case 178:
#line 1140 "ctlib/parser.y"
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
case 179:
#line 1151 "ctlib/parser.y"
{
	    yyval.list = yyvsp[-1].list;
	  ;
    break;}
case 180:
#line 1158 "ctlib/parser.y"
{
	    yyval.pEnum = enum_new( yyvsp[0].idOrType.str, yyvsp[0].idOrType.len, NULL );
	    STORE_IN_HASH( htEnumerators, yyvsp[0].idOrType, yyval.pEnum );
	  ;
    break;}
case 181:
#line 1163 "ctlib/parser.y"
{
	    yyval.pEnum = enum_new( yyvsp[-2].idOrType.str, yyvsp[-2].idOrType.len, &yyvsp[0].value );
	    STORE_IN_HASH( htEnumerators, yyvsp[-2].idOrType, yyval.pEnum );
	  ;
    break;}
case 186:
#line 1180 "ctlib/parser.y"
{;
    break;}
case 187:
#line 1181 "ctlib/parser.y"
{;
    break;}
case 188:
#line 1182 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 189:
#line 1183 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 190:
#line 1184 "ctlib/parser.y"
{;
    break;}
case 191:
#line 1185 "ctlib/parser.y"
{;
    break;}
case 192:
#line 1186 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 193:
#line 1187 "ctlib/parser.y"
{;
    break;}
case 194:
#line 1188 "ctlib/parser.y"
{;
    break;}
case 195:
#line 1189 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 196:
#line 1190 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 197:
#line 1191 "ctlib/parser.y"
{;
    break;}
case 198:
#line 1192 "ctlib/parser.y"
{;
    break;}
case 199:
#line 1193 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[0].pDecl ) ); ;
    break;}
case 200:
#line 1201 "ctlib/parser.y"
{ HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;
    break;}
case 201:
#line 1202 "ctlib/parser.y"
{ HN_delete( EX_NODE( yyvsp[0].identifier ) ); ;
    break;}
case 202:
#line 1207 "ctlib/parser.y"
{
	    yyval.idOrType.str    = yyvsp[0].identifier->key;
	    yyval.idOrType.len    = yyvsp[0].identifier->keylen;
	    yyval.idOrType.hash   = yyvsp[0].identifier->hash;
	    yyval.idOrType.node   = yyvsp[0].identifier;
	  ;
    break;}
case 203:
#line 1214 "ctlib/parser.y"
{
	    yyval.idOrType.str    = ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier;
	    HASH_STR_LEN( yyval.idOrType.hash, yyval.idOrType.str, yyval.idOrType.len );
	    yyval.idOrType.node   = NULL;
	  ;
    break;}
case 204:
#line 1223 "ctlib/parser.y"
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
case 205:
#line 1235 "ctlib/parser.y"
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
case 206:
#line 1252 "ctlib/parser.y"
{
	    yyval.value.iv = PSTATE->pCPC->int_size;
	    yyval.value.flags = 0;
	  ;
    break;}
case 207:
#line 1257 "ctlib/parser.y"
{
	    yyval.value.iv = yyvsp[0].absDecl.multiplicator * ( yyvsp[0].absDecl.pointer_flag ?
                    PSTATE->pCPC->int_size : PSTATE->pCPC->ptr_size );
	    yyval.value.flags = 0;
	  ;
    break;}
case 212:
#line 1272 "ctlib/parser.y"
{;
    break;}
case 220:
#line 1292 "ctlib/parser.y"
{ DELETE_NODE( yyvsp[0].idOrType ); ;
    break;}
case 227:
#line 1306 "ctlib/parser.y"
{ DELETE_NODE( yyvsp[-2].idOrType ); ;
    break;}
case 245:
#line 1345 "ctlib/parser.y"
{ DELETE_NODE( yyvsp[-1].idOrType ); ;
    break;}
case 255:
#line 1371 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 256:
#line 1373 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 257:
#line 1375 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 258:
#line 1377 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 259:
#line 1379 "ctlib/parser.y"
{ decl_delete( EX_DECL( yyvsp[-1].pDecl ) ); ;
    break;}
case 260:
#line 1381 "ctlib/parser.y"
{;
    break;}
case 261:
#line 1382 "ctlib/parser.y"
{;
    break;}
case 262:
#line 1383 "ctlib/parser.y"
{;
    break;}
case 263:
#line 1384 "ctlib/parser.y"
{;
    break;}
case 264:
#line 1385 "ctlib/parser.y"
{;
    break;}
case 265:
#line 1387 "ctlib/parser.y"
{;
    break;}
case 266:
#line 1388 "ctlib/parser.y"
{;
    break;}
case 267:
#line 1389 "ctlib/parser.y"
{;
    break;}
case 268:
#line 1390 "ctlib/parser.y"
{;
    break;}
case 269:
#line 1391 "ctlib/parser.y"
{;
    break;}
case 270:
#line 1395 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 271:
#line 1396 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 272:
#line 1400 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 273:
#line 1401 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 274:
#line 1406 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (size=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_size(PSTATE->declaratorList)) );
	  ;
    break;}
case 275:
#line 1413 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[-1].tspec.ptr)->pDecl->identifier, 0 );
	    if( yyvsp[0].list )
	      LL_delete( LL_splice( yyval.pDecl->array, 0, 0, EX_ARRAY( yyvsp[0].list ) ) );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (size=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_size(PSTATE->declaratorList)) );
	  ;
    break;}
case 276:
#line 1421 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 277:
#line 1428 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 278:
#line 1430 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 279:
#line 1435 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 280:
#line 1442 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 281:
#line 1444 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;
    break;}
case 282:
#line 1454 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 283:
#line 1456 "ctlib/parser.y"
{
	    yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;
    break;}
case 284:
#line 1461 "ctlib/parser.y"
{
	    yyvsp[-1].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;
    break;}
case 285:
#line 1466 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 286:
#line 1471 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 287:
#line 1478 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 288:
#line 1480 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[-1].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;
    break;}
case 289:
#line 1485 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;
    break;}
case 290:
#line 1493 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( ((Typedef *) yyvsp[0].tspec.ptr)->pDecl->identifier, 0 );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (size=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_size(PSTATE->declaratorList)) );
	  ;
    break;}
case 291:
#line 1499 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 292:
#line 1503 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 293:
#line 1504 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 294:
#line 1508 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[0].pDecl; ;
    break;}
case 295:
#line 1510 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 296:
#line 1515 "ctlib/parser.y"
{
	    yyvsp[0].pDecl->pointer_flag = 1;
	    yyval.pDecl = yyvsp[0].pDecl;
	  ;
    break;}
case 297:
#line 1523 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-1].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-1].pDecl;
	  ;
    break;}
case 298:
#line 1527 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 299:
#line 1529 "ctlib/parser.y"
{
	    POSTFIX_DECL( yyvsp[-2].pDecl, yyvsp[0].list );
	    yyval.pDecl = yyvsp[-2].pDecl;
	  ;
    break;}
case 300:
#line 1537 "ctlib/parser.y"
{
	    yyval.pDecl = decl_new( yyvsp[0].identifier->key, yyvsp[0].identifier->keylen );
	    HN_delete( EX_NODE( yyvsp[0].identifier ) );
	    LL_unshift( PSTATE->declaratorList, yyval.pDecl );
	    CT_DEBUG( PARSER, ("unshifting declarator \"%s\" (0x%08X) (size=%d)",
	                       yyval.pDecl->identifier, yyval.pDecl, LL_size(PSTATE->declaratorList)) );
	  ;
    break;}
case 301:
#line 1544 "ctlib/parser.y"
{ yyval.pDecl = yyvsp[-1].pDecl; ;
    break;}
case 302:
#line 1548 "ctlib/parser.y"
{;
    break;}
case 303:
#line 1549 "ctlib/parser.y"
{;
    break;}
case 304:
#line 1550 "ctlib/parser.y"
{;
    break;}
case 305:
#line 1555 "ctlib/parser.y"
{
	    decl_delete( EX_DECL( yyvsp[-3].pDecl ) );
	  ;
    break;}
case 306:
#line 1558 "ctlib/parser.y"
{;
    break;}
case 307:
#line 1560 "ctlib/parser.y"
{
	    LL_destroy( EX_ARRAY( yyvsp[0].list ), (LLDestroyFunc) value_delete );
	  ;
    break;}
case 308:
#line 1566 "ctlib/parser.y"
{ yyval.absDecl = yyvsp[0].absDecl; ;
    break;}
case 309:
#line 1567 "ctlib/parser.y"
{ yyval.absDecl = yyvsp[0].absDecl; ;
    break;}
case 310:
#line 1569 "ctlib/parser.y"
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
case 311:
#line 1582 "ctlib/parser.y"
{ yyval.list = yyvsp[0].list;   ;
    break;}
case 312:
#line 1583 "ctlib/parser.y"
{ yyval.list = NULL; ;
    break;}
case 313:
#line 1584 "ctlib/parser.y"
{ yyval.list = NULL; ;
    break;}
case 314:
#line 1588 "ctlib/parser.y"
{ yyval.list = NULL; ;
    break;}
case 315:
#line 1590 "ctlib/parser.y"
{
	    yyval.list = LL_new();
	    LL_unshift( PSTATE->arrayList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting array (0x%08X) (size=%d)",
	                       yyval.list, LL_size(PSTATE->arrayList)) );
	    LL_push( yyval.list, value_new( yyvsp[-1].value.iv, yyvsp[-1].value.flags ) );
	    CT_DEBUG( PARSER, ("array dimension => %d", yyvsp[-1].value) );
	  ;
    break;}
case 316:
#line 1599 "ctlib/parser.y"
{
	    yyval.list = LL_new();
	    LL_unshift( PSTATE->arrayList, yyval.list );
	    CT_DEBUG( PARSER, ("unshifting array (0x%08X) (size=%d)",
	                       yyval.list, LL_size(PSTATE->arrayList)) );
	    LL_push( yyval.list, value_new( 0, 0 ) );
	    CT_DEBUG( PARSER, ("array dimension => *") );
	  ;
    break;}
case 317:
#line 1608 "ctlib/parser.y"
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
case 318:
#line 1622 "ctlib/parser.y"
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
case 319:
#line 1639 "ctlib/parser.y"
{
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;
    break;}
case 320:
#line 1644 "ctlib/parser.y"
{
	    yyval.absDecl.pointer_flag = 1;
	    yyval.absDecl.multiplicator = 1;
	  ;
    break;}
case 321:
#line 1649 "ctlib/parser.y"
{
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;
    break;}
case 322:
#line 1654 "ctlib/parser.y"
{
	    yyvsp[0].absDecl.pointer_flag = 1;
	    yyval.absDecl = yyvsp[0].absDecl;
	  ;
    break;}
case 323:
#line 1661 "ctlib/parser.y"
{ yyval.absDecl = yyvsp[-1].absDecl; ;
    break;}
case 324:
#line 1662 "ctlib/parser.y"
{ yyval.absDecl = yyvsp[-1].absDecl; ;
    break;}
case 325:
#line 1664 "ctlib/parser.y"
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
case 326:
#line 1675 "ctlib/parser.y"
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
#line 1681 "ctlib/parser.y"



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
