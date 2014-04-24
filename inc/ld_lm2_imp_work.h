/* DEC/CMS REPLACEMENT HISTORY, Element LD_LM2_IMP_WORK.H */
/* *2     1-MAY-1991 12:21:59 KEE "(SPR -1) Landmark import workspace header file" */
/* *1     1-MAY-1991 12:18:28 KEE "Landmark import workspace header file" */
/* DEC/CMS REPLACEMENT HISTORY, Element LD_LM2_IMP_WORK.H */
/******************************************************************************

                Copyright Finder Graphics Systems, Inc. 1990
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND
MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF

			Finder Graphics Systems, Inc.
			201 Tamal Vista Blvd
			Corte Madera, CA  USA 94925
			(415) 927-0100

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work)

******************************************************************************/

#ifndef LD_LM2_IMP_WORK_H
#define LD_LM2_IMP_WORK_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif
#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif
#ifndef ESI_HT_H
#include "esi_ht.h"
#endif
#ifndef ESI_CT_H
#include "esi_ct.h"
#endif
#ifndef ESI_TC_H
#include "esi_tc.h"
#endif
#ifndef ESI_WE_WELLS_H
#include "esi_we_wells.h"
#endif
#ifndef ESI_LD_H
#include "esi_ld.h"
#endif

#define maxHorizons 32

typedef struct 
{
INT	dialogID;
TCP     projectionList;
INT     projectionCount;
CHAR    horizonFiles[maxHorizons][100];
CHAR    horizonNames[maxHorizons][30];
INT     horizonCount;
} LANDMARK_IMPSPACE;

#if USE_PROTOTYPES
extern INT ld_lm2_delete_trace(UWI uwi, CHAR traceCname[], INT traceID);
extern INT ld_lm2_edit_hrz (LANDMARK_IMPSPACE *workspace);
extern INT ld_lm2_imp_culture (FILENAME fileName, PROJECT_NAME project,
			BOOL convertProj, 
			PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj,
			CHAR *source, INT overwrite, DOUBLE proj_ll_x,
			DOUBLE proj_ll_y, DOUBLE proj_ur_x, DOUBLE proj_ur_y);
extern INT ld_lm2_imp_culture_check (CHAR *objectName, CHAR *project, 
			CHAR *source, INT overwrite, HASH_TABLE_P hash_table, 
			INT *currentObject);
extern VOID ld_lm2_imp_culture_delete (CHAR *objectName, INT object_id, 
				      CHAR *project);
extern VOID ld_lm2_imp_culture_header (BOOL writeObject, 
			  CHAR *project, CHAR *source, 
			  CHAR *objectName, INT *currentObject, 
			  CHAR *item_id, CHAR *item_class,
			  DOUBLE lower_left_x, DOUBLE lower_left_y,
			  DOUBLE upper_right_x, DOUBLE upper_right_y,
			  DOUBLE *ll_x_now, DOUBLE *ll_y_now, 
			  DOUBLE *ur_x_now, DOUBLE *ur_y_now);
extern VOID ld_lm2_imp_culture_newline (CHAR *lineColor, CHAR *fillColor, 
			  CHAR *project, CHAR *nlist_id, 
			  CHAR *polygonFlag, CHAR *full_filename);
extern INT ld_lm2_imp_culture_newobj (BOOL *newObject, BOOL *newLine, 
			  BOOL *oldObject, BOOL *oldLine,
			  NLIST_HEADER *nlist, CHAR *objectName, 
			  CHAR *full_filename, CHAR *nlist_id, 
			  CHAR *lineColor, CHAR *polygonFlag, CHAR *fillColor,
			  CHAR *project, CHAR *source, INT overwrite, 
			  HASH_TABLE_P hash_table, INT *currentObject);
extern VOID ld_lm2_imp_culture_text (BOOL *oldObject, CHAR *text,
			  CHAR *objectName, DOUBLE inputX, DOUBLE inputY, 
			  DOUBLE height, DOUBLE width, DOUBLE angle,
			  CHAR *justification, DOUBLE slant, CHAR *font, CHAR *color,
			  CHAR *project, CHAR *source, INT overwrite, 
			  HASH_TABLE_P hash_table, INT *currentObject, 
			  DOUBLE *ll_x, DOUBLE *ll_y, DOUBLE *ur_x, DOUBLE *ur_y);
extern INT ld_lm2_imp_culture_write (BOOL *oldLine, BOOL *oldObject, 
                          NLIST_HEADER *nlist, CHAR *full_filename,
			  CHAR *nlist_id, CHAR *project, CHAR *source, 
                          CHAR *objectName, INT *currentObject,
			  DOUBLE *lower_left_x, DOUBLE *lower_left_y, 
                          DOUBLE *upper_right_x, DOUBLE *upper_right_y);
extern INT ld_lm2_imp_fault (FILENAME fileName, PROJECT_NAME project,
			BOOL convertProj, PROJECTION_STRUCTURE *defaultProj, 
                        PROJECTION_STRUCTURE *inputProj, CHAR *source, 
			INT overwrite, DOUBLE ll_x, DOUBLE ll_y, DOUBLE ur_x, 
			DOUBLE ur_y, CHAR *horizon);
extern INT ld_lm2_imp_fp (FILENAME fileName, PROJECT_NAME project,
			BOOL convertProj, PROJECTION_STRUCTURE *defaultProj, 
                        PROJECTION_STRUCTURE *inputProj, CHAR *source, 
			INT overwrite);
extern VOID ld_lm2_imp_hrz (FILENAME fileName, PROJECT_NAME project,
			CHAR *horizonName, BOOL convertProj, 
			PROJECTION_STRUCTURE *defaultProj, 
                        PROJECTION_STRUCTURE *inputProj, CHAR *source, 
			INT overwrite, DOUBLE ll_x, DOUBLE ll_y, DOUBLE ur_x, 
			DOUBLE ur_y);
extern INT ld_lm2_get_uwi (CHAR *projectName, CHAR *wellName, CHAR *uwi);
extern INT ld_lm2_imp_logs (PROJECT_NAME project, FILENAME fileName, 
			CHAR *source, INT overwrite);
extern INT ld_lm2_imp_server(INT id, INT item, LANDMARK_IMPSPACE *workspace);
extern VOID ld_lm2_imp_shot_trace (FILENAME fileName, PROJECT_NAME project,
			BOOL convertProj, PROJECTION_STRUCTURE *defaultProj, 
                        PROJECTION_STRUCTURE *inputProj, CHAR *source, 
			INT overwrite);
extern INT ld_lm2_imp_shot_xy (FILENAME fileName, PROJECT_NAME project,
			BOOL convertProj, PROJECTION_STRUCTURE *defaultProj, 
                        PROJECTION_STRUCTURE *inputProj, CHAR *source, 
			INT overwrite, DOUBLE ll_x, DOUBLE ll_y, DOUBLE ur_x, 
			DOUBLE ur_y);
extern  VOID ld_lm2_imp_tops (FILENAME fileName, PROJECT_NAME project,
                        CHAR *source, INT overwrite);
extern VOID ld_lm2_imp_wells (FILENAME fileName, PROJECT_NAME project,
			BOOL convertProj, PROJECTION_STRUCTURE *defaultProj, 
                        PROJECTION_STRUCTURE *inputProj, CHAR *source, 
			INT overwrite, DOUBLE ll_x, DOUBLE ll_y, DOUBLE ur_x, 
			DOUBLE ur_y);
extern INT ld_lm2_imp_dirsrvys (FILENAME fileName, PROJECT_NAME project,
			BOOL convertProj, PROJECTION_STRUCTURE *defaultProj, 
                        PROJECTION_STRUCTURE *inputProj, CHAR *source, 
			INT overwrite);
extern VOID ld_lm2_imp_chkshots (FILENAME fileName, PROJECT_NAME project,
                        CHAR *source, INT overwrite);
extern INT ld_lm2_imp_put_top(UWI uwi, CHAR top[], TOP_STRUCT *ptop);
extern VOID ld_show_error(INT errorCode, CHAR *inWhat);
#else
extern INT ld_lm2_delete_trace ();
extern INT ld_lm2_edit_hrz ();
extern INT ld_lm2_imp_culture ();
extern INT ld_lm2_imp_culture_check ();
extern VOID ld_lm2_imp_culture_delete ();
extern VOID ld_lm2_imp_culture_header ();
extern VOID ld_lm2_imp_culture_newline ();
extern INT ld_lm2_imp_culture_newobj ();
extern VOID ld_lm2_imp_culture_text ();
extern INT ld_lm2_imp_culture_write ();
extern INT ld_lm2_imp_fault ();
extern INT ld_lm2_imp_fp ();
extern VOID ld_lm2_imp_hrz ();
extern INT ld_lm2_get_uwi ();
extern INT ld_lm2_imp_logs ();
extern INT ld_lm2_imp_server ();
extern VOID ld_lm2_imp_shot_trace ();
extern INT ld_lm2_imp_shot_xy ();
extern VOID ld_lm2_imp_wells ();
extern INT ld_lm2_imp_dirsrvys ();
extern VOID ld_lm2_imp_chkshots ();
extern VOID ld_show_error();
#endif

#endif

