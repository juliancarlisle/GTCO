/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_LIB.H*/
/* *2    14-AUG-1990 11:48:20 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:01:40 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_LIB.H*/
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

#ifndef ESI_HO_LIB_H
#define ESI_HO_LIB_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/*       
    LIB$  RTL Subroutine Declarations.
    ----------------------------------
*/
extern INT  lib$get_lun ();	/* get a free logical unit		*/
extern INT  lib$get_ef  ();	/* get an event flag cluster		*/
extern INT  lib$len     ();	/* Returns the length of a char string	*/
extern INT  lib$locc    ();	/* Locates pos of char inside a string	*/
extern INT  lib$sys_trnlog ();	/* translate logical using strnlog 	*/
extern INT  lib$sys_asctim ();	/* convert time from bin to asc string	*/
extern INT  lib$sys_fao ();	/* create str from numeric & char input	*/
extern INT  lib$wait    ();	/* make proc HIB for spec'd len of time	*/
extern VOID lib$index   ();	/* loc 1st pos of substring in a string	*/
extern VOID lib$movc3   ();	/* Move count bytes from src to dest	*/
extern VOID lib$movc5   ();	/* Move count bytes with fill char	*/
extern VOID lib$signal  ();	/* raise exception & exit image		*/
extern VOID lib$stop    ();	/* Stop execution & signal condition  	*/

/*       
    SYS$  System services  Declarations.
    ------------------------------------
*/
extern INT   sys$alloc   ();	/* Allocate and I/O Channel for process */
extern INT   sys$asctim  ();	/* convert binary time into ascii format*/
extern INT   sys$assign  ();	/* Assign channel/device to a handle	*/
extern INT   sys$bintim  ();	/* convert time from ascii to binary 	*/
extern INT   sys$canwak  ();	/* cancel process wake up time		*/
extern INT   sys$clref   ();	/* clear an event flag cluster		*/
extern INT   sys$create  ();	/* Create file	         		*/
extern INT   sys$crelnm  ();	/* Create logical name   		*/
extern INT   sys$crembx  ();	/* create mail box      		*/
extern INT   sys$crmpsc  ();	/* create shared global section		*/
extern INT   sys$dalloc  ();	/* Deallocate a device  		*/
extern INT   sys$dassgn  ();	/* deassign an I/O chan/mailbox		*/
extern INT   sys$dellnm  ();	/* delete a LOGICAL name     		*/
extern INT   sys$delmbx  ();	/* delete a mailbox     		*/
extern INT   sys$delprc  ();	/* delete a process     		*/
extern INT   sys$forcex  ();	/* force a process to exit 		*/
extern INT   sys$getdvi  ();	/* get device info    	     ASYNCH	*/
extern INT   sys$getjpi  ();	/* Get process & image info  ASYNCH	*/
extern INT   sys$getdviw ();	/* get device info    	      SYNCH	*/
extern INT   sys$getjpiw ();	/* Get process & image info   SYNCH	*/
extern INT   sys$getmsg  ();	/* Get VMS msg string for status value	*/
extern INT   sys$getsyi  ();	/* Get system stats & info ASYNCH	*/
extern INT   sys$getsyiw ();	/* Get system stats & info  SYNCH	*/
extern INT   sys$gettim  ();	/* Return system time in binary format	*/
extern INT   sys$hiber   ();	/* set proc to LEF/HIB state (inactive)	*/ 
extern INT   sys$mgblsc  ();	/* map global section file		*/
extern INT   sys$putmsg  ();	/* Sends a msg assoc w/status to proc 	*/
extern INT   sys$qio	  ();	/* SYS asynch I/O command  ASYNCH	*/
extern INT   sys$qiow    ();	/* SYS synch I/O command    SYNCH	*/
extern INT   sys$schdwk  ();	/* Set process wake up time		*/
extern INT   sys$setast  ();	/* Enable/Disable AST delivery		*/
extern INT   sys$setprn  ();	/* Change the name of the process	*/
extern INT   sys$setef   ();	/* set an event flag  cluster		*/
extern INT   sys$synch   ();	/* wait for asynch cmd to end		*/
extern INT   sys$trnlnm  ();	/* Translate logical name 		*/
extern INT   sys$waitfr  ();	/* wait for en event flag 		*/
extern INT   sys$wake    ();	/* wake up a process slept by $HIBER	*/

/*
    STR$  Facility Declarations.
    ----------------------------
*/
extern INT   str$append  ();	/* Append one string onto another 	*/
extern INT   str$trim    ();	/* Trim the garbage off ends of string	*/
extern INT   str$upcase  ();	/* Convert a string to upper case 	*/


       
	             
#endif
