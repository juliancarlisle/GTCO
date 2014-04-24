/* DEC/CMS REPLACEMENT HISTORY, Element TBH_REQ_LOC.C*/
/* *3    17-AUG-1990 22:24:55 VINCE "(SPR 5644) Code Cleanup"*/
/* *2    13-NOV-1989 11:53:46 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:40 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_REQ_LOC.C*/
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

#include  "esi_gl_defs.h"

#ifdef vms

#include  "esi_tb_defs.h"
#include  "esi_tg_mat.h"
#include  "esi_wm.h"

#endif

/* Function Description -----------------------------------------------------
Description:
    This routine is designed to request a raw data point from tablet,
    it is similar with TBH_GET_POINTS, but it will wait until the user does
    digitize a point from digitizer.

Prototype:
    publicdef INT tbh_request_locator(INT *x,INT *y,INT *b);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    (O) x           -(INT *) The returned x location.
    (O) y           -(INT *) The returned y location.
    (O) b           -(INT *) The button pressed by the user.

Return Value/Status:
    SUCCESS - Successful completion.
    TB_NOT_INIT
    CANCEL
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_request_locator (INT *x, INT *y, INT *b)
#else
publicdef INT tbh_request_locator (x, y, b)
INT *x, *y, *b;
#endif
    {
#ifdef vms
    INT status = SUCCESS, cnt = 0, tx,/* rAW TABLET X COORD       */
    ty,                             /* and y                */
    tb;                             /* button for this coord pair.  */
    
    /* 
        Poll for XY input from tablet.  Wait for a coord unless
        severe problems arise, i.e. driver not initialized.
    */
    tbh_clear_buffer ();
    tb = 0;
    while (cnt == 0)
        {
        status = tbh_get_points (1, &tx, &ty, &tb, &cnt);
        
        if (status == TB_NOT_INIT)
            break;
        }
    if (cnt >= 1)
        {
        *x = tx;
        *y = ty;
        *b = tb;
        }
    else
        {
        *x = 0;
        *y = 0;
        *b = 0;
        }
    if (tb == WM_BUTTON_CANCEL)
        status = CANCEL;
    
    return status;
#endif
    }
/* END:     */
