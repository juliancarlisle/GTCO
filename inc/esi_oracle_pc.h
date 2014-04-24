/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ORACLE_PC.H*/
/* *1    30-JUN-1989 15:03:34 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ORACLE_PC.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_oracle_pc.h,v 1.3 89/06/01 15:33:26 esi Exp $ esi_oracle_pc.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ORACLE_PC.H*/
/* *3     8-APR-1989 00:35:44 GILLESPIE "Add copyright, (INT) castings"*/
/* *2    17-DEC-1988 09:34:39 GILLESPIE "(SPR 4981) Unisource"*/
/* *1     7-JUL-1987 10:47:03 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ORACLE_PC.H*/
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

#ifndef ESI_ORACLE_H
#define ESI_ORACLE_H 1

#ifndef ESI_GL_VCHAR_H
#include "esi_gl_vchar.h"
#endif

EXEC SQL INCLUDE SQLCA.H;

/***************************  ESI-DEFINED VALUES  *****************************/

#define OR_EOF (INT)1403
#define OR_ABORT (INT)-1013
#define OR_STATUS sqlca.sqlcode
#define OR_MESSAGE sqlca.sqlerrm.sqlerrmc
#define OR_ROWCOUNT sqlca.sqlerrd[2]

#if USE_PROTOTYPES
extern INT or_login(INT argc, CHAR **argv);
extern INT or_logout(BOOL commit_flag);
#else
extern INT or_login();
extern INT or_logout();
#endif

#endif
