/* DEC/CMS REPLACEMENT HISTORY, Element AMG_QUIT.C*/
/* *2     7-FEB-1990 06:56:07 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:44:25 GILLESPIE "Fortran bindings for Application Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_QUIT.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_QUIT.C*/
/* *1    19-JUN-1989 11:59:18 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_QUIT.C*/

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

extern INT amg_quit();
/***********************************************************************
*
* GLUE ROUTINE
*
* Allows Fortran progs to call the C function  am_quit()
*
***********************************************************************/
#if UNIX

publicdef INT amg_quit_()
{
return am_quit();
}

#else

publicdef INT amg_quit()
{
return am_quit();
}

                                               
#endif
