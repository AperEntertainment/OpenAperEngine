#include "OpenWindow.h"
#include <GLFW/glfw3.h>

namespace Openw67Render
{
    OpenWindow::OpenWindow(const char *title, unsigned int width, unsigned int height, OpenMonitor monitor,
                           bool fullscreen)
    {
        OpenWindow::title = title;
        OpenWindow::width = width;
        OpenWindow::height = height;
        OpenWindow::monitor = monitor;
        OpenWindow::fullscreen = fullscreen;
        init();
    }

    GLFWwindow *OpenWindow::getWindowReference()
    {
        return window;
    }

    void OpenWindow::init()
    {
        if (fullscreen)
            window = glfwCreateWindow(width, height, title, monitor.getMonitorReference(), NULL);
        else
            window = glfwCreateWindow(width, height, title, NULL, NULL);
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
        glfwDestroyWindow(window);
        delete &window;
        delete &title;
        delete &width;
        delete &height;
        delete &x;
        delete &y;
        delete &visible;
        delete &fullscreen;
        delete &monitor;
    }
}