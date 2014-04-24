/* DEC/CMS REPLACEMENT HISTORY, Element SUN_ANSICGKS.H*/
/* *2     3-MAY-1991 16:22:23 KEE "(SPR -1) MOTIF/PRIORGKS, MOTIF/DECGKS, DECW/PRIORGKS, DECW/DECGKS version"*/
/* *1    12-JUL-1990 15:54:45 GILLESPIE "Moved from cmsref"*/
/* DEC/CMS REPLACEMENT HISTORY, Element SUN_ANSICGKS.H*/
/* @(#)ansicgks.h 11.1 88/09/14 Copyright (c) 1987 Sun Microsystems */

/*
			GKS in C (ANSI Binding)
			=======================

*************************************************************************

File:	ansicgks.h	Include everything needed for SunGKS ANSI C Binding

	This file can be included by the application which
	invokes GKS through the ANSI C binding functions.
	It allows both long and short names to be used for function calls.

*************************************************************************
*/

#ifndef SUN_ANSICGKS_H
#define SUN_ANSICGKS_H 1

#define ANSI_BINDING

/** Define compiler configuration for GKS/C **/
#define Real float
#define ENUM	/* set since enumeration type is supported*/

/** Include operating system dependant stuff for GKS/C **/
#include "esi_stdio.h"
#include "esi_math.h"

/** Include other files needed for SunGKS via ANSI C binding **/
/*
#include "sun_agksconst.h"
*/
#include "sun_agkstype.h"
#include "sun_agksfunc.h"
#include "sun_ansilong.h"
/*
#include "sun_gkswsconfig.h"
#include <gks/metafile_opdefs.h>
*/

/** Undefine min and max **/
#undef min
#undef max

/** Define constant that can be passed as second argument to gopengks **/
#define	GMEMORY	((Glong) -1)



/** Work around for sparc compiler bug (on 4.0) **/
/**   problem is that compiler can't deal with functions that return
 ** structures when a float is passed to that function (the float is
 ** corrupted).  This gets around it by converting to a double
 ** instead
 **/

#ifdef sparc
#define gevtm(a,b,c,d,e)                gevtm_sparc(a,b,((double)c),d,e)
Gsegtran gevtm_sparc();
#define gactm(a,b,c,d,e,f)              gactm_sparc(a,b,c,((double)d),e,f)
Gsegtran gactm_sparc();
#endif sparc

#endif
