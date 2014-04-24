/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CP.H */
/* *8    16-SEP-1991 18:16:01 PURNA "(SPR 0) added well log trace update" */
/* *7    11-AUG-1991 18:11:56 VINCE "(SPR 1) Fixed bit flag map to start at bit 2" */
/* *6     9-AUG-1991 17:04:07 VINCE "(SPR -1) added more DTYPE defines for GeoShare" */
/* *5    11-JUN-1991 12:42:28 PURNA "(SPR 0) update user interface" */
/* *4     6-MAY-1991 13:31:00 PURNA "(SPR 0) data mover init change" */
/* *3    14-AUG-1990 11:46:38 GILLESPIE "(SPR 2001) Major realignment of include files" */
/* *2    14-JUN-1990 11:41:13 PURNA "(SPR 0) initial change" */
/* *1     7-DEC-1989 16:11:26 PURNA "export facility" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CP.H */
#ifndef ESI_CP_H
#define ESI_CP_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#define CP_WORKSPACE "CopyProject_Workspace"

/* this are used if table need to be updated after moving nlist and
   cartographic transformation is performed on the nlist */

#define NO_EXTENDS         0
#define CP_SEIS_XY_EXTENDS 1
#define CP_GRAPHIC_OBJECT_EXTENDS 2
#define CP_FAULT_TRACE_EXTENDS 3
#define CP_LYNX_OBJECTS_EXTENDS 4
#define CP_LYNX_ARCS_EXTENDS 5
#define CP_WELL_LOG_VERSION 6

/* These flag bits are to identify which datatypes are to be moved. */
/* NOTE:  Bit 1 { (INT)(1<<0) } is not used.                        */

#define CP_WELL_DTYPE			(INT)(1<<1) /*   2 */
#define CP_SEISMIC_DTYPE		(INT)(1<<2) /*   4 */
#define CP_LEASE_DTYPE			(INT)(1<<3) /*   8 */
#define CP_CULTURE_DTYPE		(INT)(1<<4) /*  16 */
#define CP_GRAPHIC_OBJECT		(INT)(1<<5) /*  32 */
#define CP_CODES_DTYPE			(INT)(1<<6) /*  64 */
#define CP_FAULT_TRACE_SET_DTYPE	(INT)(1<<7) /* 128 */
#define CP_LITHOSTRAT_CODE_LIST_DTYPE	(INT)(1<<8) /* 256 */
#define CP_ZONE_LIST_DTYPE		(INT)(1<<9) /* 512 */

#define CP_UPDATE_OPTION (INT)2

#define CP_NONE_OPTION 1
#define CP_SELECT_OPTION 2
#define CP_ALL_OPTION 3

#define CP_GEO_NO_CONST 0
#define CP_GEO_CUR_MAP 1
#define CP_GEO_TRGT_MAP 2
#define CP_GEO_SRC_MAP 3
#define CP_GEO_MAN_ENT 4
#define CP_GEO_SPEC 5

#define CP_FINDER_P 0
#define CP_EXT_APPL 1

#define MAX_EXT_PARAM 6

typedef CHAR CP_NAME_TYPE[32];

typedef struct
    {
    INT cp_main;
    INT cp_dest;
    INT cp_trans;
    INT cp_cntrl;
    INT cp_select;
    INT cp_geo1;
    INT cp_geo2;
    INT cp_save1;
    INT cp_save2;
    INT cp_ext;
    INT new_item;
    PROJECT_NAME source_name;
    INT culture_option;
        CP_NAME_TYPE culture_sl_name;
        INT culture_refine;
    INT seismic_option;
        CP_NAME_TYPE seismic_sl_name;
        INT seismic_refine;
    INT well_option;
        CP_NAME_TYPE well_sl_name;
        INT well_refine;
    INT go_option;
        INT go_refine;
    INT lease_option;
        CP_NAME_TYPE lease_sl_name;
        INT lease_refine;
    INT update_option;
    CP_NAME_TYPE trans_name;
        TCP trans_n;
    CP_NAME_TYPE sels_name;
        TCP sels_n;
    INT dests_type;
    CHAR ext_appl_arg[256];
    PROJECT_NAME dests_name;
        TCP dests_n;
    CP_NAME_TYPE map_projection;
        TCP map_p;
    INT geo_selection_type;
    DOUBLE ll_x,ll_y,ur_x,ur_y;
    } CP_STRUCT;

publicdef NLIST_ID cp_select_list_name;

#if USE_PROTOTYPES
extern INT cp_test_dtype(CP_STRUCT *pex, INT *ret_status);
extern INT cp_call_batch(CP_STRUCT *pex, INT *ret_status);
extern INT cp_get_project_projection(PROJECT_NAME project,
	    PROJECTION_ID projection);
extern INT cp_get_filename(char *row_id,PROJECT_NAME project,TABLE_NAME tname, 
	COLUMN_NAME cname, char *cvalue, FILENAME nl_dir, FILENAME nl_file, 
	NLIST_ID nl_id, UINT col[2]);
extern INT cp_upd_seis_extends(CHAR *nlist_file,CHAR *nlist_id,
			       DOUBLE ll_x, DOUBLE ll_y,
			       DOUBLE ur_x, DOUBLE ur_y);
#else
extern INT cp_test_dtype();
extern INT cp_call_batch();
extern INT cp_get_project_projection();
extern INT cp_get_filename();
extern INT cp_upd_seis_extends();
#endif

#endif








