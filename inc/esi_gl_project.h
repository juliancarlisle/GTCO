/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_PROJECT.H*/
/* *4     6-JUN-1991 17:12:43 MING "(SPR 0) add default plotter and plot layout"*/
/* *3    14-AUG-1990 11:47:53 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    23-JUL-1990 11:17:38 GILLESPIE "(SPR 1) Add search window"*/
/* *1    30-JUN-1989 15:01:05 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_PROJECT.H*/
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

#ifndef ESI_GL_PROJECT_H
#define ESI_GL_PROJECT (INT)1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

/* This structure contains the default settings for the current project.
   They are obtained from the PROJECT_DEFAULTS table at project initialization.
   The project DBA is responsible for altering this table.  It is the intention
   of ESI that this structure be treated as STATIC, i.e., not changing during
   a run.  */

    typedef struct{
    struct {		    /* unit of measure defaults */
	UOM_NAME horizontal;
	UOM_NAME vertical;
	UOM_NAME log_depth;
	UOM_NAME time;
	} unit;

    struct {		    /* map defaults */
	PROJECTION_ID projection;
	DOUBLE upper_right_x;
	DOUBLE upper_right_y;
	DOUBLE lower_left_x;
	DOUBLE lower_left_y;
	DOUBLE scale;
	DOUBLE search_window;
	UOM_NAME scale_unit;
	PROJECTION_NAME coordinate_system;
	} map;

    DOUBLE log_digitizing_interval;    /* digitizing interval */

    PROJECTION_NAME projection;  /* map projection that the NODES table is stored in */

    CHAR seismic_survey_type[10];      /* 2-D or 3-D */

    CHAR plot_layout[40];        

    CHAR plotter[40];
    } PROJECT_DEFAULT;

#endif
