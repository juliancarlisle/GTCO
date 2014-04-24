/* DEC/CMS REPLACEMENT HISTORY, Element LEG_NL_ED.C */
/* *6    23-AUG-1990 17:50:10 PURNA "(SPR 0) compiling error fix" */
/* *5     9-AUG-1990 19:07:33 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *4     7-FEB-1990 07:00:06 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *3    25-JAN-1990 09:34:55 ADEY "(SPR -1) fix keymap_first for use_keymap & init_dialog" */
/* *2    16-OCT-1989 15:58:01 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:48:38 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element LEG_NL_ED.C */
/* DEC/CMS REPLACEMENT HISTORY, Element LEG_NL_ED.C*/
/* *3    25-SEP-1989 11:57:53 GORDON "(SPR 201) Fix bad lu call"*/
/* *2    14-SEP-1989 16:15:58 GORDON "(SPR 100) Gulf/Sun/Unix mods"*/
/* *1    19-JUN-1989 13:03:45 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element LEG_NL_ED.C*/

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


#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_LE_NLED_H
#include "esi_le_nled.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifdef vms
#ifndef ESI_LU_H
#include "esi_lu.h"
#endif
#endif

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

privatedef  LE_PARLIST LEG_PARLIST;

/***********************************************************************
*
* GLUE ROUTINE
*
* this routine will allow Fortran programs to call the C function
* le_nlist_editor.
*
* Julian  3/28/87
**********************************************************************/
#ifdef vms
publicdef INT leg_nlist_editor(status)
INT *status;
{

*status = le_nlist_editor(&LEG_PARLIST);

return *status;
}
#endif

#if UNIX
publicdef INT leg_nlist_editor_(status)
INT *status;
{

*status = le_nlist_editor(&LEG_PARLIST);

return *status;
}
#endif

#ifdef primos
publicdef INT leg_nlist_editor(status)
INT status;
{

status = le_nlist_editor(&LEG_PARLIST);

return;
}
#endif

/***********************************************************************
*
* This routine (called from fortran) will zero out the LEG_PARLIST
* structure, and the associated COMMON block on the Fortran side.
*
***********************************************************************/
publicdef INT leg_default_params()
{

tc_zeroes(&LEG_PARLIST, sizeof LEG_PARLIST);

#ifdef vms
lu_text_to_index("COLOR", &LEG_PARLIST.line.color, "NORMAL" );   /* color to draw_stroke        */
lu_text_to_index("COLOR", &LEG_PARLIST.hilight_color, "HIGHLIGHT" );      /* color to hilight strokes    */
lu_text_to_index("COLOR", &LEG_PARLIST.erase_color, "BACKGROUND" );   /* color to erase strokes      */
lu_text_to_index("LINE_STYLE", &LEG_PARLIST.line.style, "SOLID");     /*   GKS code for line style */
LEG_PARLIST.line.width = 1.0;  
LEG_PARLIST.initkeymap  = TRUE;
LEG_PARLIST.init_dialog  = FALSE;
LEG_PARLIST.use_keymap = TRUE;
LEG_PARLIST.key_swap = FALSE;
LEG_PARLIST.only_app_mac_dialog = FALSE;
LEG_PARLIST.zz_init_dial = NULL_FUNCTION_PTR;
LEG_PARLIST.zz_dial_oper = NULL_FUNCTION_PTR;
LEG_PARLIST.zz_dial_release = NULL_FUNCTION_PTR;
LEG_PARLIST.app_puck_map_disp_init = NULL_FUNCTION_PTR;
LEG_PARLIST.nlist = (NLIST_HEADER)0;
LEG_PARLIST.point_keymap = (LE_KEYS *)0;
LEG_PARLIST.num_point_keymaps = 0;
LEG_PARLIST.stroke_keymap = (LE_KEYS *)0;
LEG_PARLIST.num_stroke_keymaps = 0;

#endif
return SUCCESS;
}

                                                                                                    
