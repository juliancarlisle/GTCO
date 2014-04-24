/* DEC/CMS REPLACEMENT HISTORY, Element CO_NFILE_GC.C*/
/* *3    22-AUG-1990 15:57:53 VINCE "(SPR 5644) Code Cleanup"*/
/* *2     7-FEB-1990 06:57:38 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    13-AUG-1989 16:24:05 GILLESPIE "DGI Grid & contour FORTRAN bindings"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CO_NFILE_GC.C*/
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

#include "esi_gl_defs.h"
#include "esi_ho_desc.h"
#include "esi_ho_files.h"

/* Function Description -----------------------------------------------------
Description:
    C to Fortran glue for function co_new_file, which does a
    Fortran open and returns the unit number.

Prototype:
    publicdef VOID co_new_file_gc(FILENAME filename, INT *unit, INT *status);
    
Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    (I) filename    -(FILENAME) Filename of requested file.
    (O) unit        -(INT) Unit number of requested file.
    (O) status      -(INT) Status of operation.

Return Value/Status:
    Function returns the status code returned by co_new_file.
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef VOID co_new_file_gc (FILENAME filename, INT *unit, INT *status) 
#else
publicdef VOID co_new_file_gc (filename, unit, status)
FILENAME filename;
INT *unit;
INT *status;
#endif
    {

#ifdef vms
    co_new_file (STRING_DESCRIPTOR_FROM_C (filename), unit, status);
#endif

#if UNIX
    co_new_file_ (filename, unit, status, strlen (filename));
#endif

#ifdef primos
    fortran co_new_file();
    co_new_file((char [])filename, *unit, *status, strlen (filename), 0L, 0L);
#endif
    return;
    }
/* END:     */
