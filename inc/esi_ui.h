/* DEC/CMS REPLACEMENT HISTORY, Element ESI_UI.H*/
/* *1    30-JUN-1989 15:05:29 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_UI.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_ui.h,v 1.1 89/05/30 15:35:20 esi Exp $ esi_ui.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_UI.H*/
/* *5     8-APR-1989 00:39:54 GILLESPIE "Add copyright, (INT) castings"*/
/* *4    23-FEB-1989 16:35:53 GILLESPIE "(SPR 1) change publicdef to extern"*/
/* *3    17-DEC-1988 09:37:36 GILLESPIE "(SPR 4981) Unisource"*/
/* *2    16-NOV-1988 10:41:41 GILLESPIE "(SPR 4956) Replacement for old UI system include file, which is being retired"*/
/* *1    16-NOV-1988 10:31:03 GILLESPIE "Definitions for UI routines"*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_UI.H*/
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

#ifndef ESI_UI_H
#define ESI_UI_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* function type definitions */

#if USE_PROTOTYPES

extern BOOL ui_validate_int(INT value,INT minimum,INT maximum,
	CHAR *text,CHAR *help);
extern BOOL ui_validate_float(DOUBLE value,DOUBLE minimum,DOUBLE maximum,
	CHAR *text,CHAR *help);

#else

extern BOOL ui_validate_int();
extern BOOL ui_validate_float();

#endif

#endif
