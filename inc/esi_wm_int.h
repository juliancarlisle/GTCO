/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WM_INT.H*/
/* *15    3-MAY-1991 16:22:01 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *14   30-OCT-1990 11:33:32 KEE "(SPR -1) Fix compile noise at sun"*/
/* *13   23-OCT-1990 14:06:53 KEE "(SPR -1) Motif and DecWindow merge"*/
/* *12   14-AUG-1990 11:52:21 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *11   30-JUN-1990 23:17:09 GILLESPIE "(SPR 1) Remove reduntant function defs - correct some prototypes, omissions"*/
/* *10   28-JUN-1990 15:41:27 KEE "(SPR -1) Add menu_item under GKS_WIDGET_STRUCT "*/
/* *9    21-MAY-1990 16:42:51 KEE "(SPR -1) add wmz_inq_wk_wins and wm_wkid_to_window function prototype"*/
/* *8    21-MAY-1990 16:21:37 KEE "(SPR -1) Remove some elements in GKS_ARRAY"*/
/* *7    21-MAY-1990 12:31:20 KEE "(SPR -1) Change GKS_ARRAY"*/
/* *6    14-MAY-1990 14:33:04 SCD "(SPR 1) Add member window to GKS_WIDGET_STRUCT"*/
/* *5     3-MAY-1990 21:51:22 KEE "(SPR -1) multi window support"*/
/* *4     4-MAR-1990 10:25:18 JULIAN "(SPR 6010) Fix ultrix compile errors. "*/
/* *3     1-MAR-1990 14:26:06 JULIAN "(SPR 6010) removed references to Widget for non-X code"*/
/* *2    28-FEB-1990 15:43:05 JULIAN "(SPR -1) Add elements to WM_CURRENT struct, change MAIN_WKID & GKS_WISS_WKID def (kee)"*/
/* *1    30-JUN-1989 15:06:04 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WM_INT.H*/
/******************************************************************************     */
/*                                                                                  */
/*        Copyright Exploration Systems, Inc. 1989                                  */
/*           Unpublished -- All rights reserved                                     */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY   */
/*CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE      */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*            Exploration Systems, Inc.                                             */
/*            579 Market Street                                                     */
/*            San Francisco, CA  USA 94105                                          */
/*            (415) 974-1600                                                        */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_WM_INT_H
#define ESI_WM_INT_H 1

#ifndef ESI_WM_H
#include "esi_wm.h"
#endif

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_PR_H
#include "esi_pr.h"
#endif

#ifndef ESI_TG_MAT_H
#include "esi_tg_mat.h"
#endif

#ifndef ESI_BT_H
#include "esi_bt.h"
#endif

#ifdef USE_X
#ifndef ESI_X_H
#include "esi_x.h"

#endif

#ifndef PRIOR_GKS  /* ========== BEGIN DEC GKS ========== */
#ifndef $DESCRIPTOR
#ifndef DESCRIP_H_DEFINED

#include "descrip.h"

#endif
#endif
#endif  /* ========== END DEC GKS ========== */
#endif

/* Picking device for GPX.                                                          */
#define WM_PD_MOUSE     (INT)0
#define WM_PD_TABLET    (INT)1
#define WM_HORI_KEYPAD  (INT)0
#define WM_VERT_KEYPAD  (INT)1

/* The order of four corners is lower left, lower right, upper right,               */
/*    upper left.                                                                   */
/*                                                                                  */
typedef struct 
    {
    INT ifset;
    INT key_type;                   /* WM_PD_MOUSE, WM_PD_TABLET                    */
    INT direction;                  /* WM_HORI_KEYPAD, WM_VERT_KEYPAD               */
    INT num_rows;                   /* the total number of rows of keypad.          */
    INT num_columns;                /* the total number of columns of keypad.       */
    POINT *keypad_reg;              /* the whole range of pseudo keypad in the      */
    /*  device coord. on the tablet.                                                */
    POINT *wcs;                     /* The world coord.related to the registered tablet.    */
    POINT *tablet;                  /* The registered tablet range.                 */
    TCP menu_keys;                  /* The menus key strings.                       */
    BOOL menu_updated;              /* The menu_keys has been updated.              */
    DOUBLE wcos, wsin;              /* temp. workspaces for transformation.         */
    MATRIX *x_matrix;               /* The transformation matrix between tablet and WCS.    */
    INT default_button;
    } REGISTRATION;

typedef struct esc_data_struct
    {
    INT num_ints;
    INT num_floats;
    INT num_strings;
    INT *ints;
    FLOAT *floats;
    INT *string_sizes;
    TCP strings;
    } ESC_DATA_STRUCT;

#ifdef USE_X
typedef struct gks_widget_struct
    {
#ifndef PRIOR_GKS  /* ========== BEGIN DEC GKS ========== */
    CHAR conid_buffer[256];
    struct dsc$descriptor_s conid;
    ESC_DATA_STRUCT out_esc_data, in_esc_data;
    INT in_esc_size, out_esc_size, esc_data_return_size;
    INT int_buffer[2];
    Widget child_widget;
    Widget out_widget;

#else  /* ========== END DEC GKS = BEGIN PRIOR GKS ========== */
    GKS_REAL aspect_ratio;
    INT width;
    INT height;
#endif  /* ========== END PRIOR GKS ========== */
    Widget widget;
    Widget menu_item;
    INT ws_id;
    } GKS_WIDGET_STRUCT;
#endif
typedef struct wm_current_struct
    {
    INT win_num;
    INT nsegs;
    TREEHEAD *win_tree_ptr;
    TREEHEAD *tnr_tree_ptr;
    TREEHEAD *gro_tree_ptr;
    TREEHEAD *seg_tree_ptr;
    APPLICATION_ID app_id;
    WINDOW_ID win_id;
    TNR_ID tnr_id;
    GROUP_ID gro_id;
    SEGMENT_ID seg_id;
    PICK_ID pic_id;
    RECTANGLE ndc;
    RECTANGLE nwc;
    RECTANGLE wcs;
    GKS_REAL panx;
    GKS_REAL pany;
    GKS_REAL zoomx;
    GKS_REAL zoomy;
    REGISTRATION reg;
    GKS_REAL TM[6];
    
    GKS_INT ws_id;
    GKS_INT max_ws;
    GKS_INT max_ac_ws;
    INT wm_gks_button;
#ifdef USE_X
    GKS_WIDGET_STRUCT *gks_widget_array;
#endif
    } WM_CURRENT;

#ifdef primos

#define GKZ_MEMSEL(i) gkz_memsel(*i)
#define GKZ_DUMMY_SEGMENT(i1,ra) gkz_dummy_segment(*i1,(GKS_REAL [])ra)

#endif

#ifdef vms

#define GKZ_MEMSEL(i) gkz_memsel(i)
#define GKZ_DUMMY_SEGMENT(i1,ra) gkz_dummy_segment(i1,ra)

#endif

#if USE_PROTOTYPES
extern INT GKZ_DOITRESET (void);
extern INT GKZ_DOITSET (void);
extern INT GKZ_DRAWING_OFF (void);
extern INT gkz_dummy_segment (GKS_INT *i, GKS_REAL *ra);
extern INT gkz_memsel (GKS_INT *i);
extern WM_CURRENT *wm_static (void);
extern INT wmz_getxy (TNR_ID *tnr, GKS_REAL *x, GKS_REAL *y, INT *button, INT pet);
extern INT gpx_wmtbandvector (INT *statPtr, DOUBLE wx1, DOUBLE wy1, GKS_REAL *wx2Ptr,
                              GKS_REAL *wy2Ptr, INT *butPtr);
extern INT gpx_wmtbandrectangle (INT *statPtr, DOUBLE wx1, DOUBLE wy1,
                                 GKS_REAL *wx2Ptr, GKS_REAL *wy2Ptr, INT *butPtr);
extern INT gpx_wmtlocate (INT *statPtr, GKS_REAL *wxPtr, GKS_REAL *wyPtr, INT *butPtr);
extern INT gpx_wmtregistration (TNR_ID tnr_id, POINT wcs_points[4],
                                POINT tcs_points[4], INT points_in);
extern INT wmz_create_gks_widget (DOUBLE xur, DOUBLE xll, DOUBLE yur, DOUBLE yll,
                                  DOUBLE scale_factor);
extern INT wmz_delete_workstation (GKS_INT wk_id);
extern INT wmz_front_wk_widget (GKS_INT wk_id);
extern INT wmz_getxy (TNR_ID *tnr, GKS_REAL *x, GKS_REAL *y, INT *button, INT pet);
extern INT wmz_init_color (void);
extern INT wmz_inq_wk_wins (GKS_INT wk_id);
extern GKS_INT wmz_ngks_wk_created (void);
extern VOID wmz_set_gks_input_active (BOOL active_flag);
extern INT wmz_update_gks_title (WM_ID obj_id, CHAR *usr_name);

#ifdef USE_X
extern VOID wmz_gks_process_event (Widget widget, caddr_t data, XEvent *event);
#endif

#else
extern INT GKZ_DOITRESET ();
extern INT GKZ_DOITSET ();
extern INT gkz_dummy_segment ();
extern INT gkz_memsel ();
extern WM_CURRENT *wm_static ();
extern INT wmz_create_gks_widget ();
extern GKS_INT wmz_ngks_wk_created ();
extern INT wmz_update_gks_title ();
extern INT wmz_front_wk_widget ();
extern INT wmz_inq_wk_wins ();
extern INT wmz_delete_workstation ();
extern VOID wmz_set_gks_input_active ();
extern VOID wmz_gks_process_event ();
extern INT wmz_init_color ();

#endif
#endif
