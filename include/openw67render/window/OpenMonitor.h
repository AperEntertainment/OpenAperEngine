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

#ifndef OPENW67RENDER_OPENMONITOR_H
#define OPENW67RENDER_OPENMONITOR_H

#include <string>
#include <GLFW/glfw3.h>

namespace Openw67Render
{
    /*! @brief Video mode type.
     *
     *  This describes a single video mode.
     */
    typedef struct OpenVideoMode
    {
        OpenVideoMode(unsigned int width, unsigned int height, unsigned int redBits, unsigned int greenBits,
                      unsigned int blueBits,
                      unsigned int refreshRate) : width(width),
                                                  height(height),
                                                  redBits(redBits),
                                                  greenBits(greenBits),
                                                  blueBits(blueBits),
                                                  refreshRate(refreshRate)
        {}

        /*! The width, in screen coordinates, of the video mode.
         */
        unsigned int width;

        /*! The height, in screen coordinates, of the video mode.
         */
        unsigned int height;

        /*! The bit depth of the red channel of the video mode.
         */
        unsigned int redBits;

        /*! The bit depth of the green channel of the video mode.
         */
        unsigned int greenBits;

        /*! The bit depth of the blue channel of the video mode.
         */
        unsigned int blueBits;

        /*! The refresh rate, in Hz, of the video mode.
         */
        unsigned int refreshRate;
    } OpenVideoMode;

    class OpenMonitor
    {
    private:
        GLFWmonitor *monitor;

    public:
        OpenMonitor(GLFWmonitor *monitor = glfwGetPrimaryMonitor());

        /**
         * Gets the reference of the GLFW's monitor.
         *
         * @return Reference of the GLFW's monitor.
         */
        GLFWmonitor *getMonitorPointer();

        /*! @brief Gets the monitor's video mode.
         *
         * This function returns the current video of this monitor.
         *
         * @return The video mode type.
         */
        OpenVideoMode getVideoMode();

        /*! @brief Gets the name of the monitor.
         *
         * This function returns the native name of the monitor.
         *
         * @return Monitor's name.
         */
        inline const char *getName();

        /*! @brief Represents the primary monitor.
         *
         * The field contains the instance of the primary monitor.
         */
        const static OpenMonitor PRIMARY_MONITOR;
    };
}

#endif //OPENW67RENDER_OPENMONITOR_H
