#!/bin/sh

set -e

# build

make clean VERBOSE=1
make os.iso
