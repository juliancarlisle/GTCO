/* DEC/CMS REPLACEMENT HISTORY, Element WMGOINQ.C*/
/* *3     9-AUG-1990 19:21:08 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:09:26 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:09:43 GILLESPIE "Fortran bindings for Window Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WMGOINQ.C*/

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
VOID wmgoinq(object,class,dbastr,usrstr)
INT *object,*class;
DSC *dbastr,*usrstr;
{
	CHAR string1[STMAX];
	CHAR string2[STMAX];
		
    wmoinq(*object,class,string1,string2);
    CSTODSC(string1,dbastr);
    CSTODSC(string2,usrstr);
}
#endif
#if UNIX
VOID wmgoinq_(object,class,dbastr,usrstr,len1,len2)
INT *object,*class;
CHAR *dbastr,*usrstr;
INT len1, len2;
{
	CHAR string1[STMAX];
	CHAR string2[STMAX];
		
    wmoinq(*object,class,string1,string2);
    ftocstr(dbastr,string1,len1);
    ftocstr(usrstr,string2,len2);
}
#endif
#ifdef primos
VOID wmgoinq(object,class,dbastr,usrstr,z1,z2,z3,z4)
INT object,class;
CHAR *dbastr,*usrstr;
INT  z1,z2,z3,z4;
{
	CHAR string1[STMAX];
	CHAR string2[STMAX];
		
    wmoinq(object,&class,string1,string2);
    ctofstr((CHAR *)&dbastr,string1,z3);
    ctofstr((CHAR *)&usrstr,string2,z4);
}
#endif

