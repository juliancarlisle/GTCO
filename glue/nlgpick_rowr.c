/* DEC/CMS REPLACEMENT HISTORY, Element NLGPICK_ROWR.C */
/* *2     9-AUG-1990 19:10:06 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:24:32 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGPICK_ROWR.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_PICK_table_RANGE.C*/
/* *1    21-JUL-1989 09:38:42 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_PICK_table_RANGE.C*/

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

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifdef vms
publicdef INT nlg_pick_table_range(nlist, nCol, Col_List, Var_List,
					 min, max, table_num, row_num)
NLIST_HEADER *nlist;
INT *nCol;   /* this version only handles 2 dims... */
INT *Col_List;
DOUBLE *Var_List;
DOUBLE *min, *max;
INT *table_num, *row_num;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List,newval,*nCol);
    status = nl_pick_table_range(*nlist, *nCol, Col_List, newval,
				    min, max, table_num, row_num);
    tc_free(newval);
    return status;

}
#endif

/* NOTE: Prime and UNIX code has not been written yet for this function. */

