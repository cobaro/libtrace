// -*- mode: c -*-
/****************************************************************
COPYRIGHT_BEGIN
Copyright (C) 2015, cobaro.org
All rights reserved.
COPYRIGHT_END
****************************************************************/

#define COBARO_TRACE_ENABLED 1
#include "cobaro-trace0/trace.h"
#include "greatest.h"

TEST trace_linkage() {
    GREATEST_ASSERT(cobaro_trace_version() != NULL);
    GREATEST_PASS();
}

TEST trace_print() {
    // FIXME: How to check output?
    //  Use pipe(); close(1); dup() or dup2() to hijack stdout for the
    //  duration of the test, and make sure it's receiving the right
    //  things?
    COBARO_TRACE(1, "%s", "test1") ;
    COBARO_TRACE(2, "%s %d %u", "test2", 2, 3);
    COBARO_TRACE(3, "%d", 5) ;
    GREATEST_PASS();
}

SUITE(trace_trace) {
    //SET_SETUP(setup_cb, NULL);
    //SET_TEARDOWN(teardown_cb, NULL);

    RUN_TEST(trace_linkage);
    RUN_TEST(trace_print);
}

/* Add definitions that need to be in the test runner's main file. */
GREATEST_MAIN_DEFS();

int
main(
    int argc,
    char **argv)
{
    GREATEST_MAIN_BEGIN();      /* init & parse command-line args */
    RUN_SUITE(trace_trace);
    GREATEST_MAIN_END();        /* display results */
}
