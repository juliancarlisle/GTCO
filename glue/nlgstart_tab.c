/* DEC/CMS REPLACEMENT HISTORY, Element NLGSTART_TAB.C */
/* *2     9-AUG-1990 19:13:14 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:27:00 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGSTART_TAB.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_START_table.C*/
/* *2    24-OCT-1989 17:28:30 PURNA "(SPR 0) compiling error recovery"*/
/* *1    21-JUL-1989 09:39:58 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_START_table.C*/

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
publicdef INT nlg_start_table(nlist,table)
NLIST_HEADER *nlist;
INT *table;
{
    return nl_start_table(*nlist,(UINT *)table);
}
#endif

#if UNIX
publicdef INT nlg_start_table_(nlist,table)
NLIST_HEADER *nlist;
INT *table;
{
    return nl_start_table(*nlist,(UINT *)table);
}
#endif

#ifdef primos
publicdef INT nlg_start_table(nlist,table)
NLIST_HEADER nlist;
INT table;
{
    return nl_start_table(nlist,(UINT *)&table);
}
#endif
