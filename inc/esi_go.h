/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GO.H*/
/* *7    13-OCT-1990 00:22:09 GILLESPIE "(SPR 100) Updates from Ernie"*/
/*  5B1  13-OCT-1990 00:21:34 GILLESPIE "Updates from Ernie"*/
/* *6    14-AUG-1990 11:48:04 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *5    17-JUL-1990 15:14:07 GILLESPIE "(SPR 1) Changes for elect. drafting cleanup"*/
/* *4    28-FEB-1990 06:06:44 GILLESPIE "(SPR 1) Add additional prototypes"*/
/* *3     9-FEB-1990 12:16:44 WALTERS "(SPR 0) Fix prototype"*/
/* *2     8-FEB-1990 12:08:53 WALTERS "(SPR 0) Add prototype for go_draw_object"*/
/* *1    30-JUN-1989 15:01:15 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GO.H*/
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

/*
 * ESI_GO.H
 *
 * Definitions for Mapping Graphics Overlay.
 */

#ifndef ESI_GO_H
#define ESI_GO_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_MP_H
#include "esi_mp.h"
#endif

typedef struct 
    {
    CHAR *add_to_xyz_file;
    CHAR *bottom;
    LINE_ATTRIBUTE line;
    CHAR *marker;
    DOUBLE maximum_data_interval;
    CHAR *name;
    CHAR *select_by_phrase;
    CHAR *select_list;
    BOOL suppress_editing;
    BOOL suppress_lines;
    BOOL suppress_text;
    COLOR_INDEX text_color;
    GKS_REAL text_expansion_factor;
    FONT_INDEX text_font;
    INDEX text_precision;
    GKS_REAL text_size;
    CHAR *top;
    CHAR *object_type;
    CHAR *xyz_file;
    CHAR *source;
    NLIST_HEADER scatter;
    } GO_STRUCT;

typedef struct 
    {
    INT line_nallocated;
    INT line_nused;
    INT *line_id;
    INT *line_segm;
    INT text_nallocated;
    INT text_nused;
    INT *text_id;
    INT *text_segm;
    } PICKABLE_OBJECT;

typedef struct 
    {
    INT nallocated;
    INT nused;
    INT *object_id;
    INT *group_id;
    PICKABLE_OBJECT *pick_obj;
    } PICKABLE_GRA_OBJ;

typedef struct 
    {
    INT elem_id;
    BOOL if_text;
    INT segment_id;
    INT obj_id;
    INT group_id;
    } GO_USER_STRUCT;

typedef struct 
    {
    BOOL changed;
    NLIST_HEADER temp_nlist;
    NLIST_HEADER master_nlist;
    } GO_WORKSPACE;


#if USE_PROTOTYPES
extern INT go_build_common_nlist(NLIST_HEADER *nlist);
extern INT go_copy_stroke(NLIST_HEADER from_nlist, UINT from_stroke,
                          NLIST_HEADER to_nlist, UINT *to_stroke);
extern INT go_draw_line(GO_STRUCT *values, INT element_id, CHAR *object_type,
                        BOOL clip_required, INT *segment_id);
extern INT go_draw_object(INT object_id_in, INT object_class, GO_STRUCT *values,
                          MAP_STRUCTURE *map, INT *WM_group_id,
                          PICKABLE_OBJECT *pick_obj);
extern INT go_draw_symbol(GO_STRUCT *values, INT element_id);
extern INT go_draw_text(GO_STRUCT *values, INT element_id, BOOL clip_required,
                        INT *segment_id);
extern INT go_post_grov(GO_STRUCT *values, PICKABLE_GRA_OBJ **pick_gra_obj);
#else
extern INT go_build_common_nlist();
extern INT go_copy_stroke();
extern INT go_draw_line();
extern INT go_draw_object();
extern INT go_draw_symbol();
extern INT go_draw_text();
extern INT go_post_grov();

#endif
#endif
