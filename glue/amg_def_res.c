/* DEC/CMS REPLACEMENT HISTORY, Element AMG_DEF_RES.C*/
/* *3    27-AUG-1990 08:22:01 VINCE "(SPR 1) change old #if host to ifdef... "*/
/* *2     7-FEB-1990 06:55:56 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:44:15 GILLESPIE "Fortran bindings for Application Manager"*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_DEF_RES.C*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_DEF_RES.C*/
/* *1    19-JUN-1989 11:59:11 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element AMG_DEF_RES.C*/

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

#ifndef ESI_TS_H
#include "esi_ts.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#ifndef ESI_HO_FILES_H
#include "esi_ho_files.h"
#endif

/***********************************************************************
*
* GLUE ROUTINE
*
* Allows Fortran progs to call the C function am_def_rsrc().
*
***********************************************************************/
#ifdef vms
publicdef INT amg_define_resource(f_type,f_file,f_rsrc_id,f_server,f_id,
				  f_pointer)
INT *f_type;            /* resource type MENU or DIALOG */
DSC *f_file;            /* resource file name (.rsrc) */
INT *f_rsrc_id;         /* resrource id in file */
INT (*f_server) ();     /* resrource event server routine address */
INT *f_id;              /* returned MAC id */
BYTE *f_pointer;        /* passed pointer */
{
    INT type,rsrc_id;
    INT (*f_server2) ();          /* resrource event server routine address */
    FILENAME filename;
    INT status;

    type = *f_type;               /* de-reference and isolate               */
    rsrc_id = *f_rsrc_id;

    if (*(INT *) f_server == 0)   /* if user is not providing a server then */
	{                         /* assume he calls routine with a 0 value */
	f_server2 = NULL_FUNCTION_PTR; /* so we must set function ptr = 0   */
	}
    else
	{
	f_server2 = f_server;
	}

    DSCTOCS(f_file, filename);    /* make a C string from the descriptor    */

				  /* set server type to FORTRAN; this will
				     cause later calls to the server
				     routine to have its arguments passed
				     by reference, rather than by value     */

    status = am_define_resource(type, filename, rsrc_id, f_server2, f_id,
		f_pointer) OR am_set_server_type(*f_id, 1);

    return  status;
}
#endif

#if UNIX
publicdef INT amg_define_resource_(f_type,f_file,f_rsrc_id,f_server,f_id,
				  f_pointer,len)
INT *f_type;            /* resource type MENU or DIALOG */
CHAR *f_file;            /* resource file name (.rsrc) */
INT *f_rsrc_id;         /* resrource id in file */
INT (*f_server) ();     /* resrource event server routine address */
INT *f_id;              /* returned MAC id */
BYTE *f_pointer;        /* passed pointer */
INT len;		/* length of string (added by compiler) */
{
    INT type,rsrc_id;
    INT (*f_server2) ();          /* resrource event server routine address */
    FILENAME filename;
    INT status;

    type = *f_type;               /* de-reference and isolate               */
    rsrc_id = *f_rsrc_id;

    if (*(INT *) f_server == 0)   /* if user is not providing a server then */
	{                         /* assume he calls routine with a 0 value */
	f_server2 = NULL_FUNCTION_PTR; /* so we must set function ptr = 0   */
	}
    else
	{
	f_server2 = f_server;
	}

    ftocstr(f_file, filename, len);    /* make a C string    */

				  /* set server type to FORTRAN; this will
				     cause later calls to the server
				     routine to have its arguments passed
				     by reference, rather than by value     */

    status = am_define_resource(type, filename, rsrc_id, f_server2, f_id,
		f_pointer) OR am_set_server_type(*f_id, 1);

    return  status;
}
#endif

#ifdef primos

publicdef INT amg_define_resource(f_type,file,f_rsrc_id,f_server,f_id,
     f_pointer,z1,z2)
INT f_type;
CHAR file;
INT f_rsrc_id;
BYTE f_server;    /* this function ptr is ignored coming from Fortran */
INT f_id;
BYTE f_pointer;   /* argument list for server function -- ignored */
INT z1,z2;
{
    extern INT am_define_resource();
    INT status;
    CHAR string1[256];

    ftocstr(&file,string1,z2);

    status = am_define_resource(f_type,string1,f_rsrc_id,NULL_FUNCTION_PTR,
	&f_id,(BYTE *)0);

    return status;
}

#endif



                                                                                             
