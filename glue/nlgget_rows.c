/* DEC/CMS REPLACEMENT HISTORY, Element NLGGET_ROWS.C */
/* *2     9-AUG-1990 19:09:34 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:46 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGGET_ROWS.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_GET_rowS.C*/
/* *3    28-JUL-1989 15:09:27 GORDON "(SPR 101) Quiet compiler's info messages"*/
/* *2    28-JUL-1989 14:58:44 GORDON "(SPR 101) Quiet compiler's info messages"*/
/* *1    21-JUL-1989 09:37:26 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_GET_rowS.C*/

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

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifdef vms
publicdef INT nlg_get_rows(nlist, nalloc, nCol, Col_List, Var_List, nrows)
NLIST_HEADER *nlist;
UINT *nalloc, *nCol, *Col_List, *nrows;
DOUBLE *Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List, &newval, *nCol);
    status = nl_get_rows(*nlist, *nalloc, *nCol, Col_List, newval, nrows);
    tc_free(newval);
    return status;
}
#endif

#if UNIX
publicdef INT nlg_get_rows_(nlist, nalloc, nCol, Col_List, Var_List, nrows)
NLIST_HEADER *nlist;
UINT *nalloc, *nCol, *Col_List, *nrows;
DOUBLE *Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List, &newval, *nCol);
    status = nl_get_rows(*nlist, *nalloc, *nCol, Col_List, newval, nrows);
    tc_free(newval);
    return status;
}
#endif

#ifdef primos
publicdef INT nlg_get_rows(nlist, nalloc, nCol, Col_List, Var_List, nrows)
NLIST_HEADER nlist;
UINT nalloc, nCol, Col_List, nrows;
DOUBLE Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(&Var_List, &newval, nCol);
    status = nl_get_rows(nlist, nalloc, nCol, &Col_List, newval, &nrows);
    tc_free(newval);
    return status;
}
#endif
