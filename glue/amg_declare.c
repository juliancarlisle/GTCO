/* DEC/CMS REPLACEMENT HISTORY, Element AMG_DECLARE.C*/
/* *3    27-AUG-1990 08:21:58 VINCE "(SPR 1) change old #if host to ifdef... "*/
/* *2     7-FEB-1990 06:55:53 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:44:11 GILLESPIE "Fortran bindings for Application Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_DECLARE.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_DECLARE.C*/
/* *1    19-JUN-1989 11:59:09 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_DECLARE.C*/

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

extern INT amg_declare();
/***********************************************************************
*
* GLUE ROUTINE
*
* allows fortran progs to call the C function am_declare().
*
***********************************************************************/
#ifdef vms
publicdef INT amg_declare(tag)
DSC *tag;
{
INT status;
CHAR string[MAXLEN];

DSCTOCS(tag, string);

status = am_declare(string);

return status;
}
#endif

#if UNIX
publicdef INT amg_declare_(tag,len)
CHAR *tag;
INT len;
{
INT status;
CHAR string[MAXLEN];

ftocstr(tag, string, len);

status = am_declare(string);

return status;
}
#endif

#ifdef primos
extern INT ftocstr(), ctofstr();

publicdef INT amg_declare(tag,z1)
CHAR *tag;
INT z1;
{
    extern INT am_declare();
    INT ret;
    CHAR string1[256];

    ftocstr((CHAR *)&tag,string1,z1);
    ret = am_declare(string1);
    ctofstr((CHAR *)&tag,string1,z1);
    return(ret);
}

#endif

                                                                                                                      
