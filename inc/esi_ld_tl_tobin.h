/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_TL_TOBIN.H*/
/* *3    26-JUL-1991 12:52:40 CHEW "(SPR 0) Added lat. and lon. direction variables."*/
/* *2    14-AUG-1990 11:48:35 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:02:01 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_TL_TOBIN.H*/
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

#ifndef	ESI_LD_TL_TOBIN_H
#define ESI_LD_TL_TOBIN_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#define TL_TOBIN_LOADER_DONE   (INT)48127
#define TL_LOAD_ALL_DATA           (INT)0
#define TL_LOAD_SELECTED_DATA      (INT)1
#define TL_DATA_LOC_NORTH	   "N"
#define TL_DATA_LOC_SOUTH          "S"
#define TL_DATA_LOC_EAST           "E"
#define TL_DATA_LOC_WEST           "W"
#define TOBIN_CDLG_ID              (INT)1

#define TOBIN_CODES_DEFINED       27
#define TOBIN_CODES_LOCATION      2

typedef struct {
      INT      dialog_id;
      FILENAME to_area;
      FILENAME disk_name;
      INT      load_type;
      INT      load_codes[TOBIN_CODES_DEFINED];
      INT      n_codes_to_load;
      CHAR     lon[TOBIN_CODES_LOCATION];
      CHAR     lat[TOBIN_CODES_LOCATION];
   } TL_STRUCT ;

typedef struct {
      CHAR *code_name;
      INT   code_code;
   } CODE_STRUCT ;

#endif
