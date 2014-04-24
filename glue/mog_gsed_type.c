/* DEC/CMS REPLACEMENT HISTORY, Element MOG_GSED_TYPE.C */
/* *4     9-AUG-1990 19:08:09 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:00:42 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2     6-NOV-1989 10:42:16 GILLESPIE "(SPR 30) New glue for modelling" */
/* *1     6-NOV-1989 10:40:55 GILLESPIE "Glue for mo_get_sed_type" */
/* DEC/CMS REPLACEMENT HISTORY, Element MOG_GSED_TYPE.C */
#include "esi_mo.h"
#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

/* ************************************************************************ */
/*                                                                          */
/*    Routine:    mog_get_sed_type                                          */
/*                                                                          */
/*    Function:   Glue routine to retrieve the sedimentation type for each  */
/*                layer (which is stored in a stroke user struct).  The     */
/*                type values are stored in an array of INT's with the      */ 
/*                array subscripts corresponding to the unsorted (in Y)     */ 
/*                layers (strokes).                                         */
/*									    */
/* ************************************************************************ */

#ifdef vms

INT  mog_get_sed_type( nlist, sed_type_arr)

  NLIST_HEADER   *nlist;
  INT            *sed_type_arr;            /* Pointer to array of sed types  */
{
  SED_DATA_STRUCT sed_struct;
  UINT             nstrokes;
  INT             status;
  INT             i;
  INT             nretur;

  status = nl_inq_nlist_int( *nlist, NL_NLIST_NSTROKES, (INT *)&nstrokes);

  if ( nstrokes == 0)
    {
     return FAIL;
    }


  for ( i = 0; i < nstrokes; i ++)
    {
     status = nl_inq_stroke_user_struct( *nlist, i + 1,
				     sizeof(SED_DATA_STRUCT),
				     (VOIDPTR)&sed_struct, (size_t *)&nretur);
     sed_type_arr[i] = sed_struct.sed_type;
    }

  return status;

}


#endif         /* End of Vax code */

#if UNIX

INT  mog_get_sed_type_( nlist, sed_type_arr)

  NLIST_HEADER   *nlist;
  INT            *sed_type_arr;            /* Pointer to array of sed types  */
{
  SED_DATA_STRUCT sed_struct;
  INT             nstrokes, status;
  INT             i;
  INT             nretur;

  status = nl_inq_nlist_int( *nlist, NL_NLIST_NSTROKES, &nstrokes);

  if ( nstrokes == 0)
    {
     return FAIL;
    }


  for ( i = 0; i < nstrokes; i ++)
    {
     status = nl_inq_stroke_user_struct( *nlist, i + 1,
                                         sizeof(SED_DATA_STRUCT),
                                         (VOIDPTR)&sed_struct, (size_t *)&nretur);      

     sed_type_arr[i] = sed_struct.sed_type;
    }

}

#endif         /* End of UNIX code */

#ifdef primos

INT  mog_get_sed_type( nlist, sed_type_arr)
  NLIST_HEADER   *nlist;
  INT            sed_type_arr;
{
  SED_DATA_STRUCT sed_struct;
  INT             nstrokes, status;
  INT             i;
  INT             nretur;
  INT             *t_sed_type_arr;        /* Pointer to array of sed types  */

  t_sed_type_arr = &sed_type_arr;

/* Steven 9/14/88 nlist is declared as real* 8 in the calling program
   to hold the address of the nlist */
  status = nl_inq_nlist_int( nlist, NL_NLIST_NSTROKES, &nstrokes);

  if ( nstrokes == 0)
    {
     return FAIL;
    }


  for ( i = 0; i < nstrokes; i ++)
    {
     status = nl_inq_stroke_user_struct( nlist, i + 1,
					 sizeof(SED_DATA_STRUCT),
					 (VOIDPTR)&sed_struct, (size_t *)&nretur);

     *(t_sed_type_arr + i) = sed_struct.sed_type;
    }

}

#endif
