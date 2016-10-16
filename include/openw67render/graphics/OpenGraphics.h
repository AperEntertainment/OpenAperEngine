/*
 * Copyright © 2016 Clément "w67clement" Wagner
 *
 * This file is part of Openw67Render.
 *
 * Openw67Render is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Openw67Render is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Openw67Render.  If not, see <http://www.gnu.org/licenses/>.
 */

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
