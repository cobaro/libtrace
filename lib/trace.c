// -*- mode: c -*-
/****************************************************************
COPYRIGHT_BEGIN
Copyright (C) 2015, cobaro.org
All rights reserved.
COPYRIGHT_END
****************************************************************/

#include "cobaro-trace0/trace.h"

#include "config.h"

#if defined(HAVE_LIBGEN_H)
# include <libgen.h>
#endif

#if defined(HAVE_STDARG_H)
# include <stdarg.h>
#endif

#if defined(HAVE_STDIO_H)
# include <stdio.h>
#endif

#if defined(HAVE_STDLIB_H)
# include <stdlib.h>
#endif

#if defined(HAVE_STRING_H)
# include <string.h>
#endif

#if defined(TIME_WITH_SYS_TIME)
# include <sys/time.h>
# include <time.h>
#else
# if defined(HAVE_SYS_TIME_H)
#   include <sys/time.h>
# else
#   include <time.h>
# endif
#endif

char *cobaro_trace_version(void)
{
    return VERSION;
}
        
#define COBARO_MAX_ENVNAME (1024)
#define COBARO_MAX_LOGLINE (1024)

void cobaro_trace(char* file, int line, int level, char *format, ...)
{
    char env_name[COBARO_MAX_ENVNAME];
    char *env_value;
    int env_level;
    char *file_basename, *index;
    char buf[COBARO_MAX_LOGLINE];
    int formatted = 0;
    va_list args;
    struct timeval now = {0};

    // For a filename /path/filename.ext
    // we print filename.ext
    // we name in the env for trace_filename=level
    file_basename = basename(file); // we can print that
    snprintf(env_name, COBARO_MAX_ENVNAME, "trace_%s", file_basename);
    if ((index = strchr(env_name, '.'))) {
        *index = '\0';
    }
    env_value = getenv(env_name);

    // Give up if there is no envvar set
    // Give up if the envvar is not an integer or is zero
    // Give up if the level is less than requested
    if (!env_value || (!(env_level = atoi(env_value))) || (env_level < level)) {
        return;
    }

    // Start trace output with time (hh:mm:ss).
    gettimeofday(&now, NULL);
    formatted += strftime(buf, COBARO_MAX_LOGLINE,
                          "%T",
                          localtime(&now.tv_sec));

    // Add microseconds, file and line number.
    formatted += snprintf(&buf[formatted], COBARO_MAX_LOGLINE,
                          ".%06ld %s:%d ",
                          now.tv_usec, file_basename, line);

    // Add their trace message
    va_start(args, format);
    formatted += vsnprintf(&buf[formatted], COBARO_MAX_LOGLINE, format, args);
    fprintf(stdout, "%s\n", buf);
    va_end(args);
}

