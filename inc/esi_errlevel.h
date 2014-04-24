/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ERRLEVEL.H*/
/* *1    30-JUN-1989 15:00:17 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ERRLEVEL.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_errlevel.h,v 1.1 89/05/30 15:33:29 esi Exp $ esi_errlevel.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ERRLEVEL.H*/
/* *5     8-APR-1989 00:27:15 GILLESPIE "Add copyright, (INT) castings"*/
/* *4     7-APR-1989 23:44:08 GILLESPIE "Add copyright"*/
/* *3    17-DEC-1988 09:28:19 GILLESPIE "(SPR 4981) Unisource"*/
/* *2    23-AUG-1988 12:38:47 GILLESPIE "(SPR 4785) Fix #ifdef"*/
/* *1     7-JUL-1987 10:44:12 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ERRLEVEL.H*/
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

#ifndef ESI_ERRLEVEL_H
#define ESI_ERRLEVEL_H 1

/* Error severity levels */

#define SUGGESTION (INT)0
#define WARNING (INT)1
#define ERROR_RETURN (INT)2
#define ERROR_EXIT (INT)2
#define FATAL_ERROR (INT)4
#define ER_USER_REPORT (INT)0
#define ER_PROG1_REPORT (INT)1
#define ER_PROG2_REPORT (INT)2
#define ER_DEADLY_REPORT (INT)3
#endif

