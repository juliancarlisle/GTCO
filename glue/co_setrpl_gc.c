/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETRPL_GC.C*/
/* *3    22-AUG-1990 15:59:21 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:58:25 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:25:12 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETRPL_GC.C*/
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

#include "esi_co.h"

/* Function Description -----------------------------------------------------
Description:
    Glue routine from "c" to the FORTRAN routine "SETRPL"
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

publicdef INT co_setrpl_gc (iflrpl, funit)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflrpl;                         /* CONTOURING EXECUTION LOG LEVEL */
INT funit;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setrpl (&iflrpl, &funit);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setrpl_gc (iflrpl, funit)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflrpl;                         /* CONTOURING EXECUTION LOG LEVEL */
INT funit;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran setrpl();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setrpl (iflrpl, funit);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setrpl_gc (iflrpl, funit)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflrpl;                         /* CONTOURING EXECUTION LOG LEVEL */
INT funit;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setrpl_ (&iflrpl, &funit);
    
    return status;
    }


#endif
/* END:     */
