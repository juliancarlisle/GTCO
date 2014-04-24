C DEC/CMS REPLACEMENT HISTORY, Element SUN_GKS77.I
C *2    19-SEP-1989 12:40:21 PURNA "(SPR 100) gulf new file"
C *1    19-SEP-1989 12:36:50 PURNA "new file to support gulf"
C DEC/CMS REPLACEMENT HISTORY, Element SUN_GKS77.I
C     
C     $Header: /xd3g/finder/include/RCS/sun_gks77.i,v 2.0.1.1 89/08/16 07:54:20 esi Exp Locker: esi $ sun_gks77.i 
C     
C
C **************************************************************************
C ***         FORTRAN 77 Enumeration Types - FORTRAN include file
C ***
C *** Copyright 1986 - PRIOR Data Sciences - GKS/C Release 2.3 
C ***
C *** PROJECT:  FORTRAN GKS WRAPPER
C *** 
C *** AUTHOR:   I.G.GRAHAM         CREATIONDATE: DEC 21/86
C ***
C *** MODIFICATIONS:
C ***
C ***	1987 Feb  9	Michael F. Sargent - PRIOR Data Sciences Ltd.
C ***	    - corrected MO and MI to have leading G
C ***
C ***   1988 Feb 15	Ken Rode - PRIOR Data Sciences
C ***       The escape data record has changed slightly to correct the
C ***       mechanism whereby the escape function can be routed to all
C ***       open or active workstations, instead of to a specific
C ***       workstation. (B-581)
C ***
C **************************************************************************
C
C  Aspect source flag (bundled, individual)
      INTEGER    GBUNDL,   GINDIV
      PARAMETER (GBUNDL=0, GINDIV=1)

C  Clear control flag (conditionally, always)
      INTEGER    GCONDI,   GALWAY
      PARAMETER (GCONDI=0, GALWAY=1)

C  Clipping indicator (noclip, clip)
      INTEGER    GNCLIP,   GCLIP
      PARAMETER (GNCLIP=0, GCLIP=1)

C  Colour available (monochrome, colour)
      INTEGER    GMONOC,   GCOLOR
      PARAMETER (GMONOC=0, GCOLOR=1)

C  Coordinate switch (WC, NDC)
      INTEGER    GWC,      GNDC
      PARAMETER (GWC=0,    GNDC=1)

C  Deferral mode (ASAP, BNIG, BNIL, ASTI)
      INTEGER    GASAP,    GBNIG,    GBNIL,    GASTI
      PARAMETER (GASAP=0,  GBNIG=1,  GBNIL=2,  GASTI=3)

C  Detectability (undetectable, detectable)
      INTEGER    GUNDET,   GDETEC
      PARAMETER (GUNDET=0, GDETEC=1)

C  Device coordinate units (metres, other)
      INTEGER    GMETRE,   GOTHU
      PARAMETER (GMETRE=0, GOTHU=1)

C  Display surface empty (notempty, empty)
      INTEGER    GNEMPT,   GEMPTY
      PARAMETER (GNEMPT=0, GEMPTY=1)

C  Dynamic modification (IRG, IMM)
      INTEGER    GIRG,     GIMM
      PARAMETER (GIRG=0,   GIMM=1)

C  Echo switch (noecho, echo)
      INTEGER    GNECHO,   GECHO
      PARAMETER (GNECHO=0, GECHO=1)

C  Fill area interior style (hollow, solid, pattern, hatch)
      INTEGER    GHOLLO,   GSOLID,   GPATTR,   GHATCH
      PARAMETER (GHOLLO=0, GSOLID=1, GPATTR=2, GHATCH=3)

C  Highlighting (normal, highlighted)
      INTEGER    GNORML,   GHILIT
      PARAMETER (GNORML=0, GHILIT=1)

C  Input device status (none, ok, nopick, nochoice)
C  NOTE:  GNPICK (no pick) & GNCHOI (no choice) are both = 2
      INTEGER    GNONE,    GOK,      GNPICK,   GNCHOI
      PARAMETER (GNONE=0,  GOK=1,    GNPICK=2, GNCHOI=2)

C  Input class (locator, stroke, valuator, choice, pick, string)
      INTEGER    GNCLAS,   GLOCAT,   GSTROK,   GVALUA,   GCHOIC,
     +           GPICK,    GSTRIN
      PARAMETER (GNCLAS=0, GLOCAT=1, GSTROK=2, GVALUA=3, GCHOIC=4,
     +           GPICK=5,  GSTRIN=6)

C  Implicit regeneration mode (suppressed, allowed)
      INTEGER    GSUPPD,   GALLOW
      PARAMETER (GSUPPD=0, GALLOW=1)

C  Level of GKS (Lma, Lmb, Lmc, L0a, L0b, L0c, L1a, L1b, L1c,
C                L2a, L2b, L2c)
      INTEGER    GLMA,     GLMB,     GLMC,     GL0A,     GL0B,
     +           GL0C,     GL1A,     GL1B,     GL1C,     GL2A,
     +           GL2B,     GL2C
      PARAMETER (GLMA=-3,  GLMB=-2,  GLMC=-1,  GL0A=0,   GL0B=1,
     +           GL0C=2,   GL1A=3,   GL1B=4,   GL1C=5,   GL2A=6,
     +           GL2B=7,   GL2C=8)

C  New frame action necessary (no, yes)
      INTEGER    GNO,      GYES
      PARAMETER (GNO=0,    GYES=1)

C  Operating mode (request, sample, event)
      INTEGER    GREQU,    GSAMPL,   GEVENT
      PARAMETER (GREQU=0,  GSAMPL=1, GEVENT=2)

C  Operating state value (GKCL, GKOP, WSOP, WSAC, SGOP)
      INTEGER    GGKCL,    GGKOP,    GWSOP,    GWSAC,    GSGOP
      PARAMETER (GGKCL=0,  GGKOP=1,  GWSOP=2,  GWSAC=3,  GSGOP=4)

C  Presence of invalid value (absent, present)
      INTEGER    GABSNT,   GPRSNT
      PARAMETER (GABSNT=0, GPRSNT=1)

C  Regeneration flag (postpone, perform)
      INTEGER    GPOSTP,   GPERFO
      PARAMETER (GPOSTP=0, GPERFO=1)

C  Relative input priority (higher, lower)
      INTEGER    GHIGHR,   GLOWER
      PARAMETER (GHIGHR=0, GLOWER=1)

C  Simultaneous events flag (nomore, more)
      INTEGER    GNMORE,   GMORE
      PARAMETER (GNMORE=0, GMORE=1)

C  Text alignment horizontal (normal, left, center, right)
      INTEGER    GAHNOR,   GALEFT,   GACENT,   GARITE
      PARAMETER (GAHNOR=0, GALEFT=1, GACENT=2, GARITE=3)

C  Text alignment vertical (normal, top, cap, half, base, bottom)
      INTEGER    GAVNOR,   GATOP,    GACAP,    GAHALF,   GABASE,
     +           GABOTT
      PARAMETER (GAVNOR=0, GATOP=1,  GACAP=2,  GAHALF=3, GABASE=4,
     +           GABOTT=5)

C  Text path (right, left, up, down)
      INTEGER    GRIGHT,   GLEFT,    GUP,      GDOWN
      PARAMETER (GRIGHT=0, GLEFT=1,  GUP=2,    GDOWN=3)

C  Text precision (string, character, stroke)
      INTEGER    GSTRP,    GCHARP,   GSTRKP
      PARAMETER (GSTRP=0,  GCHARP=1, GSTRKP=2)

C  Type of returned values (set, realized)
      INTEGER    GSET,     GREALI
      PARAMETER (GSET=0,   GREALI=1)

C  Update state (notpending, pending)
      INTEGER    GNPEND,   GPEND
      PARAMETER (GNPEND=0, GPEND=1)

C  Display type (vector, raster, other)
      INTEGER    GVECTR,   GRASTR,   GOTHWK
      PARAMETER (GVECTR=0, GRASTR=1, GOTHWK=2)

C  Visibility (invisible, visible)
      INTEGER    GINVIS,   GVISI
      PARAMETER (GINVIS=0, GVISI=1)

C  Workstation category (OUTPUT, INPUT, OUTIN, WISS, MO, MI)
      INTEGER    GOUTPT,   GINPUT,   GOUTIN,   GWISS,    GMO,
     +           GMI
      PARAMETER (GOUTPT=0, GINPUT=1, GOUTIN=2, GWISS=3,  GMO=4,
     +           GMI=5)

C  Workstation state (inactive, active)
      INTEGER    GINACT,   GACTIV
      PARAMETER (GINACT=0, GACTIV=1)

C  List of GDP attributes (polyline attribute, polymarker attribute,
C                          text attribute, fill area attribute)
      INTEGER    GPLATT,   GPMATT,   GTXATT,   GFAATT
      PARAMETER (GPLATT=0, GPMATT=1, GTXATT=2, GFAATT=3)

C  Line type (solid, dash, dot, dash-dot)
      INTEGER    GLSOLI,   GLDASH,   GLDOT,    GLDASD
      PARAMETER (GLSOLI=1, GLDASH=2, GLDOT=3,  GLDASD=4)

C  Marker type (`.', `+', `*', `o', 'x')
      INTEGER    GPOINT,   GPLUS,    GAST,     GOMARK,   GXMARK
      PARAMETER (GPOINT=1, GPLUS=2,  GAST=3,   GOMARK=4, GXMARK=5)

C  Attribute control flag (current, specified)
      INTEGER    GCURNT,   GSPEC
      PARAMETER (GCURNT=0, GSPEC=1)

C  Polyline/fill area control flag (polyline, fill area)
      INTEGER    GPLINE,   GFILLA
      PARAMETER (GPLINE=0, GFILLA=1)

C  Initial choice prompt flag (off, on)
      INTEGER    GPROFF,   GPRON
      PARAMETER (GPROFF=0, GPRON=1)

C  Dynamic Segment logic states (must match PRIOR binding DynState)
      INTEGER    GDSOPU,    GDSOPE,    GDSOFF,   GDSONE,   GDSONU
      PARAMETER (GDSOPU=-2, GDSOPE=-1, GDSOFF=0, GDSONE=1, GDSONU=2)

C  Escape function routing codes (must match PRIOR binding Es_route)
      INTEGER    GWSPEC,   GWALLO,   GWALLA
      PARAMETER (GWSPEC=0, GWALLO=1, GWALLA=2)

C  The same function identification is used for both full FORTRAN 77
C  and FORTRAN 77 subset.

C  Error handling names.  These are the same as the GKS function names
C  except that the sentinel character `G' is replaced by `E'.
      INTEGER    EOPKS,     ECLKS,     EOPWK,     ECLWK,     EACWK
      PARAMETER (EOPKS=0,   ECLKS=1,   EOPWK=2,   ECLWK=3,   EACWK=4)
      INTEGER    EDAWK,     ECLRWK,    ERSGWK,    EUWK,      ESDS
      PARAMETER (EDAWK=5,   ECLRWK=6,  ERSGWK=7,  EUWK=8,    ESDS=9)
      INTEGER    EMSG,      EESC,      EPL,       EPM,       ETX
      PARAMETER (EMSG=10,   EESC=11,   EPL=12,    EPM=13,    ETX=14)
      INTEGER    EFA,       ECA,       EGDP,      ESPLI,     ESLN
      PARAMETER (EFA=15,    ECA=16,    EGDP=17,   ESPLI=18,  ESLN=19)
      INTEGER    ESLWSC,    ESPLCI,    ESPMI,     ESMK,      ESMKSC
      PARAMETER (ESLWSC=20, ESPLCI=21, ESPMI=22,  ESMK=23,   ESMKSC=24)
      INTEGER    ESPMCI,    ESTXI,     ESTXFP,    ESCHXP,    ESCHSP
      PARAMETER (ESPMCI=25, ESTXI=26,  ESTXFP=27, ESCHXP=28, ESCHSP=29)
      INTEGER    ESTXCI,    ESCHH,     ESCHUP,    ESTXP,     ESTXAL
      PARAMETER (ESTXCI=30, ESCHH=31,  ESCHUP=32, ESTXP=33,  ESTXAL=34)
      INTEGER    ESFAI,     ESFAIS,    ESFASI,    ESFACI,    ESPA
      PARAMETER (ESFAI=35,  ESFAIS=36, ESFASI=37, ESFACI=38, ESPA=39)
      INTEGER    ESPARF,    ESASF,     ESPKID,    ESPLR,     ESPMR
      PARAMETER (ESPARF=40, ESASF=41,  ESPKID=42, ESPLR=43,  ESPMR=44)
      INTEGER    ESTXR,     ESFAR,     ESPAR,     ESCR,      ESWN
      PARAMETER (ESTXR=45,  ESFAR=46,  ESPAR=47,  ESCR=48,   ESWN=49)
      INTEGER    ESVP,      ESVPIP,    ESELNT,    ESCLIP,    ESWKWN
      PARAMETER (ESVP=50,   ESVPIP=51, ESELNT=52, ESCLIP=53, ESWKWN=54)
      INTEGER    ESWKVP,    ECRSG,     ECLSG,     ERENSG,    EDSG
      PARAMETER (ESWKVP=55, ECRSG=56,  ECLSG=57,  ERENSG=58, EDSG=59)
      INTEGER    EDSGWK,    EASGWK,    ECSGWK,    EINSG,     ESSGT
      PARAMETER (EDSGWK=60, EASGWK=61, ECSGWK=62, EINSG=63,  ESSGT=64)
      INTEGER    ESVIS,     ESHLIT,    ESSGP,     ESDTEC,    EINLC
      PARAMETER (ESVIS=65,  ESHLIT=66, ESSGP=67,  ESDTEC=68, EINLC=69)
      INTEGER    EINSK,     EINVL,     EINCH,     EINPK,     EINST
      PARAMETER (EINSK=70,  EINVL=71,  EINCH=72,  EINPK=73,  EINST=74)
      INTEGER    ESLCM,     ESSKM,     ESVLM,     ESCHM,     ESPKM
      PARAMETER (ESLCM=75,  ESSKM=76,  ESVLM=77,  ESCHM=78,  ESPKM=79)
      INTEGER    ESSTM,     ERQLC,     ERQSK,     ERQVL,     ERQCH
      PARAMETER (ESSTM=80,  ERQLC=81,  ERQSK=82,  ERQVL=83,  ERQCH=84)
      INTEGER    ERQPK,     ERQST,     ESMLC,     ESMSK,     ESMVL
      PARAMETER (ERQPK=85,  ERQST=86,  ESMLC=87,  ESMSK=88,  ESMVL=89)
      INTEGER    ESMCH,     ESMPK,     ESMST,     EWAIT,     EFLUSH
      PARAMETER (ESMCH=90,  ESMPK=91,  ESMST=92,  EWAIT=93,  EFLUSH=94)
      INTEGER    EGTLC,     EGTSK,     EGTVL,     EGTCH,     EGTPK
      PARAMETER (EGTLC=95,  EGTSK=96,  EGTVL=97,  EGTCH=98,  EGTPK=99)
      INTEGER    EGTST,     EWITM,     EGTITM,    ERDITM,    EIITM
      PARAMETER (EGTST=100, EWITM=101, EGTITM=102,ERDITM=103,EIITM=104)
      INTEGER    EEVTM,     EACTM,     EPREC,     EUREC
      PARAMETER (EEVTM=105, EACTM=106, EPREC=107, EUREC=108)

C
C  Workstation configuration attribute codes
C
      INTEGER	 GBSTYPE,   GGPUSE,    GMSGSZ,    GNUMCLR
      PARAMETER (GBSTYPE=0, GGPUSE=1,  GMSGSZ=2,  GNUMCLR=3) 
      INTEGER	 GLCMODE,   GDCSZ
      PARAMETER (GLCMODE=4, GDCSZ=5)
      INTEGER    GTEXTSW,   GPANEL,    GRSZPRC
      PARAMETER (GTEXTSW=6, GPANEL=7,  GRSZPRC=8)
      INTEGER	 GDYNSEG,   GTLWDT,    GTLHGT
      PARAMETER (GDYNSEG=9, GTLWDT=10, GTLHGT=11)
      INTEGER	 GTLX,      GTLY,      GTLLBL,    GTLFARG,   GTLICFL
      PARAMETER	(GTLX=12,   GTLY=13,   GTLLBL=14, GTLFARG=15,GTLICFL=16)   
      INTEGER    GTLICLB,   GTLICLR,   GHPMINX,   GHPMINY,   GHPMAXX
      PARAMETER (GTLICLB=17,GTLICLR=18,GHPMINX=19,GHPMINY=20,GHPMAXX=21)   
      INTEGER	 GHPMAXY,   GHPSLFL,   GHPTITL
      PARAMETER	(GHPMAXY=22,GHPSLFL=23,GHPTITL=24)
      INTEGER	 GCGMENC,   GCGMVPR,   GDBLBFF
      PARAMETER (GCGMENC=25,GCGMVPR=26,GDBLBFF=27)
C
C Workstation configuration attribute values
C
      INTEGER    GUSPRF,    GUSREQ,    GUSNON
      PARAMETER (GUSPRF=0,  GUSREQ=1,  GUSNON=2)
      INTEGER    GSTAT,     GDYN
      PARAMETER (GSTAT=0,   GDYN=1)
      INTEGER	 GLCIGN,    GLCSET
      PARAMETER (GLCIGN=0,  GLCSET=1)
      INTEGER    GCLRTXT,   GBINARY,   GCHARAC
      PARAMETER (GCLRTXT=0, GBINARY=1, GCHARAC=2)
      INTEGER    GVDCLOW,   GVDCHIGH
      PARAMETER (GVDCLOW=0, GVDCHIGH=1)
      INTEGER    GNOBUFF,   GSWBUFF,   GHWBUFF
      PARAMETER (GNOBUFF=0, GSWBUFF=1, GHWBUFF=2)
C
C Text fonts
C
      INTEGER   SIMPLX,    DUPLEX,    TRIPLX,    SCRIPT,    GOTHIC
      PARAMETER (SIMPLX=1,DUPLEX=2,TRIPLX=3,SCRIPT=6,GOTHIC=10)

C
C Colours
C
      INTEGER BLACK,RED,GREEN,BLUE,YELLOW,CYAN,MAGNTA,ORANGE
      INTEGER BROWN,VIOLET,OGREEN,GREY,LGREEN,LRED,LBLUE,WHITE
      PARAMETER(BLACK=0,RED=1,GREEN=2,BLUE=3,YELLOW=4,CYAN=5)
      PARAMETER(MAGNTA=6,ORANGE=7,BROWN=8,VIOLET=9,OGREEN=10)
      PARAMETER(GREY=11,LGREEN=12,LRED=13,LBLUE=14,WHITE=15)
