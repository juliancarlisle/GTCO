/* DEC/CMS REPLACEMENT HISTORY, Element UGSSAMP_GC.C */
/* *4     9-AUG-1990 19:16:26 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:53 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:03:15 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:52:29 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element UGSSAMP_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element UGSSAMP_GC.C*/
/* *2    20-JUL-1989 11:00:33 GORDON "(SPR 100) Sun port mods"*/
/* *1    19-JUN-1989 13:34:51 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element UGSSAMP_GC.C*/

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
* FUNCTION:  ugssamp_gc
*
* SYNOPSIS: VOID ugssamp_gc( onoroff )
*	    BOOL onoroff;           Input: set sample mode on or off
*
* DESCRIPTION: Glue routine to allow C to call Fortran routine ugssamp
*
* RETURNS: None.
*
* 12/15/88 G Shannon - created
*********************************************************************/
#include "esi_gl_defs.h"

publicdef VOID ugssamp_gc( onoroff )
BOOL onoroff;
{

#ifdef vms

    ugssamp( &onoroff );

#endif
#if UNIX

/* do nothing */

#endif
#ifdef primos

    fortran ugssamp();
    ugssamp( onoroff );

#endif

    return;
} 
