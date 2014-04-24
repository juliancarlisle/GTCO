/* DEC/CMS REPLACEMENT HISTORY, Element NLGCOPY_TAB.C */
/* *2     9-AUG-1990 19:09:02 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:11 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGCOPY_TAB.C */
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
publicdef INT nlg_copy_table(from_list,from_table,to_list,to_table)
NLIST_HEADER *from_list,*to_list;
UINT *from_table,*to_table;
{
    return nl_copy_table(*from_list,*from_table,*to_list,to_table);
}
#endif

#if UNIX
publicdef INT nlg_copy_table_(from_list,from_table,to_list,to_table)
NLIST_HEADER *from_list,*to_list;
UINT *from_table,*to_table;
{
    return nl_copy_table(*from_list,*from_table,*to_list,to_table);
}
#endif

#ifdef primos
publicdef INT nlg_copy_table(from_list,from_table,to_list,to_table)
NLIST_HEADER from_list,to_list;
UINT from_table,to_table;
{
    return nl_copy_table(&from_list,from_table,&to_list,&to_table);
}
#endif
