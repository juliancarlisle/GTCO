/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DTYPES.H*/
/* *2     3-JAN-1991 17:25:58 GILLESPIE "(SPR 6347) Fix ENTRYSEPARATOR for VMS (was ., now ])"*/
/* *1    14-AUG-1990 11:54:01 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DTYPES.H*/

#ifndef ESI_DTYPES_H
#define ESI_DTYPES_H 1

/* 
This new include file contains fundamental data types to Finder at the Real Object
level, as opposed to esi_gl_defs.h file, which tracks machine-type typedefs like,
INT, DOUBLE.  This would allow modules which need data type definitions of general
interest to use them without requiring inclusion of a defining .h file which also
requires additional baggage to be useful.  Specifically, the things that would go in
here are often used as building blocks for other data types.  The more specialized
tye type, the less likely it should appear here. */

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

typedef char DATE[12];
typedef char DATE_TIME[16];

/*  database type definitions                                                       */
typedef CHAR ORACLE_NAME[32];       /*  name of any oracle object                   */
typedef CHAR EXTENDED_TABLE_NAME[128];  /*  account.tname@database                  */
typedef ORACLE_NAME ANALYST_NAME;   /*  name of an analyst account                  */
typedef ORACLE_NAME COLUMN_NAME;    /*  name of a database column                   */
typedef ORACLE_NAME INDEX_NAME;     /*  name of a database index                    */
typedef ORACLE_NAME PROJECT_NAME;   /*  name of a project account                   */
typedef ORACLE_NAME TABLE_NAME;     /*  name of a database table                    */

typedef DOUBLE COORD;               /* Cartesian coordinate - moved from esi_se.h   */
typedef UINT NODE_ID;               /* Unique node identifier - moved from esi_gl_top.h */
typedef CHAR PROJECTION_ID[16];
typedef CHAR PROJECTION_NAME[44];
typedef CHAR UOM_NAME[32];          /* Unit of measure name - Move from esi_tu.h    */
typedef CHAR UWI[24];               /* Unique Well Identifier                       */

#if UNIX
#ifdef applec

#define MAXPATHLENGTH  240    /* 239 characters + 1 nul byte                */
#define MAXENTRYLENGTH  15    /*  14 characters + 1 nul byte                */
#define ENTRYSEPERATOR  ':'   /* separates entry names in pathname          */
#define __DONE

#endif

#ifdef THINK_C

#define MAXPATHLENGTH  255    /* 254 characters + 1 nul byte                */
#define MAXENTRYLENGTH  15    /*  14 characters + 1 nul byte                */
#define ENTRYSEPERATOR  ':'   /* separates entry names in pathname          */
#define __DONE

#endif

#else /* UNIX */

#ifdef primos

#define MAXPATHLENGTH  129    /* 128 characters + 1 nul byte                */
#define MAXENTRYLENGTH  33    /*  32 characters + 1 nul byte                */
#define ENTRYSEPERATOR  '>'   /* separates entry names in pathname          */
#define __DONE

#endif      /* end PRIMOS */

#ifdef vms

#define MAXPATHLENGTH  240    /* 239 characters + 1 nul byte                */
#define MAXENTRYLENGTH  40    /*  39 characters + 1 nul byte                */
#define ENTRYSEPERATOR  ']'   /* separates directory and file name          */
#define __DONE

#endif      /* end VMS */
#endif      /* end UNIX */

#ifndef __DONE

#define MAXPATHLENGTH  240    /* 239 characters + 1 nul byte                */
#define MAXENTRYLENGTH  15    /*  14 characters + 1 nul byte                */
#define ENTRYSEPERATOR  '/'   /* separates entry names in pathname          */

#else

#undef __DONE

#endif

typedef char FILENAME[MAXPATHLENGTH];   /* fully qualified file name                */
typedef char PATHNAME[MAXPATHLENGTH];   /* path name                                */
typedef char ENTRYNAME[MAXENTRYLENGTH]; /* entry name (pathname components)         */

#endif
