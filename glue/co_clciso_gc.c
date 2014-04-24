/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCISO_GC.C*/
/* *3    22-AUG-1990 15:56:32 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:56:42 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:22:56 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCISO_GC.C*/
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
    Glue routine from "c" to the FORTRAN routine "CLCISO"
    supplied by DGI.

Prototype:
    See below.
    
Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    See below.
    
Return Value/Status:
    SUCCESS - Successful completion of call.
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#ifdef vms

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef  INT co_clciso_gc (x, y, z, npts, grid, ncols, nrows, workspace, worksize)   /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *x;                           /* SCATTER X ARRAY */
FLOAT *y;                           /* SCATTER Y ARRAY */
FLOAT *z;                           /* SCATTER Z ARRAY */
INT npts;                           /* SIZE OF SCATTER ARRAY */
FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */
INT *workspace;
INT worksize;

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clciso (x, y, z, &npts, grid, &ncols, &nrows, workspace, &worksize);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef  INT co_clciso_gc (x, y, z, npts, grid, ncols, nrows, workspace, worksize)   /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *x;                           /* SCATTER X ARRAY */
FLOAT *y;                           /* SCATTER Y ARRAY */
FLOAT *z;                           /* SCATTER Z ARRAY */
INT npts;                           /* SIZE OF SCATTER ARRAY */
FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */
INT *workspace;
INT worksize;

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran clciso();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clciso (*x, *y, *z, npts, *grid, ncols, nrows, *workspace, worksize);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef  INT co_clciso_gc (x, y, z, npts, grid, ncols, nrows, workspace, worksize)   /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *x;                           /* SCATTER X ARRAY */
FLOAT *y;                           /* SCATTER Y ARRAY */
FLOAT *z;                           /* SCATTER Z ARRAY */
INT npts;                           /* SIZE OF SCATTER ARRAY */
FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */
INT *workspace;
INT worksize;

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clciso_ (x, y, z, &npts, grid, &ncols, &nrows, workspace, &worksize);
    
    return status;
    }


#endif
/* END:     */
