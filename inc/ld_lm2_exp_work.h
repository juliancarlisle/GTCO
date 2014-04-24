/* DEC/CMS REPLACEMENT HISTORY, Element LD_LM2_EXP_WORK.H */
/* *3    14-AUG-1991 11:46:01 KEE "(SPR -1) Put in File Lock/Unlock logic" */
/* *2     1-MAY-1991 12:21:18 KEE "(SPR -1) Landmark export workspace header file" */
/* *1     1-MAY-1991 12:17:53 KEE "Landmark export workspace header file" */
/* DEC/CMS REPLACEMENT HISTORY, Element LD_LM2_EXP_WORK.H */
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

#ifndef LD_LM2_EXP_WORK_H
#define LD_LM2_EXP_WORK_H 1

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif
#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif
#ifndef ESI_CT_H
#include "esi_ct.h"
#endif
#ifndef ESI_HO_FILES_H
#include "esi_ho_files.h"
#endif

#define maxExpFiles 32

typedef struct 
{
INT	dialogID;
INT	map_count;
TCP	tcp_of_maps;
INT	siesmic;
INT	horizons;
INT	faults;
INT	wells;
INT	culture;
INT     tops;
INT	logs;
VOIDPTR temp_names;
TCP     projectionList;
INT	projectionCount;
CHAR    mapName[41];
CHAR    file_names[maxExpFiles][81];
INT	fileCount;
CHAR    titles[maxExpFiles][81];
TCP     tcp_of_curves;
INT     ncurves;
INT	ncurvesPicked;
INT	curvesPicked[32];	
VOIDPTR tempCurves;
TCP     tcp_of_sources;
INT     nsources;
INT	sourcePicked;
VOIDPTR tempSources;
} LANDMARK_WORKSPACE;

#if USE_PROTOTYPES
extern INT ld_get_wells(CHAR *selectPhrase, CHAR *selectList,
			NLIST_HEADER *well_nlist, INT *num_wells,
			DOUBLE lower_left_x, DOUBLE lower_left_y, 
			DOUBLE upper_right_x, DOUBLE upper_right_y, 
			PROJECT_NAME project);
extern INT ld_lm2_curve_pipe (LANDMARK_WORKSPACE *workspace, 
			      BOOL *goFlag);
extern VOID ld_lm2_exp_culture (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_culture_out (CHAR *selectPhrase, CHAR *cultureType, 
		   BOOL *firstIteration, FILE **myfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_culture_color (CHAR *color);
extern VOID ld_lm2_exp_fault (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_fault_out (CHAR *selectPhrase, CHAR *sourceName,
		   BOOL *firstIteration, FILE **myfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern INT ld_lm2_exp_files (LANDMARK_WORKSPACE *workspace, INT mapOrdinal, INT xyVal,
				INT spVal, INT fpVal, INT fltVal, 
				INT wellVal, INT cultVal, INT logVal,
				INT topVal, INT hrzVal, BOOL *goFlag);
extern VOID ld_lm2_exp_fp (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, PROJECTION_STRUCTURE *defaultProj, 
		   PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_fp_out(CHAR *selectPhrase, CHAR *selectList,
		   CHAR *horizonName, CHAR *sourceName,
		   BOOL *firstIteration, FILE **spfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, PROJECTION_STRUCTURE *defaultProj, 
		   PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_hrz (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, CHAR *hrzName, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern  VOID ld_lm2_exp_hrz_out (CHAR *selectList, CHAR *selectPhrase,
		   CHAR *horizonName, CHAR *source,
		   BOOL *firstIteration, FILE **spfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_logs (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, CHAR curveName[200][12], 
		   INT curveCount, CHAR *source);
extern VOID ld_lm2_exp_logs_out(CHAR *selectPhrase, CHAR *selectList,
		   BOOL *firstIteration, FILE **spfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, CHAR curveName[200][12], 
		   INT curveCount, CHAR *source);
extern INT ld_lm2_get_uwi (CHAR *projectName, CHAR *wellName, CHAR *uwi);
extern VOID ld_lm2_exp_seismic (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, FILENAME fileName2, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_seismic_out (CHAR *selectPhrase, CHAR *selectList, 
		   BOOL *firstIteration, FILE **trfile, FILE **spfile,
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY,
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, FILENAME fileName2, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern INT ld_lm2_exp_server(INT id, INT item, LANDMARK_WORKSPACE *workspace);
extern VOID ld_lm2_exp_tops (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, CHAR *source);
extern VOID ld_lm2_exp_tops_out(CHAR *selectPhrase, CHAR *selectList, 
		   BOOL *firstIteration, FILE **spfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY,
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, CHAR *source);
extern VOID ld_lm2_exp_wells (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_wells_out(CHAR *selectPhrase, CHAR *selectList, 
		   BOOL *firstIteration, FILE **spfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY,
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_seis_list(CHAR *selectPhrase, CHAR *selectList, 
		   DOUBLE lower_left_x, DOUBLE lower_left_y, 
		   DOUBLE upper_right_x, DOUBLE upper_right_y,
		   INT *lineCount, NLIST_HEADER *lineList);
extern INT ld_lm2_source_pipe (LANDMARK_WORKSPACE *workspace, BOOL *goFlag);
extern VOID ld_lm2_exp_chkshots (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, CHAR *source);
extern VOID ld_lm2_exp_chkshots_out(CHAR *selectPhrase, CHAR *selectList, 
		   BOOL *firstIteration, FILE **spfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY,
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, CHAR *source);
extern VOID ld_lm2_exp_dirsrvys (CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY, 
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, 
	           PROJECTION_STRUCTURE *inputProj);
extern VOID ld_lm2_exp_dirsrvys_out(CHAR *selectPhrase, CHAR *selectList, 
		   BOOL *firstIteration, FILE **spfile, 
		   CHAR *mapName, PROJECT_NAME projectName, 
		   DOUBLE lowerLeftX, DOUBLE lowerLeftY,
		   DOUBLE upperRightX, DOUBLE upperRightY,
		   FILENAME fileName1, BOOL convertProj, 
		   PROJECTION_STRUCTURE *defaultProj, 
	           PROJECTION_STRUCTURE *inputProj);
extern VOID ld_show_error(INT errorCode, CHAR *inWhat);
#else
extern INT ld_get_wells ();
extern INT ld_lm2_curve_pipe ();
extern VOID ld_lm2_exp_culture ();
extern VOID ld_lm2_exp_culture_out ();
extern VOID ld_lm2_exp_culture_color ();
extern VOID ld_lm2_exp_fault ();
extern VOID ld_lm2_exp_fault_out ();
extern INT ld_lm2_exp_files ();
extern VOID ld_lm2_exp_fp ();
extern VOID ld_lm2_exp_fp_out ();
extern VOID ld_lm2_exp_hrz ();
extern  VOID ld_lm2_exp_hrz_out ();
extern VOID ld_lm2_exp_logs ();
extern VOID ld_lm2_exp_logs_out ();
extern INT ld_lm2_get_uwi ();
extern VOID ld_lm2_exp_seismic ();
extern VOID ld_lm2_exp_seismic_out ();
extern INT ld_lm2_exp_server ();
extern VOID ld_lm2_exp_tops ();
extern VOID ld_lm2_exp_tops_out ();
extern VOID ld_lm2_exp_wells ();
extern VOID ld_lm2_exp_wells_out ();
extern VOID ld_lm2_seis_list ();
extern INT ld_lm2_source_pipe ();
extern VOID ld_lm2_exp_chkshots ();
extern VOID ld_lm2_exp_chkshots_out ();
extern VOID ld_lm2_exp_dirsrvys ();
extern VOID ld_lm2_exp_dirsrvys_out ();
extern VOID ld_show_error();
#endif

#endif



