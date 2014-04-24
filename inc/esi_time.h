/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TIME.H*/
/* *5    30-OCT-1990 12:27:05 GILLESPIE "(SPR 37) Fix for Sun"*/
/* *4    28-AUG-1990 09:38:55 GILLESPIE "(SPR 1) Place vms specific blinders around time_t"*/
/* *3    14-AUG-1990 12:28:57 GILLESPIE "(SPR 2001) Major include file changes"*/
/* *2    26-FEB-1990 19:07:50 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *1    30-JUN-1989 15:05:08 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TIME.H*/
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

#ifndef ESI_TIME_H
#define ESI_TIME_H

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_TYPES_H
#include "esi_types.h"
#endif

/*    TIME - Localtime() RTL Routine Return Structure Definition  */

#define CLK_TCK (100)

/*
 * VMS places the definition of time_t in types.h
 * If the symbol __TYPES is defined, then some other file
 * (like X11 things) has defined the typedef time_t.
 */
#ifdef vms
#ifndef __TYPES
typedef unsigned long time_t;
#endif
#endif

#ifdef UNIX								/* 910424:sjs: use system time.h */
#include <time.h>
typedef struct tm tm_t;
#else		/* end of UNIX */
typedef unsigned long clock_t;

typedef struct tbuffer tbuffer_t;

struct tm {
    int                tm_sec;
    int                tm_min;
    int                tm_hour;
    int                tm_mday;
    int                tm_mon;
    int                tm_year;
    int                tm_wday;
    int                tm_yday;
    int                tm_isdst;
    };

typedef struct tm tm_t;

#if USE_PROTOTYPES

extern char *asctime (const tm_t *timeptr);
extern clock_t clock (void);
extern char *ctime (const time_t *bintim);
extern double difftime (time_t time1, time_t time0);
extern tm_t *gmtime (const time_t *timer); 
extern struct tm *localtime (const time_t *bintim); 
extern time_t mktime (tm_t timeptr);
extern time_t time (time_t *time_location);
extern void times (tbuffer_t *buffer);

#else

extern char *asctime ();
extern clock_t clock ();
extern char *ctime ();
extern double difftime ();
extern tm_t *gmtime ();
extern struct tm *localtime ();
extern time_t mktime ();
extern time_t time ();
extern void times ();

#endif            /* USE_PROTOTYPES */
#endif									/* 910424:sjs: #else on UNIX #ifdef */
#endif
