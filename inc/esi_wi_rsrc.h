/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WI_RSRC.H*/
/* *1    30-JUN-1989 15:05:51 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WI_RSRC.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_wi_rsrc.h,v 1.1 89/05/30 15:35:27 esi Exp $ esi_wi_rsrc.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WI_RSRC.H*/
/* *4     8-APR-1989 00:41:02 GILLESPIE "Add copyright, (INT) castings"*/
/* *3    17-DEC-1988 09:38:21 GILLESPIE "(SPR 4981) Unisource"*/
/* *2    13-FEB-1988 20:26:21 GILLESPIE "(SPR 4212) Add function prototypes"*/
/* *1     7-JUL-1987 10:48:49 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WI_RSRC.H*/
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

/*%F Workstation Interface External Resource Include file.
     Copyright Exploration Systems, Inc. */

#ifndef ESI_WI_RSRC_H
#define ESI_WI_RSRC_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_WI_H
#include "esi_wi.h"
#endif

#define TYPE_MENU           (INT)0
#define TYPE_DIALOG      (INT)1000

typedef struct wi_rsrc_info
    {
    INT  numitems;          /* number of items in the resource */
    INT  type;              /* TYPE_DIALOG or TYPE_MENU */
    CHAR helpkey[STMAX];
    CHAR title[STMAX];
    } WI_RSRC_INFO;


#if USE_PROTOTYPES

extern INT wi_query_info (INT input_id, WI_RSRC_INFO *info);

#else	    /* no prototypes */

extern INT wi_query_info ();

#endif	    /* of USE_PROTOTYPES */

#endif
