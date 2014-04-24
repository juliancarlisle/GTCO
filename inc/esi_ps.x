/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PS.X*/
/* *1    30-JUN-1989 15:08:10 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PS.X*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_ps.x,v 1.1 89/05/30 15:49:01 esi Exp $ esi_ps.x 
 */

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

#ifndef ESI_PS_X
#define ESI_PS_X 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_PS_H
#include "esi_ps.h"
#endif

/* Declare global stacks and stack_pointers. */
extern INT ps_long_sp;
extern INT ps_double_sp;
extern INT ps_pointer_sp;
extern LONG ps_long_stack[];
extern DOUBLE ps_double_stack[];
extern BYTE *ps_pointer_stack[];

#endif
                      
