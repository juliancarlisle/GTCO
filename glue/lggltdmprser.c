/* DEC/CMS REPLACEMENT HISTORY, Element LGGLTDMPRSER.C */
/* *3     9-AUG-1990 19:07:49 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *2     5-MAR-1990 13:54:10 WALTERS "(SPR 6012) Change file name to UNIX standards" */
/* *1     5-MAR-1990 13:46:40 GILLESPIE "Rename files for Unix (SPR 6015)" */
/* DEC/CMS REPLACEMENT HISTORY, Element LGGLTDMPRSER.C */
#ifndef ESI_LG_LDEFS_H
#include "esi_lg_ldefs.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifdef vms

/******************************************************************
Program:
	lgg_ltdm_parser

Description:
	This is a glue routine to allow fortran programs to call the C
	function lg_ltdm_parser.  The routine takes a descriptor containing
	a trace name, and returns four descriptors containing:
	source, trace, service and version.
******************************************************************/
publicdef VOID lgg_ltdm_parser(trace_name,source,trace,service,version,status)
DSC             *trace_name;
DSC             *source;
DSC             *trace;
DSC             *service;
INT             *version;
INT             *status;
{
LOG_TRACE_STRUCT        Log;
LOG_TRACE_STRUCT        *pLog = &Log;

DSCTOCS(trace_name, pLog->trace_name);

*status = lg_ltdm_parser(pLog);

if(*status == SUCCESS)
    {
    CSTODSC(pLog->source, source);
    CSTODSC(pLog->trace, trace);
    CSTODSC(pLog->service, service);
    *version = pLog->version;
    }

return;

}
#endif          /* end of VMS code */

#if UNIX

/******************************************************************
Program:
	lgg_ltdm_parser

Description:
	This is a glue routine to allow fortran programs to call the C
	function lg_ltdm_parser.  The routine takes a descriptor containing
	a trace name, and returns four descriptors containing:
	source, trace, service and version.
******************************************************************/
publicdef VOID lgg_ltdm_parser_(trace_name,source,trace,service,version,status,
	len1,len2,len3,len4)
CHAR             *trace_name;
CHAR             *source;
CHAR             *trace;
CHAR             *service;
INT             *version;
INT             *status;
INT              len1,len2,len3,len4;
{
LOG_TRACE_STRUCT        Log;
LOG_TRACE_STRUCT        *pLog = &Log;

ftocstr(trace_name, pLog->trace_name,len1);

*status = lg_ltdm_parser(pLog);

if(*status == SUCCESS)
    {
    ctofstr( source, pLog->source,len2);
    ctofstr( trace,pLog->trace,len3);
    ctofstr(service, pLog->service, len4);
    *version = pLog->version;
    }

return;

}

#endif          /* end of UNIX code */

#ifdef primos

privatedef VOID lg_ltdm_parser_cvt();

/******************************************************************
Program:
	lg_ltdm_parser_cvt

Description:
	This is a glue routine to allow fortran programs to call the C
	function lg_ltdm_parser.  The routine takes a descriptor containing
	a trace name, and returns four descriptors containing:
	source, trace, service and version.
******************************************************************/
privatedef VOID lg_ltdm_parser_cvt(trace_name,source,trace,service,
				    version,status)
CHAR            *trace_name;
CHAR            *source;
CHAR            *trace;
CHAR            *service;
INT             *version;
INT             *status;
{
LOG_TRACE_STRUCT        Log;
LOG_TRACE_STRUCT        *pLog = &Log;

strcpy(pLog->trace_name, trace_name);

*status = lg_ltdm_parser(pLog);

if(*status == SUCCESS)
    {
    strcpy(source, pLog->source);
    strcpy(trace, pLog->trace);
    strcpy(service, pLog->service);
    *version = pLog->version;
    }

return;

}

/*******************************************************************************
 lg_ltdm_parser_cvt */

publicdef VOID lgg_ltdm_parser(trace_name,source,trace,service,version,
			status,z1,z2,z3,z4,z5,z6)
CHAR *trace_name;
CHAR *source;
CHAR *trace;
CHAR *service;
INT version;
INT status;
INT z1,z2,z3,z4,z5,z6;
{
    CHAR string1[MAXLEN];
    CHAR string2[MAXLEN];
    CHAR string3[MAXLEN];
    CHAR string4[MAXLEN];

    ftocstr((CHAR *)&trace_name,string1,z1);
    ftocstr((CHAR *)&source,string2,z2);
    ftocstr((CHAR *)&trace,string3,z3);
    ftocstr((CHAR *)&service,string4,z4);
    lg_ltdm_parser_cvt(string1,string2,string3,string4,&version,
	&status);
    ctofstr((CHAR *)&trace_name,string1,z1);
    ctofstr((CHAR *)&source,string2,z2);
    ctofstr((CHAR *)&trace,string3,z3);
    ctofstr((CHAR *)&service,string4,z4);
    return;
}

#endif       /* end of Primos code */
                                                                                                                             
