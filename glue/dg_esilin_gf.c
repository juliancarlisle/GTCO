/* DEC/CMS REPLACEMENT HISTORY, Element DG_ESILIN_GF.C */
/* *4     9-AUG-1990 19:06:35 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 06:59:10 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 15:56:54 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:47:45 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element DG_ESILIN_GF.C */
/* DEC/CMS REPLACEMENT HISTORY, Element DG_ESILIN_GF.C*/
/* *1    19-JUN-1989 12:45:55 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element DG_ESILIN_GF.C*/





/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: DG_ESILIN_GF.C

   AUTHOR: JOHN CONROY

   DESCRIPTION: Glue routine from FORTRAN to "c" for the line saving 
                function.  Calling routine is "DGXPLT".


   ************************************************************************ */




/* * INCLUDE FILES * */
/* ----------------- */

#include "esi_c_lib.h"
#include "esi_gl_defs.h"

/* * FUNCTION TITLE * */
/* ------------------ */

#ifdef vms

VOID esilin(mode,level,lvl_val,x,y,npts)

/* * ARGUEMENT LIST * */
/* ------------------ */

INT *mode;				/* ACTION MODE */
INT *level;				/* LEVEL NUMBER */
FLOAT *lvl_val;				/* LEVEL VALUE */
FLOAT *x;				/* X COORDINATE */
FLOAT *y;				/* Y COORDINATE */
INT *npts;				/* NUMBER OF POINTS */

/* * VARIABLE LIST * */
/* ----------------- */

{

PROGNAME("DG_ESILIN_GF");

/* ********************************************************************** */


dg_line_nlist(*mode,*level,*lvl_val,x,y,*npts);

return;
}
#endif

#if UNIX

VOID esilin_(mode,level,lvl_val,x,y,npts)

/* * ARGUEMENT LIST * */
/* ------------------ */

INT *mode;				/* ACTION MODE */
INT *level;				/* LEVEL NUMBER */
FLOAT *lvl_val;				/* LEVEL VALUE */
FLOAT *x;				/* X COORDINATE */
FLOAT *y;				/* Y COORDINATE */
INT *npts;				/* NUMBER OF POINTS */

/* * VARIABLE LIST * */
/* ----------------- */

{

PROGNAME("DG_ESILIN_GF");

/* ********************************************************************** */


dg_line_nlist(*mode,*level,*lvl_val,x,y,*npts);

return;
}
#endif
