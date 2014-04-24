/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SO.H*/
/* *15    7-JUN-1991 09:59:20 MING "(SPR 0) change SEISMIC TIME to SEISMIC DATA"*/
/* *14    6-DEC-1990 11:16:25 PURNA "(SPR 6288) add line id option on line label annotation"*/
/* *13   29-SEP-1990 10:18:18 GILLESPIE "(SPR 1) Merge beta deltas"*/
/*  11B1 28-SEP-1990 18:00:06 GILLESPIE "Beta Deltas"*/
/* *12   17-SEP-1990 09:23:02 SCD "(SPR 0) Add first,last cdp parms to prototype for so_draw_horz_terminators."*/
/* *11    5-AUG-1990 13:07:30 SCD "(SPR 1) Add Pumroy mods to SO_STRUCT: sym_xy and enhanced_shot_label_option."*/
/* *10    1-AUG-1990 13:17:06 VINCE "(SPR 5615) updated for integer line id"*/
/* *9    26-JUL-1990 17:15:56 GILLESPIE "(SPR 1) Add deltas for horizon annotation"*/
/* *8     1-JUL-1990 12:30:17 GILLESPIE "(SPR 1) Add seismic_data_type generic entry to allow ANY surface type to be posted"*/
/* *7    30-JUN-1990 10:25:39 GILLESPIE "(SPR 1) change prototype for so_draw_fault_post"*/
/* *6    29-JUN-1990 19:01:05 GILLESPIE "(SPR 1) Changes for fault posting"*/
/* *5    31-OCT-1989 11:54:27 GILLESPIE "(SPR 30) Remove extraneous includes in includes"*/
/* *4    11-AUG-1989 20:26:11 CONROY "(SPR 0) Install revised seismic selects & picking"*/
/* *3    28-JUL-1989 18:04:45 CHARLIE "(SPR 0) add line label annotation option"*/
/* *2    25-JUL-1989 19:28:18 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    30-JUN-1989 15:04:19 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SO.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Finder Graphics Systems, Inc. 1990                      */
/*         Unpublished -- All rights reserved                                       */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND   */
/*MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE  */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*          Exploration Systems, Inc.                                               */
/*          c/o Finder Graphics Systems, Inc.                                       */
/*          201 Tamal Vista Blvd                                                    */
/*          Corte Madera, CA  USA 94925                                             */
/*          (415) 927-0100                                                          */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_SO_H
#define ESI_SO_H 1

/* seismic mapping (overlay and seismic line editor include file)                   */

/* AUTHOR: STEVE SPENCE                                                             */

#ifndef  ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_SE_H
#include "esi_se.h"
#endif

#ifndef ESI_MM_H
#include "esi_mm.h"
#endif

#ifndef ESI_OV_DEFS_H
#include "esi_ov_defs.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_BT_H
#include "esi_bt.h"
#endif

typedef enum 
    {
    SO_SEISMIC = 1, SO_SEISMIC_DEPTH, SO_SEISMIC_ISOCHRON, SO_SEISMIC_ISOPACH,
    SO_SEISMIC_MISTIE, SO_SEISMIC_DATA
    } SO_OVERLAY_TYPE;

#define SO_NULL         999999.0
#define SO_ZZZZ         888888.0
#define SO_INTERPRET         0
#define SO_SIS               1
#define SO_PERP              0
#define SO_PARA              1
#define SO_NOPARA            9
#define SO_NO_LOCATIONS   1234
#define SO_NO_LABEL 0
#define SO_LINE_ONLY 1
#define SO_LINE_SURVEY 2
#define SO_SURVEY_LINE 3
#define SO_ID_ONLY 4

typedef struct 
    {
    FLOAT *array;                   /* grid aray                                    */
    FILENAME velocity_filename;     /* name of grid file                            */
    UINT ncol;                      /* number of x nodes (columns)                  */
    UINT nrow;                      /* number of y nodes (rows)                     */
    FLOAT null_value;               /* null value of grid                           */
    FLOAT x_node_size;              /* size of an x node                            */
    COORD x_origin;                 /* x origin of grid                             */
    FLOAT xmax;                     /* max x value                                  */
    FLOAT y_node_size;              /* size of a y node                             */
    COORD y_origin;                 /* y origin of grid                             */
    FLOAT ymax;                     /* max y value                                  */
    } SO_GRID;

typedef struct 
    {
    DOUBLE bulk_shift;              /* correction value                             */
    CDP cdp_inc;                    /* cdp increment of arrays                      */
    CDP first_cdp;                  /* first cdp in in array                        */
    INT icoef;                      /* interpret horizon coefficient                */
    CDP last_cdp;                   /* last cdp in array                            */
    CHAR north_or_south[6];         /* direction of line                            */
    NLIST_HEADER nlist;             /* horizon nlist                                */
    } SO_TIE_STRUCT;

typedef struct 
    {
    CHAR shot_label_trigger[2];
    CHAR shot_symbol_trigger[2];
    CHAR zvalue_trigger[2];
    INT shot_label_value;
    INT shot_symbol_value;
    INT zvalue_value;
    } SO_TRIGGER;

typedef struct 
    {
    DOUBLE bulk_shift;              /* correction value                             */
    NLIST_HEADER cdp_xy;            /* cdp, x, y nlist                              */
    NLIST_HEADER sym_xy;            /* x,y nlist only at displayed shotpoints       */
    BOOL clipped;                   /* if line was clipped                          */
    FULL_LINE_NAME current_line;    /* Current line/survey names                    */
    INT data_source;                /* SO_INTERPRET or SO_SIS                       */
    DOUBLE datum;                   /* seismic datum of map                         */
    BOOL draw_fault_throw;          /* boolean to draw fault throws                 */
    TEXT fault_label;               /* fault label                                  */
    LINE fault_line;                /* fault line marks                             */
    OV_GENERIC generic;             /* generic data type structure                  */
    SO_GRID grid;                   /* so grid structure                            */
    VOIDPTR map;                    /* current map GLOBAL workspace                 */
    SO_OVERLAY_TYPE ov_type;        /* overlay type, SO_SEISMIC, SO_SEISMIC_DEPTH, etc  */
    VOIDPTR psx;                    /* Seismic line editor                          */
    SEIS_SURFACE_HDR seismic_surface;
    NLIST_HEADER select_list;       /* select list of seismic lines                 */
    BOOL zzzz;                      /* flag to draw zzzz for data labels            */
    
    struct 
        {                           /* seismic generic                              */
        BOOL do_scatter;            /* boolean to show scatter file use             */
        BOOL draw_endpoints_only;   /* boolean to connect only endpoints            */
        BOOL draw_seismic_label;    /* boolean to draw line label;                  */
        BOOL draw_seismic_line;     /* boolean to draw connecting line              */
        BOOL draw_shotpoint_label;  /* boolean to draw shotpoint label              */
        BOOL draw_shotpoint_symbol; /* boolean to draw shotpoint symbol             */
        BOOL draw_horz_terminator;  /* boolean to draw horizon endpoints            */
        BOOL enhanced_shot_label_option;    /* boolean to post precision text angles*/
        BOOL horizons_ok;           /* TRUE if so_hor_load returns SUCCESS          */
        INT line_label_annotation;  /* LINE, LINE_SURVEY, NONE                      */
        NLIST_HEADER scatter;       /* c file pointer for scatter data              */
        FILENAME scatter_filename;  /* scatter file name                            */
        TEXT seismic_label1;        /* line name graphic text object 1              */
        TEXT seismic_label2;        /* line name graphic text object 2              */
        LINE seismic_line;          /* actual graphic line object                   */
        TEXT shotpoint_label;       /* shotpoint label graphic text object          */
        SYMBOL shotpoint_symbol;    /* shotpoint graphic symbol object              */
        ANALYST_NAME source;        /* analyst source of pick                       */
        BOOL xyzfile_append;        /* TRUE if an add to an existing file           */
        TEXT zvalue_label;          /* zvalue label graphic text object             */
        SEIS_SURFACE_DATA_TYPE surface_data_type;   /* surface data type (SE_TIME by default)   */
        } seismic_generic;
    
    struct 
        {
        SEIS_SURFACE_HDR top_horizon;
        SEIS_SURFACE_HDR base_horizon;
        } seismic_interval;
    
    struct 
        {
        CHAR *datum_line_list;      /* name of datum line select list               */
        TEXT tie_label;             /* mistie time labels                           */
        TREEHEAD mistree;           /* b tree of lines and horizon nlists           */
        CHAR default_direction[6];  /* default north or south datum lines           */
        } seismic_mistie;
    
    struct 
        {
        CHAR connect_shot_points[2];    /* seis map disp opt oracle table           */
        INT data_label_int;
        INT data_label_int_offset;
        SYMBOL default_symbol;
        DOUBLE first_line_label_angle;
        INT first_line_label_paraperp;
        DOUBLE last_line_label_angle;
        INT last_line_label_paraperp;
        SO_TRIGGER line;
        INT ntrigger_last;
        SO_TRIGGER ov;
        DOUBLE shot_label_angle;
        TEXT shot_label_default;
        CHAR shot_label_format[6];
        INT shot_label_int;
        INT shot_label_int_offset;
        NLIST_HEADER shot_label_nlist;
        CHAR shot_label_nlist_id[33];
        INT shot_label_paraperp;
        INT shot_symbol_code;
        INT shot_symbol_int;
        INT shot_symbol_int_offset;
        BOOL use_map_data_lbl_parms;
        BOOL use_map_shot_lbl_parms;
        BOOL use_map_shot_sym_parms;
        TEXT zvalue_default;
        } disp_opt;
    
    struct 
        {
        INT fault_type;
        CHAR line_color[16];        /* seis fault disp opt oracle table             */
        CHAR line_style[16];
        CHAR line_thickness[16];
        DOUBLE max_throw;
        } fdisp_opt;
    } SO_STRUCT;

/* Definitions for Software Picking Structures                                      */

typedef struct 
    {
    UINT nallocated;
    UINT nused;
    INT *segment_id;
    FULL_LINE_NAME *line_name;
    } PICKABLE_SEISMIC;

typedef struct 
    {
    BOOL changed;
    NLIST_HEADER master_nlist;
    NLIST_HEADER temp_nlist;
    } SX_WORKSPACE;

typedef struct 
    {
    FULL_LINE_NAME line_name;
    INT segment_id;
    } SX_USER_STRUCT;

#if USE_PROTOTYPES
extern INT so_angpp_to_text (TEXT *ptext, DOUBLE angle, INT paraperp);
extern INT so_build_common_nlist (SO_STRUCT *pso, NLIST_HEADER *nlist);
extern INT so_check_label (SO_STRUCT *pso, CDP cdp, SP shotpoint, BOOL *sym, BOOL *lab,
                           BOOL *zval, BOOL *special);
extern INT so_check_shot (SO_STRUCT *pso, SP shot, CHAR *ovt, INT ovv, CHAR *lt,
                          INT lv, BOOL *ok);
extern INT so_depth_convert (SO_GRID *pgrid, COORD x, COORD y, DOUBLE datum,
                             DOUBLE time, DOUBLE *depth);
extern INT so_depth_convert_isopach (SO_GRID *pgrid, COORD x, COORD y, DOUBLE datum,
                                     INT time1, INT time2, DOUBLE *depth);
extern INT so_draw_data_labels (SO_STRUCT *pso, CDP *list, UINT npts);
extern INT so_draw_fault_posts (COORD iX, COORD iY, SEIS_HOR_PICK_TYPE iflag,
                                SEIS_SURFACE_NAME iname, COORD fX, COORD fY,
                                SEIS_HOR_PICK_TYPE fflag, SEIS_SURFACE_NAME fname,
                                DOUBLE fault_throw, DOUBLE charHeight);
extern INT so_draw_horz_terminators (SO_STRUCT *pso, CDP first, CDP last);
extern INT so_draw_label (SO_STRUCT *pso, COORD x, COORD y, DOUBLE zvalue,
                          SP shot_point, BOOL special, BOOL lab, BOOL zval);
extern INT so_draw_line_itself (SO_STRUCT *pso);
extern INT so_draw_seismic_line (SO_STRUCT *pso);
extern INT so_draw_shot_labels (SO_STRUCT *pso, CDP *list, UINT npts);
extern INT so_draw_shot_symbol (SO_STRUCT *pso, COORD x, COORD y);
extern INT so_draw_symbols (SO_STRUCT *pso, CDP *list, UINT npts);
extern INT so_explode (NLIST_HEADER nlist, NLIST_HEADER *newlist, DOUBLE bulk_shift);
extern INT so_explode_cdpxy (NLIST_HEADER nlist, NLIST_HEADER *newlist);
extern INT so_find_point (NLIST_HEADER nlist, CDP cdp);
extern INT so_float_cdpxy (NLIST_HEADER nlist, NLIST_HEADER *newlist);
extern INT so_get_ends (SO_STRUCT *pso, CDP *first_cdp, CDP *last_cdp, SP *first_sp,
                           SP *last_sp, INT *cdps_per_sp);
extern INT so_hor_load (SO_STRUCT *pso);
extern INT so_hor_read (FULL_LINE_NAME *name, CHAR *horizon, CHAR *source, INT version,
                        INT data_source, SHORT **ivect, CDP *first_cdp, CDP *last_cdp,
                        CDP *cdp_inc, INT *icoef);
extern INT so_interpolate_grid (SO_GRID *pgrid, COORD x, COORD y, DOUBLE *value);
extern INT so_line_load (SO_STRUCT *pso);
extern INT so_load_disp_opt (SO_STRUCT *pso);
extern INT so_loadf_disp_opt (SO_STRUCT *pso, CHAR *fault_code, CHAR *source_code);
extern INT so_load_grid (SO_STRUCT *pso);
extern INT so_make_cdp_list (CDP first_cdp, CDP last_cdp, SP first_sp,
                             INT cdps_per_shot, INT interval, INT offset, CDP **list,
                             UINT *npts);
extern INT so_overlay (INT display_line);
extern INT so_process_fault_posts (SO_STRUCT *pso);
extern INT so_process_line (SO_STRUCT *pso, BOOL segments, INT *segment);
extern INT so_process_mistie (SO_STRUCT *pso);
extern INT so_process_overlay (SO_STRUCT *pso, PICKABLE_SEISMIC **pick_seis);
extern INT so_process_shotpoints (SO_STRUCT *pso);
extern INT so_read_nlist (NLIST_HEADER *nlist, FULL_LINE_NAME *line, NLIST_ID id);
extern INT so_set_shotpoint_defaults (SO_STRUCT *pso);
extern INT so_special_shot_points (SO_STRUCT *pso, CDP first_cdp, CDP last_cdp,
                                   CDP **shot_sym_list, UINT *n_shot_syms);
extern INT so_tie_tree (SO_STRUCT *pso);
extern INT so_zvalue (SO_STRUCT *pso, CDP cdp, CDP cdp2, COORD x, COORD y,
                      DOUBLE *zvalue);

#else
extern INT so_angpp_to_text ();
extern INT so_build_common_nlist ();
extern INT so_check_label ();
extern INT so_check_shot ();
extern INT so_depth_convert ();
extern INT so_depth_convert_isopach ();
extern INT so_draw_data_labels ();
extern INT so_draw_fault_posts ();
extern INT so_draw_horz_terminators ();
extern INT so_draw_label ();
extern INT so_draw_line_itself ();
extern INT so_draw_seismic_line ();
extern INT so_draw_shot_labels ();
extern INT so_draw_shot_symbol ();
extern INT so_draw_symbols ();
extern INT so_explode ();
extern INT so_explode_cdpxy ();
extern INT so_find_point ();
extern INT so_float_cdpxy ();
extern INT so_get_ends ();
extern INT so_hor_load ();
extern INT so_hor_read ();
extern INT so_interpolate_grid ();
extern INT so_line_load ();
extern INT so_load_disp_opt ();
extern INT so_loadf_disp_opt ();
extern INT so_load_grid ();
extern INT so_make_cdp_list ();
extern INT so_overlay ();
extern INT so_process_fault_posts ();
extern INT so_process_line ();
extern INT so_process_mistie ();
extern INT so_process_overlay ();
extern INT so_process_shotpoints ();
extern INT so_read_nlist ();
extern INT so_set_shotpoint_defaults ();
extern INT so_special_shot_points ();
extern INT so_tie_tree ();
extern INT so_zvalue ();

#endif
#endif
