/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETTIK_GC.C*/
/* *3    22-AUG-1990 15:59:46 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:58:37 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:25:30 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETTIK_GC.C*/
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
    Glue routine from "c" to the FORTRAN routine "SETTIK"
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

publicdef INT co_settik_gc (tickflag, tick_interval, d_tick_length, d_tick_separation)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT tickflag;                       /* DOWNHILL TICK MARK FLAG */
INT tick_interval;                  /* INTERVAL FOR TICK MARK CONTOURS */
DOUBLE d_tick_length;               /* TICK MARK LENGTH */
DOUBLE d_tick_separation;           /* TICK MARK SEPARATION */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT tick_length;              /* TICK MARK LENGTH */
    FLOAT tick_separation;          /* TICK MARK SEPARATION */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    tick_length = d_tick_length;
    tick_separation = d_tick_separation;
    
    settik (&tickflag, &tick_interval, &tick_length, &tick_separation);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_settik_gc (tickflag, tick_interval, d_tick_length, d_tick_separation)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT tickflag;                       /* DOWNHILL TICK MARK FLAG */
INT tick_interval;                  /* INTERVAL FOR TICK MARK CONTOURS */
DOUBLE d_tick_length;               /* TICK MARK LENGTH */
DOUBLE d_tick_separation;           /* TICK MARK SEPARATION */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT tick_length;              /* TICK MARK LENGTH */
    FLOAT tick_separation;          /* TICK MARK SEPARATION */
    fortran settik();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    tick_length = d_tick_length;
    tick_separation = d_tick_separation;
    
    settik (tickflag, tick_interval, tick_length, tick_separation);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_settik_gc (tickflag, tick_interval, d_tick_length, d_tick_separation)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT tickflag;                       /* DOWNHILL TICK MARK FLAG */
INT tick_interval;                  /* INTERVAL FOR TICK MARK CONTOURS */
DOUBLE d_tick_length;               /* TICK MARK LENGTH */
DOUBLE d_tick_separation;           /* TICK MARK SEPARATION */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT tick_length;              /* TICK MARK LENGTH */
    FLOAT tick_separation;          /* TICK MARK SEPARATION */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    tick_length = d_tick_length;
    tick_separation = d_tick_separation;
    
    settik_ (&tickflag, &tick_interval, &tick_length, &tick_separation);
    
    return status;
    }


#endif
/* END:     */
