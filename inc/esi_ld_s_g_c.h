/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_S_G_C.H*/
/* *3    17-DEC-1990 16:31:01 MING "(SPR 6244) change prototype for ld_s_g_c_server"*/
/* *2    14-AUG-1990 11:48:33 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:01:59 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_S_G_C.H*/
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

#ifndef ESI_LD_S_G_C_H
#define ESI_LD_S_G_C_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

typedef struct
    {
    INT main;
    INT scatter;
    INT grid;
    INT contour;
    INT perspective;
    } LD_SGC_IDS;

typedef struct
    {
    FILENAME directory;
    TCP file_list;
    } LD_SGC_FILE_STRUCT;

typedef struct
    {
    LD_SGC_FILE_STRUCT scatter;
    LD_SGC_FILE_STRUCT grid;
    LD_SGC_FILE_STRUCT contour;
    LD_SGC_FILE_STRUCT perspective;
    } LD_SGC_LOAD_STRUCT;
    


#if USE_PROTOTYPES

extern INT ld_s_g_c_loader(INT id, INT item, BYTE *p);
extern INT ld_s_g_c_srvr(INT id, INT item, INT *p);
extern INT ld_scatter_srvr(INT id, INT item, BYTE *p);
extern INT ld_grid_srvr(INT id, INT item, BYTE *p);
extern INT ld_contour_srvr(INT id, INT item, BYTE *p);
extern INT ld_perspective_srvr(INT id, INT item, BYTE *p);
extern INT ldz_load_scatter_files(LD_SGC_FILE_STRUCT *file_struc, 
		    INT *selected, INT number, INT skip, CHAR *projection);
extern INT ldz_load_nlist_files(INT data_type, LD_SGC_FILE_STRUCT *file_struc,
						    INT *selected, INT number);

#else

extern INT ld_s_g_c_loader();
extern INT ld_s_g_c_srvr();
extern INT ld_scatter_srvr();
extern INT ld_grid_srvr();
extern INT ld_contour_srvr();
extern INT ld_perspective_srvr();
extern INT ldz_load_scatter_files();
extern INT ldz_load_nlist_files();

#endif


#endif
