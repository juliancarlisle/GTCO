/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WI_INT.H*/
/* *13   15-JUL-1991 12:11:39 KEE "(SPR -1) Add Busy Cursor when execute Finder application code"*/
/* *12   28-JUN-1991 12:09:45 SANTIAGO "(SPR -1) removed wiz_color_init, setColorWithName, wiv.color"*/
/* *11   13-JUN-1991 14:53:58 KEE "(SPR -1)  Change PullDnMenu to OptionMenu and use non-conveient option menu creation method"*/
/* *10   23-OCT-1990 14:06:19 KEE "(SPR -1) Motif and DecWindow merge"*/
/* *9    14-AUG-1990 11:52:01 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *8    27-JUN-1990 17:19:25 KEE "(SPR -1) New wi data structure using 2-D array"*/
/* *7     3-MAY-1990 21:50:46 KEE "(SPR -1) menu sync stuff"*/
/* *6    15-MAR-1990 13:46:57 KEE "(SPR -1) Change idverify->text stucture to be dynamic alloc"*/
/* *5    28-FEB-1990 15:19:47 JULIAN "(SPR -1) get rid of gks_???_widget declaration (Kee)"*/
/* *4    28-FEB-1990 05:43:48 GILLESPIE "(SPR 6010) Change #ifdef USE_X #define USE_X 0 #endif to just use #ifdef USE_X"*/
/* *3     6-FEB-1990 00:24:02 JULIAN "(SPR -1) Include file for X"*/
/* *2    18-NOV-1989 09:42:08 GILLESPIE "(SPR 5075) Global overhaul"*/
/* *1    30-JUN-1989 15:05:44 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WI_INT.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Finder Graphics Systems, Inc. 1989                      */
/*         Unpublished -- All rights reserved                                       */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND   */
/*MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE  */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*          Finder Graphics Systems, Inc.                                           */
/*          201 Tamal Vista Blvd                                                    */
/*          Corte Madera, CA  USA 94925                                             */
/*          (415) 927-0100                                                          */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_WI_INT_H
#define ESI_WI_INT_H 1

/************************************************************************           */
/*                                                                                  */
/*NAME:    ESI_WI_INTERNAL.H                                                        */
/*                                                                                  */
/*AUTHOR:  Phil Burk, modified radically by Mike Haas & Bill Jaeck.                 */
/*                                                                                  */
/*    Internal Include for Workstation Interface, included by WI.CC and             */
/*    each WI module.  These definitions are only needed by the WI subsystem.       */
/*                                                                                  */
/************************************************************************           */

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_WI_H
#include "esi_wi.h"
#endif

#ifndef ESI_BT_H
#include "esi_bt.h"
#endif

#ifndef ESI_WI_MSG_H
#include "esi_wi_msg.h"
#endif

#ifndef ESI_WI_ERR_H
#include "esi_wi_err.h"
#endif

/* Define specific command types as macros                                          */

#define RETURN(status) return (status)
#define NUM_EVENT_TYPES 12
#define WI_STACK_SIZE (8 * sizeof (struct event_control) * NUM_EVENT_TYPES)

/* structures                                                                       */

typedef struct callback_struct      /* linked-list ov callback addresses:           */
    {
    INT_FUNCTION_PTR function;      /* pointer to event callback function           */
    BYTE *pointer;                  /* pointer passed to above function             */
    struct callback_struct *next;   /* pointer to NEXT element in list              */
    } CALLBACK_STRUCT;

typedef struct input_record
    {
    INT type;
    INT owner_id;
    CHAR owner_tag[ST_TAG_MAX];
    CHAR orig_tag[ST_TAG_MAX];
    CHAR helpkey[STMAX];
    CHAR owner_title[STMAX];
    CHAR orig_title[STMAX];
    INT file_menu_mask;
    INT numitems;
    } INPUT_RECORD;

#ifdef USE_X

#ifndef ESI_X_H
#include "esi_x.h"
#endif

#define ALL_EVENT_MASK    KeyPressMask | KeyReleaseMask | ButtonPressMask | \
                          ButtonReleaseMask | EnterWindowMask | \
                          LeaveWindowMask | PointerMotionMask | \
                          PointerMotionHintMask | Button1MotionMask | \
                          Button2MotionMask | Button3MotionMask | \
                          Button4MotionMask | Button5MotionMask | \
                          ButtonMotionMask | KeymapStateMask | \
                          ExposureMask | VisibilityChangeMask | \
                          StructureNotifyMask | ResizeRedirectMask | \
                          SubstructureNotifyMask | SubstructureRedirectMask | \
                          FocusChangeMask | PropertyChangeMask | \
                          ColormapChangeMask | OwnerGrabButtonMask 
        
#define MAX_ARG          32
#define BTNITEM     0
#define CHKITEM     1
#define RADIOITEM   2
#define STATTEXT    3
#define RECTITEM    4
#define EDITTEXT    5
#define SELECTOR    6
#define VSCROLL     16
#define VALUATOR    17
#define LOCKTEXT    18
#define OPTIONMENU  19
#define DIALOG      20
#define DMENU       21
#define MITEM       22
#define MSEPERATOR  23
#define RADIO_BOX   24
#define SETGROUP    -1
#define SETFONT     -2
#define SETTEXTSIZE -3
#define HELPKEY     -4
#define SETMODAL    -5
#define SMALL_P_TEXT      0
#define NORMAL_P_TEXT     1
#define SMALL_P_FONT      2
#define NORMAL_P_FONT     3
#define SMALL_C_TEXT      4
#define NORMAL_C_TEXT     5
#define SMALL_C_FONT      6
#define NORMAL_C_FONT     7
#define MAX_FONT          8

/********** X *********                                                             */
typedef struct btnitem_struct
    {
    BOOL deflt_btn;
    } WI_BTNITEM_STRUCT;

typedef struct radioitem_struct
    {
    Widget radio_box;
    } WI_RADIOITEM_STRUCT;

typedef struct edittext_struct
    {
    INT verifylen;
    INT verifymode;
    BOOL activate_flag;
    } WI_EDITTEXT_STRUCT;

typedef struct selector_struct
    {
    INT max_sel;
    INT num_sel;
    BOOL activate_flag;
    INT *sel_list;
    BOOL hscroll;
    } WI_SELECTOR_STRUCT;

typedef struct optionmenu_struct
    {
#ifdef MOTIF  /* ---------- BEGIN MOTIF BLOCK ---------- */
    Widget pull_down_shell;
#endif  /* ---------- END MOTIF BLOCK ---------- */
    Widget pull_down_menu;
    Widget *menu_button;
    TCP tcp;
    INT xmin;
    INT ymin;
    INT item_chosen;
    } WI_OPTIONMENU_STRUCT;

typedef struct dialog_struct
    {
    Widget popup_icon;
    BOOL clickback_flag;            /* for wi_set_cd_clickback                      */
    } WI_DIALOG_STRUCT;

typedef struct menu_struct
    {
#ifdef MOTIF  /* ---------- BEGIN MOTIF BLOCK ---------- */
    Widget pull_down_shell;
#endif  /* ---------- END MOTIF BLOCK ---------- */
    Widget pull_down_menu;
    INT if_static;
    INT if_main;
    } WI_MENU_STRUCT;

typedef struct mitem_struct
    {
    BOOL enable_flag;
    BOOL check_onoff;
    Widget menu_toggle_button;
    } WI_MITEM_STRUCT;

typedef struct widget_item_info_struct
    {
    INT type_id;
    INT group;
    CHAR *text;
    Widget widget;
    union union_tag
        {
        WI_BTNITEM_STRUCT btnitem;
        WI_RADIOITEM_STRUCT radioitem;
        WI_EDITTEXT_STRUCT edittext;
        WI_SELECTOR_STRUCT selector;
        WI_OPTIONMENU_STRUCT optionmenu;
        WI_DIALOG_STRUCT dialog;
        WI_MENU_STRUCT menu;
        WI_MITEM_STRUCT mitem;
        } item_type;
    } WIDGET_ITEM_INFO;

typedef struct dialog_menu_struct
    {
    INT (*server)();
    VOIDPTR pointer;
    INT app_id;                     /* applicataion id                              */
    INT wi_push_pop_num;            /* for keep track of fi_push/wi_push and        */
                                    /* fi_pop/wi_pop stack number                   */
    INT num_items;                  /* number of items in the dialog/menu           */
    WIDGET_ITEM_INFO *items;        /* pointer to item array                        */
    } DIALOG_MENU;

typedef struct menu_syn_item_struct
    {
    INT id;
    BOOL onoroff;
    struct menu_syn_item_struct *next;
    } MENU_SYN_ITEM_LIST;

typedef struct menu_syn_struct
    {
    MENU_SYN_ITEM_LIST *item_list;
    INT app_id;
    struct menu_syn_struct *next;
    } MENU_SYN_LIST;

/* various "code generating" macros                                                 */

#else       /* ESITERM code */

/* ---- Defines ----------------------------------------                            */
/* A version number of 4000 corresponds to version 4.000                            */
/* this is equal to the current lowest version for complete compatibility           */
#define MAC_VERSION (INT)4020
#define DEBUG FALSE         /* debugging compilation flag */
#define MAX_BAD_RESPONSES (INT)3
#define ABORT_RESPONSE (INT)-999
#define MACON '\002'
#define MACOFF '\003'
#define MACON_DBG '$'
#define MACOFF_DBG '#'
#define BLANK ' '
#define T extern

/* Define output commands for MAC ---------------------------------                 */
/*   The protocol to the Mac is based on a Reverse Polish Syntax.                   */
/*   Values are put on the stack in the MAC, then used by the                       */
/*   MAC to execute the command given.  The stack should always be                  */
/*   restored at the end of the command line to avoid interfering                   */
/*   with the NEON program.                                                         */
/*                                                                                  */
#define MC_INIT (INT)0
#define MC_QUERY_VERSION (INT)1
#define MC_TERM (INT)2

/* Menu Commands                                                                    */
#define MC_DEFINE_MN (INT)10
#define MC_DEFINE_MI (INT)11
#define MC_SELECT_MN (INT)12
#define MC_SELECT_MI (INT)13
#define MC_CHECK_MI  (INT)14
#define MC_SELECT_MA (INT)15
#define MC_CHECK_MA  (INT)16
#define MC_REQUEST_MN (INT)17
#define MC_SET_MM    (INT)18
#define MC_SET_MT    (INT)19
#define MC_RELEASE_MN (INT)20
#define MC_SET_MENU_TEXT (INT)21

/* Custom Dialog Commands ( in their approximate order to be used in )              */
#define MC_DEFINE_CD (INT)30
#define MC_SET_GR    (INT)32
#define MC_DEFINE_CI (INT)31
#define MC_OPEN_CD   (INT)33
#define MC_SET_CD_TEXT (INT)34
#define MC_SET_CD_VALUE (INT)35
#define MC_SET_CD_RANGE (INT)36
#define MC_ENABLE_CI (INT)37
#define MC_REQUEST_CD (INT)38
#define MC_CLOSE_CD  (INT)39
#define MC_RELEASE_CD (INT)40
#define MC_ENABLE_CD (INT)41
#define MC_QUERY_CURRENT_CI (INT)42
#define MC_DAMAGE_REPORT_CD (INT)43
#define MC_SET_FONT         (INT)44
#define MC_SET_TEXTSIZE     (INT)45
#define MC_SET_MAXSELECT    (INT)46
#define MC_QUERY_SELECTIONS (INT)47
#define MC_SET_CD_TITLE     (INT)48
#define MC_REQUEST_CD_HIT   (INT)49
#define MC_QUERY_FRONT_CD   (INT)50
#define MC_SET_DEFAULT_SEL  (INT)51
#define MC_INSERT_LINE      (INT)52
#define MC_DELETE_LINE      (INT)53
#define MC_SET_OWNER_ID     (INT)54
#define MC_CHANGE_OWNER     (INT)55
#define MC_SET_FILE_MENU    (INT)56
#define MC_CLEAR            (INT)57
#define MC_SET_MODAL        (INT)58
#define MC_ACTIVATE         (INT)59
#define MC_PUSH             (INT)60
#define MC_POP              (INT)61
#define MC_ENABLE_KEYBOARD  (INT)62
#define MC_REQUEST_YESNO    (INT)63
#define MC_PUSH_OWNER       (INT)64
#define MC_POP_OWNER        (INT)65
#define MC_SET_CLICKBACK    (INT)66
#define MC_QSELTEXT         (INT)67
#define MC_QEDIT_FIELD      (INT)68
#define MC_INSERT_TEXT      (INT)70
#define MC_HIGHLIGHT        (INT)71
#define MC_REPLACE_TEXT     (INT)72   /* not implemented... add to WI */
#define MC_SET_VERIFY       (INT)73
#define MC_SET_DEFAULTS     (INT)74
#define MC_ALERTX           (INT)75
#define MC_SHUTUP           (INT)76   /* be quiet for J/P */

/* Miscellaneous Commands                                                           */
#define MC_SET_PROMPT     (INT)5
#define MC_SET_DEFAULT    (INT)6
#define MC_REQUEST_ST     (INT)7
#define MC_BEEP           (INT)8
#define MC_ALERT          (INT)9

/* Define completion codes that are returned from MAC                               */
#define CANCEL_CODE (INT)0
#define HELP_CODE (INT)1
#define ERROR_CODE (INT)2
#define OK_CODE    (INT)3

/* These are the event completion codes as returned from the MAC.                   */
#define RQST_CODE (INT)10
#define QSEL_CODE (INT)11
#define ALERT_CODE (INT)12
#define RQMN_CODE (INT)13
#define RQWS_CODE (INT)14
#define RQCD_CODE (INT)15
#define DRCD_CODE (INT)16
#define RQVR_CODE (INT)17
#define FMEN_CODE (INT)19

/* Send special strings to MAC.                                                     */
#define SEND_PROMPT(str)  wiz_string_op(str,MC_SET_PROMPT)
#define SEND_DEFAULT(str) wiz_string_op(str,MC_SET_DEFAULT)
#define SEND_LINEOUT(str) wiz_puts(str); wiz_puts("\r\n")
#define G_LINEIN(str)     wiz_gets(str)
#define WAIT_RESPONSE(dr) wiz_wait_resp(IDENT, dr)
#define SEND_1_VALUE(v1) { sprintf(wiv.stl, "%d", v1); \
            wiz_scom(wiv.stl); }
#define SEND_2_VALUES(v1,v2) { sprintf(wiv.stl, "%d %d", v1,v2); \
            wiz_scom(wiv.stl); }
        
#define SEND_3_VALUES(v1,v2,v3) { sprintf(wiv.stl, "%d %d %d", v1,v2,v3); \
            wiz_scom(wiv.stl); }

#define SEND_4_VALUES(v1,v2,v3,v4) { sprintf(wiv.stl, "%d %d %d %d", v1,v2,v3,v4); \
            wiz_scom(wiv.stl); }

#define SEND_5_VALUES(v1,v2,v3,v4,v5) { sprintf(wiv.stl, "%d %d %d %d %d", \
            v1,v2,v3,v4,v5); \
            wiz_scom(wiv.stl); }

#define SEND_6_VALUES(v1,v2,v3,v4,v5,v6) { sprintf(wiv.stl, "%d %d %d %d %d %d", \
            v1,v2,v3,v4,v5,v6); \
            wiz_scom(wiv.stl); }

#define SEND_1OPCODE(op) SEND_1_VALUE(op)

#endif

/* macros for Error Checking.                                                       */
#define E_CHECK_INIT { \
    if (wiv.ifwiinit == FALSE) { \
     RETURN(WI_NOT_INITIALIZED); \
     } \
    }

#define E_CHECK_SLEN(s) { \
    if(strlen(s)==0) { \
     RETURN(WI_EMPTY_STRING); \
     } \
    }

#define E_CHECK_COUNT(n) { \
    if(n <= 0) { \
     RETURN(WI_BAD_COUNT); \
     } \
    }
#define E_CHECK_DIALOGITEM(i) { \
    if (((i) <1) || ((i) > MAX_CD_ITEMS)) { \
     RETURN(WI_TOO_MANY_CDI); \
     } \
    }


/* NOTE: usage of this macro requires that function returns INT STATUS.             */
#define E_CHECK_ID(unitid,itemid,typecode)  { \
    if ((status=wi_checkid(unitid,itemid,typecode)) != SUCCESS)  { \
       RETURN(status); \
    } \
}


#ifdef USE_X

#define E_CHECK_WIDGET(id,itemid)  { \
    if ((status=wiz_checkwidget(id,itemid)) != SUCCESS) { \
       RETURN(status); \
    } \
}

#define E_WIZ_ERROR(string,pname)  { \
       wiz_error(string,pname); { \
       RETURN(FAIL); \
    } \
}

#define E_DIALOG_MENU(id) (wiv.dialog_menu+id)
#define E_WIDGET_INFO(id,itemid) (((wiv.dialog_menu+id)->items)+itemid)
#define E_GET_WIDGET(id,itemid) (((wiv.dialog_menu+id)->items)+itemid)->widget

#endif

#define CHECK_JMODE if (wiv.jpmode != WI_JOURNAL) {  \
              return(WI_BAD_JPMODE);  \
            }

#define CHECK_PMODE if (wiv.jpmode != WI_PLAYBACK) {  \
              return(WI_BAD_JPMODE);  \
            }

#define CHECK_JPMODE if ((wiv.jpmode != WI_JOURNAL) && \
             (wiv.jpmode != WI_PLAYBACK)) {  \
              return(WI_BAD_JPMODE);  \
            }

#define OUTPUT_ENABLED ((wiv.jpmode != WI_PLAYBACK) || (wiv.playback_nosend == 0))
#define NO_JP  ((wiv.jpmode != WI_JOURNAL) && (wiv.jpmode != WI_PLAYBACK))

/* function declarations                                                            */

typedef struct wiv_struct
    {
    BOOL ifwiinit;                  /* Is WI system initialized?                    */
    BOOL if_shared_channel;
    INT terminal_io_channel;        /* channel number assigned for ESITERM          */
    INT ittype;                     /* Terminal Type                                */
    INT igtype;                     /* GKS Workstation Type                         */
    INT graphics_io_channel;
    INT stock_select_cdlgid;
    INT iwkid;                      /* GKS Workstation ID                           */
    INT if_gks_on;
    INT in_receive_mode;            /* flag for I or O mode, controls ACK           */
    CHAR macon;
    CHAR macoff;
    CHAR terminal_type[10];         /* terminal type, from TERMINAL_CONFIGURATION   */
    CHAR port_name[10];             /* device/port name (e.g. TXA2)                 */
    INT terminal_setting[3];        /* initial terminal settings (VMS)              */
    CHAR mn[3];
    CHAR stl[ST_COMMAND_MAX];       /* String for MACROS to use.                    */
    struct 
        {
        INT modal_state;
        INT owner_id;               /* Owner of Menu or Dialog                      */
        CHAR owner_tag[STMAX];      /* Tag for owner.                               */
        CHAR rsrc_helpkey[STMAX];   /* for resource file defining                   */
        } current;
    struct 
        {
        INT cdlgid;
        INT cditemid;
        INT cdvalue;
        CHAR cdtext[STMAX];
        } hold;
    TREEHEAD input_tree;            /* Tree for storing data associated with MDs    */
    /* Data structures for pushing and popping of internal state information.       */
    /*   The input modes must be saved in case someone does event driven input      */
    /*   from a subapplication.                                                     */
    /*                                                                              */
    struct event_control
        {
        INT event_code;             /* Identifying code from MAC                    */
        INT mode;                   /* REQUEST, SAMPLE, or EVENT                    */
        } event[NUM_EVENT_TYPES];
    INT wi_stack_pointer;
    INT wi_stack[WI_STACK_SIZE];
    /* journal/playback support...                                                  */
    FILE *jfile;                    /* specifies the open journal file              */
    FILENAME jfilename;             /* the original name, set by AM?                */
    INT jpmode;                     /* should be JOURNAL or PLAYBACK, set by AM     */
    CHAR jpstring[ST_MAC_MAX];      /* buffer for file access                       */
    INT jparsed;                    /* counter within the string                    */
    INT playback_nosend;            /* if zero, send stuff in playback mode         */
    INT playback_eatrcv;            /* if non-zero, eat stuff from mac              */
    
    CALLBACK_STRUCT *callback_list;

#ifdef USE_X
    DIALOG_MENU *dialog_menu;
    TCP text_list;
    MENU_SYN_LIST *menu_syn_listroot;
    
    Display *current_Display;
    
    Widget toplevel;
    Widget mainw;
    Widget mainmenubar;
    Widget *main_dialog_menu;
    INT num_main_dialog_menu;
    
    INT dialog_menu_count;
    INT text_id_count;
    INT frontdialog_id;
    INT wi_push_pop_top;
#ifdef MOTIF  /* ---------- BEGIN MOTIF BLOCK ---------- */
    XmFontList Fontlist[MAX_FONT];
#else  /* ---------- END MOTIF BLOCK - BEGIN DECW BLOCK ---------- */
    DwtFontList Fontlist[MAX_FONT];
    Window Decterm_win;
    INT Decterm_win_revert_to;
#endif  /* ---------- END DECW BLOCK ---------- */
#endif
    } WIV_STRUCT;

#if USE_PROTOTYPES
extern INT dt_wi_return (void);
extern WIV_STRUCT *wiz_static (void);
extern INT wiz_gnum (INT *num);
extern INT wiz_wait_resp (CHAR *caller_name, INT desired_response);
extern INT wiz_gstr (INT lenresp, CHAR *stresp);
extern INT wiz_scom (CHAR *str);
extern INT wiz_gets (CHAR *str);
extern INT wiz_set_echo (INT);
extern INT wiz_acknowledge (void);
extern INT wiz_puts (CHAR *str);
extern INT wiz_long_string (INT dest_char, CHAR *str);
extern INT wiz_string_op (CHAR *str, INT opcode);
extern INT wiz_remove_cr (CHAR *str);
extern INT wiz_wait_event (INT *event_class_ptr, INT *object_id_ptr, INT *item_id_ptr);
extern INT wiz_check_trapped (INT event_class, INT id, INT item_id);
extern INT wiz_push_int (INT ival);
extern INT wiz_pop_int (void);
extern INT wiz_push_many_int (INT numint, INT *ival_ptr);
extern INT wiz_pop_many_int (INT numint, INT *ival_ptr);
extern INT wiz_prepend_tag_id (CHAR *cdtitle, CHAR *owner_tag, INT owner_id,
                               CHAR *new_title);
extern INT wiz_restore_terminal (INT);

/* journal/playback routines                                                        */
extern INT wiz_jp_initialize (void);
extern INT wiz_jp_terminate (void);
extern INT wiz_jp_write_string (CHAR *string);
extern INT wiz_jp_read_line (void);
extern INT wiz_jp_name (CHAR *name);
extern INT wiz_jp_write_long (LONG thelong);
extern INT wiz_jp_read_long (LONG *thelong);
extern INT wiz_jp_write_float (DOUBLE thefloat);
extern INT wiz_jp_read_float (FLOAT *thefloat);
extern INT wiz_jp_add_text (CHAR *string);

#ifdef USE_X
extern INT wiz_stattext_sensitive_false (INT cdlgid);
extern INT wiz_delete_widget (INT dialog_menu_id);
extern INT wiz_managechild_widget (INT dialog_menu_id);
extern INT wiz_unmanagechild_widget (INT dialog_menu_id);
extern INT wiz_ins_menu_syn_list (INT app_id, INT menuid);
extern INT wiz_del_menu_syn_list (INT app_id);
extern INT wiz_menu_syn (INT cur_app_id);
extern INT wi_callback (Widget widget, INT tag, VOIDPTR *callback_data);
extern INT wiz_set_scrollbar (INT cdlgid, INT cditemid);
extern INT wiz_get_event_info (INT *cdlgid, INT *cditemid, INT *eventclass);
extern INT wiz_clear_event_info (void);
extern INT wiz_get_group_range (INT cdlgid, INT cditemid, INT *rmin, INT *rmax);
extern INT wiz_set_selector_text (INT cdlgid, INT cditemid, CHAR *strings);
extern INT wiz_checkwidget (INT cdlgid, INT cditemid);
extern VOID wiz_error (CHAR *string, CHAR *pname);
extern INT wiz_XFlush ();
extern INT wiz_busy_cursor (BOOL onoroff);
extern INT wi_create_option_menu (INT cdlgid, INT itemid, TCP tcp);

#ifdef MOTIF  /* ---------- BEGIN MOTIF BLOCK ---------- */
extern INT wiz_text_to_cslist (CHAR *strings, XmString **list_items, INT *l);
extern CHAR *wiz_ascii_from_cmp (XmString value);
#else  /* ---------- END MOTIF BLOCK - BEGIN DECW BLOCK ---------- */
extern INT wiz_text_to_cslist (CHAR *strings, DwtCompString **list_items, INT *l,
                               Dimension listbox_width);
extern CHAR *wiz_ascii_from_cmp (DwtCompString value);
extern DwtCompString wiz_DwtLatin1StringSpecial (CHAR *str, Dimension listbox_width);
#endif  /* ---------- END DECW BLOCK ---------- */
#endif      /* USE_X */

#else       /* no prototypes */
extern INT dt_wi_return ();

extern WIV_STRUCT *wiz_static ();

extern INT wiz_gnum ();
extern INT wiz_wait_resp ();
extern INT wiz_gstr ();
extern INT wiz_scom ();
extern INT wiz_gets ();
extern INT wiz_puts ();
extern INT wiz_long_string ();
extern INT wiz_string_op ();
extern INT wiz_remove_cr ();
extern INT wiz_wait_event ();
extern INT wiz_check_trapped ();
extern INT wiz_push_int ();
extern INT wiz_pop_int ();
extern INT wiz_push_many_int ();
extern INT wiz_pop_many_int ();
extern INT wiz_prepend_tag_id ();

/* journal/playback routines                                                        */
extern INT wiz_jp_initialize ();
extern INT wiz_jp_terminate ();
extern INT wiz_jp_write_string ();
extern INT wiz_jp_read_line ();
extern INT wiz_jp_name ();
extern INT wiz_jp_write_long ();
extern INT wiz_jp_read_long ();
extern INT wiz_jp_write_float ();
extern INT wiz_jp_read_float ();
extern INT wiz_jp_add_text ();

#ifdef USE_X
extern INT wiz_stattext_sensitive_false ();
extern INT wiz_del_widget ();
extern INT wiz_managechild_widget ();
extern INT wiz_unmanagechild_widget ();
extern INT wiz_ins_menu_syn_list ();
extern INT wiz_del_menu_syn_list ();
extern INT wiz_menu_syn ();
extern INT wi_callback ();
extern INT wiz_set_scrollbar ();
extern INT wiz_get_event_info ();
extern INT wiz_clear_event_info ();
extern INT wiz_get_group_range ();
extern INT wiz_set_selector_text ();
extern INT wiz_checkwidget ();
extern VOID wiz_error ();
extern INT wiz_XFlush ();
extern INT wiz_busy_cursor ();
extern INT wi_create_option_menu ();
extern INT wiz_text_to_cslist ();
extern CHAR *wiz_ascii_from_cmp ();
#ifndef MOTIF  /* ---------- BEGIN DECW BLOCK ---------- */
extern DwtCompString wiz_DwtLatin1StringSpecial ();
#endif  /* ---------- END DECW BLOCK ---------- */
#endif      /* USE_X */
#endif      /* of USE_PROTOTYPES */
#endif
