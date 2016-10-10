cmake_minimum_required(VERSION 3.5)
project(cppw67render)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenGL REQUIRED)

add_subdirectory(dependencies/glfw)
include_directories(dependencies/glfw/include)
include_directories(${OPENGL_INCLUDE_DIR})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(SOURCE_FILES main.cpp window/OpenWindow.h window/OpenWindow.cpp window/OpenMonitor.cpp window/OpenMonitor.h window/OpenCursor.cpp window/OpenCursor.h graphics/OpenGraphics.cpp graphics/OpenGraphics.h graphics/Color.cpp graphics/Color.h OpenUtils.h)
add_executable(cppw67render ${SOURCE_FILES})
target_link_libraries(cppw67render glfw ${GL_LIB} ${GLFW_LIBRARIES} ${OPENGL_gl_LIBRARY})