/* DEC/CMS REPLACEMENT HISTORY, Element AMG_SET_RSRVR.C*/
/* *3    27-AUG-1990 08:22:12 VINCE "(SPR 1) change old #if host to ifdef... "*/
/* *2     7-FEB-1990 06:56:13 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:44:32 GILLESPIE "Fortran bindings for Application Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_SET_RSRVR.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_SET_RSRVR.C*/
/* *1    19-JUN-1989 11:59:23 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_SET_RSRVR.C*/

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


extern INT amg_set_rsrvr();
/***********************************************************************
*
* GLUE ROUTINE
*
* Allows Fortran progs to call the C function am_set_resource_server()
*
***********************************************************************/
#ifdef vms
publicdef INT amg_set_rsrvr(f_id, f_server)
INT *f_id;
INT (*f_server) ();
{
INT id;

id = *f_id;

return am_set_resource_server(id, f_server);
}
#endif

#if UNIX
publicdef INT amg_set_rsrvr_(f_id, f_server)
INT *f_id;
INT (*f_server) ();
{
INT id;

id = *f_id;

return am_set_resource_server(id, f_server);
}
#endif

#ifdef primos

publicdef INT amg_set_resource_server(id,server)
INT id;
INT server;   /* this is a pointer to a function returning an integer */
{
    extern INT am_set_resource_server();
    return(am_set_resource_server(id,&server));
}

#endif
                             
