/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MATH.H*/
/* *7    26-OCT-1990 11:39:09 GILLESPIE "(SPR 1) Clean up logic to allow use of native math.h on several platforms"*/
/* *6    14-AUG-1990 12:05:19 GILLESPIE "(SPR 2001) Major include file change"*/
/* *5    12-MAR-1990 22:17:34 GILLESPIE "(SPR 6019) MPW and LSC changes needed after DECStation mods"*/
/* *4     4-MAR-1990 10:24:39 JULIAN "(SPR 6010) Fix ultrix compile errors. "*/
/* *3    28-FEB-1990 11:59:19 GILLESPIE "(SPR 6010) Honour thy ANSI"*/
/* *2    26-FEB-1990 19:07:21 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *1    30-JUN-1989 15:02:44 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MATH.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Exploration Systems, Inc. 1989                          */
/*                    Unpublished -- All rights reserved                            */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY   */
/*CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE      */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*                            Exploration Systems                                   */
/*                            c/o Finder Graphics Systems                           */
/*                            201 Tamal Vista Blvd.                                 */
/*                            Corte Madera, CA  94925                               */
/*                            (415) 927-0100                                        */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_MATH_H
#define ESI_MATH_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/*  math constants and related macros                                               */

#define PI 3.14159265358979323846
#define D_TO_R(x) (PI * (x) / 180.0)
#define R_TO_D(x) (180.0 * (x) / PI)

/*  The following are defined by ANSI.  The                                         */
/*  following environments all use the same                                         */
/*  numerical values: VMS, SUN, ULTRIXR.                                            */
/*  Persons porting to additional environments                                      */
/*  should check that they also have the same                                       */
/*  numeric value as defined on the local                                           */
/*  system.  I have found them in errno.h on                                        */
/*  other environments... jgg                                                       */


#define EDOM        (INT)33              /* math argument */
#define ERANGE      (INT)34              /* result too large */

#ifdef primos

#define HUGE_VAL 1.0E31      /* largest floating point number           */

#endif          /* if HOST == PRIMOS    */

#ifdef vms

#ifndef __MATH
#include <math.h>
#endif

#define MATH_DONE

#endif          /* end vms   */

#ifdef sun

#include <math.h>

#define MATH_DONE

#endif

#ifdef mips

#define HUGE_VAL    1.8e+308

#endif

#ifdef applec

#ifndef __MATH__
#include <Math.h>
#endif

#define MATH_DONE

#endif

#ifdef THINK_C

#ifndef _H_math
#include <Math.h>
#endif

#define MATH_DONE

#endif

#ifndef MATH_DONE

#if USE_PROTOTYPES
extern double acos (double x);
extern double asin (double x);
extern double atan (double x);
extern double atan2 (double x, double y);
extern double ceil (double x);
extern double cos (double x);
extern double cosh (double x);
extern double exp (double x);
extern double fabs (double x);
extern double floor (double x);
extern double fmod (double x, double y);
extern double frexp (double value, int *exp);
extern double hypot (double x, double y);
extern double ldexp (double x, int e);
extern double log (double x);
extern double log10 (double x);
extern double modf (double value, double *iptr);
extern double pow (double base, double exp);
extern double sin (double x);
extern double sinh (double x);
extern double sqrt (double x);
extern double tan (double x);
extern double tanh (double x);

#else
extern double acos ();
extern double asin ();
extern double atan ();
extern double atan2 ();
extern double ceil ();
extern double cos ();
extern double cosh ();
extern double exp ();
extern double fabs ();
extern double floor ();
extern double fmod ();
extern double frexp ();
extern double hypot ();
extern double ldexp ();
extern double log ();
extern double log10 ();
extern double modf ();
extern double pow ();
extern double sin ();
extern double sinh ();
extern double sqrt ();
extern double tan ();
extern double tanh ();

#endif          /* USE_PROTOTYPES*/

#else

#undef MATH_DONE

#endif
#endif          /* ESI_MATH_H */
