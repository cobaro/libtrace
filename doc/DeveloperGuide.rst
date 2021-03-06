Developer's Guide
=========================

Introduction
------------

libtrace is a lightweight runtime debug tracing library for C
projects. It can be completely disabled at compile time for releaes
builds, and selectively enabled at runtime for testing with debug
builds.

Code level documentation is provided via `doxygen
<https://www.cobaro.org/libtrace/doxygen/index.html>`_

Quickstart
~~~~~~~~~~

* Install the developer package, or build from source.
* Add `pkg-config --cflags libcobaro-trace0` to CPPFLAGS
* Add `pkg-config --libs libcobaro-trace0` to LDFLAGS
* Include the header:

.. code:: 

 #include <libcobaro-trace/trace.h>

* Add trace statements:

.. code:: 

 #define COBARO_TRACE_ENABLED 1

 COBARO_TRACE(25, "%s prints at level >= %d", "This example", 25);

* And make a run time selection based around the source file you are interested in, so for foo.c (or foo.cpp etc):

.. code:: 

  $ trace_foo=20 a.out

will print:

.. code:: 

12:01:34 foo.c:137 This example prints at level >= 25


Installation
------------
Cobaro Trace can be installed using the binary packages available for
popular OS distributions, or from source.


Binary packages
~~~~~~~~~~~~~~~
Binary packages for a limited number of platforms (typically latest
ubuntu, redhat, OSX) are available from `cobaro.org
<https://www.cobaro.org/libtrace>`_.

For redhat and debian based systems the runtime package contains only
the shared libraries and need only be installed if shared library
linkage is desired. The developer package contains everything needed
to provide statically linked libraries.

Building from source
~~~~~~~~~~~~~~~~~~~~
Source releases can be obtained from `github
<https://github.com/cobaro/libtrace>`_.

To initialize your build environment, or to reset it for some other
reason, you should run the ``bootstrap`` script.

To configure your build for the host OS platform, set compiler
options, and choose optional build features, you should run the
``configure`` script (generated by ``bootstrap``).  ``configure
--help`` describes its many options.

To compile and link the main library, you should run ``make`` (after
having run ``bootstrap`` and ``configure``).  You do not need to
re-bootstrap and re-configure for each build.

To install, run ``make install``, and to remove the installed files,
``make uninstall``.  These will target ``/usr/local`` by default, but
you can override this with the ``--prefix`` option to ``configure``.

To run the unit tests, run ``make check``.

To build an RPM or DEB package, run ``make package`` on the target
platform.

* Build dependencies for RHEL/CentOS

  * doxygen
  * framed
  * python-sphinx
  * texlive
  * texlive-collection-xetex
  * texlive-multirow
  * texlive-threeparttable
  * texlive-wrapfig
  * texlive-xcolor
  
* Build dependencies for macports

  * doxygen
  * py-sphinx
  * texlive
  * texlive-fonts-recommended
  * texlive-latex-extra
   
Compilation and Linkage
-----------------------
If you can use pkgconfig, it can provide the correct compilation and
linkage flags::

 pkgconfig --cflags libcobaro-trace0
 pkgconfig --libs libcobaro-trace0

To specify things manually is also simple::

 -I /usr/local/include -pthread
 -L /usr/local/lib -lcobaro-trace0 -pthread

Static vs Dynamic Linkage
~~~~~~~~~~~~~~~~~~~~~~~~~
When linking the trace library, you can choose to do so by including
the object code within your executable (static linking), or by
referencing an installed shared libary (dynamic linking).  The
autotools toolchain encourages dynamic linking, and makes it quite
hard to statically link a library if a shared version is installed.

So, in the Linux packages, if you install just the developer package,
no shared library is installed.  This will force autotools to use the
static library (libcobaro-trace0.a).  If you install the runtime package
on your development machine, autotools will link the dynamic library
(libcobaro-trace0.so) by default.

You can try to work around this by passing a path to the .a file to
the linker (without a -l flag), but ... that's in hairy territory and
having mentioned it, we'll leave you on your own with that.

Build environment
~~~~~~~~~~~~~~~~~
* Compiler assumed to be GCC 4.7+

* CFLAGS assumed to contain -std=c99 (at minimum).

* `Greatest <https://github.com/silentbicycle/greatest>`_ is used for testing
