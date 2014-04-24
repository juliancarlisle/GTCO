/* DEC/CMS REPLACEMENT HISTORY, Element ESI_FM.H*/
/* *4    14-AUG-1990 11:47:20 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *3     7-NOV-1989 13:22:07 GILLESPIE "(SPR 30) Rearrange for public,internal include files"*/
/* *2     7-NOV-1989 12:13:28 GILLESPIE "(SPR 30) Add fm_sys_index"*/
/* *1    30-JUN-1989 15:00:30 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_FM.H*/
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND
MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphics Systems, Inc.
			201 Tamal Vista Blvd
			Corte Madera, CA  USA 94925
			(415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: esi_fm.h

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing definitions and declarations for
		FILE MANAGEMENT CODE.

   ************************************************************************ */

#ifndef ESI_FM_H
#define ESI_FM_H 1

/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

/* * DEFINE FILE MANAGEMENT SORTING VARIABLES * */
/* -------------------------------------------- */

typedef INT FM_SORT_ATTRIBUTE;
#define FM_NAME (INT)1
#define FM_CREATION_DATE (INT)2
#define FM_MOD_DATE (INT)3
#define FM_SIZE (INT)4

typedef INT FM_SORT_TYPE;
#define FM_ASC (INT)1
#define FM_DESC (INT)2

/* * DEFINE FILE MANAGEMENT STRUCTURE USED IN HASH TABLE STORAGE * */
/* --------------------------------------------------------------- */

#define FM_KEY_SIZE 192
typedef CHAR FM_TYPE[31];
typedef CHAR FM_FILE[81];
typedef CHAR FM_PATH[81];
typedef CHAR FM_LONG[111];
typedef CHAR FM_DESCRIB[241];

/* * ROUTINE DECLARATIONS * */
/* ------------------------ */

#if USE_PROTOTYPES

extern INT fm_add_history_record(FM_PATH fi_path, FM_LONG fi_name,
				FM_TYPE file_type, FM_PATH from_path,
				FM_LONG from_name, FM_TYPE from_type,
				CHAR *desc);
extern INT fm_check_access(FM_PATH fi_path, FM_LONG fi_name,
				FM_TYPE file_type, CHAR *mode);
extern INT fm_file_list(FM_PATH fi_path, FM_TYPE file_type,
				FM_SORT_ATTRIBUTE attr, FM_SORT_TYPE sort,
				INT flag, TCP *tcp, INT *n_names);
extern INT fm_init_file(FM_PATH fi_path, FM_LONG fi_name, FM_TYPE file_type,
				CHAR *mode, INT perm, FM_DESCRIB desc,
			    INT_FUNCTION_PTR term_func, FILENAME os_name,
                CHAR *creator_app);
extern INT fm_long_name(FM_LONG in_name, FM_LONG out_name);
extern INT fm_parse_long_name(FM_LONG long_name, ANALYST_NAME owner, 
			      FM_FILE fi_filename);
extern INT fm_release_file(FM_PATH fi_path, FM_LONG fi_name, FM_TYPE file_type);
extern INT fm_sys_init(void);
extern INT fm_sys_term(void);
extern INT fm_contour_term_func(INT file_id, FILENAME os_name);
extern INT fm_grid_term_func(INT file_id, FILENAME os_name);
extern INT fm_scatter_term_func(INT file_id, FILENAME os_name);

#else 

extern INT fm_add_history_record();
extern INT fm_check_access();
extern INT fm_file_list();
extern INT fm_init_file();
extern INT fm_long_name();
extern INT fm_parse_long_name();
extern INT fm_release_file();
extern INT fm_sys_init();
extern INT fm_sys_term();
extern INT fm_contour_term_func();
extern INT fm_grid_term_func();
extern INT fm_scatter_term_func();

#endif

#endif
