/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_DEFS.H*/
/* *1    30-JUN-1989 14:59:26 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_DEFS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_am_defs.h,v 1.1 89/05/30 15:33:07 esi Exp $ esi_am_defs.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_DEFS.H*/
/* *7    10-APR-1989 13:05:17 VINCE "(SPR 4981) Added INT casting"*/
/* *6    17-DEC-1988 09:25:55 GILLESPIE "(SPR 4981) Unisource"*/
/* *5    13-FEB-1988 20:25:03 GILLESPIE "(SPR 4212) Add function prototypes"*/
/* *4     6-JAN-1988 10:56:24 DAVID "(SPR 4161) Add text object definition"*/
/* *3    10-NOV-1987 18:59:55 MARKS "(SPR 4011) revert to distinct AM_SYSTEM and AM_GLOBAL defs"*/
/* *2    10-NOV-1987 17:12:41 MARKS "(SPR 4011) AM_SYSTEM & AM_GLOBAL equated;add HT size params"*/
/* *1     7-JUL-1987 10:42:44 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AM_DEFS.H*/
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

/*************************************************************************

NAME:    ESI_AM_DEFS.H

AUTHOR:  W. Jaeck

DESCRIPTION:

    ESI_AM_DEFS.H defines all symbols which are recognized by the
    application manager as parameters to any of the application manager
    services.

*************************************************************************/

#ifndef ESI_AM_DEFS_H
#define ESI_AM_DEFS_H 1

#define AM_APPLICATION	(INT)20
#define AM_SERVER	(INT)21
#define AM_GLOBAL	(INT)22 
#define AM_MENU		(INT)23
#define AM_DIALOG	(INT)24
#define AM_DB_CURSOR	(INT)25
#define AM_STATUS	(INT)26
#define AM_ALERT	(INT)27
#define AM_SYSTEM	(INT)28
#define AM_OPEN_JOURNAL_FILE	(INT)29
#define AM_CLOSE_JOURNAL_FILE	(INT)30
#define AM_REPORT	(INT)34
#define AM_FILE_STATUS	(INT)35
#define AM_FILE_REPORT	(INT)36
#define AM_TEXT_OBJECT	(INT)37

#define AM_NUM_BUCKETS	(INT)500    /* size of hash table allocated for  */
#define AM_BUCKET_SIZE	(INT)10	    /*    the data list */

#endif
