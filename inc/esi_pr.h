/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PR.H*/
/* *2    14-AUG-1990 11:50:26 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:03:44 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PR.H*/
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

#ifndef ESI_PR_H
#define ESI_PR_H 1
/* start of defs */

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

typedef struct
{
   RECTANGLE in ;
   RECTANGLE out ;
} PIPE ;

#if USE_PROTOTYPES

/* Point routines */
extern POINT        *PR_SetPt(POINT *point, DOUBLE x, DOUBLE y) ;
extern POINT        *PR_InqPt(POINT *point, FLOAT *x, FLOAT *y) ;
extern INT           PR_EqualPt(POINT *point1, POINT *point2) ;
extern INT           PR_PtInRect(POINT *point, RECTANGLE *rectangle) ;
extern POINT        *PR_PipePt(POINT *pointIn, PIPE *pipe, POINT *pointOut) ;

/* Rectangle routines */
extern RECTANGLE    *PR_SetRect(RECTANGLE *rect, DOUBLE xq, DOUBLE y1, DOUBLE x2,
			        DOUBLE y2) ;
extern RECTANGLE    *PR_InqRect(RECTANGLE *rect, FLOAT *xq, FLOAT *y1, FLOAT *x2,
			        FLOAT *y2) ;
extern INT           PR_EqualRect(RECTANGLE *rect1, RECTANGLE *rect2) ;
extern INT           PR_RectInRect(RECTANGLE *rect1, RECTANGLE *rect2) ;
extern RECTANGLE    *PR_PipeRect(RECTANGLE *rect1, PIPE *pipe, 
				 RECTANGLE *rect2) ;
extern RECTANGLE    *PR_AspectRect(RECTANGLE *rect1, RECTANGLE *rect2) ;

/* Pipe routines */

extern PIPE         *PR_SetPipe(PIPE *pipe, RECTANGLE *rect1, 
				RECTANGLE *rect2) ;
extern PIPE         *PR_InqPipe(PIPE *pipe, RECTANGLE *rect1, 
				RECTANGLE *rect2) ;
extern INT           PR_EqualPipe(PIPE *pipe1, PIPE *pipe2) ;
extern PIPE         *PR_InvertPipe(PIPE *pipe1, PIPE *pipe2) ;

/* Debug routines */

extern VOID          PR_ShowPt(POINT *point) ;
extern VOID          PR_ShowRect(RECTANGLE *rect) ;
extern VOID          PR_ShowPipe(PIPE *pipe) ;

#else

/* Point routines */
extern POINT        *PR_SetPt() ;
extern POINT        *PR_InqPt() ;
extern INT           PR_EqualPt() ;
extern INT           PR_PtInRect() ;
extern POINT        *PR_PipePt() ;

/* Rectangle routines */
extern RECTANGLE    *PR_SetRect() ;
extern RECTANGLE    *PR_InqRect() ;
extern INT           PR_EqualRect() ;
extern INT           PR_RectInRect() ;
extern RECTANGLE    *PR_PipeRect() ;
extern RECTANGLE    *PR_AspectRect() ;

/* Pipe routines */

extern PIPE         *PR_SetPipe() ;
extern PIPE         *PR_InqPipe() ;
extern INT           PR_EqualPipe() ;
extern PIPE         *PR_InvertPipe() ;

/* Debug routines */

extern VOID          PR_ShowPt() ;
extern VOID          PR_ShowRect() ;
extern VOID          PR_ShowPipe() ;

#endif

#endif
