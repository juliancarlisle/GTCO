/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SDL.H*/
/* *2    14-AUG-1990 11:50:43 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:04:05 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SDL.H*/
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

#ifndef ESI_SDL_H
#define ESI_SDL_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

/* symbol definition routines */
#if USE_PROTOTYPES

extern INT sdl_init(void) ;
extern INT sdl_InitPolymarkerGroup(void);
extern INT sdl_term(void) ;
extern INT sdl_load(ENTRYNAME group) ;

#else

extern INT sdl_init() ;
extern INT sdl_InitPolymarkerGroup();
extern INT sdl_term() ;
extern INT sdl_load() ;

#endif

#endif
                                             
