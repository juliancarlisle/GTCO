/* DEC/CMS REPLACEMENT HISTORY, Element DG_ESILAB_GF.C */
/* *4     9-AUG-1990 19:06:32 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 06:59:07 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 15:56:38 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:47:26 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element DG_ESILAB_GF.C */
/* DEC/CMS REPLACEMENT HISTORY, Element DG_ESILAB_GF.C*/
/* *1    19-JUN-1989 12:45:52 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element DG_ESILAB_GF.C*/





/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: DG_ESILAB_GF.C

   AUTHOR: JOHN CONROY

   DESCRIPTION: Glue routine from FORTRAN to "c" for the label saving 
                function.  Calling routine is "DGLABP".


   ************************************************************************ */




/* * INCLUDE FILES * */
/* ----------------- */

#include "esi_c_lib.h"
#include "esi_gl_defs.h"

/* * FUNCTION TITLE * */
/* ------------------ */

#ifdef vms

VOID esilab(mode,level,ichr,angle,x,y,nlist_ptr)

/* * ARGUEMENT LIST * */
/* ------------------ */

INT *mode;				/* ACTION MODE */
INT *level;				/* LEVEL NUMBER */
#if UNIX
CHAR *ichr;				/* CHARACTER */
#else
INT *ichr;                              /* ASCII CODE FOR CHARACTER */
#endif
FLOAT *angle;				/* ANGLE TO PLOT CHARACTER */
FLOAT *x;				/* X COORDINATE */
FLOAT *y;				/* Y COORDINATE */
INT *nlist_ptr;				/* POINTER INTO LINE NLIST */

/* * VARIABLE LIST * */
/* ----------------- */

{

PROGNAME("DG_ESILAB_GF");

/* ********************************************************************** */

dg_lbl_nlist(*mode,*level,*ichr,*angle,*x,*y,*nlist_ptr);

return;
}
#endif

#if UNIX

VOID esilab_(mode,level,ichr,angle,x,y,nlist_ptr,ichr_len)

/* * ARGUEMENT LIST * */
/* ------------------ */

INT *mode;				/* ACTION MODE */
INT *level;				/* LEVEL NUMBER */
#if UNIX
CHAR *ichr;				/* CHARACTER */
#else
INT *ichr;                              /* ASCII CODE FOR CHARACTER */
#endif
FLOAT *angle;				/* ANGLE TO PLOT CHARACTER */
FLOAT *x;				/* X COORDINATE */
FLOAT *y;				/* Y COORDINATE */
INT *nlist_ptr;				/* POINTER INTO LINE NLIST */
INT ichr_len;				/* NUMBER OF CHARS IN ichr STRING */

/* * VARIABLE LIST * */
/* ----------------- */

{

PROGNAME("DG_ESILAB_GF");

/* ********************************************************************** */

dg_lbl_nlist(*mode,*level,*ichr,*angle,*x,*y,*nlist_ptr);

return;
}
#endif
