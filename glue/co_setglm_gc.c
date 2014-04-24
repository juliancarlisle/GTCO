/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETGLM_GC.C*/
/* *3    22-AUG-1990 15:58:22 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:57:58 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:24:26 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETGLM_GC.C*/
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
    Glue routine from "c" to the FORTRAN routine "SETGLM"
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

publicdef INT co_setglm_gc (iflglm, d_zmin, d_zmax)   /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflglm;
DOUBLE d_zmin;
DOUBLE d_zmax;

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT zmin;
    FLOAT zmax;
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    zmin = d_zmin;
    zmax = d_zmax;
    
    setglm (&iflglm, &zmin, &zmax);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setglm_gc (iflglm, d_zmin, d_zmax)   /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflglm;
DOUBLE d_zmin;
DOUBLE d_zmax;

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT zmin;
    FLOAT zmax;
    fortran setglm();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    zmin = d_zmin;
    zmax = d_zmax;
    
    setglm (iflglm, zmin, zmax);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setglm_gc (iflglm, d_zmin, d_zmax)   /* * ARGUEMENT LIST * */
/* ------------------ */

INT iflglm;
DOUBLE d_zmin;
DOUBLE d_zmax;

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT zmin;
    FLOAT zmax;
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    zmin = d_zmin;
    zmax = d_zmax;
    
    setglm_ (&iflglm, &zmin, &zmax);
    
    return status;
    }


#endif
/* END:     */
