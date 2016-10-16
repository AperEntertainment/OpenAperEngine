#ifndef CPPW67RENDER_OPENWINDOW_H
#define CPPW67RENDER_OPENWINDOW_H

#include <GLFW/glfw3.h>
#include "OpenMonitor.h"

namespace Openw67Render
{
    class OpenWindow
    {
    protected:
        GLFWwindow *window;
        const char *title;
        unsigned int width;
        unsigned int height;
        unsigned int x;
        unsigned int y;
        bool visible = false;
        bool fullscreen;
        OpenMonitor monitor;

    public:
        OpenWindow(const char *title, unsigned int width, unsigned int height, OpenMonitor monitor,
                   bool fullscreen = false);

        /**
         * Gets the reference of the GLFW's window.
         *
         * @return Reference of the GLFW's window.
         */
        GLFWwindow *getWindowPointer();

        void init();

        /**
         * Destroy the window.
         */
        void destroy();

        /**
         * Gets the title of the window.
         *
         * @return Window's title.
         */
        inline const char *getTitle();

        /**
         * Sets the title of the window.
         *
         * @param title Title of the window;
         */
        void setTitle(const char *title);

        /**
         * Checks whether the window is visible or not.
         *
         * @return True if the window is visible else false.
         */
        bool isVisible();

        /**
         * Shows or hides the window.
         *
         * @param visible Visible or not.
         */
        void setVisible(bool visible);

        ~OpenWindow();
    };

    inline const char *OpenWindow::getTitle()
    {
        return title;
    }
}

#endif //CPPW67RENDER_OPENWINDOW_H
