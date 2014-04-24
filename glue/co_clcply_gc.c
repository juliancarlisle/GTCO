/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCPLY_GC.C*/
/* *3    22-AUG-1990 15:56:39 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:56:45 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:22:59 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCPLY_GC.C*/
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
    Glue routine from "c" to the FORTRAN routine "CLCPLY"
    supplied by DGI.

Prototype:
    See below.
    
Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    See below.
    
Return Value/Status:
    SUCCESS - Successful completion fo call.
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#ifdef vms

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef  INT co_clcply_gc (x, y, npts, inside, d_znull, grid, ncols, nrows)  /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *x;                           /* BOUNDARY POLYGON X ARRAY */
FLOAT *y;                           /* BOUNDARY POLYGON Y ARRAY */
INT npts;                           /* SIZE OF BOUNDARY POLYGON ARRAY */
INT inside;                         /* INSIDE/OUTSIDE FLAG */
DOUBLE d_znull;                     /* NULL VALUE FOR OUTSIDE CELLS */
FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT znull;                    /* NULL VALUE FOR OUTSIDE CELLS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    znull = d_znull;
    
    clcply (x, y, &npts, &inside, &znull, grid, &ncols, &nrows);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef  INT co_clcply_gc (x, y, npts, inside, d_znull, grid, ncols, nrows)  /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *x;                           /* BOUNDARY POLYGON X ARRAY */
FLOAT *y;                           /* BOUNDARY POLYGON Y ARRAY */
INT npts;                           /* SIZE OF BOUNDARY POLYGON ARRAY */
INT inside;                         /* INSIDE/OUTSIDE FLAG */
DOUBLE d_znull;                     /* NULL VALUE FOR OUTSIDE CELLS */
FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT znull;                    /* NULL VALUE FOR OUTSIDE CELLS */
    fortran clcply();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    znull = d_znull;
    
    clcply (*x, *y, npts, inside, znull, *grid, ncols, nrows);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef  INT co_clcply_gc (x, y, npts, inside, d_znull, grid, ncols, nrows)  /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *x;                           /* BOUNDARY POLYGON X ARRAY */
FLOAT *y;                           /* BOUNDARY POLYGON Y ARRAY */
INT npts;                           /* SIZE OF BOUNDARY POLYGON ARRAY */
INT inside;                         /* INSIDE/OUTSIDE FLAG */
DOUBLE d_znull;                     /* NULL VALUE FOR OUTSIDE CELLS */
FLOAT *grid;                        /* GRID ARRAY */
INT ncols;                          /* NUMBER OF GRID COLUMNS */
INT nrows;                          /* NUMBER OF GRID ROWS */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT znull;                    /* NULL VALUE FOR OUTSIDE CELLS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    znull = d_znull;
    
    clcply_ (x, y, &npts, &inside, &znull, grid, &ncols, &nrows);
    
    return status;
    }


#endif
/* END:     */
