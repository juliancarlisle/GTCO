      INTEGER*4 MD_KEYWORD_MISSING
      PARAMETER (MD_KEYWORD_MISSING = -56002)
      INTEGER*4 MD_VERB_NOT_DISPLAYED
      PARAMETER (MD_VERB_NOT_DISPLAYED = -56011)
      INTEGER*4 MD_KEY_NOT_DISPLAYED
      PARAMETER (MD_KEY_NOT_DISPLAYED = -56012)
      INTEGER*4 MD_VERB_NOT_FOUND
      PARAMETER (MD_VERB_NOT_FOUND = -56013)
      INTEGER*4 MD_UNBALANCED_PARENS
      PARAMETER (MD_UNBALANCED_PARENS = -56014)
C
      INTEGER*4 MD_BAD_KEYWORD_END
      PARAMETER (MD_BAD_KEYWORD_END = -56015)
      INTEGER*4 MD_KEYWORD_NOT_FOUND
      PARAMETER (MD_KEYWORD_NOT_FOUND = -56016)
      INTEGER*4 MD_MISSING_REQ_KEYWORD
      PARAMETER (MD_MISSING_REQ_KEYWORD = -56017)
      INTEGER*4 MD_DUPLICATE_KEYWORD
      PARAMETER (MD_DUPLICATE_KEYWORD = -56018)
      INTEGER*4 MD_MISSING_REQ_PARAMETER
      PARAMETER (MD_MISSING_REQ_PARAMETER = -56019)
C
      INTEGER*4 MD_WRONG_TYPE_PARAMETER
      PARAMETER (MD_WRONG_TYPE_PARAMETER = -56020)
      INTEGER*4 MD_WRONG_NUM_PARAMETER
      PARAMETER (MD_WRONG_NUM_PARAMETER = -56021)
      INTEGER*4 MD_BAD_PARAMETER_VALUE
      PARAMETER (MD_BAD_PARAMETER_VALUE = -56022)
      INTEGER*4 MD_BAD_NUMBER_RANGE
      PARAMETER (MD_BAD_NUMBER_RANGE = -56023)
      INTEGER*4 MD_EXCLUSION_VIOLATION
      PARAMETER (MD_EXCLUSION_VIOLATION = -56024)
C
      INTEGER*4 MD_CODE_NOT_FOUND
      PARAMETER (MD_CODE_NOT_FOUND = -56025)
      INTEGER*4 MD_STRING_NOT_FOUND
      PARAMETER (MD_STRING_NOT_FOUND = -56026)
      INTEGER*4 MD_FILE_DOES_NOT_EXIST
      PARAMETER (MD_FILE_DOES_NOT_EXIST = -56027)
      INTEGER*4 MD_COLUMN_NOT_FOUND
      PARAMETER (MD_COLUMN_NOT_FOUND = -56028)
      INTEGER*4 MD_SELECT_LIST_NOT_FOUND
      PARAMETER (MD_SELECT_LIST_NOT_FOUND = -56029)
C
      INTEGER*4 MD_BAD_FILENAME
      PARAMETER (MD_BAD_FILENAME = -56030)
      INTEGER*4 MD_VERB_TOO_LONG
      PARAMETER (MD_VERB_TOO_LONG = -56031)
      INTEGER*4 MD_KEYWORD_TOO_LONG
      PARAMETER (MD_KEYWORD_TOO_LONG = -56032)
      INTEGER*4 MD_PARAMETER_TOO_LONG
      PARAMETER (MD_PARAMETER_TOO_LONG = -56033)
      INTEGER*4 MD_UNRECOGNIZED_VALID_CODE
      PARAMETER (MD_UNRECOGNIZED_VALID_CODE = -56034)
C
      INTEGER*4 MD_ORACLE_ERROR
      PARAMETER (MD_ORACLE_ERROR = -56035)
      INTEGER*4 MD_MAP_NOT_FOUND
      PARAMETER (MD_MAP_NOT_FOUND = -56036)
      INTEGER*4 MD_PLEASE_SELECT
      PARAMETER (MD_PLEASE_SELECT = -56037)
      INTEGER*4 MD_SELECT_ONE
      PARAMETER (MD_SELECT_ONE = -56038)
      INTEGER*4 MD_SELECT_PROJECTION
      PARAMETER (MD_SELECT_PROJECTION = -56039)
C
      INTEGER*4 MD_SELECT_ONE_VERB
      PARAMETER (MD_SELECT_ONE_VERB = -56040)
      INTEGER*4 MD_SELECT_ONE_KEY
      PARAMETER (MD_SELECT_ONE_KEY = -56041)
      INTEGER*4 MD_CANCEL
      PARAMETER (MD_CANCEL = -56045)
      INTEGER*4 MD_NO_MAP
      PARAMETER (MD_NO_MAP = -56046)
      INTEGER*4 MD_NO_MAP_ACTIVE
      PARAMETER (MD_NO_MAP_ACTIVE = -56048)
C
      INTEGER*4 MD_SELECT_ONE_PARM
      PARAMETER (MD_SELECT_ONE_PARM = -56049)
      INTEGER*4 MD_BAD_SQL
      PARAMETER (MD_BAD_SQL = -56050)
      INTEGER*4 MD_BAD_EXPR
      PARAMETER (MD_BAD_EXPR = -56051)
      INTEGER*4 MD_BAD_MAP_SCALE
      PARAMETER (MD_BAD_MAP_SCALE = -56052)
      INTEGER*4 MD_BAD_VERB
      PARAMETER (MD_BAD_VERB = -56053)
C
      INTEGER*4 MD_INVALID_MAP_LIMITS
      PARAMETER (MD_INVALID_MAP_LIMITS = -56054)
      INTEGER*4 MD_MISSING_REQ_KEY
      PARAMETER (MD_MISSING_REQ_KEY = -56057)
      INTEGER*4 MD_INVALID_VERB
      PARAMETER (MD_INVALID_VERB = -56058)
      INTEGER*4 MD_INVALID_KEY
      PARAMETER (MD_INVALID_KEY = -56059)
      INTEGER*4 MD_INVALID_PARAMETER
      PARAMETER (MD_INVALID_PARAMETER = -56060)
C
      INTEGER*4 MD_KEY_IN_OVERLAY
      PARAMETER (MD_KEY_IN_OVERLAY = -56061)
      INTEGER*4 MD_CANT_DEL_REQ_KEY
      PARAMETER (MD_CANT_DEL_REQ_KEY = -56062)
      INTEGER*4 MD_VALID_ERROR_PARM
      PARAMETER (MD_VALID_ERROR_PARM = -56063)
      INTEGER*4 MD_VALID_ERROR_KEY
      PARAMETER (MD_VALID_ERROR_KEY = -56064)
      INTEGER*4 MD_VALID_ERROR_VERB
      PARAMETER (MD_VALID_ERROR_VERB = -56065)
C
      INTEGER*4 MD_MAPDEF_NOT_VALID
      PARAMETER (MD_MAPDEF_NOT_VALID = -56066)
      INTEGER*4 MD_CANT_FIND_LOOKUP_TABLE
      PARAMETER (MD_CANT_FIND_LOOKUP_TABLE = -56069)
      INTEGER*4 MD_CANT_FIND_LOOKUP_VALUE
      PARAMETER (MD_CANT_FIND_LOOKUP_VALUE = -56070)
      INTEGER*4 MD_MAPNAME_TOO_LONG
      PARAMETER (MD_MAPNAME_TOO_LONG = -56071)
      INTEGER*4 MD_NON_ASSOC_KEYWORD
      PARAMETER (MD_NON_ASSOC_KEYWORD = -56074)
C
      INTEGER*4 MD_NON_ASSOC_PARAMETER
      PARAMETER (MD_NON_ASSOC_PARAMETER = -56075)
      INTEGER*4 MD_RESERVED_OVERLAY_NAME
      PARAMETER (MD_RESERVED_OVERLAY_NAME = -56076)
      INTEGER*4 MD_NO_PARAMETERS
      PARAMETER (MD_NO_PARAMETERS = -56078)
      INTEGER*4 MD_NO_INPUT_FILE_SPECIFIED
      PARAMETER (MD_NO_INPUT_FILE_SPECIFIED = -56081)
      INTEGER*4 MD_ONLY_ONE_INPUT_FILE
      PARAMETER (MD_ONLY_ONE_INPUT_FILE = -56089)
C
      INTEGER*4 MD_NAME_NOT_FOUND_EXP
      PARAMETER (MD_NAME_NOT_FOUND_EXP = -56090)
      INTEGER*4 MD_NO_TITLE_BLOCKS_RETRIEVED
      PARAMETER (MD_NO_TITLE_BLOCKS_RETRIEVED = -56091)
      INTEGER*4 MD_UOM_CONFLICT
      PARAMETER (MD_UOM_CONFLICT = -56095)
      INTEGER*4 MD_BAD_DEGREES
      PARAMETER (MD_BAD_DEGREES = -56096)
