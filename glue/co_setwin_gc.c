/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETWIN_GC.C*/
/* *3    22-AUG-1990 16:00:02 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:58:44 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:25:45 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETWIN_GC.C*/
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
    Glue routine from "c" to the FORTRAN routine "SETWIN"
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

publicdef INT co_setwin_gc (d_xwnlen, d_ywnlen, d_xwnoff, d_ywnoff)   /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_xwnlen;                    /* LENGTH OF PLOT WINDOW */
DOUBLE d_ywnlen;                    /* HEIGHT OF PLOT WINDOW */
DOUBLE d_xwnoff;                    /* HORIZONTAL OFFSET */
DOUBLE d_ywnoff;                    /* VERTICAL OFFSET */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xwnlen;                   /* LENGTH OF PLOT WINDOW */
    FLOAT ywnlen;                   /* HEIGHT OF PLOT WINDOW */
    FLOAT xwnoff;                   /* HORIZONTAL OFFSET */
    FLOAT ywnoff;                   /* VERTICAL OFFSET */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xwnlen = d_xwnlen;
    ywnlen = d_ywnlen;
    xwnoff = d_xwnoff;
    ywnoff = d_ywnoff;
    
    setwin (&xwnlen, &ywnlen, &xwnoff, &ywnoff);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setwin_gc (d_xwnlen, d_ywnlen, d_xwnoff, d_ywnoff)   /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_xwnlen;                    /* LENGTH OF PLOT WINDOW */
DOUBLE d_ywnlen;                    /* HEIGHT OF PLOT WINDOW */
DOUBLE d_xwnoff;                    /* HORIZONTAL OFFSET */
DOUBLE d_ywnoff;                    /* VERTICAL OFFSET */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xwnlen;                   /* LENGTH OF PLOT WINDOW */
    FLOAT ywnlen;                   /* HEIGHT OF PLOT WINDOW */
    FLOAT xwnoff;                   /* HORIZONTAL OFFSET */
    FLOAT ywnoff;                   /* VERTICAL OFFSET */
    fortran setwin();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xwnlen = d_xwnlen;
    ywnlen = d_ywnlen;
    xwnoff = d_xwnoff;
    ywnoff = d_ywnoff;
    
    setwin (xwnlen, ywnlen, xwnoff, ywnoff);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setwin_gc (d_xwnlen, d_ywnlen, d_xwnoff, d_ywnoff)   /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_xwnlen;                    /* LENGTH OF PLOT WINDOW */
DOUBLE d_ywnlen;                    /* HEIGHT OF PLOT WINDOW */
DOUBLE d_xwnoff;                    /* HORIZONTAL OFFSET */
DOUBLE d_ywnoff;                    /* VERTICAL OFFSET */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT xwnlen;                   /* LENGTH OF PLOT WINDOW */
    FLOAT ywnlen;                   /* HEIGHT OF PLOT WINDOW */
    FLOAT xwnoff;                   /* HORIZONTAL OFFSET */
    FLOAT ywnoff;                   /* VERTICAL OFFSET */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    xwnlen = d_xwnlen;
    ywnlen = d_ywnlen;
    xwnoff = d_xwnoff;
    ywnoff = d_ywnoff;
    
    setwin_ (&xwnlen, &ywnlen, &xwnoff, &ywnoff);
    
    return status;
    }


#endif
/* END:     */
