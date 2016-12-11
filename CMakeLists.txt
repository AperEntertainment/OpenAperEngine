cmake_minimum_required(VERSION 3.1)
project(openaperrender)

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

set(GRAPHICS_HEADERS include/openaperrender/graphics/Color.h include/openaperrender/graphics/OpenGraphics.h include/openaperrender/graphics/OpenTexture.h)
set(INPUT_HEADERS include/openaperrender/input/Controller.h include/openaperrender/input/ControllerManager.h)
set(WINDOW_HEADERS include/openaperrender/window/OpenCursor.h include/openaperrender/window/OpenMonitor.h include/openaperrender/window/OpenWindow.h)
set(BASE_HEADERS include/openaperrender/OpenUtils.h include/openaperrender/OpenContext.h)

set(HEADERS ${GRAPHICS_HEADERS} ${INPUT_HEADERS} ${WINDOW_HEADERS} ${BASE_HEADERS})

set(GRAPHICS_SOURCES src/graphics/Color.cpp src/graphics/OpenGraphics.cpp src/graphics/OpenTexture.cpp)
set(INPUT_SOURCES src/input/Controller.cpp src/input/ControllerManager.cpp)
set(WINDOW_SOURCES src/window/OpenCursor.cpp src/window/OpenMonitor.cpp src/window/OpenWindow.cpp)
set(BASE_SOURCES src/OpenContext.cpp)

set(SOURCES ${GRAPHICS_SOURCES} ${INPUT_SOURCES} ${WINDOW_SOURCES} ${BASE_SOURCES})

add_library(openaperrender ${HEADERS} ${SOURCES})

set_property(TARGET openaperrender PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET openaperrender PROPERTY CXX_STANDARD 11)

target_link_libraries(openaperrender glbinding glfw soil ${GLEW_LIBRARY} ${GLFW_LIBRARIES})
