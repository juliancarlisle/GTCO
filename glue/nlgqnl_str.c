/* DEC/CMS REPLACEMENT HISTORY, Element NLGQNL_STR.C */
/* *2     9-AUG-1990 19:10:46 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:25:21 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGQNL_STR.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_NLIST_STRING.C*/
/* *2    24-OCT-1989 15:38:56 PURNA "(SPR 0) resolve compiling errors"*/
/* *1    21-JUL-1989 09:37:55 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_NLIST_STRING.C*/

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

publicdef INT nlg_inq_nlist_string(nlist, opcode, nallocated, string,
				   nbytes)
NLIST_HEADER *nlist;
INT *opcode,*nbytes,*nallocated;
DSC *string;
{
    INT status;
    CHAR string1[MAXLEN];

    status = nl_inq_nlist_string(*nlist, *opcode, *nallocated, string1, (size_t *)nbytes);
    CSTODSC(string1,string);
    return status;
}
#endif

#if UNIX

publicdef INT nlg_inq_nlist_string_(nlist, opcode, nallocated, string,
				   nbytes,len)
NLIST_HEADER *nlist;
INT *opcode,*nbytes,*nallocated;
CHAR *string;
INT len;
{
    INT status;
    CHAR string1[MAXLEN];

    status = nl_inq_nlist_string(*nlist, *opcode, *nallocated, string1, (size_t *)nbytes);
    ctofstr(string,string1,len);
    return status;
}
#endif

#ifdef primos
publicdef INT nlg_inq_nlist_string(nlist, opcode, string, nbytes,
				   z1, z2, z3, z4)
NLIST_HEADER nlist;
INT opcode,nbytes;
CHAR string;
INT z1, z2, z3, z4;
{
    INT status;
    CHAR string1[MAXLEN];

    status = nl_inq_nlist_string(*nlist, opcode, string1, (size_t *)&nbytes);
    ctofstr(&string,string1,z4);
    return status;
}
#endif
