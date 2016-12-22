#!/usr/bin/env bash
# Go to dependencies

RED='\033[0;31m'
NC='\033[0m'

echo -e "${RED}Warning!${NC} Ubuntu users may need to install some additional packages, check the file fix_ubuntu.txt"


cd dependencies/
# Download glew 2
wget http://downloads.sourceforge.net/project/glew/glew/2.0.0/glew-2.0.0.tgz
# Extract
tar -xvzf glew-2.0.0.tgz
# Go in the directory
cd glew-2.0.0
# Compile it and install it
make
sudo make install
