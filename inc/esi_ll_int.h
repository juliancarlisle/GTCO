/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LL_INT.H*/
/* *1    30-JUN-1989 15:02:33 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LL_INT.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_ll_int.h,v 1.1 89/05/30 15:34:17 esi Exp $ esi_ll_int.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LL_INT.H*/
/* *8    12-APR-1989 18:04:08 JRB "Fix bad character in copyright notice"*/
/* *7     8-APR-1989 00:32:52 GILLESPIE "Add copyright, (INT) castings"*/
/* *6    17-DEC-1988 09:32:39 GILLESPIE "(SPR 4981) Unisource"*/
/* *5    12-APR-1988 10:08:53 GILLESPIE "(SPR 4410) Add USE_PROTOTYPES switch"*/
/* *4    30-MAR-1988 16:49:37 GARY "(SPR 4315) BACKOUT OF PRIME PORT CHECKIN OF GEN 3"*/
/* *3    25-MAR-1988 14:56:34 GARY "(SPR 4315) FINDERV5 PORT TO PRIME MODS"*/
/* *2     4-FEB-1988 14:42:01 GILLESPIE "(SPR 4224) Rewrite - remove flags from LL_NODE structure - simplify"*/
/* *1     7-JUL-1987 10:46:12 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LL_INT.H*/
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

#ifndef ESI_LL_INT_H
#define ESI_LL_INT_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif


typedef struct ll_node
    {
    struct ll_node *prev ;
    struct ll_node *next ;
    BYTE data[1];
    }  LL_NODE ;


#define NULL_LIST (LISTHEAD *)0
#define NULL_NODE (LL_NODE *)0

#define LL_STANDARD_TEST_PATTERN 0xDCBA


#if USE_PROTOTYPES

extern VOIDPTR llz_alloc (INT type, INT nbytes);
extern INT llz_free (INT flags, VOIDPTR node);

#else	    /* no prototypes */

extern VOIDPTR llz_alloc ();
extern INT llz_free ();

#endif	    /* of USE_PROTOTYPES */

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif


#endif
