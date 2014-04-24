/* DEC/CMS REPLACEMENT HISTORY, Element SUN_GKSWSCONFIG.H */
/* *3     3-MAY-1991 16:22:31 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version" */
/* *2     8-DEC-1989 10:29:17 GORDON "(SPR 0) File needed on Suns" */
/* *1     8-DEC-1989 10:28:42 GORDON "File needed on Suns" */
/* DEC/CMS REPLACEMENT HISTORY, Element SUN_GKSWSCONFIG.H */
/* "@(#)gkswsconfig.h 11.1 88/09/15 Copyr 1986 Sun Micro" */

/*
 * Copyright (c) 1986 by Sun Microsystems, Inc.
 */

#ifndef SUN_GKSWCONFIG_H
#define SUN_GKSWCONFIG_H 1
/*
#include <stdio.h>
#include <suntool/sunview.h>
#include <sunwindow/attr.h>
*/
typedef enum {
    GKS_NO_BUFFERING,
    GKS_SW_BUFFERING,
    GKS_HW_BUFFERING
} Gks_double_buffering_mode;

typedef enum {
    GKS_USE_PREFERRED,
    GKS_USE_REQUIRED,
    GKS_USE_NONE
} Gks_usage;

typedef enum {
    GKS_TYPE_TOOL,
    GKS_TYPE_CANVAS,
    GKS_TYPE_MI,
    GKS_TYPE_MOASC,
    GKS_TYPE_WISS,
    GKS_TYPE_HP
} Gks_base_type;

typedef enum {
    GKS_FALSE,
    GKS_TRUE
} Gks_boolean;

typedef enum {
    GKS_IGNORED,
    GKS_SET
} Gks_loc_mode;

typedef enum {
    GKS_STATIC,
    GKS_DYNAMIC
} Gks_dc;

typedef enum {
    GKS_LOW,
    GKS_HIGH
} Gks_vdc_prec;

typedef enum {
    GKS_CLEAR_TEXT,
    GKS_BINARY,
    GKS_CHARACTER
} Gks_encoding;

typedef enum {
    GKS_NONE = (caddr_t) NULL,
    GKS_CREATE = (caddr_t) 1
    /* Or a handle means "use this value" */
} Gks_creation;

typedef	char *	Gks_attr_value;

#define ATTR_PKG_GKS	ATTR_PKG_UNUSED_FIRST + 1
#define GKS_FIRST_ATTR	1

#define GKS_DEFAULT_GP_USAGE			GKS_USE_PREFERRED
#define GKS_DEFAULT_MSG_WIN_SIZE		3
#define GKS_DEFAULT_NUM_COLOR			16
#define GKS_DEFAULT_LOC_MODE 	 		GKS_IGNORED 
#define GKS_DEFAULT_DC_SIZING			GKS_STATIC
#define GKS_DEFAULT_RESIZE_PROC		  	NULL	
#define GKS_DEFAULT_DYNAMIC_SEG			GKS_TRUE

#define GKS_DEFAULT_TOOL_X              	50
#define GKS_DEFAULT_TOOL_Y              	50
#define GKS_DEFAULT_TOOL_WIDTH          	600
#define GKS_DEFAULT_TOOL_HEIGHT         	600
#define GKS_DEFAULT_TOOL_LABEL         		"GKS Workstation"
#define GKS_DEFAULT_TOOL_ICON_LABEL       	"SunGKS" 

#define GKS_DEFAULT_HP_NUM_COLOR		9
#define GKS_DEFAULT_HP_MINX			0
#define GKS_DEFAULT_HP_MINY			0
#define GKS_DEFAULT_HP_MAXX			7200
#define GKS_DEFAULT_HP_MAXY			10000
#define GKS_DEFAULT_HP_SOLID_FILL		GKS_TRUE
#define GKS_DEFAULT_HP_TITLE			"HPGL produced by SunGKS;"

#define GKS_DEFAULT_CGMO_ENCODING		GKS_BINARY
#define GKS_DEFAULT_CGMO_VDC_PREC		GKS_LOW

#define GKS_DEFAULT_BUFFERING_MODE		GKS_NO_BUFFERING

#define GKS_NUM_COLOUR	GKS_NUM_COLOR

#define GKS_OPT( type, ordinal) \
    ATTR( ATTR_PKG_GKS, type, ordinal)

typedef enum {
    /* base type */
    GKS_BASE_TYPE 	     = GKS_OPT( ATTR_ENUM, GKS_FIRST_ATTR),

    /* window attributes start at offset 1 */
    GKS_GP_USAGE 	     = GKS_OPT( ATTR_ENUM,	GKS_FIRST_ATTR + 1),
    GKS_MSG_WIN_SIZE 	     = GKS_OPT( ATTR_INT,	GKS_FIRST_ATTR + 2),
    GKS_NUM_COLOR 	     = GKS_OPT( ATTR_INT,	GKS_FIRST_ATTR + 3),
    GKS_LOC_MODE 	     = GKS_OPT( ATTR_ENUM,	GKS_FIRST_ATTR + 4),
    GKS_DC_SIZING      	     = GKS_OPT( ATTR_ENUM,	GKS_FIRST_ATTR + 5),
    GKS_TEXTSW		     = GKS_OPT( ATTR_OPAQUE,	GKS_FIRST_ATTR + 6),
    GKS_PANEL		     = GKS_OPT( ATTR_OPAQUE,	GKS_FIRST_ATTR + 7),
    GKS_RESIZE_PROC	     = GKS_OPT( ATTR_FUNCTION_PTR, GKS_FIRST_ATTR + 8),
    GKS_DYNAMIC_SEG	     = GKS_OPT( ATTR_BOOLEAN,	GKS_FIRST_ATTR + 9),
    GKS_DOUBLE_BUFFERING     = GKS_OPT( ATTR_ENUM,	GKS_FIRST_ATTR + 10), 

    /* tool attributes start at offset 101 */
    GKS_TOOL_WIDTH	     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  101),
    GKS_TOOL_HEIGHT	     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  102),
    GKS_TOOL_X		     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  103),
    GKS_TOOL_Y		     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  104),
    GKS_TOOL_LABEL	     = GKS_OPT( ATTR_STRING, GKS_FIRST_ATTR + 105),
    GKS_TOOL_FRAME_ARGS	     = GKS_OPT( ATTR_INT_PAIR, GKS_FIRST_ATTR + 106),
    GKS_TOOL_ICON_FILE	     = GKS_OPT( ATTR_STRING, GKS_FIRST_ATTR + 107),
    GKS_TOOL_ICON_LABEL	     = GKS_OPT( ATTR_STRING, GKS_FIRST_ATTR + 108),
    GKS_TOOL_ICON_LABEL_RECT = GKS_OPT( ATTR_RECT_PTR, GKS_FIRST_ATTR + 109),

    /* hp attributes start at offset 201 */
    GKS_HP_MINX		     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  201),
    GKS_HP_MINY		     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  202),
    GKS_HP_MAXX		     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  203),
    GKS_HP_MAXY		     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  204),
    GKS_HP_SOLID_FILL 	     = GKS_OPT( ATTR_BOOLEAN, GKS_FIRST_ATTR + 205),
    GKS_HP_TITLE	     = GKS_OPT( ATTR_STRING, GKS_FIRST_ATTR + 206),

    /* cgmo attributes start at offset 301 */
    GKS_CGMO_ENCODING	     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  301),
    GKS_CGMO_VDC_PREC	     = GKS_OPT( ATTR_INT, GKS_FIRST_ATTR +  302)

} Gks_config_attr;

typedef enum {		/* Configuration attribute codes for Fortran users */
    GBSTYPE = 0,        /* These attribute codes has to match the          */
    GGPUSE  = 1,	/* parameter values in GKS Fortran include file    */
    GMSGSZ  = 2,
    GNUMCLR = 3,
    GLCMODE = 4,
    GDCSZ   = 5,
    GTEXTSW = 6,
    GPANEL  = 7,
    GRSZPRC = 8,
    GDYNSEG = 9,
    GTLWDT  = 10,
    GTLHGT  = 11,
    GTLX    = 12,
    GTLY    = 13,
    GTLLBL  = 14,
    GTLFARG = 15,
    GTLICFL = 16,
    GTLICLB = 17,
    GTLICLR = 18,
    GHPMINX = 19,
    GHPMINY = 20,
    GHPMAXX = 21,
    GHPMAXY = 22,
    GHPSLFL = 23,
    GHPTITL = 24,
    GCGMENC = 25,
    GCGMVPR = 26,
    GDBLBFF = 27
} Gks_config_attr_f;

typedef struct gcf_config   *Gks_ws_config;

extern  void		gks_ws_config_destroy();
extern  int		gks_ws_config_set();
extern  Gks_attr_value	gks_ws_config_get();
extern  int		gks_ws_config_install();
extern  Gks_ws_config	gks_ws_config_get_installed();

extern  int	gkscf_errno;	/* contains index (origin 1) of first
				 * invalid attribute in an attribute-value
				 * list.  Not cleared, only set if an
				 * error occurs. */

#endif GKS_CONFIG_H_INCLUDED
