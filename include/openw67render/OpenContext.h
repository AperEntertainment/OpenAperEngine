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

namespace w67r
{
    class Runnable
    {
    public:
        /*! @brief Represents the GLFW error callback.
         * 
         * This function represents the GLFW's error callback.
         *
         * @param error An error code.
         * @param description A UTF-8 encoded string describing the error.
         */
        virtual void glfwErrorCallback(int error, const char *description) = 0;

        /*! @brief Represents the initialization error callback.
         *
         * This function represents the initialization error callback.
         */
        virtual void initError() = 0;

        /*!
         *  This function is your initialization function.
         */
        virtual void init() = 0;
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
    };
}

#endif //OPENW67RENDER_OPENCONTEXT_H
