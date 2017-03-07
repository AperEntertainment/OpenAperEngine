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

#include "../../include/openaperengine/window/OpenMonitor.h"

namespace oae
{
    OpenMonitor::OpenMonitor(GLFWmonitor *monitor)
    {
        OpenMonitor::monitor = monitor;
    }

    GLFWmonitor *OpenMonitor::getMonitorPointer()
    {
        return monitor;
    }

    std::string OpenMonitor::getName()
    {
        // Call GLFW API.
        return std::string(glfwGetMonitorName(monitor));
    }

    OpenVideoMode OpenMonitor::getVideoMode()
    {
        const GLFWvidmode *vidMode = glfwGetVideoMode(getMonitorPointer());
        return OpenVideoMode(static_cast<unsigned int>(vidMode->height),
                             static_cast<unsigned int>(vidMode->width),
                             static_cast<unsigned int>(vidMode->redBits),
                             static_cast<unsigned int>(vidMode->greenBits),
                             static_cast<unsigned int>(vidMode->blueBits),
                             static_cast<unsigned int>(vidMode->refreshRate));
    }

    const OpenMonitor OpenMonitor::PRIMARY_MONITOR{glfwGetPrimaryMonitor()};
}
