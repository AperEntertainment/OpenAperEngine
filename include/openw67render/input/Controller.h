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

#ifndef OPENW67RENDER_CONTROLLER_H
#define OPENW67RENDER_CONTROLLER_H

#ifdef _WIN32

#include <SDL_joystick.h>

#else
#include <SDL2/SDL_joystick.h>
#endif

namespace w67r
{
    class Controller
    {
    private:
        SDL_Joystick *joystick;

    public:
        Controller(SDL_Joystick *id);

        ~Controller();

        /*! @brief Gets the pointer of the controller.
         *
         * This function returns the pointer of the controller.
         *
         * @return Pointer of the controller.
         */
        SDL_Joystick *getPointer() const;

        /*! @brief Gets the name of the controller.
         *
         * This functions returns the native name of the controller.
         *
         * @return Controller's name.
         */
        const char *getName();

        /*! @brief Checks whether the controller is connected or not.
         *
         * This function checks whether the constroller is connected with GLFW.
         *
         * @return True if the controller is connected else false.
         */
        bool isConnected();

        /*! @brief Closes the device.
         *
         * This function closes the connected device, if you call it, isConnected will return false and you will can't
         * use any function here.
         */
        void close();
    };
}

#endif //OPENW67RENDER_CONTROLLER_H
