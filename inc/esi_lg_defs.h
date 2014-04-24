/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_DEFS.H*/
/* *3    14-AUG-1990 11:48:43 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    20-SEP-1989 17:05:47 GILLESPIE "(SPR 100) Fix prototypes for lgz_get_trace_names and lgz_get_trace_all_data"*/
/* *1    30-JUN-1989 15:02:11 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_DEFS.H*/
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

/* INCLUDE FILE for all modules in the FinderLog log analysis system.     */

/* **********************************************************************
                             DEFINITIONS
   ********************************************************************** */

#ifndef ESI_LG_DEFS_H
#define ESI_LG_DEFS_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif

#ifndef ESI_LG_ZDEFS_H
#include "esi_lg_zdefs.h"
#endif

#define ZONE_INTERVAL  (INT)1
#define DEPTH_INTERVAL (INT)2


/* **********************************************************************
                                  DATA
   ********************************************************************** */

typedef struct {

    PROJECT_NAME area_name;

                                  /*  INTERVAL SELECTION DATA  */

    BOOL      application_locked;
    INT       interval_type;
    INT       temp_button;
    CHAR      zone[ZONESIZE];
    CHAR      top_horizon[100];
    CHAR      base_horizon[100];
    DOUBLE    top_offset;
    DOUBLE    base_offset;
    DOUBLE    top_depth;
    DOUBLE    base_depth;

                                  /*   TRACE SEARCH RULES DATA  */

    INT       search_rule_flag;
    INT       search_rule_temp;
    PROJECT_NAME second_area;

                                  /*   DEFAULT SOURCES FIELDS   */

    ANALYST_NAME default_input_source;
    ANALYST_NAME default_output_source;

                                  /*   PROCESSING CUTOFFS  */

    CHAR      cutoff_operator[9][3];
    CHAR      cutoff_operand[18][50];

                                  /*   Menu ids  */
    INT       ap_num;
    INT       file_menu_id;
    INT       file_menu_array[8];
    INT       main_menu_id;
    INT       control_menu_id;
    INT       zdata_menu_id;
    INT       edit_menu_id;
    INT       env_menu_id;
    INT       lith_menu_id;
    INT       phi_menu_id;
    INT       sw_menu_id;
    INT       sxo_menu_id;
    INT       special_menu_id;
    INT       ucalc_menu_id;
    INT       xplt_menu_id;
    INT       scales_menu_id;
    INT       logplt_menu_id;

                        /* Dialog box ids */

    INT       lg_analysis_id;
    INT       cutoffs1_id;
    INT       cutoffs2_id;
    INT       interval_select_methods_id;
    INT       interval_select_depths_id;
    INT       interval_select_zones_id;
    INT       define_zone_id;
    INT       define_zone_source_id;
    INT       zone_sum_id;
    INT       default_source_id;
    INT       search_rules_id;
    INT       existing_variables_id;

    }    LG_SYS_STRUCT;


#if USE_PROTOTYPES

extern INT lgz_check_exist(CHAR *string);
extern INT lgz_delete_db_entry(LOG_TRACE_STRUCT *traceStruct);
extern INT lgz_get_trace_all_data(LOG_TRACE_STRUCT *traceStruct);
extern INT lgz_get_trace_data(LOG_TRACE_STRUCT *traceStruct);
extern INT lgz_get_trace_names(LOG_TRACE_STRUCT *traceStruct);
extern INT lgz_inq_last_version(LOG_TRACE_STRUCT *traceStruct, INT newVersion);
extern INT lgz_rename_db_entry(LOG_TRACE_STRUCT *oldTrace, 
	LOG_TRACE_STRUCT *newTrace);
extern INT lgz_update_db_entry(LOG_TRACE_STRUCT *traceStruct, INT newTrace);
extern INT lgz_update_ranges(LOG_TRACE_STRUCT *traceStruct);
extern INT lgz_update_trace(LOG_TRACE_STRUCT *traceStruct, BOOL newTrace);
extern INT lgz_add_nulls(NLIST_HEADER nlist, INT npoints, INT beforeCp );
extern INT lgz_extract_stroke(NLIST_HEADER nlist, INT stkNum, INT dim, 
	DOUBLE from, DOUBLE to, FLOAT *non_null_top, FLOAT *non_null_base);
extern INT lgz_get_trace(NLIST_HEADER *nlist, FILENAME filename, 
	NLIST_ID nlistName, INT dim, DOUBLE top, DOUBLE base, 
	FLOAT *non_null_top, FLOAT *non_null_base, INT multi_strokes, 
	INT non_append_null);
extern INT lgz_merge_strokes(NLIST_HEADER nlist, INT dim, DOUBLE from, 
	DOUBLE to, NLIST_HEADER *outNlist);
extern INT lgz_put_trace(NLIST_HEADER nlist, FILENAME filename, 
	NLIST_ID nlistName, INT dim, DOUBLE top, DOUBLE base);
extern INT lgz_update_stroke(NLIST_HEADER oldNlist, NLIST_HEADER ewNlist,
	INT dim, DOUBLE from, DOUBLE to);

#else

extern INT lgz_check_exist();
extern INT lgz_delete_db_entry();
extern INT lgz_get_trace_all_data();
extern INT lgz_get_trace_data();
extern INT lgz_get_trace_names();
extern INT lgz_inq_last_version();
extern INT lgz_rename_db_entry();
extern INT lgz_update_db_entry();
extern INT lgz_update_ranges();
extern INT lgz_update_trace();
extern INT lgz_add_nulls();
extern INT lgz_extract_stroke();
extern INT lgz_get_trace();
extern INT lgz_merge_strokes();
extern INT lgz_put_trace();
extern INT lgz_update_stroke();

#endif

#endif
