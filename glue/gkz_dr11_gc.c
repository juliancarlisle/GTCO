/* DEC/CMS REPLACEMENT HISTORY, Element GKZ_DR11_GC.C */
/* *4     9-AUG-1990 19:06:50 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 06:59:23 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 15:57:44 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:48:26 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element GKZ_DR11_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element GKZ_DR11_GC.C*/
/* *1    19-JUN-1989 12:53:03 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element GKZ_DR11_GC.C*/

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
* FUNCTION:  gkz_init_dr11_gc
*
* SYNOPSIS: VOID gkz_init_dr11_gc( channel )
*           INT channel;           Input: dma channel number
*
* DESCRIPTION: Glue routine to allow C to call gkz_init_dr11
*
* RETURNS: None
*
* 12/15/88 GShannon - created
*********************************************************************/
#include "esi_gl_defs.h"

publicdef VOID gkz_init_dr11_gc( channel )
INT channel;
{

#ifdef vms

    gkz_init_dr11( &channel );

#endif
#ifdef primos
  
    fortran gkz_init_dr11();
    gkz_init_dr11( channel );
    
#endif

    return;
}
