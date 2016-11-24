#
# Copyright © 2016 Clément "w67clement" Wagner
#
# This file is part of ClemCmakeFinders.
#
# ClemCmakeFinders is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# ClemCmakeFinders is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with ClemCmakeFinders.  If not, see <http://www.gnu.org/licenses/>.
#

# Try to find GLFW library and include path.
# Once done this will define
#
# GLFW_FOUND
# GLFW_INCLUDE_DIR
# GLFW_LIBRARY
#

include(FindPackageHandleStandardArgs)

if (WIN32)

    find_path(GLFW_INCLUDE_DIR
            NAMES
            GLFW/glfw3.h
            HINTS
            "${GLFW_LOCATION}/include"
            "$ENV{GLFW_LOCATION}/include"
            PATHS
            "$ENV{PROGRAMFILES}/GLFW/include"
            "${PROJECT_SOURCE_DIR}/extern/glfw/include"
            DOC "The directory where GLFW resides" )

    if ("${CMAKE_GENERATOR}" MATCHES "[Ww]in64")
        set(ARCH x64)
    else()
        set(ARCH x86)
    endif()

    find_library(GLFW_LIBRARY
            NAMES
            GLFW glfw glfw3dll glfwdll
            HINTS
            "${GLFW_LOCATION}/lib"
            "${GLFW_LOCATION}/lib-vc2015"
            "$ENV{GLFW_LOCATION}/lib"
            "$ENV{GLFW_LOCATION}/lib-vc2015"
            PATHS
            "$ENV{PROGRAMFILES}/GLFW/lib"
            "${PROJECT_SOURCE_DIR}/extern/glfw/bin"
            "${PROJECT_SOURCE_DIR}/extern/glfw/lib"
            PATH_SUFFIXES
            Release/${ARCH}
            DOC "The GLFW library")
endif ()

if (${CMAKE_HOST_UNIX})
    find_path( GLFW_INCLUDE_DIR
            NAMES
            GLFW/glfw3.h
            HINTS
            "${GLFW_LOCATION}/include"
            "$ENV{GLFW_LOCATION}/include"
            PATHS
            /usr/include
            /usr/local/include
            /sw/include
            /opt/local/include
            NO_DEFAULT_PATH
            DOC "The directory where GLFW resides"
            )
    find_library( GLFW_LIBRARY
            NAMES
            GLFW glfw
            HINTS
            "${GLFW_LOCATION}/lib"
            "$ENV{GLFW_LOCATION}/lib"
            PATHS
            /usr/lib64
            /usr/lib
            /usr/local/lib64
            /usr/local/lib
            /sw/lib
            /opt/local/lib
            NO_DEFAULT_PATH
            DOC "The GLFW library")
endif ()

find_package_handle_standard_args(GLFW
        REQUIRED_VARS
        GLFW_INCLUDE_DIR
        GLFW_LIBRARY
        )
