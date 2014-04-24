/* DEC/CMS REPLACEMENT HISTORY, Element HOG_GET_UNIQ.C*/
/* *3     9-AUG-1990 19:07:06 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:40 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:45:59 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_GET_UNIQ.C*/

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

/********************************************************************
*      Copyright 1988, Exploration Systems Inc. San Francisco
*
* FUNCTION:  HOG_GET_UNIQUE_FILENAME
*
* SYNOPSIS: CALL HOG_GET_UNIQUE_FILENAME( TEMPFILE )
*
* DESCRIPTION: Fortran - C glue routine
*
* RETURNS: SUCCESS
*
* 01/03/89 GS created
*
*********************************************************************/

#include "esi_gl_defs.h"
#include "esi_ho_files.h"
#include "esi_glue.h"

#ifdef vms

publicdef INT hog_get_unique_filename( tempfile )
DSC *tempfile;
{
    CHAR string1[MAXLEN];

    ho_get_unique_filename( string1 );
    CSTODSC( string1, tempfile );
    return SUCCESS;
}

#endif

#if UNIX

publicdef INT hog_get_unique_filename_( tempfile, len )
CHAR *tempfile;
INT len;
{
    CHAR string1[MAXLEN];

    ho_get_unique_filename( string1 );
    ctofstr( tempfile, string1, len );
    return SUCCESS;
}

#endif

#ifdef primos

publicdef INT hog_get_unique_filename( tempfile, len )
CHAR tempfile;
INT len;
{
    CHAR string1[MAXLEN];

    ho_get_unique_filename( string1 );
    ctofstr( &tempfile, string1, len );
    return SUCCESS;
}

#endif
                                                                                                                     
