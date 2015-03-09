libtrace
========
.. image:: hhttp://jenkins.0x1.org:8080/buildStatus/icon?job=cobaro-libtrace0

libtrace is a lightweight runtime debug tracing library for C
projects.  It can be completely disabled at compile time for releaes
builds, and selectively enabled at runtime for testing with debug
builds.

Quickstart
----------
The selection of which trace messages to emit is done using
environment variables.  Each trace statement in the code specifies a
_level_ of importance for the message.  Environment variables specify
the desired level of tracing for each source code file.

For example, if your code includes a statement like

    COBARO_TRACE(20, "%s", "Something important");

in the source code file important.c, and you run your program like:

    trace_important=20 a.out

It'll produce something like

    12:01:34 important.c:123 Something important

Compiling
---------
See the `Developers Guide <doc/BUILD.rst>`_.

Contributing
------------
Contributions are welcome.

The project is hosted at http://github.com/cobaro/libtrace.
Please submit proposed changes as a pull request, or attach a patch to
a GitHub issue.

Licence
-------
See the `license <LICENSE.txt>`_.



