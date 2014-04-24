/* DEC/CMS REPLACEMENT HISTORY, Element LDGGISUP.C */
/* *3     9-AUG-1990 19:07:25 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 06:59:59 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1    21-JUL-1989 10:55:03 GILLESPIE "Fortran binding for ld_gisup" */
/* DEC/CMS REPLACEMENT HISTORY, Element LDGGISUP.C */
/* DEC/CMS REPLACEMENT HISTORY, Element LDGGISUP.C*/
/* *1    19-JUN-1989 13:01:59 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element LDGGISUP.C*/

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

/***********************************************************
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
* DATE : 14/7/87

C
C
C
C

	glue routine called from fortran used to update
	 the GIS for seismic lines

	 nlist is the pointer to the nlist cdp,x,y describing the seismic line

	 linename is the full line name of the seismic line

*******************************************************************/

#ifndef  ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef  ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifndef  ESI_NL_H
#include "esi_nl.h"
#endif

#ifdef vms
extern VOID  ldggisup ( nlist, linename )
NLIST_HEADER *nlist;
DSC *linename;
{
CHAR string1 [STMAX] ;

    DSCTOCS(linename,string1);

     /*   call to the routine preparing the data for gi_update_seismic
	 and calling it
     */
/*    CALL TO THE ROUTNE IS IN COMMENT UNTIL WAITING FOR THE GIS TO
      BE COMPLETED

     ld_gisupd ( *nlist ,  string1);
*/

}
#endif

#if UNIX
extern VOID  ldggisup_ ( nlist, linename, len )
NLIST_HEADER *nlist;
CHAR *linename;
INT len;
{
CHAR string1 [STMAX] ;

    ftocstr(linename,string1,len);

     /*   call to the routine preparing the data for gi_update_seismic
	 and calling it
     */
/*    CALL TO THE ROUTNE IS IN COMMENT UNTIL WAITING FOR THE GIS TO
      BE COMPLETED

     ld_gisupd ( *nlist ,  string1);
*/

}
#endif

#ifdef primos
extern VOID  ldggisup ( nlist, linename, l1, l2)
NLIST_HEADER nlist;
CHAR linename;
INT l1, l2;
{
CHAR string1 [STMAX] ;

    ftocstr( &linename, string1, l2 );

     /*   call to the routine preparing the data for gi_update_seismic
	 and calling it
     */
/*    CALL TO THE ROUTNE IS IN COMMENT UNTIL WAITING FOR THE GIS TO
      BE COMPLETED

     ld_gisupd ( nlist ,  string1);
*/

}
#endif

                                                                                                                   
