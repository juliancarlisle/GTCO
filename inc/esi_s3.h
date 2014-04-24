/* DEC/CMS REPLACEMENT HISTORY, Element ESI_S3.H*/
/* *6    13-OCT-1990 00:33:58 GILLESPIE "(SPR 100) Moved from Ernie"*/
/*  3B1  13-OCT-1990 00:26:44 GILLESPIE "Updates from Ernie"*/
/* *5    20-AUG-1990 17:16:19 KEE "(SPR -1) fixing compile error at sun"*/
/* *4    14-AUG-1990 11:50:39 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *3    18-JUN-1990 12:01:15 GILLESPIE "(SPR 1) Changes to support IES data exchange"*/
/* *2    25-JUL-1989 19:27:19 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    30-JUN-1989 15:04:02 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_S3.H*/
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

#ifndef ESI_S3_H
#define ESI_S3_H 1

/* SEISMIC 3D INCLUDE FILE                                                          */

#ifndef ESI_SE_H
#include "esi_se.h"     /* to get GRID_3D definition */
#endif

#ifndef ESI_MM_H
#include "esi_mm.h"
#endif

#ifndef ESI_MP_H
#include "esi_mp.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_OV_H
#include "esi_ov.h"
#endif

#define S3_NULL (INT)99999
#define S3_ZZZZ (INT)99999
#define S3_NO_LOCATIONS
#define S3_CDP (INT)2
#define S3_LINE (INT)1
typedef struct 
    {                               /* seismic generic                              */
    LINE seismic_xline;             /* actual graphic line object                   */
    LINE seismic_yline;             /* actual graphic line object                   */
    TEXT seismic_xlabel1;           /* line name graphic text object 1              */
    TEXT seismic_xlabel2;           /* line name graphic text object 2              */
    TEXT seismic_ylabel1;           /* line name graphic text object 1              */
    TEXT seismic_ylabel2;           /* line name graphic text object 2              */
    SYMBOL shotpoint_xsymbol;       /* shotpoint graphic symbol object              */
    SYMBOL shotpoint_ysymbol;       /* shotpoint graphic symbol object              */
    TEXT shotpoint_label;           /* shotpoint label graphic text object          */
    TEXT zvalue_label;              /* zvalue label graphic text object             */
    BOOL draw_seismic_line;         /* boolean to draw connecting line              */
    BOOL draw_seismic_label;        /* boolean to draw line label;                  */
    BOOL draw_shotpoint_symbol;     /* boolean to draw shotpoint symbol             */
    BOOL draw_shotpoint_label;      /* boolean to draw shotpoint label              */
    BOOL horizon_only_on_drawn;     /* post data only on drawn lines                */
    BOOL exclusive_fault;           /* post data only at faults                     */
    BOOL do_scatter;                /* boolean to show scatter file use             */
    CHAR *xyzfile;                  /* scatter file name                            */
    BOOL xyzfile_append;            /* TRUE if an add to an existing file           */
    BOOL horizons_ok;               /* TRUE if so_hor_load returns SUCCESS          */
    CHAR source[80];                /* analyst source of pick                       */
    } S3_GENERIC;

typedef struct 
    {
    CHAR *horizon;                  /* seismic surface horizon                      */
    SHORT *horizon_array;           /* horizon array                                */
    INT first_cdp;                  /* first cdp in horizon array                   */
    INT last_cdp;                   /* last cdp in horizon array                    */
    INT cdp_inc;                    /* increment of cdps in horizon array           */
    INT icoef;                      /* interpret horizon coefficient                */
    INT version;                    /* version of horizon                           */
    BOOL post_at_fault;             /* boolean to draw fault throws                 */
    LINE fault_line;                /* fault line marks                             */
    TEXT fault_label;               /* fault label                                  */
    } S3_SURFACE;

typedef struct 
    {
    
    MAP_STRUCTURE *map;             /* current map GLOBAL workspace                 */
    INT data_source;                /* SO_INTERPRET or SO_SIS                       */
    NLIST_HEADER select_list;       /* select list of seismic lines                 */
    NLIST_HEADER cdp_nlist;         /* cdp , x, y nlist                             */
    NLIST_HEADER line_nlist;        /* line, x, y nlist                             */
    BOOL clipped;                   /* if line was clipped                          */
    OV_GENERIC generic;             /* generic data type structure                  */
    BOOL zzzz;                      /* flag to draw zzzz for data labels            */
    CHAR s3_current_survey[21];
    GRID_3D grid_3d;                /* s3 grid structure                            */
    
    /* missing items (as compared to SO_grid) include
        name
        xmax *not needed
        ymax *not needed
        x_node_size *not needed
        y_node_size *not needed
        ncol
        nrow
        null_value
        pointer to the array
    */
    S3_GENERIC seismic_generic;
    S3_SURFACE seismic_surface;
    
    struct 
        {
        INT x_trigger;
        INT y_trigger;
        INT s_trigger;
        TEXT shot_label_default;
        TEXT zvalue_default;
        CHAR shot_label_format[6];
        INT x_line_plot_incr;       /* option 21                                    */
        INT y_line_plot_incr;       /* option 31                                    */
        INT x_symb_line_plot_incr;  /* option 24                                    */
        INT y_symb_line_plot_incr;  /* option 34                                    */
        INT x_symb_incr;            /* option 28                                    */
        INT y_symb_incr;            /* option 38                                    */
        INT x_cdp_incr;             /* option 73                                    */
        INT y_cdp_incr;             /* option 83                                    */
        INT x_horiz_post_incr;      /* option 71                                    */
        INT y_horiz_post_incr;      /* option 81                                    */
        INT x_horiz_incr;           /* option 74                                    */
        INT y_horiz_incr;           /* option 84                                    */
        } disp_opt;
    
    } S3_STRUCT;

#if USE_PROTOTYPES
extern INT s3_calc_cdps_lines(GRID_3D *grid_3d, NLIST_HEADER *cdp_nlist,
                              NLIST_HEADER *line_nlist);
extern INT s3_draw_survey(S3_STRUCT *ps3);
extern INT s3_draw_symbols(S3_STRUCT *ps3, INT current, INT type);
extern INT s3_overlay(INT display_line);
extern INT s3_process_overlay(S3_STRUCT *ps3);
extern INT s3_process_survey(S3_STRUCT *ps3);
#else
extern INT s3_calc_cdps_lines();
extern INT s3_draw_survey();
extern INT s3_draw_symbols();
extern INT s3_overlay();
extern INT s3_process_overlay();
extern INT s3_process_survey();
#endif
#endif















