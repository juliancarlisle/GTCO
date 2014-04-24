/* DEC/CMS REPLACEMENT HISTORY, Element NLGPRG_TAB.C */
/* *2     9-AUG-1990 19:10:17 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:24:49 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGPRG_TAB.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_PURGE_table.C*/
/* *1    21-JUL-1989 09:38:53 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_PURGE_table.C*/

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

publicdef INT nlg_purge_table(nlist, table_num)
NLIST_HEADER *nlist;
INT *table_num;
{
    return nl_purge_table(*nlist, *table_num);
}
#endif
#if UNIX

publicdef INT nlg_purge_table_(nlist, table_num)
NLIST_HEADER *nlist;
INT *table_num;
{
    return nl_purge_table(*nlist, *table_num);
}
#endif
#ifdef primos

publicdef INT nlg_purge_table(nlist, table_num)
NLIST_HEADER nlist;
INT table_num;
{
    return nl_purge_table(nlist, table_num);
}
#endif
