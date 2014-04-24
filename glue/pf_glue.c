/* DEC/CMS REPLACEMENT HISTORY, Element PF_GLUE.C */
/* *4     9-AUG-1990 19:13:58 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:04:42 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 15:59:28 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:49:50 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element PF_GLUE.C */
/* DEC/CMS REPLACEMENT HISTORY, Element PF_GLUE.C*/
/* *1    19-JUN-1989 13:22:25 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element PF_GLUE.C*/

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

#include "esi_gl_defs.h"
#ifndef ESI_HO_H
#include "esi_ho.h"
#endif
#ifndef ESI_PF_H
#include "esi_pf.h"
#endif
#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif
#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

/******************************************************************
* Exploration Systems (C), 1988. San Francsico Ca. 94117
*
* Fortran Glue for the PF_XXX Series of routines.
*
* Julian Carlisle  May 21, 1988
* 11/21/88 GS - added Primos glue, function scope
*
*******************************************************************/
#ifdef vms

publicdef VOID pfgl_get_plotter(driver, queue, pstatus,npens,xsize,ysize,status)
DSC *driver;
DSC *queue;
DSC *pstatus;
INT *npens;
FLOAT *xsize,*ysize;
INT *status;
{
CHAR selected_plotter[128];
PDS  *pinfo;
INT pf_status = SUCCESS;


    pinfo = (PDS *)tc_zalloc(sizeof(PDS));
/* commenting out duplicate call (have to accept plotter twice) cep */
/*    pf_status = pf_get_plotter(pinfo); */

    if ((pf_status = pf_get_plotter(pinfo)) != FAIL)
	{
	*status = pf_status;
	CSTODSC(pinfo->driver,driver);
	CSTODSC(pinfo->queue,queue);
	CSTODSC(pinfo->status,pstatus);
	*npens = pinfo->pens;
	*xsize = pinfo->xsize;
	*ysize =pinfo->ysize;
	}
tc_free(pinfo);
return;
}

#endif

#if UNIX

publicdef VOID pfgl_get_plotter_(driver, queue, pstatus,npens,xsize,
		ysize,status,len1,len2,len3)
CHAR *driver;
CHAR *queue;
CHAR *pstatus;
INT *npens;
FLOAT *xsize,*ysize;
INT *status;
INT len1, len2, len3;
{
CHAR selected_plotter[128];
PDS  *pinfo;
INT pf_status = SUCCESS;


    pinfo = (PDS *)tc_zalloc(sizeof(PDS));

    if ((pf_status = pf_get_plotter(pinfo)) != FAIL)
	{
	*status = pf_status;
	ctofstr(driver,pinfo->driver,len1);
	ctofstr(queue,pinfo->queue,len2);
	ctofstr(pstatus,pinfo->status,len3);
	*npens = pinfo->pens;
	*xsize = pinfo->xsize;
	*ysize =pinfo->ysize;
	}
tc_free(pinfo);
return;
}

#endif

#ifdef primos

publicdef VOID pfgl_get_plotter(driver, queue, pstatus,npens,xsize,ysize,
		 status, len1, len2, len3)
CHAR driver;
CHAR queue;
CHAR pstatus;
INT npens;
FLOAT xsize,ysize;
INT status;
INT len1, len2, len3;
{
CHAR selected_plotter[128];
PDS  *pinfo;
INT pf_status = SUCCESS;

    pinfo = (PDS *)tc_zalloc(sizeof(PDS));

    if ((pf_status = pf_get_plotter(pinfo)) != FAIL)
	{
	status = pf_status;
	ctofstr(&driver,pinfo->driver,len1);
	ctofstr(&queue,pinfo->queue,len2);
	ctofstr(&pstatus,pinfo->status,len3);
	npens = pinfo->pens;
	xsize = pinfo->xsize;
	ysize = pinfo->ysize;
	}
tc_free(pinfo);
return;
}

#endif
                                                       
