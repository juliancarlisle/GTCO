/* DEC/CMS REPLACEMENT HISTORY, Element HOG_TRN_FILE.C*/
/* *3     9-AUG-1990 19:07:19 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:54 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:46:13 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_TRN_FILE.C*/

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
/*****************************************************************************
*
* FUNCTION:  hog_translate_filename
*
* DESCRIPTION: Glue routine to allow for Fortran to call ho_translate_filename
*
* 04/07/89 GS - created
*********************************************************************/
#include "esi_gl_defs.h"
#include "esi_glue.h"
#include "esi_ho.h"

#ifdef vms

publicdef hog_translate_filename( infile, outfile )
DSC *infile;
DSC *outfile;
{
    CHAR string1[MAXLEN], string2[MAXLEN];
    INT ret;

    DSCTOCS(infile,string1);
    ret = ho_translate_filename(string1,string2);
    CSTODSC(string2,outfile);

    return ret;
}

#endif

#if UNIX

publicdef hog_translate_filename_( infile, outfile, len1, len2 )
CHAR *infile;
CHAR *outfile;
INT len1, len2;
{
    CHAR string1[MAXLEN], string2[MAXLEN];
    INT ret;

    ftocstr(infile,string1,len1);
    ret = ho_translate_filename(string1,string2);
    ctofstr(outfile,string2,len2);

    return ret;
}

#endif

#ifdef primos

publicdef hog_translate_filename( infile, outfile, len1, len2 )
CHAR infile;
CHAR outfile;
INT len1, len2;
{
    CHAR string1[MAXLEN], string2[MAXLEN];
    INT ret;

    ftocstr(infile,string1,len1);
    ret = ho_translate_filename(string1,string2);
    ctofstr(outfile,string2,len2);

    return ret;
}

#endif


