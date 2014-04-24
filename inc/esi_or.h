/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OR.H*/
/*  7    19-NOV-1991 16:15:37 LOEBL "(SPR 0) Convert to sqlforms30"*/
/*  6    19-NOV-1991 15:49:51 LOEBL "(SPR 0) Convert to sqlforms30"*/
/* *5     4-MAY-1991 16:10:38 KEE "(SPR -1) Add Structure for or_process_sql"*/
/* *4    31-JUL-1990 09:49:26 PURNA "(SPR 0) add lynx and lease select list"*/
/* *3    12-JUL-1990 15:03:06 GILLESPIE "(SPR 3) Change publicdef to extern"*/
/* *2    18-JUL-1989 09:15:14 GORDON "(SPR 100) Add mods from Sun port"*/
/* *1    30-JUN-1989 15:03:29 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OR.H*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OR.H                                    */
/* *2    18-JUL-1989 09:15:14 GORDON "(SPR 100) Add mods from Sun port"             */
/* *1    30-JUN-1989 15:03:29 GILLESPIE ""                                          */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OR.H                                    */

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

#ifndef ESI_OR_H

#define ESI_OR_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_DB_H
#include "esi_db.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef OR_REPORTS_H
#include "or_reports.h"
#endif


typedef struct or_proc_struct
{
  TCP tcp; /* tcp of out items */
  INT nitems_prow; /* number of out items per row */
  INT nitems; /* number of out items */
  INT nrows; /* number of rows affected */
} OR_PROC_STRUCT;


#if USE_PROTOTYPES

extern INT or_check_privileges(CHAR *table, BOOL *select, BOOL *insert,
                               BOOL *update, BOOL *delete);
extern INT or_copy_forms(DB_ACCOUNT_STRUCT *db_account);
extern INT or_drop_oracle_form(CHAR *formname);
extern INT or_select_form_app(void *ptr);
extern INT or_load_seismic(CHAR *unique_name, NLIST_HEADER nlist);
extern INT or_load_wells(CHAR *unique_name, NLIST_HEADER nlist);
extern INT or_load_lynx(CHAR *unique_name, NLIST_HEADER nlist);
extern INT or_load_lease(CHAR *unique_name, NLIST_HEADER nlist);
extern INT or_login(INT argc, CHAR **argv);
extern INT or_load_script_cdlg(REPORT_STRUCT *pScript);
extern INT or_sql_processor(CHAR *not_used);
extern INT or_run_oracle_form(FILENAME formname);
extern INT or_run_oracle_report(REPORT_STRUCT *pScript);
extern INT or_select_report_app(CHAR *not_used);
extern INT or_process_sql (CHAR *statement, OR_PROC_STRUCT *or_proc);

#else

extern INT or_check_privileges();
extern INT or_copy_forms();
extern INT or_drop_oracle_form();
extern INT or_select_form_app();
extern INT or_load_seismic();
extern INT or_load_wells();
extern INT or_load_lynx();
extern INT or_load_lease();
extern INT or_login();
extern INT or_load_script_cdlg();
extern INT or_sql_processor();
extern INT or_run_oracle_form();
extern INT or_run_oracle_report();
extern INT or_select_report_app();
extern INT or_process_sql ();

#endif
#endif
