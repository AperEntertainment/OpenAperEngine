#!/usr/bin/env bash
# Dependencies
# Check compiler
#if [ -z ${CXX+x} ];
#then
#    export CXX=g++
#    export CC=gcc
#else
#    echo "Compiler used: $CXX";
#fi
# Check installation
#command -v ${CXX} >/dev/null 2>&1 || sh install_tools.sh
# Build
mkdir build/
cd build/
cmake ..
make