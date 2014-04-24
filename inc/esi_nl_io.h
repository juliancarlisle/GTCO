/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL_IO.H*/
/* *14   25-OCT-1990 12:12:34 GILLESPIE "(SPR 31) Lint run - correct some casting inconsistencies"*/
/* *13   14-AUG-1990 11:50:03 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *12   12-MAR-1990 22:17:38 GILLESPIE "(SPR 6019) MPW and LSC changes needed after DECStation mods"*/
/* *11   28-FEB-1990 06:07:44 GILLESPIE "(SPR 1) move SUN4 definition outside of UNIX define"*/
/* *10   28-FEB-1990 05:28:26 GILLESPIE "(SPR 6010) Fix up ULTRIXR change by defining SUN4 to be zero if not defined"*/
/* *9    26-FEB-1990 19:07:29 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *8    12-FEB-1990 09:25:22 GORDON "(SPR 0) Remove reference to HOST_VERSION"*/
/* *7     5-FEB-1990 18:42:36 GILLESPIE "(SPR 6002) Change DATE to char[12]; add DATE_TIME and TCP"*/
/* *6     6-DEC-1989 11:16:30 GORDON "(SPR 0) Remove erroneous defs of nlz_free_locks"*/
/* *5    24-SEP-1989 23:03:20 GILLESPIE "(SPR 200) New n-List Version 4"*/
/* *4    19-SEP-1989 10:28:16 GORDON "(SPR 100) (JGG) make NL_FILE_TYPE a typedef"*/
/* *3    15-SEP-1989 13:43:26 GORDON "(SPR 100) Many changes for Unix port"*/
/* *2    25-JUL-1989 16:40:39 GORDON "(SPR 100) redo macros, SUN4 version of expansion"*/
/* *1    30-JUN-1989 15:03:26 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_NL_IO.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Exploration Systems, Inc. 1989                          */
/*                    Unpublished -- All rights reserved                            */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY   */
/*CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE      */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*                            Exploration Systems                                   */
/*                            c/o Finder Graphics Systems                           */
/*                            201 Tamal Vista Blvd.                                 */
/*                            Corte Madera, CA  94925                               */
/*                            (415) 927-0100                                        */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_NL_IO_H

#define ESI_NL_IO_H 1

#ifndef ESI_NL_INT_H

#include "esi_nl_int.h"

#endif

#ifndef ESI_DTYPES_H

#include "esi_dtypes.h"

#endif

#ifndef ESI_C_LIB_H

#include "esi_c_lib.h"

#endif

#ifndef ESI_HT_H

#include "esi_ht.h"

#endif

#ifndef SUN4

#define SUN4 0

#endif

/************************************************************************************/
/*             BEGIN HOST-DEPENDENT DEFINITIONS                                     */
/************************************************************************************/

#if UNIX
typedef FILE *FILE_UNIT;

#define REWIND(funit) fseek((FILE *)(funit), (long)0, SEEK_SET)
#define NL_CLOSE(funit) fclose((FILE *)(funit))
#define nlz_close(funit) fclose((FILE *)(funit))
#define nlh_read(funit, buffer, nbytes) \
    ho_read((FILE *)(funit), (VOIDPTR)(buffer), (UINT)(nbytes))
        
#define nlh_seek(funit, file_offset, direc) \
    fseek((FILE *)(funit), (long)(file_offset), (int)(direc))

#define nlh_write(funit, buffer, nbytes) \
    fwrite((char *)(buffer), (size_t)(nbytes), (size_t)1, (FILE *)(funit))

#define NL_MAX_INDEX 20      /* the maximum index structure of ids stored in memory */
#define NL_DEFAULT_ENTRY_IN_BLOCK 20 /* number of entries in directory block */

#else

#ifdef vms
typedef enum 
    {
    RMS = 1, UNIXIO
    } NL_FILE_TYPE;

#include "fab.h"
#include "rab.h"
typedef struct 
    {
    struct RAB *fid;
    NL_FILE_TYPE type;
    } FILE_STRUCT, *FILE_UNIT;

#define REWIND(funit) nlh_seek((funit), (INT)0, (INT)SEEK_SET)
#define NL_CLOSE(funit) nlz_close((funit))

#if USE_PROTOTYPES
extern INT nlh_read (FILE_UNIT funit, VOIDPTR buffer, size_t length);
extern INT nlh_seek (FILE_UNIT funit, INT offset, INT direc);
extern INT nlh_write (FILE_UNIT funit, VOIDPTR buffer, size_t length);
extern INT nlz_close (FILE_UNIT funit);

#else
extern INT nlh_read ();
extern INT nlh_seek ();
extern INT nlh_write ();
extern INT nlz_close ();

#endif

#define NL_MAX_INDEX 20      /* the maximum index structure of ids stored in memory */
#define NL_DEFAULT_ENTRY_IN_BLOCK 20 /* number of entries in directory block */

#endif      /* end of VMS */

#ifdef primos

#define NL_MAX_INDEX 10      /* the maximum index structure of ids stored in memory */
#define NL_DEFAULT_ENTRY_IN_BLOCK 10 /* number of entries in directory block */
#define REWIND(funit) fseek((funit)->fid, 0, SEEK_SET)
/* position to EOF, then close                                                      */
#define NL_CLOSE(funit) fseek((funit)->fid, 0, SEEK_END), fclose((funit)->fid)
typedef FILE *FILE_UNIT;

#endif      /* End of Primos */
#endif      /* End of host-dependent bank */

/************************************************************************************/
/*               END HOST-DEPENDENT DEFINITIONS                                     */
/************************************************************************************/

/* Implementation shorthand:                                                        */
/*    Several routines worry about moving an even number of bytes around.           */
/*    If the length is found to be odd, one extra byte is moved                     */
/*    and if even, then two extra bytes are moved.                                  */
/*                                                                                  */
/*    The code could be written (if len & 1) {add 1 } else {add 2},                 */
/*    which is equivalent to value += (2 - ((len) & 1))                             */
/*                                                                                  */
/*    The macro ROUND_UP returns 1 if n is odd, 2 if even                           */
/*                                                                                  */

#define ROUND_UP(n) (2 - ((n) & 1))
#define NL_FILE_MARK (INT)43016
typedef struct                      /* logical record data I/O data structure       */
    {
    UINT offset;                    /* byte offset in file, ABSOLUTE                */
    UINT next_offset;               /* byte offset to extension record, ABSOLUTE    */
    UINT first_offset;              /* first byte offset in extended record, ABSOLUTE   */
    size_t total_bytes;             /* total number of bytes in extended data record*/
    size_t bytes;                   /* number of bytes in this data record          */
    } NLIST_LOGICAL_RECORD;

typedef struct 
    {
    UINT next_write_offset;         /* byte offset to EOF                           */
    UINT bytes_deleted;             /* number of bytes deleted in file              */
    INT file_mark;                  /* file mark                                    */
    UINT directory_offset;          /* byte offset (ABSOLUTE) to directory          */
    UINT f_directory_offset;        /* byte offset (ABSOLUTE) to file directory     */
    CHAR version_stamp[4];          /* file version stamp                           */
    CHAR os_info[8];                /* operating system / file info (see below):    */
    /*                                                                              */
    /*    os_info[0] - CHAR_TYPE  (0 = ASCII; 1 = EBCDIC; 2 = ASCII w/high bit on)  */
    /*    os_info[1] - INT_TYPE   (0 = big-endian; 1 = little-endian)               */
    /*    os_info[2] - FLOAT_TYPE (Floating point format: 0 = VAX; 1 = IEEE)        */
    /*    os_info[3] - PTR_SIZE;  (size of a pointer, in bytes)                     */
    /*    os_info[4] - CHAR_SIZE  (1 = byte-oriented; 2 = word oriented)            */
    /*    os_info[5] - UNUSED                                                       */
    /*    os_info[6] - UNUSED                                                       */
    /*    os_info[7] - UNUSED                                                       */
    /*                                                                              */
    UINT total_nlists;              /* total number of active n-Lists in file       */
    CHAR modified_date[14];         /* date this file last modified                 */
    UINT file_user_struct_offset;   /* offset of user structure of file.            */
    UINT deleted_record_offset;
#ifdef sun
    BYTE expansion[4];              /* to keep it under the magical 64 limit!       */
#else

#ifdef mips
    BYTE expansion[4];              /* to keep it under the magical 64 limit!       */
#else
    BYTE expansion[6];              /* expansion space - reserved -                 */
#endif
#endif
    } NLIST_CONTROL_RECORD;

typedef struct 
    {
    UINT offset;                    /* the offset of data of requested nlist id;    */
    UINT directory_offset;          /* the offset of directory of requested nlist id*/
    INT delete;                     /* the flag of deleting.                        */
    } NL_INDEX_DATA;

/* The following modes apply to file sharing:                                       */
/*    SHARE - open for reads - othr processes can write                             */
/*    NOSHARE - open for readonly - no other processes can access/modify file       */
/*    WRITE - open for write - other users can read                                 */
/*    WRITE_NOSHARE - open for write - disallow access to others                    */
/*                                                                                  */
typedef enum 
    {
    SHARE, NOSHARE, WRITE, WRITE_NOSHARE
    } NL_SHARE_MODE;
typedef BYTE DIRECTORY_ENTRY[162];

typedef struct 
    {
    FILENAME filename;              /* name of n-List file                          */
    FILE_UNIT funit;                /* assigned file unit                           */
    UINT accesses;                  /* number of accesses to this file              */
    NL_SHARE_MODE share_mode;       /* share mode this file was opened in           */
    DATE_TIME modified_date;        /* date/time this file last modified            */
    HASH_TABLE_P idIndex;           /* hash table for this file                     */
    NLIST_CONTROL_RECORD control_record;    /* copy of control record from file     */
    } NL_FILE_DATA;

#define ENCODE_DATA(ptr, dataCodePtr, dataSizePtr) {\
hoblockmove( (VOIDPTR)dataCodePtr, (VOIDPTR)ptr, (size_t)sizeof(INT));\
ptr += sizeof(INT);\
hoblockmove( (VOIDPTR)dataSizePtr, (VOIDPTR)ptr, (size_t)sizeof(INT));\
ptr += sizeof(INT);}
        
#define DECODE_DATA( ptr, dataCodePtr, dataSizePtr ) {\
hoblockmove( (VOIDPTR)ptr, (VOIDPTR)dataCodePtr, (size_t)sizeof(INT) );\
ptr += sizeof(INT);\
hoblockmove( (VOIDPTR)ptr, (VOIDPTR)dataSizePtr, (size_t)sizeof(INT) );\
ptr += sizeof(INT); }


#if USE_PROTOTYPES
extern INT nlh_close (FILE_UNIT funit);
extern INT nlh_open (FILE_UNIT *file_unit, FILENAME filename, NL_SHARE_MODE share_mode,
                     UINT *allocated);
extern INT nlz_build_nlist_table (FILENAME filename, UINT *totalNlists,
                                  TCP *nlistTable, NL_SHARE_MODE share_mode,
                                  FILE_UNIT *funit);
extern INT nlz_chk_exist_index (FILENAME filename, HASH_TABLE_P *bTreePtr,
                                NL_SHARE_MODE share_mode, FILE_UNIT *funit);
extern INT nlz_chk_nlist_exist (FILENAME filename, NLIST_ID name, FILE_UNIT *pfunit,
                                BOOL directory, NL_SHARE_MODE share_mode);
extern INT nlz_construct_nlist (NLIST_HEADER *nlist_ptr, VOIDPTR headerArray,
                                size_t headerArraySize);
extern INT nlz_construct_Table (NLIST_HEADER nlist, TABLE_ELEMENT *table_element,
                                VOIDPTR headerArray, size_t headerArraySize);
extern INT nlz_delete_index (UINT target);
extern INT nlz_get_control_record (FILE_UNIT funit, NLIST_CONTROL_RECORD **pcontrol);
extern INT nlz_get_directories (FILE_UNIT funit, UINT first_offset,
                                DIRECTORY_ENTRY **dirs, UINT *total_dirs);
extern INT nlz_get_file_data (FILE_UNIT funit, NL_FILE_DATA **dataptr);
extern INT nlz_get_read_funit (FILENAME filename, FILE_UNIT *funit);
extern INT nlz_get_record (FILE_UNIT funit, UINT first_offset, VOIDPTR *record,
                           UINT *length, BOOL only_one);
extern INT nlz_get_target (FILENAME filename);
extern INT nlz_init_ctrl (FILENAME filename, FILE_UNIT funit,
                          NL_SHARE_MODE share_mode);
extern INT nlz_link_deleted_record (FILE_UNIT funit, UINT deleted_offset,
                                    NLIST_CONTROL_RECORD *control_record);
extern INT nlz_put_control_record (void);
extern INT nlz_put_directories (FILE_UNIT funit, size_t length, VOIDPTR record,
                                NLIST_CONTROL_RECORD *control_record);
extern INT nlz_put_record (FILE_UNIT funit, UINT first_offset, size_t length,
                           VOIDPTR record, NLIST_CONTROL_RECORD *control_record);
extern INT nlz_rename_index_file (FILENAME old_file_name, FILENAME new_file_name);
extern INT nlz_set_block_entries (INT nblocks);
extern INT nlz_update_index (FILENAME filename, NLIST_ID nlist_id,
                             UINT directory_offset, UINT offset);
extern INT nlz_update_index_item (FILENAME filename, NLIST_ID nlist_id);
extern INT nlz_update_record (FILE_UNIT funit, UINT exist_offset, UINT length,
                              BYTE *record, NLIST_CONTROL_RECORD *control_record);

#else
extern INT nlh_close ();
extern INT nlh_open ();
extern INT nlz_build_nlist_table ();
extern INT nlz_chk_exist_index ();
extern INT nlz_chk_nlist_exist ();
extern INT nlz_construct_nlist ();
extern INT nlz_construct_Table ();
extern INT nlz_delete_index ();
extern INT nlz_get_control_record ();
extern INT nlz_get_directories ();
extern INT nlz_get_file_data ();
extern INT nlz_get_read_funit ();
extern INT nlz_get_record ();
extern INT nlz_get_target ();
extern INT nlz_init_ctrl ();
extern INT nlz_link_deleted_record ();
extern INT nlz_put_control_record ();
extern INT nlz_put_directories ();
extern INT nlz_put_record ();
extern INT nlz_rename_index_file ();
extern INT nlz_set_block_entries ();
extern INT nlz_update_index ();
extern INT nlz_update_index_item ();
extern INT nlz_update_record ();

#endif
#endif
