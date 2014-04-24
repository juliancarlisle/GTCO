/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HF.H*/
/* *5    13-OCT-1990 00:38:37 GILLESPIE "(SPR 100) Move from Ernie"*/
/*  2B1  13-OCT-1990 00:22:45 GILLESPIE "Updates from Ernie"*/
/* *4    21-AUG-1990 17:06:43 KEE "(SPR -1) Fixing compile error at sun"*/
/* *3    14-AUG-1990 11:48:10 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    18-NOV-1989 09:42:01 GILLESPIE "(SPR 5075) Global overhaul"*/
/* *1    30-JUN-1989 15:01:21 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HF.H*/
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

#ifndef ESI_HF_H
#define ESI_HF_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/*%S this include file is a list of help facility routines.
    Author James Chang.   04/04/86
*/

#if USE_PROTOTYPES

extern INT hf_display_help_init(void);
extern INT hf_do_help(CHAR *help_key);
extern INT hf_get_help(CHAR *key_string);
extern INT hf_start_help(CHAR *help_key);

#else

extern INT hf_display_help_init();
extern INT hf_do_help();
extern INT hf_get_help();
extern INT hf_start_help();

#endif

#endif



