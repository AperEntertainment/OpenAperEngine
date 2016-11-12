#!/usr/bin/env bash
# Clear Workspace task

# STB
sh get_stb.sh

# GLEW
glew="dependencies/glew-2.0.0"
# Check GLEW.
echo "Checking GLEW at $glew..."
if [ -d "$glew" ]
then
    echo "Clearing GLEW directory..."
    rm -rdv ${glew}
    rm -v dependencies/glew-2.0.0.tgz
fi