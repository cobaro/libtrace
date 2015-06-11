#! /bin/bash

# Assist build script debugging
env
set -x

# For convenience we set us up to fail on any error.
# and use a trapfunc to let us know abotu failure
function trapfunc {
    set +e
    echo Build failed
    exit 1
}
trap trapfunc ERR
set -e

export CFLAGS='-Wall -Werror -O2 -g -pipe -std=c99'
./bootstrap
./configure
make
make distcheck
make package
(cd test; make valgrind)

# From here on we need to be in a Jenkins environment so test that
# so we can exit here nicely if we're not
if [ -z "$JENKINS_HOME" ]; then exit 0; fi

# Find out what version configure thinks we're at
PACKAGE_VERSION=`grep PACKAGE_VERSION Makefile | awk '{ print $3 }'`

# Stash the build output of release builds so we can easily fetch them
# and they don't get overwritten by other builds
case "$GIT_BRANCH" in
origin/release/*)
    RELEASE=${GIT_BRANCH#origin/release/}
    TODAY=`date +%Y%m%d`

    case "$label" in
    Ubuntu*|Debian*)
        PACKAGES="libcobaro-trace0*_${PACKAGE_VERSION}_amd64.deb"
        ;;
    Centos[67]|Redhat*)
        PACKAGES="packages/rpm/RPMS/x86_64/libcobaro-trace0*-${PACKAGE_VERSION}-${TODAY}.x86_64.rpm"
        ;;
    MacOSX*)
        PACKAGES="packages/darwin/libcobaro-trace0-*.pkg"
        ;;
    *)
        echo "Unrecognised systype: $SYSTYPE"
        exit 1
        ;;
    esac

    if [ -n "$PACKAGES" ]; then
        mkdir -p releases/$RELEASE/$label
        cp $PACKAGES releases/$RELEASE/$label
    fi
    ;;

*)
    ;;
esac

echo "Build passed"
exit 0
