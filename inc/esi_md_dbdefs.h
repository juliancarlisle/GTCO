/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MD_DBDEFS.H*/
/*  24   16-JAN-1992 14:10:09 JTM "(SPR 0) Generated after Don's Contour Annotation code added."*/
/* *23    7-JUN-1991 10:37:11 MING "(SPR 0) change  seismic time to seismic data"*/
/* *22   18-MAR-1991 17:18:06 PURNA "(SPR 0) Lease Mapping Init Checkin"*/
/* *21   11-MAR-1991 09:40:16 KEE "(SPR 5043) MAPPING USER INTERFACE MODIFIED"*/
/* *20   17-DEC-1990 16:24:51 PURNA "(SPR 6354) add source option in SEISMIC overlay"*/
/* *19   30-NOV-1990 15:20:49 PURNA "(SPR 6243) Fix bug on LINE LABEL ANNOTATION doesn't work for other SEISMIC overlay"*/
/* *18   19-NOV-1990 14:49:31 PURNA "(SPR 6171) add fault source option in grid display & perspective"*/
/* *17   15-OCT-1990 14:33:16 PURNA "(SPR 0) bring changes in ernie and add option in contours"*/
/*  13B2 13-OCT-1990 00:24:42 GILLESPIE "Updates from Ernie"*/
/* *16    4-OCT-1990 14:02:31 VINCE "(SPR 5043) MAPPING USER INTERFACE MODIFIED"*/
/* *15   29-SEP-1990 10:18:07 GILLESPIE "(SPR 1) Merge beta deltas"*/
/*  13B1 28-SEP-1990 17:59:18 GILLESPIE "Beta Deltas"*/
/* *14   27-AUG-1990 17:11:34 PURNA "(SPR 0) add lease overlay keywords, and seismic horiz term"*/
/* *13    6-JUL-1990 16:55:41 PURNA "(SPR 0) add lease overlay"*/
/* *12    3-JUN-1990 08:20:28 SCD "(SPR 5043) MAPPING USER INTERFACE MODIFIED"*/
/* *11   30-APR-1990 12:34:28 PURNA "(SPR 5275) remove line color option from perspective ovl"*/
/* *10   25-APR-1990 08:24:05 PURNA "(SPR 0) remove line_color option from co_overlay"*/
/* *9    27-MAR-1990 10:29:50 GILLESPIE "(SPR 5043) MAPPING USER INTERFACE MODIFIED"*/
/* *8     1-MAR-1990 12:41:25 PURNA "(SPR 5095) ADD OPTION TO CULTURE OVERLAY"*/
/* *7    23-FEB-1990 15:12:27 PURNA "(SPR 0) fix key_code"*/
/* *6    20-FEB-1990 17:58:56 PURNA "(SPR 0) fix prev mods"*/
/* *5    20-FEB-1990 10:28:11 PURNA "(SPR 5095) CULTURE OVERLAY"*/
/* *4    15-DEC-1989 10:32:30 CONROY "(SPR 5043) MAPPING USER INTERFACE MODIFIED"*/
/* *3    23-OCT-1989 10:34:42 CONROY "(SPR 5043) Mods for new MAPPING UI programmer tools"*/
/* *2    25-JUL-1989 19:27:07 GILLESPIE "(SPR 50) Seismic system revamp"*/
/* *1    30-JUN-1989 15:02:56 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MD_DBDEFS.H*/
/*  FILE_NAME: ESI_MD_DBDEFS.H                                            */
/*  DESCRIPTION:  File containing #define variables for the mapping basis */
/*                derived from ORACLE data base tables.                   */



#ifndef ESI_MD_DBDEFS_H
#define ESI_MD_DBDEFS_H 1



/* * INCLUDE FILES * */
/* ----------------- */

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif


/* * DEFINE SIZE CONSTANTS * */
/* ------------------------- */

#define MD_MAX_OVERLAY_TYPES 23
#define MD_MAX_KEYWORDS 466


/* * DEFINE VERB CODE CONSTANTS * */
/* ------------------------------ */

#define MP_CONTOURS 1
#define MP_GRA_OBJS 2
#define MP_GRAT 3
#define MP_GRID_DSP 4
#define MP_GRID_OPS 5
#define MP_LANDGRID 6
#define MP_SEISMIC 7
#define MP_SEISDPTH 8
#define MP_SEISCHRN 9
#define MP_SEISPACH 10
#define MP_MISTIE 11
#define MP_SEISDATA 12
#define MP_WELLDPTH 13
#define MP_WELLPACH 14
#define MP_WELLS 15
#define MP_XYZ_DSP 16
#define MP_PERSPEC 17
#define MP_SEIS3D 18
#define MP_TOPOGPHY 19
#define MP_LEASE 20
#define MP_DLS_GRID 21
#define MP_NTS_GRID 22
#define MP_PLOTFILE 23



/* * DEFINE VALIDATION CODE CONSTANTS * */
/* ------------------------------------ */

#define EXPR$ 1
#define FILER$ 2
#define FILEW$ 3
#define NUM$ 4
#define NLIST$ 5
#define ONAME$ 6
#define PLU$ 7
#define PLIST$ 8
#define SLE$ 9
#define SQL$ 10
#define TLU$ 11
#define TLIST$ 12
#define UOM$ 13
#define UOMD$ 14
#define UOMS$ 15
#define UDLG$ 16
#define TCP$ 17



#endif
/***************************************************************************/
