/* DEC/CMS REPLACEMENT HISTORY, Element MOG_HOBLMOVE.C */
/* *3     9-AUG-1990 19:08:14 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 07:00:46 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1     6-NOV-1989 08:55:08 PURNA "move main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_HOBLMOVE.C */

#include "esi_mo.h"
#ifndef ESI_HO_DESC_H
#include "esi_ho_desc.h"
#endif
#ifdef vms
/***********************************************************************/

publicdef INT mog_hoblockmove(p1,p2,n)
BYTE **p1,*p2;
INT *n;
{
    hoblockmove(*p1,p2,*n);
    return SUCCESS;
}
#endif

#if UNIX

/***********************************************************************/

publicdef INT mog_hoblockmove_(p1,p2,n)
BYTE **p1,*p2;
INT *n;
{
    hoblockmove(*p1,p2,*n);
    return SUCCESS;
}
#endif         /* End of UNIX code */

#ifdef primos
INT mog_hoblockmove(p1,p2,n)
BYTE p1, p2;
INT  n;
{
   return hoblockmove (p1, &p2, n);
}

#endif     
