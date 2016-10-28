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
    /* Utilities */

    void setWindowSize_LIB(SDL_Window *window, int width, int height)
    {
        SDL_SetWindowSize(window, width, height);
    }

    /* OpenWindow */

    OpenWindow::OpenWindow(const char *title, unsigned int x, unsigned int y, unsigned int width, unsigned int height,
                           bool resizable, bool fullscreen, unsigned int refreshRate) : _title(title), _x(x), _y(y),
                                                                                        _width(width),
                                                                                        _height(height),
                                                                                        _resizable(
                                                                                                resizable),
                                                                                        _fullscreen(
                                                                                                fullscreen),
                                                                                        _refreshRate(
                                                                                                refreshRate)
    {
        init();
    }

    SDL_Window *OpenWindow::getWindowPointer()
    {
        return _window;
    }

    void OpenWindow::init()
    {
        _window = SDL_CreateWindow(_title, _x, _y, _width, _height, SDL_WINDOW_HIDDEN);
        SDL_SetWindowResizable(_window, (_resizable ? SDL_TRUE : SDL_FALSE));
    }

    void OpenWindow::destroy()
    {
        if (_window)
            SDL_DestroyWindow(_window);
    }

    void OpenWindow::setTitle(const char *title)
    {
        OpenWindow::_title = title;
        SDL_SetWindowTitle(_window, title);
    }

    inline bool OpenWindow::isVisible()
    {
        return _visible;
    }

    void OpenWindow::setVisible(bool visible)
    {
        if (visible != isVisible())
        {
            if (!_window)
            {
                if (visible)
                    SDL_ShowWindow(_window);
                else
                    SDL_HideWindow(_window);
            }
            OpenWindow::_visible = visible;
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
        setWindowSize_LIB(_window, _width, _height);
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
        setWindowSize_LIB(_window, _width, _height);
    }

    void OpenWindow::setSize(unsigned int width, unsigned int height)
    {
        // NOTE: Don't call setWidth and setHeight for better performance.
        // Update OpenWindow's fields before.
        _width = width;
        _height = height;
        // Call the SDL function.
        setWindowSize_LIB(_window, _width, _height);
    }

    void OpenWindow::updateSizeData()
    {
        int width, height;
        SDL_GetWindowSize(_window, &width, &height);
        _width = static_cast<unsigned int>(width);
        _height = static_cast<unsigned int>(height);
    }

    void OpenWindow::setMaximumSize(unsigned int minWidth, unsigned int minHeight, unsigned int maxWidth,
                                    unsigned int maxHeight)
    {
        // Call the SDL function.
        SDL_SetWindowMinimumSize(_window, minWidth, minHeight);
        SDL_SetWindowMaximumSize(_window, maxWidth, maxHeight);
    }

    void OpenWindow::setFullscreen(bool isFullscreen)
    {
        if (OpenWindow::isFullscreen() != isFullscreen)
        {
            if (_fullscreen)
                SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
            else
                SDL_SetWindowFullscreen(_window, 0);
        }
    }

    bool OpenWindow::isFullscreen()
    {
        return _fullscreen;
    }
}