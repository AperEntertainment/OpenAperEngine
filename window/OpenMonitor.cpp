#include "OpenMonitor.h"

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
}