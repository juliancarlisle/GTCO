/* DEC/CMS REPLACEMENT HISTORY, Element WIGALERT.C*/
/* *3     9-AUG-1990 19:16:40 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:06:04 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:14:04 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGALERT.C*/

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
publicdef INT wigalert(level,help,msg1,msg2)
INT *level;
DSC *help,*msg1,*msg2;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];
	CHAR string3[MAXLEN];

    DSCTOCS(help,string1);
    DSCTOCS(msg1,string2);
    DSCTOCS(msg2,string3);
    return wialert(*level,string1,string2,string3);
}
#endif
#if UNIX
publicdef INT wigalert_(level,help,msg1,msg2,l1,l2,l3)
INT *level;
CHAR *help,*msg1,*msg2;
INT l1,l2,l3;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];
	CHAR string3[MAXLEN];

    ftocstr(help,string1,l1);
    ftocstr(msg1,string2,l2);
    ftocstr(msg2,string3,l3);
    return wialert(*level,string1,string2,string3);
}
#endif
#ifdef primos
publicdef INT wigalert(level,help,msg1,msg2,z1,z2,z3,z4)
INT level;
CHAR *help,*msg1,*msg2;
INT z1,z2,z3,z4;
{
	CHAR string1[MAXLEN];
	CHAR string2[MAXLEN];
	CHAR string3[MAXLEN];

    ftocstr((CHAR *)&help,string1,z2);
    ftocstr((CHAR *)&msg1,string2,z3);
    ftocstr((CHAR *)&msg2,string3,z4);
    return wialert(level,string1,string2,string3);
}

#endif

