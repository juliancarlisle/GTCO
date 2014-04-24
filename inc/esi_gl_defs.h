/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_DEFS.H*/
/* *11   28-JUN-1991 11:39:02 DOUG "(SPR 8429) Case #2997. Changed FINDER_VERSION_INCREMENT to 3 (for Version 6.3)."*/
/* *10    3-MAY-1991 16:21:37 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *9    14-AUG-1990 11:47:49 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *8    12-APR-1990 19:19:11 JULIAN "(SPR -1) don't use prototypes on ULTRIX (mips)."*/
/* *7    27-FEB-1990 08:39:06 JULIAN "(SPR 6010) Change definition of UNIX to 0, 1 rather than FALSE, TRUE"*/
/* *6    12-FEB-1990 21:14:44 GILLESPIE "(SPR 1) Remove SUN3, SUN4 symbols"*/
/* *5     9-FEB-1990 13:53:59 GILLESPIE "(SPR 1) Remove HOST_VERSION"*/
/* *4     5-FEB-1990 18:42:08 GILLESPIE "(SPR 6002) Change DATE to char[12]; add DATE_TIME and TCP"*/
/* *3    14-SEP-1989 16:42:02 GORDON "(SPR 100) Gulf/Sun/Unix changes"*/
/* *2    26-JUL-1989 00:13:04 GILLESPIE "(SPR 51) Minor adjustments"*/
/* *1    30-JUN-1989 15:01:02 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GL_DEFS.H*/
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

#ifndef ESI_GL_DEFS_H
#define ESI_GL_DEFS_H 1

#ifdef vms
#define UNIX 0
#else
#ifdef primos
#define UNIX 0
#else
#define UNIX 1
#endif
#endif

/*********************** End auto-definition of host **************************/

#include "esi_stddef.h"		    /* ANSI standard symbol definitions */

#define FINDER_VERSION (INT)6
#define FINDER_VERSION_INCREMENT (INT)3

/* ------- Scope declarations for ESI C code ---------- */
#define publicdef
#define privatedef static

/* ------- Type declarations for ESI C code ---------- */
typedef long INT;
typedef long LONG;
typedef long BOOL;	     /*	used for true/false things		    */
typedef unsigned long UINT;

typedef short SHORT;
typedef unsigned short USHORT;

typedef char CHAR;
typedef char TBOOL;	     /*	used for true/false things (BOOL preferred) */
typedef unsigned char BYTE;
typedef unsigned char TINY;  /*	used for numbers 0 > x > 255		    */

typedef INT (*INT_FUNCTION_PTR)();
typedef CHAR **TCP;

			     /*	define the data type constants		    */
#define CHAR_TYPE   ((INT)1)
#define INT_TYPE    ((INT)3)
#define FLOAT_TYPE  ((INT)4)
#define DATE_TYPE   ((INT)8)
#define BOOL_TYPE   ((INT)9)

			     /*	define oft-used macros			    */
#define FOREVER for(;;)
#define ABS(x) (((x) < 0) ? -(x) : (x))
#define MAX(x, y) (((x) < (y)) ? (y) : (x))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

			     /*	define memory management macros		    */
#define malloc(nbytes) tc_alloc(nbytes)
#define free(nbytes) tc_free(nbytes)
#define realloc(ptr,size) tc_realloc(ptr,size)

			     /*	Define often used constants		    */
#define TRUE 1
#define ON (INT)1
#define FALSE 0
#define OFF (INT)0
			     /*	NULL defined in stddef.h, per ANSI	    */
#define NUL '\0'	     /*	This is the NUL character, not the NULL	    */
			     /*	pointer					    */
#define NULL_FUNCTION_PTR (INT_FUNCTION_PTR)0
#define SUCCESS ((INT)0)
#define FAIL ((INT)-50001)
#define CANCEL ((INT)50001)
#define ESI_ERROR_OFFSET ((INT)50000)
			     /*	Define logical operators.  These may help
			     	us avoid the deadly 'if (flag = TRUE)'
			     	error.					    */

#define EQUALS ==
#define IS_NOT_EQUAL_TO !=
#define AND &&
#define OR ||
#define NOT !

			     /*	Maximum standard string length.		    */
#define STMAX 128

/* ------- Standard Program Name String -------------- */
#define PROGNAME(x) privatedef CHAR progname[] = x


			     /*	Deal with host-specific typedefs, ANSI	    */
			     /*	compatability, prototypes, etc		    */

/****************************************************************************
The following section defines the data types VOID, VOIDPTR, FLOAT, DOUBLE
and the storage classes const and volatile.  ANSI allows void * to indicate
a generic pointer, but some target environments do not accept this construct.
****************************************************************************/
#if UNIX
/****************************************************************************/
/* UNIX-based systems should have their pecularities defined here */
/****************************************************************************/
#ifdef sun
#define USE_PROTOTYPES FALSE
#define VOID void
#define const
#define volatile
typedef char *VOIDPTR;
typedef float FLOAT;
typedef double DOUBLE;
#define Real float
/****************************************************************************/
#else
/****************************************************************************/
#ifdef mips	/* Ultrix for RISC (Decstation 3100 et al) */
#define USE_PROTOTYPES FALSE
#define VOID void
#define const
#define volatile
typedef void *VOIDPTR;					/* 910319:sjs: mips has void type */
typedef float FLOAT;
typedef double DOUBLE;
#define Real float
/****************************************************************************/
#else
/****************************************************************************/
#ifdef applec
#define USE_PROTOTYPES TRUE
#define VOID void
typedef void *VOIDPTR;
typedef float FLOAT;
typedef extended DOUBLE;
/****************************************************************************/
#else
/****************************************************************************/
#ifdef THINK_C
#define USE_PROTOTYPES TRUE
#define VOID void
#define const
#define volatile
typedef void *VOIDPTR;
typedef float FLOAT;
typedef double DOUBLE;
/****************************************************************************/
#else
/****************************************************************************/
	    /* Begin Generic Unix (ANSI) declarations */
#define USE_PROTOTYPES TRUE
#define VOID void
typedef void *VOIDPTR;
typedef float FLOAT;
typedef double DOUBLE;
/****************************************************************************/
#endif	    /* End of THINK_C */
#endif	    /* End of applec */
#endif	    /* End of mips */
#endif	    /* End of sun */
/****************************************************************************/
#else	    /* associated with UNIX ifdef */
/****************************************************************************/
#ifdef vms
#define USE_PROTOTYPES TRUE
#define VOID void
typedef void *VOIDPTR;
typedef float FLOAT;
typedef double DOUBLE;
typedef float Real;
#else	   /* End of vms */
#ifdef primos
#define USE_PROTOTYPES FALSE
#define VOID void
#define const
#define volatile
typedef char *VOIDPTR;
typedef float FLOAT;
typedef double DOUBLE;
#endif	    /* PRIMOS */
#endif	    /* vms */
/****************************************************************************/
#endif	    /* UNIX */
/****************************************************************************/

#endif	    /* ESI_GL_DEFS_H */
