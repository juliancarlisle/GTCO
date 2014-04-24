/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XS_DEFS.H*/
/*  11   27-FEB-1992 13:16:24 JESSIE "(SPR 6180) TVD display"*/
/* *10   27-MAR-1991 13:37:46 KEE "(SPR -1) Cross Section bug fixing and enhancement for Canadian Hunter"*/
/* *9    17-AUG-1990 21:44:55 GILLESPIE "(SPR 5644) Add x,y scale bar origin - somehow dropped during last checkin"*/
/* *8    14-AUG-1990 11:52:25 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *7    29-MAR-1990 18:27:11 MING "(SPR 5173) GULF bug fix"*/
/* *6    18-JAN-1990 08:48:52 GILLESPIE "(SPR 6001) More changes for new well structs"*/
/* *5    17-JAN-1990 17:47:12 GILLESPIE "(SPR 6001) Small syntax booboos"*/
/* *4    17-JAN-1990 17:17:40 GILLESPIE "(SPR 6001) Changes to separate data from display attributes"*/
/* *3     2-NOV-1989 12:01:27 GILLESPIE "(SPR 31) Move esi_md_defs stuff to esi_xs_parse.h"*/
/* *2    14-SEP-1989 16:42:15 GORDON "(SPR 100) Gulf/Sun/Unix changes"*/
/* *1    30-JUN-1989 15:06:10 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XS_DEFS.H*/
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

#ifndef ESI_XS_DEFS_H
#define ESI_XS_DEFS_H 1

/************************************************************************************/
/*                                                                                  */
/*    Include file for Cross Section System (XS) definitions.                       */
/*                                                                                  */
/************************************************************************************/

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_LG_DEFS_H
#include "esi_lg_defs.h"
#endif

#ifndef ESI_WE_WELLS_H
#include "esi_we_wells.h"
#endif

#ifndef ESI_BT_H
#include "esi_bt.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#include "esi_xs_err.h"
#include "esi_xs_msg.h"

#define XS_MENUS_FILE     "xs_menus"
#define XS_CDLGS_FILE     "xs_cdlgs"
#define XS_WORKSPACE      "cross_section_workspace"
#define XS_PARAMS_TABLE   ".CROSS_SECTION_LAYOUTS"
#define LAST_DISPLAYED_LAYOUT     "$ESI LAST DISPLAYED"
#define NEW_LAYOUT                "$ESI NEW LAYOUT"
#define XS_STRUCT_VERSION (INT)2     /* bumped to 2 by julian may 12, 1988 */
/* *********** Define log interval and log measurment parameters ***********        */
#define SEL_TOTAL_INTERVAL  (INT)0          /* defines for selection of log */
#define SEL_BY_DEPTH        (INT)1          /* interval to be displayed    */
#define SEL_BY_TOP          (INT)2
#define SEL_BY_ZONE         (INT)3

#define MEASURED_DEPTH      (INT)0
#define TVD                 (INT)1
#define SUBSEA_ELEV         (INT)2
#define TIME                (INT)3

/* ************** Define trace scaling and resampling parameters ************       */
#define VALUE_SCALE         (INT)0
#define MIN_SCALE           (INT)1
#define MAX_SCALE           (INT)2

#define NO_THINNING         (INT)0
#define DECIMATION          (INT)1
#define SLOPE_CHANGE        (INT)2

/* *********** Define X section type and measurement parameters ************        */
#define XS_NO_DATUM         (INT)0
#define XS_STRUCTURAL       (INT)1
#define XS_STRATIGRAPHIC    (INT)2

#define XS_DISTANCE_SCALE   (INT)0
#define XS_RATIO_SCALE      (INT)1

#define XS_CENTIMETER_UNITS (INT)1
#define XS_INCH_UNITS       (INT)2

/* ********* Define parameters for stentence length of xs_section.     *****        */
#define XS_BUF_INC_LENGTH (INT)200
#define XS_MAX_BUF_LENGTH (INT)63000

/* ********* Define parameters for positioning of layouts on X-section *****        */
#define XS_CONSTANT_SPACED  (INT)0
#define XS_EDGE_SPACED      (INT)1
#define XS_CENTER_SPACED    (INT)2
#define LAYOUT_GAP          (INT)2   /* gap between wells for const. spacing*/
#define LEFT_MARGIN         (INT)2   /* left margin layout offset */
#define RIGHT_MARGIN        (INT)2   /* right margin layout offset */
#define SCALE_BAR_THICKNESS (INT)1   /* thickness of right-hand scale bar   */

/* ********* Define index value of header items    ***********************          */
#if 0
/* remember to change expression_codes verb = 'LOGPLOT_HEADER_ITEM' to
the following sequence if the following is being used */
#define XS_CLASS_ITEM (INT)1
#define XS_COMP_ITEM (INT)2
#define XS_COUNTY_ITEM (INT)3
#define XS_DRILLERS_TD_ITEM (INT)4
#define XS_ELEVATION_ITEM (INT)5
#define XS_LOG_TD_ITEM (INT)6
#define XS_OFFSHORE_BLOCK_ITEM (INT)7 
#define XS_OPERATOR_ITEM (INT)8
#define XS_PLATFORM_NAME_ITEM (INT)9 
#define XS_OWNER_ITEM (INT)10
#define XS_RIGREL_ITEM (INT)11 
#define XS_SHORT_NAME_ITEM (INT)12
#define XS_SPUD_ITEM (INT)13
#define XS_STATE_ITEM (INT)14
#define XS_STATUS_ITEM (INT)15
#define XS_UWI_ITEM (INT)16
#define XS_WATER_DEPTH_ITEM (INT)17
#define XS_NAME_ITEM (INT)18
#define XS_NUMBER_ITEM (INT)19
#else
#define XS_CLASS_ITEM (INT)1
#define XS_COMP_ITEM (INT)2
#define XS_COUNTY_ITEM (INT)3
#define XS_DRILLERS_TD_ITEM (INT)4
#define XS_ELEVATION_ITEM (INT)5
#define XS_LOG_TD_ITEM (INT)6
#define XS_OPERATOR_ITEM (INT)7
#define XS_OWNER_ITEM (INT)8
#define XS_SHORT_NAME_ITEM (INT)9
#define XS_SPUD_ITEM (INT)10
#define XS_STATE_ITEM (INT)11
#define XS_STATUS_ITEM (INT)12
#define XS_UWI_ITEM (INT)13
#define XS_WATER_DEPTH_ITEM (INT)14
#define XS_NAME_ITEM (INT)15
#define XS_NUMBER_ITEM (INT)16
#endif

/* define line types (may be oracle table) and track types                          */
#define NONE (INT)0
#define TICS (INT)1
#define LINES (INT)2

/* should be expanded to match oracle table or delete whole list                    */
#define DEPTH_TRACK (INT)1
#define LINEAR_TRACK (INT)2
#define LOG_TRACK (INT)3
#define TEXT_TRACK (INT)4
#define TIME_TRACK (INT)5
#define LOG_HDR_MAX_CHARS    (INT)40    /*max. chars. on a text line of hdr. block */
#define TITLE_BLK_WIDTH      (INT)8     /*hard code title block size (in inches)   */
#define TITLE_BLK_HEIGHT     (INT)5

/* Define constant used to indicate a null depth value                              */

#define HUGE_DEPTH 200000.0
typedef struct 
    {
    CHAR trace_name[11];
    CHAR line_color[11];
    CHAR line_thickness[7];
    CHAR line_style[11];
    CHAR xplot_reverse_scale_flag[9];
    CHAR lin_log_flag[4];
    FLOAT left;
    FLOAT right;
    FLOAT track_number;
    } LG_TRACE_DEFS;

/* To be replaced by General Title Block.                                           */
/* positioned on bottom right side of x-section                                     */
typedef struct 
    {
    FLOAT xorigin;                  /* origin, in user units, of the lower left hand */
    FLOAT yorigin;                  /* hand corner of the title block.              */
    FLOAT height;                   /* in user units                                */
    FLOAT width;                    /* in user units                                */
    FLOAT text_height;              /* text size for top 4 lines of text            */
    FLOAT text_width;
    CHAR line1[64];                 /* top 4 lines of text positioned one on top of */
    CHAR line2[64];                 /* the other                                    */
    CHAR line3[64];
    CHAR line4[64];
    CHAR line5[64];                 /* bottom 2 text strings, positioned side by side   */
    CHAR line6[64];                 /* so require a smaller text size.              */
    } TITLE;

typedef struct 
    {
    INT type;                       /* DEPTH_IN_DISTANCE, DEPTH_IN_TIME             */
    INT method;                     /* top to top, zone, etc.                       */
    DOUBLE top;                     /* depth                                        */
    DOUBLE base;                    /* depth                                        */
    INT specify_as;                 /* MD, SubSea, TVD.                             */
    CHAR top_select_phrase[128];    /* SQL phrase                                   */
    CHAR base_select_phrase[128];   /* SQL phrase                                   */
    DOUBLE top_offset;              /* user entered offset value                    */
    DOUBLE base_offset;             /* user entered offset value                    */
    CHAR zone_name[ZONESIZE];       /* user entered zone name                       */
    CHAR ztop_select_phrase[128];
    CHAR zbase_select_phrase[128];
    DOUBLE ztop_offset;             /* user entered offset                          */
    DOUBLE zbase_offset;            /* user entered offset                          */
    DOUBLE ltdm_data_top;           /* top of data to be requested of LTDM          */
    DOUBLE ltdm_data_base;          /* base of data to be requested of LTDM         */
    DOUBLE true_data_top;           /* actual tested data limits from d.b.          */
    DOUBLE true_data_base;          /* actual tested data limits from d.b.          */
    DOUBLE track_top;               /* top depth of all tracks.                     */
    DOUBLE track_base;              /* base depth of all tracks.                    */
    DOUBLE true_rel_top;            /* track_top relative to datum (if one)         */
    DOUBLE true_rel_base;           /* track_base relative to datum(if one)         */
    DOUBLE display_top;             /* track_top in requested units.                */
    DOUBLE display_base;            /* track_base in requested units.               */
    } LOG_INTERVAL;

typedef struct 
    {
    INT number;                     /* arbitrary trace number used as reference     */
    INT track_num;                  /* track number for this trace                  */
    INT tnr_id;                     /* xform that this trace was drawn under        */
    INT seg_id;                     /* id if segment that contains this trace       */
    INT pick_id;
    LOG_TRACE_NAME name;            /* full log trace name                          */
    FLOAT left;                     /* left value of trace                          */
    FLOAT right;                    /* right value of trace                         */
    /* user entered minimum of data, etc.                                           */
    /* min/max not valid for logarithmic scale                                      */
    CHAR            trace_units[16]; /* requested trace units */
    DOUBLE scale_yorigin;           /* sc.bar yorigin-ref. to Scale Blk origin      */
    INT left_flag;                  /* MIN_SCALE, MAX_SCALE or VALUE_SCALE          */
    INT right_flag;                 /* MIN_SCALE, MAX_SCALE or VALUE_SCALE          */
    LINE_ATTRIBUTE line;            /* trace graphics attributes                    */
    BOOL visible;                   /* is trace to be drawn                         */
    /*up from scale origin                                                          */
    DOUBLE y_scale_bar;             /* Referenced to scale block origin.            */
    BOOL visible_scale_bar;         /* does trace have scale bar                    */
    LOG_TRACE_STRUCT trace_struct;  /* log trace structure of n-list of trace
                                    data to be displayed                            */
    } LP_TRACE_STRUCT;

typedef struct 
    {
    INT type;                       /* LINE_TYPE, TIC_TYPE or NO_MARKS              */
    DOUBLE frequency;               /* in depth units.                              */
    LINE_ATTRIBUTE line;
    } MARKS;

typedef struct 
    {
    COLOR_INDEX color;
    BOOL text;                      /* display text boolean                         */
    } ANNOTATE;

typedef struct top_info
    {
    CHAR top[10];                   /* The short name of top.                       */
    LINE_ATTRIBUTE line;            /* Graphic attributes for top                   */
    TREEHEAD uwis;                  /* the btree of uwis.                           */
    INT seg_id;                     /* graphics segment.                            */
    INT visible;                    /* the visibility of top.                       */
    INT unused[2];                  /* for the future extension.                    */
    } TOP_INFO;

typedef struct 
    {
    INT left_type;                  /* LOG_TRACE, ZONE_VALUE or CONSTANT            */
    INT left_trace_number;
    LOG_TRACE_NAME left_trace;
    CHAR left_zone[ZONESIZE];       /* Zone name.                                   */
    CHAR left_variable[40];         /* Zone variable name.                          */
    FLOAT left_constant;
    INT right_type;
    INT right_trace_number;
    LOG_TRACE_NAME right_trace;
    CHAR right_zone[ZONESIZE];
    CHAR right_variable[40];
    FLOAT right_constant;
    COLOR_INDEX color;              /* color of fill pattern                        */
    FILL_AREA_INTERIOR_STYLE pattern; /* fill pattern number                          */
    } PATTERN_FILL;

typedef struct 
    {
    INT number;                     /* arbitrary track number                       */
    /* referenced in user units -                                                   */
    DOUBLE xorigin;                 /* Referenced to log plot origin.               */
    DOUBLE yorigin;                 /* Referenced to log plot origin.               */
    DOUBLE width;
    DOUBLE length;
    BOOL visible;                   /* draw track switch                            */
    INT type;                       /* depth, time, trace                           */
    LINE_ATTRIBUTE line;
    DOUBLE annotation_interval;     /*depth annotation interval                     */
    INT tnr_id;
    INT seg_id;
    INT pick_id;
    struct 
        {
        INT number;                 /* number of divisions                          */
        FLOAT start_value;          /* important for log scales                     */
        INT type;                   /* lines/tics                                   */
        LINE_ATTRIBUTE line;
        } divisions;
    MARKS primary;
    MARKS secondary;
    MARKS tertiary;
    ANNOTATE shows;                 /* probable text block                          */
    ANNOTATE cores;                 /* probably needs top and base depths           */
    ANNOTATE tests;
    ANNOTATE perfs;
    LISTHEAD shading;               /* Linked list of shading structures.           */
    /* probable polygons                                                            */
    } TRACK_STRUCT;

typedef struct 
    {
    INT window_id;                  /* id of the main xs window                     */
    INT tnr_id;                     /* id of main xs window xform                   */
    INT seg_id;                     /* segment for this entire layout               */
    INT group_id;                   /* The group id of this entire layout           */
    DOUBLE xorigin;                 /* LogPlot origin-lower left corner of          */
    DOUBLE yorigin;                 /* layout as located on x-section               */
    DOUBLE length;                  /* Layout dimensions (user units)               */
    DOUBLE width;
    
    DOUBLE xmin;                    /* Minimum x value. (not curr. used)            */
    DOUBLE ymin;                    /* Minimum y value. (not curr. used)            */
    
    LOG_INTERVAL interval;
    
    INT data_thinning;              /* None, Decimate, Slope.                       */
    INT decimate;
    DOUBLE delta_slope;
    
    struct 
        {                           /* Log header is at top of scale blk            */
        DOUBLE xorigin;             /* Referenced to LogPlot Origin                 */
        DOUBLE yorigin;             /* Referenced to LogPlot Origin                 */
        DOUBLE height;
        DOUBLE width;
        DOUBLE angle;
        DOUBLE text_height;
        BOOL visible;               /* is logheader data visible                    */
        BOOL visible_border;        /* is logheader border drawn                    */
        LINE_ATTRIBUTE line;
        INT tnr_id;                 /* Xform id for hdr drawing                     */
        INT seg_id;
        struct 
            {                       /* info to plot well symbol                     */
            DOUBLE x;               /* Referenced to Header Block origin            */
            DOUBLE y;               /* Referenced to Header Block origin            */
            DOUBLE size;
            COLOR_INDEX color;
            BOOL visible;
            INT tnr_id;
            } well_symb;
        INT total_items;            /* the total number of items in the             */
        /* item index array.                                                        */
        INT *items;                 /* the array of items index                     */
        LISTHEAD hdr_items;         /* Linked list of header items.                 */
        } log_hdr;
    
    struct 
        {                           /* Scale block is at top of tracks.             */
        DOUBLE xorigin;             /* Referenced to LogPlot Origin                 */
        DOUBLE yorigin;             /* Referenced to LogPlot Origin                 */
        DOUBLE height;
        LINE_ATTRIBUTE line;
        DOUBLE width;
        BOOL visible;
        INT tnr_id;
        INT seg_id;
        } scale_block;
    
    LISTHEAD tracks;                /* Linked List of tracks in LogPlot.            */
    LISTHEAD traces;                /* Linked list of lp_trace structures.          */
    
    INT last_trace_number;
    
    struct 
        {                           /* Text block is at base of tracks.             */
        DOUBLE xorigin;             /* Referenced to LogPlot Origin                 */
        DOUBLE yorigin;             /* Referenced to LogPlot Origin                 */
        DOUBLE height;
        DOUBLE width;
        LINE_ATTRIBUTE line;
        BOOL visible;
        INT tnr_id;
        INT seg_id;
        } text_block;
    WELL_STRUCT *pwell;
    } LAYOUT_STRUCT;

/* This is the system data structure.                                               */
typedef struct 
    {
    /*  Menu resource ids.                                                          */
    INT layout_menu_id;
    INT edit_menu_id;
    INT wells_menu_id;
    INT tops_menu_id;
    /*  CDLG resource ids.                                                          */
    INT msg_cdlg_id;
    
    INT uselast_cdlg_id;
    INT ret_layout_cdlg_id;
    INT save_layout_cdlg_id;
    INT saveas_layout_cdlg_id;
    INT delete_layout_cdlg_id;
    INT tblock_cdlg_id;
    INT type_cdlg_id;
    INT horiscale_cdlg_id;
    INT hdr_cdlg_id;
    INT dpthscal_cdlg_id;
    INT depthgrid_cdlg_id;
    INT depthconst_cdlg_id;
    INT top2top_cdlg_id;
    INT zonesel_cdlg_id;
    INT dataint_cdlg_id;
    INT trackdef_cdlg_id;
    INT tracesel_cdlg_id;
    INT traceattr_cdlg_id;
    INT shading_cdlg_id;
    INT annotate_cdlg_id;
    
    INT digitize_top_cdlg_id;
    INT display_top_cdlg_id;
    INT retrieve_top_cdlg_id;
    INT save_top_cdlg_id;
    
    BOOL tops_changed_since_save;   /* Flag to check upon termination.              */
    BOOL faults_changed_since_save; /* Flag to check upon termination.              */
    
    CHAR layout_name[44];
    BOOL changed_since_display;
    BOOL changed_since_save;        /* Flag to check upon termination.              */
    BOOL valid_well_list;           /* TRUE when a well list exists.                */
    BOOL search_project;            /* Used to build select list.                   */
    BOOL search_accounts;           /* Used to build select list.                   */
    
    BOOL quit_flag;                 /* Used by Save to branch correctly.            */
    
    BOOL review_all_switch;         /* for review all                               */
    
    BOOL tblock_in_use;             /* for review all                               */
    BOOL type_in_use;
    BOOL horiscale_in_use;
    BOOL hdr_in_use;
    BOOL dpthscal_in_use;
    BOOL depthgrid_in_use;
    BOOL depthconst_in_use;
    BOOL top2top_in_use;
    BOOL zonesel_in_use;
    BOOL dataint_in_use;
    BOOL trackdef_in_use;
    BOOL tracesel_in_use;
    BOOL traceattr_in_use;
    BOOL shading_in_use;
    BOOL annotate_in_use;
    
    INT xs_type;                    /* MD, STRAT, STRUCT                            */
    CHAR xs_datum_select[128];
    INT xs_spacing;                 /* CONST, CENTER, GAP                           */
    DOUBLE xs_scale;
    CHAR xs_scale_str[128];
    INT xs_scale_type;              /* dist/ratio                                   */
    INT xs_scale_user_units;        /* inch/cm flag                                 */
    CHAR xs_scale_map_units[11];    /* FEET, METERS                                 */
    INT xst_type;
    INT xst_spacing;
    DOUBLE xst_scale;
    
    INT xst_bold;
    DOUBLE xst_bold_intvl;
    INT xst_medium;
    DOUBLE xst_medium_intvl;
    INT xst_fine;
    DOUBLE xst_fine_intvl;
    INT xst_tracktype;
    DOUBLE xst_annotation_intvl;
    
    BOOL xst_tracesel_no_redraw;    /* TRUE if ADD or DEL traces.                   */
    BOOL xst_trackdef_no_redraw;    /* TRUE if ADD or DEL tracks.                   */
    
    DOUBLE depth_scale;
    CHAR depth_scale_str[128];
    INT depth_scale_user_units;     /* inch/cm flag                                 */
    CHAR depth_scale_map_units[11]; /* FEET/ INCH                                   */
    INT depth_display_as;           /* MD, SubSea, TVD.                             */
    
    TITLE title;
    
    TCP layout_name_tcp;
    TCP analyst_name_tcp;
    TCP project_name_tcp;
    TCP zone_list_tcp;
    TCP hdr_list_tcp;
    TCP track_number_tcp;
    TCP trace_name_tcp;
    TCP left_tcp;
    TCP right_tcp;
    TCP trace_units_tcp;
    TCP color_tcp;
    TCP thickness_tcp;
    TCP type_tcp;
    TCP marks_tcp;
    TCP numdiv_tcp;
    TCP width_tcp;
    TCP start_loc_tcp;
    FLOAT *fthickness_trans;
    NLIST_HEADER layers;            /* N-list of tops for modelling                 */
    NLIST_HEADER well_list;         /* N-list of UWI's.                             */
    
    LAYOUT_STRUCT *ptemp;           /* Scratch layout for dialog events.            */
    LAYOUT_STRUCT *plo;             /* Current layout for building display.         */
    
    LG_TRACE_DEFS lg_trace_defs;    /* trace def for oracle retrieve                */
    
    struct 
        {
        DOUBLE xorigin;             /* origin is at lower left corner of x-section at coordinate (0,0)         */
        DOUBLE yorigin;
        DOUBLE width;               /* all coordinates are in user units            */
        DOUBLE height;
        DOUBLE sc_bar_xorigin;      /* coordinates of lower left side of vertical scale bar (positioned on right hand side of x-section) */
        DOUBLE sc_bar_yorigin;      /* coordinates of lower left side of vertical scale bar (positioned on right hand side of x-section) */
        DOUBLE sc_bar_length;
        DOUBLE sc_upper_limit;      /* Depth/subsea for sc_bar_y + length.          */
        DOUBLE sc_lower_limit;      /* Depth/subsea for sc_bar_yorigin.             */
        INT tnr_id;
        INT window_id;
        LISTHEAD log_plots;         /* Linked list of resolved Layouts.             */
        LISTHEAD top_table;         /*LINKED LIST of retrieved tops.                */
        INT drawing_num;            /* counter is bumped for each drawing           */
        INT struct_version;         /* Version of this struct. (for dump)           */
        } drawing;
    INT xs_suppress_vbar;           /* suppress vertical scale bar flag */
    FLOAT temp_float;
    INT depth_interval_scale_units; /* FEET or METER.                               */
    INT track_width_scale_units;    /* INCHES or CENTIMETER.                        */
    CHAR temp_string[247];
    } XS_STRUCT;

/**************************************************************************************************/

#if USE_PROTOTYPES
extern INT xsz_add_bin_record(CHAR *layoutName, CHAR *verbName, CHAR *sentence,
                              CHAR *analyst);
extern INT xsz_add_header(XS_STRUCT *pxs, CHAR *layout_name);
extern INT xsz_add_interval(XS_STRUCT *pxs, CHAR *layout_name);
extern INT xsz_add_record(CHAR *layoutName, CHAR *verbName, CHAR *sentence);
extern INT xsz_add_scales(XS_STRUCT *pxs, CHAR *layout_name);
extern INT xsz_add_top(XS_STRUCT *pxs, CHAR *layout_name);
extern INT xsz_add_trace(XS_STRUCT *pxs, CHAR *layout_name);
extern INT xsz_add_track(XS_STRUCT *pxs, CHAR *layout_name);
extern INT xsz_add_cross_section(XS_STRUCT *pxs, CHAR *layout_name);
extern INT xsz_build_buffer(CHAR *layout, CHAR *verb, CHAR *oldBuf, INT oldBufLen,
                            INT availLen, INT incLen, CHAR *addStr, INT addStrLen,
                            CHAR **newBuf, INT *newBufLen, INT *totalAlloc,
                            INT maxBufLen, INT writeOut);
extern INT xsz_copy_layout(LAYOUT_STRUCT *plo, LAYOUT_STRUCT *pwlo);
extern INT xsz_copy_trace_info(LP_TRACE_STRUCT *p_source, LP_TRACE_STRUCT *p_copy);
extern INT xsz_copy_track_info(TRACK_STRUCT *p_source, TRACK_STRUCT *p_copy);
extern INT xsz_copy_track_marks(TRACK_STRUCT *p_source, TRACK_STRUCT *p_copy);
extern INT xsz_c_tlu(CHAR *table, INT code, TCP *name);
extern INT xsz_depth_scale_calc(XS_STRUCT *pxs);
extern INT xsz_determine_intvl(LAYOUT_STRUCT *p_layout);
extern INT xsz_digitize_top(XS_STRUCT *pxs, CHAR *sel_top);
extern INT xsz_display_tops(XS_STRUCT *pxs, DOUBLE min_char_height);
extern INT xsz_dump_bin_lyt(XS_STRUCT *pxs, FILENAME filename);
extern INT xsz_find_log_limits(LAYOUT_STRUCT *plo, DOUBLE *d_start, DOUBLE *d_end);
extern INT xsz_find_track(LAYOUT_STRUCT *p_layout, INT track_number,
                          TRACK_STRUCT **p_track);
extern INT xsz_free_top_table(XS_STRUCT *pxs);
extern INT xsz_horiz_scale_calc(XS_STRUCT *pxs);
extern INT xsz_init_struct(XS_STRUCT *pxs);
extern XS_STRUCT *xsz_load_bin_lyt(FILENAME filename);
extern INT xsz_make_tops_tcp(XS_STRUCT *pxs, TCP *tcp);
extern INT xsz_rtr_tops(TCP *tablePtr);
extern INT xsz_save_tops(XS_STRUCT *pxs, INT total_tops, INT *top_index);
extern INT xsz_set_tops_vis(XS_STRUCT *pxs, INT total_tops, TCP tops,
                            INT *selected_list);
extern INT xsz_strip_parens(CHAR *text);
extern INT xs_gr_vbar(XS_STRUCT *pxs);
extern INT xsz_well_distance(XS_STRUCT *pxs, LAYOUT_STRUCT *p_layout1,
                             LAYOUT_STRUCT *p_layout2, DOUBLE *distance);
extern INT xs_annotate_cdlg_init(XS_STRUCT *pxs);
extern INT xs_chg_drawing(XS_STRUCT *p_xsec);
extern INT xs_copy_well_info(XS_STRUCT *pxs);
extern INT xs_create_drawing(XS_STRUCT *pstruct);
extern INT xs_create_tracks(LAYOUT_STRUCT *sample_layout,
                            LAYOUT_STRUCT *copied_layout);
extern INT xs_cs_menu_mgr(XS_STRUCT *pxs);
extern INT xs_dataint_cdlg_init(XS_STRUCT *pxs);
extern INT xs_dellayout_cdlg_init(XS_STRUCT *pxs);
extern INT xs_depth_scale_cdlg_init(XS_STRUCT *pxs);
extern INT xs_dgz_tops_init(XS_STRUCT *pxs);
extern INT xs_display_cross_section(XS_STRUCT *pxs);
extern INT xs_dsp_tops_init(XS_STRUCT *pxs);
extern INT xs_free_hdr(LISTHEAD *hdr_items);
extern INT xs_free_struct(LISTHEAD *log_plots);
extern INT xs_free_curves(LISTHEAD *trace_items);
extern INT xs_free_track(LISTHEAD *track_items);
extern INT xs_gen_hdr_list(XS_STRUCT *pxs);
extern INT xs_gen_layout_list(XS_STRUCT *pxs);
extern INT xs_gen_trc_defs(XS_STRUCT *pxs);
extern INT xs_gen_zone_list(XS_STRUCT *pxs);
extern INT xs_get_layout(XS_STRUCT *pxs, CHAR *layout_name, CHAR *project,
                         CHAR *analyst_name);
extern INT xs_hdr_cdlg_init(XS_STRUCT *pxs);
extern INT xs_hdr_size(LAYOUT_STRUCT *p_layout);
extern INT xs_horizontal_cdlg_init(XS_STRUCT *pxs);
extern INT xs_logplot_size(LISTHEAD *lplot_head);
extern INT xs_logplot_width(LISTHEAD *lplot_head);
extern INT xs_main(VOIDPTR junk);
extern INT xs_newlayout_cdlg_init(XS_STRUCT *pxs);
extern INT xs_obj_dump(XS_STRUCT *pxs, FILENAME filename);
extern XS_STRUCT *xs_obj_load(FILENAME filename);
extern INT xs_put_layout(XS_STRUCT *pxs, CHAR *layoutName);
extern INT xs_resolve_layout(LISTHEAD *lplot_head);
extern INT xs_resolve_title(XS_STRUCT *p_xsec);
extern INT xs_retlayout_cdlg_init(XS_STRUCT *pxs);
extern INT xs_retrieve_hdr(LAYOUT_STRUCT *sample_layout, LAYOUT_STRUCT *copied_layout);
extern INT xs_retrieve_traces(LAYOUT_STRUCT *sample_layout,
                              LAYOUT_STRUCT *copied_layout);
extern INT xs_rtr_tops_init(XS_STRUCT *pxs);
extern INT xs_rtr_tops_when_redraw(XS_STRUCT *pxs);
extern INT xs_save_init(XS_STRUCT *pxs);
extern INT xs_sav_tops_init(XS_STRUCT *pxs);
extern INT xs_scale_blk_size(LAYOUT_STRUCT *p_layout);
extern INT xs_send_to_plotter(XS_STRUCT *pxs);
extern INT xs_shading_cdlg_init(XS_STRUCT *pxs);
extern INT xs_start_chg_all(XS_STRUCT *pxs);
extern INT xs_stop_chg_all(XS_STRUCT *pxs);
extern INT xs_struct_loc_wellx(XS_STRUCT *pxs);
extern INT xs_struct_loc_welly(XS_STRUCT *p_xsec);
extern INT xs_tblock_cdlg_init(XS_STRUCT *pxs);
extern INT xs_tdgz_info_server();
extern INT xs_term(XS_STRUCT *pxs);
extern INT xs_traceattr_cdlg_init(XS_STRUCT *pxs);
extern INT xs_tracesel_cdlg_init(XS_STRUCT *pxs);
extern INT xs_trackdef_cdlg_init(XS_STRUCT *pxs);
extern INT xs_type_cdlg_init(XS_STRUCT *pxs);
extern INT xs_uselast_cdlg_init(XS_STRUCT *pxs);
extern INT xs_we_dgz_traverse(XS_STRUCT *pxs);
extern INT xs_we_rtr_traverse(XS_STRUCT *pxs);
extern INT xs_we_save_traverse(XS_STRUCT *pxs);
extern INT xs_we_show_well_list(XS_STRUCT *pxs);
extern INT xs_we_use_cur_well(XS_STRUCT *pxs);
extern INT xs_we_use_cur_we_list(XS_STRUCT *pxs);

#else

extern INT xsz_add_bin_record();
extern INT xsz_add_header();
extern INT xsz_add_interval();
extern INT xsz_add_record();
extern INT xsz_add_scales();
extern INT xsz_add_top();
extern INT xsz_add_trace();
extern INT xsz_add_track();
extern INT xsz_add_cross_section();
extern INT xsz_build_buffer();
extern INT xsz_copy_layout();
extern INT xsz_copy_trace_info();
extern INT xsz_copy_track_info();
extern INT xsz_copy_track_marks();
extern INT xsz_c_tlu();
extern INT xsz_depth_scale_calc();
extern INT xsz_determine_intvl();
extern INT xsz_digitize_top();
extern INT xsz_display_tops();
extern INT xsz_dump_bin_lyt();
extern INT xsz_fill_data();
extern INT xsz_fill_linterval();
extern INT xsz_fill_lh();
extern INT xsz_fill_ls();
extern INT xsz_fill_lsb();
extern INT xsz_fill_lws();
extern INT xsz_fill_ltop();
extern INT xsz_fill_ltrace();
extern INT xsz_fill_ltrack();
extern INT xsz_fill_xs();
extern INT xsz_find_log_limits();
extern INT xsz_find_track();
extern INT xsz_free_top_table();
extern INT xsz_get_parms();
extern INT xsz_horiz_scale_calc();
extern INT xsz_init_struct();
extern XS_STRUCT *xsz_load_bin_lyt();
extern INT xsz_make_tops_tcp();
extern INT xsz_rtr_tops();
extern INT xsz_save_tops();
extern INT xsz_set_tops_vis();
extern INT xsz_strip_parens();
extern INT xs_gr_vbar();
extern INT xsz_vld_ovrly();
extern INT xsz_well_distance();
extern INT xs_annotate_cdlg_init();
extern INT xs_chg_drawing();
extern INT xs_copy_well_info();
extern INT xs_create_drawing();
extern INT xs_create_tracks();
extern INT xs_cs_menu_mgr();
extern INT xs_dataint_cdlg_init();
extern INT xs_dellayout_cdlg_init();
extern INT xs_depth_scale_cdlg_init();
extern INT xs_dgz_tops_init();
extern INT xs_display_cross_section();
extern INT xs_dsp_tops_init();
extern INT xs_free_hdr();
extern INT xs_free_struct();
extern INT xs_free_curves();
extern INT xs_free_track();
extern INT xs_gen_hdr_list();
extern INT xs_gen_layout_list();
extern INT xs_gen_trc_defs();
extern INT xs_gen_zone_list();
extern INT xs_get_layout();
extern INT xs_hdr_cdlg_init();
extern INT xs_hdr_size();
extern INT xs_horizontal_cdlg_init();
extern INT xs_logplot_size();
extern INT xs_logplot_width();
extern INT xs_main();
extern INT xs_newlayout_cdlg_init();
extern INT xs_obj_dump();
extern XS_STRUCT *xs_obj_load();
extern INT xs_put_layout();
extern INT xs_resolve_layout();
extern INT xs_resolve_title();
extern INT xs_retlayout_cdlg_init();
extern INT xs_retrieve_hdr();
extern INT xs_retrieve_traces();
extern INT xs_rtr_tops_init();
extern INT xs_rtr_tops_when_redraw();
extern INT xs_save_init();
extern INT xs_sav_tops_init();
extern INT xs_scale_blk_size();
extern INT xs_send_to_plotter();
extern INT xs_shading_cdlg_init();
extern INT xs_start_chg_all();
extern INT xs_stop_chg_all();
extern INT xs_struct_loc_wellx();
extern INT xs_struct_loc_welly();
extern INT xs_tblock_cdlg_init();
extern INT xs_tdgz_info_server();
extern INT xs_term();
extern INT xs_traceattr_cdlg_init();
extern INT xs_tracesel_cdlg_init();
extern INT xs_trackdef_cdlg_init();
extern INT xs_type_cdlg_init();
extern INT xs_uselast_cdlg_init();
extern INT xs_we_dgz_traverse();
extern INT xs_we_rtr_traverse();
extern INT xs_we_save_traverse();
extern INT xs_we_show_well_list();
extern INT xs_we_use_cur_well();
extern INT xs_we_use_cur_we_list();

#endif
#endif
