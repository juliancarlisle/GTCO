/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GB.H*/
/*  10   13-FEB-1992 16:33:35 PURNA "(SPR 5770) extracted update_enable_control from gb_make_or_hi.c"*/
/* *9    14-AUG-1990 11:47:25 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *8    30-JUL-1990 17:20:15 PURNA "(SPR 0) add lynx,lease select_list"*/
/* *7     1-APR-1990 20:07:58 SCD "(SPR 1) Add prototype, etc. for new function gb_set_hilite_exists()."*/
/* *6    18-NOV-1989 09:45:21 HALL "(SPR 5075) Global overhaul"*/
/* *5    12-AUG-1989 11:13:44 CONROY "(SPR 0) Revised global, selects, SQL macros & fixes"*/
/* *4    12-AUG-1989 10:19:18 GILLESPIE "(SPR 1) Fix prototype for gb_rect_pick_well - NLIST_HEADER instead of NLIST_ID"*/
/* *3    17-JUL-1989 10:39:33 GORDON "(SPR 0) fix prototype for gb_rect_pick_well"*/
/* *2    30-JUN-1989 15:48:13 GILLESPIE "(SPR -2) SCD mods"*/
/* *1    30-JUN-1989 15:00:33 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GB.H*/
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

#ifndef ESI_GB_H
#define ESI_GB_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_HT_H
#include "esi_ht.h"
#endif

#ifndef ESI_SL_H
#include "esi_sl.h"
#endif

#ifndef ESI_MP_H
#include "esi_mp.h"
#endif

/* Function declarations */

#if USE_PROTOTYPES

extern INT gbz_get_menu_item_help(INT menuid, INT itemid, INT rsrc_id,
	CHAR *rsrc_file, CHAR *string);
extern INT gbz_clip_range(COORD xmin, COORD xmax, COORD ymin, COORD ymax,
	NLIST_HEADER *returnList);
extern INT gbz_init_map_window(void);
extern INT gbz_term_map_window(void);
extern INT gb_clear_current_list (SL_DATA_TYPE data_type);
extern INT gb_configure_analyst(BYTE *pointer);
extern INT gb_create_seis_on_map_list(MAP_STRUCTURE *map,NLIST_HEADER *nlist,
	    BOOL flag);
extern INT gb_create_well_on_map_list(MAP_STRUCTURE *map,NLIST_HEADER *nlist,
	    BOOL flag);
extern INT gb_draw_polygon_array(INT *npoints, COORD *xmin, COORD *ymin,
       COORD *xmax, COORD *ymax, COORD **x, COORD **y);
extern INT gb_front_cdlg_help(void);
extern INT gb_highlight(SL_DATA_TYPE type );
extern INT gb_host_processor(INT dummy);
extern INT gb_make_list_current (NLIST_HEADER select_list);
extern INT gb_nlist_to_arrays (NLIST_HEADER nlist, COORD **x, COORD **y,
            INT *npoints);
extern INT gb_make_or_hilite(BYTE *dummy);
extern INT gb_pick_well(COORD x, COORD y, UWI well, COORD *retx, COORD *rety);
extern INT gb_point (SL_DATA_TYPE type, NLIST_HEADER *SLP );
extern INT gb_rect_map_wells(COORD xmin, COORD ymin, COORD xmax, COORD ymax,
	    HASH_TABLE **ht, BOOL all_wells);
extern INT gb_rect_pick_well(COORD xmin, COORD ymin, COORD xmax, COORD ymax,
	    NLIST_HEADER *select_list, BOOL all_wells);
extern INT gb_relational_retrieval (SL_DATA_TYPE TypeOfData,
	    NLIST_HEADER *LSP );
extern INT gb_select_menu_help(INT menuid, INT itemid, INT rsrc_id,
	    CHAR *rsrc_file);
extern INT gbterm(void);
extern INT gb_well_picking( NLIST_HEADER *listPtr);
extern INT gb_seis_polygon( NLIST_HEADER *select_list );
extern INT gb_well_polygon( NLIST_HEADER *select_list );
extern INT gb_well_rectangle( NLIST_HEADER *listPtr);
extern INT gb_reports(SL_DATA_TYPE data_type);
extern INT gb_save_current_list(SL_DATA_TYPE data_type);
extern INT gb_update_current_status(NLIST_HEADER select_list);
extern INT gb_whereami(BYTE *dummy);
extern INT gb_zoom(void);
extern VOID gb_set_hilite_exists(SL_DATA_TYPE data_type);

#else

extern INT gbz_init_map_window();
extern INT gbz_term_map_window();
extern INT gb_clear_current_list ();
extern INT gb_configure_analyst();
extern INT gb_create_seis_on_map_list();
extern INT gb_create_well_on_map_list();
extern INT gb_highlight();
extern INT gb_host_processor();
extern INT gbinit();
extern INT gb_make_list_current ();
extern INT gb_make_or_hilite();
extern INT gb_nlist_to_arrays();
extern INT gb_point ();
extern INT gb_relational_retrieval ();
extern INT gb_rect_map_wells();
extern INT gb_rect_pick_wells();
extern INT gbterm();
extern INT gb_well_picking();
extern INT gb_seis_polygon();
extern INT gb_well_polygon();
extern INT gb_well_rectangle();
extern INT gb_reports();
extern INT gb_save_current_list();
extern INT gb_select_list();
extern INT gb_update_current_status();
extern INT gb_whereami();
extern INT gb_zoom();
extern VOID gb_set_hilite_exists();

#endif

#endif
               
