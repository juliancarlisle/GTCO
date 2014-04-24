/* DEC/CMS REPLACEMENT HISTORY, Element MOG_EMP_DRIV.C */
/* *4     9-AUG-1990 19:08:06 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:00:39 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2     6-NOV-1989 16:32:47 GILLESPIE "(SPR 1) Change model_emp_driver to mo_emp_driver" */
/* *1     6-NOV-1989 08:55:03 PURNA "move main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_EMP_DRIV.C */
#include "esi_mo.h"
#ifndef ESI_NL_H
#include "esi_nl.h"
#endif
#ifdef vms
/******************************************************************************/

publicdef INT mog_emp_driver(nlist, vel_nlist, pModel, option)
NLIST_HEADER nlist;
NLIST_HEADER vel_nlist;
STRAT_MODEL_STRUCT *pModel;
INT option;
{

    return mo_emp_driver(&nlist, &vel_nlist, &pModel, &option);
}

#endif         /* End of Vax code */

#if UNIX
/******************************************************************************/

publicdef INT mog_emp_driver(nlist, vel_nlist, pModel, option)
NLIST_HEADER nlist;
NLIST_HEADER vel_nlist;
STRAT_MODEL_STRUCT *pModel;
INT option;
{

    return mo_emp_driver_(&nlist, &vel_nlist, &pModel, &option);
}

#endif         /* End of UNIXcode */

#ifdef primos


/******************************************************************************/

publicdef INT mog_emp_driver(nlist, vel_nlist, pModel, option)
NLIST_HEADER nlist;
NLIST_HEADER vel_nlist;
STRAT_MODEL_STRUCT *pModel;
INT option;
{
    fortran mo_emp_driver();
    return mo_emp_driver(nlist, vel_nlist, pModel, option);
}
#endif   
