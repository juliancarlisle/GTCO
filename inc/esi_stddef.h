/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STDDEF.H*/
/* *12   14-AUG-1990 12:09:31 GILLESPIE "(SPR 2001) Major include file change"*/
/* *11   13-JUN-1990 23:40:58 JULIAN "(SPR -1) Don't include types in UNIX version"*/
/* *10   12-MAR-1990 22:17:46 GILLESPIE "(SPR 6019) MPW and LSC changes needed after DECStation mods"*/
/* *9    28-FEB-1990 08:46:54 GILLESPIE "(SPR 6010) More changes from Decstation port"*/
/* *8    26-FEB-1990 19:07:37 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *7    21-NOV-1989 09:54:19 GILLESPIE "(SPR 1) Remove esi_gl_defs.h circular reference"*/
/* *6    12-OCT-1989 09:47:00 GILLESPIE "(SPR 44) Changes for n-List methods"*/
/* *5    12-OCT-1989 09:32:43 GILLESPIE "(SPR 1) Get with the ANSI spirit!"*/
/* *4    19-SEP-1989 14:15:33 JULIAN "addef __STDDEF define"*/
/* *3    18-SEP-1989 16:47:16 JULIAN "(SPR 1) added define of __STDDEF"*/
/* *2    26-JUL-1989 00:13:10 GILLESPIE "(SPR 51) Minor adjustments"*/
/* *1    30-JUN-1989 15:04:29 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STDDEF.H*/
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

/* STDDEF.H   */
#ifndef ESI_STDDEF_H
#define ESI_STDDEF_H

#ifdef THINK_C
#include <stddef.h>
#else
#ifdef applec
#include <stddef.h>
#else

#ifndef NULL
#define NULL		((char *) 0) /* ANSI says this should be (void *) */
#endif

#ifndef __size_t
#define __size_t
typedef unsigned long size_t;
#endif

/*
#ifndef __wchar_t
#define __wchar_t
typedef char wchar_t;
#endif
*/

#ifdef vms
#define __STDDEF
#define offsetof(type, field)	((size_t) &((type *) 0)->field)
typedef long ptrdiff_t;
#endif

#ifdef primos
#define __STDDEF
#define offsetof(type, field)	((size_t) &((type *) 0)->field)
typedef long ptrdiff_t;
#endif

#endif	/* applec */
#endif	/* THINK_C */
#endif
