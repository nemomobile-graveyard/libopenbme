/*
 * $Id: type_def.h 1715 2008-10-23 17:16:54Z mikyline $
 *
 * ISA-compatible type definitions.
 */

#ifndef _TYPE_DEF_H
#define _TYPE_DEF_H

#include <sys/types.h>
#include <stdbool.h>

/* Unsigned types */
typedef	__uint8_t uint8;
typedef	__uint16_t uint16;
typedef	__uint32_t uint32;
typedef	__uint64_t uint64;
typedef uint8 byte;
typedef uint16 word;
typedef uint32 dword;

/* Signed types */
typedef	__int8_t int8;
typedef	__int16_t int16;
typedef	__int32_t int32;
typedef	__int64_t int64;

/* Boolean types */
typedef int8 bool8;

/* Bit types */
typedef uint8 bits8;
typedef uint16 bits16;
typedef uint32 bits32;

/* Endianess */
#define LITTLE_ENDIAN_TYPE

#endif
