/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LY.H */
/* *11   14-AUG-1990 11:49:17 GILLESPIE "(SPR 2001) Major realignment of include files" */
/* *10   19-JUL-1990 18:37:29 GILLESPIE "(SPR 1) Add nlm_window_clip_text (NOTE: This routine should be renamed to */
/*lym_window...)" */
/* *9    19-JUL-1990 09:22:32 GILLESPIE "(SPR 1) Change prototypes for ly_get_*_bundle" */
/* *8    17-JUL-1990 12:18:13 GILLESPIE "(SPR 1) add typedef for color, style and font" */
/* *7    12-JUL-1990 17:02:41 GILLESPIE "(SPR 3) Added SYMBOL_GC from esi_ly_gc.h" */
/* *6    12-JUL-1990 15:03:03 GILLESPIE "(SPR 3) Change publicdef to extern" */
/* *5    12-JUL-1990 13:43:42 GILLESPIE "(SPR 1) Change publicdef to extern" */
/* *4    24-APR-1990 14:59:08 VINCE "(SPR 1) added the lynx_class enum type" */
/* *3    23-MAR-1990 22:42:34 VINCE "(SPR 1) fixed include file" */
/* *2    23-MAR-1990 11:40:57 VINCE "(SPR 1) initial checkin" */
/* *1    21-MAR-1990 14:54:22 VINCE "lynx include file" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LY.H */
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1990
           Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND
MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

            Finder Graphics Systems, Inc.
            201 Tamal Vista Blvd
            Corte Madera, CA  USA 94925
            (415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#ifndef ESI_LY_H
#define ESI_LY_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

typedef INT ARC_ID;
typedef INT LYNX_ID;
typedef INT REGION_ID;
typedef INT SYMBOL_ID;
typedef INT TEXT_ID;

typedef struct 
    {
    TEXT_ID text_id;
    LYNX_ID lynx_id;
    NODE_ID node_id;
    CHAR text_string[81];
    TEXT_ID next_text_id;
    BUNDLE_ID text_gc_bundle_id;
    BOOL use_color_override;
    COLOR_INDEX color_override;
    INT offset_units;               /* 0 = plotter units, 1 = WCS units             */
    DOUBLE text_up_x;               /* vector defining character string angle       */
    DOUBLE text_up_y;
    DOUBLE x_offset;                /* offset from node in plotter units or WCS     */
    DOUBLE y_offset;                /* as per offset_units                          */
    } LY_TEXT_OBJECT;

/* This enum data type lists the internal lynx classes, the corresponding
 * external classes are SYMBOL, LINE, AREA, TEXT respectively.
 * (note: TEXT is the same in internal and external representation) */

typedef enum 
    {
    LYNX_NODE_CLASS, LYNX_ARC_CLASS, LYNX_REGION_CLASS, LYNX_TEXT_CLASS,
        LYNX_ALL_CLASSES
    } LYNX_CLASS;


#if USE_PROTOTYPES

extern INT ly_create_data_type(CHAR *data_type, CHAR *desc);
extern INT ly_generate_township_labels(NLIST_HEADER label_nl);
extern INT ly_get_area_bundle(CHAR *data_type, REGION_ID region_id, BUNDLE_ID bundle_id_in,
                                AREA_GC *area_gc);
extern INT ly_get_line_bundle(CHAR *data_type, ARC_ID arc_id, BUNDLE_ID bundle_id_in,
                             LINE_GC *line_gc);
extern INT ly_get_nlist(INT region_id, NLIST_HEADER *nlist);
extern INT ly_get_symbol_bundle(CHAR *data_type, SYMBOL_ID symbol_id, BUNDLE_ID bundle_id_in,
                                SYMBOL_GC *symbol_gc);
extern INT ly_get_text_bundle(CHAR *data_type, TEXT_ID text_id, BUNDLE_ID bundle_id_in,
                              TEXT_GC *text_gc);
extern INT ly_init_line_nlist(NLIST_HEADER *nlist);
extern INT ly_init_text_nlist(NLIST_HEADER *nlist);
extern INT ly_process_node(DOUBLE x, DOUBLE y, DOUBLE tolerance, NODE_ID *node_id);
extern INT ly_put_area_bundle(CHAR *data_type, REGION_ID region_id, AREA_GC *area_gc);
extern INT ly_put_line_bundle(CHAR *data_type, ARC_ID arc_id, LINE_GC *line_gc);
extern INT ly_put_symbol_bundle(CHAR *data_type, SYMBOL_ID symbol_id,
                                SYMBOL_GC *symbol_gc);
extern INT ly_put_text(LY_TEXT_OBJECT *text_object);
extern INT ly_put_text_bundle(CHAR *data_type, TEXT_ID text_id, TEXT_GC *text_gc);
extern INT ly_set_dtype_bundle(CHAR *data_type, LYNX_CLASS lynx_class, BUNDLE_ID bundle_id,
                               CHAR *color_override);
extern INT nlm_window_clip_text(NLIST_HEADER nlist, VOIDPTR param);
#else

extern INT ly_create_data_type();
extern INT ly_generate_township_labels();
extern INT ly_get_area_bundle();
extern INT ly_get_line_bundle();
extern INT ly_get_nlist();
extern INT ly_get_symbol_bundle();
extern INT ly_get_text_bundle();
extern INT ly_init_line_nlist();
extern INT ly_init_text_nlist();
extern INT ly_process_node();
extern INT ly_put_area_bundle();
extern INT ly_put_line_bundle();
extern INT ly_put_symbol_bundle();
extern INT ly_put_text();
extern INT ly_put_text_bundle();
extern INT ly_set_dtype_bundle();
extern INT nlm_window_clip_text();

#endif
#endif
