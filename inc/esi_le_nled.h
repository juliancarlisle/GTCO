/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LE_NLED.H*/
/* *6    14-AUG-1990 11:48:38 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *5     4-MAR-1990 04:20:49 JULIAN "(SPR 6010) Fixed alignment of LE_KEY struct"*/
/* *4    26-FEB-1990 19:07:14 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *3    26-JAN-1990 09:15:19 ADEY "(SPR -1) fix keymap_first for use_keymap & init_dialog"*/
/* *2    22-JAN-1990 11:53:31 ADEY "(SPR -1) fix keymap_first to use_keymap & init_dialog"*/
/* *1    30-JUN-1989 15:02:07 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LE_NLED.H*/

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


/*   definition of all the servers called in the n_list_editor */
#ifndef ESI_LE_NLED_H
#define ESI_LE_NLED_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_WM_H
#include "esi_wm.h"
#endif

/*
    definitions of the integer values of the key_function associated
    with each nlist editor server
                                                                  */
#define BUTTON_UNDEFINED       (INT)-1
#define BUTTON_EXTEND_STROKE    (INT)1
#define BUTTON_START_STROKE     (INT)2
#define BUTTON_REPLACE_STROKE   (INT)3
#define BUTTON_DELETE_POINT     (INT)4
#define BUTTON_SELECT_STROKE    (INT)5
#define BUTTON_JOIN_STROKE      (INT)6
#define BUTTON_SET_PARAM        (INT)7
#define BUTTON_ADD_MONO         (INT)8
#define BUTTON_CLEAVE_STROKE    (INT)9
#define BUTTON_ZOOMIN          (INT)10
#define BUTTON_PAN             (INT)11
#define BUTTON_CANCEL          (INT)12
#define BUTTON_DONE            (INT)13
#define BUTTON_ZOOMOUT         (INT)14
#define BUTTON_RESET           (INT)15
#define BUTTON_ADD_POINT       (INT)16
#define BUTTON_BACK_POINT      (INT)17
#define BUTTON_NOOP            (INT)18
#define BUTTON_DELETE_STROKE   (INT)19
#define BUTTON_GOLD_KEY        (INT)20
#define BUTTON_UNDO            (INT)21
#define BUTTON_MOVE_POINT      (INT)22
#define BUTTON_APP_DIAL        (INT)23
#define BUTTON_HILIGHT_PTS     (INT)24
#define BUTTON_ERASE_PTS       (INT)25
#define BUTTON_BREAK_STROKE    (INT)26
#define BUTTON_REDRAW          (INT)27

#define LE_STROKE_MODE 0X5151
#define LE_POINT_MODE  0X1515

/*  initialization of the function table containing all the servers
    which can be called in the nlist_editor                          */

#define MAX_KEYS 16      /* number of keys on the puck */

#define LE_KEYS struct le_key_struct
LE_KEYS {
    INT operation;               /* operation code parameter */
    INT_FUNCTION_PTR key_function; /* address of function to be executed */
    CHAR description[32];        /* text description of function */
    BOOL validt;                 /* switch to show validity of function */
    INT index;                   /* keymap index number */
    INT button;                  /* button number assigned */
    BOOL save_state;             /* TRUE if this function 'undo-able' */
    } ;

typedef LE_KEYS LE_KEYMAP[MAX_KEYS];

/*    Definition of the control structure which is passed to each
       of the servers called by the nlist_editor.
       Each server takes its informations in this structure and
       returns information to nlist-editor
                                                             */
typedef struct le_control_struct {
    UINT  current_point;        /* scratch variable used in operations as replace and cleave */
    UINT  current_stroke;       /* scratch variable used in operations as replace and cleave */
    INT  current_operation;    /* current  stroke operation which is performed */
    UINT  last_point;           /* scratch variable used in operations as replace and cleave */
    UINT  last_stroke;          /* scratch variable used in operations as replace and cleave */
    INT  last_operation;       /* last operation performed in stroke mode */
    LINE_ATTRIBUTE erase_attribute ;   /* structure giving parameters for
                                          GKS when drawing a line in erase color */
    LINE_ATTRIBUTE hilight_attribute ; /* structure giving parameters for
                                          GKS when drawing a line in erase color */
    LINE_ATTRIBUTE draw_attribute ;    /* structure giving parameters for
                                          GKS when drawing a line in erase color */
    INT  end_point_mark;       /* symbol highlighting a point  ( not used )*/
    UINT  scratch_str1;         /* scratch stroke used when digitizing in point mode */
    UINT  curpoint_str1;        /* scratch variable used in operations as replace and cleave */
    INT  stat;                 /* status returned by rqbutxy when a key is pressed */
    INT  but;                  /* button number returned by rqbutxy when key pressed */
    INT  nbp;                  /* used for rqbutxy : nbp = 0  means we want the locator */
                               /* nbp = 1   means  we want the rubberband linked to  */
                               /*  lastx  , lasty */
    BOOL reverse ;             /* used for replace stroke option
                                = TRUE if we need to reverse stroke 
                                = FALSE if nothing to reverse */
    BOOL stroke_mode;          /* TRUE = stroke mode ; FALSE = point mode */
    BOOL last_mode;            /*        "                 "       */
    BOOL end_edit;             /* TRUE =  end of the editor  ; FALSE =  still busy*/
    BOOL use_keym;             /* TRUE if we use the keymap with its image on a dialog  */
                               /*  FALSE  if we use another mean  of performing function  */
                               /* provided by the application calling the editor    */
    BOOL dial_update ;         /* TRUE if the keymap has been change and we need to change
                                custom dialog   ; FALSE if nothing to do on dialog */
    BOOL default_puck_map ;    /* TRUE if we display on the mac the default map of the
                                  keys of the current active keymap
                                 FALSE  if we display the app provided puck map */
    BOOL key_swap ;            /* TRUE if the application wants an automatic swapping
                                  of the keys add_point and start_stroke on the point keymap */
                               /*FALSE no automatic swapping of the keys */
    BOOL only_app_mac_dialog ; /* TRUE if the in the editor we don't need the o
                                   default mac dialog representing the keys so we dont need to define
                                   this dialogs
                                   FALSE if we need the default dialogs representing the puck_key */
    INT index_stroke_keym ;    /* index of the current stroke keymap  */
    INT index_point_keym ;     /* index of current point keymap    */
    LE_KEYS *stroke_keymap;    /* ptr to first key structure in stroke keymaps */
    LE_KEYS *point_keymap;     /* ptr to first key structure in point keymaps */
    INT num_stroke_keymaps ;   /* total number of stroke keymaps used by te editorr*/
    INT num_point_keymaps ;    /* total number of point keymaps used by te editorr*/
    FLOAT wx;                  /* current x coord returned on last puck key oper */
    FLOAT wy;                  /* current  y coord returned on last puck key oper */
    FLOAT wz;                  /* scratch coord  */
    FLOAT lastx;               /* last x coord used for rubberbanding */
    FLOAT lasty;               /* last y coord used for rubberbanding */
    FLOAT lastz;               /* scratch  coordinates      */
    WINDOW_ID window_id;       /* window ID of current window */
    TNR_ID transform_id;       /* transform ID */
    DOUBLE minx;               /* minimum WCS x value in current window */
    DOUBLE maxx;               /* maximum WCS x value in current window */
    DOUBLE miny;               /* minimum WCS y value in current window */
    DOUBLE maxy;               /* maximum WCS y value in current window */
    NLIST_HEADER nlist;        /* the n_list  we are working on   */
    BYTE *data_pointer;        /* pointer to user-defined data structure
                                  (copied from LE_PARLIST structure */
    LE_KEYS *pKey;             /* pointer to structure describing  key hit in main loop
                                  of the editor    */
    } LE_CONTROL ;


/*   definition of the structure used by the application calling the line editor */
/*   structure used to pass input parameters to n_list editor  */

typedef struct le_parlist_struct {
     INT  status ;             /* status  returned by le_nlist_editor  SUCCESS ifg  normal exit
                                       FAIL  if the editor was canceled */
     LINE_ATTRIBUTE line;      /* Standard line drawing attributes */
     COLOR_INDEX  hilight_color ;      /* color to hilight strokes    */
     COLOR_INDEX  erase_color ;        /* color to erase strokes      */
     BYTE *data_pointer ;      /* Application data structure pointer */ 
     BOOL initkeymap;	       /* NOT USED */
     BOOL init_dialog;         /* TRUE  if there are some dialog initialization to perform
                                  FALSE if no     */
     BOOL use_keymap;          /* TRUE if the application wants to use the keymap
                                    for its first operation '
                                  FALSE if the application wants to use first
                                   its own dialogs    */
     BOOL key_swap ;           /* TRUE if the application wants an automatic swapping
                                  of the keys add_point and start_stroke on the point keymap */
                                /* FALSE if no automatic swapping of the keys */
     BOOL only_app_mac_dialog ; /* TRUE if the in the editor we don't need the o
                                   default mac dialog representing the keys so we dont need to define
                                   this dialogs
                                   FALSE  if we need the default dialogs representing the puck_key */
     INT_FUNCTION_PTR zz_init_dial ;   /* pointer to an application function used to
                                  initialize dialogs different from keymaps   */
     INT_FUNCTION_PTR zz_dial_oper;   /* pointer to an application function replacing
                                  the puck key to provide a function key to the
                                  editor   */
     INT_FUNCTION_PTR zz_dial_release; /* pointer to an application function used to
                                  release the dialogs defined by the application */
     INT_FUNCTION_PTR app_puck_map_disp_init; /* pointer to an application function which is
                                          initialising and opening a dialog which will be
                                          replacing the default puck_key map display */
     NLIST_HEADER nlist;       /* pointer to the n_list to edit */
     LE_KEYS *point_keymap ;   /* pointer to application point keymap */
     INT num_point_keymaps ;   /* number of point keymaps defined by the application */
     LE_KEYS *stroke_keymap;   /* pointer to application stroke keymap */
     INT num_stroke_keymaps;   /* number of stroke keymaps defined by the application */
     CHAR title[64];           /* title bar text for keymap */
     INT mouse_input;	       /* default picking/digitizing input device. */
    } LE_PARLIST ;

#if USE_PROTOTYPES

extern INT le_nlist_editor(LE_PARLIST *ppar) ;

                                          /* keymap utilities */
extern INT le_allocate_keymap(LE_KEYS **pkeymap, INT mode, INT nmaps);
extern INT le_set_key(LE_KEYS *keymap, INT indx, INT button, INT operation,
		INT (*pfunc)(), CHAR text[32], BOOL save_state);
extern INT le_enable_key(LE_KEYS *keymap, INT indx, INT button, BOOL onoff);
extern LE_KEYS *le_scan_keymap(LE_KEYS *keymap, INT nmaps, INT operation);

                                          /* pre-defined editor functions */
extern INT le_add_point(LE_CONTROL *pctrl);
extern INT le_add_point_mono(LE_CONTROL *pctrl);
extern INT le_back_point(LE_CONTROL *pctrl);
extern INT le_cancel(LE_CONTROL *pctrl);
extern INT le_cleave_stroke(LE_CONTROL *pctrl);
extern INT le_delete_stroke(LE_CONTROL *pctrl);
extern INT le_done(LE_CONTROL *pctrl);
extern INT le_erase_pts (LE_CONTROL *pctrl) ;
extern INT le_extend_stroke(LE_CONTROL *pctrl);
extern INT le_gold_key (LE_CONTROL *pctrl) ;
extern INT le_hilight_pts(LE_CONTROL *pctrl) ;
extern INT le_join_stroke(LE_CONTROL *pctrl);
extern INT le_move_point (LE_CONTROL *pctrl) ;
extern INT le_nooperation (LE_CONTROL *pctrl) ;
extern INT le_pan(LE_CONTROL *pctrl);
extern INT le_replace_stroke(LE_CONTROL *pctrl);
extern INT le_reset(LE_CONTROL *pctrl);
extern INT le_select_stroke(LE_CONTROL *pctrl);
extern INT le_set_param(LE_CONTROL *pctrl);
extern INT le_start_stroke(LE_CONTROL *pctrl);
extern INT le_start_stroke_pt_mode(LE_CONTROL *pctrl);
extern INT le_undefined(LE_CONTROL *pctrl);
extern INT le_zoomin(LE_CONTROL *pctrl);
extern INT le_zoomout(LE_CONTROL *pctrl);

#else

extern INT le_nlist_editor() ;

                                          /* keymap utilities */
extern INT le_allocate_keymap();
extern INT le_set_key();
extern INT le_enable_key();
extern LE_KEYS *le_scan_keymap();

                                          /* pre-defined editor functions */
extern INT le_add_point();
extern INT le_add_point_mono();
extern INT le_back_point();
extern INT le_cancel();
extern INT le_cleave_stroke();
extern INT le_delete_stroke();
extern INT le_done();
extern INT le_erase_pts () ;
extern INT le_extend_stroke();
extern INT le_gold_key () ;
extern INT le_hilight_pts() ;
extern INT le_join_stroke();
extern INT le_move_point () ;
extern INT le_nooperation () ;
extern INT le_pan();
extern INT le_replace_stroke();
extern INT le_reset();
extern INT le_select_stroke();
extern INT le_set_param();
extern INT le_start_stroke();
extern INT le_start_stroke_pt_mode();
extern INT le_undefined();
extern INT le_zoomin();
extern INT le_zoomout();

#endif

#endif
