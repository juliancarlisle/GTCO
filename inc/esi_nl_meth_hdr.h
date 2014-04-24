/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL_METH_HDR.H */
/* *9    14-AUG-1990 11:50:12 GILLESPIE "(SPR 2001) Major realignment of include files" */
/* *8    25-MAR-1990 22:47:41 SCD "(SPR 1) Add drawing structure definition" */
/* *7    25-MAR-1990 08:52:17 GILLESPIE "(SPR 1) Add autopurge to window clipping method parameter" */
/* *6    17-MAR-1990 12:59:03 PURNA "(SPR 0) undo last mods" */
/* *5    16-MAR-1990 11:12:16 PURNA "(SPR 5135) create nlz_strip_points" */
/* *4    14-FEB-1990 10:37:12 GILLESPIE "(SPR 6005) Make window clip a method" */
/* *3     9-NOV-1989 14:00:13 GORDON "(SPR 5058) change opcode to filterLen" */
/* *2    12-OCT-1989 09:46:56 GILLESPIE "(SPR 44) Changes for n-List methods" */
/* *1    12-OCT-1989 09:35:21 GILLESPIE "n-List methods header file" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL_METH_HDR.H */
#ifndef ESI_NL_METH_HDR_H
#define ESI_NL_METH_HDR_H 1

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

typedef struct {				/* used by nlm_draw functions */
	VOIDPTR bundle_ptr;			/* INPUT - pointer to appropriate data type bundle struct */
	INT bundle_id;				/* INPUT - if bundle_ptr is NULL then get this bundle from DB */
	UINT x_column;				/* INPUT - use this column number for X */
	UINT y_column;				/* INPUT - use this column number for Y */
	BOOL auto_purge_flag;		/* INPUT - if TRUE, draw method allowed to purge strokes as drawn */
	} NLM_DRAW_HEADER;

typedef struct {				/* used by nlm_print functions */
	UINT nCol;
	UINT *Col_List;
	UINT first_table;
	UINT last_table;
	BOOL print_nlist_header;
	BOOL print_table_header;
	BOOL print_data;
	FILE *outFile;
	} NLM_PRINT_HEADER;
	
typedef struct {				/* Used by nlm_resample functions */
	UINT ncol;					/* INPUT */
	UINT *Col_List;				/* INPUT */
	DOUBLE resampleInc;			/* INPUT */
	INT filterLen;				/* INPUT */
	NLIST_HEADER outNlist;		/* OUTPUT */
	} NLM_RESAMPLE_HEADER;

typedef struct {				/* Used by nlm_sort functions */
	UINT ncol;					/* INPUT */
	UINT *Col_List;				/* INPUT */
	INT *sortFlags;				/* INPUT */
	NLIST_HEADER outNlist;		        /* OUTPUT */
	} NLM_SORT_HEADER;

typedef struct {				/* Used by nlm_write functions */
	FILENAME filename;
	NLIST_ID nlist_id;
	} NLM_ID_HEADER;

typedef struct {				/* Used by nlm_clip functions */
	UINT Col_List[2];			/* INPUT */
	DOUBLE minList[2];			/* INPUT */
	DOUBLE maxList[2];			/* INPUT */
	BOOL autopurge;				/* INPUT */
	NLIST_HEADER outNlist;		        /* OUTPUT */
	} NLM_CLIP_HEADER;

#endif
