/* DEC/CMS REPLACEMENT HISTORY, Element NLGCLN_FILE.C */
/* *2     9-AUG-1990 19:08:52 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *1     5-MAR-1990 12:23:01 GILLESPIE "Renamed files (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element NLGCLN_FILE.C */

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

#ifdef vms

publicdef INT nlg_clean_file(filename, percent )
DSC *filename;
DOUBLE *percent;
{
    CHAR string1[MAXLEN];

    DSCTOCS(filename,string1);
    return nl_clean_file(string1, *percent);
}
#endif

#if UNIX

publicdef INT nlg_clean_file_(filename, percent,len )
CHAR *filename;
DOUBLE *percent;
INT len;
{
    CHAR string1[MAXLEN];

    ftocstr(filename,string1,len);
    return nl_clean_file(string1, *percent);
}
#endif

#ifdef primos
publicdef INT nlg_clean_file(filename, percent, len1, len2 )
CHAR filename;
DOUBLE percent;
INT len1, len2;
{
    CHAR string1[MAXLEN];

    ftocstr(&filename,string1,len1);
    return nl_clean_file(string1, percent);
}

#endif
