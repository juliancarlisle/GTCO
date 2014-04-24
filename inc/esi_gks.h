/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GKS.H*/
/* *13    3-MAY-1991 16:21:23 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *12   30-OCT-1990 11:33:09 KEE "(SPR -1) Fix compile noise at sun"*/
/* *11   23-OCT-1990 14:06:08 KEE "(SPR -1) Motif and DecWindow merge"*/
/* *10   14-AUG-1990 11:47:36 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *9     3-MAY-1990 21:50:26 KEE "(SPR -1) multi window support."*/
/* *8     5-MAR-1990 17:09:24 JULIAN "(SPR 6010) Removed ifdef VAXSTATION (not used anymore)"*/
/* *7     3-MAR-1990 12:00:19 GILLESPIE "(SPR 6010) Replace MAIN_WKID into Sun code; remove old macros"*/
/* *6     1-MAR-1990 14:25:41 JULIAN "(SPR 6010) Changed MAIN_WKID to function  call"*/
/* *5    28-FEB-1990 15:42:25 JULIAN "(SPR -1) Add elements to WM_CURRENT struct, change MAIN_WKID & GKS_WISS_WKID def (kee)"*/
/* *4    26-FEB-1990 19:06:47 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)"*/
/* *3    18-DEC-1989 11:54:40 CONROY "(SPR 5078) Mods for plotting GKS polymarkers"*/
/* *2    26-JUL-1989 00:12:48 GILLESPIE "(SPR 51) Minor adjustments"*/
/* *1    30-JUN-1989 15:00:46 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_GKS.H*/
/******************************************************************************     */
/*                                                                                  */
/*                Copyright Finder Graphics Systems, Inc. 1990                      */
/*         Unpublished -- All rights reserved                                       */
/*                                                                                  */
/*THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Finder Graphics Systems, Inc.  AND   */
/*MAY CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE  */
/*DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE         */
/*MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF       */
/*                                                                                  */
/*          Finder Graphics Systems, Inc.                                           */
/*          201 Tamal Vista Blvd                                                    */
/*          Corte Madera, CA  USA 94925                                             */
/*          (415) 927-0100                                                          */
/*                                                                                  */
/*(The above notice does not constitute an admission of publication or              */
/*unrestricted dissemination of the work)                                           */
/*                                                                                  */
/******************************************************************************     */

/*                                                                                  */
/* * GKS definitions for VMS and PRIMOS                                             */
/*                                                                                  */

#ifndef ESI_GKS_H
#define ESI_GKS_H 1

#ifndef ESI_GTYPES_H
#include "esi_gtypes.h"
#endif

/*	#ifdef mips						 910319:sjs: not needed, using PRIOR */
/*	#ifndef _DESCRIPTOR				 910319:sjs: not needed, using PRIOR */
/*	#include "GKS3Ddescrip.h"		 910319:sjs: not needed, using PRIOR */
/*	#endif							 910319:sjs: not needed, using PRIOR */
/*	#include "GKS3Dgksbnd_defs.h"	 910319:sjs: not needed, using PRIOR */
/*	#include "GKS3Dgksbnd_msgs.h"	 910319:sjs: not needed, using PRIOR */
/*	#endif							 910319:sjs: not needed, using PRIOR */

typedef struct 
    {
    LINE_STYLE_INDEX type;
    COLOR_INDEX color;
    DOUBLE size_in_inches;
    DOUBLE inch_to_wcs_factor;
    } GKS_BATCH_POLYMARKERS;
#define GKS_CS_CIRCLE   1 /* circle */
#define GKS_CS_POINT    2 /* point */
#define GKS_CS_PLUS 3 /* plus */
#define GKS_CS_XMARK    4 /* cross */
#define GKS_CS_ASTERISK 5 /* asterisk */

/* * THE 15 WORKS ON THE VAXSTATION, AND THE 4 WORKED ON THE                        */
/*     RASTER, UNKNOWN WHAT IS NECESSARY FOR DECSTATION AND SUN *                   */

#ifdef vms  

#ifndef PRIOR_GKS
#define GKS_POLYMARKER_MULTIPLIER 15.0
#endif

#else

#define GKS_POLYMARKER_MULTIPLIER 4.0

#endif

#ifdef vms  

#ifndef PRIOR_GKS
#include "gksdefs.h"
#include "gksmsgs.h"
#endif

#endif

#ifdef vms

#ifndef PRIOR_GKS
extern INT gactm ();
extern INT gacwk ();
extern INT gasgwk ();
extern INT gca ();
extern INT gclks ();
extern INT gclrwk ();
extern INT gclsg ();
extern INT gclwk ();
extern INT gcrsg ();
extern INT gcsgwk ();
extern INT gdawk ();
extern INT gdsg ();
extern INT gdsgwk ();
extern INT gevtm ();
extern INT gfa ();
extern INT ggdp ();
extern INT ggtitm ();
extern INT giitm ();
extern INT ginlc ();
extern INT ginpk ();
extern INT ginsg ();
extern INT gkzqbtn ();
extern INT gkzschn ();
extern INT gopks ();
extern INT gopwk ();
extern INT gpl ();
extern INT gpm ();
extern INT gprec ();
extern INT gqchh ();
extern INT gqcntn ();
extern INT gqcr ();
extern INT gqdsp ();
extern INT gqfaci ();
extern INT gqfais ();
extern INT gqfasi ();
extern INT gqln ();
extern INT gqlwsc ();
extern INT gqmds ();
extern INT gqmk ();
extern INT gqmksc ();
extern INT gqnt ();
extern INT gqplci ();
extern INT gqpmci ();
extern INT gqsgwk ();
extern INT gqtxx ();
extern INT gquwkt ();
extern INT gqwkc ();
extern INT gqwkcl ();
extern INT gqwkdu ();
extern INT gqwkt ();
extern INT grditm ();
extern INT grensg ();
extern INT grqlc ();
extern INT grqpk ();
extern INT grsgwk ();
extern INT grsgwk ();
extern INT gschh ();
extern INT gschsp ();
extern INT gschup ();
extern INT gschxp ();
extern INT gsclip ();
extern INT gscr ();
extern INT gsds ();
extern INT gsdtec ();
extern INT gselnt ();
extern INT gsfaci ();
extern INT gsfai ();
extern INT gsfais ();
extern INT gsfasi ();
extern INT gshlit ();
extern INT gsln ();
extern INT gslwsc ();
extern INT gsmk ();
extern INT gsmksc ();
extern INT gspa ();
extern INT gsparf ();
extern INT gspkid ();
extern INT gsplci ();
extern INT gspli ();
extern INT gspmci ();
extern INT gspmi ();
extern INT gssgp ();
extern INT gssgt ();
extern INT gstxal ();
extern INT gstxci ();
extern INT gstxfp ();
extern INT gstxi ();
extern INT gstxp ();
extern INT gsvis ();
extern INT gsvp ();
extern INT gsvpip ();
extern INT gswkvp ();
extern INT gswkwn ();
extern INT gswn ();
extern INT gtx ();
extern INT gtxs ();
extern INT gurec ();
extern INT guwk ();
extern INT gwitm ();
#endif

#endif

/* CONSTANTS                                                                        */

/* Workstation ids.                                                                 */
#define MAIN_WKID        wm_mainwkid()
#define MAX_WKID     wm_maxwknum()
#define GKS_WISS_WKID    (MAX_WKID) 
#define GKS_METAIN_WKID  (MAX_WKID + 1)
#define GKS_METAOUT_WKID (MAX_WKID + 2)

#if UNIX							/* 910319:sjs: changed from sun */
#ifndef SUN_GKS_OR_PRIOR_GKS
#define SUN_GKS_OR_PRIOR_GKS 1
#endif
#endif

#ifdef PRIOR_GKS
#ifndef SUN_GKS_OR_PRIOR_GKS
#define SUN_GKS_OR_PRIOR_GKS 1
#endif
#endif

#ifdef SUN_GKS_OR_PRIOR_GKS

/**********     ANSI Coordinate Systems     *******                                 */

#define Gcsw unsigned   /* coordinate switch */
#define  GWC 0      /* world coordinates */
#define  GNDC 1     /* normalized device coordinates */


/*********     ANSI Segment Information     ********                                */


#define Gsegdet unsigned    /* segment detectability */
#define GUNDET 0
#define GDETEC 1
#define Gseghi unsigned     /* segment highlighting */
#define GNORML 0
#define GHILIT 1
#define Gsegvis unsigned    /* segment visibility */
#define GVISI 0
#define GINVIS 1


/**********     ANSI Dynamic Modifications     *********                            */

#define Gmodtype unsigned   /* dynamic modification type */
#define GIRG 0
#define GIMM 1

/*********     Workstation Information     ********                                 */

/***** Workstation Types *******                                                    */

#define GKS_WISS_WTYPE      1
#define GKS_MI_WTYPE        2
#define GKS_MOASC_WTYPE     3
#define GKS_SUN_TOOL_WTYPE  4
#define GKS_SUN_CANVAS_WTYPE    5
#define GKS_HPGL_WTYPE      6
#define GKS_POSTSCRIPT_WTYPE    7
#define GKS_CGMO_WTYPE      8
#define GKS_CGMI_WTYPE      9
#define GWSDEF GKS_SUN_TOOL_WTYPE
#define GCONID 0
#define GWSWIS GKS_WISS_WTYPE
#define Gwscat unsigned /* workstation categories */
#define GOUTPT 0
#define GINPUT 1
#define GOUTIN 2
#define GWISS 3
#define GMO 4
#define GMI 5
#define Gdefmode unsigned   /* deferral mode */
#define GASAP 0     /* as soon as possible */
#define GBNIG 1     /* before next interaction globally */
#define GBNIL 2     /* before next interaction locally */
#define GASTI 3     /* at some time */
#define Gdspsurf unsigned   /* display surface */
#define GEMPTY 0
#define GNEMPT 1
#define Girgmode unsigned   /* inplict regeneration mode */
#define GSUPPD 0
#define GALLOW 1
#define Gregen unsigned /* regeneration flag */
#define GPERFO 0
#define GPOSTP 1
#define Gnframe unsigned    /* new frame action at update */
#define GNO 0
#define GYES 1
#define Gwsstate unsigned   /* workstation state */
#define GINACT 0
#define GACTIV 1
#define Gwstus unsigned /* workstation transformation update state */
#define GNPEND 0
#define GPEND 1
#define Gwsclass unsigned   /* workstation classifacatin */
#define GVECTR 0
#define GRASTR 1
#define GOTHWK 2

/* The possible dynamic segment states. These must match with the                   */
/*   PRIOR binding type DynState.                                                   */

#define Gdynstate   int
#define G_DYN_OPT_UNDRAW    -2
#define G_DYN_OPT_ERASE     -1
#define G_DYN_OFF        0
#define G_DYN_ON_ERASE       1
#define G_DYN_ON_UNDRAW      2


/**********     ANSI Colour and Flags     ********                                  */

#define Gcoavail unsigned   /* colour availability */
#define GCOLOR 0
#define GMONOC 1
#define Gcovalid unsigned   /* colour values valid */
#define GABSNT 0
#define GPRSNT 1
#define Gacf unsigned   /* attribute control flag */
#define GCURNT 0
#define GSPEC 1
#define Gasf unsigned   /* aspect source flag */
#define GBUNDL 0
#define GINDIV 1

/**********     ANSI Bundle Information     *********                               */

#define Gbis unsigned   /* bundle index setting */
#define DEFINED 0
#define UNDEFINED 1

/**********     ANSI Output Attributes     ********                                 */

#define Gpfcf unsigned  /* polyline/fill area control flag */
#define GPLINE 0
#define GFILLA 1
#define Gattrs unsigned /* attributes used */
#define GPLBND 0
#define GPMBND 1
#define GTXBND 2
#define GFABND 3

/** Fill Area *                                                                     */

#define Gflinter unsigned   /* fill area interior styles */
#define GHOLLO 0
#define GSOLID 1
#define GPATTR 2
#define GHATCH 3

/** Text *                                                                          */


#define Gtxprec unsigned    /* text precision */
#define GSTRP 0
#define GCHARP 1
#define GSTRKP 2
#define Gtxhor unsigned /* text alignment horizontal component */
#define GAHNOR 0
#define GALEFT 1
#define GACENT 2
#define GARITE 3
#define Gtxver unsigned /* text alignment vertical component */
#define GAVNOR 0
#define GATOP 1
#define GACAP 2
#define GAHALF 3
#define GABASE 4
#define GABOTT 5
#define Gtxpath unsigned    /* text path */
#define GRIGHT 0
#define GLEFT 1
#define GUP 2
#define GDOWN 3

/**********     ANSI Input     *********                                            */

#define Gqtype unsigned /* inquiry type */
#define GSET 0
#define GREALI 1
#define Gsimultev unsigned  /* simultaneous events */
#define GNMORE 0
#define GMORE 1
#define Gimode unsigned /* input modes */
#define GREQU 0
#define GSAMPL 1
#define GEVENT 2
#define Giclass unsigned    /* input classes */
#define GNCLAS 0
#define GLOCAT 1
#define GSTROK 2
#define GVALUA 3
#define GCHOIC 4
#define GPICK 5
#define GSTRIN 6
#define Gistat unsigned /* request status */
#define GOK 0
#define GNONE 1
#define Gesw unsigned   /* echo switch */
#define GECHO 0
#define GNECHO 1
#define Gtoggle unsigned    /* toggle switch */
#define GPROFF 0
#define GPRON 1

/** Choice *                                                                        */

#define Gcstat unsigned /* choice status */
#define GCOK 0
#define GNCHOI 1
#define GCNONE 2

/** GKS/C presently supports 5 pets *                                               */
/**  (Pets -3, -2, -1, 1, 3) *                                                      */

/** Locator *                                                                       */

/** GKS/C presently supports 4 locater pets *                                       */
/**  (Pets 1, 2, 3 and 4) *                                                         */

/** Pick *                                                                          */

#define Gpstat unsigned /* pick status */
#define GPOK 0
#define GNPICK 1
#define GPNONE 2

/** GKS/C presently supports 1 pick pet *                                           */
/**  (Pet 1) *                                                                      */

/** String *                                                                        */

/** GKS/C presently supports 2 string pets *                                        */
/**  (pets -1 and 1) *                                                              */

/** Stroke *                                                                        */

/** GKS/C presently supports 2 stroke pets *                                        */
/**  (Pets 1 and 3) *                                                               */

/** Valuator *                                                                      */

/** GKS/C presently supports 2 valuator pets *                                      */
/**  (Pets 1 and 3) *                                                               */

/**********     ANSI Device Information     ********                                */

#define Gclip unsigned  /* clipping indicator */
#define GCLIP 0
#define GNCLIP 1
#define Gclrflag unsigned   /* clear control flag */
#define GCONDI 0
#define GALWAY 1
#define Gdevunits unsigned  /* device coordinate units */
#define GMETRE 0
#define GOTHU 1
#define Gos unsigned    /* GKS operating state */
#define GGKCL 0     /* GKS closed */
#define GGKOP 1     /* GKS open */
#define GWSOP 2     /* workstation open */
#define GWSAC 3     /* workstation active */
#define GSGOP 4     /* segment open */
#define Gvpri unsigned  /* viewport input priority */
#define GHIGHR 0
#define GLOWER 1

/*********     Escape Function Routing     ********                                 */

#define Gescroute   unsigned
#define G_SPECIFIC_WS   0   /* route to the specified workstation   */
#define G_ALL_OPEN_WS   1   /* route to all open workstations   */
#define G_ALL_ACTIVE_WS 2   /* route to all active workstations */

/* Polyline Linetypes                                                               */

#define GLSOLI  1 /* solid */
#define GLDASH  2 /* dashed */
#define GLDOT   3 /* dotted */
#define GLDASD  4 /* dotdashed */

/* Polymarker Markertypes                                                           */

#define GPOINT  1 /* dot */
#define GPLUS   2 /* plus */
#define GAST    3 /* asterisk */
#define GOMARK  4 /* circle */
#define GXMARK  5 /* cross */

/*******    Stroke Font Character Set and Font Numbers  ***********                 */
/**************  These come from gks/gkstxconst.h  ****************                 */


#define GFONT_ROMAN_SIMPLEX     1
#define GFONT_ROMAN_DUPLEX      2
#define GFONT_ROMAN_TRIPLEX     3
#define GFONT_ITALIC_COMPLEX    4
#define GFONT_ITALIC_TRIPLEX    5
#define GFONT_SCRIPT_SIMPLEX    6
#define GFONT_SCRIPT_COMPLEX    7
#define GFONT_GREEK_SIMPLEX     8
#define GFONT_GREEK_COMPLEX     9
#define GFONT_GOTHIC_ENGLISH    10
#define GFONT_ROMAN_COMPLEX     11
#define GFONT_ROMAN_MONO        12
#define GFONT_CARTOGRAPHIC      13
#define GFONT_MISC              14
#define SIMPLEX GFONT_ROMAN_SIMPLEX
#define DUPLEX  GFONT_ROMAN_DUPLEX
#define TRIPLEX GFONT_ROMAN_TRIPLEX
#define SCRIPT  GFONT_SCRIPT_SIMPLEX
#define GOTHIC  GFONT_GOTHIC_ENGLISH


/*******    Raster Font Font Numbers  ***********                                   */
/****  These come from sun/rast_fontdefs.h  *****                                   */

#define G_APL_R     -1
#define G_CMR_R     -2
#define G_CMR_B     -3
#define G_COUR_R        -4
#define G_COUR_B        -5
#define G_GACHA_R   -6
#define G_GACHA_B       -7
#define G_GALLANT_R -8
#define G_SAIL_R    -9
#define G_SCREEN_R  -10
#define G_SCREEN_B  -11
#define G_SERIF_R   -12

/* Priorities                                                                       */
#define HIGHER          GHIGHR
#define LOWER           GLOWER

/* Fill Area Styles                                                                 */
#define HOLLOW                  GHOLLO
#define SOLID                   GSOLID
#define PATTERN                 GPATTR
#define HATCH                   GHATCH

/* Character Precision                                                              */
#define STRING_PRECISION    GSTRP
#define CHAR_PRECISION      GCHARP
#define STROKE_PRECISION    GSTRKP

/* Prompt echo types.                                                               */
#define UGRQ_TYPE_BAND_VECTOR       ((GKS_INT)-4)
#define UGRQ_TYPE_BAND_RECTANGLE    ((GKS_INT)-5)
#define UGRQ_TYPE_DRAG_SEGMENT      ((GKS_INT)-7)

#else /* VAX and NOVA GKS */

/**********     ANSI Coordinate Systems     *******                                 */

/* coordinate switch                                                                */
#define  GWC ((GKS_INT)0        /* world coordinates */
#define  GNDC ((GKS_INT)1       /* normalized device coordinates */


/*********     ANSI Segment Information     ********                                */

/* segment detectability                                                            */
#define GUNDET ((GKS_INT)0)
#define GDETEC ((GKS_INT)1)

/* segment highlighting                                                             */
#define GNORML ((GKS_INT)0)
#define GHILIT ((GKS_INT)1)

/* segment visibility                                                               */
#define GVISI ((GKS_INT)1)
#define GINVIS ((GKS_INT)0)


/**********     ANSI Dynamic Modifications     *********                            */

/* dynamic modification type                                                        */
#define GIRG ((GKS_INT)0)
#define GIMM ((GKS_INT)1)


/*********     Workstation Information     ********                                 */

/***  Workstation types constants **                                                */

#ifdef VAXSTATION

#define GKS_WISS_WTYPE          ((GKS_INT)5)

#else

#define GKS_WISS_WTYPE          ((GKS_INT)0)

#endif

#define GWSDEF  ((GKS_INT)0)    /* Default workstation type                 */
#define GCONID  ((GKS_INT)0)    /* Default connection identifier            */
#define GWSWIS  ((GKS_INT)5)    /* GKS WISS workstation                     */

/* workstation categories                                                           */
#define GOUTPT ((GKS_INT)0)
#define GINPUT ((GKS_INT)1)
#define GOUTIN ((GKS_INT)2)
#define GMO ((GKS_INT)4)
#define GMI ((GKS_INT)5)

/* deferral mode                                                                    */
#define GASAP ((GKS_INT)0)      /* as soon as possible */
#define GBNIG ((GKS_INT)1)      /* before next interaction globally */
#define GBNIL ((GKS_INT)2)      /* before next interaction locally */
#define GASTI ((GKS_INT)3)      /* at some time */

/* display surface                                                                  */
#define GEMPTY ((GKS_INT)1)
#define GNEMPT ((GKS_INT)0)

/* inplict regeneration mode                                                        */
#define GSUPPD ((GKS_INT)0)
#define GALLOW ((GKS_INT)1)

/* regeneration flag                                                                */
#define GPERFO ((GKS_INT)1)
#define GPOSTP ((GKS_INT)0)

/* new frame action at update                                                       */
#define GNO ((GKS_INT)0)
#define GYES ((GKS_INT)1)

/* workstation state                                                                */
#define GINACT ((GKS_INT)0)
#define GACTIV ((GKS_INT)1)

/* workstation transformation update state                                          */
#define GNPEND ((GKS_INT)0)
#define GPEND ((GKS_INT)1)

/* workstation classifacatin                                                        */
#define GVECTR ((GKS_INT)0)
#define GRASTR ((GKS_INT)1)
#define GOTHWK ((GKS_INT)2)

/**********     ANSI Colour and Flags     ********                                  */

/* colour availability                                                              */
#define GCOLOR ((GKS_INT)0)
#define GMONOC ((GKS_INT)1)

/* colour values valid                                                              */
#define GABSNT ((GKS_INT)0)
#define GPRSNT ((GKS_INT)1)

/* attribute control flag                                                           */
#define GCURNT ((GKS_INT)0)
#define GSPEC ((GKS_INT)1)

/* aspect source flag                                                               */
#define GBUNDL ((GKS_INT)0)
#define GINDIV ((GKS_INT)1)

/**********     ANSI Bundle Information     *********                               */

/* bundle index setting                                                             */
#define DEFINED ((GKS_INT)0)
#define UNDEFINED ((GKS_INT)1)

/**********     ANSI Output Attributes     ********                                 */

/* polyline/fill area control flag                                                  */
#define GPLINE ((GKS_INT)0)
#define GFILLA ((GKS_INT)1)

/* attributes used                                                                  */
#define GPLBND ((GKS_INT)0)
#define GPMBND ((GKS_INT)1)
#define GTXBND ((GKS_INT)2)
#define GFABND ((GKS_INT)3)

/** Fill Area *                                                                     */

/* fill area interior styles                                                        */
#define GHOLLO ((GKS_INT)0)
#define GSOLID ((GKS_INT)1)
#define GPATTR ((GKS_INT)2)
#define GHATCH ((GKS_INT)3)

/** Text *                                                                          */

/* text precision                                                                   */
#define GSTRP ((GKS_INT)0)
#define GCHARP ((GKS_INT)1)
#define GSTRKP ((GKS_INT)2)

/* text alignment horizontal component                                              */
#define GAHNOR ((GKS_INT)0)
#define GALEFT ((GKS_INT)1)
#define GACENT ((GKS_INT)2)
#define GARITE ((GKS_INT)3)

/* text alignment vertical component                                                */
#define GAVNOR ((GKS_INT)0)
#define GATOP ((GKS_INT)1)
#define GACAP ((GKS_INT)2)
#define GAHALF ((GKS_INT)3)
#define GABASE ((GKS_INT)4)
#define GABOTT ((GKS_INT)5)

/* text path                                                                        */
#define GRIGHT ((GKS_INT)0)
#define GLEFT ((GKS_INT)1)
#define GUP ((GKS_INT)2)
#define GDOWN ((GKS_INT)3)

/**********     ANSI Input     *********                                            */

/* inquiry type                                                                     */
#define GSET ((GKS_INT)0)
#define GREALI ((GKS_INT)1)

/* simultaneous events                                                              */
#define GNMORE ((GKS_INT)0)
#define GMORE ((GKS_INT)1)

/* input modes                                                                      */
#define GREQU ((GKS_INT)0)
#define GSAMPL ((GKS_INT)1)
#define GEVENT ((GKS_INT)2)

/* input classes                                                                    */
#define GNCLAS ((GKS_INT)0)
#define GLOCAT ((GKS_INT)1)
#define GSTROK ((GKS_INT)2)
#define GVALUA ((GKS_INT)3)
#define GCHOIC ((GKS_INT)4)
#define GPICK ((GKS_INT)5)
#define GSTRIN ((GKS_INT)6)

/* request status                                                                   */
#define GOK ((GKS_INT)1)
#define GNONE ((GKS_INT)0)

/* echo switch                                                                      */
#define GECHO ((GKS_INT)1)
#define GNECHO ((GKS_INT)0)

/* toggle switch                                                                    */
#define GPROFF ((GKS_INT)0)
#define GPRON ((GKS_INT)1)

/** Choice *                                                                        */

/* choice status                                                                    */
#define GCOK ((GKS_INT)1)
#define GNCHOI ((GKS_INT)2)
#define GCNONE ((GKS_INT)0)

/** Pick *                                                                          */

#define Gpstat unsigned /* pick status */
#define GPOK ((GKS_INT)1)
#define GNPICK ((GKS_INT)2)
#define GPNONE ((GKS_INT)0)

/**********     ANSI Device Information     ********                                */

/* clipping indicator                                                               */
#define GCLIP ((GKS_INT)1)
#define GNCLIP ((GKS_INT)0)

/* clear control flag                                                               */
#define GCONDI ((GKS_INT)0)
#define GALWAY ((GKS_INT)1)

/* device coordinate units                                                          */
#define GMETRE ((GKS_INT)0)
#define GOTHU ((GKS_INT)1)

/* GKS operating state                                                              */
#define GGKCL ((GKS_INT)0)      /* GKS closed */
#define GGKOP ((GKS_INT)1)      /* GKS open */
#define GWSOP ((GKS_INT)2)      /* workstation open */
#define GWSAC ((GKS_INT)3)      /* workstation active */
#define GSGOP ((GKS_INT)4)      /* segment open */

/* viewport input priority                                                          */
#define GHIGHR ((GKS_INT)0)
#define GLOWER ((GKS_INT)1)

/* Polyline Linetypes                                                               */

#define GLSOLI  ((GKS_INT)1) /* solid */
#define GLDASH  ((GKS_INT)2) /* dashed */
#define GLDOT   ((GKS_INT)3) /* dotted */
#define GLDASD  ((GKS_INT)4)/* dotdashed */

/*** Polymarker type constants **                                                   */
#define GPOINT  ((GKS_INT)1)    /* Polymarker dot                           */
#define GPLUS   ((GKS_INT)2)    /* Polymarker plus sign                     */
#define GAST    ((GKS_INT)3)    /* Polymarker asterisk                      */
#define GOMARK  ((GKS_INT)4)    /* Polymarker circle                        */
#define GXMARK  ((GKS_INT)5)    /* Polymarker X                 */

/*******    Stroke Font Character Set and Font Numbers  ***********                 */
/**************  These come from gks/gkstxconst.h  ****************                 */

/* Error Status Returned From GKS                                                   */
#define GKS_NONE        GNONE
#define GKS_OK          GOK
#define GKS_NOPICK      GNPICK
#define GKS_NOCHOICE    GNCHOI

/* Fill Area Styles                                                                 */
#define HOLLOW                  GHOLLO
#define SOLID                   GSOLID
#define PATTERN                 GPATTR
#define HATCH                   GHATCH

/* Polymarker types                                                                 */
#define GKS_MARKER_DOT          GPOINT
#define GKS_MARKER_PLUS_SIGN    GPLUS
#define GKS_MARKER_ASTERISK     GAST
#define GKS_MARKER_CIRCLE       GOMARK
#define GKS_MARKER_X            GXMARK

/* Character Precision                                                              */
#define STRING_PRECISION    GSTRP
#define CHAR_PRECISION      GCHARP
#define STROKE_PRECISION    GSTRKP

/* Priorities                                                                       */
#define HIGHER          GHIGHR
#define LOWER           GLOWER

/* Prompt echo types.                                                               */
#define UGRQ_TYPE_BAND_VECTOR       ((GKS_INT)-4)
#define UGRQ_TYPE_BAND_RECTANGLE    ((GKS_INT)-5)
#define UGRQ_TYPE_DRAG_SEGMENT      ((GKS_INT)-7)

/* Tablet types.  Have been put in the file tg_set_tablet_type.c                    */
/*                and the table CODES.GRAPHICS_TABLET_TYPES                         */

/* Character Fonts                                                                  */
#define SIMPLEX         ((GKS_INT)10)
#define DUPLEX          ((GKS_INT)11)
#define TRIPLEX         ((GKS_INT)12)
#define SCRIPT          ((GKS_INT)13)
#define GOTHIC          ((GKS_INT)14)

#endif
#endif
