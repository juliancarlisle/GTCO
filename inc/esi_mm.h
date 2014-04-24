/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MM.H*/
/* *2    14-AUG-1990 11:49:31 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:03:07 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MM.H*/

#ifndef ESI_MM_H
#define ESI_MM_H 1

/*  Mapping Include File						      */

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

/* Line Structure				*/

typedef struct
{
    INT line_id;
    NLIST_HEADER line_nlist;
    LINE_ATTRIBUTE line;
    CHAR line_name[33];
    BOOL polygon_flag;
    FILL_AREA_INTERIOR_STYLE polygon_fill_style;
	FILL_AREA_STYLE_INDEX polygon_fill_index;
    COLOR_INDEX polygon_fill_color;
    }LINE;

/*  Text Structure				*/

typedef struct {
    INT text_id;
    struct{FLOAT x,y;} text_position;
    struct{FLOAT x,y;} text_offset;
    CHAR text_class[25];
    CHAR text_super_class[25];
    INDEX text_alignment[2];
    INDEX text_path;
    GKS_REAL text_up_x;
    GKS_REAL text_up_y;
    BOOL box_flag;
    FILL_AREA_INTERIOR_STYLE box_fill_code;
	LINE_ATTRIBUTE box;
    BOOL arrow_flag;
    FONT_INDEX text_font;
    COLOR_INDEX text_color;
    INDEX text_precision;
    GKS_REAL text_size;
    GKS_REAL text_expansion_factor;
    GKS_REAL text_line_spacing;
    GKS_REAL box_boundary[2][4];
    CHAR *text_string;
    }TEXT;

/*  Symbol Structure				*/

typedef struct
{
    INT symbol_id;
    struct{GKS_REAL x,y;} symbol_location;
    CHAR symbol_group[26];
    GKS_INT symbol_type;
    INDEX symbol_fill_code;
    COLOR_INDEX symbol_fill_color;
    COLOR_INDEX symbol_color;
    GKS_REAL symbol_size;
}SYMBOL;

/******************************************************************************/

#if USE_PROTOTYPES

extern INT mm_draw_line(LINE *pLine, BOOL clip_flag);
                         
extern INT mm_draw_line_dim(LINE *pLine, BOOL clip_flag, INT xdim, INT ydim);
extern INT mm_draw_polygon(LINE *pPolygon,BOOL clip_flag);
extern INT mm_draw_symbol(SYMBOL *pSymbol);
extern INT mm_draw_text(TEXT *pText, BOOL clip_flag);

#else

extern INT mm_draw_line();
extern INT mm_draw_line_dim();
extern INT mm_draw_polygon();
extern INT mm_draw_symbol();
extern INT mm_draw_text();

#endif

#endif
