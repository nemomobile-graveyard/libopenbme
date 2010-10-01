AC_PREREQ([2.65])
AC_INIT([libbmeipc], [0.8.55], [http://bugs.meego.com])
AC_CONFIG_SRCDIR([src/bmeipc.c])
# FIXME: change to bmeipc.h
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

# Checks for libraries.
# FIXME: Replace `main' with a function in `-ldl':
#AC_CHECK_LIB([dl], [main])
# FIXME: Replace `main' with a function in `-ldsme':
#AC_CHECK_LIB([dsme], [main])
# FIXME: Replace `main' with a function in `-lrt':
#AC_CHECK_LIB([rt], [main])

# Checks for header files.
AC_CHECK_HEADERS([limits.h stdlib.h string.h sys/socket.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_FUNC_ALLOCA
AC_CHECK_FUNCS([clock_gettime gettimeofday memset socket strerror])

AC_CONFIG_FILES([Makefile
                 src/Makefile])

AC_OUTPUT
