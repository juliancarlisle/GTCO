/* DEC/CMS REPLACEMENT HISTORY, Element NLGQCUR_ROW.C */
/* *2     9-AUG-1990 19:10:21 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:24:54 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGQCUR_ROW.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_CURRENT_row.C*/
/* *2    31-JUL-1989 13:34:16 GORDON "(SPR 101) Quiet compiler info messages"*/
/* *1    21-JUL-1989 09:37:36 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_CURRENT_row.C*/

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
publicdef INT nlg_inq_current_row(nlist,row,table)
NLIST_HEADER *nlist;
UINT *row,*table;
{
    return nl_inq_current_row(*nlist,row,table);
}
#endif

#if UNIX
publicdef INT nlg_inq_current_row_(nlist,row,table)
NLIST_HEADER *nlist;
UINT *row,*table;
{
    return nl_inq_current_row(*nlist,row,table);
}
#endif

#ifdef primos
publicdef INT nlg_inq_current_row(nlist,row,table)
NLIST_HEADER nlist;
UINT row,table;
{
    return nl_inq_current_row(nlist,&row,&table);
}
#endif
