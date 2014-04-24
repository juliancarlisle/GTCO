C  DEC/CMS REPLACEMENT HISTORY, Element LD_UKOOA2.I
C  *5     9-MAY-1991 18:06:07 LOEBL "(SPR 0) changed parameter L_TAB to 10000 for BHP Houston"
C  *4     1-MAR-1990 14:04:45 GILLESPIE "(SPR 1) Rearrange AR_PARAM, DA_PARAM to be at head of common block"
C  *3    19-SEP-1989 11:11:40 PURNA "(SPR 100) gulf mods"
C  *2     1-SEP-1989 14:42:00 CONROY "(SPR 9999) INIT SQL_FIRST VARIBLE"
C  *1    30-JUN-1989 15:17:51 GILLESPIE ""
C  DEC/CMS REPLACEMENT HISTORY, Element LD_UKOOA2.I
***************************************************************
*
*      INCLUDE FILE FOR UKOOA ROUTINES
*
***************************************************************
*
*   L_TAB  length of the array containing lines read in datafile

        INTEGER*4 L_TAB
        PARAMETER ( L_TAB = 10000 )
*
*  NB_CHOIC  number of fields which can be selected in data record

          INTEGER*4 NB_CHOIC
          PARAMETER ( NB_CHOIC = 7 )
*
* LSELECT  size of the buffer where we store the selection of lines

          INTEGER*4 LSELECT
          PARAMETER ( LSELECT = 1600 )
*
C NBWSEL   number of words (4bytes) for description of each
c         selected line

      INTEGER*4 NBWSEL
      PARAMETER ( NBWSEL = 8 )

*  NB_SP    maximum number of sp per line than we can process
*
          INTEGER*4 NB_SP
          PARAMETER ( NB_SP = 3000 )
*
*  L_REC    length in words  of the buffer used to read data records
*
         INTEGER*4 L_REC
         PARAMETER ( L_REC = 200 )

C  NBCARL  number of charactres in line names
C
      INTEGER*4 NBCARL
      PARAMETER ( NBCARL = 20 )
C
c   number of words (4 bytes ) equivalent tonumber of character in
c    line names
C
      INTEGER*4 NBWLI
      PARAMETER ( NBWLI = 5 )
*
C     MAXLNAM   maximum number of characters for a line name stored
c                into oracle 
c                the number of characters is the total of the characters
c                in the  line name + the number of characters  in the survey
c                name
C
       INTEGER*4  MAXLNAM
       PARAMETER ( MAXLNAM = 19 )
C
C     MAXFIELD  is the maximum of field s the operator can
c     temporarily store in buffer  buf ( routine readmag )
c    dimension of buffer buf is NB_SP * MAXFIELD in words (4 bytes)
c
      INTEGER*4 MAXFIELD
      PARAMETER ( MAXFIELD = 6 )
C
C
C------------------- ---------------------------------------------
C
C   PARAMETERS USED IN THE COMPUTATION OF THE ENVELOPE AROUND  A LIGNE
C
C   EPSILON IS A REAL*8 used to test the 'zero' value for real*8
C
       REAL*8 EPSILON
       PARAMETER ( EPSILON = 1.0D-5 )
C
C      D_LONG is the constant that we add at each end of the axis
c      of the rectangle
C
       REAL*8 D_LONG 
       PARAMETER ( D_LONG = 100.)
C
C      D_LARG is the constant that we add  'perpendicularily 'of the axis
c      of the rectangle , this constant is added to the maximum distance 
c      between the points of the line and the main axis 
C
       REAL*8 D_LARG
       PARAMETER ( D_LARG = 100. )
C
C----------------------------------------------------------------------
C
C        PARAMETERS USED IN THE COMPUTATION OF THE LINEARISATION
C
C   XD_SPAC IS A REAL*8 used to test the differ between two consecutive
c   inter cdp spacing
c
       REAL*8 XD_SPAC
       PARAMETER ( XD_SPAC = 50.0)
C
C      XANG_LIM IS the angle ( in radians ) limit for the linearisation
C
	REAL*4 XANG_LIM 
	PARAMETER ( XANG_LIM = 0.045 )
C
C    MIN_TRP is the minimum of sp that we need to have in the linearised
C    
	INTEGER*4 MIN_TRP
	PARAMETER ( MIN_TRP = 10 )
C ___________________________________________________________________
c
c     definition of flags used for correspondance cdp - sp
c     these flags must match with the flags used in c
c     defined in the include file intrp_seism.h
c
C     flag REGUL if correspondance is regular
c
      INTEGER*4 REGUL 
      PARAMETER ( REGUL = 0 )
c
C     flag SEMREGUL if correspondance is semi regular
c
      INTEGER*4 SEMREGUL 
      PARAMETER ( SEMREGUL = 1 )
c
C     flag IRREGUL if correspondance is totally irregular
c
      INTEGER*4 IRREGUL 
      PARAMETER ( IRREGUL = 2 )
c
C________________________________________________________________________
C
C        DEFINITIONS OF CONSTANTS BECAUSE ON THE PRIME ARGUMENTS OF
C      ROUTINES NEEDS TO BE PASSED THROUGH VARIABLES
C
      INTEGER*4 C0, C1,C2,C3,C4,C5,C6,C7,C8,C9
      INTEGER*4 C10, C11,C12,C13,C14,C15,C16,C17,C18,C19
      INTEGER*4 C20, C21,C22,C23,C24,C25,C26,C27,C28,C29
      INTEGER*4 C30, C31,C32,C33,C34,C35,C36,C37,C38,C39
      INTEGER*4 C40, C41,C42,C43,C44,C45,C46,C47,C48,C49
      INTEGER*4 C50,C51,C52,C53,C54,C55,C56,C57,C58,C59
      INTEGER*4 C60,C61,C62,C63,C64,C65,C66,C67,C68,C69
      PARAMETER ( C0 = 0 )
      PARAMETER ( C1 = 1 )
      PARAMETER ( C2 = 2 )
      PARAMETER ( C3 = 3 )
      PARAMETER ( C4 = 4 )
      PARAMETER ( C5 = 5 )
      PARAMETER ( C6 = 6 )
      PARAMETER ( C7 = 7 )
      PARAMETER ( C8 = 8 )
      PARAMETER ( C9 = 9 )
      PARAMETER ( C10 = 10 )
      PARAMETER ( C11 = 11 )
      PARAMETER ( C12 = 12 )
      PARAMETER ( C13 = 13 )
      PARAMETER ( C14 = 14 )
      PARAMETER ( C15 = 15 )
      PARAMETER ( C16 = 16 )
      PARAMETER ( C17 = 17 )
      PARAMETER ( C18 = 18 )
      PARAMETER ( C19 = 19 )
      PARAMETER ( C20 = 20 )
      PARAMETER ( C21 = 21 )
      PARAMETER ( C22 = 22 )
      PARAMETER ( C23 = 23 )
      PARAMETER ( C24 = 24 )
      PARAMETER ( C25 = 25 )
      PARAMETER ( C26 = 26 )
      PARAMETER ( C27 = 27 )
      PARAMETER ( C28 = 28 )
      PARAMETER ( C29 = 29 )
      PARAMETER ( C30 = 30 )
      PARAMETER ( C31 = 31 )
      PARAMETER ( C32 = 32 )
      PARAMETER ( C33 = 33 )
      PARAMETER ( C34 = 34 )
      PARAMETER ( C35 = 35 )
      PARAMETER ( C36 = 36 )
      PARAMETER ( C37 = 37 )
      PARAMETER ( C38 = 38 )
      PARAMETER ( C39 = 39 )
      PARAMETER ( C40 = 40 )
      PARAMETER ( C41 = 41 )
      PARAMETER ( C42 = 42 )
      PARAMETER ( C43 = 43 )
      PARAMETER ( C44 = 44 )
      PARAMETER ( C45 = 45 )
      PARAMETER ( C46 = 46 )
      PARAMETER ( C47 = 47 )
      PARAMETER ( C48 = 48 )
      PARAMETER ( C49 = 49 )
      PARAMETER ( C50 = 50 )
      PARAMETER ( C51 = 51 )
      PARAMETER ( C52 = 52 )
      PARAMETER ( C53 = 53 )
      PARAMETER ( C54 = 54 )
      PARAMETER ( C55 = 55 )
      PARAMETER ( C56 = 56 )
      PARAMETER ( C57 = 57 )
      PARAMETER ( C58 = 58 )
      PARAMETER ( C59 = 59 )
      PARAMETER ( C60 = 60 )
      PARAMETER ( C61 = 61 )
      PARAMETER ( C62 = 62 )
      PARAMETER ( C63 = 63 )
      PARAMETER ( C64 = 64 )
      PARAMETER ( C65 = 65 )
      PARAMETER ( C66 = 66 )
      PARAMETER ( C67 = 67 )
      PARAMETER ( C68 = 68 )
      PARAMETER ( C69 = 69 )

C
C ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*      DEFINITION OF COMMONS USED IN UKOOA ROUTINES
*----------------------------------------------------------------------
C
*      LU_UNIT  USED TO DEFINE LOGICAL UNITS
*       MAG  :   L U  USED for ukooa data file
*       DISK :   L U  used for reading the parameter file  containing
*                      information coming from the interactive  part
*       LIST :  L U   used for logging informations
C
        INTEGER*4 MAG ,DISK , LIST
        COMMON /LU_UNIT/  MAG,DISK , LIST
C
*----------------------------------------------------------------------
C
C    CHOICE   COMMON USED TO STORE OPERATOR SELECTED FIELDS TO PROCESS
C
C        END    : array containing the column numbers of
c                    the beginning of each field
C        START  : array containing the column number of
c                    beginning of each field
C        CHOIX  :  CHOIX (I) = 1  FIELD I is to be processed as
C                                    integer/decimal number or char
C                            = 2  FIELD I is processed as dddmmss.s 
C                                    formatted angle
C                            = 0   FIELD I is not to be processed
C        SELFIELD : describe the selected fields in buffer buf
c                 each field has a code
C                 CODE   1   IS  LINE NAME
C                        2   IS SP NUMBER
C                        3   IS X COORD
C                        4   IS Y COORD
C                        5   IS LATITUDE
C                        6   IS LONGITUDE
C                        7   IS WATER DEPTH
C     2 , 3 , AND 4 ARE ALWAYS IN BUFFER BUF IN THIS ORDER
C    SO  SELFIELD (1) =2
C        SELFIELD(2) =3
C        SELFIELD (3) = 4
C    THEN DEPENDING IF WE SELECT LAT / LONG OR WATER DEPTH  THIS OTHER
C       CODES ARE STACKED IN SELFIELD
C
C       MAXERR : maximum number of bogus records allowed in a line
c                if we reach this limit the line is dropped and
c                messages are displayed on the log file
c
        INTEGER*4 END(NB_CHOIC) , START(NB_CHOIC)
        INTEGER*4 CHOIX(NB_CHOIC) , SELFIELD(NB_CHOIC),MAXERR
C
        COMMON / CHOICE/ END, START,
     +           CHOIX ,SELFIELD,MAXERR
C
*
*----------------------------------------------------------------------
C
*    ENTREE    COMMON USED FOR KEEPING THE NAME OF THE LINES IN THE DATA FILE
C
*        ITABL    : array coontaining  all the line names
*        NBENT    : number of lines
*        EXTREM_C : real array containing for each lines stored in the data
*                  base the coordinates of the two ends of the axis of the
*                  rectangle enclosing the line
*                  this coordinates are used to compute the enveloppe around
*                  the profile - this enveloppe is used by interpret when picking
*                  a line on the base map 
*                   4 words for each line : 
*                    WORD1  :  X_COORD OF FIRST END
*                    WORD2  :  Y_COORD OF FIRST END
*                    WORD3  :  X_COORD OF SECOND END
*                    WORD4  :  Y_COORD OF SECOND END
*
*                    SO THE COORDINATES FOR THE FIRST LINE ARE 
*                                EXTREM_C (1) TO EXTREM_C (4)
*                    WORD4  :  Y_COORD OF SECOND END
*
*                    SO THE COORDINATES FOR THE SECOND LINE ARE 
*                                EXTREM_C (5) TO EXTREM_C (8)
*
      INTEGER*4 ITABL , NBENT , IFG
      CHARACTER*100 CTABL
      EQUIVALENCE( ITABL , CTABL)
      REAL*4 EXTREM_C 
*
        COMMON/ENTREE/ NBENT , ITABL( L_TAB ),EXTREM_C(4* L_TAB/NBWLI)
C
*----------------------------------------------------------------------
C
*    COMMON GIVING INFORMATION ON THE LINES LOADED IN THE DATA BASE
C
*     IETADB  :  FLAG = TRUE if there are already lines with coordinates
*              in the data base when we begin to load
*                FLAG = FALSe if no lines in the data base
*     NEWLINE :  number of newlines added to the data base
*     NEWMAX  , NEWMIX : bounds on x_coord of the whoole survey
*      NEWMAY ,NEWMIY  : bounds on y_coord of the whole survey
*
*     REPLINE      : number of lines replaced in the data base
*
C     MAXBOGUS :  maximum number of bogus lines allowed per session
c            a bogus line is a line having more than maxerr of decoding
c

       REAL*4 NEWMAX , NEWMIX ,NEWMAY , NEWMIY
       INTEGER*4 IETATDB , NEWLINE , NUMBOGUS , MAXBOGUS
       INTEGER*4 REPLINE
*
        COMMON/ETAT/IETATDB,NEWLINE,NEWMAX,NEWMAY,NEWMIX,
     -              NEWMIY,NUMBOGUS,MAXBOGUS, REPLINE
*
*----------------------------------------------------------------------
C
C    COMMON SISLINE  FILLED WITH LINE ALREADY EXISTING IN THE DATA BASE
C     WITH XY COORDINATES AT THE BEGINNING OF THE LOADER SESSION
C
C       NB_LIG IS the number of lines in array ligne

      INTEGER*4 LIGNE
      CHARACTER*100  CLIGNE 
      REAL*4 RLIGNE (L_TAB)
      INTEGER*4 NB_LIG
      EQUIVALENCE ( LIGNE , CLIGNE )
      EQUIVALENCE ( LIGNE , RLIGNE )
C
      COMMON / SISLINE / LIGNE ( L_TAB ),NB_LIG
C
C
*----------------------------------------------------------------------
C
C     COMMON C_AREA GIVING INFORMATIONS ON THE AREA
C
C     AREANAME  : name of the area were we load
C     SURV_NAM  :    name of the survey 
C     DATAPROJ  : code of projection in which data are in ukooa file
c                     parameters defining the projection of the data
C     DA_TYPE  :  data projection type
C     DA_ZONE  :  state plane  or utn zone code
C     DA_SPHE  :    spheroid code
C     DA_UNIT  :    units code for the spheroid
C     DA_PARAM :   parameter array for gtp$0
C     AREAPROJ  :  code of the projection for the area
c                     parameters defining the projection of the area
C     AR_TYPE  :   area projection type
C     AR_ZONE  :  state plane  or utn zone code
C     AR_SPHE  :    spheroid code
C     AR_UNIT  :    units code for the spheroid
C     AR_PARAM :   parameter array for gtp$0
C     REP_FLAG   : FLAG = TRUE if we delete line in db to replace it
c                               by new loaded line
C                       + FALSE if we keep line already in the db
C     COMP_FLAG  :  REPLACE FLAG TRUE if we replace line or part of
c                     line by new line read in ukooa file
C                      FALSE  we don"t touch db line
C
C   PROJCONV     :  LOGICAL  TRUE    IF  AREAPROJ # DATAPROJ
C                               FALSE IF AREAPROJ = DATAPROJ
C    ILSURV    :   integer length in characters of the survey name 
C
      LOGICAL*4 PROJCONV
      INTEGER*4 NB_CHAR ,ILSURV
      CHARACTER*80  AREANAME
      CHARACTER*40   SURV_NAM
C
      CHARACTER*12 AREAPROJ , DATAPROJ
      INTEGER*4 AR_TYPE , AR_ZONE , AR_SPHE , AR_UNIT
      REAL*8 AR_PARAM ( 15 )
      INTEGER*4 DA_TYPE , DA_ZONE , DA_SPHE , DA_UNIT
      REAL*8 DA_PARAM ( 15 )
      LOGICAL*4 COMP_FLAG ,REP_FLAG
C
      COMMON / C_AREA / AR_PARAM, DA_PARAM , AREANAME , NB_CHAR ,
     +	  SURV_NAM ,DATAPROJ, AREAPROJ,
     +    AR_TYPE , AR_ZONE , AR_SPHE , AR_UNIT,
     +    DA_TYPE ,DA_ZONE,DA_SPHE,DA_UNIT ,
     +    REP_FLAG , COMP_FLAG,PROJCONV,ILSURV
C
C
C--------------------------------------------------------------------
C
C        COMMON CLOGIN - CONTAINS THE LOGIN STRING 
C
        CHARACTER*100 LOG_STR
C
        COMMON /CLOGIN/ LOG_STR
C
C
C*----------------------------------------------------------------------
C
C ... PARAMETER FILE INFORMATION SAVER
C
      CHARACTER*80  PFNAM
C
      COMMON / PARFIL / PFNAM, NB1, NB2, NB3, NB4
C
C
C*----------------------------------------------------------------------
C
C ... SQL UDATE/INSERT STATEMENT PREPARATION LOGICAL
C        SET IN MAIN    RESET IN STORLIN
C
      LOGICAL*4 FIRST_SQL
C
      COMMON / UKOLOG / FIRST_SQL

C*********************   END OF COMMON   *******************************
C
