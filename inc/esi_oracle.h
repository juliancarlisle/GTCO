/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ORACLE.H*/
/* *2    26-APR-1991 11:49:01 LOEBL "(SPR 0) Added definition of MAX_FETCH"*/
/* *1    30-JUN-1989 15:03:31 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_ORACLE.H*/
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

#ifndef ESI_ORACLE_H
#define ESI_ORACLE_H 1

#ifndef ESI_GL_VCHAR_H
#include "esi_gl_vchar.h"
#endif

/* SQL stmt #1
EXEC SQL INCLUDE SQLCA.H;
*/
/* Copyright (c) 1985,1986 by Oracle Corporation. */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.
 
MODIFIED
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ long    sqlabc;
         /* b4  */ long    sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ long    sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };
 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
 
#endif
 
/* end SQLCA */

/***************************  ESI-DEFINED VALUES  *****************************/

#define OR_EOF (INT)1403
#define OR_ABORT (INT)-1013
#define OR_STATUS sqlca.sqlcode
#define OR_MESSAGE sqlca.sqlerrm.sqlerrmc
#define OR_ROWCOUNT sqlca.sqlerrd[2]
#define MAX_FETCH  32767

#if USE_PROTOTYPES
extern INT or_login(INT argc, CHAR **argv);
extern INT or_logout(BOOL commit_flag);
#else
extern INT or_login();
extern INT or_logout();
#endif

#endif
