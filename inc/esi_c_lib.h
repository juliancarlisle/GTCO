/* DEC/CMS REPLACEMENT HISTORY, Element ESI_C_LIB.H*/
/* *2    14-AUG-1990 11:46:49 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:00:03 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_C_LIB.H*/
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

/* NOTE: fopen should be defined only after stdio.h is included... JGG */
#ifndef ESI_C_LIB_H
#define ESI_C_LIB_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

			/* Undefine the memory management tokens */
#ifdef malloc

#undef malloc
#undef free
#undef realloc

#endif

#include "esi_stdio.h"
#include "esi_stdlib.h"
#include "esi_string.h"

/* redefine the memory manager stuff */

#define malloc(nbytes) tc_alloc(nbytes)
#define free(nbytes) tc_free(nbytes)
#define realloc(ptr,size) tc_realloc(ptr,size)

#ifdef primos

extern int     fexists();
extern int     ftype();

extern int     copy();
extern int     delete();
extern char    *index();
extern char    *rindex();

#define strchr(string, character) index(string, character)
#define strrchr(string, character) rindex(string, character)

#endif

#define NULL_FILE_PTR (FILE *)0

#endif
