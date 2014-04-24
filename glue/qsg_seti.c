/* DEC/CMS REPLACEMENT HISTORY, Element QSG_SETI.C*/
/* *3     9-AUG-1990 19:15:01 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:05:03 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    30-JUL-1989 00:35:36 GILLESPIE "Fortran binding for QS"*/
/* DEC/CMS REPLACEMENT HISTORY, Element QSG_SETI.C*/
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

#ifdef vms
/***********************************************************************

    qsg_seti  QS glue setting an integer

 ***********************************************************************/

publicdef INT qsg_seti ( qs_id ,number )
INT *qs_id ;
INT *number ;

/*
 *qs_id  is a code used to indicate the integer we want to set
 *number is the number we set
*/


{
    return qs_set_i ( *qs_id , *number) ;
}

#endif

#if UNIX

publicdef INT qsg_seti_ ( qs_id ,number )
INT *qs_id ;
INT *number ;

/*
 *qs_id  is a code used to indicate the integer we want to set
 *number is the number we set
*/

{
    return qs_set_i ( *qs_id , *number) ;
}
#endif

#ifdef primos

publicdef INT qsg_seti ( qs_id ,number )
INT qs_id ;
INT number ;

{
    return qs_set_i ( qs_id , number) ;
}
#endif
