/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL.H*/
/* *12   25-OCT-1990 12:12:16 GILLESPIE "(SPR 31) Lint run - correct some casting inconsistencies"*/
/* *11   14-AUG-1990 11:49:48 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *10   17-MAR-1990 19:05:37 PURNA "(SPR 5095) add init text_nlist & line_nlist"*/
/* *9    17-MAR-1990 12:58:46 PURNA "(SPR 0) undo last mods"*/
/* *8    16-MAR-1990 11:11:45 PURNA "(SPR 5135) create nlz_strip_points"*/
/* *7    14-FEB-1990 10:36:55 GILLESPIE "(SPR 6005) Make window clip a method"*/
/* *6     9-NOV-1989 14:00:46 GORDON "(SPR 5058) update prototypes after resampling changes"*/
/* *5    12-OCT-1989 09:46:44 GILLESPIE "(SPR 44) Changes for n-List methods"*/
/* *4    24-SEP-1989 23:01:57 GILLESPIE "(SPR 200) New n-List Version 4"*/
/* *3    15-SEP-1989 13:39:59 GORDON "(SPR 100) Add nl_read_nlist_exclusive to non-prototypes stuff"*/
/* *2    27-JUL-1989 22:44:46 GILLESPIE "(SPR 1) n-List methods initial release"*/
/* *1    30-JUN-1989 15:03:18 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Exploration Systems, Inc. 1989                          */
/*                    Unpublished -- All rights reserved                            */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY   */
/*CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE      */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*                            Exploration Systems                                   */
/*                            c/o Finder Graphics Systems                           */
/*                            201 Tamal Vista Blvd.                                 */
/*                            Corte Madera, CA  94925                               */
/*                            (415) 927-0100                                        */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_NL_H

#define ESI_NL_H 1

#ifndef ESI_DTYPES_H

#include "esi_dtypes.h"

#endif

#ifndef ESI_NL_METHODS_H

#include "esi_nl_methods.h"

#endif

/* Application programmers get a blind pointer - NL routines get the full boat      */

#ifndef NL_INTERNAL
typedef char *NLIST_HEADER;
#endif
typedef CHAR NLIST_ID[64];

/* ====== these are used by NL_INIT_NLIST ======                                    */

#define VALUE_LIST (INT)113
#define INCREMENT_LIST (INT)114

/* ====== these are used by NL_SORT_NLIST ======                                    */

#define NL_ASCENDING (INT)115
#define NL_DESCENDING (INT)116

/* ====== these flag bits are ANDed together and returned ======                    */

#define NL_START_OF_LIST      (INT)2
#define NL_START_OF_TABLE    (INT)4
#define NL_END_OF_LIST        (INT)8
#define NL_END_OF_TABLE      (INT)16
#define NL_EOL                (INT)64
#define NL_START_OF_STROKE    NL_START_OF_TABLE
#define NL_END_OF_STROKE      NL_END_OF_TABLE

/* define the TYPE for stroke_info and nlist_info.                                  */
#define NL_NLIST_AVG                   (INT)1001
#define NL_NLIST_DATA_TYPES            (INT)1002
#define NL_NLIST_DATA_WIDTHS           (INT)1003
#define NL_NLIST_FIND_TOLERANCE        (INT)1004
#define NL_NLIST_MAX                   (INT)1005
#define NL_NLIST_MIN                   (INT)1006
#define NL_NLIST_NON_NULL              (INT)1007
#define NL_NLIST_NULL_VALUE            (INT)1008
#define NL_NLIST_STD_DEV               (INT)1009
#define NL_NLIST_UNITS                 (INT)1010
#define NL_NLIST_NUMERIC_FORMAT        (INT)1011
#define NL_NLIST_COLUMN_NAME           (INT)1012
#define NL_NLIST_VALUE_INC             (INT)1013
#define NL_TABLE_AVG                  (INT)1051
#define NL_TABLE_INCREMENT            (INT)1052
#define NL_TABLE_MAX                  (INT)1053
#define NL_TABLE_MIN                  (INT)1054
#define NL_TABLE_NON_NULL             (INT)1055
#define NL_TABLE_START_VALUE          (INT)1056
#define NL_TABLE_STD_DEV              (INT)1057
#define NL_TABLE_NROWS                (INT)1058
#define NL_TABLE_USER_STRUCT_LEN      (INT)1059
#define NL_TABLE_DATA_OFFSET          (INT)1060

/* define the OPCODEs for table_int and nlist_int.                                  */
#define NL_NLIST_BLOCKSIZE             (INT)1021
#define NL_NLIST_DEFERRED_STATS        (INT)1022
#define NL_NLIST_NCOL                  (INT)1023
#define NL_NLIST_NROWS                 (INT)1024
#define NL_NLIST_NTABLES               (INT)1025
#define NL_NLIST_USER_STRUCT_LEN       (INT)1026
#define NL_NLIST_DATA_CLASS            (INT)1027

/* define the OPCODEs for stroke_string and nlist_string.                           */
#define NL_NLIST_FILENAME   (INT)1031
#define NL_NLIST_NAME       (INT)1032
#define NL_NLIST_NEXT       (INT)1033
#define NL_NLIST_PREVIOUS   (INT)1034
#define NL_TABLE_NAME      (INT)1081

/* define the OPCODEs for nl_compare_list                                           */
#define NL_GT               (INT)2001
#define NL_LT               (INT)2002
#define NL_GE               (INT)2003
#define NL_LE               (INT)2004
#define NL_EQ               (INT)2005
#define NL_NE               (INT)2006
#define NL_AND              (INT)2007
#define NL_OR               (INT)2008
#define NL_XOR              (INT)2009
#define NL_NAND             (INT)2010
#define NL_NOR              (INT)2011

/* define the OPCODEs for nl_operate_list_1                                         */
#define NL_ABS              (INT)3001
#define NL_LOG10            (INT)3002
#define NL_LOGE             (INT)3003
#define NL_SIN              (INT)3004
#define NL_COS              (INT)3005
#define NL_TAN              (INT)3006
#define NL_ASIN             (INT)3007
#define NL_ACOS             (INT)3008
#define NL_ATAN             (INT)3009
#define NL_IDENTICAL        (INT)3010      /* internal opcode for nl_operate_nlist_2() */
        

/* define the OPCODE for nl_operate_list_2                                          */
#define NL_ADD              (INT)4001
#define NL_SUB              (INT)4002
#define NL_MULT             (INT)4003
#define NL_DIV              (INT)4004
#define NL_EXP              (INT)4005
#define NL_MOD              (INT)4006
#define NL_CRUSH_MIN        (INT)4007
#define NL_CLIP_MIN         (INT)4008
#define NL_CRUSH_MAX        (INT)4009
#define NL_CLIP_MAX         (INT)4010

/* ========= structure for nl_find_row =================                            */

typedef struct 
    {
    UINT row;
    UINT table;
    DOUBLE distance;
    } NLIST_FIND_LIST;

/* =============== V3 COMPATABILITY ======================                          */

#define NL_NLIST_DIM_NAME               NL_NLIST_COLUMN_NAME
#define NL_STROKE_AVG                   NL_TABLE_AVG
#define NL_STROKE_INCREMENT             NL_TABLE_INCREMENT
#define NL_STROKE_MAX                   NL_TABLE_MAX
#define NL_STROKE_MIN                   NL_TABLE_MIN
#define NL_STROKE_NON_NULL              NL_TABLE_NON_NULL
#define NL_STROKE_START_VALUE           NL_TABLE_START_VALUE
#define NL_STROKE_STD_DEV               NL_TABLE_STD_DEV
#define NL_STROKE_NPOINTS               NL_TABLE_NROWS
#define NL_STROKE_USER_STRUCT_LEN       NL_TABLE_USER_STRUCT_LEN
#define NL_STROKE_DATA_OFFSET           NL_TABLE_DATA_OFFSET
#define NL_STROKE_NAME                  NL_TABLE_NAME
#define NL_NLIST_NDIM                   NL_NLIST_NCOL
#define NL_NLIST_NPOINTS                NL_NLIST_NROWS
#define NL_NLIST_NSTROKES               NL_NLIST_NTABLES
#define nl_add_points                   nl_add_rows
#define nl_add_points_convert           nl_add_rows_convert
#define nl_convert_stroke_info          nl_convert_table_info
#define nl_copy_stroke                  nl_copy_table
#define nl_delete_points                nl_delete_rows
#define nl_delete_stroke                nl_delete_table
#define nl_draw_stroke                  nl_draw_table
#define nl_find_point                   nl_find_row
#define nl_first_point                  nl_first_row
#define nl_get_points                   nl_get_rows
#define nl_get_points_convert           nl_get_rows_convert
#define nl_inq_current_point            nl_inq_current_row
#define nl_inq_stroke_info              nl_inq_table_info
#define nl_inq_stroke_info_convert      nl_inq_table_info_convert
#define nl_inq_stroke_int               nl_inq_table_int
#define nl_inq_stroke_string            nl_inq_table_string
#define nl_inq_stroke_user_struct       nl_inq_table_user_struct
#define nl_insert_points                nl_insert_rows
#define nl_insert_points_convert        nl_insert_rows_convert
#define nl_last_point                   nl_last_row
#define nl_next_point                   nl_next_row
#define nl_pick_stroke                  nl_pick_row
#define nl_pick_stroke_range            nl_pick_row_range
#define nl_previous_point               nl_previous_row
#define nl_purge_stroke                 nl_purge_table
#define nl_replace_points               nl_replace_rows
#define nl_replace_points_convert       nl_replace_rows_convert
#define nl_set_current_point            nl_set_current_row
#define nl_set_stroke_info              nl_set_table_info
#define nl_set_stroke_int               nl_set_table_int
#define nl_set_stroke_string            nl_set_table_string
#define nl_set_stroke_user_struct       nl_set_table_user_struct
#define nl_sort_stroke                  nl_sort_table
#define nl_start_stroke                 nl_start_table

/************************************************************************************/

#if USE_PROTOTYPES
extern INT nl_add_rows (NLIST_HEADER nlist, UINT nrows, UINT nCol, UINT *Col_List,
                        VOIDPTR *Value_List);
extern INT nl_add_rows_convert (NLIST_HEADER nlist, UINT nrows, UINT nCol,
                                UINT *Col_List, VOIDPTR *Value_List, INT *Units,
                                size_t *DataWidths, INT *Data_Types);
extern INT nl_clean_file (FILENAME filename, DOUBLE percent);
extern INT nl_clear_nlist (NLIST_HEADER nlist);
extern INT nl_clone_nlist (NLIST_HEADER from_list, NLIST_HEADER *to_list);
extern INT nl_close_nlist_file (FILENAME filename);
extern INT nl_compare_nlist (NLIST_HEADER nlist1, UINT *Col_List1, INT opcode,
                             NLIST_HEADER nlist2, UINT *Col_List2,
                             NLIST_HEADER *nlist3);
extern INT nl_copy_nlist (NLIST_HEADER from_list, NLIST_HEADER *to_list);
extern INT nl_copy_table (NLIST_HEADER from_list, UINT from_table,
                          NLIST_HEADER to_list, UINT *to_table);
extern INT nl_delete_nlist (FILENAME filename, NLIST_ID name);
extern INT nl_delete_nlist_file (FILENAME filename);
extern INT nl_delete_nlist_method (NLIST_HEADER nlist, NLIST_METHOD method);
extern INT nl_delete_recover (FILENAME in_filename, NLIST_ID name);
extern INT nl_delete_rows (NLIST_HEADER nlist, UINT nrows);
extern INT nl_delete_table (NLIST_HEADER nlist, UINT table_num);
extern INT nl_draw_nlist (NLIST_HEADER nlist, UINT xCol, UINT yCol);
extern INT nl_draw_table (NLIST_HEADER nlist, UINT table_num, UINT xCol, UINT yCol);
extern INT nl_find_row (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                        FLOAT **Value_List);
extern INT nl_first_row (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                         VOIDPTR *Value_List);
extern INT nl_free_nlist (NLIST_HEADER nlist);
extern INT nl_get_rows (NLIST_HEADER nlist, UINT nallocated, UINT nCol, UINT *Col_List,
                        VOIDPTR *Value_List, UINT *nrows);
extern INT nl_get_rows_convert (NLIST_HEADER nlist, UINT nallocated, UINT nCol,
                                UINT *Col_List, VOIDPTR *Value_List, INT *Data_Units,
                                size_t *Data_Width, INT *Data_Type, UINT *returnPts);
extern INT nl_init_nlist (NLIST_HEADER *nlist, UINT nCol, INT *unit, size_t *size,
                          INT *type, INT *inc_value, UINT blocksize);
extern INT nl_init_text_nlist (NLIST_HEADER *nlist);
extern INT nl_init_line_nlist (NLIST_HEADER *nlist);
extern INT nl_inq_current_row (NLIST_HEADER nlist, UINT *current_row,
                               UINT *current_table);
extern INT nl_inq_file_user_struct (FILENAME in_filename, size_t nallocated,
                                    VOIDPTR user_struct_ptr, size_t *nbyte);
extern INT nl_inq_nlist_info (NLIST_HEADER nlist, INT type, UINT nCol, UINT *Col_List,
                              VOIDPTR *Value_List);
extern INT nl_inq_nlist_info_convert (NLIST_HEADER nlist, INT type, UINT nCol,
                                      UINT *Col_List, VOIDPTR *Value_List, INT *units,
                                      size_t *dataSize, INT *dataType);
extern INT nl_inq_nlist_int (NLIST_HEADER nlist, INT type, INT *value);
extern INT nl_inq_nlist_method (NLIST_HEADER nlist, NLIST_METHOD method,
                                NLM_FUNCTION_NAME function_name,
                                INT_FUNCTION_PTR *pfunction);
extern INT nl_inq_nlist_names (FILENAME filename, UINT *totalnames, TCP *names);
extern INT nl_inq_nlist_string (NLIST_HEADER nlist, INT opcode, size_t nallocated,
                                CHAR *string, size_t *nbytes);
extern INT nl_inq_nlist_user_struct (NLIST_HEADER nlist, size_t nallocated,
                                     VOIDPTR user_struct_ptr, size_t *nbytes);
extern INT nl_inq_table_info (NLIST_HEADER nlist, UINT table_num, INT type, UINT nCol,
                              UINT *Col_List, VOIDPTR *Value_List);
extern INT nl_inq_table_info_convert (NLIST_HEADER nlist, UINT table_num, INT type,
                                      UINT nCol, UINT *Col_List, VOIDPTR *Value_List,
                                      INT *units, size_t *dataSize, INT *dataType);
extern INT nl_inq_table_int (NLIST_HEADER nlist, UINT table_num, INT type, INT *value);
extern INT nl_inq_table_string (NLIST_HEADER nlist, UINT table_num, INT type,
                                size_t nallocated, CHAR *string, size_t *nbytes);
extern INT nl_inq_table_user_struct (NLIST_HEADER nlist, UINT table_num,
                                     size_t nallocated, VOIDPTR user_struct_ptr,
                                     size_t *nbytes);
extern INT nl_insert_rows (NLIST_HEADER nlist, UINT nrows, UINT nCol, UINT *Col_List,
                           VOIDPTR *Value_List);
extern INT nl_insert_rows_convert (NLIST_HEADER nlist, UINT nrows, UINT nCol,
                                   UINT *Col_List, VOIDPTR *Value_List,
                                   INT *Data_Units, size_t *Data_Widths,
                                   INT *Data_Types);
extern INT nl_invoke_nlist_method (NLIST_HEADER nlist, NLIST_METHOD method,
                                   VOIDPTR parm);
extern INT nl_last_row (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                        VOIDPTR *Value_List);
extern INT nl_next_row (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                        VOIDPTR *Value_List);
extern INT nl_operate_nlist_1 (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                               INT opcode, NLIST_HEADER maskList, UINT *maskCol,
                               NLIST_HEADER *outList);
extern INT nl_operate_nlist_2 (NLIST_HEADER nlist1, UINT nCol, UINT *Col_List1,
                               INT opcode, NLIST_HEADER nlist2, UINT *Col_List2,
                               NLIST_HEADER maskList, UINT *maskCol,
                               NLIST_HEADER *outList);
extern INT nl_pick_row (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                        DOUBLE *Value_List[], DOUBLE *min, DOUBLE *max,
                        NLIST_HEADER *row_nList);
extern INT nl_pick_row_range (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                              DOUBLE *Value_List[], DOUBLE *min, DOUBLE *max,
                              UINT *table_num, UINT *row_num);
extern INT nl_previous_row (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                            VOIDPTR *Value_List);
extern INT nl_purge_nlist (NLIST_HEADER nlist);
extern INT nl_purge_table (NLIST_HEADER nlist, UINT table_num);
extern INT nl_read_file_bytes (FILENAME in_filename, INT offset,
                               VOIDPTR *returned_data, size_t *returned_bytes);
extern INT nl_read_nlist (NLIST_HEADER *nlist, FILENAME filename, NLIST_ID id);
extern INT nl_read_nlist_exclusive (NLIST_HEADER *nlist, FILENAME filename,
                                    NLIST_ID id);
extern INT nl_register_nlist_method (NLIST_METHOD method,
                                     NLM_FUNCTION_NAME function_name,
                                     INT_FUNCTION_PTR function);
extern INT nl_replace_rows (NLIST_HEADER nlist, UINT nrows, UINT nCol, UINT *Col_List,
                            VOIDPTR *Value_List);
extern INT nl_replace_rows_convert (NLIST_HEADER nlist, UINT nrows, UINT nCol,
                                    UINT *Col_List, VOIDPTR *Value_List, INT *Units,
                                    size_t *Data_Widths, INT *Data_Types);
extern INT nl_set_current_row (NLIST_HEADER nlist, UINT row_num, UINT table_num);
extern INT nl_set_file_user_struct (FILENAME filename, VOIDPTR pstruct, size_t nbytes);
extern INT nl_set_nlist_info (NLIST_HEADER nlist, INT type, UINT nCol, UINT *Col_List,
                              VOIDPTR *Value_List);
extern INT nl_set_nlist_int (NLIST_HEADER nlist, INT type, INT value);
extern INT nl_set_nlist_method (NLIST_HEADER nlist, NLIST_METHOD method,
                                NLM_FUNCTION_NAME function_name,
                                INT_FUNCTION_PTR function);
extern INT nl_set_nlist_string (NLIST_HEADER nlist, INT type, CHAR *value);
extern INT nl_set_nlist_user_struct (NLIST_HEADER nlist, VOIDPTR user_struct_ptr,
                                     size_t nbytes);
extern INT nl_set_table_info (NLIST_HEADER nlist, UINT table_num, INT opcode,
                              UINT nCol, UINT *Col_List, VOIDPTR *Value_List);
extern INT nl_set_table_int (NLIST_HEADER nlist, UINT table_num, INT opcode,
                             INT value);
extern INT nl_set_table_string (NLIST_HEADER nlist, UINT table_num, INT opcode,
                                CHAR *value);
extern INT nl_set_table_user_struct (NLIST_HEADER nlist, UINT table_num,
                                     VOIDPTR user_structure, size_t nbytes);
extern INT nl_sort_nlist (NLIST_HEADER inList, UINT nCol, UINT *Col_List,
                          INT *sortFlags, NLIST_HEADER *outList);
extern INT nl_sort_table (NLIST_HEADER nlist, UINT nCol, UINT *Col_List,
                          INT *sortFlags, NLIST_HEADER *outList);
extern INT nl_start_table (NLIST_HEADER nlist, UINT *table_num);
extern INT nl_update_nlist (NLIST_HEADER nlist);
extern INT nl_write_nlist (NLIST_HEADER nlist, FILENAME filename, NLIST_ID id);
extern INT nl_write_nlist_exclusive (NLIST_HEADER nlist, FILENAME filename,
                                     NLIST_ID id);

extern INT nlm_bilinear_nlist (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_draw_nlist (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_print_nlist (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_sort_nlist (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_spline_nlist (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_update_nlist (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_window_clip_break (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_window_clip_null (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_window_clip_poly (NLIST_HEADER nlist, VOIDPTR param);
extern INT nlm_write_nlist (NLIST_HEADER nlist, VOIDPTR param);

#else
extern INT nl_add_rows ();
extern INT nl_add_rows_convert ();
extern INT nl_clean_file ();
extern INT nl_clear_nlist ();
extern INT nl_close_nlist_file ();
extern INT nl_compare_nlist ();
extern INT nl_copy_nlist ();
extern INT nl_copy_table ();
extern INT nl_delete_nlist ();
extern INT nl_delete_recover ();
extern INT nl_delete_rows ();
extern INT nl_delete_table ();
extern INT nl_draw_nlist ();
extern INT nl_draw_table ();
extern INT nl_find_row ();
extern INT nl_first_row ();
extern INT nl_free_nlist ();
extern INT nl_get_rows ();
extern INT nl_get_rows_convert ();
extern INT nl_init_nlist ();
extern INT nl_init_line_nlist ();
extern INT nl_init_text_nlist ();
extern INT nl_inq_current_row ();
extern INT nl_inq_file_user_struct ();
extern INT nl_inq_nlist_info ();
extern INT nl_inq_nlist_info_convert ();
extern INT nl_inq_nlist_int ();
extern INT nl_inq_nlist_method ();
extern INT nl_inq_nlist_names ();
extern INT nl_inq_nlist_string ();
extern INT nl_inq_nlist_user_struct ();
extern INT nl_inq_table_info ();
extern INT nl_inq_table_info_convert ();
extern INT nl_inq_table_int ();
extern INT nl_inq_table_string ();
extern INT nl_inq_table_user_struct ();
extern INT nl_insert_rows ();
extern INT nl_insert_rows_convert ();
extern INT nl_invoke_nlist_method ();
extern INT nl_last_row ();
extern INT nl_next_row ();
extern INT nl_operate_nlist_1 ();
extern INT nl_operate_nlist_2 ();
extern INT nl_pick_row ();
extern INT nl_pick_row_range ();
extern INT nl_previous_row ();
extern INT nl_purge_nlist ();
extern INT nl_purge_table ();
extern INT nl_read_nlist ();
extern INT nl_read_nlist_exclusive ();
extern INT nl_register_nlist_method ();
extern INT nl_replace_rows ();
extern INT nl_replace_rows_convert ();
extern INT nl_set_current_row ();
extern INT nl_set_file_user_struct ();
extern INT nl_set_nlist_info ();
extern INT nl_set_nlist_int ();
extern INT nl_set_nlist_method ();
extern INT nl_set_nlist_string ();
extern INT nl_set_nlist_user_struct ();
extern INT nl_set_table_info ();
extern INT nl_set_table_int ();
extern INT nl_set_table_string ();
extern INT nl_set_table_user_struct ();
extern INT nl_sort_nlist ();
extern INT nl_sort_table ();
extern INT nl_start_table ();
extern INT nl_inq_nlist_names ();
extern INT nl_update_nlist ();
extern INT nl_write_nlist ();
extern INT nl_write_nlist_exclusive ();

extern INT nlm_bilinear_nlist ();
extern INT nlm_draw_nlist ();
extern INT nlm_print_nlist ();
extern INT nlm_sort_nlist ();
extern INT nlm_spline_nlist ();
extern INT nlm_update_nlist ();
extern INT nlm_window_clip_break ();
extern INT nlm_window_clip_null ();
extern INT nlm_window_clip_poly ();
extern INT nlm_write_nlist ();

#endif
#endif
