/* DEC/CMS REPLACEMENT HISTORY, Element UGRQBAND_GC.C */
/* *4     9-AUG-1990 19:16:08 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:40 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:02:09 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:51:45 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element UGRQBAND_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element UGRQBAND_GC.C*/
/* *1    19-JUN-1989 13:34:41 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element UGRQBAND_GC.C*/

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

/********************************************************************
*      Copyright 1988, Exploration Systems Inc. San Francisco
*
* FUNCTION:  ugrqband_gc
*
* SYNOPSIS: INT ugrqband_gc( petype, x1, y1, status, tnr, xpos, ypos, button )
*	    INT petype;             Input: prompt echo type
*	    GKS_REAL x1, y1;        Input: initial position in WC coordinates
*	    INT *status;            Output: completion status
*	    INT *tnr;               Output: transformation number hit
*           GKS_REAL *xpos, *ypos;  Output: location
*	    INT *button;            Output: button number hit on puck   
*
* DESCRIPTION: Glue routine to allow C to call ugrqband.
*
* RETURNS: None.
*
*********************************************************************/
#include "esi_gl_defs.h"
#include "esi_gks.h"

publicdef INT ugrqband_gc( petype, x1, y1, status, tnr, xpos, ypos, button )
INT petype;
GKS_REAL x1, y1;
INT *status;
INT *tnr;
GKS_REAL *xpos, *ypos;
INT *button;
{
  
#ifdef vms

    GKS_REAL x = x1, y = y1;
    ugrqband( &petype, &x, &y, status, tnr, xpos, ypos, button );

#endif
#ifdef primos

    fortran ugrqband();
    ugrqband( petype, (GKS_REAL)x1, (GKS_REAL)y1, *status, *tnr, 
	      *xpos, *ypos, *button );

#endif

    return *status;
}
