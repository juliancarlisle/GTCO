/* DEC/CMS REPLACEMENT HISTORY, Element WMGOINQOLD.C*/
/* *3     9-AUG-1990 19:21:16 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 07:09:33 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    24-JUL-1989 10:09:50 GILLESPIE "Fortran bindings for Window Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element WMGOINQOLD.C*/

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

#include "esi_wm.h"

#ifdef vms
VOID wmgoinqold(object,application,window,tnr,group,segment,pick)
INT *object,*application,*window,*tnr,*group,*segment,*pick;
{
    wmoinqold(*object,application,window,tnr,group,segment,pick);
}
#endif
#if UNIX
VOID wmgoinqold_(object,application,window,tnr,group,segment,pick)
INT *object,*application,*window,*tnr,*group,*segment,*pick;
{
    wmoinqold(*object,application,window,tnr,group,segment,pick);
}
#endif
#ifdef primos
VOID wmgoinqold(object,application,window,tnr,group,segment,pick)
INT object,application,window,tnr,group,segment,pick;
{
    wmoinqold(object,&application,&window,&tnr,&group,&segment,&pick);
}
#endif

