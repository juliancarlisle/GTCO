/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GD_DEFS.H*/
/* *2    14-AUG-1990 11:47:33 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:00:38 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GD_DEFS.H*/
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

#ifndef ESI_GD_DEFS_H
#define ESI_GD_DEFS_H 1


/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: ESI_GD_DEFS.H

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing definitions for 'GRID DISPLAY' overlay
		processing.

   ************************************************************************ */




/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

/* * STRUCTURES * */
/* -------------- */

typedef struct
    {
    INT label_position;
    INT row_int;
    INT col_int;
    COLOR_INDEX text_color;
    GKS_REAL text_size;
    CHAR *name;
    BOOL suppress_text;
    BOOL suppress_symbols;
    } GRID_DISPLAY;


#endif
