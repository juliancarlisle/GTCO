/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LOGNODE.H*/
/* *2    14-AUG-1990 11:49:04 GILLESPIE "(SPR 2001) Major realignment of include files"*/
/* *1    30-JUN-1989 15:02:39 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_LOGNODE.H*/
#ifndef ESI_DTYPES_H
#include "esi_dtypes.h"
#endif

/* ESI_LOGNODE.H -- Header file for logical name process on Prime and UNIX machines */

struct lognode 
	{
	struct lognode *next;
	TCP tcp;
	char log_name[1];
	};
