/* DEC/CMS REPLACEMENT HISTORY, Element TBH_SET_LAMP.C*/
/* *3    17-AUG-1990 22:25:05 VINCE "(SPR 5644) Code Cleanup"*/
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
    This program turns the LED on the tablet puck On and OFF.

Prototype:
    publicdef INT tbh_set_lamp(INT onoff);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    (I) onoff       -(INT) Set to either ON or OFF.

Return Value/Status:
    SUCCESS - Successful completion.
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_set_lamp (INT onoff)
#else
publicdef INT tbh_set_lamp (onoff)
INT onoff;
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
    
    tb_cmd_struct.command = Lamp_ctrl;
    tb_cmd_struct.buf.intbuf[0] = (unsigned)onoff;
    
    pcmd = (CHAR *) & tb_cmd_struct.c_length;
    
    /* send this command to be processed */
    tbh_send_command (pcmd, srclen, result, &reslen, &status);
    
    return status;
#endif
    }
/* END:     */
