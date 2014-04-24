/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SE.H*/
/* *22    7-JUN-1991 10:00:24 MING "(SPR 0) add more seismic_surface data types"*/
/*  18B2 15-OCT-1990 17:00:42 GILLESPIE "Merge Ernie deltas"*/
/* *21   15-OCT-1990 12:55:50 GILLESPIE "(SPR 1000) Merge Ernie deltas"*/
/*  18B1 13-OCT-1990 00:27:17 GILLESPIE "Updates from Ernie"*/
/* *20   31-AUG-1990 10:25:32 PURNA "(SPR 0) add return version number if version=0"*/
/* *19   14-AUG-1990 11:50:49 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *18   17-JUL-1990 19:31:33 VINCE "(SPR 5615) added a specific max_index to the seis_table_name enum type"*/
/* *17   29-JUN-1990 19:00:50 GILLESPIE "(SPR 1) Changes for fault posting"*/
/* *16   20-JUN-1990 09:47:10 PURNA "(SPR 0) replace ct_get_faults with co_get_faults"*/
/* *15   18-JUN-1990 12:01:25 GILLESPIE "(SPR 1) Changes to support IES data exchange"*/
/* *14    1-JUN-1990 13:22:56 GILLESPIE "(SPR 1) Add support for fault traces"*/
/* *13   30-MAY-1990 15:06:59 PURNA "(SPR 0) gulf change"*/
/* *12   21-MAY-1990 17:38:04 CHARLIE "(SPR 1) Change calling sequence to set_put"*/
/* *11   23-FEB-1990 08:44:50 GILLESPIE "(SPR 1) First change set for IES/BHP"*/
/* *10    8-FEB-1990 14:51:07 GORDON "(SPR 0) Add include of esi_ll.h "*/
/* *9     8-FEB-1990 13:41:32 WALTERS "(SPR 0) Add prototypes"*/
/* *8    23-JAN-1990 12:28:31 GILLESPIE "(SPR 6002) Change SURVEY and LINE_NAME data types to 24"*/
/* *7     1-NOV-1989 13:22:11 PURNA "(SPR 30) splittin seism_tools.pc"*/
/* *6    31-OCT-1989 11:54:17 GILLESPIE "(SPR 30) Remove extraneous includes in includes"*/
/* *5    25-OCT-1989 11:19:21 GILLESPIE "(SPR 1) Make se_retrieve_header an external function"*/
/* *4    20-SEP-1989 16:40:04 GILLESPIE "(SPR 100) Fix some prototypes"*/
/* *3     5-SEP-1989 14:03:35 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *2    25-JUL-1989 19:27:31 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    30-JUN-1989 15:04:10 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SE.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Finder Graphics Systems, Inc. 1990                      */
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

#ifndef ESI_SE_H
#define ESI_SE_H  1

#ifndef  ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

/*                                                                                  */
/**                                                                                 */
/**                                                                                 */
/** AUTHOR:REMI DORET                                                               */
/**                                                                                 */
/** DATE : July 1988                                                                */
/** MODIFIED: July 1989 J Gillespie                                                 */
/**   Extensively modified                                                          */
/**   Now is basis for FGS seismic system                                           */
/**                                                                                 */
/** FUNCTION :                                                                      */
/**                                                                                 */
/**   INCLUDE FILE used used to define symbols for                                  */
/**   seismic system manipulations                                                  */
/**                                                                                 */
/**                                                                                 */
/** LANGUAGE: C                                                                     */
/**                                                                                 */
/********************************************************************               */

/************************************************************************************/
/*                                                                                  */
/*           definitions of basic data types used in the seismic                    */
/*                                                                                  */
/************************************************************************************/

typedef long SEIS_LINE_ID;          /* Unique seismic line identifier               */
typedef char SEIS_SURV[24];         /* seismic survey name                          */
typedef char SEIS_LINE_NAME[24];    /* seismic line name, not including survey      */
typedef char SEIS_LINE[44];         /* character string containing the line_name +  */
                                    /*the survey name  this is a concatenated       */
                                    /*string with a separator                       */
typedef FILENAME SEIS_DATA_FILE;    /* name of seismic data files                   */

typedef char SEIS_SURFACE_NAME[32];
typedef double SP;                  /* shot point number giving positions of the line   */

typedef int CDP;                    /* internal cdp number                          */
typedef double CDP_FLOAT;           /* internal cdp number in float format          */

typedef int PROCESS;                /* code for process for a seismic data file     */
typedef int SAMPLE_VAL;             /* used for sample values                       */
typedef int TRACE;                  /* trace number used on seismic data            */

typedef int SEISM_TIM;              /* used for times on sections                   */

typedef char ATTRIBUTE[5];          /* character string containing attribute for    */
                                    /*seismic data file                             */

/************************************************************************************/

/* DEFAULT VALUES FOR SEISMIC SYSTEM                                                */

/*          default value used for correspondance CDP-SP                            */
#define DEF_CDP_PER_SP (INT)2
/*   default value used for initialising the correspondance between cdp-sp          */
#define DEF_INIT_CDP (INT)100
/* used for computation of closest point                                            */
#define N_DEC (INT)5
/* used for clipping rectangle in computation of closest point                      */
#define TOLERANCE 10.

/* define FLAG for checking if there is position data or not for a line             */

#define NO_POSITION_DATA (INT)-1
/* define symbols used for extrapolation computation                                */
#define BEGIN_LIST 1         /* extrapolate before beginning */
#define END_LIST 2           /* extrapolate after the end of the list    */
#define EPSILON 0.001
/* used in the intersection table when there is no seismic on a line                */
#define FLAG_NO_SEISMIC (INT)-10000
/*  used when reading back the intersection table if we want a range selection in cdp   */
#define FLAG_NO_RANGE   (INT)-10000

/* define number of characters in the line                                          */
/*    name + LINE_NAME_SEPARATOR used for                                           */
/*    creation of the long line name                                                */

#define LINE_NAME_SEPARATOR         '^'
#define NB_CAR_LINE (INT)20

/************************************************************************************/

/* FULL_LINE_NAME is the structure giving the                                       */
/*    full line name which is the association of                                    */
/*    a line name and a survey name                                                 */
typedef struct 
    {
    SEIS_LINE_ID id;                /* Unique identifier (within project)           */
    SEIS_LINE_NAME line_name;       /* line name                                    */
    SEIS_SURV survey;               /* survey name                                  */
    } FULL_LINE_NAME;

/************************************************************************************/

typedef enum 
    {
    NO_SEIS_ASSOC,                  /* no seismic or paper sections associated      */
    SEIS_ASSOC,                     /* there is at least one seismic trace file associated  */
    PAPER_SECT                      /* only paper sections associated               */
    } SEIS_ASSOCIATED_DATA;

/************************************************************************************/

/* definitions of the attributes for the seismic data                               */
typedef enum 
    {
    SE_AT_NM = 1,                   /* Normal section                               */
    SE_AT_MG = 2,                   /* Migrated section                             */
    SE_AT_SS = 3, SE_AT_PP = 4, SE_AT_PS = 5, SE_AT_SP = 6
    } SEIS_ATTRIBUTE_DATA_TYPE;

/************************************************************************************/

/* definition of codes used for hilight seismic nlist                               */
typedef enum 
    {
    PICK_XY, FIRST_CDP, LAST_CDP
    } SEIS_HILIGHT_TYPE;

/************************************************************************************/

/* definitions used for picks describing the different flags (Column 3)             */
/*   stored in the seismic surfaces                                                 */

typedef enum 
    {
    NORMAL_PICK = 0, NOPICK = 1, NODATA = 2, PINCH = 14, FAULT = 15
    } SEIS_HOR_PICK_TYPE;

/************************************************************************************/

/* define flags used for filling the intersection array in the structure line_hdr   */
typedef enum 
    {
    NO_INTERSECTION = 0, INTERS_NOT_COMPUTED = -1
    } SEIS_INTERSECT_FLAG;

/************************************************************************************/

/*    definitions for section types                                                 */

typedef enum 
    {
    X_2D = 1,                       /* 2-D line                                     */
    R_2D = 2,                       /* Random (composite) line from 2-D survey      */
    X_3D = 10,                      /* 3-D line in X direction                      */
    Y_3D = 11,                      /* 3-D line in Y direction                      */
    T_3D = 12,                      /* 3-D time slice                               */
    R_3D = 13                       /* Random line from 3-D survey                  */
    } SEIS_LINE_TYPE;

/************************************************************************************/

typedef enum 
    {
    SEIS_LOCATION_DATA = 1, SEIS_HDR_DATA = 2, SEIS_SURFACE_DATA = 3,
    SEIS_TRACE_DATA = 4, SEIS_SHOT_LABEL_DATA = 5, SEIS_OPTIM_XY_DATA = 6,
    SEIS_CDPSP_DATA = 7, SEIS_LATLONG_DATA = 8, SEIS_XY_DATA = 9, SEIS_ALTIM_DATA = 10,
    SEIS_FTRACE_DATA = 11
    } SEIS_NLIST_DATA_TYPE;

/************************************************************************************/

typedef enum 
    {
    SEIS_SNAP_P_NEAR = 1,           /* nearest peak to center of window             */
    SEIS_SNAP_P_MAX = 2,            /* largest peak in window                       */
    SEIS_SNAP_T_NEAR = 3,           /* nearest trough to center of window           */
    SEIS_SNAP_T_MAX = 4,            /* largest trough in window                     */
    SEIS_SNAP_ZPN = 5,              /* zero crossing, positive to negative          */
    SEIS_SNAP_ZNP = 6,              /* zero crossing, negative to positive          */
    SEIS_SNAP_NULL = 7,             /* snap to input point                          */
    SEIS_SNAP_UNDEFINED = 8         /* undefined snap type                          */
    } SEIS_SNAP_TYPE;

/************************************************************************************/

typedef enum 
    {
    REGULAR,                        /* flag indicating that correspondance between  */
                                    /*SP_CDP is regular established using factor    */
                                    /*cdp_per_sp                                    */
    SEMI_REGULAR,                   /* flag indicating that correspondance between  */
                                    /*SP_CDP is in strokes having more than 1       */
                                    /*point established using factor cdp_per_sp     */
    IRREGULAR                       /* flag indicating that correspondance between  */
                                    /*SP_CDP is irregular we keep in the nlist      */
                                    /*shot_label all the cdp and sp                 */
    } SEIS_SP_ORDER;

/************************************************************************************/

/* definitions of the surface type  stored in SEIS_SURFACE                          */
typedef enum 
    {
    SE_HORIZ = 1, SE_FAULT = 2
    } SEIS_SURFACE_DATA_CLASS;

/************************************************************************************/

/* definitions of the type of data stored in SEIS_SURFACE                           */

typedef enum 
    {
    SE_TIME = 1, SE_DEPTH = 2, SE_AMPL = 3, SE_VEL_STK = 4, SE_PHASE = 5,
    SE_TIME_REFINED = 6, SE_UNKNOWN = 7, SE_UNSNAPPED_TIME = 8, SE_VEL_RMS = 9,
    SE_VEL_AVG = 10, SE_VEL_INT = 11, SE_FREQUENCY = 12
    } SEIS_SURFACE_DATA_TYPE;

/************************************************************************************/

/* definitions of the n-List formats in which the data is stored                    */

typedef enum 
    {
    SE_FINDER = 1, SE_INTERP = 2, SE_GULF = 3
    } SEIS_SURFACE_NLIST_TYPE;

/************************************************************************************/

/*   definition for SURVEY type                                                     */
typedef enum 
    {
    SURVEY_2D = 1, SURVEY_3D = 2
    } SEIS_SURVEY_TYPE;

/************************************************************************************/

typedef enum 
    {
    SEIS_SURFACE_TABLE = 0,         /* Indexes must start with zero                 */
    SEIS_LINE_HDR_TABLE, SEIS_SURVEY_HDR_TABLE, SEIS_FULL_TIE_TABLE,
                         MAX_SEIS_TABLE_INDEX   /* Must be last in list             */
    } SEIS_TABLE_NAME;

/************************************************************************************/

typedef struct 
    {
    CDP cdp_inc;                    /* increment between cdps                       */
    DOUBLE cdp_interval;            /* distance between cdps                        */
    CDP_FLOAT cdp_min_fl;           /* lower cdp number stored as a float           */
    DOUBLE cos_azx;                 /* value of cos (x_azimuth )                    */
    DOUBLE cos_azy;                 /* value of cos (y_azimuth )                    */
    INT line_inc;                   /* increment between lines                      */
    DOUBLE line_interval;           /* distance between lines                       */
    CDP_FLOAT line_min_fl;          /* lower line number stored as a float          */
    CDP lower_cdp;                  /* lower cdp number                             */
    INT lower_line;                 /* lower line number                            */
    DOUBLE sin_azx;                 /* value of sin (x_azimuth )                    */
    DOUBLE sin_azy;                 /* value of sin (y_azimuth )                    */
    SEIS_SURV survey_name;          /* Name of survey                               */
    CDP upper_cdp;                  /* upper cdp number                             */
    INT upper_line;                 /* upper line number                            */
    DOUBLE x_azimuth;               /* x azimuth for the grid                       */
    COORD x_origin;                 /* x coord origin for the grid                  */
    CHAR xy_unit[20];               /* xy units                                     */
    DOUBLE y_azimuth;               /* y azimuth for the grid                       */
    COORD y_origin;                 /* y coord origin for the grid                  */
    } GRID_3D;

/************************************************************************************/

/* LINE_HDR is the structure describing the                                         */
/* informations comming from  the line header                                       */
/* and used by the functions                                                        */

typedef struct 
    {
    FULL_LINE_NAME line;            /* line and survey name structure               */
    SEIS_SURVEY_TYPE survey_type;   /* Whether line is associated with a 2-D or 3-D survey  */
    VOIDPTR *pSurvey;               /* pointer to the survey structure for this line*/
                                    /*If the line type is 2d, then this will point to a 2-D survey header;  */
                                    /*If the line type is 3d, then this will point to a 3-D survey header   */
    DOUBLE line_number;             /* line number - used only for 3-D surveys      */
    SEIS_SP_ORDER regular;
    SEIS_ASSOCIATED_DATA seismic_flag;
    SEIS_LINE_TYPE line_type;       /* flag indicating the type of seismic line     */
    CDP init_cdp;                   /* cdp corresponding to the initial SP          */
    CDP final_cdp;                  /* cdp corresponding to the final SP            */
    CDP low_cdp_coord;              /* cdp number of thelower cdp which has         */
                                    /*coordinates x y in the nlist optim_xy         */
    CDP low_cdp_label;              /* cdp number of the lowest cdp which has an    */
                                    /*SP label  associated                          */
    CDP up_cdp_coord;               /* cdp number of the greater cdp which has      */
                                    /*coordinates x y in the nlist optim_xy         */
    CDP up_cdp_label;               /* cdp number of the greater cdp which has an   */
                                    /*SP label  associated                          */
    CDP_FLOAT cdp_per_sp;           /* number of cdp per sp                         */
    SP init_sp;                     /* initial SP for this line                     */
    SP final_sp;                    /* final SP for this line                       */
    COORD encl_box[8];              /* xmin , xmax , ymin , ymax of the orinted     */
    /* rectangle                                                                    */
    COORD rect[8];                  /* array of doubles containing the coord of     */
    /* the corners of the oriented rectangle                                        */
    /* enclosing the line                                                           */
    DOUBLE sp_spacing;              /* average distance between shot points         */
    
    INT nb_points;                  /* number of points in the arrays               */
    INT cur_index;                  /* cur_index in the array array_cdp used for    */
                                    /*optimizing computations                       */
    FLOAT *array_cdp;               /* pointer to an array of float containing the  */
                                    /*cdp                                           */
    FLOAT *array_x;                 /* pointer to an array of float containing the  */
                                    /*x coordinates                                 */
    FLOAT *array_y;                 /* pointer to an array of float containing the  */
                                    /*y  coodinates                                 */
    
    NLIST_ID optim_xy_id;           /* name of the nlist where we store the         */
                                    /*(cdp,x,y)  in the optimized form              */
    NLIST_HEADER optim_xy;          /* n-List header for optimized xys              */
    
    NLIST_ID shot_xy_id;            /* name of the nlist where we store the         */
                                    /*(cdp,x,y)                                     */
    NLIST_HEADER shot_xy;           /* n-List header for 'raw' xys                  */
    
    INT *inters_array;              /* pointer to an integer array containing the   */
                                    /*interpret vector CROSS (list of the           */
                                    /*intersection on a given line                  */
    INT nb_inters;                  /* flag used for indicating the state of the vector */
                                    /* CROSS  and the number of intersection        */
                                    /* FLAG = NO_INTERSECTION means that there are no   */
                                    /*        intersections on this line            */
                                    /* FLAG = INTERS_NOT_COMPUTED means that we didn't look */
                                    /*        for the intersections yet             */
                                    /*  (if the intersections were computed)nb_inters is    */
                                    /*  the number of intersections                 */
    
    NLIST_HEADER shot_label;        /* pointer to the nlist where we store the      */
                                    /*(cdp ,sp)                                     */
    NLIST_ID shot_label_id;         /* name of the nlist where we store the (cdp    */
                                    /*,sp)                                          */
    
    FILENAME nlist_file;            /* name of the nlist_file where the nlists for  */
                                    /*the line are  stored                          */
    
    } LINE_HDR;

/************************************************************************************/

typedef struct 
    {
    SEIS_ATTRIBUTE_DATA_TYPE attribute;
    CDP cdp_inc;                    /* increment of cdps in horizon array           */
    SEIS_SURFACE_DATA_CLASS data_class;
    SEIS_SURFACE_DATA_TYPE data_type;
    CDP first_cdp;                  /* first cdp in horizon array                   */
    CDP last_cdp;                   /* last cdp in horizon array                    */
    FULL_LINE_NAME line;
    DOUBLE lower_time;
    SEIS_SURFACE_NAME name;
    NLIST_HEADER nlist;             /* handle to horizon data                       */
    SEIS_SURFACE_NLIST_TYPE nlist_type;
    SEIS_SNAP_TYPE snap;            /* attribute describing auto-trace              */
    DOUBLE snap_window;             /* size of snap window                          */
    ANALYST_NAME source;
    DOUBLE upper_time;
    INT version;                    /* version of horizon                           */
    } SEIS_SURFACE_HDR;

/************************************************************************************/

/* The following structure is stored with each table in a seismic horizon to describe   */
/*the discontinuity in more detail than available in the flag field of the surface  */

typedef struct 
    {
    SEIS_SURFACE_NAME initial;      /* name of contact associated with the first point in the table */
    SEIS_SURFACE_NAME final;        /* name of contact associated with the last point in the table  */
    } SEIS_SURFACE_CONTACTS;

/************************************************************************************/

typedef struct 
    {
    BOOL seismic_on_line;           /* true if seismic on this line - false if not  */
    BOOL seismic_on_tie_line;       /* true if seismic on tie line - false if not   */
    FULL_LINE_NAME this;            /* survey/line name of this line                */
    CDP_FLOAT this_cdp;             /* cdp in float format for the intersection on first line   */
    FULL_LINE_NAME tie;             /* survey/line name of tie line                 */
    CDP_FLOAT tie_cdp;              /* cdp in float format for the intersection on first line   */
    COORD tie_x;                    /* x_coord of  the intersection                 */
    COORD tie_y;                    /* y_coord of the intersection                  */
    } SEIS_TIE;

/************************************************************************************/

typedef struct 
    {
    ATTRIBUTE attribute;            /* attribute for this trace file                */
    FULL_LINE_NAME line;
    INT polarity;                   /* polarity of the data                         */
    PROCESS process;                /* code for the process                         */
    } TRACE_ATTRIBUTE;

typedef struct seis_trace_hdr
    {
    CDP_FLOAT cdp_per_trace;        /* number of cdp per trace                      */
    INT file_pointer;               /* first word where seismic data is stored in file  */
    CDP final_cdp;                  /* cdp corresponding to the final trace         */
    SP final_sp;                    /* final sp for this seismic file               */
    TRACE final_trace;              /* final SP for this line                       */
    INT first_log_trace;            /* logical number of first trace                */
    DOUBLE gain;                    /* gain applied by loader                       */
    INT grec;                       /* parameter used for os file decription        */
    CDP init_cdp;                   /* cdp corresponding to the initial trace       */
    SP init_sp;                     /* initial sp for this seismic file             */
    TRACE init_trace;               /* initial SP for this line                     */
    INT last_log_trace;             /* logical number of last trace                 */
    INT lrec;                       /* parameter used for os file decription        */
    SAMPLE_VAL maxi_sample_val;     /* maximum value  for the samples               */
    SEISM_TIM maxi_time;            /* maximum time on the section                  */
    SAMPLE_VAL mini_sample_val;     /* minimum value  for the samples               */
    SEISM_TIM mini_time;            /* minimum time on the section                  */
    INT nb_word_per_trace;          /* number of words ( 4bytes) per trace          */
    struct seis_trace_hdr *next;    /* next trace file                              */
    SAMPLE_VAL sample_interp;       /* number of pixels/sample (segy loader parameter)  */
    INT sample_per_trace;           /* number of samples per trace                  */
    INT sample_per_word;            /* number of samples per 32 bit-word            */
    SEISM_TIM sample_rate;          /* sampling rate for the trace                  */
    SAMPLE_VAL seis_zero;           /* value of the seismic zero                    */
    INT signed_sample;              /* = 1 samples are signed  = 0 posit values     */
    TRACE_ATTRIBUTE trace_attri;    /* structure used to described the trace attribute  */
    SEIS_DATA_FILE trace_file;      /* name of the data file where the traces are stored    */
    TRACE trace_inc;                /* increment between trace numbers              */
    TRACE trace_interp;             /* number of pixels/trace (segy loader parameter)   */
    FLOAT trace_interval;           /* interval between traces (called cdp interval)*/
    INT xy_unit;                    /* xy unit for the distances                    */
    } TRACE_HDR;

/************************************************************************************/

typedef struct 
    {
    SEIS_SURFACE_DATA_TYPE data_type;   /* if z values present, what data type is being used    */
    SEIS_SURFACE_NAME fault_name;   /* Name of fault                                */
    SEIS_SURFACE_NAME hor_code;     /* Name of horizon                              */
    NLIST_HEADER nlist;             /* n-List containing map view of fault trace (3 dimensions) */
    ANALYST_NAME source;            /* Source of interpretation                     */
    } SEIS_FAULT_TRACE;

/************************************************************************************/

/* DECLARATION OF FUNCTIONS  WHICH CAN BE CALLED BY APPLICATIONS                    */

#if USE_PROTOTYPES
extern INT sef_line_stor (CHAR *curr_seismic_list, INT *nb_lines, TCP *line_buf,
                          CHAR **charbuf);
extern INT sef_read_optim (LINE_HDR *p_hdr);
extern INT se_analyze_pick (INT pick, INT icoef, SEIS_HOR_PICK_TYPE *pick_type,
                            FLOAT *time);
extern INT se_bld_nlist_ids (FULL_LINE_NAME *line, VOIDPTR context,
                             SEIS_NLIST_DATA_TYPE data_type, NLIST_ID nlist_id,
                             FILENAME nlist_file, FILENAME full_filename);
extern INT se_cdp_from_sp (FULL_LINE_NAME *line_name, SP sp, CDP *cdp);
extern INT se_cdp_from_sp_init (FULL_LINE_NAME *line_name, INT honor, SP sp, CDP *cdp,
                                CDP *cdp_per_sp);
extern INT se_cdp_from_trace (TRACE_ATTRIBUTE *line_str, TRACE trace, CDP *cdp);
extern INT se_cdp_from_xy (FULL_LINE_NAME *line_name, COORD x, COORD y,
                           DOUBLE cdp_dist, CDP *cdp_int, CDP_FLOAT *cdp_float,
                           COORD *xproj, COORD *yproj, CDP *cdp_end, COORD *x_end,
                           COORD *y_end);
extern INT se_cre_long_line_name (SEIS_LINE_NAME short_name, SEIS_SURV survey_name,
                                  SEIS_LINE long_line_name);
extern INT se_del (CHAR *surf_code, SEIS_SURFACE_DATA_CLASS surf_type,
                   SEIS_SURFACE_DATA_TYPE data_type, FULL_LINE_NAME *line,
                   CHAR *source, SEIS_ATTRIBUTE_DATA_TYPE attribute,
                   SEIS_SURFACE_NLIST_TYPE format, INT version);
extern INT se_first_last_cdp (FULL_LINE_NAME *line_name, CDP *first_cdp, CDP *lst_cdp);
extern INT se_first_last_sp (FULL_LINE_NAME *line_name, SP *first, SP *last);
extern INT se_get (NLIST_HEADER *surface_nlist, CHAR *surf_code,
                   SEIS_SURFACE_DATA_CLASS surf_type, SEIS_SURFACE_DATA_TYPE data_type,
                   FULL_LINE_NAME *line, CHAR *source,
                   SEIS_ATTRIBUTE_DATA_TYPE attribute, SEIS_SURFACE_NLIST_TYPE format,
                   INT *version, FLOAT *upper_time, FLOAT *lower_time,
                   CDP_FLOAT *first_cdp, CDP_FLOAT *last_cdp);
extern INT se_get_faults (CHAR *horizon, CHAR *fault_source, NLIST_HEADER *fault_list);
extern INT se_get_line (SEIS_LINE_ID line_id, SEIS_LINE_NAME line_name);
extern INT se_get_survey (SEIS_LINE_ID line_id, SEIS_SURV survey_name);
extern INT se_inf_lines (CHAR *surf_code, SEIS_SURFACE_DATA_CLASS surf_type,
                         SEIS_SURFACE_DATA_TYPE data_type, CHAR *source,
                         SEIS_ATTRIBUTE_DATA_TYPE attribute,
                         SEIS_SURFACE_NLIST_TYPE format, SEIS_LINE_TYPE line_type,
                         INT version, CHAR *survey_in, INT fl_surv,
                         NLIST_HEADER *nl_lines);
extern INT se_inf_source (CHAR *surf_code, SEIS_SURFACE_DATA_CLASS surf_type,
                          SEIS_SURFACE_DATA_TYPE data_type, FULL_LINE_NAME *line,
                          SEIS_ATTRIBUTE_DATA_TYPE attribute,
                          SEIS_SURFACE_NLIST_TYPE format, SEIS_LINE_TYPE line_type,
                          INT version, NLIST_HEADER *nl_vers);
extern INT se_inf_surf (SEIS_SURFACE_DATA_CLASS surf_type,
                        SEIS_SURFACE_DATA_TYPE data_type, FULL_LINE_NAME *line,
                        CHAR *source, SEIS_ATTRIBUTE_DATA_TYPE attribute,
                        SEIS_SURFACE_NLIST_TYPE format, SEIS_LINE_TYPE line_type,
                        INT version, NLIST_HEADER *nl_surf);
extern INT se_inf_vers (CHAR *surf_code, SEIS_SURFACE_DATA_CLASS surf_type,
                        SEIS_SURFACE_DATA_TYPE data_type, FULL_LINE_NAME *line,
                        CHAR *source, SEIS_ATTRIBUTE_DATA_TYPE attribute,
                        SEIS_SURFACE_NLIST_TYPE format, SEIS_LINE_TYPE,
                        NLIST_HEADER *nl_vers);
extern INT se_init_hor_nlist (NLIST_HEADER *nlist);
extern INT se_line_cdp_from_xy (FULL_LINE_NAME *line_name, SEIS_HILIGHT_TYPE flag,
                                COORD wx, COORD wy, CDP *cdp, COORD *x, COORD *y);
extern INT se_long_name_from_struct (FULL_LINE_NAME *line_name,
                                     SEIS_LINE long_line_name);
extern INT se_put (NLIST_HEADER seismic_nlist, CHAR *surf_code,
                   SEIS_SURFACE_DATA_CLASS surf_type, SEIS_SURFACE_DATA_TYPE data_type,
                   FULL_LINE_NAME *line, CHAR *source,
                   SEIS_ATTRIBUTE_DATA_TYPE attribute, SEIS_SURFACE_NLIST_TYPE format,
                   INT version);
extern INT se_put_position (NLIST_HEADER nlist_sp, FULL_LINE_NAME *line,
                            BOOL flag_inters);
extern INT se_rd_nl_optim (FULL_LINE_NAME *line_name, NLIST_HEADER *nlist);
extern INT se_rd_nl_shot_xy (FULL_LINE_NAME *line_name, NLIST_HEADER *nlist);
extern INT se_read_shot_lab (LINE_HDR *p_hdr);
extern INT se_rep (NLIST_HEADER seismic_nlist, CHAR *surf_code,
                   SEIS_SURFACE_DATA_CLASS surf_type, SEIS_SURFACE_DATA_TYPE data_type,
                   FULL_LINE_NAME *line, CHAR *source,
                   SEIS_ATTRIBUTE_DATA_TYPE attribute, SEIS_SURFACE_NLIST_TYPE format,
                   INT version);
extern INT se_retrieve_header (FULL_LINE_NAME *seis_line, LINE_HDR **p_hdr);
extern INT se_split_long_name (SEIS_LINE long_line_name, SEIS_SURV survey_name,
                               SEIS_LINE_NAME short_name);
extern INT se_sp_from_cdp (FULL_LINE_NAME *line_name, CDP cdp, SP *sp);
extern INT se_sp_from_cdp_intern (LINE_HDR *p_hdr, CDP_FLOAT cdp, SP *sp);
extern INT se_sp_from_trace (TRACE_ATTRIBUTE *line_str, TRACE trace, SP *sp);
extern INT se_sp_from_xy (FULL_LINE_NAME *line_name, COORD wx, COORD wy, SP *sp);
extern INT se_struct_from_long_name (SEIS_LINE long_line_name,
                                     FULL_LINE_NAME *line_name);
extern INT se_trace_from_cdp (TRACE_ATTRIBUTE *line_str, CDP cdp, TRACE *trace);
extern INT se_trace_from_sp (TRACE_ATTRIBUTE *line_str, SP sp, TRACE *trace);
extern INT se_xy_from_cdp (FULL_LINE_NAME *line_name, CDP cdp, DOUBLE cdp_dist,
                           COORD *x, COORD *y);
extern INT se_xy_from_cdp_float (FULL_LINE_NAME *line_name, CDP_FLOAT cdp,
                                 DOUBLE cdp_dist, COORD *x, COORD *y);
extern INT se_xy_from_sp (FULL_LINE_NAME *line_name, SP sp, COORD *x, COORD *y);
extern INT se_xy_from_trace (TRACE_ATTRIBUTE *line_str, TRACE trace, DOUBLE inter_cdp,
                             COORD *x, COORD *y);
extern INT ss_cdpli_xy (COORD x, COORD y, CDP_FLOAT *cdp, DOUBLE *li);
extern INT ss_get_cur_2d (SEIS_SURV survey);
extern INT ss_get_cur_3d (SEIS_SURV survey);
extern INT ss_get_surv_3d (CDP *cdp_min, CDP *cdp_max, INT *line_min, INT *line_max,
                           COORD *azx, COORD *azy, DOUBLE *dx, DOUBLE *dy, COORD *orgx,
                           COORD *orgy, CHAR *unit, CDP *cdp_inc, INT *line_in);
extern INT ss_get_2d_def (SEIS_SURV survey);
extern INT ss_pick_surv (INT flag, SEIS_SURV surv_out);
extern INT ss_put_surv_3d (SEIS_SURV survey, CDP cdp_max, CDP cdp_min, INT line_min,
                           INT line_max, COORD azx, COORD azy, DOUBLE dx, DOUBLE dy,
                           COORD orgx, COORD orgy, CHAR *unit, CDP cdp_inc,
                           INT line_in);
extern INT ss_xy_cdpli (CDP_FLOAT cdp, DOUBLE li, COORD *x, COORD *y);
extern INT ss_set_cur_2d (SEIS_SURV survey);
extern INT ss_set_cur_3d (SEIS_SURV survey);

#else    /* no prototypes */
extern INT sef_line_stor ();
extern INT sef_read_optim ();
extern INT se_analyze_pick ();
extern INT se_bld_nlist_ids ();
extern INT se_cdp_from_sp ();
extern INT se_cdp_from_sp_init ();
extern INT se_cdp_from_trace ();
extern INT se_cdp_from_xy ();
extern INT se_cre_long_line_name ();
extern INT se_del ();
extern INT se_first_last_cdp ();
extern INT se_first_last_sp ();
extern INT se_get ();
extern INT se_get_faults ();
extern INT se_getinters ();
extern INT se_inf_lines ();
extern INT se_inf_source ();
extern INT se_inf_surf ();
extern INT se_inf_vers ();
extern INT se_init_hor_nlist ();
extern INT se_line_cdp_from_xy ();
extern INT se_long_name_from_struct ();
extern INT se_put ();
extern INT se_put_position ();
extern INT se_rd_nl_optim ();
extern INT se_rd_nl_shot_xy ();
extern INT se_read_shot_lab ();
extern INT se_rep ();
extern INT se_retrieve_header ();
extern INT se_split_long_name ();
extern INT se_sp_from_cdp ();
extern INT se_sp_from_cdp_intern ();
extern INT se_sp_from_trace ();
extern INT se_sp_from_xy ();
extern INT se_struct_from_long_name ();
extern INT se_trace_from_cdp ();
extern INT se_trace_from_sp ();
extern INT se_xy_from_cdp ();
extern INT se_xy_from_cdp_float ();
extern INT se_xy_from_sp ();
extern INT se_xy_from_trace ();
extern INT ss_pick_surv ();
extern INT ss_set_cur_3d ();
extern INT ss_put_surv_3d ();
extern INT ss_get_surv_3d ();
extern INT ss_xy_cdpli ();
extern INT ss_cdpli_xy ();
extern INT ss_set_cur_2d ();
extern INT ss_get_cur_2d ();
extern INT ss_get_cur_3d ();
extern INT ss_get_2d_def ();

#endif   /* of USE_PROTOTYPES */

/*      end include  file                                                           */
#endif
