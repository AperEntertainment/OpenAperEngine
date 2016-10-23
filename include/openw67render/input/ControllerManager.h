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

#ifndef OPENW67RENDER_CONTROLLERS_H
#define OPENW67RENDER_CONTROLLERS_H

#include "Controller.h"
#include <vector>

namespace w67r
{
    class ControllerBaseListener
    {
    public:
        virtual void connect(Controller &controller) = 0;

        virtual void disconnect(Controller &controller) = 0;
    };

    class Controllers
    {
    private:
        std::vector<Controller> controllers;

        std::vector<ControllerBaseListener *> baseListeners;

        Controllers();

    public:

        /*! @brief Gets an controller by his defined ID.
         *
         * This function returns an controller by his defined ID.
         * The ID is between 0 and GLFW_JOYSTICK_LAST.
         *
         * @param id ID of the controller.
         *
         * @return The instance of the controller.
         */
        Controller getController(uint8_t id);

        /*! @brief Adds an basic listener.
         *
         * This function adds a new listener.
         *
         * @param listener The pointer of the listener to add.
         */
        void addBaseListener(ControllerBaseListener *listener);

        /*! @brief Removes an basic listener.
         *
         * This function removes a new listener.
         *
         * @param listener The pointer of the listener to remove.
         *
         * @return True whether the listener was removed else false.
         */
        bool removeBaseListener(ControllerBaseListener *listener);

        /*! @brief Checks whether an basic listener is registered.
         *
         * This function checks wether an basic listener is registered.
         *
         * @param listener The pointer of the listener to check.
         *
         * @return True whether the listener was found else false.
         */
        bool hasBaseListener(ControllerBaseListener *listener);

        std::vector<ControllerBaseListener *> getBaseListeners() const;

        // For singleton.
        Controllers(Controllers const &) = delete;

        // For singleton.
        void operator=(Controllers const &)  = delete;

        static Controllers CONTROLLER_MANAGER;
    };
}

#endif //OPENW67RENDER_CONTROLLERS_H
