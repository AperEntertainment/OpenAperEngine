#Openw67Render (C++w67Render)

[![Build Status](https://travis-ci.org/w67clement/cppw67render.svg?branch=master)](https://travis-ci.org/w67clement/cppw67render)

A graphical library using **GLFW** and **OpenGL (glbinding)** written in **C++**.

## Setting up

### Setting up the Workspace and compile

#### Setting up the workspace

First, clone the repository.
```bash
git clone https://github.com/w67clement/cppw67render.git openw67render
```
Next, go in the 'openw67render' directory.
Then, setup the submodules:
```bash
git submodule update --init --remote
```
Now, the workspace is ready !

#### Compile

You need CMake (and Make) with a C++ compiler to build Openw67Render.
This will compile Openw67Render:
```bash
cmake CMakeLists.txt
make
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
- Download sources of GLFW and put them in dependencies/openw67render/dependencies/glfw
- Download sources of glbinding and put them in dependencies/openw67render/dependencies/glbinding

#### Setting up CMake

At first, add the line
```cmake
add_subdirectory(dependencies/openw67render)
include_directories(dependencies/openw67render/include)
```

Finally add this at the end:
```cmake
target_link_libraries(yourProjectName openw67render soil glfw glbinding ${GLFW_LIBRARIES})
```

And... Congratulations ! You have set up Openw67Render for your project !