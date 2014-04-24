/* DEC/CMS REPLACEMENT HISTORY, Element UGSSCAXF_GC.C */
/* *4     9-AUG-1990 19:16:30 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:56 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:03:32 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:52:41 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element UGSSCAXF_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element UGSSCAXF_GC.C*/
/* *1    19-JUN-1989 13:34:53 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element UGSSCAXF_GC.C*/

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
* FUNCTION: ugsscaxf_gc.c 
*
* DESCRIPTION: VOID ugsscaxf_gc( wkid, ifreset, xfmatr )
*              INT wkid;       Input: workstation id
*	       BOOL reset;     Input: true=reset device to no transform
*				      false=set transform
*	       GKS_REAL xfmatr[];  Input: transform matrix
* RETURN:   None
*
* 12/14/88 G Shannon - created
*
*********************************************************************/
#include "esi_gl_defs.h"
#include "esi_gks.h"

publicdef VOID ugsscaxf_gc( wkid, reset, xfmatr )
INT wkid;
BOOL reset;
GKS_REAL xfmatr[];
{

#ifdef vms

    ugsscaxf( &wkid, &reset, xfmatr );

#endif
#if UNIX

    ugsscaxf_( &wkid, &reset, xfmatr );

#endif
#ifdef primos

    fortran ugsscaxf();

    ugsscaxf( wkid, reset, (GKS_REAL [])xfmatr );

#endif

    return;
}
