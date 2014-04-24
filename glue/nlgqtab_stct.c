/* DEC/CMS REPLACEMENT HISTORY, Element NLGQTAB_STCT.C */
/* *2     9-AUG-1990 19:11:02 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:25:41 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGQTAB_STCT.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_table_USER_STRUCT.C*/
/* *2    24-OCT-1989 15:49:14 PURNA "(SPR 0) resolve compiling errors"*/
/* *1    21-JUL-1989 09:38:13 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_table_USER_STRUCT.C*/

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
publicdef INT nlg_inq_table_user_struct(nlist, table, nalloc,
					 structptr, nbytes)
NLIST_HEADER *nlist;
INT *nalloc, *nbytes,*table;
DOUBLE *structptr;
{
    return nl_inq_table_user_struct(*nlist,*table,*nalloc,structptr,(size_t *)nbytes);
}
#endif

#if UNIX
publicdef INT nlg_inq_table_user_struct_(nlist, table, nalloc,
					 structptr, nbytes)
NLIST_HEADER *nlist;
INT *nalloc, *nbytes,*table;
DOUBLE *structptr;
{
    return nl_inq_table_user_struct(*nlist,*table,*nalloc,structptr,(size_t *)nbytes);
}
#endif

#ifdef primos
publicdef INT nlg_inq_table_user_struct(nlist, table, nalloc,
					 structptr, nbytes)
NLIST_HEADER nlist;
INT nalloc, nbytes,table;
DOUBLE structptr;
{
    return nl_inq_table_user_struct(nlist,table,nalloc,&structptr,(size_t *)&nbytes);
}
#endif
