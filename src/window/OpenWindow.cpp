#include "../../include/openw67render/window/OpenWindow.h"

namespace Openw67Render
{
    OpenWindow::OpenWindow(const char *title, unsigned int width, unsigned int height, OpenMonitor monitor,
                           bool fullscreen, unsigned int refreshRate) : title(title), _width(width), _height(height),
                                                                        _monitor(monitor),
                                                                        fullscreen(fullscreen), refreshRate(refreshRate)
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
            window = glfwCreateWindow(_width, _height, title, _monitor.getMonitorPointer(), nullptr);
        else
            window = glfwCreateWindow(_width, _height, title, nullptr, nullptr);
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

    unsigned int OpenWindow::getWidth()
    {
        updateSizeData();
        return _width;
    }

    void OpenWindow::setWidth(unsigned int width)
    {
        updateSizeData();
        _width = width;
        glfwSetWindowSize(window, _width, _height);
    }

    unsigned int OpenWindow::getHeight()
    {
        updateSizeData();
        return _height;
    }

    void OpenWindow::setHeight(unsigned int height)
    {
        updateSizeData();
        _height = height;
        glfwSetWindowSize(window, _width, _height);
    }

    void OpenWindow::setSize(unsigned int width, unsigned int height)
    {
        // NOTE: Don't call setWidth and setHeight for better performance.
        // Update OpenWindow's fields before.
        _width = width;
        _height = height;
        // Call the GLFW function.
        glfwSetWindowSize(window, _width, _height);
    }

    void OpenWindow::updateSizeData()
    {
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        _width = static_cast<unsigned int>(width);
        _height = static_cast<unsigned int>(height);
    }

    void OpenWindow::setMaximumSize(unsigned int minWidth, unsigned int minHeight, unsigned int maxWidth,
                                    unsigned int maxHeight)
    {
        // Call the GLFW function.
        glfwSetWindowSizeLimits(window, minWidth, minHeight, maxWidth, maxHeight);
    }

    void OpenWindow::setFullscreen(bool isFullscreen, unsigned int xpos, unsigned int ypos, unsigned int width,
                                   unsigned int height)
    {
        if (OpenWindow::isFullscreen() != isFullscreen)
        {
            if (fullscreen)
                glfwSetWindowMonitor(window, getMonitor().getMonitorPointer(), xpos, ypos, width, height, refreshRate);
            else
                glfwSetWindowMonitor(window, nullptr, xpos, ypos, width, height, refreshRate);
        }
    }

    bool OpenWindow::isFullscreen()
    {
        fullscreen = glfwGetWindowMonitor(window) != nullptr;
        return fullscreen;
    }

    void OpenWindow::setMonitor(OpenMonitor monitor)
    {
        _monitor = monitor;
        if (isFullscreen())
        {
            int posX, posY;
            glfwGetWindowPos(window, &posX, &posY);
            updateSizeData();
            glfwSetWindowMonitor(window, monitor.getMonitorPointer(), posX, posY, _width, _height, refreshRate);
        }
    }

    OpenMonitor OpenWindow::getMonitor()
    {
        GLFWmonitor *monitor;
        if (_monitor.getMonitorPointer() != (monitor = glfwGetWindowMonitor(window)))
        {
            if (monitor == glfwGetPrimaryMonitor())
                _monitor = OpenMonitor::PRIMARY_MONITOR;
            else
                _monitor = OpenMonitor(monitor);
        }
        return _monitor;
    }
}