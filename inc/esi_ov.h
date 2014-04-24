/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OV.H*/
/* *2    14-AUG-1990 11:50:18 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:03:37 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OV.H*/
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

#ifndef ESI_OV_H
#define ESI_OV_H 1


/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: ESI_OV.H

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing function definitions for superclass
		processing.

   ************************************************************************ */




/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_OV_DEFS_H
#include "esi_ov_defs.h"
#endif

#ifndef ESI_MD_DEFS_H
#include "esi_md_defs.h"
#endif

#ifndef ESI_FM_H
#include "esi_fm.h"
#endif

#ifndef ESI_MM_H
#include "esi_mm.h"
#endif

/* * DATA STRUCTURES * */
/* ------------------- */

typedef struct
    {
    PROJECTION_ID projection;
    CHAR base_surface[21];
    CHAR top_surface[21];
    } OV_SCATTER_USER;


/* * FUNCTIONS * */
/* ------------- */

#if USE_PROTOTYPES

extern INT ov_chk_where(CHAR **string);
extern INT ov_close_overlay(INT display_line);
extern INT ov_close_scatter(NLIST_HEADER scatter, FM_FILE name, CHAR *mode,
	    FILENAME os_name);
extern INT ov_fill_generic(MD_KEY_STRUCT *keystruc, OV_GENERIC *generic);
extern INT ov_fill_line(MD_KEY_STRUCT *keystruc, LINE *line, BOOL *suppress_lines,
	BOOL *line_smoothing);
extern INT ov_fill_symbol(MD_KEY_STRUCT *keystruc, SYMBOL *symbol, BOOL *suppress);
extern INT ov_fill_text(MD_KEY_STRUCT *keystruc, TEXT *text, BOOL *suppress);
extern INT ov_get_class(CHAR *verb, INT *class, CHAR **name);
extern INT ov_inq_overlay_lists(TCP *name_list, INT id[50], INT *num_list);
extern INT ov_new_element( INT *segment_id, INT element_class, CHAR *element_name,
	    INT element_id );
extern INT ov_new_object( INT *group_id, CHAR *object_type, INT object_class,
	    INT object_id );
extern INT ov_open_overlay(INT display_line, CHAR *user_name);
extern INT ov_open_scatter(NLIST_HEADER *scatter, FM_FILE name, CHAR *mode,
	    FILENAME os_name);
extern INT ov_read_scatter(NLIST_HEADER scatter,
	    FLOAT **x, FLOAT **y, FLOAT **z, INT *npts);
extern INT ov_reset_default(CHAR *name, CHAR **dflt_name);
extern INT ov_search_list(CHAR *name, BOOL sub_groups, INT *position);
extern INT ov_set_overlay_lists(TCP name_list, INT id_list[50], INT num_list);
extern INT ov_set_upvector(TEXT *text, CHAR *string);
extern INT ov_write_scatter(NLIST_HEADER scatter,
	    FLOAT *x, FLOAT *y, FLOAT *z, INT npts);

#else

extern INT ov_chk_where();
extern INT ov_close_overlay();
extern INT ov_close_scatter();
extern INT ov_fill_generic();
extern INT ov_fill_line();
extern INT ov_fill_symbol();
extern INT ov_fill_text();
extern INT ov_get_class();
extern INT ov_inq_overlay_lists();
extern INT ov_new_element();
extern INT ov_new_object();
extern INT ov_open_overlay();
extern INT ov_open_scatter();
extern INT ov_read_scatter();
extern INT ov_reset_default();
extern INT ov_search_list();
extern INT ov_set_overlay_lists();
extern INT ov_set_upvector();
extern INT ov_write_scatter();

#endif

#endif
