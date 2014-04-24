/* DEC/CMS REPLACEMENT HISTORY, Element WMG_GPL.C */
/* *4     9-AUG-1990 19:24:24 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:11:58 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    18-DEC-1989 09:38:37 GILLESPIE "(SPR 1) Route GPL through WM_GKS_API" */
/* *1    18-DEC-1989 09:38:00 GILLESPIE "Glue for GPL" */
/* DEC/CMS REPLACEMENT HISTORY, Element WMG_GPL.C */
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1989
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

#ifndef ESI_WM_H
#include "esi_wm.h"
#endif

#ifdef vms
publicdef INT wmg_gpl(npts, px, py)
INT *npts;
FLOAT *px, *py;
    {
    wm_gpl(*npts, px, py);
    }
#endif

#if UNIX
publicdef INT wmg_gpl_(npts, px, py)
INT *npts;
FLOAT *px, *py;
    {
    return wm_gpl(*npts, px, py);
    }
#endif

#ifdef primos
publicdef INT wmg_gpl(npts, px, py)
INT npts;
FLOAT px, py;
    {
    return wm_gpl(npts, px, py);
    }
#endif
