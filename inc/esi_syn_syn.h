/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SYN_SYN.H*/
/* *2    14-AUG-1990 11:51:13 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:04:47 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SYN_SYN.H*/
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


#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#define SYNTH struct synthetic
SYNTH {
/*
    FAUST VARIABLES
*/
FLOAT faust_constant;
INT   faust;
INT   id_faust;
/*
    ALTERNATE DENSITY SOURCE VARIABLES
*/
INT   altden_calc_den_vel;
INT   altden_calc_den_fdccnl;
FLOAT altden_fluid;
FLOAT altden_matrix;
INT   id_altden;
/*
    ACOUSTIC IMPEDANCE VARIABLES
*/
INT   acous;
INT acous_min_freq;
INT acous_max_freq;
INT id_acous;
/*
    GENERAL SETUP PARAMETERS
*/
INT   general_multi;
FLOAT general_multi_coef;
INT   general_agc;
INT   general_agc_length;
INT   general_td_print;
INT   general_nfilt;
INT   general_datum;
FLOAT general_veloc;
INT   id_general;
/*
    KELLY BUSHING INFO
*/
INT   kelly_estimated;
INT   kelly_elevation;
INT   id_kelly;
/*
    USE A VELOCITY SURVEY FROM ANOTHER WELL
*/
INT   velanother_use;
INT   id_velanother;
/*
   RICKER WAVELET INFO
*/
INT   ricker_draw;
INT   ricker_type;
INT   ricker_length_taper;
INT   ricker_time1;
INT   ricker_time2;
INT   ricker_time3;
INT   ricker_freq1;
INT   ricker_freq2;
INT   ricker_freq3;
INT   id_ricker;
/*
   HALF CYCLE COSINE INFO
*/
INT   cosine_draw;
INT   cosine_length_taper;
INT   cosine_time1;
INT   cosine_time2;
INT   cosine_time3;
INT   cosine_min_freq1;
INT   cosine_min_freq2;
INT   cosine_min_freq3;
INT   cosine_max_freq1;
INT   cosine_max_freq2;
INT   cosine_max_freq3;
FLOAT cosine_phase;
INT   id_cosine;
/*
 miscellaneous synthetic variables needed in dialog boxes
*/
INT   iekb;
INT   itmax;
/*
STRAIGHT DIALOG BOX
*/
INT   straight_use;
FLOAT straight_vel;
INT   id_straight;
/*
WAVELET DIALOG BOX
*/
INT   wavelet_type;
INT   id_wavelet;
};
