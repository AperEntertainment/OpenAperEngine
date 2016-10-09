#ifndef CPPW67RENDER_OPENGRAPHICS_H
#define CPPW67RENDER_OPENGRAPHICS_H

#include "Color.h"

namespace Openw67Render
{
    class OpenGraphics
    {
    private:
        float complementX = 0.0;
        float complementY = 0.0;
        bool drawing = false;

    public:
        OpenGraphics();

        void setColor(Color color);
    };

    /**
     * <p><a href="http://www.opengl.org/sdk/docs/man/html/glViewport.xhtml">OpenGL SDK Reference</a></p>
     * <p>
     * Specifies the viewport transformation parameters for all viewports.
     *
     * @param x      The left viewport coordinate.
     * @param y      The bottom viewport coordinate.
     * @param width  The viewport width.
     * @param height The viewport height.
     */
    void setViewport(int x, int y, int width, int height);
}

#endif //CPPW67RENDER_OPENGRAPHICS_H
