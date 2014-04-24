/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SE_INT.H*/
/* *7    13-OCT-1990 00:28:37 GILLESPIE "(SPR 100) Updates from Ernie"*/
/*  5B1  13-OCT-1990 00:28:13 GILLESPIE "Updates from Ernie"*/
/* *6    31-AUG-1990 10:25:47 PURNA "(SPR 0) add return version number if version=0"*/
/* *5    25-OCT-1989 11:19:35 GILLESPIE "(SPR 1) Make se_retrieve_header an external function"*/
/* *4    19-SEP-1989 11:13:47 GILLESPIE "(SPR 102) Fix a bad prototype"*/
/* *3     5-SEP-1989 14:04:58 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *2    25-JUL-1989 19:28:06 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    30-JUN-1989 15:04:13 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SE_INT.H*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SE_INT.H*/
/* *5    25-OCT-1989 11:19:35 GILLESPIE "(SPR 1) Make se_retrieve_header an external function"*/
/* *4    19-SEP-1989 11:13:47 GILLESPIE "(SPR 102) Fix a bad prototype"*/
/* *3     5-SEP-1989 14:04:58 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *2    25-JUL-1989 19:28:06 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    30-JUN-1989 15:04:13 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SE_INT.H*/
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

#ifndef ESI_SE_INT_H
#define ESI_SE_INT_H  1

#ifndef  ESI_SE_H
#include "esi_se.h"
#endif

/*   SE_NOPIC  flag used by interpret to say that a either normal pick
               or normal pick are not present in the DB for a given
               horizon ( first_cdp,last_cdp,first_cdp_spe,last_cdp_spe) can
               be set to this value 
   SE_NOTIME  flag used by interpret to say that a either normal pick
               or normal pick are not present in the DB for a given
               horizon ( upper_time , lower_time,upper_time_spe,
              lower_time_spe can be set to this value 
*/ 

#define SE_NOPIC	(INT)-9999
#define SE_NOTIME	(INT)-100000

/*    define string values used to name the stroke inside the 
      nlist containing the values of picks  */

#define DATA_S		"DATA"
#define NODATA_S	"NODATA"
#define FAULT_S		"FAULT"
#define PINCH_S		"PINCH"
#define OTHERS_S	"OTHERS"

/*   definitions  used for picks  describing the different flags
     stored in the horizon picks 
*/

/*  DECLARATION OF FUNCTION USED IN  THE SEIS_SURFACE TOOL BOX */

#if USE_PROTOTYPES

extern INT sez_bld_interp_nl (BOOL upd, BOOL ispec, INT *icntr, INT *iopt,
			      INT *ivect, FLOAT *upper_tim, FLOAT *lower_tim,
			      CDP_FLOAT *first_cd, CDP_FLOAT *last_cd,
			      FILENAME nl_file, NLIST_ID nl_name,
		              NLIST_HEADER *nl_interp) ;
extern INT sez_del (CHAR *surf_code, SEIS_SURFACE_DATA_CLASS surf_type,
		    SEIS_SURFACE_DATA_TYPE data_type, 
		    FULL_LINE_NAME *line, CHAR *source,
		    SEIS_ATTRIBUTE_DATA_TYPE attribute,
		    SEIS_SURFACE_NLIST_TYPE format,
		    INT version) ;
extern INT sez_fillsource (CHAR * source_hor, CHAR *source_hori) ;
extern INT sez_get ( CHAR *surf_code, SEIS_SURFACE_DATA_CLASS surf_type,
		     SEIS_SURFACE_DATA_TYPE data_type,
		     FULL_LINE_NAME *line, CHAR *source,
		     SEIS_ATTRIBUTE_DATA_TYPE attribute,
		     SEIS_SURFACE_NLIST_TYPE format,
		     INT *version,
		     FLOAT *upper_time, FLOAT *lower_time, CDP_FLOAT *first_cdp,
		     CDP_FLOAT *last_cdp, FLOAT *upper_time_spe,
		     FLOAT *lower_time_spe, CDP_FLOAT *first_cdp_spe,
		     CDP_FLOAT *last_cdp_spe, NLIST_ID nlist_id,
		     FILENAME nlist_file);
extern INT sez_get_formats (CHAR *surf_code,
		    SEIS_SURFACE_DATA_CLASS surf_type,
		    SEIS_SURFACE_DATA_TYPE data_type,
		    FULL_LINE_NAME *line, CHAR *source,
		    SEIS_ATTRIBUTE_DATA_TYPE attribute,
		    INT version,
		    SEIS_SURFACE_NLIST_TYPE *format_arr,
		    INT *nb_format, INT max_format);
extern INT sez_put ( NLIST_HEADER surface_nlist , CHAR *surf_code ,
		     SEIS_SURFACE_DATA_CLASS surf_type,
		     SEIS_SURFACE_DATA_TYPE data_type,
                     FULL_LINE_NAME *line, CHAR *source,
		     SEIS_ATTRIBUTE_DATA_TYPE attribute,
		     SEIS_SURFACE_NLIST_TYPE format,
		     INT version,DOUBLE upper_time,
		     DOUBLE lower_time,CDP_FLOAT first_cdp,CDP_FLOAT last_cdp,
		     DOUBLE upper_time_spe, DOUBLE lower_time_spe,
                     CDP_FLOAT first_cdp_spe, CDP_FLOAT last_cdp_spe);
extern INT sez_read_interp_nl (FULL_LINE_NAME *line, SEIS_SURFACE_HDR *psurf,
		    BOOL ispec, INT *icntr, INT *iopt, SHORT *ivect, INT *info,
		    FILENAME nl_file, NLIST_ID nl_name) ;
extern INT sez_cv_interp_find (NLIST_HEADER interp_nl,NLIST_HEADER *finder_nl);
extern INT sez_upd_cores_cdp_sp (FULL_LINE_NAME *line_name, SEIS_SP_ORDER regul,
                                 INT honor, CDP last_cdp, SP sp, CDP *cdp);

#else

extern INT sez_bld_interp_nl () ;
extern INT sez_cv_interp_find () ;
extern INT sez_del () ;
extern INT sez_fillsource () ;
extern INT sez_get () ;
extern INT sez_put () ;
extern INT sez_read_interp_nl () ;
extern INT sez_upd () ;

#endif

/*       end include  file                                 */

#endif
