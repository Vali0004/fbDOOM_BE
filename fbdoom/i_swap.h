//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	Endianess handling, swapping 16bit and 32bit.
//


#ifndef __I_SWAP__
#define __I_SWAP__

#ifdef ORIGCODE
#include "SDL_endian.h"

// Endianess handling.
// WAD files are stored little endian.

// Just use SDL's endianness swapping functions.

// These are deliberately cast to signed values; this is the behaviour
// of the macros in the original source and some code relies on it.

#define SHORT(x)  ((signed short) SDL_SwapLE16(x))
#define LONG(x)   ((signed int) SDL_SwapLE32(x))

// Defines for checking the endianness of the system.

#if SDL_BYTEORDER == SYS_LIL_ENDIAN
#define SYS_LITTLE_ENDIAN
#elif SDL_BYTEORDER == SYS_BIG_ENDIAN
#define SYS_BIG_ENDIAN
#endif

#else
	
#ifndef __BIG_ENDIAN__

#define LONG(x) (x)
#define SHORT(x) (x)

#else

#define LONG(x) ((long)SwapLONG((unsigned long) (x)))
#define SHORT(x) ((short)SwapSHORT((unsigned short) (x)))

static unsigned long SwapLONG(unsigned long x)
{
    return
	(x>>24)
	| ((x>>8) & 0xff00)
	| ((x<<8) & 0xff0000)
	| (x<<24);
}

static unsigned short SwapSHORT(unsigned short x)
{
    return
	(x>>8) | (x<<8);
}

#endif

#endif
#endif

