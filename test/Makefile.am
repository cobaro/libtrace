# COPYRIGHT_BEGIN
# Copyright (C) 2015, cobaro.org
# All rights reserved.
# COPYRIGHT_END

if RUN_VALGRIND
VG_TESTS_ENVIRONMENT = $(LIBTOOL) --mode=execute $(VALGRIND) \
        --trace-children=yes \
        --leak-check=full \
        --show-reachable=yes \
        --error-exitcode=1
else
VG_TESTS_ENVIRONMENT = echo valgrind
endif

valgrind.sup:
	touch $@

.PHONY: valgrind
valgrind: $(TESTS) valgrind.sup
	@(for t in $(TESTS); do $(VG_TESTS_ENVIRONMENT) ./$$t; done)

TESTS = \
       test-trace

check_PROGRAMS = \
	$(TESTS)

test_trace_SOURCES = \
	test-trace.c

test_trace_LDADD = \
	../lib/libcobaro-trace0.la

AM_CPPFLAGS = \
	@CPPFLAGS@ \
	-I $(top_srcdir)/lib

noinst_HEADERS = \
	greatest.h
