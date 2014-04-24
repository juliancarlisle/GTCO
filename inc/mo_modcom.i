C  DEC/CMS REPLACEMENT HISTORY, Element MO_MODCOM.I
C  *3     3-NOV-1989 10:50:58 GILLESPIE "(SPR 1) Change in nomenclature for n-List stuff"
C  *2    14-SEP-1989 18:22:54 GORDON "(SPR -1) checkin from gulf"
C  *1    30-JUN-1989 15:17:55 GILLESPIE ""
C  DEC/CMS REPLACEMENT HISTORY, Element MO_MODCOM.I
C     
C
C MAX ROWS PER LOG - DO NOT INCREASE OR YOU MUST COMPILE WITH -BIG
C MUST BE EVEN !!!!!!!!!
C
      PARAMETER (MAX_ROWS = 16384)

C
C  MAX_VEL_ROWS IS 1/2 OF MAX_ROWS !!!!!!!!!!!!!!!
C  MAX_VEL_ROWS IS THE MOST ROWS ONE CAN PUT IN EMPIRICAL MODEL.
C  IF ANYONE EVER DOES IT, HE IS A NUT.
C
      PARAMETER (MAX_VEL_ROWS = 8192)

C
C  MAX_FILT_ROWS IS THE MAXIMUM SIZE OF THE FA BUFFER WHICH IS
C  USED AS THE FILTER WAVELET BUFFER
C
      PARAMETER (MAX_FILT_ROWS = 1001)

C
C MAX NODES IN MODEL MATRIX - DO NOT INCREASE OR USE -BIG
C
      PARAMETER (MAX_NODES = 32768)
C
C VEL   = VELOCITY ARRAY
C DEN   = DENSITY ARRAY
C DEPTH = TIME/DEPTH ARRAY
C CONN  = TRACE ARRAY
C VA    = REFLECTION COEFFICINET ARRAY
C FA    = FILTER COEFFICIENT ARRAY
C
      COMMON/MODEL1/VEL(MAX_ROWS),DEN(MAX_ROWS)
      COMMON/MODEL2/CONN(2500),VA(2500),DEPTH(2500),FA(MAX_FILT_ROWS)
C
C MODULE = MODEL MODULE NUMBER
C
      INTEGER*4 MODULE 
      DATA      MODULE /1015/
C
C MAX_WELLS = MAX NUMBER OF WELLS THIS THING WILL RUN WITH
C
      PARAMETER (MAX_WELLS=100)
C
C GKS GPL ARRAYS
C
      COMMON/MODEL3/XBUF(MAX_ROWS),YBUF(MAX_ROWS)
C
      REAL*4 GETVD_X(MAX_VEL_ROWS),GETVD_VALUE(MAX_VEL_ROWS)
      EQUIVALENCE(GETVD_X(1),XBUF(1))
      EQUIVALENCE(GETVD_VALUE(1),XBUF(MAX_VEL_ROWS+1))
C
C GETVD_X = X ARRAY USED IN FUNCTION MO_GET_VD
C GETVD_VALUE = VALUE ARRAY USED IN FUNCTION MO_GET_VD
C
C
C CORRELLATION ARRAYS, AT A SEGMENT BOUNDARY, ENLARGING MEANS YOU WILL
C HAVE TO COMPILE WITH -BIG ON PRIME
C
      COMMON/MODEL5/YOUT(MAX_NODES)
C
C VEL_LOG1 = CALCULATED NEW VELOCITY LOG FOR FIRST (LEFT) LOG
C VEL_LOG2 = CALCULATED NEW VELOCITY LOG FOR SECOND (RIGHT) LOG
C
      COMMON/MODEL6/VEL_LOG1(MAX_ROWS), VEL_LOG2(MAX_ROWS)

C
C VEL_OR1   = ORIGINAL SONIC LOG FROM LEFT WELL 
C VEL_OR2   = ORIGINAL SONIC LOG FROM RIGHT WELL 
C
C
      REAL XVEL(MAX_VEL_ROWS),YVEL(MAX_VEL_ROWS)
      EQUIVALENCE(VEL_LOG1(1),XVEL(1))
      EQUIVALENCE(VEL_LOG1(MAX_VEL_ROWS+1),YVEL(1))
C
C XVEL = X POSITONS OF VEL/DEN ROWS
C YVEL = Y POSITONS OF VEL/DEN ROWS
C
      REAL HVEL(MAX_VEL_ROWS),HDEN(MAX_VEL_ROWS)
      EQUIVALENCE(VEL_LOG2(1),HVEL(1))
      EQUIVALENCE(VEL_LOG2(MAX_VEL_ROWS+1),HDEN(1))
C
C HVEL = VELOCITIES AT TOP OF LAYER
C HDEN = DENSITIES AT TOP OF LAYER
C

      COMMON/MODEL7/VEL_OR1(MAX_ROWS), VEL_OR2(MAX_ROWS),
     X              DEN_OR1(MAX_ROWS), DEN_OR2(MAX_ROWS)
C
C     VEL_OR1 = SONIC OF LEFT TIE WELL
C     VEL_OR2 = SONIC OF RIGHT TIE WELL
C
      REAL VVEL(MAX_VEL_ROWS),VDEN(MAX_VEL_ROWS)
      EQUIVALENCE(VEL_OR1(1),VVEL(1))
      EQUIVALENCE(VEL_OR1(MAX_VEL_ROWS+1),VDEN(1))

C
C VVEL = VELOCITIES AT BOTTOM OF LAYER
C VDEN = DENSITIES AT BOTTOM OF LAYER
C
      INTEGER VEL_LAYERS(MAX_VEL_ROWS)
      EQUIVALENCE(VEL_OR2(1),VEL_LAYERS(1))
      REAL THIS_LAYER(MAX_VEL_ROWS)
      EQUIVALENCE(VEL_OR2(MAX_VEL_ROWS+1),THIS_LAYER(1))
C
C VEL_LAYERS = ARRAY CONTAINING FLAG OF WHO LAYER BELONGS TO
C THIS_LAYER = USED TO FILL UP ALL VELS OR DENS FOR A LAYER
C
C MAX LAYERS ALLOWED
C
      PARAMETER (MAX_LAYERS = 256)
C
C LAYERS   = ARRAY POSITION OF LAST ROW IN XBUF AND YBUF OF LAYER N
C LAYERS_PTRS - ARRAY POSION OF NTH LAYER AFTER SORT, USED IN EMPIRICAL
C               AS POINTERS OF VEL/DEN INFO FOR EACH LAYER MODEL
C LAYERS_NVELS - NUMBER OF VELOCITIES PER LAYER
C LAYERS_NDENS - NUMBER OF DENSITIES PER LAYER
C LAYERS_NVELPTS - TOTAL NUMBER OF VEL/DEN ROWS PER LAYER
C LAYERS_SED - TYPE OF SEDIMENTATION DEFINED (1,2, OR 3) FOR EACH LAYER
C
      COMMON/MODEL8/LAYERS(MAX_LAYERS),LAYERS_PTRS(MAX_LAYERS),
     X    LAYERS_NVELS(MAX_LAYERS),LAYERS_NDENS(MAX_LAYERS),
     X    LAYERS_NVELPTS(MAX_LAYERS), LAYERS_SED(MAX_LAYERS)
C
C FICT = FICTIONAL OR NULL VALUE PUT IN EMPTY NODES
C
      PARAMETER  (FICT = 888888.)
      PARAMETER (IFICT = 888888)
C
C MAX_GPL IS NUMBER OF ROWS TO REDUCE LARGE GPL ARRAYS TO. THIS IS TO
C REDUCE THE LARGE AMOUNTS OF DISPLAY LIST MEMORY REQUIRED.
C
      PARAMETER (MAX_GPL = 1024)
