/* DEC/CMS REPLACEMENT HISTORY, Element LDGINTER.C */
/* *4     9-AUG-1990 19:07:28 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:00:03 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    24-OCT-1989 09:53:36 GILLESPIE "(SPR 1) Moved from main source - deltas for 'new' seismic" */
/* *1    24-OCT-1989 09:52:32 GILLESPIE "Glue for seismic line intersection" */
/* DEC/CMS REPLACEMENT HISTORY, Element LDGINTER.C */
/* DEC/CMS REPLACEMENT HISTORY, Element LDGINTER.C*/
/* *1    19-JUN-1989 13:02:02 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element LDGINTER.C*/

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
* DATE : 20/5/1987
C
*
C       OUTPUT  :   ISTATUS     ERROR CODE  = 0 SUCCESS
C                                           # 0 FAILED
C
C *****************************************************************
*
*/

#include "esi_c_lib.h"

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifndef ESI_SE_H
#include "esi_se.h"
#endif

#ifdef vms
publicdef ldginter ( line_buf , nb_lines , nbw_li , survey )

INT *line_buf , *nb_lines , *nbw_li ;
DSC *survey ;

			     /*
			     	line_buf is the buffer containing the
			     	line_names for which we want the
			     	intersections each line_name is on nbw_li
			     	words

			     	there is a total of nb_lines in the buffer
			     	- nb_lines = 0 means that we want the
			     	intersections between all the lines of the
			     	survey

			     	survey is the survey name */
{
INT status , nb_line , nb_car , i  ;
BOOL all , no_dup  ;
FULL_LINE_NAME *pline, *pLine;
INT *pwork ;
CHAR string1 [100] ;

			     /*	  convert survey name to a C string	    */

    DSCTOCS ( survey , string1 ) ;

			     /*	If nb_lines = 0  this means that we compute
			     	the global intersection in the project */

    no_dup = TRUE ;

    if ( *nb_lines == 0 )
	{
	all = TRUE ;
	nb_line = 0 ;
	}
    else
	{
			     /*	we need to build the array of character	    */
			     /*	pointers and the line names		    */

	nb_line = *nb_lines ;
	nb_car = *nbw_li  * sizeof (INT);
	/* first allocate the array    */

	pLine= (FULL_LINE_NAME *)tc_alloc(sizeof (FULL_LINE_NAME)*(*nb_lines));

	pwork = line_buf ;

	for ( i = 0, pline = pLine; i < nb_line ;i++, pwork += *nbw_li, pline++)
	    {
			     /*	call a routine to convert fortran character
			     	string to c character string		    */


	    fort_to_c (pwork , pline -> line_name, nb_car ) ;
	    strcpy((char *)pline -> survey, (char *)survey);
	    pline -> id = 0;
	    all = FALSE ;
	    }
	}

    intersection ( all , pLine, nb_line, no_dup ) ;

    if ( nb_line > 0 )
       {
       tc_free (pLine) ;
       }
}
#endif

#if UNIX
extern ldginter_ ( line_buf , nb_lines , nbw_li , survey, len )
INT *line_buf , *nb_lines , *nbw_li ;
CHAR *survey ;
INT len;
{
INT status , nb_line , nb_car , i  ;
BOOL all , no_dup  ;
FULL_LINE_NAME *pline, *pLine;
INT *pwork ;
CHAR string1 [100] ;

			     /*	  convert survey name to a C string	    */

    ftocstr ( survey , string1,len ) ;

			     /*	If nb_lines = 0  this means that we compute
			     	the global intersection in the project	    */

    no_dup = TRUE ;

      if ( *nb_lines == 0 )
	{
	all = TRUE ;
	nb_line = 0 ;
	}
       else
	{
			     /*	we need to build the array of character	    */
			     /*	pointers and the line names		    */

	nb_line = *nb_lines ;
	nb_car = *nbw_li  * 4 ;
			     /*	first allocate the array		    */

	pLine= (FULL_LINE_NAME *)tc_alloc(sizeof (FULL_LINE_NAME)*(*nb_lines));

	pwork = line_buf ;

	for ( i = 0, pline = pLine; i < nb_line ;i++, pwork += *nbw_li, pline++)

	     {
			     /*	call a routine to convert fortran character
			     	string to c character string		    */


	    fort_to_c (pwork , pline -> line_name, nb_car ) ;
	    strcpy((char *)pline -> survey, (char *)survey);
	    pline -> id = 0;
	     all = FALSE ;
	     }

	}

    intersection ( all , pLine, nb_line  , no_dup ) ;

    if ( nb_line > 0 )
       {
       tc_free (pLine) ;
       }
    }
#endif

#ifdef primos

publicdef INT ldginter(line_buf,nb_lines,nbw_li,survey,z1,z2,z3,z4)
INT line_buf;
INT nb_lines;
INT nbw_li;
CHAR survey;
INT z1,z2,z3,z4;
{

			     /*
			     	* line_buf is the buffer containing the
			     	line_names for which we want the *
			     	intersections each line_name is on nbw_li
			     	words * * there is a total of nb_lines in
			     	the buffer - * nb_lines = 0 means that we
			     	want the intersections between *    all the
			     	lines of the  survey.  * * survey is the
			     	survey name */

    CHAR string1[256];
    INT status, nb_line, nb_car, i;
    BOOL all, no_dup;
    FULL_LINE_NAME *pline, *pLine;
    INT *pwork;

    ftocstr(&survey,string1,z4);

			     /*	If nb_lines = 0 this means that we compute  */
			     /*	the global intersection in the project	    */

    no_dup = TRUE;

    if (nb_lines == 0)
	{
	all = TRUE;
	nb_line = 0;
	}
    else {
			     /*	we need to build the array of character	    */
			     /*	pointers and the line names		    */
	nb_line = nb_lines;
	nb_car  = nbw_li * 4;

			     /*	first allocate the array		    */
	pLine= (FULL_LINE_NAME *)tc_alloc(sizeof (FULL_LINE_NAME)*(*nb_lines));
	pwork = &line_buf;

	for ( i = 0, pline = pLine; i < nb_line ;i++, pwork += *nbw_li, pline++)
	    {
	    fort_to_c (pwork , pline -> line_name, nb_car ) ;
	    strcpy((char *)pline -> survey, (char *)survey);
	    pline -> id = 0;
	    all = FALSE;
	    }
       }

    intersection (all, pLine, nb_line , no_dup);

    if (nb_line > 0)
       {
       tc_free (pLine) ;
       }
    return;
}
#endif
