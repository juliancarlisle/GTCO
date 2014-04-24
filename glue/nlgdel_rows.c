/* DEC/CMS REPLACEMENT HISTORY, Element NLGDEL_ROWS.C */
/* *2     9-AUG-1990 19:09:09 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:18 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGDEL_ROWS.C */
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

/***********************************************************************
 nlg_delete_rows */
#ifdef vms
publicdef INT nlg_delete_rows(nlist,nrows)
NLIST_HEADER *nlist;
INT *nrows;
{
    return nl_delete_rows(*nlist,*nrows);
}
#endif

#if UNIX
publicdef INT nlg_delete_rows_(nlist,nrows)
NLIST_HEADER *nlist;
INT *nrows;
{
    return nl_delete_rows(*nlist,*nrows);
}
#endif

#ifdef primos
publicdef INT nlg_delete_rows(nlist,nrows)
NLIST_HEADER nlist;
INT nrows;
{
    return nl_delete_rows(nlist,nrows);
}
#endif
