/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TG_MAT.H*/
/* *5    14-AUG-1990 11:51:22 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *4    30-APR-1990 15:52:09 KEE "(SPR -1) reverse back to generation 2"*/
/* *3    30-APR-1990 09:56:03 HOANG "(SPR -1) (kee)"*/
/* *2    13-NOV-1989 11:35:08 JULIAN "Added new tablet support for calcomp."*/
/* *1    30-JUN-1989 15:05:05 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TG_MAT.H*/
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

#ifndef ESI_TG_MAT_H
#define ESI_TG_MAT_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* define matrix size & datatypes */
#define	 MATSIZE 3
#define  MAXIND	(MATSIZE - 1)

typedef  DOUBLE	MATRIX[MATSIZE][MATSIZE];
typedef  DOUBLE	VECTOR[MATSIZE];
typedef  MATRIX	*MATPTR;


typedef struct {
    DOUBLE  x,y;
    } POINT2D;
    
typedef struct {
    DOUBLE  x,y,z;
    } POINT3D;
    
typedef struct {
    DOUBLE  ul_x;
    DOUBLE  ul_y;
    DOUBLE  ur_x;
    DOUBLE  ur_y;
    DOUBLE  ll_x;
    DOUBLE  ll_y;
    DOUBLE  lr_x;
    DOUBLE  lr_y;
    } EXTENTS;

/* 11/18/88 SC - declare function as extern and add prototypes */

#if USE_PROTOTYPES

extern DOUBLE tg_dot(POINT2D *p1, POINT2D *p2);
extern DOUBLE tg_point_length(POINT2D *p);
extern INT tg_calc_reg_xform(EXTENTS *dext, EXTENTS *wext, FLOAT *angle, MATRIX *x);
extern INT tg_copy_mat(MATRIX mat1, MATRIX mat2);
extern INT tg_mat_mult(MATRIX mat1, MATRIX mat2, MATRIX result);
extern INT tg_point_normalize(POINT2D *p);
extern INT tg_post_mult(MATRIX mat1, MATRIX mat2);
extern INT tg_pre_mult(MATRIX mat1, MATRIX mat2);
extern INT tg_reg_to_wcs(DOUBLE in_x, DOUBLE in_y, DOUBLE *out_x, DOUBLE *out_y, MATRIX *x);
extern INT tg_set_identity(MATRIX mat);
extern INT tg_transform_points(DOUBLE *x, DOUBLE *y, MATRIX mat, INT num);
extern INT tg_zeromat(MATRIX mat);

#else

extern DOUBLE tg_dot();
extern DOUBLE tg_point_length();
extern INT tg_calc_reg_xform();
extern INT tg_copy_mat();
extern INT tg_mat_mult();
extern INT tg_point_normalize();
extern INT tg_post_mult();
extern INT tg_pre_mult();
extern INT tg_reg_to_wcs();
extern INT tg_set_identity();
extern INT tg_transform_points();
extern INT tg_zeromat();

#endif 

#endif
