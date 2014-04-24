/* DEC/CMS REPLACEMENT HISTORY, Element SE_PPOS.C */
/* *5     9-AUG-1990 19:15:35 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *4    27-JUL-1990 13:29:12 GILLESPIE "(SPR 5703) Use LINE_NAME_SEPARATOR instead of hard-coded '$'" */
/* *3     7-FEB-1990 07:05:22 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 16:01:16 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:51:06 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element SE_PPOS.C */
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
* FUNCTION :  Routine used to store a an nlist cdp , x ,y in the
*              DATA BASE this routine is calling a fortran routine
*               setting parameters for routine STORLIN which perform
*              all the appropriate processing for loading a line
*
*            if a flag is positionned this routine is also calling
*             the intersection computation
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

#include "esi_c_lib.h"
#include "esi_se_int.h"

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

/**    definitions of static variables used for nlist manipulation                  */
#define NDIM     3
privatedef VOIDPTR Var_List[NDIM];
privatedef UINT Col_List[NDIM] = 
    {
    1, 2, 3
    };




#ifdef vms

/************************************************************************************/

#if USE_PROTOTYPES
publicdef INT se_put_position(NLIST_HEADER nlist_sp, FULL_LINE_NAME *line,
                              BOOL flag_inters)
#else
publicdef INT se_put_position(nlist_sp, line, flag_inters)
NLIST_HEADER nlist_sp;
FULL_LINE_NAME *line;
BOOL flag_inters;
#endif
/*    
         THIS  IS   A  GLUE  ROUTINE  

  nlist_sp    is a pointer to the nlist containing the list of sp , x , y
               coordinates are supposed to be in the default projection for
               the area no conversion will be made
               this a 3 dimensional nlist of FLOATS 

 line         is the line and survey structure

 flag_inters  is TRUE if we immediatly compute the intersections after loading
                      the line
              is FALSE if not

*/
    {
    FLOAT *array_sp, *pcur;
    INT status, nb_lines;
    BOOL no_dup, all;
    UINT tot_rows;
    INT i;
    DSC name_line;
    SEIS_LINE concat_name;
    
    /* look for the number of rows in the nlist in order to allocate
       float buffer to pass to the fortran program */
    
    status = nl_inq_nlist_int(nlist_sp, NL_NLIST_NPOINTS, (INT *) & tot_rows);
    if (status)
        return FAIL;
    
    /* allocate memory for the array used to store the rows                       */
    
    array_sp = (FLOAT *)TALLOC(NDIM * tot_rows * sizeof(FLOAT));
    
    pcur = array_sp;
    
    /*  perform a loop on the rows to fill the array                              */
    
    Var_List[0] = (VOIDPTR)pcur;
    Var_List[1] = (VOIDPTR)(pcur + 1);
    Var_List[2] = (VOIDPTR)(pcur + 2);
    
    status = nl_first_row(nlist_sp, NDIM, Col_List, Var_List);
    
    pcur += NDIM;
    
    for (i = 2; i <= tot_rows; i++, pcur += NDIM)
        {
        Var_List[0] = (VOIDPTR)pcur;
        Var_List[1] = (VOIDPTR)(pcur + 1);
        Var_List[2] = (VOIDPTR)(pcur + 2);
        
        status = nl_next_row(nlist_sp, NDIM, Col_List, Var_List);
        
        }
    /*    call to the fortran glue routine used to set parameters and call
          the fortran routine loading the positions in the data base 
          array_sp is passed twice as argument to simplify the call to
          another fortran routine called by ld_line    */
    
    /*   convert line_name to a fortran character string                            */
    
    name_line.dsc$w_length = sprintf(concat_name, "%s%c%s", line->line_name,
                                     LINE_NAME_SEPARATOR, line->survey);
    name_line.dsc$a_pointer = concat_name;
    
    seldline(&name_line, array_sp, array_sp, &tot_rows, &status);
    
    /*   free memory used for the array passed to fortran program                   */

#if NEED_TO_FREE
    tc_free(array_sp);
#endif
    if (status)
        return status;
    
    /*    if the flag inters_flag is true we call the intersection program
          to compute intersections between the new line and the other lines
          of the  survey 
    */
    
    if (flag_inters)
        {
        no_dup = TRUE;
        nb_lines = 1;
        all = FALSE;
        
        status = intersection(all, concat_name, nb_lines, no_dup);
        }
    return status;
    }


#endif         /* end of VMS code */

#if UNIX

/************************************************************************************/

#if USE_PROTOTYPES
publicdef INT se_put_position(NLIST_HEADER nlist_sp, FULL_LINE_NAME *line,
                              BOOL flag_inters)
#else
publicdef INT se_put_position(nlist_sp, line, flag_inters)
NLIST_HEADER nlist_sp;
FULL_LINE_NAME *line;
BOOL flag_inters;
#endif

/*    
         THIS  IS   A  GLUE  ROUTINE  

  nlist_sp    is a pointer to the nlist containing the list of sp , x , y
               coordinates are supposed to be in the default projection for
               the area no conversion will be made
        this a 3 dimensionnal nlist of FLOATS 

 line         is the line and survey structure 

 flag_inters  is TRUE if we immediatly compute the intersections after loading
                      the line
              is FALSE if not

*/
    {
    
    FLOAT *array_sp, *pcur;
    INT status, nb_lines;
    BOOL no_dup, all;
    UINT tot_rows;
    INT i;
    SEIS_LINE long_line_name;
    
    /* look for the number of rows in the nlist in order to allocate
       float buffer to pass to the fortran program */
    
    status = nl_inq_nlist_int(nlist_sp, NL_NLIST_NPOINTS, (UINT *) & tot_rows);
    if (status)
        return FAIL;
    
    /* allocate memory for the array used to store the rows                       */
    
    array_sp = (FLOAT *)TALLOC(NDIM * tot_rows * sizeof(FLOAT));
    
    pcur = array_sp;
    
    /*  perform a loop on the rows to fill the array                              */
    
    Var_List[0] = (VOIDPTR)pcur;
    Var_List[1] = (VOIDPTR)(pcur + 1);
    Var_List[2] = (VOIDPTR)(pcur + 2);
    
    status = nl_first_row(nlist_sp, NDIM, Col_List, Var_List);
    
    pcur += NDIM;
    
    for (i = 2; i <= tot_rows; i++, pcur += NDIM)
        {
        Var_List[0] = (VOIDPTR)pcur;
        Var_List[1] = (VOIDPTR)(pcur + 1);
        Var_List[2] = (VOIDPTR)(pcur + 2);
        
        status = nl_next_row(nlist_sp, NDIM, Col_List, Var_List);
        
        }
    sprintf(long_line_name, "%s%c%s", line->line_name, LINE_NAME_SEPARATOR,
            line->survey);
    
    /*    call to the fortran glue routine used to set parameters and call
          the fortran routine loading the positions in the data base 
          array_sp is passed twice as argument to simplify the call to
          another fortran routine called by ld_line    */
    
    seldline_(long_line_name, array_sp, array_sp, &tot_rows, &status,
              strlen(long_line_name));
    
    /*   free memory used for the array passed to fortran program                   */

#if NEED_TO_FREE
    tc_free(array_sp);
#endif
    if (status)
        return status;
    
    /*    if the flag inters_flag is true we call the intersection program
          to compute intersections between the new line and the other lines
          of the  survey 
    */
    
    if (flag_inters)
        {
        no_dup = TRUE;
        nb_lines = 1;
        all = FALSE;
        
        status = intersection(all, long_line_name, nb_lines, no_dup);
        }
    return status;
    
    }


#endif         /* end of UNIX code */

#ifdef primos
#if USE_PROTOTYPES
publicdef INT se_put_position(NLIST_HEADER nlist_sp, FULL_LINE_NAME *line,
                              BOOL flag_inters)
#else
publicdef INT se_put_position(nlist_sp, line, flag_inters)
NLIST_HEADER nlist_sp;
FULL_LINE_NAME *line;
BOOL flag_inters;
#endif
/*
     THIS  IS   A  GLUE  ROUTINE
  nlist_sp    is a pointer to the nlist containing the list of sp , x , y
           coordinates are supposed to be in the default projection for
           the area no conversion will be made
        this a 3 dimensionnal nlist of FLOATS
 line         is the line and survey structure
 flag_inters  is TRUE if we immediatly compute the intersections after loading
              the line
          is FALSE if not
*/
    {
    FLOAT *array_sp, *pcur;
    INT status, nb_lines;
    BOOL no_dup, all;
    INT tot_rows;
    INT i;
    INT sizeof_arr;
    fortran seldline();
    SEIS_LINE long_line_name;
    
    /* look for the number of rows in the nlist in order to allocate
    float buffer to pass to the fortran program */
    
    status = nl_inq_nlist_int(nlist_sp, NL_NLIST_NPOINTS, (INT *) & tot_rows);
    if (status)
        return FAIL;
    
    /* allocate memory for the array used to store the rows                       */
    sizeof_arr = NDIM * tot_rows * sizeof(FLOAT);
    array_sp = (FLOAT *)TALLOC(sizeof_arr);
    
    pcur = array_sp;
    
    /*  perform a loop on the rows to fill the array                              */
    
    Var_List[0] = (VOIDPTR)pcur;
    Var_List[1] = (VOIDPTR)(pcur + 1);
    Var_List[2] = (VOIDPTR)(pcur + 2);
    
    status = nl_first_row(nlist_sp, NDIM, Col_List, Var_List);
    
    pcur += NDIM;
    
    for (i = 2; i <= tot_rows; i++, pcur += NDIM)
        {
        Var_List[0] = (VOIDPTR)pcur;
        Var_List[1] = (VOIDPTR)(pcur + 1);
        Var_List[2] = (VOIDPTR)(pcur + 2);
        status = nl_next_row(nlist_sp, NDIM, Col_List, Var_List);
        }

    sprintf(long_line_name, "%s%c%s", line->line_name, LINE_NAME_SEPARATOR,
            line->survey);          /*    call to the fortran glue routine used to set parameters and call
                                    the fortran routine loading the positions in the data base
                                    array_sp is passed twice as argument to simplify the call to
                                    another fortran routine called by ld_line
                                    
                                    /*   convert line_name to a fortran character string    */
    seldline((char [])long_line_name, (float [])array_sp, (float [])array_sp,
             tot_rows, status, strlen(long_line_name), 0L, 0L, 0L, 0L);   /*   free memory used for the array passed to fortran program   */

#if NEED_TO_FREE
    tc_free(array_sp);
#endif
    if (status)
        return status;              /*    if the flag inters_flag is true we call the intersection program
                                    to compute intersections between the new line and the other lines
                                    of the  survey
                                                                                    */
    if (flag_inters)
        {
        no_dup = TRUE;
        nb_lines = 1;
        all = FALSE;
        status = intersection(all, &long_line_name, nb_lines, no_dup);
        }
    return status;
    }


#endif
