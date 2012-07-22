ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = -Wall -fPIC -I@top_srcdir@/include

bmeincludedir = @includedir@/bme
pkgconfigdir = @libdir@/pkgconfig

lib_LTLIBRARIES = libopenbmeipc.la \
                  libopenbmeipccookie.la

libopenbmeipc_la_SOURCES = src/bmeipc.c
libopenbmeipc_la_LDFLAGS = -version-info $(BMEIPC_LT_VERSION) -Wl,--version-script,@top_srcdir@/libopenbmeipc.ver

libopenbmeipccookie_la_SOURCES = src/bmeipccookie.c \
                             include/bmeipc-internal.h
libopenbmeipccookie_la_LDFLAGS = -version-info $(BMEIPCCOOKIE_LT_VERSION)
libopenbmeipccookie_la_LIBADD = libopenbmeipc.la

bmeinclude_HEADERS = include/bmeipc.h \
                     include/bmemsg.h \
                     include/bmeipccookie.h

pkgconfig_DATA = bmeipc.pc \
                 bmeipccookie.pc
