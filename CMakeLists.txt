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

set(SOURCE_FILES src/main.cpp include/openw67render/window/OpenWindow.h src/window/OpenWindow.cpp src/window/OpenMonitor.cpp include/openw67render/window/OpenMonitor.h src/window/OpenCursor.cpp include/openw67render/window/OpenCursor.h src/graphics/OpenGraphics.cpp include/openw67render/graphics/OpenGraphics.h src/graphics/Color.cpp include/openw67render/graphics/Color.h include/openw67render/OpenUtils.h)
add_executable(cppw67render ${SOURCE_FILES})
target_link_libraries(cppw67render glfw ${GL_LIB} ${GLFW_LIBRARIES} ${OPENGL_gl_LIBRARY})