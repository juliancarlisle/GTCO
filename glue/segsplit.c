/* DEC/CMS REPLACEMENT HISTORY, Element SEGSPLIT.C */
/* *4     9-AUG-1990 19:15:21 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:15 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:00:39 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:50:35 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element SEGSPLIT.C */
/* DEC/CMS REPLACEMENT HISTORY, Element SEGSPLIT.C*/
/* *1    19-JUN-1989 13:23:42 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SEGSPLIT.C*/

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
*              splitting a long line name in line name and survey name
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


/***********************************************************************/

#ifdef vms

extern INT segsplit (longname, line_name , survey_name )

DSC *line_name ;
DSC *survey_name ;
DSC *longname ;

/*   used to extract line name and survey name from
    a   long line name

 longname is the name of the nlist file created using the line nam e

 line_name is a character string containing the line_name
 survey_name is a character string containing the survey_name



*/
{
CHAR string1 [MAXLEN] , string3 [MAXLEN] ;
INT status ;
CHAR string4 [100] ;

     DSCTOCS ( longname , string1 ) ;

     /*   create the long_line name using line_name and survey name */

     se_split_long_name ( string1 , string3 , string4 ) ;


     CSTODSC (  string3 , survey_name) ;
     CSTODSC (  string4 , line_name) ;

    return status ;

}
#endif

#if UNIX

extern INT segsplit_ (longname, line_name , survey_name,len1,len2,len3 )

CHAR *line_name ;
CHAR *survey_name ;
CHAR *longname ;
INT len1, len2, len3;

/*   used to extract line name and survey name from
    a   long line name

 longname is the name of the nlist file created using the line nam e

 line_name is a character string containing the line_name
 survey_name is a character string containing the survey_name



*/
{
CHAR string1 [MAXLEN] , string3 [MAXLEN] ;
INT status ;
CHAR string4 [100] ;

     ftocstr ( longname , string1, len3 ) ;

     /*   create the long_line name using line_name and survey name */

     se_split_long_name ( string1 , string3 , string4 ) ;


     ctofstr (  survey_name, string3 , len2 ) ;
     ctofstr (  line_name, string4 , len1 ) ;

    return status ;

}
#endif

#ifdef primos


extern INT segsplit (longname, line_name , survey_name, l1, l2, l3 )

CHAR line_name ;
CHAR survey_name ;
CHAR longname ;
INT  l1, l2, l3;           /* length of strings */

/*   used to extract line name and survey name from
    a   long line name

 longname is the name of the nlist file created using the line nam e

 line_name is a character string containing the line_name
 survey_name is a character string containing the survey_name



*/
{
CHAR string1 [MAXLEN] , string3 [MAXLEN] ;
INT status ;
CHAR string4 [100] ;

    ftocstr( &longname, string1, l3 );

     /*   create the long_line name using line_name and survey name */

     se_split_long_name ( string1 , string3 , string4 ) ;


    ctofstr( &survey_name, string3, l2 );
    ctofstr( &line_name, string4, l1 );

    return status ;

}
#endif
                                                                                
