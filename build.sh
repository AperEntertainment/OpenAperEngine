#!/usr/bin/env bash
# Dependencies
sh get_dependencies.sh
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
if [ -d "$stb" ]
then
    echo "Cleaning build directory..."
    mkdir build/
else
    mkdir build/
fi
cd build/
cmake .. && make