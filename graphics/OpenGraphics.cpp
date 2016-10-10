#include "OpenGraphics.h"
#include <GLFW/glfw3.h>

namespace Openw67Render
{
    float toFloatColor(int color)
    {
        return color / 255;
    }

    void OpenGraphics::setColor(Color color)
    {
        // Call glColor.
        glColor4f(toFloatColor(color.getRed()), toFloatColor(color.getGreen()), toFloatColor(color.getBlue()),
                  toFloatColor(color.getAlpha()));
    }

    void setViewport(int x, int y, int width, int height)
    {
        glViewport(x, y, width, height);
    }
}