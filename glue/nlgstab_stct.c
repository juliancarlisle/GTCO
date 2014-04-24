/* DEC/CMS REPLACEMENT HISTORY, Element NLGSTAB_STCT.C */
/* *2     9-AUG-1990 19:12:58 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:26:47 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGSTAB_STCT.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SET_table_USER_STRUCT.C*/
/* *1    21-JUL-1989 09:39:47 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SET_table_USER_STRUCT.C*/

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
publicdef INT nlg_set_table_user_struct(nlist, table, structptr, nbytes)
NLIST_HEADER *nlist;
INT *nbytes,*table;
DOUBLE *structptr;
{
    return nl_set_table_user_struct(*nlist,*table,structptr,*nbytes);
}
#endif

#if UNIX
publicdef INT nlg_set_table_user_struct_(nlist, table, structptr, nbytes)
NLIST_HEADER *nlist;
INT *nbytes,*table;
DOUBLE *structptr;
{
    return nl_set_table_user_struct(*nlist,*table,structptr,*nbytes);
}
#endif

#ifdef primos
publicdef INT nlg_set_table_user_struct(nlist, table, nbytes, structptr)
NLIST_HEADER nlist;
INT nbytes,table;
DOUBLE structptr;
{
    return nl_set_table_user_struct(nlist,table,nbytes,&structptr);
}
#endif
