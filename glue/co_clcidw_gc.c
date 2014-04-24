/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCIDW_GC.C */
/* *3    11-MAR-1991 10:31:52 KEE "(SPR -1) Glue files for Trend/Residual project, some of them are different from esi$glue" */
/* *2    21-SEP-1990 09:09:56 CHARLIE "(SPR -1) new trend glue" */
/* *1    15-SEP-1990 12:54:34 CHARLIE "DGI glue to calculate workspace needed" */
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCIDW_GC.C */
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
    Glue routine from "c" to the FORTRAN routine "CLCIDW"
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

publicdef INT co_clcidw_gc (ideg, inmxyz, idmwrk)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT ideg;       
INT inmxyz;
INT *idmwrk;   /* THE COMPUTED OPTIMAL SIZE FOR THE SINGLE PRECISION REAL 
		  CLCFTD WORK ARRAY. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcidw (&ideg, &inmxyz, idmwrk);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clcidw_gc (ideg, inmxyz, idmwrk)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT ideg;       
INT inmxyz;
INT *idmwrk;   /* THE COMPUTED OPTIMAL SIZE FOR THE SINGLE PRECISION REAL 
		  CLCFTD WORK ARRAY. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran clcidw();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcidw (ideg, inmxyz, *idmwrk);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clcidw_gc (ideg, inmxyz, idmwrk)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT ideg;       
INT inmxyz;
INT *idmwrk;   /* THE COMPUTED OPTIMAL SIZE FOR THE SINGLE PRECISION REAL 
		  CLCFTD WORK ARRAY. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcidw_ (&ideg, &inmxyz, idmwrk);
    
    return status;
    }


#endif
/* END:     */
