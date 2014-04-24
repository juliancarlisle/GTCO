/* DEC/CMS REPLACEMENT HISTORY, Element ESI_VI.H */
/* *2    11-JUN-1991 15:07:11 JESSIE "(SPR 0) for velocity interpolation" */
/* *1    11-JUN-1991 15:06:22 JESSIE "for VI" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_VI.H */
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1991
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

#ifndef ESI_VI_H
#define ESI_VI_H  1

#ifndef  ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef  ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef  ESI_TS_H
#include "esi_ts.h"
#endif

#define VI_WORKSPACE	"vi_workspace"

typedef struct 			/* for User Interface */
	{
	INT 	id;		/* for menu */
	INT	msg_id;		/* for message box */
	CHAR	list_name[30];	/* selected list name */
	TCP	hor_tcp;	/* for horizons  */
	CHAR  	vtype[15];	/* velocity type */
	INT	smu_type;	/* smooth type */
	INT 	smu_wt;		/* only when smu_type = 3 */
	INT	num_ref;	/* the num of v-t pair */
	TCP 	ref_time;
	TCP	ref_vel;
	BOOL 	residual_mode;	/* TRUE, call input for v-t */
	TCP	source;
	TCP	hor_source;
	TCP	grid_source;
	CHAR	grid_iname[60];
	CHAR 	grid_oname[60];
	INT	sample;
	}VI_STRUCT;

#if USE_PROTOTYPES

extern INT    vi_args(INT argc, CHAR *argv[], CHAR *pat, INT *num);
extern VOID   vi_cdp_intp(INT knt, INT ref_cdp, INT *cdp, DOUBLE *value,
                 INT *ocdp, DOUBLE *out);
extern INT    vi_get_cdp_value(NLIST_HEADER tlist, DOUBLE tst_cdp,
                 DOUBLE *value);
extern INT    vi_get_vel_fun(CHAR *filename, INT *iflag, CHAR *line_name,
                 INT *shot_point, INT *ntv, INT *time, INT *vel);
extern INT    vi_get_velfn(CHAR *filename, INT *iflag, INT *line_id,      
                 INT *shot_point, INT *ntv, INT *time, INT *vel);
extern DOUBLE vi_grid_interp(DOUBLE a, DOUBLE b, DOUBLE c, DOUBLE d,
                 DOUBLE fx,DOUBLE fy);
extern VOID   vi_int_avg(INT n, DOUBLE *tim, DOUBLE *vint, DOUBLE *vavg);
extern VOID   vi_int_stk(INT n, DOUBLE *tim, DOUBLE *vint, DOUBLE *vavg);
extern DOUBLE vi_lin_intp(INT n, DOUBLE *tim, DOUBLE *vel, DOUBLE tout);
extern INT    vi_lines(PROJECT_NAME project, NLIST_ID list_name,
                 INT **lines, INT *lineknt);
extern INT    vi_mak_tbl(INT ndx, INT len, INT *cdp, DOUBLE *value,
                 INT *ocdp, DOUBLE *out, INT *knt);
extern INT    vi_make_grid(CHAR *xyz_file, DOUBLE dxmin,DOUBLE dxmax,
                 DOUBLE dymin, DOUBLE dymax, FLOAT **grid_z, INT *nrows,
                 INT *ncols, DOUBLE *grid_int);
extern VOID   vi_md3flt(INT n, DOUBLE *x);
extern INT    vi_median(INT nrows, INT ncols, FLOAT *x);
extern INT    vi_median_2d(INT nrows, INT ncols, FLOAT *x);
extern VOID   vi_rlod_d (DOUBLE *a, INT i, DOUBLE *c, INT n, INT k, INT iflg);
extern VOID   vi_rms_avg(INT n, DOUBLE *tim, DOUBLE *vrms,
                 DOUBLE *vavg);
extern INT    vi_rms_avg2 (INT n, DOUBLE *tim, DOUBLE *vrms,
                 DOUBLE *vavg, INT *nout);
extern INT    vi_vel_chk(INT n, DOUBLE *tim, DOUBLE *vel);
extern INT    vi_wt_avg(INT iwt, INT nrows, INT ncols, FLOAT *x);

#else    /* no prototypes */

extern INT    vi_args();
extern VOID   vi_cdp_intp();
extern INT    vi_get_cdp_value();
extern INT    vi_get_vel_fun();
extern INT    vi_get_velfn();
extern DOUBLE vi_grid_interp();
extern VOID   vi_int_avg();
extern VOID   vi_int_stk();
extern DOUBLE vi_lin_intp();
extern INT    vi_lines();
extern INT    vi_mak_tbl();
extern INT    vi_make_grid();
extern VOID   vi_md3flt();
extern INT    vi_median();
extern INT    vi_median_2d();
extern VOID   vi_rlod_d ();
extern VOID   vi_rms_avg();
extern INT    vi_rms_avg2 ();
extern INT    vi_vel_chk();
extern INT    vi_wt_avg();

#endif   /* of USE_PROTOTYPES */

#endif
