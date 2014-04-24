/* DEC/CMS REPLACEMENT HISTORY, Element WIGRDFCD.C*/
/* *3     9-AUG-1990 19:17:54 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:07:02 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:15:13 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGRDFCD.C*/

/******************************************************************************

                Copyright Finder Graphic Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphic Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphic Systems, Inc.
			579 Market Street
			San Francisco, CA  USA 94105
			(415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#include "esi_wi.h"
#include "esi_glue.h"

#ifdef vms
publicdef INT wigrdfcd(resid,helpkey,numc,id)
INT *resid,*numc,*id;
DSC *helpkey;
{
	CHAR string1[MAXLEN];

    DSCTOCS(helpkey,string1);
    return wirdfcd(*resid,string1,numc,id);
}
#endif
#if UNIX
publicdef INT wigrdfcd_(resid,helpkey,numc,id,len)
INT *resid,*numc,*id;
CHAR *helpkey;
INT len;
{
	CHAR string1[MAXLEN];

    ftocstr(helpkey,string1,len);
    return wirdfcd(*resid,string1,numc,id);
}
#endif
#ifdef primos
publicdef INT wigrdfcd(resid,helpkey,numc,id,z1,z2,z3,z4)
INT resid,numc,id;
CHAR *helpkey;
INT z1,z2,z3,z4;
{
	CHAR string1[MAXLEN];

    ftocstr((CHAR *)&helpkey,string1,z4);
    return wirdfcd(resid,string1,&numc,&id);
}
#endif

