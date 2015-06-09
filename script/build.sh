#! /bin/bash

# Assist build script debugging
env
set -x

export CFLAGS='-Wall -Werror -O2 -g -pipe -std=gnu99'
./bootstrap && \
./configure && \
make && \
make distcheck && \
make package && \
(cd test; make valgrind) && \
echo "Build passed" || \
(echo "Build failed" && exit 1)
