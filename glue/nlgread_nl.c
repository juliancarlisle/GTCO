/* DEC/CMS REPLACEMENT HISTORY, Element NLGREAD_NL.C */
/* *2     9-AUG-1990 19:11:28 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:25:51 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGREAD_NL.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_READ_NLIST.C*/
/* *1    21-JUL-1989 09:38:56 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_READ_NLIST.C*/

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
publicdef INT nlg_read_nlist(nlist, filename, name)
NLIST_HEADER *nlist;
DSC *filename,*name;
{
    CHAR string1[MAXLEN];
    CHAR string2[MAXLEN];

    DSCTOCS(filename,string1);
    DSCTOCS(name,string2);
    return nl_read_nlist(nlist, string1,string2);
}
#endif

#if UNIX
publicdef INT nlg_read_nlist(nlist, filename, name, len1, len2)
NLIST_HEADER *nlist;
CHAR *filename,*name;
INT len1, len2;
{
    CHAR string1[MAXLEN];
    CHAR string2[MAXLEN];

    ftocstr(filename,string1,len1);
    ftocstr(name,string2,len2);
    return nl_read_nlist(nlist, string1,string2);
}
#endif

#ifdef primos
publicdef INT nlg_read_nlist(nlist, filename, name, z1, z2, z3)
NLIST_HEADER nlist;
CHAR filename,name;
INT z1, z2, z3;
{
    CHAR string1[MAXLEN];
    CHAR string2[MAXLEN];

    ftocstr(&filename, string1, z2);
    ftocstr(&name, string2, z3);
    return nl_read_nlist(nlist, string1,string2);
}
#endif
