/* DEC/CMS REPLACEMENT HISTORY, Element ESI_QS.H*/
/* *10   13-OCT-1990 00:37:16 GILLESPIE "(SPR 100) Move from Ernie"*/
/*  8B1  13-OCT-1990 00:26:09 GILLESPIE "Updates from Ernie"*/
/* *9    14-AUG-1990 11:50:29 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *8    31-JUL-1990 11:00:48 PURNA "(SPR 0) fix compiling error"*/
/* *7    30-JUL-1990 17:20:19 PURNA "(SPR 0) add lynx,lease select_list"*/
/* *6     9-FEB-1990 13:53:16 GILLESPIE "(SPR 6006) Add QS_SOURCE_NAME for data loaders"*/
/* *5    21-DEC-1989 15:47:02 GORDON "(SPR 0) Add QS_ASPECT_RATIO_LOCK"*/
/* *4     6-SEP-1989 14:57:35 GORDON "(SPR 200) fix the typo"*/
/* *3     5-SEP-1989 14:01:52 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *2    30-JUN-1989 15:48:21 GILLESPIE "(SPR -2) SCD mods"*/
/* *1    30-JUN-1989 15:03:50 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_QS.H*/
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


#ifndef ESI_QS_H
#define ESI_QS_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* esi.qs.h  define Finder state variable index parameters  V5.0 */

/* To change, give the value a unique name
   add the name to the appropriate list (character, float, integer)
   also add the name to ESI_QS.I for FORTRAN source.                 */

/* To use call QS_INQ_C( VALUE_NAME, &character_value, &len )
               QS_INQ_I(           , &integer_value )
               QS_INQ_F(                            )
      or
               QS_SET_C(                            ), ETC... */

#define MAXDINDEX 50

/******************************************************************************/

/* Character state variables */

#define QS_FINDER_ACCOUNT            (INT)0 /*	ORACLE user		    */
#define QS_FINDER_PASSWORD           (INT)1 /*	ORACLE password		    */
#define QS_PROJECT_NAME              (INT)2 /*	FINDER project		    */
#define QS_PROJECT_PROJECTION        (INT)3
#define QS_CUR_WELL                  (INT)4 /*	UWI of current global well. */
#define QS_CUR_SEISMIC               (INT)5     
#define QS_CUR_LEASE                 (INT)6
#define QS_CUR_MAP                   (INT)7
#define QS_CUR_LYNX		     (INT)8 
#define QS_LAST_WELLS_RETRIEVED      (INT)9
#define QS_LAST_SEISMIC_RETRIEVED    (INT)10 
#define QS_LAST_LEASE_RETRIEVED      (INT)11
#define QS_LAST_MAPS_RETRIEVED	     (INT)12
#define QS_LAST_LYNX_RETRIEVED	     (INT)13
#define QS_CUR_WELL_LIST            (INT)14 /*	N-list ID.		    */
#define QS_CUR_SEISMIC_LIST         (INT)15 /*	N-list ID.		    */
#define QS_CUR_LEASE_LIST           (INT)16 /*	N-list ID.		    */
#define QS_CUR_MAP_LIST             (INT)17 /*	N-list ID.		    */
#define QS_CUR_LYNX_LIST	    (INT)18
#define QS_SOURCE_NAME		    (INT)19 /* Name of current data source */
#define QS_MAP_PROJECTION           (INT)21
#define QS_WORKSTATION_NAME         (INT)22
#define QS_TERMINAL_TYPE            (INT)23
#define QS_UOM_INIT                 (INT)24
#define QS_DATABASE                 (INT)26
#define QS_MAP_DEVICE               (INT)28 /*	"WORKSTATION" or "PLOTTER"  */
#define QS_DGI_ROOTNAME             (INT)29
#define QS_WORKSTATION_TYPE	        (INT)30 /*	RASTER TECH or GPX.	    */
#define QS_WORKSTATION_MAC_DEVICE   (INT)31 /*	Sun redirection of MAC I/O */
#define QS_ENVIRONMENT              (INT)32 /*  "SUN4", "SUN3", "VMS", "PRIMOS", etc. */
#define QS_LAST_GRAPHICS_RETRIEVED  (INT)33
#define QS_CUR_GRAPHIC_LIST	    (INT)34
#define QS_CUR_GRAPHIC		    (INT)35
#define QS_CUR_XS_LAYOUT            (INT)36 /* current cross section layout name */

#define MAXCINDEX 40

/******************************************************************************/

/* Integer state variables */

#define QS_IF_BATCH              (INT)0
#define QS_WELL_LIST_EXISTS      (INT)1
#define QS_SEISMIC_LIST_EXISTS   (INT)2
#define QS_LEASE_LIST_EXISTS     (INT)3
#define QS_MAP_LIST_EXISTS       (INT)4
#define QS_LYNX_LIST_EXISTS	 (INT)5
#define QS_OVERLAY_LIST_SIZE     (INT)6
#define QS_TABLET_TYPE           (INT)7 
#define QS_GRAPHIC_TERM          (INT)8
#define QS_USER_SKILL            (INT)9
#define GLOBAL_MENU_ID          (INT)10 
#define QS_CUR_MAP_NUMBER       (INT)11
#define QS_DIVIDE_BY_2          (INT)12
#define QS_ADD_1K               (INT)13
#define QS_ORACLE_VERSION       (INT)14
#define QS_CUR_WELL_COUNT       (INT)15 
#define QS_CUR_SEISMIC_COUNT    (INT)16
#define QS_CUR_LEASE_COUNT      (INT)17
#define QS_CUR_MAP_COUNT	(INT)18
#define QS_CUR_LYNX_COUNT	(INT)19
#define QS_ASPECT_LOCK		(INT)20
#define QS_GRAPHIC_LIST_EXISTS	 (INT)21
#define QS_CUR_GRAPHIC_COUNT	(INT)22

#define MAXIINDEX  30

/******************************************************************************/

/* Floating point state variables */

#define QS_DGI_XMIN (INT)0
#define QS_DGI_YMIN (INT)1
#define QS_DGI_SCALE_FACTOR (INT)2

#define MAXFINDEX 10

/******************************************************************************/

/* Pointer state variables */

#define MAXPINDEX 10

/******************************************************************************/

/* Character ARRAY state variables */

#define QS_MAP_NAME_LIST        (INT)0
#define QS_WELLS_ON_MAP_LIST    (INT)1
#define QS_SEISMIC_ON_MAP_LIST  (INT)2
#define QS_LEASE_ON_MAP_LIST    (INT)3
#define QS_MAPS_ON_MAP_LIST     (INT)4
#define QS_LYNX_ON_MAP_LIST     (INT)5
#define QS_GRAPHIC_ON_MAP_LIST  (INT)6


/* Integer ARRAY state variables */
#define QS_MAP_HILITE_OVERLAY        (INT)0
#define QS_MAP_WELL_HILITE_GROUP     (INT)1
#define QS_MAP_SEISMIC_HILITE_GROUP  (INT)2
#define QS_MAP_SEISMIC_PICKING_GROUP (INT)3

/* TYPE THE ROUTINES */

#if  USE_PROTOTYPES
extern BOOL qs_inq_c(INT index, CHAR *string, INT *length);
extern BOOL qs_set_c(INT index, CHAR *string, INT length);
extern BOOL qs_inq_f(INT index, FLOAT *value);
extern BOOL qs_set_f(INT index, DOUBLE value);
extern BOOL qs_inq_i(INT index, INT *value);
extern BOOL qs_set_i(INT index, INT value);
extern BOOL qs_inq_p(INT index, BYTE **value);
extern BOOL qs_set_p(INT index, BYTE *value);
extern INT  qs_set_array_c(INT array_id, INT index, CHAR *value, INT slen);
extern INT  qs_set_array_i(INT array_id, INT index, INT value);
extern INT  qs_set_array_f(INT array_id, INT index, DOUBLE value);
extern INT  qs_set_array_d(INT array_id, INT index, DOUBLE value);
extern INT  qs_set_array_p(INT array_id, INT index, BYTE *value);
extern INT  qs_inq_array_c(INT array_id, INT index, CHAR *value, INT *slen);
extern INT  qs_inq_array_i(INT array_id, INT index, INT *value);
extern INT  qs_inq_array_f(INT array_id, INT index, FLOAT *value);
extern INT  qs_inq_array_d(INT array_id, INT index, DOUBLE *value);
extern INT  qs_inq_array_p(INT array_id, INT index, BYTE **value);
#else
extern BOOL qs_inq_c();
extern BOOL qs_set_c();
extern BOOL qs_inq_f();
extern BOOL qs_set_f();
extern BOOL qs_inq_i();
extern BOOL qs_set_i();
extern BOOL qs_inq_p();
extern BOOL qs_set_p();
extern INT  qs_set_array_c();
extern INT  qs_set_array_i();
extern INT  qs_set_array_f();
extern INT  qs_set_array_d();
extern INT  qs_set_array_p();
extern INT  qs_inq_array_c();
extern INT  qs_inq_array_i();
extern INT  qs_inq_array_f();
extern INT  qs_inq_array_d();
extern INT  qs_inq_array_p();
#endif

/* QS data types defined */
#define QS_INT_TYPE (INT)0
#define QS_FLOAT_TYPE (INT)1
#define QS_DOUBLE_TYPE (INT)2
#define QS_POINTER_TYPE (INT)3
#define QS_CHAR_TYPE (INT)4

#endif
