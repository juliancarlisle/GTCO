/* DEC/CMS REPLACEMENT HISTORY, Element WMGWINQ.C*/
/* *3     9-AUG-1990 19:24:07 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:11:45 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:12:36 GILLESPIE "Fortran bindings for Window Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WMGWINQ.C*/

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
VOID wmgwinq(window, ndcx1, ndcx2, ndcy1, ndcy2, color)
INT *window;
FLOAT *ndcx1,*ndcx2,*ndcy1,*ndcy2;
INT *color;
{
    wmwinq(*window, ndcx1, ndcx2, ndcy1, ndcy2, color);
}
#endif
#if UNIX
VOID wmgwinq_(window, ndcx1, ndcx2, ndcy1, ndcy2, color)
INT *window;
FLOAT *ndcx1,*ndcx2,*ndcy1,*ndcy2;
INT *color;
{
    wmwinq(*window, ndcx1, ndcx2, ndcy1, ndcy2, color);
}
#endif
#ifdef primos
VOID wmgwinq(window, ndcx1, ndcx2, ndcy1, ndcy2, color)
INT window;
FLOAT ndcx1,ndcx2,ndcy1,ndcy2;
INT color;
{
    wmwinq(window, &ndcx1, &ndcx2, &ndcy1, &ndcy2, &color);
}
#endif

