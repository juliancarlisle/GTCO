/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LM.H */
/* *4    12-JUN-1991 14:54:05 PURNA "(SPR 0) upgrade user interface" */
/* *3     7-MAY-1991 17:50:02 PURNA "(SPR 1622) init change" */
/* *2    18-MAR-1991 17:34:10 PURNA "(SPR 0) Lease Mapping Init Checkin" */
/* *1    18-MAR-1991 17:33:39 PURNA "Lease Mapping" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LM.H */
/******************************************************************************

		Copyright Exploration Systems, Inc. 1990
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
 * ESI_LM.H
 *
 * Definitions for Mapping Leasemap Overlay.
 */

#ifndef ESI_LM_H
#define ESI_LM_H 1

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#ifndef ESI_GKS_H
#include "esi_gks.h"
#endif

typedef CHAR LM_LEASE_ID[24];


typedef struct lm_struct 
    {
    CHAR    *name;
    CHAR    *annotate;
    TCP	    annotate_tcp;
    CHAR    *color_fill_attribute;    /* Name of the db attribute */
    CHAR    *color_fill_clut;
    BOOL suppress_lines; 
    BOOL suppress_text; 
    GKS_INT text_color;
    GKS_INT text_font;
    GKS_REAL text_height;
    GKS_INT text_precision;
    LINE_ATTRIBUTE line;
    CHAR    *select_by_phrase;
    CHAR    *select_list;
    }LM_STRUCT;

typedef enum {
    LYNX_POLYGON_TYPE,
    GULF_POLYGON_TYPE,
 } LM_POLYGON_TYPE;
    
#define LM_DATE 0
#define LM_TEXT 1
#define LM_NUMERIC 3
#define LM_COLOR 4
#define LM_FILL_STYLE 5
#define LM_MDY 6
#define LM_DMY 7
#define LM_MY 8
#define LM_Y 9

#define TEXT_LEN    30
#define LM_DIALOG_WORKSPACE "LmDialogWorkspace"

typedef CHAR LM_EDIT_STRING[TEXT_LEN+2];

typedef struct lm_save_md_struct
    {
    INT save;
    INT *mth,*day;
    INT n_items;
    } LM_SAVE_MD_STRUCT;

typedef struct {
    INT lm_defs;
	INT defs_type;
	LM_EDIT_STRING defs_name;
	   TCP defs_name_list;
    INT lm_entrs;
        INT entrs_range;
	INT entrs_type;		    
	LM_EDIT_STRING entrs_typeEntry;
	    TCP entrs_typeEntry_list;
	LM_EDIT_STRING entrs_cfEntry;
	    TCP entrs_cfEntry_list;
	LM_EDIT_STRING entrs_cfPick;
	    TCP entrs_cfPick_list;
	LM_EDIT_STRING entrs_controlEntry;
	INT entrs_no_changes;	
	INT entrs_date_format;
    LM_SAVE_MD_STRUCT save_mth_n_day;
    INT lm_annot;
	TCP annot_tcp;
        TCP annot_select_tcp;
    INT lm_msg;
    } LM_DIALOG_STRUCT;
	    
    
#if USE_PROTOTYPES
extern INT lm_overlay(INT display_line);
extern INT lm_color_fill_clut(CHAR *parameter);
extern INT lm_annotate_init(CHAR *input_string,CHAR *annotate_param,BOOL *sqlphrase);
extern INT lm_display_overlay(LM_STRUCT *plm);
extern INT lm_draw_polygons(NLIST_HEADER select_list,LM_STRUCT *plm);
extern INT lm_draw_annotation(LM_LEASE_ID lease_id,NLIST_HEADER polygons,
	LM_STRUCT *plm,BOOL clipped);
extern INT lm_retrieve_column_entry(CHAR *column_name,LM_LEASE_ID lease_id,
 	CHAR *column_entry);
extern INT lmz_add_entry(INT id,LM_DIALOG_STRUCT *pex);
extern INT lmz_adjust_controls(INT prev_item,INT item,LM_DIALOG_STRUCT *pex);
extern INT lmz_check_save_changes(LM_DIALOG_STRUCT *pex,CHAR *message);
extern INT lmz_disable_date_buttons(INT id);
extern INT lmz_disable_radio_buttons(INT id);
extern INT lmz_defs_fill_selector(LM_DIALOG_STRUCT *pex);
extern INT lmz_entrs_fill_selName(INT id,LM_DIALOG_STRUCT *pex);
extern INT lmz_entrs_fill_selEntry(INT id,LM_DIALOG_STRUCT *pex);
extern INT lmz_enable_date_buttons(INT id);
extern INT lmz_enable_radio_buttons(INT id);
extern INT lmz_entrs_free_memory(LM_DIALOG_STRUCT *pex);
extern INT lmz_get_edittext(INT id,INT item,CHAR *text,CHAR *name);
extern INT lmz_load_name(LM_DIALOG_STRUCT *pex);
extern INT lmz_remove_entry(LM_DIALOG_STRUCT *pex);
extern INT lmz_save_name(LM_DIALOG_STRUCT *pex);
extern INT lmz_set_button_value(INT id,LM_DIALOG_STRUCT *pex);
extern INT lmz_set_defs_button_value(INT id,INT button_value);
#else
extern INT lm_overlay();
extern INT lm_color_fill_clut();
extern INT lm_annotate_init();
extern INT lm_init_nlist();
extern INT lm_display_overlay();
extern INT lm_draw_polygon();
extern INT lm_draw_annotation();
extern INT lm_retrieve_column_entry();
extern INT lmz_add_entry();
extern INT lmz_adjust_controls();
extern INT lmz_check_save_changes();
extern INT lmz_disable_date_buttons();
extern INT lmz_disable_radio_buttons();
extern INT lmz_defs_fill_selector();
extern INT lmz_entrs_fill_selName();
extern INT lmz_entrs_fill_selEntry();
extern INT lmz_enable_date_buttons();
extern INT lmz_enable_radio_buttons();
extern INT lmz_entrs_free_memory();
extern INT lmz_get_edittext();
extern INT lmz_load_name();
extern INT lmz_remove_entry();
extern INT lmz_save_name();
extern INT lmz_set_button_value();
extern INT lmz_set_defs_button_value();
#endif
#endif
