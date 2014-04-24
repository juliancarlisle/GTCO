/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MO.H*/
/* *6    14-AUG-1990 11:49:34 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *5    17-JAN-1990 22:53:36 GILLESPIE "(SPR 6001) Add esi_gl_txdef.h"*/
/* *4    17-JAN-1990 22:24:14 GILLESPIE "(SPR 6001) Remove pad for UWI, since it now matches a longword boundary"*/
/* *3    19-SEP-1989 11:14:48 PURNA "(SPR 100) gulf mods"*/
/* *2    14-SEP-1989 18:14:43 GORDON "(SPR -1) checkin from gulf"*/
/* *1    30-JUN-1989 15:03:09 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_MO.H*/
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

#ifndef ESI_MO_H
#define ESI_MO_H 1
/*
 * file for defining the ESI stratigraphic modelling system
 */

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

#ifndef ESI_LL_H
#include "esi_ll.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_WE_WELLS_H
#include "esi_we_wells.h"
#endif

typedef struct  {
    INT point;
    FLOAT x;
    FLOAT y;
    FLOAT vel;
    FLOAT den;
    } MO_DATA_STRUCT;

typedef struct {
    INT   sed_type;       /* sedimentation type 1,2 or 3           */
    INT   num_sub_layers; /* number of sub layers (if blocked)     */
    FLOAT x;              /* coordinates of point picked on horizon*/
    FLOAT y;              /* -to define sed type                   */
    } SED_DATA_STRUCT;


#define MO_F77_SHUTDOWN (INT)-999
#define TRATX  12.0
#define TRATY  10.0
#define MINFROMTOP 10.0

typedef struct {
    DOUBLE x;
    WELL_STRUCT *pWell;
    } CSE_WELL;

typedef struct {
    UWI    uwi;
    DOUBLE x;
    } CSE_WELL_FTN;

#define WELL_TIE (INT)0
#define PURE_EMPIRICAL (INT)1



/*  NOTE: Since this struct is equivalenced in MO_STRUCT.I, this struct must
    match exactly since FORTRAN code will be accessing it.  Therefore, we
    must ensure that each struct element begin at the same byte offset on
    each possible host.  This is accomplished by providing "fill" elements
    at critical places whose size are calculated by subtracting the sizeof
    the given struct on the current host from the known size of the 
    corresponding FORTRAN common element, which, unfortunately, are currently
    hard-coded.  Therefore, it is imperative that no changes be made to this
    structure without making the necessary modifications to MO_STRUCT.I and
    the FORTRAN code which uses it.   5/5/89 GS  

    NUTS to this!  I rearranged the structure so that those elements
    references by FORTRAN are at the front, obviating the need for those
    &^$$^ filler elements JGG 8 Sept 89 */

typedef struct {
    DOUBLE log_start;
    CHAR   model_uom[12];         /* Model uom = project uom if well tie
				      = whatever user specifies if empirical */     LISTHEAD uwi_list;

    CHAR name[132];               /* name of this modelling file */
/*************** END OF mo_struct.i FORTRAN EQUIVALENCE SECTION ***************/

    CHAR crossdef_name[128];      /* name of cross section definition */
    INT model_type;               /* 0 = well tie
				     1 = pure empirical
				   */
    struct {
       NLIST_ID id;           /* id of n-List containing velocity */
       NLIST_HEADER nlist;        /* nlist structure */
       } velocity;


    struct {
       NLIST_ID id;           /* id of n-List containing model */
       NLIST_HEADER nlist;        /* nlist structure */
       } model;

    COLOR_INDEX background_color;
    LINE_ATTRIBUTE line;

    struct {
	 INT window_id;         /* window id */
	 INT transform_id;      /* window transform id */
	 INT transform_trat;    /* ha ha ha */
	 struct {               /* world coords of current window */
	    FLOAT xmin;
	    FLOAT xmax;
	    FLOAT ymin;
	    FLOAT ymax;
	    } world;
	 struct {               /* ndc coords of current window */
	    FLOAT xmin;
	    FLOAT xmax;
	    FLOAT ymin;
	    FLOAT ymax;
	    } norm_wind;

	 } graphics;

    INT nwells;
    LISTHEAD well_list;         /* list of CSE well structure pointers */

    struct {                    /* x limits of wells in list (first,last pts) */
       FLOAT xmin;
       FLOAT xmax;
       } well;

    INT main_dialog_id;
    INT main_menu_id;
    DOUBLE xscale;              /* x dimension scaling factor (ft/inch) */
    DOUBLE yscale;              /* y dimension scaling factor (ft/inch) */
    INT    need_to_save;
    INT    corr_group;
    INT    generate_model_onoff;
    INT    mo_data_entry_onoff;
    INT    mo_digitize_onoff;
    INT    mo_tieplot_onoff;
    INT    generate_traces_onoff;
    INT    mo_traces_onoff;
    COLOR_INDEX    hvels_color;
    COLOR_INDEX    hvels_cur_color;
    INT    grat_segment_id;        /* segment id of digitizing grid           */
    INT    xs_trk_grid_onoff;      /* = 1 if track grids on else = 0          */
    INT    grid_onoff;             /* = 1 if modelling grid on else = 0       */
    INT    faults_onoff;           /* = 1 if faults to be used in well model  */


/* N-LIST user structure for storing with the nlist model file so parameters
    can be restored as before when n-list file is retrieved                   */
/* Note that currently some data is duplicated from the beginning of the stru-
    cture to avoid renumbering the FORTRAN equivalences. This can be performed
    when the structure definition stabilizes (2006 A.D.)                      */

    struct {
       FLOAT    model_xmin;        /* coordinate of model boundaries, specif- */
       FLOAT    model_xmax;        /* in feet or meters                       */
       FLOAT    model_ymin;
       FLOAT    model_ymax;

       FLOAT    wcs_xmin;          /* model window world coordinates          */
       FLOAT    wcs_xmax;          /* also in feet or meters                  */
       FLOAT    wcs_ymin;
       FLOAT    wcs_ymax;

       CHAR     title[128];        /* model title-comment, whatever           */
       CHAR     depth_uom[11];     /* FEET or METERS                          */
       CHAR     trace_uom[11];     /* Sonic velocity uom, in case is different*/
				   /* from depth uom (Well Tie Only)          */
       FLOAT    depth_samp_rate;   /* depth sample rate for model calculations*/

       CHAR     layout_name[44];   /* well tie layout-for future auto retrieve*/
       CHAR     traverse_name[44]; /* well tie traverse name                  */
       INT      model_type;        /* well tie = 0 , empirical = 1            */
       } nl_user_struct;

    } STRAT_MODEL_STRUCT;


#if USE_PROTOTYPES

extern INT model_reset_text();                  /*need a glue routine*/
extern INT mo_check_save( STRAT_MODEL_STRUCT *pModel);
extern INT mo_data_entry(STRAT_MODEL_STRUCT *pModel);
extern INT mo_digitize_model(STRAT_MODEL_STRUCT *pMode);
extern INT mo_digitize_tab_control_points( FLOAT xy_tablet[][2]);
extern INT mo_draw_vels(STRAT_MODEL_STRUCT *pModel);
extern INT mo_free(STRAT_MODEL_STRUCT *pModel);
extern INT mo_get_emp_init_param(STRAT_MODEL_STRUCT *pModel);
extern INT mo_get_tab_control_points( FLOAT xy_cntl[3][2]);
extern INT mo_graticule(STRAT_MODEL_STRUCT *pModel,DOUBLE *x_grid_int,
			DOUBLE *y_grid_int);
extern INT mo_init_empirical(STRAT_MODEL_STRUCT *pModel);
extern INT mo_init_well_tie(STRAT_MODEL_STRUCT *pModel);
extern INT mo_main_dialog_server(INT cdlgid,INT item,
				 STRAT_MODEL_STRUCT *pModel);
extern INT mo_main_menu_server(INT menuid,INT item,STRAT_MODEL_STRUCT *pModel);
extern INT mo_mark_layer_ends(STRAT_MODEL_STRUCT *pModel,NLIST_HEADER nlist);
extern INT mo_mark_sed_type(STRAT_MODEL_STRUCT  *pModel,NLIST_HEADER nlist);
extern INT mo_open_model(STRAT_MODEL_STRUCT *pModel);
extern INT mo_register_segment( STRAT_MODEL_STRUCT  *pModel);
extern INT mo_save_model(STRAT_MODEL_STRUCT *pModel);
extern INT mo_select_model( STRAT_MODEL_STRUCT *pModel, CHAR *dir);
extern INT mo_sort_strokes(NLIST_HEADER *nlist);

#else

extern INT mo_main_menu_server();
extern INT mo_save_model();
extern INT mo_digitize_model();
extern INT mo_register_segment();
extern INT mo_digitize_tab_control_points();
extern INT mo_get_tab_control_points();
extern INT mo_main_menu_server();
extern INT mo_main_dialog_server();
extern INT mo_check_save();
extern INT mo_select_model();
extern INT mo_open_model();
extern INT mo_data_entry();
extern INT mo_sort_strokes();
extern INT mo_draw_vels();
extern INT model_reset_text();                  /*need a glue routine*/
extern INT mo_free();
extern INT mo_init_well_tie();
extern INT mo_init_empirical();
extern INT mo_get_emp_init_param();
extern INT mo_graticule();
extern INT mo_mark_layer_ends();
extern INT mo_mark_sed_type();

#endif

#endif
                                                            
