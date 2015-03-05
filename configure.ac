# COPYRIGHT_BEGIN
# Copyright (C) cobaro.org
# All rights reserved.
# COPYRIGHT_END

AC_INIT([libtrace], [1.0.0], [bill@cobaro.org])

AC_CONFIG_SRCDIR(lib/trace.h)
AC_PREREQ(2.68)
AM_INIT_AUTOMAKE([-Wall, -Werror foreign])
AM_CONFIG_HEADER(lib/config.h)

AM_PROG_AR

LT_INIT()

AC_CONFIG_MACRO_DIR([m4])
AC_PROG_CC
AC_HEADER_STDC
AC_PROG_LN_S
AC_PROG_INSTALL

# Following tests use C compilation/linkage.
AC_LANG(C)

# RPM Settings
AC_PATH_PROG([RPMBUILD], [rpmbuild], [no])
AM_CONDITIONAL(RUN_RPMBUILD, test "x$RPMBUILD" != xno)

RPM_BUILD_ROOT="`pwd`/packages/rpm/BUILD"
AC_SUBST(RPM_BUILD_ROOT)
# See packages/rpm/spec.in for how this is glued together
RPM_CFLAGS="-std=gnu99 -flto -fuse-linker-plugin -Wall -Werror -O3 -pipe -m64 -mtune=generic -grecord-gcc-switches -UFXP_DEBUG -DNDEBUG"
AC_SUBST(RPM_CFLAGS)

# Header files we need to know about
AC_CHECK_HEADERS(\
 stdio.h \
)

# See if valgrind is available
if test "x$cross_compiling" = xyes; then
   # Don't try to run valgrind when cross-compiling, because a) it's
   # not going to be there anyway
   VALGRIND=no
else
   AC_PATH_PROG([VALGRIND], [valgrind], [no])
fi
AM_CONDITIONAL(RUN_VALGRIND, test "x$VALGRIND" != xno)

# See if sphinx-build is available
AC_PATH_PROG([SPHINXBUILD], [sphinx-build], [echo])
AM_CONDITIONAL(RUN_SPHINX_BUILD, test "x$SPHINXBUILD" != xecho)


AC_CONFIG_FILES([
 Makefile
 doc/Makefile
 lib/Makefile
 m4/Makefile
 packages/Makefile
 packages/rpm/Makefile
 packages/rpm/SPECS/Makefile
 packages/rpm/SOURCES/Makefile
 script/Makefile
 test/Makefile
])

AC_OUTPUT
