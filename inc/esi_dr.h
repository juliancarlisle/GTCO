/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DR.H*/
/* *9    13-OCT-1990 00:40:41 GILLESPIE "(SPR 100) Move from Ernie"*/
/*  6B2  13-OCT-1990 00:20:34 GILLESPIE "Updates from Ernie"*/
/* *8    29-SEP-1990 10:55:12 GILLESPIE "(SPR 1) Merge beta deltas"*/
/*  6B1  28-SEP-1990 17:57:12 GILLESPIE "Beta Deltas"*/
/* *7    14-AUG-1990 11:47:00 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *6    19-JUL-1990 17:52:30 GILLESPIE "(SPR 5411) Add dr*ftrc calls"*/
/* *5    18-JUL-1990 09:36:11 GILLESPIE "(SPR 1) Fix two prototypes"*/
/* *4    17-JUL-1990 15:14:02 GILLESPIE "(SPR 1) Changes for elect. drafting cleanup"*/
/* *3    12-JUN-1990 11:33:01 SCD "(SPR -1) Bug fixing and new enhancement of Electronic Drafting Text Edit"*/
/* *2    10-AUG-1989 08:37:26 GORDON "(SPR 105) change prototype for dr_selection_list, add translation switches"*/
/* *1    30-JUN-1989 15:00:10 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DR.H*/
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

#ifndef ESI_DR_H
#define ESI_DR_H 1

/*  Electronic Drafting Include File  */

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_MM_H
#include "esi_mm.h"
#endif

#ifndef ESI_GO_H
#include "esi_go.h"
#endif

/*  Edit Text Controls                                                      */

#define DR_TEXT_OPEN         (INT)1  /*  Init the editor                    */ 
#define DR_TEXT_CLOSE        (INT)2  /*  Terminate the editor               */ 
#define DR_TEXT_LOAD         (INT)3  /*  Load the text for a given ID       */ 
#define DR_TEXT_RELEASE      (INT)4  /*  Release the current text set       */ 
#define DR_TEXT_SAVE         (INT)5  /*  Save the current text set          */ 
#define DR_TEXT_DELETE_TABLE (INT)6  /*  Delete a text set                  */ 
#define DR_TEXT_DELETE_BLOCK (INT)7  /*  Delete a text block                */ 
#define DR_TEXT_SELECT       (INT)8  /*  Pick a text block                  */ 
#define DR_TEXT_NEW          (INT)9  /*  Append a new text block w/defaults */ 
#define DR_TEXT_EDIT         (INT)10 /*  Edit the current text block        */

/*  Maximum number of lines in the text editing window                      */

#define DR_MAX_TEXT_LINES 20

/*  Maximum number of characters in a text object                           */

#define DR_MAX_TEXT_STRING 1000

/*  Default line spacing as multiple of text height                         */

#define DR_DEFAULT_LINE_SPACING 1.5

/*  Internal "element" type codes to identify each member
    in the list of object_structure's */

typedef enum {
    DR_UNKNOWN_OBJECT = 0,
    DR_LINE_OBJECT    = 1,
    DR_TEXT_OBJECT    = 2,
    DR_SYMBOL_OBJECT  = 3,
    DR_FAULT_OBJECT   = 4
    } DR_OBJECT_TYPE_T;

/*  Translation flags for calling dr_table_lookup                                   */
typedef enum {
    DR_CODE_TO_NAME = 1,
    DR_NAME_TO_CODE = 2
    } DR_LOOKUP_FLAG;

#define LINE_TYPE         "LINE"
#define TEXT_TYPE         "TEXT"
#define FAULTS_TYPE       "FAULTS"
#define POLYGON_TYPE      "POLYGON"
#define AVERAGE_VELOCITY  "AVERAGE_VELOCITY"
#define INTERVAL_VELOCITY "INTERVAL_VELOCITY"

/*  Structure definitions   */

typedef struct object_structure
    {
    DR_OBJECT_TYPE_T object_type;     /*  1 = Line, 2 = Text      */
    BOOL new_object;                  /*  TRUE -> object is new   */
    union 
        {
        LINE *current_line;
        TEXT *current_text;
        } object_ptr;
    struct object_structure *next_object;
    } OBJECT_STRUCTURE;

typedef struct 
    {
    UINT no_dialog_items;
    BOOL enabled_new[32];
    BOOL enabled_old[32];
    } DR_DIALOG_DATA;

/* Menu state housekeeping structure */

typedef struct 
    {
    INT id;
    UINT num_items;
    BOOL items_new[16];
    BOOL items_old[16];
    } DR_MENU_ENTRY;

typedef struct 
    {
    BOOL pick_echo;               /*  Indicates that echo is on screen        */
    INT pick_object;              /*  WM id of last object picked             */
    BOOL all_detectable;          /*  All segments are pickable               */
    BOOL new_object;              /*  Current object is not in database       */
    BOOL object_changed;          /*  Current object has been modified        */
    INT current_detect;           /*  Group id of current detect object       */
    CHAR current_object_type[41]; /*  From GRAPHIC_OBJECT_CODES table         */
    INT current_object_class;     /*              ditto                       */
    INT current_object_key;       /*  Database key of current object          */
    INT current_object;           /*  WM id                                   */
    INT current_overlay;          /*  WM id                                   */
    INT current_overlay_class;    /*  From OVERLAY_CODES table                */
    OBJECT_STRUCTURE *line_ptr;   /*  Set of all lines for this object        */
    LINE *current_line;           /*  Pointer to current line                 */
    INT current_line_seg;         /*  WM segment ID                           */
    BOOL overlay_exists;          /*  Current object type overlay is in display list */
    OBJECT_STRUCTURE *text_ptr;   /*  Set of all text for this object         */
    TEXT *current_text;           /*  Pointer to current text element         */
    INT current_text_seg;         /*  WM segment ID                           */
    BOOL member_not_used;         /*  Space available in structure            */
    BOOL line_poly;               /*  Lines are treated as polygons           */
    BOOL line_fill;               /*  Polygons are filled                     */
    struct 
        {
        FLOAT x, y;
        } lower_left_extent;      /*  Lower left extent                       */
    struct 
        {
        FLOAT x, y;
        } upper_right_extent;     /*  Upper right extent                      */
    FLOAT x_toler, y_toler;       /*  Pick aperture (1% of the map window)    */
    LINE default_line;            /*  Line defaults                           */
    TEXT default_text;            /*  Text defaults                           */
    INT named_overlay;
    struct 
        {
        DR_MENU_ENTRY draft;
        DR_MENU_ENTRY object;
        DR_MENU_ENTRY line;
        DR_MENU_ENTRY text;
        DR_MENU_ENTRY pref;
        } menu;
    struct 
        {
        INT nallocated;
        INT nused;
        INT *new_seg_array;       /* new segments after mods                  */
        INT *old_seg_array;       /* old segments befors any mods             */
        } mod_obj_segments;
    CHAR current_marker[32];      /* Marker code ... eg, for a fault          */
    CHAR current_top[32];         /* Current top marker                       */
    CHAR current_base[32];        /* Current base marker                      */
    CHAR source[33];              /* Owner of the current object              */
    } DR_DATA;

/*  Dialog id's allocated by resource manager                                 */

typedef struct 
    {
    INT text_dialog_id;
    INT base_dialog_id;
    INT selector_id;
    INT alignment_id;
    } CDLG_ID;

/*  Function definitions  */

#if USE_PROTOTYPES
extern INT dr_append_object (DR_DATA *dr_data, VOIDPTR type_data,
                            DR_OBJECT_TYPE_T type_code, INT new_flag);
extern INT dr_calc_char_size (DR_DATA *dr_data, DOUBLE x1, DOUBLE y1,
                              DOUBLE x2, DOUBLE y2, INT *nl);
extern INT dr_calc_char_up_vector (DR_DATA *dr_data, DOUBLE deltax,
                                   DOUBLE deltay);
extern INT dr_change_object_type (CHAR *object_type, DR_DATA *dr_data);
extern INT dr_chg_obj_type_by_id (INT object_id, DR_DATA *dr_data);
extern INT dr_commit (BOOL save_flag);
extern INT dr_create_object_type (CHAR *object_type);
extern INT dr_delete_element (CHAR *object_type, INT object_id_in,
                              INT element_id_in, DR_OBJECT_TYPE_T type_code,
			      CHAR *horizon, CHAR *line_name);
extern INT dr_delete_line_element (DR_DATA *dr_data);
extern INT dr_delete_object (DR_DATA *dr_data);
extern INT dr_delete_object_rows (INT object_id_in, CHAR *object_type,
				    DR_DATA *dr_data);
extern INT dr_delete_object_type (DR_DATA *dr_data);
extern INT dr_delete_object_type_sql (CHAR *object_type, DR_DATA *dr_data);
extern INT dr_delete_text_element (DR_DATA *dr_data);
extern INT dr_draft_menu_server (INT id, INT item, DR_DATA *dr_data);
extern INT dr_edit_line (DR_DATA *dr_data);
extern INT dr_edit_text (DR_DATA *dr_data);
extern INT dr_electronic_drafting (BYTE *p);
extern INT dr_find_element (DR_DATA *dr_data, INT item_id, INT seg_id,
                            DR_OBJECT_TYPE_T type_code);
extern INT dr_get_alignment_selection (CHAR *prompt, INT h_current_index,
                                       CHAR *h_selected, BOOL *cancel);
extern INT dr_get_fault_trace (CHAR *horizon, INT seq, LINE *line);
extern INT dr_get_line (LINE *line, INT line_number, FILENAME nlist_file,
                       BOOL isfault, CHAR *horizon);
extern INT dr_get_object_list (TCP *object_type_list, INT *no_items_out);
extern INT dr_get_selection (CHAR *prompt, TCP list, INT no_items,
                             CHAR *selected, BOOL *cancel);
extern INT dr_init_resources (DR_DATA *dr_data);
extern INT dr_line_menu_server (INT id, INT item, DR_DATA *dr_data);
extern INT dr_load_line (INT item_id, DR_DATA *dr_data);
extern INT dr_load_object (DR_DATA *dr_data);
extern INT dr_load_text (INT item_id, DR_DATA *dr_data);
extern INT dr_new_line (DR_DATA *dr_data);
extern INT dr_new_object (DR_DATA *dr_data);
extern INT dr_new_object_type (DR_DATA *dr_data);
extern INT dr_new_project_id (INT *id);
extern INT dr_new_rectangle (DR_DATA *dr_data);
extern INT dr_new_text (DR_DATA *dr_data);
extern INT dr_object_menu_server (INT id, INT item, DR_DATA *dr_data);
extern INT dr_perc_extents (DR_DATA *dr_data, OBJECT_STRUCTURE *this_object);
extern INT dr_pick_line (DR_DATA *dr_data);
extern INT dr_pick_object (DR_DATA *dr_data);
extern INT dr_pick_text (DR_DATA *dr_data);
extern INT dr_pref_lines (DR_DATA *dr_data);
extern INT dr_pref_menu_server (INT id, INT item, DR_DATA *dr_data);
extern INT dr_pref_polygon (DR_DATA *dr_data);
extern INT dr_pref_polygon_fill (DR_DATA *dr_data);
extern INT dr_put_fault_trace (DR_DATA *dr_data, CHAR *horizon, INT seq,
                               LINE *line);
extern INT dr_put_line (LINE *line, FILENAME nlist_file, DR_DATA *dr_data,
                        BOOL isfault, CHAR *horizon);
extern INT dr_put_object (DR_DATA *dr_data);
extern INT dr_put_text (TEXT *text, DR_DATA *dr_data);
extern INT dr_query_marker_name (CHAR *prompt, CHAR *marker_name);
extern INT dr_redraw_line (DR_DATA *dr_data);
extern INT dr_redraw_text (DR_DATA *dr_data);
extern INT dr_release_object (DR_DATA *dr_data);
extern INT dr_reset_object (DR_DATA *dr_data);
extern INT dr_save_correlation (INT object_id_in, OBJECT_STRUCTURE *this_object);
extern INT dr_save_object (DR_DATA *dr_data);
extern INT dr_select_go_element (DR_DATA *dr_data, FLOAT *x, FLOAT *y, GO_USER_STRUCT *object);
extern INT dr_select_object (DR_DATA *dr_data);
extern INT dr_select_object_type (DR_DATA *dr_data);
extern INT dr_set_name (DR_DATA *dr_data);
extern INT dr_set_poly_pref (DR_DATA *dr_data, BOOL poly_pref, BOOL fill_pref);
extern INT dr_slt_go_element_of_obj (DR_DATA *dr_data, FLOAT *x, FLOAT *y, GO_USER_STRUCT *object);
extern INT dr_table_delete (CHAR *table_name, CHAR *name);
extern INT dr_table_insert (CHAR *table_name, CHAR *name, INT value, CHAR *desc);
extern INT dr_table_lookup_dynamic (CHAR *table_name, CHAR *name, INT *value);
extern INT dr_term (DR_DATA *dr_data);
extern INT dr_text_dialog_server (DR_DIALOG_DATA *dialog_data, DR_DATA *dr_data);
extern INT dr_text_menu_server (INT id, INT item, DR_DATA *dr_data);
extern INT dr_update_dialog (DR_DIALOG_DATA *dialog_data, DR_DATA *dr_data,
                            CDLG_ID *cdlg_id);
extern INT dr_update_fault_trace (DR_DATA *dr_data, CHAR *horizon, INT seq,
                                  LINE *line);
extern INT dr_update_line (LINE *line, FILENAME nlist_file, DR_DATA *dr_data,
                           BOOL isfault, CHAR *horizon);
extern INT dr_update_menus (DR_DATA *dr_data, BOOL reset);
extern INT dr_update_nlist (NLIST_HEADER nlist, FILENAME nlist_name, NLIST_ID nlist_id,
                           UINT *dim_list, DOUBLE conversion_tolerance,
                           DR_DATA *dr_data);
extern INT dr_update_text (TEXT *text, DR_DATA *dr_data);
extern INT dr_write_nlist (NLIST_HEADER nlist, FILENAME nlist_file, NLIST_ID nlist_id,
                          UINT *dim_list, DOUBLE conversion_tolerance,
                          DR_DATA *dr_data);

#else
extern INT dr_append_object ();
extern INT dr_calc_char_size ();
extern INT dr_calc_char_up_vector ();
extern INT dr_change_object_type ();
extern INT dr_chg_obj_type_by_id ();
extern INT dr_commit ();
extern INT dr_create_object_type ();
extern INT dr_delete_element ();
extern INT dr_delete_line_element ();
extern INT dr_delete_object ();
extern INT dr_delete_object_rows ();
extern INT dr_delete_object_type ();
extern INT dr_delete_object_type_sql ();
extern INT dr_delete_text_element ();
extern INT dr_draft_menu_server ();
extern INT dr_edit_line ();
extern INT dr_edit_text ();
extern INT dr_electronic_drafting ();
extern INT dr_find_element ();
extern INT dr_get_alignment_selection ();
extern INT dr_get_fault_trace ();
extern INT dr_get_line ();
extern INT dr_get_object_list ();
extern INT dr_get_selection ();
extern INT dr_init_resources ();
extern INT dr_line_menu_server ();
extern INT dr_load_line ();
extern INT dr_load_object ();
extern INT dr_load_text ();
extern INT dr_menu_server ();
extern INT dr_new_line ();
extern INT dr_new_object ();
extern INT dr_new_object_type ();
extern INT dr_new_project_id ();
extern INT dr_new_rectangle ();
extern INT dr_new_text ();
extern INT dr_object_menu_server ();
extern INT dr_perc_extents ();
extern INT dr_pick_line ();
extern INT dr_pick_object ();
extern INT dr_pick_text ();
extern INT dr_pref_lines ();
extern INT dr_pref_menu_server ();
extern INT dr_pref_polygon ();
extern INT dr_pref_polygon_fill ();
extern INT dr_put_fault_trace ();
extern INT dr_put_line ();
extern INT dr_put_object ();
extern INT dr_put_text ();
extern INT dr_query_marker_name ();
extern INT dr_redraw_line ();
extern INT dr_redraw_text ();
extern INT dr_release_object ();
extern INT dr_reset_object ();
extern INT dr_save_correlation ();
extern INT dr_save_object ();
extern INT dr_select_go_element ();
extern INT dr_select_object ();
extern INT dr_select_object_type ();
extern INT dr_set_name ();
extern INT dr_set_poly_pref ();
extern INT dr_slt_go_element_of_obj ();
extern INT dr_table_delete ();
extern INT dr_table_insert ();
extern INT dr_table_lookup_dynamic ();
extern INT dr_term ();
extern INT dr_text_dialog_server ();
extern INT dr_text_menu_server ();
extern INT dr_update_dialog ();
extern INT dr_update_fault_trace ();
extern INT dr_update_line ();
extern INT dr_update_menus ();
extern INT dr_update_nlist ();
extern INT dr_update_text ();
extern INT dr_write_nlist ();

#endif
#endif
