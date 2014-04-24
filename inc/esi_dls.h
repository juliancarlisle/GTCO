/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DLS.H */
/* *2     1-MAY-1991 12:09:14 KEE "(SPR -1) Modified Gulf Canada DLS/NTS for vms and sun version" */
/* *1     1-MAY-1991 12:07:48 KEE "DLS/NTS" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DLS.H */
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
 * Definitions for DLS GRID Overlay of the Map Definitions
 */

#ifndef ESI_DLS_H
#define ESI_DLS_H 1


/*
 * Structure containing information on DLS GRID overlay
 */
typedef struct
    {
    CHAR    *name;
    INT     sec_line_color;
    DOUBLE  sec_line_thickness;
    INT	    sec_line_style;
    DOUBLE  sec_text_size;
    INT     twp_line_color;
    DOUBLE  twp_line_thickness;
    INT	    twp_line_style;
    DOUBLE  twp_text_size;
    INT     text_font;
    INT     text_color;
    } DLSGRID_STRUCT;


#endif
