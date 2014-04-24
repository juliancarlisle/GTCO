/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETPGD_GC.C */
/* *4    11-MAR-1991 10:32:05 KEE "(SPR -1) Glue files for Trend/Residual project, some of them are different from esi$glue" */
/* *3    21-SEP-1990 12:33:42 CHARLIE "(SPR -1) fix calling argument" */
/* *2    21-SEP-1990 09:17:19 CHARLIE "(SPR -1) new trend glue" */
/* *1    15-SEP-1990 12:58:11 CHARLIE "DGI glue to set the row and cols for trends" */
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETPGD_GC.C */
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
    Glue routine from "c" to the FORTRAN routine "SETPGD"
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

publicdef INT co_setpgd_gc (inmxcl, xgdmin, xgdmax, inmyrw, ygdmin, ygdmax)
/* * ARGUEMENT LIST * */
/* ------------------ */

INT inmxcl;              /* NUMBER OF X-COLUMNS IN THE INPUT ELEVATION GRID. */
DOUBLE xgdmin, xgdmax;    /* MINIMUM AND MAXIMUM X -COLUMN VALUES. */
INT inmyrw;              /* NUMBER OF Y-ROWS IN THE INPUT ELEVATION GRID. */
DOUBLE ygdmin, ygdmax;    /* MINIMUM AND MAXIMUM Y-ROW VALUES. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setpgd (&inmxcl, &xgdmin, &xgdmax, &inmyrw, &ygdmin, &ygdmax);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setpgd_gc (inmxcl, xgdmin, xgdmax, inmyrw, ygdmin, ygdmax)
/* * ARGUEMENT LIST * */
/* ------------------ */

INT inmxcl;              /* NUMBER OF X-COLUMNS IN THE INPUT ELEVATION GRID. */
DOUBLE xgdmin, xgdmax;    /* MINIMUM AND MAXIMUM X -COLUMN VALUES. */
INT inmyrw;              /* NUMBER OF Y-ROWS IN THE INPUT ELEVATION GRID. */
DOUBLE ygdmin, ygdmax;    /* MINIMUM AND MAXIMUM Y-ROW VALUES. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran setpgd();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setpgd (inmxcl, xgdmin, xgdmax, inmyrw, ygdmin, ygdmax);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setpgd_gc (inmxcl, xgdmin, xgdmax, inmyrw, ygdmin, ygdmax)
/* * ARGUEMENT LIST * */
/* ------------------ */

INT inmxcl;              /* NUMBER OF X-COLUMNS IN THE INPUT ELEVATION GRID. */
DOUBLE xgdmin, xgdmax;    /* MINIMUM AND MAXIMUM X -COLUMN VALUES. */
INT inmyrw;              /* NUMBER OF Y-ROWS IN THE INPUT ELEVATION GRID. */
DOUBLE ygdmin, ygdmax;    /* MINIMUM AND MAXIMUM Y-ROW VALUES. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setpgd_ (&inmxcl, &xgdmin, &xgdmax, &inmyrw, &ygdmin, &ygdmax);
    
    return status;
    }


#endif
/* END:     */
