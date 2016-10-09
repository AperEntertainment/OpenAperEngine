#include "OpenGraphics.h"
#include <GLFW/glfw3.h>

namespace Openw67Render
{
    void OpenGraphics::setColor(Color color)
    {
        // Call glColor.
        glColor4f((float) color.getRed() / 255f, (float) color.getGreen() / 255f, (float) color.getBlue() / 255f,
                  (float) color.getAlpha() / 255f);
    }

    void setViewport(int x, int y, int width, int height)
    {
        glViewport(x, y, width, height);
    }
}