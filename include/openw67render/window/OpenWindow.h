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

#ifndef OPENW67RENDER_OPENWINDOW_H
#define OPENW67RENDER_OPENWINDOW_H

#include <SDL2/SDL_video.h>

namespace w67r
{
    class OpenWindow
    {
    protected:
        SDL_Window *_window;
        const char *_title;
        unsigned int _width;
        unsigned int _height;
        unsigned int _x;
        unsigned int _y;
        bool _resizable;
        bool _visible = false;
        bool _fullscreen;
        unsigned int _refreshRate;

        /*! @brief Updates the window's size data.
         *
         * The function will call setWindowSize_Lib (Openw67Render function) and update the fields _width and _height of OpenWindow.
         * It called in the library only.
         */
        void updateSizeData();

    public:
        OpenWindow(const char *title, unsigned int x, unsigned int y, unsigned int width, unsigned int height,
                   bool resizable = true, bool fullscreen = false, unsigned int refreshRate = 60);

        ~OpenWindow();

        /*! @brief Gets the reference of the SDL's window.
         *
         * @return Reference of the SDL's window.
         */
        SDL_Window *getWindowPointer();

        void init();

        /*! @brief Destroy the window.
         */
        void destroy();

        /*! @brief Gets the title of the window.
         *
         * @return Window's title.
         */
        inline const char *getTitle();

        /*! @brief Sets the title of the window.
         *
         * @param title Title of the window;
         */
        void setTitle(const char *title);

        /*! @brief Checks whether the window is visible or not.
         *
         * @return True if the window is visible else false.
         */
        bool isVisible();

        /*! @brief Shows or hides the window.
         *
         * @param visible Visible or not.
         */
        void setVisible(bool visible);

        /*! @brief Gets the width of the window.
         *
         * @return The width of the window.
         */
        unsigned int getWidth();

        /*! @brief Sets the width of the window.
         *
         * The function will resize the window with the new specified width.
         * It will not call setSize(unsigned int width, unsigned int height), it will update size data and then it will call setWindowSize_Lib (Openw67Render function).
         *
         * @param width The width of the window.
         */
        void setWidth(unsigned int width);

        /*! @brief Gets the height of the window.
         *
         * @return The height of the window.
         */
        unsigned int getHeight();

        /*! @brief Sets the height of the window.
         *
         * The function will resize the window with the new specified height.
         * It will not call setSize(unsigned int width, unsigned int height), it will update size data and then it will call setWindowSize_Lib (Openw67Render function).
         *
         * @param height The height of the window.
         */
        void setHeight(unsigned int height);

        /*! @brief Sets the size of the window.
         *
         * The function will resize the window with the new specified width and the new specified height.
         * It will not call setWidth and setHeight, it will call setWindowSize_Lib (Openw67Render function) directly.
         *
         * @param width Width of the window.
         * @param height Height of the window.
         */
        void setSize(unsigned int width, unsigned int height);

        /*! @brief Sets the minimum and the maximum size of the window.
         *
         * @param minWidth The maximum width of the window.
         * @param minHeight The maximum height of the window.
         * @param maxWidth The maximum width of the window.
         * @param maxHeight The maximum height of the window.
         */
        void
        setMaximumSize(unsigned int minWidth, unsigned int minHeight, unsigned int maxWidth, unsigned int maxHeight);

        void setFullscreen(bool isFullscreen);

        bool isFullscreen();
    };

    inline const char *OpenWindow::getTitle()
    {
        return _title;
    }
}

#endif //OPENW67RENDER_OPENWINDOW_H
