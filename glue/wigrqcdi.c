/* DEC/CMS REPLACEMENT HISTORY, Element WIGRQCDI.C*/
/* *3     9-AUG-1990 19:18:16 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:07:16 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:15:26 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGRQCDI.C*/

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
publicdef INT wigrqcdi(id,control,value,text)
INT *id,*control,*value;
DSC *text;
{
	CHAR string1[MAXLEN];
    INT status;

    status = wirqcdi(id,control,value,string1);
    if(status EQUALS SUCCESS)
		{
		CSTODSC(string1,text);
		}
    return status;
}
#endif
#if UNIX
publicdef INT wigrqcdi_(id,control,value,text,len)
INT *id,*control,*value;
CHAR *text;
INT len;
{
	CHAR string1[MAXLEN];
    INT status;

    status = wirqcdi(id,control,value,string1);
    if(status EQUALS SUCCESS)
		{
		ctofstr(text,string1,len);
		}
    return status;
}
#endif
#ifdef primos
publicdef INT wigrqcdi(id,control,value,text,z1,z2,z3,z4)
INT id,control,value;
CHAR *text;
INT z1,z2,z3,z4;
{
	CHAR string1[MAXLEN];
    INT status;

    status = wirqcdi(&id,&control,&value,string1);
    if(status EQUALS SUCCESS)
		{
		ctofstr((CHAR *)&text,string1,z4);
		}
    return status;
}
#endif

