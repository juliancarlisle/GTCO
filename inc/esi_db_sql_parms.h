/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DB_SQL_PARMS.H */
/* *2    11-AUG-1989 20:55:13 CONROY "(SPR 0) SQL Macro Processor" */
/* *1    11-AUG-1989 20:54:33 CONROY "SQL Macro Processor" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_DB_SQL_PARMS.H */
/*************************************************************************

FILE:    ESI_DB_SQL_PARMS.H

DESCRIPTION:

    ESI_DB_SQL_PARMS.H contains the declarations and structure definitions
    which are necessary to use the tools for processing SQL phrase
    substitution parameters.

*************************************************************************/

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

typedef struct sub_var_struct {
    struct sub_var_struct *next;    /* pointer to next  variable struct, NULL --> last */
    CHAR sub_variable[STMAX];       /* entire string <<...>> */
    CHAR prompt[STMAX];             /* prompt string */
    CHAR prompt_operator[STMAX];    /* operator string */
    CHAR response[STMAX];           /* user response or selection string */
} SUB_VAR_STRUCT;

#if USE_PROTOTYPES

publicdef INT db_sql_parms_processor(CHAR *old_phrase, CHAR **new_phrase);
publicdef INT db_sql_parms_parse(CHAR *sql_phrase, INT *nvars, SUB_VAR_STRUCT **sub_vars);
publicdef INT db_sql_parms_user(INT nvars, SUB_VAR_STRUCT *sub_vars);
publicdef INT db_sql_parms_substitute(CHAR *old_phrase, CHAR **new_phrase, 
                                    INT nvars, SUB_VAR_STRUCT *sub_vars);
publicdef INT db_sql_parms_prompt(CHAR *prompt, CHAR *response );
publicdef INT db_sql_parms_tlu(CHAR *prompt, CHAR *operator_parms, CHAR *response );

#else

publicdef INT db_sql_parms_processor();
publicdef INT db_sql_parms_parse();
publicdef INT db_sql_parms_user();
publicdef INT db_sql_parms_subsitute();
publicdef INT db_sql_parms_prompt();
publicdef INT db_sql_parms_tlu();

#endif
