/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OR_FORMS.H */
/*  4    19-NOV-1991 15:50:11 LOEBL "(SPR 0) Convert to sqlforms30" */
/* *3    14-AUG-1990 11:50:15 GILLESPIE "(SPR 2001) Major realignment of include files" */
/* *2     6-DEC-1989 12:34:38 GORDON "(SPR 0) Moving in from source directory" */
/* *1     6-DEC-1989 12:33:49 GORDON "Moving in from source directory" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_OR_FORMS.H */
/******************************************************************************

		Copyright FINDER Graphics Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF 

			FINDER Graphics Systems, Inc.
			201 Tamal Vista
			Corte Madera, CA  USA 94925
			(415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work) 


******************************************************************************/

#ifndef ESI_OR_FORMS_H
#define ESI_OR_FORMS_H 1

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

/* structure for running the ORACLE forms system from Finder */


typedef struct
    {
    INT cdlg_id;		/* ID of form selection dialog */
    INT front_dialog_id;	/* ID of dialog which was front when started */
    CHAR data_type[16];		/* data type of report */
    NLIST_HEADER nlist;		/* list of scripts */
    } FORM_STRUCT;

#endif
