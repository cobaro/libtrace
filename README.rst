libtrace
========
.. image:: http://jenkins.0x1.org:8080/buildStatus/icon?job=cobaro-libtrace0


libtrace is an `MIT licensed <LICENSE.txt>`_. lightweight runtime debug
tracing library for C projects. It can be completely disabled at
compile time for release builds, and selectively enabled at runtime
for testing with debug builds.

Quickstart
----------
The selection of which trace messages to emit is done using
environment variables.  Each trace statement in the code specifies a
_level_ of importance for the message.  Environment variables specify
the desired level of tracing for each source code file.

For example, if your code includes a statement like::

    COBARO_TRACE(20, "%s", "Something important");

in the source code file important.c, and you run your program like::

    trace_important=20 a.out

It'll produce something like::

    12:01:34 important.c:123 Something important

Currently supported platforms include Linux and OSX.

See the `Developers Guide <doc/DeveloperGuide.rst>`_ and doxygen
documentation for further information on how compile and use libtrace.  The `doxygen <https://www.cobaro.org/libtrace/doxygen/trace_8h.html>`_ documentation is also available.

Licence
-------
See the `license <LICENSE.txt>`_.

Contributing
------------
Contributions are welcome via `github
<https://github.com/cobaro/libtrace>`_.  Please submit proposed changes as
a pull request, or attach a patch to a GitHub issue.




