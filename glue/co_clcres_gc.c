/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCRES_GC.C */
/* *4    11-MAR-1991 10:31:59 KEE "(SPR -1) Glue files for Trend/Residual project, some of them are different from esi$glue" */
/* *3    31-OCT-1990 09:43:31 GILLESPIE "(SPR 37) Fix sun defs" */
/* *2    21-SEP-1990 09:13:13 CHARLIE "(SPR -1) new trend glue" */
/* *1    15-SEP-1990 12:55:42 CHARLIE "DGI glue to calculate residual" */
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCRES_GC.C */
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
    Glue routine from "c" to the FORTRAN routine "CLCRES"
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

publicdef INT co_clcres_gc (xa, ya, za, inmxyz, poly, idmply, ideg, zda)
/* * ARGUEMENT LIST * */
/* ------------------ */

FLOAT *xa;   /* THE COORDINATES OF THE INPUT DATA POINTS */
FLOAT *ya;   /* THE COORDINATES OF THE INPUT DATA POINTS */
FLOAT *za;   /* THE COORDINATES OF THE INPUT DATA POINTS */
INT inmxyz;  /* THE NUMBER OF INPUT DATA POINTS. */
FLOAT *poly; /* THE COEFFICIENTS OF THE BIVARIATE POLYNOMIAL SURFACE FROM 
		WHICH OFFSETS ARE COMPUTED. */
INT idmply;  /* THE DIMENSIONS OF THE POLY ARRAY. */
INT ideg;    /* THE DEGREE OF THE POLYNOMIAL. */
FLOAT *zda;  /* THE COMPUTED OFFSETS. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcres (xa, ya, za, &inmxyz, poly, &idmply, &ideg, zda);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clcres_gc (xa, ya, za, inmxyz, poly, idmply, ideg, zda)
/* * ARGUEMENT LIST * */
/* ------------------ */

FLOAT *xa;   /* THE COORDINATES OF THE INPUT DATA POINTS */
FLOAT *ya;   /* THE COORDINATES OF THE INPUT DATA POINTS */
FLOAT *za;   /* THE COORDINATES OF THE INPUT DATA POINTS */
INT inmxyz;  /* THE NUMBER OF INPUT DATA POINTS. */
FLOAT *poly; /* THE COEFFICIENTS OF THE BIVARIATE POLYNOMIAL SURFACE FROM 
		WHICH OFFSETS ARE COMPUTED. */
INT idmply;  /* THE DIMENSIONS OF THE POLY ARRAY. */
INT ideg;    /* THE DEGREE OF THE POLYNOMIAL. */
FLOAT *zda;  /* THE COMPUTED OFFSETS. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran clcres();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcres (*xa, *ya, *za, inmxyz, *poly, idmply, ideg, *zda);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clcres_gc (xa, ya, za, inmxyz, poly, idmply, ideg, zda)
/* * ARGUEMENT LIST * */
/* ------------------ */

FLOAT *xa;   /* THE COORDINATES OF THE INPUT DATA POINTS */
FLOAT *ya;   /* THE COORDINATES OF THE INPUT DATA POINTS */
FLOAT *za;   /* THE COORDINATES OF THE INPUT DATA POINTS */
INT inmxyz;  /* THE NUMBER OF INPUT DATA POINTS. */
FLOAT *poly; /* THE COEFFICIENTS OF THE BIVARIATE POLYNOMIAL SURFACE FROM 
		WHICH OFFSETS ARE COMPUTED. */
INT idmply;  /* THE DIMENSIONS OF THE POLY ARRAY. */
INT ideg;    /* THE DEGREE OF THE POLYNOMIAL. */
FLOAT *zda;  /* THE COMPUTED OFFSETS. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcres_ (xa, ya, za, &inmxyz, poly, &idmply, &ideg, zda);
    
    return status;
    }


#endif
/* END:     */
