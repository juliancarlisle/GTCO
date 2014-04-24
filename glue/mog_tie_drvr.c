/* DEC/CMS REPLACEMENT HISTORY, Element MOG_TIE_DRVR.C*/
/* *3    31-OCT-1990 08:31:12 GILLESPIE "(SPR 1) Moved from src directory"*/
/* *2     9-AUG-1990 19:08:38 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *1    25-JUL-1990 17:58:53 GILLESPIE "Glue for C to fortran calls for seismic modelling plotting"*/
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_TIE_DRVR.C*/
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

#include "esi_glue.h"

/***********************************************************************
*
* GLUE ROUTINE
*
* Allows Cprogs to call the FORTRAN  function MO_TIE_PLOT_DRIVER().
*
***********************************************************************/
#ifdef vms
publicdef INT mog_tie_plt_driver(c_file)
CHAR *c_file;
{
    DSC f_file;

    gf_str_to_desc(c_file, &f_file);

    return mo_tie_plt_driver(&f_file);
}
#endif

#if UNIX
publicdef INT mog_tie_plt_driver(c_file)
CHAR *c_file;
{
    INT len;

    len = strlen(c_file);     /* make a descriptor for the C string */

    return mo_tie_plt_driver_(c_file, len);
}
#endif

#ifdef primos
publicdef INT mog_tie_plt_driver(c_file)
CHAR *c_file;
{
    fortran mo_tie_plt_driver();
    INT len;

    len = strlen(c_file);     /* make a descriptor for the C string */

    return mo_tie_plt_driver(c_file, len);
}
#endif
