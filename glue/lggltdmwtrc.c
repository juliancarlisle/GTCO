/* DEC/CMS REPLACEMENT HISTORY, Element LGGLTDMWTRC.C */
/* *3     9-AUG-1990 19:07:52 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     5-MAR-1990 13:54:14 WALTERS "(SPR 6012) Change file name to UNIX standards" */
/* *1     5-MAR-1990 13:46:43 GILLESPIE "Rename files for Unix (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element LGGLTDMWTRC.C */
#ifndef ESI_TC_H
#include "esi_tc.h"
#endif

#ifndef ESI_TS_H
#include "esi_ts.h"
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
	lgg_ltdm_inq_well_trace

Description:
	This is a glue routine that allows fortran programs to call
	the C routine lg_ltdm_inq_well_trace.

******************************************************************/
publicdef VOID lgg_ltdm_inq_well_trace(uwi, sql, limit, trace_names,
					 count, status)
DSC     *uwi;           /* in */
DSC     *sql;           /* in */
INT     *limit;         /* in */
DSC_VSA *trace_names;   /* out */
INT     *count;         /* out */
INT     *status;
{
CHAR *puwi;
CHAR *psql;
INT i;
CHAR **ptcp,**ptcp_save;
INT      nwells;

*count = 0;
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

deslen=trace_names->dsc$w_maxstrlen;

for(i=0; *count < *limit AND *ptcp != NULL;i+= deslen, ptcp++,(*count)++)
	{
	srclen=strlen(*ptcp);
/* Move with blank pad */
	lib$movc5(&srclen, *ptcp, &blank,
	    &deslen,trace_names->dsc$a_pointer+i);
	}

ts_tcp_free(ptcp_save);
tc_free((BYTE *)puwi);
tc_free((BYTE *)psql);
return;
}

#endif          /* end of VMS code */

#if UNIX

/******************************************************************

Program:
	lgg_ltdm_inq_well_trace

Description:
	This is a glue routine that allows fortran programs to call
	the C routine lg_ltdm_inq_well_trace.

******************************************************************/
publicdef VOID lgg_ltdm_inq_well_trace_(uwi, sql, limit, trace_names,
					 count, status,len1,len2,len3)
CHAR     *uwi;           /* in */
CHAR     *sql;           /* in */
INT     *limit;         /* in */
CHAR    *trace_names;   /* tcp -- out */
INT     *count;         /* out */
INT     *status;
INT     len1, len2, len3;	/* in */
{
CHAR *puwi;
CHAR *psql;
INT i;
CHAR **ptcp,**ptcp_save;
CHAR *dest, *p;
INT      nwells;

*count = 0;
psql = (CHAR *)tc_zalloc(len2 + 1);
ftocstr(sql,psql,len2);

puwi = (CHAR *)tc_zalloc(len1 + 1);
ftocstr(uwi,puwi,len1);

*status = lg_ltdm_inq_well_trace(puwi, psql, &ptcp,&nwells);
if(*status != SUCCESS)
    {
    tc_free((BYTE *)psql);
    tc_free((BYTE *)puwi);
    *status = FAIL;
    return;
    }

ptcp_save = ptcp;

deslen = len3;        /* get size of each fortran string space */

for(i=0; count < limit AND *ptcp != NULL;i+= deslen, ptcp++,count++)
	{
	srclen = strlen(*ptcp);
	dest = trace_names + (i*len3);
	hoblockmove(*ptcp, dest, deslen); /* move it over */
	for (p=dest+srclen; p<dest+deslen; ++p)     /* blank pad */
	       *p = ' ';
	}

ts_tcp_free(ptcp_save);
tc_free((BYTE *)puwi);
tc_free((BYTE *)psql);
return;
}


#endif          /* end of UNIX code */

#ifdef primos

/*****************************************************************

Program:
	lgg_ltdm_inq_well_trace

Description:
	This is a glue routine that allows fortran programs to call
	the C routine lg_ltdm_inq_well_trace.

******************************************************************/

publicdef VOID lgg_ltdm_inq_well_trace(uwi, sql, limit, trace_names,
			count, status, z1,z2,z3,z4,z5,z6)
CHAR    *uwi;           /* in */
CHAR    *sql;           /* in */
INT      limit;         /* in */
CHAR    *trace_names;   /* out */
INT      count;         /* out */
INT      status;
INT     z1,z2,z3,z4,z5,z6;
{
CHAR puwi[MAXLEN];
CHAR psql[MAXLEN];
INT i;
CHAR **ptcp, **ptcp_save;
CHAR *p, *dest;
CHAR *t_trace;               /* local pointer to Fortran space */
INT  len, nwells;

t_trace = (CHAR *)&trace_names;        /* move down 1 level of indirection */
count = 0;
ftocstr((CHAR *)&sql,psql,z2);
ftocstr((CHAR *)&uwi,puwi,z1);

status = lg_ltdm_inq_well_trace(puwi, psql, &ptcp, &nwells);
if(status IS_NOT_EQUAL_TO SUCCESS)
    {
    status = FAIL;
    return;
    }

ptcp_save = ptcp;

deslen = z4 & 65535;        /* get size of each fortran string space */

for(i=0; count < limit AND *ptcp != NULL;i+= deslen, ptcp++,count++)
	{
	len = strlen(*ptcp);
	dest = t_trace + i;
	hoblockmove(*ptcp, t_trace+i, deslen); /* move it over */
	for (p=dest+len; p<dest+deslen; ++p)     /* blank pad */
	       {
	       *p = ' ';
	       }
	}

ts_tcp_free(ptcp_save);
return;
}


#endif       /* end of Primos code */
                                                                                                                             
