/* DEC/CMS REPLACEMENT HISTORY, Element UK_WORK.H*/
/* *3    14-AUG-1990 11:53:03 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    22-SEP-1989 11:13:45 GILLESPIE "(SPR 101) Add Choix field - dunno why it got dropped..."*/
/* *1    30-JUN-1989 15:06:53 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element UK_WORK.H*/
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

#ifndef UK_WORK_H
#define UK_WORK_H 1

/*
**                                 INCLUDE FILES
*/
#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

/*
**                               DEFINITIONS
*/
#define PROGRAM_NAME     "UKOOA_LOADER"

/*
**                            DATA DECLARATIONS
*/
/* This definition stores information about the UKOOA data header records */
typedef struct
    {
    INT       dialog_id;     /* Custom dialog ID */
    INT       NumHeaderRec;  /* Number of header records */
    CHAR      Survey[20];    /* Survey */
    CHAR      ProjCode[20];  /* Projection Code */
    CHAR      *Values[20];   /* Ragged array of header information */
    } UKOOA_HEADER_STRUCT;


#define   NUMBER_OF_DATA_FIELDS    7

/* This definition stores information about the UKOOA data fields */
typedef struct
    {
    INT       dialog_id;     /* Custom dialog ID */
    INT       NumDataRec;    /* Number of data records */
    INT       Columns[NUMBER_OF_DATA_FIELDS+1][2];
    CHAR      *Values[NUMBER_OF_DATA_FIELDS+1];
    INT	      Choix[NUMBER_OF_DATA_FIELDS+1];
    BOOL      Standard;      /* Standard UKOOA data format? */
    INT       Selection;
    INT       StartingColumn;
    INT       EndingColumn;
    } UKOOA_FIELDS_STRUCT;

/* This definition stores information about the UKOOA Line Selection process */
typedef struct
    {
    INT       dialog_id;     /* Custom dialog ID */
    INT       NumBogusPts;
    BOOL      Selection;     /* TRUE  = Some lines; FALSE = All lines*/
    BOOL      Replacement;   /* TRUE  = Replace line; FALSE = Honor line */
    FILE      *fp;
    FILENAME  file_name;
    TCP       line_tcp;
    TCP       firstsp_tcp;
    TCP       lastsp_tcp;
    TCP       skip_tcp;
    INT       Line_Selected;
    } UKOOA_LINES_STRUCT;

/* This definition stores information about the UKOOA data file */
typedef struct
    {
    INT       dialog_id;     /* Custom dialog ID */
    INT       RecLen;        /* Length of records in file */
    INT       BFactor;       /* Number of records per read block */
    INT       NumRecords;    /* Number of records in file */
    FILE      *fp;           /* C functions file pointer */
    FILENAME  file_name;     /* Current file */
    CHAR      Buffer[2048];  /* Record loading buffer */
    } UKOOA_FILE_STRUCT;

/* This definition groups related structures into a workspace that can
     be referenced by a workspace pointer */
typedef struct
    {
    INT                 main_dialog_id;
    CHAR                Area[STMAX];        /* Storage Area */
    INT                 ControlCheck;       /* Bad dialog control reminder */
    CHAR                *Buffer20;
    FILE                *LineInfo_fp;
    FILENAME            LI_name;
    UKOOA_HEADER_STRUCT header;
    UKOOA_FIELDS_STRUCT fields;
    UKOOA_LINES_STRUCT  lines;
    UKOOA_FILE_STRUCT   file;
    LISTHEAD            line_ll;
    FILENAME            comi_file ;       /* name of the comi file to submit*/
    } UKOOA_WORKSPACE;

/* This definition defines the link list data used in lines selection */
typedef struct
    {
    CHAR      *line;
    CHAR      *firstsp;
    CHAR      *lastsp;
    CHAR      *skip;
    } LINE_LINK;

#if USE_PROTOTYPES
extern INT  ukooa_lines_analyze_flat_file(UKOOA_WORKSPACE *pukooa);
extern INT  ukooa_lines_reset_dialog(UKOOA_WORKSPACE *pukooa);
#else
extern INT  ukooa_lines_analyze_flat_file();
extern INT  ukooa_lines_reset_dialog();
#endif

#endif
