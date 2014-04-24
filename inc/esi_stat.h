/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STAT.H*/
/* *5    30-OCT-1990 12:55:02 GILLESPIE "(SPR 37) Fix for sun"*/
/* *4    13-JUN-1990 22:53:11 JULIAN "(SPR -1) Fixed include error on SUN."*/
/* *3     4-MAR-1990 10:24:54 JULIAN "(SPR 6010) Fix ultrix compile errors. "*/
/* *2    26-FEB-1990 19:07:34 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *1    30-JUN-1989 15:04:27 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STAT.H*/
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

/*
* stat - include file for use with stat/fstat UNIX emulation functions
*/
#ifndef ESI_STAT_H
#define ESI_STAT_H

#if UNIX

#ifdef sun
#include <sys/types.h>
#include <sys/stat.h>
#endif

#else

typedef unsigned off_t;
typedef unsigned short ino_t;
typedef char *dev_t;
struct  stat
{
        dev_t   st_dev;		/* pointer to physical device name */
        ino_t   st_ino[3];	/* 3 words to receive fid */
        unsigned short st_mode;	/* file "mode" i.e. prot, dir, reg, etc. */
        int	st_nlink;	/* for compatibility - not really used */
        unsigned st_uid;	/* from ACP - QIO uic field */
        unsigned short st_gid;	/* group number extracted from st_uid */
        dev_t   st_rdev;	/* for compatibility - always zero */
        off_t   st_size;	/* file size in bytes */
        unsigned st_atime;	/* file access time; always same as st_mtime */
        unsigned st_mtime;	/* last modification time */
        unsigned st_ctime;	/* file creation time */
	char	st_fab_rfm;	/* record format */
	char	st_fab_rat;	/* record attributes */
	char	st_fab_fsz;	/* fixed header size */
	unsigned st_fab_mrs;	/* record size */
};

typedef struct stat stat_t; 

#define S_IFMT   (INT)0170000         /* type of file */
#define          S_IFDIR (INT)0040000 /* directory */
#define          S_IFCHR (INT)0020000 /* character special */
#define          S_IFBLK (INT)0060000 /* block special */
#define          S_IFREG (INT)0100000 /* regular */
#define          S_IFMPC (INT)0030000 /* multiplexed char special */
#define          S_IFMPB (INT)0070000 /* multiplexed block special */
#define S_ISUID  (INT)0004000         /* set user id on execution */
#define S_ISGID  (INT)0002000         /* set group id on execution */
#define S_ISVTX  (INT)0001000         /* save swapped text even after use */
#define S_IREAD  (INT)0000400         /* read permission, owner */
#define S_IWRITE (INT)0000200         /* write permission, owner */
#define S_IEXEC  (INT)0000100         /* execute/search permission, owner */

#endif


#endif
