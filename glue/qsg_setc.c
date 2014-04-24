/* DEC/CMS REPLACEMENT HISTORY, Element QSG_SETC.C*/
/* *3     9-AUG-1990 19:14:49 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:04:56 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    30-JUL-1989 00:35:29 GILLESPIE "Fortran binding for QS"*/
/* DEC/CMS REPLACEMENT HISTORY, Element QSG_SETC.C*/
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


#include "esi_qs.h"
#include "esi_glue.h"

#ifdef vms
/***********************************************************************

    qsg_setc  QS glue setting a character string

 ***********************************************************************/
publicdef INT qsg_setc ( qs_id ,string , nbcar )
DSC *string;
INT *qs_id ;
INT *nbcar ;

/*
 *qs_id  is a code used to indicate the string we want to be set
 string  is the character string which is stored in the QS area
 *nbcar  is the number of character in string
*/

{
	CHAR string1[MAXLEN];

    DSCTOCS(string ,string1);

    return qs_set_c ( *qs_id , string1 , *nbcar) ;
}

#endif

#if UNIX

publicdef INT qsg_setc_ ( qs_id ,string , nbcar, len )
CHAR *string;
INT *qs_id ;
INT *nbcar ;
INT len;

/*
 *qs_id  is a code used to indicate the string we want to be set
 string  is the character string which is stored in the QS area
 *nbcar  is the number of character in string
*/

{
	CHAR string1[MAXLEN];

    ftocstr(string ,string1, len);

    return qs_set_c ( *qs_id , string1 , *nbcar) ;
}
#endif

#ifdef primos
publicdef INT qsg_setc ( qs_id ,string , nbcar, l1, l2 )
CHAR string;
INT qs_id ;
INT nbcar ;
INT l1, l2;
{
	CHAR string1[MAXLEN];

    ftocstr( &string, string1, l2 );
    return qs_set_c ( qs_id , string1 , nbcar) ;
}

#endif
