/* DEC/CMS REPLACEMENT HISTORY, Element CO_ESICHR_GC.C*/
/* *3    22-AUG-1990 15:57:31 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:57:17 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:23:34 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_ESICHR_GC.C*/
/******************************************************************************

                Copyright Exploration Systems, Inc. 1989
                    Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

                            Exploration Systems
                            c/o Finder Graphics Systems
                            201 Tamal Vista Blvd.
                            Corte Madera, CA  94925
                            (415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#include "esi_co.h"

/* Function Description -----------------------------------------------------
Description:
    Glue routine from "c" to the FORTRAN routine "ESICHR"
    supplied by ESI to override the characteristics for the
    currently recognizable character set. "charsize[0]" is
    character height and "charsize[1]" to "charsize[nchar-1]"
    are the character widths for the current recognized character
    set.  This set is defined in CO_SETTXT and in DG_ESICHR.

Prototype:
    See below.
    
Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    See blelow.
    
Return Value/Status:
    SUCCESS - Successful completion
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#ifdef vms

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_esichr_gc (charsize, nchar)  /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *charsize;                    /* CHARACTER SIZE ARRAY */
INT nchar;                          /* SIZE OF CHARSIZE */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    esichr (charsize, &nchar);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_esichr_gc (charsize, nchar)  /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *charsize;                    /* CHARACTER SIZE ARRAY */
INT nchar;                          /* SIZE OF CHARSIZE */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran esichr();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    esichr (*charsize, nchar);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_esichr_gc (charsize, nchar)  /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *charsize;                    /* CHARACTER SIZE ARRAY */
INT nchar;                          /* SIZE OF CHARSIZE */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    esichr_ (charsize, &nchar);
    
    return status;
    }


#endif
/* END:     */
