/* DEC/CMS REPLACEMENT HISTORY, Element TFG_CLOSE.C */
/* *3    20-JUN-1991 15:11:11 KEE "(SPR -1) Fix Perspective Overlay display crashing " */
/* *2    20-NOV-1990 09:27:23 MING "(SPR 6173) glue for closefil" */
/* *1    15-NOV-1990 15:20:10 MING "glue file for closing a file" */
/* DEC/CMS REPLACEMENT HISTORY, Element TFG_CLOSE.C */
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1990
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND
MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphics Systems, Inc.
			201 Tamal Vista Blvd
			Corte Madera, CA  USA 94925
			(415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/



/* Function Description -----------------------------------------------------
Description:
    Glue function for closing a file open fortran


Prototype:
    publicdef INT func (arg);

Parameters:	    (indicate (I)/(O)/(M) for input/output/input-and-modified)
    (I) arg	- description

Return Value/Status:
    SUCCESS	- Successfull completion
    FAIL	- Unsuccessfull completion

Scope:
    PUBLIC
    PRIVATE to <module_description>

Limitations/Assumptions:

-----------------------------------------------------------------------------*/


#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#if USE_PROTOTYPES
publicdef INT tfg_close (INT *funit)
#else
publicdef INT tfg_close (funit)
INT *funit;
#endif
{
#ifdef vms
  closefil (funit);
#endif

#if UNIX 
  close(*funit);
#endif

#ifdef primos
  fortran closefile ();
  closefil (*funit);
#endif

  return SUCCESS;
}
