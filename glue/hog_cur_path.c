/* DEC/CMS REPLACEMENT HISTORY, Element HOG_CUR_PATH.C*/
/* *3     9-AUG-1990 19:06:59 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:32 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:45:52 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_CUR_PATH.C*/

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

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifdef vms
publicdef INT hog_get_current_path(buf)
DSC *buf;
{
    INT status=SUCCESS;
    CHAR string[MAXLEN];

    status = ho_get_current_path(string);
    CSTODSC(string,buf);
    return status;
}

#endif

#if UNIX
publicdef INT hog_get_current_path_(buf,len)
CHAR *buf;
INT len;
{
    INT status=SUCCESS;
    CHAR string[MAXLEN];

    status = ho_get_current_path(string);
    ctofstr(buf,string,len);
    return status;
}

#endif
#ifdef primos

publicdef CHAR *hog_get_current_path(buff,z1)
CHAR *buff;
INT z1;
{
    extern CHAR *ho_get_current_path();
    CHAR *ret;
    CHAR string1[MAXLEN];

    ftocstr((CHAR *)&buff,string1,z1);
    ret = ho_get_current_path(string1);
    ctofstr((CHAR *)&buff,string1,z1);
    return(ret);
}

#endif

             
