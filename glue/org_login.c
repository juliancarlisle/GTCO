/* DEC/CMS REPLACEMENT HISTORY, Element ORG_LOGIN.C */
/* *4     9-AUG-1990 19:13:41 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 08:13:39 JULIAN "(SPR 1) Fix non-portable assignment. Compiler screams quieted." */
/* *2     7-FEB-1990 07:04:35 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1    21-JUL-1989 10:52:28 GILLESPIE "Fortran binding for or_login" */
/* DEC/CMS REPLACEMENT HISTORY, Element ORG_LOGIN.C */

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

/****************************************************************************
*                                                                           *
*                       Compagnie Generale de Geophysique                   *
*                                                                           *
****************************  Copyright C.G.G.  *****************************
*                                                                           *
*   NAME       : ORG_LOGIN                                                  *
*                                                                           *
*   SYNOPSIS   : ORG_LOGIN ( ORAC_ID , STATUS )                             *
*                                                                           *
*                                                                           *
*   LANGUAGE   : C                                                          *
*                                                                           *
*   PURPOSE    : Glue routine that makes a oracle login                     *
*                                                                           *
*                                                                           *
*   INPUT PARAMETERS     : ORAC_ID   : Oracle login id.                     *
*                                                                           *
*    OUTPUT PARAMETERS   : STATUS   :STATUS RETURNED                        *
*                                   = 0 SUCCESS  ,   #0 ERROR               *
*                                                                           *
*   SUBROUTINE(S) CALLED : NONE                                             *
*                                                                           *
*                                                                           *
*   REMARKS    :                                                            *
*                                                                           *
*   AUTHOR     :  Joseph SASSON                                             *
*                                                                           *
*   DATE       :  SEPTEMBER 1988                                            *
*                                                                           *
*   MODIFICATIONS        :                                                  *
*                                                                           *
****************************************************************************/

#include "esi_gl_defs.h"
#ifndef ESI_QS_ERR_H
#include "esi_qs_err.h"
#endif
#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifdef vms

publicdef INT org_login ( orac_id , status )

 DSC  *orac_id ;
 INT  *status  ;

 {

    CHAR orac_id1[81] ;
    CHAR *orac_id2[2] ;

	DSCTOCS ( orac_id , orac_id1 ) ;

	orac_id2[0] = (CHAR *)orac_id1;
	orac_id2[1] = (CHAR *)orac_id1 ;

	*status =  or_login ( 2 , orac_id2 ) ;

	return *status;

}

#endif

#if UNIX

publicdef INT org_login_ ( orac_id , status, len )

 CHAR  *orac_id ;
 INT  *status  ;
 INT len;

 {

    CHAR orac_id1[81] ;
    CHAR *orac_id2[2] ;

	ftocstr ( orac_id , orac_id1, len ) ;

	orac_id2[0] = orac_id2[1] = orac_id1 ;

	*status =  or_login ( 2 , orac_id2 ) ;

	return *status;

}

#endif


#ifdef primos

publicdef INT org_login (orac_id , status, len)

CHAR orac_id;
INT  status;
INT  len;

    {
    CHAR orac_id1[81];
    CHAR *orac_id2[2];

    ftocstr (&orac_id, orac_id1, len);

    orac_id2[0] = orac_id2[1] = orac_id1;

    status = or_login (2, orac_id2);

    return status;
    }

#endif
               
