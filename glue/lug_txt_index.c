/* DEC/CMS REPLACEMENT HISTORY, Element LUG_TXT_INDEX.C */
/* *5     9-AUG-1990 19:08:00 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *4     7-FEB-1990 07:00:32 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *3     6-DEC-1989 15:57:48 GORDON "(SPR 0) fix typo in UNIX line" */
/* *2    16-OCT-1989 15:58:40 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:49:02 PURNA "move from cmsli" */
/* DEC/CMS REPLACEMENT HISTORY, Element LUG_TXT_INDEX.C */
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
#include "esi_gl_defs.h"
#include "esi_glue.h"
#include "esi_lu.h"

#ifdef vms

publicdef INT lug_text_to_index( keyword, index, text )
DSC *keyword;
INT *index;
DSC *text;
{
    CHAR c_keyword[30];
    CHAR c_text[30];

    DSCTOCS( keyword, c_keyword );
    DSCTOCS( text, c_text );
    return lu_text_to_index( c_keyword, index, c_text );
}

#endif

#if UNIX

publicdef INT lug_text_to_index_( keyword, index, text, len1, len2 )
CHAR *keyword;
INT *index;
CHAR *text;
INT len1, len2;
{
    CHAR c_keyword[30];
    CHAR c_text[30];

    ftocstr( keyword, c_keyword, len1 );
    ftocstr( text, c_text, len2 );
    return lu_text_to_index( c_keyword, index, c_text );
}

#endif    
