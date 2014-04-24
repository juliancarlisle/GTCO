/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WE_WELLS.H*/
/* *11   17-MAY-1991 17:55:52 DOUG "(SPR 8029) Case #2380,2385 Enlarge WELL_NAME, WELL_NUMBER, abstract, crstatus, orstatus and*/
/*prstatus to match DB"*/
/* *10    1-MAY-1991 12:16:06 KEE "(SPR -1) Landmark Import/Export, Zycor Export and Mimic Export "*/
/* *9    14-AUG-1990 11:51:46 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *8     6-MAR-1990 16:17:02 WALTERS "(SPR 0) Change prototype for we_show_wells_server"*/
/* *7     9-FEB-1990 16:14:22 WALTERS "(SPR 0) Fix prototype"*/
/* *6     8-FEB-1990 13:54:53 WALTERS "(SPR 0) Add prototypes"*/
/* *5    18-JAN-1990 08:48:43 GILLESPIE "(SPR 6001) More changes for new well structs"*/
/* *4    17-JAN-1990 23:53:30 GILLESPIE "(SPR 6001) Add WELL_HDR_1 and WELL_HDR_2"*/
/* *3    17-JAN-1990 17:17:28 GILLESPIE "(SPR 6001) Changes to separate data from display attributes"*/
/* *2    27-NOV-1989 11:17:12 CONROY "(SPR 5063) Add short struct, modify full struct"*/
/* *1    30-JUN-1989 15:05:36 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WE_WELLS.H*/
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

#ifndef ESI_WE_WELLS_H
#define ESI_WE_WELLS_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_GL_TOP_H
#include "esi_gl_top.h"
#endif

/* The above file defines the following data types:
    NODE_ID
    LATLONG
    XYNODE
 */

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif
			/* 17-May-91 DJC changed WELL_NAME from 32 -> 52    */
			/*  and WELL_NUMBER from 16 -> 24 bytes to match DB */

typedef char WELL_NAME[52]; /* db char(50) */
typedef char WELL_NUMBER[24];   /* db char(20) */
typedef char STRATCOL[32];

typedef struct {        /* structure for defining well depths */
    FLOAT md;           /* measured depth */
    FLOAT ss;           /* sub-sea depth */
    FLOAT tvd;          /* true vertical depth */
    FLOAT time;         /* time */
    FLOAT dx;           /* X deviation from top-hole position */
    FLOAT dy;           /* Y deviation from top-hole position */
    } DEPTHS ;

typedef struct {        /* structure for lithostrat codes */
    CHAR Code[16];      /* lithostrat_codes column CODE char(12), domain code 5 */
    CHAR Age[8];        /* lithostrat_codes column AGE_CODE char(6), domain code 29 */
    } LITHOSTRAT ;

typedef struct {        /* structure describing legal description of well */
    INT meridian_code;  /* well_location column PRINCIPAL_MERIDIAN, domain code 65 */
    INT township;       /* well_location column TOWNSHIP, domain code 2 */
    CHAR twpns[4];      /* well_location column NORTH_SOUTH char(1), domain code 92 */
    INT range;          /* well_location column RANGE, domain code 3 */
    CHAR rngew[4];      /* well_location column EAST_WEST char(1), domain code 92 */
    INT section;        /* well_location column SECTION, domain code ?? */
    CHAR section_type[8];   /* well_location column SECTION_TYPE char(4), domain code ?? */
    FLOAT nsfootage;    /* well_location column NS_FOOTAGE, domain code ?? */
    CHAR ns[4];         /* well_location column NS char(3), domain code ?? */
    FLOAT ewfootage;    /* well_location column EW_FOOTAGE, domain code ?? */
    CHAR ew[4];         /* well_location column EW char(3), domain code ?? */
    CHAR spot[12];      /* well_location column SPOT_CODE char(10), domain code ?? */
    CHAR abstract[16];  /* well_texas_loc column ABSTRACT_NUMBER char(12), domain code ?? */
    CHAR state[4];      /* well_hdr column PROV_ST char(2), domain code ?? */
    CHAR country[4];    /* well_hdr column COUNTRY char(3), domain code ?? */
    CHAR county[24];    /* well_hdr column COUNTY char(20), domain code ?? */
    } LEGAL ;

/*
 * Define the Module ID and Version Number for the Well system
 */
#define WELL_REVISION "2.0"

/* flag symbols for we_get_well_header */
typedef enum {WE_LOCATION_ONLY, WELL_HDR_1_DETAIL, WELL_HDR_2_DETAIL}
    WELL_HDR_DETAIL ;

typedef struct {            /* structure defining minimum well information */
    UWI uwi;                /* well_hdr column UWI, domain code 1 */
    INT symbol_code;	    /* Plot symbol code */
    XYNODE tophole_xy;      /* structure defining coordinates of top hole position */
    XYNODE bottomhole_xy;   /* structure defining coordinates of bottom hole position */

    struct {
        NLIST_HEADER nlist; /* pointer to digits */
        BYTE flag;          /* well_hdr column DEVIATION_FLAG, domain code ?? */
        } deviation;

    struct {
        VOIDPTR ptr;
        WELL_HDR_DETAIL type;
        } detail;
} WELL_STRUCT;


typedef struct {            /* WELL_HDR_1_DETAIL type */
    WELL_NAME name;         /* well_hdr column WELL_NAME, domain code ?? */
    WELL_NUMBER number;     /* well_hdr column WELL_NUMBER, domain code ?? */
    CHAR plot_name[24];     /* well_hdr column PLOT_NAME char(20), domain code ?? */
    CHAR short_name[24];    /* well_hdr column SHORT_NAME char(20), domain code ?? */
    CHAR operator[16];      /* well_hdr column OPERATOR char(12), domain code 50 */
    CHAR class[16];         /* well_hdr column CLASS char(12), domain code 52 */
    CHAR crstatus[28];      /* well_hdr column CRSTATUS char(25), domain code 51 */
    LEGAL tophole;          /* structure describing legal status of the tophole */
    LEGAL bottomhole;       /* structure describing legal status of the bottomhole */
    struct {                /* structure defining offshore specific wells */
        FLOAT water_depth;  /* DRILLING_PLATFORM_HDR column WATER_DEPTH, domain code 111 */
        } offshore;
    struct {                /* structure describing reference well elevation */
        FLOAT value;        /* well_hdr column ELEVATION, domain code 96 */
        CHAR ref[8];        /* well_hdr column ELEVATION_REF char(4), domain code ?? */
        } elevation;
    CHAR primary_source[16];/* well_hdr column PRIMARY_SOURCE char(12), domain code 28 */
    DATE Spud_Date;         /* spud, well_hdr column SPUD_DATE, domain code 16 */
    DATE Comp_Date;         /* completion, well_hdr column COMP_DATE, domain code 16 */
    struct {                /* structure defining depths of driller, logger, and plugback */
        DEPTHS driller;     /* structure describing driller depths */
                            /* well_hdr column DRILLERS_TD, domain code 11 */
        DEPTHS logger;      /* structure describing logger depths */
                            /* well_hdr column LOG_TD, domain code 11 */
        LITHOSTRAT formation;/* structure describing formation at TD */
                            /* well_hdr column FORM_AT_TD char(12), domain code 5 */
                            /* well_hdr column TD_AGE_CODE char(6), domain code 29 */
        } td;

    } WELL_HDR_1;

/******************************************************************************/

typedef struct {            /* WELL_HDR_2_DETAIL type */
    WELL_NAME name;         /* well_hdr column WELL_NAME, domain code ?? */
    WELL_NUMBER number;     /* well_hdr column WELL_NUMBER, domain code ?? */
    CHAR plot_name[24];     /* well_hdr column PLOT_NAME char(20), domain code ?? */
    CHAR short_name[24];    /* well_hdr column SHORT_NAME char(20), domain code ?? */

    CHAR operator[16];      /* well_hdr column OPERATOR char(12), domain code 50 */
    CHAR licensee[16];      /* well_hdr column LICENSEE char(12), domain code 50 */
    CHAR agent[16];         /* well_hdr column AGENT char(12), domain code 50 */

/* Class and status information */
    CHAR class[16];         /* well_hdr column CLASS char(12), domain code 52 */
    CHAR crstatus[28];      /* well_hdr column CRSTATUS char(25), domain code 51 */
    CHAR orstatus[28];      /* well_hdr column ORSTATUS char(25), domain code 51 */
    CHAR prstatus[28];      /* well_hdr column PRSTATUS char(25), domain code 51 */

/* Location information */
    INT location_type;      /* */
    CHAR location_table[32];/* well_hdr column LOCATION_TABLE char(30), domain code 71 */
    LEGAL tophole;          /* structure describing legal status of the tophole */
    LEGAL bottomhole;       /* structure describing legal status of the bottomhole */

    struct {                /* structure defining offshore specific wells */
        FLOAT water_depth;  /* DRILLING_PLATFORM_HDR column WATER_DEPTH, domain code 111 */
        CHAR platform_name[32]; /* DRILLING_PLATFORM_HDR column NAME char(30), domain code ?? */
        CHAR offshore_block[12];/* */
        CHAR utm_grid_block[8]; /* */
        INT ocs_number;     /* */
        } offshore;

/* Total depth information */
    struct {                /* structure defining depths of driller, logger, and plugback */
        DEPTHS driller;     /* structure describing driller depths */
                            /* well_hdr column DRILLERS_TD, domain code 11 */
        DEPTHS logger;      /* structure describing logger depths */
                            /* well_hdr column LOG_TD, domain code 11 */
        DEPTHS plugback;    /* structure describing plugback depths */
                            /* well_hdr column PLUGBACK_TD, domain code 11 */
        LITHOSTRAT formation;/* structure describing formation at TD */
                            /* well_hdr column FORM_AT_TD char(12), domain code 5 */
                            /* well_hdr column TD_AGE_CODE char(6), domain code 29 */
        } td;

/* Field information */
    struct {                /* structure describing field code and name */
        CHAR code[16];      /* well_hdr column FIELDCODE char(12), domain code 53 */
        CHAR name[24];      /* */
        } field;
    CHAR fldpoolwild[16];   /* well_hdr column FLDPOOLWILD char(12), domain code ?? */

/* Elevation information */
    struct {                /* structure describing reference well elevation */
        FLOAT value;        /* well_hdr column ELEVATION, domain code 96 */
        CHAR ref[8];        /* well_hdr column ELEVATION_REF char(4), domain code ?? */
        } elevation;
    FLOAT Ground_Elevation; /* ground, well_hdr column GROUND_ELEVATION, domain code 96 */
    FLOAT kb_elevation;     /* kelly bushing, well_hdr column KB_ELEVATION, domain code 96 */
    FLOAT cf_elevation;     /* casing flange, well_hdr column CF_ELEVATION, domain code 96 */
    CHAR water_ref[8];      /* well_hdr column WATER_REF char(4), domain code ?? */

/* Checkshot information */
    struct {
        DOUBLE datum;       /* well_checkshot_hdr column CHECKSHOT_DATUM, domain code 96 */
        DOUBLE vsd;         /* velocity surface to datum, well_checkshot_hdr column CHECKSHOT_VSD, domain code 95 */
        INT one_or_two_way_time;/* well_checkshot_hdr column CHECKSHOT_12WAY, domain code ?? */
        NLIST_HEADER data;  /* Pointer to digits */
        } checkshot;

/* Drilling information */
    struct {                /* structure defining drilling contractor and rig number */
        CHAR contractor[16];/* well_license column DRILL_CONTRACTOR char(12), domain code ?? */
        CHAR rig_number[8]; /* well_license column DRILL_RIG_NO char(4), domain code ?? */
        } drilling;

/* Miscellaneous Information */
    CHAR primary_source[16];/* well_hdr column PRIMARY_SOURCE char(12), domain code 28 */
    STRATCOL stratcolumn;   /* name of strat column to use for this well */
    CHAR orig_units[16];    /* well_hdr column ORIG_UNIT char(12), domain code 36 */
    CHAR proprietary;       /* well_hdr column PROPRIETARY char(1), domain code ?? */
    CHAR discover_well;     /* well_hdr column DISCOVER_WELL char(1), domain code ?? */
    CHAR fault;             /* well_hdr column FAULT char(1), domain code 33 */
 
/* Confidence Information */
    struct {
        INT index;          /* confidence index, well_hdr column CONFID_INDEX, domain code ?? */
        FLOAT ratio;        /* well_hdr column CONFID_INDEX_RATIO, domain code ?? */
        INT level;          /* well_hdr column CONFID_INDEX_LEVEL, domain code ?? */
        } confidence;

/* Confidentiality Information */
    CHAR conf_flag;         /* well_hdr column CONF_FLAG char(1), domain code 33 */
    CHAR conf_form[16];     /* well_hdr column CONF_FORM char(12), domain code 5 */
    FLOAT conf_depth;       /* well_hdr column CONF_DEPTH, domain code 11 */
    DATE conf_rel_dt;       /* confidential release, well_hdr column CONF_REL_DT, domain code 16 */

/* Dates */
    DATE Last_Update;       /* date/time of last update, well_hdr column LAST_UPDATED, domain code 17 */
    DATE Spud_Date;         /* spud, well_hdr column SPUD_DATE, domain code 16 */
    DATE Comp_Date;         /* completion, well_hdr column COMP_DATE, domain code 16 */
    DATE rigrel;            /* rig release, well_hdr column RIGREL, domain code 16 */
    DATE onprod;            /* on production, well_hdr column ONPROD, domain code 16 */
    DATE calc_onprod;       /* calculated on production, well_hdr column CALC_ONPROD, domain code 16 */
    DATE oninject;          /* on injection, well_hdr column ONINJECT, domain code 16 */
    DATE status_date;       /* last status, well_hdr column STATUS_DATE, domain code 16 */
    DATE fin_drill;         /* final drilling, well_hdr column FIN_DRILL, domain code 16 */
    
    TBOOL updated;          /* TRUE if this well structure has been updated */

/* Headers (tree-tops) for other well data classes */
    VOIDPTR tophead;        /* pointer to index for well tops */
    VOIDPTR loghead;        /* pointer to index for well log curves */
    VOIDPTR testhead;       /* pointer to index for well tests */
    VOIDPTR corehead;       /* pointer to index for well cores */

    } WELL_HDR_2;

/*************************************************************************************************/

typedef struct {            /* Formation top description */
    LITHOSTRAT Marker;      /* structure describing formation and age codes */
    DEPTHS Depth;           /* structure defining depths */
    ANALYST_NAME Source;    /* well_tops column SOURCE, domain code 24 */
    CHAR Comment[8];        /* well_tops column DESC_CODE char(4), domain code ?? */
    CHAR Best_Pick;         /* well_tops column PICK_REF char(1), domain code ?? */
    CHAR Quality;           /* well_tops column QUAL_CODE char(1), domain code ?? */
    DATE Last_Update;       /* well_tops column LAST_UPDATE, domain code 17 */
    FLOAT Measured_Thickness;   /* uncorrected for geometry */
    TBOOL updated;          /* */
    } TOP_STRUCT;

/******************************************************************************/

#if USE_PROTOTYPES

extern VOID we_get_checkshots(UWI uwi,INT  *status,INT  *ck_waytime,
	    INT  *ck_datum,INT  *nck,FLOAT *time,FLOAT *depth,
	    FLOAT *ve,FLOAT *unit);
extern INT we_get_well_header(UWI uwi, WELL_HDR_DETAIL flag, WELL_STRUCT **ppWell);
extern INT we_get_well_location(CHAR *uwi, COORD *x, COORD *y);
extern INT we_show_well_server(UWI uwi);
extern INT we_show_wells_server(TCP tcp_uwi, TCP tcp_name);
extern void well_system_init();
extern INT wes_get_dir_tvd(UWI uwi, DOUBLE in_md, DOUBLE *dx, DOUBLE *dy, DOUBLE *tvd);
extern INT wes_get_dir_md(UWI uwi, DOUBLE in_tvd, DOUBLE *dx, DOUBLE *dy, DOUBLE *md);

#else

extern VOID we_get_checkshots();
extern INT we_get_well_header();
extern INT we_get_well_location();
extern INT we_show_well_server();
extern INT we_show_wells_server();
extern void well_system_init();
extern INT wes_get_dir_tvd();
extern INT wes_get_dir_md();

#endif

#endif
