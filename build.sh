#!/usr/bin/env bash


# Warning message for Ubuntu users
RED='\033[0;31m'
NC='\033[0m'
echo -e "${RED}Warning!${NC} Ubuntu users may need to install some additional packages or do some changes, check the file fix_ubuntu.txt if you get an error"


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
