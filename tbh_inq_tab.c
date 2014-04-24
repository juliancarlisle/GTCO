/* DEC/CMS REPLACEMENT HISTORY, Element TBH_INQ_TAB.C*/
/* *4    17-AUG-1990 22:24:36 VINCE "(SPR 5644) Code Cleanup"*/
/* *3    13-NOV-1989 11:50:49 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *2    12-AUG-1989 10:32:06 GILLESPIE "(SPR 1) Comment out TB_GTCO_LARGE section"*/
/* *1    19-JUN-1989 13:31:31 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_INQ_TAB.C*/
/*****************************************************************************/
/******************************************************************************

                Copyright Exploration Systems, Inc. 1989
                    Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

                            Exploration Systems
                            c/o Finder Graphics Systems
                            201 Tamal Vista Blvd.
                            Corte Madera, CA  94925
                            (415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#include "esi_gl_defs.h"

#ifdef vms

#include "esi_tb_defs.h"
#include "esi_tg_mat.h"

#endif

/* Function Description -----------------------------------------------------
Description:
    Inquiry function to get various statisitics about the current
    tablet (such as its min/max extents) or the current driver
    state (such as whether or not it has been initialized).

Prototype:
    publicdef INT tbh_inq_tablet(INT code,BYTE *result);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    (I) code        -(INT) Type of inquiry.
    (O) result      -(BYTE *) Data (type varies dep. on inq. type).

Return Value/Status:
    SUCCESS - Successful completion.
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_inq_tablet (INT code, BYTE *result)
#else
publicdef INT tbh_inq_tablet (code, result)
INT code;
BYTE *result;
#endif
    {
#ifdef vms
    extern TB_PROC_INFO tbgbl;
    
    INT status = SUCCESS;
    INT *pint;
    EXTENTS *pext;
    
    
    switch (code)
        {
    case TB_INQ_INIT:
        pint = (INT *)result;
        if (tbgbl.tablet_init == TRUE)
            *pint = TRUE;
        else
            *pint = FALSE;
        break;
        
    case TB_INQ_EXTENTS:
        pext = (EXTENTS *)result;
        switch (tbgbl.tablet_type)
            {
        case TB_GTCO_36X48_UGRID:
            pext->ul_x = 0.0;
            pext->ul_y = 35999.0;
            pext->ur_x = 47999.0;
            pext->ur_y = 35999.0;
            pext->ll_x = 0.0;
            pext->ll_y = 0.0;
            pext->lr_x = 47999.0;
            pext->lr_y = 0.0;
            break;
            
        case TB_GTCO_11X11:
            pext->ul_x = 0.0;
            pext->ul_y = 10999.0;
            pext->ur_x = 10999.0;
            pext->ur_y = 10999.0;
            pext->ll_x = 0.0;
            pext->ll_y = 0.0;
            pext->lr_x = 10999.0;
            pext->lr_y = 0.0;
            break;
            
        case TB_CALCOMP9100:
            pext->ul_x = 0.0;
            pext->ul_y = 35999.0;
            pext->ur_x = 47999.0;
            pext->ur_y = 35999.0;
            pext->ll_x = 0.0;
            pext->ll_y = 0.0;
            pext->lr_x = 47999.0;
            pext->lr_y = 0.0;
            break;
            
        default:
            break;
            }
        break;
        
    default:
        break;
        }
    return SUCCESS;
#endif
    }
/* END:     */
