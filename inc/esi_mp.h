/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MP.H*/
/* *10   13-OCT-1990 01:01:13 GILLESPIE "(SPR 100) Merge with Ernie "*/
/*  7B2  13-OCT-1990 00:25:27 GILLESPIE "Updates from Ernie"*/
/* *9    29-SEP-1990 10:18:11 GILLESPIE "(SPR 1) Merge beta deltas"*/
/*  7B1  28-SEP-1990 17:59:41 GILLESPIE "Beta Deltas"*/
/* *8    14-AUG-1990 11:49:39 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *7     7-MAR-1990 16:39:51 WALTERS "(SPR 0) Remove FLOAT types from system"*/
/* *6    15-FEB-1990 10:42:58 WALTERS "(SPR 0) Change map structure for changes in map setup dialog"*/
/* *5    18-JAN-1990 13:17:13 WALTERS "(SPR 0) Added lat_long_format to map structure"*/
/* *4    16-JAN-1990 09:20:14 WALTERS "(SPR 0) added lat_long state variable"*/
/* *3    31-OCT-1989 11:54:14 GILLESPIE "(SPR 30) Remove extraneous includes in includes"*/
/* *2    10-OCT-1989 16:49:26 CONROY "(SPR 5028) New routines for new plotting capabilities"*/
/* *1    30-JUN-1989 15:03:12 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MP.H*/
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

/* * MAPPING INCLUDE FILE *                                                         */
/* ------------------------                                                         */

#ifndef ESI_MP_H
#define ESI_MP_H 1

/************************************************************************************/

/* * INCLUDE THE MAPDEF DEFINITIONS *                                               */
/* ----------------------------------                                               */

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_MD_DEFS_H
#include "esi_md_defs.h"
#endif

#ifndef ESI_FM_H
#include "esi_fm.h"
#endif

typedef CHAR MAP_NAME[50];
typedef CHAR MP_TTLBLK_LINE[101];

typedef struct 
    {
    TCP name;
    INT n_names;
    INT *n_references;
    INT n_define;
    FM_LONG last_used;
    } MP_FILES;

/* * THE BASIC MAP STRUCTURE *                                                      */
/* ---------------------------                                                      */

typedef struct 
    {
    /* Map Identification Elements                                                  */
    MAP_NAME map_name;
    INT map_number;
    
    /* Map/Window Manager Elements                                                  */
    INT map_window_id;
    INT map_tnr;
    INT map_header_id;
    INT wm_nalloc;
    INT *wm_id_list;
    INT *wm_id_count;
    TCP wm_group_names;
    
    /* Map Setup Elements                                                           */
    PROJECTION_ID map_projection;
    CHAR map_coordinate_system[16];
    struct 
        {
        COORD x, y;
        } lower_left_xy;
    struct 
        {
        COORD x, y;
        } upper_right_xy;
    CHAR lower_left_str[21];
    CHAR upper_right_str[21];
    DOUBLE map_scale;
    CHAR map_scale_uom[21];
    
    /* Map State Elements                                                           */
    DOUBLE wcs_to_inches;
    BOOL change_flag;
    BOOL full_screen_flag;
    BOOL map_is_registered;
    BOOL map_displayed;
    BOOL valid;
    BOOL setup_ok;
    
    /* Map Overlay Structures                                                       */
    MD_DISPLAY *display;
    MD_COMPILED_MAPDEF *compiled;
    
    /* Title Block Elements                                                         */
    BOOL map_title_on_map;
    CHAR title_block_name[41];
    INT title_size[25];
    MP_TTLBLK_LINE title_text[25];
    
    /* Map Seismic Structure                                                        */
    VOIDPTR pso;
    
    /* Plotting Layout Elements                                                     */
    
    DOUBLE ttlblk_xmin, ttlblk_xmax, ttlblk_ymin, ttlblk_ymax;
    INT bar_type;
    DOUBLE bar_xmin, bar_xmax, bar_ymin, bar_ymax;
    INT arrow_type;
    DOUBLE arrow_xmin, arrow_xmax, arrow_ymin, arrow_ymax;
    
    /* Mapping Files Structures                                                     */
    MP_FILES scatters;
    MP_FILES grids;
    MP_FILES contours;
    MP_FILES perspectives;
    
    INT scale_sizes_for_plotting;
    
    } MAP_STRUCTURE;

/* * TITLE BLOCK BUFFER STRUCTURE *                                                 */
/* --------------------------------                                                 */

typedef struct 
    {
    INT window_id;
    INT trans_id;
    INT form_id;
    INT seg_id[25];
    INT size[25];
    MP_TTLBLK_LINE text[25];
    BOOL mod_field[25];
    INT crnt_field;
    } MP_TTLBLK_VARS;

/* * RESOURCE ID'S *                                                                */
/* -----------------                                                                */

typedef struct 
    {
    INT base_dialog_id;
    INT overlays_id;
    INT map_setup_id;
    INT delete_map_id;
    INT activate_map_id;
    INT title_block_id;
    INT delete_ttlblk_id;
    INT input_text_id;
    INT file_select_id;
    } RESOURCE_ID;

/* * MENU ID'S *                                                                    */
/* -------------                                                                    */

typedef struct 
    {
    INT mapping_id;
    INT make_map_id;
    INT display_options_id;
    INT layout_id;
    BOOL menu_status[5];
    BOOL menu_item_status[4][7];
    } MENU_ID;

/* * NULL STRING FOR COMMUNICATION TO BATCH PLOTTING PROGRAM *                      */
/* -----------------------------------------------------------                      */

#define NULL_FOR_COMM "~"

/* * FUNCTION DEFINITIONS *                                                         */
/* ------------------------                                                         */


#if USE_PROTOTYPES
extern INT mp_activate_map_pipe (void);
extern INT mp_add_keyword (INT id);
extern INT mp_add_overlay (INT id);
extern INT mp_check_setup (void);
extern INT mp_close_map (void);
extern INT mp_compiled_size_check (INT num);
extern INT mp_create_map (void);
extern INT mp_default_size_scale (void);
extern INT mp_del_title_block (void);
extern INT mp_delete_keyword (INT id);
extern INT mp_delete_map_pipe (void);
extern INT mp_delete_overlay (INT id);
extern INT mp_display_map (BOOL full, BOOL screen);
extern INT mp_display_size_check (INT num);
extern INT mp_display_title_block (void);
extern INT mp_draw_north_arrow (DOUBLE xmin, DOUBLE xmax, DOUBLE ymin, DOUBLE ymax,
                                INT type);
extern INT mp_draw_scale_bar (DOUBLE xmin, DOUBLE xmax, DOUBLE ymin, DOUBLE ymax,
                              DOUBLE wcs_to_inches, DOUBLE scale, CHAR *uom, INT type);
extern INT mp_draw_ttlblk_form (void);
extern INT mp_edit_parameter (INT id);
extern INT mp_erase_map (MAP_STRUCTURE *map, BOOL flag);
extern INT mp_erase_overlay (INT comprow);
extern INT mp_fill_parm_box (MD_KEY_INFO *key_info);
extern INT mp_front_map (MAP_STRUCTURE **mapdef);
extern INT mp_gen_title_block (MAP_STRUCTURE *map);
extern INT mp_get_current_map (MAP_STRUCTURE **mapdef);
extern INT mp_get_parameter (BOOL flag, MD_KEY_INFO *key_info, CHAR *string,
                             MD_PARM_STRUCT **parmstruc);
extern INT mp_get_plot_wcs_to_inches (MAP_STRUCTURE *mapdef, DOUBLE *wcs);
extern INT mp_get_ttlblk_name (CHAR *name);
extern INT mp_hilite_window (void);
extern INT mp_init_compiled_mapdef (MD_COMPILED_MAPDEF **compiled, INT rownum);
extern INT mp_init_comp_verb (MD_COMPILED_VERB **verbstruc, MD_VERB_INFO *verb_info);
extern INT mp_init_display_struct (MD_DISPLAY **display, INT rownum);
extern INT mp_init_map_server (void);
extern INT mp_init_title_block (void);
extern BOOL mp_is_seismic_overlay (INT verb_code);
extern INT mp_keyword_selected (INT id);
extern BOOL mp_key_lookup (INT key_code, INT verb_ndx, INT *returned_ndx);
extern INT mp_layout_server (INT id, INT item, BYTE *pointer);
extern INT mp_make_map (INT id, INT item, BYTE *pointer);
extern INT mp_mapping_server (INT id, INT item, BYTE *pointer);
extern INT mp_mapping (BYTE *pointer);
extern INT mp_map_list (CHAR *project, TCP *list, INT *num);
extern INT mp_map_server (INT id, INT item, BYTE *pointer);
extern INT mp_map_setup_pipe (void);
extern INT mp_map_window (void);
extern INT mp_menu_status (void);
extern INT mp_north_arrow (void);
extern INT mp_num_displayed_maps (INT *i);
extern INT mp_open_map (void);
extern INT mp_options_server (INT id, INT item, BYTE *pointer);
extern INT mp_overlay_defaults (INT verb_ndx, INT row);
extern INT mp_overlay_selected (INT id);
extern BOOL mp_parm_ok (CHAR *string, INT verb_ndx, INT key_ndx,
                        MD_PARM_STRUCT **parmstruc, INT *status);
extern INT mp_pref_overlay_selected (INT id);
extern INT mp_project_parm_list (MD_KEY_INFO *key_info, TCP *list, INT *nitems);
extern INT mp_quit_title_block (void);
extern INT mp_read_map (CHAR *name);
extern INT mp_req_chk (INT display_line, INT *req_ndx);
extern INT mp_req_key_setup (INT req_ndx);
extern INT mp_ret_title_block (CHAR *name, INT *size, MP_TTLBLK_LINE *text);
extern INT mp_retrieve_workspace (INT i);
extern INT mp_save_map_pipe (void);
extern INT mp_save_title_block (CHAR *name, INT *size, MP_TTLBLK_LINE *text);
extern INT mp_scale_bar (void);
extern INT mp_select_map (MAP_STRUCTURE **mapdef);
extern INT mp_set_current_map (MAP_STRUCTURE *mapdef);
extern INT mp_set_duom (INT display_line);
extern INT mp_set_mapdef_buttons (void);
extern INT mp_set_text_size_btns (INT button);
extern INT mp_store_workspace (void);
extern INT mp_ttlblk_cdlg_srvr (INT id, INT item, BYTE *pointer);
extern INT mp_ttlblk_list (TCP *list, INT *nitems);
extern INT mp_ttlblk_menu_srvr (INT id, INT item, BYTE *pointer);
extern INT mp_ttlblk_upd_display (INT *size, MP_TTLBLK_LINE *text);
extern INT mp_valid_check (BOOL full);
extern BOOL mp_verb_lookup (INT verb_code, INT *return_ndx);
extern INT mp_window_header (void);

extern INT mpz_display_overlays (INT start, INT end);
extern INT mpz_get_file_struct (FM_TYPE type, MP_FILES **file_struct);
extern INT mpz_map_to_plotter (BOOL full);
extern INT mpz_map_to_screen (BOOL full);
extern BOOL mpz_pending_ok (void);

#else

extern INT mp_activate_map_pipe ();
extern INT mp_add_keyword ();
extern INT mp_add_overlay ();
extern INT mp_check_setup ();
extern INT mp_close_map ();
extern INT mp_compiled_size_check ();
extern INT mp_create_map ();
extern INT mp_default_size_scale ();
extern INT mp_del_title_block ();
extern INT mp_delete_keyword ();
extern INT mp_delete_map_pipe ();
extern INT mp_delete_overlay ();
extern INT mp_display_map ();
extern INT mp_display_size_check ();
extern INT mp_display_title_block ();
extern INT mp_draw_north_arrow ();
extern INT mp_draw_scale_bar ();
extern INT mp_draw_ttlblk_form ();
extern INT mp_edit_parameter ();
extern INT mp_erase_map ();
extern INT mp_erase_overlay ();
extern INT mp_fill_parm_box ();
extern INT mp_front_map ();
extern INT mp_gen_title_block ();
extern INT mp_get_current_map ();
extern INT mp_get_parameter ();
extern INT mp_get_plot_wcs_to_inches ();
extern INT mp_get_ttlblk_name ();
extern INT mp_hilite_window ();
extern INT mp_init_compiled_mapdef ();
extern INT mp_init_comp_verb ();
extern INT mp_init_display_struct ();
extern INT mp_init_map_server ();
extern INT mp_init_title_block ();
extern BOOL mp_is_seismic_overlay ();
extern INT mp_keyword_selected ();
extern BOOL mp_key_lookup ();
extern INT mp_layout_server ();
extern INT mp_make_map ();
extern INT mp_mapping_server ();
extern INT mp_mapping ();
extern INT mp_map_list ();
extern INT mp_map_server ();
extern INT mp_map_setup_pipe ();
extern INT mp_map_window ();
extern INT mp_menu_status ();
extern INT mp_num_displayed_maps ();
extern INT mp_north_arrow ();
extern INT mp_open_map ();
extern INT mp_options_server ();
extern INT mp_overlay_defaults ();
extern INT mp_overlay_selected ();
extern BOOL mp_parm_ok ();
extern INT mp_pref_overlay_selected ();
extern INT mp_project_parm_list ();
extern INT mp_quit_title_block ();
extern INT mp_read_map ();
extern INT mp_req_chk ();
extern INT mp_req_key_setup ();
extern INT mp_ret_title_block ();
extern INT mp_retrieve_workspace ();
extern INT mp_save_map_pipe ();
extern INT mp_save_title_block ();
extern INT mp_scale_bar ();
extern INT mp_select_map ();
extern INT mp_set_current_map ();
extern INT mp_set_duom ();
extern INT mp_set_mapdef_buttons ();
extern INT mp_set_text_size_btns ();
extern INT mp_store_workspace ();
extern INT mp_ttlblk_cdlg_srvr ();
extern INT mp_ttlblk_list ();
extern INT mp_ttlblk_menu_srvr ();
extern INT mp_ttlblk_upd_display ();
extern INT mp_valid_check ();
extern BOOL mp_verb_lookup ();
extern INT mp_window_header ();

extern INT mpz_display_overlays ();
extern INT mpz_get_file_struct ();
extern INT mpz_map_to_plotter ();
extern INT mpz_map_to_screen ();
extern BOOL mpz_pending_ok ();

#endif

#endif
