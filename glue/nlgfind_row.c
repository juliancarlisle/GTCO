/* DEC/CMS REPLACEMENT HISTORY, Element NLGFIND_ROW.C */
/* *2     9-AUG-1990 19:09:26 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:33 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGFIND_ROW.C */
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

/***********************************************************************
 nlg_find_row */

#ifdef vms
INT nlg_find_row(nlist, nCol, Col_List, Var_List)
NLIST_HEADER *nlist;
UINT *nCol,*Col_List;
DOUBLE *Var_List;
{
    INT status;
    FLOAT **newval;

    mk_int(Var_List,&newval,*nCol);
    status = nl_find_row(*nlist, *nCol, Col_List, newval);
    tc_free(newval);
    return status;
}
#endif

#if UNIX
INT nlg_find_row_(nlist, nCol, Col_List, Var_List)
NLIST_HEADER *nlist;
UINT *nCol,*Col_List;
DOUBLE *Var_List;
{
    INT status;
    FLOAT **newval;

    mk_int(Var_List,&newval,*nCol);
    status = nl_find_row(*nlist, *nCol, Col_List, newval);
    tc_free(newval);
    return status;
}
#endif

#ifdef primos
publicdef INT nlg_find_row(nlist, nCol, Col_List, Var_List)
NLIST_HEADER nlist;
UINT nCol,Col_List;
DOUBLE Var_List;
{
    INT status;
    FLOAT **newval;

    mk_int(&Var_List,&newval,nCol);
    status = nl_find_row(nlist, nCol, &Col_List, newval);
    tc_free(newval);
    return status;
}
#endif
