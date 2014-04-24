/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MG.H*/
/* *1    30-JUN-1989 15:03:05 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MG.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_mg.h,v 1.1 89/05/30 15:34:27 esi Exp $ esi_mg.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MG.H*/
/* *3     8-APR-1989 00:34:22 GILLESPIE "Add copyright, (INT) castings"*/
/* *2    17-DEC-1988 09:33:30 GILLESPIE "(SPR 4981) Unisource"*/
/* *1     7-JUL-1987 10:46:30 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MG.H*/
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

/*
 * Modified by joseph H. on 11/16/88
 * $Header: /dba0/esi/finder/include/RCS/esi_mg.h,v 1.1 89/05/30 15:34:27 esi Exp $
 * $Locker:  $
 * $Date: 89/05/30 15:34:27 $
 * $Log:	esi_mg.h,v $
 * Revision 1.1  89/05/30  15:34:27  esi
 * Initial
 * 
 * Revision 1.2  87/01/07  08:37:50  john
 * made mg() a macro
 * 
 * Revision 1.1  86/12/12  06:11:04  edb
 * Initial revision
 * 
 */


#ifndef ESI_MG_H
#define ESI_MG_H 1
#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif
/*************************************************************************

NAME:    ESI_MG.H

AUTHOR:  W. Jaeck, 25-Oct-1986

DESCRIPTION:

    Users of the mg_message facility should include this file.

*************************************************************************/

#define MG_CONFIG_FILE "MG_CONFIG"

#if USE_PROTOTYPES
extern CHAR *mg_message(INT id);
#else
extern CHAR *mg_message();
#endif

#define mg(code) mg_message(code)

#endif
