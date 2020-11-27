#!/usr/bin/env bash

cd ./flipl/external/vcpkg/
chmod +x ./bootstrap-vcpkg.sh
source ./bootstrap-vcpkg.sh

./vcpkg install graphicsmagick
