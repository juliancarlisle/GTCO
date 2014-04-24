/* DEC/CMS REPLACEMENT HISTORY, Element ESI_FM_INT.H */
/* *4     6-JUN-1991 17:11:17 MING "(SPR 0) add expiration date" */
/* *3    18-JAN-1990 15:49:44 ADEY "(SPR -1) change BOOL to INT type for perm" */
/* *2     7-NOV-1989 13:22:10 GILLESPIE "(SPR 30) Rearrange for public,internal include files" */
/* *1     7-NOV-1989 12:30:38 GILLESPIE "Internal fm include file" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_FM_INT.H */
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

#ifndef ESI_FM_INT_H

#ifndef ESI_FM_H
#include "esi_fm.h"
#endif

#ifndef ESI_HT_H
#include "esi_ht.h"
#endif

typedef struct fm_struct
    {
    FM_PATH fi_path;
    FM_FILE fi_name;
    FM_TYPE file_type;
    INT  file_id;
    ANALYST_NAME creator;
    ORACLE_NAME creator_app;
    FM_DESCRIB desc;
    CHAR mode[10];
    BOOL in_use;
    BOOL in_data_base;
    INT perm;
    DATE_TIME expiration_date;
    INT (*term_func)();
    } FM_STRUCT;

#if USE_PROTOTYPES

extern INT fm_create_file_id(INT *file_id);
extern INT fm_create_full_path(INT file_id, FM_PATH fi_path, FILENAME os_path);
extern INT fm_create_os_filename(INT file_id, FILENAME os_name);
extern HASH_TABLE_P fm_sys_index();

#else

extern INT fm_create_file_id();
extern INT fm_create_full_path();
extern INT fm_create_os_filename();
extern HASH_TABLE_P fm_sys_index();

#endif

#endif
