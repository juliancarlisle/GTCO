/* DEC/CMS REPLACEMENT HISTORY, Element HOG_GFNT.C*/
/* *3     9-AUG-1990 19:07:08 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:43 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:46:03 GILLESPIE "Fortran bing for host-dependent code"*/
/* DEC/CMS REPLACEMENT HISTORY, Element HOG_GFNT.C*/

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
#include "esi_glue.h"

#if UNIX

publicdef INT hog_gfnt( unit )
INT *unit;
{
    hogfnt_( unit );
    return SUCCESS;
}

#else 

publicdef INT hog_gfnt( unit )
INT *unit;
{
    hogfnt( unit );
    return SUCCESS;
}

#endif
