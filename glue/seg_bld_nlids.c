/* DEC/CMS REPLACEMENT HISTORY, Element SEG_BLD_NLIDS.C */
/* *4     9-AUG-1990 19:15:28 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:05:19 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:00:59 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:50:47 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element SEG_BLD_NLIDS.C */
/* DEC/CMS REPLACEMENT HISTORY, Element SEG_BLD_NLIDS.C*/
/* *2    14-SEP-1989 16:19:14 GORDON "(SPR 100) Gulf/Sun/Unix mods"*/
/* *1    26-JUL-1989 00:15:14 GILLESPIE "New seismic system mods"*/
/* DEC/CMS REPLACEMENT HISTORY, Element SEG_BLD_NLIDS.C*/

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
*               creating a seismic nlist file name 
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

publicdef INT seg_bld_nlist_ids ( survey, line_name, context, data_type,
    nlist_id, nlist_file, full_filename)

DSC *survey ;		     /*	INPUT					    */
DSC *line_name ;	     /*	INPUT					    */
DSC *context ;		     /*	INPUT					    */
INT *data_type ;	     /*	INPUT					    */
DSC *nlist_id ;		     /*	INPUT/OUTPUT				    */
DSC *nlist_file ;	     /*	INPUT/OUTPUT				    */
DSC *full_filename ;	     /*	OUTPUT					    */
{
CHAR context1 [MAXLEN]  ;
NLIST_ID nlist_id1 ;
FILENAME nlist_file1;
FILENAME full_filename1;
FULL_LINE_NAME line;
INT status ;

    DSCTOCS ( survey, line.survey ) ;
    DSCTOCS ( line_name, line.line_name ) ;
    DSCTOCS ( context, context1 );
    DSCTOCS ( nlist_id, nlist_id1 );
    DSCTOCS ( nlist_file, nlist_file1 );

    status =  se_bld_nlist_ids ( &line, (VOIDPTR)context1,
	(SEIS_NLIST_DATA_TYPE)*data_type, nlist_id1, nlist_file1,
	full_filename1);

    CSTODSC (  nlist_id1, nlist_id ) ;
    CSTODSC (  nlist_file1, nlist_file ) ;
    CSTODSC (  full_filename1, full_filename ) ;

    return status ;
} 

#endif

#if UNIX

publicdef INT seg_bld_nlist_ids_ ( survey, line_name, context, data_type,
    nlist_id, nlist_file, full_filename, n1, n2, n3, n4, n5, n6)

CHAR *survey ;		     /*	INPUT					    */
CHAR *line_name ;	     /*	INPUT					    */
CHAR *context ;		     /*	INPUT					    */
INT *data_type ;	     /*	INPUT					    */
CHAR *nlist_id ;	     /*	INPUT/OUTPUT				    */
CHAR *nlist_file ;	     /*	INPUT/OUTPUT				    */
CHAR *full_filename ;	     /*	OUTPUT					    */
INT n1, n2, n3, n4, n5, n6;  /* INPUT (Unix string length arguments )       */
{
CHAR context1 [MAXLEN]  ;
NLIST_ID nlist_id1 ;
FILENAME nlist_file1;
FILENAME full_filename1;
FULL_LINE_NAME line;
INT status ;

    ftocstr ( survey, line.survey, n1 ) ;
    ftocstr ( line_name, line.line_name, n2 ) ;
    ftocstr ( context, context1, n3 );
    ftocstr ( nlist_id, nlist_id1, n4 );
    ftocstr ( nlist_file, nlist_file1, n5 );

    status =  se_bld_nlist_ids ( &line, (VOIDPTR)context1,
	(SEIS_NLIST_DATA_TYPE)*data_type, nlist_id1, nlist_file1,
	full_filename1);

    ctofstr (  nlist_id, nlist_id1, n4 ) ;
    ctofstr (  nlist_file, nlist_file1, n5 ) ;
    ctofstr (  full_filename, full_filename1, n6 ) ;

    return status ;
} 

#endif

#ifdef primos
 
/* needs work */


publicdef INT seg_bld_nlist_ids ( filename, len )

CHAR filename ;
INT len;
{
    return FAIL ;

} 

#endif
