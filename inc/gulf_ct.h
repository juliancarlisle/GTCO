/* DEC/CMS REPLACEMENT HISTORY, Element GULF_CT.H */
/* *2     1-MAY-1991 12:09:32 KEE "(SPR -1) Modified Gulf Canada DLS/NTS for vms and sun version" */
/* *1     1-MAY-1991 12:08:26 KEE "DLS/NTS" */
/* DEC/CMS REPLACEMENT HISTORY, Element GULF_CT.H */

/************************************************************************

   This file defines the Finder Cartographic Pipeline Package

   The actual cartographic routines are adaptations of the USGS
   package GCTP and are written in Fortran-77.  The routines contained
   in this file provide  abilities to define transformation parameters
   and to perform the desired transformations.

************************************************************************/

#define SUCCESS  (int)0
typedef struct {
    double parm_1;
    double parm_2;
    double parm_3;
    double parm_4;
    double parm_5;
    double parm_6;
    double parm_7;
    double parm_8;
    double parm_9;
    double parm_10;
    double parm_11;
    double parm_12;
    double parm_13;
    double parm_14;
    double parm_15;
    }DISCRETE_PARMS;

typedef union
{
    double parm_array[15];        /* Array format                   */
    DISCRETE_PARMS d_parm;        /* Discrete format                */
} PARM_DATA;

typedef char PROJECTION_ID[16];
typedef char PROJECTION_NAME[41];
typedef struct {                  /* Projection Structure Type       */
    PROJECTION_ID projection_id;  /* Unique Projection Identifier    */
    PROJECTION_NAME projection_name;/* Projection Name (description) */
    int    projection_type;       /* USGS Projection Type Code       */
    int    spheroid_code;         /* USGS Spheroid Code              */
    int    spheroid_units;        /* UOM for Spheroid                */
    int    zone_code;             /* UTM or US State Plane Zone      */
    DISCRETE_PARMS parameters;    /* Parameters                      */
    } PROJECTION_STRUCTURE;
