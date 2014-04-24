/* DEC/CMS REPLACEMENT HISTORY, Element MOG_LLNEXT.C */
/* *3     9-AUG-1990 19:08:23 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 07:00:59 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1     6-NOV-1989 08:55:15 PURNA "move main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_LLNEXT.C */
#include "esi_mo.h"
#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#ifdef vms

/***********************************************************************/

publicdef INT mog_llnext(p1,p2)
LISTHEAD *p1;
BYTE *p2;
{
    return llnext(p1,p2);
}
#endif         /* End of Vax code */

#if UNIX


/***********************************************************************/

publicdef INT mog_llnext_(p1,p2)
LISTHEAD *p1;
BYTE *p2;
{
    return llnext(p1,p2);
}
#endif         /* End of UNIX code */

#ifdef primos

INT mog_llnext(p1,p2)
LISTHEAD *p1;
INT *p2;
{
    return llnext(&p1,&p2);
}

#endif  
