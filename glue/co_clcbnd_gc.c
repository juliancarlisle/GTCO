/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCBND_GC.C*/
/* *3    22-AUG-1990 15:55:49 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:56:24 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:22:36 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCBND_GC.C*/
/******************************************************************************

                Copyright Exploration Systems, Inc. 1989
           Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

            Exploration Systems, Inc.
            579 Market Street
            San Francisco, CA  USA 94105
            (415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#include "esi_co.h"

/* Function Description -----------------------------------------------------
Description:
    Glue routine from "c" to the FORTRAN routine "CLCBND"
    supplied by DGI.

Prototype:
    See below.
    
Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    See below.
    
Return Value/Status:
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

#ifdef vms

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clcbnd_gc (x, y, z, npts, bound_type, bound_in, x_bnd, y_bnd, bound_out) /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *x;                           /* SCATTER X ARRAY */
FLOAT *y;                           /* SCATTER Y ARRAY */
FLOAT *z;                           /* SCATTER Z ARRAY */
INT npts;                           /* SIZE OF SCATTER ARRAY */
INT bound_type;                     /* TYPE OF BOUNDARY POLYGON */
INT bound_in;                       /* SIZE OF X_BND AND Y_BND */
FLOAT *x_bnd;                       /* BOUNDARY POLYGON X ARRAY */
FLOAT *y_bnd;                       /* BOUNDARY POLYGON Y ARRAY */
INT *bound_out;                     /* NUMBER OF POINTS IN BOUNDARY */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcbnd (x, y, z, &npts, &bound_type, &bound_in, x_bnd, y_bnd, bound_out);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clcbnd_gc (x, y, z, npts, bound_type, bound_in, x_bnd, y_bnd, bound_out) /* * ARGUMENT  LIST * */
/* ------------------ */

FLOAT *x;                           /* SCATTER X ARRAY */
FLOAT *y;                           /* SCATTER Y ARRAY */
FLOAT *z;                           /* SCATTER Z ARRAY */
INT npts;                           /* SIZE OF SCATTER ARRAY */
INT bound_type;                     /* TYPE OF BOUNDARY POLYGON */
INT bound_in;                       /* SIZE OF X_BND AND Y_BND */
FLOAT *x_bnd;                       /* BOUNDARY POLYGON X ARRAY */
FLOAT *y_bnd;                       /* BOUNDARY POLYGON Y ARRAY */
INT *bound_out;                     /* NUMBER OF POINTS IN BOUNDARY */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran clcbnd();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcbnd (*x, *y, *z, npts, bound_type, bound_in, *x_bnd, *y_bnd, *bound_out);
    
    return status;
    }


#endif

#if UNIX
publicdef INT co_clcbnd_gc (x, y, z, npts, bound_type, bound_in, x_bnd, y_bnd, bound_out)
FLOAT *x;                           /* SCATTER X ARRAY */
FLOAT *y;                           /* SCATTER Y ARRAY */
FLOAT *z;                           /* SCATTER Z ARRAY */
INT npts;                           /* SIZE OF SCATTER ARRAY */
INT bound_type;                     /* TYPE OF BOUNDARY POLYGON */
INT bound_in;                       /* SIZE OF X_BND AND Y_BND */
FLOAT *x_bnd;                       /* BOUNDARY POLYGON X ARRAY */
FLOAT *y_bnd;                       /* BOUNDARY POLYGON Y ARRAY */
INT *bound_out;                     /* NUMBER OF POINTS IN BOUNDARY */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clcbnd_ (x, y, z, &npts, &bound_type, &bound_in, x_bnd, y_bnd, bound_out);
    
    return status;
    }


#endif
/* END:     */
