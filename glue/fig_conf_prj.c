/* DEC/CMS REPLACEMENT HISTORY, Element FIG_CONF_PRJ.C */
/* *3     9-AUG-1990 19:06:39 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 06:59:13 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1    21-JUL-1989 10:53:30 GILLESPIE "Fortran binding for finder_config_project" */
/* DEC/CMS REPLACEMENT HISTORY, Element FIG_CONF_PRJ.C */

/******************************************************************************

                Copyright Exploration Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Exploration Systems, Inc.
			579 Market Street
			San Francisco, CA  USA 94105
			(415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

/********************************************************************
*      Copyright 1988, Exploration Systems Inc. San Francisco
*
* FUNCTION:  fig_configure_project
*
* SYNOPSIS:  INT fig_configure_project()
*
*********************************************************************/
#include "esi_gl_defs.h"

#ifdef vms
publicdef INT fig_config_project()
{
    return finder_config_project();
}
#endif
#ifdef primos
publicdef INT fig_config_project()
{
    return finder_config_project();
}
#endif
#if UNIX
publicdef INT fig_config_project_()
{
    return finder_config_project();
}
#endif
