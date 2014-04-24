/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_VCHAR.H*/
/* *2    29-APR-1991 11:15:24 LOEBL "(SPR 0) added V_STRNCPY, V_VC_TO_VC defines"*/
/* *1    30-JUN-1989 15:01:12 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_VCHAR.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_gl_vchar.h,v 1.1 89/05/30 15:33:47 esi Exp $ esi_gl_vchar.h 
 */

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

#ifndef ESI_GL_VCHAR_H
#define ESI_GL_VCHAR_H 1

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

/* VARCHAR is a data structure used by the ORACLE precompiler interface
   It is duplicated here for programmer convenience.
   MACROS are provided for manipulation of the data type
 */

#define VARCHAR struct varchar_struct

   VARCHAR {
      SHORT len;
      CHAR  *arr;
   } ;

#define V_LEN(x)       (x.len)
#define V_STRING(x)    (x.arr)
#define V_SETZERO(x)   (V_STRING(x)[V_LEN(x)] = 0)
#define V_SETLEN(x)    (V_LEN(x) = strlen( (char *)V_STRING(x) ))
#define V_FROMC(d, s)  { strcpy((char *)V_STRING(d), (char *)s); V_SETLEN (d); }
#define V_FROMV(d, s)  { V_SETZERO(s); strcpy((char *)d, (char *)V_STRING(s)); }
#define V_CLEAR(x)     V_FROMC (x, "")
#define V_V_TO_C(d, s) V_FROMV(d, s)
#define V_C_TO_V(d, s) V_FROMC(d, s)
#define V_STRNCPY(d, s, n) { strncpy(d.arr, (char *)s, (int)n); d.len = (int)n; }
#define V_VC_TO_VC(d, s)   { strncpy(d.arr, s.arr, s.len); d.len = s.len; }

#endif
