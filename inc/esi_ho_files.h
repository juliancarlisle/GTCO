/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_FILES.H*/
/* *8    14-AUG-1991 11:45:51 KEE "(SPR -1) Put in File Lock/Unlock logic"*/
/* *7     9-NOV-1990 10:31:02 MING "(SPR -1) replace ho_find_files.c and ho_find_files2 to ho_find_pathnames and*/
/*ho_find_filenames"*/
/* *6    14-AUG-1990 11:48:17 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *5    26-FEB-1990 19:07:05 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *4    24-SEP-1989 22:59:48 GILLESPIE "(SPR 200) New n-List mods Version 4"*/
/* *3    21-SEP-1989 17:09:08 GILLESPIE "(SPR 101) Add new prototypes; add LSC and MPW support"*/
/* *2     5-SEP-1989 11:37:01 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *1    30-JUN-1989 15:01:31 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HO_FILES.H*/

/*	*****************************************************************************

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

#ifndef ESI_HO_FILES_H
#define ESI_HO_FILES_H 1

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#if USE_PROTOTYPES

extern INT hofcopy(FILENAME oldpath, FILENAME newpath, INT nq);/* copies a file */
extern INT ho_absolute_path(PATHNAME path);      /*  turns an incomplete path into a legal directory */
extern INT ho_add_path(CHAR *logical, CHAR *filename, size_t maxchars,
		CHAR *full_filename);
extern INT ho_assemble_pathname (FILENAME filename, PATHNAME pathname, ENTRYNAME entryname);
extern INT ho_change_protection(FILENAME filename, INT mode);
extern INT ho_chk_fname(FILENAME name, INT length);	/* checks that string is well formed file name  */
extern INT ho_create_directory(PATHNAME directory_spec);
extern INT ho_delete_directory(PATHNAME directory_spec);
extern INT ho_delete_file(FILENAME file, INT *status);
extern INT hoexists(FILENAME pathname);/* test for file existence */
extern INT ho_find_filenames(FILENAME file_spec, TCP *tcp);
extern INT ho_find_pathnames(FILENAME file_spec, TCP *tcp);
extern INT ho_get_date(FILENAME filename, UINT *file_size, CHAR *create_date,
	    CHAR *mod_date);
extern INT ho_get_unique_filename(FILENAME name);	/* generate a well formed file spec  */
extern INT ho_lgl_fname(FILENAME name);		/* checks that string is well formed file spec  */
extern INT ho_query_offset_length(FILENAME s, UINT *offset, UINT *data_len);
extern INT ho_query_files(FILENAME dir, UINT *return_files, TCP *existing_files,
		INT ftype);
extern FILE *ho_open(FILENAME file_name, CHAR *mode, CHAR *share_mode);
extern INT ho_read(FILE *funit, VOIDPTR record, UINT length);
extern INT ho_rename(FILENAME old_name, FILENAME new_name);
extern INT ho_split_pathname(FILENAME filename, PATHNAME pathname, ENTRYNAME entryname);
extern INT ho_translate_filename(FILENAME from, FILENAME to);
extern INT ho_write (FILE *funit, VOIDPTR record, UINT length);
extern INT ho_lock (FILE *file_ptr, INT onoroff);
		
#else	    /* NO PROTOTYPES */

extern INT hofcopy();
extern INT ho_absolute_path();      /*  turns an incomplete path into a legal directory */
extern INT ho_add_path();
extern INT ho_assemble_pathname ();
extern INT ho_change_protection();
extern INT ho_chk_fname();
extern INT ho_create_directory();
extern INT ho_delete_directory();
extern INT ho_delete_file();
extern INT hoexists();
extern INT ho_find_filenames();
extern INT ho_find_pathnames();
extern INT ho_get_date();
extern INT ho_get_unique_filename();
extern INT ho_lgl_fname();
extern INT ho_query_offset_length();
extern INT ho_query_files();
extern FILE *ho_open  ();
extern INT ho_read  ();
extern INT ho_rename();
extern INT ho_split_pathname();
extern INT ho_translate_filename();
extern INT ho_write ();
extern INT ho_lock ();

#endif	    /* of #if USE_PROTOTYPES */

#endif
