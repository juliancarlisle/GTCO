/* DEC/CMS REPLACEMENT HISTORY, Element SYQPLOTDRIVER.C*/
/* *3    28-AUG-1990 12:19:41 VINCE "(SPR 1) changed initialization of desc to prevent compiler messages"*/
/* *2     9-AUG-1990 19:16:00 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef"*/
/* *1     8-JUN-1990 10:06:44 GILLESPIE "Moved from cmslib"*/
/* DEC/CMS REPLACEMENT HISTORY, Element SYQPLOTDRIVER.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element SYQPLOTDRIVER.C*/
/* *1    19-JUN-1989 13:31:04 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SYQPLOTDRIVER.C*/

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

/********************************************************************
*      Copyright 1988, Exploration Systems Inc. San Francisco
*
* FUNCTION:  SYG_PLOT_DRIVER
*
* SYNOPSIS:  INT syg_plot_driver( paramfile )
*	     PATHNAME param_file;      Name of parameter file to read
*
* DESCRIPTION: Glue file to allow syn_plotter.c to call syn_plot_driver.for
*	       with an argument.
*
* RETURNS: SUCCESS
*
* 01/05/89 GS - created
*********************************************************************/
#include "esi_gl_defs.h"
#include "esi_ho_files.h"
#include "esi_glue.h"

publicdef INT syg_plot_driver( paramfile )
PATHNAME paramfile;
{
#ifdef vms

    struct dsc$descriptor_s desc;

    desc.dsc$w_length  = strlen(paramfile);
    desc.dsc$b_dtype   = DSC$K_DTYPE_T;
    desc.dsc$b_class   = DSC$K_CLASS_S;
    desc.dsc$a_pointer = paramfile;

    syn_plot_driver( &desc );

#endif
#ifdef primos

    fortran syn_plot_driver();
    syn_plot_driver( (CHAR [])paramfile, strlen(paramfile) );

#endif

    return SUCCESS;
}
