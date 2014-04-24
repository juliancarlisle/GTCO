/* DEC/CMS REPLACEMENT HISTORY, Element LGG_LTDMSWLL.C */
/* *3     9-AUG-1990 19:07:56 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     5-MAR-1990 13:54:17 WALTERS "(SPR 6012) Change file name to UNIX standards" */
/* *1     5-MAR-1990 13:46:47 GILLESPIE "Rename files for Unix (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element LGG_LTDMSWLL.C */
#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

privatedef CHAR blank = {' '};
privatedef unsigned short deslen,srclen;

#ifdef vms

/******************************************************************

Program:
	lgg_ltdm_sel_well

Description:
	This is a glue routine that allows fortran programs to call
	the C routine lg_ltdm_sel_well.

******************************************************************/
publicdef VOID lgg_ltdm_sel_well(uwi,sql,numselectable,prompt_string,
					ifone,trace_names,nchosen,status)
DSC     *uwi;
DSC     *sql;
INT     *numselectable;
DSC     *prompt_string;
INT     *ifone;
DSC_VSA *trace_names;
INT     *nchosen;
INT     *status;
{
CHAR    *puwi, *psql;
INT     i,nwells;
CHAR    **ptcp, **ptcp_save;
INT     *selarray;
INT     numsel,stat;
INT     index;
CHAR    *prompt;

*nchosen = 0;
*status  = SUCCESS;

psql = (CHAR *)tc_zalloc(sql->dsc$w_length + 1);
DSCTOCS(sql,psql);

puwi = (CHAR *)tc_zalloc(uwi->dsc$w_length + 1);
DSCTOCS(uwi,puwi);

*status = lg_ltdm_inq_well_trace(puwi, psql, &ptcp,&nwells);

if(*status IS_NOT_EQUAL_TO SUCCESS)
    {
    tc_free((BYTE *)psql);
    tc_free((BYTE *)puwi);
    *status = FAIL;
    return;
    }

ptcp_save = ptcp;

selarray = (INT *)tc_zalloc(*numselectable);

if (nwells == 1)                /* if ifone is false and only one well */
    {                           /* is selected then put it in a selector */
    *nchosen = 1;
    if(*ifone != TRUE)
	{
	deslen=trace_names->dsc$w_maxstrlen;
	srclen=strlen(*ptcp);
	lib$movc5(&srclen, *ptcp, &blank,
		 &deslen, trace_names->dsc$a_pointer);
	}
    else
	{
	wi_ssst("LG_LTDM/SELECT",nwells, 1, ptcp);
	prompt = (CHAR *)tc_zalloc(prompt_string->dsc$w_length + 1);
	DSCTOCS(prompt_string,prompt);
	wi_request_selection(prompt,&numsel, selarray, &stat);
	tc_free(prompt);
	if(stat == SUCCESS)
	    {
	    deslen=trace_names->dsc$w_maxstrlen;
	    srclen=strlen(*(ptcp + (selarray[0] -1)));
	    lib$movc5(&srclen, *(ptcp + (selarray[0] -1)),
		      &blank, &deslen, trace_names->dsc$a_pointer);
	    }
	else
	    {
	    *status=FAIL;
	    *nchosen=0;
	    }
	}
    }
else
    {
    wi_ssst("LG_LTDM/SELECT",nwells, numselectable, ptcp);
    prompt = (CHAR *)tc_zalloc(prompt_string->dsc$w_length + 1);
    DSCTOCS(prompt_string,prompt);
    wi_request_selection(prompt,&numsel, selarray, &stat);
    tc_free(prompt);
    if(stat == SUCCESS)
	{
	deslen=trace_names->dsc$w_maxstrlen;
	for (i=0,index = 0; i < numsel; i++)
	    {
	    srclen=strlen(*(ptcp + (*(selarray+i) -1)));
	    lib$movc5(&srclen, *(ptcp + (*(selarray+i) -1)), &blank, &deslen,
		      trace_names->dsc$a_pointer + i * deslen);
	    }
	*nchosen = numsel;
	}
    else
	{
	*nchosen=0;
	*status = FAIL;
	}
    }
return;
}

#endif          /* end of VMS code */

#if UNIX

/******************************************************************

Program:
	lgg_ltdm_sel_well

Description:
	This is a glue routine that allows fortran programs to call
	the C routine lg_ltdm_sel_well.

******************************************************************/
publicdef VOID lgg_ltdm_sel_well_(uwi,sql,numselectable,prompt_string,
					ifone,trace_names,nchosen,status,
					len1, len2, len3, len4)
CHAR     *uwi;
CHAR     *sql;
INT     *numselectable;
CHAR     *prompt_string;
INT     *ifone;
CHAR    *trace_names;
INT     *nchosen;
INT     *status;
INT     len1, len2, len3, len4;
{
CHAR    puwi[MAXLEN], psql[MAXLEN], prompt[MAXLEN];
INT     i,nwells;
CHAR    **ptcp, **ptcp_save;
CHAR    *p, *src, *dest;
INT     *selarray;
INT     numsel,stat;
INT     len;

*nchosen = 0;
*status  = SUCCESS;

ftocstr(sql,psql,len2);
ftocstr(uwi,puwi,len1);
ftocstr(prompt_string,prompt,len3);

*status = lg_ltdm_inq_well_trace(puwi,psql,&ptcp,&nwells);

if (*status != SUCCESS)
    {
    *status = FAIL;
    return;
    }

ptcp_save = ptcp;
deslen = len4;    /* get size of fortran strings */

selarray = (INT *)tc_zalloc(*numselectable * sizeof(INT));

if (nwells == 1)                /* if ifone is false and only one well */
    {                           /* is selected then put it in a selector */
    *nchosen = 1;
    if(*ifone != TRUE)
	{
	srclen=strlen(*ptcp);
	hoblockmove(*ptcp, trace_names, srclen);
	for (p=trace_names+srclen; p<trace_names+deslen; ++p)
	    *p = blank;
	}
    else
	{
	wi_ssst("LG_LTDM/SELECT",nwells, 1, ptcp);
	wi_request_selection(prompt,&numsel, selarray, &stat);
	if(stat == SUCCESS)
	    {
	    dest = *(ptcp + (selarray[0] - 1));
	    srclen=strlen(dest);
	    src = trace_names + (i * deslen);
	    hoblockmove(dest, src, srclen);
	    for (p=src+srclen; p<src+deslen; ++p)
		*p = blank;
	    }
	else
	    {
	    *status=FAIL;
	    *nchosen=0;
	    }
	}
    }
else
    {
    wi_ssst("LG_LTDM/SELECT",nwells, *numselectable, ptcp);
    wi_request_selection(prompt,&numsel, selarray, &stat);
    if(stat == SUCCESS)
	{
	for (i=0; i < numsel; i++)
	    {
	    dest = *(ptcp + selarray[i] -1);
	    srclen=strlen(dest);
	    src = trace_names + (i * deslen);
	    hoblockmove(dest, src, srclen);
	    for (p=src+srclen; p<src+((i+1)*deslen); ++p)
		*p = blank;
	    }
	*nchosen = numsel;
	}
    else
	{
	*nchosen=0;
	*status = FAIL;
	}
    }
return;
}


#endif          /* end of UNIX code */

#ifdef primos

/******************************************************************

Program:
	lg_ltdm_sel_well

Description:
	This is a glue routine that allows fortran programs to call
	the C routine lg_ltdm_sel_well.

******************************************************************/

publicdef VOID lgg_ltdm_sel_well(uwi,sql,numselectable,prompt_string,
	   ifone,trace_names,nchosen,status,z1,z2,z3,z4,z5,z6,z7,z8)
CHAR    *uwi;
CHAR    *sql;
INT     numselectable;
CHAR    *prompt_string;
INT     ifone;
CHAR    *trace_names;
INT     nchosen;
INT     status;
INT     z1,z2,z3,z4,z5,z6,z7,z8;
{
CHAR    puwi[MAXLEN], psql[MAXLEN], prompt[MAXLEN];
INT     i,nwells;
CHAR    **ptcp, **ptcp_save;
CHAR    *p, *dest;
CHAR    *t_trace;       /* local pointer to fortran space */
INT     *selarray;
INT     numsel,stat;
INT     len;

nchosen = 0;
status  = SUCCESS;

t_trace = (CHAR *)&trace_names;    /* go down 1 level of indirection */
ftocstr((CHAR *)&sql,psql,z2);
ftocstr((CHAR *)&uwi,puwi,z1);
ftocstr((CHAR *)&prompt_string,prompt,z4);

status = lg_ltdm_inq_well_trace(puwi,psql,&ptcp,&nwells);

if(status IS_NOT_EQUAL_TO SUCCESS)
    {
    status = FAIL;
    return;
    }

ptcp_save = ptcp;
deslen = z6 & 65535;    /* get size of fortran strings */

selarray = (INT *)tc_zalloc(numselectable * sizeof(INT));

if (nwells == 1)                /* if ifone is false and only one well */
    {                           /* is selected then put it in a selector */
    nchosen = 1;
    if(ifone != TRUE)
	{
	srclen=strlen(*ptcp);
	hoblockmove(*ptcp, t_trace, srclen);
	for (p=t_trace+srclen; p<t_trace+deslen; ++p)
	    {
	    *p = blank;
	    }
	}
    else
	{
	wi_ssst("LG_LTDM/SELECT",nwells, 1, ptcp);
	wi_request_selection(prompt,&numsel, selarray, &stat);
	if(stat == SUCCESS)
	    {
	    dest = *(ptcp + (selarray[0] - 1));
	    srclen=strlen(dest);
	    hoblockmove(dest, t_trace, srclen);
	    for (p=t_trace+srclen; p<t_trace+deslen; ++p)
	    {
		*p = blank;
		}
	    }
	else
	    {
	    status=FAIL;
	    nchosen=0;
	    }
	}
    }
else
    {
    wi_ssst("LG_LTDM/SELECT",nwells, numselectable, ptcp);
    wi_request_selection(prompt,&numsel, selarray, &stat);
	if(stat == SUCCESS)
	{
	for (i=0; i < numsel; i++)
	    {
	    dest = *(ptcp + selarray[i] -1);
	    srclen=strlen(dest);
	    hoblockmove(dest, t_trace + i * deslen, srclen);
	    for (p=t_trace+i*deslen+srclen; p<t_trace+(i+1)*deslen; ++p)
		{
		*p = blank;
		}
	    }
	nchosen = numsel;
	}
    else
	{
	nchosen=0;
	status = FAIL;
	}
    }
return;
}


#endif       /* end of Primos code */
                                                                                                                             
