/* DEC/CMS REPLACEMENT HISTORY, Element INTERFACE.H */
/* *2    19-SEP-1990 15:59:10 GILLESPIE "(SPR 1) Update copy from Geoquest; adjust copyright" */
/* *1    20-JUN-1990 16:38:24 GILLESPIE "GQS IES Link" */
/* DEC/CMS REPLACEMENT HISTORY, Element INTERFACE.H */


#ifndef _INTERFACE_H_DEFINED

#define _INTERFACE_H_DEFINED
/*----------------------------------------------------------------------------- */
/*|                                                                             */
/*|   Module:    inteface.h                                                     */
/*|                                                                             */
/*|   Purpose:   This file contains symbol definitions and structure            */
/*|              specifications to be used in data interchange facilities       */
/*|                                                                             */
/*|   Notes:                                                                    */
/*|                                                                             */
/*|   History:   1-Feb-1990       S. F. McAdoo,  GQS                            */
/*|                  Original code.                                             */
/*|              2-Jun-1990       J. G. Gillespie, Finder Graphics              */
/*|                  Enhance 2-D seismic structures                             */
/*|                  Add null values for seismic survey, fault trace and well structs   */
/*|                                                                             */
/*|---------------------------------------------------------------------------  */
/*|                                                                             */
/*|         This code is the proprietary and confidential property of           */
/*|         GeoQuest Systems, Inc. and Finder Graphics Systems, Inc             */
/*|         and is protected under U.S. Copyright laws.                         */
/*|         This code may not be reproduced in part or whole by any             */
/*|         technique or facsimile adoption without first obtaining the         */
/*|         explicit written consent of GeoQuest Systems, Inc. or               */
/*|         Finder Graphics Systems, Inc                                        */
/*|                                                                             */
/*+-----------------------------------------------------------------------------*/

/********************************************************************************/
/*                                                                              */
/*                            INCLUDE FILES                                     */
/*                                                                              */
/********************************************************************************/

#ifndef _portable_included_
/* GQS-based symbols and data type definitions                                  */

typedef int int_t;                  /* Fortran INTEGER                          */
typedef float real_t;               /* Fortran REAL                             */
typedef double dp_t;                /* Fortran DOUBLE PRECISION                 */
typedef int status_t;               /* IES status code type                     */
typedef unsigned int uns_t;         /* Unsigned integer                         */

struct string_tag 
    {
    int_t length;
    char *pointer;
    };
typedef struct string_tag string_t;

#endif              /* GQS-based symbols and data type definitions */

#ifndef _7PX_DEF_INCLUDE_FLAG
typedef void *gptr_t;               /* Generic pointer data type.               */
typedef struct rational_s
    {
    int_t num;
    uns_t den;
    } rational_t;
typedef unsigned symbol_t;          /* Symbol data type.                        */

#endif /* _7PX_DEF_INCLUDE_FLAG */

#ifndef _OPT_DEF_INCLUDED
/*                                                                              */
/* * structures which define an option list                                     */
/* *     and option types to avoid opt.def include                              */
/*                                                                              */

#define TYPE_INT        42001001
#define TYPE_UNS        42001002
#define TYPE_BOOL       42001003
#define TYPE_REAL       42001004
#define TYPE_DP         42001005
#define TYPE_COMPLEX    42001006
#define TYPE_DCOMPLEX   42001007
#define TYPE_RATIONAL   42001008
#define TYPE_BYTE       42001009
#define TYPE_SBYTE      42001010
#define TYPE_CHAR       42001011
#define TYPE_STRING     42001012
#define TYPE_SYMBOL     42001013
#define TYPE_STATUS     42001014
#define TYPE_ENUM       42001015
#define TYPE_TOKEN      42001016
#define TYPE_BITFIELD   42001017
#define TYPE_ABS_TIME   42001018
#define TYPE_GPTR       42001019
struct opt_hdr_s 
    {
    int_t max;
    int_t actual;
    int_t get_index;
    status_t status;
    };

struct opt_tuple_s 
    {
    int_t code;
    int_t type;
    union 
        {
        dp_t dp;
        gptr_t addr;
        int_t integer;
        rational_t rational;
        real_t real;
        string_t string;
        symbol_t symbol;
        } value;
    };

typedef struct opt_list_s
    {
    struct opt_hdr_s header;
    struct opt_tuple_s option[1];
    } opt_list_t;
#endif /* _OPT_DEF_INCLUDED */

/* The following was extracted from GQS's DB.DEF file                           */

#ifndef _DB_DEF_DEFINED
/* Units of sampling interval                                                   */
#define   DB_SR_SECS       1
#define   DB_SR_HERTZ      2
#define   DB_SR_OFFSET     3
#define   DB_SR_UKNOWN     4

/* Trace order                                                                  */
#define   DB_TRACE_ORDER_SHOT     1
#define   DB_TRACE_ORDER_CDP      2
#define   DB_TRACE_ORDER_STACK    3
#define   DB_TRACE_ORDER_SEQ      4

/* Units of offset (distance)                                                   */
#define   DB_TRACE_OFFSET_FEET    1
#define   DB_TRACE_OFFSET_METERS  2
#define   DB_TRACE_OFFSET_UNKNOWN 3

/* seismic trace codes                                                          */
#define   DB_DEAD_TRACE          -1
#define   DB_LIVE_TRACE           0
#define   DB_NULL_TRACE           1
#define   DB_SWEEP_TRACE          2

/* validity fields   validity field true or false                               */
#define   DB_VALID       1
#define   DB_NOT_VALID   -1

#endif  /* _DB_DEF_DEFINED */

/********************************************************************************/
/*                                                                              */
/*                            BASE DEFINITIONS                                  */
/*                                                                              */
/********************************************************************************/

/* option list id, when set, indicates that called are to "talk"
   about what they are doing    */
#define VERBOSE_ON   12345  
typedef long BOOLEAN_T;
typedef char DATE_T[12];
typedef long NODE_ID_T;             /* node identifier                          */
typedef char ANALYST_NAME_T[16];    /* name of any oracle object                */

typedef char STRATCOL_T[32];
typedef char UNIT_T[24];            /* Unit of measure                          */
typedef char UWI_T[24];             /* Unique Well Identifier                   */

typedef struct 
    {
    int_t Module;
    char Revision[8];
    char Finder[8];
    } VERSION_T;

typedef char *VOIDPTR_T;

typedef char WELL_NAME_T[32];       /* db char(50)                              */
typedef char WELL_NUMBER_T[16];     /* db char(20)                              */

/********************************************************************************/
/*                                                                              */
/*                    Symbolic Constant Definitions                             */
/*                                                                              */
/********************************************************************************/

/* status/completion constants - use to "turn on/off" processing of             */
/*    interface structure elements                                              */

#define     SET_3D_LOCATION     100 /* fix 3D survey in space */

/*                                                                              */
/* *       symbols for survey type                                              */
/*                                                                              */

typedef enum 
    {
    SVY_2D = 2,                     /* 2d survey symbol                         */
    SVY_3D = 3                      /* 3d survey symbol                         */
    } survey_type_t;

/*                                                                              */
/* *       symbols specifying type of line (seismic based)                      */
/*                                                                              */

typedef enum 
    {
    LINE_2D = 30,                   /* line type 2d                             */
    LINE_3DI = 31,                  /* line type 3d inline                      */
    LINE_XLN = 32,                  /* line type 3d cross line                  */
    LINE_TSL = 33,                  /* line type 3d time slice                  */
    LINE_RCN = 34                   /* line type 3d reconst cut                 */
    } line_type_t;

/*                                                                              */
/* *       symbols specifying regularity of shot / cdp correspondence           */
/*                                                                              */

typedef enum 
    {
    REGULAR_CORRESP = 0, SEMI_REGULAR_CORRESP = 1, IRREGULAR_CORRESP = 2
    } cdp_sp_corresp_t;

/*                                                                              */
/* *       symbols identifying types of interpreted surfaces                    */
/*                                                                              */

typedef enum 
    {
    SRF_TYPE_UNKNOWN = 0,           /* surface type unknown                     */
    SRF_TYPE_HOR = 1,               /* surface type horizon                     */
    SRF_TYPE_FLT = 2                /* surface type fault                       */
    } surface_type_t;

/*                                                                              */
/* *       symbols specifying type of snap operation performed                  */
/*                                                                              */

typedef enum 
    {
    SNAP_P_NEAR = 1,                /* nearest peak to center of window         */
    SNAP_P_MAX = 2,                 /* largest peak in window                   */
    SNAP_T_NEAR = 3,                /* nearest trough to center of window       */
    SNAP_T_MAX = 4,                 /* largest trough in window                 */
    SNAP_ZPN = 5,                   /* zero crossing, positive to negative      */
    SNAP_ZNP = 6,                   /* zero crossing, negative to positive      */
    SNAP_NULL = 7,                  /* snap to input point                      */
    SNAP_UNDEFINED = 8              /* undefined snap type                      */
    } snap_event_t;

/*                                                                              */
/* *      symbols specifying type of z value in surface                         */
/*                                                                              */

typedef enum 
    {
    Z_TYPE_UNDEFINED = 0, TIME_UNSNAPPED = 1,   /* Z time is original picks     */
    TIME_REFINED = 2,               /* Z time is snapped and smoothed           */
    AMPLITUDE = 3                   /* Z is amplitude from class of             */
                                    /* seismic data associated with surface     */
    } z_type_t;

/*                                                                              */
/* *       codes for type of migration                                          */
/*                                                                              */

typedef enum 
    {
    NO_MIGRATION = 0, PRESTACK_MIGRATION, POSTSTACK_MIGRATION
    } migration_type_t;
/*                                                                              */
/* *       codes for type of z value associated with a fault trace point        */
/*                                                                              */

typedef enum 
    {
    Z_VALUE_UNDEFINED = 0,          /* no z value is defined                    */
    Z_VALUE_TIME = 1,               /* z value is time                          */
    Z_VALUE_UNSNAPPED_TIME = 2,     /* z value is unsnapped time                */
    Z_VALUE_DEPTH = 3               /* z value is depth                         */
    } z_value_t;

/*                                                                              */
/* *       masks defining validity of items in struct point                     */
/*                                                                              */

#define        VALID_CDP            1      /* cdp number is valid               */
#define        VALID_SP             2      /* shot point number is valid        */
#define        VALID_X              4      /* x location is valid               */
#define        VALID_Y              8      /* y location is valid               */
#define        VALID_Z             16      /* z location is valid               */

/*                                                                              */
/* *       lengths of name fields in structures                                 */
/*                                                                              */

#define        SURVEY_NAME_LEN     36
#define        SURVEY_DESC_LEN     44
#define        UNITS_SPEC_LEN      24
#define        PROJ_NAME_LEN       32
#define        ELLIPSOID_NAME_LEN  16
#define        DATUM_NAME_LEN      16
#define        LINE_NAME_LEN       44
#define        LINE_DESC_LEN       60
#define        SRF_NAME_LEN        16
#define        SRF_DESC_LEN        44
#define        DATE_LEN            18
#define        Z_NAME_LEN          20

/*                                                                              */
/* *       symbols used in seismic line and trace headers                       */
/*                                                                              */

typedef enum 
    {
    SR_SECS = DB_SR_SECS, SR_HERTZ = DB_SR_HERTZ, SR_OFFSET = DB_SR_OFFSET,
    SR_UKNOWN = DB_SR_UKNOWN
    } sample_int_units_t;

typedef enum 
    {
    TRACE_ORDER_SHOT = DB_TRACE_ORDER_SHOT, TRACE_ORDER_CDP = DB_TRACE_ORDER_CDP,
    TRACE_ORDER_STACK = DB_TRACE_ORDER_STACK, TRACE_ORDER_SEQ = DB_TRACE_ORDER_SEQ
    } trace_order_t;

typedef enum 
    {
    TRACE_OFFSET_FEET = DB_TRACE_OFFSET_FEET,
    TRACE_OFFSET_METERS = DB_TRACE_OFFSET_METERS,
    TRACE_OFFSET_UNKNOWN = DB_TRACE_OFFSET_UNKNOWN
    } trace_offset_units_t;

typedef enum 
    {
    VALID = DB_VALID, NOT_VALID = DB_NOT_VALID
    } offset_valid_t;

typedef enum 
    {
    LIVE_TRACE = DB_LIVE_TRACE, DEAD_TRACE = DB_DEAD_TRACE,
    SWEEP_TRACE = DB_SWEEP_TRACE, NULL_TRACE = DB_NULL_TRACE
    } trace_state_t;

/*                                                                              */
/* *       error codes                                                          */
/*                                                                              */

#define        IES_E_OK             0

/********************************************************************************/
/*                                                                              */
/*                           MACRO DEFINITIONS                                  */
/*                                                                              */
/********************************************************************************/

/* None defined.                                                                */

/********************************************************************************/
/*                                                                              */
/*                   Structure Definitions and Typedefs                         */
/*                                                                              */
/********************************************************************************/

/* Basic to the interchange design is that of a vector structure which is       */
/*  specified by the following declarations:                                    */

typedef enum 
    {
    VEC_TYPE_UNKNOWN = 0,           /* vector type is unknown                   */
    VEC_TYPE_INT = 1,               /* vector type integer                      */
    VEC_TYPE_REAL = 2,              /* vector type real                         */
    VEC_TYPE_CHAR = 3,              /* vector type char                         */
    VEC_TYPE_COMPLEX = 4,           /* vector type complex                      */
    VEC_TYPE_DP = 5,                /* vector type dp precision                 */
    VEC_TYPE_FRAC16 = 6,            /* vector type 16 bit int fraction          */
    VEC_TYPE_FRAC8 = 7,             /* vector type 8 bit int fraction           */
    VEC_TYPE_POINT = 8,             /* vector type struct point                 */
    VEC_TYPE_SURFACE = 9,           /* vector type struct surface               */
    VEC_TYPE_SEGMENT = 10,          /* vector type struct segment               */
    VEC_TYPE_CONTACT = 11,          /* vector type struct contact               */
    VEC_TYPE_F_HORIZON = 12,        /* vector type struct f_horizon             */
    VEC_TYPE_FT_TRACE = 13,         /* vector type struct ft_trace              */
    VEC_TYPE_FT_POINT = 14,         /* vector type struct ft_point              */
    VEC_TYPE_SEIS_TRACE = 15,       /* vector type struct seis_trace            */
    VEC_TYPE_SEIS_LINE = 16,        /* vector type struct seis_line             */
    VEC_TYPE_SEIS_CLASS = 17,       /* vector type struct class                 */
    VEC_TYPE_TOPS = 19,             /* vector type struct tops                  */
    VEC_TYPE_DEV_SURVEY = 20,       /* vector type struct dev_survey            */
    VEC_TYPE_WELL_STRUCT_0 = 21,    /* vector type struct WELL STRUCT           */
    VEC_TYPE_LOG_RUN = 22,          /* vector type struct LOG_RUN_HDR           */
    VEC_TYPE_LOG_PASS = 23,         /* vector type struct LOG_PASS_STRUCT       */
    VEC_TYPE_LOG_SERVICE = 24,      /* vector type struct LOG_SERVICE_STRUCT    */
    VEC_TYPE_WELL_LOG_TRACE = 25    /* vector type struct LOG_TRACE_STRUCT      */
    } vec_type_t;

typedef struct vector_desc
    {
    void *vector_pointer;
    int_t number_elements;
    int_t element_size;
    vec_type_t element_format;
    } VECTOR;

/********************************************************************************/

/* Another structure which is basic to data interchange is that of a single point.  */
/*    The following is the structure for a single point.  A mask will be provided in    */
/*    association with each use of this structure (or vector of this structure) */
/*    indicating which components of the structure are valid.  For example, x and y */
/*    may not be necessary to transfer interpretation.  Further the exact meaning of    */
/*    the elements of this structure will be context dependent (i. e., the z element    */
/*    may contain a time value for interpretation).                             */

typedef struct point_desc
    {
    int_t valid;                    /* Validity mask for station vector:        */
                                    /*       VALID_CDP, VALID_SP,               */
                                    /*   VALID_X, VALID_Y, VALID_Z              */
    real_t cdp;                     /* CDP Number associated with point         */
    real_t shot_point;              /* Shot Point Number associated with        */
                                    /*   point                                  */
    dp_t x;                         /* x coordinate value associated with       */
                                    /*   point                                  */
    dp_t y;                         /* y coordinate value associated with       */
                                    /*   point                                  */
    dp_t z;                         /* z coordinate value associated with       */
                                    /*   point                                  */
    } SEISMIC_DATA_POINT;

/********************************************************************************/

/*   Projection Information                                                     */
/*      ----------------------                                                  */
/*                                                                              */
/*We will assume all location information contained within the seismic data     */
/*sturcture is given in the same coordinate system.  To properly define the     */
/*coordinate system the following two structures are used to specify the        */
/*projection which was used.  the structures are based on the USGS projection   */
/*package. and the projection codes are those used by USGS.                     */

typedef struct proj_data
    {
    int_t usgs_proj_code;
    char units[UNITS_SPEC_LEN];     /* units of distance:                       */
                                    /*"Feet", "Meters"                          */
    int_t proj_zone;                /* projection zone                          */
    dp_t lat_std[2];                /* latitude of std. parallels               */
    dp_t cent_merid;                /* longitude of central meridian            */
    dp_t grid_lat_0;                /* origin of grid                           */
    dp_t grid_long_0;               /* origin of grid                           */
    dp_t false_easting;             /* easting at origin                        */
    dp_t false_northing;            /* northing at origin                       */
    dp_t grid_scale;                /* scale factor                             */
    dp_t scal_lat_0;                /* latitude where scale applies             */
    dp_t scal_long_0;               /* longitude where scale applies            */
    char proj_name[PROJ_NAME_LEN];  /* name of projection                       */
    } PROJECTION;

typedef struct geoid_data
    {
    int_t usgs_geoid_code;
    dp_t geoid_lat_0;               /* latitude of origin                       */
    dp_t geoid_long_0;              /* longitude of origin                      */
    dp_t semi_maj;                  /* semi-major axis                          */
    dp_t r_flat;                    /* reciprocal of flattening of ellipsoid    */
    dp_t defl_vert[2];              /* deflection of vert at datum origin       */
    dp_t geoid_azim;                /* azimuth to another pt.                   */
    dp_t geoid_edif;                /* elev. diff between datum and spheroid    */
    char elipsoid[ELLIPSOID_NAME_LEN];  /* name of reference ellipsoid          */
    char geodatum[DATUM_NAME_LEN];  /* name of geodetic datum                   */
    } GEOID;

/********************************************************************************/

/*    3-D Survey Geometry Specification and Location                            */
/*      ----------------------------------------------                          */
/*                                                                              */
/*The following structure contains the information necessary to specify a 3d    */
/*survey.  If the survey does not exist in the receiving system all of the      */
/*information must be provided.  The survey is assumed to be laid out as a      */
/*regular orthogonal grid of traces so that knowing the location of one trace,  */
/*the trace and line spacing, and the azimuth of the primary lines one can      */
/*compute the location of all of the traces.                                    */

typedef struct location_3d_desc
    {
    int_t status;                   /* Instructions/Completion status           */
    /*    the following are survey geometry specifications                      */
    real_t azim_surv;               /* azimuth of 3-D survey inlines            */
                                    /*(clockwise from north)                    */
    real_t inline_dist;             /* station spacing along azimuth            */
    real_t line_spacing;            /* station spacing against azimuth          */
    rational_t lin1;                /* line # of origin inline line.            */
    rational_t lininc;              /* line number incr                         */
    int_t number_inlines;           /* number of inlines in survey              */
    rational_t cdp1;                /* origin cdp on inline lines.              */
    rational_t cdpinc;              /* cdp increment on inline lines.           */
    int_t number_cdps;              /* number of cdps in each inline            */
    rational_t sp1;                 /* sp of survey origin                      */
    rational_t spinc;               /* sp incr. of survey                       */
    /*    the following are coordinates with which to locate the survey         */
    dp_t x_surv_0;                  /* x coord of a 3-D survey trace            */
    dp_t y_surv_0;                  /* y coord of a 3-D survey trace            */
    rational_t line_no;             /* line no. of trace                        */
    rational_t cdp;                 /* cdp no. of trace                         */
    } SEISMIC_LOCATION_3D;

/********************************************************************************/

/*    2-D Survey Geometry Specification and Location                            */
/*      ----------------------------------------------                          */

typedef struct location_2d_desc
    {
    int_t status;
    cdp_sp_corresp_t cdp_sp_reg_flag;   /* Flag indicates whether or not a regular  */
                                        /* correspondence exists between cdp and sp */
    rational_t cdp_per_sp;          /* Nominal number of cdps per shot point    */
    dp_t shotpoint_interval;        /* Distance between shot points             */
    rational_t cdp1;                /* Initial cdp (index) number               */
    rational_t sp1;                 /* Initial shot point number                */
    rational_t cdpinc;              /* CDP numbering increment                  */
    rational_t spinc;               /* Shot point numbering increment           */
    VECTOR point;                   /* Vector of station location               */
                                    /*       structures                         */
    } SEISMIC_LOCATION_2D;

/********************************************************************************/

/*    Seismic Survey Information                                                */
/*      --------------------------                                              */
/*                                                                              */
/*All seismic related information is specified in a heirarcical structure.  The */
/*top of the heirarcy is a structure which groups the information according to  */
/*surveys.  Surveys may be either 2d groups of line or 3d surveys.  In order to */
/*facilitate memory management, 3d survey data will be organized according to   */
/*lines.  The following defines the survey structure:                           */

typedef struct survey_desc
    {
    char name[SURVEY_NAME_LEN];     /* Name of survey                           */
    char desc[SURVEY_DESC_LEN];     /* Survey description                       */
    survey_type_t svy_type;         /* Survey type:                             */
                                    /*SVY_2D, SVY_3D                            */
    dp_t z_datum;                   /* Datum to use in association with         */
                                    /*   elevations                             */
    char z_units[UNITS_SPEC_LEN];   /* Units of z_datum:                        */
                                    /*"Feet", "Meters"                          */
    dp_t dp_null;                   /* Null value for floating point numbers    */
    int_t int_null;                 /* Null value for integers                  */
    PROJECTION proj;                /* Projection information                   */
    GEOID gd;                       /* Geoid information                        */
    SEISMIC_LOCATION_3D loc;        /* 3d survey specificaton and               */
                                    /*    location structure                    */
    VECTOR seis_line;               /* vector of structures describing lines    */
    } SEISMIC_SURVEY;

/********************************************************************************/

/*    Seismic Data Structures                                                   */
/*      -----------------------                                                 */
/*                                                                              */
/*Seismic data will be contained in the interchange structure as a seismic line */
/*header structure and a vector of trace structures.  The trace structure       */
/*contains a trace header structure and a vector of sample values.              */

typedef struct i_seis_linehead_desc
    {
    sample_int_units_t si_units;    /* units for sampling interval              */
    /* SR_SECS   -- si is in seconds                                            */
    /* SR_HERTZ  -- si is in hertz                                              */
    /* SR_OFFSET -- si is in Offset Units                                       */
    /* SR_UKNOWN -- si is unknown                                               */
    
    trace_order_t trace_order;      /* Trace ordering                           */
    /* TRACE_ORDER_SHOT - shot ordered                                          */
    /* TRACE_ORDER_CDP  - unstacked cdps                                        */
    /* TRACE_ORDER_STACK- stacked cdps                                          */
    /* TRACE_ORDER_SEQ  - trace sequential                                      */
    
    trace_offset_units_t to_units;  /* trace offset units                       */
    /* TRACE_OFFSET_FEET                                                        */
    /* TRACE_OFFSET_METERS                                                      */
    /* TRACE_OFFSET_UNKNOWN                                                     */
    
    offset_valid_t offset_validity; /* offsets are valid                        */
    /* DB_VALID                                                                 */
    /* DB_NOT_VALID                                                             */
    
    real_t trail_offset;            /* trailing trace offset                    */
    real_t lead_offset;             /* leading trace offset                     */
    real_t near_offset;             /* ABS near trace offset                    */
    real_t far_offset;              /* ABS far trace offset                     */
    
    real_t sample_interval;         /* sampling rate                            */
    int_t n_samples;                /* maximum number of samples per trace      */
    int_t n_live_traces;            /* number of live traces                    */
    unsigned long n_live_samps;     /* number of live samples                   */
    
    int_t n_channels;               /* number of channels per record  (1)       */
    int_t n_fold;                   /* stack fold (no. of traces per cdp)       */
    
    real_t shotpoint_interval;      /* distance bewteen shots (offset unit)     */
    real_t receiver_interval;       /* distance between receivers               */
    real_t cdp_interval;            /* distance bewteen cdps                    */
    
    rational_t min_shotpoint;       /* minimum shotpoint                        */
    rational_t max_shotpoint;       /* maximum shotpoint                        */
    rational_t min_receiver;        /* minimum receiver location                */
    rational_t max_receiver;        /* maximum receiver location                */
    rational_t min_cdp;             /* minimum cdp                              */
    rational_t max_cdp;             /* maximum cdp                              */
    
    rational_t lcs_x_incr;          /* increment per trace in lcs               */
    rational_t min_x_lcs;           /* minimum lcs value                        */
    rational_t max_x_lcs;           /* maximum lcs value                        */
    rational_t lcs_y_incr;          /* increment per trace in lcs               */
    rational_t min_y_lcs;           /* minimum lcs value                        */
    rational_t max_y_lcs;           /* maximum lcs value                        */
    
    int_t cdps_valid;               /* linear progression of cdps to lcs        */
    /* DB_VALID                                                                 */
    /* DB_NOT_VALID                                                             */
    rational_t cdp_incr;            /* cdp number increment per trace           */
    int_t shotpoint_valid;          /* linear progression of sps to lcs         */
    /* DB_VALID                                                                 */
    /* DB_NOT_VALID                                                             */
    rational_t shotpoint_incr;      /* shotpoint increment per trace            */
    
    real_t max_amplitude;           /* volume statistics                        */
    real_t min_amplitude;
    real_t max_magnitude;
    real_t min_magnitude;
    real_t rms_amplitude;
    real_t mean_amplitude;
    real_t mean_magnitude;
    migration_type_t migration_type;
    } SEISMIC_LINE_HDR;

/********************************************************************************/

typedef struct i_seis_tracehead_desc
    {
    int_t trace_type;               /* DB_LIVE_TRACE                            */
                                    /* DB_DEAD_TRACE                            */
                                    /* DB_SWEEP_TRACE                           */
                                    /* DB_NULL_TRACE                            */
    rational_t cdp;                 /* common midpoint number (cmp)             */
    int_t cdp_trace_no;             /* cdp trace number                         */
    int_t cdp_fold;                 /* stacking fold at this cdp                */
    rational_t cdp_sp;              /* shotpoint above cdp                      */
    real_t cdp_elevation;           /* cdp elevation in DUs                     */
    real_t cdp_datum;               /* cdp datum in DUs                         */
    real_t cdp_wdepth;              /* depth of weathering layer at CDP         */
    /* location in DUs                                                          */
    real_t cdp_wvel;                /* velocity of weathering layer at CDP      */
    /* location in DUs / second                                                 */
    real_t cdp_x_location;          /* cdp location  x value (DUs)              */
    real_t cdp_y_location;          /* cdp location  y value (DUs)              */
    real_t distance;                /* signed trace distance from shot to       */
    /* receiver with respect to line direction                                  */
    int_t mute_length;              /* length of initial mute is samples        */
    real_t tfs;                     /* time of first sample in sample units     */
    
    rational_t shot_location;       /* shotpoint location number                */
    real_t shot_elevation;          /* shotpoint elevation in DUs               */
    real_t shot_datum;              /* shotpoint elevation datum in DUs         */
    real_t shot_depth;              /* depth of shot in distance units (DUs)    */
    real_t uphole_time;             /* shot uphole time in SI units             */
    real_t shot_wdepth;             /* depth of weathering layer at SP in DUs   */
    real_t shot_wvel;               /* velocity of weathering layer at SP       */
    /* in DUs / per seconds                                                     */
    real_t shot_x_location;         /* shotpoint location  x value (DUs)        */
    real_t shot_y_location;         /* shotpoint location  y value (DUs)        */
    
    rational_t receiver_location;   /* receiver location number                 */
    real_t receiver_elevation;      /* receiver elevation in DUs                */
    real_t receiver_datum;          /* receiver elevation datum in DUs          */
    real_t receiver_wdepth;         /* depth of weathering layer at receiver    */
    /* location in DUs                                                          */
    real_t receiver_wvel;           /* velocity of weathering layer at          */
                                    /* receiver location in DUs / second        */
    real_t receiver_x_location;     /* receiver location  x value (DUs)         */
    real_t receiver_y_location;     /* receiver location  y value (DUs)         */
    
    int_t statics_flag;             /* statics application bit flag             */
    /* 0 - shot W statics computed                                              */
    /* 1 - shot W statics applied                                               */
    /* 2 - receiver W statics computed                                          */
    /* 3 - receiver W statics applied                                           */
    /* 4 - shot D static computed                                               */
    /* 5 - shot D static applied                                                */
    /* 6 - receiver D static computed                                           */
    /* 7 - receiver D static applied                                            */
    /* 8 - shot A static computed                                               */
    /* 9 - shot A static applied                                                */
    /* 10- receiver A static computed                                           */
    /* 11- receiver A static applied                                            */
    /* 12- cdp A static computed                                                */
    /* 13- cdp A static applied                                                 */
    /* 14- bulk static computed                                                 */
    /* 15- bulk static applied                                                  */
    real_t receiver_wstatic;        /* receiver weathering static               */
    real_t receiver_dstatic;        /* receiver datum static                    */
    real_t receiver_astatic;        /* receiver automatic static                */
    real_t shot_wstatic;            /* shot weathering static                   */
    real_t shot_dstatic;            /* shot datum static                        */
    real_t shot_astatic;            /* shot automatic static                    */
    real_t cdp_astatic;             /* cdp automatic static                     */
    real_t bulk_static;             /* bulk static                              */
    
    int_t record_no;                /* sequential record number                 */
    int_t record_trace_no;          /* record trace number                      */
    int_t field_record_no;          /* field record number                      */
    int_t field_record_trace_no;
    
    int_t n_live;                   /* number of non-zero samples               */
    real_t max_amplitude;           /* maximum signed amplitude                 */
    real_t min_amplitude;           /* minimum signed amplitude                 */
    real_t max_magnitude;           /* maximum magnitude                        */
    real_t min_magnitude;           /* minimum magnitude                        */
    real_t mean_amplitude;          /* mean trace amplitude                     */
    real_t mean_magnitude;          /* mean magnitude of trace                  */
    real_t rms_amplitude;           /* rms amplitude of trace                   */
    
    real_t minimum_scalar;          /* scalar value used in scaling data to     */
    real_t maximum_scalar;          /* fraction values                          */
    
    int_t user_1;                   /* user trace header values                 */
    int_t user_2;
    int_t user_3;
    int_t user_4;
    } TRACE_HDR_T;

/********************************************************************************/

typedef struct i_seis_trace_desc
    {
    TRACE_HDR_T header;             /* Structure containing trace header        */
    VECTOR samples;                 /* Vector of seismic trace samples          */
                                    /*(see vector descriptor for sample format) */
    } SEISMIC_TRACE;

/********************************************************************************/

/*    Line Description Structure                                                */
/*      --------------------------                                              */
/*                                                                              */
/*All surveys are organized as a series of lines and the survey structure       */
/*includes a vector of line structures of the following form.  Each line may have   */
/*several variants usually depending on any processes which have been applied to*/
/*the data to alter its presentation or to extract some quality of interest.    */
/*Therefore the line structure contains location information and a vector of    */
/*classes.  There may be many types of data related to a line class.  Each type */
/*will have a structure ( or vector of structures ) in which that type of data  */
/*is stored.  Included in the current proposal is a vector of interpreted       */
/*surfaces and seismic trace data.                                              */

typedef struct seismic_line_desc
    {
    line_type_t line_type;          /* Line type:                               */
                                    /*    LINE_2D, LINE_3DI, LINE_XLN,          */
                                    /*    LINE_TSL, LINE_RCN                    */
    char line_name[LINE_NAME_LEN];  /* 2d or reconstruction cut line name       */
    int_t line_number;              /* Line number(required for LINE_3DI, LINE_XLN) */
    char line_desc[LINE_DESC_LEN];  /* Line description                         */
    int_t status;                   /* Instructions/Completion status           */
    
    VECTOR seismic_class;           /* Vector of seismic line variants          */
                                    /*       delineated according to class      */
    SEISMIC_LOCATION_2D loc;        /* LINE_2D, LINE_RCN types only             */
    } SEISMIC_LINE;

/********************************************************************************/

typedef struct seismic_class_desc
    {
    char class_name[LINE_NAME_LEN]; /* User assigned class name                 */
    char class_desc[LINE_DESC_LEN]; /* Class description                        */
    int_t status;                   /* Instructions/Completion status           */
    SEISMIC_LINE_HDR seis_line_hdr; /* Structure containing seismic line        */
                                    /*   header                                 */
    VECTOR seis_trace;              /* Vector of seismic traces                 */
    VECTOR surface;                 /* Vector of surfaces being output          */
    } SEISMIC_CLASS;

/********************************************************************************/

/*    Interpreted Surface Structure                                             */
/*      -----------------------------                                           */
/*                                                                              */
/*It will be assumed that there are two basic types of surfaces, horizons and   */
/*faults (or fault cuts).  Along any line there may be line segments indicating */
/*where the surface has been interpreted and there may be information indicating*/
/*where two surfaces contact each other.  Additionally, the segments may have   */
/*different data depending on the z value contained therein.  For example, the  */
/*user may have interpreted a horizon along a range of cdps and saved the time  */
/*values at which the horizon occured.  He may have also saved the seismic trace*/
/*amplitude at that time.  Segments containing both time and containing amplitude   */
/*may be stored for a given surface.                                            */

/*  This structure contains information specifying points along the surface at  */
/*    which the user has indicated that it intersects another surface.  The structure   */
/*    includes the location of the intersection and information about the       */
/*    intersecting structure.                                                   */

typedef struct surface_desc
    {
    surface_type_t surface_type;    /* Surface type:                            */
                                    /*    SRF_TYPE_HOR, SRF_TYPE_FLT            */
    char surface_name[SRF_NAME_LEN];    /* Surface name                         */
    char surface_des[SRF_DESC_LEN]; /* Surface description                      */
    char modified_date[DATE_LEN];   /* Last modification date/time              */
    
    /* The following are applicable only to horizon surfaces                    */
    snap_event_t snap_event;        /* Snap event:                              */
                                    /*    SNAP_P_NEAR, SNAP_P_MAX,              */
                                    /*    SNAP_T_NEAR, SNAP_T_MAX,              */
                                    /*    SNAP_ZPN,    SNAP_ZNP,                */
                                    /*    SNAP_NULL,   SNAP_UNDEFINED           */
    real_t snap_window;             /* Duration of snapping window in           */
                                    /*   seconds                                */
    int_t status;                   /* Instructions/Completion status           */
    VECTOR segment;                 /* Vector of interpretation                 */
                                    /*   segments for line                      */
    VECTOR contact;                 /* Vector of contact points                 */
                                    /*   associated with this surface           */
                                    /*   on this line                           */
    } SEISMIC_SURFACE;

/********************************************************************************/

typedef struct contact_desc
    {
    real_t cdp;                     /* CDP number of contact point              */
    real_t time;                    /* Time at which contact occurs             */
    surface_type_t surface_type_2;  /* Surface type:                            */
                                    /*   SRF_TYPE_HOR, SRF_TYPE_FLT,            */
                                    /*   SRF_TYPE_UNKNOWN                       */
    char name_2[SRF_NAME_LEN];      /* second name associated with              */
                                    /*   contact                                */
    } CONTACT;

/********************************************************************************/

typedef struct segment_desc
    {
    int_t seg_id;                   /* Number identifying segment               */
    z_type_t z_type;                /* Type of z data in point vector:          */
                                    /*   TIME_UNSNAPPED, TIME_REFINED, AMPLITUDE*/
    VECTOR point;                   /* Vector of points in interpretation       */
                                    /*           segment                        */
    } SEGMENT;

/********************************************************************************/

/*    Fault Traces                                                              */
/*      ------------                                                            */
/*                                                                              */
/*Fault traces are interpreted information defining the map view of the         */
/*intersection of faults with a particular surface.  The interpretation is      */
/*usually done on a map and cannot be organized on a line by line basis or, for */
/*that matter, on a survey basis.  Fault trace interpretation, thereforme, must */
/*be kept in a structure separate from the survey structure described above and */
/*transmitted seperately.  The following structures will be used to contain and */
/*transmit fault trace information.  The top structure contains information     */
/*necessary to define the coordinate system of the data contained in the        */
/*structure and a vector of horizon structures for which fault trace information*/
/*is transmitted.                                                               */

/*  Each horizon may have intersections with many faults.  The following        */
/*    structure names a vector of fault traces for a specified horizon.         */

typedef struct ftrace_desc
    {
    dp_t z_datum;                   /* Datum to use in association with         */
                                    /*       elevations                         */
    char z_units[UNITS_SPEC_LEN];   /* Units of z_datum:                        */
                                    /*"Feet", "Meters"                          */
    
    dp_t dp_null;                   /* Null value for floating point numbers    */
    int_t int_null;                 /* Null value for integers                  */
    PROJECTION proj;                /* Projection information                   */
    GEOID gd;                       /* Geoid information                        */
    
    VECTOR f_horizon;               /* Vector of structures of horizons         */
                                    /*having fault traces defined               */
    } SEISMIC_FTRACE;

/********************************************************************************/

typedef struct f_horizon_desc
    {
    char horizon_name[SRF_NAME_LEN];    /* Name of horizon for which            */
                                        /*traces are defined                    */
    
    int_t status;                   /* Instructions/Completion status           */
    
    VECTOR seismic_ft_trace;        /* Vector of structures defining fault traces   */
    } F_HORIZON;

/********************************************************************************/

/*  The following fault trace vector specifies the name of the intersecting fault   */
/*    and names the vector containing the points associated with the            */
/*    intersection.                                                             */

typedef struct ft_trace_desc
    {
    char fault_name[SRF_NAME_LEN];  /* Name of fault whose intersection         */
                                    /*with the horizon this trace describes     */
    int_t ft_seg_id;                /* segment id for fault trace for a given   */
                                    /*            horizon                       */
    z_value_t z_value_code;         /* z value code:                            */
                                    /*Z_VALUE_TIME,                             */
                                    /*Z_VALUE_UNSNAPPED_TIME,                   */
                                    /*Z_VALUE_DEPTH                             */
    VECTOR ft_point;                /* Vector of structures defining fault trace points */
    } SEISMIC_FT_TRACE;

/********************************************************************************/

/*  Nominally only the x and y values are meaningful.  However, some interpretation */
/*    systems attempt to maintain a z value associated with the x and y values and  */
/*    provision for transmitting that information is included.                  */

typedef struct ft_point_desc
    {
    int_t valid;                    /* Validity mask for fault trace vector:    */
                                    /*               VALID_X, VALID_Y, VALID_Z  */
    dp_t x;                         /* x value associated with fault trace point*/
    dp_t y;                         /* y value associated with fault trace point*/
    dp_t z;                         /* z value associated with fault trace point*/
    } FT_POINT;

/********************************************************************************/
/*                                                                              */
/*                          LOCATION STRUCTURES                                 */
/*                                                                              */
/********************************************************************************/
typedef struct 
    {
    dp_t decimal;
    struct 
        {
        int_t degrees;
        int_t minutes;
        dp_t seconds;
        } dms;
    } LATLONG_T;

typedef struct 
    {
    dp_t x;
    dp_t y;
    LATLONG_T latitude;
    LATLONG_T longitude;
    int_t projection_id;
    NODE_ID_T node_id;
    } XYNODE_T;

typedef struct 
    {                               /* structure describing legal description of well   */
    int_t meridian_code;            /* PRINCIPAL_MERIDIAN code number           */
    real_t township;                /* township number                          */
    char twpns[4];                  /* 'N' or 'S' of survey base line           */
    real_t range;                   /* range number                             */
    char rngew[4];                  /* 'E' or 'W' of survey principal meridian  */
    real_t section;                 /* section number in township               */
    char section_type[8];           /* type of 'section' (NULL = section, 'LOT', etc    */
    real_t nsfootage;               /* footage in north-south direction         */
    char ns[4];                     /* reference line of north-south footage ('FEL','FWL')  */
    real_t ewfootage;               /* footage in ease-west direction           */
    char ew[4];                     /* reference line of east-west footage ('FNL','FSL')    */
    char spot[12];                  /* Point in section from which measurements are references  */
    char abstract[8];               /* (Texas only) Abstract ID                 */
    char state[4];                  /* State or province abbreviation           */
    char country[4];                /* Country abbreviation                     */
    char county[24];                /* County, district, parrish name           */
    } LEGAL_T;

/********************************************************************************/
/*                                                                              */
/*                             GENERAL STRUCTURES                               */
/*                                                                              */
/********************************************************************************/
typedef struct 
    {                               /* structure for defining well depths       */
    real_t md;                      /* measured depth                           */
    real_t ss;                      /* sub-sea depth                            */
    real_t tvd;                     /* true vertical depth                      */
    real_t time;                    /* time                                     */
    real_t dx;                      /* X deviation from top-hole position       */
    real_t dy;                      /* Y deviation from top-hole position       */
    } DEPTHS_T;

typedef struct 
    {                               /* structure for lithostrat codes           */
    char Code[16];                  /* Formation code of the lithostratigraphic unit    */
    char Age[8];                    /* Client-specified age code of lithostratigraphic unit */
    } LITHOSTRAT_T;

typedef struct 
    {
    real_t value;
    UNIT_T unit;
    } MEASUREMENT_T;

#ifndef ESI_WE_WELLS_H
typedef enum 
    {
    WE_LOCATION_ONLY, WELL_HDR_1_DETAIL, WELL_HDR_2_DETAIL
    } WELL_HDR_DETAIL;
#endif

/********************************************************************************/
/*                                                                              */
/*                              WELL LIST                                       */
/*                                                                              */
/********************************************************************************/

typedef struct 
    {
    PROJECTION proj;                /* Projection information                   */
    GEOID gd;                       /* Geoid information                        */
    UNIT_T z_units;                 /* Units of all depths:                     */
                                    /*    "Feet", "Meters", etc                 */
    dp_t dp_null;                   /* Null value for floating point numbers    */
    int_t int_null;                 /* Null value for integers                  */
    VECTOR well_struct_0;           /* vector of structures describing wells    */
    } WELL_LIST;

/********************************************************************************/
/*                                                                              */
/*                            WELL STRUCTURE 0                                  */
/*                                                                              */
/********************************************************************************/

typedef struct 
    {                               /* structure defining minimum well information  */
    UWI_T uwi;                      /* Unique Well Identifier                   */
    int_t symbol_code;              /* Plot symbol code                         */
    XYNODE_T tophole_xy;            /* structure defining coordinates of top hole position  */
    XYNODE_T bottomhole_xy;         /* structure defining coordinates of bottom hole position   */
    
    struct 
        {
        int_t flag;                 /* well_hdr column DEVIATION_FLAG, domain code ??   */
        VECTOR depth;               /* measured depth                           */
        VECTOR dx;                  /* east-west offset from top hole position  */
        VECTOR dy;                  /* north-south offset from top hole position*/
        } deviation;
    
    struct 
        {
        VOIDPTR_T ptr;
        WELL_HDR_DETAIL type;
        } detail;
    } WELL_STRUCT_0;

/********************************************************************************/
/*                                                                              */
/*                            WELL STRUCTURE 1                                  */
/*                                                                              */
/********************************************************************************/

typedef struct 
    {                               /* WELL_HDR_1_DETAIL type                   */
    WELL_NAME_T name;               /* Full legal name of well lease            */
    WELL_NUMBER_T number;           /* Well permit number within lease          */
    char plot_name[24];             /* Shortened name of well lease for plotting*/
    char short_name[24];            /* Shortened or informal name of well       */
    char operator[16];              /* Name of well operator                    */
    char class [16];                /* Well classification (e.g. LAHEE class.)  */
    char crstatus[16];              /* Current well status                      */
    LEGAL_T tophole;                /* structure describing legal status of the tophole */
    LEGAL_T bottomhole;             /* structure describing legal status of the bottomhole  */
    struct 
        {                           /* structure defining offshore specific wells   */
        real_t water_depth;         /* Water depth                              */
        } offshore;
    struct 
        {                           /* structure describing reference well elevation    */
        real_t value;               /* Elevation to use for subsea corrections  */
        char ref[8];                /* Data type being used as elevation (kb, df, gs, etc)  */
        } elevation;
    char primary_source[16];        /* Source of the well information           */
    DATE_T Spud_Date;               /* Date the well was spudded                */
    DATE_T Comp_Date;               /* Date the well was completed              */
    struct 
        {                           /* structure defining depths of driller, logger, and plugback   */
        DEPTHS_T driller;           /* structure describing driller depths      */
        DEPTHS_T logger;            /* structure describing logger depths       */
        LITHOSTRAT_T formation;     /* structure describing formation at TD     */
        } td;
    
    } WELL_STRUCT_1;

/********************************************************************************/
/*                                                                              */
/*                            WELL STRUCTURE 2                                  */
/*                                                                              */
/********************************************************************************/

typedef struct 
    {                               /* WELL_HDR_2_DETAIL type                   */
    WELL_NAME_T name;               /* Full legan name of well lease            */
    WELL_NUMBER_T number;           /* Well permit number within lease          */
    char plot_name[24];             /* Shortened name of well lease for plotting*/
    char short_name[24];            /* Shortened or informal name of well       */
    
    char operator[16];              /* Name of well operator                    */
    char licensee[16];              /* Licensee of well lease                   */
    char agent[16];                 /* Name of agent                            */
    
    /* Class and status information                                             */
    char class [16];                /* Well classification (e.g. LAHEE class.)  */
    char crstatus[16];              /* Current well status                      */
    char orstatus[16];              /* Original well status                     */
    char prstatus[16];              /* Previous well status                     */
    
    /* Location information                                                     */
    int_t location_type;            /*                                          */
    char location_table[32];        /* Name of table/file containing additional location information    */
    LEGAL_T tophole;                /* structure describing legal status of the tophole */
    LEGAL_T bottomhole;             /* structure describing legal status of the bottomhole  */
    
    struct 
        {                           /* structure defining offshore specific wells   */
        real_t water_depth;         /* Water depth                              */
        char platform_name[32];     /* Name of offshore drilling platform       */
        char offshore_block[12];    /* Offshore block number                    */
        char utm_grid_block[8];     /* Universal Transverse Mercator block identifier   */
        int_t ocs_number;
        } offshore;
    
    /* Total depth information                                                  */
    struct 
        {                           /* structure defining depths of driller, logger, and plugback   */
        DEPTHS_T driller;           /* structure describing driller depths      */
        DEPTHS_T logger;            /* structure describing logger depths       */
        DEPTHS_T plugback;          /* structure describing plugback depths     */
        LITHOSTRAT_T formation;     /* structure describing formation at TD     */
        } td;
    
    /* Field information                                                        */
    struct 
        {                           /* structure describing field code and name */
        char code[16];              /* Code identifier for field                */
        char name[24];              /* Name of field                            */
        } field;
    char fldpoolwild[16];           /* Field Name, Pool Name or Wildcat         */
    
    /* Elevation information                                                    */
    struct 
        {                           /* structure describing reference well elevation    */
        real_t value;               /* Elevation to use for subsea corrections  */
        char ref[8];                /* Data type being used as elevation (kb, df, gs, etc)  */
        } elevation;
    real_t Ground_Elevation;        /* ground elevation                         */
    real_t kb_elevation;            /* kelly bushing elevation                  */
    real_t cf_elevation;            /* casing flange elevation                  */
    char water_ref[8];              /* water reference code (offshore only)     */
    
    /* Checkshot information                                                    */
    struct 
        {
        dp_t datum;                 /* datum used for checkshot                 */
        dp_t vsd;                   /* velocity surface to datum                */
        int_t one_or_two_way_time;  /* 1 = 1-way, 2 = two-way time              */
        UNIT_T time_unit;           /* Unit of time vector                      */
        VECTOR depth;               /* measured depth                           */
        VECTOR time;                /* time                                     */
        } checkshot;
    
    /* Drilling information                                                     */
    struct 
        {                           /* structure defining drilling contractor and rig number    */
        char contractor[16];        /* name of drilling contractor              */
        char rig_number[8];         /* drilling rig number or identifier        */
        } drilling;
    
    /* Miscellaneous Information                                                */
    char primary_source[16];        /* Name of source of well information       */
    STRATCOL_T stratcolumn;         /* name of strat column to use for this well*/
    UNIT_T orig_units;              /* Original units system that data was collected in */
    char proprietary;               /* Y = this well contains proprietary informaiton   */
    char discover_well;             /* Y = this is the discovery field for the field    */
    char fault;                     /* Y = this well has a faulted section      */
    
    /* Confidence Information                                                   */
    struct 
        {
        int_t index;                /* confidence index number                  */
        real_t ratio;               /* confidence ratio                         */
        int_t level;                /* confidence level                         */
        } confidence;
    
    /* Confidentiality Information                                              */
    char conf_flag;                 /* confidentiality flag                     */
    char conf_form[16];             /* confidentiality formation                */
    real_t conf_depth;              /* confidentiality depth                    */
    DATE_T conf_rel_dt;             /* confidential release date                */
    
    /* Dates                                                                    */
    DATE_T Last_Update;             /* date/time of last update                 */
    DATE_T Spud_Date;               /* spud date                                */
    DATE_T Comp_Date;               /* completion date                          */
    DATE_T rigrel;                  /* rig release date                         */
    DATE_T onprod;                  /* on production date                       */
    DATE_T calc_onprod;             /* calculated on production date            */
    DATE_T oninject;                /* on injection date                        */
    DATE_T status_date;             /* date last status was entered             */
    DATE_T fin_drill;               /* final drilling date                      */
    
    VERSION_T Version;              /* version number of this data structure    */
    BOOLEAN_T updated;              /* TRUE if this well structure has been updated */
    
    /* Headers (tree-tops) for other well data classes                          */
    VECTOR top_struct;              /* vector for well tops                     */
    VECTOR log_run_hdr;             /* vector for well log runs                 */
    
    } WELL_STRUCT_2;

/********************************************************************************/
/*                                                                              */
/*                                TOP STRUCTURE                                 */
/*                                                                              */
/********************************************************************************/
typedef struct 
    {                               /* Formation top description                */
    LITHOSTRAT_T Marker;            /* structure describing formation and age codes */
    DEPTHS_T Depth;                 /* structure defining depths                */
    ANALYST_NAME_T Source;          /* source of interpretation                 */
    char Comment[8];                /* comments describing nature of pick       */
    char Best_Pick;                 /* Y = this is best available information   */
    char Quality;                   /* Quality code of pick                     */
    DATE_T Last_Update;             /* date this interpretation made            */
    real_t Measured_Thickness;      /* uncorrected for geometry                 */
    BOOLEAN_T updated;              /*                                          */
    } TOP_STRUCT_T;

/********************************************************************************/
/*                                                                              */
/*                             LOG TRACE STRUCTURE                              */
/*                                                                              */
/********************************************************************************/

#ifndef ESI_LG_LDEFS_H
typedef char LOG_DEPTH_OR_TIME[8];  /* Depth or time notation                   */
typedef char LOG_TRACE_NAME[64];    /* Standard composite trace name            */
typedef char LOG_SOURCE[16];        /* Source of the trace data.                */
typedef char LOG_TRACE[16];         /* Log Trace name                           */
typedef char LOG_SERVICE[16];       /* Logging service name or modifier         */
typedef int_t LOG_VERSION;          /* Log Run number or trace version          */
typedef char LOG_COMMENT[244];      /* Operator entered comments                */
typedef int_t LOG_TRACE_ID;         /* The log trace sequence number            */
#define DEPTH_IN_TIME       1
#define DEPTH_IN_DISTANCE   2

#endif
typedef MEASUREMENT_T TEMPERATURE;
typedef MEASUREMENT_T RESISTIVITY;
typedef MEASUREMENT_T WEIGHT;
typedef struct 
    {
    RESISTIVITY rm;
    RESISTIVITY rmf;
    RESISTIVITY rmc;
    char source[16];
    } RESISTIVITY_STRUCT;

typedef struct 
    {
    LOG_TRACE_ID trace_id;
    LOG_TRACE trace;
    LOG_SOURCE source;
    LOG_VERSION version;
    LOG_COMMENT comments;
    real_t non_null_top;            /* Top of trace data interval               */
    real_t non_null_base;           /* Base of trace data interval              */
    real_t min;                     /* Minimum trace value                      */
    real_t max;                     /* Maximum trace value                      */
    int_t depth_type;               /* DEPTH_IN_DISTANCE, DEPTH_IN_TIME         */
    real_t dinc;                    /* Digitizing increment                     */
    UNIT_T depth_uom;               /* Units of depth measurement               */
    UNIT_T trace_uom;               /* Units of value                           */
    VECTOR depth;
    VECTOR value;
    } LOG_TRACE_STRUCT_T;

typedef struct 
    {
    /* A service is also loosely called a logging tool.                         */
    /*Several services may be used in a single pass                             */
    LOG_SERVICE service;
    char tool_id[16];
    int_t sequence;
    VECTOR log_trace_struct;
    } LOG_SERVICE_STRUCT;

typedef struct 
    {
    /* A pass is a single Trip of the tool string.                              */
    /*There is usually more than one pass per run                               */
    int_t pass_number;
    DATE_T pass_date;
    real_t top;
    real_t base;
    VECTOR log_service_struct;
    } LOG_PASS_STRUCT;

typedef struct 
    {
    /* A log run is a visit by a logging company to a drilling site.            */
    /*It usually is associated with a single billing cycle                      */
    int_t run_number;
    char logging_company[24];
    DATE_T run_date;
    int_t logging_unit_number;
    char logging_unit_loc[24];
    char recorder[44];
    char witness[44];
    struct 
        {
        DEPTHS_T driller;
        DEPTHS_T logger;
        char size[12];
        WEIGHT weight;
        char bit_size[12];
        UNIT_T bit_size_unit;
        } casing_data;
    struct 
        {
        MEASUREMENT_T density;
        MEASUREMENT_T viscosity;
        MEASUREMENT_T fluid_loss;
        real_t pH;
        RESISTIVITY_STRUCT resistivity;
        RESISTIVITY_STRUCT resistivity_bht;
        } mud_data;
    int_t time_circ_stopped;
    int_t time_logger_on_bottom;
    MEASUREMENT_T max_rec_temp;
    VECTOR log_pass_struct;
    } LOG_RUN_HDR;

/********************************************************************************/
/*                                                                              */
/*                            XYZ (Scatter) DATA                                */
/*                                                                              */
/********************************************************************************/

typedef struct 
    {
    PROJECTION proj;                /* Projection information                   */
    GEOID gd;                       /* Geoid information                        */
    
    UNIT_T uom;                     /* Units of measurement for contours:       */
                                    /*   Feet, Meters, Seconds, etc.            */
    UNIT_T typ_dat;                 /* Type of contour-data: Distance,          */
                                    /*   time, etc.                             */
    dp_t xyz_null;                  /* null value for x, y or z value           */
    
    struct 
        {
        dp_t xmin;
        dp_t ymin;
        dp_t zmin;
        
        dp_t xmax;
        dp_t ymax;
        dp_t zmax;
        } extent;
    
    VECTOR x;                       /* Vector of x-coordinate values (4 or 8 byte floats)   */
    VECTOR y;                       /* Vector of y-coordinate values (4 or 8 byte floats)   */
    VECTOR z;                       /* Vector of z-values (4 or 8 byte floats)  */
    
    VECTOR connect;                 /* Connectivity vector.  If sequences       */
                                    /*   of data points are intended to be      */
                                    /*   connected together, then this vector   */
                                    /*   will be filled.  Normally, this would  */
                                    /*   take the form of one 'connect' value   */
                                    /*   for each x,y,z value and would         */
                                    /*   consist of sequential integer values.  */
                                    /*   All points intended to be grouped      */
                                    /*   together would have the same           */
                                    /*   'connect' value. '0' would indicate a  */
                                    /*   scatter point not connected to any     */
                                    /*   other point.  This vector need not be  */
                                    /*   filled for no connected data values.   */
                                    /*   (4 byte integer)                       */
    
    } XYZ_DATA;

/********************************************************************************/
/*                                                                              */
/*                                 GRID DATA                                    */
/*                                                                              */
/********************************************************************************/

typedef struct 
    {
    PROJECTION proj;                /* Projection information                   */
    GEOID gd;                       /* Geoid information                        */
    dp_t grid_null;                 /* null value for grid                      */
    
    UNIT_T uom;                     /* Units of measurement for z:              */
                                    /*   Feet, Meters, Seconds, etc.            */
    UNIT_T typ_dat;                 /* Type of z-data: Distance,                */
                                    /*   time, etc.                             */
    /* Basic grid parameters:                                                   */
    /* xmin, ymin, xmax, ymax, row-grid distance, col-grid distance             */
    /* Note: range values in order min-to-max.  Positive row increment          */
    /* for non-rotated grid assumed to increase in positive y-direction.        */
    /* Positive column increment for non- rotated grid assumed to increase in   */
    /* positive x-direction.  Varying the sign of the row,col increments is the */
    /* mechanism for systems utilizing some corner of the grid other than the   */
    /* lower left corner as the grid origin.                                    */
    
    struct 
        {
        dp_t xmin;
        dp_t ymin;
        dp_t zmin;
        
        dp_t xmax;
        dp_t ymax;
        dp_t zmax;
        } extent;
    
    dp_t row_distance;              /* distance between rows                    */
    dp_t col_distance;              /* distance between columns                 */
    
    real_t angle;                   /* Grid rotation angle measured from the    */
                                    /*   horizontal.  Angles are in degrees     */
                                    /*   and open positively in the counter     */
                                    /*   clockwise direction.                   */
    int_t nrows;                    /* Number of rows in the grid.              */
    int_t ncols;                    /* Number of columns in the grid.           */
    int_t fl_honored;               /* Faults honored during gridding flag.     */
                                    /*   0: Fault information not used.         */
                                    /*   1: Fault information was used.         */
    VECTOR zvals;                   /* Grid values: Storage order is row 1      */
                                    /*   to row 'nrows' of column 1 followed    */
                                    /*   by the row values of columns 2         */
                                    /*   through column 'ncols' (4 or 8 byte floats)    */
    
    VECTOR xvals;                   /* x-values corresponding to z-values (4 or 8 byte floats)  */
    VECTOR yvals;                   /* y-values corresponding to z-values (4 or 8 byte floats)  */
    } GRID;

/********************************************************************************/
/*                                                                              */
/*                              CONTOUR DATA                                    */
/*                                                                              */
/********************************************************************************/

typedef struct contour_desc
    {
    PROJECTION proj;                /* Projection information                   */
    GEOID gd;                       /* Geoid information                        */
    
    UNIT_T uom;                     /* Units of measurement for contours:       */
                                    /*   Feet, Meters, Seconds, etc.            */
    UNIT_T typ_dat;                 /* Type of contour-data: Distance,          */
                                    /*   time, etc.                             */
    
    struct 
        {
        dp_t xmin;
        dp_t ymin;
        dp_t zmin;
        
        dp_t xmax;
        dp_t ymax;
        dp_t zmax;
        } extent;
    
    int_t inc_type;                 /* Type contour incrementing used.          */
                                    /*   0: User specified contour range        */
                                    /*      defined by low contour value,       */
                                    /*      high contour value and contour      */
                                    /*      increment.                          */
                                    /*   n: n-contour values specified          */
                                    /*      explicitly by value.                */
    VECTOR inc_levels;              /* Vector of user specified contour         */
                                    /*   levels.  The number of levels does not */
                                    /*   necessarily match the actual z values  */
                                    /*   See 'inc_type' above. (4 or 8 byte float)  */
    
    VECTOR z_vals;                  /* Z-values for each contour segment        */
                                    /*   stored.  The number of Z values matches*/
                                    /*   the number of segments described       */
                                    /*   in the endpts vector.  The number of Z values  */
                                    /*   does not necessarily match the         */
                                    /*   number of levels described in inc_levels   */
                                    /*   (4 or 8 byte float)                    */
    VECTOR endpts;                  /* Vector of zero-based indices in x,y-coordinate   */
                                    /*   arrays where each contour segment      */
                                    /*   terminates.  Each value stored in      */
                                    /*   'endpts' is associated with the        */
                                    /*   corresponding contour level stored     */
                                    /*   in 'z_vals'.  (4 byte integer)         */
    VECTOR x;                       /* Vector of contour x-coordinate           */
                                    /*   values. (4 or 8 byte floats)           */
    VECTOR y;                       /* Vector of contour y-coordinate           */
                                    /*   values. (4 or 8 byte floats)           */
    } CONTOUR;

/********************************************************************************/
/*                                                                              */
/*                            EXTERN VARIABLES                                  */
/*                                                                              */
/********************************************************************************/

/* None defined.                                                                */

/********************************************************************************/
/*                                                                              */
/*                          FUNCTION PROTOTYPES                                 */
/*                                                                              */
/********************************************************************************/

#if USE_PROTOTYPES
extern int_t c_put_well_ies (WELL_LIST *well_list, opt_list_t *options_ptr,
                             int_t *status_ptr);
extern int_t c_put_seis_ies (SEISMIC_SURVEY *seis_struc_ptr, opt_list_t *options_ptr,
                             int_t *status_ptr);
extern int_t c_put_ftrace_ies (SEISMIC_FTRACE *ftrace_struc_ptr,
                               opt_list_t *options_ptr, int_t *status_ptr);
extern char *ies_error_text (int_t status);
extern int_t c_put_seis_finder (SEISMIC_SURVEY *seis_struc_ptr,
                                opt_list_t *options_ptr, int_t *status_ptr);
extern int_t c_put_ftrace_finder (SEISMIC_FTRACE *ftrace_struc_ptr,
                                  opt_list_t *options_ptr, int_t *status_ptr);

#else
extern int_t c_put_well_ies ();
extern int_t c_put_seis_ies ();
extern int_t c_put_ftrace_ies ();
extern char *ies_error_text ();
extern int_t c_put_seis_finder ();
extern int_t c_put_ftrace_finder ();

#endif

/********************************************************************************/
/*                                                                              */
/*                    END OF INCLUDE FILE INTERFACE.H                           */
/*                                                                              */
/********************************************************************************/
#endif
