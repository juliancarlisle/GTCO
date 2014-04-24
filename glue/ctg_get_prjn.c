/* DEC/CMS REPLACEMENT HISTORY, Element CTG_GET_PRJN.C*/
/* *3    27-AUG-1990 08:22:19 VINCE "(SPR 1) change old #if host to ifdef... "*/
/* *2     7-FEB-1990 06:59:00 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style."*/
/* *1    21-JUL-1989 09:47:13 GILLESPIE "Fortran binding for Cartographic Routine"*/
/* DEC/CMS REPLACEMENT HISTORY, Element CTG_GET_PRJN.C*/

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


#include "esi_ct.h"
#include "esi_tc.h"
#include "esi_ho.h"
#include "esi_glue.h"

#ifdef vms
publicdef VOID ctg_get_projection(projection_id,type,zone,spheroid,units,
			  parameters,error_flag)

DSC *projection_id;                   /*  Input projection ID       */
INT *type;                            /*  Pointer to projection type */
INT *zone;                            /*  Pointer to projection zone */
INT *spheroid;                        /*  Pointer to spheroid code   */
INT *units;                           /*  Pointer to spheroid units  */
DOUBLE *parameters;                   /*  Projection parameter array */
INT *error_flag;                      /*  Returned error flag        */
{
    PROJECTION_STRUCTURE *projection;
    CHAR string[MAXLEN];

    DSCTOCS(projection_id,string);    /* translate the string */

    *error_flag = ct_get_projection(string,&projection);
    if(*error_flag EQUALS SUCCESS)
    {
	 *type = projection->projection_type;
	 *zone = projection->zone_code;
	 *spheroid = projection->spheroid_code;
	 *units = projection->spheroid_units;
	 hoblockmove(&projection->parameters, parameters, sizeof(DISCRETE_PARMS));
	 tc_free((BYTE *)projection);
    }
}
#endif
#if UNIX
publicdef VOID ctg_get_projection_(projection_id,type,zone,spheroid,units,
			  parameters,error_flag,len)

CHAR *projection_id;                   /*  Input projection ID       */
INT *type;                            /*  Pointer to projection type */
INT *zone;                            /*  Pointer to projection zone */
INT *spheroid;                        /*  Pointer to spheroid code   */
INT *units;                           /*  Pointer to spheroid units  */
DOUBLE *parameters;                   /*  Projection parameter array */
INT *error_flag;                      /*  Returned error flag        */
INT len;			      /*  Length of projection_id  (compiler-added)  */
{
    PROJECTION_STRUCTURE *projection;
    CHAR string[MAXLEN];

    ftocstr(projection_id,string,len);    /* translate the string */

    *error_flag = ct_get_projection(string,&projection);
    if(*error_flag EQUALS SUCCESS)
    {
	 *type = projection->projection_type;
	 *zone = projection->zone_code;
	 *spheroid = projection->spheroid_code;
	 *units = projection->spheroid_units;
	 hoblockmove(&projection->parameters, parameters, sizeof(DISCRETE_PARMS));
	 tc_free((BYTE *)projection);
    }
}
#endif
#ifdef primos
publicdef VOID ctg_get_projection(projection_id,type,zone,spheroid,units,
			  parameters,error_flag,len)

CHAR projection_id;                  /*  Input projection ID       */
INT type;                            /*  Pointer to projection type */
INT zone;                            /*  Pointer to projection zone */
INT spheroid;                        /*  Pointer to spheroid code   */
INT units;                           /*  Pointer to spheroid units  */
DOUBLE parameters;                   /*  Projection parameter array */
INT error_flag;                      /*  Returned error flag        */
INT len;                             /* Compiler-added argument     */
{
    PROJECTION_STRUCTURE *projection;
    CHAR string[MAXLEN];

    ftocstr(&projection_id, string, len);
    error_flag = ct_get_projection(string,&projection);
    if(error_flag EQUALS SUCCESS)
    {
	 type = projection->projection_type;
	 zone = projection->zone_code;
	 spheroid = projection->spheroid_code;
	 units = projection->spheroid_units;
	 hoblockmove(&projection->parameters, &parameters,
	     sizeof(DISCRETE_PARMS));
	 tc_free((BYTE *)projection);
    }
}
#endif
                                                                                            
