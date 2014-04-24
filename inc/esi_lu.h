/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LU.H*/
/* *5    14-AUG-1990 11:49:09 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *4    12-JUL-1990 15:03:00 GILLESPIE "(SPR 3) Change publicdef to extern"*/
/* *3    20-OCT-1989 11:24:45 CONROY "(SPR 5030) Add routine lu_num_of_keywords."*/
/* *2     5-SEP-1989 11:59:56 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *1    30-JUN-1989 15:02:41 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LU.H*/
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

#ifndef ESI_LU_H

#define ESI_LU_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#if USE_PROTOTYPES

extern INT lu_index_to_text(CHAR *keyword, CHAR *text, INDEX index);
extern INT lu_text_to_index(CHAR *keyword, INDEX *index, CHAR *text);
extern INT lu_get_tcp(CHAR *keyword, TCP *tcpPtr, INT *numRet);
extern INT lu_num_of_keywords(INT *number);
extern INT lup_get_graphic_attributes(CHAR *prompt, INDEX in_thick, LINE_STYLE_INDEX in_style,
                                      COLOR_INDEX in_color, INDEX *out_thick, LINE_STYLE_INDEX *out_style,
                                      COLOR_INDEX *out_color, CHAR *out_thick_str,
                                      CHAR *out_style_str, CHAR *out_color_str);

#else

extern INT lu_index_to_text();
extern INT lu_text_to_index();
extern INT lu_get_tcp();
extern INT lu_num_of_keywords();
extern INT lup_get_graphic_attributes();

#endif      /* of USE_PROTOTYPES */
#endif
