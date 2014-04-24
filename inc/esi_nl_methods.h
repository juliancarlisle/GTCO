/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL_METHODS.H */
/* *7    14-AUG-1990 11:50:09 GILLESPIE "(SPR 2001) Major realignment of include files" */
/* *6    16-MAR-1990 11:12:11 PURNA "(SPR 5135) create nlz_strip_points" */
/* *5    14-FEB-1990 10:37:04 GILLESPIE "(SPR 6005) Make window clip a method" */
/* *4    12-OCT-1989 09:46:54 GILLESPIE "(SPR 44) Changes for n-List methods" */
/* *3    15-SEP-1989 13:44:50 GORDON "(SPR 100) Remove INT_FUNCTION_PTR typedef - now in ESI_GL_DEFS.H" */
/* *2    27-JUL-1989 22:44:52 GILLESPIE "(SPR 1) n-List methods initial release" */
/* *1    27-JUL-1989 22:44:10 GILLESPIE "n-List methods initial release" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL_METHODS.H */
#ifndef ESI_NL_METHODS_H
#define ESI_NL_METHODS_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

typedef CHAR NLM_FUNCTION_NAME[32];

/* ========= information for n-List methods ================= */

typedef enum {
	NL_DRAW_METHOD,			/* Perform drawing */
	NL_SAVE_METHOD,			/* Save away the n-List */
	NL_UPDATE_METHOD,		/* Save away the n-List */
	NL_PRINT_METHOD,		/* Display the n-List formatted for character output */
	NL_RESAMPLE_METHOD,		/* Resampling method */
	    NL_STRIP_METHOD,		/* Remove rows when two vectors 
			                   connecting this row is colinear 
					   for given factor */
	    NL_BILINEAR_METHOD,		/* Add rows when the distance between two
					   rows is greater than the given 
					   distance	    */

	NL_SORT_METHOD,			/* Perform sorting */
	NL_CLIP_METHOD,			/* Perform simple 2d window clipping */
	NL_NULL_METHOD			/* No operation */
	} NLIST_METHOD ;

#endif
