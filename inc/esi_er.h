/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ER.H*/
/* *1    30-JUN-1989 15:00:15 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ER.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_er.h,v 1.1 89/05/30 15:33:28 esi Exp $ esi_er.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ER.H*/
/* *4     8-APR-1989 00:27:09 GILLESPIE "Add copyright, (INT) castings"*/
/* *3     7-APR-1989 23:44:01 GILLESPIE "Add copyright"*/
/* *2    17-DEC-1988 09:28:14 GILLESPIE "(SPR 4981) Unisource"*/
/* *1     7-JUL-1987 10:44:10 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ER.H*/
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


/* %S Includes for using the error handling routines.
    Author of this file: Phil Burk,    12/9/85
    Author of error handlers: James Chang
*/
/* %Q This is an incomplete list.
    The types of these routines may get changed to VOID.
*/

#ifndef ESI_ER_H
#define ESI_ER_H 1
#define ESI_ER_H_DEFS (INT)1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#if USE_PROTOTYPES
extern VOID er_log(CHAR *string);
#else
extern VOID er_log();
#endif

#define ER_OPEN_RETRYS (INT)5
#define ER_ERROR_LOG_FILENAME "FINDER_ERROR_LOG"

#endif
