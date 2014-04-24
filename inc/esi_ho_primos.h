/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_PRIMOS.H*/
/* *2    14-AUG-1990 12:05:11 GILLESPIE "(SPR 2001) Major include file change"*/
/* *1    30-JUN-1989 15:01:43 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_PRIMOS.H*/
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

#ifndef ESI_HO_PRIMOS_H
#define ESI_HO_PRIMOS_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* This file contains PRIMOS host specific definitions */

#ifdef primos

BYTE	*hobuildptr();		/* create a pointer given Segment / offset      */
CHAR	*hosyserrmess();	/* return a message for an os error code        */
INT	ho_finder_admin();	/* returns SUCCESS if user is privilaged        */
INT	ho_spawn_phantom();	/* spawns a background task for the DB server   */
INT	ho_sem_count();		/* returns the current count of a semaphore     */
INT	ho_sem_drain();		/* clear the given semaphore                    */
INT	ho_sem_notify();	/* send a notify to the given semaphore         */
INT	ho_sem_wait();		/* wait on a given semaphore                    */
INT	ho_logout_user();	/* log out a user                               */
INT	ho_user_exists();	/* 1 = user exists; 0 = not there               */

#define HO_LOCAL_SYMBOL (INT)1001
#define HO_GLOBAL_SYMBOL (INT)1002

#define ho_user_terminal           (INT)0
#define ho_dma_device              (INT)1
#define ho_async_line              (INT)3
#define HO_MAX_DEVICE_TYPE         (INT)4

char *ho_device_name[HO_MAX_DEVICE_TYPE]
              = { "TTY-(user terminal)", "DMA", "UNDEFINED", "ASYNC" }   ;

/* Begin definition of control information for asynchronous lines */

typedef struct
{  unsigned baud_rate     : 3 ;
   unsigned stop_bits_2   : 1 ;
   unsigned even_parity   : 1 ;
   unsigned enable_parity : 1 ;
   unsigned wait_on_read  : 1 ;
} ASYNC_FLAGS ;

typedef union
{  INT         word ;
   ASYNC_FLAGS async ;
} HO_CONTROL ;

#define baud_110   (INT)0
#define baud_134   (INT)1
#define baud_300   (INT)2
#define baud_1200  (INT)3
#define baud_2400  (INT)4
#define baud_4800  (INT)5
#define baud_9600  (INT)6
#define baud_19200 (INT)7

/* End of async control flag definition */

/* DEFINE the keys for the T$GPPI (fortran) subroutine */

#define READ_BLOCK         (INT)1
#define WRITE_BLOCK        (INT)2
#define READ_WORD          (INT)3
#define WRITE_WORD         (INT)4
#define WAIT_FOR_INTERRUPT (INT)5
#define DEVICE_DEP_OTA     (INT)8
#define RESET_DMA          (INT)9
#define LOAD_DEVICE_TIMEOUT (INT)10
#endif

#endif
