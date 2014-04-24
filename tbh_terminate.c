/* DEC/CMS REPLACEMENT HISTORY, Element TBH_TERMINATE.C*/
/* *4    17-AUG-1990 22:25:17 VINCE "(SPR 5644) Code Cleanup"*/
/* *3    14-NOV-1989 03:51:52 JULIAN "(SPR 1) Added kill message type."*/
/* *2    13-NOV-1989 11:56:05 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:50 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_TERMINATE.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_SET_LAMP.C*/
/* *2    13-NOV-1989 11:54:59 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:43 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_SET_LAMP.C*/
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
    This program turns kills the tablet driver by sending it an END packet.

Prototype:
    publicdef INT tbh_terminate();

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    None.
    
Return Value/Status:
    Function returns status from tbh_msabort.
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_terminate ()
#else
publicdef INT tbh_terminate ()
#endif
    {
#ifdef vms
    static TB_CMD_STRUCT tb_cmd_struct;
    
    USHORT srclen, dstlen;
    CHAR result[256], fillchar, *pcmd;
    INT status = SUCCESS, reslen;
    
    fillchar = '\0';
    srclen = 0;
    dstlen = sizeof(TB_CMD_STRUCT);
    lib$movc5 (&srclen, 0, &fillchar, &dstlen, &tb_cmd_struct);
    
    /* Check overall  len */
    srclen = (sizeof tb_cmd_struct.buf.charbuf) + (sizeof tb_cmd_struct.buf.intbuf);
    
    tb_cmd_struct.command = Term_driver;
    tb_cmd_struct.buf.intbuf[0] = 0;
    
    pcmd = (CHAR *) & tb_cmd_struct.c_length;
    
    /* send this command to be processed */
    tbh_send_command (pcmd, srclen, result, &reslen, &status);
    
    return tbh_msabort ();
#endif
    }
/* END:     */
