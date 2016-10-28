cmake_minimum_required(VERSION 2.8.7)
project(openw67render)

# Add local find scripts to CMAKE path.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if (MINGW)
    set(SDL2_PATH "C:\\SDL2\\i686-w64-mingw32")
endif (MINGW)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${SDL2_INCLUDE_DIR})

add_subdirectory(src)