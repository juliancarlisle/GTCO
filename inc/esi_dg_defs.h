/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DG_DEFS.H*/
/* *4    14-AUG-1990 11:46:56 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *3    15-FEB-1990 10:42:00 WALTERS "(SPR 0) Change user structures for map setup dialog alterations"*/
/* *2    10-AUG-1989 16:14:29 GORDON "(SPR 0) pad out structs for Sun port"*/
/* *1    30-JUN-1989 15:00:07 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DG_DEFS.H*/
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

/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: esi_dg_defs.h

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing definitions and declarations for
		ESI created routines for the dg library.

   ************************************************************************ */

#ifndef ESI_DG_DEFS_H
#define ESI_DG_DEFS_H 1


/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

/* * DECLARE STRUCTURES * */
/* ---------------------- */

typedef struct
	{
    CHAR projection[20];
    CHAR coord_system[16];
	INT bold_line_interval;
	INT label_interval;
	COLOR_INDEX line_color;
	COLOR_INDEX bold_line_color;
	COLOR_INDEX fine_line_color;
	FLOAT contour_interval;
	CHAR base_surface[24];
	CHAR top_surface[24];
	CHAR fault[44];
	BOOL uniform;
	} CONTOUR_NLIST_USER_STRUCT;


typedef struct
    {
    CHAR projection[20];
    CHAR coord_system[16];
	FLOAT xmin;
	FLOAT xmax;
	FLOAT ymin;
	FLOAT ymax;
	CHAR base_surface[24];
	CHAR top_surface[24];
	CHAR fault[44];
	BOOL uniform;
    } GRID_NLIST_USER_STRUCT;

typedef struct
	{
	INT level;
	FLOAT value;
	} DG_LINE_STROKE_USER_STRUCT;


typedef struct
	{
	INT start_ptr;
	INT end_ptr;
	FLOAT xend;
	FLOAT yend;
	} DG_LABEL_STROKE_USER_STRUCT;

typedef struct
    {
	FILENAME rootname;
	DOUBLE scale_factor;
	FLOAT xmin;
	FLOAT ymin;
	} DG_WORKSPACE_STRUCT;


#endif
