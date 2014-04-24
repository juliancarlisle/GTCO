/* DEC/CMS REPLACEMENT HISTORY, Element HOG_ADD_PATH.C*/
/* *3     9-AUG-1990 19:06:53 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:26 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:45:42 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_ADD_PATH.C*/

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
publicdef INT hog_add_path(logical,filename,maxchars,full_filename)
DSC *logical,*filename;
INT *maxchars;
DSC *full_filename;
{
    INT status;
    CHAR string1[MAXLEN],string2[MAXLEN],string3[MAXLEN];
    DSCTOCS(logical,string1);
    DSCTOCS(filename,string2);
    status = ho_add_path(string1,string2,*maxchars,string3);
    if(status == SUCCESS)
       {
       CSTODSC(string3,full_filename);
       }
    return status;
}

#endif
#if UNIX
publicdef INT hog_add_path_(logical,filename,maxchars,full_filename,
	len1, len2, len3)
CHAR *logical,*filename;
INT *maxchars;
CHAR *full_filename;
INT len1, len2, len3;
{
    INT status;
    CHAR string1[MAXLEN],string2[MAXLEN],string3[MAXLEN];
    ftocstr(logical,string1,len1);
    ftocstr(filename,string2,len2);
    status = ho_add_path(string1,string2,*maxchars,string3);
    if(status == SUCCESS)
       {
       ctofstr(full_filename,string3,len3);
       }
    return status;
}

#endif
#ifdef primos

publicdef INT hog_add_path(logical,filename,maxchars,full_filename,z1,z2
	,z3,z4)
CHAR *logical;
CHAR *filename;
INT maxchars;
CHAR *full_filename;
INT z1,z2,z3,z4;
{
    extern INT ho_add_path();
    INT ret;
    CHAR string1[MAXLEN];
    CHAR string2[MAXLEN];
    CHAR string3[MAXLEN];

    ftocstr((CHAR *)&logical,string1,z1);
    ftocstr((CHAR *)&filename,string2,z2);
    ftocstr((CHAR *)&full_filename,string3,z4);
    ret = ho_add_path(string1,string2,maxchars,string3);
    ctofstr((CHAR *)&logical,string1,z1);
    ctofstr((CHAR *)&filename,string2,z2);
    ctofstr((CHAR *)&full_filename,string3,z4);
    return(ret);
}

#endif
                                                                                  
