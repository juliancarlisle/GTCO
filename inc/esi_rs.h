/* DEC/CMS REPLACEMENT HISTORY, Element ESI_RS.H*/
/* *1    30-JUN-1989 15:03:53 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_RS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_rs.h,v 1.1 89/05/30 15:34:45 esi Exp $ esi_rs.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_RS.H*/
/* *4     8-APR-1989 00:36:59 GILLESPIE "Add copyright, (INT) castings"*/
/* *3    17-DEC-1988 09:35:16 GILLESPIE "(SPR 4981) Unisource"*/
/* *2    13-FEB-1988 20:25:51 GILLESPIE "(SPR 4212) Add function prototypes"*/
/* *1     7-JUL-1987 10:47:25 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_RS.H*/
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

#ifndef ESI_RS_H
#define ESI_RS_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_RS_ERR_H
#include "esi_rs_err.h"
#endif

#if USE_PROTOTYPES

extern INT rsinit(void);
extern INT rsterm(void);
extern INT rsmdopen(INT mdid);
extern INT rsmdclos(INT mdid);
extern INT rsopen(CHAR *rsrcfile);
extern INT rsclose(CHAR *rsrcfile);
extern INT rspush(INT mdid);
extern INT rspop(INT *mdid);
extern INT rsfetch(INT rsrcid, CHAR *rsrctype, CHAR **rsrcptr);
extern CHAR *rsgets(CHAR *s, CHAR *ptr);

#else

extern INT rsinit();
extern INT rsterm();
extern INT rsmdopen();
extern INT rsmdclos();
extern INT rsopen();
extern INT rsclose();
extern INT rspush();
extern INT rspop();
extern INT rsfetch();
extern CHAR *rsgets();

#endif
#endif
