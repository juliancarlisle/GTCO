/* DEC/CMS REPLACEMENT HISTORY, Element MOG_SDWIGGL.C */
/* *3     9-AUG-1990 19:08:31 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 07:01:08 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1     6-NOV-1989 08:55:29 PURNA "move main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_SDWIGGL.C */
#include "esi_mo.h"
#ifdef vms

/***********************************************************************/
publicdef INT mog_sdwiggl(p1,p2,p3,p4,p5)
INT *p1;
FLOAT *p2;
DOUBLE *p3,*p4,*p5;
{
    sdwiggl(*p1,p2,*p3,*p4,*p5);
    return SUCCESS;
}

#endif         /* End of Vax code */

#if UNIX
/***********************************************************************/
publicdef INT mog_sdwiggl_(p1,p2,p3,p4,p5)
INT *p1;
FLOAT *p2;
DOUBLE *p3,*p4,*p5;
{
    sdwiggl(*p1,p2,*p3,*p4,*p5);
    return SUCCESS;
}

#endif         /* End of UNIX code */

#ifdef primos
INT mog_sdwiggl(p1,p2,p3,p4,p5)
INT p1;
FLOAT p2;
DOUBLE p3,p4,p5;
{
    sdwiggl(p1,&p2,p3,p4,p5);
    return SUCCESS;
}

#endif 
