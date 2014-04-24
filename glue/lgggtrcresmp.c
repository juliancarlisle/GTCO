/* DEC/CMS REPLACEMENT HISTORY, Element LGGGTRCRESMP.C */
/* *3     9-AUG-1990 19:07:39 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     5-MAR-1990 13:54:00 WALTERS "(SPR 6012) Change file name to UNIX standards" */
/* *1     5-MAR-1990 13:46:33 GILLESPIE "Rename files for Unix (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element LGGGTRCRESMP.C */
#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif

#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifdef vms

/******************************************************************

Program:
		lgg_get_trace_resamp

Description:
		Glue routine to allow fortran routines to call
		lg_get_trace_resamp.c.

******************************************************************/
publicdef VOID lgg_ltdm_get_trace_resamp(uwi,trace_name,depth_type,
			    top,base,incr,
			    incr_uom,curve_uom,start,npts,
			    null,array,status)
DSC             *uwi;                           /* input */
DSC             *trace_name;                    /* input */
DSC             *depth_type;                    /* input */
FLOAT           *top;                           /* input */
FLOAT           *base;                          /* input */
FLOAT           *incr;                          /* input */
DSC             *incr_uom;                      /* input */
DSC             *curve_uom;                     /* input */
FLOAT           *start;                         /* out */
INT             *npts;                          /* out */
FLOAT           *null;                          /* out */
FLOAT           *array;                         /* out */
INT             *status;                        /* out */
{

LOG_TRACE_STRUCT        *pLog, *pLog_temp;
UINT ndim,i;
UINT Dim_List[2];
VOIDPTR Value_List[2];
FLOAT local_incr;
DOUBLE incr_scalar=1.0 , curve_scalar=1.0;
CHAR depth_units[21];
CHAR depth_type_cs[21];
CHAR trace_units[21];
BOOL depth_uom_conversion;
pLog = ALLOCATE(LOG_TRACE_STRUCT);
pLog_temp = ALLOCATE(LOG_TRACE_STRUCT);

DSCTOCS(uwi,pLog->uwi);
DSCTOCS(trace_name,pLog->trace_name);
DSCTOCS(incr_uom,depth_units);
DSCTOCS(depth_type, depth_type_cs);
DSCTOCS(curve_uom,trace_units);

pLog->top  = *top;
pLog->base = *base;

*status = lg_ltdm_inq_trace_struct(pLog -> uwi, pLog -> trace_name,
			depth_type_cs, pLog_temp);
if(*status IS_NOT_EQUAL_TO SUCCESS)
	{
	tc_free((BYTE *)pLog);
	return;
	}
pLog->depth_type = pLog_temp -> depth_type;

if(tu_unit_conversion((DOUBLE) (*incr),depth_units,&local_incr,
						pLog_temp ->depth_uom) == SUCCESS)
    {
     depth_uom_conversion = TRUE;
    }
    else
    {
     depth_uom_conversion = FALSE;
     local_incr = *incr;
    }

    tc_free( (BYTE *)pLog_temp );
pLog->top  = *top;
pLog->base = *base;
pLog->dinc = local_incr;

*status = lg_ltdm_get_trace_resamp(pLog);
*status = nl_inq_nlist_int(pLog->ptrace, NL_NLIST_NPOINTS, npts);

if (*status IS_NOT_EQUAL_TO SUCCESS OR *npts == 0)
	{
	tc_free((BYTE *)pLog);
	*status = FAIL;
	return;
	}


ndim = 1;
Dim_List[0] = 2;
Value_List[0] = (VOIDPTR)null;

nl_inq_nlist_info(pLog->ptrace, NL_NLIST_NULL_VALUE, ndim, Dim_List,
		  Value_List);

Value_List[0] = (VOIDPTR)array;
nl_set_current_point(pLog->ptrace,1,1);
nl_get_points(pLog->ptrace, (UINT)*npts, ndim, Dim_List, Value_List, 
    (UINT*)npts);

if(tu_unit_conversion((DOUBLE)(1.0), pLog->trace_uom, &local_incr, trace_units )
   == SUCCESS AND local_incr != 1.0)
    {

    for(i=0;i < *npts;i++)
	{
	array[i] *= local_incr;
	}
    }

Value_List[0] = (VOIDPTR)start;
Dim_List[0] = 1;
nl_first_point(pLog->ptrace, ndim, Dim_List, Value_List);

if(depth_uom_conversion AND
   tu_unit_conversion((DOUBLE) (*start), pLog->depth_uom, &local_incr, depth_units)
     == SUCCESS)
    {
     *start = local_incr;
    }

lg_ltdm_free_trace(pLog);
*status = SUCCESS;

}


#endif          /* end of VMS code */

#if UNIX

/******************************************************************

Program:
		lgg_get_trace_resamp

Description:
		Glue routine to allow fortran routines to call
		lg_get_trace_resamp.c.

******************************************************************/
publicdef VOID lgg_ltdm_get_trace_resamp_(uwi,trace_name,depth_type,
			    top,base,incr,
			    incr_uom,curve_uom,start,npts,
			    null,array,status,len1,len2,len3,len4,len5)
CHAR             *uwi;                           /* input */
CHAR             *trace_name;                    /* input */
CHAR             *depth_type;                    /* input */
FLOAT           *top;                           /* input */
FLOAT           *base;                          /* input */
FLOAT           *incr;                          /* input */
CHAR             *incr_uom;                      /* input */
CHAR             *curve_uom;                     /* input */
FLOAT           *start;                         /* out */
INT             *npts;                          /* out */
FLOAT           *null;                          /* out */
FLOAT           *array;                         /* out */
INT             *status;                        /* out */
INT len1,len2,len3,len4,len5;	/* lengths of strings */
{

LOG_TRACE_STRUCT        *pLog, *pLog_temp;
UINT ndim,i;
UINT Dim_List[2];
VOIDPTR Value_List[2];
FLOAT local_incr;
DOUBLE incr_scalar=1.0 , curve_scalar=1.0;
CHAR depth_units[21];
CHAR depth_type_cs[21];
CHAR trace_units[21];
BOOL depth_uom_conversion;
pLog = ALLOCATE(LOG_TRACE_STRUCT);
pLog_temp = ALLOCATE(LOG_TRACE_STRUCT);

ftocstr(uwi,pLog->uwi,len1);
ftocstr(trace_name,pLog->trace_name,len2);
ftocstr(incr_uom,depth_units,len4);
ftocstr(depth_type, depth_type_cs,len3);
ftocstr(curve_uom,trace_units,len5);

pLog->top  = *top;
pLog->base = *base;

*status = lg_ltdm_inq_trace_struct(pLog -> uwi, pLog -> trace_name,
			depth_type_cs, pLog_temp);
if(*status IS_NOT_EQUAL_TO SUCCESS)
	{
	tc_free((BYTE *)pLog);
	return;
	}
pLog->depth_type = pLog_temp -> depth_type;

if(tu_unit_conversion((DOUBLE) (*incr),depth_units,&local_incr,
						pLog_temp ->depth_uom) == SUCCESS)
    {
     depth_uom_conversion = TRUE;
    }
    else
    {
     depth_uom_conversion = FALSE;
     local_incr = *incr;
    }

    tc_free( (BYTE *)pLog_temp );
pLog->top  = *top;
pLog->base = *base;
pLog->dinc = local_incr;

*status = lg_ltdm_get_trace_resamp(pLog);
*status = nl_inq_nlist_int(pLog->ptrace, NL_NLIST_NPOINTS, npts);

if (*status != SUCCESS OR *npts == 0)
	{
	tc_free((BYTE *)pLog);
	*status = FAIL;
	return;
	}


ndim = 1;
Dim_List[0] = 2;
Value_List[0] = (VOIDPTR)null;

nl_inq_nlist_info(pLog->ptrace, NL_NLIST_NULL_VALUE, ndim, Dim_List,
		  Value_List);

Value_List[0] = (VOIDPTR)array;
nl_set_current_point(pLog->ptrace,1,1);
nl_get_points(pLog->ptrace, *npts, ndim, Dim_List, Value_List, npts);

if(tu_unit_conversion((DOUBLE)(1.0), pLog->trace_uom, &local_incr, trace_units )
   == SUCCESS AND local_incr != 1.0)
    {

    for(i=0;i < *npts;i++)
	{
	array[i] *= local_incr;
	}
    }

Value_List[0] = (VOIDPTR)start;
Dim_List[0] = 1;
nl_first_point(pLog->ptrace, ndim, Dim_List, Value_List);

if(depth_uom_conversion AND
   tu_unit_conversion((DOUBLE) (*start), pLog->depth_uom, &local_incr, depth_units)
     == SUCCESS)
    {
     *start = local_incr;
    }

lg_ltdm_free_trace(pLog);
*status = SUCCESS;

}

#endif          /* end of UNIX code */

#ifdef primos

privatedef VOID lg_ltdm_get_trace_resamp_cvt();

/******************************************************************

Program:
		lg_ltdm_get_trace_resamp_cvt

Description:
		routine to allow fortran routines to call
		lg_ltdm_get_trace_resamp

******************************************************************/
privatedef VOID lg_ltdm_get_trace_resamp_cvt(uwi,trace_name,depth_type,
			    top,base,incr,
			    incr_uom,curve_uom,start,npts,
			    null,array,status)
CHAR            *uwi;                           /* input */
CHAR            *trace_name;                    /* input */
CHAR            *depth_type;                    /* input */
FLOAT           *top;                            /* input */
FLOAT           *base;                           /* input */
FLOAT           *incr;                          /* input */
CHAR            *incr_uom;                      /* input */
CHAR            *curve_uom;                     /* input */
FLOAT           *start;                         /* out */
INT             *npts;                          /* out */
FLOAT           *null;                          /* out */
FLOAT           *array;                         /* out */
INT             *status;                        /* out */
{

LOG_TRACE_STRUCT        *pLog, *pLog_temp;
INT ndim,i;
INT Dim_List[2];
VOIDPTR Value_List[2];
FLOAT local_incr;
FLOAT  flt_incr;
DOUBLE incr_scalar=1.0 , curve_scalar=1.0;
CHAR depth_units[21];
CHAR trace_units[21];
CHAR depth_type_cs[21];
BOOL depth_uom_conversion;
pLog = ALLOCATE(LOG_TRACE_STRUCT);
pLog_temp = ALLOCATE(LOG_TRACE_STRUCT);

strcpy(pLog->uwi,uwi);
strcpy(pLog->trace_name,trace_name);
strcpy(depth_units,incr_uom);
strcpy(trace_units,curve_uom);
strcpy(depth_type_cs,depth_type);

pLog->top  = *top;
pLog->base = *base;

*status = lg_ltdm_inq_trace_struct(pLog -> uwi, pLog -> trace_name,
			depth_type_cs, pLog_temp);
if(*status IS_NOT_EQUAL_TO SUCCESS)
	{
	tc_free(pLog);
	return;
	}

pLog->depth_type = pLog_temp -> depth_type;

if(tu_unit_conversion((DOUBLE) (*incr),depth_units,&local_incr,
						pLog_temp ->depth_uom) == SUCCESS)
    {
     depth_uom_conversion = TRUE;
    }
    else
    {
     depth_uom_conversion = FALSE;
     local_incr = *incr;
    }

    tc_free( pLog_temp );
pLog->top  = *top;
pLog->base = *base;
pLog->dinc = local_incr;

*status = lg_ltdm_get_trace_resamp(pLog);
*status = nl_inq_nlist_int(pLog->ptrace, NL_NLIST_NPOINTS, npts);

if (*status IS_NOT_EQUAL_TO SUCCESS OR *npts == 0)
	{
	tc_free(pLog);
	*status = FAIL;
	return;
	}


ndim = 1;
Dim_List[0] = 2;
Value_List[0] = (VOIDPTR)null;

nl_inq_nlist_info(pLog->ptrace, NL_NLIST_NULL_VALUE, ndim, Dim_List,
		  Value_List);

Value_List[0] = (VOIDPTR)array;
nl_set_current_point(pLog->ptrace,1,1);
nl_get_points(pLog->ptrace, *npts, ndim, Dim_List, Value_List, npts);

if(tu_unit_conversion((DOUBLE)(1.0), pLog->trace_uom, &local_incr, trace_units )
   == SUCCESS AND local_incr != 1.0)
    {

    for(i=0;i < *npts;i++)
	{
	array[i] *= local_incr;
	}
    }

Value_List[0] = (VOIDPTR)start;
Dim_List[0] = 1;
nl_first_point(pLog->ptrace, ndim, Dim_List, Value_List);

if(depth_uom_conversion AND
   tu_unit_conversion((DOUBLE) (*start), pLog->depth_uom, &local_incr, depth_units)
     == SUCCESS)
    {
     *start = local_incr;
    }

lg_ltdm_free_trace(pLog);
*status = SUCCESS;

}


/*******************************************************************************
 lg_ltdm_get_trace_resamp_cvt */

publicdef VOID lgg_ltdm_get_trace_resamp(uwi,trace_name,depth_type,
			top,base,incr,
			incr_uom,curve_uom,start,npts,
			null,array,status,
			z1,z2,z3,z4,z5,z6,z7,z8)
CHAR  uwi;
CHAR  trace_name;
CHAR  depth_type;
FLOAT top;
FLOAT base;
FLOAT incr;
CHAR  incr_uom;
CHAR  curve_uom;
FLOAT start;
INT   npts;
FLOAT null;
FLOAT array;
INT   status;
INT   z1,z2,z3,z4,z5,z6,z7,z8;
{
    CHAR string1[MAXLEN];
    CHAR string2[MAXLEN];
    CHAR string3[MAXLEN];
    CHAR string4[MAXLEN];
    CHAR string5[MAXLEN];

    ftocstr((CHAR *)&uwi,string1,z1);
    ftocstr((CHAR *)&trace_name,string2,z2);
    ftocstr((CHAR *)&depth_type,string3,z3);
    ftocstr((CHAR *)&incr_uom,string4,z7);
    ftocstr((CHAR *)&curve_uom,string5,z8);
    lg_ltdm_get_trace_resamp_cvt(string1,string2,string3,&top,&base,&incr,
	string4,string5,&start,&npts,&null,&array,&status);
    ctofstr((CHAR *)&uwi,string1,z1);
    ctofstr((CHAR *)&trace_name,string2,z2);
    ctofstr((CHAR *)&depth_type,string3,z3);
    ctofstr((CHAR *)&incr_uom,string4,z7);
    ctofstr((CHAR *)&curve_uom,string5,z8);
    return;
}


#endif       /* end of Primos code */
                                                                                                                             
