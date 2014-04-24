/* DEC/CMS REPLACEMENT HISTORY, Element NLGSORT_TAB.C */
/* *2     9-AUG-1990 19:12:28 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:26:33 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGSORT_TAB.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SORT_table.C*/
/* *2    11-AUG-1989 16:05:19 GORDON "(SPR 101) Quiet compiler info messages"*/
/* *1    21-JUL-1989 09:39:54 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SORT_table.C*/

/******************************************************************************

                Copyright Finder Graphic Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphic Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphic, Inc.
			579 Market Street
			San Francisco, CA  USA 94105
			(415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#include "esi_nl.h"

#ifdef vms
publicdef INT nlg_sort_table(nlist, nCol, Col_List, sortflag, outlist)
NLIST_HEADER *nlist,*outlist;
UINT *nCol,*Col_List;
INT *sortflag;
{
    return nl_sort_table(*nlist,*nCol,Col_List,sortflag,outlist);
}
#endif

#if UNIX
publicdef INT nlg_sort_table_(nlist, nCol, Col_List, sortflag, outlist)
NLIST_HEADER *nlist,*outlist;
UINT *nCol,*Col_List;
INT *sortflag;
{
    return nl_sort_table(*nlist,*nCol,Col_List,sortflag,outlist);
}
#endif

#ifdef primos
publicdef INT nlg_sort_table(nlist, nCol, Col_List, sortflag, outlist)
NLIST_HEADER nlist,outlist;
UINT nCol,Col_List;
INT sortflag;
{
    return nl_sort_table(nlist,nCol,&Col_List,&sortflag,&outlist);
}
#endif
