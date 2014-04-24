/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TU.H*/
/* *3    14-AUG-1990 11:51:28 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2     7-MAR-1990 16:40:12 WALTERS "(SPR 0) Remove FLOAT types from system"*/
/* *1    30-JUN-1989 15:05:17 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TU.H*/
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

#ifndef ESI_TU_H
#define ESI_TU_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

/******************************************************************************/
/*  Include file for UOM toolkit                                              */
/******************************************************************************/

typedef struct 
{
    INT uom_code;                           /* UOM abbreviation         */
    FLOAT uom_definition;                   /* Coversion to millimeters */
    UOM_NAME uom_name;                      /* UOM Name                 */
    CHAR uom_type[11];                      /* UOM Type                 */
}UOM_STRUCTURE;

#define UOM UOM_STRUCTURE

/******************************************************************************/

/*  Define toolkit entry points       	*/

/* 11/17/88 SC - declare the following functions as extern */

#if USE_PROTOTYPES

extern INT tu_conversion_factor(CHAR *from_uom_name, CHAR *to_uom_name,
	DOUBLE *conversion_factor);
extern INT tu_disp_units_to_wcs(CHAR *units, DOUBLE *wcs, DOUBLE wcs_to_inches);
extern INT tu_get_tcp(TCP *tcp, INT type);
extern INT tu_parse_scale(CHAR *scale_string, DOUBLE *map_scale, CHAR *scale_units);
extern INT tu_parse_scale2(CHAR *scale_string, DOUBLE *map_scale, CHAR *units_right,
	CHAR *units_left);
extern INT tu_parse_unit(CHAR *unit_string, DOUBLE *value, CHAR *uom1, CHAR *uom2);
extern INT tu_scale_conversion(CHAR *from_uom_name, CHAR *scale_string,
	DOUBLE *conversion_factor);
extern INT tu_unit_conversion(DOUBLE value_in, CHAR *uom_in, DOUBLE *value_out,
	CHAR *uom_out);
extern INT tu_verify_uom(CHAR *uom_name_in, UOM_STRUCTURE *uom_data);

#else

extern INT tu_conversion_factor();
extern INT tu_disp_units_to_wcs();
extern INT tu_get_tcp();
extern INT tu_parse_scale();
extern INT tu_parse_scale2();
extern INT tu_parse_unit();
extern INT tu_scale_conversion();
extern INT tu_unit_conversion();
extern INT tu_verify_uom();

#endif

#endif
