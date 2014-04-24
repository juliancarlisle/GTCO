/* DEC/CMS REPLACEMENT HISTORY, Element GIEMOD_GC.C */
/* *4     9-AUG-1990 19:06:46 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 06:59:20 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 15:57:28 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:48:13 PURNA "mmove from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element GIEMOD_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element GIEMOD_GC.C*/
/* *3    11-AUG-1989 10:04:17 JULIAN "(SPR 999) fixing statement not reached problem"*/
/* *2    18-JUL-1989 15:25:55 GORDON "(SPR 100) Add mods from Sun port"*/
/* *1    19-JUN-1989 12:52:57 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element GIEMOD_GC.C*/

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
* FUNCTION:  giemod_gc
*
* SYNOPSIS: VOID giemod_gc( channel, model, dma_type, efn )
*	    INT channel;            Input: channel number
*	    INT model;		    Input: Raster model number
*	    INT dma_type;	    Input: type of I/O (DMA or serial)
*	    INT efn;		    Input:
*
* DESCRIPTION: Glue routine to allow C to call GIEMOD
*
* RETURNS: None.
*
* 12/15/88 GS - created
*********************************************************************/
#include "esi_gl_defs.h"

publicdef VOID giemod_gc( channel, model, dma_type, efn )
INT channel;
INT model;
INT dma_type;
INT efn;
{

#ifdef vms
   
    giemod( &channel, &model, &dma_type, &efn );
    return;

#endif

#if UNIX
   
    return;	/* not used by SUN GKS */

#endif

#ifdef primos

    fortran giemod();
    giemod( channel, model, dma_type, efn );
    return;

#endif

}
