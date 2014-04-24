/* DEC/CMS REPLACEMENT HISTORY, Element ESI_FI_INT.H*/
/* *5     5-AUG-1991 16:48:30 JTM "(SPR 0) Extened FINDER_MENU_STRUCT to handle beta item logical names."*/
/* *4    27-NOV-1989 13:05:47 GORDON "(SPR 0) Add define of NULL_MENU_ID"*/
/* *3    18-NOV-1989 09:41:59 GILLESPIE "(SPR 5075) Global overhaul"*/
/* *2    28-JUL-1989 15:33:46 GORDON "(SPR 101) Added nowait menu types, redefine MAX_MENU"*/
/* *1    30-JUN-1989 15:00:27 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_FI_INT.H*/
/*************************************************************************

NAME:   ESI_FI_INT.H

DESCRIPTION:

    Internals for FI.

*************************************************************************/

#ifndef ESI_FI_INT_H
#define ESI_FI_INT_H 1

#ifndef ESI_FI_H
#include "esi_fi.h"
#endif

#include "setjmp.h"

typedef struct {
    INT finder_dialog_id;         /* Finder dialog id */
    INT fi_push_level;            /* Push depth */
    } FINDER_WORKSPACE;

typedef enum                      /* menu item type */
    {
    Undefined,
    MenuName,
    NextMenu,
    EventsFunction,
    NoEventsFunction,
    ProgramName,
    CPName,
    CommandName,
    ProgramNowait,
    CPNowait
    } MenuType;

typedef struct                 /* menu item */
    {
    INT  id;            /* Menu item ID number     */
    INT  item;          /* Item number within menu */
    INT  flag;          /* enable/disable flag     */
    CHAR *Name;         /* Menu name or Menu entry */
    MenuType Type;      /* Activation event type   */
    struct
	 {
	 INT (*AppEntry)(); /* Next function address */
	 INT menu;          /* Next Menu Entry       */
	 CHAR *pointer;     /* a normal char pointer */
	 } Activates;
    CHAR *AppName;      /* application name or command procedure */
    CHAR *BetaLogical;   /* logical name needed to turn this item on*/
    } FINDER_MENU_STRUCT;

#define MAX_MENU 256  /* max number of menu entries in user add-on menu */
#define NULL_MENU_ID -1
typedef struct {
    jmp_buf event_env;
    } FIV;

#if USE_PROTOTYPES

extern INT fi_init_menus(void);
extern INT fi_menu_server(INT id, INT item, BYTE *ptr);
extern INT fi_start_app(FINDER_MENU_STRUCT *pm);
extern INT fi_sync_mn(INT menu);
extern INT fi_sync_smn(INT menu1, INT menu2);

extern INT fih_query_menu_function(INT *menuid, INT *itemid, INT (*function)());
extern INT fih_query_menu_helpkey (INT menuid, INT itemid, CHAR *help_key);
extern INT fih_start_application (FINDER_MENU_STRUCT *pm);

extern FIV *fiz_static(void);
extern INT fiz_vms_cond();
extern VOID fiz_onunit();
extern FINDER_MENU_STRUCT *fiz_finder_menus(void);

#else

extern INT fi_init_menus();
extern INT fi_menu_server();
extern INT fi_start_app();
extern INT fi_sync_mn();
extern INT fi_sync_smn();

extern INT fih_query_menu_function ();
extern INT fih_query_menu_helpkey ();
extern INT fih_start_application ();

extern FIV *fiz_static();
extern INT fiz_vms_cond();
extern VOID fiz_onunit();
extern FINDER_MENU_STRUCT *fiz_finder_menus();

#endif

#endif
                                                                                                           
