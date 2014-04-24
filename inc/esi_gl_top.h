/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_TOP.H*/
/* *6    14-AUG-1990 11:47:58 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *5    12-JUL-1990 12:57:30 GILLESPIE "(SPR 3) Rearrange elements between esi_gl_top.h and esi_ct.h"*/
/* *4    11-JUL-1990 15:57:36 GILLESPIE "(SPR 2) Change latitude/longitude in XYNODE to be DOUBLE rather than LATLONG"*/
/* *3     9-FEB-1990 13:45:04 MING "(SPR 0) change node_id definition to UINT"*/
/* *2    23-JAN-1990 12:26:40 GILLESPIE "(SPR 6001) Change NODE_ID from 21 to 24 characters for RISC machines"*/
/* *1    30-JUN-1989 15:01:08 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_TOP.H*/
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

#ifndef ESI_GL_TOP_H
#define ESI_GL_TOP_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

typedef struct {
    DOUBLE x;
    DOUBLE y;
    DOUBLE latitude_decimal;
    DOUBLE longitude_decimal;
    INT projection_id;
    NODE_ID node_id;
    } XYNODE ;

#endif
