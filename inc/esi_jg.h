/* DEC/CMS REPLACEMENT HISTORY, Element ESI_JG.H*/
/* *2    14-AUG-1990 11:48:26 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:01:48 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_JG.H*/
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

#ifndef ESI_JG_H
#define ESI_JG_H 1

/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: ESI_JG.H

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing function definitions for 'Land Grid'
		overlay.

   ************************************************************************ */




/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* * FUNCTIONS * */
/* ------------- */

#if USE_PROTOTYPES

extern INT jg_overlay (INT display_line);
extern INT jg_clip_line (DOUBLE *x1, DOUBLE *y1, DOUBLE *x2, DOUBLE *y2, 
		DOUBLE minx, DOUBLE miny, DOUBLE maxx, DOUBLE maxy,
		BOOL *visible, BOOL *modified);

#else

extern INT  jg_overlay();
extern INT  jg_clip_line();

#endif

#endif
