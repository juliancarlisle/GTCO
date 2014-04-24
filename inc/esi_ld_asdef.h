/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_ASDEF.H*/
/* *3    14-AUG-1990 11:48:29 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    17-JAN-1990 21:20:40 GILLESPIE "(SPR 6001) Add esi_ll.h"*/
/* *1    30-JUN-1989 15:01:56 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_ASDEF.H*/
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

#ifndef ESI_LD_ASDEF_H
#define ESI_LD_ASDEF_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#define BUF_SIZE                  4096

#define QUIT_REQUESTED            (INT)7000
#define HEADER_BAD                (INT)7001
#define ASCII_FILE_NOT_FOUND      (INT)7003

#define HEADER_BLOCK_FOUND        (INT)7010
#define HEADER_BLOCK_NOT_FOUND    (INT)7011
#define DATA_BLOCK_FOUND          (INT)7012
#define DATA_BLOCK_NOT_FOUND      (INT)7013
#define DELIMITER_BLOCK_FOUND     (INT)7015
#define DELIMITER_BLOCK_NOT_FOUND (INT)7016
#define END_OF_FILE_BLOCK_FOUND   (INT)7017

#define FORMAT_BAD                (INT)7020
#define NOT_ENOUGH_TRACE_NAMES    (INT)7021

#define LOAD_REQUESTED            (INT)7030
#define SKIP_REQUESTED            (INT)7031
#define ABORT_REQUESTED           (INT)7032

#define ASCII_WORKSPACE           "ascii_workspace"
#define VERIFY_WORKSPACE          "verify_workspace"


/* GLOBAL VARIABLES */

typedef struct
{
    INT  factor;
    CHAR type;
    INT  width;
    INT  divisor;
} FS;

typedef struct
{
    INT type;
    union
    {
        INT   ival;
        FLOAT fval;
    } uval;
} DS;


typedef struct
{
    CHAR     buffer[BUF_SIZE+1];
    CHAR     *buffer_ptr;
    INT      eof_flag;
    INT      num_errors;
    FS       **format_structures;
    INT      number_ns_formats;
    INT      number_all_formats;
    LISTHEAD data_ll;
    DS       **data_records;
    INT	     tot_count;
    FLOAT    *curr_record;
    FLOAT    *bogus_record;
    FLOAT    *prev_record;
    NLIST_HEADER *nlist;
} PLS;

typedef struct
{
    UWI       uwi;                /* Unique well identifier.    */
    FLOAT     sample_incr;        /* Sample increment.          */
    INT       depth_column;       /* depth column               */
    LOG_UOM   depth_uom;          /* depth uom                  */
    FLOAT     null_value;         /* Default null value         */
    CHAR      *delimit;           /* Characters delimiting wells*/
    CHAR      *format;            /* FORTRAN like data format.  */
    TCP       trace_names;        /* Array of trace names.      */
    CHAR      *depth_trace;       /* Name of the depth col trace*/
    INT       err_limit;          /* Max errors before abort.   */
    FILE      *pf;                /* Pointer to open input file.*/
    FILENAME  ascii_file;         /* Name of the ASCII log file.*/
    LOG_SOURCE source;            /* Source for trace name.     */
    INT       status;             /* Process Status Codes here. */

    INT       file_id;            /* Dialog id of the file CDLG */
    INT       hdr1_id;            /* Dialog id for 1st hdr CDLG */
    INT       hdr2_id;            /* Dialog id for 2nd hdr CDLG */
    INT       message_id;         /* Dialog id for the msg CDLG */
    INT       units_button;       /* Currently pressed units.   */

    PLS       *ptrLOCAL;          /* Pointer to the Parser's Local Struct */
}    LD_LG_ASCII_STRUCT;

#if USE_PROTOTYPES

extern INT ld_lg_ascii_init_parser(LD_LG_ASCII_STRUCT *pstruct);
extern INT ld_lg_ascii_get_block_type(LD_LG_ASCII_STRUCT *pstruct);
extern INT ld_lg_ascii_skip_block(LD_LG_ASCII_STRUCT *pstruct);
extern INT ld_lg_ascii_read_headers(LD_LG_ASCII_STRUCT *pstruct);
extern INT ld_lg_ascii_verify_fmt(LD_LG_ASCII_STRUCT *pstruct);
extern INT ld_lg_ascii_load_data(LD_LG_ASCII_STRUCT *pstruct);

#else

extern INT ld_lg_ascii_init_parser();
extern INT ld_lg_ascii_get_block_type();
extern INT ld_lg_ascii_skip_block();
extern INT ld_lg_ascii_read_headers();
extern INT ld_lg_ascii_verify_fmt();
extern INT ld_lg_ascii_load_data();

#endif

#endif
