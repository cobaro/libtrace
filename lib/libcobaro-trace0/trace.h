// -*- mode: c -*-
#ifndef COBARO_TRACE0_TRACE_H
#define COBARO_TRACE0_TRACE_H

/****************************************************************
COPYRIGHT_BEGIN
Copyright (C) 2015, cobaro.org
All rights reserved.
COPYRIGHT_END
****************************************************************/

/// \page Introduction to debug tracing
///
/// Provides a trace call that can be compiled out of code to avoid
/// any runtime penalty.
///
/// If enabled at compile-time (via #COBARO_TRACE_ENABLED) then code
/// will be called at runtime otherwise a trace is a nullop.
///
/// At runtime, tracing can be turned on or off on a
/// per-file basis and on a per-level basis.
///
/// Tracing for a file is enabled by setting the desired file and
/// level in the environment. e.g.,
/// \code
///     export trace_myfile=12
/// \endcode
/// would cause COBARO_TRACE statements in myfile.c or myfile.cpp of
/// level <= 12 to print the desired output.

/// \def COBARO_TRACE(level, format, ...)
///
/// \param[in] level
///     loglevel with higher numbers having more detail
///
/// \param[in] format
///     printf styled format string. Note that a as __VA_ARGS__ cannot
///     be empty this should consume at least one argument
///
/// \param[in] ...
///     printf arguments

#if defined (COBARO_TRACE_ENABLED)
# define COBARO_TRACE(level, format, ...) \
    cobaro_trace(__FILE__, __LINE__, level, format, __VA_ARGS__)
#else
# define COBARO_TRACE(level, format, ...)
#endif

/// Underlying call, use only through the macro
void cobaro_trace(char* file, int line, int level, char *format, ...)
#if defined(__GNUC__)
    __attribute__((format (printf, 4, 5)))
#endif
    ;

/// Printable version number
char *cobaro_trace_version();

#endif /* COBARO_TRACE0_TRACE_H */
