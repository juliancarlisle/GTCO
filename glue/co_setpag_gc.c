/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETPAG_GC.C*/
/* *3    22-AUG-1990 15:59:01 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:58:16 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:25:00 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETPAG_GC.C*/
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
    Glue routine from "c" to the FORTRAN routine "SETPAG"
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

publicdef INT co_setpag_gc (d_xpglen, d_ypglen, d_xpgoff, d_ypgoff)   /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_xpglen;                    /* LENGTH OF PLOT PAGE */
DOUBLE d_ypglen;                    /* HEIGHT OF PLOT PAGE */
DOUBLE d_xpgoff;                    /* HORIZONTAL OFFSET */
DOUBLE d_ypgoff;                    /* VERTICAL OFFSET */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xpglen;                   /* LENGTH OF PLOT PAGE */
    FLOAT ypglen;                   /* HEIGHT OF PLOT PAGE */
    FLOAT xpgoff;                   /* HORIZONTAL OFFSET */
    FLOAT ypgoff;                   /* VERTICAL OFFSET */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xpglen = d_xpglen;
    ypglen = d_ypglen;
    xpgoff = d_xpgoff;
    ypgoff = d_ypgoff;
    
    setpag (&xpglen, &ypglen, &xpgoff, &ypgoff);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setpag_gc (d_xpglen, d_ypglen, d_xpgoff, d_ypgoff)   /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_xpglen;                    /* LENGTH OF PLOT PAGE */
DOUBLE d_ypglen;                    /* HEIGHT OF PLOT PAGE */
DOUBLE d_xpgoff;                    /* HORIZONTAL OFFSET */
DOUBLE d_ypgoff;                    /* VERTICAL OFFSET */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xpglen;                   /* LENGTH OF PLOT PAGE */
    FLOAT ypglen;                   /* HEIGHT OF PLOT PAGE */
    FLOAT xpgoff;                   /* HORIZONTAL OFFSET */
    FLOAT ypgoff;                   /* VERTICAL OFFSET */
    fortran setpag();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xpglen = d_xpglen;
    ypglen = d_ypglen;
    xpgoff = d_xpgoff;
    ypgoff = d_ypgoff;
    
    setpag (xpglen, ypglen, xpgoff, ypgoff);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setpag_gc (d_xpglen, d_ypglen, d_xpgoff, d_ypgoff)   /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_xpglen;                    /* LENGTH OF PLOT PAGE */
DOUBLE d_ypglen;                    /* HEIGHT OF PLOT PAGE */
DOUBLE d_xpgoff;                    /* HORIZONTAL OFFSET */
DOUBLE d_ypgoff;                    /* VERTICAL OFFSET */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xpglen;                   /* LENGTH OF PLOT PAGE */
    FLOAT ypglen;                   /* HEIGHT OF PLOT PAGE */
    FLOAT xpgoff;                   /* HORIZONTAL OFFSET */
    FLOAT ypgoff;                   /* VERTICAL OFFSET */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xpglen = d_xpglen;
    ypglen = d_ypglen;
    xpgoff = d_xpgoff;
    ypgoff = d_ypgoff;
    
    setpag_ (&xpglen, &ypglen, &xpgoff, &ypgoff);
    
    return status;
    }


#endif
/* END:     */
