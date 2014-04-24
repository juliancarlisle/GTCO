/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETSLB_GC.C */
/* *2    12-SEP-1990 16:01:33 CHARLIE "(SPR -1) initial checkin" */
/* *1    12-SEP-1990 15:55:26 CHARLIE "perspective slab distance glue" */
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETSLB_GC.C */
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
    Glue routine from "c" to the FORTRAN routine "SETSLB"
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

publicdef INT co_setslb_gc (draw_base, extra)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT draw_base;                         /* GRIDDING EXECUTION LOG LEVEL */
DOUBLE extra;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT height = extra;

    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setslb (&draw_base, &height);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setslb_gc (draw_base, extra)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT draw_base;                         /* GRIDDING EXECUTION LOG LEVEL */
DOUBLE extra;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT height = extra;
    fortran setslb();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setslb (draw_base, height);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setslb_gc (draw_base, extra)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT draw_base;                         /* GRIDDING EXECUTION LOG LEVEL */
DOUBLE extra;                          /* FORTRAN LOGICAL UNIT */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT height = extra;    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    setslb_ (&draw_base, &height);
    
    return status;
    }


#endif
/* END:     */
