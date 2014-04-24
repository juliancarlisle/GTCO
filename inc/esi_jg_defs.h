/* DEC/CMS REPLACEMENT HISTORY, Element ESI_JG_DEFS.H*/
/* *1    30-JUN-1989 15:01:51 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_JG_DEFS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_jg_defs.h,v 1.1 89/05/30 15:34:02 esi Exp $ esi_jg_defs.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_JG_DEFS.H*/
/* *6     8-APR-1989 00:31:03 GILLESPIE "Add copyright, (INT) castings"*/
/* *5    17-DEC-1988 09:31:18 GILLESPIE "(SPR 4981) Unisource"*/
/* *4    23-AUG-1988 13:52:15 GILLESPIE "(SPR 4785) Add #ifndefs"*/
/* *3    23-MAR-1988 09:18:25 CONROY "(SPR 4350) Modified for new mapping interface"*/
/* *2    18-DEC-1987 09:25:11 CONROY "(SPR 4115) Initial checkin"*/
/* *1    18-DEC-1987 09:20:46 CONROY "land grid structure declaration"*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_JG_DEFS.H*/
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

#ifndef ESI_JG_DEFS_H
#define ESI_JG_DEFS_H 1

/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: ESI_JG_DEFS.H

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing definitions for 'LAND GRID' overlay
		processing.

   ************************************************************************ */




/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* * STRUCTURES * */
/* -------------- */

typedef struct
	{
	INT township_color;
	FLOAT township_line_thickness;
	DOUBLE township_text_size;
	INT section_color;
	FLOAT section_line_thickness;
	DOUBLE section_text_size;
	BOOL suppress_sections;
	CHAR *name;
	} LAND_GRID;

#endif
