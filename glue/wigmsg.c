/* DEC/CMS REPLACEMENT HISTORY, Element WIGMSG.C*/
/* *3     9-AUG-1990 19:17:23 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:06:38 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:14:42 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGMSG.C*/

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

publicdef INT wigmsg(text)
DSC *text;
{
	CHAR string1[MAXLEN];
    DSCTOCS(text,string1);
    return wimsg(string1);
}
#endif
#if UNIX
publicdef INT wigmsg_(text,len)
CHAR *text;
INT len;
{
	CHAR string1[MAXLEN];
    ftocstr(text,string1,len);
    return wimsg(string1);
}
#endif
#ifdef primos
publicdef INT wigmsg(text,z1)
CHAR *text;
INT z1;
{
	CHAR string1[MAXLEN];
    ftocstr((CHAR *)&text,string1,z1);
    return wimsg(string1);
}
#endif

