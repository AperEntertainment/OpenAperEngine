#include "../../include/openw67render/window/OpenMonitor.h"

namespace Openw67Render
{
    OpenMonitor::OpenMonitor(GLFWmonitor *monitor)
    {
        OpenMonitor::monitor = monitor;
    }

    GLFWmonitor *OpenMonitor::getMonitorPointer()
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
        const GLFWvidmode *vidMode = glfwGetVideoMode(getMonitorPointer());
        return Openw67Render::OpenVideoMode(static_cast<unsigned int>(vidMode->height),
                                            static_cast<unsigned int>(vidMode->width),
                                            static_cast<unsigned int>(vidMode->redBits),
                                            static_cast<unsigned int>(vidMode->greenBits),
                                            static_cast<unsigned int>(vidMode->blueBits),
                                            static_cast<unsigned int>(vidMode->refreshRate));
    }
}