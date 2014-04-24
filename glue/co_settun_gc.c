/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETTUN_GC.C */
/* *3    11-MAR-1991 10:32:10 KEE "(SPR -1) Glue files for Trend/Residual project, some of them are different from esi$glue" */
/* *2    21-SEP-1990 09:17:44 CHARLIE "(SPR -1) new trend glue" */
/* *1    15-SEP-1990 12:58:51 CHARLIE "DGI glue set logical unit for trend report logging" */
/* DEC/CMS REPLACEMENT HISTORY, Element CO_SETTUN_GC.C */
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
    Glue routine from "c" to the FORTRAN routine "SETTUN"
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

publicdef INT co_settun_gc (iunlog, iflrpl)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iunlog;  /*  IUNLOG (INTEGER) -- LOGICAL UNIT NUMBER FOR THE
		 TREND SURFACE LIBRARY LOG FILE. */
INT iflrpl;  /*  IFLRPL (INTEGER) -- REPORT LEVEL FLAG, WHERE --
		 1 = NO REPORT LOG IS PRODUCED.
		 2 = ONLY CALLS PROVOKING ERRORS ARE LOGGED.
		 3 = (DEFAULT) EVERY ROUTINE CALL IS LOGGED, WITH
		     ERROR MESSAGES, AND SUMMARY INFORMATION. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    settun (&iunlog, &iflrpl);
    
    return status;
    }


#endif

#ifdef primos

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_settun_gc (iunlog, iflrpl)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iunlog;  /*  IUNLOG (INTEGER) -- LOGICAL UNIT NUMBER FOR THE
		 TREND SURFACE LIBRARY LOG FILE. */
INT iflrpl;  /*  IFLRPL (INTEGER) -- REPORT LEVEL FLAG, WHERE --
		 1 = NO REPORT LOG IS PRODUCED.
		 2 = ONLY CALLS PROVOKING ERRORS ARE LOGGED.
		 3 = (DEFAULT) EVERY ROUTINE CALL IS LOGGED, WITH
		     ERROR MESSAGES, AND SUMMARY INFORMATION. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    fortran settun();
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    settun (iunlog, iflrpl);
    
    return status;
    }


#endif

#if UNIX

/* * FUNCTION TITLE * */
/* ------------------ */

publicdef INT co_settun_gc (iunlog, iflrpl)    /* * ARGUEMENT LIST * */
/* ------------------ */

INT iunlog;  /*  IUNLOG (INTEGER) -- LOGICAL UNIT NUMBER FOR THE
		 TREND SURFACE LIBRARY LOG FILE. */
INT iflrpl;  /*  IFLRPL (INTEGER) -- REPORT LEVEL FLAG, WHERE --
		 1 = NO REPORT LOG IS PRODUCED.
		 2 = ONLY CALLS PROVOKING ERRORS ARE LOGGED.
		 3 = (DEFAULT) EVERY ROUTINE CALL IS LOGGED, WITH
		     ERROR MESSAGES, AND SUMMARY INFORMATION. */

/* * VARIABLE LIST * */
/* ----------------- */
    {
    INT status;                     /* RETURN STATUS */
    
    /* ********************************************************************** */
    
    status = SUCCESS;
    
    settun_ (&iunlog, &iflrpl);
    
    return status;
    }


#endif
/* END:     */
