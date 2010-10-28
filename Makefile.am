ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = -Wall -fPIC -I@top_srcdir@/include

bmeincludedir = @includedir@/bme
pkgconfigdir = @libdir@/pkgconfig

lib_LTLIBRARIES = libbmeipc.la \
                  libbmeipccookie.la

libbmeipc_la_SOURCES = src/bmeipc.c
libbmeipc_la_LDFLAGS = -version-info $(BMEIPC_LT_VERSION) -Wl,--version-script,@top_srcdir@/libbmeipc.ver

libbmeipccookie_la_SOURCES = src/bmeipccookie.c \
                             include/bmeipc-internal.h
libbmeipccookie_la_LDFLAGS = -version-info $(BMEIPCCOOKIE_LT_VERSION)
libbmeipccookie_la_LIBADD = libbmeipc.la

bmeinclude_HEADERS = include/bmeipc.h \
                     include/bmemsg.h \
                     include/bmeipccookie.h

pkgconfig_DATA = bmeipc.pc \
                 bmeipccookie.pc
