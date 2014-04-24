/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STDIO.H*/
/* *12   14-AUG-1990 12:05:41 GILLESPIE "(SPR 2001) Major include file change"*/
/* *11   12-MAR-1990 22:17:49 GILLESPIE "(SPR 6019) MPW and LSC changes needed after DECStation mods"*/
/* *10    4-MAR-1990 10:25:05 JULIAN "(SPR 6010) Fix ultrix compile errors. "*/
/* *9     1-MAR-1990 14:42:13 JULIAN "(SPR 6010) added prototypes for fopen etc. on ULTRIX side"*/
/* *8     1-MAR-1990 11:21:40 GILLESPIE "(SPR 6010) Add SYSTEM_FIVE definition to SUN to get sprintf to be int"*/
/* *7    28-FEB-1990 19:23:12 JULIAN "(SPR 6010) FIXUP ULTRIX SIDE."*/
/* *6    27-FEB-1990 09:10:16 GILLESPIE "(SPR 6010) Syntax corrections for Ultrix checkin"*/
/* *5    26-FEB-1990 19:07:40 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *4    24-SEP-1989 23:09:37 GILLESPIE "(SPR 103) Add LSC definitions - fix prototype for fseek"*/
/* *3    19-SEP-1989 14:15:03 JULIAN "added __FILE define"*/
/* *2    18-SEP-1989 16:49:33 JULIAN "(SPR 1) added __FILE define"*/
/* *1    30-JUN-1989 15:04:32 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_STDIO.H*/
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1990
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND
MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphics Systems, Inc.
			201 Tamal Vista Blvd
			Corte Madera, CA  USA 94925
			(415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#ifndef ESI_STDIO_H
#define ESI_STDIO_H 1

/*	STDIO - ANSI 'Standard I/O' Definitions 	 */

#ifndef ESI_STDDEF_H
#include "esi_stddef.h"
#endif

#if UNIX

typedef unsigned long fpos_t;

#ifdef mips

#define	BUFSIZ	1024
#define _N_STATIC_IOBS 3
#define	_NFILE	64   /* should equal NOFILE in /sys/h/param.h */
extern	struct	_iobuf {
	int	_cnt;
	char	*_ptr;
	char	*_base;
	int	_bufsiz;
	short	_flag;
	char	_file;
} _iob[_N_STATIC_IOBS];

#define	FILE	struct _iobuf
#define	stdin	(&_iob[0])
#define	stdout	(&_iob[1])
#define	stderr	(&_iob[2])

#define _IOFBF		00000
#define	_IOREAD		00001
#define	_IOWRT		00002
#define	_IONBF		00004
#define	_IOMYBUF	00010
#define	_IOEOF		00020
#define	_IOERR		00040
#define	_IOSTRG		00100
#define	_IOLBF		00200
#define	_IORW		00400
#define _IOAPPEND	01000
#define	EOF	(-1)

#define	getc(p)		(--(p)->_cnt>=0? *(p)->_ptr++&0377:_filbuf(p))
#define	getchar()	getc(stdin)
#define putc(x,p) (--(p)->_cnt>=0? ((int)(*(p)->_ptr++=(unsigned)(x))):_flsbuf((unsigned)(x),p))
#define	putchar(x)	putc(x,stdout)
#define	feof(p)		(((p)->_flag&_IOEOF)!=0)
#define	ferror(p)	(((p)->_flag&_IOERR)!=0)
#define	fileno(p)	((p)->_file)

#define L_ctermid	9
#define L_cuserid	9
#define P_tmpdir	"/usr/tmp/"
#define L_tmpnam	(sizeof(P_tmpdir)+15)

#endif  /* mips */

#ifdef sun

#ifndef SYSTEM_FIVE
#define SYSTEM_FIVE
#endif

#define	BUFSIZ	1024
#define _SBFSIZ	8
struct	_iobuf {
	int	_cnt;
	unsigned char *_ptr;
	unsigned char *_base;
	int	_bufsiz;
	short	_flag;
	char	_file;		/* should be short */
    } ;

typedef struct	_iobuf FILE;

extern FILE _iob[];

#define _IOFBF	0
#define	_IOREAD	01
#define	_IOWRT	02
#define	_IONBF	04
#define	_IOMYBUF	010
#define	_IOEOF	020
#define	_IOERR	040
#define	_IOSTRG	0100
#define	_IOLBF	0200
#define	_IORW	0400

#define	EOF	(-1)

#define	stdin	(&_iob[0])
#define	stdout	(&_iob[1])
#define	stderr	(&_iob[2])

#ifdef lint	/* so that lint likes (void)putc(a,b) */
extern int putc();
extern int getc();
#else
#define	getc(p)		(--(p)->_cnt>=0? ((int)*(p)->_ptr++):_filbuf(p))
#define putc(x, p)	(--(p)->_cnt >= 0 ?\
	(int)(*(p)->_ptr++ = (unsigned char)(x)) :\
	(((p)->_flag & _IOLBF) && -(p)->_cnt < (p)->_bufsiz ?\
		((*(p)->_ptr = (unsigned char)(x)) != '\n' ?\
			(int)(*(p)->_ptr++) :\
			_flsbuf(*(unsigned char *)(p)->_ptr, p)) :\
		_flsbuf((unsigned char)(x), p)))
#endif
#define	getchar()	getc(stdin)
#define	putchar(x)	putc((x),stdout)
#define	feof(p)		(((p)->_flag&_IOEOF)!=0)
#define	ferror(p)	(((p)->_flag&_IOERR)!=0)
#define	fileno(p)	((p)->_file)
#define	clearerr(p)	(void) ((p)->_flag &= ~(_IOERR|_IOEOF))

#define L_ctermid	(INT)9
#define L_cuserid	(INT)9
#define P_tmpdir	"/usr/tmp/"
#define L_tmpnam	(INT)(sizeof(P_tmpdir) + 15)

#endif	/* sun */

#ifdef THINK_C

typedef struct {
	unsigned		std : 1;
	unsigned		binary : 1;
	unsigned		eof : 1;
	unsigned		err : 1;
	unsigned		dirty : 1;
	unsigned		mybuf : 1;
	unsigned		append : 1;
	unsigned		delete : 1;
	unsigned		pushed : 1;
	char			one;
	unsigned char	pushc;
	short			refnum;
	char			*buf;
	size_t			size;
	unsigned char	*ptr;
	size_t			cnt;
	fpos_t			pos;
	fpos_t			len;
	void			*window;
	int			(*proc)();
} FILE;

#define _IOFBF			0
#define _IOLBF			1
#define _IONBF			2

#define BUFSIZ			512
#define EOF			(-1)
#define FOPEN_MAX		15

#define FILENAME_MAX	256
#define L_tmpnam		20
#define TMP_MAX			9999

#define stdin			(&__file[0])
#define stdout			(&__file[1])
#define stderr			(&__file[2])

extern FILE __file[FOPEN_MAX];

int __getc(FILE *);
int __putc(int, FILE *);

#define getc(fp)	((fp)->cnt-- ? (int) *(fp)->ptr++ : __getc(fp))
#define getchar()	getc(stdin)

#define putc(c, fp)	((fp)->cnt-- > 1 ? (int) (*(fp)->ptr++ = (c)) : __putc(c, fp))
#define putchar(c)	putc(c, stdout)

#define ferror(fp)	((int) (fp)->err)
#define feof(fp)	((int) (fp)->eof)

#endif  /* THINK_C */

#ifdef applec

/*
 *	The basic data structure for a stream is the FILE.
 */

typedef struct {
	int 			_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned char	*_end;
	unsigned short	_size;
	unsigned short	_flag;
	unsigned short	_file;
} FILE;


/*
 *	These macros give the meanings of bits in a FILE's _flag.  setvbuf() takes
 *	one of _IOFBF, _IOLBF, or _IONBF as its third argument.
 */

#define _IOFBF		0			/* Pseudo-flag, default buffering style */
#define _IOREAD 	(1<<0)		/* Current mode is for reading */
#define _IOWRT		(1<<1)		/* Current mode is for writing */
#define _IONBF		(1<<2)		/* no buffering */
#define _IOMYBUF	(1<<3)		/* buffer was allocated by stdio */
#define _IOEOF		(1<<4)
#define _IOERR		(1<<5)
#define _IOLBF		(1<<6)		/* fflush(iop) when a \n is written */
#define _IORW		(1<<7)		/* Enable read/write access */
#define _IOSYNC		(1<<8)		/* Input triggers fflush() to output fp's */
#define _IOBINARY	(1<<9)		/* Binary stream */


/*
 *	Default file buffer sizes used by setbuf() and setvbuf().
 */

#define BUFSIZ	1024			/* default file buffer size */
#define _LBFSIZ  100			/* Line buffer size */


/*
 *	The standard end-of-file indicator.
 */

#define EOF		(-1)


/*
 *	L_tmpnam is the size of char array long enough to hold a temporary file name
 *	generated by tmpnam(), including the trailing null byte.  The name is in the
 *	form tmp.AAAXXXXXX, where AAA is a sequence of lower case letters ("aaa", "baa",
 *	... "zzz" on successive calls), and XXXXXX is a lower case letter followed by a sequence
 *	of digits, all determined at runtime.
 *	TMP_MAX is the number of distinct file names that tmpnam() can generate.
 */

#define L_tmpnam	14
#define TMP_MAX		17576


/*
 *	The minimum number of files that a program is guaranteed to be able to have
 *	open simultaneously (including the pre-opened stdin, stdout, and stderr).
 *	The numbers are listed in Inside Macintosh, page IV-178, as:
 *	64K ROM, 128K Macintosh		12 files
 *	64K ROM, 512K Macintosh		40 files
 *	128K ROM					40 files per volume
 */

#define FOPEN_MAX	12


/*
 *	Maximum length of a file name, including a trailing zero byte.
 */

#define FILENAME_MAX	32


/*
 *	The standard predefined streams.
 */

#define stdin		(&_iob[0])
#define stdout		(&_iob[1])
#define stderr		(&_iob[2])

#define getc(p) 	(--(p)->_cnt >= 0 ? (int) *(p)->_ptr++ : _filbuf(p))
#define getchar()	getc(stdin)
#define putc(x, p)	(--(p)->_cnt >= 0 ? \
						((int) (*(p)->_ptr++ = (unsigned char) (x))) : \
						_flsbuf((unsigned char) (x), (p)))
#define putchar(x)	putc((x), stdout)
#define clearerr(p) ((void)((p)->_flag &= ~(_IOERR | _IOEOF)))
#define feof(p) 	((p)->_flag & _IOEOF)
#define ferror(p)	((p)->_flag & _IOERR)
#define _NFILE	  20
extern FILE _iob[_NFILE];
#define _bufend(p)	(p)->_end
#define _bufsiz(p)	(p)->_size
#define fileno(p)	(p)->_file

#endif	/* MPW */

#else

#ifdef vms

#define __FILE 1

#define _NFILE 20
#define BUFSIZ 512
#define _IOLBF 1
#define _IOFBF 2

	extern	struct	_iobuf 
		{
		int	_cnt;
		char	*_ptr;
		char	*_base;
		char	_flag;

#define	_IOREAD		0x01
#define	_IOWRT		0x02
#define	_IONBF		0x04
#define	_IOMYBUF	0x08
#define	_IOEOF		0x10
#define	_IOERR		0x20
#define	_IOSTRG		0x40
#define _IORW		0x80

		char	_file;

		};

typedef struct _iobuf *FILE;
typedef struct {unsigned : 32; unsigned : 32;} fpos_t;

#define OPEN_MAX 8
#define FOPEN_MAX 8
#define TMP_MAX  32

#define L_ctermid	(INT)64
#define L_cuserid	(INT)16
#define L_tmpnam	(INT)256
#define L_lcltmpnam	(INT)256
#define L_nettmpnam	(INT)256


extern 	FILE *stdin, *stdout, *stderr;

#define getc(p)		fgetc(p)
#define getchar()	fgetc(stdin)
#define putc(x,p)	fputc(x,p)
#define putchar(x)	fputc(x,stdout)
#define feof(p)		(((*p)->_flag&_IOEOF)!=0)
#define ferror(p)	(((*p)->_flag&_IOERR)!=0)
#define fileno(p)	((*p)->_file)
#define clearerr(p)	((*p)->_flag &= ~(_IOERR|_IOEOF))

#define FILE_TYPE	struct _iobuf *

#define	EOF		(-1)

#endif	    /* VMS */

#endif	    /* UNIX */

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#if USE_PROTOTYPES

extern int	fclose (FILE *file_ptr);
extern FILE	*fdopen (int file_desc, char *a_mode);
extern int	fflush (FILE *file_ptr);
extern int	fgetc (FILE *file_ptr);
extern int	fgetpos (FILE *file_ptr, fpos_t *position);
extern char	*fgets (char *str, int maxchar, FILE *file_ptr);
extern int	fputc (int character, FILE *file_ptr);
extern int	fputs (const char *str, FILE *file_ptr);
extern size_t	fread (void *ptr, size_t size_of_item, 
		size_t number_items, FILE *file_ptr);
extern int	fseek (FILE *file_ptr, long offset, int direction);
extern long	ftell (FILE *file_ptr);
extern size_t	fwrite (void *ptr, size_t size_of_item,
			 size_t number_items, FILE *file_ptr);
extern char	*gets  (char *str);
extern int	getw (FILE *file_ptr);
extern int	puts (char *str);
extern int	putw (int integer, FILE *file_ptr);
extern int	remove (char *filename);
extern int	rename (char *oldname, char *newname);
extern int	rewind (FILE *file_ptr);
extern void	setbuf (FILE *file_ptr, char *buffer);
extern int	setvbuf (FILE *file_ptr, char *buffer, int type, size_t size);
extern FILE	*tmpfile (void);
extern char	*tmpnam (char *name);
extern int	ungetc (int character, FILE *file_ptr);
extern int	vfprintf (FILE *file_ptr, const char *format, void *arg);
extern int	vprintf  (const char *format, void *arg);
extern int	vsprintf (char *s, const char *format, void *arg);

#ifdef mips
extern FILE	*fopen ();
extern int	fscanf ();
extern FILE	*freopen ();
extern int	printf  ();
extern int	scanf  ();
/* WATCH OUT !!! Berkeley wants sprintf to be char * !!! ARGHHH */
extern int	sprintf ();
extern int	sscanf ();
extern int	fprintf ();

#else
/* Version 2.1 does not support ellipsiseseses */
extern char	*fgetname (FILE *file_ptr, char *buffer, ...);
extern FILE	*fopen (const char *filespec, const char *a_mode, ...);
extern int	fscanf (FILE *file_ptr, const char *format_spec, ...);
extern FILE	*freopen (const char *file_spec, const char *a_mode,
		    FILE *file_ptr, ...);
extern int	printf  (const char *format_spec, ...);
extern int	scanf  (const char *format_spec, ...);
/* WATCH OUT !!! Berkeley wants sprintf to be char * !!! ARGHHH */
extern int	sprintf (char *str, const char *format_spec, ...);
extern int	sscanf (char *str, const char *format_spec, ...);
extern int	fprintf (FILE *file_ptr, const char *format_spec, ...);
#endif

#else

extern int	fclose ();
extern FILE	*fdopen ();
extern int	fflush ();
extern int	fgetc ();
extern char	*fgetname ();
extern int	fgetpos ();
extern char	*fgets ();
extern FILE	*fopen ();
extern int	fprintf ();
extern int	fputc ();
extern int	fputs ();
extern size_t	fread ();
extern FILE	*freopen ();
extern int	fscanf ();
extern int	fseek ();
extern int	fsetpos ();
extern long	ftell ();
extern size_t	fwrite ();
extern char	*gets  ();
extern int	getw ();
extern int	printf  ();
extern int	puts ();
extern int	putw ();
extern int	rewind ();
extern int	scanf  ();
extern void	setbuf ();
extern int	setvbuf ();
extern int	sscanf ();
extern FILE	*tmpfile ();
extern char	*tmpnam ();
extern int	ungetc ();
extern int	vfprintf ();
extern int	vprintf  ();
extern int	vsprintf ();

/* WATCH OUT !!! Berkeley wants sprintf to be char * !!! ARGHHH */
#ifndef SYSTEM_FIVE
extern char	*sprintf();
#else
extern int	sprintf();
#endif

#endif /* USE_PROTOTYPES */

#endif
