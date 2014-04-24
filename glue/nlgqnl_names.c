/* DEC/CMS REPLACEMENT HISTORY, Element NLGQNL_NAMES.C */
/* *2     9-AUG-1990 19:10:36 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:25:11 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGQNL_NAMES.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_NLIST_NAMES.C*/
/* *2    31-JUL-1989 13:39:55 GORDON "(SPR 101) Quiet compiler info messages"*/
/* *1    21-JUL-1989 09:37:52 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_NLIST_NAMES.C*/

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

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifdef vms
publicdef INT nlg_inq_nlist_names(filename, total_names, names_tcp)
DSC *filename;
UINT *total_names;
TSG_TCP **names_tcp;
{
    INT status;
    CHAR string1[MAXLEN];

    DSCTOCS(filename,string1);

    *names_tcp = (TSG_TCP *)tc_alloc( sizeof(TSG_TCP) );
    status = nl_inq_nlist_names(string1, total_names,
					     &((*names_tcp) -> tcp));
    (*names_tcp) -> total_items = *total_names;
    return status;
}
#endif

/* NOTE: Prime and UNIX code has not been written yet for this function. */
