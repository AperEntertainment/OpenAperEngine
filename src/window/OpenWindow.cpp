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

#include "../../include/openw67render/window/OpenWindow.h"

namespace w67r
{
    OpenWindow::OpenWindow(const char *title, unsigned int width, unsigned int height, OpenMonitor monitor,
                           bool fullscreen, unsigned int refreshRate) : title(title), _width(width), _height(height),
                                                                        _monitor(monitor),
                                                                        _fullscreen(fullscreen), _refreshRate(refreshRate)
    {
        init();
    }

    GLFWwindow *OpenWindow::getWindowPointer()
    {
        return window;
    }

    void OpenWindow::init()
    {
        if (_fullscreen)
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
            if (_fullscreen)
                glfwSetWindowMonitor(window, getMonitor().getMonitorPointer(), xpos, ypos, width, height, _refreshRate);
            else
                glfwSetWindowMonitor(window, nullptr, xpos, ypos, width, height, _refreshRate);
        }
    }

    bool OpenWindow::isFullscreen()
    {
        _fullscreen = glfwGetWindowMonitor(window) != nullptr;
        return _fullscreen;
    }

    void OpenWindow::setMonitor(OpenMonitor monitor)
    {
        _monitor = monitor;
        if (isFullscreen())
        {
            int posX, posY;
            glfwGetWindowPos(window, &posX, &posY);
            updateSizeData();
            glfwSetWindowMonitor(window, monitor.getMonitorPointer(), posX, posY, _width, _height, _refreshRate);
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