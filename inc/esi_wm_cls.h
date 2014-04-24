/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WM_CLS.H*/
/* *1    30-JUN-1989 15:06:01 GILLESPIE ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WM_CLS.H*/
/*
 * $Header: /dba0/esi/finder/include/RCS/esi_wm_cls.h,v 1.1 89/05/30 15:35:30 esi Exp $ esi_wm_cls.h 
 */

/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WM_CLS.H*/
/* *4     8-APR-1989 00:41:31 GILLESPIE "Add copyright, (INT) castings"*/
/* *3    17-DEC-1988 09:38:49 GILLESPIE "(SPR 4981) Unisource"*/
/* *2     5-NOV-1987 15:21:21 JAMES "(SPR 3279) correct the capital."*/
/* *1     7-JUL-1987 10:48:59 SYSTEM ""*/
/* DEC/CMS REPLACEMENT HISTORY, Element ESI_WM_CLS.H*/
/******************************************************************************

		Copyright Exploration Systems, Inc. 1989
		   Unpublished -- All rights reserved

THIS SOFTWARE IS THE PROPRIETARY PROPERTY OF Exploration Systems, Inc.  AND MAY
CONTAIN CONFIDENTIAL TRADE SECRET INFORMATION. IT IS LICENSED FOR USE ON THE
DESIGNATED EQUIPMENT ON WHICH IT WAS ORIGINALLY INSTALLED AND  MAY NOT BE
MODIFIED, DUPLICATED OR COPIED IN ANY FORM WITHOUT PRIOR WRITTEN CONSENT OF 

			Exploration Systems, Inc.
			579 Market Street
			San Francisco, CA  USA 94105
			(415) 974-1600

(The above notice does not constitute an admission of publication or
unrestricted dissemination of the work) 


******************************************************************************/


#ifndef ESI_WM_CLS_H
#define ESI_WM_CLS_H 1

/* 1 - 99 : Window manager classes */
#define WM_CLASS_WINDOW      (INT) 1
#define WM_CLASS_TNR         (INT) 2
#define WM_CLASS_GROUP       (INT) 3
#define WM_CLASS_SEGMENT     (INT) 4
#define WM_CLASS_PICK        (INT) 5

#define WM_CLSTR_WINDOW      "Untitled Window"
#define WM_CLSTR_TNR         "Untitled Transformation"
#define WM_CLSTR_GROUP       "Untitled Group"
#define WM_CLSTR_SEGMENT     "Untitled Segment"
#define WM_CLSTR_PICK        "Untitled Pick"

#define WM_CLASS_BACKGROUND  (INT) 10
#define WM_CLASS_BORDER      (INT) 11

#define WM_CLSTR_BACKGROUND  "Background"
#define WM_CLSTR_BORDER      "Border"

#define WM_CLASS_DCS         (INT) 12
#define WM_CLASS_NDC         (INT) 13
#define WM_CLASS_NWC         (INT) 14
#define WM_CLASS_WCS         (INT) 15

#define WM_CLSTR_DCS         "Device Coordinates System"
#define WM_CLSTR_NDC         "Normalized Device Coordinates"
#define WM_CLSTR_NWC         "Normalized Window Coordinates"
#define WM_CLSTR_WCS         "World Coordinate System"

/* 101 - 199 : Misc. classes */

/* 201 - 299 : Mapper classes */
#define WM_CLASS_MAP         (INT) 201
#define WM_CLASS_OVERLAY     (INT) 202
#define WM_CLASS_KEY         (INT) 203
#define WM_CLASS_TITLE       (INT) 204
#define WM_CLASS_HILIGHT     (INT) 205      /*Gen'l purpose segment for temporary hilighting */
#define WM_CLASS_HILITE_OVERLAY (INT) 206   /* for gb_hilite.		*/
#define WM_CLASS_WELL_HILITE    (INT) 207   /* for gb_hilite.		*/
#define WM_CLASS_SEISMIC_HILITE (INT) 208   /* for gb_hilite.		*/
#define WM_CLASS_ACTIVE_MAP     (INT) 209   /* Border of active map     */

#define WM_CLSTR_MAP         "Map"
#define WM_CLSTR_OVERLAY     "Overlay"
#define WM_CLSTR_KEY         "Key"
#define WM_CLSTR_TITLE       "Title"
#define WM_CLSTR_HILIGHT     "Hilight"
#define WM_CLSTR_HILITE_OVERLAY "Highlight Overlay" /* for gb_hilite.	*/
#define WM_CLSTR_WELL_HILITE "Wells Highlights"     /* for gb_hilite.	*/
#define WM_CLSTR_SEISMIC_HILITE "Seismic Highlights"  /* for gb_hilite.	*/
#define WM_CLSTR_ACTIVE_MAP "Active Map"


/* 301 - 399 : Seismic classes */
#define WM_CLASS_SEISMIC     (INT) 301

#define WM_CLSTR_SEISMIC     "Seismic"

/* 401 - 499 : Cross section classes */
#define WM_CLASS_CROSS_SECTION  (INT) 401
#define WM_CLASS_CORR_LINE      (INT) 402
#define WM_CLASS_MARKER_NAME    (INT) 403
#define WM_CLASS_LOG_CURVE      (INT) 404
#define WM_CLASS_LOG_FRAME      (INT) 405
#define WM_CLASS_LOGS           (INT) 406         /* Group containing logs */

#define WM_CLSTR_CROSS_SECTION  "Cross Section"
#define WM_CLSTR_CORR_LINE      "Correlation Line"
#define WM_CLSTR_MARKER_NAME    "Marker Name"
#define WM_CLSTR_LOG_CURVE      "Log Curve"
#define WM_CLSTR_LOG_FRAME      "Log Frame"
#define WM_CLSTR_LOGS           "Logs"

/* 601 - 1800 : Graphic object classes */

/*             These class codes are reserved, and are maintained in */
/*             the GRAPHIC_OBJECT_CODES table. */


/* 1801 - 1899 : Graphic subobject classes */

#define WM_CLASS_LINE          (INT) 1801
#define WM_CLASS_POLYGON       (INT) 1802
#define WM_CLASS_TEXT          (INT) 1803
#define WM_CLASS_SYMBOL        (INT) 1804
#define WM_CLASS_WELL_SYMBOL   (INT) 1805

#define WM_CLSTR_LINE          "PolyLine"
#define WM_CLSTR_POLYGON       "Polygon"
#define WM_CLSTR_TEXT          "Text"
#define WM_CLSTR_SYMBOL        "Symbol"
#define WM_CLSTR_WELL_SYMBOL   "Well Symbol"

/* 1900 - 2999 : Overlay classes */

/*             These class codes are reserved, and are maintained in */
/*             the OVERLAY_CODES table. */

#endif

