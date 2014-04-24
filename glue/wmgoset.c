/* DEC/CMS REPLACEMENT HISTORY, Element WMGOSET.C*/
/* *3     9-AUG-1990 19:21:26 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:09:38 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:09:58 GILLESPIE "Fortran bindings for Window Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WMGOSET.C*/

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

#include "esi_wm.h"
#include "esi_glue.h"

#ifdef vms
VOID wmgoset(object, class, dbastr, usrstr)
INT *object,*class;
DSC *dbastr,*usrstr;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];

    DSCTOCS(dbastr,string1);
    DSCTOCS(usrstr,string2);
    wmoset(*object,*class,string1,string2);
}
#endif
#if UNIX
VOID wmgoset_(object, class, dbastr, usrstr, len1, len2)
INT *object,*class;
CHAR *dbastr,*usrstr;
INT len1, len2;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];

    ftocstr(dbastr,string1,len1);
    ftocstr(usrstr,string2,len2);
    wmoset(*object,*class,string1,string2);
}
#endif
#ifdef primos
VOID wmgoset(object, class, dbastr, usrstr, z1, z2, z3, z4)
INT object,class;
CHAR *dbastr,*usrstr;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];

    ftocstr((CHAR *)&dbastr,string1, z3);
    ftocstr((CHAR *)&usrstr,string2, z4);
    wmoset(object,class,string1,string2);
}
#endif

