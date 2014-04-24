/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WE_VFDEF.H*/
/* *2    14-AUG-1990 11:51:41 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:05:34 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WE_VFDEF.H*/
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

#ifndef ESI_WE_VFDEF_H
#define ESI_WE_VFDEF_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

typedef struct {
    UWI  uwi;
    BOOL show_well;
    BOOL well_exists;
    } VERIFY_WELL_STRUCT;

INT we_verify_well();
INT we_verify_well_server();

#endif
