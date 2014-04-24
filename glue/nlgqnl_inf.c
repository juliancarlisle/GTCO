/* DEC/CMS REPLACEMENT HISTORY, Element NLGQNL_INF.C */
/* *2     9-AUG-1990 19:10:29 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:25:02 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGQNL_INF.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_NLIST_INFO.C*/
/* *2    31-JUL-1989 13:39:27 GORDON "(SPR 101) Quiet compiler info messages"*/
/* *1    21-JUL-1989 09:37:43 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_NLIST_INFO.C*/

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

publicdef INT nlg_inq_nlist_info(nlist, opcode, ndim, dim_list, val_list)
NLIST_HEADER *nlist;
INT *opcode;
UINT *ndim, *dim_list;
DOUBLE *val_list;
{
    INT status;
    VOIDPTR *newval;

    mk_int(val_list,&newval,*ndim);
    status = nl_inq_nlist_info(*nlist,*opcode,*ndim,dim_list,newval);
    tc_free(newval);
    return status;
}
#endif

#if UNIX

publicdef INT nlg_inq_nlist_info_(nlist, opcode, ndim, dim_list, val_list)
NLIST_HEADER *nlist;
INT *opcode;
UINT *ndim, *dim_list;
DOUBLE *val_list;
{
    INT status;
    VOIDPTR *newval;

    mk_int(val_list,&newval,*ndim);
    status = nl_inq_nlist_info(*nlist,*opcode,*ndim,dim_list,newval);
    tc_free(newval);
    return status;
}
#endif

#ifdef primos
publicdef INT nlg_inq_nlist_info(nlist, opcode, ndim, dim_list, val_list)
NLIST_HEADER nlist;
INT opcode;
UINT ndim, dim_list;
DOUBLE val_list;
{
    INT status;
    VOIDPTR *newval;

    mk_int(&val_list,&newval,ndim);
    status = nl_inq_nlist_info(nlist,opcode,ndim,&dim_list,newval);
    tc_free(newval);
    return status;
}
#endif
