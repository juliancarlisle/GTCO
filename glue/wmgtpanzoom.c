/* DEC/CMS REPLACEMENT HISTORY, Element WMGTPANZOOM.C*/
/* *3     9-AUG-1990 19:23:03 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:10:50 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:11:25 GILLESPIE "Fortran bindings for Window Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WMGTPANZOOM.C*/

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

#include "esi_wm.h"

#ifdef vms
VOID wmgtpanzoom(tnr,wcsxcenter,wcsycenter,wcsxscale,wcsyscale)
INT *tnr;
FLOAT *wcsxcenter,*wcsycenter,*wcsxscale,*wcsyscale;
{
    wmtpanzoom(*tnr,*wcsxcenter,*wcsycenter,*wcsxscale,*wcsyscale);
}
#endif
#if UNIX
VOID wmgtpanzoom_(tnr,wcsxcenter,wcsycenter,wcsxscale,wcsyscale)
INT *tnr;
FLOAT *wcsxcenter,*wcsycenter,*wcsxscale,*wcsyscale;
{
    wmtpanzoom(*tnr,*wcsxcenter,*wcsycenter,*wcsxscale,*wcsyscale);
}
#endif
#ifdef primos
VOID wmgtpanzoom(tnr,wcsxcenter,wcsycenter,wcsxscale,wcsyscale)
INT tnr;
FLOAT wcsxcenter,wcsycenter,wcsxscale,wcsyscale;
{
    wmtpanzoom(tnr,wcsxcenter,wcsycenter,wcsxscale,wcsyscale);
}
#endif

