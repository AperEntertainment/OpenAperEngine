#include "../../include/openw67render/graphics/OpenGraphics.h"
#include <stdexcept>
#include <iostream>

namespace Openw67Render
{
    OpenGraphics::OpenGraphics(float complementX, float complementY)
    {
        this->complementX = complementX;
        this->complementY = complementY;
    }

    OpenGraphics::~OpenGraphics()
    {
        delete &complementX;
        delete &complementY;
        delete &drawing;
    }

    float toFloatColor(short255 color)
    {
        return (float) (color / 255.0);
    }

    void OpenGraphics::setColor(Color color)
    {
        // Call glColor.
        glColor4f(toFloatColor(color.getRed()), toFloatColor(color.getGreen()), toFloatColor(color.getBlue()),
                  toFloatColor(color.getAlpha()));
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