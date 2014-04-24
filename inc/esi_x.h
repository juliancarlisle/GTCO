/* DEC/CMS REPLACEMENT HISTORY, Element ESI_X.H */
/* *7    23-OCT-1990 14:07:01 KEE "(SPR -1) Motif and DecWindow merge" */
/* *6    14-AUG-1990 12:05:51 GILLESPIE "(SPR 2001) Major include file change" */
/* *5     4-MAR-1990 10:25:30 JULIAN "(SPR 6010) Fix ultrix compile errors. " */
/* *4     1-MAR-1990 11:50:52 JULIAN "(SPR 6010) add ifdef USE_X and delete if HOST=SUN (Kee)" */
/* *3    26-FEB-1990 19:07:59 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)" */
/* *2     6-FEB-1990 00:24:16 JULIAN "(SPR -1) Include file for X" */
/* *1     6-FEB-1990 00:22:32 JULIAN "X include file" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_X.H */
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Exploration Systems, Inc. 1989                          */
/*         Unpublished -- All rights reserved                                       */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY   */
/*CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE      */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*          Exploration Systems, Inc.                                               */
/*          579 Market Street                                                       */
/*          San Francisco, CA  USA 94105                                            */
/*          (415) 974-1600                                                          */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef  ESI_X_H
#define ESI_X_H

#ifdef USE_X

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifdef vms

#define __FILE 1
#define __STRING_LOADED 
#define __STDDEF

#endif

#include <X11/Xlib.h>

#ifdef MOTIF  /* ---------- BEGIN MOTIF BLOCK ---------- */

#include <Xm/Xm.h>
#include "ansixm.h"

#else  /* ---------- END MOTIF BLOCK - BEGIN DECW BLOCK ---------- */

#include <X11/DwtAppl.h>
#include <X11/DECwDwtApplProg.h>
#include "ansidwt.h"

#endif  /* ---------- END DECW BLOCK ---------- */
#endif
#endif
