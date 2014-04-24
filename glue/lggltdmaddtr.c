/* DEC/CMS REPLACEMENT HISTORY, Element LGGLTDMADDTR.C */
/* *3     9-AUG-1990 19:07:45 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     5-MAR-1990 13:54:06 WALTERS "(SPR 6012) Change file name to UNIX standards" */
/* *1     5-MAR-1990 13:46:38 GILLESPIE "Rename files for Unix (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element LGGLTDMADDTR.C */
#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#define NDIM 2

#ifdef vms

#define BLOCKSIZE (INT)50
/******************************************************************

Program:
	lgg_ltdm_add_trace

Description:
	This is a glue routine that will allow fortran programs
	to call the C function lg_ltdm_add_trace.

******************************************************************/
publicdef VOID lgg_ltdm_add_trace(uwi,trace_name,top,incr,npts,depth_or_time,
			  user_struct,size_of_user_struct,comment,
			  depth_uom,trace_uom,null_value,array,status)

DSC     *uwi;                                   /*in*/
DSC     *trace_name;                            /*in*/
FLOAT   *top;                                   /*in*/
FLOAT   *incr;                                  /*in*/
INT     *npts;                                  /*in*/
DSC     *depth_or_time;                         /*in*/
FLOAT   *user_struct;                           /*in*/
INT     *size_of_user_struct;                   /*in*/
DSC     *comment;                               /*in*/
DSC     *depth_uom;                             /*in*/
DSC     *trace_uom;                             /*in*/
FLOAT   *null_value;                            /*in*/
FLOAT   *array;                                 /*in*/
INT     *status;                                /*out*/
{

LOG_TRACE_STRUCT        Log;
LOG_TRACE_STRUCT        *pLog = &Log;
INT i;
privatedef INT Units[NDIM] = {0,0};
privatedef INT DataType[NDIM] = {FLOAT_TYPE, FLOAT_TYPE};
privatedef size_t DataSize[NDIM] = {sizeof(FLOAT), sizeof(FLOAT)};
privatedef INT ValueInc[NDIM] = {INCREMENT_LIST, VALUE_LIST};
UINT ndim = NDIM;
UINT stroke_num;
UINT Dim_List[1];
VOIDPTR Value_List[1];
FLOAT x;

if(*npts EQUALS 0)
	{
	*status = FAIL;
	return;
	}

DSCTOCS(uwi,pLog->uwi);
DSCTOCS(trace_name,pLog->trace_name);
DSCTOCS(depth_or_time,pLog->depth_or_time);
DSCTOCS(comment,pLog->comments);
DSCTOCS(depth_uom,pLog->depth_uom);
DSCTOCS(trace_uom,pLog->trace_uom);

pLog->top  = *top;
pLog->dinc = *incr;

nl_init_nlist(&pLog->ptrace, ndim, Units, DataSize, DataType, ValueInc,
	      BLOCKSIZE);

ndim          = 1;

					/*  Set the null value.   */

Dim_List[0]   = 2;
x             = *null_value;
Value_List[0] = (VOIDPTR)&x;
nl_set_nlist_info(pLog->ptrace,NL_NLIST_NULL_VALUE,ndim,Dim_List,Value_List);

nl_start_stroke(pLog->ptrace,&stroke_num);
if (*size_of_user_struct IS_NOT_EQUAL_TO 0)
	{
	nl_set_nlist_user_struct(pLog->ptrace, user_struct,
				 *size_of_user_struct);
	}

x = *top;
Value_List[0] = (VOIDPTR)&x;
Dim_List[0] = 1;
nl_set_stroke_info(pLog->ptrace, 0, NL_STROKE_START_VALUE, ndim,
					Dim_List, Value_List);
x = *incr;
nl_set_stroke_info(pLog->ptrace, 0, NL_STROKE_INCREMENT, ndim,
					Dim_List, Value_List);

Dim_List[0] = 2;
Value_List[0] = (VOIDPTR)array;
nl_add_points(pLog->ptrace, *npts, ndim, Dim_List, Value_List);

*status = lg_ltdm_add_trace(pLog);

nl_free_nlist(pLog->ptrace);

}

#endif          /* end of VMS code */

#if UNIX

#define BLOCKSIZE (INT)20
/******************************************************************

Program:
	lgg_ltdm_add_trace

Description:
	This is a glue routine that will allow fortran programs
	to call the C function lg_ltdm_add_trace.

******************************************************************/
publicdef VOID lgg_ltdm_add_trace_(uwi,trace_name,top,incr,npts,depth_or_time,
			  user_struct,size_of_user_struct,comment,
			  depth_uom,trace_uom,null_value,array,status,
			  len1,len2,len3,len4,len5,len6)

CHAR     *uwi;                                   /*in*/
CHAR     *trace_name;                            /*in*/
FLOAT   *top;                                   /*in*/
FLOAT   *incr;                                  /*in*/
INT     *npts;                                  /*in*/
CHAR     *depth_or_time;                         /*in*/
FLOAT   *user_struct;                           /*in*/
INT     *size_of_user_struct;                   /*in*/
CHAR     *comment;                               /*in*/
CHAR     *depth_uom;                             /*in*/
CHAR     *trace_uom;                             /*in*/
FLOAT   *null_value;                            /*in*/
FLOAT   *array;                                 /*in*/
INT     *status;                                /*out*/
INT     len1,len2,len3,len4,len5,len6;	/* lengths of strings */
{

LOG_TRACE_STRUCT        Log;
LOG_TRACE_STRUCT        *pLog = &Log;
INT i;
privatedef INT Units[NDIM] = {0,0};
privatedef INT DataType[NDIM] = {FLOAT_TYPE, FLOAT_TYPE};
privatedef size_t DataSize[NDIM] = {sizeof(FLOAT), sizeof(FLOAT)};
privatedef INT ValueInc[NDIM] = {INCREMENT_LIST, VALUE_LIST};
UINT ndim = NDIM;
UINT stroke_num;
UINT Dim_List[1];
VOIDPTR Value_List[1];
FLOAT x;

if(*npts EQUALS 0)
	{
	*status = FAIL;
	return;
	}

ftocstr(uwi,pLog->uwi,len1);
ftocstr(trace_name,pLog->trace_name,len2);
ftocstr(depth_or_time,pLog->depth_or_time,len3);
ftocstr(comment,pLog->comments,len4);
ftocstr(depth_uom,pLog->depth_uom,len5);
ftocstr(trace_uom,pLog->trace_uom,len6);

pLog->top  = *top;
pLog->dinc = *incr;

nl_init_nlist(&pLog->ptrace, ndim, Units, DataSize, DataType, ValueInc,
	      BLOCKSIZE);

ndim          = 1;

					/*  Set the null value.   */

Dim_List[0]   = 2;
x             = *null_value;
Value_List[0] = (VOIDPTR)&x;
nl_set_nlist_info(pLog->ptrace,NL_NLIST_NULL_VALUE,ndim,Dim_List,Value_List);

nl_start_stroke(pLog->ptrace,&stroke_num);
if (*size_of_user_struct IS_NOT_EQUAL_TO 0)
	{
	nl_set_nlist_user_struct(pLog->ptrace, user_struct,
				 *size_of_user_struct);
	}

x = *top;
Value_List[0] = (VOIDPTR)&x;
Dim_List[0] = 1;
nl_set_stroke_info(pLog->ptrace, 0, NL_STROKE_START_VALUE, ndim,
					Dim_List, Value_List);
x = *incr;
nl_set_stroke_info(pLog->ptrace, 0, NL_STROKE_INCREMENT, ndim,
					Dim_List, Value_List);

Dim_List[0] = 2;
Value_List[0] = (VOIDPTR)array;
nl_add_points(pLog->ptrace, *npts, ndim, Dim_List, Value_List);

*status = lg_ltdm_add_trace(pLog);

nl_free_nlist(pLog->ptrace);

}


#endif          /* end of UNIX code */

#ifdef primos

privatedef VOID lg_ltdm_add_trace_cvt();

#define BLOCKSIZE 20
/******************************************************************

Program:
	lg_ltdm_add_trace_cvt

Description:
	This is a glue routine that will allow fortran programs
	to call the C function lg_ltdm_add_trace.

******************************************************************/
privatedef VOID lg_ltdm_add_trace_cvt(uwi,trace_name,top,incr,npts,
			  depth_or_time, user_struct,size_of_user_struct,
			  comment,depth_uom,trace_uom,null_value,array,status)

CHAR    *uwi;                                   /*in*/
CHAR    *trace_name;                            /*in*/
FLOAT   *top;                                   /*in*/
FLOAT   *incr;                                  /*in*/
INT     *npts;                                  /*in*/
CHAR    *depth_or_time;                         /*in*/
FLOAT   *user_struct;                           /*in*/
INT     *size_of_user_struct;                   /*in*/
CHAR    *comment;                               /*in*/
CHAR    *depth_uom;                             /*in*/
CHAR    *trace_uom;                             /*in*/
FLOAT   *null_value;                            /*in*/
FLOAT   *array;                                 /*in*/
INT     *status;                                /*out*/
{

LOG_TRACE_STRUCT        Log;
LOG_TRACE_STRUCT        *pLog = &Log;
INT i;
privatedef INT Units[NDIM] = {0,0};
privatedef INT DataType[NDIM] = {FLOAT_TYPE, FLOAT_TYPE};
privatedef size_t DataSize[NDIM] = {sizeof(FLOAT), sizeof(FLOAT)};
privatedef INT ValueInc[NDIM] = {INCREMENT_LIST, VALUE_LIST};
UINT ndim = NDIM;
UINT stroke_num;
UINT Dim_List[1];
VOIDPTR Value_List[1];
FLOAT x;

ndim = 2;

if(*npts EQUALS 0)
	{
	*status = FAIL;
	return;
	}

strcpy(pLog->uwi,uwi);
strcpy(pLog->trace_name,trace_name);
strcpy(pLog->depth_or_time,depth_or_time);
strcpy(pLog->comments,comment);
strcpy(pLog->depth_uom,depth_uom);
strcpy(pLog->trace_uom,trace_uom);

pLog->top  = *top;
pLog->dinc = *incr;

nl_init_nlist(&pLog->ptrace, ndim, Units, DataSize, DataType, ValueInc,
	      BLOCKSIZE);

ndim          = 1;

					/*  Set the null value.   */

Dim_List[0]   = 2;
x             = *null_value;
Value_List[0] = (VOIDPTR)&x;
nl_set_nlist_info(pLog->ptrace,NL_NLIST_NULL_VALUE,ndim,Dim_List,Value_List);

nl_start_stroke(pLog->ptrace,&stroke_num);
if (*size_of_user_struct IS_NOT_EQUAL_TO 0)
	{
	nl_set_nlist_user_struct(pLog->ptrace, user_struct,
				 *size_of_user_struct);
	}

x = *top;
Value_List[0] = (VOIDPTR)&x;
Dim_List[0] = 1;
nl_set_stroke_info(pLog->ptrace, 0, NL_STROKE_START_VALUE, ndim,
					Dim_List, Value_List);
x = *incr;
nl_set_stroke_info(pLog->ptrace, 0, NL_STROKE_INCREMENT, ndim,
					Dim_List, Value_List);

Dim_List[0] = 2;
Value_List[0] = (VOIDPTR)array;
nl_add_points(pLog->ptrace, *npts, ndim, Dim_List, Value_List);

*status = lg_ltdm_add_trace(pLog);

nl_free_nlist(pLog->ptrace);

}

/*******************************************************************************
 lg_ltdm_add_trace_cvt */

publicdef VOID lgg_ltdm_add_trace(uwi,trace_name,top,incr,npts,depth_or_time,
    user_struct,size_of_user_struct,comment,depth_uom,trace_uom,
    null_value,array,status,z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,z11
	,z12,z13,z14)
CHAR *uwi;
CHAR *trace_name;
FLOAT top;
FLOAT incr;
INT npts;
CHAR *depth_or_time;
FLOAT user_struct;
INT size_of_user_struct;
CHAR *comment;
CHAR *depth_uom;
CHAR *trace_uom;
FLOAT null_value;
FLOAT array;
INT status;
INT z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,z11,z12,z13,z14;
{
    CHAR string1[MAXLEN];
    CHAR string2[MAXLEN];
    CHAR string3[MAXLEN];
    CHAR string4[MAXLEN];
    CHAR string5[MAXLEN];
    CHAR string6[MAXLEN];

    ftocstr((CHAR *)&uwi,string1,z1);
    ftocstr((CHAR *)&trace_name,string2,z2);
    ftocstr((CHAR *)&depth_or_time,string3,z6);
    ftocstr((CHAR *)&comment,string4,z9);
    ftocstr((CHAR *)&depth_uom,string5,z10);
    ftocstr((CHAR *)&trace_uom,string6,z11);
    lg_ltdm_add_trace_cvt(string1,string2,&top,&incr,&npts,string3,
	&user_struct,&size_of_user_struct,string4,string5,string6,
	&null_value,&array,&status);
    ctofstr((CHAR *)&uwi,string1,z1);
    ctofstr((CHAR *)&trace_name,string2,z2);
    ctofstr((CHAR *)&depth_or_time,string3,z6);
    ctofstr((CHAR *)&comment,string4,z9);
    ctofstr((CHAR *)&depth_uom,string5,z10);
    ctofstr((CHAR *)&trace_uom,string6,z11);
    return;
}

#endif       /* end of Primos code */
                                                                                                                             
