/* DEC/CMS REPLACEMENT HISTORY, Element NLGQFIL_STCT.C */
/* *2     9-AUG-1990 19:10:25 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:24:58 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGQFIL_STCT.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_FILE_USER_STRUCT.C*/
/* *2    24-OCT-1989 15:30:28 PURNA "(SPR 0) resolve compiling errors"*/
/* *1    21-JUL-1989 09:37:39 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_INQ_FILE_USER_STRUCT.C*/

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

publicdef INT nlg_inq_file_user_struct(filename, nalloc, structptr, nbytes)
DSC *filename;
INT *nalloc, *nbytes;
DOUBLE *structptr;
{
    CHAR string1[MAXLEN];

    DSCTOCS(filename,string1);
    return nl_inq_file_user_struct(string1,*nalloc,structptr,(size_t *)nbytes);
}
#endif

#if UNIX
publicdef INT nlg_inq_file_user_struct_(filename, nalloc, structptr, nbytes, len)
CHAR *filename;
INT *nalloc, *nbytes;
DOUBLE *structptr;
INT len;
{
    CHAR string1[MAXLEN];

    ftocstr(filename,string1,len);
    return nl_inq_file_user_struct(string1,*nalloc,structptr,(size_t *)nbytes);
}
#endif

#ifdef primos

publicdef INT nlg_inq_file_user_struct(filename, nalloc, structptr, nbytes, l1)
CHAR filename;
INT nalloc, nbytes;
DOUBLE structptr;
INT l1;
{
    CHAR string1[MAXLEN];

    ftocstr(&filename,string1,l1);
    return nl_inq_file_user_struct(string1,nalloc,&structptr,(size_t *)&nbytes);
}

#endif
