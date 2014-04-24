/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_LDEFS.H*/
/*  5     4-MAR-1992 11:46:40 JEFF "(SPR 6180) fixed prototype errors"*/
/*  4    27-FEB-1992 13:15:46 JESSIE "(SPR 6180) TVD display"*/
/* *3    14-AUG-1990 11:48:53 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    14-SEP-1989 16:42:10 GORDON "(SPR 100) Gulf/Sun/Unix changes"*/
/* *1    30-JUN-1989 15:02:21 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_LDEFS.H*/
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

/*  FinderLog Log Trace Data Manager (LTDM) definitions.   */

#ifndef ESI_LG_LDEFS_H
#define ESI_LG_LDEFS_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_WE_WELLS_H
#include "esi_we_wells.h"
#endif

/* *************************************************************************** */

#define LG_DEFAULT_SOURCE   "FINDERLOG"
#define LOG_TABLE	    ".WELL_LOG_TRACE_HDR"
#define DEPTH_IN_TIME	    (INT)1
#define DEPTH_IN_DISTANCE   (INT)2


#define LOGNULL		-99999.0

typedef CHAR LOG_DEPTH_OR_TIME[6]; /* Depth or time notation */
typedef CHAR LOG_TRACE_NAME[60];  /* Standard composite trace name    */
typedef CHAR LOG_SOURCE[16];      /* Source of the trace data.        */
typedef CHAR LOG_TRACE[16];       /* Log Trace name                   */
typedef CHAR LOG_SERVICE[16];     /* Logging service name or modifier */
typedef INT  LOG_VERSION;         /* Log Run number or trace version  */
typedef CHAR LOG_COMMENT[244];     /* Operator entered comments        */
typedef CHAR LOG_UOM[21];         /* Log UOM.                         */
typedef INT  LOG_TRACE_ID;        /* The log trace sequence number    */

typedef struct logtrace{
   FLOAT                top;		/* Top of trace data interval	    */
   FLOAT                base;		/* Base of trace data interval	    */
   FLOAT                non_null_top;	/* Top of trace data interval	    */
   FLOAT                non_null_base;	/* Base of trace data interval	    */
   FLOAT                dinc;		/* Digitizing increment		    */
   LOG_TRACE_ID         trace_id;
   UWI                  uwi;
   LOG_TRACE_NAME       trace_name;
   INT multi_strokes;			/* request return multiple strokes*/
   INT non_append_null;			/* no append NULL values in the */
					/* front or end of list.        */
   LOG_SOURCE           source;
   LOG_TRACE            trace;
   LOG_SERVICE          service;
   LOG_VERSION          version;
   LOG_DEPTH_OR_TIME	depth_or_time;
   DATE                 run_date;
   LOG_UOM              depth_uom;	/* Units of depth measurement	    */
   INT                  depth_type;	/* DEPTH_IN_DISTANCE, DEPTH_IN_TIME */
   FLOAT                min;		/* Minimum trace value		    */
   FLOAT                max;		/* Maximum trace value		    */
   LOG_UOM              trace_uom;	/* Units of trace measurement	    */
   LOG_COMMENT          comments;
   NLIST_HEADER         ptrace;
   NLIST_ID             nlist_id;
   FILENAME             filename;
   INT                  shared;		/* shared flag.			    */
   WELL_STRUCT          *pWell;
   } LOG_TRACE_STRUCT;


/*  ****************************** routines in the module ******************** */

#if USE_PROTOTYPES

extern INT lg_draw_log(NLIST_HEADER nlist, DOUBLE from, DOUBLE to, 
		DOUBLE left, DOUBLE right, INT logFlag);
extern INT lg_draw_log_clip(NLIST_HEADER nlist, DOUBLE from, DOUBLE to, 
		DOUBLE left, DOUBLE right, INT logFlag, INT omethod);
extern INT lg_draw_log_skip(NLIST_HEADER nlist, DOUBLE from, DOUBLE to, 
		DOUBLE left, DOUBLE right, INT nskip,  INT logFlag,
		NLIST_HEADER *out_list);
extern INT lg_draw_log_slope(NLIST_HEADER nlist, DOUBLE from, DOUBLE to, 
		DOUBLE left, DOUBLE right, DOUBLE delta,  INT logFlag,
		NLIST_HEADER *out_list);
extern INT lg_ltdm_add_trace(LOG_TRACE_STRUCT *traceStruct);
extern INT lg_ltdm_check_write(UWI inUwi, CHAR *traceCname);
extern INT lg_ltdm_delete_trace(UWI uwi, CHAR *traceCname);
extern INT lg_ltdm_free_trace(LOG_TRACE_STRUCT *traceStruct);
extern INT lg_ltdm_get_trace(LOG_TRACE_STRUCT *trace);
extern INT lg_ltdm_get_trace_resamp(LOG_TRACE_STRUCT *traceStruct);
extern INT lg_ltdm_inq_trace_struct(UWI inputUwi, CHAR *traceName, 
		CHAR *depthType, LOG_TRACE_STRUCT *traceStruct);
extern INT lg_ltdm_inq_well(UWI uwi, CHAR *sqlString, 
		LOG_TRACE_STRUCT ***tablePtr);
extern INT lg_ltdm_inq_well_trace(UWI inputUwi, CHAR *sqlString, 
		TCP *tablePtr, INT *returnedNum);
extern INT lg_ltdm_lock_trace(LOG_TRACE_STRUCT *traceStruct);
extern INT lg_ltdm_parser(LOG_TRACE_STRUCT *logTrace);
extern INT lg_ltdm_purge_trace(UWI traceUwi, LOG_TRACE_NAME traceName);
extern INT lg_ltdm_put_trace(LOG_TRACE_STRUCT *traceStruct);
extern INT lg_ltdm_rename_trace(UWI uwi, CHAR *oldName, CHAR *newName);
extern INT lg_ltdm_unlock_trace(LOG_TRACE_STRUCT *traceStruct);

#else

extern INT lg_draw_log();
extern INT lg_draw_log_clip();
extern INT lg_draw_log_skip();
extern INT lg_draw_log_slope();
extern INT lg_ltdm_add_trace();
extern INT lg_ltdm_check_write();
extern INT lg_ltdm_delete_trace();
extern INT lg_ltdm_free_trace();
extern INT lg_ltdm_get_trace();
extern INT lg_ltdm_get_trace_resamp();
extern INT lg_ltdm_inq_trace_struct();
extern INT lg_ltdm_inq_well();
extern INT lg_ltdm_inq_well_trace();
extern INT lg_ltdm_lock_trace();
extern INT lg_ltdm_parser();
extern INT lg_ltdm_purge_trace();
extern INT lg_ltdm_put_trace();
extern INT lg_ltdm_rename_trace();
extern INT lg_ltdm_unlock_trace();

#endif

#endif
