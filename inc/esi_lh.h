/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LH.H*/
/* *1    30-JUN-1989 15:02:27 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LH.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_lh.h,v 1.1 89/05/30 15:34:15 esi Exp $ esi_lh.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LH.H*/
/* *8    17-APR-1989 16:01:37 JRB "(SPR 1) change BYTE *	 to VOIDPTR"*/
/* *7    12-APR-1989 18:03:49 JRB "Fix bad character in copyright notice"*/
/* *6     8-APR-1989 00:32:34 GILLESPIE "Add copyright, (INT) castings"*/
/* *5    17-JAN-1989 15:07:18 GILLESPIE "(SPR 5007) Lint run"*/
/* *4    17-DEC-1988 09:32:21 GILLESPIE "(SPR 4981) Unisource"*/
/* *3     9-AUG-1988 11:11:29 GILLESPIE "(SPR 4765) Add additional function prototypes"*/
/* *2     8-AUG-1988 08:03:04 GILLESPIE "(SPR 4759) Make structures self-referencing"*/
/* *1     7-JUL-1987 10:46:07 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LH.H*/
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

/*************************  

-DESCRIPTION:

  This is the master include file for the List Handler facility.

-REVISIONS:

  May 26,1987 by Anthony P. Lucido -- Initial version.
  Aug 7, 1988 J Gillespie - redefine node struct to point to itself (rather
		than (CHAR *)

**************************/
#ifndef ESI_LH_H
#define ESI_LH_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_AM_H
#include "esi_am.h"
#endif

#include "esi_lh_err.h"
#include "esi_lh_msg.h"

#define lh_secure_value   (INT)32101
#define lh_unsecure_value (INT)10123
#define NULL_LH_NODE (lh_listnode *)0
#define NULL_LH_LIST (lh_listhead *)0

typedef  /*  Define the list node structure.    */
    struct lh_node_struct
        {
        struct lh_node_struct
	     *LAST_NODE,  /*  Pointer to the previous list element.  
                              Note that the NULL pointer value indicates
                              that this is the first list element.   */
             *NEXT_NODE,  /*  Pointer to the next list element.      
                              Note that the NULL pointer value indicates
                              that this is the last list element.    */
             *KEY_AREA,   /*  Pointer to the key field.              */
             *DATA_AREA;  /*  Pointer to the data field.             */
        INT   DATA_LENGTH;/*  Data area length.  Ignored if the header
                              contains a value that is greater than 
                              0.                                    */
        } lh_listnode;

typedef  /*  Define the list header structure.  */
    struct lh_listhead_struct
        {
        INT   SECURITY;   /*  This is the security flag, and is set
                              upon initialization of a list, reset
                              after, and always checked.
                          */
        struct lh_node_struct 
	     *FIRST_NODE, /*  Pointer to the first list element.  */
             *LAST_NODE , /*  Pointer to the last list element.   */
             *CURRENT_NODE;/* Pointer to the current node in the
                              list.  If set to NULL, then there is
                              no current node.                    */
        INT   NUMBER_OF_NODES;/*  Count of the list size.         */
        INT   KEY_LENGTH; /*  Length of the key.                  */
        INT   DATA_LENGTH;/*  Length of the data area.  If this 
                               field has the value 0, then each node
                               contains its own length value.     */
        BOOL  SIGNED_KEYS;/*  Set to 1 if the keys are taken as signed,
                              and 0, if not.
                          */
        BOOL  DUPLICATE_KEYS;/*  Set to 1 if duplicated keys can be
                              entered in the list, and 0, otherwise.*/
        BOOL  C_STRING_KEYS; /*  Set to 1 if the keys must be interpreted
                              as NULL character terminated C strings.*/
        BOOL   SYSTEM_LIST;   /*  Set to 1 if this is a system, versus
                              an application list.  Any value other than
                              1 indicates that this is an application
                              list.                                 */
        } lh_listhead;


#if USE_PROTOTYPES
extern VOIDPTR lhz_allocate (BOOL flag, INT size);

extern INT lhz_free (BOOL flag, VOIDPTR pointer);

extern lh_listnode *lhz_makenode (BOOL syslist, 
                                  VOIDPTR key_pointer,
                                  size_t  key_length, 
                                  VOIDPTR data_pointer,
                                  size_t  data_length);

extern INT lh_add (lh_listhead *header_pointer,
                   VOIDPTR key_pointer,
                   VOIDPTR data_pointer,
                   size_t  data_length);

extern INT lh_cmpkey (VOIDPTR node_key,
                      VOIDPTR test_key,
                      size_t  key_length,
                      BOOL    signed_keys,
                      BOOL    c_string_keys);

extern INT lh_copy (lh_listhead *incoming, lh_listhead *outgoing);

extern INT lh_count (lh_listhead *header_pointer);

extern INT lh_current (lh_listhead *header_pointer,
                       VOIDPTR key_pointer,
                       VOIDPTR data_pointer,
                       INT *data_length);

extern INT lh_delete (lh_listhead *header_pointer,
                      VOIDPTR key_pointer,
                      INT current_flag);

extern INT lh_find (lh_listhead *header_pointer,
                    VOIDPTR key_pointer,
                    VOIDPTR data_pointer,
                    INT *data_length);

extern INT lh_first (lh_listhead *header_pointer,
                     VOIDPTR key_pointer,
                     VOIDPTR data_pointer,
                     INT *data_length);

extern INT lh_free (lh_listhead *header_pointer);

extern INT lh_initialize (lh_listhead **header_pointer,
                          INT list_type_code, 
                          INT key_length,
                          BOOL signed_keys_flag,
                          BOOL duplicate_keys_flag,
                          BOOL c_string_keys_flag,
                          BOOL system_list_flag,
                          INT data_length);

extern INT lh_last (lh_listhead *header_pointer,
                    VOIDPTR key_pointer,
                    VOIDPTR data_pointer,
                    INT *data_length);

extern INT lh_next (lh_listhead *header_pointer,
                    VOIDPTR key_pointer,
                    VOIDPTR data_pointer,
                    INT *data_length);

extern INT lh_previous (lh_listhead *header_pointer,
                        VOIDPTR key_pointer,
                        VOIDPTR data_pointer,
                        INT *data_length);

extern INT lh_replace (lh_listhead *header_pointer,
                       VOIDPTR key_pointer,
                       VOIDPTR data_pointer,
                       INT data_length);

#else	    /* no prototypes */

extern CHAR *lhz_allocate();
extern INT lhz_free ();
extern lh_listnode *lhz_makenode ();
extern INT lh_add ();
extern INT lh_cmpkey ();
extern INT lh_count ();
extern INT lh_current ();
extern INT lh_delete ();
extern INT lh_find ();
extern INT lh_first ();
extern INT lh_free ();
extern INT lh_initialize ();
extern INT lh_last ();
extern INT lh_next ();
extern INT lh_previous ();
extern INT lh_replace ();

#endif	    /* of USE_PROTOTYPES */

#endif
