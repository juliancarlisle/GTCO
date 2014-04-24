/* DEC/CMS REPLACEMENT HISTORY, Element ESI_VERSION.H*/
/* *1    30-JUN-1989 15:05:31 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_VERSION.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_version.h,v 1.1 89/05/30 15:35:21 esi Exp $ esi_version.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_VERSION.H*/
/* *3     8-APR-1989 00:40:07 GILLESPIE "Add copyright, (INT) castings"*/
/* *2    17-DEC-1988 09:37:41 GILLESPIE "(SPR 4981) Unisource"*/
/* *1     7-JUL-1987 10:48:32 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_VERSION.H*/
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

#ifndef ESI_VERSION_H
#define ESI_VERSION_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#define VERSION struct versionstruct
VERSION {
   SHORT Module;               /* Module Number (see esi_modids.h) */       
   CHAR Revision[7];           /* Module Revision Number */                     
   CHAR Finder[7];             /* Finder Version Number */                      
   } ;

#endif
