/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GR.H*/
/* *2    14-AUG-1990 11:48:07 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:01:17 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GR.H*/
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

/*
 * Definitions for Graticule Overlay of the Map Definitions
 */

#ifndef ESI_GR_H
#define ESI_GR_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_TU_H
#include "esi_tu.h"
#endif

/*
 * Structure containing information on graticule overlay
 */
typedef struct
    {
    BOOL    index_points;
    CHAR    *x_tic_interval;
    CHAR    *y_tic_interval;
    COLOR_INDEX     color;
    DOUBLE  label_size;
    COLOR_INDEX     label_color;
    DOUBLE  index_point_size;
    CHAR    *name;
    CHAR    *uom;
    } GRAT_OV_STRUCT;


/* Function Definitions */

#if USE_PROTOTYPES
extern INT graticule_overlay(INT display_line);
extern INT gr_post_grat(GRAT_OV_STRUCT *graticule);
extern INT gr_draw_graticule(GRAT_OV_STRUCT *grat );
extern INT gr_draw_graticule_geo(GRAT_OV_STRUCT *grat, UOM_STRUCTURE *uom);
#else
extern INT graticule_overlay();
extern INT gr_post_grat();
extern INT gr_draw_graticule();
extern INT gr_draw_graticule_geo();
#endif

#endif

                                                                                                                             
