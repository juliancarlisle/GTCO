/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XS_GR.H*/
/* *6    14-AUG-1990 11:52:52 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *5     9-JUL-1990 09:46:18 MING "(SPR -1) change prototype for producing CGM"*/
/* *4    19-SEP-1989 11:15:53 PURNA "(SPR 100) gulf mods"*/
/* *3    14-SEP-1989 16:42:21 GORDON "(SPR 100) Gulf/Sun/Unix changes"*/
/* *2    18-JUL-1989 14:19:39 GORDON "(SPR 100) Add mods from Sun port"*/
/* *1    30-JUN-1989 15:06:15 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XS_GR.H*/
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

#ifndef ESI_XS_GR_H
#define ESI_XS_GR_H 1

#ifdef NO_GRAPHICS
#define ESI_GKS_H 1
#define ESI_WM_H 1
#endif

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_XS_DEFS_H
#include "esi_xs_defs.h"
#endif

#ifndef ESI_GKS_H
#include "esi_gks.h"
#endif

#ifndef ESI_WM_H
#include "esi_wm.h"
#endif

/***************************************************************
*  Copyright 1987, Exploration Systems Inc.  San Francisco CA.

	Cross Section Graphics.......Main Include File.

	Defines the various datastructures associated with
	the Cross Section Graphics routines.

* Julian Carlisle
****************************************************************/

#define BORDER  .02
#define RCH  0.05               /* percent of border around text */
#define BARSIZE (INT)2
#define TICKSIZE (INT)1
#define YTICKSCALE 0.02
#define XTICKSCALE 0.07
#define LR  (INT)2
#define MAX_TRACKS  (INT)30
#define MAX_WELLS   (INT)100
#define MAX_TRACE_NAME_LEN   (INT)35

typedef struct xs_top_xy_data
    {
    INT     seg_id;    /*Window Manager segment id. */
    FLOAT   wcs_x;     /* World Coordinate system  X & Y */
    FLOAT   wcs_y;
    FLOAT   nwc_x;     /* Normalized Window Coordinate system X & Y */
    FLOAT   nwc_y;
    LAYOUT_STRUCT *pls; /* This well */
    INT     num_tracks;
    TRACK_STRUCT  **tpt; /* All the tracks in this well */
    SHORT   deleted;
    INT     layout_num;
    INT     track_num;
    INT     trace_num;
    DOUBLE  depth;
    INT     valid;       /* TRUE if there is a top for this layout */
    SHORT   modified;
    COLOR_INDEX color;
    CHAR    color_name[33];
    FLOAT   xmin;
    FLOAT   xmax;
    FLOAT   old_bar_y;   /* position of bar prior to update. For erasing. */
    FLOAT   new_bar_y;
    } TOP_XY_DATA;

typedef struct xs_color_struct
    {
    TCP        color_names;    /* tcp of color name strings */
    COLOR_INDEX color_codes[50];  /* corresponding values for tcp entries */
    INT total_colors;     /* total entries (colors) in tcp */
    } COLOR_STRUCT;

typedef struct xs_drawinfo
    {
    INT             most_traces_count;   /* most traces in any track */
    INT             max_track_wid;       /* Width of widest track */
    INT             max_lstr_len;        /* # chars in longest left/right */
    INT             max_rstr_len;        /* trace limit number */
    INT             max_tname_len;       /* Length of longest trace name */
    TRACK_STRUCT    *most_traces_ptrack; /* ptr of track w/most traces */
    TRACK_STRUCT    *max_tname_ptrack;   /* ptr of track w/longest tname */
    FLOAT           region_ht;           /* Height of each trace scale entry */
    FLOAT           cs;                  /* std char size for trace scale text*/
    } XS_DIS;


/* declare types of functions in this module */

#if USE_PROTOTYPES

extern INT lg_gr_plot_draw_hdr(XS_STRUCT *pxs, LAYOUT_STRUCT *pls);

extern INT lg_gr_plot_draw_scale(XS_STRUCT *pxs,
				 LAYOUT_STRUCT *pls,
				 XS_DIS *pd);

extern INT xs_gr_drawline(DOUBLE x1, DOUBLE y1, DOUBLE x2, DOUBLE y2);

extern INT xs_gr_draw_marks(XS_STRUCT *pxs,
			    LAYOUT_STRUCT *pls,
			    TRACK_STRUCT *pt);

extern INT xs_gr_draw_section(XS_STRUCT *pxs, CHAR *metafile);

extern INT xs_gr_draw_ticks(XS_STRUCT *pxs,
			    LAYOUT_STRUCT *pls,
			    FLOAT *pticks,
			    DOUBLE ymin,
			    DOUBLE ymax,
			    TRACK_STRUCT *pt);

extern INT xs_gr_draw_traces(XS_STRUCT *pxs, LAYOUT_STRUCT *pls);

extern INT xs_gr_draw_tracks(XS_STRUCT *pxs,
			     LAYOUT_STRUCT *pls,
			     INT plot_flag);

extern INT xs_gr_get_drawinfo(XS_STRUCT *pxs, XS_DIS *pd);

extern COLOR_STRUCT *xs_gr_load_colors(void);

extern INT xs_gr_plot_section(XS_STRUCT *pxs);

extern INT xs_gr_open_window(XS_STRUCT *pxs, INT *ptnr, INT *pwid, CHAR *metafile);

extern INT xs_gr_rect(DOUBLE xmin, DOUBLE ymin,
		      DOUBLE xmax, DOUBLE ymax,
		      COLOR_INDEX color, DOUBLE thickness);

extern INT xs_gr_reset_attr(void);

extern INT xs_gr_set_text(DOUBLE height, DOUBLE width, COLOR_INDEX color, INT center);

extern INT xs_gr_well_symbol(XS_STRUCT *pxs,
			     LAYOUT_STRUCT *pls,
			     DOUBLE xmin, DOUBLE xmax,
			     DOUBLE ymin, DOUBLE ymax);

#else       /* no prototypes */

extern INT lg_gr_plot_draw_hdr();
extern INT lg_gr_plot_draw_scale();
extern INT xs_gr_drawline();
extern INT xs_gr_draw_marks();
extern INT xs_gr_draw_section();
extern INT xs_gr_draw_ticks();
extern INT xs_gr_draw_traces();
extern INT xs_gr_draw_tracks();
extern INT xs_gr_get_drawinfo();
extern COLOR_STRUCT *xs_gr_load_colors();
extern INT xs_gr_plot_section();
extern INT xs_gr_open_window();
extern INT xs_gr_rect();
extern INT xs_gr_reset_attr();
extern INT xs_gr_set_text();
extern INT xs_gr_well_symbol();

#endif      /* of USE_PROTOTYPES */

#endif
                            
