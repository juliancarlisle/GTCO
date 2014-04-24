/* DEC/CMS REPLACEMENT HISTORY, Element GFINDCRS.C */
/* *4     9-AUG-1990 19:06:43 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 06:59:16 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 15:57:11 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:48:02 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element GFINDCRS.C */
/* DEC/CMS REPLACEMENT HISTORY, Element GFINDCRS.C*/
/* *1    19-JUN-1989 12:52:44 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element GFINDCRS.C*/

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

/*
***********************************************************
*                                                         *
*                                                         *
*                                                         *
*                                                         *
*                                                         *
*         COMPAGNIE GENERALE DE GEOPHYSIQUE               *
*                                                         *
*                                                         *
*                                                         *
*                                                         *
*                                                         *
***********************************************************
*
*
*
* AUTHOR:REMI DORET
*
* DATE : 01/04/1987
*
* FUNCTION :  glue routine called from fortran for
*               creating a file name using seismic line name
*
*
* LANGUAGE: C
*
* FILES USED      : NO
*
* FILES CREATED   : NO
*
* TYPE:
* ROUTINES USED   :
*             *
*            *
*
*/

#include "esi_gl_defs.h"
#include "esi_glue.h"

/*
glue routine used to call the routine filling the buffer of intersections
   with the line line_name

*/

/***********************************************************************/
#ifdef vms
publicdef INT gfindcrs ( line_name , ifirst ,ilast,ibuf,lnbuf,icoef,info)
DSC *line_name ;
INT *ifirst , *ilast ,*ibuf ,*lnbuf , *icoef , *info ;


{
CHAR string1 [MAXLEN] ;
INT  status ;

     DSCTOCS ( line_name , string1 ) ;

    status = get_intersection(string1,*ifirst,*ilast,ibuf,*lnbuf,*icoef,info);

    return status ;

}

#endif

#if UNIX
publicdef INT gfindcrs_ ( line_name , ifirst ,ilast,ibuf,lnbuf,icoef,
		info, len)
CHAR *line_name ;
INT *ifirst , *ilast ,*ibuf ,*lnbuf , *icoef , *info ;
INT len;

{
CHAR string1 [MAXLEN] ;
INT  status ;

     ftocstr ( line_name , string1 , len) ;

    status = get_intersection(string1,*ifirst,*ilast,ibuf,*lnbuf,*icoef,info);

    return status ;

}

#endif

#ifdef primos

publicdef INT gfindcrs (line_name,ifirst,ilast,ibuf,lnbuf,icoef,info,len1)

CHAR line_name;
INT ifirst,ilast,ibuf,lnbuf,icoef,info ;
INT len1;              /* Fortran length of line_name */

    {
    CHAR string1 [MAXLEN] ;
    INT  status ;

    ftocstr (&line_name, string1, len1);
    status = get_intersection (string1,ifirst,ilast,&ibuf,lnbuf,icoef,&info);

    return status;
    }

#endif
                                                                                                 
