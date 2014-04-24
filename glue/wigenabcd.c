/* DEC/CMS REPLACEMENT HISTORY, Element WIGENABCD.C*/
/* *3     9-AUG-1990 19:16:58 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:06:18 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:14:19 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGENABCD.C*/

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

#ifdef vms
publicdef INT wigenabcd(id,boolean)
INT *id,*boolean;
{
    return wi_enable_dialog(*id,*boolean);
}
#endif
#if UNIX
publicdef INT wigenabcd_(id,boolean)
INT *id,*boolean;
{
    return wi_enable_dialog(*id,*boolean);
}
#endif
#ifdef primos
publicdef INT wigenabcd(id,boolean)
INT id,boolean;
{
    return wienabcd(id,boolean);
}
#endif

