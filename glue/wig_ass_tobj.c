/* DEC/CMS REPLACEMENT HISTORY, Element WIG_ASS_TOBJ.C*/
/* *3     9-AUG-1990 19:19:24 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:08:05 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:16:23 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIG_ASS_TOBJ.C*/

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
publicdef INT wig_assign_text_object(dialog, control, textid)
INT  *dialog, *control, *textid;
{
    return wi_assign_text_object(*dialog, *control, *textid);
}
#endif
#if UNIX
publicdef INT wig_assign_text_object_(dialog, control, textid)
INT  *dialog, *control, *textid;
{
    return wi_assign_text_object(*dialog, *control, *textid);
}
#endif
#ifdef primos
publicdef INT wig_assign_text_object_(dialog, control, textid)
INT  dialog, control, textid;
{
    return wi_assign_text_object(dialog, control, textid);
}
#endif

