C DEC/CMS REPLACEMENT HISTORY, Element NPDEFS.I
C *1    28-AUG-1990 09:25:01 GILLESPIE "Used by neutral file plotting"
C DEC/CMS REPLACEMENT HISTORY, Element NPDEFS.I
C  DEC/CMS REPLACEMENT HISTORY, Element NPDEFS.I
C  *1    30-JUN-1989 15:18:01 GILLESPIE ""
C  DEC/CMS REPLACEMENT HISTORY, Element NPDEFS.I
C     
C     $Header: /dba0/esi/finder/include/RCS/npdefs.i,v 1.1 89/05/30 16:33:52 esi Exp $ npdefs.i 
C     
C------------------------------------------------------------------
C
C     Include file for NP_TOOLS.FOR, NP_TEST.FOR & misc npxxx.for
C     files.
C
C     Contains the npfile header shared common block variables
C     also contains the definitions for the status codes returned
C     by np_tools.for routines.
C
C Julian Carlisle    April 27,1988
C------------------------------------------------------------------
C
C      IMPLICIT    NONE        /*This is VAX specific*/
C Declare common variable blocks
C

      REAL           NPF_XMAX
      REAL           NPF_XMIN
C  MIN/MAX X IN NPFILE
      REAL           NPF_YMAX
      REAL           NPF_YMIN
C  MIN/MAX Y IN NPFILE
      REAL           DEV_XMAX
      REAL           DEV_YMAX
      REAL           DEF_UOM
C  1.0 = INCHES;  2.54 = METRIC
      REAL           UOM_METRIC
C  Factor for metric
      REAL           UOM_ENGLISH
C  Factor for english
      INTEGER        NPF_FNLEN
      INTEGER        DPF_FNLEN
      INTEGER        NPLEN
      INTEGER        NPVERS
      INTEGER        LINELEN
      INTEGER        DEVSEL
      INTEGER        PLOTID
      LOGICAL*1      IFOPEN_IN
C  TRUE IF INLUN OPENED
      LOGICAL*1      IFOPEN_OUT
C  TRUE IF INLUN OPENED
      LOGICAL*1      IFNAMED_IN
C  TRUE IF INLUN NAMED
      LOGICAL*1      IFNAMED_OUT
C  TRUE IF OUTLUN NAMED
      CHARACTER*128  LINEIN
      CHARACTER*128  NPF_FNAME
      CHARACTER*128  DPF_FNAME


C
C Declare common variable blocks
C
      INTEGER        SUCCESS
      INTEGER        FAIL
      INTEGER        CORRUPT_FILE
      INTEGER        BAD_VERSION
      INTEGER        FILE_ERROR
      INTEGER        READ_ERROR
      INTEGER        CURR_VERS
      INTEGER        VERSION
      INTEGER        INPUT_UNIT
C  Ref. Copy of I/O Lun Nums
      INTEGER        OUTPUT_UNIT
C  For consistency 'tween pgms
      INTEGER        EXIT_VEC
C  Pseudo Lbl for exit point
      INTEGER        ERROR_VEC
C  " "    " "   for errorS
      INTEGER        ZETA_ID
      INTEGER        CALCOMP_ID
      INTEGER        DISCO_ID
C
C------- END OF GLOBAL COMMON
      PARAMETER   (ZETA_ID = 53, CALCOMP_ID=0, DISCO_ID=1)

      PARAMETER   (CURR_VERS = 100)
C  Master Ver# FOR REF.
      PARAMETER   (VERSION = 100)
C  Master Ver# FOR REF.
      PARAMETER   (FAIL=0,
C  BASIC TROUBLE REPORT
     1            SUCCESS= 1,
C  (SS$_NORMAL)
     2            FILE_ERROR= 2,
C  ERROR OPENING/FINDING FILE
     3            READ_ERROR= 4,
C  ERROR WHILE READING NPFILE
     4            BAD_VERSION= 8,
C  WRONG NPFILE VERSION NUM
     5            CORRUPT_FILE= 16)
C  BAD FILE FORMAT/TYPE
      PARAMETER   (UOM_METRIC = 2.54)
C  UOM VALUE DEFINITIONS
      PARAMETER   (UOM_ENGLISH = 1.0)
C  DECLARED AS CONSTANTS
C
C The initial UOM defaults to ENGLISH units.
      PARAMETER   (DEF_UOM=UOM_ENGLISH)
C

      PARAMETER   (INPUT_UNIT = 10)
C  Declaration of input lun
      PARAMETER   (OUTPUT_UNIT = 9)
C  "     "     of output lun

      COMMON /NPCOM/ NPF_XMAX,NPF_XMIN,NPF_YMAX,NPF_YMIN,
     1            DEV_XMAX,DEV_YMAX,NPF_FNAME,DPF_FNAME,
     2            NPF_FNLEN,DPF_FNLEN,NPLEN,NPVERS,
     3            IFOPEN_IN,IFOPEN_OUT,IFNAMED_IN,IFNAMED_OUT,
     4            LINEIN,LINELEN,DEVSEL,PLOTID
C
