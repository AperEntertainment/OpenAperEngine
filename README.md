#Openw67Render (C++w67Render)

[![Build Status](https://travis-ci.org/w67clement/cppw67render.svg?branch=master)](https://travis-ci.org/w67clement/cppw67render)

A graphical library using **SDL** and **OpenGL** written in **C++**.

## Setting up

### Setting up the Workspace and compile

#### Setting up the workspace

First, clone the repository.
```bash
git clone https://github.com/w67clement/cppw67render.git openw67render
```
In next, you need to install SDL2, after that, the workspace is ready!

#### Compile

You need CMake (and Make) with a C++ compiler to build Openw67Render.
This will compile Openw67Render:
```bash
sh build.sh
```

### Use as dependency

#### Setting up the dependencies

##### Git

With Git, it's very simple:
```bash
git submodule add https://github.com/w67clement/cppw67render.git dependencies/openw67render
```

##### Without Git

Without Git, it's a little harder:

- Download sources of Openw67Render and put them in dependencies/openw67render
- Run get_dependencies.sh in dependencies/openw67render

#### Setting up CMake

At first, add the line
```cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/dependencies/openw67render/cmake)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
```
After project flag.

Then add this:

```cmake
add_subdirectory(dependencies/openw67render)
include_directories(dependencies/openw67render/include)
include_directories(${OPENGL_INCLUDE_DIR} ${SDL2_INCLUDE_DIR})
```

Finally add this at the end:
```cmake
target_link_libraries(yourProjectName openw67render ${OPENGL_gl_LIBRARY} ${SDL2_LIBRARY})
```

And... Congratulations ! You have set up Openw67Render for your project !