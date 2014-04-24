/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_STAT.H*/
/* *2    14-AUG-1990 11:46:22 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 14:59:31 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_STAT.H*/
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

#ifndef ESI_AM_STAT_H
#define ESI_AM_STAT_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#ifndef ESI_BT_H
#include "esi_bt.h"
#endif

#ifndef ESI_HT_H
#include "esi_ht.h"
#endif

/*************************************************************************

STRUCTURE:    APPLICATION_STATIC

*************************************************************************/

typedef struct {
    BOOL initialized;
    INT application_id;
    INT next_application_id;
    BOOL accounting;
    TREEHEAD resource_list;
    TREEHEAD application_list;
    HASH_TABLE_P data_list;
    LISTHEAD workspace_list;
    FILE *journal_file;
    } APPLICATION_STATIC;

#if USE_PROTOTYPES
extern APPLICATION_STATIC *am_static(void);
#else
extern APPLICATION_STATIC *am_static();
#endif

#endif
