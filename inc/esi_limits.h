/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LIMITS.H */
/* *5    30-OCT-1990 11:33:26 KEE "(SPR -1) Fix compile noise at sun" */
/* *4    14-AUG-1990 12:05:15 GILLESPIE "(SPR 2001) Major include file change" */
/* *3    26-FEB-1990 19:07:18 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)" */
/* *2    19-SEP-1989 11:17:00 GORDON "(SPR 100) clearing house for limits.h" */
/* *1    19-SEP-1989 09:53:23 GORDON "clearing house for limits.h" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LIMITS.H */
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

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_LIMITS_H

#ifdef sun

/*	LIMITS - V3.0	*/

# define CHAR_BIT	8
# define CHAR_MAX	127
# define CHAR_MIN	-128
# define INT_MAX	2147483647
# define INT_MIN	-2147483648
# define LONG_MAX	2147483647
# define LONG_MIN	-2147483648
# define SCHAR_MAX	127	
# define SCHAR_MIN	-128
# define SHRT_MAX	32767
# define SHRT_MIN	-32768
# define UCHAR_MAX	255u
# define UINT_MAX	4294967295u
# define ULONG_MAX	4294967295u
# define USHRT_MAX	65535u

#else

#ifndef LIMITS_H
#include <limits.h>
#define LIMITS_H
#endif /* LIMITS_H */

#endif

#endif
