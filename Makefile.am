ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = -Wall -fPIC -I@abs_top_srcdir@/include

bmeincludedir = @includedir@/bme
pkgconfigdir = @libdir@/pkgconfig

lib_LTLIBRARIES = libbmeipc.la

libbmeipc_la_SOURCES = src/bmeipc.c
libbmeipc_la_LDFLAGS = -version-info $(BMEIPC_LT_VERSION)

bmeinclude_HEADERS = include/bmeipc.h \
                     include/bmemsg.h

pkgconfig_DATA = bmeipc.pc
