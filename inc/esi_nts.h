/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NTS.H */
/* *2     1-MAY-1991 12:09:24 KEE "(SPR -1) Modified Gulf Canada DLS/NTS for vms and sun version" */
/* *1     1-MAY-1991 12:08:04 KEE "DLS/NTS" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NTS.H */
/*
COPIED FROM ESI_GR.H FOR QUICK DEVELOPEMENT OF NTS GRID OVERLAY */
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

/*
 * Definitions for NTS GRID Overlay of the Map Definitions
 */

#ifndef ESI_NTS_H
#define ESI_NTS_H 1


/*
 * Structure containing information on NTS GRID overlay
 */
typedef struct
    {
    CHAR    *name;
    INT     unit_line_color;
    DOUBLE  unit_line_thickness;
    INT	    unit_line_style;
    INT     grid_line_color;
    DOUBLE  grid_line_thickness;
    INT	    grid_line_style;
    DOUBLE  map_sheet_text_size;
    INT     text_font;
    INT     text_color;
    BOOL    clip;
    } NTSGRID_STRUCT;


#endif
