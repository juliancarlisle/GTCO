/* DEC/CMS REPLACEMENT HISTORY, Element NLGQTAB_STR.C */
/* *2     9-AUG-1990 19:11:10 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:25:47 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGQTAB_STR.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_table_STRING.C*/
/* *2    24-OCT-1989 15:46:42 PURNA "(SPR 0) resolve compiling errors"*/
/* *1    21-JUL-1989 09:38:09 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_table_STRING.C*/

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
publicdef INT nlg_inq_table_string(nlist, table, opcode, nallocated,
				    string, nbytes)
NLIST_HEADER *nlist;
INT *opcode,*nbytes,*table,*nallocated;
DSC *string;
{
    INT status;
    CHAR string1[MAXLEN];

    status = nl_inq_table_string(*nlist, *table, *opcode,
					*nallocated, string1, (size_t *)nbytes);
    CSTODSC(string1,string);
    return status;
}
#endif

#if UNIX
publicdef INT nlg_inq_table_string_(nlist, table, opcode, nallocated,
				    string, nbytes, len)
NLIST_HEADER *nlist;
INT *opcode,*nbytes,*table,*nallocated;
CHAR *string;
INT len;
{
    INT status;
    CHAR string1[MAXLEN];

    status = nl_inq_table_string(*nlist, *table, *opcode,
					*nallocated, string1, (size_t *)nbytes);
    ctofstr(string,string1,len);
    return status;
}
#endif

#ifdef primos
publicdef INT nlg_inq_table_string(nlist, table, opcode, string, nbytes,
    z1, z2, z3, z4, z5)
NLIST_HEADER nlist;
INT opcode,nbytes,table;
CHAR string;
INT z1,z2,z3,z4,z5;
{
    INT status;
    CHAR string1[MAXLEN];

    status = nl_inq_table_string(nlist, table, opcode, string1, (size_t *)&nbytes);
    ctofstr(&string,string1,z5);
    return status;
}
#endif
