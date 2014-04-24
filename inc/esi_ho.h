/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO.H*/
/* *12    3-JAN-1991 17:26:24 GILLESPIE "(SPR 6347) Add ho_get_environment"*/
/* *11   29-SEP-1990 10:18:02 GILLESPIE "(SPR 1) Merge beta deltas"*/
/*  8B1  28-SEP-1990 17:57:42 GILLESPIE "Beta Deltas"*/
/* *10   27-AUG-1990 14:53:27 VINCE "(SPR 1) added declaration of ho_translate_path"*/
/* *9    14-AUG-1990 11:48:13 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *8    12-FEB-1990 12:36:04 MING "(SPR 0) add internal routine hoz_cv_date.c"*/
/* *7     8-FEB-1990 11:47:06 WALTERS "(SPR 0) Add prototype for ho_get_current_path"*/
/* *6     5-FEB-1990 18:42:24 GILLESPIE "(SPR 6002) Change DATE to char[12]; add DATE_TIME and TCP"*/
/* *5    18-DEC-1989 16:48:51 PURNA "(SPR 5069) export facility mods"*/
/* *4    31-OCT-1989 11:54:10 GILLESPIE "(SPR 30) Remove extraneous includes in includes"*/
/* *3    24-SEP-1989 22:59:11 GILLESPIE "(SPR 101) Rearrangement of a few calls; add extern keyword"*/
/* *2    14-SEP-1989 16:42:06 GORDON "(SPR 100) Gulf/Sun/Unix changes"*/
/* *1    30-JUN-1989 15:01:26 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Finder Graphics Systems, Inc. 1990                      */
/*         Unpublished -- All rights reserved                                       */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND   */
/*MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE  */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*          Exploration Systems, Inc.                                               */
/*          c/o Finder Graphics Systems, Inc.                                       */
/*          201 Tamal Vista Blvd                                                    */
/*          Corte Madera, CA  USA 94925                                             */
/*          (415) 927-0100                                                          */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_HO_H
#define ESI_HO_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifdef primos
#include "esi_ho_primos.h"
#endif

#if USE_PROTOTYPES

#ifdef THINK_C
pascal void BlockMove (VOIDPTR sourcePtr, VOIDPTR destPtr, long byteCount);
#define hoblockmove(from,to,nbytes) \
 BlockMove((VOIDPTR)(from),(VOIDPTR)(to),(long)(nbytes));

#else

#ifdef applec
pascal void BlockMove (VOIDPTR sourcePtr, VOIDPTR destPtr, long byteCount);
#define hoblockmove(from,to,nbytes) \
 BlockMove((VOIDPTR)(from),(VOIDPTR)(to),(long)(nbytes));
#else
extern INT hoblockmove (VOIDPTR from, VOIDPTR to, size_t nbytes);
#endif
#endif

extern INT hobsend (INT program_channel, UINT length, VOIDPTR buffer);
extern INT hoclosio (INT program_channel);
extern INT hogets (VOIDPTR linein);
extern INT hoopenio (INT *program_channel_ptr, CHAR *device_name);
extern INT hoputs (VOIDPTR lineout, UINT slen);
extern void hoz_cv_date (DATE_TIME, CHAR *);
extern DOUBLE ho_cpu_time (void);
extern INT ho_ctime (char *time_string);
extern CHAR *ho_date_tag (CHAR *buffer);
extern INT ho_dump (CHAR *reportfile);
extern INT ho_get_channel_type (INT channel, INT *type, INT *efn);
extern INT ho_get_environment (CHAR environment[16]);
extern INT ho_get_os_info (CHAR os_info[8]);
extern CHAR *ho_get_current_path (CHAR *buff);
extern DOUBLE ho_io_time (void);
extern INT ho_set_logical_list (CHAR *logical_table, CHAR *logical_name, TCP tcp);
extern INT ho_set_logical_name (CHAR *logical_table, CHAR *logical_name, CHAR *value,
                                INT conceal, BOOL set_process);
extern INT ho_spawn (INT type, CHAR *filename, CHAR *args, INT *user);
extern INT ho_syscom (CHAR *string);
extern INT ho_syscom_nw (CHAR *string, BOOL wait_flag);
extern CHAR *ho_terminal (CHAR *name);
extern INT ho_translate_path (char *in, char *out);
extern INT ho_translate_symbol (CHAR *symbol, TCP *ptcp);
extern CHAR *ho_user_name (char *string);
extern INT ho_user_mode (void);
extern INT ho_user_number (void);

#else

extern INT hoblockmove ();          /* high speed memory to memory copy             */
extern INT hobsend ();
extern INT hoclosio ();
extern INT hogets ();               /* get string from terminal                     */
extern INT hoopenio ();
extern INT hoputs ();               /* write string to terminal                     */
extern void hoz_cv_date ();         /* internal routine to change the format of date*/
extern DOUBLE ho_cpu_time ();       /* returns cpu time                             */
extern INT ho_ctime ();             /* return current date time string, like ctime  */
extern CHAR *ho_date_tag ();        /* returns date/time character string           */
extern INT ho_dump ();              /* dump stack                                   */
extern INT ho_get_channel_type ();
extern INT ho_get_environment ();   /* fetch character string of OS environment name */
extern INT ho_get_os_info ();
extern CHAR *ho_get_current_path ();
extern DOUBLE ho_io_time ();        /* returns io time                              */
extern INT ho_set_logical_list ();  /* set a logical name translating to a list     */
extern INT ho_set_logical_name ();  /* set a logical name with a single translation */
extern INT ho_spawn ();             /* Spawn a phantom or a batch job               */
extern INT ho_syscom ();            /* execute a system command; returns error code */
extern CHAR *ho_terminal ();        /* return name of terminal                      */
extern INT ho_translate_path ();
extern INT ho_translate_symbol ();  /* translate a global symbol                    */
extern INT ho_user_mode ();         /* returns the current user mode HO_BATCH/HO_INTERACTIVE   */
extern INT ho_user_number ();       /* returns the current user number as an INT    */
extern CHAR *ho_user_name ();       /* returns pointer to user name                 */

#endif

/* define user types for ho_spawn                                                   */
#define SPAWN_PHANTOM 0 /* spawn a Phantom type user (immediate execution)*/
#define SPAWN_BATCH 1 /* spawn a Batch type user with a log */
#define SPAWN_BATCH_NOLOG 2 /* starts a batch job without a log */

/* define user modes for HO_USER_MODE                                               */
#define HO_INTERACTIVE 0 /* current process is an interactive terminal */
#define HO_BATCH 1 /* current process is a batch job */

#endif
