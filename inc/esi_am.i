C  DEC/CMS REPLACEMENT HISTORY, Element ESI_AM.I
C  *1    30-JUN-1989 15:17:01 GILLESPIE ""
C  DEC/CMS REPLACEMENT HISTORY, Element ESI_AM.I
C     
C     $Header: /dba0/esi/finder/include/RCS/esi_am.i,v 1.1 89/05/30 16:33:35 esi Exp $ esi_am.i 
C     
C*************************************************************************
C
C NAME:    ESI_AM_DEFS.I
C
C AUTHOR:  J. GILLESPIE, after ESI_AM_DEFS.I by W. JAECK
C
C DESCRIPTION:
C
C    ESI_AM_DEFS.I defines all symbols which are recognized by the
C    application manager as parameters to any of the application manager
C    services.
C
C*************************************************************************/

      INTEGER*4 AM_APPLICATION
      PARAMETER (AM_APPLICATION = 20)
      INTEGER*4 AM_SERVER
      PARAMETER (AM_SERVER = 21)
      INTEGER*4 AM_GLOBAL
      PARAMETER (AM_GLOBAL = 22)
      INTEGER*4 AM_MENU
      PARAMETER (AM_MENU = 23)
      INTEGER*4 AM_DIALOG
      PARAMETER (AM_DIALOG = 24)
      INTEGER*4 AM_STATUS
      PARAMETER (AM_STATUS = 26)
      INTEGER*4 AM_ALERT
      PARAMETER (AM_ALERT = 27)
      INTEGER*4 AM_OPEN_JOURNAL_FILE
      PARAMETER (AM_OPEN_JOURNAL_FILE = 29)
      INTEGER*4 AM_CLOSE_JOURNAL_FILE
      PARAMETER (AM_CLOSE_JOURNAL_FILE = 30)
      INTEGER*4 AM_REPORT
      PARAMETER (AM_REPORT = 34)
      INTEGER*4 AM_FILE_STATUS
      PARAMETER (AM_FILE_STATUS = 35)
      INTEGER*4 AM_FILE_REPORT
      PARAMETER (AM_FILE_REPORT = 36)

C	DEFINE THE AM GLUE ROUTINES

c     INTEGER*4 amg_abort
c     INTEGER*4 amg_allocate
c     INTEGER*4 amg_declare
c     INTEGER*4 amg_define_resource
c     INTEGER*4 amg_define_workspace
c     INTEGER*4 amg_dispatcher
c     INTEGER*4 amg_free
c     INTEGER*4 amg_initialize
c     INTEGER*4 amg_open_workspace
c     INTEGER*4 amg_quit
c     INTEGER*4 amg_release_resource
c     INTEGER*4 amg_release_workspace
c     INTEGER*4 amg_set_resource_server
c     INTEGER*4 amg_start_application
c     INTEGER*4 amg_start_server
c     INTEGER*4 amg_terminate
c     INTEGER*4 amg_message
