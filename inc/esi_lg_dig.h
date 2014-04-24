/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_DIG.H*/
/* *2    14-AUG-1990 11:48:47 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:02:14 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_DIG.H*/
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


/* esi_lg_dig.h                                                              */
/*    Log Digitizer standard include file                                    */

#ifndef ESI_LG_DIG_H
#define ESI_LG_DIG_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif

#ifndef ESI_LE_NLED_H
#include "esi_le_nled.h"
#endif

typedef struct
{
    FLOAT top_y,bottom_y;          /*  Top/bottom log value (grid limits)*/
    FLOAT min_y,max_y;             /*  Min and max values of log scale   */
    FLOAT trace_offset;            /*  Trace offset value                */
    FLOAT trace_flip_value;        /*  Value used to flip trace          */
    CHAR log_scale_type[7];        /*  Log scale type - "LINEAR" or "LOG"*/
    CHAR log_units_system[8];      /*  Log units "ENGLISH" or "METRIC"   */
    INT num_offscales_up;          /*  Number of offscale excursions up  */
    INT num_offscales_down;        /*  Number of offscale excursions down*/
    INT current_offscale_position; /*  Where we are at so user doesn't go*/
				   /*  too far                           */
    BOOL log_exists;               /*  TRUE is trace already exists      */
    BOOL edit_flag;                /*  TRUE is edit existing trace       */
    BOOL flipped;                  /*  TRUE if log scale is decreasing up*/
    INT segment_number;            /*  Current trace segment             */
    COLOR_INDEX draw_color;        /*  Color to draw trace               */
    COLOR_INDEX hilight_color;     /*  Color to hilight trace            */
    COLOR_INDEX erase_color;       /*  Color to erase trace              */
    COLOR_INDEX background_color;  /*  Color for screen background       */
    COLOR_INDEX grid_color;        /*  Color for grid                    */
    COLOR_INDEX text_color;        /*  Color for text                    */
    LOG_TRACE_STRUCT trace_struct; /*  LTDM trace structure              */
} DIG_LOG_STRUCT ;


/* Define Entry Points  */

#if USE_PROTOTYPES

extern INT lg_get_area_defaults(DIG_LOG_STRUCT *log_header);

#else

extern INT lg_get_area_defaults();

#endif

#endif
                                                                                                                            
