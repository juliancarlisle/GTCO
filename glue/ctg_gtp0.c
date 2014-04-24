/* DEC/CMS REPLACEMENT HISTORY, Element CTG_GTP0.C */
/* *3     9-AUG-1990 19:06:28 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 06:59:04 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1     6-NOV-1989 14:21:27 GILLESPIE "Moved from main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element CTG_GTP0.C */
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

/*****************************************************************************/
/*  Cartographic Projections Glue Routines                                   */
/*****************************************************************************/

#include "esi_ct.h"
#include "esi_ct_err.h"

/******************************************************************************

NAME:             ctg_gtp$0

DESCRIPTION:      C to Fortran glue routine for gtp$0.for


     Input:       x_coord_in - the input x coordinate 
		  y_coord_in - the input y coordinate
		  projection_in - a pointer to the input projection data
		  projection_out - a pointer to the output projection data

     Output:      x_coord_out - the output x coordinate
		  y_coord_out - the output y coordinate
		  status

     Status:      SUCCESS
		  GCTP error code

******************************************************************************/

VOID ctg_gtp$0(x_coord_in,y_coord_in,projection_in, x_coord_out,y_coord_out,
		projection_out,status)
DOUBLE x_coord_in;
DOUBLE y_coord_in;
PROJECTION_STRUCTURE *projection_in;
DOUBLE *x_coord_out;
DOUBLE *y_coord_out;
PROJECTION_STRUCTURE *projection_out;
INT *status;
{

#ifdef primos
    fortran gtp$0();
#endif

    *x_coord_out = 0.0;
    *y_coord_out = 0.0;
    *status      = 0;

#ifdef vms

    gtp$0(&x_coord_in,&y_coord_in,
	  &projection_in->projection_type,
	  &projection_in->zone_code,
	  &projection_in->parameters,
	  &projection_in->spheroid_units,
	  &projection_in->spheroid_code,
	  x_coord_out, y_coord_out,
	  &projection_out->projection_type,
	  &projection_out->zone_code,
	  &projection_out->parameters,
	  &projection_out->spheroid_units,
	  &projection_out->spheroid_code,
	  status);
#endif


#if UNIX

    gtp$0_(&x_coord_in,&y_coord_in,
	  &projection_in->projection_type,
	  &projection_in->zone_code,
	  &projection_in->parameters,
	  &projection_in->spheroid_units,
	  &projection_in->spheroid_code,
	  x_coord_out, y_coord_out,
	  &projection_out->projection_type,
	  &projection_out->zone_code,
	  &projection_out->parameters,
	  &projection_out->spheroid_units,
	  &projection_out->spheroid_code,
	  status,sizeof(projection_in->projection_id)-1,
          sizeof(projection_in->projection_name)-1);
#endif


#ifdef primos

    GTP$0(x_coord_in,y_coord_in,
	  projection_in->projection_type,
	  projection_in->zone_code,
	  (DOUBLE []) &(projection_in->parameters.parm_1),
	  projection_in->spheroid_units,
	  projection_in->spheroid_code,
	  x_coord_out, y_coord_out,
	  projection_out->projection_type,
	  projection_out->zone_code,
	  (DOUBLE []) &(projection_out->parameters.parm_1),
	  projection_out->spheroid_units,
	  projection_out->spheroid_code,
	  *status);

#endif

#if 0
    The following error codes can be returned - translate them into
    Finder messages by adding a message offset...

C            = 0 , SUCCESSFUL TRANSFORMATION.
C            = 1 , ILLEGAL INPUT SYSTEM CODE.
C            = 2 , ILLEGAL OUTPUT SYSTEM CODE.
C            = 3 , ILLEGAL INPUT UNIT CODE.
C            = 4 , ILLEGAL OUTPUT UNIT CODE.
C            = 5 , INCONSISTANT UNIT AND SYSTEM CODES FOR INPUT.
C            = 6 , INCONSISTANT UNIT AND SYSTEM CODES FOR OUTPUT.
C            = 7 , ILLEGAL INPUT ZONE CODE.
C            = 8 , ILLEGAL OUTPUT ZONE CODE.
#endif

    if (*status != SUCCESS)
	{
	*status = CT_USGS_ERROR_OFFSET - *status;
	}   

}
