cmake_minimum_required(VERSION 2.8.7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(GRAPHICS_HEADERS ../include/openw67render/graphics/Color.h ../include/openw67render/graphics/OpenGraphics.h ../include/openw67render/graphics/OpenTexture.h)
set(INPUT_HEADERS ../include/openw67render/input/Controller.h ../include/openw67render/input/ControllerManager.h)
set(WINDOW_HEADERS ../include/openw67render/window/OpenCursor.h ../include/openw67render/window/OpenWindow.h)
set(BASE_HEADERS ../include/openw67render/OpenUtils.h ../include/openw67render/OpenContext.h)

set(STB_HEADERS ../include/stb/stb_image.h)

set(HEADERS ${STB_HEADERS} ${GRAPHICS_HEADERS} ${INPUT_HEADERS} ${WINDOW_HEADERS} ${BASE_HEADERS})

set(GRAPHICS_SOURCES graphics/Color.cpp graphics/OpenGraphics.cpp graphics/OpenTexture.cpp)
set(INPUT_SOURCES input/Controller.cpp input/ControllerManager.cpp)
set(WINDOW_SOURCES window/OpenCursor.cpp window/OpenWindow.cpp)
set(BASE_SOURCES OpenContext.cpp)

set(SOURCES ${GRAPHICS_SOURCES} ${INPUT_SOURCES} ${WINDOW_SOURCES} ${BASE_SOURCES})

add_library(openw67render ${HEADERS} ${SOURCES})

target_link_libraries(openw67render ${GL_LIB} ${OPENGL_gl_LIBRARY} ${SDL2_LIBRARY})