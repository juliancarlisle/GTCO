/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETXYG_GC.C*/
/* *3    22-AUG-1990 16:00:24 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:58:49 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:25:51 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETXYG_GC.C*/
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
    Glue routine from "c" to the FORTRAN routine "SETXYG"
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

publicdef INT co_setxyg_gc (ncols, d_xmin, d_xmax, nrows, d_ymin, d_ymax) /* * ARGUEMENT LIST * */
/* ------------------ */

INT ncols;                          /* NUMBER OF GRID COLUMNS */
DOUBLE d_xmin;                      /* MINIMUM X VALUE FOR GRID */
DOUBLE d_xmax;                      /* MAXIMUM X VALUE FOR GRID */
INT nrows;                          /* NUMBER OF GRID ROWS */
DOUBLE d_ymin;                      /* MINIMUM Y VALUE FOR GRID */
DOUBLE d_ymax;                      /* MAXIMUM Y VALUE FOR GRID */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xmin;                     /* MINIMUM X VALUE FOR GRID */
    FLOAT xmax;                     /* MAXIMUM X VALUE FOR GRID */
    FLOAT ymin;                     /* MINIMUM Y VALUE FOR GRID */
    FLOAT ymax;                     /* MAXIMUM Y VALUE FOR GRID */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xmin = d_xmin;
    xmax = d_xmax;
    ymin = d_ymin;
    ymax = d_ymax;
    
    setxyg (&ncols, &xmin, &xmax, &nrows, &ymin, &ymax);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setxyg_gc (ncols, d_xmin, d_xmax, nrows, d_ymin, d_ymax) /* * ARGUEMENT LIST * */
/* ------------------ */

INT ncols;                          /* NUMBER OF GRID COLUMNS */
DOUBLE d_xmin;                      /* MINIMUM X VALUE FOR GRID */
DOUBLE d_xmax;                      /* MAXIMUM X VALUE FOR GRID */
INT nrows;                          /* NUMBER OF GRID ROWS */
DOUBLE d_ymin;                      /* MINIMUM Y VALUE FOR GRID */
DOUBLE d_ymax;                      /* MAXIMUM Y VALUE FOR GRID */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xmin;                     /* MINIMUM X VALUE FOR GRID */
    FLOAT xmax;                     /* MAXIMUM X VALUE FOR GRID */
    FLOAT ymin;                     /* MINIMUM Y VALUE FOR GRID */
    FLOAT ymax;                     /* MAXIMUM Y VALUE FOR GRID */
    fortran setxyg();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xmin = d_xmin;
    xmax = d_xmax;
    ymin = d_ymin;
    ymax = d_ymax;
    
    setxyg (ncols, xmin, xmax, nrows, ymin, ymax);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setxyg_gc (ncols, d_xmin, d_xmax, nrows, d_ymin, d_ymax) /* * ARGUEMENT LIST * */
/* ------------------ */

INT ncols;                          /* NUMBER OF GRID COLUMNS */
DOUBLE d_xmin;                      /* MINIMUM X VALUE FOR GRID */
DOUBLE d_xmax;                      /* MAXIMUM X VALUE FOR GRID */
INT nrows;                          /* NUMBER OF GRID ROWS */
DOUBLE d_ymin;                      /* MINIMUM Y VALUE FOR GRID */
DOUBLE d_ymax;                      /* MAXIMUM Y VALUE FOR GRID */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xmin;                     /* MINIMUM X VALUE FOR GRID */
    FLOAT xmax;                     /* MAXIMUM X VALUE FOR GRID */
    FLOAT ymin;                     /* MINIMUM Y VALUE FOR GRID */
    FLOAT ymax;                     /* MAXIMUM Y VALUE FOR GRID */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xmin = d_xmin;
    xmax = d_xmax;
    ymin = d_ymin;
    ymax = d_ymax;
    
    setxyg_ (&ncols, &xmin, &xmax, &nrows, &ymin, &ymax);
    
    return status;
    }


#endif
/* END:     */
