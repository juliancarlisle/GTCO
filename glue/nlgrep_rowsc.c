/* DEC/CMS REPLACEMENT HISTORY, Element NLGREP_ROWSC.C */
/* *2     9-AUG-1990 19:11:48 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:26:02 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGREP_ROWSC.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_REPLACE_rowS_CONVERT.C*/
/* *2    11-AUG-1989 15:54:38 GORDON "(SPR 101) Quiet compiler info messages"*/
/* *1    21-JUL-1989 09:39:07 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_REPLACE_rowS_CONVERT.C*/

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
publicdef INT nlg_replace_rows_convert(nlist,nrows, nCol, Col_List,
					 Var_List, units, datasize, datatype)
NLIST_HEADER *nlist;
UINT  *nCol, *Col_List, *datasize, *nrows;
INT *units, *datatype;
DOUBLE *Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List,&newval,*nCol);
    status = nl_replace_rows_convert(*nlist,*nrows,*nCol,Col_List,newval,
				   units,(size_t*)datasize,datatype);
    tc_free(newval);
    return status;
}
#endif

#if UNIX
publicdef INT nlg_replace_rows_convert_(nlist,nrows, nCol, Col_List,
					 Var_List, units, datasize, datatype)
NLIST_HEADER *nlist;
UINT  *nCol, *Col_List, *datasize, *nrows;
INT *units, *datatype;
DOUBLE *Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(Var_List,&newval,*nCol);
    status = nl_replace_rows_convert(*nlist,*nrows,*nCol,Col_List,newval,
				   units,datasize,datatype);
    tc_free(newval);
    return status;
}
#endif

#ifdef primos
publicdef INT nlg_replace_rows_convert(nlist,nrows, nCol, Col_List,
					 Var_List, units, datasize, datatype)
NLIST_HEADER nlist;
UINT  nCol, Col_List, datasize, nrows;
INT units, datatype;
DOUBLE Var_List;
{
    INT status;
    VOIDPTR *newval;

    mk_int(&Var_List,&newval,nCol);
    status = nl_replace_rows_convert(nlist,nrows,nCol,&Col_List,newval,
				   &units,&datasize,&datatype);
    tc_free(newval);
    return status;
}
#endif
