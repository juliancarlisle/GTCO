/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GB_GLOBAL_SELECTION.H*/
/* *2    14-AUG-1990 11:47:29 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:00:35 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GB_GLOBAL_SELECTION.H*/
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

#ifndef ESI_GB_GLOBAL_SELECTION_H
#define ESI_GB_GLOBAL_SELECTION_H

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#ifndef ESI_BT_H
#include "esi_bt.h"
#endif

#ifndef ESI_GB_H
#include "esi_gb.h"
#endif

#define NullString              ""
#define NullChar                '\0'

typedef struct
{
    NLIST_HEADER *ListStructurePointer;
    INT_FUNCTION_PTR Function;
    INT  *Parameter;
} SAVE_LIST_STRUCTURE;

typedef struct
{
    NLIST_HEADER *ListStructurePointer;
    INT_FUNCTION_PTR Function;
    INT  *Parameter;
} EDIT_LIST_STRUCTURE;


typedef struct
{
    INT  nSelectable;
    TCP Strings;
    INT  nSelected;
    TCP Selections;
    INT  *IntSelections;
    CHAR *WindowTitle;
    INT_FUNCTION_PTR Function;
    INT  *Parameter;
} SELECT_LIST_STRUCTURE;

#endif
