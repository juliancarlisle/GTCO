/* DEC/CMS REPLACEMENT HISTORY, Element CTG_DEF_PRJ.C*/
/* *3    27-AUG-1990 08:22:15 VINCE "(SPR 1) change old #if host to ifdef... "*/
/* *2     7-FEB-1990 06:58:57 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:47:09 GILLESPIE "Fortran binding for Cartographic Routine"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CTG_DEF_PRJ.C*/

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

#include "esi_gl_defs.h"
#include "esi_glue.h"
#include "esi_ct.h"

/***********************************************************************
    glue  for ct_get_default_project

*************************************************************************/

#ifdef vms

publicdef INT ctg_get_default_project ( proj_id)
DSC *proj_id ;
 {
 CHAR string [ MAXLEN] ;
 INT status ;

	status = ct_get_default_project ( string ) ;

      if ( status EQUALS SUCCESS )
	   {
	   CSTODSC ( string , proj_id ) ;
	   }

      return status ;
 }

#endif

#if UNIX

publicdef INT ctg_get_default_project_ ( proj_id,len)
CHAR *proj_id ;
INT len;
 {
 CHAR string [ MAXLEN] ;
 INT status ;

	status = ct_get_default_project ( string ) ;

      if ( status EQUALS SUCCESS )
	   {
	   ctofstr ( proj_id, string , len) ;
	   }

      return status ;
 }

#endif

#ifdef primos

publicdef INT ctg_get_default_project ( proj_id, len)
CHAR proj_id ;
INT len;
 {
 CHAR string [ MAXLEN] ;
 INT status ;

      status = ct_get_default_project ( string ) ;

      if ( status EQUALS SUCCESS )
	   {
	   ctofstr ( &proj_id, string, len);
	   }

      return status ;
 }

#endif

                                            
