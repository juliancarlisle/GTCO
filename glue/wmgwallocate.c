/* DEC/CMS REPLACEMENT HISTORY, Element WMGWALLOCATE.C*/
/* *3     9-AUG-1990 19:23:36 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:11:15 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:11:57 GILLESPIE "Fortran bindings for Window Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WMGWALLOCATE.C*/

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
VOID wmgwallocate(window, ndcx1, ndcx2, ndcy1, ndcy2, color)
INT *window;
FLOAT *ndcx1,*ndcx2,*ndcy1,*ndcy2;
INT *color;
{
    wmwallocate(window, *ndcx1, *ndcx2, *ndcy1, *ndcy2, *color);
}
#endif
#if UNIX
VOID wmgwallocate_(window, ndcx1, ndcx2, ndcy1, ndcy2, color)
INT *window;
FLOAT *ndcx1,*ndcx2,*ndcy1,*ndcy2;
INT *color;
{
    wmwallocate(window, *ndcx1, *ndcx2, *ndcy1, *ndcy2, *color);
}
#endif
#ifdef primos
VOID wmgwallocate(window, ndcx1, ndcx2, ndcy1, ndcy2, color)
INT window;
FLOAT ndcx1,ndcx2,ndcy1,ndcy2;
INT color;
{
    wmwallocate(&window, (FLOAT)ndcx1, (FLOAT)ndcx2, (FLOAT)ndcy1,
		(FLOAT)ndcy2, color);
}
#endif

