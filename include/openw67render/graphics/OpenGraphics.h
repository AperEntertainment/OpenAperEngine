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
        OpenGraphics(float complementX = 0.0, float complementY = 0.0);

        void setColor(Color color);

        void beginDraw(unsigned int drawType);

        void endDraw();

        void vertex2f(float x, float y);

        void vertex3f(float x, float y, float z);

        /**
         * Draws a line in 2D.
         *
         * @param x  X position of the first point.
         * @param y  Y position of the first point.
         * @param x2 X position of the second point.
         * @param y2 Y position of the second point.
         */
        void drawLine2D(float x, float y, float x2, float y2);
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
