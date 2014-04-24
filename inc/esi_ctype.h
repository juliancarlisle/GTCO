/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CTYPE.H*/
/* *5    28-FEB-1990 05:21:42 GILLESPIE "(SPR 6010) Remove most everything (conflict w/prototypes on vms)"*/
/* *4    26-FEB-1990 19:06:34 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *3    12-OCT-1989 11:29:18 GILLESPIE "(SPR 44) Add #pragma directives for VMS"*/
/* *2     5-SEP-1989 11:28:10 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *1    30-JUN-1989 15:00:01 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CTYPE.H*/
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1990
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND
MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphics Systems, Inc.
			201 Tamal Vista Blvd
			Corte Madera, CA  USA 94925
			(415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#ifndef ESI_CTYPE_H
#define ESI_CTYPE_H 1

#include <ctype.h>

#ifdef _toupper
#undef _toupper
#endif

#ifdef _tolower
#undef _tolower
#endif

#define _toupper(c)	((c) >= 'a' && (c) <= 'z' ? (c) & 0x5F : (c))
#define _tolower(c)	((c) >= 'A' && (c) <= 'Z' ? (c) | 0x20 : (c))

#endif   /* end of esi_ctype.h */
