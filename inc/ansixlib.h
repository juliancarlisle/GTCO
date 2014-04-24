/* DEC/CMS REPLACEMENT HISTORY, Element ANSIXLIB.H */
/* *6     3-MAY-1991 16:21:05 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version" */
/* *5    14-AUG-1990 12:11:43 GILLESPIE "(SPR 2001) Major include file change" */
/* *4     4-MAR-1990 10:25:52 JULIAN "(SPR 6010) Fix ultrix compile errors. " */
/* *3    26-FEB-1990 19:06:18 JULIAN "(SPR 6010) Port to Decstation 3100 (ULTRIX)" */
/* *2     6-FEB-1990 00:23:47 JULIAN "(SPR -1) Include file for X" */
/* *1     6-FEB-1990 00:21:20 JULIAN "Xlib include file" */
/* DEC/CMS REPLACEMENT HISTORY, Element ANSIXLIB.H */
/*
 * ansiXlib.h - C++ interface to Xlib level headers (Xlib.h and Xutil.h)
 *
 * We must disable C++ keywords that might be used as identifiers
 * in Xlib.h and Xutil.h.  We also must disable function prototypes
 * so we can define their argument types later.
 *
 */

#ifndef ansiXlib_h
#define ansiXlib_h


/*
 * include actual X header files
 */

#ifndef _XLIB_H_
#include <X11/Xlib.h>
#endif
#ifndef _XUTIL_H_
#include <X11/Xutil.h>
#endif

#ifndef ESI_GL_DEFS_H
#include "esi_gl_defs.h"
#endif
/*
 * Xlib function prototypes with arguments specified
 */
#if USE_PROTOTYPES

#ifdef vms 
#ifndef DEC_MOTIF
#define DEC_MOTIF 1
#endif
#endif /* vms */

#if DEC_MOTIF
Status XGetSizeHints(Display*, Window, XSizeHints*, Atom);
#else
void XGetSizeHints(Display*, Window, XSizeHints*, Atom);
#endif
void XSetSizeHints(Display*, Window, XSizeHints*, Atom);

int XSaveContext(Window, XContext, caddr_t);
int XFindContext(Display*, Window, XContext, caddr_t *);
int XDeleteContext(Window, XContext);

int XParseGeometry(char*, int*, int*, int*, int*);

void XSetWMHints(Display*, Window, XWMHints*);
XWMHints* XGetWMHints(Display*, Window);

void XSetTransientForHint(Display*, Window, Window);
Status XGetTransientForHint(Display*, Window, Window*);

Region XCreateRegion(void);
Region XPolygonRegion(XPoint points[], int, int);

XImage* XCreateImage( Display*, Visual*, int, int, int,
		      void*, int, int, int, int);
void XPutImage( Display*, Drawable, GC, XImage*, int, int,
		int, int, unsigned int, unsigned int);
XImage* XGetImage( Display*, Drawable, int, int,
		unsigned int, unsigned int,
		unsigned long, int);

Display* XOpenDisplay(const char*);
char* XDisplayName(char*);
void XCloseDisplay(Display*);

char* XGetDefault(Display*, const char* prog, const char* param);
Atom XInternAtom(Display*, char*, int);
Colormap* XListInstalledColormaps();
char* XGetAtomName(Display*, Atom);

void XSetScreenSaver(
    Display*, int timeout, int interval, int blanking, int exposures
);
void XForceScreenSaver(Display*, int mode);
void XActivateScreenSaver(Display*);
void XResetScreenSaver(Display*);
void XGetScreenSaver(
    Display*, int* timeout, int* interval, int* blanking, int* exposures
);

void XAddHost(Display*, XHostAddress*);
void XAddHosts(Display*, XHostAddress[], int);
XHostAddress* XListHosts(Display*, int* n, Bool*);
void XRemoveHost(Display*, XHostAddress*);
void XRemoveHosts(Display*, XHostAddress[], int);

Window XCreateWindow(
    Display*, Window parent, int x, int y,
    unsigned int width, unsigned int height,
    unsigned int bwidth, unsigned int depth,
    unsigned int window_class, Visual*, unsigned int, XSetWindowAttributes*
);
Window XCreateSimpleWindow(
    Display*, Window, int x, int y,
    unsigned int width, unsigned int height, unsigned int bwidth,
    unsigned long border, unsigned long background
);
void XDestroyWindow(Display*, Window);
void XDestroySubwindows(Display*, Window);
void XMapWindow(Display*, Window);
void XMapRaised(Display*, Window);
void XMapSubwindows(Display*, Window);
void XUnmapWindow(Display*, Window);
void XUnmapSubwindows(Display*, Window);
void XConfigureWindow(Display*, Window, unsigned int, XWindowChanges*);
void XMoveWindow(Display*, Window, int x, int y);
void XResizeWindow(
    Display*, Window, unsigned int width, unsigned int height
);
void XMoveResizeWindow(
    Display*, Window, int x, int y, unsigned int width, unsigned int height
);
void XSetWindowBorderWidth(Display*, Window, unsigned int width);
void XRaiseWindow(Display*, Window);
void XLowerWindow(Display*, Window);
void XCirculateSubwindows(Display*, Window, int direction);
void XCirculateSubwindowsUp(Display*, Window);
void XCirculateSubwindwosDown(Display*, Window);
void XRestackWindows(Display*, Window[], int nwindows);
void XChangeWindowAttributes(
    Display*, Window, unsigned int, XSetWindowAttributes*
);
void XSetWindowBackground(Display*, Window, unsigned long);
void XSetWindowBackgroundPixmap(Display*, Window, Pixmap);
void XSetWindowBorder(Display*, Window, unsigned long);
void XSetWindowBorderPixmap(Display*, Window, Pixmap);

Cursor XCreateFontCursor(Display*, int shape);
Cursor XCreatePixmapCursor(
    Display*, Pixmap src, Pixmap mask, XColor* fg, XColor* bg, int x, int y
);
Cursor XCreateGlyphCursor(
    Display*, Font src, Font mask, unsigned int schar, unsigned int mchar,
    XColor* fg, XColor* bg
);
void XRecolorCursor(Display*, Cursor, XColor* fg, XColor* bg);
void XFreeCursor(Display*, Cursor);
void XQueryBestCursor(
    Display*, Drawable, unsigned int width, unsigned int height,
    unsigned int* rwidth, unsigned int* rheight
);
void XDefineCursor(Display*, Window, Cursor);
void XUndefineCursor(Display*, Window);

Status XQueryTree(
    Display*, Window, Window* root, Window* parent,
    Window** children, int* nchildren
);
Status XGetWindowAttributes(Display*, Window, XWindowAttributes*);
Status XGetGeometry(
    Display*, Drawable, Drawable* root, int* x, int* y,
    unsigned int* width, unsigned int* height,
    unsigned int* bwidth, unsigned int* depth
);
int XTranslateCoordinates(
    Display*, Window src, Window dst, int srcx, int srcy,
    int* dstx, int* dsty, Window* child
);

int XGetWindowProperty(
    Display*, Window, Atom, long offset, long len, Bool del,
    Atom req_type, Atom* actual_type, int* actual_format, unsigned long* n,
    long* bytes_after, unsigned char** prop
);
Atom* XListProperties(Display*, Window, int* nprop);
void XChangeProperty(
    Display*, Window, Atom prop, Atom type, int format, int mode,
    unsigned char* data, int nelements
);
void XRotateWindowProperties(Display*, Window, Atom[], int n, int npos);
void XDeleteProperty(Display*, Window, Atom);

void XSetSelectionOwner(Display*, Atom, Window, Time);
Window XGetSelectionOwner(Display*, Atom);
void XConvertSelection(
    Display*, Atom selection, Atom target, Atom prop,
    Window requestor, Time
);

void XStoreName(Display*, Window, const char*);
Status XFetchName(Display*, Window, char**);
void XSetIconName(Display*, Window, char*);
Status XGetIconName(Display*, Window, char**);
void XSetCommand(Display*, Window, char* argv[], int argc);

Colormap XCreateColormap(Display*, Window, Visual*, int alloc);
Colormap XCopyColormapAndFree(Display*, Colormap);
void XFreeColormap(Display*, Colormap);
void XSetWindowColormap(Display*, Window, Colormap);
Status XAllocColor(Display*, Colormap, XColor*);
Status XAllocNamedColor(Display*, Colormap, const char*, XColor*, XColor*);
Status XLookupColor(Display*, Colormap, const char*, XColor*, XColor*);
void XStoreColors(Display*, Colormap, XColor[], int);
void XStoreColor(Display*, Colormap, XColor*);
Status XAllocColorCells(
    Display*, Colormap, Bool, unsigned long plane[], unsigned long nplanes,
    unsigned long[], unsigned long npixels
);
Status XAllocColorPlanes(
    Display*, Colormap, Bool, unsigned long[], unsigned long npixels,
    int nreds, int ngreens, int nblues,
    unsigned long* rmask, unsigned long* gmask, unsigned long* bmask
);
void XStoreNamedColor(Display*, Colormap, const char*, unsigned long, int);
void XFreeColors(
    Display*, Colormap, unsigned long[], int, unsigned long nplanes
);
Status XQueryColor(Display*, Colormap, XColor*);
Status XQueryColors(Display*, Colormap, XColor[], int ncolors);

Font XLoadFont(Display*, const char*);
XFontStruct* XQueryFont(Display*, Font);
char** XListFontsWithInfo(
    Display*, char*, int maxnames, int count, XFontStruct**
);
XFontStruct* XLoadQueryFont(Display*, const char*);
void XFreeFont(Display*, XFontStruct*);
Bool XGetFontProperty(XFontStruct*, Atom, unsigned long*);
char** XListFonts(Display*, char*, int maxnames, int* count);
void XFreeFontNames(char**);

void XSetFontPath(Display*, char**, int);
char** XGetFontPath(Display*, int*);
void XFreeFontPath(char**);

int XTextWidth(XFontStruct*, const char*, int);
int XTextWidth16(XFontStruct*, const unsigned short*, int);
void XTextExtents(
    XFontStruct*, const char*, int,
    int* direction, int* ascent, int* descent, XCharStruct* overall
);
void XTextExtents16(
    XFontStruct*, const unsigned short*, int, int* direction,
    int* ascent, int* descent, XCharStruct* overall
);
void XQueryTextExtents(
    Display*, Font, const char*, int,
    int* direction, int* ascent, int* descent, XCharStruct* overall
);
void XQueryTextExtents16(
    Display*, Font, const XChar2b*, int,
    int* direction, int* ascent, int* descent, XCharStruct* overall
);

void XDrawText(Display*, Drawable, GC, int x, int y, XTextItem[], int);
void XDrawText16(Display*, Drawable, GC, int x, int y, XTextItem16[], int);
void XDrawString16(
    Display*, Drawable, GC, int x, int y, const XChar2b*, int
);
void XDrawImageString16(
    Display*, Drawable, GC, int x, int y, const XChar2b*, int
);

GC XCreateGC(Display*, Drawable, unsigned long, XGCValues*);
void XCopyGC(Display*, GC src, unsigned int, GC dst);
void XChangeGC(Display*, GC, unsigned long, XGCValues*);
void XFreeGC(Display*, GC);
void XSetState(
    Display*, GC, unsigned long fg, unsigned long bg, int func, unsigned long
);
void XSetFunction(Display*, GC, int);
void XSetPlaneMask(Display*, GC, unsigned long);
void XSetForeground(Display*, GC, unsigned long);
void XSetBackground(Display*, GC, unsigned long);
void XSetLineAttributes(
    Display*, GC, unsigned int width, int style, int cap, int join
);
void XSetDashes(Display*, GC, int offset, char* dash[], int n);
void XSetFillStyle(Display*, GC, int);
void XSetFillRule(Display*, GC, int);
void XQueryBestSize(
    Display*, int, Drawable, unsigned int width, unsigned int height,
    unsigned int* rwidth, unsigned int* rheight
);
void XQueryBestTile(
    Display*, Drawable, unsigned int width, unsigned int height,
    unsigned int* rwidth, unsigned int* rheight
);
void XQueryBestStipple(
    Display*, Drawable, unsigned int width, unsigned int height,
    unsigned int* rwidth, unsigned int* rheight
);
void XSetTile(Display*, GC, Pixmap);
void XSetStipple(Display*, GC, Pixmap);
void XSetTSOrigin(Display*, GC, int x, int y);

void XSetFont(Display*, GC, Font);
void XSetClipOrigin(Display*, GC, int x, int y);
void XSetClipMask(Display*, GC, Pixmap);
void XSetClipRectangles(
    Display*, GC, int x, int y, XRectangle[], int n, int ordering
);
void XSetArcMode(Display*, GC, int);
void XSetSubwindowMode(Display*, GC, int);
void XSetGraphicsExposures(Display*, GC, Bool);

Pixmap XCreatePixmap(
    Display*, Drawable,
    unsigned int width, unsigned int height, unsigned int depth
);
Pixmap XCreateBitmapFromData(
    Display*, Drawable, void*, unsigned int, unsigned int
);
void XFreePixmap(Display*, Pixmap);

void XClearArea(
    Display*, Window, int x, int y, unsigned int width, unsigned int height,
    Bool exposures
);
void XClearWindow(Display*, Window);
void XCopyArea(
    Display*, Drawable src, Drawable dst, GC, int srcx, int srcy,
    unsigned int width, unsigned int height, int dstx, int dsty
);
void XCopyPlane(
    Display*, Drawable src, Drawable dst, GC, int srcx, int srcy,
    unsigned int width, unsigned int height, int dstx, int dsty,
    unsigned long plane
);

void XDrawPoint(Display*, Drawable, GC, int x, int y);
void XDrawPoints(Display*, Drawable, GC, XPoint[], int, int mode);
void XDrawLine(Display*, Drawable, GC, int x1, int y1, int x2, int y2);
void XDrawLines(Display*, Drawable, GC, XPoint[], int n, int mode);
void XDrawSegments(Display*, Drawable, GC, XSegment[], int);
void XDrawRectangle(
    Display*, Drawable, GC, int x, int y,
    unsigned int width, unsigned int height
);
void XDrawRectangles(Display*, Drawable, GC,XRectangle[], int);
void XDrawArc(
    Display*, Drawable, GC, int x, int y,
    unsigned int width, unsigned int height,
    int angle1, int angle2
);
void XDrawArcs(Display*, Drawable, GC, XArc[], int);
void XFillRectangle(
    Display*, Drawable, GC, int x, int y,
    unsigned int width, unsigned int height
);
void XFillRectangles(Display*, Drawable, GC, XRectangle[], int);
void XFillPolygon(
    Display*, Drawable, GC, XPoint[], int, int shape, int mode
);
void XFillArc(
    Display*, Drawable, GC, int x, int y,
    unsigned int width, unsigned int height,
    int angle1, int angle2
);
void XFillArcs(Display*, Drawable, GC, XArc[], int);

void XDrawString(Display*, Drawable, GC, int x, int y, const char*, int);
void XDrawImageString(
    Display*, Drawable, GC, int x, int y, const char*, int
);

void XGrabButton(
    Display*, unsigned int, unsigned int, Window, Bool,
    unsigned int, int ptrmode, int kbdmode, Window confined, Cursor
);
void XUngrabButton(Display*, unsigned int, unsigned int, Window);
int XGrabPointer(
    Display*, Window, Bool, unsigned int, int ptrmode, int kbdmode,
    Window confined, Cursor, Time
);
void XUngrabPointer(Display*, Time);
void XChangeActivePointerGrab(Display*, unsigned int, Cursor, Time);
void XGrabKeyboard(Display*, Window, Bool, int ptrmode, int kbdmode, Time);
void XUngrabKeyboard(Display*, Time);
void XGrabKey(
    Display*, int, unsigned int, Window, Bool, int ptrmode, int kbdmode
);
void XUngrabKey(Display*, int key, unsigned int, Window);
void XAllowEvents(Display*, int, Time);

void XGrabServer(Display*);
void XUngrabServer(Display*);

void XWarpPointer(
    Display*, Window src, Window dst, int srcx, int srcy,
    unsigned int width, unsigned int height, int dstx, int dsty
);
void XSetInputFocus(Display*, Window, int revert, Time);
void XGetInputFocus(Display*, Window*, int* revert);

void XChangePointerControl(
    Display*, Bool has_acc, Bool has_thresh, int acc1, int acc2, int thresh
);
void XGetPointerControl(Display*, int* acc1, int* acc2, int* thresh);

void XChangeKeyboardControl(Display*, unsigned long, XKeyboardControl*);
void XGetKeyboardControl(Display*, XKeyboardState*);
void XAutoRepeatOn(Display*);
void XAutoRepeatOff(Display*);
void XBell(Display*, int percent);
int XSetPointerMapping(Display*, unsigned char[], int);
int XGetPointerMapping(Display*, unsigned char[], int);

void XQueryPointer(
    Display*, Window, Window* root, Window* child, int* x0, int* y0,
    int* wx, int* wy, unsigned int*
);

void XChangeKeyboardMapping(Display*, int first, int percode, KeySym[], int);
void XSetModifierMapping(Display*, XModifierKeymap*);
XModifierKeymap* XGetModifierMapping(Display*);

void XSelectInput(Display*, Window, unsigned int);
void XFlush(Display*);
void XSync(Display*, int);
int XPending(Display*);
void XNextEvent(Display*, XEvent*);
void XPeekEvent(Display*, XEvent*);

typedef Bool (*XPredicate)(Display*, XEvent*, char*);

void XIfEvent(Display*, XEvent*, XPredicate, char*);
int XCheckIfEvent(Display*, XEvent*, XPredicate, char*);
void XPeekIfEvent(Display*, XEvent*, XPredicate, char*);
void XPutBackEvent(Display*, XEvent*);
void XWindowEvent(Display*, Window, unsigned int, XEvent*);
int XCheckWindowEvent(Display*, Window, unsigned int, XEvent*);
void XMaskEvent(Display*, unsigned int, XEvent*);
int XCheckMaskEvent(Display*, unsigned int, XEvent*);
XTimeCoord* XGetMotionEvents(
    Display*, Window, Time start, Time stop, int* nevents
);

void XSendEvent(Display*, Window, Bool, unsigned int, XEvent*);

KeySym XLookupKeysym(XKeyEvent*, int);
void XRefereshKeyboardMapping(XMappingEvent*);
int XLookupString(XKeyEvent*, char*, int, KeySym*, struct _XComposeStatus*);
void XRebindKeySym(
    Display*, KeySym, KeySym[], int, unsigned char*, int nbytes
);

/*
 * Functions not in original InterViews file
 */

Window XRootWindow ( Display*, int);
Window XDefaultRootWindow( Display*);

#endif
#endif

