/* DEC/CMS REPLACEMENT HISTORY, Element ESI_FI.H*/
/* *3    14-AUG-1990 11:47:10 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    18-DEC-1989 16:48:48 PURNA "(SPR 5069) export facility mods"*/
/* *1    30-JUN-1989 15:00:23 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_FI.H*/
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

#ifndef ESI_FI_H
#define ESI_FI_H 1

/*************************************************************************

FILE:	ESI_FI.H

DESCRIPTION:

    This include file contains the definitions of routines which the
    Finder provides for use in manipulating the applications which
    Finder starts and manages.

*************************************************************************/

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#if USE_PROTOTYPES

extern INT finder_config(void);
extern INT finder_config_analyst(void);
extern INT finder_config_project(BOOL set_process);
extern INT finder_config_terminal(void);
extern INT finder_config_workstation(void);
extern INT finder_initialize(int argc, char **argv);
extern INT finder_quit(BYTE *ptr);
extern INT finder_terminate(void);
extern INT fi_change_project(BYTE *pointer);
extern INT fi_enable_menu(INT (*entry_point)());
extern INT fi_pop(void);
extern INT fi_push(void);

#else

extern INT finder_config();
extern INT finder_config_analyst();
extern INT finder_config_project();
extern INT finder_config_terminal();
extern INT finder_config_workstation();
extern INT finder_initialize();
extern INT finder_quit();
extern INT finder_terminate();
extern INT fi_change_project();
extern INT fi_enable_menu();
extern INT fi_pop();
extern INT fi_push();

#endif

#endif
