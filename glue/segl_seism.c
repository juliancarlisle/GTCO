/* DEC/CMS REPLACEMENT HISTORY, Element SEGL_SEISM.C */
/* *5     9-AUG-1990 19:15:14 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *4     7-FEB-1990 07:05:11 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *3    16-NOV-1989 21:29:15 GILLESPIE "(SPR 1) fixes for seismic line editor" */
/* *2    16-OCT-1989 16:00:20 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:50:24 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element SEGL_SEISM.C */
/* DEC/CMS REPLACEMENT HISTORY, Element SEGL_SEISM.C*/
/* *3    20-SEP-1989 14:58:28 GORDON "(SPR 200) Get in sync with Gulf"*/
/* *2    25-JUL-1989 19:40:27 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    19-JUN-1989 13:23:39 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SEGL_SEISM.C*/

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

/*************************************************************


* VAX glue routines for SEIS_TOOLS     callable from FORTRAN  *

      REMI DORET   14/5/87


*****************************************************************/


#include "esi_se.h"
#include "esi_glue.h"


/***********************************************************************
    glue  for cdp_from_sp_init

*************************************************************************/

#ifdef vms

publicdef VOID  segincdp ( line_name , survey, id, honor, sp , cdp ,
	cdp_per_sp , istat )

DSC *line_name ;
DSC *survey ;
INT *id;
INT *honor ;
FLOAT *sp ;
INT *cdp , *cdp_per_sp ;
INT *istat;
{
FULL_LINE_NAME name_struct ;

    DSCTOCS ( line_name  , name_struct.line_name) ;
    DSCTOCS ( survey, name_struct.survey) ;
    name_struct.id = -1;

    *istat = se_cdp_from_sp_init (&name_struct ,*honor, (SP)*sp,
	(CDP *)cdp , cdp_per_sp ) ;

    *id = name_struct.id;
    return ;
}
#endif

#if UNIX
publicdef VOID  segincdp_ ( line_name , survey, id, honor, sp , cdp ,
	cdp_per_sp , istat, n1, n2 )
CHAR *line_name ;
CHAR *survey ;
INT *id;
INT *honor ;
FLOAT *sp ;
INT *cdp , *cdp_per_sp ;
INT *istat;
INT n1, n2;
{
    FULL_LINE_NAME name_struct ;

    ftocstr ( line_name  , name_struct.line_name, n1) ;
    ftocstr ( survey, name_struct.survey, n2) ;
    name_struct.id = -1;

    *istat = se_cdp_from_sp_init (&name_struct ,*honor, (SP)*sp,
	(CDP *)cdp , cdp_per_sp ) ;

    *id = name_struct.id;
    return ;
}
#endif

#ifdef primos

publicdef VOID segincdp(line_name,survey,honor,sp,cdp,cdp_per_sp,istat,
    len1,len2)
CHAR line_name;
CHAR survey;
INT honor;
FLOAT  sp;
INT cdp;
INT cdp_per_sp;
INT istat;
INT len1;
{
    FULL_LINE_NAME name_struct;

    ftocstr ( &line_name  , name_struct.line_name, len1) ;
    ftocstr ( &survey, name_struct.survey, len2) ;
    name_struct.id = -1;

   istat = se_cdp_from_sp_init (&name_struct, honor, sp, &cdp, &cdp_per_sp);

    return ;
}
#endif 

/***********************************************************************

    glue  for cdp_from_sp

*************************************************************************/
#ifdef vms

publicdef VOID  segcdpsp ( line_name , survey, id, sp , cdp , istat )

DSC *line_name ;
DSC *survey;
INT *id;
FLOAT *sp ;
INT *cdp ;
INT *istat ;
{
   FULL_LINE_NAME name_struct ;

    DSCTOCS ( line_name  , name_struct.line_name) ;
    DSCTOCS ( survey, name_struct.survey) ;
    name_struct.id = *id;

   *istat = se_cdp_from_sp (&name_struct , (SP)*sp , (CDP *)cdp ) ;

    return ;
}
#endif

#if UNIX

publicdef VOID  segcdpsp_( line_name , survey, id, sp , cdp , istat, n1, n2 )
CHAR *line_name ;
CHAR *survey;
INT *id;
FLOAT *sp ;
INT *cdp ;
INT *istat ;
INT n1, n2;
{
   FULL_LINE_NAME name_struct ;

    ftocstr ( line_name  , name_struct.line_name, n1) ;
    ftocstr ( survey, name_struct.survey, n2) ;
    name_struct.id = *id;

   *istat = se_cdp_from_sp (&name_struct , (SP)*sp , (CDP *)cdp ) ;

    return ;
}
#endif

#ifdef primos

publicdef VOID segcdpsp(line_name,sp,cdp,istat,len1)
CHAR line_name;
FLOAT sp;
INT cdp;
INT istat;
INT len1;
{
    CHAR string1[256];

    ftocstr(&line_name,string1,len1);
    istat = se_l_cdp_from_sp( string1, sp, &cdp );
    return;
}
#endif

/***********************************************************************
    glue  for upd_cores_cdp_sp

*************************************************************************/
#ifdef vms

publicdef VOID updcores ( line_name , survey, id, regul , honor, last_cdp  , sp,
   cdp , istat )


DSC *line_name ;
DSC *survey ;
INT *id;
INT *regul;
INT *honor ;
INT *last_cdp;
FLOAT *sp ;
INT *cdp;
INT *istat;
{
INT status ;

   FULL_LINE_NAME name_struct ;

    DSCTOCS ( line_name  , name_struct.line_name) ;
    DSCTOCS ( survey, name_struct.survey) ;
    name_struct.id = *id;

    *istat = sez_upd_cores_cdp_sp ( &name_struct , *regul , *honor ,
				   (CDP)*last_cdp, (SP)*sp ,(CDP *)cdp ) ;
      return ;
 }

#endif          


#if UNIX
publicdef VOID updcores_ ( line_name , survey, id, regul , honor, last_cdp  , sp,
   cdp , istat, n1, n2 )
CHAR *line_name ;
CHAR *survey ;
INT *id;
INT *regul;
INT *honor ;
INT *last_cdp;
FLOAT *sp ;
INT *cdp;
INT *istat;
INT n1, n2;
{

   FULL_LINE_NAME name_struct ;

    ftocstr ( line_name  , name_struct.line_name, n1) ;
    ftocstr ( survey, name_struct.survey, n2) ;
    name_struct.id = *id;

    *istat = sez_upd_cores_cdp_sp ( &name_struct , *regul , *honor ,
				   (CDP)*last_cdp, (SP)*sp ,(CDP *)cdp ) ;
      return ;
 }


#endif          

#ifdef primos

publicdef VOID updcores (line_name, survey, regul, honor, last_cdp,
    sp, cdp, istat, len1, len2)

CHAR line_name;
CHAR survey;
INT regul;
INT honor;
INT last_cdp;
FLOAT sp;
INT cdp;
INT istat;
INT len1;

    {
    FULL_LINE_NAME name_struct ;
    CHAR string1[256];

    ftocstr (&line_name, name_struct.line_name, len1);
    ftocstr (&survey, name_struct.line_name, len2);

    istat =
	sez_upd_cores_cdp_sp (&name_struct, regul, honor, last_cdp, sp, &cdp);

    return;
    }

#endif         /* end of Prime code */
