/* DEC/CMS REPLACEMENT HISTORY, Element WIGRQST.C*/
/* *3     9-AUG-1990 19:18:33 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:07:29 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:15:40 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGRQST.C*/

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
publicdef INT wigrqst(prompt,def,help,maxlen,text,stat)
DSC *prompt,*def,*help,*text;
INT *maxlen,*stat;
{
    INT status;
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];
	CHAR string3[MAXLEN];
	CHAR string4[MAXLEN];

    DSCTOCS(prompt,string1);
    DSCTOCS(def,string2);
    DSCTOCS(help,string3);
    status = wirqst(string1,string2,string3,*maxlen,string4,stat);
    if (status EQUALS SUCCESS)
		{
		CSTODSC(string4,text);
		}
    return status;
}
#endif
#if UNIX
publicdef INT wigrqst_(prompt,def,help,maxlen,text,stat,l1,l2,l3,l4)
CHAR *prompt,*def,*help,*text;
INT *maxlen,*stat;
INT l1,l2,l3,l4;
{
    INT status;
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];
	CHAR string3[MAXLEN];
	CHAR string4[MAXLEN];

    ftocstr(prompt,string1,l1);
    ftocstr(def,string2,l2);
    ftocstr(help,string3,l3);
    status = wirqst(string1,string2,string3,*maxlen,string4,stat);
    if (status EQUALS SUCCESS)
		{
		ctofstr(text,string4,l4);
		}
    return status;
}
#endif
#ifdef primos
publicdef INT wigrqst(prompt,def,help,maxlen,text,stat,z1,z2,z3,z4,z5)
CHAR prompt,def,help,text;
INT maxlen,stat;
INT z1,z2,z3,z4,z5;
{
    INT status;
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];
	CHAR string3[MAXLEN];
	CHAR string4[MAXLEN];

    ftocstr(&prompt,string1,z1);
    ftocstr(&def,string2,z2);
    ftocstr(&help,string3,z3);
    status = wirqst(string1,string2,string3,maxlen,string4,&stat);
    if (status EQUALS SUCCESS)
		{
		ctofstr(&text,string4,z5);
		}
    return status;
}
#endif

