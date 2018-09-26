FROM ubuntu:latest
MAINTAINER Sören Gade <gade.soeren@gmail.com>

# 2.1.1 Quick Setup
RUN apt-get update && apt-get install -y build-essential nasm genisoimage

ADD . /
ENTRYPOINT /build.sh
