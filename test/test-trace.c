// -*- mode: c -*-
/****************************************************************
COPYRIGHT_BEGIN
Copyright (C) 2015, cobaro.org
All rights reserved.
COPYRIGHT_END
****************************************************************/

#include "trace.h"
#include "greatest.h"

TEST trace_linkage() {
    GREATEST_ASSERT(trace_version() != NULL);
    GREATEST_PASS();
}

SUITE(trace_trace) {
    //SET_SETUP(setup_cb, NULL);
    //SET_TEARDOWN(teardown_cb, NULL);

    RUN_TEST(trace_linkage);
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
