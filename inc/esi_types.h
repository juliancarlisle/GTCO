/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TYPES.H*/
/* *6    24-AUG-1990 11:22:35 VINCE "(SPR 1) changed __TYPES to _TYPES_ since thats what the system types.h looks for"*/
/* *5    14-AUG-1990 11:51:31 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *4    26-FEB-1990 19:07:56 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *3     2-AUG-1989 15:04:59 JULIAN "added extra #endif"*/
/* *2     2-AUG-1989 14:19:59 JULIAN "ADDED __TYPES ALREADY CALLED FLAG."*/
/* *1    30-JUN-1989 15:05:20 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TYPES.H*/
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

/*	TYPES - RTL Typedef Definitions 	*/


#ifndef ESI_TYPES_H
#define ESI_TYPES_H 1

#ifndef _TYPES_
#define _TYPES_
#ifdef UNIX

#include "sys/types.h"				/* 910319:sjs: added sys to include spec */

#else

typedef unsigned long int time_t;

#endif
#endif

#endif
