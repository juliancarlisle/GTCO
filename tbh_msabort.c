/* DEC/CMS REPLACEMENT HISTORY, Element TBH_MSABORT.C*/
/* *3    17-AUG-1990 22:24:41 VINCE "(SPR 5644) Code Cleanup"*/
/* *2    13-NOV-1989 11:52:18 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:34 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_MSABORT.C*/
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

#endif

/* Function Description -----------------------------------------------------
Description:
    Kills the sub-process and deassigns the mailbox channel to it.

Prototype:
    publicdef INT tbh_msabort();

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    None.
    
Return Value/Status:
    SUCCESS - Successful completion.
    FAIL    - Unsuccessful completion.

Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_msabort ()
#else
publicdef INT tbh_msabort ()
#endif
    {
#ifdef vms
    extern TB_PROC_INFO tbgbl;
    static CHAR buffer[80], string[64];
    
    INT status, buflen, length, n;
    
    static struct 
        {
        short buflen;
        short itmcod;
        char *bufadr;
        int *retadr;
        } itemlist[5];
    
    /*************************************************************************/
    
    /* Disable further AST's */
    sys$setast (0);
    
    /*
        Deassign the sub-process mailbox channel.
    */
    status = sys$dassgn (tbgbl.chan_to_sub);
    if (!status)
        lib$stop (status);
    
    /* Status of MSABORT is the status of DELPRC */
    
    /*
        Kill the sub-process.
    */
    status = sys$delprc (&tbgbl.sp.pid, 0);
    if (!status)
        lib$stop (status);
    
    /* Reenable the AST deliveries. */
    sys$setast (1);
    
    return status;
#endif
    }
/* END:     */
