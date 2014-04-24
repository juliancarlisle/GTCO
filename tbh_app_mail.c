/* DEC/CMS REPLACEMENT HISTORY, Element TBH_APP_MAIL.C*/
/* *4    17-AUG-1990 22:23:54 VINCE "(SPR 5644) Code Cleanup"*/
/* *3    14-NOV-1989 01:59:59 JULIAN "(SPR 1) Get rid of lib$stops."*/
/* *2    13-NOV-1989 11:47:22 JULIAN "(SPR 1) Added calcomp driver mode."*/
/* *1    19-JUN-1989 13:31:17 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_APP_MAIL.C*/
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
#include "esi_glue.h"
#include "ssdef.h"
#include "iodef.h"

#endif

/* File Description ---------------------------------------------------------
Overview:

Prototypes and one line descriptions of each function in the file.
Public_Functions:
    publicdef INT tbh_send_command(CHAR *command,INT cmdlen,CHAR *result,INT *reslen, 
        INT *state);
    
    publicdef INT tbh_send_mess(SHORT channel, TB_CMD_STRUCT *pmsg, INT *state);
    
    publicdef INT tbh_get_ack(CHAR *result,INT *reslen, INT *state);
    
    publicdef INT tbh_send_to_screen(CHAR *string);
    
    publicdef INT tbh_cleanstr(CHAR *string);

Private_Functions:

-----------------------------------------------------------------------------*/

/* Function Description -----------------------------------------------------
Description:
    Sends a command packet to the sub-process mailbox via send_mess.

Prototype:
    publicdef INT tbh_send_command(CHAR *command,INT cmdlen,CHAR *result,INT *reslen, 
        INT *state);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    command         -(CHAR *)
    cmdlen          -(INT)
    result          -(CHAR *)
    reslen          -(INT *)
    state           -(INT *)

Return Value/Status:
    SUCCESS - Successful completion.
    FAIL    - Unsuccessful completion.

Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_send_command (CHAR *command, INT cmdlen, CHAR *result, INT *reslen,
                                INT *state)
#else
publicdef INT tbh_send_command (command, cmdlen, result, reslen, state)
CHAR *command;
INT cmdlen;
CHAR *result;
INT *reslen;
INT *state;
#endif
    {
#ifdef vms
    extern TB_PROC_INFO tbgbl;
    TB_IOSB iosb;
    INT status;
    INT msglen;
    CHAR fill;
    SHORT srclen, dstlen;
    static CHAR message[128], *pbuf;
    static DSC mdsc = 
        {
        sizeof message,
        DSC$K_DTYPE_T,
        DSC$K_CLASS_S,
        message
        };
    static TB_CMD_STRUCT msg;
    CHAR *pcmd;
    
    
    /* reset our template message struct by padding out w/spaces */
    srclen = 0;
    fill = 0;
    dstlen = sizeof(TB_CMD_STRUCT) - 1;
    lib$movc5 (&srclen, 0, &fill, &dstlen, &msg);
    
    /* fill in the header for a message */
    msg.type_mess = TB_MSGTYPE_CTRL;
    msg.control = TB_CTRLTYPE_CMD;
    
    strcpy (msg.from_task, "DRIVER");
    
    /* set a pointer to the region we care about: */
    /* the message section under the param member */
    pcmd = (CHAR *) & msg.c_length;
    
    /* and move the body of the message into place. */
    srclen = (SHORT)cmdlen;
    lib$movc3 (&srclen, command, pcmd);
    msg.c_length = (SHORT)cmdlen;
    
    status = tbh_send_mess (tbgbl.chan_to_sub, &msg, state);
    tbh_get_ack (result, reslen, state);
    
    return status;
    }
/* END:     */

/* Function Description -----------------------------------------------------
Description:
    This procedure sends a message to an another process.
    It sends the message via a mail box which channel is passed as
    argument.

Prototype:
    publicdef INT tbh_send_mess(SHORT channel, TB_CMD_STRUCT *pmsg, INT *state);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    channel         -(SHORT)
    pmsg            -(TB_CMD_STRUCT *)
    state           -(INT *)

Return Value/Status:
    SUCCESS - Successful completion.
    FAIL    - Unsuccessful completion.

Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_send_mess (SHORT channel, TB_CMD_STRUCT *pmsg, INT *state)
#else
publicdef INT tbh_send_mess (channel, pmsg, state)
SHORT channel;
TB_CMD_STRUCT *pmsg;
INT *state;
#endif
    {
    extern TB_PROC_INFO tbgbl;
    TB_IOSB iosb;
    INT status;
    INT msglen;
    
    msglen = sizeof(TB_CMD_STRUCT) - 1;
    
    iosb.status = SS$_NORMAL;
    iosb.count = (SHORT)0;
    
    *state = SS$_NORMAL;
    if (msglen > TB_MBXLEN)
        {
        status = SS$_MBTOOSML;
        }
    else
        {
        status = sys$qiow (0, channel, IO$_WRITEVBLK | IO$M_NOW, &iosb, 0, 0, pmsg,
                           msglen, 0, 0, 0, 0);
        
        *state = status;
        
        while (iosb.status == SS$_MBFULL)
            {
            status = sys$qiow (0, channel, IO$_WRITEVBLK | IO$M_NOW, &iosb, 0, 0, pmsg,
                               msglen, 0, 0, 0, 0);
            
            *state = status;
            }
        }
    if (status == SS$_NORMAL)
        if (iosb.status != SS$_NORMAL)
            *state = iosb.status;
        
        return(status == SS$_NORMAL) ? SUCCESS : status;
    }
/* END:     */

/* Function Description -----------------------------------------------------
Description:
    Waits on the master mailbox until a message arrives from the 
    sub-process.  There are several different types of messages, 
    each with it's own signifigance, and response.

    MESSAGE -   Text packet meant for user notification.
    CONTROL -   Primary type, includes all Ack sub types.

    Sub-control packets within the control message group:
    COMMAND -   For sending cmds to sub-proc only. not used here.
    ACK -   A response, handshaking, may include result data.

    Sub-control of ACK types:
    CREATION -  First packet sub-proc sends us when we create
                it.  Contains the name of sub-proc's mailbox
                so that we can connect to it.

    RUN -   Command response Ack packet.  Can contain data
            that is the result of performing the command.

Prototype:
    publicdef INT tbh_get_ack(CHAR *result,INT *reslen, INT *state);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    result          -(CHAR *)
    reslen          -(INT *)
    state           -(INT *)

Return Value/Status:
    SUCCESS - Successful completion.
    FAIL    - Unsuccessful completion.

Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_get_ack (CHAR *result, INT *reslen, INT *state)
#else
publicdef INT tbh_get_ack (result, reslen, state)
CHAR *result;
INT *reslen;
INT *state;
#endif
    {
    extern TB_PROC_INFO tbgbl;
    INT status, isend_ack, l_ch, r_length, stat, len;
    
    SHORT srclen, dstlen, channel, iosb[4], timelen;
    
    PID pid;
    
    CHAR string[256], ch_time[9], temp[9], car[3], *pstr;
    
    static TB_CMD_STRUCT msg;
    
    static CHAR timestr[32], mbxstr[32];
    
    static DSC timedsc = 
        {
        10,
        DSC$K_DTYPE_T,
        DSC$K_CLASS_S,
        timestr
        };
    static DSC mbxdsc = 
        {
        10,
        DSC$K_DTYPE_T,
        DSC$K_CLASS_S,
        mbxstr
        };
    static CHAR *errstr = 
        {
        "%MBX_ROUTE-F-ERROR,  Error in mailbox routing from "
        };
    CHAR fill = '\0';
    
    *state = 0;
    /* CLEAR OUT THE MESSAGE STRUCT FOR NEXT USE */
    srclen = 0;
    dstlen = sizeof(TB_CMD_STRUCT) - 1;
    lib$movc5 (&srclen, 0, &fill, &dstlen, &msg);
    
    len = dstlen;
    channel = tbgbl.chan_to_master;
    
    
    /*
    *
    *    Read with wait  for all messages comming in the master
    *    mail box
    */
    
    status = sys$qiow (0,           /* No event flag        */
            channel,                /* mbx chan of SP       */
            IO$_READVBLK,           /* Read ctrl flags      */
            iosb,                   /* IO stat block        */
            0, 0,                   /* No AST parms     */
            &msg,                   /* Input buffer     */
            len,                    /* Max len of input     */
            0, 0, 0, 0);
    
    if (status != SS$_NORMAL)
        return FAIL;
    
    if (iosb[0] != SS$_NORMAL)
        return FAIL;
    
    /*
        Determine message type and correct response.   There are
        two catagories of packets currently: Control & Message.
        Control messages are ACK packets of different types.  An
        ACK may either be signalling the creation and startup
        of the subprocess, or, more usually, handshaking for
        a command request.  ACKs may not only consist of the
        flag for ACK but in some cases they may be a vehicle
        for returning a result of a command. I.e. X,Y,Button info.
    */
    
    switch (msg.type_mess)
        {                           /* There are two types of control messages   */
    case TB_MSGTYPE_CTRL:           /* Ack & Command.  In this routine we are    */
        /* just listening to the sub-proc so Command */
        /* type packets will never be handled.       */
        /* The Ack packets come in several different */
        /* flavors, based on the event being ack'd.  */
        switch (msg.control)
            {
        case Ack:
            switch (msg.a_sub)
                {
            case Creation:
                
                /*    Sub-proc has just been created.  We must assign a channel to it's   */
                /*    mailbox, the name of which has been passed in with this ACK packet. */
                
                pstr = msg.buf.charbuf;
                srclen = MIN (sizeof msg.buf.charbuf, sizeof mbxstr);
                strncpy (mbxstr, pstr, srclen);
                strncpy (tbgbl.sp.mailbox, pstr, srclen);
                tbgbl.sp.mb_len = srclen;
                
                mbxdsc.dsc$a_pointer = mbxstr;
                mbxdsc.dsc$w_length = (INT)srclen;
                
                status = sys$assign (&mbxdsc, &tbgbl.chan_to_sub, 0, 0);
                if (!status)
                    return FAIL;
                *reslen = 0;
                break;
                
                
            case Run:
                
                /* This is the most common ACK.  It is always sent back after the sub-proc   */
                /* has recieved and executed, successfully or not, a command from the master */
                /* we just copy the contents of the packet to the result buffer.         */
                
                srclen = (SHORT)msg.c_length;
                dstlen = srclen;
                fill = '\0';        /* space padding */
                
                lib$movc3 (&srclen, msg.buf.charbuf, result);
                
                /* tbh_cleanstr(result); */
                *reslen = srclen;
                break;
                
            case Error:             /* Error ACK packets are    */
                /* Currently not supported. */
            default:
                break;
                }
            break;                  /* end of the ack packet selections     */
            
            
        case Command:               /* Commands only make sense in the other    */
            /* direction, however this is here for      */
        default:                    /* future expansion since I do support the  */
            break;                  /* packet type elsewhere.....           */
            }
        break;                      /* End of the Control Message types switch  */
        
        /* Message packets, literally, are for those hopefully rare occasions when  */
        /* the sub-process wants to notify the application-user about something.    */
        /* the string is sent to the main process which prints it to SYS$OUTPUT.    */
        
    case TB_MSGTYPE_MSG:
        if (tbgbl.flg_mess)
            {
            pstr = &msg.command;
            tbh_cleanstr (pstr);
            
            status = sys$asctim (&timelen, &timedsc, 0, 0);
            timestr[timedsc.dsc$w_length] = '\0';
            
            sprintf (string, "%s \tMessage From Driver:\n\t%s\n", timestr, pstr);
            
            status = tbh_send_to_screen (string);
            }
        break;
        
        /*  O.K., this is junk mail.  Junk mail should'nt ever happen, but if    */
        /*  it does it's a sure bet that their is a problem w/the program and we */
        /* want to know about it so commit suicide right here.           */
        
    default:
        sprintf (string, "%s %s\n", errstr, tbgbl.sp.name);
        
        tbh_send_to_screen (string);    /* Notify User of problem       */
        
        tbh_msabort ();             /* Kill the sub-process     */
        pid = tbgbl.sp.pid;         /* then ourselves....       */
        sys$forcex (&pid);
        break;
        }
    return SUCCESS;                 /* always... */
    }
/* END:     */

/* Function Description -----------------------------------------------------
Description:

Prototype:
    publicdef INT tbh_send_to_screen(CHAR *string);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    string          -(CHAR *)

Return Value/Status:
    SUCCESS - Successful completion.
    FAIL    - Unsuccessful completion.

Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_send_to_screen (CHAR *string)
#else
publicdef INT tbh_send_to_screen (string)
CHAR *string;
#endif
    {
    extern TB_PROC_INFO tbgbl;
    INT status, slen;
    SHORT chan;
    
    chan = tbgbl.master.io_channel;
    
    if ((status = tbh_cleanstr (string)) != SUCCESS)
        return FAIL;
    
    slen = strlen (string);
    
    status = sys$qiow (0, chan, IO$_WRITEVBLK, 0, 0, 0, string, slen, 0, 0, 0, 0);
    
    if (!status)
        return FAIL;
    return(status);
    }
/* END:     */

/* Function Description -----------------------------------------------------
Description:

Prototype:
    publicdef INT tbh_cleanstr(CHAR *string);

Parameters:     (indicate (I)/(O)/(M) for input/output/input-and-modified)
    string          -(CHAR *)

Return Value/Status:
    SUCCESS - Successful completion.
    FAIL    - Unsuccessful completion.

Scope:
    PUBLIC
    
Limitations/Assumptions:

-----------------------------------------------------------------------------*/

/* BEGIN:   */
#if USE_PROTOTYPES
publicdef INT tbh_cleanstr (CHAR *string)
#else
publicdef INT tbh_cleanstr (string)
CHAR *string;
#endif
    {
    INT status = SUCCESS, slen = 0;
    static CHAR text[256];
    static DSC strdsc = 
        {
        sizeof text,
        DSC$K_DTYPE_T,
        DSC$K_CLASS_S,
        text
        };
    
    strcpy (text, string);
    status = str$trim (&strdsc, &strdsc, &slen);
    
    /* make C worthy */
    *(string + slen) = NUL;
    
    return(!status) ? SUCCESS : status;
#endif
    }
/* END:     */
