/* DEC/CMS REPLACEMENT HISTORY, Element TBH_CR_PRC.C*/
/* *4     7-AUG-1991 16:37:52 KEE "(SPR -1) Fix priority 0 bug, now explicitly set the priority to be the base priority (case*/
/*2991)"*/
/* *3    17-AUG-1990 22:24:16 VINCE "(SPR 5644) Code Cleanup"*/
/* *2    13-NOV-1989 11:48:36 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:23 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_CR_PRC.C*/
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
#include "ssdef.h"
#include "prcdef.h"
#include "jpidef.h"

#endif

/* Function Description -----------------------------------------------------
Description:
    This program creates the driver sub process.  If a driver
    process already exists for the current user, kill it and
    create a new one.

Prototype:
    publicdef INT tbh_create_prc(CHAR *image);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    image           -(CHAR *)

Return Value/Status:
    SUCCESS - Successful completion.
    FAIL    - Unsuccessful completion.

Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_create_prc (CHAR *image)
#else
publicdef INT tbh_create_prc (image)
CHAR *image;
#endif
    {
#ifdef vms
    extern TB_PROC_INFO tbgbl;
    static CHAR pid_name[16];
    static CHAR master_term[16];
    CHAR process[64];
    CHAR resultbuf[128];
    INT status;
    INT len, reslen;
    SHORT iosb[4];
    
    static DSC imgdsc = 
        {
        (size_t)0, DSC$K_DTYPE_T, DSC$K_CLASS_S, (CHAR *)0
        };
    static DSC mtermdsc = 
        {
        sizeof(tbgbl.master_term) - 1, DSC$K_DTYPE_T, DSC$K_CLASS_S, tbgbl.master_term
        };
    static DSC pidnamdsc = 
        {
        sizeof(pid_name) - 1, DSC$K_DTYPE_T, DSC$K_CLASS_S, pid_name
        };
    
    FLOAT seconds;                  /* delay time in seconds for LIB$WAIT */
    
    static struct 
        {
        short buflen;
        short itmcod;
        char *bufadr;
        int *retadr;
        } itemlist[5];
    
    if (image == (CHAR *)0)
        {
        return FAIL;
        }
    imgdsc.dsc$w_length = (SHORT)strlen (image);
    imgdsc.dsc$a_pointer = image;
    /* 
        create a process name string from the master proc's io channel 
    */
    sprintf (pid_name, "TBLT%s", tbgbl.master_term);
    pidnamdsc.dsc$w_length = (SHORT)strlen (pid_name);
    pidnamdsc.dsc$a_pointer = pid_name;
    tbgbl.master_prio = JPI$_PRIB; /* explicitly set the process priority
				      to be the base process priority -
				      Fixed by Hung Hoang of BHP Australia */
    
    /*
        Attempt to create the process.
    */
    status = sys$creprc (&tbgbl.sp.pid,/* PID              */
            &imgdsc,                /* Image to execute */
            &mtermdsc,              /* SYS$INPUT        */
            &mtermdsc,              /* SYS$OUTPUT       */
            &mtermdsc,              /* SYS$ERROR        */
            tbgbl.master_priv,      /* privilege mask   */
            0,                      /* Quota            */
            &pidnamdsc,             /* process name     */
            tbgbl.master_prio,      /* Base priority    */
            0,                      /* UIC              */
            0,                      /* Termination Mailbox  */
            0);                     /* Create Options mask  */
    
    /* 
        If a driver process already exists for the current user. We 
        must kill that process first before using the same name to  
        create another process.                 
    */
    if (status == SS$_DUPLNAM)
        {
        /* Shoot the old driver process.    */
        status = sys$delprc (0, &pidnamdsc);
        
        /* wait for the process to die...   */
        status = SS$_NORMAL;
        itemlist[3].buflen = (SHORT)15;
        itemlist[3].itmcod = JPI$_PID;
        itemlist[3].bufadr = process;
        itemlist[3].retadr = &len;
        itemlist[4].itmcod = 0;
        
        seconds = 0.50;
        do
            {
            lib$wait (&seconds);    /* pause for image exit */
            
            status = sys$getjpiw (0, 0, &pidnamdsc, itemlist, &iosb[0], 0, 0);
            } while (status != SS$_NONEXPR);
        
        /* 
        Now try again to create it.  If this fails, we fail...
        */
        status = sys$creprc (&tbgbl.sp.pid, /* PID              */
                &imgdsc,            /* Image to execute */
                &mtermdsc,          /* SYS$INPUT        */
                &mtermdsc,          /* SYS$OUTPUT       */
                &mtermdsc,          /* SYS$ERROR        */
                tbgbl.master_priv,  /* privilege mask   */
                0,                  /* Quota            */
                &pidnamdsc,         /* process name     */
                tbgbl.master_prio,  /* Base priority    */
                0,                  /* UIC              */
                0,                  /* Termination Mailbox  */
                0);                 /* Create Options mask  */
        
        }
    if (status != SS$_NORMAL)
        lib$stop (status);
    
    /* 
        The first thing that the new process will do is send an ACK 
        to the creator (us) so wait here for it to arrive. 
    */
    tbh_get_ack (resultbuf, &reslen, &status);
    
    
    return status;
#endif
    }
/* END:     */
