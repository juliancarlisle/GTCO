/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CS.H*/
/* *3    14-AUG-1990 11:46:41 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2     8-MAR-1990 17:42:52 GILLESPIE "(SPR 1) Change POLYMARKER_GROUP to POLYMKR_GRP - also need to change file in ESI$SYMBOLS"*/
/* *1    30-JUN-1989 14:59:55 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CS.H*/
/******************************************************************************

		Copyright Exploration Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF 

			Exploration Systems, Inc.
			579 Market Street
			San Francisco, CA  USA 94105
			(415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work) 


******************************************************************************/

#ifndef ESI_CS_H
#define ESI_CS_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_CS_ERR_H
#include "esi_cs_err.h"
#endif

/* polymarker group */
#define CS_POLYMARKER_GROUP   "POLYMKR_GRP"
#define CS_POLYMARKER_POINT   (INT)1
#define CS_POLYMARKER_PLUS    (INT)2
#define CS_POLYMARKER_ASTERIX (INT)3
#define CS_POLYMARKER_CIRCLE  (INT)4
#define CS_POLYMARKER_X       (INT)5

/* other groups */
#define CS_API_WELLS_GROUP   "API_WELLS"
#define CS_CGG_GROUP         "CGG"
#define CS_FILLED_GROUP      "FILLED"
#define CS_HIGHLIGHT_GROUP   "HIGHLIGHT"
#define CS_HOLLOW_GROUP      "HOLLOW"
#define CS_NOVA_GROUP        "NOVA"
#define CS_TEST_GROUP        "TEST"
#define CS_V3_WELLS_GROUP    "V3_WELLS"
#define CS_V4_WELLS_GROUP    "V4_WELLS"
#define CS_WELL_GROUP        "WELL"

/*  the filled symbols  */
#define CS_TRIANGLE  (INT)1
#define CS_DIAMOND   (INT)2
#define CS_PENTAGON  (INT)3
#define CS_HEXAGON   (INT)4
#define CS_SEPTAGON  (INT)5

/* standard symbol radius */
#define CS_NWC_RADIUS  0.0075

/* symbol definition primitives */
#define CS_POLYLINE    (INT)1
#define CS_FILLED_AREA (INT)2

/* symbol definition limits */
#define CS_MAX_PRIMITIVES 100
#define CS_MAX_POINTS     100

/* default attributes */
#define CS_DEFAULT_GROUP  CS_POLYMARKER_GROUP
#define CS_DEFAULT_SYMBOL CS_POLYMARKER_ASTERIX
#define CS_DEFAULT_SCALE  1.0
#define CS_DEFAULT_COLOR  (COLOR_INDEX)1

#if USE_PROTOTYPES

/* system routines */
extern INT cs_init(void) ;
extern INT cs_term(void) ;

/* group routines */
extern INT cs_set_group(ENTRYNAME) ;
extern INT cs_query_group(ENTRYNAME) ;
extern INT cs_query_group_size(ENTRYNAME, INT *) ;
extern INT cs_display_group(ENTRYNAME, DOUBLE, DOUBLE, DOUBLE, DOUBLE) ;

/* symbol attribute routines */
extern INT cs_set_code(INT) ;
extern INT cs_query_code(INT *) ;
extern INT cs_set_color(COLOR_INDEX) ;
extern INT cs_query_color(COLOR_INDEX *) ;
extern INT cs_set_scale_factor(DOUBLE) ;
extern INT cs_query_scale_factor(DOUBLE *) ;
extern INT cs_set_height(DOUBLE) ;
extern INT cs_query_height(DOUBLE *) ;

/* drawing routines */
extern INT cs_draw_one(DOUBLE, DOUBLE) ;
extern INT cs_draw_many(INT, DOUBLE[], DOUBLE[]) ;
extern INT cs_draw_symbol(ENTRYNAME, INT, DOUBLE, COLOR_INDEX, DOUBLE, DOUBLE) ;

/* low level routines */
extern INT csz_Init(void) ;
extern INT csz_Term(void) ;
extern INT csz_AddGroup(ENTRYNAME) ;
extern INT csz_DeleteGroup(ENTRYNAME) ;
extern INT csz_QueryGroup(ENTRYNAME, INT *) ;
extern INT csz_AddSymbol(ENTRYNAME, INT, INT, INT, INT[], INT[], 
			    DOUBLE[], DOUBLE[]) ;
extern INT csz_DeleteSymbol(ENTRYNAME, INT) ;
extern INT csz_QuerySymbol(ENTRYNAME, INT, INT *, INT *) ;
extern INT csz_DrawSymbols(ENTRYNAME, INT, DOUBLE, COLOR_INDEX, INT, 
			    DOUBLE[], DOUBLE[]) ;
extern INT csz_InitPolymarkerGroup(void) ;
extern INT csz_ScaleToRadii(DOUBLE, DOUBLE *, DOUBLE *) ;

#else 

/* system routines */
extern INT cs_init() ;
extern INT cs_term() ;

/* group routines */
extern INT cs_set_group() ;
extern INT cs_query_group() ;
extern INT cs_query_group_size() ;
extern INT cs_display_group() ;

/* symbol attribute routines */
extern INT cs_set_code() ;
extern INT cs_query_code() ;
extern INT cs_set_color() ;
extern INT cs_query_color() ;
extern INT cs_set_scale_factor() ;
extern INT cs_query_scale_factor() ;
extern INT cs_set_height() ;
extern INT cs_query_height() ;

/* drawing routines */
extern INT cs_draw_one() ;
extern INT cs_draw_many() ;
extern INT cs_draw_symbol() ;

/* low level routines */
extern INT csz_Init() ;
extern INT csz_Term() ;
extern INT csz_AddGroup() ;
extern INT csz_DeleteGroup() ;
extern INT csz_QueryGroup() ;
extern INT csz_AddSymbol() ;
extern INT csz_DeleteSymbol() ;
extern INT csz_QuerySymbol() ;
extern INT csz_DrawSymbols() ;
extern INT csz_InitPolymarkerGroup() ;
extern INT csz_ScaleToRadii() ;

#endif

#endif
