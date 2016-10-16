#ifndef CPPW67RENDER_OPENUTILS_H
#define CPPW67RENDER_OPENUTILS_H

#include <GLFW/glfw3.h>

typedef unsigned char short255;

#define DRAW_TYPE_QUADS GL_QUADS
#define DRAW_TYPE_LINES GL_LINES

namespace Openw67Render
{
    int minInt(int x, int y);

    int maxInt(int x, int y);

    short255 min(short255 x, short255 y);

    short255 max(short255 x, short255 y);
}

#endif //CPPW67RENDER_OPENUTILS_H
