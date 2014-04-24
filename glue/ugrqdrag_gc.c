/* DEC/CMS REPLACEMENT HISTORY, Element UGRQDRAG_GC.C */
/* *4     9-AUG-1990 19:16:14 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:43 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:02:26 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:51:55 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element UGRQDRAG_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element UGRQDRAG_GC.C*/
/* *1    19-JUN-1989 13:34:43 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element UGRQDRAG_GC.C*/

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
* FUNCTION:  ugrqdrag_gc
*
* SYNOPSIS:  INT ugrqdrag_gc( segment, wx1, wy1, status, tnr, wx2, wy2, but )
*            INT segment;                     Input: prompt echo segment
*	     GKS_REAL wx1, wy1;               Input: initial position (WC)
*	     INT *status;		      Output: status
*	     INT *tnr;			      Output: transformation hit num
*	     GKS_REAL *wx2, *wy2;	      Output: location
*	     INT *but;			      Output: button number hit
*
* DESCRIPTION: Glue routine to allow C to call fortran routine ugrqdrag.
*
* RETURNS: None.
*
* 12/14/88 GS - created.
*********************************************************************/
#include "esi_gl_defs.h"
#include "esi_gks.h"

publicdef INT ugrqdrag_gc( segment, wx1, wy1, status, tnr, wx2, wy2, but )
INT segment;                    
GKS_REAL wx1, wy1;              
INT *status;		     
INT *tnr;		
GKS_REAL *wx2, *wy2;	
INT *but;		
{

#ifdef vms
    
    GKS_REAL x1 = wx1, y1 = wy1;
    ugrqdrag( &segment, &x1, &y1, status, tnr, wx2, wy2, but );

#endif
#if UNIX
    
    GKS_REAL x1 = wx1, y1 = wy1;
    ugrqdrag_( &segment, &x1, &y1, status, tnr, wx2, wy2, but );

#endif
#ifdef primos

    fortran ugrqdrag();
    ugrqdrag( segment, (GKS_REAL)wx1, (GKS_REAL)wy1, *status, *tnr, 
	      *wx2, *wy2, *but );

#endif

    return *status;
} 
