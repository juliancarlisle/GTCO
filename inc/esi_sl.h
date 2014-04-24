/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SL.H*/
/*  13   13-FEB-1992 17:10:28 PURNA "(SPR 5101) added sl_exist_in_database function"*/
/* *12   18-MAR-1991 17:18:10 PURNA "(SPR 0) Lease Mapping Init Checkin"*/
/* *11   14-AUG-1990 11:51:06 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *10   30-JUL-1990 17:20:23 PURNA "(SPR 0) add lynx,lease select_list"*/
/* *9    18-JUN-1990 12:40:34 PURNA "(SPR 0) add new sl_data_type"*/
/* *8     8-FEB-1990 11:52:00 WALTERS "(SPR 0) Add prototype for sl_inq_slist_names"*/
/* *7     6-FEB-1990 13:16:14 MING "(SPR 0) change date declaration to new data type DATE_TIME"*/
/* *6     4-DEC-1989 14:05:28 PURNA "(SPR 0) make slz_get_key_column publicdef"*/
/* *5    31-OCT-1989 11:54:24 GILLESPIE "(SPR 30) Remove extraneous includes in includes"*/
/* *4    30-OCT-1989 15:59:54 PURNA "(SPR 5039) seismic select list mod"*/
/* *3    11-AUG-1989 20:25:24 CONROY "(SPR 0) Install revised seismic selects & picking"*/
/* *2    18-JUL-1989 14:22:10 GORDON "(SPR 100) Add mods from Sun port"*/
/* *1    30-JUN-1989 15:04:16 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SL.H*/
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1989
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

#ifndef ESI_SL_H
#define ESI_SL_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

/* Version number of this structure */
#define SELECT_VERSION 1

typedef CHAR SELECT_KEY_STRING[64];	/*defines the size of the first dim. */
					/* select list.			     */
typedef CHAR SELECT_KEY_STRING2[32];	/*defines the size of the fourth dim. */
					/* select list.			     */
typedef CHAR SL_DATA_TYPE_NAME[32];

/* Select list data types */

#define SL_MAX_DATA_TYPES 4

typedef enum {
	WELLS_DATA_TYPE = 1,
	SEISMIC_DATA_TYPE,
	LYNX_DATA_TYPE,
	LEASE_DATA_TYPE,
	NULL_DATA_TYPE
	} SL_DATA_TYPE;

typedef struct select_struct
{
/* Required parameters */
    INT version_of_select;
    NLIST_ID name;
    ANALYST_NAME account_name;
    PROJECT_NAME project_name;
    INT current_item;
    SL_DATA_TYPE data_type;
    DATE date_created;
    DATE expiration_date;
/* For relational retrieval */
    TABLE_NAME parent_file;
    CHAR select_phrase[256];
    TABLE_NAME control_list;
    
/* Housekeeping */
    BOOL permanent_flag;
    BOOL edited_flag;
    BOOL saved_in_project;
    
/* Highlighting information */
    BOOL connected_flag;
    INT window_id;
    INT transform_id;
    INT segment_id;
    COLOR_INDEX color;
    INT symbol;
    INT width;
    ENTRYNAME  symbol_set;
    DOUBLE size;
    DOUBLE line_width;

/* User supplied description */
    CHAR description[240];
    
    BYTE expansion[100];  /* bogus space for later consumption */

} SELECT_STRUCT;

typedef struct sl_method_header {
    SL_DATA_TYPE data_type;
    CHAR  function_name[32];
    INT_FUNCTION_PTR function;
    } SL_METHOD_HEADER;    

typedef struct sl_dtype_header {
    SL_DATA_TYPE data_type;
    SL_DATA_TYPE_NAME name;
    } SL_DTYPE_HEADER;

typedef struct sl_domain_header {
    SL_DATA_TYPE data_type;
    INT domain;
    } SL_DOMAIN_HEADER;
    
typedef struct sl_or_load_struct
    {
    CHAR unique_name[64];
    NLIST_HEADER nlist;
    } SL_OR_LOAD_STRUCT;

typedef struct sl_feed_nl_struct
{
    INT null_control;
    INT null_sql;
    COLUMN_NAME key_column;
    CHAR *table_name;
    CHAR *sql_phrase;            
    NLIST_ID name;
    NLIST_HEADER nlist;
    }SL_FEED_NL_STRUCT;
/* Function declarations */

#if USE_PROTOTYPES
extern INT slz_init_well_sl (NLIST_HEADER *select_list);
extern INT slz_init_seismic_sl (NLIST_HEADER *select_list);
extern INT slz_init_lynx_sl (NLIST_HEADER *select_list);
extern INT slz_init_lease_sl(NLIST_HEADER *select_list);
extern INT sl_choose_list(SL_DATA_TYPE data_type, NLIST_HEADER *select_list);
extern INT sl_fill_select_structure(SL_DATA_TYPE data_type, 
	NLIST_HEADER select_list);
extern INT sl_init_select_list(SL_DATA_TYPE data_type, 
	NLIST_HEADER *select_list);
extern INT sl_inq_slist_names(CHAR *data_type,TCP *ptcp,INT *nitems);
extern INT sl_make_tcp(TCP *ptcp, NLIST_HEADER nlist, INT dim);
extern INT sl_read_list(SL_DATA_TYPE data_type, NLIST_ID select_list_name,
	NLIST_HEADER *select_list);
extern INT sl_save_list(NLIST_HEADER select_list, INT overwrite_flag);
extern INT sl_select(NLIST_HEADER control_list, TABLE_NAME table_name,
        CHAR *sql_phrase, NLIST_HEADER *select_list, INT *num_items);
extern INT sl_select_description(NLIST_HEADER select_list);
extern INT sl_feed_well_nl(SL_FEED_NL_STRUCT *sl_struct);
extern INT sl_feed_seis_nl(SL_FEED_NL_STRUCT *sl_struct);
extern INT sl_feed_lynx_nl(SL_FEED_NL_STRUCT *sl_struct);
extern INT sl_feed_lease_nl(SL_FEED_NL_STRUCT *sl_struct);
extern INT sl_assign_data_type(CHAR *table_name,SL_DATA_TYPE *data_type);
extern INT sl_call_method(SL_DATA_TYPE data_type,CHAR *operator,VOIDPTR *param);
extern INT sl_get_data_type(SL_DATA_TYPE data_type,CHAR *data_type_name);
extern INT sl_get_temp_table_name(SL_DATA_TYPE data_type,CHAR *table_name);
#else

extern INT slz_init_well_sl ();
extern INT slz_init_seismic_sl ();
extern INT slz_init_lynx_sl ();
extern INT slz_init_lease_sl();
extern INT sl_choose_list();
extern INT sl_fill_select_structure();
extern INT sl_init_select_list();
extern INT sl_inq_slist_names();
extern INT sl_make_tcp();  /* creates a table of character ptrs from an n-List */
extern INT sl_save_list();
extern INT sl_read_list();
extern INT sl_select();
extern INT sl_select_description();
extern INT sl_feed_well_nl();
extern INT sl_feed_seis_nl();
extern INT sl_feed_lynx_nl();
extern INT sl_feed_lease_nl();
extern INT sl_call_method();
extern INT sl_get_data_type();
extern INT sl_get_temp_table_name();
#endif

#endif
