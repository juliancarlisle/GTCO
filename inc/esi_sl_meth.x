/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SL_METH.X */
/* *3    27-JUN-1991 14:58:53 PURNA "(SPR 0) fixed init error" */
/* *2    30-JUL-1990 17:20:30 PURNA "(SPR 0) add lynx,lease select_list" */
/* *1    30-JUL-1990 17:09:55 PURNA " sl method global definition" */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SL_METH.X */

#ifndef ESI_SL_METH_X
#define ESI_SL_METH_X 1

#ifndef ESI_SL_H
#include "esi_sl.h"
#endif 

extern const SL_METHOD_HEADER sl_method_defaults[1];
extern SL_DTYPE_HEADER sl_data_type_names[1],sl_table_header_names[1],
			sl_table_headings[1];
extern SL_DOMAIN_HEADER sl_column_domain[1],sl_qs_cur_count[1],sl_qs_cur_list[1],
			sl_qs_cur[1],sl_qs_list_exists[1],sl_gb_no_on_map[1];
#endif
