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
#ifndef OPENW67RENDER_OPENCONTEXT_H
#define OPENW67RENDER_OPENCONTEXT_H

#include <string>
#include "window/OpenWindow.h"

namespace w67r
{
    using namespace std;

    class Runnable
    {
    public:
        /*! @brief Gets the GLFW error callback to set.
         *
         * This function returns the function for set GLFW's error callback.
         *
         * @return The GLFW error callback to set.
         */
        virtual GLFWerrorfun glfwErrorCallback() = 0;

        /*! @brief Represents the initialization error callback.
         *
         * This function represents the initialization error callback.
         */
        virtual void initError(string error) = 0;

        /*!
         *  This function is your initialization function.
         */
        virtual void init() = 0;

        virtual void glInit() = 0;
    };

    class Context
    {
    private:
        Runnable *_runnable;
    public:
        Context(Runnable *runnable);

        /*! @brief Initializes the program.
         *
         * This function represents the initialization function of the program.
         */
        void init();

        void glInit();
    };
}

#endif //OPENW67RENDER_OPENCONTEXT_H
