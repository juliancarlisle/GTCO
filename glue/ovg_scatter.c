/* DEC/CMS REPLACEMENT HISTORY, Element OVG_SCATTER.C */
/* *4     9-AUG-1990 19:13:48 GILLESPIE "(SPR 2001) Change #if HOST to #ifdef" */
/* *3     7-FEB-1990 07:04:38 JULIAN "ULTRIX port mods. SUN & mips both pcc variants. use same fortran call style." */
/* *2    16-OCT-1989 15:59:10 PURNA "(SPR 0) move from cmslib" */
/* *1    16-OCT-1989 15:49:27 PURNA "move from cmslib" */
/* DEC/CMS REPLACEMENT HISTORY, Element OVG_SCATTER.C */
/* DEC/CMS REPLACEMENT HISTORY, Element OVG_SCATTER.C*/
/* *1    19-JUN-1989 13:21:41 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element OVG_SCATTER.C*/

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

#ifndef ESI_C_LIB_H
#include "esi_c_lib.h"
#endif

#ifndef ESI_GLUE_H
#include "esi_glue.h"
#endif

#define OV_BAD_WRITE 1
#define OV_BAD_READ 2

#ifdef vms

publicdef INT ovg_write_scatter( filename, x_array, y_array, z_array, num_points )

DSC *filename;
FLOAT x_array[];
FLOAT y_array[];
FLOAT z_array[];
INT *num_points;

{
    CHAR text[81];
    FILE *fp1;

/* Convert from Fortran to C string */

    DSCTOCS( filename, text );

/* Open the scatter file */

	if( ov_open_scatter( &fp1, text, "w" ) )
		return( FAIL );

/* call write scatter file function */

	if( ov_write_scatter( fp1, x_array, y_array, z_array, *num_points ) )
	{
	    ov_close_scatter( fp1 );
	    return( OV_BAD_WRITE );
	}

/* Close the scatter file */

	if( ov_close_scatter( fp1 ) )
		return( FAIL );

    return( SUCCESS );

}
#endif
#if UNIX

publicdef INT ovg_write_scatter_( filename, x_array, y_array, z_array, 
 		num_points, len )

CHAR *filename;
FLOAT x_array[];
FLOAT y_array[];
FLOAT z_array[];
INT *num_points;
INT len;

{
    CHAR text[81];
    FILE *fp1;

/* Convert from Fortran to C string */

    ftocstr( filename, text, len );

/* Open the scatter file */

	if( ov_open_scatter( &fp1, text, "w" ) )
		return( FAIL );

/* call write scatter file function */

	if( ov_write_scatter( fp1, x_array, y_array, z_array, *num_points ) )
	{
	    ov_close_scatter( fp1 );
	    return( OV_BAD_WRITE );
	}

/* Close the scatter file */

	if( ov_close_scatter( fp1 ) )
		return( FAIL );

    return( SUCCESS );

}

#endif
#ifdef vms

publicdef INT ovg_read_scatter( filename, x_array, y_array, z_array, num_points )

DSC *filename;
FLOAT x_array[];
FLOAT y_array[];
FLOAT z_array[];
INT *num_points;

{
    CHAR text[81];
    FILE *fp1;

/* Convert from Fortran to C string */

    DSCTOCS( filename, text );

/* Open the scatter file */

	if( ov_open_scatter( &fp1, text, "r" ) )
		return( FAIL );

/* call write scatter file function */

	if( ov_read_scatter( fp1, x_array, y_array, z_array, num_points ) )
	{
	    ov_close_scatter( fp1 );
	    return( OV_BAD_READ );
	}

/* Close the scatter file */

	if( ov_close_scatter( fp1 ) )
		return( FAIL );

    return( SUCCESS );

}
#endif
#if UNIX

publicdef INT ovg_read_scatter_( filename, x_array, y_array, z_array, 
		num_points, len )

CHAR *filename;
FLOAT x_array[];
FLOAT y_array[];
FLOAT z_array[];
INT *num_points;
INT len;

{
    CHAR text[81];
    FILE *fp1;

/* Convert from Fortran to C string */

    ftocstr( filename, text, len );

/* Open the scatter file */

	if( ov_open_scatter( &fp1, text, "r" ) )
		return( FAIL );

/* call write scatter file function */

	if( ov_read_scatter( fp1, x_array, y_array, z_array, num_points ) )
	{
	    ov_close_scatter( fp1 );
	    return( OV_BAD_READ );
	}

/* Close the scatter file */

	if( ov_close_scatter( fp1 ) )
		return( FAIL );

    return( SUCCESS );

}
#endif

