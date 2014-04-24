/* DEC/CMS REPLACEMENT HISTORY, Element NLGCOPY_NL.C */
/* *2     9-AUG-1990 19:08:59 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:08 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGCOPY_NL.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_COPY_NLIST.C*/
/* *1    21-JUL-1989 09:36:53 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_COPY_NLIST.C*/

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
 nlg_copy_nlist */
#ifdef vms
publicdef INT nlg_copy_nlist(from,to)
NLIST_HEADER *from,*to;
{
    return nl_copy_nlist(*from,to);
}
#endif

#if UNIX
publicdef INT nlg_copy_nlist_(from,to)
NLIST_HEADER *from,*to;
{
    return nl_copy_nlist(*from,to);
}
#endif

#ifdef primos
publicdef INT nlg_copy_nlist(from,to)
NLIST_HEADER from,to;
{
    return nl_copy_nlist(from,&to);
}
#endif
