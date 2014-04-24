/* DEC/CMS REPLACEMENT HISTORY, Element LD_ZYCOR_WORK.H */
/* *3    14-AUG-1991 11:46:17 KEE "(SPR -1) Put in File Lock/Unlock logic" */
/* *2     1-MAY-1991 12:23:49 KEE "(SPR -1) Zycor export workspace header file" */
/* *1     1-MAY-1991 12:23:12 KEE "Zycor export workspace header file" */
/* DEC/CMS REPLACEMENT HISTORY, Element LD_ZYCOR_WORK.H */
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

#ifndef LD_ZYCOR_WORK_H
#define LD_ZYCOR_WORK_H 1

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

typedef struct 
{
INT	dialogID;
CHAR    mapName[41];
CHAR	faultFile[81];
CHAR	cultureFile[81];
CHAR    xyzFile[81];
INT	map_count;
TCP	tcp_of_maps;
VOIDPTR temp_names;
} ZYCOR_WORKSPACE;

#if USE_PROTOTYPES
extern VOID ld_show_error(INT errorCode, CHAR *inWhat);
extern VOID ld_zycor_culture (CHAR *mapName, PROJECT_NAME projectName,
				 FILENAME fileName1);
extern VOID ld_zycor_fault (CHAR *mapName, PROJECT_NAME projectName,
				ANALYST_NAME account, FILENAME fileName1);
extern VOID ld_zycor_xyz (CHAR *mapName, PROJECT_NAME projectName,
			     FILENAME fileName1);
extern INT ld_zycor_exp_server (INT id, INT item, ZYCOR_WORKSPACE *workspace);
extern INT ld_zycor_file_pipe (ZYCOR_WORKSPACE *workspace, 
				  INT mapOrdinal, INT faultVal,
                                  INT cultureVal, INT xyzVal, BOOL *goFlag);

#else
extern VOID ld_show_error ();
extern VOID ld_zycor_culture ();
extern VOID ld_zycor_fault ();
extern VOID ld_zycor_xyz ();
extern INT ld_zycor_exp_server ();
extern INT ld_zycor_file_pipe ();
#endif


#endif





