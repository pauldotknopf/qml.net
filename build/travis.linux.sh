#!/usr/bin/env bash

SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

docker run -it --rm \
    -v $SCRIPT_DIR/../:/work \
    -w /work \
    -e LD_LIBRARY_PATH=/work/src/native/output \
    qmlnet/linux-ci:qt-5.11.1 \
    ./build.sh ci