/* DEC/CMS REPLACEMENT HISTORY, Element UGOPERR_GC.C */
/* *4     9-AUG-1990 19:16:04 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:36 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:01:52 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:51:35 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element UGOPERR_GC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element UGOPERR_GC.C*/
/* *2    10-OCT-1989 12:38:52 GORDON "(SPR 4999) add filename argument"*/
/* *1    19-JUN-1989 13:34:38 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element UGOPERR_GC.C*/

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
* FUNCTION:  ugoperr_gc
*
* SYNOPSIS: VOID ugoperr_gc ( unit, filename )
*	    INT *unit;            Output: Fortran unit number of error log file
*	    FILENAME filename	  Input: Name of file to open
*
* DESCRIPTION:  Glue routine to allow C to call ugoperr.
*
* RETURNS: None.
*
*********************************************************************/
#include "esi_gl_defs.h"
#include "esi_ho_desc.h"
#include "esi_ug.h"

#ifdef vms

publicdef VOID ugoperr_gc( unit, filename )
INT *unit;
FILENAME filename;
{

    ugoperr( unit, STRING_DESCRIPTOR_FROM_C(filename) );
    return;
}

#endif

#if UNIX

publicdef VOID ugoperr_gc( unit, filename )
INT *unit;
FILENAME filename;
{

    ugoperr_( unit, filename, strlen(filename) );
    return;
}


#endif

