/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETCON_GC.C*/
/* *3    22-AUG-1990 15:58:06 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:57:45 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:24:13 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETCON_GC.C*/
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
    Glue routine from "c" to the FORTRAN routine "SETCON"
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

publicdef INT co_setcon_gc (d_refelv, d_c_interval, b_interval, l_interval, textsize,
                            places) /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_refelv;                    /* REFERENCE ELEVATION */
DOUBLE d_c_interval;                /* CONTOUR INTERVAL */
INT b_interval;                     /* BOLD LINE INTERVAL */
INT l_interval;                     /* LABEL LINE INTERVAL */
INT textsize;                       /* SIZE OF TEXT */
INT places;                         /* NUMBER OF PLACES FOR LABEL */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT refelv;                   /* REFERENCE ELEVATION */
    FLOAT c_interval;               /* CONTOUR INTERVAL */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    refelv = d_refelv;
    c_interval = d_c_interval;
    
    setcon (&refelv, &c_interval, &b_interval, &l_interval, &textsize, &places);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setcon_gc (d_refelv, d_c_interval, b_interval, l_interval, textsize,
                            places) /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_refelv;                    /* REFERENCE ELEVATION */
DOUBLE d_c_interval;                /* CONTOUR INTERVAL */
INT b_interval;                     /* BOLD LINE INTERVAL */
INT l_interval;                     /* LABEL LINE INTERVAL */
INT textsize;                       /* SIZE OF TEXT */
INT places;                         /* NUMBER OF PLACES FOR LABEL */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT refelv;                   /* REFERENCE ELEVATION */
    FLOAT c_interval;               /* CONTOUR INTERVAL */
    fortran setcon();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    refelv = d_refelv;
    c_interval = d_c_interval;
    
    setcon (refelv, c_interval, b_interval, l_interval, textsize, places);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setcon_gc (d_refelv, d_c_interval, b_interval, l_interval, textsize,
                            places) /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_refelv;                    /* REFERENCE ELEVATION */
DOUBLE d_c_interval;                /* CONTOUR INTERVAL */
INT b_interval;                     /* BOLD LINE INTERVAL */
INT l_interval;                     /* LABEL LINE INTERVAL */
INT textsize;                       /* SIZE OF TEXT */
INT places;                         /* NUMBER OF PLACES FOR LABEL */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT refelv;                   /* REFERENCE ELEVATION */
    FLOAT c_interval;               /* CONTOUR INTERVAL */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    refelv = d_refelv;
    c_interval = d_c_interval;
    
    setcon_ (&refelv, &c_interval, &b_interval, &l_interval, &textsize, &places);
    
    return status;
    }


#endif
/* END:     */
