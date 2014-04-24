/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CI.H*/
/* *2    14-AUG-1990 11:46:27 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 14:59:49 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CI.H*/
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

#ifndef ESI_CI_H
#define ESI_CI_H 1

/* %F Includes for CI_COMMAND_INTERP.CC
*/

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#if USE_PROTOTYPES

extern INT ci_init(void);
extern INT ci_term(void);
extern INT ci_interpret(CHAR *string);
extern INT ci_add_command(CHAR *comname, VOID (*func_ptr)());
extern INT ci_load(FILENAME filename);

#else

extern INT ci_init();
extern INT ci_term();
extern INT ci_add_command();
extern INT ci_load();

#endif
#endif
                                                                                                                     
