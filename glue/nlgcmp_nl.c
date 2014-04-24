/* DEC/CMS REPLACEMENT HISTORY, Element NLGCMP_NL.C */
/* *2     9-AUG-1990 19:08:55 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:05 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGCMP_NL.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_COMPARE_NLIST.C*/
/* *2    28-JUL-1989 14:47:00 GORDON "(SPR 101) Quiet compiler info messages"*/
/* *1    21-JUL-1989 09:36:50 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_COMPARE_NLIST.C*/
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
 nlg_compare_nlist */

#ifdef vms
publicdef INT nlg_compare_nlist(nlist1, dim_list1, opcode, nlist2,
				dim_list2, nlist)
NLIST_HEADER *nlist1,*nlist2,*nlist;
UINT *dim_list1,*dim_list2;
INT *opcode;
{
    return nl_compare_nlist(*nlist1,dim_list1,*opcode,*nlist2,dim_list2,nlist);
}
#endif

#if UNIX
publicdef INT nlg_compare_nlist_(nlist1, dim_list1, opcode, nlist2,
				dim_list2, nlist)
NLIST_HEADER *nlist1,*nlist2,*nlist;
UINT *dim_list1,*dim_list2;
INT *opcode;
{
    return nl_compare_nlist(*nlist1,dim_list1,*opcode,*nlist2,dim_list2,nlist);
}
#endif

#ifdef primos
publicdef INT nlg_compare_nlist(nlist1, dim_list1, opcode, nlist2,
				dim_list2, nlist)
NLIST_HEADER nlist1,nlist2,nlist;
UINT *dim_list1,dim_list2;
INT opcode;
{
    return nl_compare_nlist(nlist1,&dim_list1,opcode,nlist2,&dim_list2,&nlist);
}
#endif
