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

# Stash the build output of release builds so we can easily fetch them
# and they don't get overwritten by other builds
case "$GIT_BRANCH" in
origin/release/*)
    RELEASE=${GIT_BRANCH#origin/release}
    TODAY=`date +%Y%m%d`
    SYSTYPE=`/usr/local/bin/systype.py -d`

    case "$PLATFORM" in
    Ubuntu|Debian)
        PACKAGES="libcobaro-trace0*_${RELEASE}_amd64.deb"
        ;;
    Centos/Redhat)
        PACKAGES="packages/rpm/RPMS/x86_64/libcobaro-trace0*-${RELEASE}-${TODAY}.x86_64.rpm"
        ;;
    Centos/Redhat)
        PACKAGES="packages/darwin/libcobaro-trace0-*.pkg"
        ;;
    *)
        echo "Unrecognised platform: $SYSTYPE"
        exit 1
        ;;
    esac

    if [ -n "$PACKAGES" ]; then
        mkdir -p releases
        cp $PACKAGES releases
    fi

*)
    ;;
esac

echo "Build passed"
exit 0
