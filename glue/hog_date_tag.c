/* DEC/CMS REPLACEMENT HISTORY, Element HOG_DATE_TAG.C*/
/* *3     9-AUG-1990 19:07:03 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:35 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:45:56 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_DATE_TAG.C*/

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

/* HO_DATE_TAG GLUE ROUTINE  */
#ifdef vms
publicdef INT hog_date_tag(string)
DSC *string;
{
    CHAR string1[80];
    ho_date_tag(string1);
    CSTODSC(string1,string);
}

#endif
#if UNIX
publicdef INT hog_date_tag_(string,len)
CHAR *string;
INT len;
{
    CHAR string1[80];
    ho_date_tag(string1);
    ctofstr(string,string1,len);
}

#endif
#ifdef primos

CHAR *hog_date_tag(buffer,z1)
CHAR *buffer;
INT z1;
{
    CHAR string1[MAXLEN];

    ho_date_tag(string1);
    ctofstr((CHAR *)&buffer,string1,z1);
}

#endif

                                                                
