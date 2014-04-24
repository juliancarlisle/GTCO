/* DEC/CMS REPLACEMENT HISTORY, Element SYNGL_GLUE.C */
/* *5     9-AUG-1990 19:15:52 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *4     8-FEB-1990 17:03:34 GORDON "(SPR 0) Fix typo in Unix code" */
/* *3     7-FEB-1990 07:05:26 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    17-JAN-1990 23:24:03 GILLESPIE "(SPR 6001) Changes for new well struct stuff" */
/* *1    22-SEP-1989 16:19:44 GILLESPIE "Moved from CMSLIB" */
/* DEC/CMS REPLACEMENT HISTORY, Element SYNGL_GLUE.C */
/* DEC/CMS REPLACEMENT HISTORY, Element SYNGL_GLUE.C*/
/* *2    20-JUL-1989 08:38:22 GORDON "(SPR 100) Add mods from Sun port"*/
/* *1    19-JUN-1989 13:30:51 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SYNGL_GLUE.C*/

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
#include "esi_nl.h"
#include "esi_tc.h"
#include "esi_ts.h"
#include "esi_we_wells.h"
#include "esi_glue.h"
#include "esi_syn_syn.h"
/*
  synthetics glue from fortran driver to dialog boxes
*/

#ifdef vms

static CHAR string1[MAXLEN];

/***********************************************************************
 acoustic dialog box glue */

publicdef INT synacous_dialog_gl(rerun,icancel,parg)
INT *rerun;
INT *icancel;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synacous_dialog(*rerun,icancel,parg);
}

/***********************************************************************
 alternate density box glye */

publicdef INT synaltden_dialog_gl(rerun,icancel,fdccnl_avail,parg)
INT *rerun;
INT *icancel;
INT *fdccnl_avail;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synaltden_dialog(*rerun,icancel,*fdccnl_avail,psyn);
}

/***********************************************************************
 synfaust dialog box */

publicdef INT synfaust_dialog_gl(rerun,icancel,parg)
INT *rerun;
INT *icancel;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synfaust_dialog(*rerun,icancel,parg);
}


/***********************************************************************
 syngeneral dialog box */

publicdef INT syngeneral_dialog_gl(rerun,icancel,avgvel,maxdpt,ifeet,parg)
INT *rerun;
INT *icancel;
DOUBLE *avgvel;
INT *maxdpt;
INT *ifeet;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    syngeneral_dialog(*rerun,icancel,*avgvel,*maxdpt,*ifeet,psyn);
}

/***********************************************************************
 syn kelly dialog box */

publicdef INT synkelly_dialog_gl(rerun,icancel,parg)
INT *rerun;
INT *icancel;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synkelly_dialog(*rerun,icancel,parg);
}

/***********************************************************************
 syn straight dialog box */

publicdef INT synstraight_dialog_gl(rerun,icancel,parg)
INT *rerun;
INT *icancel;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synstraight_dialog(*rerun,icancel,parg);
}

/***********************************************************************
 menu open glue */

publicdef INT synmenu_gl(rs_menu_id,wi_menu_id)
INT *rs_menu_id;
INT *wi_menu_id;
{
    synmenu(*rs_menu_id,wi_menu_id);
}

/***********************************************************************
 cdlg open glue */

publicdef INT syncdlg_gl(rs_cdlg_id,wi_cdlg_id)
INT *rs_cdlg_id;
INT *wi_cdlg_id;
{
    syncdlg(*rs_cdlg_id,wi_cdlg_id);
}

/******************************************************************
Program:
	syn_getwell

Description:
	This is a glue routine that will allow Fortran programs to call
	the C function we_get_well_header.
******************************************************************/
publicdef VOID syn_getwell(request_uwi,name,operator, state,county,elevation,
				 township,twpns,range,rngew,section,status)
DSC             *request_uwi;
DSC             *name;
DSC             *operator;
DSC             *state;
DSC             *county;
INT             *elevation;
INT             *township;
DSC             *twpns;
INT             *range;
DSC             *rngew;
INT             *section;
INT             *status;
{
WELL_STRUCT     *pWell;
WELL_HDR_1	*pwell1;
UWI             r_uwi;

DSCTOCS(request_uwi, r_uwi);

*status = we_get_well_header(r_uwi, WELL_HDR_1_DETAIL, &pWell);

if(*status IS_NOT_EQUAL_TO SUCCESS)
    {
    return;
    }

pwell1 = (WELL_HDR_1 *)pWell -> detail.ptr;
CSTODSC(pwell1->tophole.state, state);

CSTODSC(pwell1->tophole.county, county);

CSTODSC(pwell1->tophole.twpns, twpns);

CSTODSC(pwell1->tophole.rngew, rngew);

CSTODSC(pwell1->name, name);

CSTODSC(pwell1->operator, operator);

*range = (pwell1->tophole.range == 0) ? -999: (INT)pwell1->tophole.range;
*elevation = (pwell1->elevation.value == 0) ? -999 : (INT)pwell1->elevation.value;
*township = (pwell1->tophole.township == 0) ? -999 : (INT)pwell1->tophole.township;
*section = (pwell1->tophole.section == 0) ? -999 : (INT)pwell1->tophole.section;
}

/***********************************************************************/
publicdef INT syn_status_message(string)
DSC *string;
{
    DSCTOCS(string,string1);
    syn_main_text(string1);
    return SUCCESS;
}

/***********************************************************************/
publicdef INT syn_get_checkshots_gf(uwi,status,ictime,ickdat,ncksht,cktime,
		       ckdept,ve, unit)
DSC *uwi;
INT *status,*ictime,*ickdat,*ncksht;
FLOAT *cktime,*ckdept,*ve, *unit;
{
    DSCTOCS(uwi,string1);
    we_get_checkshots(string1,status,ictime,ickdat,ncksht,cktime,
		      ckdept,ve, unit);
}

#endif                 /* End of VMS Code */

#if UNIX

static CHAR string1[MAXLEN];

/***********************************************************************
 acoustic dialog box glue */

publicdef INT synacous_dialog_gl_(rerun,icancel,parg)
INT *rerun;
INT *icancel;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synacous_dialog(*rerun,icancel,parg);
}

/***********************************************************************
 alternate density box glye */

publicdef INT synaltden_dialog_gl_(rerun,icancel,fdccnl_avail,parg)
INT *rerun;
INT *icancel;
INT *fdccnl_avail;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synaltden_dialog(*rerun,icancel,*fdccnl_avail,psyn);
}

/***********************************************************************
 synfaust dialog box */

publicdef INT synfaust_dialog_gl_(rerun,icancel,parg)
INT *rerun;
INT *icancel;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synfaust_dialog(*rerun,icancel,parg);
}


/***********************************************************************
 syngeneral dialog box */

publicdef INT syngeneral_dialog_gl_(rerun,icancel,avgvel,maxdpt,ifeet,parg)
INT *rerun;
INT *icancel;
DOUBLE *avgvel;
INT *maxdpt;
INT *ifeet;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    syngeneral_dialog(*rerun,icancel,*avgvel,*maxdpt,*ifeet,psyn);
}

/***********************************************************************
 syn kelly dialog box */

publicdef INT synkelly_dialog_gl_(rerun,icancel,parg)
INT *rerun;
INT *icancel;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synkelly_dialog(*rerun,icancel,parg);
}

/***********************************************************************
 syn straight dialog box */

publicdef INT synstraight_dialog_gl_(rerun,icancel,parg)
INT *rerun;
INT *icancel;
FLOAT *parg;
{
    SYNTH *psyn = (SYNTH *) parg;
    synstraight_dialog(*rerun,icancel,parg);
}

/***********************************************************************
 menu open glue */

publicdef INT synmenu_gl_(rs_menu_id,wi_menu_id)
INT *rs_menu_id;
INT *wi_menu_id;
{
    synmenu(*rs_menu_id,wi_menu_id);
}

/***********************************************************************
 cdlg open glue */

publicdef INT syncdlg_gl_(rs_cdlg_id,wi_cdlg_id)
INT *rs_cdlg_id;
INT *wi_cdlg_id;
{
    syncdlg(*rs_cdlg_id,wi_cdlg_id);
}

/******************************************************************
Program:
	syn_getwell

Description:
	This is a glue routine that will allow Fortran programs to call
	the C function we_get_well_header.
******************************************************************/
publicdef VOID syn_getwell_(request_uwi,name,operator, state,county,elevation,
				 township,twpns,range,rngew,section,status,
				 len1,len2,len3,len4,len5,len6,len7)
CHAR             *request_uwi;
CHAR             *name;
CHAR             *operator;
CHAR             *state;
CHAR             *county;
INT             *elevation;
INT             *township;
CHAR             *twpns;
INT             *range;
CHAR             *rngew;
INT             *section;
INT             *status;
INT	        len1, len2, len3, len4, len5, len6, len7;
{
WELL_STRUCT     *pWell;
WELL_HDR_1	*pwell1;
UWI             r_uwi;

ftocstr(request_uwi, r_uwi, len1);

*status = we_get_well_header(r_uwi, WELL_HDR_1_DETAIL, &pWell);

if(*status != SUCCESS)
    {
    return;
    }

pwell1 = (WELL_HDR_1 *)pWell -> detail.ptr;
ctofstr(name, pwell1->name, len2);

ctofstr(operator, pwell1->operator, len3);

ctofstr(state, pwell1->tophole.state, len4);

ctofstr(county, pwell1->tophole.county, len5);

ctofstr(twpns, pwell1->tophole.twpns, len6);

ctofstr(rngew, pwell1->tophole.rngew, len7);

*range = (pwell1->tophole.range == 0) ? -999: (INT)pwell1->tophole.range;
*elevation = (pwell1->elevation.value == 0) ? -999 : (INT)pwell1->elevation.value;
*township = (pwell1->tophole.township == 0) ? -999 : (INT)pwell1->tophole.township;
*section = (pwell1->tophole.section == 0) ? -999 : (INT)pwell1->tophole.section;
}

/***********************************************************************/
publicdef INT syn_status_message_(string, len1)
CHAR *string;
INT len1;
{
    ftocstr(string,string1,len1);
    syn_main_text(string1);
    return SUCCESS;
}

/***********************************************************************/
publicdef INT syn_get_checkshots_gf_(uwi,status,ictime,ickdat,ncksht,cktime,
		       ckdept,ve, unit,len1)
CHAR *uwi;
INT *status,*ictime,*ickdat,*ncksht;
FLOAT *cktime,*ckdept,*ve, *unit;
INT len1;
{
    ftocstr(uwi,string1,len1);
    we_get_checkshots(string1,status,ictime,ickdat,ncksht,cktime,
		      ckdept,ve, unit);
}

/**********************************************************************/
publicdef INT syn_main_dialog_()
{
	syn_main_dialog();
}

#endif                 /* End of UNIX Code */

#ifdef primos

static CHAR string1[MAXLEN];

/***********************************************************************
 acoustic dialog box glue */

INT synacous_dialog_gl(rerun,icancel,psyn)
INT rerun;
INT icancel;
SYNTH *psyn;
{
    return(synacous_dialog(rerun,&icancel,&psyn));
}

/***********************************************************************
 alternate density box glye */


publicdef INT synaltden_dialog_gl(rerun,icancel,fdccnl_avail,psyn)
INT rerun;
INT icancel;
INT fdccnl_avail;
SYNTH *psyn;
{
    return(synaltden_dialog(rerun,&icancel,fdccnl_avail,&psyn));
}

/* **********************************************************************
 synfaust dialog box */


publicdef INT synfaust_dialog_gl(rerun,icancel,psyn)
INT rerun;
INT icancel;
SYNTH *psyn;
{
    return(synfaust_dialog(rerun,&icancel,&psyn));
}

/***********************************************************************
 syngeneral dialog box */


publicdef INT syngeneral_dialog_gl(rerun,icancel,avgvel,maxdpt,ifeet,psyn)
INT rerun;
INT icancel;
DOUBLE avgvel;
INT maxdpt;
BOOL ifeet;
SYNTH *psyn;
{
    return(syngeneral_dialog(rerun,&icancel,avgvel,maxdpt,ifeet,
	&psyn));
}

/***********************************************************************
 syn kelly dialog box */


publicdef INT synkelly_dialog_gl(rerun,icancel,psyn)
INT rerun;
INT icancel;
SYNTH *psyn;
{
    return(synkelly_dialog(rerun,&icancel,&psyn));
}

/***********************************************************************
 syn straight dialog box */


publicdef INT synstraight_dialog_gl(rerun,icancel,psyn)
INT rerun;
INT icancel;
SYNTH *psyn;
{
    return(synstraight_dialog(rerun,&icancel,&psyn));
}

/***********************************************************************
 menu open glue */


publicdef INT synmenu_gl(rsrc_id,menu_id)
INT rsrc_id;
INT menu_id;
{
    extern INT synmenu();
    return(synmenu(rsrc_id,&menu_id));
}


/***********************************************************************
 cdlg open glue */

publicdef INT syncdlg_gl(rsrc_id,cdlg_id)
INT rsrc_id;
INT cdlg_id;
{
    return(syncdlg(rsrc_id,&cdlg_id));
}

/******************************************************************
Program:
	syn_getwell

Description:
	This is a glue routine that will allow Fortran programs to call
	the C function we_get_well_header.
******************************************************************/


publicdef VOID syn_getwell(request_uwi,name,operator, state,county,elevation,
				 township,twpns,range,rngew,section,status,
				 z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,z11,z12)
CHAR            request_uwi;
CHAR            name;
CHAR            operator;
CHAR            state;
CHAR            county;
INT             elevation;
INT             township;
CHAR            twpns;
INT             range;
CHAR            rngew;
INT             section;
INT             status;
INT             z1, z2, z3, z4, z5, z6, z7, z8, z9, z10, z11, z12;
{
WELL_STRUCT     *pWell;
WELL_HDR_1	*pwell1;
UWI             r_uwi;

ftocstr(&request_uwi, r_uwi, z1);

status = we_get_well_header(r_uwi, WELL_HDR_1_DETAIL, &pWell);

if (status != SUCCESS)
    {
    return;
    }

pwell1 = (WELL_HDR_1 *)pWell -> detail.ptr;
ctofstr(&state, pwell1->tophole.state, z4);
ctofstr(&county, pwell1->tophole.county, z5);
ctofstr(&twpns, pwell1->tophole.twpns, z8);
ctofstr(&rngew, pwell1->tophole.rngew, z10);
ctofstr(&name, pwell1->name, z2);
ctofstr(&operator, pwell1->operator, z3);

range = (pwell1->tophole.range == 0) ? -999: (INT)pwell1->tophole.range;
elevation = (pwell1->elevation.value == 0) ? -999 : (INT)pwell1->elevation.value;
township = (pwell1->tophole.township == 0) ? -999 : (INT)pwell1->tophole.township;
section = (pwell1->tophole.section == 0) ? -999 : (INT)pwell1->tophole.section;
status = SUCCESS;
}

/***********************************************************************/

publicdef INT syn_status_message(string,z1)
CHAR string;
INT z1;
{
    ftocstr(&string,string1,z1);
    syn_main_text(string1);
    return SUCCESS;
}


/***********************************************************************/

publicdef INT syn_get_checkshots_gf(uwi,status,ictime,ickdat,ncksht,cktime,
		       ckdept,ve,unit,z1)
CHAR uwi;
INT status,ictime,ickdat,ncksht;
FLOAT cktime,ckdept,ve,unit;
INT z1;
{
    ftocstr(&uwi, string1, z1);
    we_get_checkshots(string1,&status,&ictime,&ickdat,&ncksht,&cktime,
		      &ckdept,&ve,&unit);
}

/***********************************************************************/


publicdef INT syn_setups_gf(ifeet,isave,icancel)
INT ifeet;
INT isave;
INT icancel;
{
    return(syn_setups_dialog(&ifeet,&isave,&icancel));
}

#endif           /* End of Primos Code */
                                          
