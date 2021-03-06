/* DEC/CMS REPLACEMENT HISTORY, Element CO_ENDGRD_GC.C*/
/* *3    22-AUG-1990 15:57:22 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:57:09 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:23:28 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_ENDGRD_GC.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_ENDGRD_GC.C*/
/* *1    19-JUN-1989 12:01:57 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_ENDGRD_GC.C*/
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
    Glue routine from "c" to FORTRAN routine "ENDGRD" supplied
    by DGI.

Prototype:
    publicdef INT co_endgrd_gc();
    
Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    None.
    
Return Value/Status:
    SUCCESS - Successful completion
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT co_endgrd_gc () 
#else
publicdef INT co_endgrd_gc ()
#endif
    {
#if UNIX
    endgrd_ ();
#else
    endgrd ();
#endif
    return SUCCESS;
    }
/* END:     */
