/* DEC/CMS REPLACEMENT HISTORY, Element WIGSCDT.C*/
/* *3     9-AUG-1990 19:18:43 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:07:35 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:15:47 GILLESPIE "Fortran bindings for Workstation Interface"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WIGSCDT.C*/

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
#include "esi_glue.h"
#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifdef vms
publicdef INT wigscdt(id,control,text)
INT *id,*control;
DSC *text;
{
    CHAR *ptr;
    INT status;

    ptr = (CHAR *) TALLOC(text->dsc$w_length+1);
    DSCTOCS(text,ptr);
    status = wiscdt(*id,*control,ptr);
#if NEED_TO_FREE
    tc_free(ptr);
#endif
    return status;
}
#endif
#if UNIX
publicdef INT wigscdt_(id,control,text,len)
INT *id,*control;
CHAR *text;
INT len;
{
    CHAR *ptr;
    INT status;

    ptr = (CHAR *) TALLOC(len+1);
    ftocstr(text,ptr,len);
    status = wiscdt(*id,*control,ptr);
#if NEED_TO_FREE
    tc_free(ptr);
#endif
    return status;
}
#endif
#ifdef primos
publicdef INT wigscdt(id,control,text,z1,z2,z3)
INT id,control;
CHAR *text;
INT z1,z2,z3;
{
    CHAR *ptr;
    INT status;

    ptr = TALLOC((z3 & 0xffff) + 1);
    ftocstr((CHAR *)&text,ptr,z3);
    status = wiscdt(id,control,ptr);
#if NEED_TO_FREE
    tc_free(ptr);
#endif
    return status;
}
#endif

