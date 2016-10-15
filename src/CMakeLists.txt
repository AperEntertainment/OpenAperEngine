cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(GRAPHICS_HEADERS ../include/openw67render/graphics/Color.h ../include/openw67render/graphics/OpenGraphics.h)
set(WINDOW_HEADERS ../include/openw67render/window/OpenCursor.h ../include/openw67render/window/OpenMonitor.h ../include/openw67render/window/OpenWindow.h)
set(BASE_HEADERS ../include/openw67render/OpenUtils.h)

set(HEADERS ${GRAPHICS_HEADERS} ${WINDOW_HEADERS} ${BASE_HEADERS})

set(GRAPHICS_SOURCES graphics/Color.cpp graphics/OpenGraphics.cpp)
set(WINDOW_SOURCES window/OpenCursor.cpp window/OpenMonitor.cpp window/OpenWindow.cpp)

set(SOURCES ${GRAPHICS_SOURCES} ${WINDOW_SOURCES} OpenUtils.cpp)

add_library(openw67render ${HEADERS} ${SOURCES})

target_link_libraries(openw67render glfw ${GL_LIB} ${GLFW_LIBRARIES} ${OPENGL_gl_LIBRARY})