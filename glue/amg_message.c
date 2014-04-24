/* DEC/CMS REPLACEMENT HISTORY, Element AMG_MESSAGE.C*/
/* *3    27-AUG-1990 08:22:07 VINCE "(SPR 1) change old #if host to ifdef... "*/
/* *2     7-FEB-1990 06:56:03 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:44:22 GILLESPIE "Fortran bindings for Application Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_MESSAGE.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_MESSAGE.C*/
/* *1    19-JUN-1989 11:59:16 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_MESSAGE.C*/

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

extern INT amg_message();
/***********************************************************************
*
* GLUE ROUTINE
*
* Allows Fortran progs to call the C function am_message().
*
***********************************************************************/
#ifdef vms
publicdef INT amg_message(f_type, f_string)
INT *f_type;
DSC *f_string;
{
INT type;
CHAR message[MAXLEN];

type = *f_type;     /* de-reference and isolate */
DSCTOCS(f_string, message);

return am_message(type, message);
}
#endif

#if UNIX
publicdef INT amg_message_(f_type, f_string, len)
INT *f_type;
CHAR *f_string;
INT len;
{
INT type;
CHAR message[MAXLEN];

type = *f_type;     /* de-reference and isolate */
ftocstr(f_string, message, len);

return am_message(type, message);
}
#endif
#ifdef primos

publicdef INT amg_message(level,text,z1,z2)
INT level;
CHAR *text;
INT z1,z2;
{
    extern INT am_message();
    INT ret;
    CHAR string1[256];

    ftocstr((CHAR *)&text,string1,z2);
    ret = am_message(level,string1);
    ctofstr((CHAR *)&text,string1,z2);
    return(ret);
}

#endif
                                            
