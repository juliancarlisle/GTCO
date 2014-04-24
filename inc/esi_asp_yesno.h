/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ASP_YESNO.H*/
/* *1    30-JUN-1989 14:59:36 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ASP_YESNO.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_asp_yesno.h,v 1.1 89/05/30 15:33:13 esi Exp $ esi_asp_yesno.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ASP_YESNO.H*/
/* *4     8-APR-1989 00:24:35 GILLESPIE "Add copyright, (INT) castings"*/
/* *3     7-APR-1989 23:41:29 GILLESPIE "Add copyright"*/
/* *2    17-DEC-1988 09:26:15 GILLESPIE "(SPR 4981) Unisource"*/
/* *1     7-JUL-1987 10:42:49 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ASP_YESNO.H*/
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

NAME:    ESI_ASP_YESNO.H

AUTHOR:  W. Jaeck, 23-April-1987

DESCRIPTION:

    ESI_ASP_YESNO.H defines the protocol buffer between an application
    program and the ASP_YESNO application server.

*************************************************************************/

#ifndef ESI_ASP_YESNO_H
#define ESI_ASP_YESNO_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#define ASP_YESNO_WORKSPACE AS_YESNO_WORKSPACE

#ifdef ESI_AS_YESNO_H
#undef ESI_AS_YESNO_H
#endif

#include "esi_as_yesno.h"

#if USE_PROTOTYPES
extern INT asp_yesno(ASP_YESNO_WORKSPACE *);
#else
extern INT asp_yesno();
#endif


#endif
