/* DEC/CMS REPLACEMENT HISTORY, Element ESI_EE.H*/
/* *2    14-AUG-1990 11:47:06 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:00:13 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_EE.H*/
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

#ifndef ESI_EE_H
#define ESI_EE_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#define MAX_DEPTH 30
#define OPERATOR_TYPE (INT)1
#define VARIABLE_TYPE (INT)2
#define CONSTANT_TYPE (INT)3

#if USE_PROTOTYPES
extern INT ee_perform_operation(CHAR *result_nl, CHAR *token,
	CHAR *left_nl, CHAR *right_nl, FILENAME temp_nlists );
extern INT ee_parser(CHAR *exp_in, CHAR **exp_out);
extern INT ee_evaluator(CHAR *exp_in, CHAR **value);
#else
extern INT ee_perform_operation();
extern INT ee_parser();
extern INT ee_evaluator();
#endif

#endif
                                                                                                        
