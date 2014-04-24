/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCTRD_GC.C */
/* *4     3-OCT-1991 16:03:48 PURNA "(SPR 4149) fixed casting" */
/* *3    24-SEP-1991 11:41:15 PURNA "(SPR 4149) replaced the fortran call clcres to clctrd" */
/* *2    21-SEP-1990 09:16:11 CHARLIE "(SPR -1) new trend glue" */
/* *1    15-SEP-1990 12:57:02 CHARLIE "DGI glue to calculate trend surface polynomial" */
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCTRD_GC.C */
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
    Glue routine from "c" to the FORTRAN routine "CLCTRD"
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

publicdef INT co_clctrd_gc (x, y, z, npts, polynom, polysize, ideg, 
			    check_config, wrk_array, wrk_size, flag)
/* ------------------ */

FLOAT *x, *y, *z;
INT npts;
FLOAT *polynom;
INT polysize, ideg, check_config;
FLOAT *wrk_array;
INT wrk_size, *flag;

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clctrd (x, y, z, &npts, polynom, &polysize, &ideg, &check_config,
		wrk_array, &wrk_size, flag);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clctrd_gc ()    /* * ARGUEMENT LIST * */
/* ------------------ */


/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran clctrd();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    clctrd ();
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_clctrd_gc (x, y, z, npts, polynom, polysize, ideg,
		check_config, wrk_array, wrk_size, flag)    /* * ARGUEMENT LIST * */
/* ------------------ */

FLOAT *x, *y, *z;
INT npts;
FLOAT *polynom;
INT polysize, ideg, check_config;
FLOAT *wrk_array;
INT wrk_size;
INT *flag;

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    /* fixed the call to fortran function, it was clcres (case 4149) */
    clctrd_ (x, y, z, &npts, polynom, &polysize, &ideg, &check_config,
		wrk_array, &wrk_size, flag);
    
    return status;
    }


#endif
/* END:     */
