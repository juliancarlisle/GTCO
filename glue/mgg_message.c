/* DEC/CMS REPLACEMENT HISTORY, Element MGG_MESSAGE.C*/
/* *3     9-AUG-1990 19:08:03 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:00:36 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:45:04 GILLESPIE "Fortran binding for mg_message"*/
/* DEC/CMS REPLACEMENT HISTORY, Element MGG_MESSAGE.C*/

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

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifndef ESI_MG_H
#include "esi_mg.h"
#endif

extern VOID mgg_message();
/***********************************************************************
*
* GLUE ROUTINE
*
* This routine will allow fortran programs to call the C function
* mg_message().  The difference between the fortran and C versions is
* that the fortran version returns the character string in the parameter
* list as opposed to the C function which returns the string as the value
* of the function.
*
* Julian   3/28/87
***********************************************************************/
#ifdef vms
publicdef VOID mgg_message(f_id, f_string)
INT *f_id;
DSC *f_string;
{

INT id;
CHAR *msg;

id = *f_id;                             /* de-reference and isolate from Fortran */

msg = mg_message(id);

CSTODSC(msg,f_string);

return;
}

#endif

#if UNIX
publicdef VOID mgg_message_(f_id, f_string, len)
INT *f_id;
CHAR *f_string;
INT len;
{

INT id;
CHAR *msg;

id = *f_id;                             /* de-reference and isolate from Fortran */

msg = mg_message(id);

ctofstr(f_string,msg,len);

return;
}

#endif

#ifdef primos
publicdef VOID mgg_message(f_id, f_string,z1,z2)
INT f_id;
CHAR *f_string;
INT z1, z2;
{

INT id;
CHAR *msg;

id = f_id;                       /* de-reference and isolate from Fortran */

msg = mg_message(id);

ctofstr((CHAR *)&f_string,msg,z2);

return;
}
#endif
                        
