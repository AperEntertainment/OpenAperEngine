#include "../../include/openw67render/window/OpenWindow.h"

namespace Openw67Render
{
    OpenWindow::OpenWindow(const char *title, unsigned int width, unsigned int height, OpenMonitor monitor,
                           bool fullscreen) : title(title), width(width), height(height), monitor(monitor),
                                              fullscreen(fullscreen)
    {
        init();
    }

    GLFWwindow *OpenWindow::getWindowPointer()
    {
        return window;
    }

    void OpenWindow::init()
    {
        if (fullscreen)
            window = glfwCreateWindow(width, height, title, monitor.getMonitorPointer(), nullptr);
        else
            window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    }

    void OpenWindow::destroy()
    {
        if (window)
            glfwDestroyWindow(window);
    }

    void OpenWindow::setTitle(const char *title)
    {
        OpenWindow::title = title;
        glfwSetWindowTitle(window, title);
    }

    inline bool OpenWindow::isVisible()
    {
        return visible;
    }

    void OpenWindow::setVisible(bool visible)
    {
        if (visible != isVisible())
        {
            if (!window)
            {
                if (visible)
                    glfwShowWindow(window);
                else
                    glfwHideWindow(window);
            }
            OpenWindow::visible = visible;
        }
    }

    OpenWindow::~OpenWindow()
    {
        destroy();
    }
}