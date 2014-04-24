/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_TXDEF.H*/
/* *2    14-AUG-1990 11:48:01 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:01:10 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_TXDEF.H*/
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

#ifndef ESI_GL_TXDEF_H
#define ESI_GL_TXDEF_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

enum justify {right = 3, center = 2, left = 1, top = 1, bottom = 5,
              normal = 0, half = 3} ;
enum mtype {absolute, relative } ;

typedef struct {
    COLOR_INDEX color;
    LINE_STYLE_INDEX  style;
    GKS_REAL width;
    } LINE_ATTR;

typedef struct {
    GKS_REAL x3d;
    GKS_REAL y3d;
    GKS_REAL z3d;
    } XYZ;

typedef struct {
   XYZ world;
   enum mtype motion;
   CHAR *ptext;
   INT plength;
   enum justify vjust;
   enum justify hjust;
   LINE_ATTR line;
   FONT_INDEX font;
   GKS_REAL height;
   GKS_REAL aspect;
   GKS_REAL xspace;
   GKS_REAL yspace;
   GKS_REAL skew;
   GKS_REAL rot;
   INDEX pattern;
   INDEX fill;
   BOOL reset;
   INDEX precision;
   BOOL draw_backface;
   XYZ char_path;
   XYZ char_up;
   } TEXTDEF;

#endif
