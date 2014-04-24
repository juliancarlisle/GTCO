/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_TSTWS.H*/
/* *1    30-JUN-1989 14:59:34 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_TSTWS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_am_tstws.h,v 1.1 89/05/30 15:33:10 esi Exp $ esi_am_tstws.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_TSTWS.H*/
/* *4     8-APR-1989 00:24:29 GILLESPIE "Add copyright, (INT) castings"*/
/* *3     7-APR-1989 23:41:23 GILLESPIE "Add copyright"*/
/* *2    17-DEC-1988 09:26:10 GILLESPIE "(SPR 4981) Unisource"*/
/* *1     7-JUL-1987 10:42:47 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_TSTWS.H*/
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

/*************************************************************************

NAME:    ESI_AM_TEST_WORKSPACE.H

AUTHOR:  W. Jaeck, 13-Sep-86

DESCRIPTION:

    ESI_AM_TEST_WORKSPACE is used by the test menu program TEST_AM_DUMP.

*************************************************************************/
#ifndef ESI_AM_TSTWS_H
#define ESI_AM_TSTWS_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

typedef struct {
    INT dump_menu_id;
    INT dialog_id;
    } AM_TEST_WORKSPACE;

#endif
