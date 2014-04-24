/* DEC/CMS REPLACEMENT HISTORY, Element HO_CPU_TM_GC.C*/
/* *3     9-AUG-1990 19:07:22 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *2     7-FEB-1990 06:59:56 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    20-SEP-1989 17:09:24 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element HO_CPU_TM_GC.C*/
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

/* ************************************************************************ 

   NAME: HO_CPU_TM_GC.C

   AUTHOR: G Shannon

   DESCRIPTION: C to Fortran glue for function ho_cpu_time, which obtains
		the cpu time.

   ************************************************************************ */

#include "esi_gl_defs.h"
#include "esi_ho.h"

#ifdef vms
publicdef DOUBLE ho_cpu_tm_gc()
{
    return(ho_cpu_time());
}
#endif

#if UNIX
publicdef DOUBLE ho_cpu_tm_gc_()
{
    return(ho_cpu_time());
}
#endif

#ifdef primos
publicdef DOUBLE ho_cpu_tm_gc()
{
    return(ho_cpu_time());
}
#endif
