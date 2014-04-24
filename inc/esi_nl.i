C  DEC/CMS REPLACEMENT HISTORY, Element ESI_NL.I
C  *2     3-NOV-1989 10:43:58 GILLESPIE "(SPR 1) Changes for new n-List nomenclature"
C  *1    30-JUN-1989 15:17:04 GILLESPIE ""
C  DEC/CMS REPLACEMENT HISTORY, Element ESI_NL.I
C     
C     $Header: /dba0/esi/finder/include/RCS/esi_nl.i,v 1.1 89/05/30 16:33:35 esi Exp $ esi_nl.i 
C     
C ****************************************************************
C
C      INCLUDE FILE FOR FORTRAN PROGRAMS CALLING THE
C        NLIST SERVICES
C
C ****************************************************************
C
C
C DATA TYPE CODES
      INTEGER*4 CHAR_TYPE
      PARAMETER (CHAR_TYPE = 1)
      INTEGER*4 INT_TYPE
      PARAMETER (INT_TYPE = 3)
      INTEGER*4 FLOAT_TYPE
      PARAMETER (FLOAT_TYPE = 4)
      INTEGER*4 DATE_TYPE
      PARAMETER (DATE_TYPE = 8)
      INTEGER*4 BOOL_TYPE
      PARAMETER (BOOL_TYPE = 9)

C ******************************************************************
C
C      DECLARATION OF THE FUNCTION HOPTR WHICH IS REPLACING
C      FORTRAN FUNCTION  LOC     GIVING THE ADRESS OF A VARIABLE
C
C ****************************************************************
C
      REAL*8 HOPTR
C
C* ====== these are used by NL_INIT_NLIST ====== */

      INTEGER*4 VALUE_LIST
      PARAMETER ( VALUE_LIST = 113 )
      INTEGER*4  INCREMENT_LIST
      PARAMETER  ( INCREMENT_LIST = 114 )
C* ====== these are used by NL_SORT_NLIST ====== */

      INTEGER*4  NL_ASCENDING
      PARAMETER  ( NL_ASCENDING = 115 )
      INTEGER*4  NL_DESCENDING
      PARAMETER  ( NL_DESCENDING = 116 )
C* ====== these flag bits are ANDed together and returned ====== */

      INTEGER*4  NL_START_OF_LIST
      PARAMETER  ( NL_START_OF_LIST      = 2 )
      INTEGER*4  NL_START_OF_TABLE
      PARAMETER  ( NL_START_OF_TABLE    = 4 )
      INTEGER*4  NL_END_OF_LIST
      PARAMETER  ( NL_END_OF_LIST        = 8 )
      INTEGER*4  NL_END_OF_TABLE
      PARAMETER  ( NL_END_OF_TABLE      = 16 )
      INTEGER*4  NL_EOL
      PARAMETER  ( NL_EOL                = 64 )


C* define the TYPE for table info and nlist info.   */
      INTEGER*4  NL_NLIST_AVG
      PARAMETER  ( NL_NLIST_AVG                   = 1001 )
      INTEGER*4  NL_NLIST_DATA_TYPE
      PARAMETER  ( NL_NLIST_DATA_TYPE             = 1002 )
      INTEGER*4  NL_NLIST_DATA_WIDTHS
      PARAMETER  ( NL_NLIST_DATA_WIDTHS           = 1003 )
      INTEGER*4  NL_NLIST_FIND_TOLERANCE
      PARAMETER  ( NL_NLIST_FIND_TOLERANCE        = 1004 )
      INTEGER*4  NL_NLIST_MAX
      PARAMETER  ( NL_NLIST_MAX                   = 1005 )
      INTEGER*4  NL_NLIST_MIN
      PARAMETER  ( NL_NLIST_MIN                   = 1006 )
      INTEGER*4  NL_NLIST_NON_NULL
      PARAMETER  ( NL_NLIST_NON_NULL              = 1007 )
      INTEGER*4  NL_NLIST_NULL_VALUE
      PARAMETER  ( NL_NLIST_NULL_VALUE            = 1008 )
      INTEGER*4  NL_NLIST_STD_DEV
      PARAMETER  ( NL_NLIST_STD_DEV               = 1009 )
      INTEGER*4  NL_NLIST_UNITS
      PARAMETER  ( NL_NLIST_UNITS                 = 1010 )
      INTEGER*4  NL_NLIST_NUMERIC_FORMAT
      PARAMETER  ( NL_NLIST_NUMERIC_FORMAT        = 1011 )
      INTEGER*4  NL_NLIST_DIM_NAME
      PARAMETER  ( NL_NLIST_DIM_NAME              = 1012 )
      INTEGER*4  NL_NLIST_VALUE_INC
      PARAMETER  ( NL_NLIST_VALUE_INC             = 1013 )
      INTEGER*4  NL_TABLE_AVG
      PARAMETER  ( NL_TABLE_AVG                  = 1051 )
      INTEGER*4  NL_TABLE_INCREMENT
      PARAMETER  ( NL_TABLE_INCREMENT            = 1052 )
      INTEGER*4  NL_TABLE_MAX
      PARAMETER  ( NL_TABLE_MAX                  = 1053 )
      INTEGER*4  NL_TABLE_MIN
      PARAMETER  ( NL_TABLE_MIN                  = 1054 )
      INTEGER*4  NL_TABLE_NON_NULL
      PARAMETER  ( NL_TABLE_NON_NULL             = 1055 )
      INTEGER*4  NL_TABLE_START_VALUE
      PARAMETER  ( NL_TABLE_START_VALUE          = 1056 )
      INTEGER*4  NL_TABLE_STD_DEV
      PARAMETER  ( NL_TABLE_STD_DEV              = 1057 )

C* define the OPCODEs for table int and nlist int.   */
      INTEGER*4  NL_NLIST_BLOCKSIZE
      PARAMETER  ( NL_NLIST_BLOCKSIZE             = 1021 )
      INTEGER*4  NL_NLIST_DEFERRED_STATS
      PARAMETER  ( NL_NLIST_DEFERRED_STATS        = 1022 )
      INTEGER*4  NL_NLIST_NDIM
      PARAMETER  ( NL_NLIST_NDIM                  = 1023 )
      INTEGER*4  NL_NLIST_NROWS
      PARAMETER  ( NL_NLIST_NROWS               = 1024 )
      INTEGER*4  NL_NLIST_NTABLES
      PARAMETER  ( NL_NLIST_NTABLES              = 1025 )
      INTEGER*4  NL_TABLE_NROWS
      PARAMETER  ( NL_TABLE_NROWS              = 1058 )

C* define the OPCODEs for TABLE_string and nlist_string.   */
      INTEGER*4  NL_NLIST_FILENAME
      PARAMETER  ( NL_NLIST_FILENAME   = 1031 )
      INTEGER*4  NL_NLIST_NAME
      PARAMETER  ( NL_NLIST_NAME       = 1032 )
      INTEGER*4  NL_NLIST_NEXT
      PARAMETER  ( NL_NLIST_NEXT       = 1033 )
      INTEGER*4  NL_TABLE_NAME
      PARAMETER  ( NL_TABLE_NAME      = 1081 )
C* define the OPCODEs for nl_compare_list    */
      INTEGER*4  NL_GT
      PARAMETER  ( NL_GT               = 2001 )
      INTEGER*4  NL_LT
      PARAMETER  ( NL_LT               = 2002 )
      INTEGER*4  NL_GE
      PARAMETER  ( NL_GE               = 2003 )
      INTEGER*4  NL_LE
      PARAMETER  ( NL_LE               = 2004 )
      INTEGER*4  NL_EQ
      PARAMETER  ( NL_EQ               = 2005 )
      INTEGER*4  NL_NE
      PARAMETER  ( NL_NE               = 2006 )
      INTEGER*4  NL_AND
      PARAMETER  ( NL_AND              = 2007 )
      INTEGER*4  NL_OR
      PARAMETER  ( NL_OR               = 2008 )
      INTEGER*4  NL_XOR
      PARAMETER  ( NL_XOR              = 2009 )
      INTEGER*4  NL_NAND
      PARAMETER  ( NL_NAND             = 2010 )
      INTEGER*4  NL_NOR
      PARAMETER  ( NL_NOR              = 2011 )

C* define the OPCODEs for nl_operate_list_1    */
      INTEGER*4  NL_ABS
      PARAMETER  ( NL_ABS              = 3001 )
      INTEGER*4  NL_LOG10
      PARAMETER  ( NL_LOG10            = 3002 )
      INTEGER*4  NL_LOGE
      PARAMETER  ( NL_LOGE             = 3003 )
      INTEGER*4  NL_SIN
      PARAMETER  ( NL_SIN              = 3004 )
      INTEGER*4  NL_COS
      PARAMETER  ( NL_COS              = 3005 )
      INTEGER*4  NL_TAN
      PARAMETER  ( NL_TAN              = 3006 )
      INTEGER*4  NL_ASIN
      PARAMETER  ( NL_ASIN             = 3007 )
      INTEGER*4  NL_ACOS
      PARAMETER  ( NL_ACOS             = 3008 )
      INTEGER*4  NL_ATAN
      PARAMETER  ( NL_ATAN             = 3009 )
      INTEGER*4  NL_IDENTICAL
      PARAMETER  ( NL_IDENTICAL        = 3010 )
C* define the OPCODE for nl_operate_list_2    */
      INTEGER*4  NL_ADD
      PARAMETER  ( NL_ADD              = 4001 )
      INTEGER*4  NL_SUB
      PARAMETER  ( NL_SUB              = 4002 )
      INTEGER*4  NL_MULT
      PARAMETER  ( NL_MULT             = 4003 )
      INTEGER*4  NL_DIV
      PARAMETER  ( NL_DIV              = 4004 )
      INTEGER*4  NL_EXP
      PARAMETER  ( NL_EXP              = 4005 )
      INTEGER*4  NL_MOD
      PARAMETER  ( NL_MOD              = 4006 )
      INTEGER*4  NL_CRUSH_MIN
      PARAMETER  ( NL_CRUSH_MIN        = 4007 )
      INTEGER*4  NL_CLIP_MIN
      PARAMETER  ( NL_CLIP_MIN         = 4008 )
      INTEGER*4  NL_CRUSH_MAX
      PARAMETER  ( NL_CRUSH_MAX        = 4009 )
      INTEGER*4  NL_CLIP_MAX
      PARAMETER  ( NL_CLIP_MAX         = 4010 )
C* ======= OPCODE for NL_RESAMPLE_NLIST ================== */
      INTEGER*4  NL_SPLINE_FIT
      PARAMETER  ( NL_SPLINE_FIT       = 5001 )
      INTEGER*4  NL_BI_LINEAR
      PARAMETER  ( NL_BI_LINEAR        = 5002 )

C******************************************************************************/

      INTEGER*4  NLG_ADD_ROWS_CONVERT
      INTEGER*4  NLG_ADD_ROWS
      INTEGER*4  NLG_DELETE_ROWS
      INTEGER*4  NLG_FIND_ROW
      INTEGER*4  NLG_FIRST_ROW
      INTEGER*4  NLG_GET_ROWS
      INTEGER*4  NLG_GET_ROWS_CONVERT
      INTEGER*4  NLG_INQ_CURRENT_ROW
      INTEGER*4  NLG_INQ_ROW_FLAG
      INTEGER*4  NLG_INSERT_ROWS_CONVERT
      INTEGER*4  NLG_INSERT_ROWS
      INTEGER*4  NLG_LAST_ROW
      INTEGER*4  NLG_NEXT_ROW
      INTEGER*4  NLG_PREVIOUS_ROW
      INTEGER*4  NLG_REPLACE_ROWS
      INTEGER*4  NLG_SET_CURRENT_ROW
      INTEGER*4  NLG_DRAW_NLIST
      INTEGER*4  NLG_DRAW_TABLE
      INTEGER*4  NLG_CLEAR_NLIST
      INTEGER*4  NLG_COMPARE_NLIST
      INTEGER*4  NLG_COPY_NLIST
      INTEGER*4  NLG_FREE_NLIST
      INTEGER*4  NLG_FREE_TABLE
      INTEGER*4  NLG_INIT_NLIST
      INTEGER*4  NLG_INQ_NLIST_INFO
      INTEGER*4  NLG_INQ_NLIST_INT
      INTEGER*4  NLG_INQ_NLIST_STRING
      INTEGER*4  NLG_INQ_NLIST_USER_STRUCT
      INTEGER*4  NLG_OPERATE_NLIST_1
      INTEGER*4  NLG_OPERATE_NLIST_2
      INTEGER*4  NLG_RESAMPLE_NLIST
      INTEGER*4  NLG_SET_NLIST_INFO
      INTEGER*4  NLG_SET_NLIST_INT
      INTEGER*4  NLG_SET_NLIST_STRING
      INTEGER*4  NLG_SET_NLIST_USER_STRUCT
      INTEGER*4  NLG_SORT_NLIST
      INTEGER*4  NLG_SORT_TABLE
      INTEGER*4  NLG_GET_CURRENT_ROW
      INTEGER*4  NLG_COPY_TABLE
      INTEGER*4  NLG_DELETE_NLIST
      INTEGER*4  NLG_DELETE_TABLE
      INTEGER*4  NLG_INQ_TABLE_INFO
      INTEGER*4  NLG_INQ_TABLE_INT
      INTEGER*4  NLG_INQ_TABLE_STRING
      INTEGER*4  NLG_INQ_TABLE_USER_STRUCT
      INTEGER*4  NLG_READ_NLIST
      INTEGER*4  NLG_READ_NLIST_EXCLUSIVE
      INTEGER*4  NLG_SET_TABLE_INFO
      INTEGER*4  NLG_SET_TABLE_INT
      INTEGER*4  NLG_SET_TABLE_STRING
      INTEGER*4  NLG_SET_TABLE_USER_STRUCT
      INTEGER*4  NLG_START_TABLE
      INTEGER*4  NLG_UPDATE_NLIST
      INTEGER*4  NLG_WINDOW_CLIP_NLIST
      INTEGER*4  NLG_WRITE_NLIST
      INTEGER*4  NLG_WRITE_NLIST_EXCLUSIVE
