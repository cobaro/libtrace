# COPYRIGHT_BEGIN
# Copyright (C) 2015, cobaro.org
# All rights reserved.
# COPYRIGHT_END

EXTRA_DIST = spec.in
DISTCLEANFILES = spec

all: spec

edit = sed \
	-e s,@RELEASE\@,`date +\%Y\%m\%d`,g \
	-e 's,@PACKAGE\@,$(PACKAGE),g' \
	-e 's,@VERSION\@,$(VERSION),g' \
	-e 's,@RPM_BUILD_ROOT\@,$(RPM_BUILD_ROOT),g' \
	-e 's,@PACKAGE_CFLAGS\@,$(PACKAGE_CFLAGS),g' \
	-e 's,@PACKAGE_CONFIGURE\@,$(PACKAGE_CONFIGURE),g'

spec: spec.in $(top_srcdir)/configure.ac
	rm -f spec spec.tmp
	$(edit) $(srcdir)/spec.in >spec.tmp
	mv spec.tmp spec
