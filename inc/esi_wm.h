/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WM.H*/
/*  14   22-OCT-1991 15:37:17 PURNA "(SPR 2567) added extern to wm_toggle_aspect_ratio"*/
/* *13    5-JUL-1991 11:28:29 KEE "(SPR 7598) Fix Electronic Drafting Line Editor PuckKey handling error, case 1893"*/
/* *12    3-MAY-1991 16:21:52 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *11   23-OCT-1990 14:06:36 KEE "(SPR -1) Motif and DecWindow merge"*/
/* *10   29-SEP-1990 10:18:29 GILLESPIE "(SPR 1) Merge beta deltas"*/
/*  8B1  28-SEP-1990 18:00:57 GILLESPIE "Beta Deltas"*/
/* *9    14-AUG-1990 11:52:13 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *8    30-JUN-1990 23:16:56 GILLESPIE "(SPR 1) Remove reduntant function defs - correct some prototypes, omissions"*/
/* *7     5-MAY-1990 21:23:32 SCD "(SPR 1) Add prototype for wmwclear()"*/
/* *6     3-MAY-1990 21:51:03 KEE "(SPR -1) multi window support"*/
/* *5    28-FEB-1990 15:42:52 JULIAN "(SPR -1) Add elements to WM_CURRENT struct, change MAIN_WKID & GKS_WISS_WKID def (kee)"*/
/* *4    15-AUG-1989 09:45:04 JULIAN "added gpx_wmtregistration prototype and esi_pr.h include"*/
/* *3    26-JUL-1989 00:13:14 GILLESPIE "(SPR 51) Minor adjustments"*/
/* *2    17-JUL-1989 10:36:21 GORDON "(SPR 0) add def of WM_BUTTON_CONTINUE"*/
/* *1    30-JUN-1989 15:05:57 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WM.H*/
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

#ifndef ESI_WM_H
#define ESI_WM_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#ifdef PRIOR_GKS  /* ========== BEGIN PRIOR GKS ========== */
#ifndef SUN_AGKSTYPE_H
#include "sun_agkstype.h"
#endif
#ifndef ESI_STDIO_H
#include "esi_stdio.h"
#endif
#endif  /* ========== END PRIOR GKS ========== */

/* Window Manager 'Object' typedefs                                                 */
typedef INT WM_ID;
typedef WM_ID APPLICATION_ID;
typedef WM_ID WINDOW_ID;
typedef WM_ID TNR_ID;
typedef WM_ID GROUP_ID;
typedef WM_ID SEGMENT_ID;
typedef WM_ID PICK_ID;

/* 'Object' string lengths                                                          */
#define WM_DBS_STR_SIZE 33
#define WM_DBS_STR_LEN (WM_DBS_STR_SIZE - 1)
#define WM_USR_STR_SIZE 33
#define WM_USR_STR_LEN (WM_USR_STR_SIZE - 1)

/* Registration modes                                                               */
#define WM_REG_MODE_OFF (INT)0
#define WM_REG_MODE_ABS (INT)1
#define WM_REG_MODE_REL (INT)2

/*                                                                                  */
/*JSC 3/16/89:    This is the input data record definition for                      */
/*        the CHOICE device driver in wm_gpx_input.c                                */
/*                                                                                  */
typedef struct 
    {
    INT fill_flag;
    INT acf;
    INT type_asf;
    INT width_asf;
    INT color_asf;
    INT polyline_index;
    LINE_STYLE_INDEX polyline_type;
    COLOR_INDEX color_index;
    GKS_REAL width;
    } LOCATE_DATREC;

typedef struct 
    {
    INT numstr;
    INT *sizes;
    TCP strings;
    CHAR *title;
    INT title_len;
    } CHOICE_DATREC;

typedef struct 
    {
    INT nstr;
    INT *sizes;
    TCP tcp;
    INT side;
    INT active;
    } WM_MENU_WS;

/* Definitions of standard FINDER puck zoom/pan buttons:                            */
/*  All applications which perform their own button trapping must use these         */
/*  symbols to ensure that the puck can be remapped by changing only this           */
/*  include file.                                                                   */
/*                                                                                  */

#define WM_BUTTON_ZOOMIN 0XA        /* A key */
#define WM_BUTTON_PAN 0XB           /* B key */
#define WM_BUTTON_CANCEL 0XC        /* C key */
#define WM_BUTTON_DONE 0XD          /* D Key */
#define WM_BUTTON_ASPECT_RATIO 0XE  /* E Key */
#define WM_BUTTON_RESET 0XF         /* F key */
#define WM_BUTTON_CONTINUE 0

#if USE_PROTOTYPES

/*                                                                                  */
/*    ************ START OF DEC GKS CONVERTED C BINDINGS **********                 */
/*    !!!!!!!!!!!!!  SOME HAVE NON-STANDARD PARMS. !!!!!!!!!!!!!!                   */
/*                                                                                  */

extern INT wm_gschm (GKS_INT wks_id, GKS_INT chdev, GKS_INT mode, GKS_INT echoflag);
extern INT wm_gsmch (GKS_INT wks_id, GKS_INT chdev, GKS_INT *status, GKS_INT *choice);
extern INT wm_grqch (GKS_INT wks_id, GKS_INT chdev, GKS_INT *status, GKS_INT *choice);
extern INT wm_gslcm (GKS_INT wks_id, GKS_INT locdev, GKS_INT mode, GKS_INT echoflag);
extern INT wm_gsmlc (GKS_INT wks_id, GKS_INT locdev, GKS_INT *xform, GKS_REAL *x,
                     GKS_REAL *y);

/************ END OF DEC GKS C-BINDING CONVERSIONS **********                       */

#ifdef PRIOR_GKS  /* ========== BEGIN PRIOR GKS ========== */
extern INT wm_gqchs (GKS_INT wks_id, GKS_INT choice_dev, GKS_INT record_buflen,
		     GKS_INT *err_stat, GKS_INT *input_mode,
		     GKS_INT *echo_flag, GKS_INT *initial_status, 
		     GKS_INT *initial_choice, GKS_INT *echo_type,
		     GKS_REAL echo_area[], GKS_INT *record_size, 
		     Gchoicerec *datrec);
extern INT wm_ginch (GKS_INT wks_id, GKS_INT choice_dev, 
		     GKS_INT initial_status, GKS_INT initial_choice, 
		     GKS_INT echo_type, GKS_REAL echo_area[], 
		     GKS_INT record_buflen, Gchoicerec *datrec);
extern INT wm_ginlc (GKS_INT wks_id, GKS_INT locdev, DOUBLE world_x, DOUBLE world_y,
                     GKS_INT xform, GKS_INT echo_type, GKS_REAL echo_area[],
                     GKS_INT reclen, Glocrec *locate_datrec);
extern INT wm_gqlcs (GKS_INT wks_id, GKS_INT locdev, GKS_INT type, GKS_INT reclen,
                     GKS_INT *status, GKS_INT *mode, GKS_INT *echo_flag,
                     GKS_INT *xform, GKS_REAL *world_x, GKS_REAL *world_y,
                     GKS_INT *echo_type, GKS_REAL echo_area[], GKS_INT *record_size,
                     Glocrec *datrec);

extern INT wm_gopks (FILE *errfil, Glong memory);

#else  /* ========== END PRIOR GKS = BEGIN DEC GKS ========== */
extern INT wm_gqchs (GKS_INT wks_id, GKS_INT chdev, GKS_INT reclen, GKS_INT *err_stat,
                     GKS_INT *input_mode, GKS_INT *echo_flag, GKS_INT *defstatus,
                     GKS_INT *defch, GKS_INT *echo_type, GKS_REAL echo_area[],
                     GKS_INT *record_size, CHOICE_DATREC *choice_datrec);
extern INT wm_ginch (GKS_INT wks_id, GKS_INT chdev, GKS_INT defstatus, GKS_INT defch,
                     GKS_INT echo_type, GKS_REAL echo_area[], GKS_INT reclen,
                     CHOICE_DATREC *datrec);
extern INT wm_ginlc (GKS_INT wks_id, GKS_INT locdev, DOUBLE world_x, DOUBLE world_y,
                     GKS_INT xform, GKS_INT echo_type, GKS_REAL echo_area[],
                     GKS_INT reclen, LOCATE_DATREC *locate_datrec);
extern INT wm_gqlcs (GKS_INT wks_id, GKS_INT locdev, GKS_INT type, GKS_INT reclen,
                     GKS_INT *status, GKS_INT *mode, GKS_INT *echo_flag,
                     GKS_INT *xform, GKS_REAL *world_x, GKS_REAL *world_y,
                     GKS_INT *echo_type, GKS_REAL echo_area[], GKS_INT *record_size,
                     LOCATE_DATREC *datrec);

extern INT wm_gopks (GKS_INT i1, GKS_INT i2);

#endif  /* ========== END DEC GKS ========== */

extern INT wm_attach_window_screen (WINDOW_ID win_id);
extern INT wm_gevtm (DOUBLE r1, DOUBLE r2, DOUBLE r3, DOUBLE r4, DOUBLE r5, DOUBLE r6,
                     DOUBLE r7, GKS_INT i1, GKS_REAL *ra1);
extern INT wm_ginsg (GKS_INT i1, GKS_REAL *ra2);
extern INT wm_gssgt (GKS_INT sgna, GKS_REAL *ra1);
extern INT wm_gacwk (GKS_INT n);
extern INT wm_gasgwk (GKS_INT n, GKS_INT m);
extern INT wm_gclrwk (GKS_INT n, GKS_INT m);
extern INT wm_gclsg (void);
extern INT wm_gclwk (GKS_INT n);
extern INT wm_gcrsg (GKS_INT sgna);
extern INT wm_gdawk (GKS_INT n);
extern INT wm_gdsg (GKS_INT i1);
extern INT wm_get_choice (DOUBLE x, DOUBLE y, GKS_INT tnr, GKS_INT *b);
extern INT wm_gfa (GKS_INT n, GKS_REAL *px, GKS_REAL *py);
extern INT wm_gkzqbtn (INT *button);
extern INT wm_gopwk (GKS_INT n, GKS_INT m, GKS_INT p);
extern INT wm_gpl (GKS_INT n, GKS_REAL *px, GKS_REAL *py);
extern INT wm_gpm (GKS_INT n, GKS_REAL *px, GKS_REAL *py);
extern INT wm_gqcntn (GKS_INT *i1, GKS_INT *i2);
extern INT wm_gqdsp (GKS_INT wtype, GKS_INT *errind, GKS_INT *dcunit, GKS_REAL *rx,
                     GKS_REAL *ry, GKS_INT *lx, GKS_INT *ly);
extern INT wm_gqfaci (INT *status, COLOR_INDEX *color);
extern INT wm_gqfais (INT *status, FILL_AREA_INTERIOR_STYLE *fill_style);
extern INT wm_gqfasi (INT *status, FILL_AREA_STYLE_INDEX *style_index);
extern INT wm_gqln (INT *status, LINE_STYLE_INDEX *line_style);
extern INT wm_gqlwsc (INT *status, GKS_REAL *line_style);
extern INT wm_gqnt (GKS_INT tnr, GKS_INT *i2, GKS_REAL *ra1, GKS_REAL *ra2);
extern INT wm_gqplci (INT *status, COLOR_INDEX *color);
extern INT wm_gqtxx (GKS_INT wkid, DOUBLE px, DOUBLE py, CHAR *str, GKS_INT *errind,
                     GKS_REAL *cpx, GKS_REAL *cpy, GKS_REAL txexpx[],
                     GKS_REAL txexpy[]);
extern INT wm_gqwkc (GKS_INT n, GKS_INT *m, GKS_INT *mm, GKS_INT *mmm);
extern INT wm_gqwkt (GKS_INT i1, GKS_INT *i2, GKS_INT *i3, GKS_REAL *ra1,
                     GKS_REAL *ra2, GKS_REAL *ra3, GKS_REAL *ra4);
extern INT wm_grensg (GKS_INT sgna, GKS_INT i1);
extern INT wm_grqlc (GKS_INT wkid, GKS_INT dev, GKS_INT *status, GKS_INT *tnr,
                     GKS_REAL *xpos, GKS_REAL *ypos);
extern INT wm_gqwkm (GKS_INT *errind, GKS_INT *max_op, GKS_INT *max_ac,
                     GKS_INT *max_seg);
extern INT wm_grqpk (GKS_INT wkid, GKS_INT pk_dev_num, GKS_INT *pick_status,
                     GKS_INT *segment, GKS_INT *pick);
extern INT wm_grsgwk (GKS_INT wkid);
extern INT wm_gsasf (GKS_INT flags[]);
extern INT wm_gschh (DOUBLE chh);
extern INT wm_gschsp (DOUBLE chsp);
extern INT wm_gschup (DOUBLE chux, DOUBLE chuy);
extern INT wm_gschxp (DOUBLE chxp);
extern INT wm_gscr (GKS_INT id, GKS_INT ic, DOUBLE r, DOUBLE g, DOUBLE b);
extern INT wm_gsds (GKS_INT i1, GKS_INT i2, GKS_INT i3);
extern INT wm_gsdtec (GKS_INT id, GKS_INT detec);
extern INT wm_gselnt (GKS_INT tnr);
extern INT wm_gsfaci (COLOR_INDEX coli);
extern INT wm_gsfais (FILL_AREA_INTERIOR_STYLE ints);
extern INT wm_gsfasi (FILL_AREA_STYLE_INDEX ints);
extern INT wm_gshlit (GKS_INT id, GKS_INT hilite);
extern INT wm_gsln (LINE_STYLE_INDEX ltype);
extern INT wm_gslwsc (DOUBLE lwidth);
extern INT wm_gsmk (GKS_INT pmk);
extern INT wm_gsmksc (DOUBLE mksc);
extern INT wm_gspkid (GKS_INT id);
extern INT wm_gsplci (COLOR_INDEX coli);
extern INT wm_gspmci (COLOR_INDEX coli);
extern INT wm_gssgp (GKS_INT segment, DOUBLE prior);
extern INT wm_gstxal (GKS_INT txalh, GKS_INT txalv);
extern INT wm_gstxci (COLOR_INDEX coli);
extern INT wm_gstxfp (GKS_INT font, GKS_INT prec);
extern INT wm_gstxp (GKS_INT txp);
extern INT wm_gsvis (GKS_INT id, GKS_INT vis);
extern INT wm_gsvp (GKS_INT n, DOUBLE x, DOUBLE y, DOUBLE xx, DOUBLE yy);
extern INT wm_gsvpip (GKS_INT n, GKS_INT nn, GKS_INT nnn);
extern INT wm_gswkvp (GKS_INT n, DOUBLE x, DOUBLE xx, DOUBLE xxx, DOUBLE xxxx);
extern INT wm_gswkwn (GKS_INT n, DOUBLE x, DOUBLE xx, DOUBLE xxx, DOUBLE xxxx);
extern INT wm_gswn (GKS_INT n, DOUBLE x, DOUBLE y, DOUBLE xx, DOUBLE yy);
extern INT wm_gtx (DOUBLE x0, DOUBLE y0, CHAR *chars);
extern INT wm_guwk (GKS_INT n, GKS_INT m);
extern INT wm_hold_updates (void);
extern BOOL wm_if_tablet (void);
extern INT wm_inq_current_screen (INT *default_screen);
extern INT wm_inq_deferral (GKS_INT *, GKS_INT *);
extern INT wm_inq_front_window (WINDOW_ID *front_window);
extern INT wm_inq_seg_vis (SEGMENT_ID seg_id);
extern INT wm_inq_user_structure (WM_ID obj_id, VOIDPTR user_structure_ptr,
                                  size_t nbytes);
extern INT wm_inq_wkvp (GKS_REAL *dcMinXPtr, GKS_REAL *dcMaxXPtr, GKS_REAL *dcMinYPtr,
                        GKS_REAL *dcMaxYPtr);
extern INT wm_inq_wkvp_max (GKS_REAL *dcMinXPtr, GKS_REAL *dcMaxXPtr,
                            GKS_REAL *dcMinYPtr, GKS_REAL *dcMaxYPtr);
extern INT wm_inq_wkwn (GKS_REAL *ndcMinXPtr, GKS_REAL *ndcMaxXPtr,
                        GKS_REAL *ndcMinYPtr, GKS_REAL *ndcMaxYPtr);
extern GKS_INT wm_mainwkid (void);
extern GKS_INT wm_maxwknum (void);
extern GKS_INT wm_obj_wkid (WM_ID obj_id);
extern INT wm_set_current_screen (INT default_screen);
extern INT wm_set_deferral (GKS_INT, GKS_INT);
extern INT wm_set_mouse_menu (TCP menutcp, INT *buttonmap);
extern INT wm_set_pick_device (TNR_ID, INT);
extern INT wm_set_user_structure (WM_ID obj_id, VOIDPTR user_structure_ptr,
                                  size_t nbytes);
extern INT wm_set_window_screen (WINDOW_ID window_id, INT screen);
extern INT wm_set_wkvp (DOUBLE vpMinX, DOUBLE vpMaxX, DOUBLE vpMinY, DOUBLE vpMaxY);
extern INT wm_update (void);
extern INT wm_update_mainwkid (GKS_INT cur_wkid);
extern INT wm_wkid_update (WINDOW_ID);
extern INT wmaclose (APPLICATION_ID app_id);
extern INT wmaopen (APPLICATION_ID app_id);
extern INT wmcontrol (void);
extern INT wmgallocate (GROUP_ID *gro_id_ptr);
extern INT wmgclose (GROUP_ID gro_id);
extern INT wmgdelete (GROUP_ID gro_id);
extern INT wmgdtec (GROUP_ID gro_id, INT detectability);
extern INT wmghlit (GROUP_ID gro_id, INT hilighting);
extern INT wmginqlist (INT  class , LISTHEAD *gro_list);
extern INT wmgopen (GROUP_ID gro_id);
extern INT wmgselector (CHAR *prompt, INT  class , INT max_sel, INT *num_sel,
                        GROUP_ID *gro_ids, INT *statusPtr);
extern INT wmgvis (GROUP_ID gro_id, INT visibility);
extern INT wminit (void);
extern INT wmoattach (APPLICATION_ID app, WINDOW_ID win, TNR_ID tnr, GROUP_ID gro,
                      INT *statusPtr);
extern INT wmoexists (APPLICATION_ID app, WINDOW_ID win, TNR_ID tnr, GROUP_ID gro,
                      INT *ifExistsPtr);
extern INT wmoinq (WM_ID obj_id, INT * class , CHAR *db_name, CHAR *usr_name);
extern INT wmoinqcur (APPLICATION_ID *app_id, WINDOW_ID *win_id, TNR_ID *tnr_id,
                      GROUP_ID *gro_id, SEGMENT_ID *seg_id, PICK_ID *pic_id);
extern INT wmoinqold (WM_ID obj_id, APPLICATION_ID *app_id, WINDOW_ID *win_id,
                      TNR_ID *tnr_id, GROUP_ID *gro_id, SEGMENT_ID *seg_id,
                      PICK_ID *pic_id);
extern INT wmoinqtyp (WM_ID obj_id, INT *typ_id);
extern INT wmoset (WM_ID obj_id, INT  class , CHAR *db_name, CHAR *usr_name);
extern INT wmowhere (APPLICATION_ID *appPtr, WINDOW_ID *winPtr, TNR_ID *tnrPtr,
                     GROUP_ID *groPtr, INT *statusPtr);
extern INT wmpallocate (PICK_ID *pic_id_ptr);
extern INT wmpclose (PICK_ID pic_id);
extern INT wmpopen (PICK_ID pic_id);
extern INT wmprequest (INT *statPtr, SEGMENT_ID *segPtr, PICK_ID *pickPtr,
                       INT *butPtr);
extern INT wmsallocate (SEGMENT_ID *seg_id_ptr);
extern INT wmsclose (SEGMENT_ID seg_id);
extern INT wmsdelete (SEGMENT_ID seg_id);
extern INT wmsdtec (SEGMENT_ID seg_id, INT detectability);
extern INT wmshlit (SEGMENT_ID seg_id, INT hilighting);
extern INT wmsinqlist (INT  class , LISTHEAD *seg_list);
extern INT wmsrelprior (SEGMENT_ID seg1, SEGMENT_ID seg2, INT relprior);
extern INT wmsselector (CHAR *prompt, INT  class , INT max_sel, INT *num_sel,
                        SEGMENT_ID *seg_ids, INT *statusPtr);
extern INT wmsvis (SEGMENT_ID seg_id, INT visibility);
extern INT wm_giitm (GKS_INT type, GKS_INT len, GKS_INT dim, CHAR *data);
extern INT wm_grditm (GKS_INT wkid, GKS_INT len, GKS_INT dim, CHAR *data);
extern INT wm_gwitm (GKS_INT wkid, GKS_INT type, GKS_INT len, GKS_INT dim, CHAR *data);
extern INT wmtallocate (TNR_ID *tnr_id_ptr, DOUBLE vx_ll, DOUBLE vx_ur, DOUBLE vy_ll,
                        DOUBLE vy_ur, DOUBLE wx_ll, DOUBLE wx_ur, DOUBLE wy_ll,
                        DOUBLE wy_ur);
extern INT wmtbandrectangle (INT *statPtr, DOUBLE wx1, DOUBLE wy1, GKS_REAL *wx2Ptr,
                             GKS_REAL *wy2Ptr, INT *butPtr);
extern INT wmtbandvector (INT *statPtr, DOUBLE wx1, DOUBLE wy1, GKS_REAL *wx2Ptr,
                          GKS_REAL *wy2Ptr, INT *butPtr);
extern INT wmtbuttoninterp (BOOL on_off);
extern INT wmtdopuckkey (DOUBLE wx, DOUBLE wy, INT puckkey);
extern INT wmtdragrectangle (INT *statPtr, DOUBLE llx, DOUBLE lly, DOUBLE urx,
                             DOUBLE ury, GKS_REAL *llxPtr, GKS_REAL *llyPtr,
                             INT *butPtr);
extern INT wmtdragsegment (INT *statPtr, SEGMENT_ID seg_id, DOUBLE wx1, DOUBLE wy1,
                           GKS_REAL *wx2Ptr, GKS_REAL *wy2Ptr, INT *butPtr);
extern INT wmterm (void);
extern INT wmtinq (TNR_ID tnr_id, GKS_REAL *vx_ll, GKS_REAL *vx_ur, GKS_REAL *vy_ll,
                   GKS_REAL *vy_ur, GKS_REAL *wx_ll, GKS_REAL *wx_ur, GKS_REAL *wy_ll,
                   GKS_REAL *wy_ur);
extern INT wmtinqbuttoninterp (INT *onOff);
extern INT wmtinqlist (INT  class , LISTHEAD *tnr_list);
extern INT wmtinqpanzoom (TNR_ID tnr_id, DOUBLE *xo, DOUBLE *yo, DOUBLE *fx,
                          DOUBLE *fy);
extern INT wmtlocate (INT *statPtr, GKS_REAL *wxPtr, GKS_REAL *wyPtr, INT *butPtr);
extern INT wmtpanzoom (TNR_ID tnr_id, DOUBLE xo, DOUBLE yo, DOUBLE fx, DOUBLE fy);
extern INT wmtregdefault (GKS_REAL xform[6]);
extern INT wmtregistration (TNR_ID tnr_id, GKS_REAL xpoints[3], GKS_REAL ypoints[3],
                            DOUBLE x1, DOUBLE y1, DOUBLE x2, DOUBLE y2);
extern INT wmtregmode (INT mode);
extern INT wmtregonoff (BOOL on_off);
extern INT wmtselect (TNR_ID tnr_id);
extern INT wmtselector (CHAR *prompt, INT  class , INT max_sel, INT *num_sel,
                        TNR_ID *tnr_ids, INT *statusPtr);
extern INT wmwallocate (WINDOW_ID *win_id_ptr, DOUBLE nx_ll, DOUBLE nx_ur,
                        DOUBLE ny_ll, DOUBLE ny_ur, COLOR_INDEX win_color);
extern INT wmwband (WINDOW_ID win_id);
extern INT wmwclose (WINDOW_ID win_id);
extern INT wmwclear (WINDOW_ID win_id);
extern INT wmwdelete (WINDOW_ID win_id);
extern INT wmwdrag (WINDOW_ID win_id);
extern INT wmwdtec (WINDOW_ID win_id, INT detectability);
extern INT wmwfront (WINDOW_ID win_id);
extern INT wmwhlit (WINDOW_ID win_id, INT highlighting);
extern INT wmwinq (WINDOW_ID win_id, GKS_REAL *nx_ll, GKS_REAL *nx_ur, GKS_REAL *ny_ll,
                   GKS_REAL *ny_ur, COLOR_INDEX *color);
extern INT wmwinqlist (INT  class , LISTHEAD *win_list);
extern INT wmwinqslist (WINDOW_ID win_id, LISTHEAD *seg_list_ptr);
extern INT wmwopen (WINDOW_ID win_id);
extern INT wmwpanzoom (WINDOW_ID win_id, DOUBLE wxo, DOUBLE wyo, DOUBLE wfx,
                       DOUBLE wfy);
extern INT wmwselector (CHAR *prompt, INT  class , INT max_sel, INT *num_sel,
                        WINDOW_ID *win_ids, INT *statusPtr);
extern INT wmwsetndc (WINDOW_ID win_id, DOUBLE x_min, DOUBLE x_max, DOUBLE y_min,
                      DOUBLE y_max);
extern INT wmwvis (WINDOW_ID win_id, INT visibility);
extern INT wmwzoom (WINDOW_ID win_id, BOOL if_zoomin);
extern VOID zzt_wcs2nwc (DOUBLE wcsX, DOUBLE wcsY, GKS_REAL *nwcXPtr,
                         GKS_REAL *nwcYPtr);
extern WINDOW_ID wm_wkid_to_window (GKS_INT wk_id);
extern TNR_ID wm_wkid_to_tnr (GKS_INT wk_id);
extern BOOL wm_is_menu_button (VOID);

#else     /* no prototypes */
extern INT wm_attach_window_screen ();
extern INT wm_gacwk ();
extern INT wm_gasgwk ();
extern INT wm_gclrwk ();
extern INT wm_gclsg ();
extern INT wm_gclwk ();
extern INT wm_gcrsg ();
extern INT wm_gdawk ();
extern INT wm_gdsg ();
extern INT wm_gevtm ();
extern INT wm_gfa ();
extern INT wm_ginsg ();
extern INT wm_gkzqbtn ();
extern INT wm_gopks ();
extern INT wm_gopwk ();
extern INT wm_gpl ();
extern INT wm_gpm ();
extern INT wm_gqcntn ();
extern INT wm_gqdsp ();
extern INT wm_gqnt ();
extern INT wm_gqtxx ();
extern INT wm_gqwkc ();
extern INT wm_gqwkt ();
extern INT wm_grensg ();
extern INT wm_grqlc ();
extern INT wm_gqwkm ();
extern INT wm_grqpk ();
extern INT wm_grsgwk ();
extern INT wm_gschh ();
extern INT wm_gschsp ();
extern INT wm_gschup ();
extern INT wm_gschxp ();
extern INT wm_gsdtec ();
extern INT wm_gselnt ();
extern INT wm_gsfaci ();
extern INT wm_gsfais ();
extern INT wm_gshlit ();
extern INT wm_gsln ();
extern INT wm_gslwsc ();
extern INT wm_gsmk ();
extern INT wm_gsmksc ();
extern INT wm_gspkid ();
extern INT wm_gsplci ();
extern INT wm_gspmci ();
extern INT wm_gssgp ();
extern INT wm_gssgt ();
extern INT wm_gstxal ();
extern INT wm_gstxci ();
extern INT wm_gstxfp ();
extern INT wm_gstxp ();
extern INT wm_gsvis ();
extern INT wm_gsvp ();
extern INT wm_gsvpip ();
extern INT wm_gswkvp ();
extern INT wm_gswkwn ();
extern INT wm_gswn ();
extern INT wm_gtx ();
extern INT wm_guwk ();
extern INT wm_hold_updates ();
extern BOOL wm_if_tablet ();
extern INT wm_inq_current_screen ();
extern INT wm_inq_deferral ();
extern INT wm_inq_front_window ();
extern INT wm_inq_seg_vis ();
extern INT wm_inq_user_structure ();
extern INT wm_inq_wkvp ();
extern INT wm_inq_wkvp_max ();
extern INT wm_inq_wkwn ();
extern GKS_INT wm_mainwkid ();
extern GKS_INT wm_maxwknum ();
extern GKS_INT wm_obj_wkid ();
extern INT wm_set_current_screen ();
extern INT wm_set_deferral ();
extern INT wm_set_pick_device ();
extern INT wm_set_user_structure ();
extern INT wm_set_window_screen ();
extern INT wm_set_wkvp ();
extern INT wm_update_mainwkid ();
extern INT wm_wkid_update ();
extern INT wmaclose ();
extern INT wmaopen ();
extern INT wmcontrol ();
extern INT wmgallocate ();
extern INT wmgclose ();
extern INT wmgdelete ();
extern INT wmgdtec ();
extern INT wmghlit ();
extern INT wmginqlist ();
extern INT wmgopen ();
extern INT wmgselector ();
extern INT wmgvis ();
extern INT wminit ();
extern INT wmoattach ();
extern INT wmoexists ();
extern INT wmoinq ();
extern INT wmoinqcur ();
extern INT wmoinqold ();
extern INT wmoinqtyp ();
extern INT wmoset ();
extern INT wmowhere ();
extern INT wmpallocate ();
extern INT wmpclose ();
extern INT wmpopen ();
extern INT wmprequest ();
extern INT wmsallocate ();
extern INT wmsclose ();
extern INT wmsdelete ();
extern INT wmsdtec ();
extern INT wmshlit ();
extern INT wmsinqlist ();
extern INT wmsrelprior ();
extern INT wmsselector ();
extern INT wmsvis ();
extern INT wm_giitm ();
extern INT wm_grditm ();
extern INT wm_gwitm ();
extern INT wmtallocate ();
extern INT wmtbandrectangle ();
extern INT wmtbandvector ();
extern INT wmtbuttoninterp ();
extern INT wmtdopuckkey ();
extern INT wmtdragrectangle ();
extern INT wmtdragsegment ();
extern INT wmterm ();
extern INT wmtinq ();
extern INT wmtinqbuttoninterp ();
extern INT wmtinqlist ();
extern INT wmtinqpanzoom ();
extern INT wmtlocate ();
extern INT wmtpanzoom ();
extern INT wmtregdefault ();
extern INT wmtregistration ();
extern INT wmtregmode ();
extern INT wmtregonoff ();
extern INT wmtselect ();
extern INT wmtselector ();
extern INT wmwallocate ();
extern INT wmwband ();
extern INT wmwclear ();
extern INT wmwclose ();
extern INT wmwdelete ();
extern INT wmwdrag ();
extern INT wmwdtec ();
extern INT wmwfront ();
extern INT wmwhlit ();
extern INT wmwinq ();
extern INT wmwinqlist ();
extern INT wmwinqslist ();
extern INT wmwopen ();
extern INT wmwpanzoom ();
extern INT wmwselector ();
extern INT wmwsetndc ();
extern INT wmwvis ();
extern INT wmwzoom ();
extern VOID zzt_wcs2nwc ();
extern WINDOW_ID wm_wkid_to_window ();
extern TNR_ID wm_wkid_to_tnr ();
extern BOOL wm_is_menu_button ();

#endif    /* of USE_PROTOTYPES */
#endif
