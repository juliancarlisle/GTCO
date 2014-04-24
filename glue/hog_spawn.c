/* DEC/CMS REPLACEMENT HISTORY, Element HOG_SPAWN.C*/
/* *3     9-AUG-1990 19:07:11 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:46 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:46:06 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_SPAWN.C*/

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
publicdef INT hog_spawn(type,file,args,user)
INT *type;
DSC *file,*args;
INT *user;
{
    INT status;
    CHAR string1[MAXLEN],string2[MAXLEN];
    DSCTOCS(file,string1);
    DSCTOCS(args,string2);
    status = ho_spawn(*type,string1,string2,user);
    return status;
}

#endif

#if UNIX
publicdef INT hog_spawn_(type,file,args,user,len1, len2)
INT *type;
CHAR *file,*args;
INT *user;
INT len1, len2;
{
    INT status;
    CHAR string1[MAXLEN],string2[MAXLEN];

    ftocstr(file,string1,len1);
    ftocstr(args,string2,len2);
    status = ho_spawn(*type,string1,string2,user);
    return status;
}

#endif

#ifdef primos

publicdef INT hog_spawn(type,filename,args,user,z1,z2,z3,z4)
INT type;
CHAR *filename;
CHAR *args;
INT user;
INT z1,z2,z3,z4;
{
    extern INT ho_spawn();
    INT ret;
    CHAR string1[MAXLEN];
    CHAR string2[MAXLEN];

    ftocstr((CHAR *)&filename,string1,z2);
    ftocstr((CHAR *)&args,string2,z3);
    ret = ho_spawn(type,string1,string2,&user);
    ctofstr((CHAR *)&filename,string1,z2);
    ctofstr((CHAR *)&args,string2,z3);
    return(ret);
}

#endif

                      
