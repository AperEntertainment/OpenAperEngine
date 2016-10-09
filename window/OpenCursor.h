#ifndef CPPW67RENDER_OPENCURSOR_H
#define CPPW67RENDER_OPENCURSOR_H

#include <GLFW/glfw3.h>

namespace Openw67Render
{
    class OpenCursor
    {
    private:
        GLFWcursor *cursor;

    public:
        GLFWcursor *getCursorReference();
    };

}
#endif //CPPW67RENDER_OPENCURSOR_H
