/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STDLIB.H*/
/* *4    23-AUG-1990 16:39:07 VINCE "(SPR 1) modified #ifdef stuff around EXIT_SUCCESS/FAIL"*/
/* *3    14-AUG-1990 12:05:47 GILLESPIE "(SPR 2001) Major include file change"*/
/* *2    26-FEB-1990 19:07:47 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *1    30-JUN-1989 15:04:35 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STDLIB.H*/
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

#ifndef ESI_STDLIB_H
#define ESI_STDLIB_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/*	STDLIB - ANSI Standard Library Declarations */

#ifndef ESI_STDDEF_H
#include "esi_stddef.h"
#endif

struct DIV_T {
    int quot,rem;
    };
typedef struct DIV_T div_t;

struct LDIV_T {
    long quot,rem;
    };
typedef struct LDIV_T ldiv_t;

/* max value returned by rand function */
#define RAND_MAX  (INT)2147473647

#ifdef vms
#define EXIT_SUCCESS (INT)1  /* VMS NORMAL STATUS */
#define EXIT_FAILURE (INT)44 /* VMS ABORT STATUS */
#else
#define EXIT_SUCCESS (INT)0  /* NORMAL STATUS */
#define EXIT_FAILURE (INT)1  /* ABORT STATUS */
#endif

#if USE_PROTOTYPES

extern void	abort(void);
extern int	abs(int j);
extern int	atexit(void (*func)(void));
extern double	atof(const char *nptr);
extern int	atoi(const char *nptr);
extern long	int atol(const char *nptr);
extern VOIDPTR	bsearch(const VOIDPTR key, const VOIDPTR base, size_t nmemb,
     	      size_t size, int (*compar)());
extern VOIDPTR	calloc(size_t nmemb, size_t size);
extern int	cfree (VOIDPTR ptr);             /* NOTE return not ANSII */
extern div_t	div(int number, int denom);
extern void	exit(int status);
extern int	free (VOIDPTR ptr);		   /* NOTE return not ANSII */
extern char	*getenv(const char *name);
extern long int labs(long int j);
extern ldiv_t	ldiv(long int numer, long int denom);
extern VOIDPTR	malloc(size_t size);
extern void	qsort(VOIDPTR base, size_t nmemb, size_t size,
     	   int (*compar)());
extern int	rand(void);
extern VOIDPTR	realloc(VOIDPTR ptr, size_t size);
extern int	srand(int seed);
extern double	strtod(const char *nptr, char **endptr);
extern long int strtol(const char *nptr, char **endptr, int base);
extern unsigned long int strtoul(const char *nptr, char **endptr, int base );
extern int	system(const char *string);

#else

extern void	abort();
extern int	abs();
extern int	atexit();
extern double	atof();
extern int	atoi();
extern long	int atol();
extern VOIDPTR	bsearch();
extern VOIDPTR	calloc();
extern int	cfree ();
extern div_t	div();
extern void	exit();
extern int	free ();
extern char	*getenv();
extern long int labs();
extern ldiv_t	ldiv();
extern VOIDPTR	malloc();
extern void	qsort();
extern int	rand();
extern VOIDPTR	realloc();
extern int	srand();
extern double	strtod();
extern long int strtol();
extern unsigned long int strtoul();
extern int	system();

#endif				/* USE_PROTOTYPES */

#endif
