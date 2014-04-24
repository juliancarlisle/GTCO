/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TABLET_WS.H*/
/* *2    13-NOV-1989 11:58:06 JULIAN "(SPR 1) Added driver name to workspace"*/
/* *1    30-JUN-1989 15:04:50 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TABLET_WS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_tablet_ws.h,v 1.1 89/05/30 15:35:06 esi Exp $ esi_tablet_ws.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TABLET_WS.H*/
/* *3     8-APR-1989 00:38:36 GILLESPIE "Add copyright, (INT) castings"*/
/* *2    26-DEC-1988 10:17:30 JULIAN "(SPR 4983) TABLET WKSPACE DEF"*/
/* *1    26-DEC-1988 10:16:22 JULIAN "Include file for tablet workspace definition."*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TABLET_WS.H*/
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

/*************************************************************************
FILE:   ESI_TABLET_WS.H

DESCRIPTION:
    This is the definition of the TABLET workspace.  It holds 
    information about the tablet device that is connected to
    the current workstation.
    
    Julian Carlisle   Dec 26, 1988
*************************************************************************/

#ifndef ESI_TABLET_WS_H
#define ESI_TABLET_WS_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_TG_MAT_H
#include "esi_tg_mat.h"
#endif

typedef struct {    
    INT		tablet_type;	    /* model/brand type code from DB  */
    CHAR	tablet_port[32];    /* connection port name on HOST   */
    CHAR	tablet_name[32];    /* arbitrary name for this tablet */
    unsigned    modemask;	    /* concatonated modes mask.       */
    unsigned    temp_modemask;	    /* temp storage for saved modes.  */
    INT		init;		    /* TRUE if driver is initialized  */
    INT		init_status;	    /* Saved status of initialization */
    EXTENTS	dext;		    /* Tablet device x,y max extents. */
    MATRIX	regdef;		    /* Default reg xform. 1/1 mapping */
    MATPTR	*pregdef;	    /* pointer to default reg xform   */
	CHAR	driver[256];	/* Name of the tablet driver executable */
    } TABLET_WORKSPACE;


#endif









