/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CT.H*/
/* *14    8-JUL-1991 11:43:58 CHEW "(SPR 7344) Replace UINT minutes in LATLONG struct. to INT minutes."*/
/* *13    6-MAY-1991 13:31:05 PURNA "(SPR 0) data mover init change"*/
/* *12   14-AUG-1990 11:46:45 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *11   17-JUL-1990 15:13:58 GILLESPIE "(SPR 1) Changes for elect. drafting cleanup"*/
/* *10   12-JUL-1990 12:57:23 GILLESPIE "(SPR 3) Rearrange elements between esi_gl_top.h and esi_ct.h"*/
/* *9    20-JUN-1990 09:47:04 PURNA "(SPR 0) replace ct_get_faults with co_get_faults"*/
/* *8    26-FEB-1990 19:06:28 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *7     9-FEB-1990 17:26:03 MING "(SPR 0) delete non-referenced functions"*/
/* *6     8-FEB-1990 14:12:09 WALTERS "(SPR 0) Add include statement for esi_tu.h"*/
/* *5     8-FEB-1990 12:13:28 WALTERS "(SPR 0) Add prototype for ct_get_projection_uom"*/
/* *4    18-DEC-1989 16:50:23 PURNA "(SPR 5069) export facility mods"*/
/* *3    17-OCT-1989 15:44:59 CONROY "(SPR 5020) change parameters to ct_transform_array"*/
/* *2    10-OCT-1989 10:54:58 PURNA "(SPR 5020) mods for CT parameter change"*/
/* *1    30-JUN-1989 14:59:58 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CT.H*/
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


#ifndef ESI_CT_H
#define ESI_CT_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_MM_H
#include "esi_mm.h"
#endif

/************************************************************************

   This file defines the Finder Cartographic Pipeline Package

   The actual cartographic routines are adaptations of the USGS
   package GCTP and are written in Fortran-77.  The routines contained
   in this file provide  abilities to define transformation parameters
   and to perform the desired transformations.

************************************************************************/

#define NO_OF_PROJECTIONS (INT)21
#define NO_OF_SPHEROIDS (INT)20
#define NO_OF_UNITS (INT)6
#define ZERO (INT)0

typedef COORD ROW_XY[2];

typedef struct {
    DOUBLE parm_1;
    DOUBLE parm_2;
    DOUBLE parm_3;
    DOUBLE parm_4;
    DOUBLE parm_5;
    DOUBLE parm_6;
    DOUBLE parm_7;
    DOUBLE parm_8;
    DOUBLE parm_9;
    DOUBLE parm_10;
    DOUBLE parm_11;
    DOUBLE parm_12;
    DOUBLE parm_13;
    DOUBLE parm_14;
    DOUBLE parm_15;
    }DISCRETE_PARMS;

typedef union
{
    DOUBLE parm_array[15];        /* Array format                   */
    DISCRETE_PARMS d_parm;        /* Discrete format                */
} PARM_DATA;

typedef enum {LATITUDE = 0, LONGITUDE = 1} LL_T;

typedef struct {
    DOUBLE decimal;
    struct {
       INT degrees;
       INT minutes;
       DOUBLE seconds;
       } dms;
    }  LATLONG;

typedef struct {                  /* Projection Structure Type       */
    PROJECTION_ID projection_id;  /* Unique Projection Identifier    */
    PROJECTION_NAME projection_name;/* Projection Name (description) */
    INT    projection_type;       /* USGS Projection Type Code       */
    INT    spheroid_code;         /* USGS Spheroid Code              */
    INT    spheroid_units;        /* UOM for Spheroid                */
    INT    zone_code;             /* UTM or US State Plane Zone      */
    DISCRETE_PARMS parameters;    /* Parameters                      */
    } PROJECTION_STRUCTURE;

/************************************************************************/
/*   Carto package entry points                                         */
/************************************************************************/

#if USE_PROTOTYPES

extern VOID ctg_gtp$0(COORD x_coord_in,COORD y_coord_in,
	PROJECTION_STRUCTURE *projection_in, COORD *x_coord_out,
	COORD *y_coord_out, PROJECTION_STRUCTURE *projection_out, INT *status);
extern VOID ct_decimal_to_dms(LATLONG *latlong, LL_T type, CHAR *latlong_str);
extern VOID ct_dms_to_decimal(LATLONG *latlong);
extern INT ct_get_default_project(PROJECTION_ID projection_id_out);
extern INT ct_get_line(LINE *line, INT line_number, FILENAME nlist_file);
extern INT ct_get_nlist(NLIST_HEADER *nlist, FILENAME nlist_name, NLIST_ID nlist_id,
	UINT *dim_list, DOUBLE convergence_tolerance);
extern INT ct_get_node(NODE_ID node_id, COORD *x, COORD *y);
extern INT ct_get_projection(PROJECTION_ID projection_id_in,
	PROJECTION_STRUCTURE **projection_data);
extern INT ct_get_projection_uom(PROJECTION_ID projection_name, UOM_NAME uom_name);
extern INT ct_get_symbol(SYMBOL *symbol, INT symbol_number);
extern INT ct_get_text(TEXT *text, INT text_number);
extern INT ct_get_uom_factor(CHAR *from_projection, CHAR *to_projection, 
			     DOUBLE *factor);
extern INT ct_map_nlist_xy(NLIST_HEADER nlist_in, NLIST_HEADER *nlist_out,
	UINT *dim_list, DOUBLE conversion_tolerance);
extern INT ct_map_xy(COORD x_coord_in, COORD y_coord_in,
	 COORD *x_coord_out, COORD *y_coord_out);
extern INT ct_projection_list(TCP *list, INT *nitems, BOOL for_mapping);
extern INT ct_project_nlist_xy(NLIST_HEADER nlist_in, NLIST_HEADER *nlist_out,
	UINT *dim_list, DOUBLE conversion_tolerance);
extern INT ct_project_xy(COORD x_coord_in, COORD y_coord_in,
	COORD *x_coord_out, COORD *y_coord_out);
extern INT ct_put_node(COORD x, COORD y, NODE_ID *node_id);
extern INT ct_transform_array(COORD *x_array_in, COORD *y_array_in,
	INT no_of_pts_in, PROJECTION_STRUCTURE *projection_in,
	COORD **x_array_out, COORD **y_array_out,
	INT *no_of_pts_out, PROJECTION_STRUCTURE *projection_out,
	DOUBLE conversion_tolerance);
extern INT ct_transform_nlist(NLIST_HEADER nlist_in,
	PROJECTION_STRUCTURE *projection_in, NLIST_HEADER *nlist_out,
	PROJECTION_STRUCTURE *projection_out, UINT dim_list_in[2],
	DOUBLE conversion_tolerance);
extern INT ct_transform_point(COORD x_coord_in,COORD y_coord_in,
	PROJECTION_STRUCTURE *projection_in, COORD *x_coord_out,
	COORD *y_coord_out, PROJECTION_STRUCTURE *projection_out);
extern INT ct_update_node(NODE_ID node_id, COORD x, COORD y);

#else

extern VOID ctg_gtp$0();
extern VOID ct_decimal_to_dms();
extern VOID ct_dms_to_decimal();
extern INT ct_get_default_project();
extern INT ct_get_line();
extern INT ct_get_nlist();
extern INT ct_get_node();
extern INT ct_get_projection();
extern INT ct_get_projection_uom();
extern INT ct_get_symbol();
extern INT ct_get_text();
extern INT ct_get_uom_factor();
extern INT ct_get_well_location();
extern INT ct_map_nlist_xy();
extern INT ct_map_xy();
extern INT ct_projection_list();
extern INT ct_project_nlist_xy();
extern INT ct_project_xy();
extern INT ct_put_node();
extern INT ct_transform_array();
extern INT ct_transform_nlist();
extern INT ct_transform_point();
extern INT ct_update_node();

#endif

/************************************************************************/

#ifdef primos
fortran GTP$0();                 /* Fortran entry point */
#else
#ifdef vms
extern VOID gtp$0();
#endif
#if UNIX
extern VOID gtp$0();
#endif
#endif

#endif
