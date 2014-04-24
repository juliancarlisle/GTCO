/* DEC/CMS REPLACEMENT HISTORY, Element NLGGET_ROWSC.C */
/* *2     9-AUG-1990 19:09:37 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:53 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGGET_ROWSC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_GET_rowS_CONVERT.C*/
/* *3    24-OCT-1989 15:18:27 PURNA "(SPR 0) resolve compiling error"*/
/* *2    28-JUL-1989 15:10:31 GORDON "(SPR 101) Quiet compiler's info messages"*/
/* *1    21-JUL-1989 09:37:29 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_GET_rowS_CONVERT.C*/

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
publicdef INT nlg_get_rows_convert(nlist, nalloc, nCol, Col_List,
			     Var_List, units, datasize, datatype, nrows)
NLIST_HEADER *nlist;
UINT *nalloc, *nCol, *Col_List, *nrows;
INT *units, *datasize, *datatype;
DOUBLE *Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List,&newval,*nCol);
    status = nl_get_rows_convert(*nlist,*nalloc,*nCol,Col_List,newval,
				   units,(size_t *)datasize,datatype,nrows);
    tc_free(newval);
    return status;
}
#endif

#if UNIX
publicdef INT nlg_get_rows_convert_(nlist, nalloc, nCol, Col_List,
			     Var_List, units, datasize, datatype, nrows)
NLIST_HEADER *nlist;
UINT *nalloc, *nCol, *Col_List, *nrows;
INT *units, *datasize, *datatype;
DOUBLE *Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List,&newval,*nCol);
    status = nl_get_rows_convert(*nlist,*nalloc,*nCol,Col_List,newval,
				   units,datasize,datatype,nrows);
    tc_free(newval);
    return status;
}
#endif

#ifdef primos
publicdef INT nlg_get_rows_convert(nlist, nalloc, nCol, Col_List,
			    Var_List, units,datasize, datatype, nrows)
NLIST_HEADER nlist;
UINT nalloc, nCol, Col_List, nrows;
INT units, datasize, datatype;
DOUBLE Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(&Var_List,&newval,nCol);
    status = nl_get_rows_convert(nlist,nalloc,nCol,&Col_List,newval,
				   &units,&datasize,&datatype,&nrows);
    tc_free(newval);
    return status;
}
#endif
