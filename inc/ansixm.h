/* DEC/CMS REPLACEMENT HISTORY, Element ANSIXM.H */
/* *3     3-MAY-1991 16:21:11 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version" */
/* *2    23-OCT-1990 14:05:50 KEE "(SPR -1) Motif and DecWindow merge" */
/* *1    23-OCT-1990 14:04:54 KEE "Motit Xm call include file" */
/* DEC/CMS REPLACEMENT HISTORY, Element ANSIXM.H */

#if USE_PROTOTYPES

#ifdef vms 
#ifndef DEC_MOTIF
#define DEC_MOTIF 1
#endif
#endif /* vms */

#if DEC_MOTIF
extern Widget XmCreateForm (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateBulletinBoard (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateBulletinBoardDialog (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateCascadeButton (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateFrame (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateLabelGadget (Widget, char *, Arg *, int);
extern Widget XmCreateMainWindow (Widget, char *, ArgList, int);
extern Widget XmCreateMenuBar (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateMenuShell (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateOptionMenu (Widget, char *, ArgList, Cardinal);
extern Widget XmCreatePopupMenu (Widget, char *, ArgList, Cardinal);
extern Widget XmCreatePulldownMenu (Widget, char *, ArgList, Cardinal);
extern Widget XmCreatePushButton (Widget, char *, ArgList, Cardinal);
extern Widget XmCreatePushButtonGadget (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateRadioBox (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateRowColumn (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateScale (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateScrollBar (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateScrolledList (Widget, char *, ArgList, int);
extern Widget XmCreateScrolledText (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateSeparatorGadget (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateText (Widget, char *, ArgList, Cardinal);
extern Widget XmCreateToggleButton (Widget, char *, Arg *, int);
extern Widget XmCreateToggleButtonGadget (Widget, char *, Arg *, int);
extern Widget XmCreateWarningDialog (Widget, char *, ArgList, Cardinal);
extern Boolean XmStringGetNextSegment (XmStringContext , char **, XmStringCharSet *,
                                       XmStringDirection *, Boolean *);
extern void XmStringFreeContext (XmStringContext);
#else
extern Widget XmCreateBulletinBoard (Widget, String, ArgList, Cardinal);
extern Widget XmCreateBulletinBoardDialog (Widget, String, ArgList, Cardinal);
extern Widget XmCreateCascadeButton (Widget, String, ArgList, Cardinal);
extern Widget XmCreateFrame (Widget, String, ArgList, Cardinal);
extern Widget XmCreateLabelGadget (Widget, String, ArgList, Cardinal);
extern Widget XmCreateMainWindow (Widget, String, ArgList, Cardinal);
extern Widget XmCreateMenuBar (Widget, String, ArgList, Cardinal);
extern Widget XmCreateMenuShell (Widget, String, ArgList, Cardinal);
extern Widget XmCreateOptionMenu (Widget, String, ArgList, Cardinal);
extern Widget XmCreatePopupMenu (Widget, String, ArgList, Cardinal);
extern Widget XmCreatePulldownMenu (Widget, String, ArgList, Cardinal);
extern Widget XmCreatePushButton (Widget, String, ArgList, Cardinal);
extern Widget XmCreatePushButtonGadget (Widget, String, ArgList, Cardinal);
extern Widget XmCreateRadioBox (Widget, String, ArgList, Cardinal);
extern Widget XmCreateRowColumn (Widget, String, ArgList, Cardinal);
extern Widget XmCreateScale (Widget, String, ArgList, Cardinal);
extern Widget XmCreateScrollBar (Widget, String, ArgList, Cardinal);
extern Widget XmCreateScrolledList (Widget, String, ArgList, Cardinal);
extern Widget XmCreateScrolledText (Widget, String, ArgList, Cardinal);
extern Widget XmCreateSeparatorGadget (Widget, String, ArgList, Cardinal);
extern Widget XmCreateText (Widget, String, ArgList, Cardinal);
extern Widget XmCreateToggleButton (Widget, String, ArgList, Cardinal);
extern Widget XmCreateToggleButtonGadget (Widget, String, ArgList, Cardinal);
extern Widget XmCreateWarningDialog (Widget, String, ArgList, Cardinal);
extern Boolean XmStringGetNextSegment (XmStringContext *, char *, XmStringCharSet *,
                                       XmStringDirection *, Boolean *);
extern void XmStringFreeContext (XmStringContext *);
#endif
extern XmFontList XmFontListCreate (XFontStruct *, XmStringCharSet);
extern void XmListAddItem (Widget, XmString, int);
extern void XmListDeletePos (Widget, int);
extern void XmListDeselectAllItems (Widget);
extern void XmListDeselectPos (Widget, int);
extern void XmListSelectPos (Widget, int , Boolean);
extern void XmScaleSetValue (Widget, int);
extern void XmScrollBarGetValues (Widget, int *, int *, int *, int *);
extern void XmScrollBarSetValues (Widget, int , int , int , int , Boolean);
extern XmString XmStringCreate (char *, XmStringCharSet);
extern Boolean XmStringInitContext (XmStringContext *, XmString);
extern void XmStringFree (XmString);
extern void XmTextClearSelection (Widget, Time);
extern char *XmTextGetSelection (Widget);
extern char *XmTextGetString (Widget);
extern void XmTextSetMaxLength (Widget, int);
extern void XmTextSetSelection (Widget, long , long , Time);
extern void XmTextSetString (Widget, char *);
extern void XmToggleButtonSetState (Widget, Boolean, Boolean);

#else
extern Boolean XmStringGetNextSegment ();
extern Boolean XmStringInitContext ();
extern Widget XmCreateForm ();
extern Widget XmCreateBulletinBoard ();
extern Widget XmCreateBulletinBoardDialog ();
extern Widget XmCreateCascadeButton ();
extern Widget XmCreateFrame ();
extern Widget XmCreateLabelGadget ();
extern Widget XmCreateMainWindow ();
extern Widget XmCreateMenuBar ();
extern Widget XmCreateMenuShell ();
extern Widget XmCreateOptionMenu ();
extern Widget XmCreatePopupMenu ();
extern Widget XmCreatePulldownMenu ();
extern Widget XmCreatePushButton ();
extern Widget XmCreatePushButtonGadget ();
extern Widget XmCreatePushButtonGadget ();
extern Widget XmCreateRadioBox ();
extern Widget XmCreateRowColumn ();
extern Widget XmCreateScale ();
extern Widget XmCreateScrollBar ();
extern Widget XmCreateScrolledList ();
extern Widget XmCreateScrolledText ();
extern Widget XmCreateSeparatorGadget ();
extern Widget XmCreateText ();
extern Widget XmCreateToggleButton ();
extern Widget XmCreateToggleButtonGadget ();
extern Widget XmCreateWarningDialog ();
extern XmFontList XmFontListCreate ();
extern XmString XmStringCreate ();
extern void XmStringFreeContext ();
extern void XmStringFree ();
extern char *XmTextGetSelection ();
extern char *XmTextGetString ();
extern void XmListAddItem ();
extern void XmListDeletePos ();
extern void XmListDeselectAllItems ();
extern void XmListDeselectPos ();
extern void XmListSelectPos ();
extern void XmScaleSetValue ();
extern void XmScrollBarGetValues ();
extern void XmScrollBarSetValues ();
extern void XmTextClearSelection ();
extern void XmTextSetMaxLength ();
extern void XmTextSetSelection ();
extern void XmTextSetString ();
extern void XmToggleButtonSetState ();

#endif
