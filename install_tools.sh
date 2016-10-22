#!/usr/bin/env bash
# Update repositories
echo "Adding repository 'ppa:ubuntu-toolchain-r/test'..."
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
# Update
echo "Updating..."
sudo apt-get update -y -qq
# Install libraries
echo "Installing libraries..."
sudo apt-get install -y -qq libyajl-dev libxml2-dev libxqilla-dev
# Check compiler
if [ -z ${CXX+x} ];
then
    export CXX=g++
    export CC=gcc
else
    echo "Compiler defined: $CXX";
fi
# Install compilers
echo "Installing $CXX compiler..."
if [ "$CXX" = "clang++" ]; then sudo apt-get install -y  -qq libstdc++-4.8-dev; fi
if [ "$CXX" = "g++" ]; then sudo apt-get install -y -qq g++-4.8; fi
if [ "$CXX" = "g++" ]; then export CXX="g++-4.8" CC="gcc-4.8"; fi
echo "Use compiler: $CXX"