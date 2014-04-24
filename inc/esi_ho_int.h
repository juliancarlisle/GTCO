/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_INT.H*/
/* *1    30-JUN-1989 15:01:34 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_INT.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_ho_int.h,v 1.1 89/05/30 15:33:55 esi Exp $ esi_ho_int.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_INT.H*/
/* *4    10-APR-1989 11:38:39 GILLESPIE "(SPR 24) Remove (INT) casts"*/
/* *3     8-APR-1989 00:30:27 GILLESPIE "Add copyright, (INT) castings"*/
/* *2    17-DEC-1988 09:30:53 GILLESPIE "(SPR 4981) Unisource"*/
/* *1     7-JUL-1987 10:45:40 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_INT.H*/
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

#ifndef ESI_HO_INT_H
#define ESI_HO_INT_H 1

/*	file:  ESI_HO_INT.H  a file internal to the HO routines
    	which stores the device channel from the open and the
    	status:
    		-1	channel available
    		 0	asynchronous line
    		 1	dma channel
    	int efn: (local event flag)
    		-1	not set
    		 0	available for all processes
    		 >31 <64	local to a process
*/ 

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#define HO_MAX_OPEN_DEVICES         10

struct HOV
{ 
    INT first_time;
    INT device_status[HO_MAX_OPEN_DEVICES][3];
}  ;

extern INT hoz_set_channel_type();

#endif
