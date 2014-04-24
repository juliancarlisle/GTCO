/* DEC/CMS REPLACEMENT HISTORY, Element WIGQCCDI.C*/
/* *3     9-AUG-1990 19:17:38 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:06:50 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:14:56 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGQCCDI.C*/

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
publicdef INT wigqccdi(id, item, value, text)
INT *id,*item,*value;
DSC *text;
{
    INT status;
	CHAR string1[MAXLEN];

    status = wiqccdi(*id,*item,value,string1);
    if(status EQUALS SUCCESS)
		{
		CSTODSC(string1,text);
		}
    return status;
}
#endif
#if UNIX
publicdef INT wigqccdi_(id, item, value, text,len)
INT *id,*item,*value;
CHAR *text;
INT len;
{
    INT status;
	CHAR string1[MAXLEN];

    status = wiqccdi(*id,*item,value,string1);
    if(status EQUALS SUCCESS)
		{
		ctofstr(text,string1,len);
		}
    return status;
}
#endif
#ifdef primos
publicdef INT wigqccdi(id, item, value, text, z1, z2, z3, z4)
INT id,item,value;
CHAR *text;
INT z1, z2, z3, z4;
{
    INT status;
	CHAR string1[MAXLEN];

    status = wiqccdi(id,item,&value,string1);
    if(status EQUALS SUCCESS)
		{
		ctofstr((CHAR *)&text,string1,z4);
		}
    return status;
}
#endif

