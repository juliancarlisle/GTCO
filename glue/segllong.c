/* DEC/CMS REPLACEMENT HISTORY, Element SEGLLONG.C */
/* *4     9-AUG-1990 19:15:06 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:07 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 15:59:47 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:50:02 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element SEGLLONG.C */
/* DEC/CMS REPLACEMENT HISTORY, Element SEGLLONG.C*/
/* *2    25-JUL-1989 19:40:10 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    19-JUN-1989 13:23:32 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SEGLLONG.C*/

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

#include "esi_se.h"
#include "esi_glue.h"


/***********************************************************************/

#ifdef vms

publicdef INT segllong ( line_name , survey_name , longname)

DSC *line_name ;
DSC *survey_name ;
DSC *longname ;

/*   used to create the long line name from a linename  
 
 line_name is a character string containing the line_name 
 survey_name is a character string containing the survey_name 

 longname is the name of the nlist file created using the line nam e

  
*/ 
{
CHAR string1 [MAXLEN] , string2 [MAXLEN] ,string3 [MAXLEN] ;
INT status ;
CHAR string4 [100] ;

     DSCTOCS ( line_name , string1 ) ;
     DSCTOCS ( survey_name , string3 ) ;

     /*   create the long_line name using line_name and survey name */

     status = se_cre_long_line_name ( string1 , string3 , string4 ) ; 


     CSTODSC (  string4 , longname ) ;

    return status ;

} 

#endif     /* end of VMS code */

#if UNIX

publicdef INT segllong_ ( line_name , survey_name , longname,
		len1, len2, len3)

CHAR *line_name ;
CHAR *survey_name ;
CHAR *longname ;
INT len1, len2, len3;

/*   used to create the long line name from a linename  
 
 line_name is a character string containing the line_name 
 survey_name is a character string containing the survey_name 

 longname is the name of the nlist file created using the line nam e

  
*/ 
{
CHAR string1 [MAXLEN] , string2 [MAXLEN];
INT status ;
CHAR string3 [100] ;

     ftocstr ( line_name , string1, len1) ;
     ftocstr ( survey_name , string2, len2 ) ;

     /*   create the long_line name using line_name and survey name */

     status = se_cre_long_line_name ( string1 , string2 , string3 ) ; 


     ctofstr (  longname, string3, len3 ) ;

    return status ;

} 

#endif     /* end of UNIX code */

#ifdef primos


publicdef INT segllong ( line_name , survey_name , longname, l1, l2, l3 )

CHAR line_name ;
CHAR survey_name ;
CHAR longname ;
INT l1, l2, l3;
/*   used to create the long line name from a linename  
 line_name is a character string containing the line_name 
 survey_name is a character string containing the survey_name 
 longname is the name of the nlist file created using the line name
*/ 

{
CHAR string1 [MAXLEN] , string2 [MAXLEN] ,string3 [MAXLEN] ;
INT status ;
CHAR string4 [100] ;

    ftocstr( &line_name, string1, l1 );
    ftocstr( &survey_name, string3, l2 );

     /*   create the long_line name using line_name and survey name */

    status = se_cre_long_line_name ( string1 , string3 , string4 ) ; 


    ctofstr( &longname, string4, l3 );
    return status;

} 

#endif        /* end of Prime code */
