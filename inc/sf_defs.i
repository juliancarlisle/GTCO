C  DEC/CMS REPLACEMENT HISTORY, Element SF_DEFS.I
C  *1    30-JUN-1989 15:18:04 GILLESPIE ""
C  DEC/CMS REPLACEMENT HISTORY, Element SF_DEFS.I
C     
C     $Header: /dba0/esi/finder/include/RCS/sf_defs.i,v 1.1 89/05/30 16:33:53 esi Exp $ sf_defs.i 
C     
C
C	FILTER DEFINITIONS FOR THE VARIOUS TYPES
C

      INTEGER*4  COSINE_WAV, ORMSBY_WAV, BUTTERWORTH_WAV
      INTEGER*4  RICKER_WAV, USER_DEFINED_WAV
      INTEGER*4  ORMSBY_HPASS, ORMSBY_BPASS, ORMSBY_LPASS, ORMSBY_NOTCH 

      PARAMETER (COSINE_WAV = 1)
      PARAMETER (ORMSBY_WAV = 2)
      PARAMETER (BUTTERWORTH_WAV = 3)
      PARAMETER (RICKER_WAV = 4)
      PARAMETER (USER_DEFINED_WAV = 5)

      PARAMETER (ORMSBY_BPASS = 1)
      PARAMETER (ORMSBY_LPASS = 2)
      PARAMETER (ORMSBY_HPASS = 3)
      PARAMETER (ORMSBY_NOTCH = 4)

C
C  SET THE MAXIMUM NUMBER OF SAMPLES IN THE FILTER BUFFER
C
      PARAMETER (MAX_FILT_LENGTH = 501)    

