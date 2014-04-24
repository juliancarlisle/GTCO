/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_INT.H*/
/* *1    30-JUN-1989 14:59:28 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_INT.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_am_int.h,v 1.1 89/05/30 15:33:08 esi Exp $ esi_am_int.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_INT.H*/
/* *16   17-APR-1989 16:00:53 JRB "(SPR 1) change BYTE *	 to VOIDPTR"*/
/* *15   12-APR-1989 17:54:11 JRB "Fix bad character in copyright notice"*/
/* *14    9-APR-1989 00:09:43 GILLESPIE "(SPR 24) Remove some (INT) castings"*/
/* *13    8-APR-1989 00:24:13 GILLESPIE "Add copyright, (INT) castings"*/
/* *12    7-APR-1989 23:41:09 GILLESPIE "Add copyright"*/
/* *11   17-DEC-1988 09:26:00 GILLESPIE "(SPR 4981) Unisource"*/
/* *10   23-SEP-1988 15:44:30 GILLESPIE "(SPR 4848) Change style of referencing APPLICATION_STATIC"*/
/* *9    31-AUG-1988 15:40:40 JAMES "(SPR 4821) Add LENGTH element in the WORKSPACE_LIST."*/
/* *8    15-JUL-1988 16:46:22 GILLESPIE "(SPR 4617) New top-level Finder menu software bus"*/
/* *7    25-MAR-1988 11:06:58 GILLESPIE "(SPR 4363) Add language flag to the resource list structure"*/
/* *6    14-MAR-1988 09:46:23 GILLESPIE "(SPR 4337) Move APPLICATION_STATIC definition to its own include file"*/
/* *5    13-FEB-1988 20:25:08 GILLESPIE "(SPR 4212) Add function prototypes"*/
/* *4    30-NOV-1987 16:04:37 GILLESPIE "(SPR 4042) Move APPLICATION_STATIC here"*/
/* *3    10-NOV-1987 17:10:55 MARKS "(SPR 4011) mod to datalist definition-bt replaced by ht"*/
/* *2    14-JUL-1987 12:26:30 GILLESPIE "removed esi_gl_modid.h"*/
/* *1     7-JUL-1987 10:42:45 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_INT.H*/
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

#ifndef ESI_AM_INT_H
#define ESI_AM_INT_H 1

/*************************************************************************

FILE = ESI_AM_INT.H

*************************************************************************/

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_AM_H
#include "esi_am.h"
#endif

#ifndef ESI_AM_STAT_H
#include "esi_am_stat.h"
#endif

#define AM_WORKSPACE_KEY_SIZE 30
#define AM_RESOURCE_KEY_SIZE 30
#define AM_TAG_SIZE 20

/*************************************************************************

STRUCTURE:    RESOURCE_LIST

KEY:          Menu or custom dialog id, integer

*************************************************************************/

typedef struct {
    CHAR file[AM_RESOURCE_KEY_SIZE+1];
    INT resource_id;
    INT application_id;
    INT type;
    INT (*server)();
    VOIDPTR pointer;
    INT language;	/* 0 = C, 1 = FORTRAN */
    } RESOURCE_LIST;

/*************************************************************************

STRUCTURE:    WORKSPACE_LIST

KEY:          Name, CHAR

*************************************************************************/

typedef struct {
    CHAR name[AM_WORKSPACE_KEY_SIZE+1];
    INT application_id;
    VOIDPTR data;
    INT length;
    } WORKSPACE_LIST;

/*************************************************************************

STRUCTURE:    DATA_LIST

KEY:          Data Pointer, pointer to byte

*************************************************************************/

typedef struct {
    INT application_id;
    INT type;
    } DATA_LIST;

/*************************************************************************

STRUCTURE:    APPLICATION_LIST

KEY:          Application id, integer

*************************************************************************/

typedef struct {
    CHAR tag[AM_TAG_SIZE+1];
    INT parent_id;
    INT (*server)();
    INT (*entry_point)();
    INT type;
    VOIDPTR pointer;
    INT status_dialog_id;
    BOOL accounting;
    DOUBLE start_cpu_time;
    DOUBLE start_io_time;
    DOUBLE cpu_time;
    DOUBLE io_time;
    } APPLICATION_LIST;

#if USE_PROTOTYPES

extern INT am_check_pointer(VOIDPTR pointer, CHAR *access);
extern INT am_start_instance(INT type, INT (*entry_point)(), INT (*return_point)(),
	VOIDPTR pointer);
extern APPLICATION_STATIC *am_static(void);
extern CHAR *am_symbol(INT value);

#else

extern INT am_check_pointer();
extern INT am_start_instance();
extern APPLICATION_STATIC *am_static();
extern CHAR *am_symbol();

#endif
#endif
