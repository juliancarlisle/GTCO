/* DEC/CMS REPLACEMENT HISTORY, Element TBH_INIT.C*/
/* *3    17-AUG-1990 22:24:30 VINCE "(SPR 5644) Code Cleanup"*/
/* *2    13-NOV-1989 11:49:58 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:29 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_INIT.C*/
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
#include "ssdef.h"

/*
    This is the spot where these global datastructures are decalred.
    They are referenced in other tb*.c source files.
*/
TB_PROC_INFO tbgbl = 
    {
    0
    };


TB_GLOBUF tb_buffer = 
    {
    0
    };


#endif

/* Function Description -----------------------------------------------------
Description:
    Init the tablet and it's I/O channel.  The given device will be
    allocated and opened, the modes indicated by the bitmap in ModeMask
    will be set in the tablet if available.  

Prototype:
    publicdef INT tbh_initialize(INT tablet_type, CHAR *device_name, unsigned ModeMask,
        CHAR *image);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    tablet_type     -(INT) A token that identifies specific hardware.
    device_name     -(CHAR *) The VMS device name of the tablet port.
    ModeMask        -(UINT) The startup configuration flags.
    image           -(CHAR *) 

Return Value/Status:
    SUCCESS - Successful completion.
    TB_IO_ERROR
    TB_INVALID_CHANNEL
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_initialize (INT tablet_type, CHAR *device_name, unsigned ModeMask,
                              CHAR *image)
#else
publicdef INT tbh_initialize (tablet_type, device_name, ModeMask, image)
INT tablet_type;
CHAR *device_name;
unsigned ModeMask;
CHAR *image;
#endif
    {
#ifdef vms
    USHORT plen, rlen;              /* Lengths of param & result buf */
    INT j, k, cnt = 0,              /* counters & indexes       */
    istate = 0, status = 0;
    BYTE *pbyte;
    
    USHORT srclen = 0, dstlen;
    CHAR fillchar = '\0';
    CHAR *pcmd;
    CHAR result[256];
    INT reslen;
    static TB_CMD_STRUCT tb_gb_cmd_struct;
    /* 
        reset:
        TB_GLOBUF, TB_GB_INFO, TB_CMD_STRUCT
        
        Reset the global datastructures here since this 
        should be a first call into the tablet system for this
        application.
    */
    tbgbl.tablet_init = FALSE;
    fillchar = '\0';
    srclen = 0;
    
    dstlen = sizeof(TB_GLOBUF);
    lib$movc5 (&srclen, 0, &fillchar, &dstlen, &tb_buffer);
    
    dstlen = sizeof(TB_GB_INFO);
    lib$movc5 (&srclen, 0, &fillchar, &dstlen, &tbgbl);
    
    dstlen = sizeof(TB_CMD_STRUCT);
    lib$movc5 (&srclen, 0, &fillchar, &dstlen, &tb_gb_cmd_struct);
    
    /* 
        Start the communications context for the master & create sub-process. 
    */
    status = tbh_msinit (image);
    
    /* 
        If all went well then send the init command to the sub-process.
    */
    if (!status)
        {
        
        /* Check overall  len */
        srclen = (sizeof tb_gb_cmd_struct.buf.charbuf) +
                 (sizeof tb_gb_cmd_struct.buf.intbuf);
        
        tb_gb_cmd_struct.c_length = srclen;
        tb_gb_cmd_struct.command = Init_driver;
        tb_gb_cmd_struct.buf.intbuf[0] = (INT)tablet_type;
        tb_gb_cmd_struct.buf.intbuf[1] = (unsigned)ModeMask;
        
        strcpy (tb_gb_cmd_struct.buf.charbuf, device_name);
        tbgbl.tablet_type = (INT)tablet_type;
        
        pcmd = (CHAR *) & tb_gb_cmd_struct.c_length;
        
        /* send this command to be processed */
        tbh_send_command (pcmd, srclen, result, &reslen, &status);
        
        switch ((INT)(result[4]))
            {
        case SS$_NOPRIV:
        case SS$_NOSUCHDEV:
            status = TB_INVALID_CHANNEL;
            break;
            
        case SS$_DEVNOTALLOC:
        case SS$_DEVALRALLOC:
            status = TB_IO_ERROR;
            break;
            
        default:
            status = SUCCESS;
            tbgbl.tablet_init = TRUE;
            }
        }
    return status;
#endif
    }
/* END:     */
