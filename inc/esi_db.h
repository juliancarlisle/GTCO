/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DB.H*/
/*  13    9-MAR-1992 09:50:55 LOEBL "(SPR 6056) Alter calling sequence to dba_delete_account"*/
/*  12   21-NOV-1991 09:17:07 LOEBL "(SPR 0) Convert to sqlforms30 on VMS"*/
/* *11   19-SEP-1991 15:44:19 LOEBL "(SPR 4126) Include sqlforms version number"*/
/* *10    4-JAN-1991 17:12:38 PURNA "(SPR 6091) add the -L option to add new logical names and create new directories"*/
/* *9    14-AUG-1990 11:46:52 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *8    30-MAR-1990 16:43:43 GILLESPIE "(SPR 1) Remove form flag from db_table_storage"*/
/* *7    14-OCT-1989 15:58:01 VINCE "(SPR -1) mods for new update schem"*/
/* *6    22-SEP-1989 17:03:19 VINCE "(SPR -1) changed calling sequence of db_table_storage"*/
/* *5    19-SEP-1989 12:00:23 GILLESPIE "(SPR 102) add externs"*/
/* *4    14-SEP-1989 16:41:57 GORDON "(SPR 100) Gulf/Sun/Unix changes"*/
/* *3    11-AUG-1989 13:36:56 CONROY "(SPR 9999) Add prototypes for new routines for ORACLE V6"*/
/* *2    11-AUG-1989 12:50:02 CONROY "(SPR 9999) Mods for ORACLE V6 tablespace and storage parameters"*/
/* *1    30-JUN-1989 15:00:05 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DB.H*/
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

#ifndef ESI_DB_H
#define ESI_DB_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

enum create_funcs
    {
    CREATE_ACCOUNT = 1,
    MAKE_TABLES,
    MAKE_VIEWS,
    MAKE_INDEXES,
    CHECK_EXISTING_TABLES,
    GRANT_PRIVILEGES,
    MAKE_LOGICALS,
    MAKE_FORMS,
    COPY_DEFAULT_DATA,
    REVIEW_PROJECTIONS,
    REVIEW_DEFAULTS,
    REVIEW_GEO_INDEXES,
    RESTORE_SAVESET,
    RESTORE_EXPORT,
    DROP_EXISTING_INDEXES,
    DROP_EXISTING_VIEWS
    };

typedef struct
    {
    CHAR name[62];              /* account name */
    ORACLE_NAME password;       /* account password */
    ORACLE_NAME database;       /* Name of current Oracle "database" */
    CHAR scope[8];		/* text of account scope type */
    struct
        {
	BOOL analyst;
	BOOL project;
	BOOL code;
	BOOL system;
	} account_scope;        /* booleans indicating all applicable scopes */
    struct
        {
	BOOL flag;
	CHAR name[62];
	ORACLE_NAME password;
	ORACLE_NAME database;
	} dba;                  /* dba account name/password */
    enum create_funcs create_functions[20];
    } DB_ACCOUNT_STRUCT;


/* control flags for account creation */

typedef struct {
    BOOL create_tables;
    BOOL create_indexes;
    BOOL create_views;
    BOOL create_constraints;
    BOOL create_sequences;
    BOOL create_synonyms;
    BOOL grant_privileges;
} DB_CREATE_FLAGS;


#if USE_PROTOTYPES
extern INT db_create_bootstrap_tables	(DB_ACCOUNT_STRUCT *db_account);
extern INT db_move_bootstraps		(DB_ACCOUNT_STRUCT *db_account);
extern INT db_create_tablespaces	(DB_ACCOUNT_STRUCT *db_account);
extern INT db_table_storage		(DB_ACCOUNT_STRUCT *db_account,
						BOOL load);
extern INT db_move_table		(CHAR *table, CHAR *type);
extern INT db_get_storage_string	(CHAR *table, CHAR *type,
						CHAR *string);
extern INT db_copy_default_project	(DB_ACCOUNT_STRUCT *db_account);
extern INT db_create_table		(DB_ACCOUNT_STRUCT *db_account,
						CHAR *table_name);
extern INT db_dba_func			(CHAR *not_used);
extern INT db_upd_mapping		(DB_ACCOUNT_STRUCT *db_struct);
extern INT dba_archive_account		(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_create_directories	(DB_ACCOUNT_STRUCT *db_account,
						BOOL interactive);
extern INT dba_create_account		(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_delete_account		(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_grant_public_privileges	(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_grant_privileges		(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_restore_account		(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_update_account		(DB_ACCOUNT_STRUCT *db_account,
						DB_CREATE_FLAGS *create_flags);
extern INT dba_update_indexes		(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_update_tables		(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_update_1_table		(DB_ACCOUNT_STRUCT *db_account,
						CHAR *table_name);
extern INT dba_update_views		(DB_ACCOUNT_STRUCT *db_account);
extern INT dba_validate_account		(DB_ACCOUNT_STRUCT *db_account,
						DB_CREATE_FLAGS *create_flags);
#else
extern INT db_create_bootstrap_tables();
extern INT db_move_bootstraps();
extern INT db_create_tablespaces();
extern INT db_table_storage();
extern INT db_move_table();
extern INT db_get_storage_string();
extern INT db_copy_default_project();
extern INT db_create_table();
extern INT db_dba_func();
extern INT db_upd_mapping();
extern INT dba_archive_account();
extern INT dba_create_directories();
extern INT dba_create_account();
extern INT dba_delete_account();
extern INT dba_grant_public_privileges();
extern INT dba_grant_privileges();
extern INT dba_restore_account();
extern INT dba_update_account();
extern INT dba_update_indexes();
extern INT dba_update_tables();
extern INT dba_update_1_table();
extern INT dba_update_views();
extern INT dba_validate_account();
#endif

#endif

/* define Oracle SQL*FORMS version in use */

#ifdef vms
#define SQLFORMS30 FALSE
#endif

#if UNIX
#define SQLFORMS30 FALSE
#endif

