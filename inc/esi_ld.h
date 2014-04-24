/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD.H */
/* *3    10-SEP-1991 07:41:53 KEE "(SPR -1) Add element into the structure" */
/* *2     1-MAY-1991 12:20:25 KEE "(SPR -1) Loader line scanner header file " */
/* *1     1-MAY-1991 12:17:00 KEE "Loader Scanner structure" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD.H */
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Finder Graphics Systems, Inc. 1989                      */
/*           Unpublished -- All rights reserved                                     */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND   */
/*MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE  */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*            Finder Graphics Systems, Inc.                                         */
/*            201 Tamal Vista Blvd                                                  */
/*            Corte Madera, CA  USA 94925                                           */
/*            (415) 927-0100                                                        */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_LD_H
#define ESI_LD_H 1

#ifndef ESI_STDIO_H
#include "esi_stdio.h"
#endif

#define LD_STMAX 256

#define LD_STRING 1
#define LD_INT 2
#define LD_DOUBLE 3

typedef struct ld_parm_struct 
{
  INT parmtype; /* 1 = STRING, 2 = INT, 3 = DOUBLE */
  union {
    INT ival;
    DOUBLE dbval;
    CHAR *cval;
  } parmval;
  INT num_digit; /* num of digit for double */
} LD_PARM_STRUCT;

typedef struct ld_scanner_in_struc
{
  BOOL fix_format; /* fix format flag */

  /* following variables for fix_format == TRUE */
  BOOL snowhite;
  BOOL string_only; /* get string only */
  INT  num_pair; /* number of start-end pair */
  INT  start[LD_STMAX];
  INT  end[LD_STMAX];

  /* following variables for fix_format == FALSE */
  CHAR seperator[LD_STMAX]; /* seperator chars */
  CHAR skip_char[LD_STMAX]; /* skip chars */
} LD_SCANNER_IN_STRUC;
  
typedef struct ld_scanner_struct
{
  LD_SCANNER_IN_STRUC in; /* in info */
  LD_PARM_STRUCT *out; /* out info */
  INT out_nitems; /* number of out items */
  CHAR line[LD_STMAX]; /* the line being processed */
  BOOL eof; /* end of file flag */
} LD_SCANNER_STRUCT;


#if USE_PROTOTYPES
extern INT ld_scan_line(FILE *spfile, LD_SCANNER_STRUCT *ld_scan);
extern INT ld_isdigitstr (CHAR *str);
extern INT ld_isfloatstr (CHAR *str);
#else
extern INT ld_scan_line();
extern INT ld_isdigitstr ();
extern INT ld_isfloatstr ();
#endif

#endif
