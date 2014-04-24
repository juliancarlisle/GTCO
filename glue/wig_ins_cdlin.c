/* DEC/CMS REPLACEMENT HISTORY, Element WIG_INS_CDLIN.C*/
/* *3     9-AUG-1990 19:19:52 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:08:27 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:16:49 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIG_INS_CDLIN.C*/

/******************************************************************************

                Copyright Finder Graphic Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphic Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphic Systems, Inc.
			579 Market Street
			San Francisco, CA  USA 94105
			(415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#include "esi_wi.h"
#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifdef vms
publicdef INT wig_insert_cd_line(id, control, line, text)
INT *id,*control,*line;
DSC *text;
{
	CHAR string1[MAXLEN];
    DSCTOCS(text,string1);
    return wi_insert_cd_line(*id,*control,*line,string1);
}
#endif
#if UNIX
publicdef INT wig_insert_cd_line_(id, control, line, text, len)
INT *id,*control,*line;
CHAR *text;
INT len;
{
	CHAR string1[MAXLEN];
    ftocstr(text,string1,len);
    return wi_insert_cd_line(*id,*control,*line,string1);
}
#endif
#ifdef primos
publicdef INT wig_insert_cd_line(id, control, line, text, z1, z2, z3, z4)
INT id,control,line;
CHAR *text;
INT z1, z2, z3, z4;
{
	CHAR string1[MAXLEN];
    ftocstr((CHAR *)&text,string1,z4);
    return wi_insert_cd_line(id,control,line,string1);
}
#endif

