/* DEC/CMS REPLACEMENT HISTORY, Element HOG_CTIME.C*/
/* *3     9-AUG-1990 19:06:56 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:29 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:45:49 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_CTIME.C*/

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

/***************************************************/
/*    hog_ctime  : glue subroutine called from
	fortran application and returning an ascii
	string with the date and time  -
*/
#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_TS_H
#include "esi_ts.h"
#endif

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifndef ESI_GLUE_H
#include  "esi_glue.h"
#endif

#ifndef ESI_HO_H
#include "esi_ho.h"
#endif

#ifdef vms
extern void  hog_ctime() ;

/*****************************************************/
 void hog_ctime ( string_date )

		    /*  string_date is the fortran character string
			we store the ascii string containing date and time
			to be used by a fortran programm

			len_string pointer to an integer which contains the
			length of the string returned to the fortran progrm   */

		    /* 12/19/88 SC - removed len_string which's never 
				     used by caller */
DSC *string_date ;

{
CHAR string1 [100] ;

ho_ctime ( string1 ) ;

CSTODSC ( string1 , string_date ) ;

}
#endif

#if UNIX

/*****************************************************/
 void hog_ctime_ ( string_date, len )

		    /*  string_date is the fortran character string
			we store the ascii string containing date and time
			to be used by a fortran programm

			len_string pointer to an integer which contains the
			length of the string returned to the fortran progrm   */

CHAR *string_date ;
INT len;

{
CHAR string1 [100] ;

ho_ctime ( string1 ) ;

ctofstr ( string_date , string1, len ) ;

}
#endif

#ifdef primos

publicdef INT hog_ctime(time_string,z1)
CHAR *time_string;
INT z1;
{
    extern INT ho_ctime();
    INT ret;
    CHAR string1[256];

    ftocstr((CHAR *)&time_string,string1,z1);
    ret = ho_ctime(string1);
    ctofstr((CHAR *)&time_string,string1,z1);
    return(ret);
}

#endif
                                                                       
