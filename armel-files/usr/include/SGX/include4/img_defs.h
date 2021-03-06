/*!****************************************************************************
@File           img_defs.h

@Title          Common header containing type definitions for portability

@Author         Imagination Technologies

@date           August 2001

@Copyright      Copyright 2003-2008 by Imagination Technologies Limited.
                All rights reserved. No part of this software, either material
                or conceptual may be copied or distributed, transmitted,
                transcribed, stored in a retrieval system or translated into
                any human or computer language in any form by any means,
                electronic, mechanical, manual or other-wise, or disclosed to
                third parties without the express written permission of
                Imagination Technologies Limited, Home Park Estate,
                Kings Langley, Hertfordshire, WD4 8LZ, U.K.

@Platform       cross platform / environment

@Description    Contains variable and structure definitions. Any platform
                specific types should be defined in this file.

@DoxygenVer

******************************************************************************/

/******************************************************************************
Modifications :-
$Log: img_defs.h $
*******************************************************************************/
#if !defined (__IMG_DEFS_H__)
#define __IMG_DEFS_H__

#include "img_types.h"

/*!
 *****************************************************************************
 *	These types should be changed on a per-platform basis to retain
 *	the indicated number of bits per type. e.g.: A DP_INT_16 should
 *	always reflect a signed 16 bit value.
 *****************************************************************************/

typedef		enum	img_tag_TriStateSwitch
{
	IMG_ON		=	0x00,
	IMG_OFF,
	IMG_IGNORE

} img_TriStateSwitch, * img_pTriStateSwitch;

#define		IMG_SUCCESS				0

#define		IMG_NO_REG				1

#if defined (NO_INLINE_FUNCS)
	#define	INLINE
	#define	FORCE_INLINE
#else
#if defined (__cplusplus)
	#define INLINE					inline
	#define	FORCE_INLINE			inline
#else
	#define	INLINE					__inline
	#define	FORCE_INLINE			static __inline
#endif
#endif


/* Use this in any file, or use attributes under GCC - see below */
#ifndef PVR_UNREFERENCED_PARAMETER
#define	PVR_UNREFERENCED_PARAMETER(param) (param) = (param)
#endif

/* The best way to supress unused parameter warnings using GCC is to use a
 * variable attribute.  Place the unref__ between the type and name of an
 * unused parameter in a function parameter list, eg `int unref__ var'. This
 * should only be used in GCC build environments, for example, in files that
 * compile only on Linux. Other files should use UNREFERENCED_PARAMETER */
#ifdef __GNUC__
#define unref__ __attribute__ ((unused))
#else
#define unref__
#endif

/*
	Wide character definitions
*/
#ifndef _TCHAR_DEFINED
#if defined(UNICODE)
typedef unsigned short		TCHAR, *PTCHAR, *PTSTR;
#else	/* #if defined(UNICODE) */
typedef char				TCHAR, *PTCHAR, *PTSTR;
#endif	/* #if defined(UNICODE) */
#define _TCHAR_DEFINED
#endif /* #ifndef _TCHAR_DEFINED */


			#if defined(__linux__) || defined(__METAG)

				#define IMG_CALLCONV
				#define IMG_INTERNAL	__attribute__ ((visibility ("hidden")))
				#define IMG_EXPORT
				#define IMG_IMPORT
				#define IMG_RESTRICT	__restrict__

			#else
					#error("define an OS")
			#endif

// Use default definition if not overridden
#ifndef IMG_ABORT
	#define IMG_ABORT()	abort()
#endif

#ifndef IMG_MALLOC
	#define IMG_MALLOC(A)		malloc	(A)
#endif

#ifndef IMG_FREE
	#define IMG_FREE(A)			free	(A)
#endif

#define IMG_CONST const

#define IMG_ARRAY_SIZE(x)  (sizeof(x) / sizeof(x[0]))

#endif /* #if !defined (__IMG_DEFS_H__) */
/*****************************************************************************
 End of file (IMG_DEFS.H)
*****************************************************************************/
