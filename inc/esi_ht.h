/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HT.H*/
/* *3    14-AUG-1990 11:48:23 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *2    21-NOV-1989 10:04:07 CONROY "(SPR 5059) Add new key type HT_BYTE_KEY"*/
/* *1    30-JUN-1989 15:01:45 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_HT.H*/
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

/******************************************************************************

    Include file for the hash table toolkit

******************************************************************************/

#ifndef ESI_HT_H
#define ESI_HT_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

/*  trace compile switch */
#define HT_TRACE   0


/*  Defines  */

#define HT_APPLICATION_TABLE (INT)000
#define HT_SYSTEM_TABLE      (INT)001

#define HT_INT_KEY    (INT)7001
#define HT_FLOAT_KEY  (INT)7002
#define HT_DOUBLE_KEY (INT)7003
#define HT_CHAR_KEY   (INT)7004
#define HT_PTR_KEY    (INT)7005
#define HT_BYTE_KEY   (INT)7006

#define HT_CHECK_CODE (INT)123987

/*   trace file */



/*  Bucket definition  */

typedef struct hash_bucket
        {
        UINT no_of_keys;
        struct hash_bucket *next_bucket;
        BYTE *bucket;
        } HASH_BUCKET;

/*  Table definition  */

typedef struct
        {
        INT ht_check_field;
        UINT user_no_of_buckets;
        UINT actual_no_of_buckets;
        UINT bucket_size;
        INT key_type;
        size_t key_length;
        size_t data_length;
        INT flag;
        UINT current_key_count;
        HASH_BUCKET *bucket_array;
        } HASH_TABLE;


typedef HASH_TABLE  *HASH_TABLE_P;

typedef BYTE        *BYTE_P;

#if USE_PROTOTYPES

extern INT ht_check_for_key(HASH_TABLE_P hash_table, VOIDPTR key, INT address,
		HASH_BUCKET  **found_bucket, HASH_BUCKET  **prev_bucket, 
		UINT *keyno);
extern INT ht_clear_table(HASH_TABLE  *hash_table);
extern INT ht_count_keys(HASH_TABLE_P hash_table, UINT *nkeys);
extern INT ht_delete(HASH_TABLE_P hash_table, VOIDPTR key);
extern INT ht_find(HASH_TABLE_P hash_table, VOIDPTR key, VOIDPTR data);
extern INT ht_free_table(HASH_TABLE_P *hash_table);
extern INT ht_get_all(HASH_TABLE_P hash_table, UINT *nkeys, VOIDPTR *keys_out,
		VOIDPTR *data_out);
extern INT ht_hash_code(VOIDPTR key, INT key_type, size_t key_length, 
		UINT table_length, INT *hash_code);
extern INT ht_init_hash_table(UINT no_of_buckets, UINT bucket_size,
	INT key_type, size_t key_length, size_t data_length, INT flag, 
		HASH_TABLE_P  *hash_table);
extern INT ht_insert(HASH_TABLE_P hash_table, VOIDPTR key, VOIDPTR data);
extern INT ht_rand(INT i, INT j);
extern INT ht_update(HASH_TABLE_P hash_table, VOIDPTR key, VOIDPTR data);

extern VOIDPTR htz_zalloc(size_t nbytes,INT flag);

#else

extern INT ht_check_for_key();
extern INT ht_clear_table();
extern INT ht_count_keys();
extern INT ht_delete();
extern INT ht_find();
extern INT ht_free_table();
extern INT ht_get_all();
extern INT ht_hash_code();
extern INT ht_init_hash_table();
extern INT ht_insert();
extern INT ht_rand();
extern INT ht_update();
extern VOIDPTR htz_zalloc();

#endif

#endif
