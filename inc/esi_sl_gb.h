/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SL_GB.H */
/* *2    23-AUG-1990 17:18:47 PURNA "(SPR 0) compiling error" */
/* *1    23-AUG-1990 17:18:14 PURNA "sl method " */
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_SL_GB.H */
#ifndef ESI_SL_GB_H
#define ESI_SL_GB_H 1

#ifndef ESI_MP_H
#include "esi_mp.h"
#endif

#ifndef ESI_NL_H
#include "esi_nl.h"
#endif

typedef struct sl_gb_rrmap_struct
    {
    MAP_STRUCTURE *map;
    NLIST_HEADER nlist;
    BOOL flag;
    } SL_GB_RRMAP_STRUCT;

#endif
