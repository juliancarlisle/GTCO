/* DEC/CMS REPLACEMENT HISTORY, Element NLGOP_NL1.C */
/* *2     9-AUG-1990 19:09:57 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:24:19 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGOP_NL1.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_OPERATE_NLIST.C*/
/* *2    11-AUG-1989 09:09:30 GORDON "(SPR 101) Quiet compiler info messages"*/
/* *1    21-JUL-1989 09:38:30 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_OPERATE_NLIST.C*/

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
publicdef INT nlg_operate_nlist_1(nlist, ndim, dim_list, opcode, masknlist,
				  mask_dim, nlist_out)
NLIST_HEADER *nlist,*masknlist,*nlist_out;
UINT *ndim,*dim_list,*mask_dim;
INT *opcode;
{
    return nl_operate_nlist_1(*nlist, *ndim, dim_list, *opcode, *masknlist,
			      mask_dim, nlist_out);
}
#endif

#if UNIX
publicdef INT nlg_operate_nlist_1_(nlist, ndim, dim_list, opcode, masknlist,
				  mask_dim, nlist_out)
NLIST_HEADER *nlist,*masknlist,*nlist_out;
UINT *ndim,*dim_list,*mask_dim;
INT *opcode;
{
    return nl_operate_nlist_1(*nlist, *ndim, dim_list, *opcode, *masknlist,
			      mask_dim, nlist_out);
}
#endif

#ifdef primos
publicdef INT nlg_operate_nlist_1(nlist, ndim, dim_list, opcode,
				  masknlist, mask_dim, nlist_out)
NLIST_HEADER nlist,masknlist,nlist_out;
UINT ndim,dim_list,mask_dim;
INT opcode;
{
    return nl_operate_nlist_1(nlist, ndim, &dim_list, opcode, &masknlist,
			      &mask_dim, &nlist_out);
}
#endif
