#OpenAperRender

[![Build Status](https://travis-ci.org/AperEntertainment/OpenAperRender.svg?branch=master)](https://travis-ci.org/w67clement/cppw67render)

A multimedia graphics library using **GLFW**, **SOIL** and **OpenGL (glbinding)** written in **C++**.

## Setting up

### Setting up the Workspace and compile

#### Setting up the workspace

First, clone the repository.
```bash
git clone https://github.com/AperEntertainment/OpenAperRender.git openaperrender
```
Next, go in the 'openaperrender' directory.
Then, setup the submodules:
```bash
git submodule update --init --remote
```
Now, the workspace is ready !

#### Compile

You need CMake (and Make) with a C++ compiler to build OpenAperRender.
This will compile OpenAperRender:
```bash
cmake CMakeLists.txt
make
```

### Use as dependency

#### Setting up the dependencies

##### Git

With Git, it's very simple:
```bash
git submodule add AperEntertainment/OpenAperRender.git dependencies/openaperrender
```

#### Setting up CMake

At first, add the line
```cmake
add_subdirectory(dependencies/openaperrender)
include_directories(dependencies/openaperrender/include)
```

Finally add this at the end:
```cmake
target_link_libraries(yourProjectName openaperrender soil glfw glbinding ${GLFW_LIBRARIES})
```

And... Congratulations ! You have set up OpenAperRender for your project !
