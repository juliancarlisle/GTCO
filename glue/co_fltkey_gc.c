/* DEC/CMS REPLACEMENT HISTORY, Element CO_FLTKEY_GC.C */
/* *2    12-SEP-1990 15:58:55 CHARLIE "(SPR -1) initial checkin" */
/* *1    12-SEP-1990 15:50:18 CHARLIE "faulted key map" */
/* DEC/CMS REPLACEMENT HISTORY, Element CO_FLTKEY_GC.C */
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
    Glue routine from "c" to the FORTRAN routine "FLTKEY"
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

publicdef  INT co_fltkey_gc (grid, ncols, nrows, workspace, workspace_size)    /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */
INT *workspace;                     /* WORKSPACE ARRAY */
INT workspace_size;                 /* SIZE WORKSPACE ARRAY */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    fltkey (grid, &ncols, &nrows, workspace, &workspace_size);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef  INT co_fltkey_gc (grid, ncols, nrows, workspace, workspace_size)    /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */
INT *workspace;                     /* WORKSPACE ARRAY */
INT workspace_size;                 /* SIZE WORKSPACE ARRAY */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran fltkey();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    fltkey((float [])grid, ncols, nrows, (int [])workspace, workspace_size);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_fltkey_gc (grid, ncols, nrows, workspace, workspace_size)    /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */
INT *workspace;                     /* WORKSPACE ARRAY */
INT workspace_size;                 /* SIZE WORKSPACE ARRAY */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    fltkey_ (grid, &ncols, &nrows, workspace, &workspace_size);
    
    return status;
    }


#endif
/* END:     */
