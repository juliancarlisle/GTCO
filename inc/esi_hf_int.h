/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HF_INT.H*/
/* *1    30-JUN-1989 15:01:23 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HF_INT.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_hf_int.h,v 1.1 89/05/30 15:33:52 esi Exp $ esi_hf_int.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HF_INT.H*/
/* *6     8-APR-1989 00:30:13 GILLESPIE "Add copyright, (INT) castings"*/
/* *5     7-APR-1989 23:47:03 GILLESPIE "Add copyright"*/
/* *4    17-DEC-1988 09:30:33 GILLESPIE "(SPR 4981) Unisource"*/
/* *3    23-AUG-1988 11:00:29 GILLESPIE "(SPR 4785) Add #ifndef calls; add prototypes"*/
/* *2     9-FEB-1988 10:36:51 JAMES "(SPR 4208) THE new include file for help facility."*/
/* *1     9-FEB-1988 10:20:30 JAMES "The internal include file for HELP FACILITY."*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HF_INT.H*/
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

#ifndef ESI_HF_INT_H
#define ESI_HF_INT_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_HF_H
#include "esi_hf.h"
#endif

#define MAX_NUM_CHARS (INT)50

typedef struct hfstruct
    {
    INT	    total_used_chars;
    INT	    total_allocated_chars;
    CHAR    *message_ptr;
    CHAR    *current_key;
    CHAR    *parent_key;
    INT	    cdlg_id;
    INT	    total_lines;
    } HF_STRUCT ;

#endif
