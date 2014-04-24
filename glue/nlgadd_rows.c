/* DEC/CMS REPLACEMENT HISTORY, Element NLGADD_ROWS.C */
/* *2     9-AUG-1990 19:08:45 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:22:53 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGADD_ROWS.C */

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

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

/***********************************************************************
 nlg_add_rows */

#ifdef vms

publicdef INT nlg_add_rows(nlist, nrows, nCol, Col_List, Var_List)
NLIST_HEADER *nlist;
INT *nrows,*nCol,*Col_List;
DOUBLE *Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List,&newval,*nCol);
    status = nl_add_rows(*nlist, *nrows, *nCol, (UINT *)Col_List, newval);
    tc_free(newval);
    return status;
}
#endif
#ifdef primos

publicdef INT nlg_add_rows(nlist, nrows, nCol, Col_List, Var_List)
NLIST_HEADER nlist;
INT nrows,nCol,Col_List;
DOUBLE Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(&Var_List,&newval,nCol);
    status = nl_add_rows(nlist, nrows, nCol, &Col_List, newval);
    tc_free(newval);
    return status;
}
#endif
#if UNIX
publicdef INT nlg_add_rows_(nlist, nrows, nCol, Col_List, Var_List)
NLIST_HEADER *nlist;
INT *nrows,*nCol,*Col_List;
DOUBLE *Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List,&newval,*nCol);
    status = nl_add_rows(*nlist, *nrows, *nCol, (UINT *)Col_List, newval);
    tc_free(newval);
    return status;
}
#endif

