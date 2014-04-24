/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MD_DEFS.H*/
/* *4    14-AUG-1990 11:49:25 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *3    23-OCT-1989 10:34:53 CONROY "(SPR 5043) Mods for new MAPPING UI programmer tools"*/
/* *2    10-OCT-1989 14:17:25 GORDON "(SPR 4999) New lookup method mods"*/
/* *1    30-JUN-1989 15:02:59 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MD_DEFS.H*/
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

/* * FILE DESCRIPTION * */
/* -------------------- */
/* ************************************************************************

   NAME: esi_md_defs.h

   AUTHOR: JOHN CONROY

   DESCRIPTION: Include file containing definitions and declarations for
		Map Definitions.

   ************************************************************************ */

#ifndef ESI_MD_DEFS_H
#define ESI_MD_DEFS_H 1


/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/* * DEFINE SOME CONSTANTS * */
/* ------------------------- */

#define SEPARATOR ','
#define START_PARMS '='
#define OPEN_PAREN '('
#define CLOSE_PAREN ')'
#define NULL_VERB ((MD_VERB_STRUCT *) 0)
#define NULL_KEY ((MD_KEY_STRUCT *) 0)
#define NULL_PARM ((MD_PARM_STRUCT *) 0)
#define NULL_KEYLIST ((MD_KEYLIST *) 0)

#define MD_MAX_PARM_STRING 1000
#define SELECTOR_SIZE 21

#define MD_NAMED_OVERLAY (INT)1900
#define NO_EXCL ((INT *)0)

#define MD_VERB_LENGTH 26
#define MD_KEY_LENGTH 26
#define MD_ARG_LENGTH 62
#define MD_DEF_LENGTH 41


/* * DECLARE MAP DEF STRUCTURES * */
/* ------------------------------ */

typedef union {
	INT ival;
	DOUBLE dbval;
	CHAR *cval;
	} MD_PARMVAL_UNION;

typedef struct md_parm_struct 
    {
    INT parmtype;			/* 1 = STRING, 2 = INT, 3 = DOUBLE */
    MD_PARMVAL_UNION parmval;
    struct md_parm_struct *nxtparm;
    } MD_PARM_STRUCT;


typedef struct md_key_struct 
    {
    CHAR *keywrd;
    CHAR *realverb;
    BOOL valid;
    BOOL chk_exclude;
    struct md_key_struct *nxtkey;
    struct md_parm_struct *parmptr;
    } MD_KEY_STRUCT;


typedef struct md_verb_struct 
    {
    CHAR *overlay;
    CHAR *verb;
    struct md_key_struct *keyptr;
    } MD_VERB_STRUCT;


typedef struct md_keylist 
    {
    CHAR verb[26];
    CHAR keyword[26];
    CHAR key_rqd;
    CHAR parm_rqd;
    CHAR exclude;
    CHAR val_code[26];
    CHAR val_arg[62];
    CHAR tran_flg;
    CHAR key_dflt[41];
    CHAR parm_dflt[41];
    CHAR state_var[33];
    struct md_keylist *nxtkey;
    } MD_KEYLIST;


/* * THE FOLLOWING IS FOR THE NEW (1988) MAPPING INTERFACE * */

typedef struct 
    {
    INT nrows;
    INT *key_code;
    INT *key_used;		/* 0=NOT USED, 1=USER DEFINED, 2=DEFAULT */
    MD_PARM_STRUCT **parm_ptr;
    } MD_COMPILED_VERB;


typedef struct 
    {
    INT nrows;
    INT last_row_used;
    BYTE **picks;
    INT *verb_code;
    INT *overlay_wm_id;
    INT *wm_arr_ndx;
    INT *verb_wm_id;
    MD_COMPILED_VERB **verb_ptr;
    } MD_COMPILED_MAPDEF;

typedef CHAR MD_DSP_VERB [MD_VERB_LENGTH];
typedef CHAR MD_DSP_KEY [MD_KEY_LENGTH];

typedef struct 
    {
    INT nrows;
    INT last_row_used;
    MD_DSP_VERB *verbs;
    MD_DSP_KEY *keywords;
    TCP parameters;
    INT *verb_ndx;
    INT *key_ndx;
    INT *compiled_row;
    BOOL *overlay_displayed;
    } MD_DISPLAY;


typedef struct
    {
    INT  key_code;
    CHAR keyword[MD_KEY_LENGTH];
    BOOL key_req;
    BOOL parm_req;
    INT  *exclusion_array;
    INT  val_code;
    CHAR val_arg[MD_ARG_LENGTH];
    BOOL translate;
    CHAR key_default[MD_DEF_LENGTH];
    } MD_KEY_INFO;

typedef struct 
    {
    INT verb_code;
    CHAR verb[MD_VERB_LENGTH];
    INT no_of_keywords;
    TCP key_tcp;
    INT obj_id;
    MD_KEY_INFO *key_list;
    } MD_VERB_INFO;

typedef struct
    {
    BOOL verb_pending;
    BOOL button_status[6];
    INT crnt_select_verb;
    INT crnt_pref_verb_start;
    INT crnt_pref_verb_end;
    INT active_verb_ndx;
    INT active_key_ndx;
    INT last_key_obj;
    INT last_parm_obj;
    INT no_of_parameters;
    CHAR keyword[28];
    TCP parm_list;
    INT crnt_pref_key_parm;
    } MD_STATE_WORKSPACE;


/* * FUNCTIONS * */
/* ------------- */

#if USE_PROTOTYPES
extern INT	md_alt(MD_PARM_STRUCT *parmstruc, MD_KEY_STRUCT *keystruc);
extern INT	md_date(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_dlu(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_duom(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_expr(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern BYTE	*md_find_key(CHAR *phrase, INT *status);
extern BYTE	*md_find_parm(CHAR *parm_list, INT *status);
extern INT	md_fne(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_free_parms(MD_PARM_STRUCT *parmstruc);
extern INT	md_free_structs(MD_VERB_STRUCT *verbstruc);
extern INT	md_lfn(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_litho(MD_PARM_STRUCT *parmstruc);
extern CHAR	*md_next_delim(CHAR *phrase, INT *status);
extern INT	md_num(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_parm_value(CHAR *parm, INT *parm_type, MD_PARMVAL_UNION *parm_value);
extern BYTE	*md_parse_ovrly(CHAR *sentence, INT *status);
extern INT	md_plu(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_seis_fault(MD_PARM_STRUCT *parmstruc);
extern INT	md_seis_hor(MD_PARM_STRUCT *parmstruc);
extern INT	md_sle(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_sql(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_subr(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_tlu(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_uom(MD_PARM_STRUCT *parmstruc, MD_KEYLIST *keylist);
extern INT	md_verify_fne(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_lfn(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_num(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_numlist(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_oname(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_plist(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_plu(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_sle(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_sql(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_tlist(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_tlu(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_uom(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_uomd(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_verify_uoms(MD_KEY_INFO *key_info, CHAR *parm_string,
	    MD_PARM_STRUCT **parmstruc);
extern INT	md_vld_1key(MD_KEY_STRUCT *keystruc);
extern INT	md_vld_parm(MD_KEY_STRUCT *keystruc, MD_KEYLIST *keylist);
#else
extern INT	md_alt();
extern INT	md_date();
extern INT	md_dlu();
extern INT	md_duom();
extern INT	md_expr();
extern BYTE	*md_find_key();
extern BYTE	*md_find_parm();
extern INT	md_fne();
extern INT	md_free_parms();
extern INT	md_free_structs();
extern INT	md_lfn();
extern INT	md_litho();
extern CHAR	*md_next_delim();
extern INT	md_num();
extern INT	md_parm_value();
extern BYTE	*md_parse_ovrly();
extern INT	md_plu();
extern INT	md_seis_fault();
extern INT	md_seis_hor();
extern INT	md_sle();
extern INT	md_sql();
extern INT	md_subr();
extern INT	md_tlu();
extern INT	md_uom();
extern INT	md_verify_fne();
extern INT	md_verify_lfn();
extern INT	md_verify_num();
extern INT	md_verify_numlist();
extern INT	md_verify_oname();
extern INT	md_verify_plist();
extern INT	md_verify_plu();
extern INT	md_verify_sle();
extern INT	md_verify_sql();
extern INT	md_verify_tlist();
extern INT	md_verify_tlu();
extern INT	md_verify_uom();
extern INT	md_verify_uomd();
extern INT	md_verify_uoms();
extern INT	md_vld_1key();
extern INT	md_vld_parm();
#endif

#endif
/******************************************************************************/
