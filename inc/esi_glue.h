/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GLUE.H*/
/* *7     3-MAY-1991 16:21:33 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *6    14-AUG-1990 11:47:45 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *5    27-FEB-1990 08:39:16 GILLESPIE "(SPR 6010) Fix up Ultrix checkin"*/
/* *4    26-FEB-1990 19:06:56 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *3     9-AUG-1989 11:45:09 JULIAN "(SPR -1) change ftocstr function definition"*/
/* *2    26-JUL-1989 00:12:59 GILLESPIE "(SPR 51) Minor adjustments"*/
/* *1    30-JUN-1989 15:00:59 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GLUE.H*/

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

#ifndef ESI_GLUE_H
#define ESI_GLUE_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef MAXLEN
#define MAXLEN 256
#endif

typedef struct {
     INT total_items;            /* total_items requsted, not includes NULL */
     TCP tcp;
    }TSG_TCP;
	
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

#ifdef vms
#ifndef $DESCRIPTOR
#include "descrip.h"
#endif
#define USE_DESCRIPTORS 1
#endif

/*	#ifdef mips					 910318:sjs: not needed, using UNIX */
/*	#ifndef _DESCRIPTOR			 910318:sjs: not needed, using UNIX */
/*	#include "GKS3Ddescrip.h"	 910318:sjs: not needed, using UNIX */
/*	#endif						 910318:sjs: not needed, using UNIX */
/*	#define USE_DESCRIPTORS 1	 910318:sjs: not needed, using UNIX */
/*	#endif						 910318:sjs: not needed, using UNIX */

#ifdef USE_DESCRIPTORS

#define DSC		struct dsc$descriptor
#define DSC_VSA		struct dsc$descriptor_vsa
#define CSTODSC(cs,dsc) gf_str_to_desc(cs,dsc)
#define DSCTOCS(dsc,cs) gf_desc_to_str(dsc, cs)

#define STRING_DESCRIPTOR_FROM_C(string) hoz_str_descpt(string)
#define STRING_DESCRIPTOR_TO_C(string) hoz_str_descpt(string)

#if USE_PROTOTYPES
extern VOID gf_str_to_desc(CHAR *cs, DSC *dsc);
extern VOID gf_desc_to_str(DSC *dsc, CHAR *cs);
extern struct dsc$descriptor *hoz_str_descpt(CHAR *cs);
#else
extern VOID gf_str_to_desc();
extern VOID gf_desc_to_str();
extern struct dsc$descriptor *hoz_str_descpt();
#endif

#endif /* End of USE_DESCRIPTORS */

#if UNIX							/* 910318:sjs: changed from 'sun' */

#if USE_PROTOTYPES
extern INT ftocstr(CHAR *, CHAR *, INT);
extern VOID ctofstr(CHAR *, CHAR *, INT);
#else
extern INT ftocstr();
extern VOID ctofstr();
#endif

#endif /* End of SUN section */

#ifdef primos
#define STRING_DESCRIPTOR_FROM_C(string) ((char [])string)
#define STRING_DESCRIPTOR_TO_C(string) ((char [])string)
#endif

#endif
