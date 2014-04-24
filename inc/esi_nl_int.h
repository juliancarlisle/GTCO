/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL_INT.H*/
/* *22   25-OCT-1990 12:12:25 GILLESPIE "(SPR 31) Lint run - correct some casting inconsistencies"*/
/* *21   14-AUG-1990 11:49:55 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *20   29-MAY-1990 12:06:47 GILLESPIE "(SPR 1) Add nlz_copy_structure function for copying user structures"*/
/* *19   29-APR-1990 20:04:18 CHARLIE "(SPR 1) Rekick esimake to ensure everybody in synch with changes here."*/
/* *18   18-APR-1990 11:23:18 GILLESPIE "(SPR 1) Change order of fields in nlist_header to insulate from memory overwrites"*/
/* *17    9-APR-1990 10:25:06 GILLESPIE "(SPR 1) Remove obsolete macros"*/
/* *16   22-MAR-1990 01:55:37 GILLESPIE "(SPR 1) Bogus character slipped by me on last checkin in NLZ_GET_CONVERT_VALUE"*/
/* *15   21-MAR-1990 17:59:06 GILLESPIE "(SPR 1) Add n_valid_rows to data_header"*/
/* *14   17-MAR-1990 12:58:53 PURNA "(SPR 0) undo last mods"*/
/* *13   16-MAR-1990 14:44:17 PURNA "(SPR 0) fix prev mods"*/
/* *12   16-MAR-1990 11:11:56 PURNA "(SPR 5135) create nlz_strip_points"*/
/* *11   16-MAR-1990 08:59:35 GILLESPIE "(SPR 1) Change a prototype to use TCP* instead of CHAR***"*/
/* *10   27-FEB-1990 09:10:09 GILLESPIE "(SPR 6010) Syntax corrections for Ultrix checkin"*/
/* *9    26-FEB-1990 19:07:24 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *8     9-FEB-1990 13:52:35 GILLESPIE "(SPR 6005) Move windowing functions to ag"*/
/* *7    28-NOV-1989 14:54:11 GORDON "(SPR 0) Add prototype for nlz_anti_alias_filter"*/
/* *6    12-OCT-1989 09:46:50 GILLESPIE "(SPR 44) Changes for n-List methods"*/
/* *5    25-SEP-1989 10:51:34 GILLESPIE "(SPR 200) Back out last change"*/
/* *4    25-SEP-1989 10:00:58 GORDON "(SPR 200) Add include of esi_nl_msg.h"*/
/* *3    24-SEP-1989 23:35:26 GILLESPIE "(SPR 200) New n-List Version 4 Table/Row Nomenclature change"*/
/* *2    27-JUL-1989 22:47:28 GILLESPIE "(SPR 1) Implementation of n-List methods"*/
/* *1    30-JUN-1989 15:03:23 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL_INT.H*/
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

/* symbols and type definitions of internal routines                                */
#ifndef ESI_NL_INT_H

#define ESI_NL_INT_H 1

#ifndef USEDUMP

#define NL_INTERNAL 1

#ifndef ESI_DTYPES_H

#include "esi_dtypes.h"

#endif

#ifndef ESI_NL_METHODS_H

#include "esi_nl_methods.h"

#endif

#ifndef ESI_NL_ERR_H

#include "esi_nl_err.h"

#endif

#ifndef ESI_VERSION_H

#include "esi_version.h"

#endif

#define NL_VERSION_3 "3.0"
#define NL_VERSION_4 "4.0"
#define NL_DEFAULT_BLOCKSIZE (INT)20
#define NL_DEFAULT_NULL -9999.9883
#define NL_ROUND_ERROR 0.001
#define NLIST_INIT 0X41512
#define NULL_TABLE ((TABLE_HEADER *)0)
typedef struct 
    {
    BOOL inc_value;                 /* (120) TRUE if incrementing; FALSE if values  */
    UINT n_valid_rows;              /* (204) number of valid (non-null) data rows   */
    /* in table                                                                     */
    DOUBLE start_value;             /* (210) starting value for incrementing        */
    /* column                                                                       */
    DOUBLE increment;               /* (211) increment for incrementing column      */
    DOUBLE min;                     /* (206) minimum value in table list            */
    DOUBLE max;                     /* (207) maximum value in list                  */
    DOUBLE sum_x;                   /* (208) sum of data values in table            */
    DOUBLE sum_x_squared;           /* (209) sum of square of data values           */
    BYTE *data;                     /* ptr to first byte of data area               */
    } DATA_HEADER;

typedef struct 
    {
    UINT nrows;                     /* (202) number of rows in table                */
    UINT nallocated;                /* # rows allocated                             */
    UINT n_value_cols;              /* Number of non-incrementing columns           */
    UINT record_offset;             /* (214) the offset of the first record of      */
    /* table data in the file.                                                      */
    size_t totalBytesInTable;       /*   (212) the total bytes, which are stored in */
                                    /* the file for this table.                     */
    enum 
        {
        NL_DATA_NOT_LOADED, NL_DATA_LOADED, NL_DATA_UPDATED
        } data_loaded;              /* status of data wrt data file                 */
    size_t user_struct_len;         /*  (201) Length of User Structure              */
    BOOL updated;                   /* 1 = table has been updated; 0 = not          */
    /* updated                                                                      */
    CHAR *name;                     /* (203) name for current table                 */
    VOIDPTR user_struct;            /* (201) Pointer to User Structure              */
    DATA_HEADER data_ptr[1];        /* Top of nCol pointer to data area             */
    } TABLE_HEADER;

typedef struct 
    {
    UINT header_offset;
    TABLE_HEADER *ptable;
    } TABLE_ELEMENT;

typedef struct 
    {
    INT unit;                       /* (109) Unit code                              */
    size_t data_size;               /* (111) size, in bytes, of each data element   */
    INT data_type;                  /* (110) Data type flag                         */
    BOOL inc_value;                 /* (120) default value for this column -        */
                                    /* can be over-ridden TRUE if incrementing;     */
                                    /* FALSE if values                              */
    UINT n_valid_rows;              /* (129)number of valid (non-null) data rows    */
    /* in entire column                                                             */
    DOUBLE tolerance;               /* (117) locate tolerance                       */
    DOUBLE min;                     /* (113) minimum value in this column           */
    DOUBLE max;                     /* (114) maximum value in this column           */
    DOUBLE sum_x;                   /* (115) sum of data values in nlist            */
    DOUBLE sum_x_squared;           /* (116) sum of square of data values           */
    DOUBLE null_value;              /* (108) Null value                             */
    CHAR convert_format[10];        /* (123) Format for numeric conversion.         */
    CHAR column_name[32];           /* (124) Name of this column.                   */
    } COLUMN_HEADER;

/* method definitions                                                               */

typedef struct nlist_method_struct
    {
    struct nlist_method_struct *next;   /* ptr to next function in list             */
    NLIST_METHOD method_id;         /* (128a) Identifier of method type             */
    NLM_FUNCTION_NAME function_name;    /* (128b) Text string name of function      */
    INT_FUNCTION_PTR function;      /* ptr to method to invoke                      */
    } NL_METHOD_HEADER;

typedef struct 
    {
    BOOL initialized;               /* Initialization flag                          */
    BOOL updated;                   /* TRUE if data rows added, but statistics deferred */
    BOOL defer_stats;               /* (122) 1 = defer statistics calculation until */
                                    /* inquires 0 = calculate immediately           */
    UINT nCol;                      /* (101) Number of columns                      */
    UINT total_rows;                /* (105) Total # of rows in plist               */
    UINT total_tables;              /* (107) Total # of tables in plist             */
    UINT current_table;             /* Current table #                              */
    UINT current_row;               /* Current row # in current table               */
    UINT n_value_cols;              /* Number of columns that are non-incrementing by default   */
    UINT blocksize;                 /* (112) allocation blocksize                   */
    UINT nallocated_tables;         /* Number of table elements allocated           */
    size_t user_struct_len;         /* (103) Length of User Structure               */
    INT nlist_data_class;           /* (125) The type defined externally by the     */
                                    /* user for the whole nlist, e.g, LOG_TRACE,    */
                                    /* SELECT_LIST,...                              */
    TABLE_HEADER *current_table_ptr;    /* ptr to current table structure           */
    TABLE_ELEMENT *table_elements;  /* (126)The array of all tables.                */
    TABLE_HEADER *deleted_tables;   /* ptr to deleted tables.                       */
    NL_METHOD_HEADER *method_list;  /* ptr to first n-List method                   */
    VOIDPTR user_struct;            /* (103) Pointer to User Structure              */
    CHAR *name;                     /* (102) name of this n-List                    */
    CHAR *data_filename;            /* name of file this n-List read from.          */
    CHAR *prev_nlist;               /* (121) name of previous n-List                */
    CHAR *next_nlist;               /* (104) name of next n-List                    */
    VERSION version;                /* (100) version number of this software        */
    DATE creation_date;             /* (119) date this nlist created                */
    COLUMN_HEADER info_ptr[1];      /*   top of table-independent data block        */
    /* array                                                                        */
    } NLIST_STRUCT, *NLIST_HEADER;

#ifndef ESI_NL_H

#include "esi_nl.h"

#endif

/* ****************************************************************************     */

#define TEST_LEVEL 10

#if (TEST_LEVEL > 1)

#define INIT_TEST(nlist) \
   if ((nlist) EQUALS (NLIST_HEADER)0) return NL_INVALID_POINTER;\
   else if ( (nlist)->initialized IS_NOT_EQUAL_TO NLIST_INIT) \
      return NL_NLIST_NOT_INITIALIZED;
        

#else

#define INIT_TEST(nlist)

#endif

#if TEST_LEVEL > 2

#define COLUMN_TEST(nlist, column) \
   if ((column) == 0 OR (column) > (nlist) -> nCol) \
      return NL_INVALID_COLUMN;


#else

#define COLUMN_TEST(nlist, column)

#endif

#if TEST_LEVEL > 2

#define TABLE_TEST(nlist, table_num) \
   if ((table_num) == 0 OR (table_num) > (nlist) -> total_tables) \
      return NL_INVALID_TABLE;


#else

#define TABLE_TEST(nlist, table_num)

#endif

#if TEST_LEVEL > 2

#define EMPTY_TEST(nlist) \
   if ( (nlist) -> total_rows == 0) return NL_EMPTY_NLIST;

#else

#define EMPTY_TEST(nlist)

#endif

#if TEST_LEVEL > 2

#define NROWS_TEST(nrows) \
   if ( (nrows) ==  0) return NL_INVALID_NROWS;

#else

#define NROWS_TEST(nrows)

#endif

/* ****************************************************************************     */

#if USE_PROTOTYPES
extern INT nlz_add_nulls (NLIST_HEADER nlist, UINT nrows, INT beforeCp);
extern INT nlz_aid_rows_convert (NLIST_HEADER nlist, UINT nrows, UINT nCol,
                                 UINT Col_List[], VOIDPTR *Var_List, INT Data_Units[],
                                 size_t *Data_Widths, INT *Data_Types,
                                 INT add_or_insert);
extern INT nlz_anti_alias_filter (NLIST_HEADER nlist, UINT nCol, UINT Col_List[],
                                  DOUBLE newIncr, UINT filterLen);
extern INT nlz_bi_linear_nlist (NLIST_HEADER nlist, UINT nCol, UINT Col_List[],
                                DOUBLE distance, NLIST_HEADER *outNlist);
extern INT nlz_check_start_inc (NLIST_HEADER nlist, UINT nCol);
extern INT nlz_compute_delete_stats (NLIST_HEADER nlist);
extern INT nlz_compute_nlist_stats (NLIST_HEADER nlist);
extern INT nlz_compute_row_stats (NLIST_HEADER nlist);
extern INT nlz_compute_table_stats (NLIST_HEADER nlist, UINT table_num);
extern INT nlz_convert_inc_2_real (NLIST_HEADER nlist);
extern INT nlz_copy_structure (VOIDPTR ptr_in, size_t len_in, VOIDPTR *ptr_out,
                               size_t *len_out);
extern INT nlz_delete_nulls (NLIST_HEADER nlist, UINT nCol, UINT Col_List[]);
extern INT nlz_extract_table (NLIST_HEADER nlist, UINT table_num, UINT nCol,
                              DOUBLE from, DOUBLE to);
extern INT nlz_fill_data_array (NLIST_HEADER nlist, UINT table_num, UINT nCol,
                                UINT Col_List[], DOUBLE startValue, DOUBLE increment,
                                UINT total_rows, DOUBLE *Var_List[]);
extern INT nlz_find_start_and_total (NLIST_HEADER nlist, UINT table_num, UINT nCol,
                                     DOUBLE increment, DOUBLE startValue[],
                                     UINT *total_rows);
extern INT nlz_get_current_row (NLIST_HEADER nlist, UINT nCol, UINT Col_List[],
                                VOIDPTR Var_List[]);
extern DOUBLE *nlz_get_double_array (NLIST_HEADER nlist, UINT nCol, INT *status);
extern FLOAT *nlz_get_float_array (NLIST_HEADER nlist, UINT nCol, INT *status);
extern INT nlz_get_index_value (NLIST_HEADER nlist, DOUBLE indexValue,
                                UINT Col_List[2], VOIDPTR value, BOOL returnDouble);
extern INT nlz_get_value (DATA_HEADER *pdata, COLUMN_HEADER *pinfo, UINT current_row,
                          DOUBLE *px);
extern INT nlz_inq_row_flag (NLIST_HEADER nlist);
extern INT nlz_load_data (NLIST_HEADER nlist);
extern INT nlz_merge_table (NLIST_HEADER nlist, UINT nCol, DOUBLE from, DOUBLE to);
extern INT nlz_move_data (VOIDPTR pbyte, INT type, size_t size, DOUBLE dValue);
extern INT nlz_replace_value (DATA_HEADER *pdata, COLUMN_HEADER *pinfo,
                              UINT current_row, DOUBLE *px);
extern TABLE_HEADER *nlz_read_table_header (NLIST_HEADER nlist,
                                            TABLE_ELEMENT *table_element);
extern TABLE_HEADER *nlz_set_table (NLIST_HEADER nlist, UINT table_num);
extern INT nlz_shell_sort_dim (UINT len, UINT indexA[], DOUBLE value[], INT order,
                               DOUBLE nullValue);
extern INT nlz_sort_dim (UINT len, UINT indexA[], DOUBLE *value, INT order,
                         COLUMN_HEADER *pinfo);
extern INT nlz_sort_rows (NLIST_HEADER nlist, TABLE_HEADER *ptable, UINT nCol,
                          UINT Col_List[], INT sortFlags[], UINT orderArray[]);
extern INT nlz_spline_nlist (NLIST_HEADER nlist, UINT nCol, UINT Col_List[],
                             DOUBLE resampleInc, NLIST_HEADER *outNlist);
extern INT nlz_update_table (NLIST_HEADER oldNlist, NLIST_HEADER newNlist, UINT nCol,
                             DOUBLE from, DOUBLE to);
extern INT nlz_update_valid_rows (NLIST_HEADER nlist, UINT nrows, UINT nCol,
                                  UINT Col_List[], VOIDPTR Var_List[]);

#else
extern INT nlz_anti_alias_filter ();
extern INT nlz_check_start_inc ();
extern INT nlz_compute_nlist_stats ();
extern INT nlz_compute_table_stats ();
extern INT nlz_compute_delete_stats ();
extern INT nlz_compute_row_stats ();
extern INT nlz_convert_inc_2_real ();
extern INT nlz_copy_structure ();
extern INT nlz_delete_nulls ();
extern INT nlz_get_current_row ();
extern DOUBLE *nlz_get_double_array ();
extern FLOAT *nlz_get_float_array ();
extern INT nlz_get_index_value ();
extern INT nlz_get_value ();
extern INT nlz_inq_row_flag ();
extern INT nlz_load_data ();
extern INT nlz_move_data ();
extern TABLE_HEADER *nlz_read_table_header ();
extern TABLE_HEADER *nlz_set_table ();
extern INT nlz_replace_value ();
extern INT nlz_shell_sort_dim ();
extern INT nlz_sort_dim ();
extern INT nlz_sort_rows ();
extern INT nlz_spline_nlist ();
extern INT nlz_update_valid_rows ();

#endif  /* USE_PROTOTYPES */

#ifdef applec
#ifdef MAKEDUMP

#pragma dump "mpw:esi_nl_int.mpw"

#endif
#endif

#else   /* USEDUMP */

#ifdef applec

#pragma load "mpw:esi_nl_int.mpw"

#endif
#endif  /* USEDUMP */
#endif  /* ESI_NL_INT_H */
