/* DEC/CMS REPLACEMENT HISTORY, Element MOG_LLCOUNT.C */
/* *3     9-AUG-1990 19:08:17 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 07:00:53 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1     6-NOV-1989 08:55:10 PURNA "move main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_LLCOUNT.C */
#include "esi_mo.h"
#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#ifdef vms
/***********************************************************************/

publicdef INT mog_llcount(p1)
LISTHEAD *p1;
{
    return llcount(p1);
}
#endif         /* End of Vax code */

#if UNIX
/***********************************************************************/

publicdef INT mog_llcount_(p1)
LISTHEAD *p1;
{
    return llcount(p1);
}

#endif         /* End of UNIX code */

#ifdef primos

INT mog_llcount(p1)
LISTHEAD *p1;
{
    return llcount(&p1);
}
#endif 
