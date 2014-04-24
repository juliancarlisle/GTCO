/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CONF_WS.H*/
/* *7    27-NOV-1990 14:34:19 JESSIE "(SPR 6087) add crt buffer"*/
/* *6    13-OCT-1990 00:19:58 GILLESPIE "(SPR 100) Updates from Ernie"*/
/*  4B1  13-OCT-1990 00:19:25 GILLESPIE "Updates from Ernie"*/
/* *5    14-AUG-1990 11:46:35 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *4    10-JUL-1990 19:16:39 MING "(SPR -1) ADD WISS ELEMENT IN CONFIGURATION_WORKSAPCE FOR TURN OFF WISS"*/
/* *3    10-AUG-1989 14:50:19 GORDON "(SPR 105) change user_menu_file to a tcp"*/
/* *2    28-JUL-1989 15:31:44 GORDON "(SPR 101) Add user_menu_file & use_x to workspace"*/
/* *1    30-JUN-1989 14:59:53 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CONF_WS.H*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CONF_WS.H*/
/* *4    10-JUL-1990 19:16:39 MING "(SPR -1) ADD WISS ELEMENT IN CONFIGURATION_WORKSAPCE FOR TURN OFF WISS"*/
/* *3    10-AUG-1989 14:50:19 GORDON "(SPR 105) change user_menu_file to a tcp"*/
/* *2    28-JUL-1989 15:31:44 GORDON "(SPR 101) Add user_menu_file & use_x to workspace"*/
/* *1    30-JUN-1989 14:59:53 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CONF_WS.H*/
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

NAME:    ESI_CONF_WS.H

AUTHOR:  W. Jaeck, 12-Aug-1986

DESCRIPTION:

    The CONFIGURATION global workspace contains information which is
    dependent on the configuration of the current Finder session. This
    includes information about the terminal which Finder was run from,
    the graphics workstation, if any, available for the session, and
    the analyst who started the session.

*************************************************************************/

#ifndef ESI_CONF_WS_H
#define ESI_CONF_WS_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

typedef struct {
    BOOL test;                         /* Test mode */
    BOOL maconly;                      /* No graphics workstation */
    CHAR terminal_line_id[10];         /* Terminal Line Identifier */
    CHAR terminal_type[21];            /* Terminal type */
    CHAR workstation_name[31];         /* Workstation name */
    BOOL on_units;                     /* On units active */
    FILENAME journal_file;             /* Journal file name */
    CHAR graphics_tablet_type[21];     /* Tablet type */
    CHAR graphics_terminal_type[21];   /* Graphics terminal type */
    CHAR graphics_device[21];          /* Physical channel */
    INT graphics_channel;              /* Logical channel */
    INT graphics_heads;                /* Number of CRTs */
    INT graphics_planes;               /* Number of color planes */
    CHAR tablet_firmware_rev[21];      /* Tablet firmware rev level */
    CHAR threed_firmware_rev[21];      /* 3-D firmware rev level */
    CHAR seismic_firmware_rev[21];     /* Seismic firmware rev level */
    INT experience_level;              /* Analyst's experience level */
    CHAR user_name[31];                /* User's login name */
    INT gks_error_log;                 /* LUN for GKS error logging */
    INT record_play_mode;	           /* Journal playback mode */
    FILENAME record_play_file;         /* Journal playback filename */
    TCP user_menu_tcp;	               /* User's dynamic menu add-on files */
    BOOL use_x;			               /* X-window interface switch */
    BOOL wiss;                         /* flag to turn on/off GKS WISS (for window control)
    */
    BOOL checkwi;                      /* flag to turn on/off of checking
					  wi layer memory */
    CHAR crt_name[31];			/* crt name */
    } CONFIGURATION_WORKSPACE;

#endif
