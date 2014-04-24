/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AS_SAVE.H*/
/* *2    14-AUG-1990 11:46:24 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 14:59:40 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_AS_SAVE.H*/
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

NAME:    ESI_AS_SAVE.H

AUTHOR:  Dave Barber, 3 February 1987

DESCRIPTION:

    ESI_AS_SAVE.H defines the protocol buffer between an application
    program and the AS_SAVE application server.


*************************************************************************/

#ifndef ESI_AS_SAVE_H
#define ESI_AS_SAVE_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

typedef struct {
    INT status;                   /* Completion status */
    BOOL cancel;                  /* Operator cancelled */
    CHAR message[100];            /* Message to display */
    FILENAME filename;            /* Filename from operator */
    } AS_SAVE_WORKSPACE;

#if USE_PROTOTYPES
extern INT as_save(AS_SAVE_WORKSPACE *);
#else
extern INT as_save();
#endif

#endif

