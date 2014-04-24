/* DEC/CMS REPLACEMENT HISTORY, Element NLGSTAB_STR.C */
/* *2     9-AUG-1990 19:13:07 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:26:52 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGSTAB_STR.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SET_table_STRING.C*/
/* *1    21-JUL-1989 09:39:44 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SET_table_STRING.C*/

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

#ifdef vms
INT nlg_set_table_string(nlist, table, opcode, string)
NLIST_HEADER *nlist;
INT *opcode,*table;
DSC *string;
{
    CHAR string1[MAXLEN];

    DSCTOCS(string,string1);
    return nl_set_table_string(*nlist, *table, *opcode, string1);
}
#endif

#if UNIX
INT nlg_set_table_string_(nlist, table, opcode, string, len)
NLIST_HEADER *nlist;
INT *opcode,*table;
CHAR *string;
INT len;
{
    CHAR string1[MAXLEN];

    ftocstr(string,string1,len);
    return nl_set_table_string(*nlist, *table, *opcode, string1);
}
#endif

#ifdef primos
publicdef INT nlg_set_table_string(nlist, table, opcode, string,
				    z1,z2,z3,z4)
NLIST_HEADER nlist;
INT opcode,table;
CHAR string;
INT z1, z2, z3, z4;
{
    CHAR string1[MAXLEN];

    ftocstr(&string, string1, z4);
    return nl_set_table_string(nlist, table, opcode, string1);
}
#endif
