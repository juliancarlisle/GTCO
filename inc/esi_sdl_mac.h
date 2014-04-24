/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SDL_MAC.H*/
/* *2    14-AUG-1990 11:50:46 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:04:07 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SDL_MAC.H*/
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

#ifndef ESI_SDL_MAC_H
#define ESI_SDL_MAC_H 1

#ifndef ESI_MATH_H
#include "esi_math.h"
#endif

/* static values moved to ESI_SDL_MAC.A */

#define SDL_START_GROUP(group) \
        { \
           strncpy( (char *)(sdl_Group), (char *)(group), MAXENTRYLENGTH ) ; \
           sdl_Status = csz_AddGroup( sdl_Group ) ; \
        }

#define SDL_END_GROUP \
        { \
           sdl_Group[0] = NUL ; \
        }

#define SDL_START_SYMBOL(symbol) \
        { \
           sdl_Symbol = (symbol) ; \
           sdl_NumPrims  = 0 ; \
           sdl_NumPoints = 0 ; \
        }

#define SDL_END_SYMBOL \
        if ((sdl_NumPrims > 0) && (sdl_NumPoints > 0)) \
        { \
           sdl_Status = csz_AddSymbol( sdl_Group, sdl_Symbol, \
                                       sdl_NumPrims, sdl_NumPoints, \
                                       sdl_Types, sdl_Npts, sdl_Px, sdl_Py ) ; \
        } \
        else \
        { \
           sdl_Status = CS_ERR_INVALID_PARAMETER ; \
        }

#define SDL_START_PRIMITIVE(type) \
        { \
           sdl_Type = (type) ; \
           sdl_PrimNpts = 0 ; \
        }

#define SDL_END_PRIMITIVE \
        if (sdl_NumPrims < CS_MAX_PRIMITIVES) \
        { \
           sdl_Types[sdl_NumPrims] = sdl_Type ; \
           sdl_Npts[sdl_NumPrims]  = sdl_PrimNpts ; \
           sdl_NumPrims++ ; \
        } \
        else \
        { \
           sdl_Status = CS_ERR_TOO_MANY_PRIMITIVES ; \
        }

#define SDL_ADD_POINT(x,y) \
        if (sdl_NumPoints < CS_MAX_POINTS) \
        { \
           sdl_Px[sdl_NumPoints] = (x) ; \
           sdl_Py[sdl_NumPoints] = (y) ; \
           sdl_NumPoints++ ; \
           sdl_PrimNpts++ ; \
        } \
        else \
        { \
           sdl_Status = CS_ERR_TOO_MANY_POINTS ; \
        }

#define SDL_GATHER_POINTS \
        { \
           sdl_Type = 0 ; \
           sdl_PrimNpts = 0 ; \
        }

#define SDL_POLYLINE \
        { \
           sdl_Type = CS_POLYLINE ; \
           SDL_END_PRIMITIVE ; \
        }

#define SDL_FILLED_AREA \
        { \
           sdl_Type = CS_FILLED_AREA ; \
           SDL_END_PRIMITIVE ; \
        }

#define SDL_LINE(x1,y1,x2,y2) \
        { \
           SDL_START_PRIMITIVE( CS_POLYLINE ) ; \
              SDL_ADD_POINT( (x1), (y1) ) ; \
              SDL_ADD_POINT( (x2), (y2) ) ; \
           SDL_END_PRIMITIVE ; \
        }

#define SDL_ADD_CIRCLE(x,y,r) \
        { \
           SDL_ADD_POINT( (x) + ((r) * -1.0000), (y) + ((r) *  0.0000) ) ; \
           SDL_ADD_POINT( (x) + ((r) * -0.7071), (y) + ((r) *  0.7071) ) ; \
           SDL_ADD_POINT( (x) + ((r) *  0.0000), (y) + ((r) *  1.0000) ) ; \
           SDL_ADD_POINT( (x) + ((r) *  0.7071), (y) + ((r) *  0.7071) ) ; \
           SDL_ADD_POINT( (x) + ((r) *  1.0000), (y) + ((r) *  0.0000) ) ; \
           SDL_ADD_POINT( (x) + ((r) *  0.7071), (y) + ((r) * -0.7071) ) ; \
           SDL_ADD_POINT( (x) + ((r) *  0.0000), (y) + ((r) * -1.0000) ) ; \
           SDL_ADD_POINT( (x) + ((r) * -0.7071), (y) + ((r) * -0.7071) ) ; \
           SDL_ADD_POINT( (x) + ((r) * -1.0000), (y) + ((r) *  0.0000) ) ; \
        }

#define SDL_FILLED_CIRCLE(x,y,r) \
        { \
           SDL_START_PRIMITIVE( CS_FILLED_AREA ) ; \
              SDL_ADD_CIRCLE((x),(y),(r)) ; \
           SDL_END_PRIMITIVE ; \
        }

#define SDL_HOLLOW_CIRCLE(x,y,r) \
        { \
           SDL_START_PRIMITIVE( CS_POLYLINE ) ; \
              SDL_ADD_CIRCLE((x),(y),r) ; \
           SDL_END_PRIMITIVE ; \
        }

#define SDL_FILLED_RECT(x1,y1,x2,y2) \
        { \
           SDL_START_PRIMITIVE( CS_FILLED_AREA ) ; \
              SDL_ADD_POINT( (x1), (y1) ) ; \
              SDL_ADD_POINT( (x1), (y2) ) ; \
              SDL_ADD_POINT( (x2), (y2) ) ; \
              SDL_ADD_POINT( (x2), (y1) ) ; \
              SDL_ADD_POINT( (x1), (y1) ) ; \
           SDL_END_PRIMITIVE ; \
        }

#define SDL_HOLLOW_RECT(x1,y1,x2,y2) \
        { \
           SDL_START_PRIMITIVE( CS_POLYLINE ) ; \
              SDL_ADD_POINT( (x1), (y1) ) ; \
              SDL_ADD_POINT( (x1), (y2) ) ; \
              SDL_ADD_POINT( (x2), (y2) ) ; \
              SDL_ADD_POINT( (x2), (y1) ) ; \
              SDL_ADD_POINT( (x1), (y1) ) ; \
           SDL_END_PRIMITIVE ; \
        }

#define SDL_RADIAL_SEGMENT(x,y,r1,r2,d) \
        { \
           SDL_LINE( ((x) + (r1) * cos(D_TO_R(d))), ((y) + (r1) * sin(D_TO_R(d))), \
                     ((x) + (r2) * cos(D_TO_R(d))), ((y) + (r2) * sin(D_TO_R(d))) ) ; \
        }

#endif
