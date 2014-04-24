/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XD_DEFS.H*/
/* *1    30-JUN-1989 15:06:07 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XD_DEFS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_xd_defs.h,v 1.1 89/05/30 15:35:32 esi Exp $ esi_xd_defs.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XD_DEFS.H*/
/* *7     8-APR-1989 00:41:47 GILLESPIE "Add copyright, (INT) castings"*/
/* *6    17-DEC-1988 09:39:04 GILLESPIE "(SPR 4981) Unisource"*/
/* *5    14-OCT-1988 15:33:11 CONROY "(SPR 4879) Mods to fix XYZ FILE DISPLAY overlay"*/
/* *4    23-AUG-1988 11:37:53 GILLESPIE "(SPR 4785) Add #ifndef constructs"*/
/* *3    23-MAR-1988 09:21:50 CONROY "(SPR 4350) Modified for new mapping interface"*/
/* *2     8-JAN-1988 13:28:46 CONROY "(SPR 4178) initial checkin"*/
/* *1     8-JAN-1988 13:04:44 CONROY "include file for XYZ FILE DISPLAY overlay structures"*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XD_DEFS.H*/
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

#ifndef ESI_XD_DEFS_H
#define ESI_XD_DEFS_H 1


/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: ESI_XD_DEFS.H

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing definitions for 'XYZ FILE DISPLAY'
		overlay processing.

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
    CHAR *xyz_file;
    INT label_position;
    INT sample_int;
    INT text_color;
    FLOAT text_size;
    CHAR *name;
    BOOL suppress_text;
    BOOL suppress_symbols;
    } XYZ_DISPLAY;


#endif
