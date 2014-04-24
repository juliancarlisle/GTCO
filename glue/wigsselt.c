/* DEC/CMS REPLACEMENT HISTORY, Element WIGSSELT.C*/
/* *3     9-AUG-1990 19:19:08 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:07:53 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:16:09 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGSSELT.C*/

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
publicdef INT wigsselt(id,selector,vscroll,numitems,maxsel,list)
INT *id, *selector, *vscroll, *numitems, *maxsel;
TSG_TCP **list;
{
    return wisselt(*id,*selector,*vscroll,*numitems,
			*maxsel, (*list) -> tcp);
}
#endif
#if UNIX
publicdef INT wigsselt_(id,selector,vscroll,numitems,maxsel,list)
INT *id, *selector, *vscroll, *numitems, *maxsel;
TSG_TCP **list;
{
    return wisselt(*id,*selector,*vscroll,*numitems,
			*maxsel, (*list) -> tcp);
}
#endif
#ifdef primos
#ifndef ESI_TS_H
#include "esi_ts.h"
#endif
#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

publicdef INT wigsselt(id,selector,vscroll,numitems,maxsel,list,
	      z1, z2, z3, z4, z5, z6)
INT id, selector, vscroll, numitems, maxsel;
CHAR list;
INT z1, z2, z3, z4, z5, z6;   /* low word of z6 is len of each string */
{
    INT i;
    CHAR **tcp,**ptcp;
    CHAR *src = (CHAR *)&list;
    INT status;

    tcp = ptcp = ts_tcp_alloc(numitems+1);  /* allow 1 for null terminator */
    srclen = z6 & 0xff;     /* get the fortran-declared size of each element */
    deslen = srclen + 1;
    for(i=0; i<numitems; i++, ptcp++)
	{
	*ptcp = (CHAR *)tc_zalloc(deslen);
	status = strncpy(*ptcp,src + (i * srclen),srclen);
	}

    wisselt(id,selector,vscroll,numitems,maxsel,tcp);
    ts_tcp_free(tcp);
    return status;
}
#endif

