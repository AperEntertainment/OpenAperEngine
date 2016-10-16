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

#include "../../include/openw67render/graphics/OpenGraphics.h"
#include <stdexcept>
#include <iostream>

namespace Openw67Render
{
    OpenGraphics::OpenGraphics(float complementX, float complementY) : complementX(complementX),
                                                                       complementY(complementY)
    {
    }

    float toFloatColor(short255 color)
    {
        return static_cast<float>(color / 255.0);
    }

    void OpenGraphics::setColor(Color color)
    {
        // Call glColor.
        glColor4f(toFloatColor(color.red()), toFloatColor(color.green()), toFloatColor(color.blue()),
                  toFloatColor(color.alpha()));
    }

    void OpenGraphics::beginDraw(unsigned int drawType)
    {
        if (drawing)
            throw std::runtime_error("Already drawing an object.");
        drawing = true;
        glBegin(drawType);
    }

    void OpenGraphics::endDraw()
    {
        if (!drawing)
            throw std::runtime_error("Not drawing, cannot finish to draw.");
        glEnd();
        drawing = false;
    }

    void OpenGraphics::vertex2f(float x, float y)
    {
        glVertex2f(x, y);
    }

    void OpenGraphics::vertex3f(float x, float y, float z)
    {
        glVertex3f(x, y, z);
    }

    void OpenGraphics::drawLine2D(float x, float y, float x2, float y2)
    {
        // Calculate the real X, the real Y, the real second X and the real second Y.
        x += complementX;
        y += complementY;
        x2 += complementX;
        y2 += complementY;

        // Start to draw the line.
        beginDraw(DRAW_TYPE_LINES);
        // Defines vertex
        vertex2f(x, y);
        vertex2f(x2, y2);
        // Finish to draw the line.
        endDraw();
    }

    void setViewport(int x, int y, int width, int height)
    {
        glViewport(x, y, width, height);
    }
}