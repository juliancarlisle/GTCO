/* DEC/CMS REPLACEMENT HISTORY, Element TBH_MSINIT.C*/
/* *4    17-AUG-1990 22:24:46 VINCE "(SPR 5644) Code Cleanup"*/
/* *3    14-NOV-1989 02:00:07 JULIAN "(SPR 1) Get rid of lib$stops."*/
/* *2    13-NOV-1989 11:53:10 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:37 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_MSINIT.C*/
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
#include "jpidef.h"
#include "dvidef.h"
#include "lnmdef.h"
#include "secdef.h"     /* CRMPSC needs this */
#include "ctype.h"
#include "rms.h"        /* FAB description */

#endif

/* Function Description -----------------------------------------------------
Description:
    Init the communications mailboxes etc. for the main process.
        * Map in  global section
        * Create mailboxes for talking to sub-process
        * Create the sub-process

Prototype:
    publicdef INT tbh_msinit(CHAR *image);

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
publicdef INT tbh_msinit (CHAR *image)
#else
publicdef INT tbh_msinit (image)
CHAR *image;
#endif
    {
#ifdef vms
    extern TB_PROC_INFO tbgbl;
    extern TB_GLOBUF tb_buffer;
    static CHAR mbname[32],     /* MBX name string      */
        lnmtbl[] = 
        {
        "LNM$JOB"
        },                          /* logical name class   */
    tbgsname[] = 
        {
        "tablet_com"
        };                          /* Name of gbl section  */
    
    static DSC logname = 
        {
        13,
        DSC$K_DTYPE_T,
        DSC$K_CLASS_S,
        mbname
        };
    static DSC tabname = 
        {
        7,
        DSC$K_DTYPE_T,
        DSC$K_CLASS_S,
        lnmtbl
        };
    static DSC gsdname = 
        {
        10,
        DSC$K_DTYPE_T,
        DSC$K_CLASS_S,
        tbgsname
        };
    
    CHAR buffer[96],                /* Gen purpose      */
        string[128];                /* Gen purpose      */
    
    INT passadr[2], retadr[2], sec_mask = 0, status = SUCCESS, buflen = 0, n;
    size_t l_len = 0;               /* long length (4 bytes) */
    
    /* 
        Item list struct for GETDVI & GETJPI calls. 
    */
    static struct 
        {
        SHORT buflen;
        SHORT itmcod;
        VOIDPTR bufadr;
        VOIDPTR retadr;
        } itemlist[5];
    
    struct FAB fab;
    static TB_IOSB iosb;
    
    iosb.status = SS$_NORMAL;
    iosb.count = 0;
    /*
        Inquire some characteristics of the current process (MASTER).
    */
    itemlist[0].buflen = (SHORT)4;
    itemlist[0].itmcod = JPI$_PID;
    itemlist[0].bufadr = &tbgbl.master.pid;
    itemlist[0].retadr = &l_len;
    
    itemlist[1].buflen = (SHORT)4;
    itemlist[1].itmcod = JPI$_PRIB;
    itemlist[1].bufadr = &tbgbl.master_prio;
    itemlist[1].retadr = &l_len;
    
    itemlist[2].buflen = (SHORT)sizeof tbgbl.master_priv;
    itemlist[2].itmcod = JPI$_PROCPRIV;
    itemlist[2].bufadr = tbgbl.master_priv;
    itemlist[2].retadr = &l_len;
    
    itemlist[3].buflen = (SHORT)sizeof tbgbl.master_term;
    itemlist[3].itmcod = JPI$_TERMINAL;
    itemlist[3].bufadr = &tbgbl.master_term[1];
    itemlist[3].retadr = &l_len;
    
    itemlist[4].buflen = 0;
    itemlist[4].itmcod = 0;
    itemlist[4].bufadr = 0;
    itemlist[4].retadr = 0;
    
    status = sys$getjpiw (0, 0, 0, itemlist, &iosb, 0, 0);
    if ((status & 1) != SS$_NORMAL)
        return FAIL;
    if (iosb.status != SS$_NORMAL)
        return FAIL;
    
    /*
        Build the master terminal name string by prefixing '_'
        to create a raw device name from a logical reference.
    */
    tbgbl.master_term[0] = '_';
    tbgbl.master_term[1 + l_len] = '\0';
    
    
    /*
        Assign the output channel for the master.    
    */
    strcpy (buffer, "SYS$OUTPUT");
    logname.dsc$a_pointer = buffer;
    logname.dsc$w_length = (SHORT)strlen (buffer);
    
    status = sys$assign (&logname, &tbgbl.master.io_channel, 0, 0);
    if ((status & 1) != SS$_NORMAL)
        return FAIL;
    
    
    /* 
         create a mail box used by the process to communicate
         with the subprocess
    */
    status = sys$crembx (0, &tbgbl.chan_to_master, TB_MBXLEN, TB_MBXQUO, 65280, 0, 0);
    
    if ((status & 1) != SS$_NORMAL)
        return FAIL;
    
    /*
        Get the name of the Master mailbox device.
    */
    itemlist[0].buflen = (SHORT)64;
    itemlist[0].itmcod = DVI$_DEVNAM;
    itemlist[0].bufadr = buffer;
    itemlist[0].retadr = &l_len;
    
    itemlist[1].buflen = 0;
    itemlist[1].itmcod = 0;
    itemlist[1].bufadr = 0;
    itemlist[1].retadr = 0;
    
    iosb.status = SS$_NORMAL;
    iosb.count = 0;
    status = sys$getdviw (0, tbgbl.chan_to_master, 0, itemlist, &iosb, 0, 0, 0);
    
    if ((status & 1) != SS$_NORMAL)
        return FAIL;
    if (iosb.status != SS$_NORMAL)
        {
        status = iosb.status;
        return FAIL;
        }
    /*
        Copy the master mailbox device name to the global info struct.
    */
    strncpy (tbgbl.master.mailbox, buffer, l_len);
    tbgbl.master.mb_len = (SHORT)l_len;
    
    /*
       create the name of the master mail box
       using the master pid, and set a descriptor for it.
    */
    sprintf (string, "%8X", tbgbl.master.pid);
    
    for (n = 0; isspace (string[n]); n++)
        string[n] = '0';
    
    sprintf (mbname, "MLTB_%8.8s", string);
    logname.dsc$a_pointer = mbname;
    logname.dsc$w_length = (SHORT)strlen (mbname);
    
    
    /*
        Create a logical name that holds the master mailbox channel by
        concatonating the Master process PID together with 'MLTB_'.
        
        This allows a sub-process to get access to it because a 
        sub-process can always find out the PID of it's creator.
    */
    itemlist[0].buflen = (SHORT)l_len;
    itemlist[0].itmcod = LNM$_STRING;
    itemlist[0].bufadr = buffer;    /* preserved from GETDVI call earlier */
    itemlist[0].retadr = &l_len;    /* preserved from GETDVI call earlier */
    itemlist[1].buflen = 0;
    itemlist[1].itmcod = 0;
    itemlist[1].bufadr = 0;
    itemlist[1].retadr = 0;
    
    status = sys$crelnm (0, &tabname, &logname, 0, itemlist);
    
    if ((status & 1) != SS$_NORMAL)
        return FAIL;
    
    
    /* 
        Create a global section file using an FAB description block.
        
        This will create a global section FAB file that
        can be mapped into another process' address space
        in such a way that both processes will appear to share
        the memory that the file is mapped into.
    */
    
    fab = cc$rms_fab;
    fab.fab$b_rtv = -1;
    fab.fab$b_shr = FAB$M_UPI | FAB$M_SHRGET | FAB$M_SHRPUT;
    fab.fab$b_rfm = FAB$C_FIX;
    fab.fab$w_mrs = 512;
    fab.fab$b_org = FAB$C_SEQ;
    fab.fab$b_rat = 0;
    
    fab.fab$l_fna = gsdname.dsc$a_pointer;
    fab.fab$b_fns = strlen (gsdname.dsc$a_pointer);
    fab.fab$l_alq = sizeof(TB_GLOBUF) / 512;
    fab.fab$b_fac = FAB$M_PUT | FAB$M_GET | FAB$M_BRO;
    fab.fab$l_fop = (FAB$M_CBT | FAB$M_UFO | FAB$M_TMD);
    
    status = sys$create (&fab);
    if ((status & 1) != SS$_NORMAL)
        return FAIL;
    
    /*
        Now associate the global section file with 
        a the part of our address space containing the buffer.
    */
    passadr[0] = (INT) & tb_buffer;
    passadr[1] = (INT) & tb_buffer.flag + 4;
    sec_mask = SEC$M_WRT | SEC$M_DZRO | SEC$M_GBL;
    
    status = sys$crmpsc (passadr, retadr, 0, sec_mask, &gsdname, 0, 0, fab.fab$l_stv,
                         0, 0, 0, 0);
    if ((status & 1) != SS$_NORMAL)
        return FAIL;
    
    /*
        Get an event flag for general usage.
    */
    if (((status = lib$get_ef (&tbgbl.master.efn)) & 1) != SS$_NORMAL)
        return FAIL;
    
    /*
        O.K. - The master process is completely described & initialized so
        we can create the sub-process that will link us to the tablet via
        a set of mailbox channels.
    */
    status = tbh_create_prc (image);
    
    return status;
#endif
    }
/* END:     */
