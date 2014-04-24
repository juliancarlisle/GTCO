/* DEC/CMS REPLACEMENT HISTORY, Element UGSRAWXF_GC.C */
/* *4     9-AUG-1990 19:16:23 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:49 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:02:59 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:52:16 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element UGSRAWXF_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element UGSRAWXF_GC.C*/
/* *2    20-JUL-1989 10:59:26 GORDON "(SPR 100) Sun port mods"*/
/* *1    19-JUN-1989 13:34:48 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element UGSRAWXF_GC.C*/

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
* FUNCTION:  ugsrawxf_gc
*
* SYNOPSIS:  VOID ugsrawxf_gc( xf )
*	     GKS_REAL xf[];     Input: raw xform array
*
* DESCRIPTION: Glue to allow C to call ugsrawxf
*
* RETURNS: None
*
* 12/14/88 GS - created
*********************************************************************/
#include "esi_gl_defs.h"
#include "esi_gks.h"

publicdef VOID ugsrawxf_gc ( xf )
GKS_REAL xf[];
{

#ifdef vms

    ugsrawxf( xf );

#endif

#if UNIX

/* do nothing */

#endif

#ifdef primos

    fortran ugsrawxf();

    ugsrawxf( (GKS_REAL [])xf );

#endif

    return;
} 

