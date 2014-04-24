/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_ZDEFS.H*/
/* *2    14-AUG-1990 11:48:56 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:02:24 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LG_ZDEFS.H*/
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

/* INCLUDE FILE for any modules calling the zone database routines.     */

#ifndef ESI_LG_ZDEFS_H
#define ESI_LG_ZDEFS_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#define ZONESIZE   21
#define VARBSIZE   21

#if USE_PROTOTYPES

extern INT get_system_default(CHAR *vname, CHAR *value);
extern INT lg_get_install_default(CHAR *zone, CHAR *vname, CHAR *value);
extern INT lg_zone_add_definition(CHAR *zone, CHAR *top_horizon, 
		CHAR *base_horizon);
extern INT lg_zone_get_variable_desc(CHAR *zone, CHAR *vname, CHAR *desc,
		CHAR *algorithm);
extern INT lg_zone_get_definition(CHAR *zone, CHAR *top_horizon, 
		CHAR *base_horizon);
extern INT lg_zone_get_value(UWI uwi, CHAR *zone, CHAR *vname, FLOAT *pvalue);
extern INT lg_zone_put_value(UWI uwi, CHAR *zone, DOUBLE top, DOUBLE base,
		CHAR *vname, DOUBLE value, CHAR *units, CHAR *fn);
extern INT lg_zone_put_variable_desc(CHAR *zone, CHAR *vname, CHAR *desc,
		CHAR *algorithm);
extern INT lg_zone_update_definition(CHAR *zone, CHAR *top_horizon,
		CHAR *base_horizon);

#else

extern INT get_system_default();
extern INT lg_get_install_default();
extern INT lg_zone_add_definition();
extern INT lg_zone_get_variable_desc();
extern INT lg_zone_get_definition();
extern INT lg_zone_get_value();
extern INT lg_zone_put_value();
extern INT lg_zone_put_variable_desc();
extern INT lg_zone_update_definition();

#endif

#endif
