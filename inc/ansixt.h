/* DEC/CMS REPLACEMENT HISTORY, Element ANSIXT.H */
/* *10    6-AUG-1991 16:58:33 KEE "(SPR -1) fix 5 compile warning error of X dependent file " */
/* *9    16-JUL-1991 14:24:09 SANTIAGO "(SPR -1) last checkin didn't take changes" */
/* *8    16-JUL-1991 14:17:46 SANTIAGO "(SPR -1) fixed errors due to having defined DEC_MOTIF prototypes" */
/* *7     3-MAY-1991 16:21:15 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version" */
/* *6    23-OCT-1990 14:05:53 KEE "(SPR -1) Motif and DecWindow merge" */
/* *5    14-AUG-1990 12:11:48 GILLESPIE "(SPR 2001) Major include file change" */
/* *4     4-MAR-1990 10:24:22 JULIAN "(SPR 6010) Fix ultrix compile errors. " */
/* *3    26-FEB-1990 19:06:23 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)" */
/* *2     6-FEB-1990 00:23:55 JULIAN "(SPR -1) Include file for X" */
/* *1     6-FEB-1990 00:22:12 JULIAN "Xt include file" */
/* DEC/CMS REPLACEMENT HISTORY, Element ANSIXT.H */
/*                                                                                  */
/* * ansiXt.h - C++ interface to the X Intrinsics                                   */
/* *                                                                                */
/* * We must disable C++ keywords that might be used as identifiers in Motif.       */
/* * We must also disable function prototypes, so we can define their argument      */
/* * types later.                                                                   */
/* *                                                                                */
/* * The functions are in man page order, which is roughly alphabetical.            */
/* * Functions which aren't defined in the man pages are put in where it            */
/* * seems sensible.                                                                */
/* *                                                                                */
/*                                                                                  */
#ifdef mips

#define _ansiXt_h

#endif

#ifdef sun

#define _ansiXt_h

#endif

#ifndef _ansiXt_h

#define _ansiXt_h

/*                                                                                  */
/* * Redefine C++ keywords if an including file hasn't already done it              */
/*                                                                                  */

#ifndef _REDEFINEDCLASS

#define _REDEFINEDCLASS     /* so ansiXlib.h won't redefine class */
#define _XTHREDEFINEDCLASS  /* so this file knows to undef class */
#define class CC_class
#define new CC_new
#define delete CC_delete
#define inline CC_inline
#define virtual CC_virtual

#endif /* _REDEFINEDCLASS */

/*                                                                                  */
/* * Redefine Intrinsics Functions                                                  */
/*                                                                                  */

#define XtAddCallback cc_XtAddCallback
#define XtAddCallbacks cc_XtAddCallbacks
#define XtRemoveCallback cc_XtRemoveCallback
#define XtRemoveCallbacks cc_XtRemoveCallbacks
#define XtRemoveAllCallbacks cc_XtRemoveAllCallbacks
#define XtAddEventHandler cc_XtAddEventHandler
#define XtAddRawEventHandler cc_XtAddRawEventHandler
#define XtRemoveEventHandler cc_XtRemoveEventHandler
#define XtRemoveRawEventHandler cc_XtRemoveRawEventHandler
#define XtAddExposureToRegion cc_XtAddExposureToRegion
#define XtAddGrab cc_XtAddGrab
#define XtRemoveGrab cc_XtRemoveGrab
#define XtAppAddActions cc_XtAppAddActions
#define XtAppAddConverter cc_XtAppAddConverter
#define XtAddConverter cc_XtAddConverter
#define XtAppAddInput cc_XtAppAddInput
#define XtRemoveInput cc_XtRemoveInput
#define XtAppAddTimeOut cc_XtAppAddTimeOut
#define XtRemoveTimeOut cc_XtRemoveTimeOut
#define XtAppAddWorkProc cc_XtAppAddWorkProc
#define XtRemoveWorkProc cc_XtRemoveWorkProc
#define XtAppCreateShell cc_XtAppCreateShell
#define XtAppError cc_XtAppError
#define XtAppSetErrorHandler cc_XtAppSetErrorHandler
#define XtAppSetWarningHandler cc_XtAppSetWarningHandler
#define XtAppWarning cc_XtAppWarning
#define XtAppErrorMsg cc_XtAppErrorMsg
#define XtAppSetErrorMsgHandler cc_XtAppSetErrorMsgHandler
#define XtAppSetWarningMsgHandler cc_XtAppSetWarningMsgHandler
#define XtAppWarningMsg cc_XtAppWarningMsg
#define XtAppGetErrorDatabase cc_XtAppGetErrorDatabase
#define XtAppGetErrorDatabaseText cc_XtAppGetErrorDatabaseText
#define XtAppGetSelectionTimeout cc_XtAppGetSelectionTimeout
#define XtAppSetSelectionTimeout cc_XtAppSetSelectionTimeout
#define XtAppNextEvent cc_XtAppNextEvent
#define XtAppPeekEvent cc_XtAppPeekEvent
#define XtAppPending cc_XtAppPending
#define XtAppProcessEvent cc_XtAppProcessEvent
#define XtDispatchEvent cc_XtDispatchEvent
#define XtAppMainLoop cc_XtAppMainLoop
#define XtBuildEventMask cc_XtBuildEventMask
#define XtCallAcceptFocus cc_XtCallAcceptFocus
#define XtCallCallbacks cc_XtCallCallbacks
#define XtHasCallbacks cc_XtHasCallbacks
#define XtClass cc_XtClass
#define XtSuperclass cc_XtSuperclass
#define XtIsSubclass cc_XtIsSubclass
#define XtCheckSubclass cc_XtCheckSubclass
/* #define XtIsComposite cc_XtIsComposite --- macro                                 */
#define XtIsManaged cc_XtIsManaged
#define XtConfigureWidget cc_XtConfigureWidget
#define XtMoveWidget cc_XtMoveWidget
#define XtResizeWidget cc_XtResizeWidget
#define XtResizeWindow cc_XtResizeWindow
#define XtConvert cc_XtConvert
#define XtDirectConvert cc_XtDirectConvert
#define XtCreateApplicationContext cc_XtCreateApplicationContext
#define XtDestroyApplicationContext cc_XtDestroyApplicationContext
#define XtWidgetToApplicationContext cc_XtWidgetToApplicationContext
#define XtToolkitInitialize cc_XtToolkitInitialize
#define XtCreatePopupShell cc_XtCreatePopupShell
#define XtCreateWidget cc_XtCreateWidget
#define XtCreateManagedWidget cc_XtCreateManagedWidget
#define XtDestroyWidget cc_XtDestroyWidget
#define XtInstallAllAcelerators cc_XtInstallAllAcelerators
#define XtInitialize cc_XtInitialize
#define XtCreateWindow cc_XtCreateWindow
#define XtDisplay cc_XtDisplay
#define XtParent cc_XtParent
#define XtScreen cc_XtScreen
#define XtWindow cc_XtWindow
#define XtDisplayInitialize cc_XtDisplayInitialize
#define XtOpenDisplay cc_XtOpenDisplay
#define XtCloseDisplay cc_XtCloseDisplay
#define XtDatabase cc_XtDatabase
#define XtGetGC cc_XtGetGC
#define XtReleaseGC cc_XtReleaseGC
#define XtGetResourceList cc_XtGetResourceList
#define XtGetSelectionValue cc_XtGetSelectionValue
#define XtGetSelectionValues cc_XtGetSelectionValues
#define XtGetSelectionValueIncremental cc_XtGetSelectValueIncremental
#define XtGetSelectionValuesIncremental cc_XtGetSelectValuesIncremental
#define XtGetSubresources cc_XtGetSubresources
#define XtGetApplicationResources cc_XtGetApplicationResources
#define XtMakeGeometryRequest cc_XtMakeGeometryRequest
#define XtMakeResizeRequest cc_XtMakeResizeRequest
#define XtMalloc cc_XtMalloc
#define XtCalloc cc_XtCalloc
#define XtRealloc cc_XtRealloc
#define XtFree cc_XtFree
/* #define XtNewString cc_XtNewString --- macro                                     */

#define XtManageChildren cc_XtManageChildren
#define XtManageChild cc_XtManageChild
#define XtUnmanageChildren cc_XtUnmanageChildren
#define XtUnmanageChild cc_XtUnmanageChild

/* #define XtMapWidget cc_XtMapWidget --- macro                                     */
#define XtSetMappedWhenManaged cc_XtSetMappedWhenManaged
/* #define XtUnmapWidget cc_XtUnmapWidget --- macro                                 */

#define XtNameToWidget cc_XtNameToWidget
#define XtWindowToWidget cc_XtWindowToWidget
#define XtOwnSelection cc_XtOwnSelection
#define XtOwnSelectionIncremental cc_XtOwnSelectionIncremental
#define XtDisownSelection cc_XtDisownSelection
#define XtParseAcceleratorTable cc_XtParseAcceleratorTable
#define XtInstallAccelerators cc_XtInstallAccelerators
#define XtInstallAllAccelerators cc_XtInstallAllAccelerators
#define XtParseTranslationTable cc_XtParseTranslationTable
#define XtAugmentTranslations cc_XtAugmentTranslations
#define XtOverrideTranslations cc_XtOverrideTranslations
#define XtUninstallTranslations cc_XtUninstallTranslations
#define XtPopdown cc_XtPopdown
#define XtCallbackPopdown cc_XtCallbackPopdown
#define MenuPopdown cc_MenuPopdown
#define XtPopup cc_XtPopup
#define XtCallbackNone cc_XtCallbackNone
#define XtCallbackNonexclusive cc_XtCallbackNonexclusive
#define XtCallbackExclusive cc_XtCallbackExclusive
#define MenuPopup cc_MenuPopup
#define XtQueryGeometry cc_XtQueryGeometry
#define XtRealizeWidget cc_XtRealizeWidget
#define XtIsRealized cc_XtIsRealized
#define XtUnrealizeWidget cc_XtUnrealizeWidget

/* #define XtSetArg --- macro                                                       */
#define XtMergeArgLists cc_XtMergeArgLists
#define XtSetKeyboardFocus cc_XtSetKeyboardFocus
#define XtSetKeyTranslator cc_XtSetKeyTranslator
#define XtTranslateKeycode cc_XtTranslateKeycode
#define XtTranslateKey cc_XtTranslateKey
#define XtRegisterCaseConverter cc_XtRegisterCaseConverter
#define XtConvertCase cc_XtConvertCase
#define XtSetSensitive cc_XtSetSensitive
#define XtIsSensitive cc_XtIsSensitive
#define XtSetValues cc_XtSetValues
#define XtSetSubvalues cc_XtSetSubvalues
#define XtGetValues cc_XtGetValues
#define XtGetSubvalues cc_XtGetSubvalues
#define XtStringConversionWarning cc_XtStringConversionWarning
#define XtTranslateCoords cc_XtTranslateCoords

/*                                                                                  */
/* * Include the necessary Xlib and Intrinsics files                                */
/*                                                                                  */

#include "ansixlib.h"
#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Selection.h>
#include <X11/Xatom.h>
#include <X11/Shell.h>

/*                                                                                  */
/* * Undefine all the Intrinsics functions                                          */
/*                                                                                  */

#undef XtAddCallback
#undef XtAddCallbacks
#undef XtRemoveCallback
#undef XtRemoveCallbacks
#undef XtRemoveAllCallbacks
#undef XtAddEventHandler
#undef XtAddRawEventHandler
#undef XtRemoveEventHandler
#undef XtRemoveRawEventHandler
#undef XtAddExposureToRegion
#undef XtAddGrab
#undef XtRemoveGrab
#undef XtAppAddActions
#undef XtAppAddConverter
#undef XtAddConverter
#undef XtAppAddInput
#undef XtRemoveInput
#undef XtAppAddTimeOut
#undef XtRemoveTimeOut
#undef XtAppAddWorkProc
#undef XtRemoveWorkProc
#undef XtAppCreateShell
#undef XtAppError
#undef XtAppSetErrorHandler
#undef XtAppSetWarningHandler
#undef XtAppWarning
#undef XtAppErrorMsg
#undef XtAppSetErrorMsgHandler
#undef XtAppSetWarningMsgHandler
#undef XtAppWarningMsg
#undef XtAppGetErrorDatabase
#undef XtAppGetErrorDatabaseText
#undef XtAppGetSelectionTimeout
#undef XtAppSetSelectionTimeout
#undef XtAppNextEvent
#undef XtAppPeekEvent
#undef XtAppPending
#undef XtAppProcessEvent
#undef XtDispatchEvent
#undef XtAppMainLoop
#undef XtBuildEventMask
#undef XtCallAcceptFocus
#undef XtCallCallbacks
#undef XtHasCallbacks
#undef XtClass
#undef XtSuperclass
#undef XtIsSubclass
#undef XtCheckSubclass
#undef XtIsManaged
#undef XtConfigureWidget
#undef XtMoveWidget
#undef XtResizeWidget
#undef XtResizeWindow
#undef XtConvert
#undef XtDirectConvert
#undef XtCreateApplicationContext
#undef XtDestroyApplicationContext
#undef XtWidgetToApplicationContext
#undef XtToolkitInitialize
#undef XtCreatePopupShell
#undef XtCreateWidget
#undef XtCreateManagedWidget
#undef XtDestroyWidget
#undef XtInstallAllAcelerators
#undef XtInitialize
#undef XtCreateWindow
#undef XtDisplay
#undef XtParent
#undef XtScreen
#undef XtWindow
#undef XtDisplayInitialize
#undef XtOpenDisplay
#undef XtCloseDisplay
#undef XtDatabase
#undef XtGetGC
#undef XtReleaseGC
#undef XtGetResourceList
#undef XtGetSelectionValue
#undef XtGetSelectionValues
#undef XtGetSelectionValueIncremental
#undef XtGetSelectionValuesIncremental
#undef XtGetSubresources
#undef XtGetApplicationResources
#undef XtMakeGeometryRequest
#undef XtMakeResizeRequest
#undef XtMalloc
#undef XtCalloc
#undef XtRealloc
#undef XtFree
#undef XtManageChildren
#undef XtManageChild
#undef XtUnmanageChildren
#undef XtUnmanageChild
#undef XtSetMappedWhenManaged
#undef XtNameToWidget
#undef XtWindowToWidget
#undef XtOwnSelection
#undef XtOwnSelectionIncremental
#undef XtDisownSelection
#undef XtParseAcceleratorTable
#undef XtInstallAccelerators
#undef XtInstallAllAccelerators
#undef XtParseTranslationTable
#undef XtAugmentTranslations
#undef XtOverrideTranslations
#undef XtUninstallTranslations
#undef XtPopdown
#undef XtCallbackPopdown
#undef MenuPopdown
#undef XtPopup
#undef XtCallbackNone
#undef XtCallbackNonexclusive
#undef XtCallbackExclusive
#undef MenuPopup
#undef XtQueryGeometry
#undef XtRealizeWidget
#undef XtIsRealized
#undef XtUnrealizeWidget

/* #undef XtSetArg                                                                  */
#undef XtMergeArgLists
#undef XtSetKeyboardFocus
#undef XtSetKeyTranslator
#undef XtTranslateKeycode
#undef XtTranslateKey
#undef XtRegisterCaseConverter
#undef XtConvertCase
#undef XtSetSensitive
#undef XtIsSensitive
#undef XtSetValues
#undef XtSetSubvalues
#undef XtGetValues
#undef XtGetSubvalues
#undef XtStringConversionWarning
#undef XtTranslateCoords

/*                                                                                  */
/* * Undefine C++ keywords and other various #define's if they were                 */
/* * originally #define'd in this file.                                             */
/*                                                                                  */

#ifdef _XTHREDEFINEDCLASS

#undef class
#undef new
#undef delete
#undef inline
#undef virtual
#undef _XTHREDEFINEDCLASS
#undef _REDEFINEDCLASS

#endif /* _XTHREDEFINEDCLASS */

/*                                                                                  */
/* * Xt function prototypes with arguments specified                                */
/*                                                                                  */

void XtAddCallback (Widget, String, XtCallbackProc, caddr_t);
void XtAddCallbacks (Widget, String, XtCallbackList);
void XtRemoveCallback (Widget, String, XtCallbackProc, caddr_t);
void XtRemoveCallbacks (Widget, String, XtCallbackList);
void XtRemoveAllCallbacks (Widget, String);

void XtAddEventHandler (Widget, EventMask, Boolean, XtEventHandler, caddr_t);
void XtAddRawEventHandler (Widget, EventMask, Boolean, XtEventHandler, caddr_t);
void XtRemoveEventHandler (Widget, EventMask, Boolean, XtEventHandler, caddr_t);
void XtRemoveRawEventHandler (Widget, EventMask, Boolean, XtEventHandler, caddr_t);

void XtAddExposureToRegion (XEvent *, Region);

void XtAddGrab (Widget, Boolean, Boolean);
void XtRemoveGrab (Widget);

void XtAppAddActions (XtAppContext, XtActionList, Cardinal);

void XtAppAddConverter (XtAppContext, String, String, XtConverter, XtConvertArgList,
                        Cardinal);
void XtAddConverter (String, String, XtConverter, XtConvertArgList, Cardinal);

XtInputId XtAppAddInput (XtAppContext, int , caddr_t, XtInputCallbackProc, caddr_t);
void XtRemoveInput (XtInputId);

XtIntervalId XtAppAddTimeOut (XtAppContext, unsigned long , XtTimerCallbackProc,
                              caddr_t);
void XtRemoveTimeOut (XtIntervalId);

XtWorkProcId XtAppAddWorkProc (XtAppContext, XtWorkProc, caddr_t);
void XtRemoveWorkProc (XtWorkProcId);

Widget XtAppCreateShell (String, String, WidgetClass, Display *, ArgList, Cardinal);

void XtAppError (XtAppContext, String);
void XtAppWarning (XtAppContext, String);
void XtAppErrorMsg (XtAppContext, String, String, String, String, String *,
                    Cardinal *);
void XtAppWarningMsg (XtAppContext, String, String, String, String, String *,
                      Cardinal *);

XrmDatabase *XtAppGetErrorDatabase (XtAppContext);
void XtAppGetErrorDatabaseText (XtAppContext, char *, char *, char *, char *, char *,
                                int , XrmDatabase);

unsigned long XtAppGetSelectionTimeout (XtAppContext);
void XtAppSetSelectionTimeout (XtAppContext, unsigned long);

void XtAppNextEvent (XtAppContext, XEvent *);
Boolean XtAppPeekEvent (XtAppContext, XEvent *);
XtInputMask XtAppPending (XtAppContext);
void XtAppProcessEvent (XtAppContext, XtInputMask);
void XtAppMainLoop (XtAppContext);

EventMask XtBuildEventMask (Widget);

Boolean XtCallAcceptFocus (Widget, Time *);

void XtCallCallbacks (Widget, String, caddr_t);
XtCallbackStatus XtHasCallbacks (Widget, String);

WidgetClass XtClass (Widget);
WidgetClass XtSuperclass (Widget);
Boolean XtIsSubclass (Widget, WidgetClass);
void XtCheckSubclass (Widget, WidgetClass, String);
Boolean XtIsManaged (Widget);

void XtConfigureWidget (Widget, Position, Position, Dimension, Dimension, Dimension);
void XtMoveWidget (Widget, Position, Position);
void XtResizeWidget (Widget, Dimension, Dimension, Dimension);
void XtResizeWindow (Widget);

void XtConvert (Widget, String, XrmValuePtr, String, XrmValuePtr);
void XtDirectConvert (XtConverter, XrmValuePtr, Cardinal, XrmValuePtr, XrmValuePtr);

XtAppContext XtCreateApplicationContext ();
void XtDestroyApplicationContext (XtAppContext);
XtAppContext XtWidgetToApplicationContext (Widget);
void XtToolkitInitialize ();

Widget XtCreatePopupShell (String, WidgetClass, Widget, ArgList, Cardinal);

Widget XtCreateWidget (String, WidgetClass, Widget, ArgList, Cardinal);
Widget XtCreateManagedWidget (String, WidgetClass, Widget, ArgList, Cardinal);
void XtInstallAllAccelerators (Widget, Widget);
Widget XtInitialize (String, String, XrmOptionDescRec *, Cardinal, Cardinal *,
                     char **);
void XtDestroyWidget (Widget);

void XtCreateWindow (Widget, unsigned int , Visual *, XtValueMask,
                     XSetWindowAttributes *);

Display *XtDisplay (Widget);
Widget XtParent (Widget);
Screen *XtScreen (Widget);
Window XtWindow (Widget);

void XtDisplayInitialize (XtAppContext, Display *, String, String, XrmOptionDescRec *,
                          Cardinal, Cardinal *, String *);
Display *XtOpenDisplay (XtAppContext, String, String, String, XrmOptionDescRec *,
                        Cardinal, Cardinal *, String *);
void XtCloseDisplay (Display *);
XrmDatabase XtDatabase (Display *);

GC XtGetGC (Widget, XtGCMask, XGCValues *);
void XtReleaseGC (Widget, GC);

void XtGetResourceList (WidgetClass, XtResourceList *, Cardinal *);

void XtGetSelectionValue (Widget, Atom, Atom, XtSelectionCallbackProc, caddr_t, Time);
void XtGetSelectionValues (Widget, Atom, Atom *, int , XtSelectionCallbackProc,
                           caddr_t, Time);
void XtGetSelectionValueIncremental (Widget, Atom, Atom, XtSelectionCallbackProc,
                                     XtSelectionCallbackProc, caddr_t, Time);
void XtGetSelectionValuesIncremental (Widget, Atom, Atom *, int ,
                                      XtSelectionCallbackProc, XtSelectionCallbackProc,
                                      caddr_t, Time);

void XtGetSubresources (Widget, caddr_t, String, String, XtResourceList, Cardinal,
                        ArgList, Cardinal);
void XtGetApplicationResources (Widget, caddr_t, XtResourceList, Cardinal, ArgList,
                                Cardinal);

XtGeometryResult XtMakeGeometryRequest (Widget, XtWidgetGeometry *,
                                        XtWidgetGeometry *);
XtGeometryResult XtMakeResizeRequest (Widget, Dimension, Dimension, Dimension *,
                                      Dimension *);

char *XtMalloc (Cardinal);
char *XtCalloc (Cardinal, Cardinal);
char *XtRealloc (char *, Cardinal);
void XtFree (char *);

void XtManageChildren (WidgetList, Cardinal);
void XtManageChild (Widget);
void XtUnmanageChildren (WidgetList, Cardinal);
void XtUnmanageChild (Widget);

void XtSetMappedWhenManaged (Widget, Boolean);

Widget XtNameToWidget (Widget, String);
Widget XtWindowToWidget (Display *, Window);

Boolean XtOwnSelection (Widget, Atom, Time, XtSelectionCallbackProc,
                        XtSelectionCallbackProc, XtSelectionCallbackProc);
Boolean XtOwnSelectionIncremental (Widget, Atom, Time, XtSelectionCallbackProc,
                                   XtSelectionCallbackProc, XtSelectionCallbackProc,
                                   XtSelectionCallbackProc, caddr_t);
void XtDisownSelection (Widget, Atom, Time);

XtAccelerators XtParseAcceleratorTable (String);
void XtInstallAccelerators (Widget, Widget);
void XtInstallAllAccelerators (Widget, Widget);

XtTranslations XtParseTranslationTable (String);
void XtAugmentTranslations (Widget, XtTranslations);
void XtOverrideTranslations (Widget, XtTranslations);
void XtUninstallTranslations (Widget);

void XtPopdown (Widget);
void XtCallbackPopdown (Widget, caddr_t, caddr_t);
void MenuPopdown (String);

void XtPopup (Widget, XtGrabKind);
void XtCallbackNone (Widget, caddr_t, caddr_t);
void XtCallbackNonexclusive (Widget, caddr_t, caddr_t);
void XtCallbackExclusive (Widget, caddr_t, caddr_t);
void MenuPopup (String);

XtGeometryResult XtQueryGeometry (Widget, XtWidgetGeometry);

void XtRealizeWidget (Widget);
Boolean XtIsRealized (Widget);
void XtUnrealizeWidget (Widget);

/* void XtSetArg( Arg, String, XtArgVal);                                           */
ArgList XtMergeArgLists (ArgList, Cardinal, ArgList, Cardinal);

void XtSetKeyboardFocus (Widget, Widget);

void XtSetKeyTranslator (Display *, XtKeyProc);
void XtTranslateKeycode (Display *, KeyCode, Modifiers, Modifiers *, KeySym *);
void XtTranslateKey (Display *, KeyCode *, Modifiers *, Modifiers *, KeySym *);
void XtRegisterCaseConverter (Display *, XtCaseProc, KeySym, KeySym);
void XtConvertCase (Display *, KeySym, KeySym *, KeySym *);

void XtSetSensitive (Widget, Boolean);
Boolean XtIsSensitive (Widget);

void XtSetValues (Widget, ArgList, Cardinal);
void XtSetSubvalues (caddr_t, XtResourceList, Cardinal, ArgList, Cardinal);
void XtGetValues (Widget, ArgList, Cardinal);
void XtGetSubvalues (caddr_t, XtResourceList, Cardinal, ArgList, Cardinal);

void XtStringConversionWarning (String, String);

void XtTranslateCoords (Widget, Position, Position, Position *, Position *);

XtErrorHandler XtAppSetErrorHandler (XtAppContext, XtErrorHandler);
XtErrorHandler XtAppSetWarningHandler (XtAppContext, XtErrorHandler);
XtErrorMsgHandler XtAppSetErrorMsgHandler (XtAppContext, XtErrorMsgHandler);
XtErrorMsgHandler XtAppSetWarningMsgHandler (XtAppContext, XtErrorMsgHandler);
Boolean XtDispatchEvent (XEvent *);

#endif /* _ansiXt_h */
