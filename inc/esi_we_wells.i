C  DEC/CMS REPLACEMENT HISTORY, Element ESI_WE_WELLS.I
C  *1    30-JUN-1989 15:17:32 GILLESPIE ""
C  DEC/CMS REPLACEMENT HISTORY, Element ESI_WE_WELLS.I
C     
C     $Header: /dba0/esi/finder/include/RCS/esi_we_wells.i,v 1.1 89/05/30 16:33:43 esi Exp $ esi_we_wells.i 
C     
C
C	SIZE SETTINGS FOR STRING VARIABLE DECLARATION
C	EXAMPLE: CHARACTER*(SIZEOF_UWI) UWI
C
      INTEGER*4 SIZEOF_UWI
      PARAMETER (SIZEOF_UWI = 20)
      INTEGER*4 SIZEOF_WNAME
      PARAMETER (SIZEOF_WNAME = 32)
      INTEGER*4 SIZEOF_STATE
      PARAMETER (SIZEOF_STATE = 20)
      INTEGER*4 SIZEOF_COUNTY
      PARAMETER (SIZEOF_COUNTY = 25)
      INTEGER*4 SIZEOF_OPER
      PARAMETER (SIZEOF_OPER = 35)
