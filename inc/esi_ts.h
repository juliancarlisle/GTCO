/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TS.H*/
/*  15    9-MAR-1992 16:23:49 JILL "(SPR 0) fix prototype for ts_separate"*/
/*  14    4-MAR-1992 11:51:22 JANTINA "(SPR 0) added #include esi_ct.h"*/
/*  13    3-MAR-1992 07:58:06 JILL "(SPR 0) Update for new routines and new protos"*/
/* *12    3-APR-1991 14:44:23 KEE "(SPR -1) Change ts_???_CHAR to ts_???_char"*/
/* *11   18-MAR-1991 17:18:15 PURNA "(SPR 0) Lease Mapping Init Checkin"*/
/* *10   25-OCT-1990 12:12:40 GILLESPIE "(SPR 31) Lint run - correct some casting inconsistencies"*/
/* *9    12-JUL-1990 15:03:10 GILLESPIE "(SPR 3) Change publicdef to extern"*/
/* *8    22-MAY-1990 15:11:41 VINCE "(SPR 1) added prototypes for new routines"*/
/* *7    18-MAY-1990 17:58:02 VINCE "(SPR 1) Added some new prototypes"*/
/* *6    26-FEB-1990 19:07:53 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *5     6-FEB-1990 15:44:09 WALTERS "(SPR 0) Change ts_tcp_copy prototype"*/
/* *4    24-SEP-1989 22:54:29 GILLESPIE "(SPR 200) Gulf mods"*/
/* *3    15-JUL-1989 17:07:26 GILLESPIE "(SPR 44) Add new string test macros"*/
/* *2    30-JUN-1989 15:48:30 GILLESPIE "(SPR -2) SCD mods"*/
/* *1    30-JUN-1989 15:05:13 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_TS.H*/
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

#ifndef ESI_TS_H
#define ESI_TS_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

/*  Use these macros instead of (strlen(s) > 0) or (strlen(s) == 0)                 */

#define IS_STRING(s) ((CHAR *)(s)!=(CHAR *)0 && *(CHAR *)(s)!=0)
#define IS_EMPTY_STRING(s) ((CHAR *)(s)==(CHAR *)0 || *(CHAR *)(s)==0)
#define ARE_DIFFERENT(s1,s2) ((*(CHAR *)(s1)!=*(CHAR *)(s2))||strcmp((CHAR *)(s1),(CHAR *)(s2))!=0)
        
#define ARE_SAME(s1,s2) ((*(CHAR *)(s1)==*(CHAR *)(s2))&&strcmp((CHAR *)(s1),(CHAR *)(s2))==0)


#if USE_PROTOTYPES
extern CHAR *ts_convert_char (CHAR *string, INT oldchar, INT newchar);
extern INT ts_copy_substring (CHAR *out_string, CHAR *start_ptr, CHAR *end_ptr);
extern CHAR *ts_fill (CHAR *text, INT fill_char, INT ntimes);
extern CHAR *ts_find_char (CHAR *string, CHAR c);
extern INT ts_find_substring (CHAR *string, CHAR *substring, TCP pos);
extern CHAR *ts_fortran_to_c (CHAR *string);
extern CHAR *ts_insert (CHAR *subject, CHAR *insert);
extern INT ts_isfloat (CHAR *x);
extern BOOL ts_like (CHAR *string, CHAR *pattern, INT wildcard);
extern TCP ts_make_tcp (CHAR *string, INT nitems);
extern CHAR *ts_next_token (CHAR *line, CHAR *token, CHAR terminator);
extern CHAR *ts_next_word (CHAR *line, CHAR *token);
extern CHAR *ts_noblanks (CHAR *text);
extern CHAR *ts_pack_strings (INT num_strings, TCP string_pointers);
extern CHAR *ts_quote (CHAR *string, CHAR quote_char);
extern CHAR *ts_search (CHAR *subject, CHAR *search, BOOL match_case);
extern CHAR *ts_shift (CHAR *subject, INT shift_size);
extern CHAR *ts_snowhite (CHAR *string);
extern CHAR *ts_standard_name (CHAR *string);
extern CHAR *ts_sto_lower (CHAR *string);
extern CHAR *ts_sto_upper (CHAR *string);
extern void ts_str_alpha(CHAR *string, CHAR **field_ptrs, INT *field_lengths,
			INT *field_types, INT *nfields);
extern INT ts_str_fill(CHAR *image, CHAR *fill_char, INT nchars);
extern INT ts_str_trim(char	*string);
extern INT ts_str_word(CHAR *image, CHAR **word_ptrs, INT *word_lengths,
			INT *nwords);
extern INT ts_strn_trim(char	*string, INT  n);
extern INT ts_str_convert (CHAR *string, INT str_len, INT search_char,
                           INT replace_char);
extern INT ts_strcmpi (CHAR *master, CHAR *pattern);
extern INT ts_strncmpi (CHAR *master, CHAR *pattern, INT cmplen);
extern CHAR *ts_subs (CHAR *subject, CHAR *search, CHAR *replace, BOOL iflag);
extern INT ts_sub_substring (CHAR *string, CHAR *find, CHAR *replace);
extern INT ts_switch (CHAR *string, TCP tcp);
extern TCP ts_tcp_alloc (INT len);
extern INT ts_tcp_and (TCP table1, TCP table2, TCP *table3);
extern TCP ts_tcp_append (TCP *tcp, CHAR *string);
extern TCP ts_tcp_copy (TCP *to, TCP from);
extern INT ts_tcp_delete (TCP tcp, INT idx);
extern INT ts_tcp_free (TCP strings);
extern INT ts_tcp_from_table (CHAR *table_name, CHAR *column_name, TCP *row_list,
                              INT *no_rows);
extern INT ts_tcp_len (TCP strings);
extern INT ts_tcp_sort (TCP tcp);
extern TCP ts_token(CHAR *string,CHAR *delimeter);
extern INT ts_trim (CHAR *string);
extern UINT ts_uniq_num (void);

#else
extern CHAR *ts_convert_char ();
extern CHAR *ts_cpystr ();
extern CHAR *ts_fill ();
extern CHAR *ts_find_char ();
extern CHAR *ts_fortran_to_c ();
extern CHAR *ts_insert ();
extern CHAR *ts_next_token ();
extern CHAR *ts_next_word ();
extern CHAR *ts_noblanks ();
extern CHAR *ts_pack_strings ();
extern CHAR *ts_quote ();
extern CHAR *ts_search ();
extern CHAR *ts_shift ();
extern CHAR *ts_snowhite ();
extern CHAR *ts_standard_name ();
extern void ts_str_alpha();
extern INT ts_str_fill();
extern INT ts_str_trim();
extern INT ts_str_word();
extern INT ts_strn_trim();
extern CHAR *ts_sto_lower ();
extern CHAR *ts_sto_upper ();
extern CHAR *ts_subs ();
extern INT ts_copy_substring ();
extern INT ts_find_substring ();
extern INT ts_isfloat ();
extern BOOL ts_like ();
extern TCP ts_make_tcp ();
extern INT ts_str_convert ();
extern INT ts_strcmpi ();
extern INT ts_strncmpi ();
extern INT ts_sub_substring ();
extern INT ts_switch ();
extern TCP ts_tcp_alloc ();
extern INT ts_tcp_and ();
extern TCP ts_tcp_append ();
extern TCP ts_tcp_copy ();
extern INT ts_tcp_delete ();
extern INT ts_tcp_free ();
extern INT ts_tcp_from_table ();
extern INT ts_tcp_len ();
extern INT ts_tcp_sort ();
extern TCP ts_token();
extern INT ts_trim ();
extern UINT ts_uniq_num ();

#endif
#endif                                                                          
