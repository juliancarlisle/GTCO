/* DEC/CMS REPLACEMENT HISTORY, Element WIG_S_CDCLKBK.C*/
/* *3     9-AUG-1990 19:20:20 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:08:45 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:17:12 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIG_S_CDCLKBK.C*/

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
publicdef INT wig_set_cd_clickback(id,boolean)
INT *id,*boolean;
{
    return wi_set_cd_clickback(*id,*boolean);
}
#endif
#if UNIX
publicdef INT wig_set_cd_clickback_(id,boolean)
INT *id,*boolean;
{
    return wi_set_cd_clickback(*id,*boolean);
}
#endif
#ifdef primos
publicdef INT wig_set_cd_clickback(id,boolean)
INT id,boolean;
{
    return wi_set_cd_clickback(id,boolean);
}
#endif

