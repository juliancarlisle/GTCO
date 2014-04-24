/* DEC/CMS REPLACEMENT HISTORY, Element NLGSFIL_STCT.C */
/* *2     9-AUG-1990 19:11:57 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:26:08 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGSFIL_STCT.C */
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SET_FILE_USER_STRUCT.C*/
/* *1    21-JUL-1989 09:39:18 GILLESPIE "Fortran binding for n-List function"*/
/* DEC/CMS REPLACEMENT HISTORY, Element NLG_SET_FILE_USER_STRUCT.C*/

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
publicdef INT nlg_set_file_user_struct(filename, structptr, nbytes)
DSC *filename;
INT *nbytes;
DOUBLE *structptr;
{
    CHAR string1[MAXLEN];

    DSCTOCS(filename,string1);
    return nl_set_file_user_struct(string1,structptr,*nbytes);
}
#endif

/* NOTE: Prime and UNIX code has not been written yet for this function. */

