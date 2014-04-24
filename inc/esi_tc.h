/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TC.H*/
/* *6    14-AUG-1990 11:51:16 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *5     9-FEB-1990 13:45:15 PURNA "(SPR 0) add tc_prime"*/
/* *4     5-FEB-1990 18:42:49 GILLESPIE "(SPR 6002) Change DATE to char[12]; add DATE_TIME and TCP"*/
/* *3    14-SEP-1989 18:15:24 GORDON "(SPR -1) checkin from gulf"*/
/* *2    18-JUL-1989 09:27:00 GORDON "(SPR 100) merge changes"*/
/* *1    30-JUN-1989 15:04:57 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TC.H*/
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

#ifndef ESI_TC_H
#define ESI_TC_H 1

/*************************************************************************

FILE:    ESI_TC.H

DESCRIPTION:

    ESI_TC.H contains the declarations and structure definitions
    which are necessary to use the miscellaneous tools (TC).

*************************************************************************/

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifdef sun
#include <alloca.h>		/* For stack allocator */
#endif

#if USE_PROTOTYPES

extern CHAR  *tch_today(DATE string);
extern CHAR  *tch_tomorrow(DATE string);
extern VOIDPTR tc_alloc(size_t nbytes);
extern CHAR  *tc_today(DATE string);
extern INT    tc_array_stretch(DOUBLE in[], INT in_len, DOUBLE xform[][2],
	      INT xform_len, DOUBLE out[]);
extern INT    tc_check_pointer(VOIDPTR ptr);
extern INT    tc_free(VOIDPTR ptr);
extern INT    tc_magnitude(DOUBLE number);
extern INT    tc_pack_bits(INT numitems, INT onoroff[32], INT *packed_flags);
extern VOIDPTR tc_realloc(VOIDPTR p_in, size_t nbytes);
extern INT    tc_swap(VOIDPTR a, VOIDPTR b, size_t size);
extern VOIDPTR tc_zalloc(size_t size);
extern VOIDPTR tc_zeroes(VOIDPTR ps, size_t num_bytes);
extern BOOL    tc_prime(INT inum);
#else

extern CHAR  *tch_today();
extern CHAR  *tch_tomorrow();
extern VOIDPTR tc_alloc();
extern CHAR  *tc_today();
extern INT    tc_array_stretch();
extern INT    tc_check_pointer();
extern INT    tc_free();
extern INT    tc_magnitude();
extern VOIDPTR tc_realloc();
extern INT    tc_swap();
extern INT    tc_pack_bits();
extern VOIDPTR tc_zalloc();
extern VOIDPTR tc_zeroes();
extern BOOL    tc_prime();

#endif

/*
 * TALLOC - this macro is used for allocating temporary space conveniently --
 * that is, space which is needed only during the scope of the function which
 * allocates it.  For VMS, salloc() is used, and the space is freed
 * automatically when the function returns.  For machines which don't have
 * this capability, a specific freeing call is necessary, hence the
 * NEED_TO_FREE macro.  Any time space is allocated using TALLOC, there
 * MUST be corresponding freeing code based upon NEED_TO_FREE.
 */

#ifdef sun
/* NOTE:  alloca is in standard Sun library - 'Stack Allocator' */
#define TALLOC(ptr) alloca(ptr)
#define NEED_TO_FREE FALSE
#else
#define TALLOC(ptr) tc_alloc(ptr)
#define NEED_TO_FREE TRUE
#endif	/* sun */

/*
 * macros to perform standard allocations
 * TCP allocates a table of character pointers, producing a zero-terminated
 * table (which FGS tools deal with nicely)
 */

#define ALLOCATE(dtype)        ((dtype *)tc_zalloc((size_t)sizeof (dtype)))
#define STRING_ALLOCATE(stype) ((CHAR  *)tc_zalloc((size_t)strlen((char *)stype) + 1))
#define TCP_ALLOCATE(n)        ((TCP)tc_zalloc((size_t)(((n)+1)*sizeof (char *))))
#define TI_ALLOCATE(n)         ((INT   *)tc_zalloc((size_t)(((n)+1)*sizeof (INT))))


#endif
