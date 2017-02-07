cmake_minimum_required(VERSION 3.1)
project(openaperengine)

# Add local find scripts to CMAKE path.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(GLFW_DIR dependencies/glfw)
set(GLFW_INCLUDE_DIR dependencies/glfw/include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -march=native -mtune=native -ffast-math -D__extern_always_inline=\"extern __always_inline\"")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -march=native -mtune=native -ffast-math")
endif()

find_package(GLEW REQUIRED)

add_subdirectory(${GLFW_DIR})
include_directories(${GLFW_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})

add_subdirectory(dependencies/glbinding)
include_directories(dependencies/glbinding/source/glbinding/include)

add_subdirectory(dependencies/soil)
include_directories(dependencies/soil/inc)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(GRAPHICS_HEADERS include/openaperengine/graphics/Color.h include/openaperengine/graphics/OpenGraphics.h include/openaperengine/graphics/OpenTexture.h)
set(INPUT_HEADERS include/openaperengine/input/Controller.h include/openaperengine/input/ControllerManager.h)
set(WINDOW_HEADERS include/openaperengine/window/OpenCursor.h include/openaperengine/window/OpenMonitor.h include/openaperengine/window/OpenWindow.h)
set(BASE_HEADERS include/openaperengine/OpenUtils.h include/openaperengine/OpenContext.h)

set(HEADERS ${GRAPHICS_HEADERS} ${INPUT_HEADERS} ${WINDOW_HEADERS} ${BASE_HEADERS})

set(GRAPHICS_SOURCES src/graphics/Color.cpp src/graphics/OpenGraphics.cpp src/graphics/OpenTexture.cpp)
set(INPUT_SOURCES src/input/Controller.cpp src/input/ControllerManager.cpp)
set(WINDOW_SOURCES src/window/OpenCursor.cpp src/window/OpenMonitor.cpp src/window/OpenWindow.cpp)
set(BASE_SOURCES src/OpenContext.cpp)

set(SOURCES ${GRAPHICS_SOURCES} ${INPUT_SOURCES} ${WINDOW_SOURCES} ${BASE_SOURCES})

add_library(openaperengine ${HEADERS} ${SOURCES})

set_property(TARGET openaperengine PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET openaperengine PROPERTY CXX_STANDARD 11)

target_link_libraries(openaperengine glbinding glfw soil ${GLEW_LIBRARY} ${GLFW_LIBRARIES})
