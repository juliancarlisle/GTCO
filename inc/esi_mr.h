/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MR.H*/
/* *3    14-AUG-1990 11:49:45 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2     7-MAR-1990 16:40:04 WALTERS "(SPR 0) Remove FLOAT types from system"*/
/* *1    30-JUN-1989 15:03:15 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MR.H*/
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

#ifndef ESI_MR_H
#define ESI_MR_H 1

#ifndef ESI_CT_H
#include "esi_ct.h"
#endif

/*  Define Map Registration Entry Points   */
#if USE_PROTOTYPES

extern INT mr_register_map(void);
extern INT mr_get_projection(CHAR *map_name,CHAR *message,
			     PROJECTION_ID projection_id,INT *numpoints,
			     CHAR coord_system[]);
extern INT mr_get_projection_term(void);
extern INT mr_get_xy_control_point(CHAR *message,CHAR *instructions,
				   PROJECTION_STRUCTURE *projection,
				   COORD *x, COORD *y);
extern INT mr_get_xy_control_point_term(void);
extern INT mr_get_str_control_points(DOUBLE xy_cntl[][2],CHAR ll_str[],
                                     CHAR ur_str[]);
extern INT mr_get_str_control_points_term(void);

extern INT mr_calc_xform (DOUBLE xy_cntl[][2], DOUBLE xy_tablet[][2],
			  INT n_points, DOUBLE tr_mat[2][2]);

extern INT mr_calc_3p (COORD xy_cntl[][2],        /* Map control points  */
                       DOUBLE xy_tab[][2],       /* Tablet control points */
                       COORD llx,
                       COORD lly,
                       COORD urx,
                       COORD ury,        /* Corners of registration area */
                       FLOAT xpoints[3],
                       FLOAT ypoints[3],        /* Points to be generated */
                       DOUBLE tr[2][2]);          /* WCS to NDC transform */

extern INT mr_get_section_corners(CHAR str_id[], COORD *llx, COORD *lly,
				  COORD *urx, COORD *ury);

#else 

extern INT mr_register_map();
extern INT mr_get_projection();
extern INT mr_get_projection_term();
extern INT mr_get_xy_control_point();
extern INT mr_get_xy_control_point_term();
extern INT mr_get_str_control_points();
extern INT mr_get_str_control_points_term();
extern INT mr_calc_xform();
extern INT mr_calc_3p();
extern INT mr_get_section_corners();

#endif

#endif
