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

add_subdirectory(dependencies/aperutils)
include_directories(dependencies/aperutils/include)

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

set(GRAPHICS_HEADERS src/main/cpp/include/openaperengine/graphics/Color.h src/main/cpp/include/openaperengine/graphics/OpenGraphics.h src/main/cpp/include/openaperengine/graphics/OpenTexture.h)
set(INPUT_HEADERS src/main/cpp/include/openaperengine/input/Controller.h src/main/cpp/include/openaperengine/input/ControllerManager.h)
set(WINDOW_HEADERS src/main/cpp/include/openaperengine/window/OpenCursor.h src/main/cpp/include/openaperengine/window/OpenMonitor.h src/main/cpp/include/openaperengine/window/OpenWindow.h)
set(BASE_HEADERS src/main/cpp/include/openaperengine/OpenUtils.h src/main/cpp/include/openaperengine/OpenContext.h)

set(HEADERS ${GRAPHICS_HEADERS} ${INPUT_HEADERS} ${WINDOW_HEADERS} ${BASE_HEADERS})

set(GRAPHICS_SOURCES src/main/cpp/sources/graphics/Color.cpp src/main/cpp/sources/graphics/OpenGraphics.cpp src/main/cpp/sources/graphics/OpenTexture.cpp)
set(INPUT_SOURCES src/main/cpp/sources/input/Controller.cpp src/main/cpp/sources/input/ControllerManager.cpp)
set(WINDOW_SOURCES src/main/cpp/sources/window/OpenCursor.cpp src/main/cpp/sources/window/OpenMonitor.cpp src/main/cpp/sources/window/OpenWindow.cpp)
set(BASE_SOURCES src/main/cpp/sources/OpenContext.cpp)

set(SOURCES ${GRAPHICS_SOURCES} ${INPUT_SOURCES} ${WINDOW_SOURCES} ${BASE_SOURCES})

add_library(openaperengine ${HEADERS} ${SOURCES})

set_property(TARGET openaperengine PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET openaperengine PROPERTY CXX_STANDARD 11)

target_link_libraries(openaperengine glbinding glfw soil ${GLEW_LIBRARY} ${GLFW_LIBRARIES})
