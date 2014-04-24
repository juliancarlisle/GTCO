/* DEC/CMS REPLACEMENT HISTORY, Element ESI_BT.H*/
/* *2    31-OCT-1989 11:54:07 GILLESPIE "(SPR 30) Remove extraneous includes in includes"*/
/* *1    30-JUN-1989 14:59:44 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_BT.H*/
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

/************************* ESI_BT.H *********************************
-FUNCTION:  This file is the new BT include file.  It sits on top of the
            LH include file.

-REVISIONS:

  May 29,1987 by Anthony P. Lucido -- Initial version.
  June 11, 1987  JGG  Remove esi_lh.h

************************** ESI_BT.H ********************************/

#ifndef ESI_BT_H
#define ESI_BT_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

typedef VOIDPTR TREEHEAD;

#define BT_IS_TREE                (INT) 01
#define BT_KEY_HAS_SIGN           (INT) 02
#define BT_DUPLICATE_KEYS_ALLOWED (INT) 04
#define BT_IS_TEMPORARY           (INT) 010
#define BT_KEY_IS_C_STRING        (INT) 020
#define BT_TREE_GLOBAL            (INT) 040
#define BT_TREE_SYSTEM		  (INT) 0100

#define BT_NODE_IS_TOP       (INT) 01
#define BT_NODE_IS_FIRST     (INT) 02
#define BT_NODE_IS_LAST      (INT) 04
#define BT_NODE_UNBAL_LEFT   (INT) 010
#define BT_NODE_UNBAL_RIGHT  (INT) 020
#define BT_NODE_IS_LIST      (INT) 040

#if USE_PROTOTYPES
extern INT       btadd(TREEHEAD *, VOIDPTR , VOIDPTR );
extern INT       btcopy(TREEHEAD *, TREEHEAD *);
extern INT       btcount(TREEHEAD *);
extern INT       btcurr(TREEHEAD *, VOIDPTR , VOIDPTR );
extern INT       btdel(TREEHEAD *, VOIDPTR );
extern INT       btfind(TREEHEAD *, VOIDPTR , VOIDPTR );
extern INT       btfirst(TREEHEAD *, VOIDPTR , VOIDPTR ) ;
extern INT       btfree(TREEHEAD *);
extern INT       btinit(TREEHEAD *, INT, size_t, size_t, INT) ;
extern INT       btlast(TREEHEAD *, VOIDPTR , VOIDPTR ) ;
extern INT       btnext(TREEHEAD *, VOIDPTR , VOIDPTR ) ;
extern INT       btprev(TREEHEAD *, VOIDPTR , VOIDPTR ) ;
extern INT       btrepcur(TREEHEAD *, VOIDPTR , VOIDPTR ) ;

#else

extern INT       btset() ;
extern INT       btadd() ;
extern INT       btcopy() ;
extern INT       btcount() ;
extern INT       btcurr() ;
extern INT       btdel() ;
extern INT       btfind() ;
extern INT       btfirst() ;
extern INT       btfree() ;
extern INT       btinit() ;
extern INT       btlast() ;
extern INT       btnext() ;
extern INT       btprev() ;
extern INT       btrepcur() ;
extern INT       btset() ;

#endif

#endif
