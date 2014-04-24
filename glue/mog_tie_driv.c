/* DEC/CMS REPLACEMENT HISTORY, Element MOG_TIE_DRIV.C */
/* *3     9-AUG-1990 19:08:34 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     7-FEB-1990 07:01:12 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *1     6-NOV-1989 08:55:34 PURNA "move main source" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_TIE_DRIV.C */
#include "esi_mo.h"

#ifdef vms

/******************************************************************************/

publicdef INT mog_tie_driver(nlist, pModel, option)
NLIST_HEADER nlist;
STRAT_MODEL_STRUCT *pModel;
INT option;
{

    return mo_tie_driver(&nlist, &pModel, &option);
}

#endif         /* End of Vax code */

#if UNIX

/******************************************************************************/

publicdef INT mog_tie_driver(nlist, pModel, option)
NLIST_HEADER nlist;
STRAT_MODEL_STRUCT *pModel;
INT option;
{

    return mo_tie_driver_(&nlist, &pModel, &option);
}
#endif         /* End of UNIX code */

#ifdef primos
/******************************************************************************/

publicdef INT mog_tie_driver(nlist, pModel, option)
NLIST_HEADER nlist;
STRAT_MODEL_STRUCT *pModel;
INT option;
{

    fortran mo_tie_driver();
    return mo_tie_driver(nlist, pModel, option);
}
#endif 
