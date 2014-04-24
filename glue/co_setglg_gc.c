/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETGLG_GC.C*/
/* *3    22-AUG-1990 15:58:17 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:57:53 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:24:23 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETGLG_GC.C*/
/*****************************************************************************/
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

#ifndef ESI_CO_H

#include "esi_co.h"

#endif

/* Function Description -----------------------------------------------------
Description:
    Glue routine from "c" to the FORTRAN routine "SETGLG"
    supplied by DGI.

Prototype:
    See below.
    
Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    See below.
    
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

publicdef INT co_setglg_gc (iflglg, funit)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflglg;                         /* GRIDDING EXECUTION LOG LEVEL */
INT funit;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setglg (&iflglg, &funit);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setglg_gc (iflglg, funit)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflglg;                         /* GRIDDING EXECUTION LOG LEVEL */
INT funit;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran setglg();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setglg (iflglg, funit);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setglg_gc (iflglg, funit)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflglg;                         /* GRIDDING EXECUTION LOG LEVEL */
INT funit;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setglg_ (&iflglg, &funit);
    
    return status;
    }


#endif
/* END:     */
