/* DEC/CMS REPLACEMENT HISTORY, Element WIGRQINT.C*/
/* *3     9-AUG-1990 19:18:24 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:07:23 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:15:32 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGRQINT.C*/

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
publicdef INT wigrqint(prompt,help,min,max,def,value,stat)
DSC *prompt,*help;
INT *min,*max,*def,*value,*stat;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];

    DSCTOCS(prompt,string1);
    DSCTOCS(help,string2);
    return wirqint(string1,string2,*min,*max,*def,value,stat);
}
#endif
#if UNIX
publicdef INT wigrqint_(prompt,help,min,max,def,value,stat,l1,l2)
CHAR *prompt,*help;
INT *min,*max,*def,*value,*stat;
INT l1,l2;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];

    ftocstr(prompt,string1,l1);
    ftocstr(help,string2,l2);
    return wirqint(string1,string2,*min,*max,*def,value,stat);
}
#endif
#ifdef primos
publicdef INT wigrqint(prompt,help,min,max,def,value,stat,z1,z2,z3,z4,z5,z6,z7)
CHAR *prompt,*help;
INT min,max,def,value,stat;
INT z1,z2,z3,z4,z5,z6,z7;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];

    ftocstr((CHAR *)&prompt,string1,z1);
    ftocstr((CHAR *)&help,string2,z2);
    return wirqint(string1,string2,min,max,def,&value,&stat);
}
#endif

