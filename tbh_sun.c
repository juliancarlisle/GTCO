/* DEC/CMS REPLACEMENT HISTORY, Element TBH_SUN.C */
/* *3    30-JUL-1991 15:56:20 MING "(SPR 0) put #if UNIX " */
/* *2    30-JUL-1991 15:10:04 JULIAN "(SPR -1) -1" */
/* *1    30-JUL-1991 15:04:12 JULIAN "sun tablet driver" */
/* DEC/CMS REPLACEMENT HISTORY, Element TBH_SUN.C */
#ifdef RCSID
static char *RCSid = 
   "$Header: /j/finder/src/RCS/tbh_sun.c,v 1.1 2008/02/09 09:09:54 julian Exp $ tbh_init.c ";
#endif /* RCSID */

/********************************************************************
*      Copyright 1990, Finder Graphics Inc. Corta Madera  CA.
*  
*	Unix Tablet Driver functions for Finder.
*
*   Julian Carlisle  Oct 2, 1990
*********************************************************************/

#include "esi_c_lib.h"
#include "esi_gl_defs.h"
#include "esi_tb_defs.h"
#include "esi_wm.h"
#include "esi_tg_mat.h"
#include "esi_ctype.h"
#if UNIX									/* 910314:sjs: changed from sun */
#include <termio.h>
publicdef struct termio sun_term_buf, sun_term_save;
#endif
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
publicdef INT tbh_config_tablet(FILE *channel, unsigned modes);
publicdef INT tbh_close_chan( FILE *channel );
publicdef INT tbh_cmd_tab(INT tablet,INT incmd,CHAR *outstr);
publicdef INT tbh_do_cmd(FILE *channel,INT command);
publicdef INT tbh_gtco_get_points2(INT count,INT *x,INT *y,INT *button,INT *nout);
publicdef INT tbh_clcmp_get_points(INT count,INT *x,INT *y,INT *button,INT *nout);
publicdef INT tbh_gtco_decode_h(BYTE *fmt,INT *x,INT *y,INT *button);
publicdef INT tbh_gtco_decode_ugrid(BYTE *fmt,INT *x,INT *y,INT *button);
publicdef INT tbh_gtco_decode_l(CHAR *fmt,INT *x,INT *y,INT *button);
publicdef INT tbh_gtco_reset(FILE *channel);
publicdef INT tbh_gtco_talk(FILE *channel,CHAR *str,INT len);
publicdef INT tbh_clcmp_talk(FILE *channel,CHAR *str,INT len);
publicdef INT tbh_read_one(FILE *channel,CHAR *pch);
publicdef INT tbh_send_one(FILE *channel,CHAR ch);
publicdef INT tbh_clear_buffer();
publicdef INT tbh_set_lamp(INT onoff);
publicdef INT tbh_set_mode(unsigned modemask);
publicdef INT tbh_request_locator(INT *x,INT *y,INT *b);
publicdef INT tbh_bell(INT bellnum);
#if UNIX
/*
    These are global datastructures that each have their own PSECT.
*/
publicdef TB_PROC_INFO	tbgbl = {0};
publicdef TB_GLOBUF	tb_buffer = {0};	    /* Global shared section. */


/*
    Command code & mask tables.
*/
static INT opcodes[] = { 
		TB_ALARM_ON,			/*  1 */
		TB_ALARM_OFF,			/*  2 */
		TB_ENGLISH_UNITS,		/*  3 */
		TB_METRIC_UNITS,		/*  4 */	
		TB_PORT_A,			/*  5 */
		TB_PORT_B,			/*  6 */	
		TB_LOW_RES,			/*  7 */
		TB_HIGH_RES,			/*  8 */
		TB_LINE_MODE,			/*  9 */	   	
		TB_STREAM_MODE,			/* 10 */	
		TB_INCREMENTAL_MODE,		/* 11 */		
		TB_STREAM_INC_MODE,		/* 12 */
		TB_POINT_MODE,			/* 13 */		
		TB_SET_RATE12,			/* 14 */	    
		TB_SET_RATE100,			/* 15 */	
		TB_SET_RATE5,			/* 16 */
		TB_SET_RATE10,			/* 17 */		
		TB_SET_RATE50,			/* 18 */
		TB_PUCK_16,			/* 19 */	
		TB_PUCK_STYLUS,			/* 20 */	
		TB_PUCK_1,			/* 21 */	
		TB_PUCK_4,			/* 22 */
		TB_PUCK_5 }; 	     		/* 23 */	


static INT opmasks[] = { 
		TB_M_ALARM_ON,			/*  1 */
		TB_M_ALARM_OFF,			/*  2 */
		TB_M_ENGLISH_UNITS,   		/*  3 */
		TB_M_METRIC_UNITS,   		/*  4 */	
		TB_M_PORT_A,        		/*  5 */
		TB_M_PORT_B,			/*  6 */	
		TB_M_LOW_RES,       		/*  7 */
		TB_M_HIGH_RES,			/*  8 */
		TB_M_LINE_MODE,			/*  9 */	   	
		TB_M_STREAM_MODE,   		/* 10 */	
		TB_M_INCREMENTAL_MODE,		/* 11 */		
		TB_M_STREAM_INC_MODE,		/* 12 */
		TB_M_POINT_MODE,		/* 13 */		
		TB_M_SET_RATE12,		/* 14 */	    
		TB_M_SET_RATE100,   		/* 15 */	
		TB_M_SET_RATE5,			/* 16 */
		TB_M_SET_RATE10,		/* 17 */		
		TB_M_SET_RATE50,		/* 18 */
		TB_M_PUCK_16,			/* 19 */	
		TB_M_PUCK_STYLUS,   		/* 20 */	
		TB_M_PUCK_1,			/* 21 */	
		TB_M_PUCK_4,			/* 22 */
		TB_M_PUCK_5 };			/* 23 */	

static void tbh_log();
static long tbh_debugging = FALSE;

/* unique state ids for each level/stage of driver operation. */
static enum TB_SPSTATES {
	notinit = 1,
	init_info,
	init_mast_mbx,
	init_sp_mbx,
	init_gblsect,
	init_done,
	ast_wait,
	set_port,
	get_point,
	do_cmd,
	idle,
	terminate
	} tbh_run_state;

static CHAR  *tbh_state_str[] =  {
	"notinit",
	"init_info",
	"init_mast_mbx",
	"init_sp_mbx",
	"init_gblsect",
	"init_done",
	"ast_wait",
	"set_port",
	"get_point",
	"do_cmd",
	"idle",
	"terminate",
	0};


/********************************************************************
*
* PROGRAM:  TB_INITIALIZE()
*
* DESCRIPTION:
*   Init the tablet and it's I/O channel.  The given device will be
*   allocated and opened, the modes indicated by the bitmap in ModeMask
*   will be set in the tablet if available.  
*
* ARGUMENTS:
*   INT	    tablet_type	-   A token that identifies specific hardware.
*   CHAR    device_name	-   The device name of the tablet port.
*   INT	    ModeMask	-   The startup configuration flags.
*   INT	    istat	-   The returned status SUCCESS or FAIL. 
*
*   Julian Carlisle
*********************************************************************/

INT tbh_initialize(tablet_type, device_name, ModeMask,image)
INT	    tablet_type;
CHAR	    *device_name;
unsigned    ModeMask;
CHAR	    *image;
{
INT status;
if (strlen (device_name))
    {
    tbgbl.tablet_channel = (FILE *)fopen (device_name, "r+");
    if (tbgbl.tablet_channel == (FILE *)0)
	    {
	    tbgbl.tablet_init = FALSE;
	    perror ("Error opening tablet port.");
	    return FAIL;
	    }
    }
tbgbl.tablet_type = tablet_type;
tbgbl.tablet_init = FALSE;
if (ioctl (fileno(tbgbl.tablet_channel), TCGETA, &sun_term_buf) == -1)
    {
    perror ("tbh_init: ioctl to get term parameters failed");
    }
sun_term_save = sun_term_buf;
sun_term_buf.c_iflag &= ~(IUCLC | ISTRIP );
/* sun_term_buf.c_iflag &= ~(IUCLC | ISTRIP | INLCR | ICRNL ); */
sun_term_buf.c_iflag |= IXON;
#ifndef ECHOCTL							/* 910314:sjs: no ECHOCTL on mips */
sun_term_buf.c_lflag &= ~(ICANON | ISIG );
#else
sun_term_buf.c_lflag &= ~(ICANON | ECHOCTL |  ISIG );
#endif	/* ECHOCTL */
sun_term_buf.c_cflag &= ~PARENB;
sun_term_buf.c_cflag &= ~CS7;
sun_term_buf.c_cflag |= CS8;
sun_term_buf.c_cflag &= ~B9600;
sun_term_buf.c_cflag |= B9600;
sun_term_buf.c_cc[VMIN] = 0;
sun_term_buf.c_cc[VTIME] = 100;


if (ioctl (fileno(tbgbl.tablet_channel), TCSETA, &sun_term_buf) == -1)
    {
    perror ("tbh_init: ioctl to set term parameters failed");
    }
 setbuf (tbgbl.tablet_channel, NULL);     /* set no buffering */
tbgbl.resmode = TB_HIGHRES_MODE;
/* Initialize the port. */

status = tbh_config_tablet(tbgbl.tablet_channel, ModeMask);
tbgbl.tablet_init = TRUE;
if (tbgbl.resmode != TB_HIGHRES_MODE &&
	tbgbl.resmode != TB_LOWRES_MODE)
	{
/*	tbh_do_cmd(tbgbl.tablet_channel, TB_HIGH_RES); */
	}
tbh_gtco_reset(tbgbl.tablet_channel);
return status;
}


static void tbh_log(str)
CHAR *str;
{	
static CHAR text[128],efile[128];
FILE *fp;
static firstcall = TRUE;

if (firstcall == TRUE)
	{
	strcpy(text,"Tablet_driver");
	sprintf(efile,"%s.log",text);
	firstcall = FALSE;
	}
if ((fp = fopen(efile,"a+")) != (FILE *)0)
	{
	fprintf(fp,"*------------------------------------------*\n"); 
	fprintf(fp,"*  Time: %s\n",ho_date_tag(text));
	fprintf(fp,"* Error: -->  %s  <-- \n",str); 
	fprintf(fp,"*------------------------------------------*\n\n"); 
	fclose(fp);
	}
return;
}	
		
	
/********************************************************************
*
* PROGRAM: tbh_config_tablet
* DESCRIPTION:
*   This program decodes the modemask argument and sends
*   the proper command codes to the tablet to implement
*   the modes requested in the bitmap.
*
* ARGUMENTS:
*   In:	FILE 	    *channel	-   The tablet device channel
*	unsigned    modes	-   Bitmap of selected modes.
*
* RETURNS:
*   The status of the do_command low-level tablet service. (SUCCESS)
*
*   Julian Carlisle 
*********************************************************************/
publicdef INT tbh_config_tablet(channel, modes)
FILE *channel;
unsigned modes;
{
INT status = SUCCESS;
unsigned mask;
INT n;

modes &= 0x7fffffff;	    /* drop sign if any */

/*  
    Decode the Users Preferences Mask & Execute the resulting commands.
    
    For each bit position that is on, fetch & execute
    the corresponding tablet option command from the 
    opcode table.
    
    Julian  sep 6, 1988
*/

for (n = 0,mask = opmasks[0]; (mask & 0x3fffffff); n++, mask <<= 1)
    status = (modes & mask) ? tbh_do_cmd(channel,opcodes[n]) : SUCCESS;
   
return status;
}

/********************************************************************
*
* PROGRAM: tbh_close_chan()
*
* DESCRIPTION:
*   Closes/deallocates the given I/O channel.  Called after all 
*   I/O operations have completed and the channel is no longer needed.
*
* ARGUMENTS:
*   Input:  FILE *channel	    - The channel id to close.
*
* RETURNS:
*   Either SUCCESS or the status from $DASSGN if problem occurs.
*
*   Julian Carlisle  
*********************************************************************/
publicdef INT tbh_close_chan( channel )
FILE *channel;
{
INT status;
if (channel != (FILE *)0 && tbgbl.tablet_init == TRUE)
	{
	fclose(channel);
	tbgbl.tablet_init = FALSE;
	status = SUCCESS;
	}
return status;
}


/********************************************************************
*
* PROGRAM: tbh_cmd_tab()
*
* DESCRIPTION:
*   Takes a command id code and returns the appropriate command string
*   for the currently active tablet.  The string returned is only the
*   'command string' for the tablet, a delimiter must be appended by the
*   calling routine as well as a 'attention' prefix character.  For the 
*   GTCO tablet for instance, the prefix to the command string is the
*   ascii char SOH or hex 01 and the delimiter ending the command must
*   be and ESC char or hex 1B.
*
* ARGUMENTS:
*   Input:  INT tablet	    - The id code for a supported tablet.
*   Input:  INT	incmd	    - The command code requested.
*   Output: CHAR *outstr    - The proper command str for the tablet.
*
* RETURNS:
*   Either SUCCESS or one of (TB_UNKNOWN_COMMAND,TB_UNKNOWN_TABLET)
*
*   Julian Carlisle    
*********************************************************************/

publicdef INT tbh_cmd_tab(tablet,incmd,outstr)
INT tablet,incmd;
CHAR *outstr;
{
CHAR cmdbuf[10];
INT status = SUCCESS;
switch(tablet)
    {
    case TB_GTCO_11X11:
    case TB_GTCO_11X17:
    case TB_GTCO_20X20:
    case TB_GTCO_36X48_UGRID:
    case TB_GTCO_42X60_UGRID:
        *outstr = (BYTE)0x01;
	outstr++;
	switch(incmd)
	    {
	    case TB_RESET:
		 strcpy(outstr,"RS");
		 break;
	    case TB_POINT_MODE:
		strcpy(outstr,"PT");
		break;
	    case TB_LINE_MODE:
		strcpy(outstr,"LN");
		break;
	    case TB_STREAM_MODE:
		strcpy(outstr,"CN");
		break;
	    case TB_INCREMENTAL_MODE:
		strcpy(outstr,"IC");
		break;
	    case TB_STREAM_INC_MODE:
		strcpy(outstr,"CL");
		break;
	    case TB_SET_INCREMENT:
		strcpy(outstr,"IV");
		break;
	    case TB_SET_RATE12:
		strcpy(outstr,"R1");
		break;
	    case TB_SET_RATE100:
		strcpy(outstr,"R2");
		break;
	    case TB_SET_RATE200:
		strcpy(outstr,"R3");
		break;
	    case TB_SET_RATE5:
		strcpy(outstr,"R4");
		break;
	    case TB_SET_RATE10:
		strcpy(outstr,"R5");
		break;
	    case TB_SET_RATE50:
		strcpy(outstr,"R6");
		break;
	    case TB_PUCK_16:
		strcpy(outstr,"6B");
		break;
	    case TB_PUCK_STYLUS:
	    case TB_PUCK_1:
	    case TB_PUCK_4:
	    case TB_PUCK_5:
		strcpy(outstr,"5B");
		break;
	    case TB_ENGLISH_UNITS:
	        strcpy(outstr,"IN");
		break;
	    case TB_METRIC_UNITS:
		strcpy(outstr,"MT");
		break;
	    case TB_PORT_A:
		strcpy(outstr,"PA");
		break;
	    case TB_PORT_B:
		strcpy(outstr,"PB");
		break;
	    case TB_SEND_ASCII:
		strcpy(outstr,"AS");
		break;
	    case TB_SEND_BINARY:
		strcpy(outstr,"BI");
		break;
	    case TB_LOW_RES:
		strcpy(outstr,"LR");
		break;
	    case TB_HIGH_RES:
		strcpy(outstr,"HR");
		break;
	    case TB_ALARM_ON:
		strcpy(outstr,"AE");
		break;
	    case TB_ALARM_OFF:
		strcpy(outstr,"AD");
		break;
	    case TB_BELL_1:
		strcpy(outstr,"T1");
		break;
	    case TB_BELL_2:
		strcpy(outstr,"T2");
		break;
	    case TB_BELL_3:
		strcpy(outstr,"T3");
		break;
	    case TB_BELL_4:
		strcpy(outstr,"T4");
		break;
	    case TB_LAMP_ON:
		strcpy(outstr,"ON");
		break;
	    case TB_LAMP_OFF:
		strcpy(outstr,"OF");
		break;
	    default:
	        status = TB_UNKNOWN_COMMAND;
		break;
	     }

	break;

     case TB_CALCOMP9100UGRID:
     case TB_CALCOMP9100:
        *outstr++ = ESC;
	*outstr++ = '%';
	switch(incmd)
	    {
	    case TB_RESET:
		 strcpy(outstr,"VR");
		 break;
	    case TB_POINT_MODE:
		strcpy(outstr,"P");
		break;
	    case TB_LINE_MODE:
		strcpy(outstr,"U");
		break;
	    case TB_STREAM_MODE:
		strcpy(outstr,"R");
		break;
	    case TB_INCREMENTAL_MODE:
		strcpy(outstr,"IC");
		break;
	    case TB_STREAM_INC_MODE:
		strcpy(outstr,"IR");
		break;
	    case TB_SET_RATE12:
		strcpy(outstr,"W12");
		break;
	    case TB_SET_RATE100:
		strcpy(outstr,"W100");
		break;
	    case TB_SET_RATE5:
		strcpy(outstr,"W5");
		break;
	    case TB_SET_RATE10:
		strcpy(outstr,"W10");
		break;
	    case TB_SET_RATE50:
		strcpy(outstr,"W50");
		break;
	    case TB_PORT_A:
		strcpy(outstr,"A1");
		break;
	    case TB_PORT_B:
		strcpy(outstr,"B1");
		break;
	    case TB_LOW_RES:
		strcpy(outstr,"JR500,0");
		break;
	    case TB_HIGH_RES:
		strcpy(outstr,"JR1000,0");
		break;
	    case TB_ALARM_ON:
		strcpy(outstr,"V9");
		break;
	    case TB_ALARM_OFF:
		strcpy(outstr,"V8");
		break;
	    case TB_LAMP_ON:
		strcpy(outstr,"V1");
		break;
	    case TB_LAMP_OFF:
		strcpy(outstr,"V0");
		break;
	    case TB_BELL_1:
	    case TB_BELL_2:
	    case TB_BELL_3:
	    case TB_BELL_4:
	    case TB_PUCK_1:
	    case TB_PUCK_4:
	    case TB_PUCK_5:
	    case TB_PUCK_16:
	    case TB_SET_INCREMENT:
	    case TB_SET_RATE200:
	    case TB_SEND_ASCII:
	    case TB_SEND_BINARY:
	    case TB_PUCK_STYLUS:
	    case TB_METRIC_UNITS:
	    case TB_ENGLISH_UNITS:
	    default:
	        status = TB_UNKNOWN_COMMAND;
		break;
	     }

	break;

    default:
	break;
    }
return status;
}	


 
 


/********************************************************************
*
* PROGRAM: tbh_do_cmd()
*
* DESCRIPTION:
*   Send the given command code to the tablet currently active.
*
* ARGUMENTS:
*   Input:  FILE  *channel  - The channel for I/O with tablet.
*   Input:  INT command	    - The id of the command to execute.
*
* RETURNS:
*   Either SUCCESS or the I/O status returned from tb_talk().
*
*   Julian Carlisle     
*********************************************************************/
publicdef INT tbh_do_cmd(channel,command)
FILE *channel;
INT command;
{
INT status = SUCCESS;
CHAR strbuf[32];
INT len = 0;
CHAR cmdbuf[32];


status = tbh_cmd_tab(tbgbl.tablet_type, command, strbuf);
if (status != SUCCESS)
    return status;


/* replace the NUL terminating the string with a carriage return CR. */
len = strlen(strbuf);

switch(tbgbl.tablet_type) 
    {
    case TB_GTCO_11X11:
    case TB_GTCO_11X17:
    case TB_GTCO_20X20:
    case TB_GTCO_36X48_UGRID:
    case TB_GTCO_42X60_UGRID:
	strbuf[len++] = ESC; 
	status = tbh_gtco_talk(channel,strbuf,len);
	break;
    
    case TB_CALCOMP9100UGRID:
    case TB_CALCOMP9100:
	strbuf[len] = CR;
	status = tbh_clcmp_talk(channel,strbuf,len+1);
	break;
    }
    
if (status == SUCCESS) {
    switch(command)
	{
	case TB_HIGH_RES:
	    tbgbl.resmode = TB_HIGHRES_MODE;
	    break;
	case TB_LOW_RES:
	    tbgbl.resmode = TB_LOWRES_MODE;
	    break;
	default:
	    break;
	}
    }
return status;

}
 



/*************************************************************************
*
* PROGRAM: tbh_gtco_get_points2()
*
* DESCRIPTION:
*   Reads the next coord set from the global point buffers.  If the
*   buffer is empty, it arranges for the current typeahead buffer
*   full of formats to be read in and converted and stored in the 
*   global buffers. 
*
* ARGUMENTS:
*   Input:  INT	    count	-   Total to fetch (Max)
*    Output: INT    x[]		-   Arrays of xyb coords
*    Output: INT    y[]
*    Output: INT    button[]
*    Output: INT    *nout	-   count returned
*
* RETURNS:
*   SUCCESS or TB_NO_POINTS, TB_BUF_OVERFLOW
*
* Julian Carlisle  
**************************************************************************/
publicdef INT tbh_gtco_get_points2(count,x,y,button,nout)
INT count,*x, *y, *button, *nout;
{
INT 	status;
USHORT 	flen;
INT 	nbytes, 
	sync_mask, 
	i,
	bufsize;

*nout = 0;	/* assume the worst in beginning */
status = TB_NO_POINTS;
tc_zeroes(tb_buffer.rawbuf,(sizeof tb_buffer.rawbuf)-1);
switch(tbgbl.tablet_type){
case TB_GTCO_36X48_UGRID:
case TB_GTCO_42X60_UGRID:
    flen = TB_UGRID_FORMAT_LEN;
    sync_mask = 0x40;
    break;

default:
    /* the length in bytes of the format packet for a given resolution. */    
    flen = (tbgbl.resmode == TB_HIGHRES_MODE) ? TB_HIGHRES_FORMAT_LEN : 
                                             TB_LOWRES_FORMAT_LEN;
    /* The sync bit is in different places on different formats. */
    sync_mask = (tbgbl.resmode == TB_HIGHRES_MODE) ? 0x80 : 0x40;
    break;
    }

/* Read in next flen bytes to make a coordinate format. */

tb_buffer.rawcur = 0;
tb_buffer.rawend = 0;
/* Get enough read to build a format....  */
bufsize=tb_buffer.rawend-tb_buffer.rawcur;
while (bufsize < flen) 
	{
	status = fread(&tb_buffer.rawbuf[tb_buffer.rawend],
			1,(flen-bufsize),tbgbl.tablet_channel);
	if (status == 0)
		continue;
	else
		tb_buffer.rawend += status;
	while (!((INT)(tb_buffer.rawbuf[tb_buffer.rawcur]) & sync_mask))
		{
		if (tb_buffer.rawcur < tb_buffer.rawend)
			tb_buffer.rawcur++;
		else	
			{
			tb_buffer.rawcur = 0;
			tb_buffer.rawend = 0;
			break;
			}
				
		}
	bufsize=tb_buffer.rawend-tb_buffer.rawcur;
	}		

/* Frame the format packet by checking the sync_mask */

switch (tbgbl.tablet_type){
case TB_GTCO_36X48_UGRID:
case TB_GTCO_42X60_UGRID:
	status = tbh_gtco_decode_ugrid(&tb_buffer.rawbuf[tb_buffer.rawcur],
			x,y,button );
	break;
case TB_GTCO_11X11:
case TB_GTCO_11X17:
case TB_GTCO_20X20:
default:     
	switch (tbgbl.resmode )	{
	case TB_HIGHRES_MODE:
		status = tbh_gtco_decode_h(&tb_buffer.rawbuf[tb_buffer.rawcur],
			x,y,button );
		break;

	case TB_LOWRES_MODE:
		status = tbh_gtco_decode_l(&tb_buffer.rawbuf[tb_buffer.rawcur],
					x,y,button );
		break;
	
	default:
		status = TB_NOT_INIT;
		return status;
		break;
	}
}

if  (status == TB_BAD_FORMAT_FRAME)
	{
	tb_buffer.rawcur++;
	tbh_log("Error framing format packets...\n");
	return TB_NO_POINTS;
	}
else
	{
	(*nout)++;
	status = SUCCESS;
	}
	
    /* reset the buffer pointers whenever they actually match */
if (tb_buffer.rawcur >= tb_buffer.rawend)
	{
	tb_buffer.rawcur = 0;
	tb_buffer.rawend = 0;
	}
else if (tb_buffer.rawend-tb_buffer.rawcur >= flen)
	{
	status = TB_MORE_DATA;
	}
return status;
}

/*************************************************************************
*
* PROGRAM: tbh_clcmp_get_points()
*
* DESCRIPTION:
*   This program reads ascii format strings from the calcomp 9100.
*   Reads the next coord set from the global point buffers.  If the
*   buffer is empty, it arranges for the current typeahead buffer
*   full of formats to be read in and converted and stored in the 
*   global buffers. 
*
* ARGUMENTS:
*   Input:  INT	    count	-   Total to fetch (Max)
*    Output: INT    x[]		-   Arrays of xyb coords
*    Output: INT    y[]
*    Output: INT    button[]
*    Output: INT    *nout	-   count returned
*
* RETURNS:
*   SUCCESS or TB_NO_POINTS, TB_BUF_OVERFLOW
*
* Julian Carlisle  
**************************************************************************/
publicdef INT tbh_clcmp_get_points(count,x,y,button,nout)
INT count,*x, *y, *button, *nout;
{
INT status = SUCCESS,buf_status;
USHORT flen;
CHAR cbuf[16];
INT nbytes;
INT sync_mask = 0;
INT i;
static INT half_way = TB_RD_BUF_SIZE / 2;
SHORT srclen;
CHAR bstr[4],xstr[8],ystr[8];
CHAR *ptr;
INT btn;
long framed = FALSE;

/*  12 byte ascii format terminated by carriage return & optional linefeed. */
/*  LEGEND:	bdxxxxxyyyyyR[L]	    where:			    */
/*  b=button,	d=<ignore>, X=xxxxx,	Y=yyyyy,  <CR>=R,   <LF>=L	    */
flen = 12;  	



/*
    ----------------------------------------------------------------------
    Note on indexes:    
    rawcur = the index of the next byte in the buffer to be processed.  
    rawend = the index pointing to the next free byte (current end-of-data)
    
    ----------------------------------------------------------------------
*/

*nout = 0;		    /* assume the worst in beginning */
status = TB_NO_POINTS;
nbytes = 0;

do { 
    nbytes = fread(&tb_buffer.rawbuf[tb_buffer.rawend],
			1,1,tbgbl.tablet_channel);
} while (! isalnum(tb_buffer.rawbuf[tb_buffer.rawend]));

tb_buffer.rawend += nbytes;

for (i=nbytes; i < flen; i++) {
    nbytes = fread(&tb_buffer.rawbuf[tb_buffer.rawend],
			1,1,tbgbl.tablet_channel);
    tb_buffer.rawend += nbytes;
}	

#if 0
nbytes = fread(&tb_buffer.rawbuf[tb_buffer.rawend],
		   1,flen, tbgbl.tablet_channel);
#endif	

/* Pickup where we left off last time through */
tb_buffer.xybcur = tb_buffer.xybend;

/* if there are enough bytes to build a packet, go for it... */
if (tb_buffer.rawend - tb_buffer.rawcur >= flen)
    {
    
    /* For each point requested.... */
    for (i=0; i < count; i++)
	{
	/*------------------------------------------------------*/
	/* Loop through buffer until framed on the next packet  */
	/* 2nd char of packet is always 'D', so lets search...  */
	/*------------------------------------------------------*/
	framed = FALSE;	
	while(!framed)
	    {
	    if ((isalnum(tb_buffer.rawbuf[tb_buffer.rawcur])) AND
		((CHAR)tb_buffer.rawbuf[tb_buffer.rawcur+1] == 'D'))
		{
		framed = TRUE;
		continue;
		}
	    
	    tb_buffer.rawcur++;
	    if (tb_buffer.rawcur >= tb_buffer.rawend)
		{
		/* End of data reached... reset indexes and leave */
		tb_buffer.rawcur = 0;
		tb_buffer.rawend = 0;
		
		/* have any coords been delivered this read? */
		status = (i == 0) ? TB_NO_POINTS : SUCCESS ;
		break;
		}
	    }
	if (!framed)
	    break;
	    
	if (tb_buffer.rawend-tb_buffer.rawcur < flen)
	    {
	    /* We presumably have good framing here... But not	*/
	    /* enough data to work with... Maybe next time	*/
	    status = (i == 0) ? TB_NO_POINTS : SUCCESS ;
	    break;
	    }
	    
	/* Build a coordinate packet */	    	
	ptr = (CHAR *)&tb_buffer.rawbuf[tb_buffer.rawcur];
	    
	bstr[0] = *ptr++;

	memcpy(xstr,++ptr,(size_t)5);
	memcpy(ystr,ptr+5,(size_t)5);

	bstr[1] = '\0';
	xstr[5] = '\0';
	ystr[5] = '\0';

	if(bstr[0] >= '0' AND bstr[0] <= '9')
	    btn = atol(bstr);
	else
	    btn = (bstr[0] - 'A')+10;

	*x = atol(xstr);
	*y = atol(ystr); 
	*button =  btn;
	
	/* store points in shared memory buffers so that */
	/* the application can get at them quickly	 */
	tb_buffer.x_long[tb_buffer.xybend + i] = *x;
	tb_buffer.y_long[tb_buffer.xybend + i] = *y;
	tb_buffer.b_byte[tb_buffer.xybend + i] = (CHAR)*button;
	
	tb_buffer.xybend++;
	tb_buffer.rawcur += flen;
	(*nout)++;
	status = SUCCESS;
	}
    
	
    if (tb_buffer.rawend-tb_buffer.rawcur >= flen)
		{
		status = TB_MORE_DATA;
		}
	
    }

/* reset the buffer pointers whenever we hit the end */
if (tb_buffer.rawcur >= tb_buffer.rawend)
    {
    tb_buffer.rawcur = 0;
    tb_buffer.rawend = 0;
    }

if (tb_buffer.xybend >= 512)
	{
	if (tbh_debugging == TRUE)
		tbh_log("tb_buffer.xybend > 512....Resetting to 0 in tbh_clcmp_get_point");
	tb_buffer.xybend = 0;
	}
			
return status;
}



/********************************************************************
*
* PROGRAM:  tbh_gtco_decode_h()
* DESCRIPTION:
*   This function decodes the X, Y and Button data from a high 
*   resolution mode binary format read from the tablet.  The 
*   coordinate information is returned.
*
* ARGUMENTS:
*   Input:  CHAR *fmt	- The buffer containing format bytes.
*   Output: INT  x,y		- The X and Y coordinates.
*   Output: INT  button		- The number of the button pressed.
*				  or -1 if no button was pressed.
* RETURNS:
*   Either SUCCESS or TB_BAD_FORMAT_FRAME.
*
*   Julian Carlisle     
*********************************************************************/
publicdef INT tbh_gtco_decode_h(fmt,x,y,button)
BYTE *fmt;
INT  *x,*y;
INT  *button;
{

/* temporary bit accumulators */
unsigned temp1,temp2,temp3;	/* 2 bytes */

INT	status = SUCCESS;

/* The high order bit of the first byte in the buffer must be set.  This */
/* bit is the sync mark.  All the other high order bits in the format must */
/* be unset.  This is how we check for a properly framed format packet. */

if ((((unsigned)fmt[1]|(unsigned)fmt[2]|(unsigned)fmt[3]|
      (unsigned)fmt[4]|(unsigned)fmt[5]) & 0x80) OR 
     ((unsigned)fmt[0] & 0x80 == 0))
    {
    status = TB_BAD_FORMAT_FRAME;
    }
else
    {
    temp1 = ((unsigned)fmt[0] & 0x7c);	                       /* get button info  */
    if (temp1 == 0)
	*button = -1;
    else
	{
	temp1 >>= 2;
	temp1 &= 0x0f;
	*button = temp1;		            /* Make button byte */
	}

    temp1 = (unsigned)fmt[0] & 0x03;                   /* bits 15,14 of x  */
    temp1 <<= 14;

    temp2 = (unsigned)fmt[1] & 0x7f;                   /* bits 13 - 7 of x */
    temp2 <<= 7;

    temp3 = (unsigned)fmt[2] & 0x7f;                   /* bits 6 - 0 of x  */
    *x = (temp1 | temp2 | temp3);  /* build x coord    */

    temp1 = (unsigned)fmt[3] & 0x03;                   /* bits 15,14 of y  */
    temp1 <<= 14;

    temp2 = (unsigned)fmt[4] & 0x7f;                   /* bits 13 - 7 of y */
    temp2 <<=7;

    temp3 = (unsigned)fmt[5] & 0x7f;                   /* bits 6 - 0 of y  */
    *y = (temp1 | temp2 | temp3);               /* build y coord    */

    status = SUCCESS;
    }
return status;
}


publicdef INT tbh_gtco_decode_ugrid(fmt,x,y,button)
BYTE *fmt;
INT  *x,*y;
INT  *button;
{

/* temporary bit accumulators */
unsigned temp1,temp2,temp3;	/* 2 bytes */

INT	status = SUCCESS;

/* The high order bit of the first byte in the buffer must be set.  This */
/* bit is the sync mark.  All the other high order bits in the format must */
/* be unset.  This is how we check for a properly framed format packet. */

if (((fmt[1]|fmt[2]|fmt[3]|
      fmt[4]|fmt[5]|fmt[6]|fmt[7]) & 0x40) OR 
     (fmt[0] & 0x40 == 0))
    {
    status = TB_BAD_FORMAT_FRAME;
    }
else
    {
    temp1 = (fmt[1] & 0x1f);	                       /* get button info  */
    *button =  (temp1 == 0) ?  -1 : temp1;
    
    temp1 = fmt[4] & 0x0f;
    temp1 <<= 12;
    
    temp2 = fmt[3] & 0x3f;                   /* bits 13 - 7 of x */
    temp2 <<= 6;

    temp3 = fmt[2] & 0x7f;                   /* bits 6 - 0 of x  */
    *x = (temp1 | temp2 | temp3);  /* build x coord    */

    temp1 = fmt[7] & 0x0f;
    temp1 <<= 12;
    
    temp2 = fmt[6] & 0x3f;                   /* bits 13 - 7 of x */
    temp2 <<= 6;

    temp3 = fmt[5] & 0x7f;                   /* bits 6 - 0 of x  */
    *y = (temp1 | temp2 | temp3);               /* build y coord    */

    status = SUCCESS;
    }
return status;
}



 
 

/********************************************************************
*
* PROGRAM:  tbh_gtco_decode_l()
* DESCRIPTION:
*   This routine decodes GTCO low resolution binary coordinate formats.
*   Its usage and behavior is the same as for tbh_gtco_decode_h().
*
* ARGUMENTS:
*   Input:  CHAR *fmt	- The buffer containing format bytes.
*   Output: INT  x,y		- The X and Y coordinates.
*   Output: INT  button		- The number of the button pressed.
*				  or -1 if no button was pressed.
* RETURNS:
*   Either SUCCESS or TB_BAD_FORMAT_FRAME
*  Julian Carlisle  
*********************************************************************/
publicdef INT tbh_gtco_decode_l(fmt,x,y,button)
CHAR *fmt;
INT  *x,*y;
INT  *button;
{

/* temporary bit accumulators */
unsigned	temp;		                /* 1 byte */
unsigned	temp1,temp2,temp3;	/* 2 bytes */

INT	status = SUCCESS;

/* Bit #6 of the first byte in the buffer must be set.  This */
/* bit is the sync mark.  All the other bit #6's in the format must */
/* be unset.  This is how we check for a properly framed format packet. */

if ((((unsigned)fmt[1]|(unsigned)fmt[2]|(unsigned)fmt[3]|
      (unsigned)fmt[4]) & (unsigned)0x40) OR 
     ((unsigned)fmt[0] & (unsigned)0x40 == 0))
    {
    status = TB_BAD_FORMAT_FRAME;
    }
else
    {
    temp = ((unsigned)fmt[0] & 0x003e);	                 /* get button info  */
    if (temp = 0)
	*button = -1;
    else
		    /* Make button byte */
	*button = (unsigned)((temp >> 1) & 0x001f); 

    temp2 = (unsigned)fmt[1] & 0x003f;                 /* bits 13 - 7 of x */
    temp3 = (unsigned)fmt[2] & 0x003f;                 /* bits 6 - 0 of x  */
    *x = ((temp3<<6)|temp2);                           /* build x coord    */

    temp2 = (unsigned)fmt[3] & 0x003f;                 /* bits 13 - 7 of y */
    temp3 = (unsigned)fmt[4] & 0x003f;                 /* bits 6 - 0 of y  */
    *y = ((temp3<<6)|temp2);                           /* build y coord    */

    status = SUCCESS;
    }
return status;
}



 
 


/********************************************************************
*
* PROGRAM:  tbh_gtco_reset()
* DESCRIPTION:
*   Sends a reset command string to the GTCO tablet.
*
* ARGUMENTS:
*   Input:  FILE *channel   - The I/O channel assoc. with the tablet.
*
* RETURNS:
*   Either SUCCESS or TB_IO_ERROR
*
*   Julian Carlisle     
*********************************************************************/
publicdef INT tbh_gtco_reset(channel)
FILE *channel;
{
return tbh_do_cmd(channel, TB_RESET);
}

 
 


/********************************************************************
*
* PROGRAM:  tbh_gtco_talk()
* DESCRIPTION:
*   Sends a command string to the GTCO tablet.  This done by first
*   transmitting the attention character (first char in buffer) then
*   waiting for the GTCO to send its command prompt, then sending the
*   remainder of the command string.  This interaction is device 
*   specific.
*
* ARGUMENTS:
*   Input:  FILE *channel   - The I/O channel assoc. with the tablet.
*   Input:  CHAR *str	    - The buffer hol ding the string to xmit.
*   Input:  INT len	    - The length of the string in the buffer.
*
* RETURNS:
*   Either SUCCESS or one of (TB_IO_TIMEOUT,TB_IO_ERROR)
*
*   Julian Carlisle     
*********************************************************************/
publicdef INT tbh_gtco_talk(channel,str,len)
FILE *channel;
CHAR *str;
INT len;
{
INT status, n;
CHAR buf[64];

tc_zeroes(buf,sizeof(buf) -1);
status = fwrite(str++,1, 1, channel);
do {
    status = fread(buf,1,1,channel); 
    if (status != 1 || buf[0] != '>') {
	    tbh_send_one(channel,ESC);
	    tbh_send_one(channel,SOH);
	    }
} while (status != 1 || buf[0] != '>');

status = fwrite(str++,1, 1, channel);
status = fwrite(str++,1, 1, channel);
status = fwrite(str++,1, 1, channel);
status = fread(buf,1,2,channel); 

return (status == 2) ? SUCCESS : TB_IO_ERROR;
}



/********************************************************************
*
* PROGRAM:  tbh_clcmp_talk()
* DESCRIPTION:
*   Sends a command string to the CALCOMP tablet.  This done by first
*   transmitting the attention character (an escape char) then sending the
*   remainder of the command string.  This interaction is device 
*   specific.
*
* ARGUMENTS:
*   Input:  FILE channel    - The I/O channel assoc. with the tablet.
*   Input:  CHAR *str	    - The buffer holding the string to xmit.
*   Input:  INT len	    - The length of the string in the buffer.
*
* RETURNS:
*   Either SUCCESS or TB_IO_ERROR
*
*   Julian Carlisle     
*********************************************************************/
publicdef INT tbh_clcmp_talk(channel,str,len)
FILE *channel;
CHAR *str;
INT len;
{
INT status, n;

status = (fwrite(str,1, len, channel) > 0)  ? SUCCESS : TB_IO_ERROR;
for(n=0;n<3000;n++) ;  

return status;
}


/******************************************************************
*
* Program:  TBH_READ_ONE()
*
* Description:
*
*     Given a character and an I/O channel, read a single byte 
*     from the port. 
*
******************************************************************/
publicdef INT tbh_read_one(channel,pch)
FILE *channel;
CHAR *pch;
{
INT status;

if (pch != (CHAR *)0)
	status = (fread(pch, 1, 1, channel) > 0 ) ? SUCCESS : TB_IO_ERROR;
else
	status = FAIL;

return status;
}
 
 

/******************************************************************
*
* Program:  TBH_SEND_ONE()
*
* Description:
*
*     Given a character and an I/O channel, send a single byte to 
*     the port. 
*
******************************************************************/
publicdef INT tbh_send_one(channel,ch)
FILE *channel;
CHAR ch;
{
CHAR *pch;
INT status = SUCCESS;
pch = (CHAR *)&ch;

status = (fwrite(pch, 1, 1, channel) > 0 ) ? SUCCESS : TB_IO_ERROR;
return status;
}
 
 



/********************************************************************
*
* PROGRAM:	tbh_clear_buffer
*
* DESCRIPTION:
*   This program clears the internal buffers so that the next
*   coordinate fetch is directly from the device. (New data).
*
* ARGUMENTS:
*   Out:    INT *state	    -	Status of operation
*   
*   Julian Carlisle    
*********************************************************************/
publicdef INT tbh_clear_buffer()
{
INT status;
status = SUCCESS;
return status;
}



/********************************************************************
*
* PROGRAM:	tbh_set_lamp
*
* DESCRIPTION:
*   This program turns the LED on the tablet puck On and OFF.
*
* ARGUMENTS:
*   In:	INT   onoff	Set to either ON or OFF.
*   Out: INT *state		Status from operation.	 
*
* RETURNS:
*   Status from set lamp request.  Normally SUCCESS
*
*   Julian Carlisle 
*********************************************************************/
publicdef INT tbh_set_lamp(onoff)
INT onoff;
{
INT status;
if (onoff)
    status = tbh_do_cmd(tbgbl.tablet_channel, TB_LAMP_ON);
else
    status = tbh_do_cmd(tbgbl.tablet_channel, TB_LAMP_OFF);
return status;
}

/********************************************************************
*
* PROGRAM:	tbh_set_mode
*
* DESCRIPTION:
*   This program allows users to set different operational 
*   characteristics of the tablet.
*
* ARGUMENTS:
*   
* RETURNS:
*
*   Julian Carlisle     
*********************************************************************/
publicdef INT tbh_set_mode(modemask)
unsigned modemask;
{

return tbh_config_tablet(tbgbl.tablet_channel, modemask);

}

/********************************************************************
* 
*
* PROGRAM:	TBH_GET_POINTS()	    -	Application Interface rtn.
*
* DESCRIPTION:	
*   This is the interface that application programs call to get
*   tablet coords.  
*
*   The method for getting points to the application program depends
*   on the number of points being fetched.  
*	   or:
*	      1) The user has pressed a puck key defined as a DONE key.
*	      2) An I/O error causes the point stream to stop early.
*	      3) The number of points fetched becomes greater than the
*	         amount of space available in the user-supplied buffer. 
*	      4) The global points buffer becomes full.
*	      5) - - - ?
*	      
*	d) The driver fetches points until either it is finished or 
*	   one of the above conditions caused it to terminate early and
*	   returns these points to the user.
*
*
* ARGUMENTS:
*	Input:	INT npoints	- The number of points to fetch.
*	Output:	INT *retcnt	- The actual returned count.
*	Output: INT *x,*y,*b	- Ptrs to the destination buffers for XYB.
*	Output: INT *stat	- SUCCESS or FAIL or TB_NO_POINTS.
*
*   Julian Carlisle      
******************************************************************************/
INT tbh_get_points(npoints, x, y, b, retcnt)
INT npoints;
INT *x, *y, *b;
INT *retcnt;
{  
INT status,istat,*pint,nbytes;


/* simple case first */
switch(tbgbl.tablet_type)
    {
    case TB_GTCO_11X11:
    case TB_GTCO_11X17:
    case TB_GTCO_20X20:
    case TB_GTCO_36X48_UGRID:
    case TB_GTCO_42X60_UGRID:
	status = tbh_gtco_get_points2(npoints,x, y, b,retcnt);
	break;
	
	case TB_CALCOMP9100:
	status = tbh_clcmp_get_points(npoints, x, y, b,retcnt);
	break;
	
    default:
	status = TB_UNKNOWN_DEVICE;
    }

return status;
}



/**************************************************************************

    ROUTINE: TBH_REQUEST_LOCATOR

    DESCRIPTION:
	This routine is designed to request a raw data point from tablet,
    it is similar with TBH_GET_POINTS, but it will wait until the user does
    digitize a point from digitizer.

    INPUT:
	NONE.
    
    OUTPUT:
	X   =(INT *) The returned x location.
	Y   =(INT *) The returned y location.
	B   =(int *) The button pressed by the user.

Julian Carlisle
********************************************************************** */
publicdef INT tbh_request_locator(x,y,b)
INT *x,*y,*b;
{
INT	status = SUCCESS,
	cnt = 0,
	tx,	    /* RAW TABLET X COORD	    */
	ty,	    /* and y			    */
	tb;	    /* button for this coord pair.  */


/* 
    Poll for XY input from tablet.  Wait for a coord unless
    severe problems arise, i.e. driver not initialized.
*/
    tbh_clear_buffer();
tb = 0;
while(cnt == 0)
    {
    status = tbh_get_points(1,&tx,&ty,&tb,&cnt);
    
    if (status == TB_NOT_INIT)
    break;
    }

if(cnt >= 1)
    {
    *x = tx;
    *y = ty;
    *b = tb;    
    }
else
    {
    *x = 0;
    *y = 0;
    *b = 0;    
    }

if (tb == WM_BUTTON_CANCEL)
    status = CANCEL;
    
return status;
}

/********************************************************************
*
*
* PROGRAM:	tbh_terminate
*
* DESCRIPTION:
*   This program turns kills the tablet driver by sending it an END packet.
*
* ARGUMENTS:
*			NONE
* RETURNS:
*			SUCCESS
*
*   Julian Carlisle   
*********************************************************************/
INT tbh_terminate()
{

INT  status = SUCCESS;
tbgbl.tablet_init = FALSE;
tbh_close_chan(tbgbl.tablet_channel);
return SUCCESS;
}
/********************************************************************
*
* PROGRAM:  TBH_INQ_TABLET
* DESCRIPTION:
*   Inquiry function to get various statisitics about the current
*   tablet (such as its min/max extents) or the current driver
*   state (such as whether or not it has been initialized).
*
* ARGUMENTS:
*   In:	    INT code	-   Type of inquiry.
*   Out:    (BYTE *)	-   data (type varies dep. on inq. type)
*
* RETURNS:
*   SUCCESS
*   Julian Carlisle     
*********************************************************************/
INT tbh_inq_tablet(code,result)
INT code;
BYTE *result;
{
INT status = SUCCESS;
INT *pint;
EXTENTS *pext;




switch(code)
    {
    case TB_INQ_INIT:
	pint = (INT *)result;
	if ( tbgbl.tablet_init == TRUE)
	    *pint = TRUE;
	else
	    *pint = FALSE;
	break;
	
    case TB_INQ_EXTENTS:
	pext = (EXTENTS *)result;
	switch(tbgbl.tablet_type)
	    {
	    case TB_GTCO_36X48_UGRID:
		pext->ul_x = 0.0;
		pext->ul_y = 35999.0;
		pext->ur_x = 47999.0;
		pext->ur_y = 35999.0;
		pext->ll_x = 0.0;
		pext->ll_y = 0.0;
		pext->lr_x = 47999.0;
		pext->lr_y = 0.0;
		break;
		
	    case TB_GTCO_11X11:
		pext->ul_x = 0.0;
		pext->ul_y = 10999.0;
		pext->ur_x = 10999.0;
		pext->ur_y = 10999.0;
		pext->ll_x = 0.0;
		pext->ll_y = 0.0;
		pext->lr_x = 10999.0;
		pext->lr_y = 0.0;
		break;
		
	    case TB_CALCOMP9100:
		pext->ul_x = 0.0;
		pext->ul_y = 35999.0;
		pext->ur_x = 47999.0;
		pext->ur_y = 35999.0;
		pext->ll_x = 0.0;
		pext->ll_y = 0.0;
		pext->lr_x = 47999.0;
		pext->lr_y = 0.0;
		break;
		
	    default:
		break;
	    }
	break;
    
    default:
	break;
    }
return SUCCESS;
}



/********************************************************************
*
* PROGRAM: tbh_bell 
*
* DESCRIPTION:
* 	This routine sounds a beep on the tablet if such an option
*	is available.  The number determines the beep generated.
*	On GTCO tablets, the bellnum can be 1-4 (low-high)
*	on Calcomp, the bellnum is limitied to 1. (All nums map to 1)
*
* ARGUMENTS:
*	INT	bellnum;
*
* RETURNS:
*   SUCCESS
*
*   Julian Carlisle     
*********************************************************************/
publicdef INT tbh_bell(bellnum)
INT bellnum;
{
static INT bellcodes[] = {TB_BELL_1,TB_BELL_2,TB_BELL_3,TB_BELL_4};

return tbh_do_cmd(tbgbl.tablet_channel,bellcodes[bellnum & 3]);
}

#endif
