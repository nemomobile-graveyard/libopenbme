AC_PREREQ([2.65])
AC_INIT([libbme], [0.0.0], [http://bugs.meego.com])

# NOTE: Must the LT version must be changed when code is released:
#  - If interfaces changed/added/removed: lt_current++, lt_rev=0
#  - If interfaces added: lt_age++
#  - If Interfaces removed: lt_age=0
#  - If only code changes (interface untouched): lt_rev++
bmeipc_lt_current=0
bmeipc_lt_rev=0
bmeipc_lt_age=0
AC_SUBST([BMEIPC_LT_VERSION],[$bmeipc_lt_current:$bmeipc_lt_rev:$bmeipc_lt_age])

AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([src/bmeipc.c])
# FIXME: start to use config.h
#AC_CONFIG_HEADERS([config.h])

AC_DEFINE(_GNU_SOURCE)

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_LIBTOOL

# Specify dir for local macros
AC_CONFIG_MACRO_DIR([m4])

AC_CHECK_LIB([rt], [clock_gettime], [], AC_MSG_FAILURE([librt required!]))

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h sys/socket.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_FUNC_ALLOCA
AC_CHECK_FUNCS([clock_gettime gettimeofday memset socket strerror])

AC_CONFIG_FILES([Makefile bmeipc.pc])

AC_OUTPUT
