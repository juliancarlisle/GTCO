/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TO.H */
/* *11    6-MAY-1991 13:30:18 PURNA "(SPR 0) add select list in culture" */
/* *10   14-AUG-1990 11:51:25 GILLESPIE "(SPR 2001) Major realignment of include files" */
/* *9    12-JUL-1990 15:23:57 GILLESPIE "(SPR 1) Remove reference to esi_ly_gc.h" */
/* *8     1-JUN-1990 15:42:03 PURNA "(SPR 0) remove session_id from to_draw_text parameter" */
/* *7    31-MAY-1990 15:53:01 PURNA "(SPR 0) add new function to_assemble_nlist" */
/* *6    26-MAY-1990 14:23:30 SCD "(SPR 1) Add text horiz & vertical alignment members to TO_STRUCT." */
/* *5    24-MAR-1990 18:15:52 SCD "(SPR 1) Added to_draw_composite_objects prototype." */
/* *4    22-MAR-1990 10:27:09 PURNA "(SPR 0) create .ah and .x file" */
/* *3    21-MAR-1990 16:23:32 PURNA "(SPR 0) more changes" */
/* *2    16-MAR-1990 09:00:34 PURNA "(SPR 5095) culture" */
/* *1    16-MAR-1990 08:55:55 PURNA "culture overlay" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TO.H */
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

/*
 * ESI_TO.H
 *
 * Definitions for Mapping Topologic Overlay.
 */

#ifndef ESI_TO_H
#define ESI_TO_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

typedef struct to_struct
    {
    CHAR *add_to_xyz_file;
    LINE_ATTRIBUTE line;
    CHAR *name;
    CHAR *select_by_phrase;
    CHAR *select_list;
    BOOL suppress_lines;
    BOOL suppress_text;
    COLOR_INDEX text_color;
    GKS_REAL text_height;
    FONT_INDEX text_font;
    GKS_REAL text_spacing;
    INDEX text_h_just;
    INDEX text_v_just;
    CHAR *object_type;
    CHAR *xyz_file;
    NLIST_HEADER scatter;
    } TO_STRUCT;


#if USE_PROTOTYPES

extern INT to_overlay(INT display_line);
extern INT to_post_grov(TO_STRUCT *values);
extern INT to_assemble_nlist(NLIST_HEADER *nlist, INT n_arcs, INT *final_node_array,
                             INT *init_node_array, INT *arc_array);
extern INT to_draw_object(INT suppress_lines, INT suppress_text, INT *n_lines);
extern INT to_draw_composite_objects(CHAR *data_type, TO_STRUCT *values);
extern INT to_draw_line(CHAR *data_type, NLIST_HEADER *nlist);
extern INT to_draw_text(CHAR *data_type_in, NLIST_HEADER *nlist);
extern INT to_draw_line_method(NLIST_HEADER nlist, VOIDPTR param);
extern INT to_draw_text_method(NLIST_HEADER nlist, VOIDPTR param);
extern BOOL to_fetch_nlist(INT nlist_index, INT n_culture, long culture_id,
                           BOOL prop_flag);

#else

extern INT to_overlay();
extern INT to_post_grov();
extern INT to_assemble_nlist();
extern INT to_draw_object();
extern INT to_draw_composite_objects();
extern INT to_draw_line();
extern INT to_draw_text();
extern INT to_draw_line_method();
extern INT to_draw_text_method();
extern BOOL to_fetch_nlist();

#endif
#endif
