/* DEC/CMS REPLACEMENT HISTORY, Element AMG_ALLOCATE.C*/
/* *3    27-AUG-1990 08:21:55 VINCE "(SPR 1) change old #if host to ifdef... "*/
/* *2     7-FEB-1990 06:55:49 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:44:08 GILLESPIE "Fortran bindings for Application Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_ALLOCATE.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_ALLOCATE.C*/
/* *1    19-JUN-1989 11:59:06 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_ALLOCATE.C*/

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

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_TS_H
#include "esi_ts.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifdef vms
extern INT amg_allocate();
/***********************************************************************
*
* GLUE ROUTINE
*
* Allows Fortran progs to call the C function am_allocate()
*
***********************************************************************/
publicdef INT amg_allocate(f_type, f_length)
INT *f_type;
INT *f_length;
{
INT type,length;

type = *f_type;
length = *f_length;

return am_allocate(type,length);
}
#endif

#ifdef primos
extern INT ftocstr(), ctofstr();

publicdef BYTE *amg_allocate(type,length)
INT type;
INT length;
{
    extern BYTE *am_allocate();
    return(am_allocate(type,length));
}
#endif


                         
