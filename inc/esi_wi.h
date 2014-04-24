/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WI.H*/
/* *5     3-MAY-1991 16:21:48 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *4    13-OCT-1990 00:31:35 GILLESPIE "(SPR 100) Move Ernie deltas"*/
/*  2B1  13-OCT-1990 00:29:08 GILLESPIE "Updates from Ernie"*/
/* *3    14-AUG-1990 11:51:52 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    18-NOV-1989 09:42:04 GILLESPIE "(SPR 5075) Global overhaul"*/
/* *1    30-JUN-1989 15:05:40 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WI.H*/
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

/*%F Workstation Interface Include file.
     This should be included by the user in any file calling the WI module.
     Copyright Exploration Systems, Inc. */

#ifndef ESI_WI_H
#define ESI_WI_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#define WI_BAD_OBJECT_ID (INT)0

/* define Event Classes and Input Modes. */
#define WI_MENU_EVENT       (INT)8
#define WI_DIALOG_EVENT     (INT)9
#define WI_SELECT_EVENT    (INT)10
#define WI_FILE_MENU_EVENT (INT)11
#define WI_NO_TIMEOUT      (INT)-1

#define WI_REQUEST_MODE (INT)0
#define WI_SAMPLE_MODE  (INT)1
#define WI_EVENT_MODE   (INT)2

/* Owner ID for illegal unowned dialogs and menus. */
#define WI_NO_OWNER_ID (0)

/* file_menu item #s...*/
#define WI_FILE_MENU_NEW     (INT)9001
#define WI_FILE_MENU_OPEN    (INT)9002
#define WI_FILE_MENU_CLOSE   (INT)9003
#define WI_FILE_MENU_SAVE    (INT)9004
#define WI_FILE_MENU_SAVE_AS (INT)9005
#define WI_FILE_MENU_DELETE  (INT)9006
#define WI_FILE_MENU_QUIT    (INT)9007

#define WI_JOURNAL (INT)1
#define WI_PLAYBACK (INT)2

#define WI_DIALOG (INT)1
#define WI_MENU (INT)2

/* for app mgr 9/26/86 ... returned as item# on WI_SELECT_EVENT */
#define WI_SELECTED (INT)9020

/* Terminal Types */
#define TTYPE_VT100 (INT)0
#define TTYPE_ESITERM (INT)1

/* Graphics Terminal Symbols for Workstation */

#define WTYPE_NONGRAPHIC (INT)0
#define WTYPE_RT110 (INT)110
#define WTYPE_RT180 (INT)180

/* Workstation Interface Data Structures */
#define ST_MAC_MAX 256
#define ST_MENU_MAX 32
#define ST_TAG_MAX 32

/*%D Mac dependant. */
#define MAX_MN_ITEMS 16

/*%D Change NEON Code in AACUSTOMD on MAC for larger value. */
#define MAX_CD_ITEMS 64

/*%D Change NEON code in AASELECTOR on MAC for larger value. */
#define MAX_CD_SELECTABLE 32
/* There is no theoretical limit, just memory limits. */
#define MAX_CD_SELECTIONS 2048
/* Define string to be recognized as the HELP string. */
#define HELP_STRING "help"

/* This is determined by the length of the NEON terminal input buffer. */
/* It is the maximum length of a command string. */
#define ST_COMMAND_MAX 80
#define ST_SUBSTRING_MAX (ST_COMMAND_MAX-15)

#define VERIFY_NONE         (INT)0
#define VERIFY_ALPHANUMERIC (INT)1
#define VERIFY_FLOAT        (INT)2
#define VERIFY_INTEGER      (INT)3

/* structure used by Software (BOZO) Bus to communicate MENU and ITEM IDS */

typedef struct event_id_struct
    {
    INT menu_id;
    INT item_id;
    } EVENT_ID_STRUCT;

/* Pull Down Menu */
struct mitem       /* Menu Item */
    {
    CHAR command[ST_MENU_MAX];
    BYTE ifenab;
    BYTE ifcheck;
    };

struct menu        /* Menu */
    {
    INT num_mn_items;                  /* Number of items used in menu. */
    BYTE ifstatic;                /* Does not get rolled off screen? */
    BYTE ifmain;                  /* Main menu for an application? */
    BYTE ifvisibl;                /* Is the menu visible? */
    CHAR mtitle[ST_MENU_MAX];     /* Menu title for menu bar. */
    struct mitem item[MAX_MN_ITEMS];   /* Item in menu. */
    };

typedef struct menu MENU;

/* Rectangle ------------------------------------------------ */
struct int_rectangle
    {
    INT ixmin, ixmax, iymin, iymax;
    } ;
typedef struct int_rectangle INT_RECTANGLE;

/* Custom Dialog Box ---------------------------------------- */
struct cditem       /* Custom Dialog Item */
    {
    INT_RECTANGLE cd_item_rect;         /* Item bounds. */
    CHAR cd_item_text[ST_MAC_MAX];
    BYTE cd_item_value;
    BYTE if_cd_item_enabled;
    INT  cd_item_type;
    INT cd_item_group;
    INT cd_item_font;
    INT cd_item_textsize;
    INT cd_item_verify;
    INT cd_item_verify_len;
    BOOL cd_hscroll;
    };

struct custom_dialog                  /* Custom Dialog */
    {
    INT_RECTANGLE cd_rect;        /* Window placement. */
    CHAR cd_title[ST_MAC_MAX];    /* Menu title for custom dialog bar. */
    INT num_cd_items;             /* Number of items used in custom dialog. */
    struct cditem cd_item[MAX_CD_ITEMS];  /* Items in custom dialog. */
    };

typedef struct custom_dialog CUSTOM_DIALOG;

/* 11/17/88 SC - declare functions extern and update list of functions */

#if USE_PROTOTYPES

extern INT wi_activate(INT cdlgid, INT cditemid, INT activate_flag);
extern INT wi_add_callback (INT (*addr)(), BYTE *ptr);
extern INT wi_alert(INT level, CHAR *helpkey, CHAR *message1, CHAR *message2);
extern INT wi_alertx(INT level, CHAR *helpkey,CHAR *message1, CHAR *message2,
    INT owner, CHAR *tag);
extern INT wi_assign_text_object(INT dialog, INT control, INT textid);
extern INT wi_beep(INT beepid);
extern INT wi_checkid(INT input_id, INT item_id, INT typecode);
extern INT wi_change_owner_id(INT input_id, INT new_owner_id);
extern INT wi_change_owner_tag(INT input_id, CHAR *new_owner_tag);
extern INT wi_check_menu_item(INT menuid, INT itemid, INT onoroff);
extern INT wi_clear(INT input_id);
extern INT wi_close_dialog(INT cdlgid);
extern INT wi_define_dialog(CUSTOM_DIALOG *thecdlg, CHAR *help_key, INT *cdlgid);
extern INT wi_define_menu(MENU *themenu, CHAR *help_key, INT *menuid);
extern INT wi_define_text_object(TCP strings, INT numstrings, INT *textid);
extern INT wi_delete_cd_line(INT cdlg_id, INT item_id, INT line_num);
extern INT wi_do_help(INT object_id);
extern INT wi_enable_dialog(INT cdlgid, INT enable_flag);
extern INT wi_enable_dialog_item(INT cdlgid, INT cditemid, INT enable_flag);
extern INT wi_enable_dialog_items(INT cdlgid, INT numitems, INT *do_or_dont,
    INT *onoroff);
extern INT wi_enable_file_menu_item(INT cdlgid, INT fmitemid, INT enable_flag);
extern INT wi_enable_keyboard(INT onoroff);
extern INT wi_enable_menu(INT menuid, INT flag);
extern INT wi_enable_menu_item(INT menuid, INT itemid, INT onoroff);
extern INT wi_enable_menu_items(INT menuid, INT numitems, INT *onoroff);
extern INT wi_initialize(INT wkid, INT gtype, INT ttype, INT jp_mode, CHAR *jp_name);
extern INT wi_insert_cd_line(INT cdlg_id, INT item_id, INT line_num, CHAR *line_text);
extern INT wi_message(CHAR *message);
extern INT wi_open_dialog(INT cdlgid);
extern INT wi_pop(void);
extern INT wi_pop_owner(INT owner_id);
extern INT wi_push(void);
extern INT wi_push_owner(INT owner_id);
extern INT wi_qedit_selection(INT cdlgid, INT cditemid, INT *cdvalue, CHAR *cdtext);
extern INT wi_query_dialog_changes(INT cdlgid, INT maxitems, INT *numitems, INT *items);
extern INT wi_query_dialog_item(INT cdlgid, INT cditemid, INT *cdvalue, CHAR *cdtext);
extern INT wi_query_front_dialog(INT *cdlgid);
extern INT wi_query_helpkey(INT input_id, CHAR *helpkey);
extern INT wi_query_input_owner_id(INT input_id, INT *owner_id_ptr);
extern INT wi_query_input_owner_tag(INT input_id, CHAR *owner_tag);
extern INT wi_query_selections(INT cdlgid, INT cditemid, INT *numitems, INT *items);
extern INT wi_read_define_dialog(INT cdrsid, CHAR *help_key, INT *numitems, INT *cdlgid);
extern INT wi_read_define_menu(INT mrsid, CHAR *help_key, INT *numitems, INT *menuid);
extern INT wi_read_dialog(INT cdrsid, CUSTOM_DIALOG *thecdlg);
extern INT wi_read_menu(INT mrsid, MENU *themenu);
extern INT wi_release_dialog(INT cdlgid);
extern INT wi_release_menu(INT menuid);
extern INT wi_release_text_object(INT textid);
extern INT wi_remove_callback (INT (*addr)());
extern INT wi_request_dialog_item(INT *cdlgid, INT *cditemid, INT *cdvalue,
    CHAR *cdtext);
extern INT wi_request_event (INT timeout, INT *event_class_ptr, INT *object_id_ptr,
    INT *item_id_ptr);
extern INT wi_request_integer(CHAR *stprompt, CHAR *helpkey, INT valmin, INT valmax,
    INT valdefault, INT *thevalue, INT *status);
extern INT wi_request_locate(INT *status, INT *tnr, FLOAT *xpos, FLOAT *ypos,
    INT *button);
extern INT wi_request_selection(CHAR *prompt, INT *numselected, INT *selected,
    INT *status);
extern INT wi_request_string(CHAR *stprompt, CHAR *stdefault, CHAR *helpkey,
    INT lenresp, CHAR *stresponse, INT *status);
extern INT wi_set_cd_clickback(INT cdlgid, INT enable_flag);
extern INT wi_set_default_sel(INT cdlgid, INT cditemid, INT default_sel);
extern INT wi_set_defaults(INT cdlgid, INT cditemid, INT numitems, INT *items_array,
    INT onoroff);
extern INT wi_set_default_button(INT cdlgid, INT cditemid, INT state);
extern INT wi_set_dialog_range(INT cdlgid, INT cditemid, INT cdvmin, INT cdvmax);
extern INT wi_set_dialog_text(INT cdlgid, INT cditemid, CHAR *cdtext);
extern INT wi_set_dialog_title (INT cdlgid, CHAR *cdtitle);
extern INT wi_set_dialog_value(INT cdlgid, INT cditemid, INT cdvalue);
extern INT wi_set_event_mode(INT event_class, INT in_mode);
extern INT wi_set_menu_text(INT menu_id, INT item_id, CHAR *item_text);
extern INT wi_set_owner_id(INT owner_id);
extern INT wi_set_owner_tag(CHAR *owner_tag);
extern INT wi_set_selection_limit(INT cdlgid, INT cditemid, INT max_selectable);
extern INT wi_set_selections(INT cdlgid, INT cd_sel_id, INT cd_scroll_id,
    INT num_selections, INT max_selectable, TCP select_list);
extern INT wi_set_selections_obj(INT cdlgid, INT cd_sel_id, INT cd_scroll_id,
    INT num_selections, INT max_selectable, INT select_id);
extern INT wi_set_verify(INT cdlgid, INT cditemid, INT verifymode, INT length);
extern INT wi_ssst(CHAR *help_key, INT num_selections, INT max_selectable,
    TCP selections);
extern INT wi_terminate(void);
extern INT wiyesno(CHAR *prompt, CHAR *helpfil, BOOL *ifyes, INT *status);

#else

extern INT wi_activate();
extern INT wi_add_callback ();
extern INT wi_alert();
extern INT wi_alertx();
extern INT wi_assign_text_object();
extern INT wi_beep();
extern INT wi_checkid();
extern INT wi_change_owner_id();
extern INT wi_change_owner_tag();
extern INT wi_check_menu_item();
extern INT wi_clear();
extern INT wi_close_dialog();
extern INT wi_define_dialog();
extern INT wi_define_menu();
extern INT wi_define_text_object();
extern INT wi_delete_cd_line();
extern INT wi_do_help();
extern INT wi_enable_dialog();
extern INT wi_enable_dialog_item();
extern INT wi_enable_dialog_items();
extern INT wi_enable_file_menu_item();
extern INT wi_enable_keyboard();
extern INT wi_enable_menu();
extern INT wi_enable_menu_item();
extern INT wi_enable_menu_items();
extern INT wi_initialize();
extern INT wi_insert_cd_line();
extern INT wi_message();
extern INT wi_open_dialog();
extern INT wi_pop();
extern INT wi_pop_owner();
extern INT wi_push();
extern INT wi_push_owner();
extern INT wi_qedit_selection();
extern INT wi_query_dialog_changes();
extern INT wi_query_dialog_item();
extern INT wi_query_front_dialog();
extern INT wi_query_helpkey();
extern INT wi_query_input_owner_id();
extern INT wi_query_input_owner_tag();
extern INT wi_query_selections();
extern INT wi_read_define_dialog();
extern INT wi_read_define_menu();
extern INT wi_read_dialog();
extern INT wi_read_menu();
extern INT wi_release_dialog();
extern INT wi_release_menu();
extern INT wi_release_text_object();
extern INT wi_remove_callback ();
extern INT wi_request_dialog_item();
extern INT wi_request_event();
extern INT wi_request_integer();
extern INT wi_request_locate();
extern INT wi_request_selection();
extern INT wi_request_string();
extern INT wi_set_cd_clickback();
extern INT wi_set_default_sel();
extern INT wi_set_defaults();
extern INT wi_set_default_button();
extern INT wi_set_dialog_range();
extern INT wi_set_dialog_text();
extern INT wi_set_dialog_title();
extern INT wi_set_dialog_value();
extern INT wi_set_event_mode();
extern INT wi_set_menu_text();
extern INT wi_set_owner_id();
extern INT wi_set_owner_tag();
extern INT wi_set_selection_limit();
extern INT wi_set_selections();
extern INT wi_set_selections_obj();
extern INT wi_set_verify();
extern INT wi_ssst();
extern INT wi_terminate();
extern INT wiyesno();

#endif

#include "esi_wi_mac.h"
#endif
