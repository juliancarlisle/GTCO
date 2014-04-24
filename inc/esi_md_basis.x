/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MD_BASIS.X*/
/* *3    23-OCT-1989 10:34:31 CONROY "(SPR 5043) Mods for new MAPPING UI programmer tools"*/
/* *2     5-SEP-1989 13:55:37 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *1    30-JUN-1989 15:07:58 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MD_BASIS.X*/
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

#ifndef ESI_MD_BASIS_X
#define ESI_MD_BASIS_X 1

#ifndef ESI_MD_DEFS_H
#include "esi_md_defs.h"
#endif

#ifndef ESI_MD_DBDEFS_H
#include "esi_md_dbdefs.h"
#endif


extern MD_KEY_INFO keyinfo[MD_MAX_KEYWORDS+1] ;	/*keyword array*/

extern MD_VERB_INFO overlay_verbs[MD_MAX_OVERLAY_TYPES+1] ; /*verb array*/

extern CHAR *overlay_tcp[MD_MAX_OVERLAY_TYPES+1] ;

#endif
