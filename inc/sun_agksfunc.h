/* DEC/CMS REPLACEMENT HISTORY, Element SUN_AGKSFUNC.H*/
/* *2     3-MAY-1991 16:22:10 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *1    30-JUN-1989 15:06:41 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SUN_AGKSFUNC.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/sun_agksfunc.h,v 1.1 89/05/30 15:35:46 esi Exp $ sun_agksfunc.h 
 */

/*	Copyright 1987 - PRIOR Data Sciences - GKS/C	*/
/*							*/
/*		GKS in C (ANSI Binding)			*/
/*		=======================			*/
   
/*----------------------------------------------------------------------
|
|-  File: agksfunc.h    Revision: 11.1    (88/09/16)
|
|-  Contents:
|	This include file defines all the ANSI binding functions.
|
|-  Written:
|	1985 Jul 16	Michael Hoffman - PRIOR Data Sciences Limited
|
|_  Modifications:
|
|	1988 Jan 8	Ken Rode - PRIOR Data Sciences
|	    This file has been examined for completeness and correctness,
|	    and the discrepancies have been repaired. (B-573)
|
-----------------------------------------------------------------------*/

#ifndef SUN_AGKSFUNC_H
#define SUN_AGKSFUNC_H 1

/* GDP Functions Available	*/
Ggdpi		gcirgdp();		/* gcirclegdp 			*/
Ggdpi		garcgdp();		/* garcgdp			*/
Ggdpi		grecgdp();		/* grectanglegdp		*/
Ggdpi		gfcirgdp();		/* gfilledcirclegdp 		*/
Ggdpi		gfarcgdp();		/* gfilledarcgdp		*/
Ggdpi		gfrecgdp();		/* gfilledrectanglegdp		*/


/* Request Input Functions	*/
Gqloc		grqlc();		/* greqloc			*/
Gqstroke	grqsk();		/* greqstroke			*/
Gqval		grqvl();		/* greqval			*/
Gqchoice	grqch();		/* greqchoice			*/
Gqpick		grqpk();		/* greqpick			*/
Gqstring	grqst();		/* greqstring			*/

/* Sample Input Functions	*/
Gloc		gsmlc();		/* gsampleloc			*/
Gstroke		gsmsk();		/* gsamplestroke		*/
Gfloat		gsmvl();		/* gsampleval			*/
Gint		gsmch();		/* gsamplechoice		*/
Gpick		gsmpk();		/* gsamplepick			*/
Gchar	       *gsmst();		/* gsamplestring		*/

/* Event Input Functions	*/
Gevent		gwait();		/* gawaitevent			*/
Gloc		ggtlc();		/* ggetloc			*/
Gstroke		ggtsk();		/* ggetstroke			*/
Gfloat		ggtvl();		/* ggetval			*/
Gint		ggtch();		/* ggetchoice			*/
Gpick		ggtpk();		/* ggetpick			*/
Gchar	       *ggtst();		/* ggetstring			*/

/* Metafile Functions	*/
Ggksmit		ggtitm();		/* ggetgksm			*/
Gchar	       *grditm();		/* greadgksm			*/

/* Inquiry Functions for Operating State	*/
Gos		gqops();		/* ginqopstate			*/
Gdynstate	gqdyns();		/* ginqdynamicseg		*/

/* Inquiry Functions for GKS Description Table	*/
Gchar	       *gqlvks();		/* ginqlevelgks			*/
Gchar	      **gqavwk();		/* ginqavailwstypes		*/
Gwsmax		gqwkm();		/* ginqwsmaxnum			*/
Gint		gqmntn();		/* ginqmaxnormtrannum		*/

/* Inquiry Functions for GKS State List	*/
Gws	       *gqopwk();		/* ginqopenws			*/
Gws	       *gqacwk();		/* ginqactivews			*/
Gindex		gqpli();		/* ginqlineindex		*/
Gindex		gqpmi();		/* ginqmarkerindex		*/
Gindex		gqtxi();		/* ginqtextindex		*/
Gchrht		gqchh();		/* ginqcharheight		*/
Gchrwid		gqchw();		/* ginqcharwidth		*/
Gwpoint		gqchup();		/* ginqcharup			*/
Gwpoint		gqchb();		/* ginqcharbase			*/
Gtxpath		gqtxp();		/* ginqtextpath			*/
Gtxalign	gqtxal();		/* ginqtextalign		*/
Gindex		gqfai();		/* ginqfillindex		*/
Gwpoint		gqpaw();		/* ginqpatwidth			*/
Gwpoint		gqpah();		/* ginqpatheight		*/
Gwpoint		gparf();		/* ginqpatrefpoint		*/
Gescout		gesc();			/* gescape			*/
Gpickid		gqpkid();		/* ginqpickid			*/
Glntype		gqln();			/* ginqlinetype			*/
Gscale		gqlwsc();		/* ginqlinewidth		*/
Gcolour		gqplci();		/* ginqlinecolour		*/
Gmktype		gqmk();			/* ginqmarkertype		*/
Gscale		gqmksc();		/* ginqmarkersize		*/
Gcolour		gqpmci();		/* ginqmarkercolour		*/
Gtxfp		gqtxfp();		/* ginqtextfontprec 		*/
Gchrexp		gqchxp();		/* ginqcharexp			*/
Gchrsp		gqchsp();		/* ginqcharspace		*/
Gcolour		gqtxci();		/* ginqtextcolour		*/
Gflinter	gqfais();		/* ginqfillintstyle		*/
Gflstyle	gqfasi();		/* ginqfillstyleindex		*/
Gcolour		gqfaci();		/* ginqfillcolour		*/
Gasfs		gqasf();		/* ginqasf			*/
Gint		gqcntn();		/* ginqcurnormtrannum		*/
Gint	       *gqlntn();		/* ginqnormtrannum 		*/
Gwlimit		gqwn();			/* ginqwindow			*/
Gnlimit		gqvp();			/* ginqviewport			*/
Gcliprec	gqclip();		/* ginqclip			*/
Gseg		gqopsg();		/* ginqnameopenseg		*/
Gseg	       *gqsgus();		/* ginqsegnames			*/
Gsimultev	gqsim();		/* ginqmoreevents		*/

/* Inquiry Functions for Workstation State List	*/
Gwsct		gqwkc();		/* ginqwsconntype		*/
Gwsstate	gqwks();		/* ginqwsstate			*/
Gwsdus		gqwkdu();		/* ginqwsdeferralupdate		*/
Gbii		gqlpli();		/* ginqlineindices		*/
Glnbundl	gqplr();		/* ginqlinerep			*/
Gbii		gqlpmi();		/* ginqmarkerindices		*/
Gmkbundl	gqpmr();		/* ginqmarkerrep		*/
Gbii		gqltxi();		/* ginqtextindices		*/
Gtxbundl	gqtxr();		/* ginqtextrep			*/
Gextent		gqtxx();		/* ginqtextextent		*/
Gbii		gqlfai();		/* ginqfillindices		*/
Gflbundl	gqfar();		/* ginqfillrep			*/
Gbii		gqlpai();		/* ginqpatindices		*/
Gptbundl	gqpar();		/* ginqpatrep			*/
Gbii		gqlci();		/* ginqcolourindices		*/
Gcobundl	gqcr();			/* ginqcolourrep		*/
Gwsti		gqwkt();		/* ginqwstran			*/
Gseg	       *gqsgwk();		/* ginqsegnamesws		*/
Glocst		gqlcs();		/* ginqlocstate			*/
Gstrokest	gqsks();		/* ginqstrokestate		*/
Gvalst		gqvls();		/* ginqvalstate			*/
Gchoicest	gqchs();		/* ginqchoicestate		*/
Gpickst		gqpks();		/* ginqpickstate		*/
Gstringst	gqsts();		/* ginqstringstate		*/
Gdspsize	gqcds();		/* ginqcurdisplaysize		*/

/* Inquiry Functions for Workstation Description Table	*/
Gdspsize	gqmds();	 	/* ginqdisplaysize,		*/
					/* ginqmaxdisplaysize		*/
Gwscat		gqwkca();		/* ginqwscategory		*/
Gwsclass	gqwkcl();		/* ginqwsclass			*/
Gmodws		gqdwka();		/* ginqmodws			*/
Gdefer		gqdds();		/* ginqdefdeferral		*/
Gptfac		gqpaf();		/* ginqpatfac			*/
Glnfac		gqplf();		/* ginqlinefac			*/
Gptbundl	gqppar();		/* ginqprepatrep		*/
Glnbundl	gqpplr();		/* ginqprelinerep		*/
Gmkfac		gqpmf();		/* ginqmarkerfac		*/
Gmkbundl	gqppmr();		/* ginqpremarkerrep		*/
Gtxfac		gqtxf();		/* ginqtextfac			*/
Gtxbundl	gqptxr();		/* ginqpretextrep		*/
Gflfac		gqfaf();		/* ginqfillfac			*/
Gflbundl	gqpfar();		/* ginqprefillrep		*/
Gcofac		gqcf();			/* ginqcolourfac		*/
Gcobundl	gqpcr();		/* ginqprecolourrep		*/
Gwstables	gqlwk();		/* ginqmaxwstables		*/
Gint		gqsgp();		/* ginqnumsegpri		*/
Gmodseg		gqdsga();		/* ginqmodseg			*/
Gnumdev		gqli();			/* ginqnumavailinput		*/
Gdefloc		gqdlc();		/* ginqdefloc			*/
Gdefstroke	gqdsk();		/* ginqdefstroke		*/
Gdefval		gqdvl();		/* ginqdefval			*/
Gdefchoice	gqdch();		/* ginqdefchoice		*/
Gdefpick	gqdpk();		/* ginqdefpick			*/
Gdefstring	gqdst();		/* ginqdefstring		*/
Ggdpfac		gqgdp();		/* ginqgdp			*/
Gint         (**gdlgdp())();		/* ginqavailgdp			*/

/* Inquiry Functions of Associated Workstations	*/
Gws	       *gqaswk();		/* ginqassocws			*/
Gsegtran	gqsgt();		/* ginqsegtran			*/
Gsegvis		gqvis();		/* ginqvis			*/
Gseghi		gqhlit();		/* ginqhighlight		*/
Gsegpri		gqsgpr();		/* ginqsegpri			*/
Gsegdet		gqdet();		/* ginqdet			*/

/* Pixel Inquiries	*/
Gipoint		gqpxad();		/* ginqpixelarraydim		*/
Gpxarray	gqpxa();		/* ginqpixelarray		*/
Gcolour		gqpx();			/* ginqpixel			*/

/* Inquiry Functions for 2C input	*/
Gqinfo		gqiqov();		/* ginqinputoverflow		*/

/* Utility Functions	*/
Gsegtran	gevtm();		/* gevaltran			*/
Gsegtran	gactm();		/* gaccumtran			*/


#ifdef ALL_DEFINITIONS

/* The following function declarations are all for integer valued    */
/* functions and as such are not absolutely required by a C compiler */
/* since functions are by default integer-valued. The definitions    */
/* are listed here for completeness.				     */
Gint		gacwk();		/* gactivatews			*/
Gint		gasgwk();		/* gassocsegws			*/
Gint		gca();			/* gcellarray			*/
Gint		gclrwk();		/* gclearws			*/
Gint		gclks();		/* gclosegks			*/
Gint		gclsg();		/* gcloseseg			*/
Gint		gclwk();		/* gclosews			*/
Gint		gcsgwk();		/* gcopysegws			*/
Gint		gcrsg();		/* gcreateseg			*/
Gint		gdacwk();		/* gdeactivatews		*/
Gint		gdsgwk();		/* gdeletesegws			*/
Gint		gdsg();			/* gdeleteseg			*/
Gint		geclks();		/* gemergencyclosegks		*/
Gint		gerhnd();		/* gerrorhand			*/
Gint		gerlog();		/* gerrorlog			*/
Gint		gfa();			/* gfillarea			*/
Gint		gflush();		/* gflushevents			*/
Gint		ggdp();			/* ggdp				*/
Gint		ginch();		/* ginitchoice			*/
Gint		ginlc();		/* ginitloc			*/
Gint		ginpk();		/* ginitpick			*/
Gint		ginst();		/* ginitstring			*/
Gint		ginsk();		/* ginitstroke			*/
Gint		ginvl();		/* ginitval			*/
Gint		ginsg();		/* ginsertseg			*/
Gint		giitm();		/* ginterpret			*/
Gint		gmsg();			/* gmessage			*/
Gint		gopks();		/* gopengks			*/
Gint		gopwk();		/* gopenws			*/
Gint		gpl();			/* gpolyline			*/
Gint		gpm();			/* gpolymarker			*/
Gint		grsgwk();		/* gredrawsegws			*/
Gint		grensg();		/* grenameseg			*/
Gint		gselnt();		/* gselnormtran			*/
Gint		gsasf();		/* gsetasf			*/
Gint		gschxp();		/* gsetcharexp			*/
Gint		gschh();		/* gsetcharheight		*/
Gint		gschsp();		/* gsetcharspace		*/
Gint		gschup();		/* gsetcharup			*/
Gint		gschm();		/* gsetchoicemode		*/
Gint		gsclip();		/* gsetclip			*/
Gint		gscr();			/* gsetcolourrep		*/
Gint		gsds();			/* gsetdeferral			*/
Gint		gsdtec();		/* gsetdet			*/
Gint		gsfaci();		/* gsetfillcolour		*/
Gint		gsfai();		/* gsetfillindex		*/
Gint		gsfais();		/* gsetfillintstyle		*/
Gint		gsfar();		/* gsetfillrep			*/
Gint		gsfasi();		/* gsetfillstyleindex		*/
Gint		gshlit();		/* gsethighlight		*/
Gint		gsln();			/* gsetlinetype			*/
Gint		gslwsc();		/* gsetlinewidth		*/
Gint		gslcm();		/* gsetlocmode			*/
Gint		gsmksc();		/* gsetmarkersize		*/
Gint		gsmk();			/* gsetmarkertype		*/
Gint		gspa();			/* gsetpatsize			*/
Gint		gspar();		/* gsetpatrep			*/
Gint		gsparf();		/* gsetpatrefpoint		*/
Gint		gspkid();		/* gsetpickid			*/
Gint		gspkm();		/* gsetpickmode			*/
Gint		gsplci();		/* gsetlinecolour		*/
Gint		gspli();		/* gsetlineindex		*/
Gint		gsplr();		/* gsetlinerep			*/
Gint		gspmci();		/* gsetmarkercolour		*/
Gint		gspmi();		/* gsetmarkerindex		*/
Gint		gspmr();		/* gsetmarkerrep		*/
Gint		gssgp();		/* gsetsegpri			*/
Gint		gssgt();		/* gsetsegtran			*/
Gint		gsstm();		/* gsetstringmode		*/
Gint		gsskm();		/* gsetstrokemode		*/
Gint		gstxal();		/* gsettextalign		*/
Gint		gstxci();		/* gsettextcolour		*/
Gint		gstxfp();		/* gsettextfontprec		*/
Gint		gstxi();		/* gsettextindex		*/
Gint		gstxp();		/* gsettextpath			*/
Gint		gstxr();		/* gsettextrep			*/
Gint		gsvlm();		/* gsetvalmode			*/
Gint		gsvpip();		/* gsetviewportpri		*/
Gint		gsvp();			/* gsetviewport			*/
Gint		gsvis();		/* gsetvis			*/
Gint		gswn();			/* gsetwindow			*/
Gint		gwkvp();		/* gsetwsviewport		*/
Gint		gswkwn();		/* gsetwswindow			*/
Gint		gtx();			/* gtext			*/
Gint		gugk();			/* gupdatews			*/
Gint		gwitm();		/* gwritegksm			*/

#endif
#endif
