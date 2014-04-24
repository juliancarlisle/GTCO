/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TG.H*/
/* *5     1-JUL-1991 15:08:15 KEE "(SPR 8013) Fix Polyline Color Palette Window being orphaned after CANCEL, case 2364"*/
/* *4    14-AUG-1990 11:51:20 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *3    20-APR-1990 18:29:10 PURNA "(SPR 0) fix text leaking"*/
/* *2    18-APR-1990 10:08:34 PURNA "(SPR 1) fix depth tracks bad aspect ratio"*/
/* *1    30-JUN-1989 15:05:03 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TG.H*/
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

#ifndef ESI_TG_H
#define ESI_TG_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

/* defines for tg_drawline and tg_setline */
#define TG_DEFAULT_COLOR  (COLOR_INDEX)WHITE
#define TG_DEFAULT_WIDTH  (GKS_REAL)1.0
#define TG_DEFAULT_LTYPE  (LINE_STYLE_INDEX)1     /* solid line */

typedef struct {
    LINE_ATTRIBUTE line;
    INT         npts;
    GKS_REAL    *xarray;
    GKS_REAL    *yarray;
} TG_LINE_STRUCT ;

#if USE_PROTOTYPES

extern INT tg_ask_polyline_attributes(COLOR_INDEX *color_returned,
                                      LINE_STYLE_INDEX *type_returned,
			       GKS_REAL *width_returned, INT *status_returned);
extern INT tg_calc_3p_xform(FLOAT xpoint[], FLOAT ypoint[], DOUBLE x1, DOUBLE y1,
		     DOUBLE x2, DOUBLE y2, FLOAT xform[], FLOAT *angle);
extern INT tg_drawline(TG_LINE_STRUCT *pl);
extern INT tg_fit_string(CHAR *string, DOUBLE xmin, DOUBLE ymin,
    DOUBLE xmax, DOUBLE ymax, DOUBLE chh, DOUBLE *char_height);
extern INT tg_fit_text(LISTHEAD *llist, DOUBLE xmin, DOUBLE ymin,
    DOUBLE xmax, DOUBLE ymax, DOUBLE chh, DOUBLE *char_height);
extern INT tg_help_convert(INT tnr, INT status, DOUBLE xpos, DOUBLE ypos,
		    FLOAT *xreturn, FLOAT *yreturn);
extern INT tg_init(void);
extern INT tg_set_tablet_type( INT tablet_type, GKS_REAL *screenToReg );
extern INT tg_term(void);
extern INT tg_tnr2tnr(INT tnrin, DOUBLE xin, DOUBLE yin, INT tnrout,
	       FLOAT *xout, FLOAT *yout);
extern INT tg_window_id(VOID);
extern VOID tg_delete_window(VOID);

#else

extern INT tg_ask_polyline_attributes();
extern INT tg_calc_3p_xform();
extern INT tg_fit_string();
extern INT tg_fit_text();
extern INT tg_drawline();
extern INT tg_help_convert();
extern INT tg_init();
extern INT tg_set_tablet_type();
extern INT tg_term();
extern INT tg_tnr2tnr();
extern INT tg_window_id();
extern VOID tg_delete_window();

#endif

#endif
