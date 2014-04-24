/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM.H*/
/* *3    14-AUG-1990 11:46:18 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    18-NOV-1989 09:41:55 GILLESPIE "(SPR 5075) Global overhaul"*/
/* *1    30-JUN-1989 14:59:24 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM.H*/
/*******************************************************************************

                    Copyright Exploration Systems, Inc. 1989
                       Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc. AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE 
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND MAY NOT BE 
MODIFIED, DUPLICATED, OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

                         Exploration Systems, Inc.
                         579 Market Street
                         San Francisco, CA  USA 94105
                         (415) 974-1600

(The above notice does not constitute an admission of publication or 
unrestricted dissemination of the work.) 

*******************************************************************************/

#ifndef ESI_AM_H
#define ESI_AM_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_AM_DEFS_H
#include "esi_am_defs.h"
#endif

#if USE_PROTOTYPES

extern INT am_abort(void);
extern VOIDPTR am_allocate(INT type, size_t length);
extern INT am_declare(CHAR *tag);
extern INT am_define_resource(INT type, FILENAME file, INT resource_id,
		INT_FUNCTION_PTR server, INT *id, VOIDPTR pointer);
extern INT am_define_text_resource(TCP tcp, INT tcp_len, INT *id);
extern INT am_define_workspace(CHAR *name, INT type, size_t length, VOIDPTR *pointer);
extern INT am_dispatcher(INT event_type, INT id, INT item);
extern INT am_free (VOIDPTR pointer);
extern INT am_initialize(void);
extern INT am_message(INT level, CHAR *text);
extern INT am_open_workspace(CHAR *name, INT type, VOIDPTR *pointer);
extern INT am_quit(void);
extern INT am_quit_current(INT current_app_id, BOOL call_completion_routine);
extern VOIDPTR am_reallocate (VOIDPTR pointer, size_t size);
extern INT am_release_resource(INT id);
extern INT am_release_text_resource(INT id);
extern INT am_release_workspace(CHAR *name, INT type);
extern INT am_rename_workspace(CHAR *old_name, CHAR *new_name, INT type);
extern INT am_set_resource_server(INT id, INT_FUNCTION_PTR server);
extern INT am_start_application(INT_FUNCTION_PTR entry_point, VOID *pointer);
extern INT am_start_server(INT_FUNCTION_PTR entry_point,INT_FUNCTION_PTR return_point, VOIDPTR pointer);
extern INT am_terminate(void);

#else

extern INT am_abort();
extern VOIDPTR am_allocate();
extern INT am_declare();
extern INT am_define_resource();
extern INT am_define_text_resource();
extern INT am_define_workspace();
extern INT am_dispatcher();
extern INT am_free();
extern INT am_initialize();
extern INT am_message();
extern INT am_open_workspace();
extern INT am_quit();
extern INT am_quit_current();
extern VOIDPTR am_reallocate();
extern INT am_release_resource();
extern INT am_release_workspace();
extern INT am_release_text_resource();
extern INT am_rename_workspace();
extern INT am_set_resource_server();
extern INT am_start_application();
extern INT am_start_server();
extern INT am_terminate();

#endif

#ifdef primos
#define MAX_ALLOC_SPACE       0x1fff4	/* segment size less 12 bytes for memory police */
#else
#define MAX_ALLOC_SPACE       0x400000   /* 4 mb for now -- could be more if needed */
#endif

#endif
