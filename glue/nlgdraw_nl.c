/* DEC/CMS REPLACEMENT HISTORY, Element NLGDRAW_NL.C */
/* *2     9-AUG-1990 19:09:17 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:26 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGDRAW_NL.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_DRAW_NLIST.C*/
/* *2    28-JUL-1989 14:48:31 GORDON "(SPR 101) Quiet compiler's info messages"*/
/* *1    21-JUL-1989 09:37:09 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_DRAW_NLIST.C*/

/******************************************************************************

                Copyright Exploration Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Exploration Systems, Inc.
			579 Market Street
			San Francisco, CA  USA 94105
			(415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#include "esi_nl.h"

#ifdef vms

publicdef INT nlg_draw_nlist(nlist,xdim,ydim)
NLIST_HEADER *nlist;
UINT *xdim,*ydim;
{
    return nl_draw_nlist(*nlist,*xdim,*ydim);
}
#endif

#if UNIX

publicdef INT nlg_draw_nlist_(nlist,xdim,ydim)
NLIST_HEADER *nlist;
UINT *xdim,*ydim;
{
    return nl_draw_nlist(*nlist,*xdim,*ydim);
}
#endif

#ifdef primos
publicdef INT nlg_draw_nlist(nlist,xdim,ydim)
NLIST_HEADER nlist;
UINT xdim,ydim;
{
    return nl_draw_nlist(nlist,xdim,ydim);
}
#endif
