/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AS_GETP.H*/
/* *1    30-JUN-1989 14:59:38 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AS_GETP.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_as_getp.h,v 1.1 89/05/30 15:33:11 esi Exp $ esi_as_getp.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AS_GETP.H*/
/* *4     8-APR-1989 00:24:42 GILLESPIE "Add copyright, (INT) castings"*/
/* *3     7-APR-1989 23:41:35 GILLESPIE "Add copyright"*/
/* *2    17-DEC-1988 09:26:20 GILLESPIE "(SPR 4981) Unisource"*/
/* *1     7-JUL-1987 10:42:51 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AS_GETP.H*/
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

NAME:    ESI_AS_GETP.H

AUTHOR:  W. Jaeck, 14-Aug-86

DESCRIPTION:

    ESI_AS_GETP.H is the definition of the protocol between an
    application and the as_get_project application server.

*************************************************************************/

#ifndef ESI_AS_GETP_H
#define ESI_AS_GETP_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_AS_ERR_H
#include "esi_as_err.h"
#endif

typedef struct {
    INT status;                   /* Completion status */
    BOOL cancel;                  /* Allow user to CANCEL */
    BOOL quit;                    /* Allow user to QUIT */
    BOOL no_selection;            /* Allow user to select nothing */
    CHAR project[31];             /* Project selected by user */
    } AS_GET_PROJECT_WORKSPACE;

#if USE_PROTOTYPES
extern INT as_get_project(AS_GET_PROJECT_WORKSPACE *);
#else
extern INT as_get_project();
#endif

#endif
