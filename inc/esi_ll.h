/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LL.H*/
/* *2    14-AUG-1990 11:49:01 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:02:31 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LL.H*/
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

#ifndef ESI_LL_H
#define ESI_LL_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#define LL_IS_LIST		(INT)1
#define LL_IS_TEMPORARY		(INT)2
#define LL_LIST_GLOBAL		(INT)4
#define LL_LIST_SYSTEM		(INT)10

/* mask the true nature of the node structure from the outside world */

#ifndef ESI_LL_INT_H
typedef char LL_NODE;
#endif

typedef struct listhead
    {
    INT pattern ;			/* initialization pattern */
    INT flags ;				/* data type flags */
    INT entries ;			/* # entries in list */
    INT data_size ;			/* size of data element */
    INT index;				/* index number of current node */
    LL_NODE *current ;			/* pointer to current node */
    LL_NODE *first ;			/* pointer to first node */
    LL_NODE *last ;			/* pointer to last node */
    }   LISTHEAD ;


#if USE_PROTOTYPES

extern INT llappnd (LISTHEAD *head_in, VOIDPTR data_in);

extern INT llcopy (LISTHEAD *source, LISTHEAD *destin);

extern INT llcount (LISTHEAD *head_in);

extern INT llcurr (LISTHEAD *head_in, VOIDPTR data_in);

extern INT lldela (LISTHEAD *head_in);

extern INT lldelb (LISTHEAD *head_in);

extern INT llfirst (LISTHEAD *head_in, VOIDPTR data_in);

extern INT llfree (LISTHEAD *head_in);

extern INT llgetn (LISTHEAD *head_in, VOIDPTR  data_in, INT nth);

extern INT llinit (LISTHEAD *head_in, INT type_in, INT d_siz_in, INT flags_in);

extern INT llinsa (LISTHEAD *head_in, VOIDPTR  data_in);

extern INT llinsb (LISTHEAD *head_in, VOIDPTR  data_in);

extern INT lllast (LISTHEAD *head_in, VOIDPTR  data_in);

extern INT llnext (LISTHEAD *head_in, VOIDPTR  data_in);

extern INT llprev (LISTHEAD *head_in, VOIDPTR  data_in);

extern INT llqcur (LISTHEAD *head_in);

extern INT llquery (LISTHEAD *head_in, 
                    INT *type_in,
                    INT *d_siz_in,
                    INT *flags_in,
                    INT *num_in);

extern INT llreplc (LISTHEAD *head_in, VOIDPTR  data_in);

#else	    /* no prototypes */

extern INT llappnd ();
extern INT llcopy ();
extern INT llcount ();
extern INT llcurr ();
extern INT lldela ();
extern INT lldelb ();
extern INT llfirst ();
extern INT llfree ();
extern INT llgetn ();
extern INT llinit ();
extern INT llinsa ();
extern INT llinsb ();
extern INT lllast ();
extern INT llnext ();
extern INT llprev ();
extern INT llqcur ();
extern INT llquery ();
extern INT llreplc ();

#endif	    /* of USE_PROTOTYPES */

#endif
