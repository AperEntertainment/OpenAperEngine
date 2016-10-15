#ifndef CPPW67RENDER_OPENMONITOR_H
#define CPPW67RENDER_OPENMONITOR_H

#include <string>
#include <GLFW/glfw3.h>

namespace Openw67Render
{
    class OpenMonitor
    {
    private:
        GLFWmonitor *monitor;

    public:
        OpenMonitor(GLFWmonitor *monitor = glfwGetPrimaryMonitor());

        /**
         * Gets the reference of the GLFW's monitor.
         *
         * @return Reference of the GLFW's monitor.
         */
        GLFWmonitor *getMonitorReference();

        /**
         * Gets the name of the monitor.
         *
         * @return Monitor's name.
         */
        inline const char *getName();

    };
}

#endif //CPPW67RENDER_OPENMONITOR_H
