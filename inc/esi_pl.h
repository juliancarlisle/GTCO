/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PL.H */
/*  8     3-MAR-1992 13:21:27 JILL "(SPR 0) Add #defines for GPD/LEAS LEGEND and LOGO" */
/* *7    13-JUN-1991 14:44:34 MING "(SPR 0) fix a boo-boo from last checkin" */
/* *6     6-JUN-1991 17:15:13 MING "(SPR 0) new plot file managment" */
/* *5     5-APR-1991 12:22:48 JESSIE "(SPR 0) add xs_spacing on pl_ase_win structure" */
/* *4    30-JAN-1991 10:00:42 MING "(SPR 6548) change well symbol legend" */
/* *3     7-DEC-1990 13:53:28 GILLESPIE "(SPR 1) Remove duplicate definition of PL_ACENTER" */
/* *2    15-OCT-1990 12:18:42 GILLESPIE "(SPR 1) Remove extra include files" */
/* *1    13-OCT-1990 17:54:34 GILLESPIE "Move from Ernie" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PL.H */
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1990
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
#ifndef ESI_PL_H
#define ESI_PL_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_TU_H
#include "esi_tu.h"
#endif

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_PF_H
#include "esi_pf.h"
#endif

/* ------------------------------------------ */
/* window type for structure PLOT_LOUT_WINDOW */
/* ------------------------------------------ */
#define  PL_MAP         0
#define  PL_XSECT       1
#define  PL_TTLBLK      2
#define  PL_INDEX_MAP   3
#define  PL_NORTH_ARROW 4
#define  PL_SCALE_BAR   5
#define  PL_WELL_LEGEND 6
#define  PL_METAFILE    7
#define  PL_EMPTY       8

/* --------- */
/* Zone type */
/* --------- */
#define PL_ZBELOW 0
#define PL_ZRIGHT 1
#define PL_ZABOVE 2
#define PL_ZLEFT  3

/* -------------- */
/* Alignment type */
/* -------------- */
#define PL_ATOP 0
#define PL_ABOTTOM 1
#define PL_ACENTER 2
#define PL_ALEFT 0
#define PL_ARIGHT 1

/* ----------- */
/* Border type */
/* ----------- */
#define PL_BNONE 0
#define PL_BFINE 1
#define PL_BBOLD 2
#define PL_BFINE_FINE 3
#define PL_BBOLD_FINE 4
#define PL_BFINE_BOLD 5
#define PL_BBOLD_BOLD 6
#define PL_BTRIPLE_FINE 7


/* --------------------------- */
/* structure for layout window */
/* --------------------------- */
typedef struct
  {
  INT window_type;              /* MAP, TITLE_BLOCK,LEGEND,XSECT.. */
  CHAR window_name[256];         /* mapdefname, ttlblk def name, xsec def ... */
  BOOL drop;                    /* drop flag to tell if the actual */
				/* size is smaller than the lower limit */
  DOUBLE max_width;             /* width of the window on the plot (no border)*/
  DOUBLE max_height;            /* height of the window */
  DOUBLE mini_width;            /* lower limit of the width */
  DOUBLE mini_height;           /* lower limit of the height */
  DOUBLE plot_width;            /* actual width of the window */ 
  DOUBLE plot_height;           /* actual height of the window */ 
  DOUBLE plot_margin;           /* actual margin of the winodw */  
  DOUBLE x;                     /* x coord. on the plot */
  DOUBLE y;                     /* y coord. on the plot respect to */
				/* lower left conrner of the window */
  DOUBLE margin;                /* margin of the window */
  DOUBLE ll_wcs_x;              /* wcs extent of the window */
  DOUBLE ll_wcs_y;              /* use mainly in index map */
  DOUBLE ur_wcs_x;
  DOUBLE ur_wcs_y;
  BOOL border;                  /* TRUE/FALSE */
  BOOL clip;                    /* clipping flag (implement in the future) */
  INT win_id;                   /* window id */
  INT tnr_id;                   /* transformation id */
  INT seg_id;                   /* segment id for interactive composer */
  INT sequence;                 /* sequence number inside the zone */
  INT alignment;                /* how window is place within the actual window */
  } PLOT_LAYOUT_WIN;

/* ------------------------- */
/* structure for layout zone */
/* ------------------------- */
typedef struct 
  {
  INT nwins;                    /* number of windows in the zone */
  DOUBLE shrink_factor;         /* shrink factor of the zone */
  DOUBLE white_space;           /* white space between windows in the zone */
  DOUBLE max_width;             /* the original width for the zone */
  DOUBLE max_height;            /* the original height for the zone */
  DOUBLE plot_width;            /* the actual width for the zone */
  DOUBLE plot_height;           /* the actual height for the zone */
  PLOT_LAYOUT_WIN win[10];      /* widow element for the zone */
  }  PLOT_LAYOUT_ZONE;

/* ------------------------ */
/* structure for the layout */
/* ------------------------ */
typedef struct
  {
  ORACLE_NAME layout_name;            /* layout name */
  INT border;                      /* 0 = no border */
  INT orientation;                 /* 0:horizontal superior, 1:vertical superior */
  DOUBLE width;                    /* width of the entire layout */
  DOUBLE height;                   /* height of the entire layout */ 
  DOUBLE text_factor;              /* scale factor for the text */
  DOUBLE margin;                   /* size of outer margin */
  UOM_NAME layout_unit;            /* user defined unit for the layout */
  INT win_id;                      /* window id */
  INT tnr_id;                      /* transformation id */
  PLOT_LAYOUT_ZONE zone[4];        /* zone */
  }  PLOT_LAYOUT;

/* ----------------------------- */
/* structure for the base window */
/* ----------------------------- */
typedef struct
  {
  INT type;              /* 0: for map; 1: for cross section */
  INT win_id;            /* window id */
  INT tnr_id;            /* transformation id */
  PATHNAME file;         /* data file name of the window */
  ORACLE_NAME name;         /* name of the window */
  DOUBLE x;              /* x coordinate for the window */
  DOUBLE y;              /* y coordinate for the window */
  DOUBLE width;          /* width of the window */
  DOUBLE height;         /* height of the window */
  DOUBLE ll_wcs_x;       /* wcs extent of the window */
  DOUBLE ll_wcs_y;
  DOUBLE ur_wcs_x;
  DOUBLE ur_wcs_y;
  DOUBLE scale;          /* scale for the window */
  UOM_NAME scale_uom;    /* uom for the window */
  CHAR projection[16]; /* projection if base window is map */
  INT xs_spacing;	/* xs space: CONST, CENTER, GAP */
  } PL_BASE_WINDOW;

/* --------------------------------- */
/* structure for well legend element */
/* --------------------------------- */
typedef struct
  {
  INT symbol;               /* symbol type */
  INT color;                /* symbol color */
  } WELL_LEGEND_ELT;

/* ------------------------------- */
/* typedef of the well legend list */
/* ------------------------------- */
#define MAX_WELL_SYMBOL 50

typedef WELL_LEGEND_ELT WELL_LEGEND_LIST[MAX_WELL_SYMBOL];

/* ------------------------------------ */
/* structure for the well legend column */
/* each column has 20 symbols the most  */
/* ------------------------------------ */
typedef struct
  {
  INT nelts;                   /* number of well symbol */
  DOUBLE max_len;              /* max len of the symbol description in the column */
  CHAR text[20][240];           /* description of the symbol */
  WELL_LEGEND_ELT elt[20];     /* 20 symbols */
  } WELL_LEGEND;


#if USE_PROTOTYPES
extern INT pl_add_well_symbol (INT symbol, INT color);
extern INT pl_draw_arrow (GKS_REAL width, GKS_REAL height);
extern INT pl_draw_bar (CHAR *name, CHAR* uom, GKS_REAL width, GKS_REAL height);
extern INT pl_draw_index_map (INT bw_type,CHAR *indexmap_name, DOUBLE width, 
                          DOUBLE height,DOUBLE x, DOUBLE y, DOUBLE plot_range);
extern INT pl_draw_map (PL_BASE_WINDOW *base_window);
extern INT pl_draw_ttlblk (PL_BASE_WINDOW *bw,CHAR *name, DOUBLE width,DOUBLE height);
extern INT pl_draw_well_symbol (DOUBLE width, DOUBLE height);
extern INT pl_draw_win (PLOT_LAYOUT *layout, PL_BASE_WINDOW *base_win, 
		         CHAR *plot_file,CHAR *plotfile_type);
extern INT pl_draw_xs (PL_BASE_WINDOW *base_window);
extern INT pl_init_well_symbol (void);
extern INT pl_place_win (PLOT_LAYOUT *layout, PL_BASE_WINDOW *base_window);
/*
extern INT pl_read_base_win (PL_BASE_WINDOW *base_window, PF_INFO *pf_info);
extern INT pl_read_layout (PLOT_LAYOUT *layout, CHAR *layout_name, INT bw_type);
extern INT pl_read_map (PL_BASE_WINDOW *base_window,PF_INFO *pf_info);
extern INT pl_read_xs (PL_BASE_WINDOW *base_window,PF_INFO *pf_info);
*/

#else

extern INT pl_add_well_symbol ();
extern INT pl_draw_arrow ();
extern INT pl_draw_bar ();
extern INT pl_draw_idxmp ();
extern INT pl_draw_map ();
extern INT pl_draw_ttlblk ();
extern INT pl_draw_well_symbol ();
extern INT pl_draw_win ();
extern INT pl_draw_xs ();
extern INT pl_init_well_symbol ();
extern INT pl_place_win ();
extern INT pl_read_base_win ();
extern INT pl_read_layout ();
extern INT pl_read_map ();
extern INT pl_read_xs ();
#endif

#endif
