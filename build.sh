#!/usr/bin/env bash
# STB Directory
stb="include/stb"
# Check STB.
echo "Checking STB at $stb..."
if [ -d "$stb" ]
then
    echo "OK."
else
    mkdir ${stb}
    # Download STB.
    echo "Downloading needed files of STB..."
    wget -P ${stb} https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
fi
# Build
cmake CMakeLists.txt
make