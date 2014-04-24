/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETCLB_GC.C*/
/* *3    22-AUG-1990 15:58:01 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:57:41 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:24:08 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETCLB_GC.C*/
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

#include "esi_co.h"

/* Function Description -----------------------------------------------------
Description:
    Glue routine from "c" to the FORTRAN routine "SETCLB"
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

publicdef INT co_setclb_gc (d_bgnlen, d_srcdst, d_angmax, d_dstmax) /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_bgnlen;                    /* MINIMUM DISTANCE BETWEEN LABELS */
DOUBLE d_srcdst;                    /* SEARCH DISTANCE FOR LABEL */
DOUBLE d_angmax;                    /* MAXIMUM ANGLE FOR LABEL */
DOUBLE d_dstmax;                    /* MAX. ANGLE BETWEEN LINE SEGS */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT bgnlen;                   /* MINIMUM DISTANCE BETWEEN LABELS */
    FLOAT srcdst;                   /* SEARCH DISTANCE FOR LABEL */
    FLOAT angmax;                   /* MAXIMUM ANGLE FOR LABEL */
    FLOAT dstmax;                   /* MAX. ANGLE BETWEEN LINE SEGS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    bgnlen = d_bgnlen;
    srcdst = d_srcdst;
    angmax = d_angmax;
    dstmax = d_dstmax;
    
    setclb (&bgnlen, &srcdst, &angmax, &dstmax);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setclb_gc (d_bgnlen, d_srcdst, d_angmax, d_dstmax) /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_bgnlen;                    /* MINIMUM DISTANCE BETWEEN LABELS */
DOUBLE d_srcdst;                    /* SEARCH DISTANCE FOR LABEL */
DOUBLE d_angmax;                    /* MAXIMUM ANGLE FOR LABEL */
DOUBLE d_dstmax;                    /* MAX. ANGLE BETWEEN LINE SEGS */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT bgnlen;                   /* MINIMUM DISTANCE BETWEEN LABELS */
    FLOAT srcdst;                   /* SEARCH DISTANCE FOR LABEL */
    FLOAT angmax;                   /* MAXIMUM ANGLE FOR LABEL */
    FLOAT dstmax;                   /* MAX. ANGLE BETWEEN LINE SEGS */
    fortran setclb();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    bgnlen = d_bgnlen;
    srcdst = d_srcdst;
    angmax = d_angmax;
    dstmax = d_dstmax;
    
    setclb (bgnlen, srcdst, angmax, dstmax);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_setclb_gc (d_bgnlen, d_srcdst, d_angmax, d_dstmax) /* * ARGUEMENT LIST * */
/* ------------------ */

DOUBLE d_bgnlen;                    /* MINIMUM DISTANCE BETWEEN LABELS */
DOUBLE d_srcdst;                    /* SEARCH DISTANCE FOR LABEL */
DOUBLE d_angmax;                    /* MAXIMUM ANGLE FOR LABEL */
DOUBLE d_dstmax;                    /* MAX. ANGLE BETWEEN LINE SEGS */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    FLOAT bgnlen;                   /* MINIMUM DISTANCE BETWEEN LABELS */
    FLOAT srcdst;                   /* SEARCH DISTANCE FOR LABEL */
    FLOAT angmax;                   /* MAXIMUM ANGLE FOR LABEL */
    FLOAT dstmax;                   /* MAX. ANGLE BETWEEN LINE SEGS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    bgnlen = d_bgnlen;
    srcdst = d_srcdst;
    angmax = d_angmax;
    dstmax = d_dstmax;
    
    setclb_ (&bgnlen, &srcdst, &angmax, &dstmax);
    
    return status;
    }


#endif
/* END:     */
