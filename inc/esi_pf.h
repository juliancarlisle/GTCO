/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PF.H*/
/* *9    16-AUG-1991 16:56:34 MING "(SPR 0) add more agrument to pf_close_file"*/
/* *8     6-JUN-1991 17:13:45 MING "(SPR 0) new plot file managment"*/
/* *7    14-AUG-1990 11:50:22 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *6    20-JUN-1990 16:15:48 MING "(SPR 0) change float to double in prototype"*/
/* *5    20-JUN-1990 14:23:44 GILLESPIE "(SPR 1) add esi_lh.h include file ref"*/
/* *4    20-JUN-1990 11:00:05 MING "(SPR 0) add rebind segment routines prototypes"*/
/* *3    27-APR-1990 13:04:51 MING "(SPR 0) add metatype for PDS"*/
/* *2     6-FEB-1990 14:27:57 MING "(SPR 0) delete unused date_stamp fields in PF_LIST"*/
/* *1    30-JUN-1989 15:03:42 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_PF.H*/
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

#ifndef ESI_PF_H
#define ESI_PF_H 1

/******************************************************************
   Copyright 1988,  Exploration Systems Inc. San Francisco Ca.
    
	   Finder Plotting System main include file.
   
    Created on Feb 27, 1988  by  Julian Carlisle
******************************************************************/

#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

#ifndef ESI_LH_H
#include "esi_lh.h"
#endif

#ifndef ESI_MP_H
#include "esi_mp.h"
#endif

#ifndef ESI_PL_H
#include "esi_pl.h"
#endif

#ifndef ESI_XS_DEFS_H
#include "esi_xs_defs.h"
#endif

#define PF_WORKSPACE	"Plotting System Workspace"

typedef struct plotter_desc_struct {
    CHAR	name[80];
    CHAR	driver[80];
    CHAR	queue[80];
    CHAR	status[80];
    DOUBLE 	xsize;
    DOUBLE	ysize;
    INT		pens;
    CHAR    	meta_type[20];
    } PDS;

typedef struct plotfile_struct {
    FILENAME	neutral_file;
    FILENAME	device_file;
    PDS		plotter;
    CHAR		description[239];
    } PLOTFILE;
    
typedef struct pf_filelist {
    TCP	filelist;
    INT		num_files;
    FILENAME	key;
    INT		context;
    } PF_FLIST;
    
typedef struct {
    PDS		*selected_plotter;
    PDS		*default_plotter;
    PF_FLIST	neut_files;
    PF_FLIST	device_files;
    PLOTFILE	plotfile;
    FILENAME	username;
    FILENAME	flat_file;
    FILENAME	oracle_login;
    PROJECT_NAME	project;
    FILENAME	tempfile;	
    struct {
	INT num_plotters;
	INT index;
	FILENAME   name;
	INT temp;
	} sp;    
    TCP	   pname_tcp;

    struct {
	INT	    got_plotter;
	INT	    got_file;
	} flags;
		
    struct {
	INT pf_file_id;
	INT	pf_menu_id;
	INT	pf_ctrl_id;
	INT	pf_choose_id;
	} cdlgids;
    } PF_STRUCT;
	

typedef struct {
    INT file_id;
    FILENAME filename;
    PATHNAME pathname;
    FILENAME finder_path;
    CHAR meta_type[8];
    CHAR layout[40];
    COORD xsize;
    COORD ysize;
    COORD vdc_ll_x;
    COORD vdc_ll_y;
    COORD vdc_ur_x;
    COORD vdc_ur_y;
    BOOL save;
    BOOL plot;
    BOOL perm;
    INT copies;
    DATE creation_date;
    DATE expired_date;
    PROJECT_NAME project;
    ANALYST_NAME analyst;
    CHAR remark[240];
    CHAR app[12];
    INT type;
    INT size;
    union 
	{
	MAP_STRUCTURE *map;
	XS_STRUCT *xs;
	} parm;  
    }  PF_INFO;

typedef struct {
    FILENAME filename;
    } PF_OV_STRUCT;

#define PF_GET_FM_HDR_ONLY 	0
#define PF_GET_ALL 		1

#if USE_PROTOTYPES

extern INT pf_file_srvr_init(PF_STRUCT *pfp);
extern INT pf_file_init(INT *meta_ws,PATHNAME metafile);
extern INT pf_file_close(INT meta_ws,PATHNAME metafile,CHAR *units, DOUBLE width,DOUBLE height, DOUBLE ndc_width, DOUBLE ndc_height);
extern INT pf_win_init(INT meta_ws,INT window_id,lh_listhead **seg_list_ptr);
extern INT pf_win_close(INT window_id,lh_listhead *seg_list_ptr,INT meta_ws);
extern INT pf_all_segs(lh_listhead *seg_list_ptr);
extern INT pf_one_seg(INT seg_id,lh_listhead *seg_list_ptr);
extern INT pf_all_groups(lh_listhead *seg_list_ptr);
extern INT pf_one_group(INT gro_id,lh_listhead *seg_list_ptr);
extern INT pf_win_to_meta(INT meta_ws,INT window_id);
extern INT pf_ovl_to_meta(INT meta_ws,INT window_id,INT tnr_id,DOUBLE xscale,
      DOUBLE yscale,DOUBLE xoffset,DOUBLE yoffset,INT subgroup_id,INT group_id);
extern publicdef INT pf_open_plotfile (INT ws,CHAR *metafile,CHAR *meta_type,CHAR *mode);
extern publicdef INT pf_display_pf (CHAR *metafile, CHAR *meta_type);
extern publicdef INT pf_get_plot_info (PDS *pinfo,CHAR *layout,PF_INFO *pf_info,INT type);
extern publicdef INT pf_get_xs_plot_info (PDS *pinfo,CHAR *layout,PF_INFO *pf_info,INT type);
extern publicdef BOOL pfz_file_exists (CHAR *filename,CHAR *app);
extern publicdef INT pf_inq_plotter (CHAR *pname, PDS *pinfo);
extern publicdef INT pf_manager (void);
extern publicdef INT pfz_delete_pf (CHAR *file, CHAR *src, CHAR *app);
extern publicdef INT pf_get_plotters (INT *nplotters, CHAR ***tcp_list, CHAR *type);
extern publicdef INT pf_get_plotfile (PF_INFO *pf_info, CHAR *name, CHAR *type, CHAR *source);
extern publicdef INT pf_overlay (INT display_line);
extern publicdef pf_post_overlay (PF_INFO *pf);
extern publicdef pf_get_clip_extent (PF_INFO *pf,DOUBLE *ndc_ll_x,DOUBLE *ndc_ll_y,DOUBLE *ndc_ur_x,DOUBLE *ndc_ur_y);
extern publicdef pf_read_parfile (PATHNAME metafile,DOUBLE *vdc_ll_x,DOUBLE *vdc_ll_y,DOUBLE *vdc_ur_x,DOUBLE *vdc_ur_y);
extern publicdef INT pf_put_plotfile (PF_INFO *pf_info);
extern publicdef INT pf_put_xs_pf (PF_INFO *pf_info);
extern publicdef INT pf_put_mp_pf (PF_INFO *pf_info);
#else
extern INT pf_file_srvr_init();
extern INT pf_file_init();
extern INT pf_file_close();
extern INT pf_win_init();
extern INT pf_win_close();
extern INT pf_all_segs();
extern INT pf_one_seg();
extern INT pf_all_groups();
extern INT pf_one_group();
extern INT pf_win_to_meta();
extern INT pf_ovl_to_meta();
extern INT pf_overlay ();
extern INT pf_post_overlay ();
extern publicdef INT pf_open_plotfile ();
extern publicdef INT pf_display_pf ();
extern publicdef INT pf_get_plot_info ();
extern publicdef INT pf_get_xs_plot_info ();
extern publicdef INT pfz_check_size ();
extern publicdef BOOL pfz_file_exists ();
extern publicdef INT pf_inq_plotter ();
extern publicdef INT pf_manager ();
extern publicdef INT pfz_delete_pf ();
extern publicdef INT pf_get_plotters ();
extern publicdef INT pf_get_plotfile ();
extern publicdef INT pf_overlay ();
extern publicdef pf_post_overlay ();
extern publicdef pf_get_clip_extent ();
extern publicdef pf_read_parfile ();
extern publicdef INT pf_put_plotfile ();
extern publicdef INT pf_put_xs_pf ();
extern publicdef INT pf_put_mp_pf ();
#endif		 /* End of File */
#endif
