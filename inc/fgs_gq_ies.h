/* DEC/CMS REPLACEMENT HISTORY, Element FGS_GQ_IES.H */
/* *1    18-JUN-1990 12:03:13 GILLESPIE "GQS IES Data Exchange application" */
/* DEC/CMS REPLACEMENT HISTORY, Element FGS_GQ_IES.H */
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1990
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND
MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphics Systems, Inc.
			201 Tamal Vista Blvd
			Corte Madera, CA  USA 94925
			(415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/
#ifndef FGS_GQ_IES_H
#define FGS_GQ_IES_H 1

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

typedef struct
    {
    INT cdlg_id;
    INT message_field;
    TCP seis_tcp;
    NLIST_ID seis_list_name;
    TCP wells_tcp;
    NLIST_ID wells_list_name;
    PROJECT_NAME project_name;
    ANALYST_NAME user_id;
    CHAR user_password[32];
    INT ies_error;
    } IES_STRUCT;


#endif
