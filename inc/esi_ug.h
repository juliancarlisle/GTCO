/* DEC/CMS REPLACEMENT HISTORY, Element ESI_UG.H*/
/* *4    14-AUG-1990 11:51:34 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *3     7-DEC-1989 07:12:22 GORDON "(SPR 0) Fix type of ugoperr_gc in non-prototype section"*/
/* *2    10-OCT-1989 12:43:04 GORDON "(SPR 4999) add arg to prototype of ugoperr_gc"*/
/* *1    30-JUN-1989 15:05:22 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_UG.H*/
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

/*
 *  Name : esi_ug.h
 *
 *  Author : John Barton
 *
 *  Description :
 *      Header file containing stuctures and defines for
 *      Graphics Utilities.
 */

#ifndef ESI_UG_H
#define ESI_UG_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

/*
 *  Typedef structure workstation information.
 */
typedef struct {
    INT      channel;              /* workstation identification   */
    INT      type;                 /* wkstation type               */
    INT      tablet_type;          /* tablet type                  */
    } WKS_ID ;

/*
 * minimum and maximum definitions for legal channel numbers
 */
#define MINCHAN (INT)0
#define MAXCHAN (INT)100

#if USE_PROTOTYPES

extern INT ugescape_gc(void);
extern VOID ugoperr_gc(INT *errfil, FILENAME filename);
extern INT ugrqband_gc( INT mode, DOUBLE ugWx1, DOUBLE ugWy1, INT *ugStatus, INT *ugTnr,
			GKS_REAL *ugWx2, GKS_REAL *ugWy2, INT *ugButton ) ;
extern INT ugrqdrag_gc( INT ugSegment, DOUBLE ugWx1, DOUBLE ugWy1, INT *ugStatus,
			INT *ugTnr, GKS_REAL *ugWx2, GKS_REAL *ugWy2, INT *ugButton ) ;
extern INT ugsbutmap_gc(void);
extern INT ugsrawxf_gc(void);
extern INT ugssamp_gc(BOOL i);
extern INT ugsscaxf_gc(void);
extern INT ugstabxf_gc(INT wkid, INT i, FLOAT *tabxf) ;
extern INT ugstbtyp_gc(void);
extern INT ug_if_gpx(void);
extern INT ug_init_gks(WKS_ID *wks_id);
extern INT ug_term_gks(INT channel);

#else

extern INT ugescape_gc();
extern VOID ugoperr_gc();
extern INT ugrqband_gc() ;
extern INT ugrqdrag_gc() ;
extern INT ugsbutmap_gc();
extern INT ugsrawxf_gc();
extern INT ugssamp_gc();
extern INT ugsscaxf_gc();
extern INT ugstabxf_gc() ;
extern INT ugstbtyp_gc();
extern INT ug_if_gpx();
extern INT ug_init_gks();
extern INT ug_term_gks();

#endif

#endif
                                                                             
