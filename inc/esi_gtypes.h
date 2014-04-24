/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GTYPES.H*/
/* *1    14-AUG-1990 11:54:13 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GTYPES.H*/
/* 
This new include file contains fundamental graphic data types to Finder
*/

#ifndef ESI_GTYPES_H
#define ESI_GTYPES_H 1

#ifndef ESI_DTYPES
#include "esi_dtypes.h"
#endif

typedef LONG GKS_INT;               /* Graphics system integer - moved from esi_gks.h   */
typedef float GKS_REAL;             /* Graphics system floating point moved from esi_gks.h  */
typedef GKS_INT INDEX;              /* Index number for a graphics attribute        */
typedef INDEX COLOR_INDEX;
typedef INDEX FONT_INDEX;
typedef INDEX LINE_STYLE_INDEX;
typedef INDEX FILL_AREA_INTERIOR_STYLE;
typedef INDEX FILL_AREA_STYLE_INDEX;
typedef INT BUNDLE_ID;

typedef struct {
    GKS_REAL x ;
    GKS_REAL y ;
    } POINT ;

typedef struct {
    POINT min ;			/* Lower left corner */
    POINT max ;			/* Upper right corner */
    } RECTANGLE ;

typedef struct {
    COLOR_INDEX color;
    LINE_STYLE_INDEX style;
    DOUBLE width;
    } LINE_ATTRIBUTE;

typedef struct 				/* SYMBOLS */
    {
    BUNDLE_ID symbol_bundle_id;
    COLOR_INDEX symbol_color;
    INT symbol_type;
    DOUBLE symbol_size;
    } SYMBOL_GC;

typedef struct 				/* LINES */
    {
    BUNDLE_ID line_bundle_id;
    LINE_ATTRIBUTE line;
    } LINE_GC;

typedef struct 				/* POLYGONS */
    {
    BUNDLE_ID area_bundle_id;
	LINE_ATTRIBUTE frame;
	enum {FILL_ONLY, FRAME_ONLY, FILL_FRAME} frame_flag;
    COLOR_INDEX fill_color;
    FILL_AREA_INTERIOR_STYLE fill_style;
	FILL_AREA_STYLE_INDEX style_index;
    } AREA_GC;

typedef struct 				/* TEXT */
    {
    BUNDLE_ID text_bundle_id;       /* bundle id of current CG param                */
    COLOR_INDEX text_color;         /* color index number                           */
    FONT_INDEX text_font;           /* GKS font index                               */
    INDEX text_precision;           /* GKS text precision code                      */
    INDEX text_path;                /* GKS text path code                           */
    INDEX string_h_just;            /* GKS horizontal alignment code                */
    INDEX string_v_just;            /* GKS vertical alignment code                  */
    DOUBLE string_spacing;          /* in char_height units                         */
    DOUBLE char_height;             /* in project default horizontal UOM            */
    DOUBLE char_spacing;            /* in char_width units                          */
    } TEXT_GC;

#endif
