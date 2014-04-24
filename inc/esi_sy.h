/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SY.H*/
/* *3    14-AUG-1990 11:51:10 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2     6-FEB-1990 13:18:12 MING "(SPR 0) change date/time declaration to new data type DATE_TIME"*/
/* *1    30-JUN-1989 15:04:44 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SY.H*/
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


/****************************************************************************

    ESI_SY.H 
    include file for synthetics application

    author : PIERO


****************************************************************************/


#ifndef ESI_SY_H

#define ESI_SY_H 1

/* esi general include file */

#ifndef  ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef  ESI_GL_PROJECT_H
#include "esi_gl_project.h"
#endif

/* nlist include file */

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

/* wells include file */

#ifndef ESI_WE_WELLS_H
#include "esi_we_wells.h"
#endif

/* application manager include file */

#ifndef ESI_AM_H
#include "esi_am.h"
#endif

/* log include file	    */

#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif

/* b tree include file */

#ifndef ESI_BT_H
#include "esi_bt.h"
#endif

#define IS ==
#define IS_NOT !=

#define SY_AUTOMATIC	(INT)0
#define SY_MANUAL	(INT)1

#define SY_TIME_UOM "SECONDS"
#define SY_DEF_TIME_SAMPLING 0.002
#define SY_MIN_TIME_SAMPLING 0.000125
#define SY_MAX_TIME_SAMPLING 0.008

#define SY_MIN_VELOCITY 1001.	    /*	METERS/SECOND	*/
	/*  minimum velocity used for sampling optimization	*/

#define SY_FAUST_DEFAULT    1958.
#define SY_FAUST_MIN	    30.
#define SY_FAUST_MAX	    20000.

#define SY_CONV (INT)0
#define SY_CORR (INT)1

#define SY_DEFAULT_NULL -9999.28

#define SY_NO_CHECKSHOTS	(INT)0
#define SY_USE_CHECKSHOTS	(INT)1
#define SY_NOT_USE_CHECKSHOTS	(INT)2

#define SY_NORMAL	(INT)0
#define SY_TO_BE_SAVED	(INT)1
#define SY_SAVED_OK	(INT)2
#define SY_NOT_SAVED	(INT)3

typedef struct {
    INT pipo;
}   SYNTHE_DISPLAY;

typedef struct {
    DATE_TIME date_tag;
}   SY_USER_STRUCT;

typedef struct {
    CHAR name;
    INT flag;
    FLOAT start;
    FLOAT end;
    FLOAT inc;
    FLOAT shift;
    CHAR comments[256];
    FLOAT *values;
}   SYNTHE_TRACE;

typedef struct {
    INT flag;
    LOG_TRACE_STRUCT *log_hdr;
    FLOAT *values;
} SYNTHE_LOG;

#define SY_TRACE_NPTS(trace) ((trace->end - trace->start)/trace->inc +1.0001)
#define SY_LOG_NPTS(log) ((log->base - log->top)/log->dinc +1.0001)

typedef struct {
    INT flag;
    INT n_checkshots;
    FLOAT *depth;
    FLOAT *time;
} SYNTHE_CHECKSHOT;
    
    
typedef struct {
/*  general informations	*/

    PROJECT_DEFAULT *proj_def;
    WELL_STRUCT   *pWell;
/*				*/
/*	depth	domain		*/
/*				*/
    FLOAT depth_inc;
    UOM_NAME depth_uom;

/*  database log data			*/
    SYNTHE_LOG **logs;
    INT n_logs;
    INT n_sonics;
    INT n_density;
    INT n_resistivity;
    INT n_reflexions;

/*  computed if needed			*/
    SYNTHE_LOG *sonic;		    /*	the sonic used			*/
    SYNTHE_LOG *density;	    /*	the eventual density used	*/
    SYNTHE_LOG *impedance;	    /*	the impedance used		*/
    SYNTHE_LOG *time_curve;	    /*	time versus depth		*/

/*  tops				*/
    TOP_STRUCT	**tops;		    /*	available for current well	*/
    TOP_STRUCT	**disp_tops;	    /*	to be displayed			*/

/*	checkshots		*/
    INT use_checkshots;
    SYNTHE_CHECKSHOT *checkshots;

/*				*/
/*	time domain		*/
/*				*/

    FLOAT time_inc;
    UOM_NAME time_uom;
    FLOAT shift;
    FLOAT surface_velocity;

    SYNTHE_TRACE *impulse;	    /*	impulse trace		*/
    SYNTHE_TRACE *depth_curve;	    /*  depth versus time	*/
    SYNTHE_TRACE *multiple;	    /*  impulse with multiples	*/

    SYNTHE_TRACE **traces ;	    /*  convolved traces	*/
    INT n_traces ;		    /*  nb of traces		*/
    SYNTHE_TRACE **time_logs;	    /*  time transformed logs	*/

/*  display parameters		*/
    SYNTHE_DISPLAY *display;

/*  menus IDs			*/
    INT main_menu_id;
    INT display_menu_id;

}   SYNTHE_STRUCT;


#if USE_PROTOTYPES

extern INT sy_get_log_hdr(SYNTHE_STRUCT *p_synthe);
extern INT sy_get_reflexions(SYNTHE_STRUCT *p_synthe);
extern INT sy_use_reflexion(SYNTHE_STRUCT *p_synthe);
extern INT sy_compute_reflexion(SYNTHE_STRUCT *p_synthe);

#else

extern INT sy_get_log_hdr();
extern INT sy_get_reflexions();
extern INT sy_use_reflexion();
extern INT sy_compute_reflexion();

#endif


#endif
