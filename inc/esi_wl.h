/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WL.H*/
/* *7    18-OCT-1991 16:28:21 JTM "(SPR 0)  Fixes by Charlie for WELL DEPTH and ISOPACH - SOURCE option was ignored. Case 4568."*/
/* *6     9-JUL-1991 19:23:31 CHARLIE "(SPR 3109) add support for suppress surface symbol"*/
/* *5    23-MAY-1991 10:33:51 MING "(SPR -1) change prototype for wl_get_md"*/
/* *4    29-SEP-1990 10:18:25 GILLESPIE "(SPR 1) Merge beta deltas"*/
/*  2B1  28-SEP-1990 18:00:33 GILLESPIE "Beta Deltas"*/
/* *3    14-AUG-1990 11:52:09 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    17-JAN-1990 17:17:36 GILLESPIE "(SPR 6001) Changes to separate data from display attributes"*/
/* *1    30-JUN-1989 15:05:54 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WL.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Finder Graphics Systems, Inc. 1990                      */
/*         Unpublished -- All rights reserved                                       */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND   */
/*MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE  */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*          Exploration Systems, Inc.                                               */
/*          c/o Finder Graphics Systems, Inc.                                       */
/*          201 Tamal Vista Blvd                                                    */
/*          Corte Madera, CA  USA 94925                                             */
/*          (415) 927-0100                                                          */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_WL_H
#define ESI_WL_H 1

/* * FILE DESCRIPTION *                                                             */
/* --------------------                                                             */
/* ************************************************************************         */
/*                                                                                  */
/*   NAME: ESI_WL.H                                                                 */
/*                                                                                  */
/*   AUTHOR: JOHN CONROY                                                            */
/*                                                                                  */
/*   DESCRIPTION: Include file containing function definitions for 'WELLS'          */
/*        overlay.                                                                  */
/*                                                                                  */
/*   ************************************************************************       */

/* * INCLUDE FILES *                                                                */
/* -----------------                                                                */

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_SL_H
#include "esi_sl.h"
#endif

#ifndef ESI_WE_WELLS_H
#include "esi_we_wells.h"
#endif

/* (CP) this should be defined in finder_messages maybe?                            */
#define WL_DO_TCP 1

/* * DATA STRUCTURES *                                                              */
/* -------------------                                                              */
typedef struct 
    {
    WELL_STRUCT *pWell;
    struct 
        {
        INT code;                   /* well_hdr column PLOT_SYMBOL char(12), domain code 67 */
        COLOR_INDEX color;          /* GKS symbol color                             */
        INT pick_id;                /* GKS pick ID                                  */
        DOUBLE scale_factor;        /* centered symbol scale factor in NWC          */
        } symbol;
    } WL_WELL_STRUCT;


typedef SELECT_KEY_STRING WELL_NAMES;

typedef struct pickable_wells
    {
    INT nallocated;
    INT nused;
    INT seg_id;
    WL_WELL_STRUCT *list;
    } PICKABLE_WELLS;

typedef struct 
    {
    INT ov_type;
    INT zfield;
    CHAR *xyz_file;
    CHAR *add_to_xyz_file;
    CHAR *above;
    CHAR *below;
    CHAR *left;
    CHAR *right;
    CHAR *centered;
    NLIST_HEADER scatter;
    CHAR *bottom_horizon;
    CHAR *top_horizon;
    CHAR *source;
    INT label_position;
    CHAR *select_by_phrase;
    CHAR *select_list;
    CHAR *name;
    BOOL suppress_symbols;
    BOOL suppress_surface_symbols;
    BOOL suppress_text;
    COLOR_INDEX symbol_color;
    FLOAT symbol_size;
    INT symbol_type;
    COLOR_INDEX text_color;
    GKS_REAL text_size;
    BOOL full_trace;
    } WELLS;

/* * FUNCTIONS *                                                                    */
/* -------------                                                                    */

#if USE_PROTOTYPES
extern INT wl_do_deviated_wells (WELLS *wells, NLIST_HEADER dev_nlist,
                                 BOOL suppress_text, NLIST_HEADER label_nlist,
                                 PICKABLE_WELLS *picks);
extern INT wl_do_nodev_wells (WELLS *wells, NLIST_HEADER dev_nlist, BOOL suppress_text,
                              NLIST_HEADER label_nlist, PICKABLE_WELLS *picks);
extern INT wl_draw_deviation (void);
extern INT wl_get_label (UWI uwi, CHAR *sent_sql, INT mode, CHAR *label);
extern INT wl_get_label_tcp (UWI uwi, TCP sql_tcp, INT mode, TCP *label_tcp);
extern INT wl_get_md (UWI uwi, CHAR *form, CHAR *source, DOUBLE *md, 
				DOUBLE *elevation, BOOL re_init);
extern INT wl_get_wells (WELLS *wells, NLIST_HEADER nodev_nlist,
                         NLIST_HEADER *dev_nlist, NLIST_HEADER well_nlist,
                         INT *num_wells);
extern INT wl_label_sql (WELLS *wells);
extern INT wl_overlay (INT display_line);
extern INT wl_parse_label (CHAR *label, CHAR **sqlstmt);
extern INT wl_parse_label_tcp (CHAR *sent_sql, CHAR *source, TCP *sql_tcp);
extern INT wl_parse_where (CHAR *where_cls, CHAR special_key[3][13], INT num_in,
                           INT *num_found);
extern INT wl_post_tcp (COORD x, COORD y, DOUBLE text_size, INT text_position,
                        TCP well_tcp);
extern INT wl_post_wells (WELLS *wells, NLIST_HEADER nodev_nlist,
                          NLIST_HEADER dev_nlist, PICKABLE_WELLS *picks);
extern INT wl_text_placement (DOUBLE size, COORD x1, COORD y1, COORD x2, COORD y2,
                              COORD x3, COORD y3, DOUBLE *x_offset, DOUBLE *y_offset,
                              DOUBLE *x_up, DOUBLE *y_up);

extern INT wlz_add_pick (PICKABLE_WELLS *picks, UWI uwi);


#else       /* no prototypes */
extern INT wl_do_deviated_wells ();
extern INT wl_do_nodev_wells ();
extern INT wl_draw_deviation ();
extern INT wl_get_label ();
extern INT wl_get_label_tcp ();
extern INT wl_get_md ();
extern INT wl_get_wells ();
extern INT wl_label_sql ();
extern INT wl_overlay ();
extern INT wl_parse_label ();
extern INT wl_parse_label_tcp ();
extern INT wl_parse_where ();
extern INT wl_post_tcp ();
extern INT wl_post_wells ();
extern INT wl_text_placement ();
extern INT wlz_add_pick ();

#endif      /* of USE_PROTOTYPES */
#endif
