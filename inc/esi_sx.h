/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SX.H*/
/* *5    14-SEP-1989 18:15:05 GORDON "(SPR -1) checkin from gulf"*/
/* *4     1-SEP-1989 14:41:36 CONROY "(SPR 9999) MODS FOR NEW FULL_LINE_STRUCT"*/
/* *3    11-AUG-1989 20:27:05 CONROY "(SPR 0) Install revised seismic selects & picking"*/
/* *2    25-JUL-1989 19:28:47 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    30-JUN-1989 15:04:41 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SX.H*/
/*
 * $Header: /xd3g/finder/include/RCS/esi_sx.h,v 2.0.1.2 89/08/31 15:31:51 esi Exp Locker: esi $ esi_sx.h 
 */

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

#ifndef ESI_SX_H
#define ESI_SX_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_SO_H
#include "esi_so.h"
#endif

#ifndef ESI_SE_H
#include "esi_se.h"
#endif

#ifndef ESI_BT_H
#include "esi_bt.h"
#endif

#ifndef ESI_WM_H
#include "esi_wm.h"
#endif

#define SX_RETURN return status

#define SX_AUTO      0
#define SX_MANUAL    1
#define SX_ASCEND    1
#define SX_DESCEND  -1
#define SX_NUMERIC   0
#define SX_ARBITRARY 1
#define SX_ERASE     1
#define SX_VISIBLE   2
#define SX_BLINK     3
#define SX_FIRST_LABEL 1
#define SX_LAST_LABEL  2
#define SX_BOTH_LABELS 3

typedef struct {
    SO_STRUCT *pso;                   /* seismic overlay structure */
    PROJECT_NAME project_name;        /* project name */
    BOOL new_line;                    /* if a brand new line, TRUE */
    BOOL on_map;		      /* TRUE if line already on map */
    BOOL default_filter;	      /* TRUE if user does not change filter */
    BOOL free_pso;                /* local pso or global pso flag */
    BOOL line_selected;           /* line in progress flag */
    BOOL need_to_save;            /* need to save line flag */
    DOUBLE new_line_slope;             /* set to 2 (shot = cdp * 2) */
    DOUBLE new_line_intercept;         /* set to 0 (shot = cdp * 2) + 0 */
    TREEHEAD lines;                   /* b tree of line names and segments */
    INT nlines;                  /* number of lines */
    INT nshots;                  /* number of shots */
    INT nchanges;                /* number of changes to line */
    SO_TRIGGER stash;                 /* trigger struct stash area */
    SO_TRIGGER all;                   /* used to draw all shotpoints for SLE */

    struct {
        WINDOW_ID       window;
        GROUP_ID       group;
        TNR_ID       tnr;
        GKS_INT background_color;
        } graphics;                   /* graphics information */

    struct {
        INT ls;                    
        INT sp;
        INT lp;
        } menu_id;                    /* menu ids */

    struct {                          /* cdlg ids */
        INT main;
        INT dialog_spo;
        INT dialog_sio_sym;
        INT dialog_sio_lab;
        INT dialog_sio_zval;
        INT dialog_clp_line;
        INT dialog_clp_lab;
        INT dialog_clp_1lab;
        INT dialog_line_name;
        } cdlg_id;

    struct {
        INT sio_sym_mode;
        INT sio_lab_mode;
        INT sio_zval_mode;
        } trigger;

    struct {
        INT   add_type;               /* SX_AUTO or SX_MANUAL */
        SP   start_shot;             /* starting shot point for SX_AUTO */
        SP   shot_incr;              /* shot point increment */
        INT   shot_incr_factor;       /* SX_ASCEND or SX_DESCEND */
        INT   shot_spacing_method;    /* SX_AUTO or SX_MANUAL */
        DOUBLE shot_spacing;           /* shot spacing if SX_AUTO */
        INT   shot_label_type;        /* SX_NUMERIC or SX_ARBITRARY */
        SP   current_shot;           /* number of current shot */
        }     dialog_spo;

    } SX_STRUCT ;

typedef struct {
    SX_STRUCT *psx;
    DOUBLE    angle;
    INT       paraperp;
    CDP       cdp;
    INT       menu_item;
    BOOL      first;
    } SX_CLP_STRUCT ;

#if USE_PROTOTYPES

extern INT sxz_mode(SX_STRUCT *psx, INT id, INT item);
extern INT sx_add_point(SX_STRUCT *psx, NLIST_HEADER nlist, DOUBLE x, DOUBLE y);
extern INT sx_add_point_auto(SX_STRUCT *psx, NLIST_HEADER nlist, DOUBLE x, DOUBLE y);
extern INT sx_adj_sln(SX_STRUCT *psx);
extern INT sx_auto_line_labels(SX_STRUCT *psx);
extern INT sx_auto_shot_labels(SX_STRUCT *psx);
extern INT sx_change_delete(SX_STRUCT *psx, NLIST_HEADER nlist);
extern INT sx_change_point(SX_STRUCT *psx, NLIST_HEADER nlist, NLIST_HEADER nlist_sln,
	DOUBLE x, DOUBLE y);
extern INT sx_check_dialog_item(INT id, INT item, INT message, INT data_type,
	BYTE *min, BYTE *max, BYTE *value);
extern INT sx_check_sln(SX_STRUCT *psx);
extern INT sx_clip_draw(SX_STRUCT *psx, INT ngpl, FLOAT *xarray, FLOAT *yarray);
extern INT sx_convert_cdpxy(SX_STRUCT *psx, NLIST_HEADER *converted_cdp);
extern INT sx_default_disp_opt(SO_STRUCT *pso);
extern INT sx_delete_line(SX_STRUCT *psx);
extern INT sx_delete_point(SX_STRUCT *psx, NLIST_HEADER nlist, NLIST_HEADER nlist_sln,
	DOUBLE x, DOUBLE y);
extern INT sx_dialog_clp_citerm(SX_CLP_STRUCT *pclp);
extern INT sx_dialog_clp_clterm(SX_CLP_STRUCT *pclp);
extern INT sx_dialog_clp_lsdterm(SX_CLP_STRUCT *pclp);
extern INT sx_dialog_clp_setup(SX_CLP_STRUCT *pclp, INT id);
extern INT sx_dialog_clp_srvr(INT id, INT item, SX_CLP_STRUCT *pclp);
extern INT sx_dialog_sio_read(SX_STRUCT *psx, INT id, INT type);
extern INT sx_dialog_sio_setup(SX_STRUCT *psx, INT id, BOOL updatez);
extern INT sx_dialog_sio_srvr(INT id, INT item, SX_STRUCT *psx);
extern INT sx_dialog_spo_read(SX_STRUCT *psx);
extern INT sx_dialog_spo_setup(SX_STRUCT *psx);
extern INT sx_dialog_spo_srvr(INT id, INT item, SX_STRUCT *psx);
extern INT sx_do_draw(SX_STRUCT *psx, DOUBLE x, DOUBLE y, CDP cdp, SP shot_point,
	INT mode);
extern INT sx_do_line_labels(SX_STRUCT *psx, INT mode, INT which);
extern INT sx_find_point(SX_STRUCT *psx, NLIST_HEADER nlist, DOUBLE x, DOUBLE y);
extern INT sx_graphic_picking(SX_STRUCT *psx);
extern INT sx_load_psx(SX_STRUCT *psx, INT *group_id);
extern INT sx_locate(SX_STRUCT *psx, INT *stat, FLOAT *x, FLOAT *y, INT *button);
extern INT sx_lp_menu_srvr(INT menuid, INT item, SX_STRUCT *psx);
extern INT sx_ls_menu_srvr(INT menuid, INT item,SX_STRUCT *psx);
extern INT sx_main(BYTE *byte_pointer);
extern INT sx_manual_entry(SX_STRUCT *psx);
extern INT sx_manual_entry_srvr(INT id, INT item, SX_STRUCT *psx);
extern INT sx_menu_lp_setup(SX_STRUCT *psx);
extern INT sx_menu_ls_setup(SX_STRUCT *psx);
extern INT sx_menu_sp_setup(SX_STRUCT *psx);
extern INT sx_move_point(SX_STRUCT *psx, NLIST_HEADER nlist, DOUBLE x, DOUBLE y);
extern INT sx_pick_line(SO_STRUCT *pso, DOUBLE x, DOUBLE y,
		    FULL_LINE_NAME *line_name, INT* segment_id);
extern INT sx_process_shotpoints(SX_STRUCT *psx, INT item);
extern INT sx_save_disp_opt(SX_STRUCT *psx);
extern INT sx_save_line(SX_STRUCT *psx, BOOL ifask);
extern INT sx_set_1_label_position(SX_STRUCT *psx);
extern INT sx_set_def_label_positions(SX_STRUCT *psx);
extern INT sx_set_line_label_positions(SX_STRUCT *psx);
extern INT sx_set_trigger(SX_STRUCT *psx, INT item);
extern INT sx_shutdown(SX_STRUCT *psx);
extern INT sx_special_pso(SX_STRUCT *psx);
extern INT sx_sp_from_cdp(SX_STRUCT *psx, CDP cdp, SP *fshot);
extern INT sx_sp_menu_srvr(INT menuid, INT item, SX_STRUCT *psx);
extern INT sx_zzzz(SX_STRUCT *psx);

#else

extern INT sxz_mode();
extern INT sx_add_point();
extern INT sx_add_point_auto();
extern INT sx_adj_sln();
extern INT sx_auto_line_labels();
extern INT sx_auto_shot_labels();
extern INT sx_change_delete();
extern INT sx_change_point();
extern INT sx_check_dialog_item();
extern INT sx_check_sln();
extern INT sx_clip_draw();
extern INT sx_convert_cdpxy();
extern INT sx_default_disp_opt();
extern INT sx_delete_line();
extern INT sx_delete_point();
extern INT sx_dialog_clp_citerm();
extern INT sx_dialog_clp_clterm();
extern INT sx_dialog_clp_lsdterm();
extern INT sx_dialog_clp_setup();
extern INT sx_dialog_clp_srvr();
extern INT sx_dialog_sio_read();
extern INT sx_dialog_sio_setup();
extern INT sx_dialog_sio_srvr();
extern INT sx_dialog_spo_read();
extern INT sx_dialog_spo_setup();
extern INT sx_dialog_spo_srvr();
extern INT sx_do_draw();
extern INT sx_do_line_labels();
extern INT sx_find_point();
extern INT sx_graphic_picking();
extern INT sx_load_psx();
extern INT sx_locate();
extern INT sx_lp_menu_srvr();
extern INT sx_ls_menu_srvr();
extern INT sx_main();
extern INT sx_manual_entry();
extern INT sx_manual_entry_srvr();  /* 11/17/88 SC - was absent */
extern INT sx_menu_lp_setup();
extern INT sx_menu_ls_setup();
extern INT sx_menu_sp_setup();
extern INT sx_move_point();
extern INT sx_pick_line();
extern INT sx_process_shotpoints();
extern INT sx_save_disp_opt();
extern INT sx_save_line();
extern INT sx_set_1_label_position();
extern INT sx_set_def_label_positions();
extern INT sx_set_line_label_positions();
extern INT sx_set_trigger();
extern INT sx_shutdown();
extern INT sx_special_pso();
extern INT sx_sp_from_cdp();
extern INT sx_sp_menu_srvr();
extern INT sx_zzzz();

#endif

#endif
