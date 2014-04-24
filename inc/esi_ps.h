/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PS.H*/
/* *4     6-DEC-1989 08:51:42 GORDON "(SPR 0) fix non-prototype section"*/
/* *3    20-SEP-1989 16:34:48 GILLESPIE "(SPR 1) Change some prototypes"*/
/* *2     5-SEP-1989 14:00:58 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *1    30-JUN-1989 15:03:47 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PS.H*/
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

#ifndef ESI_PS_H
#define ESI_PS_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* Declare sizes. */
#define STACK_SIZE (100)

#define PS_LONG_PUSH(val)  {ps_long_sp++, ps_long_stack[ps_long_sp] = (val); }
#define PS_LONG_POP (ps_long_stack[ps_long_sp--])
#define PS_LONG_TOS (ps_long_stack[ps_long_sp])

#define PS_DOUBLE_PUSH(val)  {ps_double_sp++,\
				ps_double_stack[ps_double_sp] = (val);}
#define PS_DOUBLE_POP (ps_double_stack[ps_double_sp--])
#define PS_DOUBLE_TOS (ps_double_stack[ps_double_sp])

#define PS_POINTER_PUSH(val)  { ps_pointer_sp++,\
				ps_pointer_stack[ps_pointer_sp] = (val);}
#define PS_POINTER_POP (ps_pointer_stack[ps_pointer_sp--])
#define PS_POINTER_TOS (ps_pointer_stack[ps_pointer_sp])

/* Declare user callable routines. */

#if USE_PROTOTYPES

extern INT ps_init(void);                       /*no arguments*/
extern INT ps_term(void);                       /*no arguments*/
extern INT ps_check_stacks(void);               /*no arguments*/
extern INT ps_reset(void);                      /*no arguments*/
extern INT ps_long_push(LONG some_value);
extern LONG ps_long_pop(void);          /*no arguments*/
extern LONG ps_long_tos(void);          /*no arguments*/
extern INT ps_long_many(void);          /*no arguments*/
extern INT ps_long_view(void);          /*no arguments*/
extern INT    ps_double_push(DOUBLE some_value);
extern DOUBLE ps_double_pop(void);              /*no arguments*/
extern DOUBLE ps_double_tos(void);              /*no arguments*/
extern INT    ps_double_many(void);             /*no arguments*/
extern INT    ps_double_view(void);             /*no arguments*/
extern INT ps_pointer_push(VOIDPTR some_value);
extern VOIDPTR ps_pointer_pop(void);            /*no arguments*/
extern VOIDPTR ps_pointer_tos(void);            /*no arguments*/
extern INT ps_pointer_many(void);               /*no arguments*/
extern INT ps_pointer_view(void);               /*no arguments*/

#else

extern INT ps_init();                       /*no arguments*/
extern INT ps_term();                       /*no arguments*/
extern INT ps_check_stacks();               /*no arguments*/
extern INT ps_reset();                      /*no arguments*/
extern INT ps_long_push();
extern LONG ps_long_pop();          /*no arguments*/
extern LONG ps_long_tos();          /*no arguments*/
extern INT ps_long_many();          /*no arguments*/
extern INT ps_long_view();          /*no arguments*/
extern INT    ps_double_push();
extern DOUBLE ps_double_pop();              /*no arguments*/
extern DOUBLE ps_double_tos();              /*no arguments*/
extern INT    ps_double_many();             /*no arguments*/
extern INT    ps_double_view();             /*no arguments*/
extern INT ps_pointer_push();
extern VOIDPTR ps_pointer_pop();            /*no arguments*/
extern VOIDPTR ps_pointer_tos();            /*no arguments*/
extern INT ps_pointer_many();               /*no arguments*/
extern INT ps_pointer_view();               /*no arguments*/

#endif

#endif
                                                                                                                
