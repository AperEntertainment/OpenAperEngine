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

namespace w67r
{
    OpenGraphics::OpenGraphics(float complementX, float complementY) : _complementX(complementX),
                                                                       _complementY(complementY)
    {
    }

    float OpenGraphics::complementX() const
    {
        return _complementX;
    }

    float OpenGraphics::complementY() const
    {
        return _complementY;
    }

    void OpenGraphics::setOrthoOn(OpenWindow *window)
    {
        int width, height;
        glfwGetFramebufferSize(window->getWindowPointer(), &width, &height);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix(); // preserve perspective view
        glLoadIdentity(); // clear the perspective matrix
        glOrtho( // turn on 2D mode
                //// viewportX,viewportX+viewportW, // left, right
                //// viewportY,viewportY+viewportH, // bottom, top !!!
                0, width, // left, right
                height, 0, // bottom, top
                -500, 500); // Zfar, Znear
        // clear the modelview matrix
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix(); // Preserve the Modelview Matrix
        glLoadIdentity(); // clear the Modelview Matrix
        // disable depth test so further drawing will go over the current scene
        glDisable(GL_DEPTH_TEST);
    }

    void OpenGraphics::setOrthoOff()
    {
        // Restore the original positions and views.
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
        // Turn Depth Testing back on.
        glEnable(GL_DEPTH_TEST);
    }

    void OpenGraphics::setTransparency(bool transparency)
    {
        if (transparency != isTransparency())
            if (transparency)
            {
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            }
            else
                glDisable(GL_BLEND);
    }

    bool OpenGraphics::isTransparency()
    {
        return glIsEnabled(GL_BLEND);
    }

    void OpenGraphics::setTexture2DOn(bool useTexture2D)
    {
        if (useTexture2D != isTexture2D())
            if (useTexture2D)
            {
                glEnable(GL_TEXTURE_2D);
            }
            else
                glDisable(GL_TEXTURE_2D);
    }

    bool OpenGraphics::isTexture2D()
    {
        return glIsEnabled(GL_TEXTURE_2D);
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
        x += _complementX;
        y += _complementY;
        x2 += _complementX;
        y2 += _complementY;

        // Start to draw the line.
        beginDraw(DRAW_TYPE_LINES);
        // Defines vertex
        vertex2f(x, y);
        vertex2f(x2, y2);
        // Finish to draw the line.
        endDraw();
    }

    void OpenGraphics::drawImage(OpenTexture texture, float x, float y, float width, float height)
    {
        drawImage(texture, x, y, width, height, OpenTextureRegion::BASE);
    }

    void
    OpenGraphics::drawImage(OpenTexture texture, float x, float y, float width, float height, OpenTextureRegion region)
    {
        x = x + _complementX;
        y = y + _complementY;

        texture.bind();
        beginDraw(DRAW_TYPE_QUADS);
        glTexCoord2f(region.minX(), region.minY());
        vertex2f(x, y + height);
        glTexCoord2f(region.minX(), region.maxY());
        vertex2f(x, y);
        glTexCoord2f(region.maxX(), region.maxY());
        vertex2f(x + width, y);
        glTexCoord2f(region.maxX(), region.minY());
        vertex2f(x + width, y + height);
        endDraw();
        texture.unbind();
    }

    void setViewport(int x, int y, int width, int height)
    {
        glViewport(x, y, width, height);
    }
}