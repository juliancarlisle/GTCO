/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_EDIT.H*/
/* *4     9-AUG-1991 17:05:40 KEE "(SPR -1) Fix Compile noise of lg_edit_main.c because of mismatch parameter type"*/
/* *3    17-JUL-1991 16:43:43 JANTINA "(SPR 0) Splice variables added"*/
/* *2    14-AUG-1990 11:48:50 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:02:17 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_EDIT.H*/
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



#ifndef ESI_LG_EDIT_H
#define ESI_LG_EDIT_H 1

/* INCLUDE FILES */

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif


/***************************************************************************/
/*    This is the structure definition for the Log Trace Editor structure  */
/***************************************************************************/

typedef struct  {
      INT  delete_priv;              /* Database access priviledges           */
      INT  update_priv;              /* ( = 1 if allowed else = 0             */
      INT  select_priv;
      INT  insert_priv;

      INT  valid_edit_uwi;           /* = 1 if a there is a valid current UWI */
      INT  valid_ref1_uwi;           /* = 1 if valid donor UWI(s) present     */
      INT  valid_ref2_uwi;

      UWI  edit_uwi;                 /* UWI's for edit and donor wells        */
      UWI  reference1_uwi;
      UWI  reference2_uwi;

      LOG_TRACE_NAME   edit_trace;   /* Current trace                         */
      LOG_TRACE_NAME   rename_trace; /* Temp trace for use by rename routine  */
      LOG_TRACE_STRUCT *ptrace;      /* Scratch log trace struct pointer      */
      LOG_TRACE_STRUCT *ptrace_2;    /* Extra log trace struct pointer        */

      LOG_TRACE_NAME splice_log_1;   /* trace name for first splice log       */
      LOG_TRACE_NAME splice_log_2;   /* trace name for overlay trace          */
      DOUBLE splice_1_top;           /* top of splice log 1                   */
      DOUBLE splice_1_base;          /* base of splice log 1                  */
      DOUBLE splice_2_top;           /* top of splice log 2                   */
      DOUBLE splice_2_base;          /* base of splice log 2                  */

      TCP  uwi_tcp;                  /* Tcp for UWI's retrieved from ORACLE   */
      TCP  trace_tcp;                /* Tcp for traces for UWI                */
      INT  num_uwis;                 /* Number of UWI's in tcp                */
      INT  num_traces;               /* Number of traces in tcp               */
      INT  num_traces_delete;        /* Number of traces to delete            */


      INT  log_edit_menu_id;
      INT  db_menu_id;
      INT  well_menu_id;
      INT  msg_cdlg_id;

      INT  db_info_cdlg_id;
      INT  db_info_hdr_cdlg_id;

      INT  db_rename_cdlg_id;

      INT  db_copy_cdlg_id;

      INT  db_delete_cdlg_id;
      INT  db_delete_conf_cdlg_id;

      INT  edit_ltrans_cdlg_id;

    } LOG_EDIT_STRUCT;


#if USE_PROTOTYPES
extern INT lg_edit_main(BYTE *param);
extern INT lg_ed_db_menu_vis_on_off(LOG_EDIT_STRUCT *plg, INT vis_flag);
extern INT lg_ed_well_menu_vis_on_off(LOG_EDIT_STRUCT *plg, INT vis_flag);
extern INT lg_ed_edit_menu_vis_on_off(LOG_EDIT_STRUCT *plg, INT vis_flag);

/* Well menu function definitions                                    */
extern INT lg_well_get_uwi(LOG_EDIT_STRUCT *plg);
extern INT lg_well_get_uwi_list(LOG_EDIT_STRUCT *plg);

/* Database menu function definitions                                */
extern INT lg_db_info_cdlg_init(LOG_EDIT_STRUCT *plg);
extern INT lg_db_rename_cdlg_init(LOG_EDIT_STRUCT *plg);
extern INT lg_db_copy_cdlg_init(LOG_EDIT_STRUCT *plg);
extern INT lg_db_delete_cdlg_init(LOG_EDIT_STRUCT *plg);

/* Edit menu function definitions                                     */
extern INT lg_edit_ltrans_cdlg_init(LOG_EDIT_STRUCT *plg);

#else

extern INT lg_edit_main();
extern INT lg_ed_db_menu_vis_on_off();
extern INT lg_ed_well_menu_vis_on_off();
extern INT lg_ed_edit_menu_vis_on_off();

extern INT lg_well_get_uwi();
extern INT lg_well_get_uwi_list();
extern INT lg_db_info_cdlg_init();
extern INT lg_db_rename_cdlg_init();
extern INT lg_db_copy_cdlg_init();
extern INT lg_db_delete_cdlg_init();
extern INT lg_edit_ltrans_cdlg_init();

#endif

#endif
                                                                                      
