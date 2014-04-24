/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCHGT_GC.C*/
/* *3    22-AUG-1990 15:56:07 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:56:36 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:22:46 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCHGT_GC.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCHGT_GC.C*/
/* *1    19-JUN-1989 12:01:23 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_CLCHGT_GC.C*/
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
    FORTRAN glue for call to DGI routine CLCHGT.

Prototype:
    publicdef co_clchgt_gc(FLOAT *xptarr, FLOAT *yptarr, INT inmxyp, FLOAT *elvarr, 
    INT idmxcl, INT idmycl, FLOAT *hgtarr);
    
Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    See below.
    
Return Value/Status:
        
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef co_clchgt_gc (FLOAT *xptarr, FLOAT *yptarr, INT inmxyp, FLOAT *elvarr,
                        INT idmxcl, INT idmycl, FLOAT *hgtarr) 
#else
publicdef co_clchgt_gc (xptarr, yptarr, inmxyp, elvarr, idmxcl, idmycl, hgtarr)
FLOAT *xptarr;
FLOAT *yptarr;
INT inmxyp;
FLOAT *elvarr;
INT idmxcl;
INT idmycl;
FLOAT *hgtarr;
#endif
    {
#ifdef vms
    CLCHGT (xptarr, yptarr, &inmxyp, elvarr, &idmxcl, &idmycl, hgtarr);
#endif

#if UNIX
    clchgt_ (xptarr, yptarr, &inmxyp, elvarr, &idmxcl, &idmycl, hgtarr);
#endif

#ifdef primos
    fortran clchgt();
    clchgt ((FLOAT [])xptarr, (FLOAT [])yptarr, inmxyp, (FLOAT [])elvarr, idmxcl, idmycl,
            (FLOAT [])hgtarr);
#endif
    }
/* END:     */
