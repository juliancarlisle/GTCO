/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TC_MEMPOLICE.H*/
/* *1    30-JUN-1989 15:05:00 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TC_MEMPOLICE.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_tc_mempolice.h,v 1.1 89/05/30 15:35:09 esi Exp $ esi_tc_mempolice.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TC_MEMPOLICE.H*/
/* *4     8-APR-1989 00:39:01 GILLESPIE "Add copyright, (INT) castings"*/
/* *3     1-MAR-1989 12:27:15 GILLESPIE "(SPR 2) Remove extraneous typedef; make count size_t"*/
/* *2    16-JAN-1989 16:52:59 JHUANG "(SPR 4981) Replace the old one"*/
/* *1    12-JAN-1989 16:40:58 JHUANG "New memory-police struct"*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TC_MEMPOLICE.H*/
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

/***************************************************************
* ESI_TC_MEMPOLICE.H:                                          *
*   This include file contains a struct type for TC_ modules   *
* used for memory-police.                                      *
***************************************************************/
#ifndef ESI_TC_MEMPOLICE_H
#define ESI_TC_MEMPOLICE_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

typedef struct police {
    char pattern1;            /* pattern for memory police*/
    size_t  nbyte;            /* number of byte of used memory*/
    char pattern2;            /* ending pattern for memory police*/
} MEM_POLICE;

#define IN_USE_PATTERN '\170'      /*pattern for memory police*/
#define FREE_PATTERN   '\133'      /*free-pattern for memory police*/
#endif
                                                                        
