/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AG.H*/
/* *6     4-MAY-1991 15:32:05 KEE "(SPR -1) Fix compile error due to a comma missing"*/
/* *5    18-MAR-1991 17:17:35 PURNA "(SPR 0) Lease Mapping Init Checkin"*/
/* *4    12-FEB-1990 10:24:10 GILLESPIE "(SPR 6008) Add ag_inside()"*/
/* *3     9-FEB-1990 13:41:51 GILLESPIE "(SPR 6005) Add ag_clip_2"*/
/* *2     9-FEB-1990 12:36:10 GILLESPIE "(SPR 6005) Changes to include window clipping"*/
/* *1    30-JUN-1989 14:59:21 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AG.H*/

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

#ifndef ESI_AG_H
#define ESI_AG_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

typedef struct {
   DOUBLE x;
   DOUBLE y;
   } POINT2D;

typedef struct {
   DOUBLE x;
   DOUBLE y;
   DOUBLE z;
   } POINT3D;

#define AG_IN_WINDOW     (INT)0
#define AG_LEFT_WINDOW   (INT)2
#define AG_RIGHT_WINDOW  (INT)4
#define AG_TOP_WINDOW    (INT)8
#define AG_BOTTOM_WINDOW (INT)16

#if USE_PROTOTYPES
extern DOUBLE ag_arc_angle (DOUBLE angle1, DOUBLE angle2);
extern void ag_auto_scaled (DOUBLE exact_max, DOUBLE exact_min, 
			    DOUBLE *scaled_max, DOUBLE *scaled_min, 
			    DOUBLE *scaled_intrv, INT min_intrvs, 
			    INT *n_intrvs, INT *ndec_places);
extern void ag_auto_scaler (DOUBLE values[],INT n,DOUBLE *scaled_max, 
			    DOUBLE *scaled_min, DOUBLE *scaled_intrv,
			    INT min_intrvs,DOUBLE *conf,INT *n_intrvs, 
			    INT *ndec_places);
extern INT ag_clip_code( DOUBLE x, DOUBLE y, DOUBLE minx, DOUBLE miny, DOUBLE maxx,
		     DOUBLE maxy, INT *code);
extern INT ag_clip_1(DOUBLE *x1, DOUBLE *y1, DOUBLE *x2, DOUBLE *y2,
			DOUBLE minx, DOUBLE miny, DOUBLE maxx, DOUBLE maxy,
			DOUBLE *const1, DOUBLE *const2, BOOL *visible);
extern INT ag_clip_2(DOUBLE *x1, DOUBLE *y1, DOUBLE *x2, DOUBLE *y2,
			DOUBLE minx, DOUBLE miny, DOUBLE maxx, DOUBLE maxy,
			DOUBLE *const1, DOUBLE *const2, BOOL *visible);
extern void ag_donut_shape (DOUBLE xout[], DOUBLE yout[], INT nout,
			DOUBLE xin[], DOUBLE yin[],INT nin,
			DOUBLE xbuf[], DOUBLE ybuf[], INT *itotal);
extern void ag_ext_ag_intersxn (DOUBLE x1, DOUBLE y1, DOUBLE x2, DOUBLE y2, 
			DOUBLE xx1, DOUBLE yy1, DOUBLE xx2, DOUBLE yy2, 
			DOUBLE extfct, INT *ncross, DOUBLE *xc, DOUBLE *yc,
			INT *nseg);
extern BOOL ag_inside(DOUBLE test_x,DOUBLE test_y,DOUBLE *x,DOUBLE *y,
		     INT start_pnt,INT npts);
extern void ag_intersxn (DOUBLE x1, DOUBLE y1, DOUBLE x2, DOUBLE y2, 
			DOUBLE xx1, DOUBLE yy1, DOUBLE xx2, DOUBLE yy2, 
			DOUBLE *xc, DOUBLE *yc,INT *ncross, INT *isense);
extern void ag_plabxy_ (float xpoly[], float ypoly[], INT *np, INT *isense,
			float *wratio, float *xlab, float *ylab, float *wmax);
extern void ag_polar_coord (DOUBLE x, DOUBLE y, DOUBLE xorign, DOUBLE yorign, 
			DOUBLE *angle, DOUBLE *r);
extern void ag_poly_area (DOUBLE xpoly[], DOUBLE ypoly[], INT np, 
			DOUBLE wratio, DOUBLE *area, DOUBLE *xcentr, 
			DOUBLE *ycentr, DOUBLE *wmax);
extern void ag_poly_convex (DOUBLE xpoly[], DOUBLE ypoly[], INT np, 
			INT isense, INT jpoly, DOUBLE xout[], DOUBLE yout[],
			INT *nout);
extern void ag_poly_filler (INT np, DOUBLE xpoly[], DOUBLE ypoly[], 
			DOUBLE degrees, DOUBLE rdist, DOUBLE xout[], 
			DOUBLE yout[], INT *nout);
extern void ag_poly_gap (DOUBLE xpoly[], DOUBLE ypoly[], INT np, 
			INT iconcv, INT iconvx, DOUBLE xout[], 
			DOUBLE yout[], INT *nout);
extern void ag_poly_labelxy (DOUBLE xpoly[], DOUBLE ypoly[], INT np, INT isense,
			DOUBLE wratio, DOUBLE *xlab, DOUBLE *ylab, 
			DOUBLE *wmax);
extern void poly_cparal (DOUBLE xpin[], DOUBLE ypin[], INT npin, INT isense,
			DOUBLE pdist, INT maxout, DOUBLE xpout[], 
			DOUBLE ypout[], INT *npout);
extern void ag_poly_pt_cncv (DOUBLE xpoly[], DOUBLE ypoly[], INT np, 
			INT isense, INT nstart, INT *nreman, INT *ndone, 
			INT *iconcv, DOUBLE *angle1);
extern void ag_poly_pt_cnvx (DOUBLE xpoly[], DOUBLE ypoly[], INT np, 
			INT isense, INT nstart, DOUBLE angle1, 
			INT *nreman, INT *ndone, INT *iconvx);
extern DOUBLE ag_proj_2dpoint_line(POINT2D *,DOUBLE,DOUBLE,DOUBLE,POINT2D *);
extern void ag_shift_DOUBLE (DOUBLE buf[], INT n, INT nshift);
extern void ag_tm_ll_xy (DOUBLE lat, DOUBLE long_, DOUBLE lamdac, DOUBLE k0, 
			 DOUBLE ec, DOUBLE *x, DOUBLE *y);
#else
extern DOUBLE ag_arc_angle ();
extern void ag_auto_scaled ();
extern void ag_auto_scaler ();
extern INT ag_clip_code( );
extern INT ag_clip_1();
extern INT ag_clip_2();
extern void ag_donut_shape ();
extern void ag_ext_ag_intersxn ();
extern BOOL ag_inside();
extern void ag_intersxn ();
extern void ag_plabxy_ ();
extern void ag_polar_coord ();
extern void ag_poly_area ();
extern void ag_poly_convex ();
extern void ag_poly_filler ();
extern void ag_poly_gap ();
extern void ag_poly_labelxy ();
extern void poly_cparal ();
extern void ag_poly_pt_cncv ();
extern void ag_poly_pt_cnvx ();
extern DOUBLE ag_proj_2dpoint_line();
extern void ag_shift_DOUBLE ();
#endif

#endif
