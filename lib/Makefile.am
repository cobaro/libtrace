# COPYRIGHT_BEGIN
# Copyright (C) 2015, cobaro.org
# All rights reserved.
# COPYRIGHT_END

SUBDIRS = libcobaro-trace0

lib_LTLIBRARIES = libcobaro-trace0.la

libcobaro_trace0_ladir = $(includedir)/libcobaro-trace0

libcobaro_trace0_la_HEADERS = \
	libcobaro-trace0/trace.h

libcobaro_trace0_la_SOURCES = \
	trace.c

libcobaro_trace0_la_LDFLAGS = \
	-version-info @LIB_VERSION@

AM_CPPFLAGS = \
	@CPPFLAGS@
