/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ERRNO.H*/
/* *5    20-AUG-1990 17:16:14 KEE "(SPR -1) fixing compile error at sun"*/
/* *4    14-AUG-1990 12:05:03 GILLESPIE "(SPR 2001) Major include file change"*/
/* *3    26-FEB-1990 19:06:41 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *2    29-NOV-1989 11:45:18 GILLESPIE "(SPR 1) Fix up VMS include section for C 3.0 compiler"*/
/* *1    30-JUN-1989 15:00:20 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ERRNO.H*/
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1989
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
#ifndef ESI_ERRNO_H
#define ESI_ERRNO_H 1

#ifdef sun
/* on sun these will be defined in errno.h */
#undef EDOM
#undef ERANGE
#endif

#include <errno.h>

#ifdef primos
extern INT errno;
#define ERANGE 0xAA	/* when result too large , errno gets this value*/
#endif

#endif		/*	ESI_ERRNO_H		*/
