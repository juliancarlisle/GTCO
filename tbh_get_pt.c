/* DEC/CMS REPLACEMENT HISTORY, Element TBH_GET_PT.C*/
/* *3    17-AUG-1990 22:24:24 VINCE "(SPR 5644) Code Cleanup"*/
/* *2    13-NOV-1989 11:49:16 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:26 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_GET_PT.C*/
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
    This is the interface that application programs call to get
    tablet coords.  

    The method for getting points to the application program depends
    on the number of points being fetched.  

    If just a single point requested the following occurs:

        a) A type 'G' command packet is sent to the drivers mailbox.
            Since the mailbox has a write attention characteristic set
            an AST is activated by the mailbox write.

        b) The AST awakes the sub-process if it is hibernating.

        c) The AST calls the driver fetch a point.  If the point
            is fetched then it is returned to the application via
            a mailbox by appending it to the end of a standard ACK
            message.  This is done simply because the driver 
            always sends and ACK back after it gets a request, whether
            it is for 1 point or 10000, so it seems to be more efficient.

    If a stream of n (n>1) points is requested the following occurs:

        a) A type 'G' command packet is sent to the drivers mailbox.
            Since the mailbox has a write attention characteristic set
            an AST is activated by the mailbox write.

        b) The AST awakes the sub-process if it is hibernating.

        c) The AST tells the driver to begin fetching points and only
            to return when either the requested # have been fetched
        or:
            1) The user has pressed a puck key defined as a DONE key.
            2) An I/O error causes the point stream to stop early.
            3) The number of points fetched becomes greater than the
                amount of space available in the user-supplied buffer. 
            4) The global points buffer becomes full.
            5) - - - ?

        d) The driver fetches points until either it is finished or 
            one of the above conditions caused it to terminate early and
            returns these points to the user.

Prototype:
    publicdef INT tbh_get_points(INT npoints, INT *x, INT *y, INT *b, INT *retcnt);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    (I) npoints     -(INT) The number of points to fetch.
    (O) retcnt      -(INT *) The actual returned count.
    (O) x           -(INT *) -|
    (O) y           -(INT *) -\
    (O) b           -(INT *) Ptrs to the destination buffers for XYB.

Return Value/Status:
    SUCCESS - Successful completion.
    FAIL    - Unsuccessful completion.
    TB_NO_POINTS
    
Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_get_points (INT npoints, INT *x, INT *y, INT *b, INT *retcnt)
#else
publicdef INT tbh_get_points (npoints, x, y, b, retcnt)
INT npoints;
INT *x, *y, *b;
INT *retcnt;
#endif
    {
#ifdef vms
    extern TB_PROC_INFO tbgbl;
    extern TB_GLOBUF tb_buffer;
    INT status, istat, *pint, nbytes;
    static TB_CMD_STRUCT msg;
    SHORT srclen, dstlen;
    CHAR fill = 0;
    static INT result[256];
    static INT reslen;
    
    srclen = 0;
    dstlen = sizeof(TB_CMD_STRUCT) - 1;
    lib$movc5 (&srclen, 0, &fill, &dstlen, &msg);
    
    fill = '\0';
    dstlen = (sizeof result) - 1;
    lib$movc5 (&srclen, 0, &fill, &dstlen, result);
    
    /* build command packet header */
    msg.command = Get_points;
    msg.c_length = sizeof msg.buf.charbuf;
    
    /* Pass the number of points requested */
    pint = (INT *) & msg.buf.charbuf[0];
    *pint = (INT)npoints;
    
    status = tbh_send_command ((CHAR *) & msg.c_length, msg.c_length, (CHAR *)result,
                               &reslen, &istat);
    *retcnt = 0;
    pint = &result[0];
    
    if ((!status) AND reslen >= (sizeof(INT) * 4))
        {
        nbytes = *pint++;
        status = *pint++;
        if ((status == TB_NO_ERRORS) || (status == TB_MORE_DATA) ||
            (status == TB_BUF_OVERFLOW))
            {
            *x = *pint++;
            *y = *pint++;
            *b = *pint++;
            *retcnt = *pint;
            if (*retcnt > 1)
                {
                srclen = (*retcnt) * (sizeof(INT));
                lib$movc3 (&srclen, &tb_buffer.x_long[tb_buffer.xybcur], x);
                lib$movc3 (&srclen, &tb_buffer.y_long[tb_buffer.xybcur], y);
                lib$movc3 (&srclen, &tb_buffer.b_byte[tb_buffer.xybcur], b);
                }
            }
        }
    return status;
#endif
    }
/* END:     */
