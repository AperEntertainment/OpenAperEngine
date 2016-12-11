/*
 * Copyright © 2016 Clément "w67clement" Wagner
 *
 * This file is part of OpenAperRender.
 *
 * OpenAperRender is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenAperRender is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with OpenAperRender.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../include/openaperrender/input/Controller.h"

namespace oar
{
    Controller::Controller(int id) : joystick(id)
    {
    }

    int Controller::getId() const
    {
        return joystick;
    }

    const char *Controller::getName()
    {
        const char *name = glfwGetJoystickName(joystick);
        if (name == NULL)
            return "NULL";
        return name;
    }

    bool Controller::isConnected()
    {
        return glfwJoystickPresent(joystick) == 1;
    }
}
