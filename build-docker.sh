#!/bin/sh

set -e

# Build docker image
IMAGE_ID=$(docker build . | awk 'NF>1{print $NF}' | tail -n1)

# Run build
docker run -v "$PWD":/build -w /build $IMAGE_ID
