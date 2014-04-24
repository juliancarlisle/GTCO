/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TB_DEFS.H*/
/* *4    30-JUL-1991 15:38:43 MING "(SPR 0) change declaration of tablet_channel"*/
/* *3    13-NOV-1989 11:34:51 JULIAN "Added new tablet support for calcomp."*/
/* *2    30-JUN-1989 16:32:06 GILLESPIE "(SPR 5) CHANGE VALUES TO MATCH DB"*/
/* *1    30-JUN-1989 15:04:53 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TB_DEFS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_tb_defs.h,v 1.1 89/05/30 15:35:07 esi Exp $ esi_tb_defs.h 
 */

/******************************************************************************

		Copyright Exploration Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF 

			Exploration Systems, Inc.
			579 Market Street
			San Francisco, CA  USA 94105
			(415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work) 


******************************************************************************/

#ifndef TB_DEFS_H
#define TB_DEFS_H 1

/* define data types and new typedefs...*/
#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif
#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif
#ifndef ESI_HO_LIB_H
#include "esi_ho_lib.h"
#endif
#include "esi_glue.h"
/* #include "limits.h" */
#include "esi_tb_err.h"
#include "esi_tb_msg.h"


/**************************************************************************

                          TABLET DRIVER DEFINITIONS

 July	11, 1988      Julian Carlisle.
 August 30, 1988      Julian Carlisle.  Addem mode masks.
 January 5, 1989      Julian Carlisle.  Added prototypes.
***************************************************************************/


#define TB_NO_ERRORS  SUCCESS

/* These values all have the lowest order bit turned on */

#define TB_LAMP_ON		0x00000001
#define TB_LAMP_OFF		0x00000003
#define TB_RESET		0x00000005
#define TB_POINT_MODE		0x00000007
#define TB_LINE_MODE		0x00000009
#define TB_STREAM_MODE		0x0000000b
#define TB_INCREMENTAL_MODE	0x0000000d	
#define TB_STREAM_INC_MODE	0x0000000f	
#define TB_SET_INCREMENT	0x00000011	
#define TB_SET_RATE12		0x00000013
#define TB_SET_RATE100		0x00000015
#define TB_SET_RATE200		0x00000017
#define TB_SET_RATE5		0x00000019
#define TB_SET_RATE10		0x0000001b
#define TB_SET_RATE50		0x0000001d
#define TB_PUCK_16		0x0000001f
#define TB_PUCK_STYLUS		0x00000021
#define TB_PUCK_1		0x00000023
#define TB_PUCK_4		0x00000025
#define TB_PUCK_5		0x00000027
#define TB_ENGLISH_UNITS	0x00000029	
#define TB_METRIC_UNITS		0x0000002b
#define TB_PORT_A		0x0000002d
#define TB_PORT_B		0x0000002f
#define TB_SEND_ASCII		0x00000031
#define TB_SEND_BINARY		0x00000033
#define TB_LOW_RES		0x00000035
#define TB_HIGH_RES		0x00000037
#define TB_ALARM_ON		0x00000039
#define TB_ALARM_OFF		0x0000003b
#define TB_BELL_1		0x0000003d
#define TB_BELL_2		0x0000003f
#define TB_BELL_3		0x00000041
#define TB_BELL_4		0x00000043




/********************** TABLET CONFIGURATION MASKS **********************
*
*   The following are tablet mode MASKS that may be OR'd together.
*   
*   To set multiple tablet characteristics with one function call  
*   simply OR the desired flags together and pass the resultant 
*   value to TB_SET_DIGITIZER_MODE() inside the Mode argument.
*   
*   It is only valid to OR the TB_M_xxxx flags together in this
*   fashion.  You will get incorrect results if you attempt this 
*   with the normal TB_xxxx codes.
*
* 
***************************************************************************/

/* These values all have the lowest order byte turned off */


#define TB_M_ALARM_ON	        0x00000002  /* Warning alarms mode   */
#define TB_M_ALARM_OFF		0x00000004
#define TB_M_ENGLISH_UNITS	0x00000008  /* Inchs or Millimeters  */
#define TB_M_METRIC_UNITS	0x00000010
#define TB_M_PORT_A		0x00000020  /* Tablet output port    */
#define TB_M_PORT_B		0x00000040
#define TB_M_LOW_RES		0x00000080  /* Low / High Resolution */
#define TB_M_HIGH_RES		0x00000100
#define TB_M_LINE_MODE		0x00000200  /* digitizing modes...   */
#define TB_M_STREAM_MODE	0x00000400
#define TB_M_INCREMENTAL_MODE	0x00000800
#define TB_M_STREAM_INC_MODE	0x00001000
#define TB_M_POINT_MODE		0x00002000

#define TB_M_SET_RATE12 	0x00004000  /* XY output rates...    */
#define TB_M_SET_RATE100	0x00008000
#define TB_M_SET_RATE5		0x00010000
#define TB_M_SET_RATE10 	0x00020000
#define TB_M_SET_RATE50  	0x00040000

#define TB_M_PUCK_16		0x00080000  /* Puck types....        */
#define TB_M_PUCK_STYLUS	0x00100000
#define TB_M_PUCK_1		0x00200000
#define TB_M_PUCK_4		0x00400000
#define TB_M_PUCK_5		0x00800000


typedef USHORT		UWORD;
typedef SHORT		WORD;
typedef INT		PID;

/* The following defines are set in limits.h */
#define MAX_UINT    (INT)ULONG_MAX
#define MIN_UINT    (INT)0

#define MAX_INT	    (INT)LONG_MAX
#define MIN_INT	    (INT)LONG_MIN

#define MAX_UWORD   (INT)USHRT_MAX
#define MIN_UWORD   (INT)0 

#define MAX_WORD    (INT)SHRT_MAX   
#define MIN_WORD    (INT)SHRT_MIN

       
       
/*
 These are the tablet types currently supported. Note that I assume the 
 operation codes are the same for different models within the same 'family'.
 Should this assumption later be incorrect, i.e. different commands for 
 different calcomp tablets, the additional switch must be added in the
 routine TB_CMD_TAB().
*/
/* BINARY INPUT FORMATS.... (ID < 32) */
#define TB_GTCO_DP5	    (INT)1	/* For now, all GTCO's look similar */
#define TB_GTCO_SMALL	    (INT)1
#define TB_GTCO_11X11	    (INT)1
#define TB_GTCO_11X17	    (INT)2
#define TB_GTCO_20X20	    (INT)3
#define TB_GTCO_36X48_UGRID (INT)4
#define TB_GTCO_42X60_UGRID (INT)5
#define TB_GTCO_UGRID	    (INT)4	/* GTCO Firmware ver: T4.4b  only.  */
#define TB_CALCOMP9100UGRID (INT)11	/* configured for UGRID or not.	    */

/* ASCII INPUT FORMAT CONFIGURATIONS...	    (ID >= 32 )*/
#define TB_CALCOMP9100	    (INT)32	/* Calcomps behave differently if   */

#define TB_MBXQUO	    (INT)1280
#define TB_MBXLEN	    (INT)80
#define TEST		    FALSE
#define TB_DEBUG	    TEST
#define TIMEOUT_LIMIT	    (INT)60          /* Port timeout in seconds.  */
#define TB_RW_TIMEOUT_LIMIT (INT)30
#define TB_TYPEAHEAD_BUFSIZE (INT)100


#define	TB_I_CMD_ARGCNT	((UWORD)3)   /* Tablet_type, Device_name, ModeMask   */
#define	TB_G_CMD_ARGCNT	((UWORD)1 )  /* number of points to fetch	    */



#define TB_HIGHRES_MODE  (INT)1
#define TB_LOWRES_MODE   (INT)2
#define TB_UGRID_FORMAT_LEN  (INT)8
#define TB_HIGHRES_FORMAT_LEN  (INT)6
#define TB_LOWRES_FORMAT_LEN  (INT)5

#define TB_ASCII_FORMAT 1
#define TB_BINARY_FORMAT 2

#define CAN ((BYTE) 0x18)
#define SOH ((BYTE) 0x01)
#define LF  ((BYTE) 0x0a)
#define FF  ((BYTE) 0x0c)
#define CR  ((BYTE) 0x0d)
#define SO  ((BYTE) 0x0e)
#define ESC ((BYTE) 0x1b)
#define XON ((BYTE) 0x11)
#define XOFF ((BYTE) 0x13)

/* definitions for tb_inq function */
#define TB_INQ_INIT (INT)1
#define TB_INQ_EXTENTS (INT)2


/*
    Define the different types of messages that are used with the mailbox.
*/
#define	    Type_mess	    'M'	/* Message type */
#define	    Type_ctrl	    'C'	/* Control type */

#define	    TB_MSGTYPE_CTRL 'C'
#define	    TB_MSGTYPE_MSG  'M'

/*
    Define the Command opcodes for the sub-process.
*/
#define  Init_driver	    'I'	/*  Start the driver process.	    */
#define  Set_mode	    'M'	/*  Select data fetch method.	    */
#define  Get_points	    'G'	/*  Request points from tablet.	    */
#define  Lamp_ctrl	    'L'	/*  Switch puck LEDS on/off.	    */
#define  Ring_bell	    'B'	/*  Sound a bell tone on tablet.    */
#define  Term_driver	    'T'	/*  Shutdown the tablet driver.	    */
#define  Clear_buffer	    'C'	/*  Clear the input buffer, reset   */
#define  Debug_driver	    'D' /*  Set/Clear sub-proc debug states */
/*
    Messages that are 'type_ctrl' may represent either a command
    to be sent to the driver sub-process or a simple ACK.
*/
#define Ack		    'A'	/* Acknowedge type  */
#define Command		    'B'	/* Command line	    */

#define	TB_CTRLTYPE_ACK	    'A'
#define	TB_CTRLTYPE_CMD	    'B'


/* 
    Sub control of acknowedge message type
*/
#define  Creation	    'C'	/* Creation of sp   */
#define  Run		    'R'	/* Sp is started    */
#define  Error		    'E'	/* Sp is on error   */

#define TB_SUB_CREATION	    'C'
#define TB_SUB_RUN	    'R'
#define TB_SUB_ERROR	    'E'



typedef struct {
	    SHORT   len;
	    SHORT   type;
	    BYTE    byte[16];
	}TB_PARAM;


typedef struct {    
	    SHORT   msglen;	    /* offset 1 */
	    CHAR    type_mess;	    /* " 3 */	
	    CHAR    from_task[8];   /* " 4 */
	    CHAR    control;	    /* " 11 */
	    CHAR    a_sub;	    /* " 12 */
	    SHORT   c_length;	    /* " 13 */
	    CHAR    command;	    /* " 15 */
	    struct {
		CHAR  charbuf[32];  /* 32 bytes */        
		INT   intbuf[8];   /* 32 bytes*/
	    } buf;
	}TB_CMD_STRUCT;

    
typedef union	{
	    CHAR    cbuf[256];		/* global char result buf       */
	    INT	    ibuf[64];		/* global integer result buf       */
	    } TB_RESULT_STRUCT;

typedef struct  {
	BYTE	*g_rdptr;
	INT	g_cmd_result_len;	    
	INT   	timeout;		/* Timeout in seconds		    */
	UWORD	iosb[4];		/* I/O Status Block for QIO	    */
	UWORD	io_status;		/* copy of last iosb status	    */
	CHAR   	device[16];		/* ASCII tablet device name	    */
	CHAR	stringbuf[256];		/* global length of result	    */
	INT	tablet_init_flag;	/* TRUE after init performed. */
	} TB_GB_INFO;


#define TB_RD_BUF_SIZE	    16384
#define TB_GLOBAL_SIZE_B    TB_RD_BUF_SIZE
#define TB_GLOBAL_SIZE_I    (TB_RD_BUF_SIZE / 4)
    
/*
    Global buffer datastructure that is mapped to global section & shared.
*/
typedef struct {
    BYTE rawbuf[TB_GLOBAL_SIZE_B];	/* 16384 		*/
    INT	 x_long[512];			    /* 2048 		*/
    INT	 y_long[512];			    /* 2048 		*/
    BYTE b_byte[512];
    INT result[118];		    /* fills to 512 boundary*/
	CHAR pad[512];
    INT reslen;
    INT count;
    INT xybcur;			    /* cur xyb index	*/
    INT xybend;			    /* xyb end pos		*/
    INT	rawcur;			    /* raw buffer cur index */
    INT	rawend;			    /* raw buf end pos	*/
    INT	lastx;
    INT lasty;
    INT	lastb;
    INT flag;			    /* marks the end	*/
    }TB_GLOBUF;
	    

    
/*
    Process info struct.
*/
typedef struct {
    INT	    pid;	    /* proc id (hex)		    */
    CHAR    name[16];       /* proc name		    */
    SHORT   name_len;	    /* n chars in name		    */
    CHAR    mailbox[16];    /* mailbox name string	    */
    SHORT   mb_len;	    /* n chars in mailbox string    */
    UWORD   io_channel;    /* mail box channel id	    */
    INT	    efn;	    /* process event flag cluster   */
    INT	    master_pid;	    /* pid of master proc in tree   */
    CHAR    image[64];	    /* name of image curr running   */
    SHORT   image_len;	    /* n chars in image name string */
    } TB_PROC;
    
    
/*
    IO status block (unsigned quadword) for passing to QIO routines. 
*/
typedef union {
    UWORD	status;
    UWORD	count;
    UINT	info;
    } TB_IOSB;


typedef struct {
    TB_PROC master;
    TB_PROC sp;
    SHORT   chan_to_master;
    SHORT   chan_to_sub;
    INT	    tablet_init;
    INT	    sp_sched;
    INT	    flg_mess;
    INT	    master_priv[2];
    CHAR    master_term[10];
    INT	    master_prio;
    FILE    *tablet_channel;
    INT	    tablet_type;
    INT	    astreq;
    INT	    resmode;		    /* Low/High resolution mode */
    INT	    format;		    /* TB_ASCII_FORMAT or TB_BINARY_FORMAT */
    }TB_PROC_INFO;
    

#if USE_PROTOTYPES
extern INT tbh_send_command(CHAR *command,INT cmdlen,CHAR *result,
    INT *reslen,INT *state);
extern INT tbh_send_mess(SHORT channel, TB_CMD_STRUCT *pmsg, INT *state);
extern INT tbh_get_ack(CHAR *result,INT *reslen,INT *state);
extern INT tbh_send_to_screen(CHAR *string);
extern INT tbh_cleanstr(CHAR *string);
extern INT tbh_clear_buffer(void);
extern INT tbh_create_prc(CHAR *image);
extern VOID tbh_ast (void);
extern INT tbh_get_points(INT npoints,INT  *x,INT  *y,INT *b,INT *retcnt);
extern INT tbh_initialize(INT tablet_type, CHAR *device_name, 
		unsigned ModeMask,CHAR *image);
extern INT tbh_inq_tablet(INT code,BYTE *result);
extern INT tbh_msabort(void);
extern INT tbh_msinit(CHAR *image);
extern INT tbh_set_lamp(INT onoff);
extern INT tbh_set_mode(unsigned modemask);
extern INT tbh_terminate(void);
#endif
#endif
