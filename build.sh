#!/bin/sh

NUM_CPUS="$(nproc)"

make -j${NUM_CPUS}
make -j${NUM_CPUS} DEBUG_BUILD=1
