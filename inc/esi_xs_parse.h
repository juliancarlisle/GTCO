/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XS_PARSE.H */
/* *2     2-NOV-1989 12:02:32 GILLESPIE "(SPR 31) Initial release" */
/* *1     2-NOV-1989 12:02:06 GILLESPIE "Contains defs required to parse xs definition" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_XS_PARSE.H */
#ifndef ESI_XS_PARSE_H
#define ESI_XS_PARSE_H 1

#ifndef ESI_XS_DEFS_H
#include "esi_xs_defs.h"
#endif

#ifndef ESI_MD_DEFS_H
#include "esi_md_defs.h"
#endif

#if USE_PROTOTYPES

extern INT xsz_fill_data(CHAR *verb, MD_VERB_STRUCT *verbptr, XS_STRUCT *xsptr,
			 INT init);
extern INT xsz_fill_linterval(MD_KEY_STRUCT *keyStr, XS_STRUCT *pxs);
extern INT xsz_fill_lh(MD_KEY_STRUCT *keyptr, XS_STRUCT *xsptr);
extern INT xsz_fill_ls(MD_KEY_STRUCT *keyptr, XS_STRUCT *xsptr);
extern INT xsz_fill_lsb(MD_KEY_STRUCT *keyptr, XS_STRUCT *xsptr);
extern INT xsz_fill_lws(MD_KEY_STRUCT *keyptr, XS_STRUCT *xsptr);
extern INT xsz_fill_ltop(MD_KEY_STRUCT *keyStr, INT init, INT talloc,
			 INT insert,XS_STRUCT *pxs);
extern INT xsz_fill_ltrace(MD_KEY_STRUCT *keyStr, INT init, INT talloc,
			   INT insert, XS_STRUCT *pxs);
extern INT xsz_fill_ltrack(MD_KEY_STRUCT *keyStr, INT init, INT talloc,
			   INT insert, XS_STRUCT *pxs);
extern INT xsz_fill_xs(MD_KEY_STRUCT *keyptr, XS_STRUCT *xsptr);
extern INT xsz_get_parms(MD_KEY_STRUCT *keyStr, MD_PARM_STRUCT *parmStr,
			 INT ith, BYTE *variable, INT *status) ;
extern INT xsz_vld_ovrly(MD_VERB_STRUCT *verbstruc);

#else

extern INT xsz_fill_data();
extern INT xsz_fill_linterval();
extern INT xsz_fill_lh();
extern INT xsz_fill_ls();
extern INT xsz_fill_lsb();
extern INT xsz_fill_lws();
extern INT xsz_fill_ltop();
extern INT xsz_fill_ltrace();
extern INT xsz_fill_ltrack();
extern INT xsz_fill_xs();
extern INT xsz_get_parms() ;
extern INT xsz_vld_ovrly();

#endif
#endif
