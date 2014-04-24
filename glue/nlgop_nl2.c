/* DEC/CMS REPLACEMENT HISTORY, Element NLGOP_NL2.C */
/* *2     9-AUG-1990 19:09:59 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:24:23 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGOP_NL2.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_OPERATE_NLIST_2.C*/
/* *2    11-AUG-1989 10:34:20 GORDON "(SPR 101) 101"*/
/* *1    21-JUL-1989 09:38:34 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_OPERATE_NLIST_2.C*/

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
publicdef INT nlg_operate_nlist_2(nlist, ndim, dim_list, opcode,
		      nlist2, dim_list2, masknlist, mask_dim, nlist_out)
NLIST_HEADER *nlist,*nlist2,*masknlist,*nlist_out;
UINT *ndim,*dim_list,*dim_list2,*mask_dim;
INT *opcode;
{
    return nl_operate_nlist_2(*nlist, *ndim, dim_list, *opcode, *nlist2,
			      dim_list2, *masknlist, mask_dim, nlist_out);
}
#endif

#if UNIX
publicdef INT nlg_operate_nlist_2_(nlist, ndim, dim_list, opcode,
		      nlist2, dim_list2, masknlist, mask_dim, nlist_out)
NLIST_HEADER *nlist,*nlist2,*masknlist,*nlist_out;
UINT *ndim,*dim_list,*dim_list2,*mask_dim;
INT *opcode;
{
    return nl_operate_nlist_2(*nlist, *ndim, dim_list, *opcode, *nlist2,
			      dim_list2, *masknlist, mask_dim, nlist_out);
}
#endif

#ifdef primos
publicdef INT nlg_operate_nlist_2(nlist, ndim, dim_list, opcode,
			 nlist2, dim_list2, masknlist, mask_dim, nlist_out)
NLIST_HEADER nlist,nlist2,masknlist,nlist_out;
UINT ndim,dim_list,dim_list,mask_dim;
INT opcode;
{
    return nl_operate_nlist_2(nlist, ndim, &dim_list, opcode, nlist2,
			      &dim_list2, &masknlist, &mask_dim, &nlist_out);
}
#endif
