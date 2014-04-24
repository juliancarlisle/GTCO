/* DEC/CMS REPLACEMENT HISTORY, Element MOG_SDDFWIG.C */
/* *3     9-AUG-1990 19:08:29 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 07:01:05 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1     6-NOV-1989 08:55:27 PURNA "move main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_SDDFWIG.C */
#include "esi_mo.h"

#ifdef vms

/***********************************************************************/
publicdef INT mog_sddfwig(p1,p2,p3,p4)
DOUBLE *p1,*p2;
INT    *p3,*p4;
{
    sddfwig(*p1,*p2,*p3,*p4);
    return SUCCESS;
}
#endif         /* End of Vax code */

#if UNIX


/***********************************************************************/
publicdef INT mog_sddfwig_(p1,p2,p3,p4)
DOUBLE *p1,*p2;
INT    *p3,*p4;
{
    sddfwig(*p1,*p2,*p3,*p4);
    return SUCCESS;
}

#endif         /* End of UNIX code */

#ifdef primos
INT mog_sddfwig(p1,p2,p3,p4)
DOUBLE p1,p2;
INT    p3,p4;
{
    sddfwig(p1,p2,p3,p4);
    return SUCCESS;
}
#endif  
