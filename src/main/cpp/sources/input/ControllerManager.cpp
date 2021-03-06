/*
 * Copyright © 2016 Clément "w67clement" Wagner
 *
 * This file is part of OpenAperEngine.
 *
 * OpenAperEngine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenAperEngine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with OpenAperEngine.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../include/openaperengine/input/ControllerManager.h"
#include <string>
#include <stdexcept>
#include <algorithm>

namespace oae
{
    void invokeControllerBaseEvent(int joy, int event)
    {
        Controllers &controllers = Controllers::CONTROLLER_MANAGER;
        Controller controller = controllers.getController(static_cast<uint8_t >(joy));
        for (ControllerBaseListener *listener : controllers.getBaseListeners())
        {
            if (event == GLFW_CONNECTED)
                listener->connect(controller);
            else if (event == GLFW_DISCONNECTED)
                listener->disconnect(controller);
        }
    }

    Controllers::Controllers()
    {
        controllers.reserve(GLFW_JOYSTICK_LAST + 1);
        for (uint8_t i = 0; i < GLFW_JOYSTICK_LAST + 1; i++)
            controllers.emplace_back(Controller(i));
    }

    void Controllers::init()
    {
        glfwSetJoystickCallback(invokeControllerBaseEvent);
    }

    Controller Controllers::getController(uint8_t id)
    {
        if (id > controllers.size() && id > GLFW_JOYSTICK_LAST)
            throw std::out_of_range("Cannot get a Controller with the ID: " + std::to_string(id));
        return controllers[id];
    }

    std::vector<Controller> Controllers::getControllers() const
    {
        return controllers;
    }

    void Controllers::addBaseListener(ControllerBaseListener *listener)
    {
        if (!hasBaseListener(listener))
            baseListeners.push_back(listener);
    }

    bool Controllers::removeBaseListener(ControllerBaseListener *listener)
    {
        if (!hasBaseListener(listener))
            return false;
        baseListeners.erase(std::remove(baseListeners.begin(), baseListeners.end(), listener), baseListeners.end());
        return true;
    }

    bool Controllers::hasBaseListener(ControllerBaseListener *listener)
    {
        return std::find(baseListeners.begin(), baseListeners.end(), listener) != baseListeners.end();
    }

    std::vector<ControllerBaseListener *> Controllers::getBaseListeners() const
    {
        return baseListeners;
    }

    Controllers Controllers::CONTROLLER_MANAGER{};
}
