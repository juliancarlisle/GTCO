/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_TOBIN.H*/
/* *1    30-JUN-1989 15:02:04 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_TOBIN.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_ld_tobin.h,v 1.1 89/05/30 15:34:08 esi Exp $ esi_ld_tobin.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_TOBIN.H*/
/* *6    12-APR-1989 18:02:28 JRB "Fix bad character in copyright notice"*/
/* *5    10-APR-1989 12:26:16 GILLESPIE "(SPR 24) Remove some (INT) casts"*/
/* *4     8-APR-1989 00:31:33 GILLESPIE "Add copyright, (INT) castings"*/
/* *3    17-DEC-1988 09:31:40 GILLESPIE "(SPR 4981) Unisource"*/
/* *2    17-JUL-1987 15:00:18 GILLESPIE "Upper case conversion of types"*/
/* *1     7-JUL-1987 10:45:50 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LD_TOBIN.H*/
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


#ifndef ESI_LD_TOBIN_H
#define ESI_LD_TOBIN_H 1

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#define TOBIN_LAND_REC_SIZE   82

#define HEADER_TYPE '0'
#define LABEL_TYPE  '2'
#define POINT_TYPE  '3'

#define NAME_TYPE_0 '0'
#define NAME_TYPE_1 '1'
#define NAME_TYPE_2 '2'
#define NAME_TYPE_3 '3'
#define NAME_TYPE_4 '4'
#define NAME_TYPE_5 '5'
#define NAME_TYPE_6 '6'

#define END_OF_POLY '9'

#define TEXAS_STATE_CODE	(INT)42
#define TEXAS_ZONE_CONSTANT	(INT)6
#define LOUISIANA_STATE_CODE	(INT)99
#define LOUISIANA_ZONE_CONSTANT	(INT)3

#define MAX_DEFINED_LEVELS 32

   struct extents_ {
      INT    init;
      DOUBLE xmin;
      DOUBLE ymin;
      DOUBLE xmax;
      DOUBLE ymax;
   } extents ;


   /*  *********************************************************** */
   /*  Starting positions and lengths within			   */
   /*  TOBIN record formats					   */
   /*  *********************************************************** */
#define RECORD_TYPE$	(INT)0
#define RECORD_TYPE_	(INT)1
   /*  **********************************************************  */
   /*  type 0  (Header)                                            */
#define LLEVEL$		(INT)1
#define LLEVEL_		(INT)2
#define NAME_FMT$	(INT)3
#define NAME_FMT_	(INT)1
#define NAME$		(INT)4
#define NAME_		(INT)19
#define REVISION_DATE$	(INT)32
#define REVISION_DATE_	(INT)6
#define SOURCE$		(INT)38
#define SOURCE_		(INT)1
#define RANGE_BOX$	(INT)39
#define RANGE_BOX_	(INT)30
#define RANGE_SW$	(INT)39
#define RANGE_SW_	(INT)15
#define RANGE_SW_LAT$	(INT)39
#define RANGE_SW_LAT_	(INT)7
#define RANGE_SW_LON$	(INT)46
#define RANGE_SW_LON_	(INT)8
#define RANGE_NE$	(INT)54
#define RANGE_NE_	(INT)15
#define RANGE_NE_LAT$	(INT)54
#define RANGE_NE_LAT_   (INT)7
#define RANGE_NE_LON$	(INT)61
#define RANGE_NE_LON_	(INT)8
#define CONVERSION$	(INT)69
#define CONVERSION_	(INT)4
#define CNVR_STATE$	(INT)69
#define CNVR_STATE_	(INT)2
#define CNVR_ZONE$	(INT)71
#define CNVR_ZONE_	(INT)2
#define N_PARTS$	(INT)73
#define N_PARTS_	(INT)2
   /*  **********************************************************  */
   /*  type 2  (Annotation)     */
#define SW_CORNER_LL$	(INT)1
#define SW_CORNER_LL_	(INT)15
#define SW_CORNER_XY$	(INT)16
#define SW_CORNER_XY_	(INT)18
#define ANGLE$		(INT)34
#define ANGLE_		(INT)5
#define SIZE$		(INT)39
#define SIZE_		(INT)6
#define N_CHARS$	(INT)45
#define N_CHARS_	(INT)2
#define FONT$		(INT)47
#define FONT_		(INT)1
#define TEXT$		(INT)48
#define TEXT_		32	/* used as an array size; no INT casting! */
   /*  **********************************************************  */
   /*  type 3  (Vector)                                            */
#define AT_LL$		(INT)1
#define AT_LL_		(INT)15
#define AT_XY$		(INT)16
#define AT_XY_		(INT)20
#define TO_LL$		(INT)36
#define TO_LL_		(INT)15
#define TO_XY$		(INT)51
#define TO_XY_		(INT)20
#define LINE_CODE$	(INT)71
#define LINE_CODE_	(INT)2
#define SEG_SEQ_NO$	(INT)73
#define SEG_SEQ_NO_	(INT)6
#define EOP_FLAG$	(INT)79
#define EOP_FLAG_	(INT)1
   /*  **********************************************************  */
   /*  Name Formats                                                */
#define STATE$		(INT)4
#define STATE_		(INT)2
#define ALPHA_5$	(INT)4
#define ALPHA_5_	(INT)19
#define COUNTY$		(INT)6
#define COUNTY_		(INT)3
#define PREFIX$		(INT)9
#define PREFIX_		(INT)1
#define C_M$		(INT)9
#define C_M_		(INT)1
#define C_N$		(INT)9
#define C_N_		(INT)1
#define ALPHA_4$	(INT)9
#define ALPHA_4_	(INT)14
#define SURVEY_CODE$	(INT)9
#define SURVEY_CODE_	(INT)3
#define ALPHA_3$	(INT)10
#define ALPHA_3_	(INT)13
#define TWP$		(INT)11
#define TWP_		(INT)3
#define A_T_B$		(INT)11
#define A_T_B_		(INT)1
#define B_L$		(INT)12
#define B_L_		(INT)1
#define BLK$		(INT)13
#define BLK_		(INT)4
#define N_S$		(INT)13
#define N_S_		(INT)1
#define RANGE$		(INT)14
#define RANGE_		(INT)3
#define SURVEY_NO$	(INT)16
#define SURVEY_NO_	(INT)5
#define LEAGUE_TWP$	(INT)17
#define LEAGUE_TWP_	(INT)2
#define E_W$		(INT)17
#define E_W_		(INT)1
#define ALPHA_2$	(INT)18
#define ALPHA_2_	(INT)5
#define SECTION$	(INT)18
#define SECTION_	(INT)3
#define DEC_DIR$	(INT)19
#define DEC_DIR_	(INT)1
#define S_L_T$		(INT)20
#define S_L_T_		(INT)1
#define SLT_NO$		(INT)21
#define SLT_NO_		(INT)5
#define DEC_SUB$	(INT)21
#define DEC_SUB_	(INT)2
#define S_A$		(INT)26
#define S_A_		(INT)1
#define SA_NO$		(INT)27
#define SA_NO_		(INT)5
   /*  **********************************************************  */

#endif
