/* DEC/CMS REPLACEMENT HISTORY, Element TBH_CLR_BUF.C*/
/* *3    17-AUG-1990 22:24:11 VINCE "(SPR 5644) Code Cleanup"*/
/* *2    13-NOV-1989 11:47:57 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:21 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_CLR_BUF.C*/
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
    This program clears the internal buffers so that the next
    coordinate fetch is directly from the device. (New data).

Prototype:
    publicdef INT tbh_clear_buffer();

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
publicdef INT tbh_clear_buffer ()
#else
publicdef INT tbh_clear_buffer ()
#endif
    {
#ifdef vms
    static TB_CMD_STRUCT tb_cmd_struct;
    
    USHORT plen, rlen;              /* Lengths of param & result buf */
    INT j, k, cnt = 0;              /* counters & indexes       */
    BYTE *pbyte;
    USHORT srclen = 0, dstlen;
    CHAR fillchar = '\0', *pcmd;
    static long tb_init_flag = FALSE;
    INT status;
    CHAR result[256];
    INT reslen;
    
    fillchar = '\0';
    srclen = 0;
    dstlen = sizeof(TB_CMD_STRUCT);
    lib$movc5 (&srclen, 0, &fillchar, &dstlen, &tb_cmd_struct);
    
    /* Check overall  len */
    srclen = (sizeof tb_cmd_struct.buf.charbuf) + (sizeof tb_cmd_struct.buf.intbuf);
    
    tb_cmd_struct.command = Clear_buffer;
    
    pcmd = (CHAR *) & tb_cmd_struct.c_length;
    
    /* send this command to be processed */
    tbh_send_command (pcmd, srclen, result, &reslen, &status);
    
    return status;
#endif
    }
/* END:     */
