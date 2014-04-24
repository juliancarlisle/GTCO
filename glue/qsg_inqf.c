/* DEC/CMS REPLACEMENT HISTORY, Element QSG_INQF.C*/
/* *3     9-AUG-1990 19:14:11 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:04:49 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    30-JUL-1989 00:35:22 GILLESPIE "Fortran binding for QS"*/
/* DEC/CMS REPLACEMENT HISTORY, Element QSG_INQF.C*/
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

    qsg_inqf  QS glue inquiring for a integer

 ***********************************************************************/
#include "esi_qs.h"

#ifdef vms
publicdef INT qsg_inqf ( qs_id ,number )
INT *qs_id ;
FLOAT *number ;

/*
 *qs_id  is a code used to indicate the float we want to be returned
 *number is the number returned by the inquiry
*/


{
    return qs_inq_f ( *qs_id , number) ;
}

#endif

#if UNIX

publicdef INT qsg_inqf_ ( qs_id ,number )
INT *qs_id ;
FLOAT *number ;

/*
 *qs_id  is a code used to indicate the float we want to be returned
 *number is the number returned by the inquiry
*/


{
    return qs_inq_f ( *qs_id , number) ;
}

#endif

#ifdef primos
publicdef INT qsg_inqf ( qs_id ,number )
INT qs_id ;
FLOAT number ;
{
	INT status;
    FLOAT tnum = number;
	
    status = qs_inq_f ( qs_id , &tnum) ;
    number = tnum;

    return status;
}

#endif
