cmake_minimum_required(VERSION 3.6)
project(cppw67render)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")

add_subdirectory(dependencies/glfw)
include_directories(dependencies/glfw/include)

set(SOURCE_FILES main.cpp window/OpenWindow.h window/OpenWindow.cpp window/OpenMonitor.cpp window/OpenMonitor.h window/OpenCursor.cpp window/OpenCursor.h graphics/OpenGraphics.cpp graphics/OpenGraphics.h graphics/Color.cpp graphics/Color.h OpenUtils.h)
add_executable(cppw67render ${SOURCE_FILES})
target_link_libraries(cppw67render glfw ${GLFW_LIBRARIES})