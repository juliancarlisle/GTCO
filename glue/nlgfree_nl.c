/* DEC/CMS REPLACEMENT HISTORY, Element NLGFREE_NL.C */
/* *2     9-AUG-1990 19:09:32 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:42 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGFREE_NL.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_FREE_NLIST.C*/
/* *1    21-JUL-1989 09:37:22 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_FREE_NLIST.C*/

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
INT nlg_free_nlist(nlist)
NLIST_HEADER *nlist;
{
    return nl_free_nlist(*nlist);
}
#endif

#if UNIX
INT nlg_free_nlist_(nlist)
NLIST_HEADER *nlist;
{
    return nl_free_nlist(*nlist);
}
#endif

#ifdef primos
publicdef INT nlg_free_nlist(nlist)
NLIST_HEADER nlist;
{
    return nl_free_nlist(nlist);
}
#endif
