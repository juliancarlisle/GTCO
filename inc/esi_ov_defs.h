/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OV_DEFS.H*/
/* *1    30-JUN-1989 15:03:39 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OV_DEFS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_ov_defs.h,v 1.1 89/05/30 15:34:40 esi Exp $ esi_ov_defs.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OV_DEFS.H*/
/* *4     8-APR-1989 00:36:00 GILLESPIE "Add copyright, (INT) castings"*/
/* *3    17-DEC-1988 09:34:50 GILLESPIE "(SPR 4981) Unisource"*/
/* *2     9-JUN-1988 08:25:43 GILLESPIE "(SPR 4452) Changes for functional prototypes"*/
/* *1     7-JUL-1987 10:47:08 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OV_DEFS.H*/
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

#ifndef ESI_OV_DEFS_H
#define ESI_OV_DEFS_H 1

/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: ESI_OV_DEFS.H

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing definitions for the processing of
		superclass information in an overlay.

   ************************************************************************ */




/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_MD_DEFS_H
#include "esi_md_defs.h"
#endif

/* * STRUCTURES * */
/* -------------- */

typedef struct
	{
	CHAR *unit_of_measure;
	CHAR *select_list;
	CHAR *select_by_phrase;
	MD_PARM_STRUCT *best_sources;
	CHAR *name;
	BOOL replace;
	BOOL delete;
	BOOL dim;
	} OV_GENERIC;

#endif
