/* DEC/CMS REPLACEMENT HISTORY, Element MOG_RESETTXT.C */
/* *6     9-AUG-1990 19:08:26 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *5     7-FEB-1990 07:01:02 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *4     7-DEC-1989 11:44:05 GORDON "(SPR 0) Undo last fix & add some flipping comments" */
/* *3     7-DEC-1989 11:03:16 GORDON "(SPR 0) fix SUN line (bad underscore)" */
/* *2     6-NOV-1989 16:34:36 GILLESPIE "(SPR 1) Change model_teset_text to mo_reset_text" */
/* *1     6-NOV-1989 08:55:21 PURNA "move main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_RESETTXT.C */
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
#include "esi_gl_defs.h"
#include "esi_mo.h"

/* This is a glue routine to enable C modules to call the Fortran
   routine MO_RESET_TEXT. */

#ifdef vms

publicdef INT mog_reset_text()
{
    mo_reset_text();
    return SUCCESS;
}

#endif         /* End of Vax code */

#if UNIX
publicdef INT mog_reset_text()
{
    mo_reset_text_();
    return SUCCESS;
}

#endif         /* End of UNIX code */

#ifdef primos

publicdef INT mog_reset_text()
{
    mo_reset_text();
    return SUCCESS;
}
#endif 
