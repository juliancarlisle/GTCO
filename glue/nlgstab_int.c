/* DEC/CMS REPLACEMENT HISTORY, Element NLGSTAB_INT.C */
/* *2     9-AUG-1990 19:12:41 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:26:43 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGSTAB_INT.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SET_table_INT.C*/
/* *1    21-JUL-1989 09:39:40 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SET_table_INT.C*/

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
publicdef INT nlg_set_table_int(nlist,table,opcode,integ)
NLIST_HEADER *nlist;
INT *opcode,*integ,*table;
{
    return nl_set_table_int(*nlist,*table,*opcode,*integ);
}
#endif

#if UNIX
publicdef INT nlg_set_table_int_(nlist,table,opcode,integ)
NLIST_HEADER *nlist;
INT *opcode,*integ,*table;
{
    return nl_set_table_int(*nlist,*table,*opcode,*integ);
}
#endif

#ifdef primos
publicdef INT nlg_set_table_int(nlist,table,opcode,integ)
NLIST_HEADER nlist;
INT opcode,integ,table;
{
    return nl_set_table_int(nlist,table,opcode,integ);
}
#endif
