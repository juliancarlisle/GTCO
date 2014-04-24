/* DEC/CMS REPLACEMENT HISTORY, Element NLGINIT_NL.C */
/* *2     9-AUG-1990 19:09:41 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:57 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGINIT_NL.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INIT_NLIST.C*/
/* *2    24-OCT-1989 15:22:05 PURNA "(SPR 0) resolve compiling error"*/
/* *1    21-JUL-1989 09:37:32 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INIT_NLIST.C*/

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

#ifdef vms

publicdef INT nlg_init_nlist(nlist, ndim, units, datasize, datatype,
			     val_inc, blksize)
NLIST_HEADER *nlist;
INT *ndim, *units, *datasize, *datatype, *val_inc, *blksize;
{
    return nl_init_nlist(nlist,*ndim,units,(size_t *)datasize,datatype,val_inc,*blksize);
}
#endif

#if UNIX

publicdef INT nlg_init_nlist_(nlist, ndim, units, datasize, datatype,
			     val_inc, blksize)
NLIST_HEADER *nlist;
INT *ndim, *units, *datasize, *datatype, *val_inc, *blksize;
{
    return nl_init_nlist(nlist,*ndim,units,datasize,datatype,val_inc,*blksize);
}
#endif

#ifdef primos
INT nlg_init_nlist(nlist, ndim, units, datasize, datatype, val_inc, blksize)
NLIST_HEADER nlist;
INT ndim, *units, *datasize, *datatype, *val_inc, blksize;
{
    return nl_init_nlist(&nlist,ndim,&units,&datasize,&datatype,
			 &val_inc,blksize);
}
#endif
