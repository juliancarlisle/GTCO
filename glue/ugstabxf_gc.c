/* DEC/CMS REPLACEMENT HISTORY, Element UGSTABXF_GC.C */
/* *4     9-AUG-1990 19:16:33 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:59 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:03:49 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:52:51 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element UGSTABXF_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element UGSTABXF_GC.C*/
/* *1    19-JUN-1989 13:34:56 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element UGSTABXF_GC.C*/

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
* FUNCTION:  ugstabxf_gc  
*
* SYNOPSIS: VOID ugstabxf_gc( wkid, reset, xfmatr )
*	    INT wkid;          Input: workstation id
*	    BOOL reset;        Input: true=reset tablet to no transform
*				      false=set transform
*	    GKS_REAL xfmatr[]; Input: transform matrix
*
* DESCRIPTION: Glue routine to allow C to call Fortran routine UGSTABXF
*
* RETURNS: None
*
* 12/15/88 G Shannon - created
*********************************************************************/
#include "esi_gl_defs.h"
#include "esi_gks.h"

publicdef VOID ugstabxf_gc( wkid, reset, xfmatr )
INT wkid;
BOOL reset;
GKS_REAL xfmatr[];
{

#ifdef vms

    ugstabxf( &wkid, &reset, xfmatr );

#endif

#if UNIX

    ugstabxf_( &wkid, &reset, xfmatr );

#endif

#ifdef primos

    fortran ugstabxf();
    ugstabxf( wkid, reset, (GKS_REAL [])xfmatr );

#endif

    return;
}
