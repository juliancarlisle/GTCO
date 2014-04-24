/* DEC/CMS REPLACEMENT HISTORY, Element INTER_WORK.H*/
/* *2    14-AUG-1990 11:52:57 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:06:21 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element INTER_WORK.H*/
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

#ifndef INTER_WORK_H
#define INTER_WORK_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

/*
**                            DATA DECLARATIONS
*/
/* This definition stores information about the line intersections calculation */
typedef struct
    {
    INT       dialog_id;     /* Custom dialog ID */
    CHAR      Area[31];      /* Project name */
    CHAR      Survey[20];    /* Survey */
    CHAR      User[31];      /* Finder user account */
    INT       Flag_all;      /* Flag =1 if calculations for all lines */
    CHAR      curr_seismic_list[255];      /* Current seismic list if 
                                               Flag_all = 0 */
    FILENAME  comi_file ;    /* name of the comi file to submit*/
    } INTER_WORKSPACE;

#endif
