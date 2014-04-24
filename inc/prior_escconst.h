/* DEC/CMS REPLACEMENT HISTORY, Element PRIOR_ESCCONST.H */
/* *3     3-MAY-1991 16:22:06 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version" */
/* *2    23-OCT-1990 14:07:05 KEE "(SPR -1) Motif and DecWindow merge" */
/* *1    23-OCT-1990 14:05:19 KEE "prior gks escape const" */
/* DEC/CMS REPLACEMENT HISTORY, Element PRIOR_ESCCONST.H */
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Finder Graphics Systems, Inc. 1990                      */
/*         Unpublished -- All rights reserved                                       */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND   */
/*MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE  */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*          Finder Graphics Systems, Inc.                                           */
/*          201 Tamal Vista Blvd                                                    */
/*          Corte Madera, CA  USA 94925                                             */
/*          (415) 927-0100                                                          */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef PRIOR_ESCCONST_H

#define PRIOR_ESCCONST_H 1

/**** These come from /usr/gks/agksconst.h (PRIOR GKS) ***                          */
/*----------------------------------------------------------------------------------*/
/*--- The following constants are the escape function codes for the ---             */
/*--- kernel-supported GKS/C escape functions.                      ---             */
/*----------------------------------------------------------------------------------*/

#define GESC_ACTSEG -1  /* ACTIVATE SEGMENT         */
#define GESC_DEACTSEG   -2  /* DEACTIVATE SEGMENT           */
#define GESC_DRW1SEG    -5  /* DRAW ONE SEGMENT         */
#define GESC_ICURDISP   -6  /* INQUIRE CURRENT DISPLAY SPACE SIZE   */
#define GESC_IIRGSTRAT  -7  /* INQUIRE IRG STRATEGY         */
#define GESC_SIRGSTRAT  -8  /* SET IMPLICIT REGENERATION STRATEGY   */
/* correction of PRIOR GKS by Finder - comments of GESC_IIRGSTRAT and               */
/*   GESC_SIRGSTRAT have been reversed to the correct order                         */
#define GESC_SETWINDOW  -9  /* SET DEFAULT WINDOW SIZE      */
/*>>> OBSOLETE                                                                      */
#define GESC_IDYNSEG    -3  /* INQUIRE DYNAMIC SEGMENT STATE    */
#define GESC_SDYNSEG    -4  /* SET DYNAMIC SEGMENT STATE        */

#endif
