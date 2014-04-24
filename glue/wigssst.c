/* DEC/CMS REPLACEMENT HISTORY, Element WIGSSST.C*/
/* *3     9-AUG-1990 19:19:12 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:07:56 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:16:12 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGSSST.C*/

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
publicdef INT wigssst(helpkey,numsel,maxsel,carray)
DSC *helpkey;
INT *numsel,*maxsel;
TSG_TCP **carray;
{
	CHAR string1[MAXLEN];

    DSCTOCS(helpkey,string1);
    return wissst(string1,*numsel,*maxsel,(*carray) ->tcp);
}
#endif
#if UNIX
publicdef INT wigssst_(helpkey,numsel,maxsel,carray,z1)
CHAR *helpkey;
INT *numsel,*maxsel;
TSG_TCP **carray;
INT z1;
{
	CHAR string1[MAXLEN];

    ftocstr(helpkey,string1, z1);
    return wissst(string1,*numsel,*maxsel,(*carray) ->tcp);
}
#endif
#ifdef primos
#ifndef ESI_TS_H
#include "esi_ts.h"
#endif

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

publicdef INT wigsst(helpkey,numsel,maxsel,carray,z1,z2,z3,z4)
INT numsel,maxsel;
CHAR helpkey;
CHAR carray;
INT z1, z2, z3, z4;
{
    CHAR **tcp,**ptcp;
    CHAR *src = (CHAR *)&carray;
    INT i;
    INT status;

    ftocstr(&helpkey,string1,z1);
    tcp = ptcp = ts_tcp_alloc(numsel+1);
    srclen = z4 & 0xff;
    deslen = srclen + 1;
    for(i=0; i < numsel; i++, ptcp++)
	{
	*ptcp = (CHAR *)tc_alloc(deslen);
	strncpy(*ptcp,src + (i * srclen),srclen);
	}

    status = wissst(string1,numsel,maxsel,tcp);
    ts_tcp_free(tcp);
    return status;
}
#endif

