/* DEC/CMS REPLACEMENT HISTORY, Element SUN_ANSILONG.H*/
/* *2     3-MAY-1991 16:22:27 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *1    30-JUN-1989 15:06:50 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element SUN_ANSILONG.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/sun_ansilong.h,v 1.1 89/05/30 15:35:48 esi Exp $ sun_ansilong.h 
 */

/*	Copyright 1986 - PRIOR Data Sciences - GKS/C	*/
/*							*/
/*		Graphic Kernel System (GKS) in C	*/
/*		================================	*/
   
/*----------------------------------------------------------------------
|   
|-  File: ansilong.h    Revision: 11.1    (88/09/16)
|
|-  Contents:	Define long names for ANSI C binding
|	This file is always included by the application which
|	invokes GKS through the ANSI C wrapper.  It allows both
|	long and short names to be used for function calls.
|
|	Note: The 1985 ANSI C binding defines gppmr to be the short
|	name for ginqpremarkrep.  This is inconsistent with the 
|	Fortran binding so it has been changed to gqppmr.
|   
|-  Written:
|	1985 Jul 25	Michael Hoffman - PRIOR Data Sciences
|
|-  Modifications:
|
|	1987 May 7	Kevin Cornell - PRIOR Data Sciences
|	    Changed the define for ginqtextcolour from gqtxcin
|	    to gqtxci.
|	
|	1987 May 14	Gayle Younger - PRIOR Data Sciences
|	    Changed the define for ginqmodseg from gdpsga to gqdsga.
|
|	1987 Jul 28	Kevin Cornell - PRIOR Data Sciences
|	    Added the mapping "ginqdisplaysize" to "gqmds" as
|	    a result of bug # 494.
|
|	1987 Jul 30	Michael F. Sargent - PRIOR Data Sciences Ltd.
|	    Added definitions for the new functions set and inquire
|	    dynamic segments.
|
|	1987 Aug 4	Jennifer Black	- PRIOR Data Sciences
|	    - changed ansi long names ginqmarkfac and ginqpremarkrep to
|	      ginqmarkerfac and ginqpremarkerrep respectively. These
|	      bugs were reported by Sun (Dean Stanton) on Jul 14, 1987.
|
|	1987 Sep 10	Kevin Cornell - PRIOR Data Sciences
|	    Added the new function gdrwsg.
|
|	1988 Jan 8	Ken Rode - PRIOR Data Sciences
|	    This file has been examined for completeness and correctness,
|	    and the discrepancies have been repaired. (B-573)
|
-----------------------------------------------------------------------*/

/* For the following functions, the long ANSI name is the */
/* same as the short ANSI name:				  */
/*		ggdp					  */
/*		garcgdp					  */
/*							  */
/* Also, ginqsegpri was gqsgp but conflicted with ginqnumsegpri */

#ifndef SUN_ANSILONG_H
#define SUN_ANSILONG_H 1

#define gaccumtran		gactm
#define gactivateseg		gacsg
#define gactivatews		gacwk
#define gassocsegws		gasgwk
#define gawaitevent		gwait
#define gcellarray		gca
#define gcirclegdp		gcirgdp
#define gclearws		gclrwk
#define gclosegks		gclks
#define gcloseseg		gclsg
#define gclosews		gclwk
#define gcopysegws		gcsgwk
#define gcreateseg		gcrsg
#define gdeactivateseg		gdacsg
#define gdeactivatews		gdacwk
#define gdeleteseg		gdsg
#define gdeletesegws		gdsgwk
#define gdraw1seg		gdrwsg
#define gemergencyclosegks	geclks
#define gerrorhand		gerhnd
#define gerrorlog		gerlog
#define gescape			gesc
#define gevaltran		gevtm
#define gfillarea		gfa
#define gflushevents		gflush
#define ggetchoice		ggtch
#define ggetgksm		ggtitm
#define ggetloc			ggtlc
#define ggetpick		ggtpk
#define ggetstring		ggtst
#define ggetstroke		ggtsk
#define ggetval			ggtvl
#define ginitchoice		ginch
#define ginitloc		ginlc
#define ginitpick		ginpk
#define ginitstring		ginst
#define ginitstroke		ginsk
#define ginitval		ginvl
#define ginqactivews		gqacwk
#define ginqasf			gqasf
#define ginqassocws		gqaswk
#define ginqavailgdp		gqlgdp
#define ginqavailwstypes	gqavwk
#define ginqcharbase		gqchb
#define ginqcharexp		gqchxp
#define ginqcharheight		gqchh
#define ginqcharspace		gqchsp
#define ginqcharup		gqchup
#define ginqcharwidth		gqchw
#define ginqchoicestate		gqchs
#define ginqclip		gqclip
#define ginqcolourfac		gqcf
#define ginqcolourindices	gqlci
#define ginqcolourrep		gqcr
#define ginqcurdisplaysize	gqcds
#define ginqcurnormtrannum	gqcntn
#define ginqdefchoice		gqdch
#define ginqdefdeferral		gqdds
#define ginqdefloc		gqdlc
#define ginqdefpick		gqdpk
#define ginqdefstring		gqdst
#define ginqdefstroke		gqdsk
#define ginqdefval		gqdvl
#define ginqdet			gqdet
#define ginqdisplaysize		gqmds
#define ginqdynamicseg		gqdyns
#define ginqfillcolour		gqfaci
#define ginqfillfac		gqfaf
#define ginqfillindex		gqfai
#define ginqfillindices		gqlfai
#define ginqfillintstyle	gqfais
#define ginqfillrep		gqfar
#define ginqfillstyleindex	gqfasi
#define ginqgdp			gqgdp
#define ginqhighlight		gqhlit
#define ginqinputoverflow	gqiqov
#define ginqlevelgks		gqlvks
#define ginqlinecolour		gqplci
#define ginqlinefac		gqplf
#define ginqlineindex		gqpli
#define ginqlineindices		gqlpli
#define ginqlinerep		gqplr
#define ginqlinetype		gqln
#define ginqlinewidth		gqlwsc
#define ginqlocstate		gqlcs
#define ginqmarkercolour	gqpmci
#define ginqmarkerfac		gqpmf
#define ginqmarkerindex		gqpmi
#define ginqmarkerindices	gqlpmi
#define ginqmarkerrep		gqpmr
#define ginqmarkersize		gqmksc
#define ginqmarkertype		gqmk
#define ginqmaxdisplaysize	gqmds
#define ginqmaxnormtrannum	gqmntn
#define ginqmaxwstables		gqlwk
#define ginqmodseg		gqdsga
#define ginqmodws		gqdwka
#define ginqmoreevents		gqsim
#define ginqnameopenseg		gqopsg
#define ginqnormtrannum		gqlntn
#define ginqnumavailinput	gqli
#define ginqnumsegpri		gqsgp	
#define ginqopenws		gqopwk
#define ginqopstate		gqops
#define ginqpatfac		gqpaf
#define ginqpatheight		gqpah
#define ginqpatindices		gqlpai
#define ginqpatrefpoint		gparf
#define ginqpatrep		gqpar
#define ginqpatwidth		gqpaw
#define ginqpickid		gqpkid
#define ginqpickstate		gqpks
#define ginqpixel		gqpx
#define ginqpixelarray		gqpxa
#define ginqpixelarraydim	gqpxad
#define ginqprecolourrep	gqpcr
#define ginqprefillrep		gqpfar
#define ginqprelinerep		gqpplr
#define ginqpremarkerrep	gqppmr
#define ginqprepatrep		gqppar
#define ginqpretextrep		gqptxr
#define ginqsegnames		gqsgus
#define ginqsegnamesws		gqsgwk
#define ginqsegpri		gqsgpr 
#define ginqsegtran		gqsgt
#define ginqstringstate		gqsts
#define ginqstrokestate		gqsks
#define ginqtextalign		gqtxal
#define ginqtextcharsetfac	gqtxcf
#define ginqtextcharsets	gqtxcs
#define ginqtextcolour		gqtxci
#define ginqtextextent		gqtxx
#define ginqtextfac		gqtxf
#define ginqtextfontprec	gqtxfp
#define ginqtextindex		gqtxi
#define ginqtextindices		gqltxi
#define ginqtextpath		gqtxp
#define ginqtextrep		gqtxr
#define ginqvalstate		gqvls
#define ginqviewport		gqvp
#define ginqvis			gqvis
#define ginqwindow		gqwn
#define ginqwscategory		gqwkca
#define ginqwsclass		gqwkcl
#define ginqwsconntype		gqwkc
#define ginqwsdeferralupdate	gqwkdu
#define ginqwsmaxnum		gqwkm
#define ginqwsstate		gqwks
#define ginqwstran		gqwkt
#define ginsertseg		ginsg
#define ginterpret		giitm
#define gmessage		gmsg
#define gopengks		gopks
#define gopenws			gopwk
#define gpolyline		gpl
#define gpolymarker		gpm
#define greadgksm		grditm
#define grectanglegdp		grecgdp
#define gredrawsegws		grsgwk
#define grenameseg		grensg
#define greqchoice		grqch
#define greqloc			grqlc
#define greqpick		grqpk
#define greqstring		grqst
#define greqstroke		grqsk
#define greqval			grqvl
#define gsamplechoice		gsmch
#define gsampleloc		gsmlc
#define gsamplepick		gsmpk
#define gsamplestring		gsmst
#define gsamplestroke		gsmsk
#define gsampleval		gsmvl
#define gselnormtran		gselnt
#define gsetasf			gsasf
#define gsetcharexp		gschxp
#define gsetcharheight		gschh
#define gsetcharspace		gschsp
#define gsetcharup		gschup
#define gsetchoicemode		gschm
#define gsetclip		gsclip
#define gsetcolourrep		gscr
#define gsetdeferral		gsds
#define gsetdet			gsdtec
#define gsetdynamicseg		gsdyns
#define gsetfillcolour		gsfaci
#define gsetfillindex		gsfai
#define gsetfillintstyle	gsfais
#define gsetfillrep		gsfar
#define gsetfillstyleindex	gsfasi
#define gsethighlight		gshlit
#define gsetlinecolour		gsplci
#define gsetlineindex		gspli
#define gsetlinerep		gsplr
#define gsetlinetype		gsln
#define gsetlinewidth		gslwsc
#define gsetlocmode		gslcm
#define gsetmarkercolour	gspmci
#define gsetmarkerindex		gspmi
#define gsetmarkerrep		gspmr
#define gsetmarkersize		gsmksc
#define gsetmarkertype		gsmk
#define gsetpatrefpoint		gsparf
#define gsetpatrep		gspar
#define gsetpatsize		gspa
#define gsetpickid		gspkid
#define gsetpickmode		gspkm
#define gsetsegpri		gssgp
#define gsetsegtran		gssgt
#define gsetstringmode		gsstm
#define gsetstrokemode		gsskm
#define gsettextalign		gstxal
#define gsettextcharesets	gstxcs
#define gsettextcolour		gstxci
#define gsettextfontprec	gstxfp
#define gsettextindex		gstxi
#define gsettextpath		gstxp
#define gsettextrep		gstxr
#define gsetvalmode		gsvlm
#define gsetviewport		gsvp
#define gsetviewportpri		gsvpip
#define gsetvis			gsvis
#define gsetwindow		gswn
#define gsetwsviewport		gwkvp
#define gsetwswindow		gswkwn
#define gtext			gtx
#define gupdatews		gugk
#define gwritegksm		gwitm

#endif
