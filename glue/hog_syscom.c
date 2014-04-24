/* DEC/CMS REPLACEMENT HISTORY, Element HOG_SYSCOM.C*/
/* *3     9-AUG-1990 19:07:16 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:50 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:46:09 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_SYSCOM.C*/

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

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifndef ESI_HO_DESC_H
#include "esi_ho_desc.h"
#endif

/******************************************************************************/
/*                                                                            */
/*    Routine:    hog_syscom                                                  */
/*                                                                            */
/*    Function:   Glue routine to call ho_syscom (execute system commands from*/
/*                within a program) from FORTRAN programs.                    */
/*                                                                            */
/******************************************************************************/

#ifdef vms

publicdef INT  hog_syscom( com_string)

  DSC      *com_string;

{
   CHAR     string[MAXLEN];
   INT      status;


   DSCTOCS  ( com_string, string);
   status =  ho_syscom( string);

   return status;
}

#endif

#if UNIX

publicdef INT  hog_syscom_( com_string, len)

CHAR *com_string;
INT len;

{
   CHAR     string[MAXLEN];
   INT      status;


   ftocstr  ( com_string, string, len);
   status =  ho_syscom( string);

   return status;
}

#endif
#ifdef primos

publicdef INT hog_syscom(string,z1)
CHAR *string;
INT z1;
{
    extern INT ho_syscom();
    INT ret;
    CHAR string1[256];

    ftocstr((CHAR *)&string,string1,z1);
    ret = ho_syscom(string1);
    ctofstr((CHAR *)&string,string1,z1);
    return(ret);
}

#endif

                                                                              
