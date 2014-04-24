/* DEC/CMS REPLACEMENT HISTORY, Element WIGRQSS.C*/
/* *3     9-AUG-1990 19:18:29 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:07:26 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:15:36 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGRQSS.C*/

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
publicdef INT wigrqss(prompt,numsel,sel,stat)
DSC *prompt;
INT *numsel,*sel,*stat;
{
	CHAR string1[MAXLEN];

	DSCTOCS(prompt,string1);
	return wirqss(string1,numsel,sel,stat);
}
#endif
#if UNIX
publicdef INT wigrqss_(prompt,numsel,sel,stat,len)
CHAR *prompt;
INT *numsel,*sel,*stat;
INT len;
{
	CHAR string1[MAXLEN];

	ftocstr(prompt,string1,len);
	return wirqss(string1,numsel,sel,stat);
}
#endif
#ifdef primos
publicdef INT wigrqss(prompt,numsel,sel,stat,z1,z2,z3,z4)
CHAR *prompt;
INT numsel,sel,stat;
INT z1,z2,z3,z4;
{
	CHAR string1[MAXLEN];

	ftocstr((CHAR *)&prompt,string1,z1);
	return wirqss(string1,&numsel,&sel,&stat);
}
#endif

