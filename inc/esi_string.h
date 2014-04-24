/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STRING.H*/
/* *3    19-SEP-1989 13:59:03 GILLESPIE "(SPR 300) ROLLBACK OF LAST CHANGE"*/
/* *2    19-SEP-1989 12:21:28 JULIAN "(SPR 1) added __STRING_LOADED define for system compatability."*/
/* *1    30-JUN-1989 15:04:38 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STRING.H*/
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

#ifndef ESI_STRING_H
#define ESI_STRING_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* STRING.H  ANSI string handling function definitions */

#ifndef ESI_STDDEF_H
#include "esi_stddef.h"
#endif

#if USE_PROTOTYPES

extern VOIDPTR	memchr (const void *s1, int c, size_t size);
extern int	memcmp (const void *s1, const void *s2, size_t size);
extern VOIDPTR	memcpy (void *s1, const void *s2, size_t size);
extern VOIDPTR	memmove (void *s1, const void *s2, size_t size);
extern VOIDPTR	memset (void *s, int character, size_t size);
extern char	*strcat (char *s1, const char *s2);
extern char	*strchr (const char *s, int character);
extern int	strcmp (const char *s1, const char *s2);
extern char	*strcpy (char *s1, const char *s2);
extern size_t	strcspn (const char *s1, const char *s2);
extern char	*strerror (int errnum);
extern size_t	strlen (const char *s);
extern char	*strncat (char *s1, const char *s2, size_t n);
extern int	strncmp (const char *s1, const char *s2, size_t n);
extern char	*strncpy (char *s1, const char *s2, size_t n);
extern char	*strpbrk (const char *s1, const char *s2);
extern char	*strrchr (const char *s, int character);
extern size_t	strspn (const char *s1, const char *s2);
extern char	*strstr (const char *s1, const char *s2);
extern char	*strtok (char *s1, const char *s2);

#else

extern VOIDPTR	memchr ();
extern int	memcmp ();
extern VOIDPTR	memcpy ();
extern VOIDPTR	memmove ();
extern VOIDPTR	memset ();
extern char	*strcat ();
extern char	*strchr ();
extern int	strcmp ();
extern char	*strcpy ();
extern size_t	strcspn ();
extern char	*strerror ();
extern size_t	strlen ();
extern char	*strncat ();
extern int	strncmp ();
extern char	*strncpy ();
extern char	*strpbrk ();
extern char	*strrchr ();
extern size_t	strspn ();
extern char	*strstr ();
extern char	*strtok ();

#endif

#endif
