/* DEC/CMS REPLACEMENT HISTORY, Element QSG_INQC.C*/
/* *3     9-AUG-1990 19:14:03 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:04:46 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    30-JUL-1989 00:35:18 GILLESPIE "Fortran binding for QS"*/
/* DEC/CMS REPLACEMENT HISTORY, Element QSG_INQC.C*/
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


/***********************************************************************

    qsg_inqc  QS glue inquiring for a character string 

 ***********************************************************************/

#include "esi_qs.h"
#include "esi_glue.h"

#ifdef vms
publicdef INT qsg_inqc ( qs_id ,string , nbcar )
INT *qs_id ;
DSC *string;
INT *nbcar ;

/*
 *qs_id  is a code used to indicate the string we want to be returned
 string  is the character string which is returned
 *nbcar  will contain the number of characters in the returned string
*/

{
	CHAR string1[MAXLEN];
	INT status;
	
    status = qs_inq_c ( *qs_id , string1 , nbcar ) ;

    if(status EQUALS SUCCESS)
		{
		CSTODSC(string1,string);
		}
    return status;
}

#endif

#if UNIX
publicdef INT qsg_inqc_ ( qs_id ,string , nbcar, len )
INT *qs_id ;
CHAR *string;
INT *nbcar ;
INT len;

/*
 *qs_id  is a code used to indicate the string we want to be returned
 string  is the character string which is returned
 *nbcar  will contain the number of characters in the returned string
*/

{
	CHAR string1[MAXLEN];
	INT status;

    status = qs_inq_c ( *qs_id , string1 , nbcar ) ;

    if(status EQUALS SUCCESS)
		{
		ctofstr(string,string1,len);
		}
    return status;
}

#endif

#ifdef primos
publicdef INT qsg_inqc ( qs_id ,string , nbcar, l1, l2 )
INT qs_id ;
CHAR string;
INT nbcar ;
INT l1, l2;

{
	CHAR string1[MAXLEN];
	INT status;

    status = qs_inq_c ( qs_id , string1 , &nbcar ) ;

    if(status EQUALS SUCCESS)
		{
		ctofstr( &string, string1, l2 );
		}
    return status;
}

#endif
