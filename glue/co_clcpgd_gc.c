/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCPGD_GC.C */
/* *3    11-MAR-1991 10:31:56 KEE "(SPR -1) Glue files for Trend/Residual project, some of them are different from esi$glue" */
/* *2    21-SEP-1990 09:10:22 CHARLIE "(SPR -1) new trend glue" */
/* *1    15-SEP-1990 12:55:12 CHARLIE "DGI glue to calculate grid rows from polynomial trend" */
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCPGD_GC.C */
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
    Glue routine from "c" to the FORTRAN routine "CLCPGD"
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

publicdef INT co_clcpgd_gc (poly, idmply, ideg, elvarr, idmxcl, idmyrw)
/* * ARGUEMENT LIST * */
/* ------------------ */

FLOAT *poly;          /* COEFFICIENTS OF THE POLYNOMIAL TO BE EVALUATED */
INT idmply;           /* DIMENSIONS OF THE POLY ARRAY. */
INT ideg;             /* THE DEGREE OF THE POLYNOMIAL. */
FLOAT *elvarr;        /* THE VALUES OF THE POLYNOMIAL EVALUATED OVER THE GRID. */
INT idmxcl, idmyrw;   /* NUMBER OF X-COLUMNS AND Y-ROWS IN THE ELEVATION 
			 ARRAY, ELVARR. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcpgd (poly, &idmply, &ideg, elvarr, &idmxcl, &idmyrw);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clcpgd_gc (poly, idmply, ideg, elvarr, idmxcl, idmyrw)
/* * ARGUEMENT LIST * */
/* ------------------ */

FLOAT *poly;          /* COEFFICIENTS OF THE POLYNOMIAL TO BE EVALUATED */
INT idmply;           /* DIMENSIONS OF THE POLY ARRAY. */
INT ideg;             /* THE DEGREE OF THE POLYNOMIAL. */
FLOAT *elvarr;        /* THE VALUES OF THE POLYNOMIAL EVALUATED OVER THE GRID. */
INT idmxcl, idmyrw;   /* NUMBER OF X-COLUMNS AND Y-ROWS IN THE ELEVATION 
			 ARRAY, ELVARR. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran clcpgd();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcpgd (*poly, idmply, ideg, *elvarr, idmxcl, idmyrw);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clcpgd_gc (poly, idmply, ideg, elvarr, idmxcl, idmyrw)
/* * ARGUEMENT LIST * */
/* ------------------ */

FLOAT *poly;          /* COEFFICIENTS OF THE POLYNOMIAL TO BE EVALUATED */
INT idmply;           /* DIMENSIONS OF THE POLY ARRAY. */
INT ideg;             /* THE DEGREE OF THE POLYNOMIAL. */
FLOAT *elvarr;        /* THE VALUES OF THE POLYNOMIAL EVALUATED OVER THE GRID. */
INT idmxcl, idmyrw;   /* NUMBER OF X-COLUMNS AND Y-ROWS IN THE ELEVATION 
			 ARRAY, ELVARR. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcpgd_ (poly, &idmply, &ideg, elvarr, &idmxcl, &idmyrw);
    
    return status;
    }


#endif
/* END:     */

