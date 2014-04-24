/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WE_EDIT.H */
/* *2    11-MAR-1991 10:57:18 KEE "(SPR -1) Edit Well Depth Application include file" */
/* *1    11-MAR-1991 10:35:45 KEE "Include file for Edit Well Depth application" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WE_EDIT.H */
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

#ifndef ESI_WE_EDIT_H
#define ESI_WE_EDIT_H

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_WL_H
#include "esi_wl.h"
#endif

#ifndef ESI_WE_WELLS_H
#include "esi_we_wells.h"
#endif

#ifndef ESI_GKS_H
#include "esi_gks.h"
#endif

#ifndef ESI_MM_H
#include "esi_mm.h"
#endif

#ifndef ESI_WM_H
#include "esi_wm.h"
#endif

#ifndef ESI_MP_H
#include "esi_mp.h"
#endif

typedef struct 
	{
	INT label_position;
	CHAR horizon_name[41];
	CHAR source[31];	         
	BOOL suppress_symbols;
	BOOL suppress_text;
	GKS_REAL symbol_size;
	GKS_REAL text_size;
	COLOR_INDEX text_color;
	COLOR_INDEX symbol_color;
	
	INT   cdlgid;                     /* dialog id */
	INT   map_number;                 /* map id */
	INT   overlay_ndx;                /* overlay index on map definition */
	INT   well_pick_ndx;              /* pickable well index */
	FLOAT new_depth;                  /* new subsea depth */
	FLOAT label_x;                    /* well label x coordinate */
	FLOAT label_y;                    /* well label y coordinate */
        FLOAT cur_drillers_td;            /* original driller td */
	BOOL  has_drillers_td;            /* driller_td exist flag */
	MAP_NAME map_name;                /* map name */
	GROUP_ID group_id;                /* group id for all segment */
	CHAR orig_new_depth_str[31];      /* orig new subsea depth string */
	SYMBOL symbol;                    /* well symbol currently drawing */
	SEGMENT_ID *seg_id_label;         /* segment id arrary for label */
	SEGMENT_ID *seg_id_symbol;        /* segment id arrary for symbol */
	BOOL  *save_well;                 /* well_already save array */
	PICKABLE_WELLS *well_picks;       /* pointer to pickable well struct */
	WELL_STRUCT *well_header;	
	} WELL_EDIT;

typedef struct
       {
	 WELL_EDIT *pwe_array;
	 INT num_map;
       } WELL_EDIT_ARRAY;

/* function prototypes */

#if USE_PROTOTYPES

extern INT we_edit_well_init (CHAR *dummy);
extern INT we_edit_well_srvr (INT id, INT item, WELL_EDIT *pwe);
extern INT we_edit_well_quit (WELL_EDIT *pwe);
extern INT we_edit_well_updates (WELL_EDIT *pwe);
extern INT we_pick_one_well (WELL_EDIT *pwe);
extern INT wl_get_well_xy(FLOAT f_pick_x, FLOAT f_pick_y, 
			  FLOAT *f_ret_x, FLOAT *f_ret_y,
			  PICKABLE_WELLS *well_picks, INT *well_pick_ndx);
extern INT we_display_graphic_updates (WELL_EDIT *pwe, BOOL highlightsymbol);
extern INT we_display_well_info (WELL_EDIT *pwe);

#else

extern INT we_edit_well_init ();
extern INT we_edit_well_srvr ();
extern INT we_edit_well_quit ();
extern INT we_edit_well_updates ();
extern INT we_pick_one_well ();
extern INT we_pick_well_xy ();
extern INT we_display_graphic_updates ();
extern INT we_display_well_info ();

#endif

#endif









