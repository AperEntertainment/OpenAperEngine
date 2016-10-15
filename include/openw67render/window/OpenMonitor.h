#ifndef CPPW67RENDER_OPENMONITOR_H
#define CPPW67RENDER_OPENMONITOR_H

#include <string>
#include <GLFW/glfw3.h>

namespace Openw67Render
{
    /*! @brief Video mode type.
     *
     *  This describes a single video mode.
     */
    typedef struct OpenVideoMode
    {
        OpenVideoMode(unsigned int width, unsigned int height, unsigned int redBits, unsigned int greenBits,
                      unsigned int blueBits,
                      unsigned int refreshRate) : width(width),
                                                  height(height),
                                                  redBits(redBits),
                                                  greenBits(greenBits),
                                                  blueBits(blueBits),
                                                  refreshRate(refreshRate)
        {}

        ~OpenVideoMode()
        {
            delete &width;
            delete &height;
            delete &redBits;
            delete &greenBits;
            delete &blueBits;
            delete &refreshRate;
        }

        /*! The width, in screen coordinates, of the video mode.
         */
        unsigned int width;

        /*! The height, in screen coordinates, of the video mode.
         */
        unsigned int height;

        /*! The bit depth of the red channel of the video mode.
         */
        unsigned int redBits;

        /*! The bit depth of the green channel of the video mode.
         */
        unsigned int greenBits;

        /*! The bit depth of the blue channel of the video mode.
         */
        unsigned int blueBits;

        /*! The refresh rate, in Hz, of the video mode.
         */
        unsigned int refreshRate;
    } OpenVideoMode;

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

        /*! @brief Gets the monitor's video mode.
         *
         * This function returns the current video of this monitor.
         *
         * @return The video mode type.
         */
        OpenVideoMode getVideoMode();

        /**
         * Gets the name of the monitor.
         *
         * @return Monitor's name.
         */
        inline const char *getName();

    };
}

#endif //CPPW67RENDER_OPENMONITOR_H
