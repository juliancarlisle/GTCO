/* DEC/CMS REPLACEMENT HISTORY, Element SUN_AGKSTYPE.H*/
/* *3     3-MAY-1991 16:22:15 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *2    30-OCT-1990 13:10:43 GILLESPIE "(SPR 37) Add esi_gks.h for definition of Gmodtype"*/
/* *1    30-JUN-1989 15:06:45 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SUN_AGKSTYPE.H*/

/*	Copyright 1987 - PRIOR Data Sciences - GKS/C	*/
/*							*/
/*		Graphic Kernel System (GKS) in C	*/
/*		================================	*/
   
/*----------------------------------------------------------------------
|   
|-  File: agkstype.h    Revision: 11.1    (88/09/16)
|
|-  Contents:	ANSI-C Binding Data Type Definitions
|   
|-  Written:
|	1985 Jul 16	Michael Hoffman - PRIOR Data Sciences
|
|-  Modifications:
|
|	1987/01/19	Jennifer Black	- PRIOR Data Sciences Ltd., Ottawa
|	    - removed the ifdef MSDOS from around the undefine
|	      min and max statements. Conflict with the Sun.
|
|	1987/01/26	Derek Thorslund - PRIOR Data Sciences Ltd., Ottawa
|	    - Added the type Ggdpfac (bug #280)
|
|	1987 Jan 27	Jamie Spyker - PRIOR Data Sciences
|	    - Corrected the data types to match those of the standards
|	      document.  Main differences are related to the passing of
|	      implementation dependent data (all such must be defined as
|	      pointers to Gchar).
|
|	1987 Feb 3	Derek Thorslund - PRIOR Data Sciences Ltd.
|	    - fixed compilation problems resulting from above fix
|	      (missing "struct" in typedefs)
|
|	1987 Feb 11	Kim Stretton - PRIOR Data Sciences
|	    - corrected spelling mistakes in comments
|
|	1987 Feb 13	Michael F. Sargent - PRIOR Data Sciences Ltd.
|	    - added ifdef's back aroung the udef's for min and max because
|	      the encryption failed. The ifdef is now conditional on
|	      encryption which should make everything work just fine.
|
|	1987 Feb 23	Gayle Younger - PRIOR Data Sciences
| 	    - "devno" member of Gqinfo structure changed from
| 	      Gint to Gidevno.
|
|	1987 Mar 02	Kevin Cornell - PRIOR Data Sciences
|	    - The modifications for SCCS revision 1.19 were done
|	      incorrectly. Thus the file must be fixed manually
|	      by starting with SCCS revision 1.18 and making the
|	      appropriate changes.
|	    
|	1987 May 8	Kevin Cornell - PRIOR Data Sciences
|	    Made fixes to the input data records (fixup for SUN)
|	    Choice:
|		pet 2 - removed pet completely (not supported)
|		pet 4 - removed pet completely (not supported)
|		pet 5 - removed pet completely (not supported)
|	    Locator:
|		pet 4 - removed the field: Gchar *data
|		pet 5 - removed the field: Gchar *data
|		pet 6 - removed pet completely (not supported)
|	    Pick:
|		pet 2 - removed pet completely (not supported)
|		pet 3 - removed pet completely (not supported)
|	    String:
|		pet 2 - removed pet completely (not supported)
|	    Stroke:
|		pet 1 - removed the field: Gchar *data
|		        added   the field: Gmkattr mk
|		pet 2 - removed pet completely (not supported)
|		pet 3 - removed the field: Gchar *data
|		pet 4 - removed the field: Gchar *data
|	    Valuator:
|		pet 2 - removed pet completely (not supported)
|	
|	1987 Sep 8	Kevin Cornell - PRIOR Data Sciences
|	    Defined a new type "Ggdpi" for the GDP functions
|	    available to the ANSI C applications. This type is
|	    a general type used in agksfunc.h which is not included
|	    by any of the ANSI wrapper modules themselves. It is
|	    only included by ANSI applications.
|
|	1987 Nov 11	Kevin Cornell - PRIOR Data Sciences
|	    Modify the input device data record handling so that 
|	    ALL implementation PET (-ve PET and PET 1) use the 
|	    same field (pet1) of the data records. Also added
|	    PET 2 for the pick device.
|
|	1988 Feb 15	Ken Rode - PRIOR Data Sciences
|	    The escape data record has changed slightly to correct the
|	    mechanism whereby the escape function can be routed to all
|	    open or active workstations, instead of to a specific
|	    workstation. (B-581)
|
-----------------------------------------------------------------------*/

#ifndef SUN_AGKSTYPE_H
#define SUN_AGKSTYPE_H 1

#ifndef ESI_GKS_H
/* Get Gmodtype */
#include "esi_gks.h"
#endif

#ifndef ENCRYPTED
#ifdef min
#undef min
#endif 
#ifdef max
#undef max
#endif 
#endif 

/**********     ANSI Datatypes     **********/

typedef char	Gchar;
typedef int	Gint;
typedef Real	Gfloat;
typedef long	Glong;



/**********     ANSI Coordinate Systems     ********/

typedef struct	/* integer point */
    {
    Gint x;	/* x coordinate */
    Gint y;	/* y coordinate */
    } Gipoint;


typedef Gfloat	Gdc;	/* device coordinates */

typedef struct 	/* device coordinate point */
    {
    Gdc	x;	/* x coordinate */
    Gdc	y;	/* y coordinate */
    } Gdpoint;

typedef struct 	/* device coordinate limits */
    {
    Gdc	xmin;	/* x minimum limit */
    Gdc	xmax;	/* x maximum limit */
    Gdc ymin;	/* y minimum limit */
    Gdc ymax;	/* y maximum limit */
    } Gdlimit;

typedef struct	/* device coordinate rectangle */
    {
    Gdpoint ll;		/* lower left corner */
    Gdpoint ur;		/* upper right corner */
    } Gdrect;


typedef Gfloat	Gndc;	/* normalized device coordinates */

typedef struct	/* normalized device coordinate point */
    {
    Gndc x;	/* x coordinate */
    Gndc y;	/* y coordinate */
    } Gnpoint;

typedef	struct	/* normalized device coordinate limits */
    {
    Gndc xmin;	/* x minimum limit */
    Gndc xmax;	/* x maximum limit */
    Gndc ymin;	/* y minimum limit */
    Gndc ymax;	/* y maximum limit */
    } Gnlimit;

typedef struct	/* normalize device coordinate rectangle */
    {
    Gnpoint ll;	/* lower left corner */
    Gnpoint ur;	/* upper right corner */
    } Gnrect;


typedef Gfloat	Gwc;	/* world coordinates */

typedef struct	/* world coordinate point */
    {
    Gwc	x;	/* x coordinate */
    Gwc y;	/* y coordinate */
    } Gwpoint;

typedef struct	/* world coordinate limits */
    {
    Gwc xmin;	/* x minimum limit */
    Gwc xmax;	/* x maximum limit */
    Gwc ymin;	/* y minimum limit */
    Gwc ymax;	/* y maximum limit */
    } Gwlimit;

typedef struct	/* world coordinate rectangle */
    {
    Gwpoint ll;		/* lower left-hand corner */
    Gwpoint ur;		/* upper right-hand corner */
    } Gwrect;



/*********     ANSI Segment Information     *********/

typedef	Gint	Gseg;	/* segment */

typedef Gfloat	Gsegpri;	/* segment priority */

typedef struct	/* segment transformation */
    {
    Gfloat m11;		/* matrix element (1,1) */
    Gfloat m12;		/* matrix element (1,2) */
    Gndc   m13;		/* matrix element (1,3) */
    Gfloat m21;		/* matrix element (2,1) */
    Gfloat m22;		/* matrix element (2,2) */
    Gndc   m23;		/* matrix element (2,3) */
    } Gsegtran;



/**********     ANSI Dynamic Modifications     **********/


typedef struct	/* dynamic modification of segment attributes */
    {
    Gmodtype transform;		/* transformation */
    Gmodtype appear;		/* appearing (turning visible) */
    Gmodtype disappear;		/* disappearing (turning visible) */
    Gmodtype highlight;		/* highlighting */
    Gmodtype priority;		/* priority */
    Gmodtype addition;		/* addition of primitives to segment */
    Gmodtype deletion;		/* deletion of segment */
    } Gmodseg;

typedef struct	/* dynamic modification of workstation attributes */
    {
    Gmodtype line;	/* polyline */
    Gmodtype mark;	/* polymarker */
    Gmodtype text;	/* text */
    Gmodtype fill;	/* fill area */
    Gmodtype pat;	/* pattern */
    Gmodtype colour;	/* colour */
    Gmodtype wstran;	/* workstation transformation */
    } Gmodws;



/*********     Workstation Information     *********/

typedef	Gint	Gws;	/* workstation identifier: non-zero */

typedef struct	/* workstation connection and type */
    {
    Gchar *conn;	/* workstation connection */
    Gchar *type;	/* workstation type */
    } Gwsct;


typedef struct	/* workstation deferral and update state */
    {
    Gdefmode defmode;	/* deferral mode */
    Gdspsurf dspsurf;	/* display surface */
    Girgmode irgmode;	/* implicit regeneration mode */
    Gnframe  nframe;	/* new frame action at update */
    } Gwsdus;

typedef struct	/* deferral state */
    {
    Gdefmode defmode;	/* deferral mode */
    Girgmode irgmode;	/* implicit regeneration mode */
    } Gdefer;

typedef struct	/* workstation maximum numbers */
    {
    Gint open;		/* number of open workstations */
    Gint active;	/* number of active workstations */
    Gint assoc;		/* number of associated workstations */
    } Gwsmax;


typedef struct	/* length of workstation tables */
    {
    Gint line;		/* polyline tables */
    Gint mark;		/* polymarker tables */
    Gint text;		/* text tables */
    Gint fill;		/* fill area tables */
    Gint pat;		/* pattern tables */
    Gint colour;	/* colour tables */
    } Gwstables;

typedef struct	/* workstation transformation */
    {
    Gnlimit w;	/* window */
    Gdlimit v;	/* viewport */
    } Gwstran;


typedef struct	/* workstation transformation information */
    {
    Gwstus  wstus;	/* workstation transformation update state */
    Gwstran request;	/* requested transformation */
    Gwstran current;	/* current transformation */
    } Gwsti;



/**********     ANSI Colour and Flags     *********/

typedef	Gint	Gcolour;	/* colour index */


typedef	Gfloat	Ginten;		/* colour intensity */

typedef struct	/* colour bundle */
    {
    Ginten red;		/* red intensity */
    Ginten green;	/* green intensity */
    Ginten blue;	/* blue intensity */
    } Gcobundl;

typedef struct	/* colour facilities */
    {
    Gint     colours;		/* number of colours */
    Gcoavail coavail;		/* colour availability */
    Gint     predefined;	/* number of predefined bundles */
    } Gcofac;


typedef struct	/* pixel array */
    {
    Gcovalid covalid;	/* valid colours */
    Gcolour  *array;	/* pixel array */
    } Gpxarray;

typedef struct	/* aspect source flags */
    {
    Gasf ln_type;	/* line type */
    Gasf ln_width;	/* line width */
    Gasf ln_colour;	/* line colour */
    Gasf mk_type;	/* marker type */
    Gasf mk_size;	/* marker size */
    Gasf mk_colour;	/* marker colour */
    Gasf tx_fp;		/* text font and precision */
    Gasf tx_exp;	/* text expansion */
    Gasf tx_space;	/* text spacing */
    Gasf tx_colour;	/* text colour */
    Gasf fl_inter;	/* fill area interior style */
    Gasf fl_style;	/* fill area style index */
    Gasf fl_colour;	/* fill area colour */
    } Gasfs;



/**********     ANSI Bundle Information     **********/

typedef Gint	Gindex;		/* bundle index */


typedef struct	/* bundle index information */
    {
    Gint number;	/* number of bundles */
    Gbis *defined;	/* defined bundles */
    } Gbii;

typedef struct	/* pattern bundle */
    {
    Gipoint size;	/* pattern array size */
    Gcolour *array;	/* pattern array */
    } Gptbundl;

typedef struct	/* pattern facilities */
    {
    Gint types;		/* number of pattern types */
    Gint predefined;	/* number of predefined bundles */
    } Gptfac;



/**********     ANSI Output Attributes     *********/


/** Fill Area **/


typedef Gint	Gflstyle;	/* fill area style index */

typedef	struct	/* fill area bundle */
    {
    Gflinter inter;	/* fill area interior style */
    Gflstyle style;	/* fill area style index */
    Gcolour  colour;	/* fill area colour index */
    } Gflbundl;

typedef	struct	/* fill area facilities */
    {
    Gint n_inter;	/* number of interior styles */
    Gint *interiors;	/* list of available interior styles */
    Gint n_hatch;	/* number of hatch styles */
    Gint *hatches;	/* list of available hatch styles */
    Gint predefined;	/* number of predefined bundels */
    } Gflfac;

typedef struct	/* fill area attributes */
    {
    Gasf     fl_inter;		/* fill area interior style ASF */
    Gasf     fl_style;		/* fill area style index ASF */
    Gasf     fl_colour;		/* fill area colour ASF */
    Gindex   fill;		/* fill area index */
    Gflbundl flbundl;		/* fill area bundle */
    } Gflattr;


/** Polyline **/

typedef Gint	Glntype;	/* line type */

typedef Gfloat	Gscale;		/* scale factor */

typedef	struct	/* polyline bundle */
    {
    Glntype type;	/* line type */
    Gscale  width;	/* linewidth scale factor */
    Gcolour colour;	/* polyline colour index */
    } Glnbundl;

typedef	struct	/* polyline facilities */
    {
    Gint types;		/* number of line types */
    Gint *list;		/* list of available line types */
    Gint widths;	/* number of line widths */
    Gdc	 nom;		/* nominal width */
    Gdc  min;		/* minimum width */
    Gdc  max;		/* maximum width */
    Gint predefined;	/* number of predefined bundles */
    } Glnfac;

typedef	struct	/* polyline attributes */
    {
    Gasf     ln_type;	/* linetype ASF */
    Gasf     ln_width;	/* linewidth ASF */
    Gasf     ln_colour;	/* line colour ASF */
    Gindex   line;	/* line index */
    Glnbundl lnbundl;	/* line bundle */
    } Glnattr;


/** Polymarker **/

typedef	Gint	Gmktype;	/* marker type */

typedef	struct	/* polymarker bundle */
    {
    Gmktype type;	/* marker type */
    Gscale  size;	/* marker size */
    Gcolour colour;	/* marker colour */
    } Gmkbundl;

typedef struct	/* polymarker facilities */
    {
    Gint types;		/* number of marker types */
    Gint *list;		/* list of available marker types */
    Gint sizes;		/* number of marker sizes */
    Gdc  nom;		/* nominal size */
    Gdc  min;		/* minimum size */
    Gdc  max;		/* maximum size */
    Gint predefined;	/* number of predefined bundles */
    } Gmkfac;

typedef struct	/* polymarker attributes */
    {
    Gasf     mk_type;	/* marker type */
    Gasf     mk_size;	/* marker width */
    Gasf     mk_colour;	/* marker colour */
    Gindex   mark;	/* marker index */
    Gmkbundl mkbundl;	/* marker bundle */
    } Gmkattr;


/** Text **/

typedef	Gint	Gtxfont;	/* text font */


typedef	struct	/* text font and precision */
    {
    Gtxfont font;	/* text font */
    Gtxprec prec;	/* text precision */
    } Gtxfp;

typedef	struct	/* text alignment */
    {
    Gtxhor hor;		/* horizontal component */
    Gtxver ver;		/* vertical component */
    } Gtxalign;


typedef struct	/* text extent */
    {
    Gwpoint concat;	/* concatenation point */
    Gwpoint ll;		/* lower left corner */
    Gwpoint lr;		/* lower right corner */
    Gwpoint ur;		/* upper right corner */
    Gwpoint ul;		/* upper left corner */
    } Gextent;


typedef Gfloat	Gchrexp;	/* character expansion factor */

typedef Gfloat	Gchrsp;		/* character spacing */

typedef Gwc	Gchrht;		/* character height */

typedef Gwc	Gchrwid;	/* character width */

typedef struct	/* text bundle */
    {
    Gtxfp   fp;		/* font and precision */
    Gchrexp exp;	/* character expansion */
    Gchrsp  space;	/* character spacing */
    Gcolour colour;	/* text colour */
    } Gtxbundl;

typedef	struct	/* text facilities */
    {
    Gint  fps;		/* number of fonts and precisions */
    Gtxfp *fp_list;	/* list of available fonts and precisions */
    Gint  heights;	/* number of character heights */
    Gdc   min_ht;	/* minimum height */
    Gdc   max_ht;	/* maximum height */
    Gint  expansions;	/* number of character expansion factor */
    Gdc   min_ex;	/* minimum expansion factor */
    Gdc   max_ex;	/* maximum expansion factor */
    Gint  predefined;	/* number of predefined bundles */
    } Gtxfac;

typedef struct	/* text attributes */
    {
    Gasf     tx_fp;	/* text font and precision ASF */
    Gasf     tx_exp;	/* text character expansion ASF */
    Gasf     tx_space;	/* text character spacing ASF */
    Gasf     tx_colour;	/* text colour ASF */
    Gindex   text;	/* text index */
    Gtxbundl txbundl;	/* text bundle */
    } Gtxattr;

/** GDP's **/

typedef struct
    {
    Gint   number;	/* number of GDP's */
    Gattrs *attrs;	/* list of attributes used */
    } Ggdpfac;

typedef union 
    {
    struct 
	{
	char *temp;
	} gdpid1;
    } Ggdprec;
    


/**********     ANSI Input     **********/


typedef Gint	Gidevno;	/* input device number */

typedef struct	/* event */
    {
    Gws     ws;		/* workstation */
    Gidevno dev;	/* device number */
    Giclass class;      /* event class */
    } Gevent;


typedef Gint	Gpet;	/* prompt and echo type */


typedef	Gint	Gpickid;	/* pick identifier */


/** Choice **/
/** Utilitarian types required to conform to the standards rule that all **/
/** implementation dependent data must be linked to the type by a Gchar * **/

typedef struct 
    {
    Gint    number;	 	/* choice number */
    Gchar   **strings;		/* choice string */
    Gint    *alt;		/* number of alternatives */
    Gcolour colour;		/* colour index */
    } Guchpet1;

typedef struct 
    {
    Gint    *alt;		/* number of alternatives */
    Gcolour colour;		/* colour index */
    } Guchpet3;


/** GKS/C presently supports 5 pets **/
/**  (Pets -3, -2, -1, 1, 3) **/
typedef union	/* choice data record */
    {
    struct
	{
	Gchar	*data;	/* actually a pointer to a Guchpet1 record */
	} pet1;		/* Implementation PETs (1 and all -ve PETs) */
    struct
	{
	Gint    number;		/* number of choice strings */
	Gchar   **strings;	/* array of strings */
	Gchar	*data;		/* actually a pointer to a Guchpet3 record */
	} pet3;
    } Gchoicerec;

typedef struct	/* choice state */
    {
    Gimode     mode;	/* mode */
    Gesw       esw;	/* echo switch */
    Gint       choice;	/* choice data */
    Gpet       pet;	/* prompt and echo type */
    Gdlimit    e_area;	/* echo area */
    Gchoicerec record;	/* choice data record */
    } Gchoicest;

typedef struct	/* default choice data */
    {
    Gint       choices;		/* maximum number of choices */
    Gint       n_pets;		/* number of prompt and echo types */
    Gpet       *pets;		/* list of prompt and echo types */
    Gdlimit    e_area;		/* default echo area */
    Gchoicerec record;		/* default choice data record */
    } Gdefchoice;

typedef struct	/* request choice */
    {
    Gcstat status;	/* request status */
    Gint   choice;	/* choice data */
    } Gqchoice;


/** Locator **/

typedef union	/* locator data record */
    {
    struct
	{
	Gchar	*data;	/* actually is a pointer to a Gcolour value */
	} pet1;		/* Implementation PETs (1 and all -ve PETs) */
    struct
	{
	Gchar	*data;	/* actually is a pointer to a Gcolour value */
	} pet2;
    struct
	{
	Gchar	*data;	/* actually is a pointer to a Gcolour value */
	} pet3;
    struct
	{
	Gacf    acf;	/* attribute control flag */
	Glnattr ln;	/* polyline attributes */
	} pet4;
    struct
	{
	Gpfcf pfcf;	/* polyline/fill area control flag */
	Gacf  acf;	/* attribute control flag */
	union
	    {
	    Glnattr ln;		/* polyline attributes */
	    Gflattr fl;		/* fill area attributes */
	    } attr;
	} pet5;
    } Glocrec;

typedef struct	/* locator data */
    {
    Gint    transform;	/* normalization transformation number */
    Gwpoint position;	/* locator position */
    } Gloc;

typedef struct	/* locator state */
    {
    Gimode  mode;	/* mode */
    Gesw    esw;	/* echo switch */
    Gloc    loc;	/* locator data */
    Gpet    pet;	/* prompt and echo type */
    Gdlimit e_area;	/* echo area */
    Glocrec record;	/* locator data record */
    } Glocst;

typedef	struct	/* default locator data */
    {
    Gwpoint position;	/* initial position */
    Gint    n_pets;	/* number of prompt and echo types */
    Gpet    *pets;	/* list of prompt and echo types */
    Gdlimit e_area;	/* default echo area */
    Glocrec record;	/* default locator data record */
    } Gdefloc;

typedef	struct	/* request locator */
    {
    Gistat status;	/* request status */
    Gloc   loc;		/* locator data */
    } Gqloc;

/** Pick **/

/** Utilitarian types required to conform to the standards rule that all **/
/** implementation dependent data must be linked to the type by a Gchar * **/

typedef struct 
    {
    Gfloat  ratio;	/* pick ratio */
    Gcolour colour; 	/* pick colour */
    } Gupkpet1;

typedef struct 
    {
    Gfloat  ratio;	/* pick ratio */
    Gcolour colour; 	/* pick colour */
    } Gupkpet2;

/** GKS/C presently supports pick pets 1 and 2 **/
/**  (Pet 1) **/
typedef	union	/* pick data record */
    {
    struct
	{
	Gchar *data;	/* actually a pointer to a Gupkpet1 record */
	} pet1;		/* Implementation PETs (1 and all -ve PETs) */
    struct
	{
	Gchar *data;	/* actually a pointer to a Gupkpet2 record */
	} pet2;
    } Gpickrec;

typedef	struct	/* pick data */
    {
    Gpstat  status;	/* pick status */
    Gseg    seg;	/* pick segment */
    Gpickid pickid;	/* pick identifier */
    } Gpick;

typedef struct	/* pick state */
    {
    Gimode   mode;	/* mode */
    Gesw     esw;	/* echo switch */
    Gpick    pick;	/* pick data */
    Gpet     pet;	/* prompt and echo type */
    Gdlimit  e_area;	/* echo area */
    Gpickrec record;	/* pick data record */
    } Gpickst;

typedef struct	/* default pick data */
    {
    Gint     n_pets;	/* number of prompt and echo types */
    Gpet     *pets;	/* list of prompt and echo types */
    Gdlimit  e_area;	/* default echo area */
    Gpickrec record;	/* default pick data record */
    } Gdefpick;

typedef struct	/* request pick */
    {
    Gpstat  status;	/* request status */
    Gseg    seg;	/* segment */
    Gpickid pickid;	/* pick identifier */
    } Gqpick;



/** String **/

/** GKS/C presently supports 2 string pets **/
/**  (pets -1 and 1) **/
typedef union	/* string data record */
    {
    struct
	{
	Gint    bufsiz;		/* buffer size */
	Gint    position;	/* initial cursor position */
	Gchar	*data;		/* actually is a pointer to a Gcolour */
	} pet1;		/* Implementation PETs (1 and all -ve PETs) */
    } Gstringrec;

typedef struct	/* string state */
    {
    Gimode     mode;	/* mode */
    Gesw       esw;	/* echo switch */
    Gchar      *string;	/* string data */
    Gpet       pet;	/* prompt and echo type */
    Gdlimit    e_area;	/* echo area */
    Gstringrec record;  /* string data record */
    } Gstringst;

typedef struct	/* default string data */
    {
    Gint       bufsiz;	/* initial buffer size */
    Gint       n_pets;	/* number of prompt and echo types */
    Gpet       *pets;	/* list of prompt and echo types */
    Gdlimit    e_area;	/* default echo area */
    Gstringrec record;	/* default string data record */
    } Gdefstring;

typedef struct	/* request string */
    {
    Gistat status;	/* request status */
    Gchar  *string;	/* string data */
    } Gqstring;


/** Stroke **/

/** GKS/C presently supports 2 stroke pets **/
/**  (Pets 1, 3) **/
typedef union	/* stroke data record */
    {
    struct
	{
	Gint    bufsiz; 	/* input buffer size */
	Gint    editpos;	/* editing position */
	Gwpoint interval;	/* x,y interval */
	Gfloat  time;		/* time interval */
	Gmkattr mk;		/* marker attributes */
	} pet1;		/* Implementation PETs (1 and all -ve PETs) */
    struct
	{
	Gint    bufsiz; 	/* input buffer size */
	Gint    editpos;	/* editing position */
	Gwpoint interval;	/* x,y interval */
	Gfloat  time;		/* time interval */
	Gacf    acf;		/* attribute control flag */
	Gmkattr mk;	        /* marker attributes */
	} pet3;
    struct
	{
	Gint    bufsiz;	/* input buffer size */
	Gint    editpos;	/* editing position */
	Gwpoint interval;	/* x,y interval */
	Gfloat  time;		/* time interval */
	Gacf    acf;		/* attribute control flag */
	Glnattr ln;	        /* marker attributes */
	} pet4;
    } Gstrokerec;

typedef struct	/* stroke data */
    {
    Gint    transform;		/* normalization transformation number */
    Gint    n_points;		/* number of points in stroke */
    Gwpoint *points;		/* points in stroke */
    } Gstroke;

typedef struct	/* stroke state */
    {
    Gimode     mode;		/* mode */
    Gesw       esw;		/* echo switch */
    Gstroke    stroke;		/* stroke data */
    Gpet       pet;		/* prompt and echo type */
    Gdlimit    e_area;		/* echo area */
    Gstrokerec record;		/* stroke data record */
    } Gstrokest;

typedef struct	/* default stroke data */
    {
    Gint       bufsiz;		/* buffer size */
    Gint       n_pets;		/* number of prompt and echo types */
    Gpet       *pets;		/* list of prompt and echo types */
    Gdlimit    e_area;		/* default echo area */
    Gstrokerec record;		/* default stroke data record */
    } Gdefstroke;

typedef struct	/* request stroke */
    {
    Gistat  status;		/* request status */
    Gstroke stroke;		/* stroke data */
    } Gqstroke;


/** Valuator **/

/** GKS/C presently supports 2 valuator pets **/
/**  (Pets 1 and 3) **/
typedef union	/* valuator data record */
    {
    struct
	{
	Gfloat  low;	/* low range limit */
	Gfloat  high;	/* high range limit */
	Gchar	*data;	/* actually is a pointer to a Gcolour */
	} pet1;		/* Implementation PETs (1 and all -ve PETs) */
    struct
	{
	Gfloat  low;	/* low range limit */
	Gfloat  high;	/* high range limit */
	Gchar	*data;	/* actually is a pointer to a Gcolour */
	} pet3;
    } Gvalrec;

typedef struct	/* valuator state */
    {
    Gimode  mode;	/* mode */
    Gesw    esw;	/* echo switch */
    Gfloat  val;	/* valuator data */
    Gpet    pet;	/* prompt and echo type */
    Gdlimit e_area;	/* echo area */
    Gvalrec record;	/* valuator data record */
    } Gvalst;

typedef struct	/* valuator default data */
    {
    Gfloat  value;	/* initial value */
    Gint    n_pets;	/* number of prompt and echo types */
    Gpet    *pets;	/* list of prompt and echo types */
    Gdlimit e_area;	/* default echo area */
    Gvalrec record;	/* default valuator record data */
    } Gdefval;

typedef struct	/* request valuator */
    {
    Gistat status;	/* request status */
    Gfloat val;		/* valuator data */
    } Gqval;

    

typedef struct	/* GKS metafile item */
    {
    Gint type;		/* item type */
    Gint length;	/* item length */
    } Ggksmit;



/**********     ANSI Device Information     *********/


typedef struct	/* clipping rectangle */
    {
    Gclip   ind;	/* clipping indicator */
    Gnlimit rec;	/* clipping rectangle */
    } Gcliprec;


typedef struct	/* display size */
    {
    Gdevunits units;	/* device coordinate units */
    Gdpoint   device;	/* device coordinate unit size */
    Gipoint   raster;	/* raster unit size */
    } Gdspsize;

typedef struct	/* number of input devices */
    {
    Gint locator;	/* locators */
    Gint stroke;	/* strokes */
    Gint valuator;	/* valuators */
    Gint choice;	/* choices */
    Gint pick;		/* picks */
    Gint string;	/* strings */
    } Gnumdev;




/*********     ANSI Escapes     *********/

typedef struct
    {
    Gint      esc_function;
    Gescroute esc_route;
    Gws       esc_ws;
    Gint      n_ints;
    Gint     *int_array;
    Gint      n_reals;
    Gfloat   *real_array;
    Gint      n_strings;
    Gchar   **string_array;
    } Gescin;

/* This structure is never filled by ANSI or PRIOR GKS. */
typedef struct
    {
    Gint    status;
    Gint    n_ints;
    Gint   *int_array;
    Gint    n_reals;
    Gfloat *real_array;
    Gint    n_strings;
    Gchar **string_array;
    } Gescout;

typedef struct
    {
    Gws     ws;
    Giclass class;
    Gidevno devno;
    } Gqinfo;

/* Define a type for the ANSI GDP functions, for applications only. */
#define	Ggdpi   int

#endif
