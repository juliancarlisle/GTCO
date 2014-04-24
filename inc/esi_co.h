/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CO.H*/
/*  9    11-MAR-1992 18:08:41 JTM "(SPR 0)  fixed protos for co_post_labels and co_post_contours"*/
/*  8    16-JAN-1992 12:09:55 JTM "(SPR 0)  Contour Annotation code from Don V."*/
/* *7    11-MAR-1991 10:07:19 KEE "(SPR -1) Add some more co function "*/
/* *6    23-OCT-1990 11:22:03 GILLESPIE "(SPR 1000) Move from Ernie"*/
/*  3B1  23-OCT-1990 11:20:25 GILLESPIE "Merge from Ernie"*/
/* *5    15-SEP-1990 13:08:00 CHARLIE "(SPR -1) moved defines to include"*/
/* *4    14-AUG-1990 11:46:29 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *3    25-APR-1990 08:23:33 PURNA "(SPR 0) remove line_color option from co_overlay"*/
/* *2     5-SEP-1989 11:24:58 GORDON "(SPR 200) Gulf changes (August trip)"*/
/* *1    30-JUN-1989 14:59:51 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_CO.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Exploration Systems, Inc. 1989                          */
/*         Unpublished -- All rights reserved                                       */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY   */
/*CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE      */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*                            Exploration Systems                                   */
/*                            c/o Finder Graphics Systems                           */
/*                            201 Tamal Vista Blvd.                                 */
/*                            Corte Madera, CA  94925                               */
/*                            (415) 927-0100                                        */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

#ifndef ESI_CO_H
#define ESI_CO_H 1

/* * FILE DESCRIPTION *                                                             */
/* --------------------                                                             */
/* ************************************************************************         */
/*                                                                                  */
/*   NAME: ESI_CO.H                                                                 */
/*                                                                                  */
/*   AUTHOR: JOHN CONROY                                                            */
/*                                                                                  */
/*   DESCRIPTION: Include file containing function definitions for 'CONTOUR'        */
/*      overlay.                                                                    */
/*                                                                                  */
/*   ************************************************************************       */


/* * INCLUDE FILES *                                                                */
/* -----------------                                                                */

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

/* for trend and residuals under contouring (not final home)                        */
#define SURFACE_TYPE 0
#define TREND_TYPE 1
#define RESIDUAL_TYPE 2
#define MAP_TYPE 0
#define PERSPECTIVE_TYPE 1

/* should be lu call to get these                                                   */
#define CONTOUR_TYPE 1
#define CONTOUR_KEY_TYPE 2
#define MESH_TYPE 3
#define RIDGE_TYPE 4
#define TRACE_TYPE 5

/* * STRUCTURES *                                                                   */
/* --------------                                                                   */

typedef struct 
    {
    CHAR *grid_interval;
    CHAR *grid_minimum;
    CHAR *grid_maximum;
    CHAR *contour_minimum;
    CHAR *contour_maximum;
    CHAR *contour_interval;
    CHAR *xyz_file;
    CHAR *grid_file;
    CHAR *contour_file;
    CHAR *faulted;
    CHAR *fault_source;
    INT bold_line_interval;
    INT label_interval;
    COLOR_INDEX bold_line_color;
    COLOR_INDEX fine_line_color;
    BOOL suppress_smoothing;
    BOOL bounded_by_data;
    BOOL use_file_defaults;
    BOOL isopach;
    CHAR *name;
    FLOAT vertical_exaggeration;
    FLOAT view_azimuth;
    FLOAT view_distance;
    FLOAT view_inclination;
    INT view_type;
    INT grid_type;
    INT trend_or_resid_order;
    } CONTOURS;

/* * FUNCTIONS *                                                                    */
/* -------------                                                                    */

#if USE_PROTOTYPES
extern INT co_bgngrd_gc (void);
extern INT co_bgnplt_gc (void);
extern INT co_clcbnd_gc (FLOAT *x, FLOAT *y, FLOAT *z, INT npts, INT bound_type,
                         INT bound_in, FLOAT *x_bnd, FLOAT *y_bnd, INT *bound_out);
extern INT co_clcflt_gc (FLOAT *x, FLOAT *y, FLOAT *z, INT npts, FLOAT *grid,
                         INT ncols, INT nrows, INT *workspace, INT worksize);
extern INT co_clcgrd_gc (FLOAT *x, FLOAT *y, FLOAT *z, INT npts, FLOAT *grid,
                         INT ncols, INT nrows, INT *workspace, INT worksize);
extern INT co_clcisf_gc (FLOAT *x, FLOAT *y, FLOAT *z, INT npts, FLOAT *grid,
                         INT ncols, INT nrows, INT *workspace, INT worksize);
extern INT co_clciso_gc (FLOAT *x, FLOAT *y, FLOAT *z, INT npts, FLOAT *grid,
                         INT ncols, INT nrows, INT *workspace, INT worksize);
extern INT co_clcply_gc (FLOAT *x, FLOAT *y, INT npts, INT inside, DOUBLE znull,
                         FLOAT *grid, INT ncols, INT nrows);
extern INT co_clchgt_gc (FLOAT *xptrarr, FLOAT *yptarr, INT inmxyp, FLOAT *elvarr,
                         INT idmxcl, INT idmycl, FLOAT *hgtarr);
extern INT co_clc_grid_cells (CONTOURS *contours, INT *ncols, DOUBLE *xmin,
                              DOUBLE *xmax, INT *nrows, DOUBLE *ymin, DOUBLE *ymax);
extern INT co_conmap_gc (FLOAT *grid, INT ncols, INT nrows, INT *workspace,
                         INT workspace_size);
extern INT co_contour (CONTOURS *contours, FLOAT *grid, INT ncols, INT nrows);
extern INT co_contour_interval (CONTOURS *contours, NLIST_HEADER grid_nlist);
extern INT co_defflt_gc (INT fault_num, FLOAT *x, FLOAT *y, INT npts);
extern INT co_defgfl_gc (INT fault_num, FLOAT *x, FLOAT *y, INT npts);
extern INT co_delete_contour_nlists (FILENAME file);
extern INT co_endgrd_gc (void);
extern INT co_endplt_gc (void);
extern INT co_esichr_gc (FLOAT *charsize, INT nchar);
extern INT co_faulted_contour (FLOAT *grid, INT nrows, INT ncols);
extern INT co_faulted_grid (CONTOURS *contours, FLOAT *x, FLOAT *y, FLOAT *z, INT npts,
                            INT nrows, INT ncols, FLOAT *grid);
extern INT co_fltmap_gc (FLOAT *grid, INT ncols, INT nrows, INT *workspace,
                         INT workspace_size);
extern INT co_get_contour_limits (CONTOURS *contours, NLIST_HEADER grid_nlist,
                                  DOUBLE *contour_min, DOUBLE *contour_max);
extern INT co_get_con_info (CONTOURS *contours, DOUBLE *c_interval, INT *places);
extern INT co_get_grid_limits (CONTOURS *contours, FLOAT *scat_z, INT npts,
                               DOUBLE *grid_min, DOUBLE *grid_max);
extern INT co_grid (CONTOURS *contours, FLOAT *x, FLOAT *y, FLOAT *z, INT npts,
                    INT nrows, INT ncols, FLOAT *grid);
extern INT co_grid_size (CONTOURS *contours, FLOAT *x, FLOAT *y, INT npts);
extern INT co_make_contours (CONTOURS *contours);
extern INT co_make_grid (CONTOURS *contours);
extern INT co_overlay (INT display_line);
extern INT co_polygon (DOUBLE znull, FLOAT *x, FLOAT *y, FLOAT *z, INT npts, INT nrows,
                       INT ncols, DOUBLE xmin, DOUBLE xmax, DOUBLE ymin, DOUBLE ymax,
                       FLOAT *grid);
extern INT co_post_contours (CONTOURS *contours);
extern INT co_post_labels (FILENAME file_name, NLIST_HEADER in_lines,
                           NLIST_HEADER *out_lines, INT stroke, DOUBLE mins[2],
                           DOUBLE maxs[2], INT level);
extern INT co_setclb_gc (DOUBLE bgnlen, DOUBLE srcdst, DOUBLE angmax, DOUBLE dstmax);
extern INT co_setcon_gc (DOUBLE refelv, DOUBLE c_interval, INT b_interval,
                         INT l_interval, INT textsize, INT places);
extern INT co_setedg_gc (INT edge_flag);
extern INT co_setglg_gc (INT iflglg, INT funit);
extern INT co_setglm_gc (INT iflglm, DOUBLE zmin, DOUBLE zmax);
extern INT co_setgnl_gc (INT iflgnl, DOUBLE zptnul, DOUBLE ztoler);
extern INT co_setgrd_gc (INT ncols, DOUBLE xmin, DOUBLE xmax, INT nrows, DOUBLE ymin,
                         DOUBLE ymax);
extern INT co_setgrp_gc (INT iflgrp, INT funit, INT imxlne);
extern INT co_setnul_gc (INT null_flag, DOUBLE znull, DOUBLE tolerance);
extern INT co_setpag_gc (DOUBLE xpglen, DOUBLE ypglen, DOUBLE xpgoff, DOUBLE ypgoff);
extern INT co_setrpl_gc (INT iflrpl, INT funit);
extern INT co_setsep_gc (INT sepflg, DOUBLE bold_dist, DOUBLE light_dist);
extern INT co_setsmt_gc (INT smoothing_flag);
extern INT co_settik_gc (INT tickflag, INT tick_interval, DOUBLE tick_length,
                         DOUBLE tick_separation);
extern INT co_settxt (CONTOURS *contours, DOUBLE scale);
extern INT co_setwin_gc (DOUBLE xwnlen, DOUBLE ywnlen, DOUBLE xwnoff, DOUBLE ywnoff);
extern INT co_setxyg_gc (INT ncols, DOUBLE xmin, DOUBLE xmax, INT nrows, DOUBLE ymin,
                         DOUBLE ymax);
extern INT co_setzbd_gc (INT iflzbd, DOUBLE zbdmin, DOUBLE zbdmax);
extern INT co_set_faults (CONTOURS *contours, INT mode);
extern INT co_bgntrd_gc ();
extern INT co_clcidw_gc (INT ideg, INT inmxyz, INT *idmwrk);
extern INT co_clcpgd_gc (FLOAT *poly, INT idmply, INT ideg, FLOAT *elvarr, 
			 INT idmxcl, INT idmyrw);
extern INT co_clcres_gc (FLOAT *xa, FLOAT *ya, FLOAT *za, INT inmxyz, 
			 FLOAT *poly, INT idmply, INT ideg, FLOAT *zda);
extern INT co_endtrd_gc ();
extern INT co_setpgd_gc (INT inmxcl, DOUBLE xgdmin, DOUBLE xgdmax,
			 INT inmyrw, DOUBLE ygdmin, DOUBLE ygdmax);
extern INT co_settun_gc (INT iunlog, INT iflrpl);

#else
extern INT co_bgngrd_gc ();
extern INT co_bgnplt_gc ();
extern INT co_clcbnd_gc ();
extern INT co_clcflt_gc ();
extern INT co_clcgrd_gc ();
extern INT co_clcisf_gc ();
extern INT co_clciso_gc ();
extern INT co_clcply_gc ();
extern INT co_clc_grid_cells ();
extern INT co_conmap_gc ();
extern INT co_contour ();
extern INT co_contour_interval ();
extern INT co_defflt_gc ();
extern INT co_defgfl_gc ();
extern INT co_delete_contour_nlists ();
extern INT co_endgrd_gc ();
extern INT co_endplt_gc ();
extern INT co_esichr_gc ();
extern INT co_faulted_contour ();
extern INT co_faulted_grid ();
extern INT co_fltmap_gc ();
extern INT co_get_contour_limits ();
extern INT co_get_con_info ();
extern INT co_get_grid_limits ();
extern INT co_grid ();
extern INT co_grid_size ();
extern INT co_make_contours ();
extern INT co_make_grid ();
extern INT co_overlay ();
extern INT co_polygon ();
extern INT co_post_contours ();
extern INT co_post_labels ();
extern INT co_setclb_gc ();
extern INT co_setcon_gc ();
extern INT co_setedg_gc ();
extern INT co_setglg_gc ();
extern INT co_setglm_gc ();
extern INT co_setgnl_gc ();
extern INT co_setgrd_gc ();
extern INT co_setgrp_gc ();
extern INT co_setnul_gc ();
extern INT co_setpag_gc ();
extern INT co_setrpl_gc ();
extern INT co_setsep_gc ();
extern INT co_setsmt_gc ();
extern INT co_settik_gc ();
extern INT co_settxt ();
extern INT co_setwin_gc ();
extern INT co_setxyg_gc ();
extern INT co_setzbd_gc ();
extern INT co_clchgt_gc ();
extern INT co_set_faults ();
extern INT co_bgntrd_gc ();
extern INT co_clcidw_gc ();
extern INT co_clcpgd_gc ();
extern INT co_clcres_gc ();
extern INT co_endtrd_gc ();
extern INT co_setpgd_gc ();
extern INT co_settun_gc ();

#endif
#endif
