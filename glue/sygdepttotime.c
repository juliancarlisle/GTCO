/* DEC/CMS REPLACEMENT HISTORY, Element SYGDEPTTOTIME.C*/
/* *2     9-AUG-1990 19:15:46 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *1     8-JUN-1990 10:06:38 GILLESPIE "Moved from cmslib"*/
/* DEC/CMS REPLACEMENT HISTORY, Element SYGDEPTTOTIME.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element SYGDEPTTOTIME.C*/
/* *1    19-JUN-1989 13:30:47 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SYGDEPTTOTIME.C*/

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

/****************************************************************************
*                                                                           *
*                       Compagnie Generale de Geophysique                   * 
*                                                                           * 
****************************  Copyright C.G.G.  *****************************
*                                                                           *
*   NAME       : SYG_DEPTH_TO_TIME                                          *
*                                                                           *
*   SYNOPSIS   : SYG_DEPTH_TO_TIME(well_name,dptop,tmtop,tmuom,		    *
*				   nbtops,status)			    *
*                                                                           *
*                                                                           *
*   LANGUAGE   : C          					            *
*                                                                           *
*   PURPOSE    : Glue routine that get time conversion from depth	    *
*		 for well tops						    *
*									    *
*                                                                           *
*   INPUT PARAMETERS     : WELL_NAME : Name of the well for which we look   *
*				       fo the tops list			    *
*                          DPTOP     : Depth table for tops	            *
*                          TMTOP     : Time table for tops	            *
*                          NBTOPS    : Number of top retrieved              *
*                                                                           *
*    OUTPUT PARAMETERS   : STATUS   :STATUS RETURNED			    *
*				    = 0 SUCCESS  ,   #0 ERROR               *
*                                                                           *
*   SUBROUTINE(S) CALLED : NONE                                             *
*								            *
*                                                                           *
*   REMARKS    :                                                            *
*                                                                           *
*   AUTHOR     :  Joseph SASSON                                             *
*                                                                           *
*   DATE       :  SEPTEMBER 1988                                            *
*                                                                           *
*   MODIFICATIONS        :                                                  *
*                                                                           *
****************************************************************************/

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifdef vms
publicdef INT syg_depth_to_time (well_name,dptop,tmtop,tmuom,nbtops,status)

 INT  *status, *nbtops  ;
 DSC  *well_name ;
 DSC  *tmuom ;
 FLOAT *dptop ;
 FLOAT *tmtop ;
  
 {

    CHAR well_name1[20] ;
    CHAR tmuom1[20] ;

        DSCTOCS ( well_name , well_name1 ) ;
        DSCTOCS ( tmuom , tmuom1 ) ;

        *status =  sy_depth_to_time (well_name1,dptop,tmtop,tmuom1,*nbtops) ;

        return *status;

}
#endif
