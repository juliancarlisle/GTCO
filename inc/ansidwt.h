/* DEC/CMS REPLACEMENT HISTORY, Element ANSIDWT.H */
/* *6    14-AUG-1990 12:11:33 GILLESPIE "(SPR 2001) Major include file change" */
/* *5     4-MAR-1990 12:24:50 JULIAN "(SPR 6010) Fix proto problem on ULTRIXR" */
/* *4     4-MAR-1990 10:25:41 JULIAN "(SPR 6010) Fix ultrix compile errors. " */
/* *3    26-FEB-1990 19:06:14 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)" */
/* *2     6-FEB-1990 00:23:41 JULIAN "(SPR -1) Include file for X" */
/* *1     6-FEB-1990 00:21:49 JULIAN "Dwt include file" */
/* DEC/CMS REPLACEMENT HISTORY, Element ANSIDWT.H */
#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif

#if USE_PROTOTYPES
extern Widget DwtMainWindowCreate(Widget, char *, ArgList, int);
extern Widget DwtCautionBoxCreate(Widget, char *, ArgList, int);
extern Widget DwtMenuBarCreate(Widget, char *, ArgList, int);
extern DwtCompString DwtLatin1String(char *);
extern DwtFontList DwtCreateFontList(XFontStruct *, long);
extern Widget DwtDialogBoxCreate(Widget, char *, ArgList, int);
extern Widget DwtDialogBoxPopupCreate(Widget, char *, ArgList, int);
extern int DwtGetNextSegment(DwtCompStringContext *, char *, long *,
	Boolean *, long *, long *);
extern int DwtInitGetSegment(DwtCompStringContext *, DwtCompString);
extern void DwtListBoxAddItem(Widget,DwtCompString, int);
extern Widget DwtListBoxCreate(Widget, char *, ArgList, int);
extern void DwtListBoxDeletePos(Widget, int);
extern void DwtListBoxDeselectAllItems(Widget);
extern void DwtListBoxDeselectPos(Widget, int);
extern void DwtListBoxSelectPos(Widget, int, Boolean);
extern Widget DwtMenuPulldownCreate (Widget, char *, ArgList, int);
extern Widget DwtPullDownMenuEntryCreate(Widget, char *, ArgList, int);
extern Widget DwtPushButtonCreate(Widget, char *, ArgList, int);
extern Widget DwtRadioBoxCreate(Widget, char *, ArgList, int);
extern void DwtSTextClearSelection(Widget,Time);
extern Widget DwtSTextCreate (Widget, char *, ArgList, int);
extern char *DwtSTextGetSelection(Widget);
extern char *DwtSTextGetString(Widget);
extern void DwtSTextSetMaxLength(Widget, int);
extern void DwtSTextSetSelection(Widget, int, int, Time);
extern void DwtSTextSetString(Widget,char *);
extern Widget DwtScaleCreate(Widget, char *, ArgList, int);
extern void DwtScaleSetSlider(Widget, int);
extern Widget DwtScrollBarCreate(Widget, char *, ArgList, int);
extern void DwtScrollBarGetSlider(Widget, int*, int*, int*, int*);
extern void DwtScrollBarSetSlider(Widget, int, int, int, int, Boolean);
extern Widget DwtSeparatorGadgetCreate(Widget, char *, ArgList, int);
extern Widget DwtToggleButtonCreate(Widget, char *, ArgList, int);
extern void DwtToggleButtonSetState(Widget, Boolean, Boolean);
#else
extern Widget DwtMainWindowCreate();
extern Widget DwtCautionBoxCreate();
extern Widget DwtMenuBarCreate();
extern DwtCompString DwtLatin1String();
extern DwtFontList DwtCreateFontList();
extern Widget DwtDialogBoxCreate();
extern Widget DwtDialogBoxPopupCreate();
extern int DwtGetNextSegment();
extern int DwtInitGetSegment();
extern void DwtListBoxAddItem();
extern Widget DwtListBoxCreate();
extern void DwtListBoxDeletePos();
extern void DwtListBoxDeselectAllItems();
extern void DwtListBoxDeselectPos();
extern void DwtListBoxSelectPos();
extern Widget DwtMenuPulldownCreate ();
extern Widget DwtPullDownMenuEntryCreate();
extern Widget DwtPushButtonCreate();
extern Widget DwtRadioBoxCreate();
extern void DwtSTextClearSelection();
extern Widget DwtSTextCreate ();
extern char *DwtSTextGetSelection();
extern char *DwtSTextGetString();
extern void DwtSTextSetMaxLength();
extern void DwtSTextSetSelection();
extern void DwtSTextSetString();
extern Widget DwtScaleCreate();
extern void DwtScaleSetSlider();
extern Widget DwtScrollBarCreate();
extern void DwtScrollBarGetSlider();
extern void DwtScrollBarSetSlider();
extern Widget DwtSeparatorGadgetCreate();
extern Widget DwtToggleButtonCreate();
extern void DwtToggleButtonSetState();

#endif
