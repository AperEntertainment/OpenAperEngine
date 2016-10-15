#include "../../include/openw67render/window/OpenMonitor.h"

namespace Openw67Render
{
    OpenMonitor::OpenMonitor(GLFWmonitor *monitor)
    {
        OpenMonitor::monitor = monitor;
    }

    GLFWmonitor *OpenMonitor::getMonitorReference()
    {
        return monitor;
    }

    inline const char *OpenMonitor::getName()
    {
        // Call GLFW API.
        return glfwGetMonitorName(monitor);
    }

    OpenVideoMode OpenMonitor::getVideoMode()
    {
        const GLFWvidmode *vidMode = glfwGetVideoMode(getMonitorReference());
        return Openw67Render::OpenVideoMode((unsigned int) vidMode->height, (unsigned int) vidMode->width,
                                            (unsigned int) vidMode->redBits, (unsigned int) vidMode->greenBits,
                                            (unsigned int) vidMode->blueBits, (unsigned int) vidMode->refreshRate);
    }
}