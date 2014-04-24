/* DEC/CMS REPLACEMENT HISTORY, Element OR_REPORTS.H*/
/* *2    14-AUG-1990 11:53:00 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:06:39 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element OR_REPORTS.H*/
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

#ifndef OR_REPORTS_H
#define OR_REPORTS_H 1

/* structure for running the ORACLE report system from Finder */

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_SL_H
#include "esi_sl.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

typedef struct
    {
    BOOL control_list_required;          /* TRUE if a control list is present */
    BOOL run_interactive;		 /* TRUE if interactive, FALSE if batch  */
    BOOL print;				 /* TRUE if report to be printed */
    BOOL save;				 /* TRUE if report to be kept */
    INT parms_id;			 /* ID of parameter selection dialog */
    INT scripts_id;			 /* ID of script selection dialog */
    CHAR data_type[16];	                 /* data type of report */
    CHAR script_type[16];                /* name of program that executes report (SQLPLUS, RPT, ... */
    FILENAME script_name;                /* name of report script file */
    FILENAME report_name;                /* name of output report file */
    SELECT_KEY_STRING select_list_name;  /* name of select list */
    NLIST_HEADER nlist;			 /* list of scripts */
    } REPORT_STRUCT;

#endif
