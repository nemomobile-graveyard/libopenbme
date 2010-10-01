/*
 * $Id: global.h 1332 2005-10-12 08:50:13Z mikyline $
 *
 * Various definitions, needed by almost all ISA components.
 */

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <unistd.h>

#ifndef NULL
#define NULL	0
#endif

#ifndef NUL
#define NUL	'\0'
#endif

/** Boolean constants **/
#define FALSE		0
#define TRUE		1
#define NO		FALSE
#define YES		TRUE
#define OFF		FALSE
#define ON		TRUE
#define FAIL		FALSE
#define OK		TRUE
#define DISABLED	FALSE
#define ENABLED		TRUE

/** Projects **/
#define G_N770		165

/** Customers **/
#define G_NOKIA		1

/** Serial number type masks **/
#define G_SN_IMEI_MASK	1
#define G_SN_CSN_MASK	2
#define G_SN_ESN_MASK	4
#define G_SN_EESN_MASK	8

/** Test environments **/
#define G_NORMAL_ENV	1
#define G_FIELD_TEST	3
#define G_MODULE_TEST	6
#define G_UNIT_TEST	7

/** OS layer **/
#define G_OS		0	/* Multi-stack OS */
#define G_OS_SS		1	/* Single-stack OS */           
#define G_OS_ENOS	2	/* Special Multi-stack OS */
#define G_OS_DSP_OSE	3	/* OSE operating system for DSP */

/** Compiler types **/
#define G_GCC_ELF_ARM_C	24

/** Some useful macros **/
#define Case break;case
#define ArrSize(a) ((int)(sizeof(a)/sizeof(*a)))

#define LOCAL static

#define GLOBAL_ASSERT(x)  \
	do { \
		if(!(x)) { \
			fprintf(stderr, "assertion failed (line: %d).\n", \
					__LINE__); \
			abort(); \
		} \
	} while (0)

#endif
