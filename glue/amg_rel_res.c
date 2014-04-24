/* DEC/CMS REPLACEMENT HISTORY, Element AMG_REL_RES.C*/
/* *3    27-AUG-1990 08:22:09 VINCE "(SPR 1) change old #if host to ifdef... "*/
/* *2     7-FEB-1990 06:56:10 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:44:29 GILLESPIE "Fortran bindings for Application Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_REL_RES.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_REL_RES.C*/
/* *1    19-JUN-1989 11:59:20 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_REL_RES.C*/

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


#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_TS_H
#include "esi_ts.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

extern INT amg_release_resource();
/***********************************************************************
*
* GLUE ROUTINE
*
* Allows Fortran progs to call the C function am_release_resource().
*
***********************************************************************/
#ifdef vms
publicdef INT amg_release_resource(f_id)
INT *f_id;
{
INT id;

id = *f_id;     /* isolate from Fortran */

return am_release_resource(id);
}
#endif

#if UNIX
publicdef INT amg_release_resource_(f_id)
INT *f_id;
{
INT id;

id = *f_id;     /* isolate from Fortran */

return am_release_resource(id);
}
#endif

#ifdef primos

publicdef INT amg_release_resource(id)
INT id;
{
    extern INT am_release_resource();
    return(am_release_resource(id));
}

#endif
                                                                                                                 
